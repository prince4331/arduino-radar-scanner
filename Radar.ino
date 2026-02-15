#include <Servo.h>. 

const int trigPin = 10;
const int echoPin = 11;
const int buzzer = 2;
const int led4 = 13;
const int led3 = 6;
const int led2 = 5;
const int led1 = 4;
const int led0 = 7;


long duration;
int distance;
int safetyDistance;

Servo myServo;
void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(buzzer, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led0, OUTPUT);

  Serial.begin(9600);
  myServo.attach(12); 
}
void loop() {

  for(int i=0;i<=180;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  
  Serial.print(i);
  Serial.print(","); 
  Serial.print(distance);
  Serial.print("."); 
  }
 
  for(int i=180;i>0;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}

int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;

   safetyDistance = distance;

if (safetyDistance <= 5){
  digitalWrite(buzzer, HIGH);  
  digitalWrite(led4, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(led4, LOW);
}

if (safetyDistance <= 10){ 
  digitalWrite(led3, HIGH);
}
else{
  digitalWrite(led3, LOW);
}

if (safetyDistance <= 20){
  digitalWrite(led2, HIGH);
}
else{
  digitalWrite(led2, LOW);
}

if (safetyDistance <= 40){
  digitalWrite(led1, HIGH);
}
else{
  digitalWrite(led1, LOW);
}

if (safetyDistance > 40){
  digitalWrite(led0, HIGH);
}
else{
  digitalWrite(led0, LOW);
}
return distance;

Serial.print("Distance: ");
Serial.println(distance);
delay(400);
}
