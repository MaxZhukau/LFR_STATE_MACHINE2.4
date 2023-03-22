
long getIRCode() {
  long retCmd = 0;
  if (IrReceiver.decode()) {
    switch (IrReceiver.decodedIRData.decodedRawData) {
      case IR_MOVE:
        retCmd =  IR_MOVE;
        break;
      case IR_STOP:
        retCmd =  IR_STOP;
     break;
      case IR_CALIBR:
        retCmd =  IR_CALIBR;
        break;
      case IR_READSENS:
        retCmd =  IR_READSENS;
        break;
      case IR_INFO:
        retCmd =  IR_INFO;
        break;
      case  IR_INFO_CALIBR:
        retCmd = IR_INFO_CALIBR;
        break;
    }
    IrReceiver.resume();
  }

  return retCmd;

}
void PrintIRCode() {
  if (IrReceiver.decode()) {
    IrReceiver.printIRResultShort(&Serial);
  }
  IrReceiver.resume();
}
