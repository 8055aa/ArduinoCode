#define sensorPin   2
#define ledPin  9
int led = 13;
int analogPin = A0;
int inputValue = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(sensorPin,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(sensorPin)==HIGH){
    digitalWrite(ledPin,HIGH);
    delay(500);
    digitalWrite(ledPin,LOW);
    digitalWrite(led,HIGH);
    delay(100);
    digitalWrite(led,LOW);
    inputValue = analogRead(analogPin);
    Serial.println(inputValue);
  }else{
    digitalWrite(led,LOW);
  }
  delay(10);
}
