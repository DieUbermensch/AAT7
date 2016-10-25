/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... DAT
* FILENAME...... csl_dat.h
* DATE CREATED.. Thu 11/11/1999 
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... CSL service layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:        11/11/1999 Created
*   MODIFIED:       07/10/2000 modified for C55xx
*   LAST MODIFIED:  04/16/2001 modified header comments
*   LAST MODIFIED:  06/09/2004 Fixed C++ compiler errors 
*
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the DAT module)
*
*
*
\******************************************************************************/
#ifndef _DAT_H_
#define _DAT_H_

#include <_csl.h>
#include <csl_dma.h>

#if (_DAT_SUPPORT)    

/****************************************\
* DAT scope and inline control macros
\****************************************/

#ifdef __cplusplus
#define CSLAPI extern "C"  
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _DAT_MOD_
  #define IDECL CSLAPI
  #define IDEF
#else
  #ifdef  _INLINE
    #define IDECL static inline
    #define USEDEFS
    #define IDEF  static inline
  #else
    #define IDECL CSLAPI
  #endif
#endif


/****************************************\
* DAT global macro declarations
\****************************************/
#if (_DMA_SUPPORT)
  #define DAT_CHA_ANY   DMA_CHA_ANY
  #define DAT_CHA0      DMA_CHA0
  #define DAT_CHA1      DMA_CHA1
  #define DAT_CHA2      DMA_CHA2
  #define DAT_CHA3      DMA_CHA3
  #define DAT_CHA4      DMA_CHA4
  #define DAT_CHA5      DMA_CHA5
  #define DAT_PRI_LOW   0
  #define DAT_PRI_HIGH  1

  #define DAT_1D2D      0x00000013
  #define DAT_2D1D      0x00000031
  #define DAT_2D2D      0x00000033

#endif

/* error codes */
#define DAT_ERR_MAJOR            (ERR_BASE_DAT)
#define DAT_ERR_ALLOC            (0x00000000)
#define DAT_ERR_INVALID_HANDLE   (0x00000001)
#define DAT_ERR_NOT_OPEN         (0x00000002)
/* open flags */
#define DAT_OPEN_2D    1

/****************************************\
* DAT global typedef declarations
\****************************************/

/*******************************************\
* DMA global macro definition : ROMABILITY
\*******************************************/  
/* Reserved ROM Area by datdata.h */
 
/* Data definition */
typedef struct {
 Uint16 Private;
} *DAT_Handle;


/****************************************\
* DAT global function declarations
\****************************************/
CSLAPI DAT_Handle DAT_open(int ChaNum, int Priority, Uint32 Flags);
CSLAPI void DAT_close(DAT_Handle hDat);
CSLAPI Uint16 DAT_copy(DAT_Handle hDat, DMA_AdrPtr Src , DMA_AdrPtr Dst , Uint16 ElemCnt);
CSLAPI Uint16 DAT_copy2D(DAT_Handle hDat, Uint16 Type, DMA_AdrPtr Src, DMA_AdrPtr Dst, Uint16 LineLen, Uint16 LineCnt, Uint16 LinePitch);
CSLAPI Uint16 DAT_fill(DAT_Handle hDat, DMA_AdrPtr Dst , Uint16 ElemCnt, Uint16 *Value);
CSLAPI void DAT_wait(DAT_Handle hDat);
/****************************************\
* DAT inline function declarations
\****************************************/

/****************************************\
* DAT inline function definitions
\****************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */

#endif /* _DAT_SUPPORT */
#endif /* _DAT_H_ */
/******************************************************************************\
* End of csl_dat.h
\******************************************************************************/
