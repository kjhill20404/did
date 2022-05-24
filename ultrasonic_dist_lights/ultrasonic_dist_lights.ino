const int trig = 12;
const int echo = 13;

const int LED1 = 8;
const int LED2 = 7;
const int LED3 = 6;
const int LED4 = 5;
const int LED5 = 4;
const int LED6 = 3;
const int LED7 = 2;

int duration = 0;
int distance = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
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
  
  LEDon();
  delay(distance * 50);
  LEDoff();
  delay(distance * 50);
  
while(distance >= 90);{
  digitalWrite(LED1,HIGH); ///led red1 on
  digitalWrite(LED6,HIGH); ///led green2 on
  }
while(distance < 90){
  digitalWrite(LED6,LOW);///LED green2 off
  digitalWrite(LED5,HIGH);///led yellow2 on
  delay(2000);
  digitalWrite(LED5,LOW);///led yellow2 off
  digitalWrite(LED4,HIGH);///led red2 on
  digitalWrite(LED1,LOW);
  digitalWrite(LED
  }
}
