#include <DHT.h>

#define TEMP_PIN 3
#define DHT_MODEL DHT11

DHT dht(TEMP_PIN, DHT_MODEL);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);

  float Humidity = dht.readHumidity();
  float Temperature = dht.readTemperature();

  if (isnan(Humidity) || isnan(Temperature)) {
    Serial.println("ERROR");
    return;
  }

   Serial.print("温度: ");
   Serial.print(Temperature);
   Serial.print("[℃]");
 
   Serial.print("  湿度: "); 
   Serial.print(Humidity);  
   Serial.println("[%]");
}
