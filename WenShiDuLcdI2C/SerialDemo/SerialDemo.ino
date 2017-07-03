String RecStr;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  RecStr = 'a';
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
  RecStr += char(Serial.read());
  delay(2);
  }
  if(RecStr[RecStr.length()-1] =='Q' ){
     delay(1000);      
      Serial.println("Receive,123");
      RecStr = "";
  }
  if(RecStr.length() > 0){
  Serial.println("OVER.");
   Serial.println(RecStr.length());
   
   
  }
   delay(3000);
}
