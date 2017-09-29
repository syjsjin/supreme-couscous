### done
2. 온습도 센서 사용
3. 도트 매트릭스 사용
### work
1. 구매 목록 정리
  - 기구매목록
    작성해야 됨!!
  - 추가구매목록
    [모터 드라이버](http://mechasolution.com/shop/goods/goods_view.php?goodsno=9266&category=131014) 1,320원
    [배터리 홀더 X2](http://mechasolution.com/shop/goods/goods_view.php?goodsno=330427&category=135002) 3,740원
    [배터리 AA 16개](http://mechasolution.com/shop/goods/goods_view.php?goodsno=773&category=135001) 12,320원(AA 배터리면 됩니다.)
    [블루투스](http://mechasolution.com/shop/goods/goods_view.php?goodsno=71794&category=054001) 4,180원 (선택사항)
1. 초음파 센서 사용
  - KEYWORD : Arduino UltraSonic Sensor
  ```
  
//출력핀(trig)과 입력핀(echo) 연결 설정, 다른 핀을 연결해도 됨.
int trigPin = 9;
int echoPin = 8;
 
//시리얼 속도설정, trigPin을 출력, echoPin을 입력으로 설정
void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
//초음파를 보낸다. 다 보내면 echo가 HIGH(신호받기) 상태로 대기
void loop(){
  float duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
 
  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  duration = pulseIn(echoPin, HIGH);
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  // 340은 초당 초음파(소리)의 속도, 10000은 밀리세컨드를 세컨드로, 왕복거리이므로 2로 나눠준다.
  distance = ((float)(340 * duration) / 10000) / 2;
 
  //시리얼모니터에 Echo가 HIGH인 시간 및 거리를 표시해준다.
  Serial.print("Duration:");
  Serial.print(duration);
  Serial.print("\nDIstance:");
  Serial.print(distance);
  Serial.println("cm\n");
  delay(500);
}

출처: http://deneb21.tistory.com/215 [Do It Yourself!]
  ```
  ![](http://mechasolutionwiki.com/1/f/fb/%ED%9A%8C%EB%A1%9C_%EC%B4%88%EC%9D%8C%ED%8C%8C.png)
2. 모터 제어
  - KEYWORD : Arduino DC Motor
  - MotorDriver or TR
  ```
  //모터A 컨트롤
int IN1=7;
int IN2=6;
 
//모터B 컨트롤
int IN3=5;
int IN4=4;
 
void setup() {
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}
 
void loop() {
  bothMotorStart();
  delay(3000);
  turnLeft();
  delay(3000);  
  turnRight();
  delay(3000);
  motorA_Rotation();
  delay(3000);
  motorB_Rotation();
  delay(3000);
  motorA_Reverse();
  delay(3000);
  motorB_Reverse();
  delay(3000);
  stopAllMotor();
  delay(3000);
}
 
//모터A,B 정회전
void bothMotorStart()
{
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
}
 
//모터A,B Stop
void stopAllMotor()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
}
 
//모터A 역회전, 모터B 정회전
void turnLeft()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
}
 
//모터A 정회전, 모터B 역회전
void turnRight()
{
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
}
 
//모터A 정회전, 모터B Stop
void motorA_Rotation()
{
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
}
 
//모터A Stop, 모터B 정회전
void motorB_Rotation()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
}
 
//모터A 역회전, 모터B Stop
void motorA_Reverse()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
}
 
//모터A Stop, 모터B 역회전
void motorB_Reverse()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
}

출처: http://deneb21.tistory.com/277 [Do It Yourself!]
  ```
  ![](http://cfile8.uf.tistory.com/image/21304F4356EF79D3245D29)
  - Power Supply
4. 프로그래밍 설계
  - 구동부
   초음파 값이 50보다 작다면 좌회전
   평상시에는 직진
     - timer 기능으로 구동부 제어하기
```
//출력핀(trig)과 입력핀(echo) 연결 설정, 다른 핀을 연결해도 됨.
int trigPin = 9;
int echoPin = 8;

//모터A 컨트롤
int IN1=7;
int IN2=6;
 
//모터B 컨트롤
int IN3=5;
int IN4=4;
 
//시리얼 속도설정, trigPin을 출력, echoPin을 입력으로 설정
void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}
 
//초음파를 보낸다. 다 보내면 echo가 HIGH(신호받기) 상태로 대기
void loop(){

}

//모터A,B 정회전
void bothMotorStart()
{
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
}
 
//모터A,B Stop
void stopAllMotor()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
}
 
//모터A 역회전, 모터B 정회전
void turnLeft()
{
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
} 

void timer(){
  float duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
 
  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  duration = pulseIn(echoPin, HIGH);
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  // 340은 초당 초음파(소리)의 속도, 10000은 밀리세컨드를 세컨드로, 왕복거리이므로 2로 나눠준다.
  distance = ((float)(340 * duration) / 10000) / 2;

  while(distance < 50){
     turnLeft();
  }
  bothMotorStart();
}
```
  - 센서부
   온 습도 센서값으로부터 불쾌지수 계산하기
   계산한 값으로 도트매트릭스 표정 구현하기

5. 도안 설계
  - 종이 도면(평면형태 조립)
6. 도안 제작
7. 프린팅