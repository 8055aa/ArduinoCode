int buzzerW = 7;
int buzzerY = 8;
void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerW,OUTPUT);
  pinMode(buzzerY,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned char i,j;
  while(1)
  {
    for(i = 0;i<80;i++)
    {
      digitalWrite(buzzerW,HIGH);
      delay(1000);
      digitalWrite(buzzerW,LOW);
      delay(1000);
      digitalWrite(buzzerY,HIGH);
      delay(500);
      digitalWrite(buzzerY,LOW);
      delay(500);
    }
    for(i=0;i<100;i++)
    {
      digitalWrite(buzzerW,HIGH);
      delay(2);
      digitalWrite(buzzerW,LOW);
      delay(2);
      digitalWrite(buzzerY,HIGH);
      delay(2);
      digitalWrite(buzzerY,LOW);
      delay(2);
    }
  }

}
