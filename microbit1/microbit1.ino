#define ANALOG_PIN 0
#define BTN_PIN 1
int v = 0;
int btn_prev;

void setup() {
  pinMode(BTN_PIN, INPUT_PULLUP);
  btn_prev = digitalRead(BTN_PIN);
  Serial.begin(115200);
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

void check() {
  if (v == 1) {
    analogWrite(ANALOG_PIN, 0);
    v = 2;
  } else if (v == 2) {
    analogWrite(ANALOG_PIN, 50);
    v = 3;
  } else if (v == 3) {
    analogWrite(ANALOG_PIN, 113);
    v = 0;
  } else if (v == 0) {
    analogWrite(ANALOG_PIN, 1017);
    v = 1;
  }
  Serial.println(v);
}