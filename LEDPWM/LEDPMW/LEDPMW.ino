#define redLED 3
#define greenLED 5
#define blueLED 6

#define btn 2

int val = 0;
int old_val = 0;
int state = 0;
int brightness = 0;
unsigned long startTime = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLED,OUTPUT);
  pinMode(greenLED,OUTPUT);
  pinMode(blueLED,OUTPUT);
  pinMode(btn,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(btn);
  if((val == HIGH)&&(old_val == LOW)){
    state = 1 - state;
    startTime = millis();
    delay(10);
  }
  if((val == HIGH)&&(old_val ==HIGH)){
    if(state ==1 && (millis() - startTime) > 500){
      brightness++;
      delay(10);

      if(brightness > 255){
        brightness = 0;
      }
    }
  }

  old_val = val;
  if(state == 1){
    analogWrite(redLED,brightness);
    analogWrite(greenLED,brightness);
    analogWrite(blueLED,brightness);
  }else{
    analogWrite(redLED,0);
    analogWrite(greenLED,0);
    analogWrite(blueLED,0);
  }
  
}
