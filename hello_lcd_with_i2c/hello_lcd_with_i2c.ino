#include <LiquidCrystal_I2C.h>

// アドレス0x27 16文字2行の液晶
// アドレスはモジュールの仕様書を確認
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();

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
