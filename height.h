/* height.h
*
* Created: 8/8/2025 10:33:49 PM
* Author: Corvette Engineering / keith vasilakes
*/

#include "microlevelio.h"
#include "corner.h"

#ifndef __HEIGHT_INCLUDED_H__
#define __HEIGHT_INCLUDED_H__

class CHeight
{
  public:
  CHeight();

    enum HeightStates_e{
        HeightStateAuto,
        HeightStateManual
    };

    void Setup(int btn, CCorner *lf, CCorner *fr, CCorner *lr, CCorner *rr);
    //void SetState(CornerStates_e state);

    void BtnHndlr( int button);

  private:

    void SetState(HeightStates_e state);
    
    int Button;
    HeightStates_e HeightState;

    CCorner *LF;
    CCorner *FR;
    CCorner *LR;
    CCorner *RR;
    
};
#endif