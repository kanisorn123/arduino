#include <Stepper.h>

#define STEPS 2048  // number of steps per revolution
#define IN1 32
#define IN2 33
#define IN3 25
#define IN4 26

#define IN5 18
#define IN6 5
#define IN7 17
#define IN8 16

#define JOYX 13
#define JOYY 15
int a = 0;
int b = 0;

Stepper myStepper(STEPS, IN1, IN3, IN2, IN4);
Stepper myStepper2(STEPS, IN5, IN7, IN6, IN8);

void setup() {
  myStepper.setSpeed(5);  // = 5rpm
  myStepper2.setSpeed(5); 
  Serial.begin(115200);
  pinMode(JOYX, INPUT);
  pinMode(JOYY, INPUT);
}

void loop() {
  a = analogRead(JOYX);
  b = analogRead(JOYY);
  Serial.printf("x = %d\n y = %d\n", a, b);

  if (a < 10) {
    myStepper.step(100);
  } else if (a > 4000) {
    myStepper.step(-100);
  } else if (b < 10) {
    myStepper2.step(100);
  } else if (b > 4000) {
    myStepper2.step(-100);
  }

  //myStepper.step(STEPS);
  //delay(100);
  //Serial.println("CCW");
  //myStepper.step(-STEPS);
  delay(100);
}
