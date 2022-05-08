#include <IRremote.hpp>

const int receive_pin = 2;
const int indicator_pin = 3;
const int sender_button_pin = 12;

long pins_timer[13];
long current_time, indicator_timer;

IRrecv receiver(receive_pin);
decode_results results;

void setup() {
  Serial.begin(9600);
  receiver.enableIRIn();
  pinMode(indicator_pin, OUTPUT);
  pinMode(sender_button_pin, INPUT);
  
}

void loop() {
  current_time = millis();

  if (digitalRead(sender_button_pin) == HIGH) {
    indicator_timer = current_time + 1000;
    Serial.println("pushed");
    
  } else if (receiver.decode(&results))  {
//    Serial.println(results.value, HEX);
    Serial.println(results.value);
    indicator_timer = current_time + 1000;
    receiver.resume();
    
  }

  flash_led(indicator_pin, indicator_timer);
//  delay(10);
}

/*
 * LEDの点滅
 * 対象LEDのpinと点滅終了時刻（通算ミリ秒）を指定すると、終了時刻まで繰り返し点滅する。
 * delayを使ってないので点滅中に処理が止まることがない。マルチスレッド使えるrasp piつよい。
 */
void flash_led(int pin, long time) {
  bool terminated = time - current_time < 0;
  long gap = current_time - pins_timer[pin];
  bool lighted = digitalRead(pin)==HIGH;
  
  if (!terminated &&  gap > 300) {
    digitalWrite(pin, lighted ?0:1);
    pins_timer[pin] = current_time;
    
  } else if (terminated && lighted) {
    digitalWrite(pin, LOW);
  }
}
