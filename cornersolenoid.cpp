/* MicroLevel Four Ride Height controller (c) 2025 Keith Vasilakes / Corvette Engineering */

#include <inttypes.h>
#include <Arduino.h>

#include "cornersolenoid.h"

CCornerSolenoid::CCornerSolenoid()
{}

void CCornerSolenoid::Setup(int fill, int dump)
{
  Fill = fill;
  Dump = dump;

  pinMode(Fill, OUTPUT);
  pinMode(Dump, OUTPUT);
}

void CCornerSolenoid::SetState(CornerStates_e state)
{
  switch(state)
  {
    case CornerStateHold:
    {
      digitalWrite(Fill, LOW);
      digitalWrite(Dump, LOW);
    }
    break;

    case CornerStateFill:
    {
      digitalWrite(Fill, HIGH);
      digitalWrite(Dump, LOW);
    }
    break;

    case CornerStateDump:
    {
      digitalWrite(Fill, LOW);
      digitalWrite(Dump, HIGH);
     }
    break;
  }
  
}