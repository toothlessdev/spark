#ifndef DISPLAY_H
#define DISPLAY_H

#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Wire.h>

extern int dhtPin;
extern LiquidCrystal_I2C lcd;
float prev_humid = 0, prev_temp = 0;
DHT dht(dhtPin, DHT11);

class Display{
  public:
    //Display();
    void initDisplay();
    void displayTempHumid();
    void displayDiscomfortIdx();
    void displayExpectedTime(int expectedTime);
};


void Display::initDisplay(){
  lcd.init();
  lcd.backlight();
}

void Display::displayTempHumid(){
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();

  if((int)humid == 0 && (int)temp == 0){
    lcd.init();
    lcd.setCursor(0,0);
    lcd.print("Humid: ");
    lcd.print(prev_humid);
    lcd.setCursor(0,1);
    lcd.print("Temp : ");
    lcd.print(prev_temp);
  }
  else{
    prev_humid = humid;
    prev_temp = temp;
    lcd.init();
    lcd.setCursor(0,0);
    lcd.print("Humid: ");
    lcd.print(humid);
    lcd.setCursor(0,1);
    lcd.print("Temp : ");
    lcd.print(temp);
  }
}

void Display::displayDiscomfortIdx(){
  float discomfort_idx = 1.8*prev_temp-0.55*(1-prev_humid/100)*(1.8*prev_temp-26)+32;
  lcd.init();
  lcd.setCursor(0,0);
  lcd.print("Discomfort Index");
  lcd.setCursor(0,1);
  lcd.print(discomfort_idx);
}

void Display::displayExpectedTime(int expectedTime){
  lcd.init();
  lcd.setCursor(0,0);
  lcd.print("WELCOME!!");
  lcd.setCursor(0,1);
  lcd.print("Time : ");
  lcd.print(expectedTime);
}

#endif
