// 초음파 센서로 물건 접근 인식 -> 조도 센서 빛 감지 체크 -> 모터 작동 -> 모터 작동 끝날시 부저 작동
#include <Servo.h>
#define trigPin 9
#define echoPin 10
#define thresholdDistance 5 // 거리 임계값 (단위: cm)
#define buzzerPin 3 // 부저를 3번 핀에 연결

Servo servo;
int check;

void setup() {
  int check = 0;
  Serial.begin(9600);
  servo.attach(6); // 서보 모터를 6번 핀에 연결
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT); // 부저를 출력 핀으로 설정
}

void loop() {
  int readValue = analogRead(A0);
  Serial.println(readValue);
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= thresholdDistance && check == 0) {
    // 거리가 임계값 이하이고 check가 0일 때
    servo.write(35); // 서보 모터를 원하는 각도로 회전
    delay(1000); // 모터가 움직이는 시간을 대기
    servo.write(0); // 서보 모터를 초기 위치로 회전
    delay(8000);
    tone(buzzerPin, 256); // 부저의 주파수를 설정하여 소리를 발생
    delay(200); // 소리를 내는 시간을 대기
    tone(buzzerPin, 500); // 부저의 주파수를 설정하여 소리를 발생
    delay(200); // 소리를 내는 시간을 대기
    tone(buzzerPin, 750); // 부저의 주파수를 설정하여 소리를 발생
    delay(500); // 소리를 내는 시간을 대기
    noTone(buzzerPin); // 부저의 소리를 멈춤
    check = 1; // check를 1로 설정하여 다음 루프에서 이 부분을 무시함
  } else if (distance > thresholdDistance && check == 1) {
    // 거리가 임계값을 초과하고 check가 1일 때
    check = 0; // check를 0으로 설정하여 다음 루프에서 다시 체크할 수 있도록 함
  }

  delay(100); // 일정 시간 간격으로 거리 측정을 반복
}
