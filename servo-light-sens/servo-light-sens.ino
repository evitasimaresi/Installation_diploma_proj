// C++ code
//https://www.arduino.cc/en/Tutorial/Knob - servo instructions
#include <Servo.h>
int sensorvalue = 0;
int sensorvalue_new = 0;
int rotation ;
Servo myservo;

int maxL = 500 ; //max light
int minL= 5;   //min light
int maxR = 180; //max rotation
int time = 15; //delay time
int lim = 15; // + - limits for first if


void setup()
{
  myservo.attach(9);
  pinMode(A5, INPUT);
  Serial.begin(9600);
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
}

void loop()
{
  sensorvalue_new = analogRead(A5);
  
  Serial.print ("light:");
  Serial.print(sensorvalue);
  Serial.print ("   ");
  Serial.print (" new light:");
  Serial.print(sensorvalue_new);
  Serial.print ("   ");
  if (sensorvalue_new > sensorvalue +lim || sensorvalue_new < sensorvalue -lim ) {
   if (sensorvalue_new > maxL ) {
     rotation = maxR;
     myservo.write (rotation);
   }
   else if (sensorvalue_new > minL ){
     rotation = map(sensorvalue_new, minL , maxL , 1, maxR);
     myservo.write (rotation);
   }
   
  // time = rotation / 5000; //delay time
  }
  else if (sensorvalue_new = 0){
      rotation = 0;
      myservo.write (rotation);
  }
  sensorvalue = sensorvalue_new;
  Serial.print ("roation:");
  Serial.println(rotation);
  delay (time);
}
