/***************************BLUETOOTH CONTROLLED CAR CODE**************************/
#include <SoftwareSerial.h>
#include <Servo.h>.
//Declare the arduino pins
SoftwareSerial mySerial(3,2);
Servo myServo;
int lm1 = 10;
int lm2 = 9;
int rm1 = 8;
int rm2 = 7;
int EN1 = 6; //(right)
int EN2= 5; // left
const int trigPin = 13;
const int echoPin = 12;
// Variables for the duration and the distance
long duration;
int distance;



void setup()
{
  //initlize the mode of the pins
   pinMode(lm1,OUTPUT);
   pinMode(lm2,OUTPUT);
   pinMode(rm1,OUTPUT);
   pinMode(rm2,OUTPUT);
   pinMode(EN1,OUTPUT);
   pinMode(EN2,OUTPUT);
  // pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
 // pinMode(echoPin, INPUT); // Sets the echoPin as an Input


   //set the serial communication rate
 TCCR1B = (TCCR1B & 0b11111000) | 0x04;
  Serial.begin(9600);
  mySerial.begin(9600);
   myServo.attach(11); // Defines on which pin is the servo motor attached
}

void loop()
{
 
 /*
  // rotates the servo motor from 15 to 165 degrees
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(10);
  distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  
  Serial.print(i); // Sends the current degree into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.print(distance); // Sends the distance value into the Serial Port
  Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
  // Repeats the previous lines from 165 to 15 degrees
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
 
*/
  
  char val;
  if(mySerial.available()){
    val = mySerial.read();
    Serial.println(val);
    }
// check whether arduino is reciving signal or not 
  while(Serial.available() == 0);
  val = Serial.read() ;//reads the signal
  Serial.print(val);

  /*********For Forward motion*********/
        if(val == '2')
       {
          digitalWrite(lm1,HIGH);  digitalWrite(rm2,HIGH);
          digitalWrite(lm2,LOW);       digitalWrite(rm1,LOW);
          analogWrite(EN1,120); analogWrite(EN2,120);
          delay(50);
          digitalWrite(lm1,HIGH);  digitalWrite(rm1,HIGH);
          digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
          digitalWrite(EN1,LOW); digitalWrite(EN2,LOW);
          //delay(5000);  
       }
       else if(val == '1')
       {
          digitalWrite(lm1,LOW);  digitalWrite(rm2,LOW);
          digitalWrite(lm2,HIGH);       digitalWrite(rm1,HIGH);
          analogWrite(EN1,120); analogWrite(EN2,120);
          delay(50);
          digitalWrite(lm1,HIGH);  digitalWrite(rm1,HIGH);
          digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
          digitalWrite(EN1,LOW); digitalWrite(EN2,LOW);
          
       }
       else if(val == '4')
       {
          digitalWrite(lm1,HIGH);  digitalWrite(rm1,HIGH);
          digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
          analogWrite(EN1,120); analogWrite(EN2,120);
          delay(50);
          digitalWrite(lm1,HIGH);  digitalWrite(rm1,HIGH);
          digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
          digitalWrite(EN1,LOW); digitalWrite(EN2,LOW);
          
       }
       else if(val == '3')
       {
          digitalWrite(lm2,HIGH);  digitalWrite(rm2,HIGH);
          digitalWrite(lm1,LOW);       digitalWrite(rm1,LOW);
          analogWrite(EN1,120); analogWrite(EN2,120);
          delay(50);
          digitalWrite(lm1,HIGH);  digitalWrite(rm1,HIGH);
          digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
          digitalWrite(EN1,LOW); digitalWrite(EN2,LOW);
          //delay(5000);
       }

  
}


// Function for calculating the distance measured by the Ultrasonic sensor
  int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}

