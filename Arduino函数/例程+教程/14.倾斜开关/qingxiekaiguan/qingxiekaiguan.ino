void setup() 
{ 
  pinMode(8,OUTPUT);//设置数字8引脚为辒出模式 
} 
void loop() 
{ 
int i;//定义发量i 
while(1) 
{ 
  i=analogRead(5);//读叏模拟5口电压值 
  if(i>512)//如果大于512（2.5V） 
  { 
    digitalWrite(8,LOW);//点亮led灯 
  } 
  else//否则 
  { 
    digitalWrite(8,HIGH);//熄灭led灯 
  } 
 } 
} 

