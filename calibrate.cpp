/* MicroLevel Four Ride Height controller (c) 2025 Keith Vasilakes / Corvette Engineering */

#include <inttypes.h>
#include <Arduino.h>

#include "calibrate.h"

CCalibrate::CCalibrate()
{}

void CCalibrate::Setup(int btn, CCorner *lf, CCorner *fr, CCorner *lr, CCorner *rr)
{
  Button = btn;
  LF = lf;
  FR = fr;
  LR = lr;
  RR = rr;
}

void CCalibrate::SetState(CalStates_e state)
{
  CalState = state;
}

void CCalibrate::BtnHndlr( int button)
{
  switch(CalState)
  {
    case CalStateManual:
    {
      if(button == Button) //only two buttons Up and down
      {
        SetState(CalStateAuto);
      }

    }
    break;

    case CalStateAuto:
    {
      if(button == Button) //only two buttons Up and down
      {
        SetState(CalStateManual);
      }
    }
    break;
  }
}
