 
 int IN1 =10;
 int IN2 =9;
 int ENA =3;
 
 
 
 
 void setup() {
   pinMode(IN1,OUTPUT);
   pinMode(IN2,OUTPUT);
   pinMode(ENA,OUTPUT);


}

void loop() {
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  analogWrite(ENA, 50);
  delay(8000);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  delay(3000);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  delay(3000);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  delay(3000);



  

}
