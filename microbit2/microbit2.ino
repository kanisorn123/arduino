#define ANALOG_PIN 1
#define LED 0
int v = 0;
int a = 0;
int btn_prev;

void setup() {
  pinMode(ANALOG_PIN, INPUT);
  Serial.begin(115200);
}

void loop() {
  a = analogRead(ANALOG_PIN);
  Serial.println(a);
  check();
  delay(100);
}

void check() {
  if (a > 0 && a < 200) {
    analogWrite(LED, 0);
  } else if (a > 200 && a < 400) {
    analogWrite(LED, 50);
  } else if (a > 400 && a < 800) {
    analogWrite(LED, 113);
  } else if (a > 800 && a < 1023) {
    analogWrite(LED, 1017);
  }
}