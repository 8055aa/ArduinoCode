#include <avr/io.h>
#include <avr/interrupt.h>

int pin = 13;
volatile int state = LOW;
int count = 0;

void init_time()
{
  TCCR2A |= (1 << WGM21) | (1 << WGM20);
  TCCR2B |= (1 << CS22);
  TCCR2B &= ~((1 << CS21) | (1 << CS20));
  TCCR2B &=~((1 << WGM21) | (1 << WGM20));
  ASSR |= (1 << AS2);
  TIMSK2 |= (1 << TOIE2) | (0 << OCIE2B);
  TCNT2 = 6;
  sei();
}
SIGNAL(SIG_OVERFLOW2)
{
  TCNT2 = 6;
  ++count;
  if(count == 1000)
  {
    Serial.print("$ ");
    count = 0;
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(pin,OUTPUT);
//  attachInterrupt(0,blink,CHANGE);
  Serial.begin(115200);
  init_time();
}

void loop() {
  // put your main code here, to run repeatedly:
//  digitalWrite(pin,state);
  Serial.println("start ... ... ");
  while(1)
  {
    delay(100);
  }
}
void blink()
{
  state = !state;
  digitalWrite(pin,state);
}

