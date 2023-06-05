    void secondServo() {
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
}
