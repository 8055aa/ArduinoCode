#define redLED 3
#define greenLED 5
#define blueLED 6

#define keyDayORNight 2

int potPin = A0;
bool switchStatus = LOW;
int keyDown = 0;
int oldKeyDown = 0;

unsigned int val = 0;
unsigned int val1 = 0;
unsigned int val2 = 0;
static int count = 0;

void setup()
{
  pinMode(redLED,OUTPUT);//定义小灯接口为输出接口
  pinMode(greenLED,OUTPUT);//定义小灯接口为输出接口
  pinMode(blueLED,OUTPUT);//定义小灯接口为输出接口
  
  pinMode(keyDayORNight,INPUT);//定义按键接口为输入接口
  attachInterrupt(0,DayOrNight,FALLING);
  Serial.begin(9600);
  
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
  digitalWrite(blueLED, LOW);
}
void loop()
{
  val=analogRead(potPin);// 读取传感器的模拟值并赋值给val
  val1 = map(val,0,1023,150,255);//日模式
  val2 = map(val,0,1023,0,100); //夜模式
  DayOrNight();
if (HIGH == switchStatus){
    analogWrite(redLED,val1);// 打开LED 并设置亮度（PWM 输__________出最大值255）
    analogWrite(greenLED,val1);
    analogWrite(blueLED,val1);
    delay(10);//延时0.01 秒
  }
  else{
    analogWrite(redLED,val2);// 打开LED 并设置亮度（PWM 输__________出最大值255）
    analogWrite(greenLED,val2);
    analogWrite(blueLED,val2);
    delay(10);//延时0.01 秒
 
  }
  Serial.println(switchStatus);
}
void DayOrNight()
{
  keyDown = digitalRead(keyDayORNight);
  if((keyDown == LOW) && (oldKeyDown == HIGH))
  {
    switchStatus = 1 - switchStatus;
    delay(10);
  }
  oldKeyDown = keyDown;
}

