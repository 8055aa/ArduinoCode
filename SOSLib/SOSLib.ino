#include <Morse.h>
Morse morse(11);
Morse morse2(10);
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  morse.dot();morse.dot();morse.dot();
  morse.dash();morse.dash();morse.dash();
  morse.dot();morse.dot();morse.dot();
  delay(3000);
  morse2.dot();morse2.dot();morse2.dot();
  morse2.dash();morse2.dash();morse2.dash();
  morse2.dot();morse2.dot();morse2.dot();
  delay(3000);

}
