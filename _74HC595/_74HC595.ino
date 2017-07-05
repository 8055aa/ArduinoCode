int data = 2;
int clock = 5;
int latch = 4;
int ledState = 0;
const int ON = HIGH;
const int OFF = LOW;


void setup() {
  // put your setup code here, to run once:
 
  pinMode(data,OUTPUT);
  pinMode(clock,OUTPUT);
  pinMode(latch,OUTPUT);
//  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
for(int i = 0;i<256;i++)
{
  updateLEDs(i);
  delay(500); 
}
}
void updateLEDs(int value)
{
  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,value);
  digitalWrite(latch,HIGH);
}
void updateLEDsLong(int value)
{
  digitalWrite(latch,LOW);
  for(int i=0;i<8;i++)
  {
    int bit = value &B10000000;
    value = value << 1;
    if(bit == 128){digitalWrite(data,HIGH);}
    else{digitalWrite(data,HIGH);}
    digitalWrite(clock,HIGH);
    delay(1);
    digitalWrite(clock,LOW);
  }
  digitalWrite(latch,HIGH);
}
int bits[]={B00000001,B00000010,B00000100,B00001000,B00010000,B00100000,B01000000,B10000000};
int masks[]={B11111110,B11111101,B11111011,B11110111,B11101111,B11011111,B10111111,B01111111};
void changeLED(int led,int state)
{
  ledState = ledState & masks[led];
  if(state == ON){ledState = ledState|bits[led];};
  updateLEDs(ledState);
}

