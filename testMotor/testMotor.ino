<<<<<<< HEAD
//Motor pins
const int motor1a = 8;
const int motor1b = 9;
const int motor1En = 12;
const int motor2a = 10;
const int motor2b = 11;
const int motor2En = 13;

//Sensor pins
const int photoLeft = A0;
const int photoRight = A1;
const int photoCenter = A2;
const int irLeft = A3;
const int irRight = A4;
const int irFront= A5;

//State
=======
//Motor pins. 1 is right motor, 2 is left motor
const int motor1a = 4;
const int motor1b = 5;
const int motor1En = 3;
const int motor2a = 7;
const int motor2b = 8;
const int motor2En = 6;

//Motor states
>>>>>>> origin/master
int m1aState= LOW;
int m1bState = LOW;
int m1EnState= LOW;
int m2aState= LOW;
int m2bState= LOW;
int m2EnState= LOW;

<<<<<<< HEAD
//input values
const int photolBlack= 0;
const int photorBlack= 0;
const int photocBlack= 0;
const int photocREd= 0;
const int irClose= 1.5; //1.5 V threshold

//Initialization function
void setup() {
  //Put each pin in the correct mode.
  //Motors are in OUTPUT mode
=======
//Button pin
const int buttonPin = 12;

//Button starting

//Initialization function
void setup() {
  //Put each pin in the correct mode. 
  //Motor control pins are output
>>>>>>> origin/master
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
<<<<<<< HEAD
  //Digital write writes a value, HIGH or LOW to the output port
  //test sequence
  forward();
  delay (1000);
  backward();
  delay(1000);
  turnCounterClockwise();
  delay(1000);
  turnClockwise();
  delay(1000);
  correctToRight();
  correcToLeft();
  
  
  //line following- in progress
  /*
   if (analogRead(photoCenter== photocRed)
     halt();
     delay(500);
   else if (analogRead(irFront== irFrontClose))
     halt();
     delay(500);
   else{
      if((analogRead(photoCenter)==photocBlack)&& (analogRead(photoRight)!=photolBlack)&&(analogRead(photoLeft!=photolBlack))){
        forward();
        delay(500);
      
      }
    
    if((analogRead(photoLeft)!= photoBlack)&&(analogRead(photoRight)!= photoBlack)&&(analogRead(photoCenter)!=photocBlack)){
      backward()
      delay(500);
      halt();
     
    }
     if((analogRead(photoLeft)!= photolBlack)&&(analogRead(photoCenter)!=photocBlack)&&(analogRead(photoRight)==photorBlack)){
       correctToRight();
       delay(500);
       halt();
   
    }
    
    if ((analogRead(photoRight)!= photoBlack)&&(photoLeft)==photoBlack)){
     correctToLeft();
     delay(500);
     halt();
    }
    if ((analogRead(irLeft)>= irClose){
      correctToRight();
      delay(500);
      halt();
    }
    if (analogRead(irLeft)>=irClose){
      correctToLeft();
      delay(500);
      halt();
  
  
  }    */
  
}


void correctToRight(){
   turnClockwise();
   delay(500);
   forward();
   delay(500);
   turnCounterClockwise();
   delay(500);
   halt(); 
}

void correctToLeft(){
   turnCounterClockwise();
   delay(500);
   forward();
   delay(500);
   turnClockwise();
   delay(500);
   halt();
=======
  int button = digitalRead(buttonPin);
  if(button == HIGH) {
    forward();
  }
  else if(button == LOW) {
    halt();
  }

  //Wait 50 milliseconds before starting the loop again
  delay(50);
>>>>>>> origin/master
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

  

