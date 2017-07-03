#include <DS1302.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <stdio.h>
#include <DS1302.h>

LiquidCrystal_I2C lcd(0x3f,16,2);
namespace {

// Set the appropriate digital I/O pin connections. These are the pin
// assignments for the Arduino as well for as the DS1302 chip. See the DS1302
// datasheet:
//
//   http://datasheets.maximintegrated.com/en/ds/DS1302.pdf
const int kCePin   = 5;  // Chip Enable
const int kIoPin   = 6;  // Input/Output
const int kSclkPin = 7;  // Serial Clock
/* 日期变量缓存 */
char buf[50];
char bufD[40];
char bufT[40];
char day[10];
/* 串口数据缓存 */
String comdata = "";
int numdata[7] ={0}, j = 0, mark = 0;
/* 创建 DS1302 对象 */
DS1302 rtc(kCePin, kIoPin, kSclkPin);

}  // namespace
void print_time()
{
    /* 从 DS1302 获取当前时间 */
    Time t = rtc.time();
    /* 将星期从数字转换为名称 */
    memset(day, 0, sizeof(day));
    switch (t.day)
    {
    case 1: strcpy(day, "Sunday"); break;
    case 2: strcpy(day, "Monday"); break;
    case 3: strcpy(day, "Tuesday"); break;
    case 4: strcpy(day, "Wednesday"); break;
    case 5: strcpy(day, "Thursday"); break;
    case 6: strcpy(day, "Friday"); break;
    case 7: strcpy(day, "Saturday"); break;
    }
    /* 将日期代码格式化凑成buf等待输出 */
    snprintf(buf, sizeof(buf), "%s %04d-%02d-%02d %02d:%02d:%02d", day, t.yr, t.mon, t.date, t.hr, t.min, t.sec);
    snprintf(bufD, sizeof(bufD), "%04d-%02d-%02d",  t.yr, t.mon, t.date);
     snprintf(bufT, sizeof(bufT), "%s %02d:%02d:%02d", day, t.hr, t.min, t.sec);
    /* 输出日期到串口 */
    Serial.println(buf);
}


int DHpin = 8; 
byte dat[5]; 
byte read_data() 
{ 
   byte data; 
  for(int i=0; i<8; i++) 
  { 
    if(digitalRead(DHpin) == LOW) 
    { 
      while(digitalRead(DHpin) == LOW);  //等待50us； 
      delayMicroseconds(30);  //判断高电平的持续时间，以判定数据是‘0’还是‘1’；  
      if(digitalRead(DHpin) == HIGH) 
      data |= (1<<(7-i));  //高位在前，低位在后 
       while(digitalRead(DHpin) == HIGH);  //数据‘1’，等待下一位的接收； 
    }   
  } 
     return data; 
} 
void start_test() 
{ 
  digitalWrite(DHpin,LOW);  //拉低总线，发开始信号； 
  delay(30);  //延时要大于 18ms，以便 DHT11 能检测到开始信号； 
  digitalWrite(DHpin,HIGH); 
  delayMicroseconds(40);  //等待DHT11 响应； 
         pinMode(DHpin,INPUT); 
         while(digitalRead(DHpin) == HIGH); 
         delayMicroseconds(80);  //DHT11 发出响应，拉低总线 80us； 
         if(digitalRead(DHpin) == LOW); 
         delayMicroseconds(80);  //DHT11 拉高总线 80us 后开始发送数据； 
         for(int i=0;i<4;i++)   //接收温湿度数据，校验位不考虑； 
         dat[i] = read_data(); 
        pinMode(DHpin,OUTPUT);
        digitalWrite(DHpin,HIGH);  //发送完一次数据后释放总线，等待主机的下一次开始信号； 
} 

void setup() {
  // put your setup code here, to run once:
  pinMode(DHpin,OUTPUT); 
  lcd.begin(16,2);
  lcd.init();
  for(int i =0 ; i<3;i++);
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("This is a");
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print(" Meteor Station.");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("Tom Yang");
  delay(5000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Current humdity = ");
  lcd.setCursor(0,1);
  lcd.print("Current temperature = ");

   Serial.begin(9600);

  rtc.writeProtect(false);

  // Clear all RAM bytes, using the byte interface.
  for (int i = 0; i < DS1302::kRamSize; ++i) {
    rtc.writeRam(i, 0x00);
  }

  // Write a string using the bulk interface.
  static const char kHelloWorld[] = "hello world";
  rtc.writeRamBulk((uint8_t*)kHelloWorld, sizeof(kHelloWorld) - 1);
  rtc.halt(false);
}

void loop() {
  // put your main code here, to run repeatedly:
   start_test(); 
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Humd = ");
   lcd.print(dat[0], DEC); //显示湿度的整数位;
   lcd.print('.');
   lcd.print(dat[1],DEC); //显示湿度的小数位;
   lcd.print('%');
   lcd.setCursor(0,1);
    lcd.print("Temp = ");
   lcd.print(dat[2], DEC);  //显示温度的整数位;
   lcd.print('.');
   lcd.print(dat[3],DEC); //显示温度的小数位;
   lcd.print('C');
   delay(3000);
   while(Serial.available()>0)
   {
    comdata += char(Serial.read());
    delay(2);
    mark = 1;
   }
    if(mark == 1)
    {
        Serial.print("You inputed : ");
        Serial.println(comdata);
        for(int i = 0; i < comdata.length() ; i++)
        {
            if(comdata[i] == ',' || comdata[i] == 0x10 || comdata[i] == 0x13)
            {
                j++;
            }
            else
            {
                numdata[j] = numdata[j] * 10 + (comdata[i] - '0');
            }
        }
        /* 将转换好的numdata凑成时间格式，写入DS1302 */
        Time t(numdata[0], numdata[1], numdata[2], numdata[3], numdata[4], numdata[5], numdata[6]);
        rtc.time(t);
        mark = 0;j=0;
        /* 清空 comdata 变量，以便等待下一次输入 */
        comdata = String("");
        /* 清空 numdata */
        for(int i = 0; i < 7 ; i++) numdata[i]=0;
    }
     print_time();
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print(bufD);
    lcd.setCursor(0,1);
     lcd.print(bufT);
    delay(3000);
   
  
}
