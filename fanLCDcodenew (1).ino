#include <Wire.h>
#include <DS1307RTC.h>
#include "RTClib.h"
#include <LiquidCrystal.h>
RTC_DS1307 rtc;

int speedPin = 9;
int dir1 = 8;
int dir2 = 10;
int mSpeed = 150;
int btn=0;
const int buttonApin = 12;
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2); 
   if (! rtc.begin()) 
  {
    lcd.print("Couldn't find RTC");
    while (1);
  }
  if (! rtc.isrunning()) 
  {
    lcd.print("RTC is NOT running!");
  }
  
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  pinMode(buttonApin, INPUT);
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);                           
}

void loop() {
 lcd.setCursor(0,1);
 lcd.print("Time:  ");
 DateTime now = rtc.now();
 Serial.println(now.second());
 lcd.print(now.hour());
 lcd.print(':');
 lcd.print(now.minute());
 lcd.print(':');
 lcd.print(now.second());
 lcd.print("   ");
 delay(1000);
  // put your main code here, to run repeatedly
if (now.second() > 30){
  btn=0;
  lcd.begin(16,2);
  lcd.setCursor(0, 0);
  lcd.print("Speed: 0");
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, LOW);
  analogWrite(speedPin, 0);
}
  
if (now.second() < 30){
  if (digitalRead(buttonApin)== HIGH){
    btn=btn+1;
    delay(500);
  }
  if (btn==0){
    lcd.begin(16,2);
    lcd.setCursor(0, 0);
    lcd.print("Speed: 0");
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, LOW);
    analogWrite(speedPin, 0);
}
  
  else if (btn==1){
    lcd.begin(16,2);
    lcd.setCursor(0, 0);
    lcd.print("Speed: 1/2 C");
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    //analogWrite(speedPin, 255);
    delay(100);
    analogWrite(speedPin,127);

  }
  else if (btn==2){
    lcd.begin(16,2);
    lcd.setCursor(0, 0);
    lcd.print("Speed: 3/4 C");
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    //analogWrite(speedPin, 255);
    delay(100);
    analogWrite(speedPin,191);

  }
  else if (btn==3){
    lcd.begin(16,2);
    lcd.setCursor(0, 0);
    lcd.print("Speed: FULL C");
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    //analogWrite(speedPin, 255);
    delay(100);
    analogWrite(speedPin,255);

  }
  else if (btn==4){
    lcd.begin(16,2);
    lcd.setCursor(0, 0);
    lcd.print("Speed: 1/2 CC");
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    //analogWrite(speedPin, 255);
    delay(100);
    analogWrite(speedPin,127);
 
  }
  else if (btn==5){
    lcd.begin(16,2);
    lcd.setCursor(0, 0);
    lcd.print("Speed: 3/4 CC");
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    //analogWrite(speedPin, 255);
    delay(100);
    analogWrite(speedPin,191);

  }
  else if (btn==6){
    lcd.begin(16,2);
    lcd.setCursor(0, 0);
    lcd.print("Speed: FULL CC");
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    //analogWrite(speedPin, 255);
    delay(100);
    analogWrite(speedPin,255);
  }
  else if (btn>6){
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW);
    //analogWrite(speedPin, 255);
    delay(100);
    analogWrite(speedPin,0); 
    
    btn=0;
  }
}
}
