#include <LiquidCrystal.h>
#include "MQ135.h"

LiquidCrystal lcd(7,8,9,10,11,12);

const int AO_IN = A0;
// const int DO_IN = ;
const int interval = 1000;

MQ135 gasSensor = MQ135(AO_IN);

void setup() { 

  Serial.begin(9600);
  lcd.begin(16, 2);

  pinMode(AO_IN, INPUT);
  // pinMode(DO_IN, INPUT);

  // センサー抵抗値計測用
  // measure_sensor_resistor();
}

void loop() {
  
  measure_co2();
  delay(interval);
}

void measure_co2() {
    float ppm = gasSensor.getPPM();
    Serial.print("ppm: ");
    Serial.println(ppm);

    lcd.clear();
    lcd.print("CO2 conc.");

    lcd.setCursor(0, 1);
    lcd.print("ppm: ");
    lcd.print(ppm);
}

void measure_sensor_resistor() {
  
  uint32_t total_rzero = 0;
  int count = 0;
  while(true) {
    float rzero = gasSensor.getRZero();
    Serial.print("rzero: ");
    Serial.println(rzero);

    lcd.clear();
    lcd.print("rzero:");
    lcd.print(rzero);

    // 5分間隔（大体1秒間隔
    if (count >= 5 *1000 *60 /interval) {
      total_rzero = static_cast< double >(total_rzero / count);
      count = 1;
    }

    count++;
    lcd.setCursor(0, 1);
    total_rzero += rzero * 100.0;
    lcd.print("avg:");
    lcd.print(static_cast< double >(total_rzero / count / 100.0));
    delay(interval);
  }
}
