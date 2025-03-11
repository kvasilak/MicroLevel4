/* MicroLevel Four Ride Height controller (c) 2025 Keith Vasilakes / Corvette Engineering */

#include <inttypes.h>
#include <Arduino.h>

#include "travel.h"

static CTravel *CL;

static void TravelButton(void)
{CL->BtnHndlr(BTN_LF_UP);}

CTravel::CTravel()
{}

void CTravel::Setup(int btn, CCorner *lf, CCorner *fr, CCorner *lr, CCorner *rr)
{
  CL = this;
  Button = btn;
  LF = lf;
  FR = fr;
  LR = lr;
  RR = rr;

  attachInterrupt(digitalPinToInterrupt(btn),   Button, FALLING );
}

void CTravel::SetState(TravelStates_e state)
{
  TravelState = state;
}

void CTravel::BtnHndlr( int button)
{
  switch(TravelState)
  {
    case TravelStateManual:
    {
      if(button == Button) //only two buttons Up and down
      {
        SetState(TravelStateAuto);
      }

    }
    break;

    case TravelStateAuto:
    {
      if(button == Button) //only two buttons Up and down
      {
        SetState(TravelStateManual);
      }
    }
    break;
  }
}
