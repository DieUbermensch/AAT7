/******************************************************************************\ *           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------ 
* MODULE NAME... STDINC - standard include module
* FILENAME...... csl_stdhal.h
* DATE CREATED.. Thu 03/11/1999
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS.. none
*------------------------------------------------------------------------------ 
* HISTORY:
*   CREATED:       03/11/1999 Created
*   MODIFIED:      11/23/1999 Modified for TMS320C54xx
*   LAST MODIFIED: 04/16/2001 updated FILENAME and other header comments
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the STDINC module)
*
*
*
\******************************************************************************/
#ifndef _STDINCHAL_H_
#define _STDINCHAL_H_

/****************************************\
* HSTDINC scope and inline control macros
\****************************************/
#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#define IDECL static inline
#define USEDEFS
#define IDEF  static inline

/****************************************\
* HSTDINC global macro declarations
\****************************************/
#define UNREFERENCED_PARAMETER(P)    ((P)=(P))


/*============================================================================*\
* register referencing macros
\*============================================================================*/


/*------------------------------------------------------------------------*\
 * PREG - peripheral control registers, These are alllocated in I/O space 
\*------------------------------------------------------------------------*/
#define PREG8(addr)  (*(volatile ioport Uint8*)(addr))
#define PREG16(addr) (*(volatile ioport Uint16*)(addr))
#define PREG32(addr) (*(volatile ioport Uint32*)(addr))
#define Preg16Ptr    (volatile ioport Uint16 *)

/*------------------------------------------------------------------------*\
 * Memory-mapped register, located in normal (data/program) space 
\*------------------------------------------------------------------------*/
#define REG8(addr)  (*(volatile Uint8*)(addr))
#define REG16(addr) (*(volatile Uint16*)(addr))
#define REG32(addr) (*(volatile Uint32*)(addr))
#define Reg16Ptr    (volatile Uint16 *)




/****************************************\
* HSTDINC global typedef declarations
\****************************************/

/****************************************\
* HSTDINC global variable declarations
\****************************************/

/****************************************\
* HSTDINC global function declarations
\****************************************/

/****************************************\
* HSTDINC inline function declarations
\****************************************/

/****************************************\
* HSTDINC inline function definitions
\****************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#endif /* USEDEFS */

#endif /* _STDINCHAL_H_ */
/******************************************************************************\
* End of stdinchal.h
\******************************************************************************/

