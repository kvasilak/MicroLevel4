/* MicroLevel Four Ride Height controller (c) 2025 Keith Vasilakes / Corvette Engineering */

#include <inttypes.h>
#include <Arduino.h>

#include "common.h"
#include "microlevelio.h"

//setup the IO for the sequencer
void CCommon::SetupIO()
{
  //DDRA = 0xFF;
  DDRB = 0xFF;
  DDRC = B11000011;
  DDRD = 0xF0; //B11110000;
}

// MainModes_e CCommon::GetMode(void)
// {
//   MainModes_e Mode = digitalRead(BUTTON_ONE) == LOW;
//   Mode |= (digitalRead(BUTTON_TWO) == LOW) << 1;

//   return Mode;
// }

CCommon::CCommon()
{

}

int CCommon::Getbuttons()
{
  return 0;
}

void CCommon::RunManualMode()
{
  // int button = Getbuttons();

  // switch(button)
  // {
  //   case BTN_LF_UP:
  //   {

  //   }
  //   break;

  //   case BTN_LF_DOWN:
  //   {

  //   }
  //   break;

  //   case BTN_RF_UP:
  //   {

  //   }
  //   break;

  //   case BTN_RF_DOWN:
  //   {

  //   }
  //   break;

  //   case BTN_LR_UP:
  //   {

  //   }
  //   break;

  //   case BTN_LR_DOWN:
  //   {

  //   }
  //   break;

  //   case BTN_RR_UP:
  //   {

  //   }
  //   break;

  //   case BTN_RR_DOWN:
  //   {

  //   }
  //   break;
  // }
}

// void CCommon::RunCalibrate()
// {

// }