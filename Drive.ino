void drive(int left, int right) {
  left = constrain(left, minSpeed, maxSpeed);
  right = constrain(right, minSpeed, maxSpeed);
  if (left >= 0) {
    digitalWrite(LMotor1, 0);
    digitalWrite(LMotor2, 1);
  } else {

    digitalWrite(LMotor1, 1);
    digitalWrite(LMotor2, 0);

  }
  if (right >= 0) {
    digitalWrite(RMotor1, 0);
    digitalWrite(RMotor2, 1);

  }else {
    digitalWrite(RMotor1, 1);
    digitalWrite(RMotor2, 0);

  }

  analogWrite(LMotorPwm, abs(left));
  analogWrite(RMotorPwm, abs(right));
}
