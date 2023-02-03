
void calibration() {

  const int Loop = 7000 ;

  for (int i = 0; i < Num_Sens; i++) {
    minCalibr[i] = 1023;
  }
  for (int i = 0; i < Num_Sens; i++) {
    maxCalibr[i] = 0;
  }

  drive(50, -50);

  for (int i = 0; i < Loop; i++) {
    readSens();
    
    for (int i = 0; i < Num_Sens; i++) {

      if (Sens[i] > maxCalibr[i]) {
        maxCalibr[i] = Sens[i];


      }
      if (Sens[i] < minCalibr[i]) {
        minCalibr[i] = Sens[i];
      }

    }
   saveCalibr();
  }
}
