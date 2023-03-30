void Save()
{
EEPROM.put(200, BSpeed);
EEPROM.put(210,  minSpeed);
EEPROM.put(220, maxSpeed);
EEPROM.put(230, TH_LINE);
EEPROM.put(240,  NOISE);

}
