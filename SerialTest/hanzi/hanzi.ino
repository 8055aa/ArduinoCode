void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int testByte = 65;
  Serial.print("这是一个汉字hanzi:");
  Serial.println((byte)testByte);
 
  Serial.print("DEC:");
  Serial.println(testByte,DEC);

  Serial.print("HEX:");
  Serial.println(testByte,HEX);

  Serial.print("BIN:");
  Serial.println(testByte,BIN);

  Serial.print("OCT:");
  Serial.println(testByte,OCT);

  delay(1000);
  Serial.println("------------------------------------------------------");

}
