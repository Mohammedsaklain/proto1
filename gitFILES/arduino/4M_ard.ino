#include<LiquidCrystal.h>
int LED1=12;
int LED2=13;
int trigPin=11;
int echoPin=10;
long distance;
long duration;
int i;
int motorPin1=6;
int motorPin2=7;
int motorPin3=8;
int motorPin4=9;
int pc;
LiquidCrystal lcd(0,1,2,3,4,5);
void setup()
{
  pinMode(motorPin1,OUTPUT);
   pinMode(motorPin2,OUTPUT);
    pinMode(motorPin3,OUTPUT);
     pinMode(motorPin4,OUTPUT);
 lcd.begin(16,2);
  pinMode(trigPin,OUTPUT);
   pinMode(echoPin,INPUT);
    pinMode(LED1,OUTPUT);
    pinMode(LED2,OUTPUT);
    lcd.setCursor(0,0);
     lcd.print("Team 6");
       lcd.setCursor(0,1);
        lcd.print("23,24,25,26");
      for(int pc=0;pc<16;pc++)
      {
       lcd.scrollDisplayRight();
       delay(100);
      }
}

void loop()
{
 
  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("D-(cm): ");
  lcd.print(distance);
  delay(1000);
  if(distance<=100)
  {
    
     digitalWrite(motorPin1,LOW);
     digitalWrite(motorPin2,LOW);
     digitalWrite(motorPin3,LOW);
     digitalWrite(motorPin4,LOW);
     delay(500);
     digitalWrite(LED1,HIGH);
     digitalWrite(LED2,LOW);
     digitalWrite(motorPin1,LOW);
     digitalWrite(motorPin2,HIGH);
     digitalWrite(motorPin3,LOW);
     digitalWrite(motorPin4,LOW);
     delay(1000);
  
  }
  else
     {
     digitalWrite(motorPin1,HIGH);
     digitalWrite(motorPin2,LOW);
     digitalWrite(motorPin3,HIGH);
     digitalWrite(motorPin4,LOW);
     digitalWrite(LED1,LOW);
     digitalWrite(LED2,HIGH);
     }
}
