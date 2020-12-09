#ifndef SMARTBENCH_H
#define SMARTBENCH_H

#include <Servo.h>

extern Servo servo;

class SmartBench{
  private:
    int cdsPin;
    int servoPin;
  public:
    SmartBench(int cdsPin);
    void setBench();
    void rotateServo(int angle);
    float getBright();
};

SmartBench::SmartBench(int cdsPin){
  this->cdsPin = cdsPin;
}

void SmartBench::setBench(){
  float bright = getBright();
  Serial.print("Bench Cds : ");
  Serial.println(bright);
  

  if(bright >= 200){
    Serial.println("Rotate = 90");
    servo.write(90);
    delay(200);
  }
  else if(bright < 200) {
    Serial.println("Rotate = 180");
    servo.write(180);
    delay(200);
  }
}
void SmartBench::rotateServo(int angle){
  servo.write(angle);
  delay(500);
}
float SmartBench::getBright(){
  return analogRead(cdsPin);
}

#endif
