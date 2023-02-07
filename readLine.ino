int readLine() {
  long sumWV = 0;
  int sumW = 0;
  bool onLine = false;
  byte W = 128;
  byte DL = 0;

  readSens();

  for (int i = 0; i < Num_Sens; i++) {
    Sens[i] = map(Sens[i], minCalibr[i], maxCalibr[i], 0, 1000);

    if (Sens[i] > 1000) {
      Sens[i] = 1000;
    }
    if (Sens[i] < 0) {
      Sens[i] = 0;
    }
    if (Sens[i] > TH_LINE) {
      onLine = true;
      DL = DL + W;
    }
    W = W / 2;
    if (Sens[i] > NOISE) {
      sumWV = sumWV + (long)ws[i] * Sens[i];
      sumW = sumW + Sens[i];
    }
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
