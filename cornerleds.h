/* MicroLevel Four Ride Height controller (c) 2025 Keith Vasilakes / Corvette Engineering */


#ifndef __CORNERLEDS_H_INCLUDED__
#define __CORNERLEDS_H_INCLUDED__

#include "circularbuffer.h"
#include "microlevelio.h"
#include "leddriver.h"

class CCornerLeds : private CLedDriver
{
  public:
    CCornerLeds();

    void Setup(int up, int dwn);

    void Run();

    void SetState(CornerStates_e state);

    void FillLED(bool on);

    void DumpLED(bool on);

  private:

    CircularBuffer <CornerStates_e, 5> Events;

    int Up;
    int Dwn;
};

#endif