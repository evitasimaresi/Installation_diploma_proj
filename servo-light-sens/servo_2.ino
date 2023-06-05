    void thirdServo() {
  if (sensorvalue_new_3 <= 500 || sensorvalue_new_3 >= 5) {
    if ( abs(sensorvalue_new_3 - sensorvalue_3) > lim) {
      if (sensorvalue_new_3 > sensorvalue_3) {
        sensorvalue_3 += 5;
        rotation_3 += 5;
        if (rotation_3 > 180) {
          rotation_3 = 180;
        }
      }

      else {
        rotation_3 -= 5;
        sensorvalue_3 -= 5;
        if (rotation_3 < 0) {
          rotation_3 = 0;
        }
      }
    }

  }
  else if (sensorvalue_new_3 < 5) {
    rotation_3 = 0;
  }
  else if (sensorvalue_new_3 > 500) {
    rotation_3 = 180;
  }
}
