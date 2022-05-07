#include "pitches.h"

const int AUDIO_PIN = 2;

unsigned int tempo = 128;
const int START_MELODY[][2] = {
  {NOTE_G4, 8}, {NOTE_B4, 8} , {NOTE_D5, 1}, {-1, -1}
};

const int DRUM_MELODY[][2] = {
  {NOTE_F2, 4}, {NOTE_F2, 4} , {NOTE_C3, 4}, {NOTE_F2, 4},
  {NOTE_F2, 4}, {NOTE_F2, 4} , {NOTE_A2, 4}, {NOTE_F2, 4},
  {NOTE_F2, 4}, {NOTE_F2, 4} , {NOTE_C3, 4}, {NOTE_F2, 4},
  {NOTE_F2, 4}, {NOTE_F2, 4} , {NOTE_G2, 4}, {NOTE_F2, 4},
  {-1, -1}
};

void setup() {
  Serial.begin(9600);
  sound(START_MELODY);
  delay(1000);
}

void loop() {
  tempo = 64;
  sound(DRUM_MELODY);
}

void sound(int melody[][2]) {
  for (int i = 0; melody[i][0] != -1; i++) {
    unsigned int d =  1000 *60 /tempo /melody[i][1];
    tone(AUDIO_PIN, melody[i][0], d);
    delay(d);
  }
}
