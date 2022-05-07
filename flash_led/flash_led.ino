int led_board = 13;
int led = 2;
int gap = 300;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(led_board, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);
  digitalWrite(led_board, HIGH);
  delay(gap);
  digitalWrite(led, LOW);
  digitalWrite(led_board, LOW);
  delay(gap);
}
