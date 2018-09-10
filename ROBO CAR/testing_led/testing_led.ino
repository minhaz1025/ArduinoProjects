int pinLed = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLed, OUTPUT);
}

void loop() {
  
  digitalWrite(pinLed, HIGH);
  delay(1000);
  digitalWrite(pinLed, LOW);
  delay(1000);
  // put your main code here, to run repeatedly:

}
