/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... ERR
* FILENAME...... csl_errdat.h
* DATE CREATED.. Thu 03/30/2000 
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... CSL service layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:  03/30/2000
*   MODIFIED: 04/16/2001 updated FILENAME and other header comments
*   MODIFIED: 10 April 2003 added reference for CSL_ErrData for .csldata size
*                           fix
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the PWR module)
*       Reserved ROM Area for EBUS Data 
*
*
\******************************************************************************/
#ifndef _ERR_DATA_H_
  #define _ERR_DATA_H_ 

  #include <csl_std.h>

  #define CSL_ERRDATAINIT  { 0x0000u }

  typedef struct {
   Uint16 ErrReserved;
  } CSL_ErrDataObj;

extern CSL_ErrDataObj CSL_ErrData;

#define CSL_ERR_DATA  CSL_ErrData

#endif
 
