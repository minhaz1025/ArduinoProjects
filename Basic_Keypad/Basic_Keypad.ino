

int row[4]     = {2,3,4,5};
int column[4]  = {6,7,8,9};
int a;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  /*
  for(int i=0;i<4;i++){
    pinMode(row[i],INPUT);
    pinMode(column[i],INPUT);
  }
  */
  pinMode(2, INPUT);
  a = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  int a= digitalRead(row[0]);
  int b= digitalRead(column[0]);
  /*
  if(a == HIGH && b == HIGH){
    Serial.println("HI");
  }
  */
  //Serial.println((char)a + " : " +(char) b);
  Serial.println(digitalRead(2));
  
  delay(1);

}
