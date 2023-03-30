#include <Servo.h>

#define SERVO_PIN 17

Servo servo1;

void setup() {
  Serial.begin(115200);
  servo1.attach(SERVO_PIN);
  servo1.write(45);
  delay(1000);
  servo1.write(135);
}

void loop() {
  //for (int angle = 45; angle <= 135; angle++) {
    //servo1.write(angle);
   // Serial.println(angle);
   // delay(100);
  //}

  //for (int angle = 135; angle >= 45; angle--) {
    //servo1.write(angle);
  //  Serial.println(angle);
   // delay(100);
 // }
}
