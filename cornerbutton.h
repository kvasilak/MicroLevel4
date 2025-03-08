/* MicroLevel Four Ride Height controller (c) 2025 Keith Vasilakes / Corvette Engineering */

#ifndef __CORNERBUTTON_H_INCLUDED__
#define __CORNERBUTTON_H_INCLUDED__

#include "cornerleds.h"
#include "cornersolenoid.h"
#include "microlevelio.h"

class CCornerButton
{
  public:
    CCornerButton();

    void Setup();
    void Setup(int up, int dwn, CCornerLeds *Leds, CCornerSolenoid *sol);
    void BtnHndlr(int button);

  private:
    void SetState(CornerStates_e state);


    CornerStates_e CornerState;;

    CCornerLeds *Led;
    CCornerSolenoid *Sol;

    int UpButton;
    int DownButton;
};

#endif