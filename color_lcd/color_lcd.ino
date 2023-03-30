#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include "color_hack.h"
#include <Adafruit_TCS34725.h>
#define TCS_I2C_ADDR 0x29
#define TFT_CS 1
#define TFT_DC 2
#define TFT_RST 12
#define TFT_MOSI 15  // Data out (VSPI)
#define TFT_SCLK 13  // Clock out (VSPI)
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS,TCS34725_GAIN_4X);

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup(void) {
  Serial.begin(115200);
  Serial.print("Hello! ST77xx TFT Test...");
  tft.initR(INITR_MINI160x80);  // Init ST7735S mini display 80x160
  Serial.println("Initialized");
  tft.setRotation(3);  // 0=default, 3=pin up
  Serial.begin(115200);
  Wire.begin();
  tcs.begin(TCS_I2C_ADDR);


  uint16_t time = millis();
  tft.fillScreen(ST77XX_BLACK);
  time = millis() - time;
  Serial.print("fillScreen time=");
  Serial.print(time, DEC);
  Serial.println("ms.");
  delay(1000);
}
void loop() {
  testdrawrects();
  
  delay(10);

}

void testdrawrects() {
  float r, g, b;
  tcs.getRGB(&r, &g, &b);
  int rr = ceil(r);
  int gg = ceil(g);
  int bb = ceil(b);
  int c = color565_mod(rr,gg,bb);
  Serial.print("r:");
  Serial.print(rr);
  Serial.print(",g:");
  Serial.print(gg);
  Serial.print(",b:");
  Serial.print(bb);
  Serial.println();
  tft.fillRect(60,20,50,70,c);
}
