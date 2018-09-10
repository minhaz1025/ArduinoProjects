int pinRed = 9;
int pinBlue = 10;
int pinGreen = 11;

void setup() {
  pinMode(pinRed, OUTPUT);
  pinMode(pinBlue, OUTPUT);
  pinMode(pinGreen, OUTPUT);
}
void rgbColorSelect(int rVal, int gVal, int bVal){
    analogWrite(pinRed, 255-rVal);
    analogWrite(pinGreen, 255-gVal);
    analogWrite(pinBlue, 255-bVal);
    
  
  }



void loop() {
  int currentPin = pinRed;
  int myDelay = 500;
  int r = abs(1+rand()%255), g = abs(1+rand()%255), b = abs(1+rand()%255);
  int rr = random(0, 255), gg = random(0, 255), bb = random(0, 255);
  
  rgbColorSelect(rr,gg,bb);
  delay(myDelay);
  
  /*
  rgbColorSelect(255,255,0);
  delay(myDelay);
  rgbColorSelect(0,64,0);
  delay(myDelay);
  rgbColorSelect(0,255,223);
  delay(myDelay);
  */
  /*
  digitalWrite(pinRed, LOW);
  digitalWrite(pinBlue,HIGH);
  digitalWrite(pinGreen, HIGH);
  delay(myDelay);
  digitalWrite(pinRed, HIGH);
  digitalWrite(pinBlue,LOW);
  digitalWrite(pinGreen, HIGH);
  delay(myDelay);
  digitalWrite(pinRed, HIGH);
  digitalWrite(pinBlue,HIGH);
  digitalWrite(pinGreen, LOW);
  delay(myDelay);
  */
  
}
