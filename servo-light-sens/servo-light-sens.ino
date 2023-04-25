// C++ code
//https://www.arduino.cc/en/Tutorial/Knob - servo instructions
#include <Servo.h>
int sensorvalue = 0;
int sensorvalue_new = 0;
int rotation =0;
Servo myservo;

int maxL = 500 ; //max light
int minL = 5;  //min light
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


  Serial.print ("light:" );
  Serial.print(sensorvalue);
  Serial.print ("   ");
  Serial.print (" new light:");
  Serial.print(sensorvalue_new);
  Serial.print ("   ");
 

  if (sensorvalue_new <= 500 || sensorvalue_new >= 5) {
    if ( abs(sensorvalue_new - sensorvalue) > 15) {
      rotation = map(sensorvalue_new, minL , maxL , 1, maxR);
    }
  }
  else if (sensorvalue_new < 5) {
    rotation = 0;
  }
  else if (sensorvalue_new > 500) {
    rotation = 180;
  }
  myservo.write (rotation);
  time = rotation / 5000 ; //delay time

  sensorvalue = sensorvalue_new;
 Serial.print ("rotation:");
  Serial.println(rotation);

  delay (100);
}
