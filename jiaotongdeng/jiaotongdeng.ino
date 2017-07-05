int redPin =  9;
int yellowPin = 10;
int greenPin = 8;
int analogPin = 0;
int val = 0;
int state = 0;
char str[] = "asdfsdfagsdag";
char *sl[] = {a,,v,h,r,w,s,g,f,l};
void setLights(int red, int yellow, int green)
{
  digitalWrite(redPin, red);
  digitalWrite(yellowPin, yellow);
  digitalWrite(greenPin, green);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(9600);

}


void loop() {
  // put your main code here, to run repeatedly:
  int period =   analogRead(analogPin) / 2 + 25;

  digitalWrite(redPin, HIGH);
  delay(period);
  digitalWrite(redPin, LOW);

  delay(period);
}




