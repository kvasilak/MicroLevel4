/* MicroLevel Four Ride Height controller (c) 2026 Keith Vasilakes / Corvette Engineering */

// wait for an event and updates the LED and solenoids 

//  inputs:
//  Up event ( may be button, remote, from the autolevel system, or ???)
//  Down event

// Button states
// Hold, filling, dumping

// In hold -> up button press -> Fill
// In Hold -> Down button press -> Dump
// In filling -> Up button press -> Hold
// In Filling -> down button pressed -> Dump
// In dumping -> up button press -> Fill
// In Dumping -> down button press -> Hold

#include <inttypes.h>
#include <Arduino.h>

#include "corner.h"
#include "cornersolenoid.h"
#include "cornerleds.h"

CCorner::CCorner()
{}

void CCorner::Setup( CCornerLeds *led, CCornerSolenoid *sol)
{
  Led = led;
  Sol = sol;
}


void CCorner::SetState(CornerStates_e state)
{
  if( CornerState != state)
  {
    CornerState = state;

    //update LEDs
    Led->SetState(state);

    //update solenoids
    Sol->SetState(state);
  }
}

//this function is called from the ISR when either of the two buttons is released.
void CCorner::Event( int evt)
{
  Serial.print("Event:");
  Serial.print(evt);
  Serial.print("," );

  switch(CornerState)
  {
    case CornerStateHold:
    {
      Serial.println("hold->");
      if(evt == UpEvent) //only two buttons Up and down
      {
        Serial.println("fill");
        SetState(CornerStateFill);
      }
      else if(evt == DownEvent)
      {
        Serial.println("dump");
        SetState(CornerStateDump);
      }
    }
    break;

    case CornerStateFill:
    {
      Serial.print("Fill->");
      if(evt == UpEvent) //only two buttons Up and down
      {
        Serial.println("hold");
        SetState(CornerStateHold);
      }
      else if(evt == DownEvent)
      {
        Serial.println("dump");
        SetState(CornerStateDump);
      }
    }
    break;

    case CornerStateDump:
    {
      Serial.print("Dump->");
      if(evt == UpEvent) //only two buttons Up and down
      {
        Serial.println("fill");
        SetState(CornerStateFill);
      }
      else if(evt == DownEvent)
      {
        Serial.println("hold");
        SetState(CornerStateHold);
      }
      else
      {
        Serial.println("NA");
      }
    }
    break;

    //handle travel buttons?
    default:
    {
      Serial.println("Default");
    }
  }
}

