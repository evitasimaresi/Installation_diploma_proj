// C++ code
//https://www.arduino.cc/en/Tutorial/Knob - servo instructions
#include <Servo.h>
#include <ArduinoJson.h>
#include <EEPROM.h>

#define MAX_HISTORY_SIZE 100  // Maximum number of entries in the history

struct HistoryEntry {
  int sensorvalue_new;
  int rotation;
};

HistoryEntry history[MAX_HISTORY_SIZE];
int historyIndex = 0;

// Create a JSON object to store the data
StaticJsonDocument<200> doc;

int sensorvalue = 0;
int sensorvalue_new = 0;
int rotation = 0;
int sensorvalue_2 = 0; // 2nd servo
int sensorvalue_new_2 = 0; //2nd servo
int rotation_2 = 0; //2nd servo
Servo myservo;
Servo myservo2;

int maxL = 500 ; //max light
int minL = 5;  //min light
int maxR = 180; //max rotation
int time = 15; //delay time
int lim = 10; // + - limits for if

void setup()
{

  Serial.begin(9600);
  myservo.attach(9);
  myservo2.attach(10);
  pinMode(A5, INPUT);
  pinMode(A4, INPUT);
  //monitor_print_info ();

  // Load the history from EEPROM
  for (int i = 0; i < MAX_HISTORY_SIZE; i++) {
    EEPROM.get(i * sizeof(HistoryEntry), history[i]);
  }
}

void loop()
{
  sensorvalue_new = analogRead(A5);
  sensorvalue_new_2 = analogRead(A4);

  //Json save 1st servo -------------------------------------
  // Save the current sensor value and rotation to history
  HistoryEntry entry;
  entry.sensorvalue_new = sensorvalue_new;
  entry.rotation = rotation;
  history[historyIndex] = entry;
  historyIndex = (historyIndex + 1) % MAX_HISTORY_SIZE;

  // Update the JSON object with the latest values
  doc["light"] = sensorvalue_new;
  doc["rotation"] = rotation;

  // Update the EEPROM with the latest history
  int eepromIndex = 0;
  for (int i = 0; i < MAX_HISTORY_SIZE; i++) {
    EEPROM.put(eepromIndex, history[i]);
    eepromIndex += sizeof(HistoryEntry);
  }

  // Serialize the JSON object and print it
  String jsonStr;
  serializeJson(doc, jsonStr);
  Serial.println(jsonStr);

  //Serial.print ("light:" );
  //Serial.print(sensorvalue_new);
  //  Serial.print ("   ");
  //  Serial.print (" new light:");
  //  Serial.print(sensorvalue_new_2);
  //  Serial.print ("   ");

  //first servo if--------------------------------------------
  if (sensorvalue_new <= 500 || sensorvalue_new >= 5) {
    if ( abs(sensorvalue_new - sensorvalue) > lim) {
      if (sensorvalue_new > sensorvalue) {
        sensorvalue += 5;
        rotation += 5;
        if (rotation > 180) {
          rotation = 180;
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

  }
  //end of servo --------------------------------------------




  //second servo if--------------------------------------------
  if (sensorvalue_new_2 <= 500 || sensorvalue_new_2 >= 5) {
    if ( abs(sensorvalue_new_2 - sensorvalue_2) > lim) {
      if (sensorvalue_new_2 > sensorvalue_2) {
        sensorvalue_2 += 5;
        rotation_2 += 5;
        if (rotation_2 > 180) {
          rotation_2 = 180;
        }
      }

      else {
        rotation_2 -= 5;
        sensorvalue_2 -= 5;
        if (rotation_2 < 0) {
          rotation_2 = 0;
        }
      }
    }

  }
  else if (sensorvalue_new_2 < 5) {
    rotation_2 = 0;
  }
  else if (sensorvalue_new_2 > 500) {
    rotation_2 = 180;
  }
  //end of second servo --------------------------------------------

  myservo.write (rotation);
  myservo2.write (rotation_2);
  //time = rotation / 5000 ; //delay time

  sensorvalue = sensorvalue_new;
  //Serial.print ("rotation:");
  //Serial.println(rotation_2);
}
/*
  void monitor_print_info (){
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
