int ledpin=8;//定义数字11 接口
int inpin=5;//定义数字7 接口
int reset=2;
int val;//定义变量val
void setup()
{
  pinMode(ledpin,OUTPUT);//定义小灯接口为输出接口
  pinMode(inpin,INPUT);//定义按键接口为输入接口
  pinMode(reset,INPUT);
}
void loop()
{
val=digitalRead(inpin);//读取数字7 口电平值赋给val
if(val==HIGH) LED_YES();//检测按键是否按下，按键按下时小灯亮起
}
void LED_YES()
{
  while(digitalRead(reset)==LOW)
  {
    digitalWrite(ledpin,HIGH);
  }
  clear_led();
}
void clear_led()
{
  digitalWrite(ledpin,LOW);
}

