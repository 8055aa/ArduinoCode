/*
 Demo Code for HDSP 2133 using SN74HC595D
 Thomas Yang <8055aa@gmail.com>
 rework from  Matt Joyce < matt@nycresistor.com >
  */
 
//Pin connected to latch pin (ST_CP) of 74HC595
const int latchPin = 4;
//Pin connected to clock pin (SH_CP) of 74HC595
const int clockPin = 5;
////Pin connected to Data in (DS) of 74HC595
const int dataPin = 2;

const int ce = 10;
const int wr = 6;
const int fe = 3;
const int rst = 11;

const int a2 = 9;
const int a1 = 8;
const int a0 = 7;

const int a3 = 12;
const int a4 = 13;

int analogPin = A0;
int incomingByte = 0;
int analogVal = 0;
int key = 0;
 
void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(a0, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  
  pinMode(a3, OUTPUT);
  pinMode(a4, OUTPUT);
  
  pinMode(rst, OUTPUT);
  pinMode(ce, OUTPUT);
  pinMode(wr, OUTPUT);
  pinMode(fe, OUTPUT);

  pinMode(analogPin,INPUT);
  digitalWrite(ce, HIGH);
  digitalWrite(wr, HIGH);
  digitalWrite(rst, HIGH);

  resetDisplay();
  Serial.begin(9600);
}
 
void resetDisplay() {
  digitalWrite(rst, LOW);
  delayMicroseconds(1);
  digitalWrite(rst,HIGH);
  delayMicroseconds(150);
  digitalWrite(a3, HIGH);
  digitalWrite(a4, HIGH);

  digitalWrite(fe, HIGH);
}  
 
void writeDisplay(char *input) {
  Serial.println(key);
  for (int i=0; i<8; i++) {    
    digitalWrite(a0, (1&i)!=0?HIGH:LOW);

    digitalWrite(a1, (2&i)!=0?HIGH:LOW);

    digitalWrite(a2, (4&i)!=0?HIGH:LOW);

       
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, input[i] );
    digitalWrite(latchPin, HIGH);
    delay(1);    
    digitalWrite(ce, LOW);
    delay(1);
    digitalWrite(wr, LOW);
    delay(1);
    digitalWrite(wr, HIGH);
    delay(1);
    digitalWrite(ce, HIGH);
    delay(1);
  }
}
 
void scrollDisplay(char *words) {
  char buffer[9];
  int i = 0;
  while(words[i] != 0){
    boolean blank = false;
    for (int j = 0; j<8; j++) {
      if (!blank && words[i+j] == 0 ) {
        blank = true;
      }
     
      if (blank) {
        buffer[j] = ' ';
      }
      else {
        buffer[j] = words[i+j];
      }
    }
    buffer[8]=0;
    writeDisplay(buffer);
    delay(500);
    i++;
    analogVal = analogRead(analogPin);
    if(analogVal > 1000){
      key = 1;
    }
    else if(analogVal > 600){
      key = 2;
      }
      else if(analogVal > 300){
        key = 3;
      }
      else {
        key = 4;
      }
 }
 
}
void loop() {
    char intro[] = "        This is Thomas Yang's first HDSP-2133 DEMO. ";
    scrollDisplay(intro);
//    delay(500);

}
