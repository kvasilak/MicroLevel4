
#include <Wire.h>
#include <avr/pgmspace.h> 
#include <Arduino.h>

#include "leddriver.h"

#define Addr_GND 0x60 
//7 bit format is 0x3F 
uint8_t PWM_Gamma64[64]= 
{ 
  0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07, 
  0x08,0x09,0x0b,0x0d,0x0f,0x11,0x13,0x16, 
  0x1a,0x1c,0x1d,0x1f,0x22,0x25,0x28,0x2e, 
  0x34,0x38,0x3c,0x40,0x44,0x48,0x4b,0x4f, 
  0x55,0x5a,0x5f,0x64,0x69,0x6d,0x72,0x77, 
  0x7d,0x80,0x88,0x8d,0x94,0x9a,0xa0,0xa7, 
  0xac,0xb0,0xb9,0xbf,0xc6,0xcb,0xcf,0xd6, 
  0xe1,0xe9,0xed,0xf1,0xf6,0xfa,0xfe,0xff 
}; 

void CLedDriver::Setup() 
{ 
  // put your setup code here, to run once: 
  Wire.begin(); 
  Wire.setClock(400000);//I2C 400kHz 
  //  pinMode(4,OUTPUT);//SDB 
  //  digitalWrite(4,HIGH);//SDB_HIGH 
  Init(); 
} 
void CLedDriver::Run(void) 
{ 
// put your main code here, to run repeatedly: 
   Demo();//breath mode 
} 

void CLedDriver::WriteByte(uint8_t Dev_Add,uint8_t Reg_Add,uint8_t Reg_Dat) 
{ 
  Wire.beginTransmission(Dev_Add/2);  
  Wire.write(Reg_Add); // sends regaddress 
  Wire.write(Reg_Dat); // sends regaddress 
  Wire.endTransmission(); // stop transmitting 
} 
void CLedDriver::Init(void) 
{ 
  uint8_t i = 0; 

  for(i=0x49;i<=0x6C;i++) 
  { 
    WriteByte(Addr_GND,i,0x80);//turn on all LED 
  } 

   for(i=0x01;i<=0x48;i++) 
  { 
    WriteByte(Addr_GND,i,0x00);//write all HPWM set 0x00 
  } 

  WriteByte(Addr_GND,0x6D,0x00);//update PWM & congtrol registers 
  WriteByte(Addr_GND,0x6E,0xFF);//Global current 
  WriteByte(Addr_GND,0x6F,0xFF);//Global current 
  WriteByte(Addr_GND,0x70,0xFF);//Global current 
  WriteByte(Addr_GND,0x00,0x01);//normal operation and set 32k HFPS & 120 LFPS 8bit 
  // write 0x11, set 64k HFPS & 240 LFPS 8bit 
  // write 0x31, set 128k HFPS & 480 LFPS 8bit 
  // write 0x03, set 32k HFPS & 120 LFPS 10bit 
} 

void CLedDriver::Demo(void)//white LED 
{ 
  int8_t i = 0; 
  int8_t j = 0; 

//Red LEDs ON?
  for(i=1;i<=24;i+=2) 
  { 
    WriteByte(Addr_GND,(i*3),0xFF);//set   HPWM_L   
    WriteByte(Addr_GND,0x6D,0x00);//update PWM & congtrol registers
    delay(80);//100ms 
  } 

  delay(500); //keep 0.5s 

//Green LEDs ON
  for(i=23;i>0;i-=2)//G LED running 
  { 
    WriteByte(Addr_GND,(i*3-2),0xFF);//set  HPWM_L  
    WriteByte(Addr_GND,0x6D,0x00);//update PWM & congtrol registers 
    delay(80);//100ms 
  } 

  delay(500); //keep 0.5s 

  //Blue LEDs ON
  for(i=1;i<=24;i+=2)//B LED running 
  { 
    WriteByte(Addr_GND,(i*3+2),0xFF);//set  HPWM_L   
    WriteByte(Addr_GND,0x6D,0x00);//update PWM & congtrol registers 
    delay(80);//100ms 
  } 
  delay(500); //keep 0.5s 


  for (j=63;j>=0;j--)//all LED breath falling  
  { 
    for(i=1;i<=0x48;i+=2) 
    {
      WriteByte(Addr_GND,i,PWM_Gamma64[j]);//set all HPWM_L  
    }

    WriteByte(Addr_GND,0x6D,0x00);//update PWM & congtrol registers 
    delay(30);//20ms 
  }  
  delay(500); //keep o 0.5s 
}
