#include <Adafruit_GFX.h>
//#include "Adafruit_GC9A01A.h"
#include <Adafruit_GC9A01A.h>

// Определяем пины для Arduino Due
#define TFT_CS   10
#define TFT_DC   8
#define TFT_RST  9

// Инициализация дисплея
Adafruit_GC9A01A tft(TFT_CS, TFT_DC, TFT_RST);

void setup() 
{
  Serial.begin(115200);
  Serial.println("GC9A01 Test begin!");
  
  // Инициализация дисплея
  tft.begin();
  
  Serial.println("Display GC9A01 installed");
  
  // Поворот дисплея (0, 1, 2, 3)
  int iRotation = 2;
  Serial.println("Display GC9A01 rotation:" + String(iRotation));
  tft.setRotation(iRotation);
  
  // Заполняем экран черным
  tft.fillScreen(GC9A01A_BLACK);
  delay(500);
  
  // Тест графики и текста
  testDrawShapes();
  testText();
}

void loop() {
  // Анимация меняющихся кругов
  for (int i = 0; i < 240; i += 10) {
    tft.fillCircle(i, 120, 20, random(0xFFFF));
    delay(50);
  }
  
  tft.fillScreen(GC9A01A_BLACK);
  delay(500);
}

void testDrawShapes() {
  // Рисуем прямоугольник
  tft.drawRect(10, 10, 100, 50, GC9A01A_RED);
  
  // Заливаем прямоугольник
  tft.fillRect(120, 10, 100, 50, GC9A01A_BLUE);
  
  // Рисуем круг
  tft.drawCircle(60, 120, 30, GC9A01A_GREEN);
  
  // Заливаем круг
  tft.fillCircle(180, 120, 30, GC9A01A_YELLOW);
  
  // Рисуем треугольник
  tft.drawTriangle(30, 180, 60, 220, 90, 180, GC9A01A_CYAN);
  
  delay(2000);
  tft.fillScreen(GC9A01A_BLACK);
}

void testText() {
  tft.setCursor(0, 0);
  
  // Разный размер текста
  tft.setTextColor(GC9A01A_WHITE);
  tft.setTextSize(1);
  tft.println("Размер 1: Arduino Due");
  
  tft.setTextColor(GC9A01A_GREEN);
  tft.setTextSize(2);
  tft.println("Размер 2: GC9A01");
  
  tft.setTextColor(GC9A01A_RED);
  tft.setTextSize(3);
  tft.println("Размер 3: 240x240");
  
  tft.setTextColor(GC9A01A_BLUE);
  tft.setTextSize(4);
  tft.println("SPI");
  
  delay(3000);
  tft.fillScreen(GC9A01A_BLACK);
  
  // Вывод различных данных
  tft.setTextSize(2);
  tft.setTextColor(GC9A01A_WHITE);
  tft.setCursor(0, 0);
  
  tft.print("Voltage: ");
  tft.println(3.3, 1);
  
  tft.print("Time: ");
  tft.println(millis());
  
  delay(2000);
}