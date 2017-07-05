#include <Servo.h>

Servo myServo;


void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  
}

void loop() {
  // put your main code here, to run repeatedly:
 myServo.write(0);
 delay(5000);
 myServo.write(90);
 delay(5000);
 myServo.write(180);
 delay(5000);
 myServo.write(0);
}
