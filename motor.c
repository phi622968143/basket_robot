//ControlRotation
#include <Servo.h>
Servo myservo;
//int sensor=0;

void setup(){
   myservo.attach(9);//接腳
}

void loop(){
   //sensor=analogRead(A0);
   myservo.write(150);// 轉到60度
   delay(15);
   myservo.write(0);//轉回去
   delay(15);
   myservo.write(150);
   delay(15);
}
