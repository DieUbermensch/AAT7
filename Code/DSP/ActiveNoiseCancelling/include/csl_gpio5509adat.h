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
#ifndef _GPIO5509A_DAT_H_
  #define _GPIO5509A_DAT_H_

  #include <csl_chiphal.h>

  #if (_GPIO_PGPIO_SUPPORT)
    #include <_csl_pgpiodat.h>
 #else
   #include <_csl_gpiodat.h>
 #endif
#endif
