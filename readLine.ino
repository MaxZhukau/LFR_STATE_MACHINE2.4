int readLine() {
  long sumWV = 0;
  int sumW = 0;
  bool onLine = false;
  byte W = 128;


  readSens();

  for (int i = 0; i < Num_Sens; i++) {
    Sens[i] = map(Sens[i], minCalibr[i], maxCalibr[i], 0, 1000);
    Sens[i] = constrain(Sens[i], 0, 1000);


    if (Sens[i] > TH_LINE) {
      onLine = true;
      DL = DL + W;
    }
    if (Sens[i] > NOISE) {
      sumWV = sumWV + (long)ws[i] * Sens[i];
      sumW = sumW + Sens[i];
    }

    W = W / 2;
  }

  switch (EventLine[DL]) {
    case EV_Corner_R:
      lastPos = maxValue;
      return lastPos;  // ?
      break;
    case EV_Corner_L:
      lastPos = minValue;
      return lastPos;  // ?
      break;
  }

  if (onLine == false) {
    if (lastPos < target) {
      return minValue;
    } else {
      return maxValue;
    }
  }

  lastPos = sumWV / sumW;
  return lastPos;
}
