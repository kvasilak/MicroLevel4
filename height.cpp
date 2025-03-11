/* MicroLevel Four Ride Height controller (c) 2025 Keith Vasilakes / Corvette Engineering */

#include <inttypes.h>
#include <Arduino.h>

#include "height.h"

CHeight::CHeight()
{}

void CHeight::Setup(int btn, CCorner *lf, CCorner *fr, CCorner *lr, CCorner *rr)
{
  Button = btn;
  LF = lf;
  FR = fr;
  LR = lr;
  RR = rr;
}

void CHeight::SetState(HeightStates_e state)
{
  HeightState = state;
}

void CHeight::BtnHndlr( int button)
{
  switch(HeightState)
  {
    case HeightStateManual:
    {
      if(button == Button) //only two buttons Up and down
      {
        SetState(HeightStateAuto);
      }

    }
    break;

    case HeightStateAuto:
    {
      if(button == Button) //only two buttons Up and down
      {
        SetState(HeightStateManual);
      }
    }
    break;
  }
}
