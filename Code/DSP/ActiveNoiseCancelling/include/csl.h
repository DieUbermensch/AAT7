/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... CSL - chip support library service layer interface
* FILENAME...... csl.h
* DATE CREATED.. Fri 06/11/1999 
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS.. 
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:         06/11/1999  Created
*   MODIFIED:        11/13/1999  Modified for TMS320C54xx
*   MODIFIED:        04/12/2001  Changed CSL_version
*   MODIFIED:        04/16/2001  updated CSL_init
*   MODIFIED:        07/29/2002  removed static declaration of _CSL_init()
*   MODIFIED:        07/28/2004  Added 5501 support 
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the CSL library)
*
*
*
\******************************************************************************/
#ifndef _CSL_H_
#define _CSL_H_   

#include <_csl.h>

/****************************************\
* CSL scope and inline control macros
\****************************************/
#ifdef __cplusplus
#define CSLAPI extern "C" 
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _CSL_MOD_
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
* CSL global macro declarations
\****************************************/

/****************************************\
* CSL global typedef declarations
\****************************************/
   
/****************************************\
* CSL global variable declarations
\****************************************/

/****************************************\
* CSL global function declarations
\****************************************/

CSLAPI void CSL5510_LIB_();
CSLAPI void CSL5510_PG1_0_LIB_();
CSLAPI void CSL5510_PG1_2_LIB_();
CSLAPI void CSL5510_PG2_0_LIB_();
CSLAPI void CSL5510_PG2_1_LIB_();
CSLAPI void CSL5510_PG2_2_LIB_();

CSLAPI void CSL5509_LIB_();
CSLAPI void CSL5509A_LIB_();
CSLAPI void CSL5502_LIB_();
CSLAPI void CSL5501_LIB_();

CSLAPI void _CSL_init(Uint16 osPresent);


#ifndef _CSL_MOD_
/****************************************\
* CSL inline function declarations
\****************************************/
static inline void CSL_init(void);

/*******************************************************************************\
* Setup (non Rom model) or retrieve (ROM model) address of global data
\*******************************************************************************/
/* ROM Area */

/*******************************************************************************\
* Chip Support Library Global Initialization Function
\*******************************************************************************/
static inline void CSL_init(void) {

  #if (CHIP_5510)
    CSL5510_LIB_();
  #elif (CHIP_5510PG1_0)
    CSL5510_PG1_LIB_();
  #elif (CHIP_5510PG1_2)
    CSL5510_PG1_2_LIB_();

  #elif (CHIP_5510PG2_0)
    CSL5510_PG2_0_LIB_();
  #elif (CHIP_5510PG2_1)
    CSL5510_PG2_1_LIB_();
  #elif (CHIP_5510PG2_2)
    CSL5510_PG2_2_LIB_();

  #elif (CHIP_5509)
    CSL5509_LIB_();
  #elif (CHIP_5509A)
    CSL5509A_LIB_();
  #elif (CHIP_5502)
    CSL5502_LIB_();
  #elif (CHIP_5501)
    CSL5501_LIB_();
  #endif


   _CSL_init(0);     // Call _CSL_init with 0 for operating system
                     // flag


  }  
#else
  CSLAPI void CSL_init(void);
#endif

#endif /* _CSL_H_ */
/******************************************************************************\
* End of csl.h
\******************************************************************************/

