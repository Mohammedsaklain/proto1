#include<LiquidCrystal.h>
LiquidCrystal lcd(0,1,2,3,4,5);
int sensor =A0;
float tempc;
float temp;
int motorPin1=6;
int motorPin2=7;
int trigPin=9;
int echoPin=8;
long duration;
long distance;

void setup() 
{
  pinMode(motorPin1,OUTPUT);
  pinMode(motorPin2,OUTPUT);
  pinMode(sensor,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  lcd.begin(16,2);
}

void loop()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
        duration=pulseIn(echoPin,HIGH);
        temp=analogRead(sensor);
        tempc=(temp*500)/1023;
       distance=duration*0.034/2;
      lcd.setCursor(0,0);
      lcd.clear();
      lcd.print("D-(cm):");
      lcd.print(distance);
      lcd.setCursor(0,1);
      lcd.print(tempc);
       delay(200);
        digitalWrite(trigPin,LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin,HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin,LOW);
        duration=pulseIn(echoPin,HIGH);
        distance=duration*0.034/2;
        delay(1000);
 
  if(tempc<=25||distance>=200)
  {
    digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin2,LOW);
  }
   else
   digitalWrite(motorPin1,LOW);
   digitalWrite(motorPin2,HIGH);
}
