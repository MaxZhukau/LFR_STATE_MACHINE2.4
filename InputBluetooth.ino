
char getBTCode() {
  char retCmd = '0';
  if (BTSerial.available()) {
    switch (BTSerial.read()) {
      case '1':
        retCmd = BT_MOVE;
        break;
      case '2':
        retCmd = BT_STOP;
        break;
      case '3':
        retCmd = BT_CALIBR;
        break;
      case '4':
        retCmd = BT_READSENS;
        break;
      case '5':
        retCmd = BT_INFO;
        break;
      case '6':
        retCmd = BT_INFO_CALIBR;
        break;
      case '7':
        kp = kp + 0.01;
        break;
      case '8':
        kd = kd + 0.10;
        break;
      case '9':
        kp = kp - 0.01;
        break;
      case 'a':
        kd = kd - 0.10;
        break;
      case 'b':
        BSpeed = BSpeed - 10;
        break;
      case 'p':
        BSpeed = BSpeed + 10;
        break;
        case 's':
        maxSpeed=maxSpeed+10;
        break;
         case 'w':
        maxSpeed=maxSpeed-10;
        break;
         case 'd':
        minSpeed = minSpeed+10;
        break;
         case 'h':
        maxSpeed=minSpeed-10;
        break;
        case 'r':
        TH_LINE=TH_LINE+10;
        break;
        case 'l':
        TH_LINE=TH_LINE-10;
        break;
        case 'f':
       NOISE = NOISE+10;
       break;
       case 'x':
       NOISE = NOISE-10;
        break;
    }

  }

  return retCmd;

}
