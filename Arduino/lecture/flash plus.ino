#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define buzzerPin 8

// LCD 모듈 설정
LiquidCrystal_I2C lcd(0x27, 16, 2);  // 주소 0x27에 16x2 크기의 LCD 모듈을 사용합니다.

const int buttonPinA = 2; // 버튼 핀을 디지털 핀 2에 연결합니다.
const int buttonPinB = 3;
const int buttonPinC = 4;
const int buttonPinD = 5;
// 이전 버튼 상태 변수 초기화
int previousButtonStateA = LOW;
int previousButtonStateB = LOW;
int previousButtonStateC = LOW;
int previousButtonStateD = LOW;

int level = 1;

int gameend = 0;

void setup() {
  // 버튼 핀을 입력으로 설정
  pinMode(buttonPinA, INPUT);
  pinMode(buttonPinB, INPUT);
  pinMode(buttonPinC, INPUT);
  pinMode(buttonPinD, INPUT);
  
  // LCD 초기화
  lcd.init();
  lcd.backlight();

  // 시리얼 통신 시작
  Serial.begin(9600);
}

void loop() {
  // 버튼 상태 읽기
  int buttonStateA = digitalRead(buttonPinA);
  int buttonStateB = digitalRead(buttonPinB);
  int buttonStateC = digitalRead(buttonPinC);
  int buttonStateD = digitalRead(buttonPinD);
  int A = 50;
  int iter = 1;
  randomSeed(analogRead(0));
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("flash plus");
  lcd.setCursor(0, 1);
  lcd.print("press to start");
  delay(50);
  if(iter == 1){
    iter += 1;
    tone(buzzerPin, 261);
    delay(A);
    noTone(buzzerPin);
  }
  if(iter == 2){
    iter += 1;
    tone(buzzerPin, 391);
    delay(A);
    noTone(buzzerPin);
  }
  if(iter == 3){
    iter += 1;
    tone(buzzerPin, 329);
    delay(A);
    noTone(buzzerPin);
  }
  if(iter == 4){
    iter += 1;
    tone(buzzerPin, 391);
    delay(A);
    noTone(buzzerPin);
  }
  if(iter == 5)
    iter = 1;
  Serial.print(iter);
  Serial.print("\n");
  
  
  if (buttonStateA == HIGH && previousButtonStateA == LOW) {
    while(true){
      tone(buzzerPin, 523);
      delay(200);
      noTone(buzzerPin);
      int time_c = 0;
      int randomNumberA = random(1, level*10);
      int randomNumberB = random(1, level*10);
      int randomNumberC = random(1, level*10);
      int randomNumberD = random(1, level*10);
      int randomNumberE = random(1, level*10);
      int sum = randomNumberA + randomNumberB + randomNumberC + randomNumberD + randomNumberE;
      int answer = 0;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("start");
      lcd.setCursor(0, 1);
      lcd.print("level ");
      lcd.print(level);
      delay(1000);
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Plus all number");
      lcd.setCursor(0, 1);
      lcd.print(randomNumberA);
      delay(1000);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Plus all number");
      lcd.setCursor(0, 1);
      lcd.print(randomNumberB);
      delay(1000);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Plus all number");
      lcd.setCursor(0, 1);
      lcd.print(randomNumberC);
      delay(1000);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Plus all number");
      lcd.setCursor(0, 1);
      lcd.print(randomNumberD);
      delay(1000);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Plus all number");
      lcd.setCursor(0, 1);
      lcd.print(randomNumberE);
      delay(1000);

      int T = 0;
      unsigned long startTime = millis();
      while(millis() - startTime < 10000){
        T++;
        Serial.print(T);
        Serial.print("\n");
        if(T % 14 == 0){
          tone(buzzerPin, 1046);
          delay(100);
          noTone(buzzerPin);
        }
        buttonStateB = digitalRead(buttonPinB);
        buttonStateC = digitalRead(buttonPinC);
        buttonStateD = digitalRead(buttonPinD);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Answer is");
        lcd.setCursor(0, 1);
        lcd.print(answer);
        delay(50);
        
        if (buttonStateB == HIGH && previousButtonStateB == LOW) {
          tone(buzzerPin, 523);
          delay(A);
          noTone(buzzerPin);
          answer += 100;
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Answer is");
          lcd.setCursor(0, 1);
          lcd.print(answer);
          delay(50);
        }
        if (buttonStateC == HIGH && previousButtonStateC == LOW) {
          tone(buzzerPin, 523);
          delay(A);
          noTone(buzzerPin);
          answer += 10;
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Answer is");
          lcd.setCursor(0, 1);
          lcd.print(answer);
          delay(50);
        }
        if (buttonStateD == HIGH && previousButtonStateD == LOW) {
          tone(buzzerPin, 523);
          delay(A);
          noTone(buzzerPin);
          answer += 1;
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Answer is");
          lcd.setCursor(0, 1);
          lcd.print(answer);
          delay(50);
        }
        
        previousButtonStateA = buttonStateA;
        previousButtonStateB = buttonStateB;
        previousButtonStateC = buttonStateC;
        previousButtonStateD = buttonStateD;
      }
      
      if(answer == sum){
        level += 1;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("You are right!");
        lcd.setCursor(0, 1);
        lcd.print("Soon next level");
        tone(buzzerPin, 1046);
        delay(200);
        tone(buzzerPin, 1318);
        delay(200);
        tone(buzzerPin, 1567);
        delay(500);
        noTone(buzzerPin);
        delay(5000);
      }
      else{
        
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("You are lose");
        lcd.setCursor(0, 1);
        lcd.print("Game End");
        gameend = 1;
        tone(buzzerPin, 1046);
        delay(200);
        noTone(buzzerPin);
        delay(100);
        tone(buzzerPin, 1046);
        delay(500);
        noTone(buzzerPin);
        delay(5000);
      }
        
      if(gameend == 1)
        break;
        
      previousButtonStateA = buttonStateA;
      previousButtonStateB = buttonStateB;
      previousButtonStateC = buttonStateC;
      previousButtonStateD = buttonStateD;
    }
  }
  if(gameend == 1){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Last level is ");
    lcd.print(level);
    lcd.setCursor(0, 1);
    lcd.print("Game End");
    delay(1000000000);
    previousButtonStateA = buttonStateA;
    previousButtonStateB = buttonStateB;
    previousButtonStateC = buttonStateC;
    previousButtonStateD = buttonStateD;
  }
  gameend = 0;
}
