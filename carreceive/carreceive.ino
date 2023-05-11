#include <NRF51_Radio_library.h>
#include <Adafruit_Microbit.h>
#define MOTOR_A_1A_PIN 0
#define MOTOR_A_1B_PIN 1
#define MOTOR_A_2A_PIN 8
#define MOTOR_A_2B_PIN 12
Adafruit_Microbit_Matrix matrix;
NRF51_Radio radio = NRF51_Radio();
FrameBuffer* sendBuf = new FrameBuffer();

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

  pinMode(MOTOR_A_1A_PIN, OUTPUT);
  pinMode(MOTOR_A_1B_PIN, OUTPUT);
  pinMode(MOTOR_A_2A_PIN, OUTPUT);
  pinMode(MOTOR_A_2B_PIN, OUTPUT);
}


void loop() {
  char* s = radioReceiveString();
  String ss = String(s);

  if (strlen(s) > 0) {
    //matrix.print(s);
    if (ss == "gogo") {
      analogWrite(MOTOR_A_1A_PIN, 240);
      digitalWrite(MOTOR_A_1B_PIN, 0);

      digitalWrite(MOTOR_A_2A_PIN, 0);
      analogWrite(MOTOR_A_2B_PIN, 255);

      delay(500);
    } else if (ss == "brake") {
      analogWrite(MOTOR_A_1A_PIN, 0);
      digitalWrite(MOTOR_A_1B_PIN, 0);

      digitalWrite(MOTOR_A_2A_PIN, 0);
      analogWrite(MOTOR_A_2B_PIN, 0);
    } else if (ss == "right") {
      digitalWrite(MOTOR_A_1A_PIN, 0);
      digitalWrite(MOTOR_A_1B_PIN, 0);
      digitalWrite(MOTOR_A_2A_PIN, 0);
      analogWrite(MOTOR_A_2B_PIN, 250);
    }else if (ss == "left"){
      analogWrite(MOTOR_A_1A_PIN, 250);
       digitalWrite(MOTOR_A_1B_PIN, 0);
      digitalWrite(MOTOR_A_2A_PIN, 0);
      digitalWrite(MOTOR_A_2B_PIN, 0);
    }
  }
  Serial.println(ss);

  delay(200);
}
