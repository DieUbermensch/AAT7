/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... RTC
* FILENAME...... csl_i2cdat.h
* DATE CREATED.. Thu 02/20/2001
* PROJECT....... Chip Support Library
* COMPONENT..... CSL service layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   MODIFIED: 
*   LAST MODIFIED: 10 April 2003 added reference to CSL_I2cData for .csldata
*                                size fix
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the RTC module)
*       Reserved ROM Area for RTC Data 
*
*
\******************************************************************************/
#ifndef _CSL_I2C_DATA_H_
#define _CSL_I2C_DATA_H_

  #include <csl_std.h>

  #define CSL_I2CDATAINIT\
  { 0x00000000u,\
    0x00000000u,\
    0x00000000u,\
    0x00000000u,\
    0x00000000u,\
    0x00000000u\
  }

  

  typedef struct {
    Uint32 I2C_isrDispatchTable[6];
  } CSL_I2cDataObj;

extern CSL_I2cDataObj CSL_I2cData;

#define CSL_I2C_DATA  CSL_I2cData

#endif
