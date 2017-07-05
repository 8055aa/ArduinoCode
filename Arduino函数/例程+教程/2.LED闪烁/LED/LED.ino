//2014.3.13
int relay1 = 5;
int relay2 = 6;
char c;
void setup()
{
  pinMode(relay1, OUTPUT); // 口为输出接口，Arduino 上我们用到的I/O 口都要进行类似这样的定义。
  pinMode(relay2, OUTPUT);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay1, HIGH);
  Serial.begin(9600);
}

void loop() //死循环体
{
  if (Serial.available()) {
    c = Serial.read();
  } else {
    if (c == 's') {
      digitalWrite(relay1, HIGH);
      digitalWrite(relay2, HIGH);
    } else if (c == 'b') {
      c = 'b';
      digitalWrite(relay1, HIGH); //IO口10设置为高电平，点亮数字10 口LED
      digitalWrite(relay2, LOW);
      delay(5000);//延时500MS
      digitalWrite(relay1, LOW); //IO口10设置为低电平，熄灭数字10 口LED
      digitalWrite(relay2, HIGH);
      delay(5000);//延时500MS
    }
  }

}
