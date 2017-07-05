#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3f,16,2);//设置接口	
int xpotPin = 0;  //设置模拟口0为X的信号输入端口
int ypotPin = 1;  //设置模拟口1为Y的信号输入端口
int xval=0;    //设置变量
int yval=0;	
int btn = 2;

void setup()
{
  Serial.begin(9600);
 
  lcd.init();
  pinMode(xpotPin,INPUT);//
  pinMode(ypotPin,INPUT);//
  pinMode(btn,INPUT);
//  lcd.begin(16, 2);  //初始化LCD
  lcd.backlight();
  delay(1); //延时1000ms
}	
void loop ()
{	
  xval = analogRead(xpotPin);   //xval变量为从0信号口读取到的数值
  yval = analogRead(ypotPin);   //yval变量为从1信号口读取到的数值
  lcd.setCursor(0, 0) ; //设置光标位置为第一行第一个位置
  lcd.print("X=");      //使屏幕显示文字X=
  lcd.print(xval);
  lcd.setCursor(7, 0) ; //设置光标位置为第一行第八个位置
  lcd.print("Y=");      //使屏幕显示文字Y=
  lcd.print(yval);	
  lcd.setCursor(1, 1) ;
  lcd.print("Hi,WOW!...。。。");
  delay(100);                     //延时0.1秒，这里也就是刷新速度。	
  lcd.clear(); //清屏

}
