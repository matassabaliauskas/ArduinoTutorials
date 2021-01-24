const int ledPin1 = 9;
const int ledPin2 = 10;
const int ledPin3 = 11;

const int varPin = A0;
int varval = 0;
int vardelay;

int red = 0;      //LEVELS
int green = 0;
int blue = 0;

int redup = 4;
int greenup = 5;
int blueup = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  pinMode(varPin, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  varval = analogRead(varPin);
  Serial.print(varval);
  Serial.print("\n");
  
  digitalWrite(ledPin1, red);
  analogWrite(ledPin2, green);
  analogWrite(ledPin3, blue);
  
  red = red + redup;
  green = green + greenup;
  blue = blue + blueup;
  
  if(red >= 255 || red < 1){redup = -redup;}
  
  if(green >= 255 || green < 1){greenup = -greenup;}
  
  if(blue >= 255 || blue < 1){blueup = -blueup;}

  vardelay = varval/50;
  delay(vardelay);
}
