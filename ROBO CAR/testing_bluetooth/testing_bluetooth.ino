/*
 * Minhaz NOTE
 * Remove TX and RX pins before uploading the code
 * 
 */


char data = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11, OUTPUT);
}



void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    data = Serial.read();
    Serial.println(data);
  }
}
