/* MicroLevel Four Ride Height controller (c) 2025 Keith Vasilakes / Corvette Engineering */

//https://github.com/kriswiner/IS31FL3246/blob/main/LedRing_IS31FL3246A_Dragonfly/LedRing_IS31FL3246A_Dragonfly.ino

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

  pinMode(Up, OUTPUT); 
  pinMode(Dwn, OUTPUT); 

  digitalWrite(Up, HIGH); // Turn LED off
  digitalWrite(Dwn, HIGH); 
  
  // Serial.print("up: ");
  // Serial.print(up);
  // Serial.print(", dwn: ");
  // Serial.println(dwn);
}

void CCornerLeds::SetState(CornerStates_e state)
{
  //add state to circular buffer
  Events.Put(state);
}

//todo spi connection to LED controller
void CCornerLeds::FillLED(bool on)
{
  // Serial.print("fill: ");
  // Serial.println(on);

  digitalWrite(Up, on);
}

void CCornerLeds::DumpLED(bool on)
{
   digitalWrite(Dwn, on);
}

void CCornerLeds::Run()
{
  //read state from circular button
  CornerStates_e state;
  bool ok;

  ok = Events.Get(state);

  if(ok) // is there an event in the queue?
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