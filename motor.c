#include <Servo.h>
Servo myservo;
int trigPin = 11;    // 超音波感測器 Trig腳接 Arduino pin 11
int echoPin = 12;    //超音波感測器 Echo 腳接 Arduino pin 12
int speakerpin = 7;  //蜂鳴器 + 腳接 Arduino pin 7
long duration, d ;  //宣告計算距離時，需要用到的兩個實數


//int sensor=0;
void setup() {
  Serial.begin (9600);           //設定序列埠監控視窗 (Serial Monitor) 和 Arduino資料傳輸速率為 9600 bps (Bits Per Second)
  pinMode(trigPin, OUTPUT);      //Arduino 對外啟動距離感測器Trig腳，射出超音波
  pinMode(echoPin, INPUT);       //超音波被障礙物反射後，Arduino讀取感測器Echo腳的時間差

   myservo.attach(9);//接腳
}

void loop()
{ //程式計算出距離值 cm
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  d = (duration / 2) / 29.1;

  Serial.print(d);
  Serial.println("cm");
  
  int pos;
  for (pos = 0; pos <= 150; pos += 15) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay((1/d)*100);                       // waits depend on distance
  }
  for (pos = 90; pos >= 150; pos -=10) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits depend on distance
  }

}
