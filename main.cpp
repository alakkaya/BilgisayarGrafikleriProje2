#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>

#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"

// Font rendering
#include <ft2build.h>
#include FT_FREETYPE_H

#include "Shader.h"
#include "Geometry.h"

// Pencere boyutları
const unsigned int SCR_WIDTH = 1700;
const unsigned int SCR_HEIGHT = 900;

// Kamera ayarları
glm::vec3 cameraPos = glm::vec3(0.0f, 1.0f, 8.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

// Kamera modu
enum CameraMode
{
    DEFAULT,
    FPS
};
CameraMode cameraMode = DEFAULT;

// Fare kontrol değişkenleri
float yaw = -90.0f;
float pitch = 0.0f;
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// Robot state
glm::vec3 robotPos = glm::vec3(0.0f, -1.0f, 4.0f);
float robotAngle = 0.0f;
bool isMoving = false;
int currentKeyframe = 0;
float animationTime = 0.0f;
bool isSleeping = false;
bool isJumping = false;
float jumpTime = 0.0f;
glm::vec3 jumpStartPos;
glm::vec3 jumpEndPos;

// Yatak pozisyonu
glm::vec3 bedPos(2.2f, -1.0f, 2.7f); // Yatağın render edildiği pozisyonla güncellendi
float bedRadius = 2.0f;

// Işık pozisyonu
glm::vec3 lightPos(0.0f, 3.0f, 0.0f); // Işığı tavana taşıdık

// Zaman değişkenleri
float deltaTime = 0.0f;
float lastFrame = 0.0f;

// Game State
enum GameState
{
    INITIAL_CHOICE,
    MOVING_TO_BED,
    MOVING_TO_DESK,
    AT_BED,
    AT_DESK,
    FREE_ROAM
};
GameState currentGameState = INITIAL_CHOICE;
float choiceTimeout = 40.0f; // 40 saniye sonra varsayılan seçim
std::string message = "Robot once yataga mi gidecek, yoksa masaya mi?\nYatak icin 'Z', Masa icin 'X' tusuna bas.\nC tusuna basarak serbest moda gecebilirsiniz.";

/// Holds all state information relevant to a character as loaded using FreeType
struct Character
{
    unsigned int TextureID; // ID handle of the glyph texture
    glm::ivec2 Size;        // Size of glyph
    glm::ivec2 Bearing;     // Offset from baseline to left/top of glyph
    unsigned int Advance;   // Horizontal offset to advance to next glyph
};

std::map<char, Character> Characters;
unsigned int textVAO, textVBO;

// Hedef pozisyonları
glm::vec3 deskPos(0.0f, -1.0f, 1.0f);

// Fonksiyon prototipleri
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void mouse_callback(GLFWwindow *window, double xpos, double ypos);
void processInput(GLFWwindow *window);
unsigned int loadShader(const char *vertexPath, const char *fragmentPath);
void RenderText(unsigned int shader, std::string text, float x, float y, float scale, glm::vec3 color);
unsigned int createCube();
std::vector<float> createSphereVertices(float radius, int sectorCount, int stackCount, glm::vec3 color);
std::vector<unsigned int> createSphereIndices(int sectorCount, int stackCount);
unsigned int createSphere(float radius, int sectorCount, int stackCount, glm::vec3 color);
bool loadRobotModel(const char *path, std::vector<float> &vertices);

// Globalde sadece pointer tanımla
Shader *shaderProgram;
Shader *textShaderProgram;

unsigned int deskVAO, deskVBO;
unsigned int legVAO, legVBO;
unsigned int monitorVAO, monitorVBO;
unsigned int mouseVAO, mouseVBO;
unsigned int keyboardVAO, keyboardVBO;
unsigned int bookVAO, bookVBO;
unsigned int caseVAO, caseVBO;
unsigned int bedVAO, bedVBO;
unsigned int sheetVAO, sheetVBO;
unsigned int pyramidVAO, pyramidVBO;
unsigned int floorVAO, floorVBO;
unsigned int leftWallVAO, leftWallVBO;
unsigned int rightWallVAO, rightWallVBO;
unsigned int backWallVAO, backWallVBO;
unsigned int lampVAO, lampVBO;

int main()
{
    // GLFW başlat
    if (!glfwInit())
    {
        std::cerr << "GLFW başlatılamadı!" << std::endl;
        return -1;
    }
    std::cout << "A: GLFW başlatıldı" << std::endl;

    // OpenGL versiyonu ayarla
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Pencere oluştur
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Final Öncesi Projesi", NULL, NULL);
    if (!window)
    {
        std::cerr << "Pencere oluşturulamadı!" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);

    // Fare yakalama modu
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // GLEW başlat
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "GLEW başlatılamadı!" << std::endl;
        glfwTerminate();
        return -1;
    }
    std::cout << "B: GLEW başlatıldı" << std::endl;

    // Derinlik testi etkinleştir
    glEnable(GL_DEPTH_TEST);

    // OBJELERİN VAO/VBO OLUŞTURULMASI
    createDesk(deskVAO, deskVBO);
    createLeg(legVAO, legVBO);
    createMonitor(monitorVAO, monitorVBO);
    createMouse(mouseVAO, mouseVBO);
    createKeyboard(keyboardVAO, keyboardVBO);
    createBook(bookVAO, bookVBO);
    createCase(caseVAO, caseVBO);
    createBed(bedVAO, bedVBO);
    createSheet(sheetVAO, sheetVBO);
    createPyramid(pyramidVAO, pyramidVBO);
    createFloor(floorVAO, floorVBO);
    createLeftWall(leftWallVAO, leftWallVBO);
    createRightWall(rightWallVAO, rightWallVBO);
    createBackWall(backWallVAO, backWallVBO);
    createLamp(lampVAO, lampVBO);
    std::cout << "C: VAO/VBO'lar oluşturuldu" << std::endl;

    // FreeType Yükle
    FT_Library ft;
    if (FT_Init_FreeType(&ft))
    {
        std::cerr << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
        return -1;
    }
    std::cout << "D: FreeType başlatıldı" << std::endl;
    FT_Face face;
    if (FT_New_Face(ft, "/System/Library/Fonts/Supplemental/Arial.ttf", 0, &face))
    {
        std::cerr << "ERROR::FREETYPE: Failed to load font" << std::endl;
        return -1;
    }
    std::cout << "E: Font yüklendi" << std::endl;
    FT_Set_Pixel_Sizes(face, 0, 48);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    for (unsigned char c = 0; c < 128; c++)
    {
        if (FT_Load_Char(face, c, FT_LOAD_RENDER))
        {
            std::cerr << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
            continue;
        }
        unsigned int texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RED,
            face->glyph->bitmap.width,
            face->glyph->bitmap.rows,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            face->glyph->bitmap.buffer);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        Character character = {
            texture,
            glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
            glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
            (unsigned int)face->glyph->advance.x};
        Characters.insert(std::pair<char, Character>(c, character));
    }
    glBindTexture(GL_TEXTURE_2D, 0);
    FT_Done_Face(face);
    FT_Done_FreeType(ft);

    // Metin için VAO/VBO
    glGenVertexArrays(1, &textVAO);
    glGenBuffers(1, &textVBO);
    glBindVertexArray(textVAO);
    glBindBuffer(GL_ARRAY_BUFFER, textVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Robot modeli yükle
    std::vector<float> robotVertices;
    if (!loadRobotModel("models/robot.obj", robotVertices))
    {
        std::cerr << "Robot modeli yüklenemedi!" << std::endl;
        return -1;
    }
    std::cout << "F: Robot modeli yüklendi" << std::endl;
    // Robot VAO/VBO oluştur
    unsigned int robotVAO, robotVBO;
    glGenVertexArrays(1, &robotVAO);
    glGenBuffers(1, &robotVBO);
    glBindVertexArray(robotVAO);
    glBindBuffer(GL_ARRAY_BUFFER, robotVBO);
    glBufferData(GL_ARRAY_BUFFER, robotVertices.size() * sizeof(float), &robotVertices[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glBindVertexArray(0);

    std::cout << "G: Ana döngü başlıyor" << std::endl;
    // GLEW başlatıldıktan sonra shader nesnelerini oluştur
    shaderProgram = new Shader("shaders/shader.vert", "shaders/shader.frag");
    textShaderProgram = new Shader("shaders/text.vert", "shaders/text.frag");
    std::cout << "B2: Shader nesneleri oluşturuldu" << std::endl;
    // Ana döngü
    while (!glfwWindowShouldClose(window))
    {
        // Zaman hesaplaması
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Input
        processInput(window);

        // Animasyon / State Updates
        isMoving = false;
        if (currentGameState == INITIAL_CHOICE)
        {
            choiceTimeout -= deltaTime;
            if (choiceTimeout <= 0)
            {
                currentGameState = MOVING_TO_BED; // Varsayılan seçim
            }
        }
        else if (currentGameState == MOVING_TO_BED)
        {
            glm::vec3 direction = glm::normalize(bedPos - robotPos);
            robotAngle = -glm::degrees(atan2(direction.z, direction.x));

            float distance = glm::length(bedPos - robotPos);
            if (distance > 1.0f)
            {
                robotPos += direction * 2.0f * deltaTime;
                isMoving = true;
            }
            else
            {
                currentGameState = AT_BED;
                message = "Aferin! Dogru tahmin ettin! Tekrar oynamak icin R basiniz.";
                // Otomatik yatma animasyonunu başlat
                isJumping = true;
                jumpTime = 0.0f;
                jumpStartPos = robotPos;
                jumpEndPos = glm::vec3(bedPos.x, -0.5f, bedPos.z);
            }
        }
        else if (currentGameState == MOVING_TO_DESK)
        {
            glm::vec3 direction = glm::normalize(deskPos - robotPos);
            robotAngle = -glm::degrees(atan2(direction.z, direction.x));

            float distance = glm::length(deskPos - robotPos);
            if (distance > 0.5f)
            {
                robotPos += direction * 2.0f * deltaTime;
                isMoving = true;
            }
            else
            {
                currentGameState = AT_DESK;
                message = "Yanlis secim yapildi! Yeniden denemek için R basiniz!";
            }
        }
        else if (isJumping)
        {
            jumpTime += deltaTime * 1.5f; // Zıplama hızı
            if (jumpTime >= 1.0f)
            {
                jumpTime = 1.0f;
                isJumping = false;
                isSleeping = true;
                robotPos = jumpEndPos; // Zıplama bitince son pozisyonu ayarla
            }
        }

        // Yürüme animasyonu için keyframe güncellemesi (eğer hareket varsa)
        if (isMoving)
        {
            animationTime += deltaTime;
            if (animationTime > 0.2f)
            {
                animationTime = 0.0f;
                currentKeyframe = (currentKeyframe + 1) % 2;
            }
        }
        else
        {
            animationTime = 0.0f; // Hareketsizken animasyonu sıfırla
        }

        // Temizleme
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Aktive shader
        shaderProgram->use();

        // Işık ayarları
        shaderProgram->setVec3("lightPos", lightPos);
        shaderProgram->setVec3("viewPos", cameraPos);
        shaderProgram->setVec3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));

        // View/Projection dönüşümleri
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        if (cameraMode == FPS)
        {
            cameraPos = robotPos + glm::vec3(0.0f, 1.8f, 0.0f); // Robotun göz hizası
        }
        glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

        shaderProgram->setMat4("projection", projection);
        shaderProgram->setMat4("view", view);

        // Masa üst kısmını çiz
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
        shaderProgram->setMat4("model", model);
        glBindVertexArray(deskVAO);
        glDrawArrays(GL_TRIANGLES, 0, 42); // 42 vertices for desk

        // Masa bacakları
        // Sol ön bacak
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-1.3f, 0.0f, 0.6f));
        shaderProgram->setMat4("model", model);
        glBindVertexArray(legVAO);
        glDrawArrays(GL_TRIANGLES, 0, 24);

        // Sağ ön bacak
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(1.3f, 0.0f, 0.6f));
        shaderProgram->setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 24);

        // Sol arka bacak
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-1.3f, 0.0f, -0.6f));
        shaderProgram->setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 24);

        // Sağ arka bacak
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(1.3f, 0.0f, -0.6f));
        shaderProgram->setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 24);

        // Monitör
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
        shaderProgram->setMat4("model", model);
        glBindVertexArray(monitorVAO);
        glDrawArrays(GL_TRIANGLES, 0, 30);

        // Mouse
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.4f, 0.0f, 0.4f));
        shaderProgram->setMat4("model", model);
        glBindVertexArray(mouseVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        // Klavye
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.6f));
        shaderProgram->setMat4("model", model);
        glBindVertexArray(keyboardVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        // Kasa (computer case)
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(1.0f, -0.1f, 0.2f)); // öne taşı
        model = glm::scale(model, glm::vec3(1.0f, 1.1f, 1.5f));      // yandan daha uzun
        shaderProgram->setMat4("model", model);
        glBindVertexArray(caseVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        // Kitaplar
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
        shaderProgram->setMat4("model", model);
        glBindVertexArray(bookVAO);
        glDrawArrays(GL_TRIANGLES, 0, 108);

        // Yatak (bed)
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(2.2f, -1.0f, 2.7f));
        model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::scale(model, glm::vec3(2.5f, 5.0f, 1.5f));
        shaderProgram->setMat4("model", model);
        glBindVertexArray(bedVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        // Çarşaf (sheet)
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(2.2f, -0.988f, 2.7f));
        model = glm::rotate(model, glm::radians(-90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::scale(model, glm::vec3(2.5f, 1.0f, 1.5f));
        shaderProgram->setMat4("model", model);
        glBindVertexArray(sheetVAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        // Oda tabanı (floor)
        model = glm::mat4(1.0f);
        shaderProgram->setMat4("model", model);
        glBindVertexArray(floorVAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        // Sol duvar (left wall)
        model = glm::mat4(1.0f);
        shaderProgram->setMat4("model", model);
        glBindVertexArray(leftWallVAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        // Sağ duvar (right wall)
        model = glm::mat4(1.0f);
        shaderProgram->setMat4("model", model);
        glBindVertexArray(rightWallVAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        // Arka duvar (back wall)
        model = glm::mat4(1.0f);
        shaderProgram->setMat4("model", model);
        glBindVertexArray(backWallVAO);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        // Ampulü çiz
        model = glm::mat4(1.0f);
        model = glm::translate(model, lightPos);
        model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
        shaderProgram->setMat4("model", model);
        glBindVertexArray(lampVAO);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 10);
        glDrawArrays(GL_TRIANGLE_FAN, 10, 10);
        glDrawArrays(GL_TRIANGLE_STRIP, 20, 6);

        // Piramit
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-0.2f, 0.0f, -0.2f));
        model = glm::scale(model, glm::vec3(1.2f, 1.0f, 1.0f));
        shaderProgram->setMat4("model", model);
        glBindVertexArray(pyramidVAO);
        glDrawArrays(GL_TRIANGLES, 0, 18);

        // Robotu çiz
        if (cameraMode != FPS)
        {
            glBindVertexArray(robotVAO);
            glm::mat4 robotModel = glm::mat4(1.0f);
            if (isJumping)
            {
                float jumpHeight = 1.5f;
                glm::vec3 currentPos = glm::mix(jumpStartPos, jumpEndPos, jumpTime);
                currentPos.y += jumpHeight * (1.0f - pow(2.0f * jumpTime - 1.0f, 2.0f));
                robotModel = glm::translate(robotModel, currentPos);
                robotModel = glm::rotate(robotModel, glm::radians(robotAngle), glm::vec3(0.0f, 1.0f, 0.0f));
            }
            else if (isSleeping)
            {
                glm::vec3 sleepPos = glm::vec3(bedPos.x, -0.5f, bedPos.z);
                robotModel = glm::translate(robotModel, sleepPos);
                robotModel = glm::rotate(robotModel, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                robotModel = glm::rotate(robotModel, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
            }
            else
            {
                glm::vec3 currentRobotPos = robotPos;
                if (isMoving)
                {
                    if (currentKeyframe == 0)
                    {
                        currentRobotPos.y -= 0.05f;
                    }
                    else
                    {
                        currentRobotPos.y += 0.05f;
                    }
                }
                robotModel = glm::translate(robotModel, currentRobotPos);
                robotModel = glm::rotate(robotModel, glm::radians(robotAngle), glm::vec3(0.0f, 1.0f, 0.0f));
            }
            robotModel = glm::scale(robotModel, glm::vec3(0.6f, 0.6f, 0.6f));
            shaderProgram->setMat4("model", robotModel);
            glDrawArrays(GL_TRIANGLES, 0, robotVertices.size() / 9);
        }

        // Metni çiz
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glm::mat4 textProjection = glm::ortho(0.0f, (float)SCR_WIDTH, 0.0f, (float)SCR_HEIGHT);
        textShaderProgram->use();
        textShaderProgram->setMat4("projection", textProjection);
        RenderText(textShaderProgram->ID, message, 25.0f, 25.0f, 0.5f, glm::vec3(1.0, 1.0f, 1.0f));
        glDisable(GL_BLEND);

        // Buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Temizlik
    glDeleteVertexArrays(1, &deskVAO);
    glDeleteVertexArrays(1, &legVAO);
    glDeleteVertexArrays(1, &monitorVAO);
    glDeleteVertexArrays(1, &mouseVAO);
    glDeleteVertexArrays(1, &keyboardVAO);
    glDeleteVertexArrays(1, &bookVAO);
    glDeleteVertexArrays(1, &caseVAO);
    glDeleteVertexArrays(1, &bedVAO);
    glDeleteVertexArrays(1, &sheetVAO);
    glDeleteVertexArrays(1, &floorVAO);
    glDeleteVertexArrays(1, &leftWallVAO);
    glDeleteVertexArrays(1, &rightWallVAO);
    glDeleteVertexArrays(1, &backWallVAO);
    glDeleteVertexArrays(1, &lampVAO);
    glDeleteVertexArrays(1, &pyramidVAO);
    glDeleteVertexArrays(1, &robotVAO);
    glDeleteBuffers(1, &pyramidVBO);
    glDeleteBuffers(1, &deskVBO);
    glDeleteBuffers(1, &legVBO);
    glDeleteBuffers(1, &monitorVBO);
    glDeleteBuffers(1, &mouseVBO);
    glDeleteBuffers(1, &keyboardVBO);
    glDeleteBuffers(1, &bookVBO);
    glDeleteBuffers(1, &caseVBO);
    glDeleteBuffers(1, &bedVBO);
    glDeleteBuffers(1, &sheetVBO);
    glDeleteBuffers(1, &floorVBO);
    glDeleteBuffers(1, &leftWallVBO);
    glDeleteBuffers(1, &rightWallVBO);
    glDeleteBuffers(1, &backWallVBO);
    glDeleteBuffers(1, &lampVBO);
    glDeleteBuffers(1, &robotVBO);

    glfwTerminate();
    delete shaderProgram;
    delete textShaderProgram;
    return 0;
}

// Görüntü ekranı boyut değişimi
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// Fare hareketi
void mouse_callback(GLFWwindow *window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // Y koordinatları tersine çevrilmiş
    lastX = xpos;
    lastY = ypos;

    const float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    // Bakış kilitlemesi (90 dereceden fazla yukarı veya aşağı bakmayı engeller)
    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    // Yeni ön vektör hesapla
    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(direction);
}

// Klavye girişi
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
    {
        // Reset camera
        cameraPos = glm::vec3(0.0f, 1.0f, 8.0f);
        cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
        cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
        yaw = -90.0f;
        pitch = 0.0f;
        firstMouse = true;
        cameraMode = DEFAULT;

        // Reset robot
        robotPos = glm::vec3(0.0f, -1.0f, 4.0f);
        robotAngle = 0.0f;
        isMoving = false;
        currentKeyframe = 0;
        animationTime = 0.0f;
        isSleeping = false;
        isJumping = false;
        jumpTime = 0.0f;

        // Reset game state
        currentGameState = INITIAL_CHOICE;
        choiceTimeout = 10.0f;
        message = "Robot once yataga mi gidecek, yoksa masaya mi?\nYatak icin 'Z', Masa icin 'X' tusuna bas.\nC tusuna basarak serbest moda gecebilirsiniz.";
        return; // Resetledikten sonra diğer inputları bu frame için işleme
    }

    // Kamera modu değişimi
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
    {
        cameraMode = DEFAULT;
        cameraPos = glm::vec3(0.0f, 1.0f, 8.0f);
        cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
        cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
        yaw = -90.0f;
        pitch = 0.0f;
    }
    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
        cameraMode = FPS;
    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS)
    {
        currentGameState = FREE_ROAM;
        message = "Serbest mod: Yon tusları ile karakteri hareket ettirebilir, E ile yatağa yatabilirsiniz.";
    }

    // Kamera hareketleri (DEFAULT modunda, serbest mod HARİÇ)
    if (cameraMode == DEFAULT && currentGameState != FREE_ROAM)
    {
        float cameraSpeed = 2.5f * deltaTime;
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            cameraPos += cameraSpeed * cameraFront;
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            cameraPos -= cameraSpeed * cameraFront;
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    }

    // Game State'e göre inputları yönet
    switch (currentGameState)
    {
    case INITIAL_CHOICE:
        if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
        {
            currentGameState = MOVING_TO_BED;
            message = "";
        }
        if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
        {
            currentGameState = MOVING_TO_DESK;
            message = "";
        }
        break;
    case AT_BED:
    case AT_DESK:
    case FREE_ROAM:
        if (isSleeping)
        {
            if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
            {
                isSleeping = false;
                robotPos = glm::vec3(bedPos.x - 1.5f, -1.0f, bedPos.z);
            }
        }
        else if (!isJumping)
        {
            float robotSpeed = 2.5f * deltaTime;
            isMoving = false; // Her frame başında sıfırla

            if (cameraMode == FPS)
            {
                // FPS modunda kamera yönüne göre hareket (strafe)
                glm::vec3 front = cameraFront;
                front.y = 0.0f;
                front = glm::normalize(front);
                glm::vec3 right = glm::normalize(glm::cross(cameraFront, cameraUp));
                if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
                {
                    robotPos += front * robotSpeed;
                    isMoving = true;
                }
                if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
                {
                    robotPos -= front * robotSpeed;
                    isMoving = true;
                }
                if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
                {
                    robotPos -= right * robotSpeed;
                    isMoving = true;
                }
                if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
                {
                    robotPos += right * robotSpeed;
                    isMoving = true;
                }
            }
            else
            { // DEFAULT camera mode (tank controls)
                // Tank kontrolleri: A/D/Left/Right ile dön, W/S/Up/Down ile ileri/geri
                if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
                {
                    robotAngle += 100.0f * deltaTime;
                }
                if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
                {
                    robotAngle -= 100.0f * deltaTime;
                }

                if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
                {
                    glm::vec3 robotForward(cos(glm::radians(robotAngle)), 0.0f, -sin(glm::radians(robotAngle)));
                    robotPos += robotForward * robotSpeed;
                    isMoving = true;
                }
                if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
                {
                    glm::vec3 robotForward(cos(glm::radians(robotAngle)), 0.0f, -sin(glm::radians(robotAngle)));
                    robotPos -= robotForward * robotSpeed;
                    isMoving = true;
                }
            }

            if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
            {
                float distance = glm::length(robotPos - bedPos);
                if (distance < bedRadius)
                {
                    isJumping = true;
                    isMoving = false;
                    jumpTime = 0.0f;
                    jumpStartPos = robotPos;
                    jumpEndPos = glm::vec3(bedPos.x, -0.5f, bedPos.z);
                }
            }
        }
        break;
    case MOVING_TO_BED:
    case MOVING_TO_DESK:
        // Otomatik hareket sırasında kullanıcı inputu alma
        break;
    }
}

void RenderText(unsigned int shader, std::string text, float x, float y, float scale, glm::vec3 color)
{
    // activate corresponding render state
    glUseProgram(shader);
    glUniform3f(glGetUniformLocation(shader, "textColor"), color.x, color.y, color.z);
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(textVAO);

    // iterate through all characters
    std::string::const_iterator c;
    for (c = text.begin(); c != text.end(); c++)
    {
        Character ch = Characters[*c];

        float xpos = x + ch.Bearing.x * scale;
        float ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

        float w = ch.Size.x * scale;
        float h = ch.Size.y * scale;
        // update VBO for each character
        float vertices[6][4] = {
            {xpos, ypos + h, 0.0f, 0.0f},
            {xpos, ypos, 0.0f, 1.0f},
            {xpos + w, ypos, 1.0f, 1.0f},

            {xpos, ypos + h, 0.0f, 0.0f},
            {xpos + w, ypos, 1.0f, 1.0f},
            {xpos + w, ypos + h, 1.0f, 0.0f}};
        // render glyph texture over quad
        glBindTexture(GL_TEXTURE_2D, ch.TextureID);
        // update content of VBO memory
        glBindBuffer(GL_ARRAY_BUFFER, textVBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // be sure to use glBufferSubData and not glBufferData

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        // render quad
        glDrawArrays(GL_TRIANGLES, 0, 6);
        // now advance cursors for next glyph (note that advance is number of 1/64 pixels)
        x += (ch.Advance >> 6) * scale; // bitshift by 6 to get value in pixels (2^6 = 64 (divide amount of 1/64th pixels by 64 to get amount of pixels))
    }
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

// Küre oluşturma fonksiyonu
std::vector<float> createSphereVertices(float radius, int sectorCount, int stackCount, glm::vec3 color)
{
    std::vector<float> vertices;
    float x, y, z, xy;                           // vertex position
    float nx, ny, nz, lengthInv = 1.0f / radius; // normal

    float sectorStep = 2 * M_PI / sectorCount;
    float stackStep = M_PI / stackCount;
    float sectorAngle, stackAngle;

    for (int i = 0; i <= stackCount; ++i)
    {
        stackAngle = M_PI / 2 - i * stackStep; // starting from pi/2 to -pi/2
        xy = radius * cosf(stackAngle);        // r * cos(u)
        z = radius * sinf(stackAngle);         // r * sin(u)

        for (int j = 0; j < sectorCount; ++j)
        {
            sectorAngle = j * sectorStep; // starting from 0 to 2pi

            x = xy * cosf(sectorAngle); // r * cos(u) * cos(v)
            y = xy * sinf(sectorAngle); // r * cos(u) * sin(v)
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);

            nx = x * lengthInv;
            ny = y * lengthInv;
            nz = z * lengthInv;
            vertices.push_back(nx);
            vertices.push_back(ny);
            vertices.push_back(nz);

            // Renk bilgisi ekliyoruz
            vertices.push_back(color.r);
            vertices.push_back(color.g);
            vertices.push_back(color.b);
        }
    }
    return vertices;
}

std::vector<unsigned int> createSphereIndices(int sectorCount, int stackCount)
{
    std::vector<unsigned int> indices;
    int k1, k2;

    for (int i = 0; i < stackCount; ++i)
    {
        k1 = i * (sectorCount + 1); // beginning of current stack
        k2 = k1 + sectorCount + 1;  // beginning of next stack

        for (int j = 0; j < sectorCount; ++j, ++k1, ++k2)
        {
            if (i != 0)
            {
                indices.push_back(k1);
                indices.push_back(k2);
                indices.push_back(k1 + 1);
            }

            if (i != (stackCount - 1))
            {
                indices.push_back(k1 + 1);
                indices.push_back(k2);
                indices.push_back(k2 + 1);
            }
        }
    }
    return indices;
}

unsigned int createSphere(float radius, int sectorCount, int stackCount, glm::vec3 color)
{
    std::vector<float> vertices = createSphereVertices(radius, sectorCount, stackCount, color);
    std::vector<unsigned int> indices = createSphereIndices(sectorCount, stackCount);

    unsigned int VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);

    return VAO;
}

bool loadRobotModel(const char *path, std::vector<float> &vertices)
{
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string warn, err;

    if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, path))
    {
        throw std::runtime_error(warn + err);
    }

    vertices.clear();
    for (const auto &shape : shapes)
    {
        for (const auto &index : shape.mesh.indices)
        {
            // Vertex
            vertices.push_back(attrib.vertices[3 * index.vertex_index + 0]);
            vertices.push_back(attrib.vertices[3 * index.vertex_index + 1]);
            vertices.push_back(attrib.vertices[3 * index.vertex_index + 2]);

            // Normal
            if (index.normal_index >= 0)
            {
                vertices.push_back(attrib.normals[3 * index.normal_index + 0]);
                vertices.push_back(attrib.normals[3 * index.normal_index + 1]);
                vertices.push_back(attrib.normals[3 * index.normal_index + 2]);
            }
            else
            {
                vertices.push_back(0.0f);
                vertices.push_back(0.0f);
                vertices.push_back(0.0f);
            }
            // Color (gri)
            vertices.push_back(0.5f);
            vertices.push_back(0.5f);
            vertices.push_back(0.5f);
        }
    }
    return true;
}
