
void readSens() {
  for (int i = 0; i < Num_Sens; i++) {
    Sens[i] = analogRead(Pins[i]);
  }
 

  for (int i = 0; i < Num_Sens; i++) {
    Sens[i] = (Sens[i] + analogRead(Pins[i])) / 2;
  }
}
