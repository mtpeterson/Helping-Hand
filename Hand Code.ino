#include <Servo.h>

Servo index;
Servo pinky;
Servo thumb;
int closeBut = 10;
int openBut = 11;

bool closeButState;
bool prevCloseButState;
// bool openButState;
int grip;


void setup() {
  Serial.begin(9600);
  index.attach(9);
  pinky.attach(6);
  thumb.attach(5);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  closeButState = 1;
  prevCloseButState = 1;
  // openButState = 1;
  grip = 0;
}

void loop() {
  closeButState = debounce(closeBut, prevCloseButState);
  if(closeButState == 0 && prevCloseButState == 1) {
    grip += 20;
  }
  if(grip > 180) {
    grip = 180;
  }
  if(digitalRead(openBut) == 0) {
    grip = 0;
  }
  index.write(grip);
  pinky.write(grip);
  thumb.write(grip + 10);

  prevCloseButState = closeButState;
  // Serial.println(digitalRead(closeBut));
  // Serial.println(digitalRead(openBut));
  // Serial.println(closeButState);
  // myServo.write(100);
  // delay(500);
  // myServo.write(0);
  // delay(500);
}

boolean debounce(int aButtonPin, boolean aPrevState){
  boolean butState = digitalRead(aButtonPin);

  if(aPrevState == butState){
    return butState;
  }
  else {
    delay(5);
    return butState;
  }
}