/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... WATCHDOG TIMER
* FILENAME...... csl_wdtim.h
* DATE CREATED.. Sun 06/20/1999 
* PROJECT....... Chip Support Library
* COMPONENT..... service layer
* PREREQUISITS.. cslhal.h
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:       06/20/1999 (BWC) Created for C6x.  
*   MODIFIED:      12/06/2000 (FSCA) Modification for C54x.
*   MODIFIED:      02/18/2000 (FSCA) C54x Romability.
*   MODIFIED: 	 06/19/2000 make #ifdefs consistent with new csl_ header names,
*                            cpluplus compatability
*   LAST MODIFIED: 12/22/2000 (IM) Modified for Amadeus.
*
*------------------------------------------------------------------------------
* DESCRIPTION:  (interface file for the WATCHDOG TIMER module)
*
*
*
\******************************************************************************/
#ifndef _CSL_WDTIM_H_
#define _CSL_WDTIM_H_


#include <_csl.h>
#include <csl_chiphal.h>

#if (_WDTIM_SUPPORT)
  #if (_WDTIMA_SUPPORT)
     #include <csl_wdtimA.h>
  #elif (_WDTIMB_SUPPORT)
     #include <csl_wdtimB.h>
  #endif
#else
  #ifndef _WDTIM_MOD_ /*TIMER_SUPPORT */
    #error Watchdog Timer Module Not Supported on Specified Target
  #endif
#endif /*WDTIM_SUPPORT */

#endif /* _CSL_WDTIM_H_ */                
/******************************************************************************\
* End of csl_wdtim.h
\******************************************************************************/

