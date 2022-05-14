#include <Wire.h>
#include <DS3231.h>
#include <time.h>

RTClib rtc;
DS3231 ds_clock;
const int setup_button_pin = 12;

int year, month, day, hour, minute, seconds;
long current_time, display_time;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(setup_button_pin, INPUT);

  Serial.println("start.");
}

void loop() {
  current_time = millis();
  print_time(rtc.now());
  text_import();
  
  if (digitalRead(setup_button_pin) == HIGH) {
    setup_time();
//    Serial.println("pushed setup_button");
  } 

  delay(100);
}

void print_time(DateTime time) {
  if (current_time - display_time < 1000) {
    return;
  }

  Serial.print(time.year(), DEC);
  Serial.print('/');
  Serial.print(time.month(), DEC);
  Serial.print('/');
  Serial.print(time.day(), DEC);
  Serial.print(' ');
  Serial.print(time.hour(), DEC);
  Serial.print(':');
  Serial.print(time.minute(), DEC);
  Serial.print(':');
  Serial.print(time.second(), DEC);
 
  if (year >= 1900) {
    Serial.print("(inputed time: ");
    Serial.print(year);
    Serial.print("/");
    Serial.print(month);
    Serial.print("/");
    Serial.print(day);
    Serial.print(" ");
    Serial.print(hour);
    Serial.print(":");
    Serial.print(minute);
    Serial.print(":");
    Serial.print(seconds);
    Serial.print(")");
  }
  Serial.println();
  display_time = millis();
}

void text_import(void) {
  if (!Serial.available()) {
    return;
  }

  String value = Serial.readString();
  value.trim();
  if (value.length() <= 0) {
    return;
  }

  // 20220514012345
  year = value.substring(0, 4).toInt();
  month = value.substring(4,6).toInt();
  day = value.substring(6, 8).toInt();
  hour = value.substring(8, 10).toInt();
  minute = value.substring(10, 12).toInt();
  seconds = value.substring(12, 14).toInt();
}

void setup_time(void) {
  if (year < 1900) {
      return;
  }

  ds_clock.setClockMode(false);
  ds_clock.setYear(year);
  ds_clock.setMonth(month);
  ds_clock.setDate(day);
  ds_clock.setHour(hour);
  ds_clock.setMinute(minute);
  ds_clock.setSecond(seconds);

  Serial.println("DS3231 clock updated.");
  year = 0;
}
