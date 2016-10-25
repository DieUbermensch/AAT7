/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... GPIO
* FILENAME...... gpiodata.h
* DATE CREATED.. Thu 03/30/2000 
* PROJECT....... Chip Support Library
* COMPONENT..... CSL service layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   
*   
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the GIO module)
*       Reserved Area for GIO Data 
*
*
\******************************************************************************/
#ifndef _GPIO5502_DAT_H_
  #define _GPIO5502_DAT_H_


#define _GPIO_PIN_GRPS         (4)
 
  typedef struct {
     Uint16 regIndx;
     Uint16 pinsAllocated;
     Uint16 *enableReg;
     Uint16 *dirReg;
     Uint16 *datReg;
  } GPIO_PrivateObj;

  #define CSL_GPIODATAINIT  {\
      0x0000u,            \
      0x0000u,            \
      (Uint16 *)0x0000u,  \
      (Uint16 *)0x3400u,  \
      (Uint16 *)0x3401u,  \
      0x0000u,            \
      0x0000u,            \
      (Uint16 *)0x4400u,  \
      (Uint16 *)0x4401u,  \
      (Uint16 *)0x4402u,  \
      0x0000u,            \
      0x0000u,            \
      (Uint16 *)0x4403u,  \
      (Uint16 *)0x4404u,  \
      (Uint16 *)0x4405u,  \
      0x0000u,            \
      0x0000u,            \
      (Uint16 *)0x4406u,  \
      (Uint16 *)0x4407u,  \
      (Uint16 *)0x4408u   \
  }

  typedef struct {
     GPIO_PrivateObj pinObj[_GPIO_PIN_GRPS];
  } CSL_GpioDataObj;

extern CSL_GpioDataObj   CSL_GpioData;

#define CSL_GPIO_DATA    CSL_GpioData

#endif
