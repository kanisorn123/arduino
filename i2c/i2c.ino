#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
//#define I2C_SCL_PIN 32
//#define I2C_SDA_PIN 33
#define OLED_I2C_ADDR 0x3C  // 0x78 on board ==> 0x3C address.
#define OLED_RESET -1
#define analog_pin 0
int l;
int w;
int h;
int x = 0;
int max = 1000;
int min = 0;
int y;
int o;
int old[128];

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  pinMode(analog_pin, INPUT);
  Serial.begin(115200);
  for (int q = 0; q < 128; q++) {
    old[q] = 0;
  }



  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDR)) {
    Serial.println(F("SSD1306 allocation failed"));
  } else {
    //delay(1000);
    display.clearDisplay();
    //display.setTextSize(1);  // 1=smallest
    //display.setTextColor(SSD1306_WHITE);
    //display.setCursor(0, 0);
    //display.println(F("Hello\nI2C OLED."));
    //display.display();
    w = display.width();
    h = display.height();
  }
}

void loop() {
  display.clearDisplay();
  l = analogRead(analog_pin);
  Serial.println(l);
  y = 0;

  y = h - floor((l / 1000.0) * h);
  display.drawPixel(x, y, SSD1306_WHITE);
  for (int l = 127; l > 0; l--) {
    old[l] = old[l - 1];
    display.drawPixel(l, old[l], SSD1306_WHITE);
  }
  old[0] = y;
  display.drawPixel(x, old[0], SSD1306_WHITE);
  delay(10);
  display.display();
}
