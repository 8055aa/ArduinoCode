int sensorpin =  2;
int ledPin = 13;      // select the pin for the LED
void setup() {
 pinMode(ledPin, OUTPUT); 
 pinMode(sensorpin, INPUT); 
  Serial.begin(9600); 
}
void loop() {   
  if(digitalRead(sensorpin)==HIGH)
  {
     digitalWrite(ledPin,HIGH);
     delay(5000);
     digitalWrite(ledPin,LOW);
  }   
 delay(10);
}

