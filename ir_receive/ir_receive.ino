#include <IRremote.hpp>

const int receive_pin = 2;
const int indicator_pin = 3;
const int sender_button_pin = 12;

long pins_timer[13];
long current_time, indicator_timer;

IRrecv receiver(receive_pin);
decode_results results;
unsigned long transmission;

void setup() {
  Serial.begin(9600);
  receiver.enableIRIn();
  pinMode(indicator_pin, OUTPUT);
  pinMode(sender_button_pin, INPUT);
}

void loop() {
  current_time = millis();
  
  if (digitalRead(sender_button_pin) == HIGH && isEnabledSenderButton()) {
    indicator_timer = createTimeFromCurrentTime(1000); // インジケーターの点滅時間
    pins_timer[sender_button_pin] = createTimeFromCurrentTime(200); // ボタンの無効時間
    Serial.println("pushed");
    
  } else if (receiver.decode(&results) && isChangedDataForTransmission(results))  {
    transmission = results.value;
    Serial.println(transmission, HEX);
//    Serial.println(transmission);
    indicator_timer = createTimeFromCurrentTime(1000);
    receiver.resume();
    
  }

  flash_led(indicator_pin, indicator_timer);
}

bool isChangedDataForTransmission(decode_results val) {
  return transmission != val.value;
}

bool isEnabledSenderButton() {
  return current_time > pins_timer[sender_button_pin];
}

long createTimeFromCurrentTime(long gap) {
  return current_time + gap;
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

    Serial.print("light:");
    Serial.println(lighted);
  } else if (terminated && lighted) {
    digitalWrite(pin, LOW);
  }
}
