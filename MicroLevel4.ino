/* MicroLevel 4 Ride Height controller (c) 2026 Keith Vasilakes / Corvette Engineering */
/*
based on the ATMega324PB. 
Note that the ATMega324PB version has more IO and is quite different than the ATMega324
and requires the Mighty core 3.0.3m https://github.com/MCUdude/MightyCore

usage ==================================
Power up
setup and start running
May do return to travel on power up

Power down
Doesn't do much

Travel mode
Set each corner to the calibrated height
Will also maintain height if the load varies

Manual mode
Raise and lower individual corners

Calibrate
Set height to desired ride height
Press calibrate to save height values

I/O ====================================
Digital in (buttons)

D2. travel (long press to calibrate)
D3. up
D4. down
D5. select L/R

Digital out
D6. L up
D7. L down
D8. r dwn
D9. R dwn
D10. 
D11. 


Analog in
A0. L
A1. R
A2. 
A3. 
A4. 
A5. 

i2c
LED controller
accel?

Design ===============================

******CCornerLeds
turn LEDs on and off

******CCornerSolenoid
Controls turning the proper solenoid on and off

used to manually control height
Used by travel mode to control height

******CCorner
Used by travel mode to control height

******CLevel
manges the corners while in travel mode

****** Circular buffer
Used to store and recieve events

Main state machine
*/

#include "common.h"
#include "corner.h"
#include "cornerleds.h"
#include "cornersolenoid.h"
#include "level.h"

 //CCommon Cmn;
 CCornerLeds LedLF;
 CCornerLeds LedRF;
 CCornerLeds LedLR;
 CCornerLeds LedRR;

 CCornerSolenoid SolLF;
 CCornerSolenoid SolRF;
 CCornerSolenoid SolLR;
 CCornerSolenoid SolRR;

 CCorner CornerLF;
 CCorner CornerRF;
 CCorner CornerLR;
 CCorner CornerRR;

 CLevel Leveler;


const int BUTTON1_PIN = 2; // Button connected to pin 2
const int BUTTON2_PIN = 3; // Button connected to pin 3


// Variables for button state tracking
int buttonState = LOW;       // Current reading from the button
int lastButtonState = LOW;   // Previous reading from the button

// Debounce timing
unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;    // milliseconds

volatile bool buttonPressed = false;
volatile unsigned long Btn1Debounce = 0;
volatile unsigned long Btn2Debounce = 0;

void setup() 
{
  //Cmn.SetupIO();

  Serial.begin(115200);

  Serial.print("MicroLevel Four Start\n");

  LedLF.Setup(lED_LF_UP, lED_LF_DOWN);
  LedRF.Setup(lED_RF_UP, lED_RF_DOWN);
  LedLR.Setup(lED_LR_UP, lED_LR_DOWN);
  LedRR.Setup(lED_RR_UP, lED_RR_DOWN);

  SolLF.Setup(SOL_LF_UP, SOL_LF_DOWN);
  SolRF.Setup(SOL_RF_UP, SOL_RF_DOWN);
  SolLR.Setup(SOL_LR_UP, SOL_LR_DOWN);
  SolRR.Setup(SOL_RR_UP, SOL_RR_DOWN);

// //attach evrything to each corner
  CornerLF.Setup( &LedLF, &SolLF);
  CornerRF.Setup(&LedRF, &SolRF);
  CornerLR.Setup(&LedLR, &SolLR);
  CornerRR.Setup(&LedRR, &SolRR);

  Leveler.Setup( &CornerLF, &CornerRF, &CornerLR, &CornerRR);


   pinMode(BUTTON1_PIN, INPUT_PULLUP); // Use internal pull-up resistor
   pinMode(BUTTON2_PIN, INPUT_PULLUP); // Use internal pull-up resistor

  // pinMode(LED1_PIN, INPUT_PULLUP);
  // pinMode(LED2_PIN, INPUT_PULLUP);

  // pinMode(LED1_PIN, OUTPUT);
  // pinMode(LED2_PIN, OUTPUT);   

   attachInterrupt(digitalPinToInterrupt(BUTTON1_PIN), Btn1IRQ, FALLING);  
   attachInterrupt(digitalPinToInterrupt(BUTTON2_PIN), Btn2IRQ, FALLING); 
}

//LF up button
void Btn1IRQ()
{
  if(millis() - Btn1Debounce > 100)
  {
    Btn1Debounce = millis();
    Leveler.Event(CLevel::BtnLF, CLevel::EvtButtonPressed);
    Serial.println("Button 1 pressed");
  }
}

//LF down button
void Btn2IRQ()
{
  if(millis() - Btn2Debounce > 100)
  {
    Btn2Debounce = millis();
    Leveler.Event(CLevel::BtnRF, CLevel::EvtButtonPressed);
    Serial.println("Button 2 pressed");
  }
}

void loop() 
{
  int SensorZero = analogRead(A0);
  int SensorOne = analogRead(A1);

  // print out the value you read:
  Serial.print("A0: ");
  Serial.print(SensorZero);
  Serial.print(", A1: ");
  Serial.println(SensorOne);
  //Serial.println();


  delay(500);  // delay in between reads for stability

// static uint16_t count = 0;
//   //buttons are interrupt driven

//   // LedLF.Run();
//   // LedRF.Run();
//   // LedLR.Run();
//   // LedRR.Run();

//   if (buttonPressed)
//   {
//     buttonPressed = false; // Reset flag
//     Serial.println("Button interrupt detected!");
//   }

// // Read the button (LOW when pressed because of INPUT_PULLUP)
//   int reading = digitalRead(3); //buttonPin);

//   // Check if the button state has changed
//   if (reading != lastButtonState) 
//   {
//     lastDebounceTime = millis(); // Reset debounce timer
//   }

//   // If enough time has passed, confirm the change
//   if ((millis() - lastDebounceTime) > debounceDelay) 
//   {
//     // If the button state has changed
//     if (reading != buttonState) {
//       buttonState = reading;

//       // Toggle LED only when button is pressed (LOW)
//       if (buttonState == LOW) 
//       {
//         digitalWrite(ledPin, !digitalRead(ledPin)); // Toggle LED
//         Serial.println("Button pressed - LED toggled");
//       }
//     }
//   }

//   // Save the reading for next loop
//   lastButtonState = reading;
}
