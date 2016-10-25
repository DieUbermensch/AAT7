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
#ifndef _GPIO_DAT_H_
  #define _GPIO_DAT_H_

  #include <csl_chiphal.h>

  #if (CHIP_5509_FAMILY)
    #include <csl_gpio5509dat.h>
  #elif (CHIP_5502_FAMILY)
    #include <csl_gpio5502dat.h>
  #else    /* Default (CHIP_5510_FAMILY) */
    #include <csl_gpio5510dat.h>
  #endif

#endif
