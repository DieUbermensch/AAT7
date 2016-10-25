/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... GPIO
* FILENAME...... csl_gpio.h
* DATE CREATED.. Fri 06/09/2000 
* PROJECT....... Chip Support Library
* COMPONENT..... CSL service layer
* PREREQUISITS.. 
* VERSION....... 1.00
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:         06/09/2000 created for C5510
*   LAST MODIFIED:   04/16/2001 updated module name and other header comments
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the GPIO module)
*
*
*
\******************************************************************************/
#ifndef _CSL_GPIO_H_
  #define _CSL_GPIO_H_

  #include <csl.h>
  #include <csl_chiphal.h>

   
   #if (CHIP_5509_FAMILY)
      #include <csl_gpio5509.h>
   #elif (CHIP_5502_FAMILY)
      #include <csl_gpio5502.h>
   #else    /* Default (CHIP_5510_FAMILY) */
      #include <csl_gpio5510.h>
   #endif

#endif   /* _CSL_GPIO_H_ */
/******************************************************************************\
* End of gpio.h
\******************************************************************************/
