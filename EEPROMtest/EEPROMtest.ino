#include <EEPROM.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  char letterToWrite = 'A';
  EEPROM.write(0,letterToWrite);
  char letterToRead;
  letterToRead = EEPROM.read(0);
  Serial.println("This is ::: ",(byte)letterToRead);
  Serial.println("---------------------cut--------------------");

}
