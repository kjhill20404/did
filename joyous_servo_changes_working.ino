#include <Servo.h>
#include <Servo.h>

Servo servo1;
Servo servo2;
int joyx = 0;
int joyy = 1;

int joyval;
int joyswt = 2;
int notloop1;
int lopint1;
int lopint2;
int addto;
int subfrom;
int impnumx;
int impnumy;
void setup() {
  // put your setup code here, to run once:
 servo1.attach(3);
 servo2.attach(5);
 Serial.begin(9600);


 
///everything afer this line in the setup function is for stoping joystick drift  
 notloop1 = 0;
 if(notloop1 < 30) { //a loop to make a array for the value reported by x of the servo
  joyval= analogRead (joyx);//get number from the x pin on joystick note* the muber will be between 0-1023
  joyval= map(joyval,0,1023,0,180);//allow the servo to know what the number means in relation to 180 degrees
  lopint1 = lopint1 + joyval;
  notloop1++;
  //lopint1[notloop1] = joyval;//adds the number to the array
 }
 notloop1 = 0; 
 if(notloop1 < 30 ) { //a loop to make a array for the value reported by y of the servo
  joyval= analogRead (joyy);
  joyval= map(joyval,0,1023,0,180);
  
  lopint2 = lopint2 + joyval;
  notloop1++;
  
 }
lopint1 = lopint1 / notloop1;
lopint2 = lopint2 / notloop1;

if(lopint1 > 90){
 subfrom = lopint1 - 90;
  impnumx = (180 -subfrom) -1;
}

if(lopint1 < 90){
  addto = 90 - lopint1;
  impnumx = 180 +addto +1;
  } else{
    impnumx = 180;
  }


if(lopint2 > 90){
  subfrom = lopint2 - 90;
  impnumy = (180 -subfrom) -1;
  }

if(lopint2 < 90){
  addto = 90 - lopint2;
  impnumy = 180 +addto +1;
  }  else{
    impnumy = 180;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  joyval= analogRead (joyx);
  joyval= map(joyval,0,1023,0,impnumx);
  Serial.print("x = ");
  Serial.print(joyval);
  servo1.write(joyval);
  
  joyval= analogRead (joyy);
  joyval= map(joyval,0,1023,0,impnumy);
  Serial.print("  y = ");
  Serial.println (joyval);
  servo2.write(joyval);
  delay(15);
}


void removeDrift() {
 

	
	
	
	
}
