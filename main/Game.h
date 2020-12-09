#ifndef GAME_H
#define GAME_H

typedef enum {
  C = 262, D = 294, E = 330, F = 349, G = 392, A = 440, B = 494, _C = 524
} Note;

class Game{
  private:
    int score;
    int cdsPin;
    int cdsValue;
    int buzzerPin;
  public:
    Game(int cdsPin, int buzzerPin);
    void detectCdsValue();
    void increaseScore();
    float getCds();
};

Game::Game(int cdsPin, int buzzerPin){
  this->score = 0;
  this->cdsPin = cdsPin;
  this->buzzerPin = buzzerPin;
  this->cdsValue = 0;
}
void Game::detectCdsValue(){
  float cdsValue = getCds();
  Serial.print("Game CDS : ");
  Serial.println(cdsValue);
  Serial.print("Game Score : ");
  Serial.println(score);
  
  if (cdsValue <= 100) {
    increaseScore();
    tone(buzzerPin, C, 250);
    delay(300);
    tone(buzzerPin, E, 250);
    delay(300);
    tone(buzzerPin, G, 250);
    delay(300);
    tone(buzzerPin, _C, 250);
    delay(300);
  }
}
void Game::increaseScore(){
  score++;
}
inline float Game::getCds(){
  return analogRead(this->cdsPin);
}

#endif
