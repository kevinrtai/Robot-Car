//Motor pins
const int motor1a = 8;
const int motor1b = 9;
const int motor1En = 12;
const int motor2a = 10;
const int motor2b = 11;
const int motor2En = 13;

//Initialization function
void setup() {
  //Put each pin in the correct mode. In this case, since we're
  //only controlling motors, we put all pins to ouput mode.
  pinMode(motor1a, OUTPUT); 
  pinMode(motor1b, OUTPUT);
  pinMode(motor2a, OUTPUT);
  pinMode(motor2b, OUTPUT);
}

//Infinite loop called automatically by the Arduino board
void loop() {
  //Digital write writes a value, HIGH or LOW to the output port
  digitalWrite(motor1a, HIGH);
  digitalWrite(motor1b, LOW);
  digitalWrite(motor2a, HIGH);
  digitalWrite(motor2b, LOW);
  digitalWrite(motor1En, HIGH);
  digitalWrite(motor2En, HIGH);
}
