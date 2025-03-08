
#include <Wire.h>

#include "leddriver.h"

// default constructor
CLedDriver::CLedDriver():
LEDReg0(0x0C),
LEDReg1(0x0D)
{
	// initialize I2C library
	//i2c_init();  
}

void CLedDriver::Init()
{
  // Wire.begin(); // join I2C bus as the master

	//   if(i2c_start(0x40)==0) //LED controller address
  //     {      
	//    if(i2c_write(0x80)==0)  //Control reg autoincrement starting at mode0
  //      {
	//     if(i2c_write(0x80)==0)  //mode1 auto inc
  //       {
	//      if(i2c_write(0x00)==0)  //mode2
  //        {
	//       if(i2c_write(0xFF)==0)       //PWM0
  //         {
	//        if(i2c_write(0xFF)==0)       //PWM1
  //          {
	//         if(i2c_write(0xFF)==0)       //PWM2
  //           {
	//          if(i2c_write(0xFF)==0)       //PWM3
  //            {
	//           if(i2c_write(0xFF)==0)       //PWM4
  //             {
	//            if(i2c_write(0xFF)==0)       //PWM5
  //              {
	//             if(i2c_write(0xFF)==0)       //PWM6
  //               {
	//              if(i2c_write(0xFF)==0)       //PWM7
  //                {
	//               if(i2c_write(0x00)==0)    //GRPPWM
  //                 {
	//                if(i2c_write(0x00)==0)    //GRPFREQ
  //                  {
	//                 if(i2c_write(0X00)==0)    //LEDOUT0
  //                   {
	//                  if(i2c_write(0x00)==0)    //LEDOUT1
  //                    {
  //                       CSerial::is() << "** CLED Driver Init Succeeded\n";
  //                    }                         
  //                    else {CSerial::is() << "** CLED Driver Init failed LED out 1\n"; } 
  //                   }
  //                   else {CSerial::is() << "** CLED Driver I2C Init failed led out 2!!\n"; } 
  //                  }
  //                  else {CSerial::is() << "** CLED Driver I2C Init failed grpfreq!!\n"; } 
  //                 }
  //                 else {CSerial::is() << "** CLED Driver I2C Init failed grppwm!!\n"; } 
  //                }
  //                else {CSerial::is() << "** CLED Driver I2C Init failed PWM 7!!\n"; } 
  //               }
  //               else {CSerial::is() << "** CLED Driver I2C Init failed PWM 6!!\n"; } 
  //              }
  //              else {CSerial::is() << "** CLED Driver I2C Init failed PWM 5!!\n"; } 
  //             }
  //             else {CSerial::is() << "** CLED Driver I2C Init failed PWM 4!!\n"; } 
  //            }
  //            else {CSerial::is() << "** CLED Driver I2C Init failed PWM 3 !!\n"; } 
  //           }
  //           else {CSerial::is() << "** CLED Driver I2C Init failed PWM 2!!\n"; } 
  //          }
  //          else {CSerial::is() << "** CLED Driver I2C Init failed PWM 1!!\n"; } 
  //         }
  //         else {CSerial::is() << "** CLED Driver I2C Init failed PWM 0 !!\n"; } 
  //        }
  //        else {CSerial::is() << "** CLED Driver I2C Init failed mODE 2!!\n"; } 
  //       }
  //       else {CSerial::is() << "** CLED Driver I2C Init failed aUTO iNC!!\n"; } 
  //      }                                                                
  //      else {CSerial::is() << "** CLED Driver I2C Init failed CTRL REG!!\n"; }                                                                                                                                                                    
  //     }
  //     else {CSerial::is() << "** CLED Driver I2C Init failed led addr!!\n"; }                                       
	  
	//   i2c_stop();
}

//brightness, 0 to 255
void CLedDriver::Dim(uint8_t Brightness)
{
	//WriteReg(0X0A, Brightness);
}

void CLedDriver::WriteReg(uint8_t Reg, uint8_t data)
{
  // Wire.beginTransmission(0x40); // informs the bus that we will be sending data to slave device 8 (0x08)
	// Wire.write(reg);              
  // Wire.write(data);
	// Wire.endTransmission();       // informs the bus and the slave device that we have finished sending data

}