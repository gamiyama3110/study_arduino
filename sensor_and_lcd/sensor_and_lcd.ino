#include <LiquidCrystal.h>

#define TrigPin 3
#define EchoPin 2

float ProDelay = 0;
float Distance = 0;

LiquidCrystal lcd(7,8,13,10,11,12);

void setup() {
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  
  lcd.begin(16, 2);
}

void loop() {
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(10);
  
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(TrigPin, LOW);

  ProDelay = pulseIn(EchoPin, HIGH);

  Serial.println(ProDelay * 0.017);
  
  if (ProDelay > 0) {
    Distance = 340 * ProDelay / 2 /10000;
    
//    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Dis. ");
//    lcd.setCursor(6, 0);
    lcd.print(Distance);
    lcd.print("cm");
  }
  delay(1000);
}
