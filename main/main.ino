#include "Display.h"
#include "Game.h"
#include "SmartBench.h"
#include <Servo.h>

int servoPin = 2;
int buzzerPin = 3;
int btnPin = 4;
int laserPin = 5;
int benchCds = A1;
int dhtPin = A2;
int cdsPin = A3;
int elapsedTime = 0;

SmartBench bench(benchCds);
Game shootingGame(cdsPin, buzzerPin);
Display lcdDisplay;

Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void shootLaser();

void setup() {
  Serial.begin(19200);
  servo.attach(servoPin);
  lcd.init();
  lcd.backlight();

  pinMode(btnPin, INPUT);
  pinMode(laserPin, OUTPUT);
}

void loop() {
  delay(1000);
  elapsedTime++; 

  Serial.println("--------------------------");
  Serial.print("ElapsedTime : ");
  Serial.println(elapsedTime);
      
  switch(elapsedTime % 9){
    case 0:
      Serial.println("displayTempHumid()");
      lcdDisplay.displayTempHumid(); break;
    case 1:
      Serial.println("displayTempHumid()");
      lcdDisplay.displayTempHumid(); break;
    case 2:
      Serial.println("displayTempHumid()");
      lcdDisplay.displayTempHumid(); break;
    case 3:
      Serial.println("displayDiscomfortIdx()");
      lcdDisplay.displayDiscomfortIdx(); break;
    case 4:
      Serial.println("displayDiscomfortIdx()");
      lcdDisplay.displayDiscomfortIdx(); break;
    case 5:
      Serial.println("displayDiscomfortIdx()");
      lcdDisplay.displayDiscomfortIdx(); break;
    case 6:
      Serial.println("displayExpectedTime()");
      lcdDisplay.displayExpectedTime(elapsedTime); break;
    case 7:
      Serial.println("displayExpectedTime()");
      lcdDisplay.displayExpectedTime(elapsedTime); break;
    case 8:
      Serial.println("displayExpectedTime()");
      lcdDisplay.displayExpectedTime(elapsedTime); break;
  }

  if(digitalRead(btnPin) == HIGH) shootLaser();
  else digitalWrite(laserPin, LOW);
  
  shootingGame.detectCdsValue();
  bench.setBench(); 
}

void shootLaser(){
  digitalWrite(laserPin, HIGH);
  delay(200);
  digitalWrite(laserPin,LOW);
}
