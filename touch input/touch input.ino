#include <analogWrite.h>
#define TOUCH_PIN 13
#define LED_PIN 19

int a = 0;
int touch_pin;
int v = 0;
void setup()
{
  Serial.begin(115200);
  delay(1000);
  Serial.println("ESP32 Touch Test");
}

void loop() {
  a = touchRead(TOUCH_PIN);
  Serial.println(a);
  if (a < 50) {
    check();
  }
  touch_pin = a;
  delay(1000);
}

void check(){
  if (v == 0){
    analogWrite(LED_PIN, 0);
    v = 1;
  }
  else if (v == 1){
    analogWrite(LED_PIN, 113);
    v = 2;
  }else if (v == 2){
    analogWrite(LED_PIN, 350);
    v = 3;
  }
  else if (v == 3){
    analogWrite(LED_PIN, 1017);
    v = 0;
  }
}
