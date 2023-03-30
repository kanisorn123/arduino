#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#define TFT_CS 1
#define TFT_DC 2
#define TFT_RST 12
#define TFT_MOSI 15  // Data out (VSPI)
#define TFT_SCLK 13
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
void setup() {
  Serial.begin(115200);
  tft.initR(INITR_MINI160x80);
  tft.setRotation(3);  // 0=default, 3=pin up
  tft.fillScreen(ST77XX_BLACK);
}

void loop() {
  six(0);
  delay(1000);
}

void o() {
  tft.drawRect(95, 0, 50, 75, ST77XX_GREEN);
}

void one(int p) {
  if (p == 0) {
    tft.drawLine(20, 0, 20, 75, ST77XX_GREEN);
  }
  if (p == 1) {
    tft.drawLine(120, 0, 120, 75, ST77XX_GREEN);
  }
}
void two(int q) {
  if (q == 0) {
    tft.drawLine(10, 0, 50, 0, ST77XX_GREEN);
    tft.drawLine(50, 0, 50, 30, ST77XX_GREEN);
    tft.drawLine(50, 30, 10, 30, ST77XX_GREEN);
    tft.drawLine(10, 30, 10, 60, ST77XX_GREEN);
    tft.drawLine(10, 60, 50, 60, ST77XX_GREEN);
  }
  if (q == 1) {
    tft.drawLine(100, 0, 150, 0, ST77XX_GREEN);
    tft.drawLine(150, 0, 150, 30, ST77XX_GREEN);
    tft.drawLine(150, 30, 100, 30, ST77XX_GREEN);
    tft.drawLine(100, 30, 100, 60, ST77XX_GREEN);
    tft.drawLine(100, 60, 150, 60, ST77XX_GREEN);
  }
}
void tree(int w) {
  if (w == 0) {
    tft.drawLine(10, 0, 50, 0, ST77XX_GREEN);
    tft.drawLine(50, 0, 50, 30, ST77XX_GREEN);
    tft.drawLine(50, 30, 10, 30, ST77XX_GREEN);
    tft.drawLine(50, 30, 50, 60, ST77XX_GREEN);
    tft.drawLine(10, 60, 50, 60, ST77XX_GREEN);
  }
  if (w == 1) {
    tft.drawLine(100, 0, 150, 0, ST77XX_GREEN);
    tft.drawLine(150, 0, 150, 30, ST77XX_GREEN);
    tft.drawLine(150, 30, 100, 30, ST77XX_GREEN);
    tft.drawLine(150, 30, 150, 60, ST77XX_GREEN);
    tft.drawLine(100, 60, 150, 60, ST77XX_GREEN);
  }
}
void four(int e) {
  if (e == 0) {
    tft.drawLine(10, 0, 10, 40, ST77XX_GREEN);
    tft.drawLine(10, 40, 50, 40, ST77XX_GREEN);
    tft.drawLine(50, 0, 50, 90, ST77XX_GREEN);
  }
  if (e == 1) {
    tft.drawLine(100, 0, 100, 40, ST77XX_GREEN);
    tft.drawLine(100, 40, 150, 40, ST77XX_GREEN);
    tft.drawLine(150, 0, 150, 90, ST77XX_GREEN);
  }
}
void five(int r){
    if (r == 0){
     tft.drawLine(50, 0, 10, 0, ST77XX_GREEN);
    tft.drawLine(10, 0, 10, 30, ST77XX_GREEN);
    tft.drawLine(10, 30, 50, 30, ST77XX_GREEN);
    tft.drawLine(50, 30, 50, 60, ST77XX_GREEN);
    tft.drawLine(50, 60, 10, 60, ST77XX_GREEN);
  }
  if (r == 1){
     tft.drawLine(150, 0, 100, 0, ST77XX_GREEN);
    tft.drawLine(100, 0, 100, 30, ST77XX_GREEN);
    tft.drawLine(100, 30, 150, 30, ST77XX_GREEN);
    tft.drawLine(150, 30, 150, 60, ST77XX_GREEN);
    tft.drawLine(150, 60, 100, 60, ST77XX_GREEN);
  }
}
void six(int t){
  if(six == 0){
    tft.drawLine(50, 0, 10, 0, ST77XX_GREEN);
    tft.drawLine(10, 0, 10, 60, ST77XX_GREEN);

  }
}