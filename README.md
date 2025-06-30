# 📋 Bilgisayar Grafikleri - Vize Sonrası Proje 2

Bu proje, 3D grafik programlama teknikleri kullanılarak geliştirilmiş interaktif bir oda simülasyonudur. Sahne, yaşam alanımı temsil eden bir odayı içerir ve içerisinde masaüstü bilgisayar, monitör, yatak gibi günlük yaşam nesneleri bulunur. Projenin en önemli özelliği, sahne içerisinde hareket edebilen ve kullanıcı komutlarına yanıt verebilen 3D robot karakteridir.

## 🚀 Yeni Özellikler

### 🤖 İnteraktif Robot Sistemi

- **3D Robot Karakteri**: OBJ format ile yüklenmiş detaylı robot modeli
- **Akıllı Hareket Sistemi**: Robot masaya veya yatağa gidebilir
- **Animasyon Sistemi**: Yürüme, uyuma ve zıplama animasyonları
- **Durum Yönetimi**: Robot farklı modlarda çalışabilir (yatak, masa, serbest dolaşım)

### 🎮 Gelişmiş Kamera Sistemi

- **İki Kamera Modu**: Varsayılan ve FPS (First Person Shooter) modu
- **Fare Kontrolü**: Mouse ile 360° kamera döndürme
- **WASD Hareketi**: Klavye ile serbest kamera hareketi
- **Kamera Kilitleme**: Bakış açısı sınırlama sistemi

### 💬 Metin Rendering Sistemi

- **FreeType Entegrasyonu**: Dinamik metin görüntüleme
- **Kullanıcı Talimatları**: Ekranda interaktif yönlendirme mesajları
- **Durum Bildirimleri**: Robot durumu ve oyun modu bilgilendirmeleri

### 🎯 Oyun Mekanikleri

- **Seçim Sistemi**: Z (yatak) / X (masa) / C (serbest mod) tuş komutları
- **Zaman Limiti**: 10 saniye sonra otomatik varsayılan seçim
- **State Machine**: Karmaşık oyun durumu yönetimi
- **Collision Detection**: Robot ve nesneler arası etkileşim

### 🏠 Gelişmiş 3D Sahne

- **Detaylı Oda Modeli**: Zemin, duvarlar, tavan ile tam bir oda
- **Gerçekçi Aydınlatma**: Phong shading ile gelişmiş ışık efektleri
- **Çoklu Nesne**: Masa, sandalye, yatak, monitör, klavye, mouse, kitaplar
- **Texture Desteği**: Nesneler için görsel dokular

## 📑 Proje Raporu

Proje raporuna [BG-Rapor1.pdf](./BG-Rapor1.pdf) bağlantısından ulaşabilirsiniz.

## 🎬 Tanıtım Videosu

Tanıtım videosuna ulaşmak için [tıklayın.](https://youtu.be/fZrfbLcKuJM?si=WhfK7fwuLF3sLP3G)

## 🛠 Kullanılan Kütüphaneler (Gereklilikler)

Projenin çalışabilmesi için aşağıdaki kütüphanelerin indirilmesi zorunludur.

- **GLFW**: 3.3 veya üstü (Pencere oluşturma ve giriş işlemleri için)
- **GLEW**: 2.1.0 veya üstü (OpenGL fonksiyonlarının yüklenmesi için)
- **GLM**: 0.9.9.8 veya üstü (Matematiksel işlemler, matris ve vektör hesaplamaları için)
- **OpenGL**: 3.3 veya üstü (Grafik API'si)
- **GLSL** (OpenGL Shading Language): 3.30 (Shader programlama için)
- **FreeType**: Font rendering için dinamik metin gösterimi
- **TinyObjLoader**: OBJ 3D model dosyalarını yüklemek için

## ✅ Uygulamayı Çalıştırma Adımları

1. Proje dosyalarını indirin veya klonlayın:
   ```bash
   git clone https://github.com/alakkaya/BilgisayarGrafikleriProje1.git
   cd BilgisayarGrafikleriProje1
   ```
2. Gerekli kütühaneleri yükleyin (GLFW, GLEW)
3. Projeyi derlemek için herhangi hata çıkmaması için aşağıdaki kodu terminale yapıştırın.
   ```bash
   clang++ -std=c++17 -fdiagnostics-color=always -Wall -g \
   -I./dependencies/include \
   -I/opt/homebrew/opt/freetype/include \
   -I/opt/homebrew/opt/freetype/include/freetype2 \
   -L./dependencies/library \
   -L/opt/homebrew/opt/freetype/lib \
   ./dependencies/library/libglfw.3.4.dylib \
   ./dependencies/library/libGLEW.2.2.0.dylib \
   -lfreetype \
   ./main.cpp ./glad.c ./Geometry.cpp ./Shader.cpp \
   -o app \
   -framework OpenGL \
   -framework Cocoa \
   -framework IOKit \
   -framework CoreVideo \
   -framework CoreFoundation \
   -Wno-deprecated
   ```
4. Çalıştırmak için terminale aşağıdaki komutu yazın.
   ```bash
     ./app
   ```

## 🕹️ Kullanım

### Kamera Kontrolleri

- `W/A/S/D` ile kamera hareketi
- `Mouse` ile özgürce kameranızı döndürebilirsiniz
- `1` Default kamera modu
- `2` FPS (First Person Shooter) kamera modu

### Robot Kontrolleri

- `Z` Robot yatağa git
- `X` Robot masaya git
- `C` Serbest dolaşım modu
- `Yön Tuşları` Robot hareketi (Serbest dolaşım modunayken)
- `R` Sahneyi sıfırla

### Özel Özellikler

- Robot otomatik olarak hedef noktasına yürür
- Yürüme animasyonları ile gerçekçi hareket
- Ekranda dinamik metin yönergeleri
- 10 saniyeli otomatik seçim sistemi

## 🖼️ Görseller

<table>
        <tr>
            <th>Ön Görünüm</th>
        </tr>
        <tr>
            <td><img src="https://github.com/user-attachments/assets/25e64573-b54b-40c7-b090-8d9a3a3fc313" ></td>
        </tr>
        <tr>
            <th>Üst Görünüm</th>
        </tr>
        <tr>
            <td><img src="https://github.com/user-attachments/assets/a4a89f6a-ff82-4a27-a920-c3989cd9a5df" ></td>
        </tr>
        <tr>
            <th>Çapraz Görünüm</th>
        </tr>
        <tr>
            <td><img src="https://github.com/user-attachments/assets/95858b77-0486-480f-b6b9-bad82a717d57" ></td>
        </tr>
    </table>
