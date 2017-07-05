#include <stdio.h>
#include <string.h>
#include <DS1302.h>

uint8_t CE_PIN = 5;
uint8_t IO_PIN = 6;
uint8_t SCLK_PIN = 7;

char buf[50];
char day[10];
String comdata = "";
int numdata[7] = {0}, j = 0, mark = 0;
DS1302 rtc(CE_PIN, IO_PIN, SCLK_PIN);

int DHpin = 8;
byte dat[5];
byte read_data()
{
  byte data;
  for (int i = 0; i < 8; i++)
  {
    if (digitalRead(DHpin) == LOW)
    {
      while (digitalRead(DHpin) == LOW); //等待50us；
      delayMicroseconds(30);  //判断高电平的持续时间，以判定数据是‘0’还是‘1’；
      if (digitalRead(DHpin) == HIGH)
        data |= (1 << (7 - i)); //高位在前，低位在后
      while (digitalRead(DHpin) == HIGH); //数据‘1’，等待下一位的接收；
    }
  }
  return data;
}
void start_test()
{
  digitalWrite(DHpin, LOW); //拉低总线，发开始信号；
  delay(30);  //延时要大于 18ms，以便 DHT11 能检测到开始信号；
  digitalWrite(DHpin, HIGH);
  delayMicroseconds(40);  //等待DHT11 响应；
  pinMode(DHpin, INPUT);
  while (digitalRead(DHpin) == HIGH);
  delayMicroseconds(80);  //DHT11 发出响应，拉低总线 80us；
  if (digitalRead(DHpin) == LOW);
  delayMicroseconds(80);  //DHT11 拉高总线 80us 后开始发送数据；
  for (int i = 0; i < 4; i++) //接收温湿度数据，校验位不考虑；
    dat[i] = read_data();
  pinMode(DHpin, OUTPUT);
  digitalWrite(DHpin, HIGH); //发送完一次数据后释放总线，等待主机的下一次开始信号；
}

void print_time()
{
  Time t = rtc.time();
  memset(day, 0, sizeof(day));
  switch (t.day)
  {
    case 1: strcpy(day, "Sunday"); break;
    case 2: strcpy(day, "Monday"); break;
    case 3: strcpy(day, "Tuesday"); break;
    case 4: strcpy(day, "Wednesday"); break;
    case 5: strcpy(day, "Thursday"); break;
    case 6: strcpy(day, "Friday"); break;
    case 7: strcpy(day, "Staturday"); break;
  }
  snprintf(buf, sizeof(buf), "%s %04d-%02d-%02d %02d:%02d:%02d", day, t.yr, t.mon, t.date, t.hr, t.min, t.sec);
  digitalWrite(13, LOW);
  Serial.println(buf);

}

void setup()
{
  Serial.begin(19200, SERIAL_8N1);
  pinMode(DHpin, OUTPUT);
  rtc.write_protect(false);
  rtc.halt(false);
}

void loop()  // run over and over again
{
  while (Serial.available() > 0)
  {
    comdata += char(Serial.read());
    delay(2);
    mark = 1;
  }
  if (mark == 1)
  {
    Serial.print("You inputed: ");
    Serial.println(comdata);
    for (int i = 0; i < comdata.length(); i++)
    {
      if (comdata[i] == ',' || comdata[i] == 0x10 || comdata[i] == 0x13)
      {
        j++;
      }
      else
      {
        numdata[j] = numdata[j] * 10 + (comdata[i] - '0');
      }
    }
    Time t(numdata[0], numdata[1], numdata[2], numdata[3], numdata[4], numdata[5], numdata[6]);
    rtc.time(t);
    mark = 0; j = 0;
    comdata = String("");
    for (int i = 0; i < 7; i++) numdata[i] = 0;
  }
  print_time();
  delay(1000);
  start_test();
  Serial.print("Current humdity = ");
  Serial.print(dat[0], DEC);  //显示湿度的整数位；
  Serial.print('.');
  Serial.print(dat[1], DEC); //显示湿度的小数位；
  Serial.println('%');
  Serial.print("Current temperature = ");
  Serial.print(dat[2], DEC);  //显示温度的整数位；
  Serial.print('.');
  Serial.print(dat[3], DEC); //显示温度的小数位；
  Serial.println('C');
  delay(700);
}


