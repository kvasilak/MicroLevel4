/* 
* level.h
*
* Created: 8/8/2025 10:33:49 PM
* Author: Corvette Engineering / keith vasilakes
*/

#include "microlevelio.h"
#include "corner.h"

#ifndef __LEVEL_INCLUDED_H__
#define __LEVEL_INCLUDED_H__

class CTravel
{
  public:
  CTravel();

    enum TravelStates_e{
        TravelStateAuto,
        TravelStateManual
    };

    void Setup(int btn, CCorner *lf, CCorner *fr, CCorner *lr, CCorner *rr);
    //void SetState(CornerStates_e state);

    void BtnHndlr( int button);

  private:

    void SetState(TravelStates_e state);
    
    int Button;
    TravelStates_e TravelState;

    CCorner *LF;
    CCorner *FR;
    CCorner *LR;
    CCorner *RR;
    
};
#endif