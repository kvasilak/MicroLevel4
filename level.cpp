/* MicroLevel Four Ride Height controller (c) 2025 Keith Vasilakes / Corvette Engineering */

#include <inttypes.h>
#include <Arduino.h>

#include "level.h"

static CLevel *CL;

static void LevelButton(void)
{CL->BtnHndlr(BTN_LF_UP);}

CLevel::CLevel()
{}

void CLevel::Setup(int btn, CCorner *lf, CCorner *fr, CCorner *lr, CCorner *rr)
{
  Button = btn;
  LF = lf;
  FR = fr;
  LR = lr;
  RR = rr;

  attachInterrupt(digitalPinToInterrupt(btn),   LevelButton, FALLING );
}

void CLevel::SetState(LevelStates_e state)
{
  LevelState = state;
}

void CLevel::BtnHndlr( int button)
{
  switch(LevelState)
  {
    case LevelStateManual:
    {
      if(button == Button) //only two buttons Up and down
      {
        SetState(LevelStateAuto);
      }

    }
    break;

    case LevelStateAuto:
    {
      if(button == Button) //only two buttons Up and down
      {
        SetState(LevelStateManual);
      }
    }
    break;
  }
}
