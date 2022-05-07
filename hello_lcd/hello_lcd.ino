#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);

void setup() {
  lcd.begin(16,2);
  lcd.print("hello world!");

  lcd.setCursor(0,1);
  lcd.print("let's enjoy");
}

void loop() {
//  lcd.noBlink();
  lcd.noCursor();
//  lcd.noDisplay();
  delay(500);

//  lcd.blink();
  lcd.cursor();
//  lcd.display();
  delay(1000);
}
