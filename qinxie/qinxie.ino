int ledPin = 8 ;
int potPin = 5;

void setup() {
  // put your setup code here, to run once:
 
 pinMode(ledPin,OUTPUT);
 pinMode(potPin,INPUT);
   Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 int i;
 while(1)
 {
  i = analogRead(potPin);
  if(i>512)
  {
    digitalWrite(ledPin,LOW);
     Serial.println(i);
  }
  else{
    digitalWrite(ledPin,HIGH);
     Serial.println(i);
  }
  
 }

}
