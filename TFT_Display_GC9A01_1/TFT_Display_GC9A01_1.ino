/*
Программа тестирования дисплея GC9A01A
Версия 1.

*/

//=============================================================================
// Подключаемые файлы
//=============================================================================
#include <Adafruit_GFX.h>
#include <Adafruit_GC9A01A.h>

//=============================================================================
// Константы
//=============================================================================

// Определяем пины для Arduino Due
#define TFT_CS   10
#define TFT_DC   8
#define TFT_RST  9

//=============================================================================
// Глобальные переменные
//=============================================================================

// Инициализация дисплея
Adafruit_GC9A01A tft(TFT_CS, TFT_DC, TFT_RST);
int X0 = 0;
int Y0 = 0;

//=============================================================================
// Программа начальной установки
//=============================================================================
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
  //testDrawShapes();
  //testText();
  int Height = 8;
  int InitialY = 120;
  int Y = InitialY; 
  //---------------------------------Размер шрифта 1---------------------------
  //Ширина символа 6 пикселей
  //Позиция 120
  tft.setCursor(0, Y);
  
  // Разный размер текста
  tft.setTextColor(GC9A01A_GREEN);
  tft.setTextSize(1);
  tft.println("1234567890123456789012345678901234567890");//ширина строки 40 символов

  Y = Y + Height;

  //Позиция 126
  tft.setCursor(0, Y);
  tft.setTextColor(GC9A01A_WHITE);
  tft.println("1234567890123456789012345678901234567890");//ширина строки 40 символов

  Y = Y + Height;

  //Позиция 132
  tft.setCursor(0, Y);
  tft.setTextColor(GC9A01A_BLUE);
  tft.println("1234567890123456789012345678901234567890");//ширина строки 40 символов

  Y = Y + Height;

  //Позиция 132
  tft.setCursor(0, Y);
  tft.setTextColor(GC9A01A_RED);
  tft.println("1234567890123456789012345678901234567890");//ширина строки 40 символов

  
  
  




}//End of void setup()

//=============================================================================
// Главный цикл программы
//=============================================================================
void loop() 
{
/*  
  // Анимация меняющихся кругов
  for (int i = 0; i < 240; i += 10) {
    tft.fillCircle(i, 120, 20, random(0xFFFF));
    delay(50);
  }
  
  tft.fillScreen(GC9A01A_BLACK);
  delay(500);
*/  
}//End of void loop()

//=============================================================================
// Подпрограммы
//=============================================================================
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
  
  delay(20000);
  tft.fillScreen(GC9A01A_BLACK);
}

void testText() {
  tft.setCursor(X0, Y0);
  
  // Разный размер текста
  tft.setTextColor(GC9A01A_WHITE);
  tft.setTextSize(1);
  tft.println("Size 1: Arduino Due");
  
  tft.setTextColor(GC9A01A_GREEN);
  tft.setTextSize(2);
  tft.println("Size 2: GC9A01");
  
  tft.setTextColor(GC9A01A_RED);
  tft.setTextSize(3);
  tft.println("Size 3: 240x240");
  
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