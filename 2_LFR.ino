void resetLFR() {
  error = 0;
  lastError = 0;
  delta = 0;
  deltaError = 0;
}

void LFR() {
  switch (EventLine[DL]) {
    case EV_Corner_R:
      lastPos = 9000;
      return lastPos;
      break;
    case EV_Corner_L:
      lastPos = 0;
      return lastPos;
      break;
    default:
      error = target - readLine();
      deltaError = error - lastError;
      lastError = error;
      delta = error * kp + deltaError * kd;
      drive(BSpeed - delta, BSpeed + delta);
  }
}
