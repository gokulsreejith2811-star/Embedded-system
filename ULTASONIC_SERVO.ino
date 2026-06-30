#include<Servo.h>
servo myservo;







const int trigPin = 9;
const int echoPin = 10;
int red=12;
int green=8;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green,OUTPUT);
  myservo.attach(11);
  Serial.begin(9600);


}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  //
  duration = pulseIn(echoPin, HIGH);
  //
  distance = duration * 0.034/2;
  //
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

  if (distance< 10){
  
    // digitalWrite(red,HIGH);
    // digitalWrite(green,LOW);
    myservo.Write(0);
    serial.println(distance);
  }
  else if (distance >10 && distance <30){

  

    // digitalWrite(green,HIGH);
    // digitalWrite(red,LOW);
    myservo.write(90);
    serial.printin(distance);
  }
  delay(500);
}

  

