  
 int IN1 =10;
 int IN2 =9;
 int IN3 =11;
 int IN4 =12; 
 int ENA =3;
 int ENB =5;
 const int trigPin = 8;
 const int echoPin = 13;
 
 

void setup() {
   pinMode(IN1,OUTPUT);
   pinMode(IN2,OUTPUT);
   pinMode(ENA,OUTPUT);
   pinMode(ENB,OUTPUT);
   pinMode(trigPin,OUTPUT);
   pinMode(echoPin,INPUT);
   analogWrite(ENA, 100);
   analogWrite(ENB, 110);
   Serial.begin(9600);
}

void loop() 
{
    digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  //
  long duration = pulseIn(echoPin, HIGH,30000);
  //
  int distance = duration * 0.034/2;
  //
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  if (distance< 10 && distance > 0){
  roverBrake();
  delay(500);
  moveBackward();
  delay(1000);
  turnRight();
  delay(500);

  }
    else
  {
  moveForward();
  
  }
}
void moveForward(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}
void moveBackward(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}
void turnRight(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH); 
}
void roverBrake(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW); 


}

