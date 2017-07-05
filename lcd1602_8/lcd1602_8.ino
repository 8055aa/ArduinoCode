#include <LiquidCrystal.h>


int DI =12;
int RW =11;
int DB[] = {3,4,5,6,7,8,9,10};
int Enable = 2;

void LcdCommandWrite(int value)
{
  int i = 0;
  for (i = DB[0];i<=DI;i++)
  {
    digitalWrite(i,value&01);
    value >>=1;
  }
  digitalWrite(Enable,LOW);
  delayMicroseconds(1);
  digitalWrite(Enable,HIGH);
  delayMicroseconds(1);
  digitalWrite(Enable,LOW);
  delayMicroseconds(1);
}
void LcdDataWrite(int value)
{
  int i = 0;
  digitalWrite(DI,HIGH);
  digitalWrite(RW,LOW);
  for(i = DB[0];i<=DB[7];i++)
  {
    digitalWrite(i,value & 01);
    value >>= 1;
  }
    digitalWrite(Enable,LOW);
    delayMicroseconds(1);
    digitalWrite(Enable,HIGH);
    delayMicroseconds(1);
    digitalWrite(Enable,LOW);
    delayMicroseconds(1);
}
void setup(void){
  int i = 0;
  for(i=Enable;i<=DI;i++){
    pinMode(i,OUTPUT);
  }
  delay(100);
  LcdCommandWrite(0x38);
  delay(64);
  LcdCommandWrite(0x38);
  delay(50);
  LcdCommandWrite(0x38);
  delay(20);
  LcdCommandWrite(0x06);
  delay(20);
  LcdCommandWrite(0x0E);
  delay(20);
  LcdCommandWrite(0x01);
  delay(100);
  LcdCommandWrite(0x80);
  delay(20);
}

void loop(void){
  LcdCommandWrite(0x01);
  delay(10);
  LcdCommandWrite(0x80+3);
  delay(100);
  LcdDataWrite('W');
  LcdDataWrite('e');
  LcdDataWrite('l');
  LcdDataWrite('c');
  LcdDataWrite('o');
  LcdDataWrite('m');
  LcdDataWrite('e');
  LcdDataWrite(' ');
  LcdDataWrite('t');
  LcdDataWrite('o');
  delay(5000);
  
  LcdCommandWrite(0xc0+1);
    delay(10);
  LcdDataWrite('g');
  LcdDataWrite('e');
  LcdDataWrite('e');
  LcdDataWrite('k');
  LcdDataWrite('-');
  LcdDataWrite('w');
  LcdDataWrite('o');
  LcdDataWrite('r');
  LcdDataWrite('k');
  delay(5000);
  LcdCommandWrite(0x01);
    delay(10);
   LcdDataWrite('I');
   LcdDataWrite(' ');
   LcdDataWrite('a');
   LcdDataWrite('m');
   LcdDataWrite(' ');
   LcdDataWrite('h');
   LcdDataWrite('o');
   LcdDataWrite('n');
   
  delay(3000);

    LcdCommandWrite(0x02);
    delay(10);
     LcdDataWrite('t');
      LcdDataWrite('h');
       LcdDataWrite('e');
        LcdDataWrite(' ');
         LcdDataWrite('a');
    

}


