#include "pitches.h"

int duration = 50;
int audio_pin = 2;

int melody[] = {  //配列を定義 melodyという変数に下記64個の値を格納、０は周波数０ということ音がでない
  NOTE_C5,  0, NOTE_D5,  0, NOTE_E5,  0, NOTE_F5,  0, NOTE_E5,  0, NOTE_D5,  0, NOTE_C5,  0,  0,  0,
  NOTE_E5,  0, NOTE_F5,  0, NOTE_G5,  0, NOTE_A5,  0, NOTE_G5,  0, NOTE_F5,  0, NOTE_E5,  0,  0,  0,
  NOTE_C5,  0,  0,  0, NOTE_C5,  0,  0,  0, NOTE_C5,  0,  0,  0, NOTE_C5,  0,  0,  0,
  NOTE_C5, NOTE_C5, NOTE_D5, NOTE_D5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_F5, NOTE_E5,  0, NOTE_D5,  0, NOTE_C5,  0,  0,  0 };

// 523, 659, 784
int start_melody[] = {
  NOTE_C5, NOTE_E5, NOTE_G5
};

void setup() {
//  sound(start_melody);
}

void loop() {
  sound(start_melody);
  delay(2000);
}

void sound(int* melody) {
  int arr_length = sizeof(melody) / sizeof(melody[0]);
  for (int i = 0; i < arr_length; i++) {       //0～63まで繰り返す。64になったらfor文を抜ける
    tone( audio_pin, melody[i], duration );  //ポートの8番に配列melodyの周波数で、0.2秒
    delay(duration);
  }
}
