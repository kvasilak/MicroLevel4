/* 
* CLed.h
*
* Created: 1/13/2015 10:33:49 PM
* Author: keith
*/


#ifndef __CLEDDRIVER_H__
#define __CLEDDRIVER_H__

#include <avr/io.h>			//I/O
#include <inttypes.h>
#include <avr/pgmspace.h>		//PGM space read

class CLedDriver
{

public:

  void Setup(void);
	//void On(uint8_t led, bool on);
	//void Brightness(uint8_t led, uint8_t brightness);
	//void Dim(uint8_t brightness);
	//void Blink(uint8_t rate);
  void Run(void);

private:

void Init(void);

void Demo(void);

void WriteByte(uint8_t Dev_Add,uint8_t Reg_Add,uint8_t Reg_Dat);

}; //CLedDriver

#endif //__CLEDDRIVER_H__
