int trig = 3;
int echo = 2;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {

  digitalWrite(trig, LOW);
  delayMicroseconds(1);

  digitalWrite(trig, HIGH);
  delayMicroseconds(11);

  digitalWrite(trig, LOW);

  int t = pulseIn(echo, HIGH);
  float distance = t * 0.017;

  Serial.print(distance);
  Serial.println(" cm");
  delay(500);

}
