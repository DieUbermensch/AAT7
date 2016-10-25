/****************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... PLL
* FILENAME...... csl_pllB.h
* DATE CREATED.. Mon Jan 28 14:25:28 2002
* PROJECT....... Chip Support Library
* COMPONENT..... Service Layer
* PREREQUISITS..
*------------------------------------------------------------------------------
*
* HISTORY:
*	 Created:  Mon Jan 28 14:25:28 2002 (Automatic generation)
*	 MODIFIED: 08/04/2003 Added CLKOUTSR register, Renamed CLKMD0 to CLKMD in
*                         Config structure and configArgs arguments list
*			   09/25/2003 Renamed WAKEUP -> WKEN, changed PLLDIV0,1,2,3 default
*						  value
*
*------------------------------------------------------------------------------
* DESCRIPTION: CSL Service Layer interface for the PLLB module
*              Supports PLL for 5502
*
\*************************************************************************/

#ifndef _CSL_PLLB_H_
#define _CSL_PLLB_H_

#include <csl_pllBhal.h>
#include <csl_std.h>
#include <csl.h>
#include <csl_chiphal.h>

#if (_PLLB_SUPPORT)

/*----------------------------------------------------------------*\
*	 PLL scope and inline control macros
\*----------------------------------------------------------------*/

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

/* error codes */
#define PLL_ERR_MAJOR		   (ERR_BASE_PLL)
#define PLL_ERR_ALLOC		   (0x00000000)
#define PLL_ERR_INVALID_HANDLE  (0x00000001)

/* ============================================================== */
 /* Make OSCDIV1 register values based on symbolic constants  */

/*  OSCDIV1 field values  */

	#define PLL_OSCDIV1_OD1EN_DISABLED			(0x0000u)
	#define PLL_OSCDIV1_OD1EN_ENABLED			(0x0001u)
	#define PLL_OSCDIV1_OD1EN_DEFAULT		PLL_OSCDIV1_OD1EN_DISABLED

	#define PLL_OSCDIV1_OSCDIV1_OF(x)               ((Uint16)(x))
	#define PLL_OSCDIV1_OSCDIV1_DEFAULT			(0x0000u)


#define PLL_OSCDIV1_RMK(od1en,oscdiv1)\
 ((Uint16) ( \
  ( PLL_FMK(OSCDIV1,OD1EN,od1en))|\
  ( PLL_FMK(OSCDIV1,OSCDIV1,oscdiv1))\
)\
 )

#define PLL_OSCDIV1_RMKS(od1en_sym,oscdiv1_sym)\
 ((Uint16) ( \
  ( PLL_FMKS(OSCDIV1,OD1EN,od1en_sym))|\
  ( PLL_FMKS(OSCDIV1,OSCDIV1,oscdiv1_sym))\
)\
 )

/*  Default OSCDIV1 register value  */

/* ============================================================== */
 /* Make PLLCSR register values based on symbolic constants  */

/*  PLLCSR field values  */

	#define PLL_PLLCSR_STABLE_UNSTABLE			(000000u)
	#define PLL_PLLCSR_STABLE_STABLE			(0x0001u)
	#define PLL_PLLCSR_STABLE_DEFAULT		PLL_PLLCSR_STABLE_UNSTABLE

	#define PLL_PLLCSR_LOCK_NOTLOCKED			(0x0000u)
	#define PLL_PLLCSR_LOCK_LOCKED			(0x0001u)
	#define PLL_PLLCSR_LOCK_DEFAULT		PLL_PLLCSR_LOCK_NOTLOCKED

	#define PLL_PLLCSR_PLLRST_RESET_RELEASED		(0x0000u)
	#define PLL_PLLCSR_PLLRST_RESET_ASSERTED		(0x0001u)
	#define PLL_PLLCSR_PLLRST_DEFAULT		PLL_PLLCSR_PLLRST_RESET_RELEASED

	#define PLL_PLLCSR_OSCPWRDN_OSC_ON			(0x0000u)
	#define PLL_PLLCSR_OSCPWRDN_OSC_PWRDN		(0x0001u)
	#define PLL_PLLCSR_OSCPWRDN_DEFAULT		PLL_PLLCSR_OSCPWRDN_OSC_ON

	#define PLL_PLLCSR_PLLPWRDN_PLL_ON			(0x0000u)
	#define PLL_PLLCSR_PLLPWRDN_PLL_PWRDN		(0x0001u)
	#define PLL_PLLCSR_PLLPWRDN_DEFAULT		PLL_PLLCSR_PLLPWRDN_PLL_ON

	#define PLL_PLLCSR_PLLEN_BYPASS_MODE		(0x0000u)
	#define PLL_PLLCSR_PLLEN_PLL_MODE			(0x0001u)
	#define PLL_PLLCSR_PLLEN_DEFAULT		PLL_PLLCSR_PLLEN_BYPASS_MODE


#define PLL_PLLCSR_RMK(pllrst,oscpwrdn,pllpwrdn,pllen)\
 ((Uint16) ( \
  ( PLL_FMK(PLLCSR,PLLRST,pllrst))|\
  ( PLL_FMK(PLLCSR,OSCPWRDN,oscpwrdn))|\
  ( PLL_FMK(PLLCSR,PLLPWRDN,pllpwrdn))|\
  ( PLL_FMK(PLLCSR,PLLEN,pllen))\
)\
 )

#define PLL_PLLCSR_RMKS(pllrst_sym,oscpwrdn_sym,pllpwrdn_sym,pllen_sym)\
 ((Uint16) ( \
  ( PLL_FMKS(PLLCSR,PLLRST,pllrst_sym))|\
  ( PLL_FMKS(PLLCSR,OSCPWRDN,oscpwrdn_sym))|\
  ( PLL_FMKS(PLLCSR,PLLPWRDN,pllpwrdn_sym))|\
  ( PLL_FMKS(PLLCSR,PLLEN,pllen_sym))\
)\
 )

/*  Default PLLCSR register value  */

/* ============================================================== */
 /* Make PLLDIV0 register values based on symbolic constants  */

/*  PLLDIV0 field values  */

	#define PLL_PLLDIV0_D0EN_DISABLED			(0x0000u)
	#define PLL_PLLDIV0_D0EN_ENABLED			(0x0001u)
	#define PLL_PLLDIV0_D0EN_DEFAULT		PLL_PLLDIV0_D0EN_ENABLED

	#define PLL_PLLDIV0_PLLDIV0_OF(x)			((Uint16)(x))
	#define PLL_PLLDIV0_PLLDIV0_DEFAULT		      (0x0000u)


#define PLL_PLLDIV0_RMK(d0en,plldiv0)\
 ((Uint16) ( \
  ( PLL_FMK(PLLDIV0,D0EN,d0en))|\
  ( PLL_FMK(PLLDIV0,PLLDIV0,plldiv0))\
)\
 )

#define PLL_PLLDIV0_RMKS(d0en_sym,plldiv0_sym)\
 ((Uint16) ( \
  ( PLL_FMKS(PLLDIV0,D0EN,d0en_sym))|\
  ( PLL_FMKS(PLLDIV0,PLLDIV0,plldiv0_sym))\
)\
 )

/*  Default PLLDIV0 register value  */

/* ============================================================== */
 /* Make PLLDIV1 register values based on symbolic constants  */

/*  PLLDIV1 field values  */

	#define PLL_PLLDIV1_D1EN_DISABLED			(0x0000u)
	#define PLL_PLLDIV1_D1EN_ENABLED			(0x0001u)
	#define PLL_PLLDIV1_D1EN_DEFAULT		PLL_PLLDIV1_D1EN_ENABLED

	#define PLL_PLLDIV1_PLLDIV1_OF(x)		      ((Uint16)(x))
	#define PLL_PLLDIV1_PLLDIV1_DEFAULT		      (0x0003u)


#define PLL_PLLDIV1_RMK(d1en,plldiv1)\
 ((Uint16) ( \
  ( PLL_FMK(PLLDIV1,D1EN,d1en))|\
  ( PLL_FMK(PLLDIV1,PLLDIV1,plldiv1))\
)\
 )

#define PLL_PLLDIV1_RMKS(d1en_sym,plldiv1_sym)\
 ((Uint16) ( \
  ( PLL_FMKS(PLLDIV1,D1EN,d1en_sym))|\
  ( PLL_FMKS(PLLDIV1,PLLDIV1,plldiv1_sym))\
)\
 )

/*  Default PLLDIV1 register value  */

/* ============================================================== */
 /* Make PLLDIV2 register values based on symbolic constants  */

/*  PLLDIV2 field values  */

	#define PLL_PLLDIV2_D2EN_DISABLED			(0x0000u)
	#define PLL_PLLDIV2_D2EN_ENABLED			(0x0001u)
	#define PLL_PLLDIV2_D2EN_DEFAULT		PLL_PLLDIV2_D2EN_ENABLED

	#define PLL_PLLDIV2_PLLDIV2_OF(x)		       ((Uint16)(x))
	#define PLL_PLLDIV2_PLLDIV2_DEFAULT		       (0x0003u)


#define PLL_PLLDIV2_RMK(d2en,plldiv2)\
 ((Uint16) ( \
  ( PLL_FMK(PLLDIV2,D2EN,d2en))|\
  ( PLL_FMK(PLLDIV2,PLLDIV2,plldiv2))\
)\
 )

#define PLL_PLLDIV2_RMKS(d2en_sym,plldiv2_sym)\
 ((Uint16) ( \
  ( PLL_FMKS(PLLDIV2,D2EN,d2en_sym))|\
  ( PLL_FMKS(PLLDIV2,PLLDIV2,plldiv2_sym))\
)\
 )

/*  Default PLLDIV2 register value  */

/* ============================================================== */
 /* Make PLLDIV3 register values based on symbolic constants  */

/*  PLLDIV3 field values  */

	#define PLL_PLLDIV3_D3EN_DISABLED			(0x0000u)
	#define PLL_PLLDIV3_D3EN_ENABLED			(0x0001u)
	#define PLL_PLLDIV3_D3EN_DEFAULT		PLL_PLLDIV3_D3EN_ENABLED

	#define PLL_PLLDIV3_PLLDIV3_OF(x)			((Uint16)(x))
	#define PLL_PLLDIV3_PLLDIV3_DEFAULT		      (0x0003u)


#define PLL_PLLDIV3_RMK(d3en,plldiv3)\
 ((Uint16) ( \
  ( PLL_FMK(PLLDIV3,D3EN,d3en))|\
  ( PLL_FMK(PLLDIV3,PLLDIV3,plldiv3))\
)\
 )

#define PLL_PLLDIV3_RMKS(d3en_sym,plldiv3_sym)\
 ((Uint16) ( \
  ( PLL_FMKS(PLLDIV3,D3EN,d3en_sym))|\
  ( PLL_FMKS(PLLDIV3,PLLDIV3,plldiv3_sym))\
)\
 )

/*  Default PLLDIV3 register value  */

/* ============================================================== */
 /* Make PLLM register values based on symbolic constants  */

/*  PLLM field values  */

	#define PLL_PLLM_PLLM_OF(x)			((Uint16)(x))
	#define PLL_PLLM_PLLM_DEFAULT		      (0x0000u)


#define PLL_PLLM_RMK(pllm)\
 ((Uint16) ( \
  ( PLL_FMK(PLLM,PLLM,pllm))\
)\
 )

#define PLL_PLLM_RMKS(pllm_sym)\
 ((Uint16) ( \
  ( PLL_FMKS(PLLM,PLLM,pllm_sym))\
)\
 )

/*  Default PLLM register value  */

/* ============================================================== */
 /* Make WKEN register values based on symbolic constants  */

/*  WKEN field values  */

	#define PLL_WKEN_WKEN4_DISABLED			(0x0001u)
	#define PLL_WKEN_WKEN4_ENABLED			(0x0000u)
	#define PLL_WKEN_WKEN4_DEFAULT		PLL_WKEN_WKEN4_DISABLED

	#define PLL_WKEN_WKEN3_DISABLED			(0x0001u)
	#define PLL_WKEN_WKEN3_ENABLED			(0x0000u)
	#define PLL_WKEN_WKEN3_DEFAULT		PLL_WKEN_WKEN3_DISABLED

	#define PLL_WKEN_WKEN2_DISABLED			(0x0001u)
	#define PLL_WKEN_WKEN2_ENABLED			(0x0000u)
	#define PLL_WKEN_WKEN2_DEFAULT		PLL_WKEN_WKEN2_DISABLED

	#define PLL_WKEN_WKEN1_DISABLED			(0x0001u)
	#define PLL_WKEN_WKEN1_ENABLED			(0x0000u)
	#define PLL_WKEN_WKEN1_DEFAULT		PLL_WKEN_WKEN1_DISABLED

	#define PLL_WKEN_WKEN0_DISABLED			(0x0001u)
	#define PLL_WKEN_WKEN0_ENABLED			(0x0000u)
	#define PLL_WKEN_WKEN0_DEFAULT		PLL_WKEN_WKEN0_DISABLED


#define PLL_WKEN_RMK(wken4,wken3,wken2,wken1,wken0)\
 ((Uint16) ( \
  ( PLL_FMK(WKEN,WKEN4,wken4))|\
  ( PLL_FMK(WKEN,WKEN3,wken3))|\
  ( PLL_FMK(WKEN,WKEN2,wken2))|\
  ( PLL_FMK(WKEN,WKEN1,wken1))|\
  ( PLL_FMK(WKEN,WKEN0,wken0))\
)\
 )

#define PLL_WKEN_RMKS(wken4_sym,wken3_sym,wken2_sym,wken1_sym,wken0_sym)\
 ((Uint16) ( \
  ( PLL_FMKS(WKEN,WKEN4,wken4_sym))|\
  ( PLL_FMKS(WKEN,WKEN3,wken3_sym))|\
  ( PLL_FMKS(WKEN,WKEN2,wken2_sym))|\
  ( PLL_FMKS(WKEN,WKEN1,wken1_sym))|\
  ( PLL_FMKS(WKEN,WKEN0,wken0_sym))\
)\
 )

/*  Default CLKMD register value  */

/* ============================================================== */
 /* Make CLKMD register values based on symbolic constants  */

/*  CLKMD field values  */

#define PLL_CLKMD_CLKMD0_OSCOUT        (0x0000u)
#define PLL_CLKMD_CLKMD0_CLKIN        (0x0001u)
#define PLL_CLKMD_CLKMD0_DEFAULT      PLL_CLKMD_CLKMD0_OSCOUT

#define PLL_CLKMD_RMK(clkmd0)\
 ((Uint16)PLL_FMK(CLKMD,CLKMD0,clkmd0))

#define PLL_CLKMD_RMKS(clkmd0_sym)\
 ((Uint16)PLL_FMKS(CLKMD,CLKMD0,clkmd0_sym))

/*  Default CLKOUTSR register value  */

/* ============================================================== */
 /* Make CLKOUTSR register values based on symbolic constants  */

/*  CLKOUTSR field values  */

#define PLL_CLKOUTSR_CLKOSEL_SYSCLK1        (0x0001u)
#define PLL_CLKOUTSR_CLKOSEL_SYSCLK2        (0x0002u)
#define PLL_CLKOUTSR_CLKOSEL_SYSCLK3        (0x0003u)
#define PLL_CLKOUTSR_CLKOSEL_DEFAULT      PLL_CLKOUTSR_CLKOSEL_SYSCLK1

#define PLL_CLKOUTSR_CLKOUTDIS_ENABLED      (0x0000u)
#define PLL_CLKOUTSR_CLKOUTDIS_DISABLED     (0x0001u)
#define PLL_CLKOUTSR_CLKOUTDIS_DEFAULT     PLL_CLKOUTSR_CLKOUTDIS_ENABLED

#define PLL_CLKOUTSR_RMK(clkosel,clkoutdis)\
 ((Uint16)((PLL_FMK(CLKOUTSR,CLKOSEL,clkosel)) |\
           (PLL_FMK(CLKOUTSR,CLKOUTDIS,clkoutdis)))\
 )

#define PLL_CLKOUTSR_RMKS(clkosel_sym,clkoutdis_sym)\
 ((Uint16)((PLL_FMKS(CLKOUTSR,CLKOSEL,clkosel_sym)) |\
           (PLL_FMKS(CLKOUTSR,CLKOUTDIS,clkoutdis_sym)))\
 )

/*  Default CK3SEL register value  */

/* ============================================================== */
 /* Make CK3SEL register values based on symbolic constants  */

/*  CK3SEL field values  */

#define PLL_CK3SEL_CK3SEL_PLL        (0x000Bu)
#define PLL_CK3SEL_CK3SEL_DIV0		 (0x000Au)
#define PLL_CK3SEL_CK3SEL_NOCHANGE	 (0x0009u)
#define PLL_CK3SEL_CK3SEL_DEFAULT    PLL_CK3SEL_CK3SEL_PLL

#define PLL_CK3SEL_RMK(ck3sel)\
 ((Uint16)PLL_FMK(CK3SEL,CK3SEL,(ck3sel & PLL_CK3SEL_CK3SEL_PLL)))

#define PLL_CK3SEL_RMKS(ck3sel_sym)\
 ((Uint16)((PLL_FMKS(CK3SEL,CK3SEL,PLL)) & \
           (PLL_FMKS(CK3SEL,CK3SEL,ck3sel_sym))) \
 )

/*************************************************\
 PLL global typedef declarations
\*************************************************/

typedef struct {
	Uint16 pllcsr;
	Uint16 pllm;
	Uint16 plldiv0;
	Uint16 plldiv1;
	Uint16 plldiv2;
	Uint16 plldiv3;
	Uint16 oscdiv1;
	Uint16 wken;
	Uint16 clkmd;
	Uint16 clkoutsr;
} PLL_Config;

/*************************************************\
* PLL global variable declarations
\*************************************************/


/*************************************************\
* PLL global function declarations
\*************************************************/

CSLAPI void PLL_config(PLL_Config *myConfig);
CSLAPI void PLL_configArgs(Uint16 pllcsr,Uint16 pllm,Uint16 plldiv0,Uint16 plldiv1,Uint16 plldiv2,Uint16 plldiv3,
                           Uint16 oscdiv1,Uint16 wken,Uint16 clkmd, Uint16 clkoutsr);

CSLAPI void PLL_setFreq (Uint16 mode, Uint16 mul, Uint16 div0, Uint16 div1, Uint16 div2,
                  Uint16 div3, Uint16 oscdiv);

/*************************************************\
* PLL inline function declarations
\*************************************************/


#ifdef USEDEFS


/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/

#endif /*USEDEFS */

#elif (!(_PLL_MOD))
	#error PLL Hal Module Not Supported on Specified Target
#endif  /* _PLLB_SUPPORT  */

#endif  /* _CSL_PLLBHAL_H  */

/******************************************************************************\
*
*      End of csl_pllB.h
*
\******************************************************************************/
