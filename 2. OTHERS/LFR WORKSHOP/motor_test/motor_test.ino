#define inA 2 
#define inB 3 
#define inC 8
#define inD 9
#define ena 5
#define enb 6

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
void setup() {
  // put your setup code here, to run once:
  mot_init(); 
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(inA, HIGH);
  digitalWrite(inB, LOW);
  digitalWrite(13, HIGH);
  delay(2000);

  digitalWrite(inA, LOW);
  digitalWrite(inB, HIGH);
  digitalWrite(13, LOW);

  delay(2000);                        
}
