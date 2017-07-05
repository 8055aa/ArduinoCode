int data = 2;//74HC595的14脚 数据输入引脚SI 
int clock = 5;//74hc595的11脚 时钟线 SCK
int latch = 4;//74hc595的12脚 输出存储器锁存线RCK 
int ledState = 0;
const int ON = HIGH;
const int OFF = LOW;
void setup()
{
pinMode(data, OUTPUT);
pinMode(clock, OUTPUT);
pinMode(latch, OUTPUT);
}
void loop()
{
for(long i = 0; i < 65535; i++)
{
updateLEDs(i);
delay(100);
}
}
void updateLEDs(int value)
{
digitalWrite(latch, LOW);//
shiftOut(data, clock, MSBFIRST, value);//串行数据输出，高位在先
digitalWrite(latch, HIGH);//锁存
}



