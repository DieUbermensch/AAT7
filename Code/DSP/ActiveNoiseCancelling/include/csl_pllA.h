 /******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... PLL
* FILENAME...... pll.h
* DATE CREATED.. Mon 06/05/2000 
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... service layer
* PREREQUISITS.. cslhal.h
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:  06/05/2000 Created.  
*   MODIFIED: 07/05/2001 Modified to include support for both DPLL and APLL
*   MODIFIED: 01/24/2002 fixed problem with CLKDIV support for 5510PG2
*------------------------------------------------------------------------------
* DESCRIPTION:  (interface file for the PLL module)
\******************************************************************************/
#ifndef _PLLA_H_
#define _PLLA_H_

#include <_csl.h>
#include <csl_pllAhal.h>

#if (_PLLA_SUPPORT)
/****************************************\
* PLL scope and inline control macros
\****************************************/
#ifdef __cplusplus
#define CSLAPI extern "C"  
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _PLL_MOD_
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
* PLL global macro declarations
\****************************************/ 
#define PLL_DEVICE_CNT           HPLL_DEVICE_CNT

/* PLL_Open() flags */
#define PLL_OPEN_RESET           (0x0001)

/* error codes */
#define PLL_ERR_MAJOR            (ERR_BASE_PLL) 
#define PLL_ERR_ALLOC            (0x00000000)
#define PLL_ERR_INVALID_HANDLE   (0x00000001)


/*----------------------------------------------------------------------------*/
#define PLL_RESET(hPll)   CLKMD = hPll->reset


/*******************************************\
* PLL global macro definition : ROMABILITY
\*******************************************/ 
/* Reserved ROM Area for pllData.h */
/* Data definition */   

/* Predefined Device Handlers */
/* #define PLL_defaultHandle          PLL_SYM(2) */

/*******************************************/
/* Define a debuging assertion macro 	 */ 
/* for validating device handles 		 */


/*-----------------------------------------------------------------------*/
/* The following macros are used to construct peripheral register        */
/* values based on symbolic constants. They will be useful to initialize */
/* the TIMER_Config structure in a readable way.                         */
/*-----------------------------------------------------------------------*/

#if (!(_PLL_ANALOG_SUPPORT))	//Digital PLL (only one that works in 55xx)

/*===========================================================================*\
* PLL CLKMD Clock Mode Register Macros
*
* Fields:
*  (RW) IAI
*  (RW) IOB
*  (RW) TEST
*  (RW) PLLMULT
*  (RW) PLLDIV
*  (RW) PLLENABLE
*  (RW) BYPASSDIV
*  (R)  BREAKLN
*  (RW) LOCK
\*==========================================================================*/

/*---------------------------------------*\
* PLL_CLKMD_MK Macro
\*---------------------------------------*/

#define PLL_CLKMD_RMK(iai,iob,test,pllmult,plldiv,pllenable,bypassdiv)\
  ((Uint16) (PLL_FMK(CLKMD,IAI,iai) 				|	\
			PLL_FMK(CLKMD,IOB,iob) 				|	\
			PLL_FMK(CLKMD,TEST,test) 			|	\
			PLL_FMK(CLKMD,PLLMULT,pllmult) 		|	\
			PLL_FMK(CLKMD,PLLDIV,plldiv) 			|	\
			PLL_FMK(CLKMD,PLLENABLE,pllenable) 		|	\
			PLL_FMK(CLKMD,BYPASSDIV,bypassdiv) 			\
	   	))

#define PLL_CLKMD_RMKS(iai_s,iob_s,test_s,pllmult_s,plldiv_s,\
           pllenable_s,bypassdiv_s)\
  ((Uint16) (PLL_FMKS(CLKMD,IAI,iai_s) 			|\
		 PLL_FMKS(CLKMD,IOB,iob_s) 			|\
		 PLL_FMKS(CLKMD,TEST,test_s) 			|\
		 PLL_FMKS(CLKMD,PLLMULT,pllmult_s) 		|\
		 PLL_FMKS(CLKMD,PLLDIV,plldiv_s) 		|\
		 PLL_FMKS(CLKMD,PLLENABLE,pllenable_s) 	|\
		 PLL_FMKS(CLKMD,BYPASSDIV,bypassdiv_s) 	\
	   	))
	   	
#else	   			//Analog PLL

/*===========================================================================*\
* PLL CLKMD Clock Mode Register Macros
*
* Fields:
*  (RW) VCOONOFF
*  (RW) PLLMULT
*  (RW) PLLDIV
*  (RW) PLLENABLE
\*==========================================================================*/

#define PLL_CLKMD_RMK(vcoonoff,pllmult,plldiv,pllenable)\
  ((Uint16) (   	PLL_FMK(CLKMD,VCOONOFF,vcoonoff) 				|	\
			PLL_FMK(CLKMD,PLLMULT,pllmult) 		|	\
			PLL_FMK(CLKMD,PLLDIV,plldiv) 			|	\
			PLL_FMK(CLKMD,PLLENABLE,pllenable) 			\
	   	))

#define PLL_CLKMD_RMKS(vcoonoff_s,pllmult_s,plldiv_s,\
           pllenable_s)\
  ((Uint16) (PLL_FMKS(CLKMD,VCOONOFF,vcoonoff_s) 	|\
		 PLL_FMKS(CLKMD,PLLMULT,pllmult_s) 		|\
		 PLL_FMKS(CLKMD,PLLDIV,plldiv_s) 		|\
		 PLL_FMKS(CLKMD,PLLENABLE,pllenable_s) 	 \
	   	))
#endif

#define PLL_CLKMD_DEFAULT               	(0x0000u)

#define PLL_CLKMD_VCOONOFF_OFF           	(0x0000u)
#define PLL_CLKMD_VCOONOFF_ON            	(0x0001u)

#define PLL_CLKMD_IAI_OFF           	(0x0000u)
#define PLL_CLKMD_IAI_ON            	(0x0001u)

#define PLL_CLKMD_IOB_OFF           	(0x0000u)
#define PLL_CLKMD_IOB_ON            	(0x0001u)

#define PLL_CLKMD_TEST_OFF           	(0x0000u)
#define PLL_CLKMD_TEST_ON            	(0x0001u)

#define PLL_CLKMD_PLLMULT_OF(x)          	((Uint16)x)

#define PLL_CLKMD_PLLDIV_OF(x)           	((Uint16)x)

#define PLL_CLKMD_PLLENABLE_OFF           (0x0000u)
#define PLL_CLKMD_PLLENABLE_ON            (0x0001u)

#define PLL_CLKMD_BYPASSDIV_OF(x)         ((Uint16)x)

#define PLL_CLKMD_LOCK_OFF           	(0x0000u)
#define PLL_CLKMD_LOCK_ON            	(0x0001u)

/****************************************\
* PLL global typedef declarations
\****************************************/
/* device handle type */

#if (!(_PLL_ANALOG_SUPPORT))	//Digital PLL

/* device configuration structure */
typedef struct {
  Uint16 iai;
  Uint16 iob;
  Uint16 pllmult;
  Uint16 div;
} PLL_Config;

#else			//Analog PLL

typedef struct {
  Uint16 vcoonoff;
  Uint16 pllmult;
  Uint16 plldiv;
} PLL_Config;

#endif
/****************************************\
* PLL global function declarations
\****************************************/
CSLAPI void PLL_config(PLL_Config *Config);

#if (!(_PLL_ANALOG_SUPPORT))				//Digital PLL
	CSLAPI void PLL_configArgs(Uint16 iai, Uint16 iob, Uint16 pllmult, Uint16 div);
#else
	CSLAPI void PLL_configArgs(Uint16 vcoonoff, Uint16 pllmult,Uint16 plldiv);
#endif


CSLAPI void PLL_setFreq (Uint16 mul, Uint16 div);

#else
  #ifndef _PLL_MOD_ 						/*PLL_SUPPORT */
    #error PLL Module Not Supported on Specified Target
  #endif
#endif 								/*PLLA_SUPPORT */

#endif 								/* _PLLA_H_ */

/******************************************************************************\
* End of PLL.h
\******************************************************************************/
