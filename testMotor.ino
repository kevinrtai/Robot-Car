//Motor pins
const int motor1a = 8;
const int motor1b = 9;
const int motor1En = 12;
const int motor2a = 10;
const int motor2b = 11;
const int motor2En = 13;

void setup() {
  pinMode(motor1a, OUTPUT); 
  pinMode(motor1b, OUTPUT);
  pinMode(motor2a, OUTPUT);
  pinMode(motor2b, OUTPUT);
}

void loop() {
  digitalWrite(motor1a, HIGH);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2a, HIGH);
  digitalWrite(motor2b, LOW);
  digitalWrite(motor1En, HIGH);
  digitalWrite(motor2En, HIGH);
}
