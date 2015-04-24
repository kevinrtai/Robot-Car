//Motor pins
const int motor1a = 4;
const int motor1b = 5;
const int motor1En = 3;
const int motor2a = 7;
const int motor2b = 8;
const int motor2En = 6;
int m1aState= LOW;
int m1bState = LOW;
int m1EnState= LOW;
int m2aState= LOW;
int m2bState= LOW;
int m2EnState= LOW;

//Initialization function
void setup() {
  //Put each pin in the correct mode. In this case, since we're
  //only controlling motors, we put all pins to ouput mode.
  pinMode(motor1a, OUTPUT); 
  pinMode(motor1b, OUTPUT);
  pinMode(motor2a, OUTPUT);
  pinMode(motor2b, OUTPUT);
  pinMode(motor1En, OUTPUT);
  pinMode(motor2En, OUTPUT);
}

//Infinite loop called automatically by the Arduino board
void loop() {
  //Digital write writes a value, HIGH or LOW to the output port
  digitalWrite(motor1a, LOW);
  digitalWrite(motor1b, HIGH);
  digitalWrite(motor2a, HIGH);
  digitalWrite(motor2b, LOW);
  digitalWrite(motor1En, HIGH);
  digitalWrite(motor2En, HIGH);
}

void turnCounterClockwise()
{
  //left motor backwards, right motor forward
  digitalWrite(motor1En, HIGH);
  m1EnState= HIGH;
  digitalWrite(motor1a, HIGH);
  m1aState= HIGH;
  digitalWrite(motor1b, LOW);
  m1bState= LOW;
  digitalWrite(motor2En, HIGH);
  m2EnState= LOW;
  digitalWrite(motor2a, LOW);
  m2aState= LOW;
  digitalWrite(motor2b, HIGH);
  m2bState= LOW;
}

void turnClockwise(){
  //left motor forward, right motor backwards
  digitalWrite(motor1En, HIGH);
  m1EnState= HIGH;
  digitalWrite(motor1a, LOW);
  m1aState= HIGH;
  digitalWrite(motor1b, HIGH);
  m1bState= LOW;
  digitalWrite(motor2En, HIGH);
  m2EnState= HIGH;
  digitalWrite(motor2a, HIGH);
  m2aState= LOW;
  digitalWrite(motor2b, LOW);
  m2bState= HIGH;
}

void halt(){
  //stops motors by turning enables for both motors off
  digitalWrite(motor1En, LOW);
  m1EnState= LOW;
  digitalWrite(motor2En, LOW);
  m2EnState= LOW;
}

void forward()
{
  //both motors forward
  digitalWrite(motor1En, HIGH);
  m1EnState= HIGH;
  digitalWrite(motor1a, HIGH);
  m1aState= HIGH;
  digitalWrite(motor1b, LOW);
  m1bState= LOW;
  digitalWrite(motor2En, HIGH);
  m2EnState= HIGH;
  digitalWrite(motor2a, HIGH);
  m2aState= HIGH;
  digitalWrite(motor2b, LOW);
  m2bState= LOW;
}

void backward() 
{
  //both motors back
  digitalWrite(motor1En, HIGH);
  m1EnState= HIGH;
  digitalWrite(motor1a, LOW);
  m1aState= LOW;
  digitalWrite(motor1b, HIGH);
  m1bState= HIGH;
  digitalWrite(motor2En, HIGH);
  m2EnState= HIGH;
  digitalWrite(motor2a, LOW);
  m2aState= LOW;
  digitalWrite(motor2b, HIGH);
  m2bState= HIGH;

}

void resume(){
  //restores states
 digitalWrite(motor1En, m1EnState);
 digitalWrite(motor1a, m1aState);
 digitalWrite(motor1b, m1bState);
 digitalWrite(motor2En, m2EnState);
 digitalWrite(motor2a, m2aState);
 digitalWrite(motor2b, m2bState);
}

  

