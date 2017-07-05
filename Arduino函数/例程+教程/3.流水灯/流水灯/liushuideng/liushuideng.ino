int BASE = 2 ;  //第一颗LED 接的 I/O 脚
int NUM = 8;   //LED 的个数

void setup()
{
   for (int i = BASE; i < BASE + NUM; i ++) 
   {
     pinMode(i, OUTPUT);   //設定數字I/O腳為輸出
   }
}

void loop()
{
   for (int i = BASE; i < BASE + NUM; i++) 
   {
     digitalWrite(i, LOW);    //設定數字I/O腳輸出為"低"，即逐漸關燈
     delay(100);        //延遲
   }
   for (int i = BASE ; i < BASE + NUM; i++) 
   {
     digitalWrite(i, HIGH);    //設定數字I/O腳輸出為"低"，即逐漸開燈
     delay(100);        //延遲
   }  
}

