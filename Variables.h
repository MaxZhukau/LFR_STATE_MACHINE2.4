byte EventLine[256];

enum EV {
  EV_No_Line,
  EV_L_Line,
  EV_R_Line,
  EV_Corner_R,
  EV_Corner_L,
  EV_Cross,
  EV_Center,
  EV_Ub
};

String Ev[8] {
  "Ev_NoLine",
  "Ev_Left",
  "Ev_Right",
  "Ev_CronerR",
  "Ev_CronerL",
  "Ev_Cross",
  "Ev_Center",
  "Ev_UB"
};

int error;
int lastError;
int delta;
int deltaError;
int minCalibr[8] {};
int maxCalibr[8] {};
const long IR_STOP = 0xBF40FF00;
const long IR_MOVE = 0xEF1FF00;
const long IR_READSENS = 0xB649FF00;
const long IR_INFO = 0xE11EFF00;
const long IR_CALIBR = 0xB34CFF00;
const long IR_INFO_CALIBR = 0xB24DFF00;
const char BT_STOP = '2';
const char BT_MOVE = '1';
const char BT_READSENS = '3';
const char BT_INFO = '5';
const char BT_CALIBR = '4';
const char BT_INFO_CALIBR = '6';
const char KP_P = '7';
const char KD_P = '8';
const char KP_M = '9';
const char KD_M = 'a';
const char B_P = 'b';
const char B_M = 'p';

const byte button = 12;
const byte led = 11;
const byte IR = 10;
const byte LMotorPwm = 5;
const byte LMotor2 = 4;
const byte LMotor1 = 7;
const byte RMotorPwm = 6;
const byte RMotor2 = 9;
const byte RMotor1 = 8;

const int ADR = 100;

//long IRData;
long BTData;

int BSpeed = 200;
int ws[8] = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000 };


int minSpeed = -50 ;
int maxSpeed = 220;
int minValue = 0;
int maxValue = 9000;
int TH_LINE = 200;
int NOISE = 90;

float kp = 0.07;
float kd = 0.5;

void readSens();
void printSens();
void printInfo();
int readLine();
void resetLFR();
void loadCalibr();
void saveCalibr();
char getBTCode();

unsigned long StartTime;
unsigned long DeltaTime;
byte DL = 0;

enum State { STOP,
             MOVE,
             READSENS,
             INFO,
             CALIBR,
             INFO_CALIBR
           };
State currentState = STOP;
int target = 4500;
int lastPos = target;
const byte Num_Sens = 8;
int Sens[Num_Sens] {};
int Pins[Num_Sens] { A0, A1, A2, A3, A4, A5, A6, A7 };
