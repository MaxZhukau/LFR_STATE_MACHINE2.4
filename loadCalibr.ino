void loadCalibr() {
  int adr = ADR;
  for (int i = 0; i < Num_Sens; i++) {
    EEPROM.get(adr, minCalibr[i]);
    EEPROM.get(adr + 2, maxCalibr[i]);
    adr = adr + 4;
  }
}
