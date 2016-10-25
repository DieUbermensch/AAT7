/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... GPIO
* FILENAME...... csl_gpiodat.h
* DATE CREATED.. Thu 03/30/2000 
* PROJECT....... Chip Support Library
* COMPONENT..... CSL service layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   
*   MODIFIED: 10 APril 2003 added reference for CSL_GpioData for .csldata size
*                          fix
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the GIO module)
*       Reserved Area for GIO Data 
*
*
\******************************************************************************/
#ifndef _GPIO_DATA_H_
  #define _GPIO_DATA_H_
  #define CSL_GPIODATAINIT\
  { 0x0000u }

  typedef struct {
   Uint16 GpioReserved;
  } CSL_GpioDataObj;

extern CSL_GpioDataObj CSL_GpioData;

#define CSL_GPIO_DATA  CSL_GpioData

#endif
