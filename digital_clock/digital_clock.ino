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
int time = 60;
int f;
int d;
void setup() {
  Serial.begin(115200);
  tft.initR(INITR_MINI160x80);
  tft.setRotation(3);  // 0=default, 3=pin up
  tft.fillScreen(ST77XX_BLACK);
}

void loop() {
   
  f = time / 10;
  d = time % 10;
  if (f == 0) {
  }
  if (f == 1) {
    one(0,ST77XX_GREEN);
  }
  if (f == 2) {
    two(0,ST77XX_GREEN);
  }
  if (f == 3) {
    tree(0,ST77XX_GREEN);
  }
  if (f == 4) {
    four(0,ST77XX_GREEN);
  }
  if (f == 5) {
    five(0,ST77XX_GREEN);
  }
  if (f == 6) {
    six(0,ST77XX_GREEN);
  }
  if (f == 7) {
    seven(0,ST77XX_GREEN);
  }
  if (f == 8) {
    e(0,ST77XX_GREEN);
  }
  if (f == 9) {
    n(0,ST77XX_GREEN);
  }
  if (d == 0) {
    o(ST77XX_GREEN);
  }
  if (d == 1) {
    one(1,ST77XX_GREEN);
  }
  if (d == 2) {
    two(1,ST77XX_GREEN);
  }
  if (d == 3) {
    tree(1,ST77XX_GREEN);
  }
  if (d == 4) {
    four(1,ST77XX_GREEN);
  }
  if (d == 5) {
    five(1,ST77XX_GREEN);
  }
  if (d == 6) {
    six(1,ST77XX_GREEN);
  }
  if (d == 7) {
    seven(1,ST77XX_GREEN);
  }
  if (d == 8) {
    e(1,ST77XX_GREEN);
  }
  if (d == 9) {
    n(1,ST77XX_GREEN);
  }
  time = time-1;
  delay(1000);
  if (f == 0) {
  }
  if (f == 1) {
    one(0,ST77XX_BLACK);
  }
  if (f == 2) {
    two(0,ST77XX_BLACK);
  }
  if (f == 3) {
    tree(0,ST77XX_BLACK);
  }
  if (f == 4) {
    four(0,ST77XX_BLACK);
  }
  if (f == 5) {
    five(0,ST77XX_BLACK);
  }
  if (f == 6) {
    six(0,ST77XX_BLACK);
  }
  if (f == 7) {
    seven(0,ST77XX_BLACK);
  }
  if (f == 8) {
    e(0,ST77XX_BLACK);
  }
  if (f == 9) {
    n(0,ST77XX_BLACK);
  }
  if (d == 0) {
    o(ST77XX_BLACK);
  }
  if (d == 1) {
    one(1,ST77XX_BLACK);
  }
  if (d == 2) {
    two(1,ST77XX_BLACK);}
  if (d == 3) {
    tree(1,ST77XX_BLACK);
  }
  if (d == 4) {
    four(1,ST77XX_BLACK);
  }
  if (d == 5) {
    five(1,ST77XX_BLACK);
  }
  if (d == 6) {
    six(1,ST77XX_BLACK);
  }
  if (d == 7) {
    seven(1,ST77XX_BLACK);
  }
  if (d == 8) {
    e(1,ST77XX_BLACK);
  }
  if (d == 9) {
    n(1,ST77XX_BLACK);
  }
}

void o(int c) {
  tft.drawRect(95, 0, 50, 75, c);
}

void one(int p,int c) {
  int dx;
  if (p == 0) {
    dx = 0;
  }
  if (p == 1) {
    dx = 100;
  }
  tft.drawLine(dx + 20, 0, dx + 20, 75, c);
}
void two(int q,int c) {
  int dx;
  if (q == 0) {
    dx = 0;
  }
  if (q == 1) {
    dx = 100;
  }
  tft.drawLine(dx + 10, 0, dx + 50, 0, c);
  tft.drawLine(dx + 50, 0, dx + 50, 30, c);
  tft.drawLine(dx + 50, 30, dx + 10, 30, c);
  tft.drawLine(dx + 10, 30, dx + 10, 60, c);
  tft.drawLine(dx + 10, 60, dx + 50, 60, c);
}
void tree(int w,int c) {
  int dx;
  if (w == 0) {
    dx = 0;
  }
  if (w == 1) {
    dx = 100;
  }
  tft.drawLine(dx + 10, 0, dx + 50, 0, c);
  tft.drawLine(dx + 50, 0, dx + 50, 30, c);
  tft.drawLine(dx + 50, 30, dx + 10, 30, c);
  tft.drawLine(dx + 50, 30, dx + 50, 60, c);
  tft.drawLine(dx + 10, 60, dx + 50, 60, c);
}
void four(int e,int c) {
  int dx;
  if (e == 0) {
    dx = 0;
  }
  if (e == 1) {
    dx = 100;
  }
  tft.drawLine(dx + 10, 0, dx + 10, 40, c);
  tft.drawLine(dx + 10, 40, dx + 50, 40, c);
  tft.drawLine(dx + 50, 0, dx + 50, 90, c);
}
void five(int r,int c) {
  int dx;
  if (r == 0) {
    dx = 0;
  }
  if (r == 1) {
    dx = 100;
  }
  tft.drawLine(dx + 50, 0, dx + 10, 0, c);
  tft.drawLine(dx + 10, 0, dx + 10, 30, c);
  tft.drawLine(dx + 10, 30, dx + 50, 30, c);
  tft.drawLine(dx + 50, 30, dx + 50, 60, c);
  tft.drawLine(dx + 50, 60, dx + 10, 60, c);
}
void six(int t,int c) {
  int dx;
  if (t == 0) {
    dx = 0;
  }
  if (t == 1) {
    dx = 100;
  }
  tft.drawLine(dx + 50, 5, dx + 10, 5, c);
  tft.drawLine(dx + 10, 5, dx + 10, 70, c);
  tft.drawLine(dx + 10, 70, dx + 50, 70, c);
  tft.drawLine(dx + 50, 70, dx + 50, 40, c);
  tft.drawLine(dx + 50, 40, dx + 10, 40, c);
}
void seven(int y,int c) {
  int dx;
  if (y == 0) {
    dx = 0;
  }
  if (y == 1) {
    dx = 100;
  }
  tft.drawLine(dx + 10, 5, dx + 50, 5, c);
  tft.drawLine(dx + 50, 5, dx + 50, 70, c);
}
void e(int u,int c) {
  int dx;
  if (u == 0) {
    dx = 0;
  }
  if (u == 1) {
    dx = 100;
  }
  tft.drawLine(dx + 50, 5, dx + 10, 5, c);
  tft.drawLine(dx + 10, 5, dx + 10, 70, c);
  tft.drawLine(dx + 10, 70, dx + 50, 70, c);
  tft.drawLine(dx + 50, 70, dx + 50, 35, c);
  tft.drawLine(dx + 50, 35, dx + 10, 35, c);
  tft.drawLine(dx + 50, 70, dx + 50, 5, c);
}

void n(int i,int c) {
  int dx;
  if (i == 0) {
    dx = 0;
  }
  if (i == 1) {
    dx = 100;
  }
  tft.drawLine(dx + 10, 5, dx + 50, 5, c);
  tft.drawLine(dx + 50, 5, dx + 50, 70, c);
  tft.drawLine(dx + 50, 35, dx + 10, 35, c);
  tft.drawLine(dx + 10, 35, dx + 10, 5, c);
  tft.drawLine(dx + 50, 70, dx + 10, 70, c);
}