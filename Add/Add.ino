#include <Add.h>
Add add;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
//  for(int i = 0;i < 500; i++){
//    int val = add.Calculation(i,i);
//    Serial.println(val);
//    delay(500);
//   }
   int i =2,j = 3,k = 0;
   k = myMultiplyFunction(i,j);
   Serial.println(k);
   delay(1000);

}
int myMultiplyFunction(int x,int y){
  int result;
  result = x * y;
  return result;
}

