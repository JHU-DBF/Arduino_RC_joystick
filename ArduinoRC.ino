// #include "MegaJoy.h"
#include "UnoJoy.h"

#define CH1 21
#define CH2 20
#define CH3 19
#define CH4 18
#define CH5 2

#define NEUTRAL_THROTTLE 1000
#define NEUTRAL_INPUT 1500

volatile int nCH1In = NEUTRAL_THROTTLE;
volatile int nCH2In = NEUTRAL_INPUT;
volatile int nCH3In = NEUTRAL_INPUT;
volatile int nCH4In = NEUTRAL_INPUT;
volatile int nCH5In = NEUTRAL_INPUT;

volatile unsigned long ulStartPeriod1 = 0;
volatile unsigned long ulStartPeriod2 = 0;
volatile unsigned long ulStartPeriod3 = 0;
volatile unsigned long ulStartPeriod4 = 0;
volatile unsigned long ulStartPeriod5 = 0;

void setup(){
  attachInterrupt(digitalPinToInterrupt(CH1),calcInput1,CHANGE);
  attachInterrupt(digitalPinToInterrupt(CH2),calcInput2,CHANGE);
  attachInterrupt(digitalPinToInterrupt(CH3),calcInput3,CHANGE);
  attachInterrupt(digitalPinToInterrupt(CH4),calcInput4,CHANGE);
  attachInterrupt(digitalPinToInterrupt(CH5),calcInput5,CHANGE);

  // setupMegaJoy();
  setupUnoJoy();
}

void loop(){
  // megaJoyControllerData_t controllerData = getControllerData();
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);
}



dataForController_t getControllerData(void){
// megaJoyControllerData_t getControllerData(void){

  dataForController_t controllerData =  getBlankDataForController();
  // megaJoyControllerData_t controllerData = getBlankDataForMegaController();
  // for (int i = 2; i < 54; i++){
  //   controllerData.buttonArray[(i - 2) / 8] |= (LOW) << ((i - 2) % 8);
  // }
  
  controllerData.leftStickX = (int)((nCH4In - 1000)*0.256);
  controllerData.leftStickY = (int)((nCH1In - 1000)*0.256);
  controllerData.rightStickX = (int)((nCH2In - 1000)*0.256);
  controllerData.rightStickY = (int)((nCH3In - 1000)*0.256);

  return controllerData;
}

void calcInput1()
{
  if(digitalRead(CH1) == HIGH)
  { 
    ulStartPeriod1 = micros();
  }
  else
  {
    if(ulStartPeriod1)
    {
      nCH1In = (int)(micros() - ulStartPeriod1);
      ulStartPeriod1 = 0;
    }
  }
}

void calcInput2()
{
  if(digitalRead(CH2) == HIGH)
  { 
    ulStartPeriod2 = micros();
  }
  else
  {
    if(ulStartPeriod2)
    {
      nCH2In = (int)(micros() - ulStartPeriod2);
      ulStartPeriod2 = 0;
    }
  }
}

void calcInput3()
{
  if(digitalRead(CH3) == HIGH)
  { 
    ulStartPeriod3 = micros();
  }
  else
  {
    if(ulStartPeriod3)
    {
      nCH3In = (int)(micros() - ulStartPeriod3);
      ulStartPeriod3 = 0;
    }
  }
}

void calcInput4()
{
  if(digitalRead(CH4) == HIGH)
  { 
    ulStartPeriod4 = micros();
  }
  else
  {
    if(ulStartPeriod4)
    {
      nCH4In = (int)(micros() - ulStartPeriod4);
      ulStartPeriod4 = 0;
    }
  }
}

void calcInput5()
{
  if(digitalRead(CH5) == HIGH)
  { 
    ulStartPeriod5 = micros();
  }
  else
  {
    if(ulStartPeriod5)
    {
      nCH5In = (int)(micros() - ulStartPeriod5);
      ulStartPeriod5 = 0;
    }
  }
}
