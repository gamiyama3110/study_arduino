#include "pitches.h"

const int DURATION = 80;
const int AUDIO_PIN = 2;

int melody[] = {  //配列を定義 melodyという変数に下記64個の値を格納、０は周波数０ということ音がでない
  NOTE_C5,  0, NOTE_D5,  0, NOTE_E5,  0, NOTE_F5,  0, NOTE_E5,  0, NOTE_D5,  0, NOTE_C5,  0,  0,  0,
  NOTE_E5,  0, NOTE_F5,  0, NOTE_G5,  0, NOTE_A5,  0, NOTE_G5,  0, NOTE_F5,  0, NOTE_E5,  0,  0,  0,
  NOTE_C5,  0,  0,  0, NOTE_C5,  0,  0,  0, NOTE_C5,  0,  0,  0, NOTE_C5,  0,  0,  0,
  NOTE_C5, NOTE_C5, NOTE_D5, NOTE_D5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_F5, NOTE_E5,  0, NOTE_D5,  0, NOTE_C5,  0,  0,  0 , -1};

const int START_MELODY[] = {
  NOTE_G4, NOTE_B4, NOTE_D5, -1
};

const int DRY_MELODY[] = {
  NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, -1
};

void setup() {
  sound(START_MELODY);
  delay(2000);

  sound(DRY_MELODY);
  delay(2000);
}

void loop() {
  sound(START_MELODY);
  delay(2000);
}

void sound(int* melody) {
  
  for (int i = 0; melody[i] != -1; i++) {
    tone(AUDIO_PIN, melody[i], DURATION);
    delay(DURATION);
  }
}
