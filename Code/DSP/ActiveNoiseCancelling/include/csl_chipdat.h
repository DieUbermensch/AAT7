/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... CHIP
* FILENAME...... csl_chipdata.h
* CHIP CREATED.. Thu 03/30/2000 
* PROJECT....... Chip Support Library (CSL)
* COMPONENT..... CSL service layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   MODIFIED: 06/19/2000
*   LAST MODIFIED: 05/31/2001 Updated for new initialization model
*------------------------------------------------------------------------------
* DESCRIPTION:  (CHIP Module Initialization Data)
*
*
\******************************************************************************/
#ifndef _CSL_CHIP_DATA_H_
#define _CSL_CHIP_DATA_H_

  #define CSL_CHIPDATAINIT\
  { 0x0000  /* Reserved */\
  }

  typedef struct {
    Uint16 ChipReserved;
  } CSL_ChipDataObj;

#endif
