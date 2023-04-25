// C++ code
//https://www.arduino.cc/en/Tutorial/Knob - servo instructions
#include <Servo.h>
int sensorvalue = 0;
int sensorvalue_new = 0;
int rotation = 0;
Servo myservo;
Servo myservo2;

int maxL = 500 ; //max light
int minL = 5;  //min light
int maxR = 180; //max rotation
int time = 15; //delay time
int lim = 10; // + - limits for if


void setup()
{
  //pinMode (13, OUTPUT); //LEDBLINK
  myservo.attach(9);
  myservo2.attach(10);
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
  //digitalWrite(13, LOW); //LEDBLINK
  sensorvalue_new = analogRead(A5);
  Serial.print ("light:" );
  Serial.print(sensorvalue);
  Serial.print ("   ");
  Serial.print (" new light:");
  Serial.print(sensorvalue_new);
  Serial.print ("   ");


  if (sensorvalue_new <= 500 || sensorvalue_new >= 5) {
    if ( abs(sensorvalue_new - sensorvalue) > lim) {
      if (sensorvalue_new > sensorvalue) {
        sensorvalue += 5;
        rotation += 5;
        if (rotation > 180) {
          rotation = 180;
          //digitalWrite(13, HIGH); //LEDBLINK
        }
      }

      else {
        rotation -= 5;
        sensorvalue -= 5;
        if (rotation < 0) {
          rotation = 0;
        }
      }
    }

  }
  else if (sensorvalue_new < 5) {
    rotation = 0;
  }
  else if (sensorvalue_new > 500) {
    rotation = 180;
    //digitalWrite(13, HIGH); //LEDBLINK
  }
  myservo.write (rotation);
  myservo2.write (rotation);
  time = rotation / 5000 ; //delay time


  //sensorvalue = sensorvalue_new;
  Serial.print ("rotation:");
  Serial.println(rotation);

  // delay (1000);
}
