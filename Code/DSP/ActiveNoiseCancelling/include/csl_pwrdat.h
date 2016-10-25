/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... PWR
* FILENAME...... csl_pwrdata.h
* DATE CREATED.. Thu 03/30/2000 
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... CSL service layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:  03/30/2000
*   MODIFIED: 04/16/2001  updated FILENAME and other header comments
*   MODIFIED: 06/28/2001  updated for new CSL initialization model
*   MODIFIED: 10 Apr 2003 added reference for CSL_PwrData for .csldata size fix
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the PWR module)
*       Reserved ROM Area for PWR Data 
*
*
\******************************************************************************/
#ifndef _PWR_DATA_H_
#define _PWR_DATA_H_ 

  #include <csl_std.h>

  #define CSL_PWRDATAINIT\
  { 0x0000u } 

  typedef struct {
    Uint16 PwrReserved;
  } CSL_PwrDataObj;

extern CSL_PwrDataObj CSL_PwrData;

#define CSL_PWR_DATA  CSL_PwrData;

#endif
