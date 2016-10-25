/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... DMA
* FILENAME...... csl_dmadat.h
* DATE CREATED.. Thu 03/30/2000 
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... CSL service layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   MODIFIED:  03/27/2001 Modified to support 5510 PG2.0
*   MODIFIED:  04/16/2001 modified header comments
*   MODIFIED:  01/22/2002 modified for 5510 PG2.0 support and fix
*                         for 5509 support
*   MODIFIED:  06/19/2003 added GTCR
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the DMA module)
*       Reserved Area for DMA Data 
*
*
\******************************************************************************/
#ifndef _DMA_DAT_H_
#define _DMA_DAT_H_

#if (_DMA_DST_AND_SRC_INDEX_SUPPORT)
   #include <csl_dmadatB.h>
#else
   #include <csl_dmadatA.h>
#endif

/* private object, not to be used by application code */
typedef struct {
  Uint16 EventId;
  Uint16 DmaChaNum;
  Uint16 DmaGcrAddr;
#if (_DMA_DST_AND_SRC_INDEX_SUPPORT)
  Uint16 DmaGtcrAddr;
  Uint16 DmaGscrAddr;
#endif
  Uint16 DmaCsdpAddr;
  Uint16 DmaCcrAddr;
  Uint16 DmaCicrAddr;
  Uint16 DmaCsrAddr;
  Uint16 DmaCssalAddr;
  Uint16 DmaCssauAddr;
  Uint16 DmaCdsalAddr;
  Uint16 DmaCdsauAddr;
  Uint16 DmaCenAddr;
  Uint16 DmaCfnAddr;
#if (_DMA_DST_AND_SRC_INDEX_SUPPORT)
  Uint16 DmaCsfiAddr;
  Uint16 DmaCseiAddr;
  Uint16 DmaCdfiAddr;
  Uint16 DmaCdeiAddr;
  Uint16 DmaCsacAddr;
  Uint16 DmaCdacAddr;
#else
  Uint16 DmaCfiAddr;
  Uint16 DmaCeiAddr;
#endif
} DMA_PrivateObj;

typedef struct {
  DMA_PrivateObj DmaChan[6];
} CSL_DmaDataObj;

extern CSL_DmaDataObj CSL_DmaData;

#define CSL_DMA_DATA  CSL_DmaData

#endif
