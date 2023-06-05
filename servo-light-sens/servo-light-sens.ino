// C++ code
//https://www.arduino.cc/en/Tutorial/Knob - servo instructions
#include <Servo.h>

//1st Servo
int sensorvalue = 0;
int sensorvalue_new = 0;
int rotation = 0;
Servo myservo;

//2nd Servo
int sensorvalue_2 = 0;
int sensorvalue_new_2 = 0;
int rotation_2 = 0;
Servo myservo2;

//3nd Servo
int sensorvalue_3 = 0;
int sensorvalue_new_3 = 0;
int rotation_3 = 0;
Servo myservo3;

//4th Servo
int sensorvalue_4 = 0;
int sensorvalue_new_4 = 0;
int rotation_4 = 0;
Servo myservo4;



int maxL = 500 ; //max light
int minL = 5;  //min light
int maxR = 180; //max rotation
int time = 15; //delay time
int lim = 10; // + - limits for if

void setup()
{
  Serial.begin(9600);

  //1st Servo-///////////////////////////////////////////////////////////////
  myservo.attach(11);
  pinMode(A0, INPUT);

  //2nd Servo-///////////////////////////////////////////////////////////////
  myservo2.attach(10);
  pinMode(A1, INPUT);

  //3rd Servo-///////////////////////////////////////////////////////////////
  myservo3.attach(9);
  pinMode(A2, INPUT);

  //3th Servo-///////////////////////////////////////////////////////////////
  myservo4.attach(6);
  pinMode(A3, INPUT);
}

void loop()
{
  sensorvalue_new = analogRead(A0); //1st Servo
  sensorvalue_new_2 = analogRead(A1);//2nd Servo
  sensorvalue_new_3 = analogRead(A2);//3rd Servo
  sensorvalue_new_4 = analogRead(A3);//4th Servo

  //Servos ifs--------------------------------------------
  firstServo();
  secondServo();
  thirdServo();
  fourthServo();
  //end of servos --------------------------------------------

  myservo.write (rotation);//send the angle of rotatin to 1st servo
  myservo2.write (rotation_2);//send the angle of rotatin to 2nd servo
  myservo3.write (rotation_3);//send the angle of rotatin to 3rd servo
  myservo4.write (rotation_4);//send the angle of rotatin to 4th servo


  //1st Servo--------------------------
  Serial.print ("1st:");
  Serial.print(sensorvalue_new);
  Serial.print (":");
  Serial.println(rotation);

  //2nd Servo------------------------
  Serial.print ("2nd:");
  Serial.print(sensorvalue_new_2);
  Serial.print (":");
  Serial.println(rotation_2);

  //3rd Servo------------------------
  Serial.print ("3rd:");
  Serial.print(sensorvalue_new_3);
  Serial.print (":");
  Serial.println(rotation_3);
  
  //4th Servo------------------------
  Serial.print ("4th:");
  Serial.print(sensorvalue_new_4);
  Serial.print (":");
  Serial.println(rotation_4);

  //time = rotation / 5000 ; //delay time
}


/*void monitor_print_info (){
  Serial.print ("max light/minlight:");
  Serial.print (maxL);
  Serial.print ("/");
  Serial.print (minL);
  Serial.print (" | max rotation:");
  Serial.print (maxR);
  Serial.print (" | delay time:");
  Serial.print (time);
  Serial.print (" | limits for first if:");
  Serial.println (lim);
  }*/


