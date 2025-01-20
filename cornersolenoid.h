/* MicroLevel Four Ride Height controller (c) 2025 Keith Vasilakes / Corvette Engineering */


#ifndef __CORNERSOLENOID_H_INCLUDED__
#define __CORNERSOLENOID_H_INCLUDED__

#include "microlevelio.h"

class CCornerSolenoid
{
  public:
    CCornerSolenoid();

    void Setup(int fill, int dump);
    //void Run(void);
    void SetState(CornerStates_e state);
    
    

  private:
  void FillSolenoid(bool on);
    void DumpSolenoid(bool on);
  
  

};

#endif