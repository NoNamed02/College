void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(0));

  pinMode(8, OUTPUT); // 1번 불
  pinMode(7, INPUT); // 버튼
  pinMode(10, OUTPUT); // 2번 불
  pinMode(5, OUTPUT); // 3
}

void loop() {
  int dy = 1000;
  int BT(digitalRead(7));
  Serial.println(BT);
  int check = 0;
  int A = 0;
  int score = 0;


  int rc = 0;
  int level = 0;
  
  while(true){
    int dy = 1000;
    int a = random(50,100);
    Serial.print("level is ");
    Serial.println(level);
    Serial.println(a);                      
    if(a%2==0){
      Serial.println("R_T");
    }
    else{
      Serial.println("L_T");
    }
    for(int i = 0; i<a+1 ; i++){ // 오 켜짐 check = 0;
      if(i%2==0){
        digitalWrite(8,HIGH);
        digitalWrite(10, LOW);
        check = 0;
      }
      else if(i%2==1){
        digitalWrite(8,LOW);
        digitalWrite(10, HIGH);
        check = 1;
      }
      if(dy > ((6-level)*30)){
        dy -= 50;
      }
      rc++;
      delay(dy);
     }
     digitalWrite(8,LOW);
     digitalWrite(10, LOW);
     for(int i = 0; i<5; i++){
       digitalWrite(5, HIGH);
       delay(1000);
       int BT(digitalRead(7));
       Serial.println(BT);
       if(BT == true){ // digitalWrite(8,LOW); // 오 꺼짐 check = 0;
        A = 1;
        Serial.println("You choice R_Turn on"); 
       }
       else{ // check = 1;
        A = 0;
        Serial.println("You choice L_Turn on"); 
       }
       digitalWrite(5, LOW);
       delay(1000);
     }
     
     if(A==1 && check == 0){
       score += 1;
       Serial.println("GOOD!!");
       for(int i = 0; i<5; i++){
        digitalWrite(5, HIGH);
        delay(50);
        digitalWrite(5, LOW);
        delay(50);
       }
     }
     else if(A==0 && check == 1){
       score += 1;
       Serial.println("GOOD!!");
       for(int i = 0; i<5; i++){
        digitalWrite(5, HIGH);
        delay(50);
        digitalWrite(5, LOW);
        delay(50);
       }
     }
     else if(level == 5){
      Serial.println("You clear game");
      break;
     }
     else{
      digitalWrite(5, HIGH);
      Serial.println("You die....");
      delay(2000);
      digitalWrite(5, LOW);
      Serial.print("You Score is ");
      Serial.println(score);
      break;
     }
     level++;
  }
  
  delay(100000000000);
}
