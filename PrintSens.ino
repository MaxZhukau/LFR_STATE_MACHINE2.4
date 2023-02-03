void printSens() {
  for (int i = 0; i < Num_Sens; i++) {
    readSens();
    BTSerial.print (Sens[i]);
    BTSerial.print(' ');
  }
  BTSerial.println();
  BTSerial.print("position:");
  BTSerial.println(readLine());
  delay(400);
}
