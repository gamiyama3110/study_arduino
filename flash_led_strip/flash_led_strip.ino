#include <Adafruit_NeoPixel.h>

const int DIN_PIN = 12;
const int LED_COUNT = 6;

Adafruit_NeoPixel pixels(LED_COUNT, DIN_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  pixels.begin();

  flash_led(0, pixels.Color(16, 0, 0));
  delay(300);
  flash_led(0, pixels.Color(0, 16, 0));
  delay(300);
  flash_led(0, pixels.Color(0, 0, 16));
  delay(300);
}

void loop() {
  for (int i=0; i<LED_COUNT; i++){
    flash_led(i, pixels.Color(0,0,16));
    delay(100);
  }
}

void flash_led(int index, uint32_t color) {
  pixels.clear();
  pixels.setPixelColor(index, color);
  pixels.show();
}
