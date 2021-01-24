#include<Servo.h>
Servo myservo;
// compulsory import parts for the servo

const int buttonPin = 2;
const int xPin = A0;
const int yPin = A1;
int servo = 9;


int horizontalposition;
int verticalposition;
int buttonposition;
int servoposition;

//  horizontal neutral (yPin) = 513
//  vertical neutral (xPin) = 491
//  0< <1023

void setup() {
  
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(servo, OUTPUT);

  myservo.attach(servo); //another compulsory code that includes servo in the code
  
}

void loop() {
  
  horizontalposition = analogRead(yPin);
  verticalposition = analogRead(xPin);
  buttonposition = !digitalRead(buttonPin);
 //xservoposition = analogRead(servo);
  //xservoposition = analogRead(servo);
  
  /*
  Serial.print(" Horizontal position is: ");
  Serial.print( horizontalposition );

  Serial.print(" Vertical position is: ");
  Serial.print( verticalposition );

  Serial.print(" Button position is: ");
  Serial.print( buttonposition );
  */
  Serial.print(" Servo position is: ");
  Serial.print( servoposition );
  Serial.print("\n");

  for (int i=0; i>= 20; i+=20){ // increment by 20 degrees
    myservo.write(i); 
    delay(1000);
  }
/*  analogWrite(servo, horizontalposition);
  delay(100);
*/
}
