#include <Adafruit_TCS34725.h>
#define TCS_I2C_ADDR 0x29

Adafruit_TCS34725 tcs = Adafruit_TCS34725(
                          TCS34725_INTEGRATIONTIME_50MS, 
                          TCS34725_GAIN_4X);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  tcs.begin(TCS_I2C_ADDR);
}

void loop() {
  float r, g, b;
  tcs.getRGB(&r, &g, &b);
  Serial.print("r:");
  Serial.print(r);
  Serial.print(",g:");
  Serial.print(g);
  Serial.print(",b:");
  Serial.print(b);
  Serial.println();
  delay(1000);
}
