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

class CLevel
{
  public:
    CLevel();

    void Setup(int btn, CCorner *lf, CCorner *fr, CCorner *lr, CCorner *rr);
    //void SetState(CornerStates_e state);

  private:
    int Button;
    CCorner *LF;
    CCorner *FR;
    CCorner *LR;
    CCorner *RR;
    
};
#endif