#include <LiquidCrystal.h>
#include "pitches.h"

// sound conf
const int DURATION = 80;
const int AUDIO_PIN = 13;

const int START_MELODY[] = {
  NOTE_G4, NOTE_B4, NOTE_D5, -1
};

const int DRY_MELODY[] = {
  NOTE_C4, 0, NOTE_C4, 0, NOTE_C4, -1
};

// sensor conf
const int SENSOR_PIN = 7;
const int FREQUENCY = 1 * 1000;

const int WATER_VALUE = 360;
int air_value = 600;
int intervals = (air_value - WATER_VALUE)/3;
int soil_moisture_value = 0;

bool is_dry = false;

// indicator
const int INDICATOR_PIN = 2;

// lcd
LiquidCrystal lcd(7,8,9,10,11,12);

void setup() {
  
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  pinMode(INDICATOR_PIN, OUTPUT);

  for (int i=0; i<3; i++) {
    flash_led();
  }
  
  sound(START_MELODY);
}

void loop() {
  
  soil_moisture_value = analogRead(SENSOR_PIN);
  Serial.println(soil_moisture_value);
    
  if (soil_moisture_value > (WATER_VALUE + intervals)) {
    update_dry_flg(true);
  } else {
    update_dry_flg(false);
  }

//  update_lcd();

  delay(FREQUENCY);
}

void flash_led() {
  
  digitalWrite(INDICATOR_PIN, HIGH);
  delay(200);
  digitalWrite(INDICATOR_PIN, LOW);
  delay(200);
}

void update_lcd() {

  lcd.clear(); 
  lcd.print("moisture");
  lcd.print(":");
  lcd.print(soil_moisture_value);
  lcd.setCursor(0, 1);
  if (is_dry) {
    lcd.print("please, water!!!");
  } else {
    lcd.print("ok, sir.");
  }
}

void update_dry_flg(bool flg) {
  
  if (is_dry != flg && flg == true) {
    sound(DRY_MELODY);
  } else if (is_dry != flg && flg == false) {
    sound(START_MELODY);
  }

  if (flg) {
    flash_led();
  }
  
  is_dry = flg;
}

void sound(int* melody) {
  
  for (int i = 0; melody[i] != -1; i++) {
    tone(AUDIO_PIN, melody[i], DURATION);
    delay(DURATION);
  }
}
