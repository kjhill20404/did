#include <Servo.h> //includes the servo library so we can control it
Servo servo; //declares the servo variabule 
int angle; //declares the angle interger variable

void setup()  {//// this is the stuff that you only want to do once 
    servo.attach(8);///tells the arduino that the servo is connected to this port 
    Serial.begin(9600);///starts the serial info communication with the arduino at 9600 baud 
} ///ends the on startup loop


void loop() ///starts the code that you want to run contueusly 
{///begins the void loop funtion
  
  //scan from 0 to 180 degrees
  servo.write(angle); //moves the servo to the value of the "angle" variabul set previuly 
  
  Serial.print("------"); ///prints a spacer in the serial moniter
  
  for(angle = 10; angle < 180; angle++) ///begins a for loop, at the begining of the void loop it sets the angle to 10; then it is contenusly checking if angle is less than 180, if so it does the code in the loop; then adds one to the value of angle
  {///starts the code for the "for" loop
    servo.write(angle); ///makes the servo move to the value of angle
    SRSW(); ///calls SRSW to run the code in it
    delay(15); ///tells the program to wait 15 millisec
    
  }///ends the code for the "for" loop

  Serial.print("------"); ///puts a spacer in the searal monitor 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 10; angle--) ///begins a for loop, at the begining of the void loop it sets the angle to 180; then it is contenusly checking if angle is more than 10, if so it does the code in the loop; then subtracts one from the value of angle
  {///starts the code for the "for" loop
    servo.write(angle);///moves the servo to angle degrees
    SRSW();///calls SRSW to run the code in it 
    delay(15);///tells the program to wait for 15 millisec
  }///ends the code for the "for" loop
}///ends the code that you want to run continusely 

int SRSW() {///the curlybrackets start a fuction since they are attached to a variabule 
  int sangle;///start a variabule in the fucton 

  sangle = servo.read()///sets "sangle" to the vaule that the servo has moved

  Serial.print("angle = ");///prints in the serial monitor "angle = "
  Serial.println(sangle);///prints on the same line as the previous code
}///ends the functon
