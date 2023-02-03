void resetLFR() {
  error = 0;
  lastError = 0;
  delta = 0;
  deltaError = 0 ;
}

void LFR() {
  error = target - readLine();
  deltaError = error - lastError;
  lastError = error;
  delta = error * kp + deltaError * kd;
  drive(BSpeed - delta, BSpeed + delta);
}
