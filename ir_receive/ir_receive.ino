#include <IRremote.hpp>

const int receive_pin = 2;
const int indicator_pin = 3;
const int sender_button_pin = 12;

long pins_timer[13];
long current_time, indicator_timer;

IRrecv receiver(receive_pin);
unsigned long transmission;

void setup() {
  Serial.begin(9600);
  receiver.enableIRIn();
  pinMode(indicator_pin, OUTPUT);
  pinMode(sender_button_pin, INPUT);

  digitalWrite(indicator_pin, HIGH);
  delay(200);
  digitalWrite(indicator_pin, LOW);
  delay(200);
  Serial.println("start");
}

void loop() {
  current_time = millis();
  decode_results results;
  
  if (digitalRead(sender_button_pin) == HIGH && isEnabledSenderButton()) {
    indicator_timer = createTimeFromCurrentTime(1000); // インジケーターの点滅時間
    pins_timer[sender_button_pin] = createTimeFromCurrentTime(200); // ボタンの無効時間
    Serial.println("pushed");
    
  } else if (receiver.decode(&results))  {
    if (!isChangedDataForTransmission(results)) {
      receiver.resume();
      goto skip;
    }
    
    transmission = results.value;
//    Serial.println(transmission, HEX);
//    Serial.println(transmission);
    dump(&results);
    indicator_timer = createTimeFromCurrentTime(1000);
    receiver.resume();
    Serial.println("saved");
    
  }
  skip:

  flash_led(indicator_pin, indicator_timer);

//  free(&results);
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

// Dumps out the decode_results structure.
// Call this after IRrecv::decode()
// void * to work around compiler issue
//void dump(void *v) {
//  decode_results *results = (decode_results *)v
void dump(decode_results *results) {
  int count = results->rawlen;
  if (results->decode_type == UNKNOWN) {
    Serial.print("Unknown encoding: ");
  } 
  else if (results->decode_type == NEC) {
    Serial.print("Decoded NEC: ");
  } 
  else if (results->decode_type == SONY) {
    Serial.print("Decoded SONY: ");
  } 
  else if (results->decode_type == RC5) {
    Serial.print("Decoded RC5: ");
  } 
  else if (results->decode_type == RC6) {
    Serial.print("Decoded RC6: ");
  }
  else if (results->decode_type == PANASONIC) {  
    Serial.print("Decoded PANASONIC: ");
//    Serial.print("Decoded PANASONIC - Address: ");
//    Serial.print(results->panasonicAddress,HEX);
//    Serial.print(" Value: ");
  }
  else if (results->decode_type == LG) {
     Serial.print("Decoded LG: ");
  }
  else if (results->decode_type == JVC) {
     Serial.print("Decoded JVC: ");
  }
  Serial.print(results->value, HEX);
  Serial.print(" (");
  Serial.print(results->bits, DEC);
  Serial.println(" bits)");
  Serial.print("Raw (");
  Serial.print(count, DEC);
  Serial.print("): ");

  for (int i = 0; i < count; i++) {
    if ((i % 2) == 1) {
      Serial.print(results->rawbuf[i]*USECPERTICK, DEC);
    } 
    else {
      Serial.print(-(int)results->rawbuf[i]*USECPERTICK, DEC);
    }
    Serial.print(" ");
  }
  Serial.println("\n end");

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

//    Serial.print("light:");
//    Serial.println(lighted);
  } else if (terminated && lighted) {
    digitalWrite(pin, LOW);
  }

//  free(terminated);
//  free(gap);
//  free(lighted);
}
