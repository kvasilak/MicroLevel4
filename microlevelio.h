/* MicroLevel Four Ride Height controller (c) 2025 Keith Vasilakes / Corvette Engineering */

#ifndef __MICROLEVELIO_H_INCLUDED__
#define __MICROLEVELIO_H_INCLUDED__

enum MainModes_e
{
  ModeManual,
  ModeAutomatic,
  ModeCalibrate
};

enum CornerStates_e{
  CornerStateHold,
  CornerStateFill,
  CornerStateDump
};

/*
input and output defines
*/

#include <Arduino.h>
//port B
#define FRONT_LEFT_HEIGHT       0 //PORT_A_0
#define FRONT_RIGHT_HEIGHT      1 //PORT_A_1
#define REAR_LEFT_HEIGHT        2 //PORT_A_2
#define REAR_RIGHT_HEIGHT       3 //PORT_A_3
#define FRONT_LEFT_PRESSURE     4 //PORT_A_4
#define FRONT_RIGHT_PRESSURE    5 //PORT_A_5
#define REAR_LEFT_PRESSURE      6 //PORT_A_6
#define REAR_RIGHT_PRESSURE     7 //PORT_A_7

//port A
#define SPARE_ONE               0 //PORT_B_0
#define SPARE_TWO               1 //PORT_B_1
#define SPARE_THREE             2 //PORT_B_2
#define SPARE_FOUR              3 //PORT_B_3
#define LR_DOWN                 4 //PORT_B_4
#define RR_DOWN                 5 //PORT_B_5
#define LF_DOWN                 6 //PORT_B_6
#define RF_DOWN                 7 //PORT_B_7

//port D
#define RX                      8 //PORT_D_
#define TX                      9 //PORT_D_
#define IO_1                    10 //PORT_D_
#define IO_2                    11 //PORT_D_
#define IO_3                    12 //PORT_D_
#define IO_4                    13 //PORT_D_
#define IO_5                    14 //PORT_D_
#define IO_6                    15 //PORT_D_

//port C
// #define SCL                  PORT_C_
// #define SDA                  PORT_C_
// #define TCK                  PORT_C_
// #define TMS                  ORT_C_
// #define TDO                  PORT_C_
// #define TDI                  PORT_C_
#define RR_UP                   22 //PORT_C_
#define LF_UP                   23 //PORT_C_

//port E
//#define XTAL1                 PORT_E_0
//#define XTAL2                 PORT_E_1
#define IO_7                    34  //PORT_E_2
#define IO_8                    35  //PORT_E_3
#define RF_UP                   36  //PORT_E_4
#define LR_UP                   37  //PORT_E_5
#define IGNITION_ON             38  //PORT_E_6

#define BUTTON_ONE              IO_7
#define BUTTON_TWO              IO_8


#define BTN_LF_UP       0
#define BTN_LF_DOWN     1
#define BTN_RF_UP       2
#define BTN_RF_DOWN     3
#define BTN_LR_UP       4
#define BTN_LR_DOWN     5
#define BTN_RR_UP       6
#define BTN_RR_DOWN     7

#define SOL_LF_UP       8
#define SOL_LF_DOWN     9
#define SOL_RF_UP       10
#define SOL_RF_DOWN     11
#define SOL_LR_UP       12
#define SOL_LR_DOWN     13
#define SOL_RR_UP       14
#define SOL_RR_DOWN     15

#define lED_LF_UP       8
#define lED_LF_DOWN     9
#define lED_RF_UP       10
#define lED_RF_DOWN     11
#define lED_LR_UP       12
#define lED_LR_DOWN     13
#define lED_RR_UP       14
#define lED_RR_DOWN     15

#endif