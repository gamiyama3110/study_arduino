const int LED_PIN = 13;
const int INPUT_PIN = 2;
int val;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(INPUT_PIN, INPUT);
  Serial.begin(9600);  

}

void loop() {
  val = digitalRead(INPUT_PIN);
  digitalWrite(LED_PIN, val);
  Serial.println(val);
  delay(500);
}
