const int ledPin1 = 9;        //RED
const int ledPin2 = 10;       //GREEN
const int ledPin3 = 11;       //BLUE

const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;


int buttonstate1;
int buttonstate2;
int buttonstate3;

int brightness1 = 0;
int brightness2 = 0;
int brightness3 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
}

void loop() {
  buttonstate1 = digitalRead(buttonPin1);
  buttonstate2 = digitalRead(buttonPin2);
  buttonstate3 = digitalRead(buttonPin3);

  
  if(buttonstate1 == LOW){
    brightness1 = brightness1 + 5;
    Serial.print("RED ");
  }
  if(buttonstate2 == LOW){
    brightness2 = brightness2 + 5;
    Serial.print("GREEN ");
  }
  if(buttonstate3 == LOW){
    brightness3 = brightness3 + 5;
    Serial.print("BLUE ");
  }
  
  analogWrite(ledPin1, brightness1);
  analogWrite(ledPin2, brightness2);
  analogWrite(ledPin3, brightness3);

  if(brightness1 >= 255){brightness1 = 0;}
  if(brightness2 >= 255){brightness2 = 0;}
  if(brightness3 >= 255){brightness3 = 0;}
  
  delay(100);
}

