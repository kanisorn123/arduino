
#define BTN_PIN 13
#define G_PIN 23
#define Y_PIN 19
#define R_PIN 22
#define NUM_LEDS 25

char color;
int wait;
int btn_prev;
CRGB leds[NUM_LEDS];

void setup() {
  pinMode(BTN_PIN, INPUT_PULLUP);
  btn_prev = digitalRead(BTN_PIN);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(64);
  Serial.begin(115200);

  color = 'R';
  wait = 5000;
  digitalWrite(R_PIN, HIGH);
}

void loop() {
  detectClick();

  if (wait <= 0) {
    changeLight();
  }

  wait -= 100;
  delay(100);
}


void detectClick() {
  int a = digitalRead(BTN_PIN);
  if (a == LOW && btn_prev == HIGH) {
    Serial.println("Clicked");
    color = 'R';
    wait = 5000;
    digitalWrite(R_PIN, HIGH);
  }
  btn_prev = a;
}

void changeLight() {
  if (color == 'R') {
    color = 'Y';
    wait = 2000;
    digitalWrite(R_PIN, HIGH);
  } else if (color == 'Y') {
    color = 'G';
    wait = 3000;
    digitalWrite(Y_PIN, HIGH);
  } else if (color == 'G') {
    color = 'R';
    wait = 5000;
    digitalWrite(G_PIN, HIGH);
  }
}
