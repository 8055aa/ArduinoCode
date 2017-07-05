char c = '1';
int i = 13;

void setup() {
  // put your setup code here, to run once:
  
    pinMode(i,OUTPUT);

  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char c;
  if(Serial.available()){
  c = Serial.read();
  }
 if(c == 'b'){
    for(int clk=0;clk<30;clk++){
    digitalWrite(i,LOW);
    
    delay(1000);
    
     digitalWrite(i,HIGH);
   
    delay(1000);
    Serial.println("in 'b' forLoop !");
    }
    Serial.println("out of 'b' forLoop !");
 }
   if(c ==  'c'){
    digitalWrite(i,LOW);
    delay(1000);
    Serial.println("in of 'c' code !!");
   }

  if(c ==  'q'){
    digitalWrite(i,HIGH);
    delay(1000);
    Serial.println("in of 'q' code !!");
   }
}
