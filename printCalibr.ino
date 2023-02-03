void PrintCalibr(){
  for(int i = 0;i<Num_Sens;i++){
    BTSerial.print(minCalibr[i]);
    BTSerial.print(' ');
    }
   BTSerial.println(' ');
    for(int i = 0;i<Num_Sens;i++){
    BTSerial.print(maxCalibr[i]);
    BTSerial.print(' ');
    }
  
  
  }
