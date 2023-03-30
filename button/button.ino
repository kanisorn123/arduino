#define BTN_PIN 22
#define LED_PIN 15
int btn_prev;
int v = 0;
void setup() {
  pinMode(BTN_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
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

void check(){
  if (v == 1){
    digitalWrite(LED_PIN, LOW);
    v = 0;
  }
  else if (v == 0){
    digitalWrite(LED_PIN, HIGH);
    v = 1;
  }
}
