int potPin = 0 ;
int ledPin = 11;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(potPin);
  Serial.println(val);
  analogWrite(ledPin,val/4);
  delay(10);

}
