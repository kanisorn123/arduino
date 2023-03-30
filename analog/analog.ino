#include <analogWrite.h>
#define ANALOG_PIN 13
#define BTN_PIN 15
int v = 0;
int btn_prev; 

void setup() {
    analogWriteResolution(ANALOG_PIN, 10);
    pinMode(BTN_PIN, INPUT_PULLUP);
}

void loop() {
   int a = digitalRead(BTN_PIN);
  Serial.println(a);

  if (a == LOW && btn_prev == HIGH) {
    check();
  }
  btn_prev = a;
  delay(100);
}

void check(){
  if (v == 0){
    analogWrite(ANALOG_PIN, 0);
    v = 1;
  }
  else if (v == 1){
    analogWrite(ANALOG_PIN, 113);
    v = 2;
  }else if (v == 2){
    analogWrite(ANALOG_PIN, 113);
    v = 2;
  }
  else if (v == 3){
    analogWrite(ANALOG_PIN, 1017);
    v = 0;
  }
}
