int arr[8];
int pin = 8;
int pins[] = {A0, A1, A2, A3, A4, A5, 5,6};
int irPin = 7;
void display2(int a, int b){
  Serial.print(a);
  Serial.print( " : ");
  Serial.print(b);  
  Serial.print( "\n");
 
}
void turnHigh(int pin){
  digitalWrite(pin,HIGH);
  delay(4);
}
void turnLow(int pin){
  digitalWrite(pin,LOW);
  delay(4);
  
}
void setup() {
  // put your setup code here, to run once:
  pinMode(irPin, OUTPUT);
  for(int i=0;i<pin;i++){
    pinMode(pins[i], INPUT);
  }
  Serial.begin(9600);
  delay(100);
}

void loop() {
  
  turnHigh(irPin);
  int a = analogRead(pins[0]);
  int b = analogRead(pins[1]);
  Serial.print("High: ");
  display2(a,b);
  delay(200);
  delay(1000);
  turnLow(irPin);
  a = analogRead(pins[0]);
  b = analogRead(pins[1]);
  Serial.print("LOW: ");
  display2(a,b);
  delay(200);
  delay(1000);
}
