/* MicroLevel Four Ride Height controller (c) 2025 Keith Vasilakes / Corvette Engineering */
/*
based on the ATMega324PB. 
Note that the ATMega324PB version has more IO and is quite different than the ATMega324
and requires the Mighty core 3.0.3m https://github.com/MCUdude/MightyCore
*/

#include "common.h"
#include "cornerbutton.h"
#include "cornerleds.h"
#include "cornersolenoid.h"

CCommon Cmn;
CCornerLeds LedLF;
CCornerLeds LedRF;
CCornerLeds LedLR;
CCornerLeds LedRR;

CCornerSolenoid SolLF;
CCornerSolenoid SolRF;
CCornerSolenoid SolLR;
CCornerSolenoid SolRR;

CCornerButton ButtonLF;
CCornerButton ButtonRF;
CCornerButton ButtonLR;
CCornerButton ButtonRR;

// void BTN_LF_UP_Released(void)
// {ButtonLF.BtnHndlr(BTN_LF_UP);}

// void BTN_LF_DOWN_Released(void)
// {ButtonLF.BtnHndlr(BTN_LF_DOWN);}

// void BTN_RF_UP_Released(void)
// {ButtonRF.BtnHndlr(BTN_RF_UP);}

// void BTN_RF_DOWN_Released(void)
// {ButtonRF.BtnHndlr(BTN_RF_DOWN);}

// void BTN_LR_UP_Released(void)
// {ButtonLR.BtnHndlr(BTN_LR_UP);}

// void BTN_LR_DOWN_Released(void)
// {ButtonLR.BtnHndlr(BTN_LR_DOWN);}

// void BTN_RR_UP_Released(void)
// {ButtonRR.BtnHndlr(BTN_RR_UP);}

// void BTN_RR_DOWN_Released(void)
// {ButtonRR.BtnHndlr(BTN_RR_DOWN);}

void setup() 
{
  Cmn.SetupIO();

  Serial.begin(115200);

  pinMode(BUTTON_ONE, INPUT_PULLUP);
  pinMode(BUTTON_TWO, INPUT_PULLUP);

  Serial.print("MicroLevel Four Start\n");

  LedLF.Setup(lED_LF_UP, lED_LF_DOWN);
  LedRF.Setup(lED_RF_UP, lED_RF_DOWN);
  LedLR.Setup(lED_LR_UP, lED_LR_DOWN);
  LedRR.Setup(lED_RR_UP, lED_RR_DOWN);

  SolLF.Setup(SOL_LF_UP, SOL_LF_DOWN);
  SolRF.Setup(SOL_RF_UP, SOL_RF_DOWN);
  SolLR.Setup(SOL_LR_UP, SOL_LR_DOWN);
  SolRR.Setup(SOL_RR_UP, SOL_RR_DOWN);

  ButtonLF.Setup(BTN_LF_UP, BTN_LF_DOWN, &LedLF, &SolLF);
  ButtonRF.Setup(BTN_RF_UP, BTN_RF_DOWN, &LedRF, &SolRF);
  ButtonLR.Setup(BTN_LR_UP, BTN_LR_DOWN, &LedLR, &SolLR);
  ButtonRR.Setup(BTN_RR_UP, BTN_RR_DOWN, &LedRR, &SolRR);

//attach button interrupts
  // attachInterrupt(digitalPinToInterrupt(BTN_LF_UP),   BTN_LF_UP_Released, FALLING );
  // attachInterrupt(digitalPinToInterrupt(BTN_LF_DOWN), BTN_LF_DOWN_Released, FALLING );
  // attachInterrupt(digitalPinToInterrupt(BTN_RF_UP),   BTN_RF_UP_Released, FALLING );
  // attachInterrupt(digitalPinToInterrupt(BTN_RF_DOWN), BTN_RF_DOWN_Released, FALLING );
  // attachInterrupt(digitalPinToInterrupt(BTN_LR_UP),   BTN_LR_UP_Released, FALLING );
  // attachInterrupt(digitalPinToInterrupt(BTN_LR_DOWN), BTN_LR_DOWN_Released, FALLING );
  // attachInterrupt(digitalPinToInterrupt(BTN_RR_UP),   BTN_RR_UP_Released, FALLING );
  // attachInterrupt(digitalPinToInterrupt(BTN_RR_DOWN), BTN_RR_DOWN_Released, FALLING );
}

void loop() 
{
  //buttons are interrupt driven

  LedLF.Run();
  LedRF.Run();
  LedLR.Run();
  LedRR.Run();
}
