
#include <SoftwareSerial.h>
#include <EEPROM.h>
#include <IRremote.hpp>
#include "Variables.h"
SoftwareSerial BTSerial(3, 2);

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(LMotor1, OUTPUT);
  pinMode(LMotor2, OUTPUT);
  pinMode(RMotor1, OUTPUT);
  pinMode(RMotor2, OUTPUT);

  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
  Serial.begin(9600);
  //IrReceiver.begin(IR);
  loadCalibr();
  Get();
  fillEvents();
  BTSerial.begin(9600);
}

void loop() {
  //IRData = getIRCode();
  BTData = getBTCode();

  DoState();
  Serial.println(currentState);
}

void DoState() {
  switch (currentState) {
    case STOP:
      DoSTOP();
      break;

    case MOVE:
      DoMOVE();
      break;

    case READSENS:
      DoREADSENS();
      break;

    case INFO:
      DoINFO();
      break;

    case CALIBR:
      DoCALIBR();
      break;

    case INFO_CALIBR:
      DoINFO_CALIBR();
      break;
  }
}

void ChangeState(State newState) {
  switch (newState) {

    case STOP:
      BTSerial.println("TO_STOP");
      drive(0, 0);
      break;

    case MOVE:
      BTSerial.println("TO_MOVE");
      resetLFR();
      break;

    case READSENS:
      BTSerial.println("TO_READSENS");
      break;

    case INFO:
      BTSerial.println("TO_INFO");
      break;

    case CALIBR:
      BTSerial.println("TO_CALIBR");
      break;

    case INFO_CALIBR:
      BTSerial.println("TO_INFO_CALIBR");
      break;
  }
  currentState = newState;
}

void DoINFO_CALIBR() {
  PrintCalibr();
  ChangeState(STOP);
}

void DoSTOP() {
  if (CheckMOVE()) return;
  if (CheckCALIBR()) return;
  if (CheckREADSENS()) return;
  if (CheckINFO()) return;
  if (CheckINFO_CALIBR()) return;
}

void DoMOVE() {
  if (CheckSTOP()) return;
  LFR();
}

void DoREADSENS() {
  if (CheckMOVE()) return;
  if (CheckSTOP()) return;
  if (CheckCALIBR()) return;
  if (CheckINFO()) return;
  if (CheckINFO_CALIBR()) return;
  printSens();
}

void DoINFO() {
  printINFO();
  ChangeState(STOP);
}

void DoCALIBR() {
  calibration();
  ChangeState(INFO_CALIBR);
}

bool CheckINFO_CALIBR() {

  if (/*IRData == IR_INFO_CALIBR ||*/ BTData == BT_INFO_CALIBR) {
    ChangeState(INFO_CALIBR);
    return true;
  }
  return false;
}


bool CheckSTOP() {

  if (/*IRData == IR_STOP ||*/ BTData == BT_STOP) {
    ChangeState(STOP);
    return true;
  }
  return false;
}

bool CheckMOVE() {

  if (/*IRData == IR_MOVE ||*/ BTData == BT_MOVE) {
    ChangeState(MOVE);
    return true;
  }
  return false;
}

bool CheckCALIBR() {

  if (/*IRData == IR_CALIBR ||*/ BTData == BT_CALIBR) {
    ChangeState(CALIBR);
    return true;
  }
  return false;
}

bool CheckREADSENS() {

  if (/*IRData == IR_READSENS ||*/ BTData == BT_READSENS) {
    ChangeState(READSENS);
    return true;
  }
  return false;
}

bool CheckINFO() {

  if (/*IRData == IR_INFO ||*/ BTData == BT_INFO) {
    ChangeState(INFO);
    return true;
  }
  return false;
}
