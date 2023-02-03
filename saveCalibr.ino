void saveCalibr() {
  int adr = ADR;
  for (int i = 0; i < Num_Sens; i++) {
    EEPROM.put(adr, minCalibr[i]);
    EEPROM.put(adr + 2, maxCalibr[i]);
    adr = adr + 4;
  }
}
