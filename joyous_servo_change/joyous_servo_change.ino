#include <Servo.h>
#include <Servo.h>

Servo servo1;
Servo servo2;
int joyx = 0;
int joyy = 1;

int joyval;
int joyswt = 2;
int notloop1;
int notloop2;
int lopint1[] ={};
int lopint2[] = {};

void setup() {
  // put your setup code here, to run once:
 servo1.attach(3);
 servo2.attach(5);
 Serial.begin(9600);
 if(notloop1 = 0;notloop1 < 30;notloop1++) {
  joyval= analogRead (joyx);
  joyval= map(joyval,0,1023,0,180);
  lopint1[notloop1] = joyval;
 }
 if(notloop2 = 0;notloop2 < 30;notloop2++) {
  joyval= analogRead (joyy);
  joyval= map(joyval,0,1023,0,180);
  lopint2[notloop2] = joyval;
  
 }
 for(int i = 0; 
}

void loop() {
  // put your main code here, to run repeatedly:
  joyval= analogRead (joyx);
  joyval= map(joyval,0,1023,0,180);
  Serial.print("x = ");
  Serial.print(joyval);
  servo1.write(joyval);
  
  joyval= analogRead (joyy);
  joyval= map(joyval,0,1023,0,180);
  Serial.print("  y = ");
  Serial.println (joyval);
  servo2.write(joyval);
  delay(15);
}
