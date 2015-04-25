//Motor pins. 1 is right motor, 2 is left motor
const int motor1a = 4;
const int motor1b = 5;
const int motor1En = 3;
const int motor2a = 7;
const int motor2b = 8;
const int motor2En = 6;

//Motor states
int m1aState= LOW;
int m1bState = LOW;
int m1EnState= LOW;
int m2aState= LOW;
int m2bState= LOW;
int m2EnState= LOW;

//Button pin
const int buttonPin = 12;

//Toggle start and stop button
const int ACTIVE = 1;
const int INACTIVE = 0;
int carStatus = INACTIVE;

//Initialization function
void setup() {
  //Put each pin in the correct mode. 
  //Motor control pins are output
  pinMode(motor1a, OUTPUT); 
  pinMode(motor1b, OUTPUT);
  pinMode(motor2a, OUTPUT);
  pinMode(motor2b, OUTPUT);
  pinMode(motor1En, OUTPUT);
  pinMode(motor2En, OUTPUT);
  
  //Button pin is input
  pinMode(buttonPin, INPUT);
}

//Infinite loop called automatically by the Arduino board
void loop() {
  int button = digitalRead(buttonPin);
  if(button == HIGH) {
    //Toggle the car status
    if(carStatus == ACTIVE) {
      carStatus = INACTIVE; 
    }
    else {
      carStatus = ACTIVE;
    }
    
    //Wait for the button to be released
    while(button == HIGH) {
      button = digitalRead(buttonPin);
      delay(100);
    }
  }
  
  if(carStatus == ACTIVE) {
    forward();
  }
  else {
    halt();
  }

  //Wait 50 milliseconds before starting the loop again
  delay(50);
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

  

