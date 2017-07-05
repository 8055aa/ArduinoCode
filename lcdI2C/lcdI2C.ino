#include <LiquidCrystal.h>

#include <LiquidCrystal.h>

#include <Wire.h>


LiquidCrystal lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("This is Yang's clock:");

}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  for(i = 0;i<3600;i++)
  {
    lcd.setCursor(0,1);
    lcd.print(i);
    delay(1000);
  }

}
