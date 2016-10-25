/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... PLL
* FILENAME...... csl_plldata.h
* DATE CREATED.. Thu 03/30/2000 
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... SL - Service Layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:  03/30/2000
*   MODIFIED: 04/16/2001 updated FILENAME and other header comments
*   MODIFIED: 06/28/2001 updated for new CSL initialization model
*   
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the PLL module)
*       Reserved Area for PLL Data 
*
*
\******************************************************************************/
#ifndef _PLL_DATA_H_
#define _PLL_DATA_H_

 #include <csl_std.h>

 #define CSL_PLLDATAINIT\
 { 0x0000u  }

 typedef struct {
   Uint16 PllReserved;
 } CSL_PllDataObj;

extern CSL_PllDataObj CSL_PllData;

#define CSL_PLL_DATA  CSL_Plldata

#endif
