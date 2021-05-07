#define PIN_LED1 13
#define BOUTON 2

#define pas 2
char data;
int etat=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED1,OUTPUT);
  digitalWrite(PIN_LED1,LOW);
  Serial.begin(9600);
  int test=0;

}

void loop() {
  // put your main code here, to run repeatedly:
   if(Serial.available())
   {
     
    
   
    
  data = Serial.read();
   if(data == '2')
  {
    while(data!=2)
    {
    digitalWrite(PIN_LED1,HIGH);
    delay(500);
    digitalWrite(PIN_LED1,LOW);
    delay(500);
    }
  }
   }


   
 /* if(Serial.available())
  {
    data = Serial.read();
    if(data == '1')
    {
      digitalWrite(PIN_LED2,HIGH);
      Serial.write('1');
    }
    else if(data == '0')
    {
      digitalWrite(PIN_LED2,LOW);
      Serial.write('0');
    }
    else if(data == '2')
    {
      if(x+pas <=255)
     x+=pas;
     analogWrite(PIN_LED1,x);
    }
    else if(data == '3')
    {
      if((x>pas))
      x=x-pas;
      else
      x=0;
      analogWrite(PIN_LED1,x);
    }
  }*/

}
