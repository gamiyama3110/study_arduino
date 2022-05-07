#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, 9, 10, 11, 13, 12);

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  hello_world();
  
}

void loop() {
}

void hello_world(void) {
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.cp437(true);
  display.print("hello world!");
  
//  display.setCursor(0,1);
//  display.print("let's enjoy");

  display.display();
  delay(2000);
}
