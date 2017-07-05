int potPin = 0;
int LED = 9;
int i = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
//  digitalWrite(ledPin,HIGH);
//  delay(val1);
//  digitalWrite(ledPin,LOW);
//  delay(val1); 
//  val =0.5*val + 0.5* analogRead(potPin);
//  val1 = 700 - val;
//  Serial.print("analog value = ");
//  Serial.println(val);
  for(i = 0;i<255;i++)
  {
    analogWrite(LED,i);
    delay(10);
  }
  for(i=255;i>0;i--)
  {
    analogWrite(LED,i);
    delay(10);
   
  }
}
