#include<LiquidCrystal.h>
//#include<DHT.h>
//#define Type DHT11

int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

int echoPin=5;
int trigPin=4  ;
int pingTravelTime;
float SOS;
float pingTravelDistance;
float distanceToTarget;
int dt=100;

//int sensePin=2;
//DHT HT(sensePin,Type);
//float hmdty;
//float tempC;
//float tempF;
//int setTime=500;


#include <Servo.h>
int servoPin=6;
Servo myServo;


void setup() {
  // put your setup code here, to run once:
//HT.begin();
Serial.begin(9600);
lcd.begin(16,2);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);

myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:


digitalWrite(trigPin,LOW);
delayMicroseconds(10);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);

pingTravelTime=pulseIn(echoPin,HIGH);
delay(25);

SOS=334;

pingTravelDistance=(343.0/1000000.0)*pingTravelTime*100;
distanceToTarget=(pingTravelDistance/2);
Serial.print("Distance to Target is: ");
Serial.print(distanceToTarget);
Serial.println(" cm.");
lcd.setCursor(0,0);
lcd.print("Target Distance:");
lcd.setCursor(0,1);
lcd.print(distanceToTarget);
lcd.print(" cm. ");
delay(dt);
lcd.clear();

if(distanceToTarget<20.0){
myServo.write(90);
//delay(100);
}
if(distanceToTarget>20.0){
myServo.write(0);
}
}