#define BTN_PIN 35
#define RED_PIN 19
#define YELLOW_PIN 23
#define GREEN_PIN 22


int wait;
int wait1;
int btn_prev;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT_PULLUP);
}

void light() {
  digitalWrite(RED_PIN, HIGH);
  delay(100);
  digitalWrite(RED_PIN, LOW);
  wait1 = 1000;
}

void light2() {
  digitalWrite(YELLOW_PIN, HIGH);
  delay(100);
  digitalWrite(YELLOW_PIN, LOW);
  delay(100);
  digitalWrite(YELLOW_PIN, HIGH);
  delay(100);
  digitalWrite(YELLOW_PIN, LOW);
  wait = 2000;
}

void loop() {
  if (wait1 <= 0) {
    light();
  }
  if (wait <= 0) {
    light2();
  }
  wait1 -= 100;
  wait -= 100;
  delay(100);
}