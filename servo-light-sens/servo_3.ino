    void fourthServo() {
  if (sensorvalue_new_4 <= 500 || sensorvalue_new_4 >= 5) {
    if ( abs(sensorvalue_new_4 - sensorvalue_4) > lim) {
      if (sensorvalue_new_4 > sensorvalue_4) {
        sensorvalue_4 += 5;
        rotation_4 += 5;
        if (rotation_4 > 180) {
          rotation_4 = 180;
        }
      }

      else {
        rotation_4 -= 5;
        sensorvalue_4 -= 5;
        if (rotation_4 < 0) {
          rotation_4 = 0;
        }
      }
    }

  }
  else if (sensorvalue_new_4 < 5) {
    rotation_4 = 0;
  }
  else if (sensorvalue_new_4 > 500) {
    rotation_4 = 180;
  }
}
