/* MicroLevel Four Ride Height controller (c) 2025 Keith Vasilakes / Corvette Engineering */

#include <inttypes.h>
#include <Arduino.h>

#include "level.h"

CLevel::CLevel()
{}

void CLevel::Setup(int btn, CCorner *lf, CCorner *fr, CCorner *lr, CCorner *rr)
{
  Button = btn;
  LF = lf;
  FR = fr;
  LR = lr;
  RR = rr;
}