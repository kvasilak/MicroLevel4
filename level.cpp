/* MicroLevel Four Ride Height controller (c) 2025 Keith Vasilakes / Corvette Engineering */

#include <inttypes.h>
#include <Arduino.h>

#include "level.h"

#define DEBOUNCETIME 20     //miliseconds
#define LONGPRESSTIME 3000
#define BtnRepeatTime 100

CLevel::CLevel()
{}

void CLevel::Setup(CCorner *lf, CCorner *rf, CCorner *lr, CCorner *rr)
{
//  Button = btn;
  LF = lf;
  RF = rf;
  LR = lr;
  RR = rr;

//  attachInterrupt(digitalPinToInterrupt(btn),   LevelButton, FALLING );
}

void CLevel::SetState(LevelStates_e state)
{
  LevelState = state;
}

//debounce and check for short press or long press
CLevel::BtnPressType_e CLevel::PressType(uint32_t start, uint32_t end)
{
  CLevel::BtnPressType_e type = CLevel::BtnPressBounce;

  uint32_t time = end - start;

  if(time < DEBOUNCETIME) //debounceing
  {
      type = CLevel::BtnPressBounce;
  }
  else if( time < LONGPRESSTIME) //short press
  {
      type = CLevel::BtnPressShort;
  }
  else //long press
  {
    type = CLevel::BtnPressLong;
  }

  return type;
}

//start timer on press
//Check on release
//If <20ms ignore
//else if < 3 seconds short press event
//if > 3 seconds, long press
void CLevel::BtnHndlerLF(CLevel::LevelEvents_e evt)
{
  static uint32_t StartPress;

  switch(evt)
  {
    case EvtButtonPressed: 
    {
      //don't reset time on a bounce
      if( (millis() - StartPress) > BtnRepeatTime)
      {
        StartPress = millis();
      }
    }
    break;

    case EvtButtonReleased:
    {
      LF->Event(PressType(StartPress, millis()) );
    }
    break;
  }
}

void CLevel::BtnHndlerRF(CLevel::LevelEvents_e evt)
{
  switch(evt)
  {
    case CLevel::EvtButtonPressed: 
    {
      
    }
    case CLevel::EvtButtonReleased:
    {

    }
  }
}

void CLevel::BtnHndlerLR(CLevel::LevelEvents_e evt)
{
  switch(evt)
  {
    case CLevel::EvtButtonPressed: 
    {
      
    }
    case CLevel::EvtButtonReleased:
    {

    }
  }
}

void CLevel::BtnHndlerRR(CLevel::LevelEvents_e evt)
{
  switch(evt)
  {
    case CLevel::EvtButtonPressed: 
    {
      
    }
    case CLevel::EvtButtonReleased:
    {

    }
  }
}

void CLevel::Event( CLevel::Buttons_e btn, CLevel::LevelEvents_e evt)
{
  switch(LevelState)
  {
    case CLevel::LevelStateManual:
    {
      switch(btn)
      {
        case CLevel::BtnLF:
        {
          BtnHndlerLF(evt);
        }
        break;

        case CLevel::BtnRF:
        {
          BtnHndlerRF(evt);
        }
        break;

        case CLevel::BtnLR:
        {
          BtnHndlerLR(evt);
        }
        break;

        case CLevel::BtnRR:
        {
          BtnHndlerRR(evt);
        }
        break;

        case CLevel::BtnAuto:
        {
          BtnHndlerRR(evt);
        }
        break;
      } 
    }
    break;

    case CLevel::LevelStateAuto:
    {
      if(btn == CLevel::BtnAuto) 
      {
        SetState(CLevel::LevelStateManual);
      }
    }
    break;
  }
}
