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

    enum LevelStates_e{
      LevelStateAuto,
      LevelStateManual
    };

    enum LevelEvents_e{
      EvtButtonPressed,
      EvtButtonReleased,
      //LevelEventTimer
    };

    enum Buttons_e{
      BtnLF,
      BtnRF,
      BtnLR,
      BtnRR,
      BtnAuto
    };

    enum BtnPressType_e{
      BtnPressBounce,
      BtnPressShort,
      BtnPressLong
    };

    void Setup( CCorner *lf, CCorner *fr, CCorner *lr, CCorner *rr);
    //void SetState(CornerStates_e state);

    void Event( CLevel::Buttons_e btn, CLevel::LevelEvents_e evt);

  private:

    void SetState(LevelStates_e state);
    
    LevelStates_e LevelState;

    CCorner *LF;
    CCorner *RF;
    CCorner *LR;
    CCorner *RR;

    void BtnHndlerLF(CLevel::LevelEvents_e evt);
    void BtnHndlerRF(CLevel::LevelEvents_e evt);
    void BtnHndlerLR(CLevel::LevelEvents_e evt);
    void BtnHndlerRR(CLevel::LevelEvents_e evt);

    CLevel::BtnPressType_e PressType(uint32_t start, uint32_t end);
    
};
#endif