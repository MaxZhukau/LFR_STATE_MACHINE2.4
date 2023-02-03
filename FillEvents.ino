void fillEvents() {
  for (int i = 0; i <= 256; i++) {
    EventLine[i] = EV_Ub;
  }
  EventLine[0] = EV_No_Line;

  EventLine[1] = EV_R_Line;
  EventLine[2] = EV_R_Line;
  EventLine[3] = EV_R_Line;
  EventLine[6] = EV_R_Line;
   EventLine[12] = EV_R_Line;
    EventLine[4] = EV_R_Line;
    EventLine[7] = EV_R_Line;
   

  EventLine[128] = EV_L_Line;
  EventLine[192] = EV_L_Line;
  EventLine[96] = EV_L_Line;
  EventLine[48] = EV_L_Line;
  EventLine[64] = EV_L_Line;
  EventLine[32] = EV_L_Line;
   EventLine[224] = EV_L_Line;
   

  EventLine[15] = EV_Corner_R;
  EventLine[31] = EV_Corner_R;

  EventLine[240] = EV_Corner_L;
  EventLine[248] = EV_Corner_L;

  EventLine[126] = EV_Cross;
  EventLine[255] = EV_Cross;
  EventLine[254] = EV_Cross;
  EventLine[127] = EV_Cross;

  EventLine[24] = EV_Center;
  EventLine[48] = EV_Center;
  EventLine[8] = EV_Center;
  EventLine[16] = EV_Center;

}