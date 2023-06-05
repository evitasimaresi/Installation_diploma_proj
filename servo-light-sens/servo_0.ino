void firstServo() {
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
}
