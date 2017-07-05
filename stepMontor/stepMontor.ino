#include <Stepper.h>
#define STEPS 100
Stepper stepper(STEPS,8,9,10,11);
int previous = 0;
int analogPin = A0;

void setup() {
  // put your setup code here, to run once:
  stepper.setSpeed(180);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(analogPin);
  stepper.step(val - previous);
  previous = val;
  Serial.println(analogPin);
}
