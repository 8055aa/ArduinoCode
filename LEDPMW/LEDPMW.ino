#define LED 9
#define btn 7
int val = 0;
int old_val = 0;
int state = 0;
int brightness = 0;
unsigned long startTime = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
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
    analogWrite(LED,brightness);
  }else{
    analogWrite(LED,0);
  }
  
}
