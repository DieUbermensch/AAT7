/****************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved 
*------------------------------------------------------------------------------
* MODULE NAME... PLL
* FILENAME...... csl_pll.h
* DATE CREATED.. Mon Jan 28 14:25:28 2002
* PROJECT....... Chip Support Library
* COMPONENT..... Service Layer
* PREREQUISITS.. 
*------------------------------------------------------------------------------
*
* HISTORY:
*	 Created:		Mon Jan 28 14:25:28 2002 (Automatic generation)
*	 Last Modified:	
*
*------------------------------------------------------------------------------
* DESCRIPTION: CSL Service Layer interface for the PLL module 
*              Supports PLL for 5510/5509/5502
*              pllA - 5510/5509 PLL
*              pllB - 5502 PLL
*
\*************************************************************************/

#ifndef _CSL_PLL_H_
  #define _CSL_PLL_H_

  #include <csl_std.h>
  #include <csl.h>
  #include <csl_chiphal.h>

  #if (_PLL_SUPPORT)
    #if (_PLLB_SUPPORT) 
       #include <csl_pllB.h>
    #elif (_PLLA_SUPPORT)
      #include <csl_pllA.h>
    #else
      #error PLL Support Not Defined
    #endif /* _PLLB_SUPPORT */
  #endif  /* _PLL_SUPPORT  */
#endif  /* CSL_PLL_H */

/******************************************************************************\
*     
*      End of csl_pll.h 
*
\******************************************************************************/
