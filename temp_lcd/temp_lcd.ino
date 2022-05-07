#include <LiquidCrystal.h>
#include <DHT.h>
g
#define TEMP_PIN 3
#define DHT_MODEL DHT11

LiquidCrystal lcd(7,8,9,10,11,12);
DHT dht(TEMP_PIN, DHT_MODEL);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Humid    ");
  lcd.print("Temp ");
  
  dht.begin();
}

void loop() {
  delay(2000);

  float Humidity = dht.readHumidity();
  float Temperature = dht.readTemperature();

  if (isnan(Humidity) || isnan(Temperature)) {
    Serial.println("ERROR");
    lcd.setCursor(0, 1);
    lcd.print("     ERROR     ");
    return;
  }

   Serial.print("温度: ");
   Serial.print(Temperature);
   Serial.print("[℃]");
 
   Serial.print("  湿度: "); 
   Serial.print(Humidity);  
   Serial.println("[%]");

   lcd.setCursor(0, 1);
   lcd.print(Humidity);
   lcd.print("%  ");
   lcd.print(Temperature);
   lcd.print("C");
}
