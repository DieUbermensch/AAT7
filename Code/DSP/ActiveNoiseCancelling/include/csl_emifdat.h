/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... EMIF
* FILENAME...... csl_emifdat.h
* DATE CREATED.. Thu 03/30/2000 
* PROJECT....... CSL  - Chip Support Library
* COMPONENT..... CSL service layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:       03/30/2000
*   MODIFIED: 04/16/2001 modified header comments
*   MODIFIED: 03/27/2003 Updated register names as per SPRU621A
*   MODIFIED: 10 April 2003 added reference for CLS_EmifData for .csldata
*                           size fix
*   
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the EMIF module)
*       Reserved Area for EMIF Data 
*
*
\******************************************************************************/
#ifndef _EMIF_DATA_H_
#define _EMIF_DATA_H_

  #include <csl_std.h>

  #if (_EMIFB_SUPPORT)
     typedef struct {
	Uint16 gblctl1;
	Uint16 gblctl2;
	Uint16 ce1ctl1;
	Uint16 ce1ctl2;
	Uint16 ce0ctl1;
	Uint16 ce0ctl2;
      Uint16 reserved0;
      Uint16 reserved1;
	Uint16 ce2ctl1;
	Uint16 ce2ctl2;
	Uint16 ce3ctl1;
	Uint16 ce3ctl2;
	Uint16 sdctl1;
	Uint16 sdctl2;
	Uint16 sdrfr1;
	Uint16 sdrfr2;
	Uint16 sdext1;
	Uint16 sdext2;
      Uint16 reserved3[16];
	Uint16 ce1sec1;
      Uint16 reserved4;
	Uint16 ce0sec1;
      Uint16 reserved6[3];
	Uint16 ce2sec1;
      Uint16 reserved5;
	Uint16 ce3sec1;
      Uint16 reserved7[21];
      Uint16 cescr;
      } EMIF_RegObj, *EMIF_RegPtr;
    
      typedef struct {
        EMIF_RegPtr regs;
      } CSL_EmifDataObj;     


     #define CSL_EMIFDATAINIT\
     { (EMIF_RegPtr)0x0800u }

  #else

     typedef struct {
       Uint16 EmifReserved;
     } CSL_EmifDataObj;

     #define CSL_EMIFDATAINIT\
     { 0x0000u }

  #endif

extern CSL_EmifDataObj CSL_EmifData;

#define CSL_EMIF_DATA CSL_EmifData

#endif
