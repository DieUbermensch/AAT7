/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... TIMER
* FILENAME...... csl_wdtimdat.h
* DATE CREATED.. Thu 03/30/2000 
* PROJECT....... Chip Support Library
* COMPONENT..... CSL service layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   MODIFIED: 06/19/2000
*   LAST MODIFIED: (IM) 12/27/2000 modified for Amadeus
*   MODIFIED: 10 April 2003 added refrence CSL_WdtimData for .csldata size fix
*   
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the PWR module)
*       Reserved ROM Area for TIMER Data 
*
*
\******************************************************************************/
#ifndef _CSL_WDTIM_DATA_H_
#define _CSL_WDTIM_DATA_H_

#include <csl_std.h>
#include <csl_chiphal.h>

#if (_WDTIMB_SUPPORT)    /* 5502 */
   typedef struct {
 	volatile Uint16 wdtpid1;
	volatile Uint16 wdtpid2;
	volatile Uint16 wdtemu;
	volatile Uint16 wdtclk;
	volatile Uint16 wdtgpint;
	volatile Uint16 wdtgpen;
	volatile Uint16 wdtgpdir;
	volatile Uint16 wdtgpdat;
	volatile Uint16 wdtcnt1;
	volatile Uint16 wdtcnt2;
	volatile Uint16 wdtcnt3;
	volatile Uint16 wdtcnt4;
	volatile Uint16 wdtprd1;
	volatile Uint16 wdtprd2;
	volatile Uint16 wdtprd3;
	volatile Uint16 wdtprd4;
	volatile Uint16 wdtctl1;
	volatile Uint16 wdtctl2;
	volatile Uint16 wdtgctl1;
    volatile Uint16 wdtgctl2;
    volatile Uint16 wdtwctl1;
    volatile Uint16 wdtwctl2;
  } WDTIM_RegObj, *WDTIM_RegPtr;

  #define CSL_WDTIMDATAINIT\
   { 0x0000u, 0x000Bu, (WDTIM_RegPtr)0x4000u }   /* Start of Wtchdog Regs */

  typedef struct {
    Uint16 devNum;
    Uint16 EventId;
    WDTIM_RegPtr regs;
  }CSL_WdtimDataObj;
#else
  #define CSL_WDTIMDATAINIT\
   { 0x000Bu  }  /* WDTIM EventId */

  typedef struct {
    Uint16 WDTIM_reserved;
  }CSL_WdtimDataObj;
 
#endif  /* WDTIM_SUPPORT */

  extern CSL_WdtimDataObj CSL_WdtimData;

  #define CSL_WDTIM_DATA  CSL_WdtimData
#endif
