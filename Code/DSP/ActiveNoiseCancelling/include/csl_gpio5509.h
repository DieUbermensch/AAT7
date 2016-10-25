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
#ifndef _CSL_GPIO5509_H_
  #define _CSL_GPIO5509_H_

  #include <csl.h>
  #include <csl_chiphal.h>

   #if (_GPIO_SUPPORT)

     #if (_GPIO_PGPIO_SUPPORT)
        #include <_csl_pgpio.h>
     #else
       #include <_csl_gpio.h>
     #endif

  #endif 					/* _GPIO_SUPPORT_ */
#endif   /* _CSL_GPIO_H_ */
/******************************************************************************\
* End of gpio.h
\******************************************************************************/
