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
int t = 60;
void setup() {
  Serial.begin(115200);
  Serial.print("");
  tft.initR(INITR_MINI160x80);
  tft.setRotation(3);
  tft.fillScreen(ST77XX_BLACK);
  tft.println("hello");  // Init ST7735S mini display 80x160
}

void loop() {
  tft.setCursor(0, 30);
  tft.setTextColor(ST77XX_RED);
  tft.setTextSize(2);
  tft.println(t);
  t = t - 1;
  delay(1000);
  tft.fillRect(0,20,25,25,ST77XX_BLACK);

}