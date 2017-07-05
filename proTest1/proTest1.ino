int potPin=0;//定义模拟接口0
int ledPin1=9;//定义数字接口9（PWM 输出）
int ledPin2=10;
int val=0;// 暂存来自传感器的变量数值
int x = 1;
int i = 0;
String  myString[] = {
  "This is string1!","This is string2,","This is string3.",
  "This is string4?","This is string5$","This is string6*"};
int myArray[10] = {1,2,3,4,5,6,7,8,9,0};
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(ledPin1,OUTPUT);
 pinMode(ledPin2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

//  for(int i = 0;i <=255;i = i+x){
//    analogWrite(ledPin1,i);
//    if(i ==255) x= -1;
//    if(i == 1)  x= 1;
//    delay(20);
//   }
    int x = 5,y = 8;
    for(i = 0;i < 10;i++){
//      Serial.println(myArray[i]);
//      delay(500);
     
    }
     Serial.println(min(x,y));
      delay(500);
      Serial.println(max(x,y));
      delay(500);
}

