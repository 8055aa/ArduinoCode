int servoPin = 9;
int myAngle;
int pulseWidth;
int val;

void servoPulse(int servoPin,int myAngle)
{
  pulseWidth = (myAngle * 11)+500;
  digitalWrite(servoPin,HIGH);
  delayMicroseconds(pulseWidth);
  digitalWrite(servoPin,LOW);
  delay(20 - pulseWidth/1000);
}


void setup() {
  // put your setup code here, to run once:
  pinMode(servoPin,OUTPUT);
  Serial.begin(9600);
  Serial.println("servo = o_seral_simple ready");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  val = Serial.read();
  if(val>'0' && val <='9')
  {
    val = val-'0';
    val = val *(180/9);
    Serial.print("moving servo to ");
    Serial.print(val,DEC);
    Serial.println();
    for(int i = 0 ; i <= 50; i++)
    {
      servoPulse(servoPin,val);
    }
  }

}
