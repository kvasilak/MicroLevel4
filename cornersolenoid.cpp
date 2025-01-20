/* MicroLevel Four Ride Height controller (c) 2025 Keith Vasilakes / Corvette Engineering */

#include <inttypes.h>
#include <Arduino.h>

#include "cornersolenoid.h"

CCornerSolenoid::CCornerSolenoid()
{}

void CCornerSolenoid::Setup(int fill, int dump)
{}

void CCornerSolenoid::FillSolenoid(bool on)
{
(void)on;
}

void CCornerSolenoid::DumpSolenoid(bool on)
{
(void)on;
}

void CCornerSolenoid::SetState(CornerStates_e state)
{
  switch(state)
  {
    case CornerStateHold:
    {
      FillSolenoid(false);
      DumpSolenoid(false);
    }
    break;

    case CornerStateFill:
    {
      FillSolenoid(true);
      DumpSolenoid(false);
    }
    break;

    case CornerStateDump:
    {
      FillSolenoid(false);
      DumpSolenoid(true);
    }
    break;
  }
  
}