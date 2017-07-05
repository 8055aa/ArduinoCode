#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int ledRedPin=10;//定义redLED接口
int ledBluePin=11;//定义数字blueLED接口
int ledGreenPin=9;//定义数字greenLED 接口

int keyDayORNight = 13;//定义 日夜转换按键 接口
int blinkKey = 8;

int potPin=0;//定义模拟接口0

int ledpin1=9;//定义数字接口11（PWM 输出）
int ledpin2=10;
int val = 0;
int val1=0;// 暂存来自传感器的变量数值
int val2=0;// 暂存来自传感器的变量数值
int keyDown = 0;
int blinkKeyDown = 0;
int oldBlinkKeyDown = 0;

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
//byte rowPins[COLS] = {2,3,4,5};
byte rowPins[ROWS] = {6,7,8,9};
byte colPins[COLS] = {5,4,3,2};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
boolean blink = false;
boolean dayORnight = false;

LiquidCrystal_I2C lcd(0x3f,16,2);

void setup()
{
  pinMode(ledRedPin,OUTPUT);//定义小灯接口为输出接口
  pinMode(ledBluePin,OUTPUT);//定义小灯接口为输出接口
  pinMode(ledGreenPin,OUTPUT);//定义小灯接口为输出接口
  
  pinMode(keyDayORNight,INPUT);//定义按键接口为输入接口
  pinMode(blinkKey,INPUT);
  
  pinMode(potPin,INPUT);

  Serial.begin(9600);

  digitalWrite(ledRedPin, LOW);
  digitalWrite(ledBluePin, LOW);
  digitalWrite(ledGreenPin, LOW);

  lcd.init();
  lcd.backlight();
  
  lcd.print("Hello World!!!");
  lcd.setCursor(2,1);
  lcd.print("I am ready GO!");
 
  
}
void loop()
{
  blinkKeyDown = digitalRead(blinkKey); 
  if((blinkKeyDown == LOW)&&(oldBlinkKeyDown == HIGH))
  {
    blink = 1 - blink;
    delay(10);
  }
  oldBlinkKeyDown = blinkKeyDown;

  
  val=analogRead(potPin);// 读取传感器的模拟值并赋值给val
  keyDown = digitalRead(keyDayORNight);
// lcd.clear();
//  lcd.print("Day:");//显示val 变量
//  lcd.print(val1,DEC);//显示val1 变量
//  lcd.setCursor(0,1);
//  lcd.print("Night:");//显示val 变量 
//  lcd.print(val2,DEC);//显示val2 变量
//  delay(500);
  
//  char key = keypad.getKey();
//  
//  if (key != NO_KEY) {
//    Serial.println(key);
//  }

if (keyDown){
    val1 = map(val,0,1023,150,255);
    if(blink){
    analogWrite(ledRedPin,val1);// 打开LED 并设置亮度（PWM 输__________出最大值255）
    analogWrite(ledBluePin,val1);
    analogWrite(ledGreenPin,val1);
    delay(10);//延时0.01 秒
    }else{
       analogWrite(ledRedPin,0);// 打开LED 并设置亮度（PWM 输__________出最大值255）
       analogWrite(ledBluePin,0);
       analogWrite(ledGreenPin,0);
    }
  }
  else{
    val2 = map(val,0,1023,0,100);    
    if(blink){
    analogWrite(ledRedPin,val2);// 打开LED 并设置亮度（PWM 输__________出最大值255）
    analogWrite(ledBluePin,val2);
    analogWrite(ledGreenPin,val2);
    delay(10);//延时0.01 秒
    }else{
       analogWrite(ledRedPin,0);// 打开LED 并设置亮度（PWM 输__________出最大值255）
       analogWrite(ledBluePin,0);
       analogWrite(ledGreenPin,0);
    }
  }
}

//void LED_YES()
//{
//  while(digitalRead(reset)==LOW)
//  {
//    digitalWrite(ledGreenPin,HIGH);
//  }
//  clear_led();
//}
//void clear_led()
//{
//  digitalWrite(ledGreenPin,LOW);
//}




