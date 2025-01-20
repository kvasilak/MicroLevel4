/* MicroLevel Four Ride Height controller (c) 2025 Keith Vasilakes / Corvette Engineering */

/* looks at button states ( interrupts ) and determines new button states
Then tell the solenoid class what state to transition to.
*/


//  inputs:
//  an up button
//  a down button
// Corner Solenoid class ( pointer?? )

// Button states
// Hold, filling, dumping

// In hold -> up button press -> Fill
// In Hold -> Down button press -> Dump
// In filling -> Up button press -> Hold
// In Filling -> down button pressed -> Dump
// In dumping -> up button press -> Fill
// In Dumping -> down button press -> Hold
// In dumping -> Up button press -> Fill

#include <inttypes.h>
#include <Arduino.h>

#include "cornerbutton.h"
#include "cornersolenoid.h"
#include "cornerleds.h"


CCornerButton::CCornerButton()
{

}

void CCornerButton::Setup(int up, int dwn, CCornerLeds *led, CCornerSolenoid *sol)
{
  UpButton = up;
  DownButton = dwn;

  Led = led;
  Sol = sol;
}


void CCornerButton::SetState(CornerStates_e state)
{
  CornerState = state;

  //update LEDs
  Led->SetState(state);

  //update solenoids
  Sol->SetState(state);

}

//this function is called from the ISR when either of the two buttons is released.
void CCornerButton::BtnHndlr( )
{
  switch(CornerState)
  {
    case CornerStateHold:
    {
      if(Button == UpButton) //only two buttons Up and down
      {
        SetState(CornerStateFill);
      }
      else if(Button == DownButton)
      {
        SetState(CornerStateDump);
      }

    }
    break;

    case CornerStateFill:
    {
      if(Button == UpButton) //only two buttons Up and down
      {
        SetState(CornerStateHold);
      }
      else if(Button == DownButton)
      {
        SetState(CornerStateDump);
      }
    }
    break;

    case CornerStateDump:
    {
      if(Button == UpButton) //only two buttons Up and down
      {
        SetState(CornerStateFill);
      }
      else if(Button == DownButton)
      {
        SetState(CornerStateHold);
      }
    }
    break;

    //handle travel buttons
    default:
    {

    }
  }
}

