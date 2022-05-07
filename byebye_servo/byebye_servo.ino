#include <Servo.h>

Servo servo;
int servo_pin = 3;

void setup() {
  servo.attach(3);
}

void loop() {
  servo.write(0);
  delay(500);

  servo.write(30);
  delay(500);
}
