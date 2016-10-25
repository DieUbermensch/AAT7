/****************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved 
*------------------------------------------------------------------------------
* MODULE NAME... HPI
* FILENAME...... csl_hpidat.h
* DATE CREATED.. Thu Mar 21 09:27:17 2002
* PROJECT....... Chip Support Library
* COMPONENT..... Service Layer
* PREREQUISITS.. 
*------------------------------------------------------------------------------
*
* HISTORY:
*	 Created:		Thu Mar 21 09:27:17 2002 (Automatic generation)
*	 Last Modified:	3 Apr 2003 changed module names to fit datasheet sprs166c
*                                  revised Feb 2003
*                   10 April 2003 added reference for CSL_UhpiData
*                                     for .csldata size fix               
*
*------------------------------------------------------------------------------
* DESCRIPTION: CSL Service Layer interface for the HPI module 
*
\*************************************************************************/

#ifndef _CSL_HPIDAT_H_
#define _CSL_HPIDAT_H_

#include <csl_std.h>
#include <csl_chiphal.h>

#if (_HPI_SUPPORT) 

#include <csl_hpihal.h>

/*----------------------------------------------------------------*\
*	 HPI scope and inline control macros 			
\*----------------------------------------------------------------*/

typedef struct {
      Uint16 pidlsw;
      Uint16 pidmsw;
	Uint16 hpwremu;
      Uint16 rsrvd1[3];
	Uint16 hgpioen;
      Uint16 rsrvd2;
	Uint16 hgpiodir;
      Uint16 rsrvd3;
	Uint16 hgpiodat;
      Uint16 rsrvd4[13];
	Uint16 hpic;
      Uint16 rsrvd5;
      Uint16 hpiaw;
      Uint16 rsrvd6;
      Uint16 hpiar;
} HPI_RegObj;

typedef struct {
    Uint16 reserved;
} CSL_HpiDataObj;

#define CSL_HPIDATAINIT  {0x0000u}

extern CSL_HpiDataObj  CSL_HpiData;

#define CSL_HPI_DATA   CSL_HpiData

#endif  /* _HPI_SUPPORT  */

#endif  /* _CSL_HPIDAT_H  */

/******************************************************************************\
*     
*      End of csl_hpidat.h 
*
\******************************************************************************/
