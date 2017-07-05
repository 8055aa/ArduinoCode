#include <EEPROM.h>

#define analogPin 0
#define ledPin 8
#define maxReadings 255
#define beta 4096
#define resistance 33

float readings[maxReadings];
int lastReading = EEPROM.read(0);
boolean loggingOn = false;
long period = 300;
long count =0 ;
char mode = 'C';


void setup() {
  // put your setup code here, to run once:
 pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
  Serial.println("I'm Ready");

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char ch = Serial.read();
    if(ch == 'r' || ch == 'R'){
      sendBackdata();
    }
    else if (ch == 'x' ||ch == 'X'){
      lastReading = 0;
      EEPROM.write(0,0);
      Serial.println("Data cleared");
    }else if(ch == 'g' || ch == 'G'){
      loggingOn = true;
      Serial.println("Logging started");
    }
    else if(ch >'0' && ch <='9'){
      setPeriod(ch);
    }else if (ch == 'c' or ch =='C'){
      Serial.println("Mode set to deg C");
      mode = 'C';
    }else if(ch =='f' or ch == 'F')
    {
      Serial.println("Mode set to deg F");
      mode = 'F';
    }else if(ch == '?'){
      reportStatus();
    }
  }
  if(loggingOn && count >period){
    logReading();
    count = 0;
  }
  count++;
  delay(1000);

}

void sendBackdata()
{
  loggingOn = false;
  Serial.println("Logging stopped");
  Serial.println("-------cut here---------------");
  Serial.print("Time (min)\tTemp(");
  Serial.print(mode);
  Serial.println(")");
  for(int i = 0 ;i <lastReading;i++)
  {
    Serial.print((period *i)/60);
    Serial.print("\t");
    float temp = getReading(i);
    if(mode == 'F'){
      temp = (temp * 9)/5 +32;
    }
    Serial.println(temp);
  }
  Serial.println("------cut here------------");
  }

  void setPeriod(char ch)
  {
    int periodMins = ch -'0';
    Serial.print("Sample period set to:");
    Serial.print(periodMins);
    Serial.println("mins");
    period = periodMins * 60;
  }
void logReading()
{
  if(lastReading < maxReadings){
    int a = analogRead(analogPin);
    int temp = (125*a)>>8;;
    storeReading(temp,lastReading);
    lastReading++;
  }
  else{
    Serial.println("Full!logging stopped");
  }
}

void storeReading(int reading,int index)
{
  EEPROM.write(0,(byte)index);
  int compressedReading = (reading<<8)/125;
  EEPROM.write(index + 1,compressedReading);
}

float getReading(int index)
{
  lastReading = EEPROM.read(0);
  byte compressedReading = EEPROM.read(index + 1);
  float uncompressesReading = (compressedReading /4.0)-20.0;
  return uncompressesReading;
}
void reportStatus()
{
  Serial.println("--------------------------------");
  Serial.println("Status");
  Serial.print("Sample period\t");
  Serial.println(period /60);
  Serial.print("Num reading\t");
  Serial.println(lastReading);
  Serial.print("Mode degrees\t");
  Serial.println(mode);
  Serial.println("--------------------------------------");
}

