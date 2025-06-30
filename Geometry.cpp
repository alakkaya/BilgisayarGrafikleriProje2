#include <GL/glew.h>
#include "Geometry.h"

void createDesk(unsigned int &VAO, unsigned int &VBO) {
    // Masa için vertex verileri
    float deskVertices[] = {
        // pozisyonlar          // normallar         // renkler (kahverengi)
        // Üst yüzey
        -1.5f, -0.1f, -0.8f, 0.0f, 1.0f, 0.0f, 0.55f, 0.27f, 0.07f,
        1.5f, -0.1f, -0.8f, 0.0f, 1.0f, 0.0f, 0.55f, 0.27f, 0.07f,
        1.5f, -0.1f, 0.8f, 0.0f, 1.0f, 0.0f, 0.55f, 0.27f, 0.07f,
        1.5f, -0.1f, 0.8f, 0.0f, 1.0f, 0.0f, 0.55f, 0.27f, 0.07f,
        -1.5f, -0.1f, 0.8f, 0.0f, 1.0f, 0.0f, 0.55f, 0.27f, 0.07f,
        -1.5f, -0.1f, -0.8f, 0.0f, 1.0f, 0.0f, 0.55f, 0.27f, 0.07f,
    
        // Masa alt yüzü
        -1.5f, -0.15f, -0.8f, 0.0f, -1.0f, 0.0f, 0.45f, 0.20f, 0.05f,
        1.5f, -0.15f, -0.8f, 0.0f, -1.0f, 0.0f, 0.45f, 0.20f, 0.05f,
        1.5f, -0.15f, 0.8f, 0.0f, -1.0f, 0.0f, 0.45f, 0.20f, 0.05f,
        1.5f, -0.15f, 0.8f, 0.0f, -1.0f, 0.0f, 0.45f, 0.20f, 0.05f,
        -1.5f, -0.15f, 0.8f, 0.0f, -1.0f, 0.0f, 0.45f, 0.20f, 0.05f,
        -1.5f, -0.15f, -0.8f, 0.0f, -1.0f, 0.0f, 0.45f, 0.20f, 0.05f,
    
        // Masa kenarları
        -1.5f, -0.15f, -0.8f, 0.0f, 0.0f, -1.0f, 0.50f, 0.25f, 0.06f,
        1.5f, -0.15f, -0.8f, 0.0f, 0.0f, -1.0f, 0.50f, 0.25f, 0.06f,
        1.5f, -0.1f, -0.8f, 0.0f, 0.0f, -1.0f, 0.50f, 0.25f, 0.06f,
        1.5f, -0.1f, -0.8f, 0.0f, 0.0f, -1.0f, 0.50f, 0.25f, 0.06f,
        -1.5f, -0.1f, -0.8f, 0.0f, 0.0f, -1.0f, 0.50f, 0.25f, 0.06f,
        -1.5f, -0.15f, -0.8f, 0.0f, 0.0f, -1.0f, 0.50f, 0.25f, 0.06f,
    
        1.5f, -0.15f, -0.8f, 1.0f, 0.0f, 0.0f, 0.50f, 0.25f, 0.06f,
        1.5f, -0.15f, 0.8f, 1.0f, 0.0f, 0.0f, 0.50f, 0.25f, 0.06f,
        1.5f, -0.1f, 0.8f, 1.0f, 0.0f, 0.0f, 0.50f, 0.25f, 0.06f,
        1.5f, -0.1f, 0.8f, 1.0f, 0.0f, 0.0f, 0.50f, 0.25f, 0.06f,
        1.5f, -0.1f, -0.8f, 1.0f, 0.0f, 0.0f, 0.50f, 0.25f, 0.06f,
        1.5f, -0.15f, -0.8f, 1.0f, 0.0f, 0.0f, 0.50f, 0.25f, 0.06f,
    
        -1.5f, -0.15f, 0.8f, 0.0f, 0.0f, 1.0f, 0.50f, 0.25f, 0.06f,
        1.5f, -0.15f, 0.8f, 0.0f, 0.0f, 1.0f, 0.50f, 0.25f, 0.06f,
        1.5f, -0.1f, 0.8f, 0.0f, 0.0f, 1.0f, 0.50f, 0.25f, 0.06f,
        1.5f, -0.1f, 0.8f, 0.0f, 0.0f, 1.0f, 0.50f, 0.25f, 0.06f,
        -1.5f, -0.1f, 0.8f, 0.0f, 0.0f, 1.0f, 0.50f, 0.25f, 0.06f,
        -1.5f, -0.15f, 0.8f, 0.0f, 0.0f, 1.0f, 0.50f, 0.25f, 0.06f,
    
        -1.5f, -0.15f, -0.8f, -1.0f, 0.0f, 0.0f, 0.50f, 0.25f, 0.06f,
        -1.5f, -0.15f, 0.8f, -1.0f, 0.0f, 0.0f, 0.50f, 0.25f, 0.06f,
        -1.5f, -0.1f, 0.8f, -1.0f, 0.0f, 0.0f, 0.50f, 0.25f, 0.06f,
        -1.5f, -0.1f, 0.8f, -1.0f, 0.0f, 0.0f, 0.50f, 0.25f, 0.06f,
        -1.5f, -0.1f, -0.8f, -1.0f, 0.0f, 0.0f, 0.50f, 0.25f, 0.06f,
        -1.5f, -0.15f, -0.8f, -1.0f, 0.0f, 0.0f, 0.50f, 0.25f, 0.06f,
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(deskVertices), deskVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void createLeg(unsigned int &VAO, unsigned int &VBO) {
    // Masa ayakları için vertex verileri
    float legVertices[] = {
        // positions          // normals           // colors (dark brown)
        -0.05f, -0.8f, -0.05f, 0.0f, 0.0f, -1.0f, 0.35f, 0.18f, 0.04f,
        0.05f, -0.8f, -0.05f, 0.0f, 0.0f, -1.0f, 0.35f, 0.18f, 0.04f,
        0.05f, 0.0f, -0.05f, 0.0f, 0.0f, -1.0f, 0.35f, 0.18f, 0.04f,
        0.05f, 0.0f, -0.05f, 0.0f, 0.0f, -1.0f, 0.35f, 0.18f, 0.04f,
        -0.05f, 0.0f, -0.05f, 0.0f, 0.0f, -1.0f, 0.35f, 0.18f, 0.04f,
        -0.05f, -0.8f, -0.05f, 0.0f, 0.0f, -1.0f, 0.35f, 0.18f, 0.04f,
    
        -0.05f, -0.8f, 0.05f, 0.0f, 0.0f, 1.0f, 0.35f, 0.18f, 0.04f,
        0.05f, -0.8f, 0.05f, 0.0f, 0.0f, 1.0f, 0.35f, 0.18f, 0.04f,
        0.05f, 0.0f, 0.05f, 0.0f, 0.0f, 1.0f, 0.35f, 0.18f, 0.04f,
        0.05f, 0.0f, 0.05f, 0.0f, 0.0f, 1.0f, 0.35f, 0.18f, 0.04f,
        -0.05f, 0.0f, 0.05f, 0.0f, 0.0f, 1.0f, 0.35f, 0.18f, 0.04f,
        -0.05f, -0.8f, 0.05f, 0.0f, 0.0f, 1.0f, 0.35f, 0.18f, 0.04f,
    
        -0.05f, 0.0f, 0.05f, -1.0f, 0.0f, 0.0f, 0.35f, 0.18f, 0.04f,
        -0.05f, 0.0f, -0.05f, -1.0f, 0.0f, 0.0f, 0.35f, 0.18f, 0.04f,
        -0.05f, -0.8f, -0.05f, -1.0f, 0.0f, 0.0f, 0.35f, 0.18f, 0.04f,
        -0.05f, -0.8f, -0.05f, -1.0f, 0.0f, 0.0f, 0.35f, 0.18f, 0.04f,
        -0.05f, -0.8f, 0.05f, -1.0f, 0.0f, 0.0f, 0.35f, 0.18f, 0.04f,
        -0.05f, 0.0f, 0.05f, -1.0f, 0.0f, 0.0f, 0.35f, 0.18f, 0.04f,
    
        0.05f, 0.0f, 0.05f, 1.0f, 0.0f, 0.0f, 0.35f, 0.18f, 0.04f,
        0.05f, 0.0f, -0.05f, 1.0f, 0.0f, 0.0f, 0.35f, 0.18f, 0.04f,
        0.05f, -0.8f, -0.05f, 1.0f, 0.0f, 0.0f, 0.35f, 0.18f, 0.04f,
        0.05f, -0.8f, -0.05f, 1.0f, 0.0f, 0.0f, 0.35f, 0.18f, 0.04f,
        0.05f, -0.8f, 0.05f, 1.0f, 0.0f, 0.0f, 0.35f, 0.18f, 0.04f,
        0.05f, 0.0f, 0.05f, 1.0f, 0.0f, 0.0f, 0.35f, 0.18f, 0.04f,
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(legVertices), legVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void createMonitor(unsigned int &VAO, unsigned int &VBO) {
    // Monitör için vertex verileri
    float monitorVertices[] = {
        // pozisyonlar          // normallar         // renkler (siyah)
        // Ana ekran yüzeyi (ekran kısmı - koyu siyah)
        -0.3f, 0.0f, -0.02f, 0.0f, 0.0f, 1.0f, 0.05f, 0.05f, 0.05f,
        0.3f, 0.0f, -0.02f, 0.0f, 0.0f, 1.0f, 0.05f, 0.05f, 0.05f,
        0.3f, 0.4f, -0.02f, 0.0f, 0.0f, 1.0f, 0.05f, 0.05f, 0.05f,
        0.3f, 0.4f, -0.02f, 0.0f, 0.0f, 1.0f, 0.05f, 0.05f, 0.05f,
        -0.3f, 0.4f, -0.02f, 0.0f, 0.0f, 1.0f, 0.05f, 0.05f, 0.05f,
        -0.3f, 0.0f, -0.02f, 0.0f, 0.0f, 1.0f, 0.05f, 0.05f, 0.05f,

        // Monitör çerçevesi (gri)
        -0.32f, -0.02f, -0.03f, 0.0f, 0.0f, 1.0f, 0.3f, 0.3f, 0.3f,
        0.32f, -0.02f, -0.03f, 0.0f, 0.0f, 1.0f, 0.3f, 0.3f, 0.3f,
        0.32f, 0.42f, -0.03f, 0.0f, 0.0f, 1.0f, 0.3f, 0.3f, 0.3f,
        0.32f, 0.42f, -0.03f, 0.0f, 0.0f, 1.0f, 0.3f, 0.3f, 0.3f,
        -0.32f, 0.42f, -0.03f, 0.0f, 0.0f, 1.0f, 0.3f, 0.3f, 0.3f,
        -0.32f, -0.02f, -0.03f, 0.0f, 0.0f, 1.0f, 0.3f, 0.3f, 0.3f,

        // Monitör standı (koyu gri)
        -0.05f, -0.02f, -0.03f, 0.0f, 0.0f, 1.0f, 0.2f, 0.2f, 0.2f,
        0.05f, -0.02f, -0.03f, 0.0f, 0.0f, 1.0f, 0.2f, 0.2f, 0.2f,
        0.05f, -0.1f, -0.03f, 0.0f, 0.0f, 1.0f, 0.2f, 0.2f, 0.2f,
        0.05f, -0.1f, -0.03f, 0.0f, 0.0f, 1.0f, 0.2f, 0.2f, 0.2f,
        -0.05f, -0.1f, -0.03f, 0.0f, 0.0f, 1.0f, 0.2f, 0.2f, 0.2f,
        -0.05f, -0.02f, -0.03f, 0.0f, 0.0f, 1.0f, 0.2f, 0.2f, 0.2f,

        // Monitör taban (koyu gri) - Y koordinatlarını artırarak tabanı yukarı kaldır
        -0.15f, -0.09f, -0.03f, 0.0f, 0.0f, 1.0f, 0.2f, 0.2f, 0.2f, // Eski: -0.15f, -0.1f, -0.03f
        0.15f, -0.09f, -0.03f, 0.0f, 0.0f, 1.0f, 0.2f, 0.2f, 0.2f,  // Eski: 0.15f, -0.1f, -0.03f
        0.15f, -0.09f, 0.1f, 0.0f, 0.0f, 1.0f, 0.2f, 0.2f, 0.2f,    // Eski: 0.15f, -0.1f, 0.1f
        0.15f, -0.09f, 0.1f, 0.0f, 0.0f, 1.0f, 0.2f, 0.2f, 0.2f,    // Eski: 0.15f, -0.1f, 0.1f
        -0.15f, -0.09f, 0.1f, 0.0f, 0.0f, 1.0f, 0.2f, 0.2f, 0.2f,   // Eski: -0.15f, -0.1f, 0.1f
        -0.15f, -0.09f, -0.03f, 0.0f, 0.0f, 1.0f, 0.2f, 0.2f, 0.2f, // Eski: -0.15f, -0.1f, -0.03f
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(monitorVertices), monitorVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void createMouse(unsigned int &VAO, unsigned int &VBO) {
    // Mouse için dikdörtgen küp (3D blok)
    float mouseVertices[] = {
        // Top face
        -0.03f, -0.07f, -0.03f, 0.0f, 1.0f, 0.0f, 0.15f, 0.15f, 0.15f,
        0.03f, -0.07f, -0.03f, 0.0f, 1.0f, 0.0f, 0.15f, 0.15f, 0.15f,
        0.03f, -0.07f, -0.08f, 0.0f, 1.0f, 0.0f, 0.15f, 0.15f, 0.15f,
        0.03f, -0.07f, -0.08f, 0.0f, 1.0f, 0.0f, 0.15f, 0.15f, 0.15f,
        -0.03f, -0.07f, -0.08f, 0.0f, 1.0f, 0.0f, 0.15f, 0.15f, 0.15f,
        -0.03f, -0.07f, -0.03f, 0.0f, 1.0f, 0.0f, 0.15f, 0.15f, 0.15f,

        // Bottom face
        -0.03f, -0.11f, -0.03f, 0.0f, -1.0f, 0.0f, 0.15f, 0.15f, 0.15f,
        0.03f, -0.11f, -0.03f, 0.0f, -1.0f, 0.0f, 0.15f, 0.15f, 0.15f,
        0.03f, -0.11f, -0.08f, 0.0f, -1.0f, 0.0f, 0.15f, 0.15f, 0.15f,
        0.03f, -0.11f, -0.08f, 0.0f, -1.0f, 0.0f, 0.15f, 0.15f, 0.15f,
        -0.03f, -0.11f, -0.08f, 0.0f, -1.0f, 0.0f, 0.15f, 0.15f, 0.15f,
        -0.03f, -0.11f, -0.03f, 0.0f, -1.0f, 0.0f, 0.15f, 0.15f, 0.15f,

        // Front face
        -0.03f, -0.11f, -0.03f, 0.0f, 0.0f, 1.0f, 0.15f, 0.15f, 0.15f,
        0.03f, -0.11f, -0.03f, 0.0f, 0.0f, 1.0f, 0.15f, 0.15f, 0.15f,
        0.03f, -0.07f, -0.03f, 0.0f, 0.0f, 1.0f, 0.15f, 0.15f, 0.15f,
        0.03f, -0.07f, -0.03f, 0.0f, 0.0f, 1.0f, 0.15f, 0.15f, 0.15f,
        -0.03f, -0.07f, -0.03f, 0.0f, 0.0f, 1.0f, 0.15f, 0.15f, 0.15f,
        -0.03f, -0.11f, -0.03f, 0.0f, 0.0f, 1.0f, 0.15f, 0.15f, 0.15f,

        // Back face
        -0.03f, -0.11f, -0.08f, 0.0f, 0.0f, -1.0f, 0.15f, 0.15f, 0.15f,
        0.03f, -0.11f, -0.08f, 0.0f, 0.0f, -1.0f, 0.15f, 0.15f, 0.15f,
        0.03f, -0.07f, -0.08f, 0.0f, 0.0f, -1.0f, 0.15f, 0.15f, 0.15f,
        0.03f, -0.07f, -0.08f, 0.0f, 0.0f, -1.0f, 0.15f, 0.15f, 0.15f,
        -0.03f, -0.07f, -0.08f, 0.0f, 0.0f, -1.0f, 0.15f, 0.15f, 0.15f,
        -0.03f, -0.11f, -0.08f, 0.0f, 0.0f, -1.0f, 0.15f, 0.15f, 0.15f,

        // Left face
        -0.03f, -0.11f, -0.03f, -1.0f, 0.0f, 0.0f, 0.15f, 0.15f, 0.15f,
        -0.03f, -0.11f, -0.08f, -1.0f, 0.0f, 0.0f, 0.15f, 0.15f, 0.15f,
        -0.03f, -0.07f, -0.08f, -1.0f, 0.0f, 0.0f, 0.15f, 0.15f, 0.15f,
        -0.03f, -0.07f, -0.08f, -1.0f, 0.0f, 0.0f, 0.15f, 0.15f, 0.15f,
        -0.03f, -0.07f, -0.03f, -1.0f, 0.0f, 0.0f, 0.15f, 0.15f, 0.15f,
        -0.03f, -0.11f, -0.03f, -1.0f, 0.0f, 0.0f, 0.15f, 0.15f, 0.15f,

        // Right face
        0.03f, -0.11f, -0.03f, 1.0f, 0.0f, 0.0f, 0.15f, 0.15f, 0.15f,
        0.03f, -0.11f, -0.08f, 1.0f, 0.0f, 0.0f, 0.15f, 0.15f, 0.15f,
        0.03f, -0.07f, -0.08f, 1.0f, 0.0f, 0.0f, 0.15f, 0.15f, 0.15f,
        0.03f, -0.07f, -0.08f, 1.0f, 0.0f, 0.0f, 0.15f, 0.15f, 0.15f,
        0.03f, -0.07f, -0.03f, 1.0f, 0.0f, 0.0f, 0.15f, 0.15f, 0.15f,
        0.03f, -0.11f, -0.03f, 1.0f, 0.0f, 0.0f, 0.15f, 0.15f, 0.15f};

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(mouseVertices), mouseVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void createKeyboard(unsigned int &VAO, unsigned int &VBO) {
    float keyboardVertices[] = {
            // Ana klavye gövdesi (siyah)
            // pozisyonlar          // normallar         // renkler (siyah)
            // Üst yüzey
            -0.25f, -0.09f, -0.15f, 0.0f, 1.0f, 0.0f, 0.15f, 0.15f, 0.15f,
            0.25f, -0.09f, -0.15f, 0.0f, 1.0f, 0.0f, 0.15f, 0.15f, 0.15f,
            0.25f, -0.09f, -0.35f, 0.0f, 1.0f, 0.0f, 0.15f, 0.15f, 0.15f,
            0.25f, -0.09f, -0.35f, 0.0f, 1.0f, 0.0f, 0.15f, 0.15f, 0.15f,
            -0.25f, -0.09f, -0.35f, 0.0f, 1.0f, 0.0f, 0.15f, 0.15f, 0.15f,
            -0.25f, -0.09f, -0.15f, 0.0f, 1.0f, 0.0f, 0.15f, 0.15f, 0.15f,
        
            // Alt yüzey
            -0.25f, -0.11f, -0.15f, 0.0f, -1.0f, 0.0f, 0.1f, 0.1f, 0.1f,
            0.25f, -0.11f, -0.15f, 0.0f, -1.0f, 0.0f, 0.1f, 0.1f, 0.1f,
            0.25f, -0.11f, -0.35f, 0.0f, -1.0f, 0.0f, 0.1f, 0.1f, 0.1f,
            0.25f, -0.11f, -0.35f, 0.0f, -1.0f, 0.0f, 0.1f, 0.1f, 0.1f,
            -0.25f, -0.11f, -0.35f, 0.0f, -1.0f, 0.0f, 0.1f, 0.1f, 0.1f,
            -0.25f, -0.11f, -0.15f, 0.0f, -1.0f, 0.0f, 0.1f, 0.1f, 0.1f,
        
            // Ön yüzey
            -0.25f, -0.11f, -0.15f, 0.0f, 0.0f, 1.0f, 0.12f, 0.12f, 0.12f,
            0.25f, -0.11f, -0.15f, 0.0f, 0.0f, 1.0f, 0.12f, 0.12f, 0.12f,
            0.25f, -0.09f, -0.15f, 0.0f, 0.0f, 1.0f, 0.12f, 0.12f, 0.12f,
            0.25f, -0.09f, -0.15f, 0.0f, 0.0f, 1.0f, 0.12f, 0.12f, 0.12f,
            -0.25f, -0.09f, -0.15f, 0.0f, 0.0f, 1.0f, 0.12f, 0.12f, 0.12f,
            -0.25f, -0.11f, -0.15f, 0.0f, 0.0f, 1.0f, 0.12f, 0.12f, 0.12f,
        
            // Arka yüzey
            -0.25f, -0.11f, -0.35f, 0.0f, 0.0f, -1.0f, 0.12f, 0.12f, 0.12f,
            0.25f, -0.11f, -0.35f, 0.0f, 0.0f, -1.0f, 0.12f, 0.12f, 0.12f,
            0.25f, -0.09f, -0.35f, 0.0f, 0.0f, -1.0f, 0.12f, 0.12f, 0.12f,
            0.25f, -0.09f, -0.35f, 0.0f, 0.0f, -1.0f, 0.12f, 0.12f, 0.12f,
            -0.25f, -0.09f, -0.35f, 0.0f, 0.0f, -1.0f, 0.12f, 0.12f, 0.12f,
            -0.25f, -0.11f, -0.35f, 0.0f, 0.0f, -1.0f, 0.12f, 0.12f, 0.12f,
        
            // Sol yüzey
            -0.25f, -0.11f, -0.35f, -1.0f, 0.0f, 0.0f, 0.12f, 0.12f, 0.12f,
            -0.25f, -0.11f, -0.15f, -1.0f, 0.0f, 0.0f, 0.12f, 0.12f, 0.12f,
            -0.25f, -0.09f, -0.15f, -1.0f, 0.0f, 0.0f, 0.12f, 0.12f, 0.12f,
            -0.25f, -0.09f, -0.15f, -1.0f, 0.0f, 0.0f, 0.12f, 0.12f, 0.12f,
            -0.25f, -0.09f, -0.35f, -1.0f, 0.0f, 0.0f, 0.12f, 0.12f, 0.12f,
            -0.25f, -0.11f, -0.35f, -1.0f, 0.0f, 0.0f, 0.12f, 0.12f, 0.12f,
        
            // Sağ yüzey
            0.25f, -0.11f, -0.35f, 1.0f, 0.0f, 0.0f, 0.12f, 0.12f, 0.12f,
            0.25f, -0.11f, -0.15f, 1.0f, 0.0f, 0.0f, 0.12f, 0.12f, 0.12f,
            0.25f, -0.09f, -0.15f, 1.0f, 0.0f, 0.0f, 0.12f, 0.12f, 0.12f,
            0.25f, -0.09f, -0.15f, 1.0f, 0.0f, 0.0f, 0.12f, 0.12f, 0.12f,
            0.25f, -0.09f, -0.35f, 1.0f, 0.0f, 0.0f, 0.12f, 0.12f, 0.12f,
            0.25f, -0.11f, -0.35f, 1.0f, 0.0f, 0.0f, 0.12f, 0.12f, 0.12f,
        };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(keyboardVertices), keyboardVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void createBook(unsigned int &VAO, unsigned int &VBO) {
     // Kitaplar (üst üste 3 kitap)
    float bookVertices[] = {
        // Birinci kitap (kırmızı kitap)
        // pozisyonlar          // normallar         // renkler (kırmızı)
        // Üst yüzey
        -1.3f, -0.09f, 0.6f, 0.0f, 1.0f, 0.0f, 0.8f, 0.1f, 0.1f,
        -1.0f, -0.09f, 0.6f, 0.0f, 1.0f, 0.0f, 0.8f, 0.1f, 0.1f,
        -1.0f, -0.09f, 0.3f, 0.0f, 1.0f, 0.0f, 0.8f, 0.1f, 0.1f,
        -1.0f, -0.09f, 0.3f, 0.0f, 1.0f, 0.0f, 0.8f, 0.1f, 0.1f,
        -1.3f, -0.09f, 0.3f, 0.0f, 1.0f, 0.0f, 0.8f, 0.1f, 0.1f,
        -1.3f, -0.09f, 0.6f, 0.0f, 1.0f, 0.0f, 0.8f, 0.1f, 0.1f,

        // Alt yüzey
        -1.3f, -0.12f, 0.6f, 0.0f, -1.0f, 0.0f, 0.7f, 0.1f, 0.1f,
        -1.0f, -0.12f, 0.6f, 0.0f, -1.0f, 0.0f, 0.7f, 0.1f, 0.1f,
        -1.0f, -0.12f, 0.3f, 0.0f, -1.0f, 0.0f, 0.7f, 0.1f, 0.1f,
        -1.0f, -0.12f, 0.3f, 0.0f, -1.0f, 0.0f, 0.7f, 0.1f, 0.1f,
        -1.3f, -0.12f, 0.3f, 0.0f, -1.0f, 0.0f, 0.7f, 0.1f, 0.1f,
        -1.3f, -0.12f, 0.6f, 0.0f, -1.0f, 0.0f, 0.7f, 0.1f, 0.1f,

        // Ön yüzey
        -1.3f, -0.12f, 0.6f, 0.0f, 0.0f, 1.0f, 0.75f, 0.1f, 0.1f,
        -1.0f, -0.12f, 0.6f, 0.0f, 0.0f, 1.0f, 0.75f, 0.1f, 0.1f,
        -1.0f, -0.09f, 0.6f, 0.0f, 0.0f, 1.0f, 0.75f, 0.1f, 0.1f,
        -1.0f, -0.09f, 0.6f, 0.0f, 0.0f, 1.0f, 0.75f, 0.1f, 0.1f,
        -1.3f, -0.09f, 0.6f, 0.0f, 0.0f, 1.0f, 0.75f, 0.1f, 0.1f,
        -1.3f, -0.12f, 0.6f, 0.0f, 0.0f, 1.0f, 0.75f, 0.1f, 0.1f,

        // Arka yüzey
        -1.3f, -0.12f, 0.3f, 0.0f, 0.0f, -1.0f, 0.75f, 0.1f, 0.1f,
        -1.0f, -0.12f, 0.3f, 0.0f, 0.0f, -1.0f, 0.75f, 0.1f, 0.1f,
        -1.0f, -0.09f, 0.3f, 0.0f, 0.0f, -1.0f, 0.75f, 0.1f, 0.1f,
        -1.0f, -0.09f, 0.3f, 0.0f, 0.0f, -1.0f, 0.75f, 0.1f, 0.1f,
        -1.3f, -0.09f, 0.3f, 0.0f, 0.0f, -1.0f, 0.75f, 0.1f, 0.1f,
        -1.3f, -0.12f, 0.3f, 0.0f, 0.0f, -1.0f, 0.75f, 0.1f, 0.1f,

        // Sol yüzey
        -1.3f, -0.12f, 0.3f, -1.0f, 0.0f, 0.0f, 0.75f, 0.1f, 0.1f,
        -1.3f, -0.12f, 0.6f, -1.0f, 0.0f, 0.0f, 0.75f, 0.1f, 0.1f,
        -1.3f, -0.09f, 0.6f, -1.0f, 0.0f, 0.0f, 0.75f, 0.1f, 0.1f,
        -1.3f, -0.09f, 0.6f, -1.0f, 0.0f, 0.0f, 0.75f, 0.1f, 0.1f,
        -1.3f, -0.09f, 0.3f, -1.0f, 0.0f, 0.0f, 0.75f, 0.1f, 0.1f,
        -1.3f, -0.12f, 0.3f, -1.0f, 0.0f, 0.0f, 0.75f, 0.1f, 0.1f,

        // Sağ yüzey
        -0.95f, -0.09f, 0.35f, 1.0f, 0.0f, 0.0f, 0.1f, 0.1f, 0.75f,
        -0.95f, -0.09f, 0.55f, 1.0f, 0.0f, 0.0f, 0.1f, 0.1f, 0.75f,
        -0.95f, -0.05f, 0.55f, 1.0f, 0.0f, 0.0f, 0.1f, 0.1f, 0.75f,
        -0.95f, -0.05f, 0.55f, 1.0f, 0.0f, 0.0f, 0.1f, 0.1f, 0.75f,
        -0.95f, -0.05f, 0.35f, 1.0f, 0.0f, 0.0f, 0.1f, 0.1f, 0.75f,
        -0.95f, -0.09f, 0.35f, 1.0f, 0.0f, 0.0f, 0.1f, 0.1f, 0.75f,

        // Üçüncü kitap (yeşil kitap, ikincinin üstünde)
        // Üst yüzey
        -1.2f, -0.01f, 0.5f, 0.0f, 1.0f, 0.0f, 0.1f, 0.7f, 0.3f,
        -1.0f, -0.01f, 0.5f, 0.0f, 1.0f, 0.0f, 0.1f, 0.7f, 0.3f,
        -1.0f, -0.01f, 0.4f, 0.0f, 1.0f, 0.0f, 0.1f, 0.7f, 0.3f,
        -1.0f, -0.01f, 0.4f, 0.0f, 1.0f, 0.0f, 0.1f, 0.7f, 0.3f,
        -1.2f, -0.01f, 0.4f, 0.0f, 1.0f, 0.0f, 0.1f, 0.7f, 0.3f,
        -1.2f, -0.01f, 0.5f, 0.0f, 1.0f, 0.0f, 0.1f, 0.7f, 0.3f,

        // Alt yüzey (bu, ikinci kitabın üzerine oturuyor)
        -1.2f, -0.05f, 0.5f, 0.0f, -1.0f, 0.0f, 0.1f, 0.6f, 0.3f,
        -1.0f, -0.05f, 0.5f, 0.0f, -1.0f, 0.0f, 0.1f, 0.6f, 0.3f,
        -1.0f, -0.05f, 0.4f, 0.0f, -1.0f, 0.0f, 0.1f, 0.6f, 0.3f,
        -1.0f, -0.05f, 0.4f, 0.0f, -1.0f, 0.0f, 0.1f, 0.6f, 0.3f,
        -1.2f, -0.05f, 0.4f, 0.0f, -1.0f, 0.0f, 0.1f, 0.6f, 0.3f,
        -1.2f, -0.05f, 0.5f, 0.0f, -1.0f, 0.0f, 0.1f, 0.6f, 0.3f,

        // Ön yüzey
        -1.2f, -0.05f, 0.5f, 0.0f, 0.0f, 1.0f, 0.1f, 0.65f, 0.3f,
        -1.0f, -0.05f, 0.5f, 0.0f, 0.0f, 1.0f, 0.1f, 0.65f, 0.3f,
        -1.0f, -0.01f, 0.5f, 0.0f, 0.0f, 1.0f, 0.1f, 0.65f, 0.3f,
        -1.0f, -0.01f, 0.5f, 0.0f, 0.0f, 1.0f, 0.1f, 0.65f, 0.3f,
        -1.2f, -0.01f, 0.5f, 0.0f, 0.0f, 1.0f, 0.1f, 0.65f, 0.3f,
        -1.2f, -0.05f, 0.5f, 0.0f, 0.0f, 1.0f, 0.1f, 0.65f, 0.3f,

        // Arka yüzey
        -1.2f, -0.05f, 0.4f, 0.0f, 0.0f, -1.0f, 0.1f, 0.65f, 0.3f,
        -1.0f, -0.05f, 0.4f, 0.0f, 0.0f, -1.0f, 0.1f, 0.65f, 0.3f,
        -1.0f, -0.01f, 0.4f, 0.0f, 0.0f, -1.0f, 0.1f, 0.65f, 0.3f,
        -1.0f, -0.01f, 0.4f, 0.0f, 0.0f, -1.0f, 0.1f, 0.65f, 0.3f,
        -1.2f, -0.01f, 0.4f, 0.0f, 0.0f, -1.0f, 0.1f, 0.65f, 0.3f,
        -1.2f, -0.05f, 0.4f, 0.0f, 0.0f, -1.0f, 0.1f, 0.65f, 0.3f,

        // Sol yüzey
        -1.2f, -0.05f, 0.4f, -1.0f, 0.0f, 0.0f, 0.1f, 0.65f, 0.3f,
        -1.2f, -0.05f, 0.5f, -1.0f, 0.0f, 0.0f, 0.1f, 0.65f, 0.3f,
        -1.2f, -0.01f, 0.5f, -1.0f, 0.0f, 0.0f, 0.1f, 0.65f, 0.3f,
        -1.2f, -0.01f, 0.5f, -1.0f, 0.0f, 0.0f, 0.1f, 0.65f, 0.3f,
        -1.2f, -0.01f, 0.4f, -1.0f, 0.0f, 0.0f, 0.1f, 0.65f, 0.3f,
        -1.2f, -0.05f, 0.4f, -1.0f, 0.0f, 0.0f, 0.1f, 0.65f, 0.3f,

        // Sağ yüzey
        -1.0f, -0.05f, 0.4f, 1.0f, 0.0f, 0.0f, 0.1f, 0.65f, 0.3f,
        -1.0f, -0.05f, 0.5f, 1.0f, 0.0f, 0.0f, 0.1f, 0.65f, 0.3f,
        -1.0f, -0.01f, 0.5f, 1.0f, 0.0f, 0.0f, 0.1f, 0.65f, 0.3f,
        -1.0f, -0.01f, 0.5f, 1.0f, 0.0f, 0.0f, 0.1f, 0.65f, 0.3f,
        -1.0f, -0.01f, 0.4f, 1.0f, 0.0f, 0.0f, 0.1f, 0.65f, 0.3f,
        -1.0f, -0.05f, 0.4f, 1.0f, 0.0f, 0.0f, 0.1f, 0.65f, 0.3f};

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(bookVertices), bookVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void createCase(unsigned int &VAO, unsigned int &VBO) {
    float caseVertices[] = {
        // Top face
        -0.1f, 0.5f, -0.1f, 0.0f, 1.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        0.1f, 0.5f, -0.1f, 0.0f, 1.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        0.1f, 0.5f, 0.1f, 0.0f, 1.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        0.1f, 0.5f, 0.1f, 0.0f, 1.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        -0.1f, 0.5f, 0.1f, 0.0f, 1.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        -0.1f, 0.5f, -0.1f, 0.0f, 1.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        // Bottom face
        -0.1f, 0.0f, -0.1f, 0.0f, -1.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        0.1f, 0.0f, -0.1f, 0.0f, -1.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        0.1f, 0.0f, 0.1f, 0.0f, -1.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        0.1f, 0.0f, 0.1f, 0.0f, -1.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        -0.1f, 0.0f, 0.1f, 0.0f, -1.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        -0.1f, 0.0f, -0.1f, 0.0f, -1.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        // Front face
        -0.1f, 0.0f, 0.1f, 0.0f, 0.0f, 1.0f, 0.7f, 0.7f, 0.7f,
        0.1f, 0.0f, 0.1f, 0.0f, 0.0f, 1.0f, 0.7f, 0.7f, 0.7f,
        0.1f, 0.5f, 0.1f, 0.0f, 0.0f, 1.0f, 0.7f, 0.7f, 0.7f,
        0.1f, 0.5f, 0.1f, 0.0f, 0.0f, 1.0f, 0.7f, 0.7f, 0.7f,
        -0.1f, 0.5f, 0.1f, 0.0f, 0.0f, 1.0f, 0.7f, 0.7f, 0.7f,
        -0.1f, 0.0f, 0.1f, 0.0f, 0.0f, 1.0f, 0.7f, 0.7f, 0.7f,
        // Back face
        -0.1f, 0.0f, -0.1f, 0.0f, 0.0f, -1.0f, 0.7f, 0.7f, 0.7f,
        0.1f, 0.0f, -0.1f, 0.0f, 0.0f, -1.0f, 0.7f, 0.7f, 0.7f,
        0.1f, 0.5f, -0.1f, 0.0f, 0.0f, -1.0f, 0.7f, 0.7f, 0.7f,
        0.1f, 0.5f, -0.1f, 0.0f, 0.0f, -1.0f, 0.7f, 0.7f, 0.7f,
        -0.1f, 0.5f, -0.1f, 0.0f, 0.0f, -1.0f, 0.7f, 0.7f, 0.7f,
        -0.1f, 0.0f, -0.1f, 0.0f, 0.0f, -1.0f, 0.7f, 0.7f, 0.7f,
        // Left face
        -0.1f, 0.0f, -0.1f, -1.0f, 0.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        -0.1f, 0.0f, 0.1f, -1.0f, 0.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        -0.1f, 0.5f, 0.1f, -1.0f, 0.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        -0.1f, 0.5f, 0.1f, -1.0f, 0.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        -0.1f, 0.5f, -0.1f, -1.0f, 0.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        -0.1f, 0.0f, -0.1f, -1.0f, 0.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        // Right face
        0.1f, 0.0f, -0.1f, 1.0f, 0.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        0.1f, 0.0f, 0.1f, 1.0f, 0.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        0.1f, 0.5f, 0.1f, 1.0f, 0.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        0.1f, 0.5f, 0.1f, 1.0f, 0.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        0.1f, 0.5f, -0.1f, 1.0f, 0.0f, 0.0f, 0.7f, 0.7f, 0.7f,
        0.1f, 0.0f, -0.1f, 1.0f, 0.0f, 0.0f, 0.7f, 0.7f, 0.7f};
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(caseVertices), caseVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void createBed(unsigned int &VAO, unsigned int &VBO) {
    // Yatak (bed) VAO/VBO
    float bedVertices[] = {
        // Top face
        -0.5f, 0.1f, -0.5f, 0.0f, 1.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        0.5f, 0.1f, -0.5f, 0.0f, 1.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        0.5f, 0.1f, 0.5f, 0.0f, 1.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        0.5f, 0.1f, 0.5f, 0.0f, 1.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        -0.5f, 0.1f, 0.5f, 0.0f, 1.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        -0.5f, 0.1f, -0.5f, 0.0f, 1.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        // Bottom face
        -0.5f, 0.0f, -0.5f, 0.0f, -1.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        0.5f, 0.0f, -0.5f, 0.0f, -1.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        0.5f, 0.0f, 0.5f, 0.0f, -1.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        0.5f, 0.0f, 0.5f, 0.0f, -1.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        -0.5f, 0.0f, 0.5f, 0.0f, -1.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        -0.5f, 0.0f, -0.5f, 0.0f, -1.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        // Front face
        -0.5f, 0.0f, 0.5f, 0.0f, 0.0f, 1.0f, 0.8f, 0.8f, 0.8f,
        0.5f, 0.0f, 0.5f, 0.0f, 0.0f, 1.0f, 0.8f, 0.8f, 0.8f,
        0.5f, 0.1f, 0.5f, 0.0f, 0.0f, 1.0f, 0.8f, 0.8f, 0.8f,
        0.5f, 0.1f, 0.5f, 0.0f, 0.0f, 1.0f, 0.8f, 0.8f, 0.8f,
        -0.5f, 0.1f, 0.5f, 0.0f, 0.0f, 1.0f, 0.8f, 0.8f, 0.8f,
        -0.5f, 0.0f, 0.5f, 0.0f, 0.0f, 1.0f, 0.8f, 0.8f, 0.8f,
        // Back face
        -0.5f, 0.0f, -0.5f, 0.0f, 0.0f, -1.0f, 0.8f, 0.8f, 0.8f,
        0.5f, 0.0f, -0.5f, 0.0f, 0.0f, -1.0f, 0.8f, 0.8f, 0.8f,
        0.5f, 0.1f, -0.5f, 0.0f, 0.0f, -1.0f, 0.8f, 0.8f, 0.8f,
        0.5f, 0.1f, -0.5f, 0.0f, 0.0f, -1.0f, 0.8f, 0.8f, 0.8f,
        -0.5f, 0.1f, -0.5f, 0.0f, 0.0f, -1.0f, 0.8f, 0.8f, 0.8f,
        -0.5f, 0.0f, -0.5f, 0.0f, 0.0f, -1.0f, 0.8f, 0.8f, 0.8f,
        // Left face
        -0.5f, 0.0f, -0.5f, -1.0f, 0.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        -0.5f, 0.0f, 0.5f, -1.0f, 0.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        -0.5f, 0.1f, 0.5f, -1.0f, 0.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        -0.5f, 0.1f, 0.5f, -1.0f, 0.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        -0.5f, 0.1f, -0.5f, -1.0f, 0.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        -0.5f, 0.0f, -0.5f, -1.0f, 0.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        // Right face
        0.5f, 0.0f, -0.5f, 1.0f, 0.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        0.5f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        0.5f, 0.1f, 0.5f, 1.0f, 0.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        0.5f, 0.1f, 0.5f, 1.0f, 0.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        0.5f, 0.1f, -0.5f, 1.0f, 0.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        0.5f, 0.0f, -0.5f, 1.0f, 0.0f, 0.0f, 0.8f, 0.8f, 0.8f};
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(bedVertices), bedVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void createSheet(unsigned int &VAO, unsigned int &VBO) {
    float sheetVertices[] = {
        // Tek yüzey (üst) - 6 vertex
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.8f, 0.0f, 0.0f,
        0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.8f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.8f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.8f, 0.0f, 0.0f,
        -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.8f, 0.0f, 0.0f,
        -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.8f, 0.0f, 0.0f};
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(sheetVertices), sheetVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void createPyramid(unsigned int &VAO, unsigned int &VBO) {
    // Piramit için vertex verileri
    float pyramidVertices[] = {
        // Taban (2 üçgen)
        2.5f, -1.0f, -1.0f,  0.0f, -1.0f, 0.0f,  0.7f, 0.4f, 0.2f,
        1.5f, -1.0f, -1.0f,  0.0f, -1.0f, 0.0f,  0.7f, 0.4f, 0.2f,
        1.5f, -1.0f, 0.0f,   0.0f, -1.0f, 0.0f,  0.7f, 0.4f, 0.2f,
        
        2.5f, -1.0f, -1.0f,  0.0f, -1.0f, 0.0f,  0.7f, 0.4f, 0.2f,
        1.5f, -1.0f, 0.0f,   0.0f, -1.0f, 0.0f,  0.7f, 0.4f, 0.2f,
        2.5f, -1.0f, 0.0f,   0.0f, -1.0f, 0.0f,  0.7f, 0.4f, 0.2f,
        
        // Ön yüz
        2.0f, 0.5f, -0.5f,   0.0f, 0.5f, 1.0f,   0.8f, 0.5f, 0.3f,
        2.5f, -1.0f, 0.0f,   0.0f, 0.5f, 1.0f,   0.8f, 0.5f, 0.3f,
        1.5f, -1.0f, 0.0f,   0.0f, 0.5f, 1.0f,   0.8f, 0.5f, 0.3f,
        
        // Sağ yüz
        2.0f, 0.5f, -0.5f,   1.0f, 0.5f, 0.0f,   0.7f, 0.4f, 0.2f,
        2.5f, -1.0f, -1.0f,  1.0f, 0.5f, 0.0f,   0.7f, 0.4f, 0.2f,
        2.5f, -1.0f, 0.0f,   1.0f, 0.5f, 0.0f,   0.7f, 0.4f, 0.2f,
        
        // Sol yüz
        2.0f, 0.5f, -0.5f,   -1.0f, 0.5f, 0.0f,  0.8f, 0.5f, 0.3f,
        1.5f, -1.0f, 0.0f,   -1.0f, 0.5f, 0.0f,  0.8f, 0.5f, 0.3f,
        1.5f, -1.0f, -1.0f,  -1.0f, 0.5f, 0.0f,  0.8f, 0.5f, 0.3f,
        
        // Arka yüz
        2.0f, 0.5f, -0.5f,   0.0f, 0.5f, -1.0f,  0.7f, 0.4f, 0.2f,
        1.5f, -1.0f, -1.0f,  0.0f, 0.5f, -1.0f,  0.7f, 0.4f, 0.2f,
        2.5f, -1.0f, -1.0f,  0.0f, 0.5f, -1.0f,  0.7f, 0.4f, 0.2f
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(pyramidVertices), pyramidVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void createFloor(unsigned int &VAO, unsigned int &VBO) {
    // Oda tabanı (floor)
    float floorVertices[] = {
        -2.5f, -1.0f, -1.5f, 0.0f, 1.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        3.0f, -1.0f, -1.5f, 0.0f, 1.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        3.0f, -1.0f, 5.0f, 0.0f, 1.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        3.0f, -1.0f, 5.0f, 0.0f, 1.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        -2.5f, -1.0f, 5.0f, 0.0f, 1.0f, 0.0f, 0.8f, 0.8f, 0.8f,
        -2.5f, -1.0f, -1.5f, 0.0f, 1.0f, 0.0f, 0.8f, 0.8f, 0.8f};
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(floorVertices), floorVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void createLeftWall(unsigned int &VAO, unsigned int &VBO) {
    // Sol duvar (left wall)
    float leftWallVertices[] = {
        -2.5f, -1.0f, -1.5f, 1.0f, 0.0f, 0.0f, 0.6f, 0.3f, 0.1f, // Arka duvar hizasına çekildi
        -2.5f, 5.0f, -1.5f, 1.0f, 0.0f, 0.0f, 0.6f, 0.3f, 0.1f, // Arka duvar hizasına çekildi
        -2.5f, 5.0f, 5.0f, 1.0f, 0.0f, 0.0f, 0.6f, 0.3f, 0.1f,
        -2.5f, 5.0f, 5.0f, 1.0f, 0.0f, 0.0f, 0.6f, 0.3f, 0.1f,
        -2.5f, -1.0f, 5.0f, 1.0f, 0.0f, 0.0f, 0.6f, 0.3f, 0.1f,
        -2.5f, -1.0f, -1.5f, 1.0f, 0.0f, 0.0f, 0.6f, 0.3f, 0.1f  // Arka duvar hizasına çekildi
    };
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(leftWallVertices), leftWallVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void createRightWall(unsigned int &VAO, unsigned int &VBO) {
     // Sağ duvar (right wall)
    float rightWallVertices[] = {
        3.0f, -1.0f, -1.5f, -1.0f, 0.0f, 0.0f, 0.6f, 0.3f, 0.1f, // Arka duvar hizasına çekildi
        3.0f, 5.0f, -1.5f, -1.0f, 0.0f, 0.0f, 0.6f, 0.3f, 0.1f, // Arka duvar hizasına çekildi
        3.0f, 5.0f, 5.0f, -1.0f, 0.0f, 0.0f, 0.6f, 0.3f, 0.1f,
        3.0f, 5.0f, 5.0f, -1.0f, 0.0f, 0.0f, 0.6f, 0.3f, 0.1f,
        3.0f, -1.0f, 5.0f, -1.0f, 0.0f, 0.0f, 0.6f, 0.3f, 0.1f,
        3.0f, -1.0f, -1.5f, -1.0f, 0.0f, 0.0f, 0.6f, 0.3f, 0.1f  // Arka duvar hizasına çekildi
    };
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(rightWallVertices), rightWallVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void createBackWall(unsigned int &VAO, unsigned int &VBO) {
    // Arka duvar (back wall)
    float backWallVertices[] = {
        -2.5f, -1.0f, -1.5f, 0.0f, 0.0f, 1.0f, 0.6f, 0.3f, 0.1f,
        3.0f, -1.0f, -1.5f, 0.0f, 0.0f, 1.0f, 0.6f, 0.3f, 0.1f,
        3.0f, 5.0f, -1.5f, 0.0f, 0.0f, 1.0f, 0.6f, 0.3f, 0.1f,
        3.0f, 5.0f, -1.5f, 0.0f, 0.0f, 1.0f, 0.6f, 0.3f, 0.1f,
        -2.5f, 5.0f, -1.5f, 0.0f, 0.0f, 1.0f, 0.6f, 0.3f, 0.1f,
        -2.5f, -1.0f, -1.5f, 0.0f, 0.0f, 1.0f, 0.6f, 0.3f, 0.1f};
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(backWallVertices), backWallVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void createLamp(unsigned int &VAO, unsigned int &VBO) {
    // Ampul modeli için vertex verileri
    float lampVertices[] = {
        // Taban çemberi (8 nokta kullanarak yaklaşık bir çember)
        // positions               // normals             // colors
        0.0f, 0.0f, 0.0f,        0.0f, -1.0f, 0.0f,    1.0f, 1.0f, 0.8f,  // Merkez
        0.1f, 0.0f, 0.0f,        0.0f, -1.0f, 0.0f,    1.0f, 1.0f, 0.8f,
        0.07f, 0.0f, 0.07f,      0.0f, -1.0f, 0.0f,    1.0f, 1.0f, 0.8f,
        0.0f, 0.0f, 0.1f,        0.0f, -1.0f, 0.0f,    1.0f, 1.0f, 0.8f,
        -0.07f, 0.0f, 0.07f,     0.0f, -1.0f, 0.0f,    1.0f, 1.0f, 0.8f,
        -0.1f, 0.0f, 0.0f,       0.0f, -1.0f, 0.0f,    1.0f, 1.0f, 0.8f,
        -0.07f, 0.0f, -0.07f,    0.0f, -1.0f, 0.0f,    1.0f, 1.0f, 0.8f,
        0.0f, 0.0f, -0.1f,       0.0f, -1.0f, 0.0f,    1.0f, 1.0f, 0.8f,
        0.07f, 0.0f, -0.07f,     0.0f, -1.0f, 0.0f,    1.0f, 1.0f, 0.8f,
        0.1f, 0.0f, 0.0f,        0.0f, -1.0f, 0.0f,    1.0f, 1.0f, 0.8f,  // Çemberi kapatmak için tekrar
        
        // Koni yüzeyi
        0.0f, 0.2f, 0.0f,        0.0f, 1.0f, 0.0f,     1.0f, 1.0f, 0.8f,  // Tepe nokta
        0.1f, 0.0f, 0.0f,        0.5f, 0.5f, 0.0f,     1.0f, 1.0f, 0.8f,
        0.07f, 0.0f, 0.07f,      0.35f, 0.5f, 0.35f,   1.0f, 1.0f, 0.8f,
        0.0f, 0.0f, 0.1f,        0.0f, 0.5f, 0.5f,     1.0f, 1.0f, 0.8f,
        -0.07f, 0.0f, 0.07f,     -0.35f, 0.5f, 0.35f,  1.0f, 1.0f, 0.8f,
        -0.1f, 0.0f, 0.0f,       -0.5f, 0.5f, 0.0f,    1.0f, 1.0f, 0.8f,
        -0.07f, 0.0f, -0.07f,    -0.35f, 0.5f, -0.35f, 1.0f, 1.0f, 0.8f,
        0.0f, 0.0f, -0.1f,       0.0f, 0.5f, -0.5f,    1.0f, 1.0f, 0.8f,
        0.07f, 0.0f, -0.07f,     0.35f, 0.5f, -0.35f,  1.0f, 1.0f, 0.8f,
        0.1f, 0.0f, 0.0f,        0.5f, 0.5f, 0.0f,     1.0f, 1.0f, 0.8f,  // Çemberi kapatmak için tekrar
    
        // Metal kısım (silindir üst yüzeyi)
        0.02f, 0.2f, 0.02f,      0.0f, 1.0f, 0.0f,     0.7f, 0.7f, 0.7f,
        -0.02f, 0.2f, 0.02f,     0.0f, 1.0f, 0.0f,     0.7f, 0.7f, 0.7f,
        -0.02f, 0.2f, -0.02f,    0.0f, 1.0f, 0.0f,     0.7f, 0.7f, 0.7f,
        0.02f, 0.2f, -0.02f,     0.0f, 1.0f, 0.0f,     0.7f, 0.7f, 0.7f,
        0.02f, 0.3f, 0.02f,      0.0f, 1.0f, 0.0f,     0.7f, 0.7f, 0.7f,
        -0.02f, 0.3f, 0.02f,     0.0f, 1.0f, 0.0f,     0.7f, 0.7f, 0.7f
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(lampVertices), lampVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
} 