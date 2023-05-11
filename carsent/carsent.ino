#include <NRF51_Radio_library.h>
#include <Adafruit_Microbit.h>
#define A_PIN 5
#define B_PIN 11
#define JOYX_PIN 0
Adafruit_Microbit_Matrix matrix;
NRF51_Radio radio = NRF51_Radio();
FrameBuffer* sendBuf = new FrameBuffer();
int button1;
int button2;
int joyx = 0;
int radioSendString(String s) {
  sendBuf->length = MICROBIT_RADIO_HEADER_SIZE + s.length();
  sendBuf->group = 0;     // from microbit upy
  sendBuf->version = 1;   // from microbit upy
  sendBuf->protocol = 1;  // from microbit upy
  s.getBytes(sendBuf->payload, MICROBIT_RADIO_MAX_PACKET_SIZE);
  return radio.send(sendBuf);
}

char* radioReceiveString() {
  FrameBuffer* myData = radio.recv();
  if (myData != NULL) {
    // Serial.print("l:"); Serial.print(myData->length);
    // Serial.print(", v:"); Serial.print(myData->version);
    // Serial.print(", g:"); Serial.print(myData->group);
    // Serial.print(", p:"); Serial.print(myData->protocol);
    // Serial.print(", rssi:"); Serial.print(myData->rssi);
    // Serial.print(", payload:"); Serial.print((char*)myData->payload);
    delete myData;
    return (char*)myData->payload;
  } else {
    return "";
  }
}
void setup() {
  matrix.begin();
  matrix.show(matrix.MICROBIT_SMILE);

  Serial.begin(115200);
  Serial.println("Starting the Radio Library");

  radio.setGroup(1);
  radio.enable();

  pinMode(A_PIN, INPUT_PULLUP);
  pinMode(B_PIN, INPUT_PULLUP);
  button1 = digitalRead(A_PIN);
  button2 = digitalRead(B_PIN);

  pinMode(JOYX_PIN,INPUT);
  Serial.begin(115200);
}
void loop() {
  int a = digitalRead(A_PIN);
  int b = digitalRead(B_PIN);

  int joyx = analogRead(JOYX_PIN);
  if (a == LOW && button1 == HIGH) {
    gogo();
  }

  if (b == LOW && button2 == HIGH) {
    brake();
  }
  if (joyx > 1000){
    left();
  }
  if (joyx < 20){
    right();
  }
  button1 = a;
  button2 = b;
  Serial.println(joyx);
  delay(200);
}



void right(){
  radioSendString("right");  
}
void left(){
  radioSendString("left");
}
void brake(){
  radioSendString("brake");
}
void gogo(){
  radioSendString("gogo");
}
