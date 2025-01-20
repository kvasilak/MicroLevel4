/* MicroLevel Four Ride Height controller (c) 2025 Keith Vasilakes / Corvette Engineering */

#ifndef __COMMON_H_INCLUDED__
#define __COMMON_H_INCLUDED__

#include <Arduino.h>

class CCommon
{
  public:
    CCommon();

    void SetupIO();
    // MainModes_e GetMode(void);

    // MainModes_e RunManualMode();
    void RunManualMode();

    // MainModes_e RunCalibrate();

  private:

  int Getbuttons();

};
#endif