/* height.h
*
* Created: 8/8/2025 10:33:49 PM
* Author: Corvette Engineering / keith vasilakes
*/

#include "microlevelio.h"
#include "corner.h"

#ifndef __CALIBRATE_INCLUDED_H__
#define __CALIBRATE_INCLUDED_H__

class CCalibrate
{
  public:
  CCalibrate();

    enum CalStates_e{
        CalStateAuto,
        CalStateManual
    };

    void Setup(int btn, CCorner *lf, CCorner *fr, CCorner *lr, CCorner *rr);
    //void SetState(CornerStates_e state);

    void BtnHndlr( int button);

  private:

    void SetState(CalStates_e state);
    
    int Button;
    CalStates_e CalState;

    CCorner *LF;
    CCorner *FR;
    CCorner *LR;
    CCorner *RR;
    
};
#endif