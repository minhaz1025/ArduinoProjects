
#include<IRremote.h>

int pinRec = A0;

IRrecv irrecv(pinRec);
decode_results result;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:

  if(irrecv.decode(&result)){
    Serial.println(analogRead(pinRec));
    Serial.println(result.value, HEX);
    Serial.println(result.decode_type);
    irrecv.resume();  
  
  }
}
