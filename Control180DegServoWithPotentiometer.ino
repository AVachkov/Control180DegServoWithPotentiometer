#include "Arduino.h"
#include <Servo.h>

int main()
{
  init();
  Serial.begin(9600);

  const uint8_t servoPin = 9;
  const uint8_t potentiometerPin = A0;

  Servo myServo;
  myServo.attach(servoPin);
  
  pinMode(potentiometerPin, INPUT);

  uint8_t lastDeg = 255; // set it to something different than [0-180]
  while (true) {
    int16_t reading = analogRead(potentiometerPin);
    uint8_t deg = map(reading, 0, 1023, 0, 180);
    if (deg != lastDeg) {
      Serial.println(deg);
      myServo.write(deg);
      lastDeg = deg;
    }
    delay(15);
  }


  return 0;
}