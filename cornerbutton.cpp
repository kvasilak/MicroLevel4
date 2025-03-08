/* MicroLevel Four Ride Height controller (c) 2025 Keith Vasilakes / Corvette Engineering */

/* looks at button states ( interrupts ) and determines new button states
Then tell the LED and solenoid classes what state to transition to.
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

static CCorner *CB;

static void UP_Released(void)
{CB->BtnHndlr(BTN_LF_UP);}

static void DOWN_Released(void)
{CB->BtnHndlr(BTN_LF_DOWN);}

CCorner::CCorner()
{}

void CCorner::Setup(int up, int dwn, CCornerLeds *led, CCornerSolenoid *sol)
{
  CB = this; //set pointer to ourself

  UpButton = up;
  DownButton = dwn;

  attachInterrupt(digitalPinToInterrupt(up),   UP_Released, FALLING );
  attachInterrupt(digitalPinToInterrupt(dwn), DOWN_Released, FALLING );

  Led = led;
  Sol = sol;
}


void CCorner::SetState(CornerStates_e state)
{
  CornerState = state;

  //update LEDs
  Led->SetState(state);

  //update solenoids
  Sol->SetState(state);

}

//this function is called from the ISR when either of the two buttons is released.
void CCorner::BtnHndlr( int button)
{
  switch(CornerState)
  {
    case CornerStateHold:
    {
      if(button == UpButton) //only two buttons Up and down
      {
        SetState(CornerStateFill);
      }
      else if(button == DownButton)
      {
        SetState(CornerStateDump);
      }
    }
    break;

    case CornerStateFill:
    {
      if(button == UpButton) //only two buttons Up and down
      {
        SetState(CornerStateHold);
      }
      else if(button == DownButton)
      {
        SetState(CornerStateDump);
      }
    }
    break;

    case CornerStateDump:
    {
      if(button == UpButton) //only two buttons Up and down
      {
        SetState(CornerStateFill);
      }
      else if(button == DownButton)
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

