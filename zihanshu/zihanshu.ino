/*
  String to Integer conversion

 Reads a serial input string until it sees a newline, then converts
 the string to a number if the characters are digits.

 The circuit:
 No external components needed.

 created 29 Nov 2010
 by Tom Igoe

 This example code is in the public domain.
 */

String inString = "";    // string to hold input
int power(int ,int n)
{
  int i =0,p = 0;
  for(i=0;i<n;i++){
    p *= n;
  }
  return (p);
}

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // send an intro:
  Serial.println("\n\nString toInt():");
  Serial.println();
}

void loop() {
  // Read serial input:
  int x,n,p;
  while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char
      // and add it to the string:
      inString += (char)inChar;
    }
    // if you get a newline, print the string,
    // then the string's value:
    if (inChar == '\n') {
      Serial.print("Value:");
      x = Serial.println(inString.toInt());
      Serial.print("String: ");
      Serial.println(inString);
      Serial.print("Please enter N: ");
      // clear the string for new input:
      inString = "";
    }
     if (isDigit(inChar)) {
      // convert the incoming byte to a char
      // and add it to the string:
      inString += (char)inChar;
    }
    // if you get a newline, print the string,
    // then the string's value:
    if (inChar == '\n') {
      Serial.print("Value:");
      n = Serial.println(inString.toInt());
      Serial.print("String: ");
      Serial.println(inString);
      p = power(x,n);
      Serial.print("result is : ");
      Serial.println(p);
      // clear the string for new input:
      inString = "";
    }
  }
}
