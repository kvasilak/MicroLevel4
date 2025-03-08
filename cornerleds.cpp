/* MicroLevel Four Ride Height controller (c) 2025 Keith Vasilakes / Corvette Engineering */

#include <inttypes.h>
#include <Arduino.h>

#include "cornerleds.h"

CCornerLeds::CCornerLeds()
{}

void CCornerLeds::Setup(int up, int dwn)
{
  //which leds to use
  Up = up;
  Dwn = dwn;
}

void CCornerLeds::SetState(CornerStates_e state)
{
  //add state to circular buffer
  Events.Put(state);
}

void CCornerLeds::FillLED(bool on)
{
  if(on)
  {
    //WriteReg();
  }
  else
  {

  }
}

void CCornerLeds::DumpLED(bool on)
{
  if(on)
  {

  }
  else
  {
    
  }
}

void CCornerLeds::Run()
{
  //read state from circular button
  CornerStates_e state;
  bool ok;

  ok = Events.Get(state);

  if(ok)
  {
    switch(state)
    {
      case CornerStateHold:
      {
        FillLED(false);
        DumpLED(false);
      }
      break;

      case CornerStateFill:
      {
        FillLED(true);
        DumpLED(false);
      }
      break;

      case CornerStateDump:
      {
        FillLED(false);
        DumpLED(true);
      }
      break;
    }
  }

}