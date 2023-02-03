void printINFO() {
  BTSerial.print("kp=");
  BTSerial.print(" ");
  BTSerial.println(kp);
  BTSerial.print("kd=");
  BTSerial.print(" ");
  BTSerial.println(kd);
  BTSerial.print("NOISE=");
  BTSerial.print(" ");
  BTSerial.println(NOISE);
  BTSerial.print("MAX_SPEED=");
  BTSerial.print(" ");
  BTSerial.println(maxSpeed);
  BTSerial.print("MIN_SPEED=");
  BTSerial.print(" ");
  BTSerial.println(minSpeed);
  BTSerial.print("BSpeed=");
  BTSerial.print(" ");
  BTSerial.println(BSpeed);
  BTSerial.print("TH=");
  BTSerial.print(" ");
  BTSerial.println(TH_LINE);
  BTSerial.println("///////////////////////////////////////");
  for (int i = 0; i < Num_Sens; i++) {
    BTSerial.print(minCalibr[i]);
    BTSerial.print(' ');
  }
  BTSerial.println(' ');
  for (int i = 0; i < Num_Sens; i++) {
    BTSerial.print(maxCalibr[i]);
    BTSerial.print(' ');
  }
  BTSerial.println(' ');
}
