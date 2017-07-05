#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte colPins[ROWS] = {2, 3, 4, 5};
byte rowPins[COLS] = {6, 7, 8, 9};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
byte ledPin = 10;
boolean blink = false;
int count;

int data = 12;//74HC595的14脚 数据输入引脚SI
int clock = 11;//74hc595的11脚 时钟线 SCK
int latch = 13;//74hc595的12脚 输出存储器锁存线RCK
int ledState = 0;
const int ON = HIGH;
const int OFF = LOW;

void setup()
{
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  keypad.addEventListener(keypadEvent);
  Serial.begin(9600);
  for (int i = 0; i < 256; i++) {
    updateLEDs(i);
    delay(50);

  }
  updateLEDs(0);
}
void loop()
{
//  char key = keypad.getKey();
//
//  if (key != NO_KEY) {
//    Serial.println(key);
//  }
//  switch(count){
//    case '1': blinkLED(1);break;
//    case '2': blinkLED(2);break;
//  }

  for(long i = 0; i < 256; i++)
  {
  updateLEDs(i);
  delay(500);
  }
}
void updateLEDs(int value)
{
  digitalWrite(latch, LOW);//
  shiftOut(data, clock, MSBFIRST, value);//串行数据输出，高位在先
  digitalWrite(latch, HIGH);//锁存
}

//take care of some special events
void keypadEvent(KeypadEvent key) {

  switch (keypad.getState()) {
    case PRESSED:
      switch (key) {
        case '1': count = 1; break;
        case '2': count = 2; break;
        case '3': count = 3; break;
        case '4': count = 4; break;
        case '5': count = 5; break;
        case '6': count = 6; break;
        case '7': count = 7; break;
        case '8': count = 8; break;
        case '9': count = 9; break;
          break;
      }
      break;
    case RELEASED:
      switch (key) {
        case '*':
          
          blink = false;
          break;
      }
      break;
    case HOLD:
      switch (key) {
        case '*': blink = true; break;
      }
      break;
  }
}
void blinkLED(int i)
{
  updateLEDs(i);
  delay(1000);
  updateLEDs(0);
  delay(500);
  updateLEDs(i);
  delay(1000);
  updateLEDs(0);
}


