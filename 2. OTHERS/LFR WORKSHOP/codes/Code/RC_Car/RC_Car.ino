#include <SoftwareSerial.h>

SoftwareSerial btbot(10, 11); //(TX,RX)


#define inA 2 
#define inB 3 
#define inC 4
#define inD 7
#define ena 5
#define enb 6

char a;
void setup() {
  Serial.begin(9600);
  btbot.begin(38400);
  mot_init();
}

void loop() {
  if (btbot.available()) {
    a = btbot.read();
    Serial.println(a);
//    if (a=='F')
//    wheel(150,150);
//    else if (a=='B')
//    wheel(-150,-150);
//    else if (a=='R')
//    wheel(150,-150);
//    else if (a=='L')
//    wheel(-150,150);
//    else if (a=='S')
//    wheel(0,0); 
  }
}

void mot_init()
{
  pinMode(inA,OUTPUT);
  pinMode(inB,OUTPUT);
  pinMode(inC,OUTPUT);
  pinMode(inD,OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);
  
  digitalWrite(inA,HIGH);
  digitalWrite(inB,HIGH);
  digitalWrite(inC,HIGH);
  digitalWrite(inD,HIGH);
}

void wheel(int lm, int rm)
{
  if(lm==0)
  {
    digitalWrite(inA,LOW);
    digitalWrite(inB,LOW);
  }
  if(lm>0)
  {
    digitalWrite(inA,HIGH);
    digitalWrite(inB,LOW);
  }
  else if(lm<0)
  {
    digitalWrite(inA,LOW);
    digitalWrite(inB,HIGH);
  }


  if(rm==0)
  {
    digitalWrite(inC,LOW);
    digitalWrite(inD,LOW);
  }
  if(rm>0)
  {
    digitalWrite(inC,HIGH);
    digitalWrite(inD,LOW);
  }
  else if(rm<0)
  {
    digitalWrite(inC,LOW);
    digitalWrite(inD,HIGH);
  }
  if(lm>254) lm=254;
  if(lm<-254) lm=-254;
  if(rm>254) rm=254;
  if(rm<-254) rm=-254;
  
  analogWrite(ena,abs(rm));
  analogWrite(enb,abs(lm));
  
}
