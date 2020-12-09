#ifndef BUZZER_H
#define BUZZER_H

typedef enum {
  C = 262, D = 294, E = 330, F = 349, G = 392, A = 440, B = 494
} Note;

class Buzzer{
  private:
    int buzzerPin;
  public:
    Buzzer(int buzzerPin);
    void playNote(Note n);
};

Buzzer::Buzzer(int buzzerPin){
  this->buzzerPin = buzzerPin;
}
void Buzzer::playNote(Note n){
  
}

#endif
