const int trig = 12;
const int echo = 13;

const int RED1 = 8;///red
const int YELLOW1 = 7;
const int GREEN1 = 6;

const int RED2 = 5;
const int YELLOW2 = 4;
const int GREEN2 = 3;
const int LED7 = 2;

int duration = 0;
int distance = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(RED1, OUTPUT);
  pinMode(YELLOW1, OUTPUT);
  pinMode(GREEN1, OUTPUT);
  pinMode(RED2, OUTPUT);
  pinMode(YELLOW2, OUTPUT);
  pinMode(GREEN2, OUTPUT);
  pinMode(LED7, OUTPUT);

  Serial.begin(9600);

}

int LEDon() {

  int num = 8;
  while(num >= 2){
    digitalWrite(num, HIGH);
    num = num -1;
  }
}


int LEDoff() {

  int num = 8;
  while(num >= 2 ){
    digitalWrite(num, LOW);
    num = num -1;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) / 28.5;
  Serial.println(distance);
  
//  LEDon();
//  delay(distance * 50);
//  LEDoff();
//  delay(distance * 50);
  
if(distance >= 90);{
  digitalWrite(RED1,HIGH); ///led red1 on
  digitalWrite(GREEN2,HIGH); ///led green2 on
  }
  if(distance < 90){
  digitalWrite(GREEN2,LOW);///LED green2 off
  digitalWrite(YELLOW2,HIGH);///led yellow2 on
  delay(2000);
  digitalWrite(YELLOW2,LOW);///led yellow2 off
  digitalWrite(RED2,HIGH);///led red2 on
  digitalWrite(RED1,LOW);
  digitalWrite(GREEN1,HIGH);
  delay(2000);
  digitalWrite(GREEN1,LOW);
  digitalWrite(YELLOW1,HIGH);
  delay(2000);
  digitalWrite(YELLOW1,LOW);
  digitalWrite(RED2,LOW);
  }
}
