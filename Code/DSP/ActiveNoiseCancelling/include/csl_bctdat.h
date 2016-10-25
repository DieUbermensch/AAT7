/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... BCT (Bios Counter)
* FILENAME...... csl_bctdat.h
* DATE CREATED.. Thu 03/30/2000 
* PROJECT....... Chip Support Library
* COMPONENT..... CSL service layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED: 02/19/2002
*   MODIFIED: 10 April 2003 added reference for CSL_BctData for .csldata size
*                           fix
*------------------------------------------------------------------------------
* DESCRIPTION:  
*       Reserved ROM Area for Bios Counter Data 
*
*
\******************************************************************************/
#ifndef _CSL_BCT_DATA_H_
#define _CSL_BCT_DATA_H_

#include <csl_std.h>
#include <csl_chiphal.h>

#if (_BCT_SUPPORT)    /* 5502 */
   typedef struct {
 	volatile Uint16 bctpid1;
	volatile Uint16 bctpid2;
	volatile Uint16 bctemu;
	volatile Uint16 bctclk;
	volatile Uint16 bctgpint;
	volatile Uint16 bctgpen;
	volatile Uint16 bctgpdir;
	volatile Uint16 bctgpdat;
	volatile Uint16 bctcnt1;
	volatile Uint16 bctcnt2;
	volatile Uint16 bctcnt3;
	volatile Uint16 bctcnt4;
	volatile Uint16 bctprd1;
	volatile Uint16 bctprd2;
	volatile Uint16 bctprd3;
	volatile Uint16 bctprd4;
	volatile Uint16 bctctl1;
	volatile Uint16 bctctl2;
	volatile Uint16 bctgctl1;
  } BCT_RegObj, *BCT_RegPtr;

  #define CSL_BCTDATAINIT\
   { 0x0000u, 0x0000u, (BCT_RegPtr)0x7800u  }   /* Start of Bios Counter Regs */

  typedef struct {
    Uint16 devNum;
    Uint16 EventId;
    BCT_RegPtr regs;
  }CSL_BctDataObj;
#else
  #define CSL_BCTDATAINIT\
   { 0x0000u  }  /* BCT EventId (dummy this has none) */

  typedef struct {
    Uint16 BCT_reserved;
  }CSL_BctDataObj;
 
#endif  /* BCT_SUPPORT */

extern CSL_BctDataObj CSL_BctData;

#define CSL_BCT_DATA  CSL_BctData

#endif
