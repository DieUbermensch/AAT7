/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... DAT
* FILENAME...... csl_datdaa.h
* DATE CREATED.. Thu 03/30/2000 
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... CSL service layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:       03/30/2000
*   MODIFIED:      04/16/2001 modified FILENAME and header comments
*   
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the DAT module)
*       Reserved Area for DAT Data 
*
*
\******************************************************************************/
#ifndef _DAT_DATA_H_
#define _DAT_DATA_H_

#include <csl_std.h>

#define CSL_DATDATAINIT\
{ 0x0000  /* Reserved */ }

typedef struct {
  Uint16 DatReserved;
} CSL_DatDataObj;

#endif
