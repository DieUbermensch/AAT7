/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... ERR
* FILENAME...... csl_err.h
* DATE CREATED.. Tue 06/22/1999 
* PROJECT....... CSL - CHip Support Library
* COMPONENT..... SL - Service Layer
* PREREQUISITS.. 
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:        06/22/1999 Created
*   MODIFIED:       02/22/2000 C54x Romability .
*   MODIFIED:       07/13/2000 modified for C55x
*   LAST MODIFIED:  04/16/2001 modified FILENAME and header comments
*   MODIFIED: 10 April 2003 added #include for csl_errdat.h
*------------------------------------------------------------------------------
* DESCRIPTION:  (interface file for the ERR module)
*
*
*
\******************************************************************************/
#ifndef _ERR_H_
#define _ERR_H_

#include <_csl.h>

#include <csl_errdat.h>

#if (_ERR_SUPPORT)
/****************************************\
* ERR scope and inline control macros
\****************************************/
#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _INLINE
  #define IDECL static inline
  #define USEDEFS
  #define IDEF  static inline
#else
  #define IDECL extern
#endif

/****************************************\
* ERR global macro declarations
\****************************************/   

#define ERR_BASE_DAT     0x00000001
#define ERR_BASE_DMA     0x00000002
#define ERR_BASE_EDMA    0x00000003
#define ERR_BASE_MCBSP   0x00000004
#define ERR_BASE_TIMER   0x00000005 
#define ERR_BASE_PWR     0x00000006
#define ERR_BASE_GPIO    0x00000007
#define ERR_BASE_PLL     0x00000008
#define ERR_BASE_CACHE   0x00000009

#define ERR_BASE_USER  0x80000000

/****************************************\
* ERR global typedef declarations
\****************************************/
typedef void(*ERR_Handler)(Uint32 Major, Uint32 Minor);

/*******************************************\
* ERR global macro definition : ROMABILITY
\*******************************************/ 
/* Reserved ROM Area for Err Data */

/* ErrFunc is "far type" : 32bit Address */

/****************************************\
* ERR global variable declarations
\****************************************/

/****************************************\
* ERR global function declarations
\****************************************/
extern void   ERR_defaultHandler(Uint32 Major, Uint32 Minor);
extern void   ERR_installHandler(ERR_Handler Handler);
extern void   ERR_submit(Uint32 Major, Uint32 Minor);
extern Uint16 ERR_getCount();

/****************************************\
* ERR inline function declarations
\****************************************/


/****************************************\
* ERR inline function definitions
\****************************************/

#endif /* ERR_SUPPORT */
#endif /* _ERR_H_ */
/******************************************************************************\
* End of err.h
\******************************************************************************/

