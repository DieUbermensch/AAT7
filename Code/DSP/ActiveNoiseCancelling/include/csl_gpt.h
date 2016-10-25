/****************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated. 
*                           All Rights Reserved  
*------------------------------------------------------------------------------ 
* MODULE NAME... GPT 
* FILENAME...... csl_gpt.h 
* DATE CREATED.. Sat Feb  9 16:13:17 2002 
* PROJECT....... Chip Support Library 
* COMPONENT..... Service Layer 
* PREREQUISITS..  
*------------------------------------------------------------------------------ 
* 
* HISTORY: 
*	 Created:	Sat Feb  9 16:13:17 2002 (Automatic generation) 
*	 Modified:	10/30/2003 Fixed few typos in macros, added TDDR34 
*                          in GPTGCTL1_RMK, added IDEF and IDECL for _stop12()
*                          and _stop34() API and fixed bug in _stop()
*               03/12/2003 Modified register names and fields as per SPRU618A.   
* 
*------------------------------------------------------------------------------ 
* DESCRIPTION: CSL Service Layer interface for the GPT module  
* 
\*************************************************************************/ 
 
#ifndef _CSL_GPT_H_ 
#define _CSL_GPT_H_ 
 
#include <csl_gpthal.h> 
#include <csl_std.h> 
#include <_csl.h> 
#include <csl_chiphal.h> 
 
#if (_GPT_SUPPORT)  
 
/*----------------------------------------------------------------*\
*	 GPT scope and inline control macros 			 
\*----------------------------------------------------------------*/ 
 
#ifdef __cplusplus 
#define CSLAPI extern "C" 
#else 
#define CSLAPI extern  
#endif 
 
#undef  USEDEFS 
#undef  IDECL 
#undef  IDEF 
 
#ifdef  _GPT_MOD_ 
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
* GPT global macro declarations 
\****************************************/ 
 
/* error codes */ 
#define GPT_ERR_MAJOR		   (ERR_BASE_GPT)  
#define GPT_ERR_ALLOC		   (0x00000000)  
#define GPT_ERR_INVALID_HANDLE  (0x00000001)  
 
#define GPT_DEVICE_CNT		2 
 
/* GPT_Open() flags */ 
#define GPT_OPEN_RESET	  (0x0001) 
 
/* device identifiers for GPT_Open() */ 
#define GPT_DEVANY  (-1) 
#define GPT_DEV0    (0) 
#define GPT_DEV1    (1) 
 
/* define a debuging assertion macro for validating device handles */ 
#ifdef _MCRTE_DEBUG 
  #define GPT_ASSERT_HANDLE(hGPT,RetExp) \
    if (hGPT == INV) { \
       ERR_submit(GPT_ERR_MAJOR, GPT_ERR_INVALID_HANDLE); \
       RetExp; \
    }  
#else 
  #define GPT_ASSERT_HANDLE(hGPT,RetExp)  
#endif 
 
/*******************************************\
* GPT global macro definition : ROMABILITY  
\*******************************************/  
/* Reserved ROM Area for GPTData.h */ 
/* Data definition */   
#define GPT_Initialized            GPT_SYM(0) 
#define GPT_DeviceTable            GPT_SYM(1) 
 
/* Predefined Device Handlers */ 
 
#define GPT_hDev0 ((GPT_Handle)&(CSL_GPT_DATA.Gpt[0])) 
 
#define GPT_hDev1 ((GPT_Handle)&(CSL_GPT_DATA.Gpt[1])) 
 
#define GPT_hDev(dev) ((GPT_Handle)&(CSL_GPT_DATA.Gpt[dev])) 
 
/* ============================================================== */ 
/*  Generic Access Macros                                         */ 
/* ============================================================== */ 
 
#define GPT_getEventId(hGpt)   (((GPT_PrivateObj *)hGpt)->EventId) 
 
/* ============================================================== */ 
 /* Make GPTCLK register values based on symbolic constants  */ 
 
/*  GPTCLK field values  */ 
 	
	#define GPT_GPTCLK_CLKDIV_DIV0	       (0x0000u) 
	#define GPT_GPTCLK_CLKDIV_DIV1	       (0x0001u) 
	#define GPT_GPTCLK_CLKDIV_DIV2	       (0x0002u) 
	#define GPT_GPTCLK_CLKDIV_DIV4	       (0x0004u) 
	#define GPT_GPTCLK_CLKDIV_DIV8	       (0x0008u)
	#define GPT_GPTCLK_CLKDIV_DEFAULT      GPT_GPTCLK_CLKDIV_DIV0
	
	#define GPT_GPTCLK0_CLKDIV_DIV0	       (0x0000u) 
	#define GPT_GPTCLK0_CLKDIV_DIV1	       (0x0001u) 
	#define GPT_GPTCLK0_CLKDIV_DIV2	       (0x0002u) 
	#define GPT_GPTCLK0_CLKDIV_DIV4	       (0x0004u) 
	#define GPT_GPTCLK0_CLKDIV_DIV8	       (0x0008u) 
	#define GPT_GPTCLK0_CLKDIV_DEFAULT     GPT_GPTCLK0_CLKDIV_DIV0
 
        #define GPT_GPTCLK1_CLKDIV_DIV0	       (0x0000u) 
	#define GPT_GPTCLK1_CLKDIV_DIV1	       (0x0001u) 
	#define GPT_GPTCLK1_CLKDIV_DIV2	       (0x0002u) 
	#define GPT_GPTCLK1_CLKDIV_DIV4	       (0x0004u) 
	#define GPT_GPTCLK1_CLKDIV_DIV8	       (0x0008u) 
	#define GPT_GPTCLK1_CLKDIV_DEFAULT     GPT_GPTCLK1_CLKDIV_DIV0

 
 
/*  Default GPTCLK register value  */ 
 
/* ============================================================== */ 
 /* Make GPTCNT1 register values based on symbolic constants  */ 
 
/*  GPTCNT1 field values  */ 
 
	#define GPT_GPTCNT1_CNT1_OF(x)		((Uint16)(x)) 
      #define GPT_GPTCNT1_CNT1_DEFAULT     	GPT_GPTCNT1_CNT1_OF(0) 
 
	#define GPT_GPTCNT10_CNT1_OF(x)		((Uint16)(x)) 
      #define GPT_GPTCNT10_CNT1_DEFAULT     	GPT_GPTCNT1_CNT1_OF(0) 
 
	#define GPT_GPTCNT11_CNT1_OF(x)		((Uint16)(x)) 
      #define GPT_GPTCNT11_CNT1_DEFAULT     	GPT_GPTCNT1_CNT1_OF(0) 
 
 /*
#define GPT_GPTCNT1_RMK(cnt1) \
 ((Uint16) ( \
  ( GPT_FMK(GPTCNT1,CNT1,##cnt1##)) \
) \
 ) 
 */

#define GPT_GPTCNT1_RMK(cnt1) \
 ((Uint16) ( \
  ( GPT_FMK(GPTCNT1,CNT1,##cnt1##)) \
) \
 )
  
#define GPT_GPTCNT1_RMKS(cnt1_sym) \
 ((Uint16) ( \
  ( GPT_FMKS(GPTCNT1,CNT1,cnt1_sym)) \
) \
 ) 
 
/*  Default GPTCNT1 register value  */ 
 
/* ============================================================== */ 
 /* Make GPTCNT2 register values based on symbolic constants  */ 
 
/*  GPTCNT2 field values  */ 
 
	#define GPT_GPTCNT2_CNT2_OF(x)		((Uint16)(x)) 
	#define GPT_GPTCNT2_CNT2_DEFAULT		GPT_GPTCNT2_CNT2_OF(0) 
 
	#define GPT_GPTCNT20_CNT2_OF(x)		((Uint16)(x)) 
	#define GPT_GPTCNT20_CNT2_DEFAULT		GPT_GPTCNT2_CNT2_OF(0) 
 
	#define GPT_GPTCNT21_CNT2_OF(x)		((Uint16)(x)) 
	#define GPT_GPTCNT21_CNT2_DEFAULT		GPT_GPTCNT2_CNT2_OF(0) 
 
 
#define GPT_GPTCNT2_RMK(cnt2)\
 ((Uint16) ( \
  ( GPT_FMK(GPTCNT2,CNT2,cnt2))\
)\
 ) 
 
#define GPT_GPTCNT2_RMKS(cnt2_sym)\
 ((Uint16) ( \
  ( GPT_FMKS(GPTCNT2,CNT2,cnt2_sym))\
)\
 ) 
 
/*  Default GPTCNT2 register value  */ 
 
/* ============================================================== */ 
 /* Make GPTCNT3 register values based on symbolic constants  */ 
 
/*  GPTCNT3 field values  */ 
 
	#define GPT_GPTCNT3_CNT3_OF(x)		((Uint16)(x)) 
	#define GPT_GPTCNT3_CNT3_DEFAULT		GPT_GPTCNT3_CNT3_OF(0) 
 
	#define GPT_GPTCNT30_CNT3_OF(x)		((Uint16)(x)) 
	#define GPT_GPTCNT30_CNT3_DEFAULT		GPT_GPTCNT3_CNT3_OF(0) 
 
	#define GPT_GPTCNT31_CNT3_OF(x)		((Uint16)(x)) 
	#define GPT_GPTCNT31_CNT3_DEFAULT		GPT_GPTCNT3_CNT3_OF(0) 
 
 
#define GPT_GPTCNT3_RMK(cnt3)\
 ((Uint16) ( \
  ( GPT_FMK(GPTCNT3,CNT3,cnt3))\
)\
 ) 
 
#define GPT_GPTCNT3_RMKS(cnt3_sym)\
 ((Uint16) ( \
  ( GPT_FMKS(GPTCNT3,CNT3,cnt3_sym))\
)\
 ) 
 
/*  Default GPTCNT3 register value  */ 
 
/* ============================================================== */ 
 /* Make GPTCNT4 register values based on symbolic constants  */ 
 
/*  GPTCNT4 field values  */ 
 
	#define GPT_GPTCNT4_CNT4_OF(x)		((Uint16)(x)) 
	#define GPT_GPTCNT4_CNT4_DEFAULT		GPT_GPTCNT4_CNT4_OF(0) 
 
	#define GPT_GPTCNT40_CNT4_OF(x)		((Uint16)(x)) 
	#define GPT_GPTCNT40_CNT4_DEFAULT		GPT_GPTCNT4_CNT4_OF(0) 
 
	#define GPT_GPTCNT41_CNT4_OF(x)		((Uint16)(x)) 
	#define GPT_GPTCNT41_CNT4_DEFAULT		GPT_GPTCNT4_CNT4_OF(0) 
 
 
#define GPT_GPTCNT4_RMK(cnt4)\
 ((Uint16) ( \
  ( GPT_FMK(GPTCNT4,CNT4,cnt4))\
)\
 ) 
 
#define GPT_GPTCNT4_RMKS(cnt4_sym)\
 ((Uint16) ( \
  ( GPT_FMKS(GPTCNT4,CNT4,cnt4_sym))\
)\
 ) 
 
/*  Default GPTCNT4 register value  */ 
 
/* ============================================================== */ 
 /* Make GPTCTL1 register values based on symbolic constants  */ 
 
/*  GPTCTL1 field values  */ 
 
	#define GPT_GPTCTL1_TIEN_NOT_GATED			(000000u) 
	#define GPT_GPTCTL1_TIEN_GATED_BY_TINP			(0x0001u) 
	#define GPT_GPTCTL1_TIEN_DEFAULT		GPT_GPTCTL1_TIEN_NOT_GATED 
 
	#define GPT_GPTCTL10_TIEN_NOT_GATED			(000000u) 
	#define GPT_GPTCTL10_TIEN_GATED_BY_TINP			(0x0001u) 
	#define GPT_GPTCTL10_TIEN_DEFAULT		GPT_GPTCTL1_TIEN_NOT_GATED 
 
	#define GPT_GPTCTL11_TIEN_NOT_GATED			(000000u) 
	#define GPT_GPTCTL11_TIEN_GATED_BY_TINP			(0x0001u) 
	#define GPT_GPTCTL11_TIEN_DEFAULT		GPT_GPTCTL1_TIEN_NOT_GATED 
 
	#define GPT_GPTCTL1_CLKSRC_VBUS				(000000u) 
	#define GPT_GPTCTL1_CLKSRC_INPUT_PIN			(0x0001u) 
	#define GPT_GPTCTL1_CLKSRC_DEFAULT		GPT_GPTCTL1_CLKSRC_VBUS 
 
	#define GPT_GPTCTL10_CLKSRC_VBUS			(000000u) 
	#define GPT_GPTCTL10_CLKSRC_INPUT_PIN			(0x0001u) 
	#define GPT_GPTCTL10_CLKSRC_DEFAULT		GPT_GPTCTL1_CLKSRC_VBUS 
 
	#define GPT_GPTCTL11_CLKSRC_VBUS			(000000u) 
	#define GPT_GPTCTL11_CLKSRC_INPUT_PIN			(0x0001u) 
	#define GPT_GPTCTL11_CLKSRC_DEFAULT		GPT_GPTCTL1_CLKSRC_VBUS 
 
	#define GPT_GPTCTL1_ENAMODE_DISABLED			(000000u) 
	#define GPT_GPTCTL1_ENAMODE_ONCE			(0x0001u) 
	#define GPT_GPTCTL1_ENAMODE_CONTINUOUS			(0x0002u) 
	#define GPT_GPTCTL1_ENAMODE_DEFAULT		GPT_GPTCTL1_ENAMODE_DISABLED 
 
	#define GPT_GPTCTL10_ENAMODE_DISABLED			(000000u) 
	#define GPT_GPTCTL10_ENAMODE_ONCE			(0x0001u) 
	#define GPT_GPTCTL10_ENAMODE_CONTINUOUS			(0x0002u) 
	#define GPT_GPTCTL10_ENAMODE_DEFAULT		GPT_GPTCTL1_ENAMODE_DISABLED 
 
	#define GPT_GPTCTL11_ENAMODE_DISABLED			(000000u) 
	#define GPT_GPTCTL11_ENAMODE_ONCE			(0x0001u) 
	#define GPT_GPTCTL11_ENAMODE_CONTINUOUS			(0x0002u) 
	#define GPT_GPTCTL11_ENAMODE_DEFAULT		GPT_GPTCTL1_ENAMODE_DISABLED 
 
	#define GPT_GPTCTL1_PWID_INACTIVE_1CYCLE		(000000u) 
	#define GPT_GPTCTL1_PWID_INACTIVE_2CYCLES		(0x0001u) 
	#define GPT_GPTCTL1_PWID_INACTIVE_3CYCLES		(0x0002u) 
	#define GPT_GPTCTL1_PWID_INACTIVE_4CYCLES		(0x0003u) 
	#define GPT_GPTCTL1_PWID_DEFAULT		GPT_GPTCTL1_PWID_INACTIVE_1CYCLE
 
	#define GPT_GPTCTL10_PWID_INACTIVE_1CYCLE		(000000u) 
	#define GPT_GPTCTL10_PWID_INACTIVE_2CYCLES		(0x0001u) 
	#define GPT_GPTCTL10_PWID_INACTIVE_3CYCLES		(0x0002u) 
	#define GPT_GPTCTL10_PWID_INACTIVE_4CYCLES		(0x0003u) 
	#define GPT_GPTCTL10_PWID_DEFAULT		GPT_GPTCTL1_PWID_INACTIVE_1CYCLE
 
	#define GPT_GPTCTL11_PWID_INACTIVE_1CYCLE		(000000u) 
	#define GPT_GPTCTL11_PWID_INACTIVE_2CYCLES		(0x0001u) 
	#define GPT_GPTCTL11_PWID_INACTIVE_3CYCLES		(0x0002u) 
	#define GPT_GPTCTL11_PWID_INACTIVE_4CYCLES		(0x0003u) 
	#define GPT_GPTCTL11_PWID_DEFAULT		GPT_GPTCTL1_PWID_INACTIVE_1CYCLE
 
	#define GPT_GPTCTL1_CP_CLOCK_MODE			(0x0001u) 
	#define GPT_GPTCTL1_CP_PULSE_MODE			(000000u) 
	#define GPT_GPTCTL1_CP_DEFAULT			GPT_GPTCTL1_CP_PULSE_MODE 
 
	#define GPT_GPTCTL10_CP_CLOCK_MODE			(0x0001u) 
	#define GPT_GPTCTL10_CP_PULSE_MODE			(000000u) 
	#define GPT_GPTCTL10_CP_DEFAULT			GPT_GPTCTL1_CP_PULSE_MODE 
 
	#define GPT_GPTCTL11_CP_CLOCK_MODE			(0x0001u) 
	#define GPT_GPTCTL11_CP_PULSE_MODE			(000000u) 
	#define GPT_GPTCTL11_CP_DEFAULT			GPT_GPTCTL1_CP_PULSE_MODE 
 
	#define GPT_GPTCTL1_INVIN_INVERT_OUTPUT			(0x0001u) 
	#define GPT_GPTCTL1_INVIN_DONT_INVERT_OUTPUT		(000000u) 
	#define GPT_GPTCTL1_INVIN_DEFAULT		GPT_GPTCTL1_INVIN_DONT_INVERT_OUTPUT 
 
	#define GPT_GPTCTL10_INVIN_INVERT_OUTPUT		(0x0001u) 
	#define GPT_GPTCTL10_INVIN_DONT_INVERT_OUTPUT		(000000u) 
	#define GPT_GPTCTL10_INVIN_DEFAULT		GPT_GPTCTL1_INVIN_DONT_INVERT_OUTPUT 
 
	#define GPT_GPTCTL11_INVIN_INVERT_OUTPUT		(0x0001u) 
	#define GPT_GPTCTL11_INVIN_DONT_INVERT_OUTPUT		(000000u) 
	#define GPT_GPTCTL11_INVIN_DEFAULT		GPT_GPTCTL1_INVIN_DONT_INVERT_OUTPUT 
 
 
	#define GPT_GPTCTL1_INVOUT_INVERT_OUTPUT		(0x0001u) 
	#define GPT_GPTCTL1_INVOUT_DONT_INVERT_OUTPUT		(000000u) 
	#define GPT_GPTCTL1_INVOUT_DEFAULT		GPT_GPTCTL1_INVOUT_DONT_INVERT_OUTPUT 
 
	#define GPT_GPTCTL10_INVOUT_INVERT_OUTPUT		(0x0001u) 
	#define GPT_GPTCTL10_INVOUT_DONT_INVERT_OUTPUT		(000000u) 
	#define GPT_GPTCTL10_INVOUT_DEFAULT		GPT_GPTCTL1_INVOUT_DONT_INVERT_OUTPUT 
 
	#define GPT_GPTCTL11_INVOUT_INVERT_OUTPUT		(0x0001u) 
	#define GPT_GPTCTL11_INVOUT_DONT_INVERT_OUTPUT		(000000u) 
	#define GPT_GPTCTL11_INVOUT_DEFAULT		GPT_GPTCTL1_INVOUT_DONT_INVERT_OUTPUT 
 
	#define GPT_GPTCTL1_TSTAT_HIGH				(0x0001u) 
	#define GPT_GPTCTL1_TSTAT_LOW				(000000u) 
 
	#define GPT_GPTCTL10_TSTAT_HIGH				(0x0001u) 
	#define GPT_GPTCTL10_TSTAT_LOW				(000000u) 
 
	#define GPT_GPTCTL11_TSTAT_HIGH				(0x0001u) 
	#define GPT_GPTCTL11_TSTAT_LOW				(000000u) 
 
#define GPT_GPTCTL1_RMK(tien,clksrc,enamode,pwid,cp,invin,invout)\
 ((Uint16) ( \
  ( GPT_FMK(GPTCTL1,TIEN,tien))|\
  ( GPT_FMK(GPTCTL1,CLKSRC,clksrc))|\
  ( GPT_FMK(GPTCTL1,ENAMODE,enamode))|\
  ( GPT_FMK(GPTCTL1,PWID,pwid))|\
  ( GPT_FMK(GPTCTL1,CP,cp))|\
  ( GPT_FMK(GPTCTL1,INVIN,invin))|\
  ( GPT_FMK(GPTCTL1,INVOUT,invout))\
)\
 ) 
 
#define GPT_GPTCTL1_RMKS(tien_sym,clksrc_sym,enamode_sym,pwid_sym,cp_sym,invin_sym,invout_sym)\
 ((Uint16) ( \
  ( GPT_FMKS(GPTCTL1,TIEN,tien_sym))|\
  ( GPT_FMKS(GPTCTL1,CLKSRC,clksrc_sym))|\
  ( GPT_FMKS(GPTCTL1,ENAMODE,enamode_sym))|\
  ( GPT_FMKS(GPTCTL1,PWID,pwid_sym))|\
  ( GPT_FMKS(GPTCTL1,CP,cp_sym))|\
  ( GPT_FMKS(GPTCTL1,INVIN,invin_sym))|\
  ( GPT_FMKS(GPTCTL1,INVOUT,invout_sym))\
)\
 ) 
 
/*  Default GPTCTL1 register value  */ 
 
/* ============================================================== */ 
 /* Make GPTCTL2 register values based on symbolic constants  */ 
 
/*  GPTCTL2 field values  */ 
 
	#define GPT_GPTCTL2_TIEN_NOT_GATED			(000000u) 
	#define GPT_GPTCTL2_TIEN_GATED_BY_TINP			(0x0001u) 
	#define GPT_GPTCTL2_TIEN_DEFAULT		GPT_GPTCTL2_TIEN_NOT_GATED 
 
	#define GPT_GPTCTL20_TIEN_NOT_GATED			(000000u) 
	#define GPT_GPTCTL20_TIEN_GATED_BY_TINP			(0x0001u) 
	#define GPT_GPTCTL20_TIEN_DEFAULT		GPT_GPTCTL2_TIEN_NOT_GATED 
 
	#define GPT_GPTCTL21_TIEN_NOT_GATED			(000000u) 
	#define GPT_GPTCTL21_TIEN_GATED_BY_TINP			(0x0001u) 
	#define GPT_GPTCTL21_TIEN_DEFAULT		GPT_GPTCTL2_TIEN_NOT_GATED 
 
	#define GPT_GPTCTL2_CLKSRC_VBUS				(000000u) 
	#define GPT_GPTCTL2_CLKSRC_INPUT_PIN			(0x0001u) 
	#define GPT_GPTCTL2_CLKSRC_DEFAULT		GPT_GPTCTL2_CLKSRC_VBUS 
 
	#define GPT_GPTCTL20_CLKSRC_VBUS			(000000u) 
	#define GPT_GPTCTL20_CLKSRC_INPUT_PIN			(0x0001u) 
	#define GPT_GPTCTL20_CLKSRC_DEFAULT		GPT_GPTCTL2_CLKSRC_VBUS 
 
	#define GPT_GPTCTL21_CLKSRC_VBUS			(000000u) 
	#define GPT_GPTCTL21_CLKSRC_INPUT_PIN			(0x0001u) 
	#define GPT_GPTCTL21_CLKSRC_DEFAULT		GPT_GPTCTL2_CLKSRC_VBUS 
 
	#define GPT_GPTCTL2_ENAMODE_DISABLED			(000000u) 
	#define GPT_GPTCTL2_ENAMODE_ONCE			(0x0001u) 
	#define GPT_GPTCTL2_ENAMODE_CONTINUOUS			(0x0002u) 
	#define GPT_GPTCTL2_ENAMODE_DEFAULT		GPT_GPTCTL2_ENAMODE_DISABLED 
 
	#define GPT_GPTCTL20_ENAMODE_DISABLED			(000000u) 
	#define GPT_GPTCTL20_ENAMODE_ONCE			(0x0001u) 
	#define GPT_GPTCTL20_ENAMODE_CONTINUOUS			(0x0002u) 
	#define GPT_GPTCTL20_ENAMODE_DEFAULT		GPT_GPTCTL2_ENAMODE_DISABLED 
 
	#define GPT_GPTCTL21_ENAMODE_DISABLED			(000000u) 
	#define GPT_GPTCTL21_ENAMODE_ONCE			(0x0001u) 
	#define GPT_GPTCTL21_ENAMODE_CONTINUOUS			(0x0002u) 
	#define GPT_GPTCTL21_ENAMODE_DEFAULT		GPT_GPTCTL2_ENAMODE_DISABLED 
 
	#define GPT_GPTCTL2_PWID_INACTIVE_1CYCLE		(000000u) 
	#define GPT_GPTCTL2_PWID_INACTIVE_2CYCLES		(0x0001u) 
	#define GPT_GPTCTL2_PWID_INACTIVE_3CYCLES		(0x0002u) 
	#define GPT_GPTCTL2_PWID_INACTIVE_4CYCLES		(0x0003u) 
	#define GPT_GPTCTL2_PWID_DEFAULT		GPT_GPTCTL2_PWID_INACTIVE_1CYCLE 
 
	#define GPT_GPTCTL20_PWID_INACTIVE_1CYCLE		(000000u) 
	#define GPT_GPTCTL20_PWID_INACTIVE_2CYCLES		(0x0001u) 
	#define GPT_GPTCTL20_PWID_INACTIVE_3CYCLES		(0x0002u) 
	#define GPT_GPTCTL20_PWID_INACTIVE_4CYCLES		(0x0003u) 
	#define GPT_GPTCTL20_PWID_DEFAULT		GPT_GPTCTL2_PWID_INACTIVE_1CYCLE 
 
	#define GPT_GPTCTL21_PWID_INACTIVE_1CYCLE		(000000u) 
	#define GPT_GPTCTL21_PWID_INACTIVE_2CYCLES		(0x0001u) 
	#define GPT_GPTCTL21_PWID_INACTIVE_3CYCLES		(0x0002u) 
	#define GPT_GPTCTL21_PWID_INACTIVE_4CYCLES		(0x0003u) 
	#define GPT_GPTCTL21_PWID_DEFAULT		GPT_GPTCTL2_PWID_INACTIVE_1CYCLE 
 
	#define GPT_GPTCTL2_CP_CLOCK_MODE			(0x0001u) 
	#define GPT_GPTCTL2_CP_PULSE_MODE			(000000u) 
	#define GPT_GPTCTL2_CP_DEFAULT			GPT_GPTCTL2_CP_PULSE_MODE 
 
	#define GPT_GPTCTL20_CP_CLOCK_MODE			(0x0001u) 
	#define GPT_GPTCTL20_CP_PULSE_MODE			(000000u) 
	#define GPT_GPTCTL20_CP_DEFAULT			GPT_GPTCTL2_CP_PULSE_MODE 
 
	#define GPT_GPTCTL21_CP_CLOCK_MODE			(0x0001u) 
	#define GPT_GPTCTL21_CP_PULSE_MODE			(000000u) 
	#define GPT_GPTCTL21_CP_DEFAULT			GPT_GPTCTL2_CP_PULSE_MODE 
 
 
	#define GPT_GPTCTL2_INVIN_INVERT_OUTPUT			(0x0001u) 
	#define GPT_GPTCTL2_INVIN_DONT_INVERT_OUTPUT		(000000u) 
	#define GPT_GPTCTL2_INVIN_DEFAULT		GPT_GPTCTL2_INVIN_DONT_INVERT_OUTPUT 
 
	#define GPT_GPTCTL20_INVIN_INVERT_OUTPUT		(0x0001u) 
	#define GPT_GPTCTL20_INVIN_DONT_INVERT_OUTPUT		(000000u) 
	#define GPT_GPTCTL20_INVIN_DEFAULT		GPT_GPTCTL2_INVIN_DONT_INVERT_OUTPUT 
 
	#define GPT_GPTCTL21_INVIN_INVERT_OUTPUT		(0x0001u) 
	#define GPT_GPTCTL21_INVIN_DONT_INVERT_OUTPUT		(000000u) 
	#define GPT_GPTCTL21_INVIN_DEFAULT		GPT_GPTCTL2_INVIN_DONT_INVERT_OUTPUT 
 
	#define GPT_GPTCTL2_INVOUT_INVERT_OUTPUT		(0x0001u) 
	#define GPT_GPTCTL2_INVOUT_DONT_INVERT_OUTPUT		(000000u) 
	#define GPT_GPTCTL2_INVOUT_DEFAULT		GPT_GPTCTL2_INVOUT_DONT_INVERT_OUTPUT 
 
	#define GPT_GPTCTL20_INVOUT_INVERT_OUTPUT		(0x0001u) 
	#define GPT_GPTCTL20_INVOUT_DONT_INVERT_OUTPUT		(000000u) 
	#define GPT_GPTCTL20_INVOUT_DEFAULT		GPT_GPTCTL2_INVOUT_DONT_INVERT_OUTPUT 
 
	#define GPT_GPTCTL21_INVOUT_INVERT_OUTPUT		(0x0001u) 
	#define GPT_GPTCTL21_INVOUT_DONT_INVERT_OUTPUT		(000000u) 
	#define GPT_GPTCTL21_INVOUT_DEFAULT		GPT_GPTCTL2_INVOUT_DONT_INVERT_OUTPUT 
 
	#define GPT_GPTCTL2_TSTAT_HIGH				(0x0001u) 
	#define GPT_GPTCTL2_TSTAT_LOW				(000000u) 
 
	#define GPT_GPTCTL20_TSTAT_HIGH				(0x0001u) 
	#define GPT_GPTCTL20_TSTAT_LOW				(000000u) 
 
	#define GPT_GPTCTL21_TSTAT_HIGH				(0x0001u) 
	#define GPT_GPTCTL21_TSTAT_LOW				(000000u) 
 
#define GPT_GPTCTL2_RMK(tien,clksrc,enamode,pwid,cp,invin,invout)\
 ((Uint16) ( \
  ( GPT_FMK(GPTCTL2,TIEN,tien))|\
  ( GPT_FMK(GPTCTL2,CLKSRC,clksrc))|\
  ( GPT_FMK(GPTCTL2,ENAMODE,enamode))|\
  ( GPT_FMK(GPTCTL2,PWID,pwid))|\
  ( GPT_FMK(GPTCTL2,CP,cp))|\
  ( GPT_FMK(GPTCTL2,INVIN,invin))|\
  ( GPT_FMK(GPTCTL2,INVOUT,invout))\
)\
 ) 
 
#define GPT_GPTCTL2_RMKS(tien_sym,clksrc_sym,enamode_sym,pwid_sym,cp_sym,invin_sym,invout_sym)\
 ((Uint16) ( \
  ( GPT_FMKS(GPTCTL2,TIEN,tien_sym))|\
  ( GPT_FMKS(GPTCTL2,CLKSRC,clksrc_sym))|\
  ( GPT_FMKS(GPTCTL2,ENAMODE,enamode_sym))|\
  ( GPT_FMKS(GPTCTL2,PWID,pwid_sym))|\
  ( GPT_FMKS(GPTCTL2,CP,cp_sym))|\
  ( GPT_FMKS(GPTCTL2,INVIN,invin_sym))|\
  ( GPT_FMKS(GPTCTL2,INVOUT,invout_sym))\
)\
 ) 
 
/*  Default GPTCTL2 register value  */ 
 
/* ============================================================== */ 
 /* Make GPTEMU register values based on symbolic constants  */ 
 
/*  GPTEMU field values  */ 
 
	#define GPT_GPTEMU_FREE_ON  			(000000u) 
	#define GPT_GPTEMU_FREE_OFF			(000001u) 
        #define GPT_GPTEMU_FREE_DEFAULT           GPT_GPTEMU_FREE_ON 
          
	#define GPT_GPTEMU0_FREE_ON			(000000u) 
	#define GPT_GPTEMU0_FREE_OFF			(000001u) 
        #define GPT_GPTEMU0_FREE_DEFAULT          GPT_GPTEMU0_FREE_ON
          
	#define GPT_GPTEMU1_FREE_ON			(000000u) 
	#define GPT_GPTEMU1_FREE_OFF			(000001u) 
        #define GPT_GPTEMU1_FREE_DEFAULT          GPT_GPTEMU1_FREE_ON 
        
        #define GPT_GPTEMU_SOFT_ON  			(000000u) 
	#define GPT_GPTEMU_SOFT_OFF			(000001u) 
        #define GPT_GPTEMU_SOFT_DEFAULT           GPT_GPTEMU_SOFT_ON 
         
	#define GPT_GPTEMU0_SOFT_ON			(000000u) 
	#define GPT_GPTEMU0_SOFT_OFF			(000001u) 
        #define GPT_GPTEMU0_SOFT_DEFAULT          GPT_GPTEMU0_SOFT_ON 
 
	#define GPT_GPTEMU1_SOFT_ON			(000000u) 
	#define GPT_GPTEMU1_SOFT_OFF			(000001u) 
	#define GPT_GPTEMU1_SOFT_DEFAULT          GPT_GPTEMU1_SOFT_ON 
 
   
/*  Default GPTEMU register value  */ 
 
/* ============================================================== */ 
 /* Make GPTGPEN register values based on symbolic constants  */ 
 
/*  GPTGPEN field values  */ 
 
	#define GPT_GPTGPEN_TOUT1EN_TIMER_OUTPUT		(000000u) 
	#define GPT_GPTGPEN_TOUT1EN_GPIO_PIN			(0x0001u) 
	#define GPT_GPTGPEN_TOUT1EN_DEFAULT		    GPT_GPTGPEN_TOUT1EN_TIMER_OUTPUT 
 
	#define GPT_GPTGPEN0_TOUT1EN_TIMER_OUTPUT		(000000u) 
	#define GPT_GPTGPEN0_TOUT1EN_GPIO_PIN			(0x0001u) 
	#define GPT_GPTGPEN0_TOUT1EN_DEFAULT		GPT_GPTGPEN_TOUT1EN_TIMER_OUTPUT 
 
	#define GPT_GPTGPEN1_TOUT1EN_TIMER_OUTPUT		(000000u) 
	#define GPT_GPTGPEN1_TOUT1EN_GPIO_PIN			(0x0001u) 
	#define GPT_GPTGPEN1_TOUT1EN_DEFAULT		GPT_GPTGPEN_TOUT1EN_TIMER_OUTPUT 
 
	#define GPT_GPTGPEN_TIN1EN_TIMER_INPUT			(000000u) 
	#define GPT_GPTGPEN_TIN1EN_GPIO_PIN			    (0x0001u) 
	#define GPT_GPTGPEN_TIN1EN_DEFAULT		    GPT_GPTGPEN_TIN1EN_TIMER_INPUT 
 
	#define GPT_GPTGPEN0_TIN1EN_TIMER_INPUT		    (000000u) 
	#define GPT_GPTGPEN0_TIN1EN_GPIO_PIN			(0x0001u) 
	#define GPT_GPTGPEN0_TIN1EN_DEFAULT		    GPT_GPTGPEN_TIN1EN_TIMER_INPUT 
 
	#define GPT_GPTGPEN1_TIN1EN_TIMER_INPUT		    (000000u) 
	#define GPT_GPTGPEN1_TIN1EN_GPIO_PIN		    (0x0001u) 
	#define GPT_GPTGPEN1_TIN1EN_DEFAULT		    GPT_GPTGPEN_TIN1EN_TIMER_INPUT 
 
 
#define GPT_GPTGPEN_RMK(tout1en,tin1en)\
 ((Uint16) ( \
  ( GPT_FMK(GPTGPEN,TOUT1EN,tout1en))|\
  ( GPT_FMK(GPTGPEN,TIN1EN,tin1en))\
)\
 ) 
 
#define GPT_GPTGPEN_RMKS(tout1en_sym,tin1en_sym)\
 ((Uint16) ( \
  ( GPT_FMKS(GPTGPEN,TOUT1EN,tout1en_sym))|\
  ( GPT_FMKS(GPTGPEN,TIN1EN,tin1en_sym))\
)\
 ) 
 
/*  Default GPTGPEN register value  */ 
 
/* ============================================================== */ 
 /* Make GPTGCTL1 register values based on symbolic constants  */ 
 
/*  GPTGCTL1 field values  */ 
 
	#define GPT_GPTGCTL1_TDDR34_OF(x)		((Uint16)(x)) 
	#define GPT_GPTGCTL1_TDDR34_DEFAULT		GPT_GPTGCTL1_TDDR34_OF(0) 
 
	#define GPT_GPTGCTL10_TDDR34_OF(x)		((Uint16)(x)) 
	#define GPT_GPTGCTL10_TDDR34_DEFAULT		GPT_GPTGCTL1_TDDR34_OF(0) 
 
	#define GPT_GPTGCTL11_TDDR34_OF(x)		((Uint16)(x)) 
	#define GPT_GPTGCTL11_TDDR34_DEFAULT		GPT_GPTGCTL1_TDDR34_OF(0) 
 
	#define GPT_GPTGCTL1_PSC34_OF(x)		((Uint16)(x)) 
	#define GPT_GPTGCTL1_PSC34_DEFAULT		GPT_GPTGCTL1_PSC34_OF(0) 
 
	#define GPT_GPTGCTL10_PSC34_OF(x)		((Uint16)(x)) 
	#define GPT_GPTGCTL10_PSC34_DEFAULT		GPT_GPTGCTL1_PSC34_OF(0) 
 
	#define GPT_GPTGCTL11_PSC34_OF(x)		((Uint16)(x)) 
	#define GPT_GPTGCTL11_PSC34_DEFAULT		GPT_GPTGCTL1_PSC34_OF(0) 
 
	#define GPT_GPTGCTL1_TIMMODE_64BIT_GPTIM			(000000u) 
	#define GPT_GPTGCTL1_TIMMODE_32BIT_DUAL				(0x0001u) 
	#define GPT_GPTGCTL1_TIMMODE_32BIT_CHAINED			(0x0003u) 
	#define GPT_GPTGCTL1_TIMMODE_DEFAULT			GPT_GPTGCTL1_TIMMODE_64BIT_GPTIM 
 
	#define GPT_GPTGCTL10_TIMMODE_64BIT_GPTIM			(000000u) 
	#define GPT_GPTGCTL10_TIMMODE_32BIT_DUAL			(0x0001u) 
	#define GPT_GPTGCTL10_TIMMODE_32BIT_CHAINED			(0x0003u) 
	#define GPT_GPTGCTL10_TIMMODE_DEFAULT			GPT_GPTGCTL1_TIMMODE_64BIT_GPTIM 
 
	#define GPT_GPTGCTL11_TIMMODE_64BIT_GPTIM			(000000u) 
	#define GPT_GPTGCTL11_TIMMODE_32BIT_DUAL			(0x0001u) 
	#define GPT_GPTGCTL11_TIMMODE_32BIT_CHAINED			(0x0003u) 
	#define GPT_GPTGCTL11_TIMMODE_DEFAULT			GPT_GPTGCTL1_TIMMODE_64BIT_GPTIM 
 
	#define GPT_GPTGCTL1_TIM34RS_IN_RESET				(000000u) 
	#define GPT_GPTGCTL1_TIM34RS_NOT_IN_RESET			(0x0001u) 
	#define GPT_GPTGCTL1_TIM34RS_DEFAULT			GPT_GPTGCTL1_TIM34RS_IN_RESET 
 
	#define GPT_GPTGCTL10_TIM34RS_IN_RESET				(000000u) 
	#define GPT_GPTGCTL10_TIM34RS_NOT_IN_RESET			(0x0001u) 
	#define GPT_GPTGCTL10_TIM34RS_DEFAULT			GPT_GPTGCTL1_TIM34RS_IN_RESET 
 
	#define GPT_GPTGCTL11_TIM34RS_IN_RESET				(000000u) 
	#define GPT_GPTGCTL11_TIM34RS_NOT_IN_RESET			(0x0001u) 
	#define GPT_GPTGCTL11_TIM34RS_DEFAULT			GPT_GPTGCTL1_TIM34RS_IN_RESET 
 
	#define GPT_GPTGCTL1_TIM12RS_IN_RESET				(000000u) 
	#define GPT_GPTGCTL1_TIM12RS_NOT_IN_RESET			(0x0001u) 
	#define GPT_GPTGCTL1_TIM12RS_DEFAULT			GPT_GPTGCTL1_TIM12RS_IN_RESET 
 
	#define GPT_GPTGCTL10_TIM12RS_IN_RESET				(000000u) 
	#define GPT_GPTGCTL10_TIM12RS_NOT_IN_RESET			(0x0001u) 
	#define GPT_GPTGCTL10_TIM12RS_DEFAULT			GPT_GPTGCTL1_TIM12RS_IN_RESET 
 
	#define GPT_GPTGCTL11_TIM12RS_IN_RESET				(000000u) 
	#define GPT_GPTGCTL11_TIM12RS_NOT_IN_RESET			(0x0001u) 
	#define GPT_GPTGCTL11_TIM12RS_DEFAULT			GPT_GPTGCTL1_TIM12RS_IN_RESET 
 
#define GPT_GPTGCTL1_RMK(tddr34,psc34,timmode,tim34rs,tim12rs)\
 ((Uint16) ( \
  ( GPT_FMK(GPTGCTL1,TDDR34,tddr34))|\
  ( GPT_FMK(GPTGCTL1,PSC34,psc34))|\
  ( GPT_FMK(GPTGCTL1,TIMMODE,timmode))|\
  ( GPT_FMK(GPTGCTL1,TIM34RS,tim34rs))|\
  ( GPT_FMK(GPTGCTL1,TIM12RS,tim12rs))\
)\
 ) 
 
#define GPT_GPTGCTL1_RMKS(tddr34_sym,psc34_sym,timmode_sym,tim34rs_sym,tim12rs_sym)\
 ((Uint16) ( \
  ( GPT_FMKS(GPTGCTL1,TDDR34,tddr34_sym))|\
  ( GPT_FMKS(GPTGCTL1,PSC34,psc34_sym))|\
  ( GPT_FMKS(GPTGCTL1,TIMMODE,timmode_sym))|\
  ( GPT_FMKS(GPTGCTL1,TIM34RS,tim34rs_sym))|\
  ( GPT_FMKS(GPTGCTL1,TIM12RS,tim12rs_sym))\
)\
 ) 
 
/*  Default GPTGCTL1 register value  */ 
 
/* ============================================================== */ 
 /* Make GPTGPDAT register values based on symbolic constants  */ 
 
/*  GPTGPDAT field values  */ 
 

	#define GPT_GPTGPDAT_TOUT1DAT_HIGH			(0x0001u) 
	#define GPT_GPTGPDAT_TOUT1DAT_LOW			(000000u) 
	#define GPT_GPTGPDAT_TOUT1DAT_DEFAULT		GPT_GPTGPDAT_TOUT1DAT_LOW 
 
	#define GPT_GPTGPDAT0_TOUT1DAT_HIGH			(0x0001u) 
	#define GPT_GPTGPDAT0_TOUT1DAT_LOW			(000000u) 
	#define GPT_GPTGPDAT0_TOUT1DAT_DEFAULT		GPT_GPTGPDAT_TOUT1DAT_LOW 
 
	#define GPT_GPTGPDAT1_TOUT1DAT_HIGH			(0x0001u) 
	#define GPT_GPTGPDAT1_TOUT1DAT_LOW			(000000u) 
	#define GPT_GPTGPDAT1_TOUT1DAT_DEFAULT		GPT_GPTGPDAT_TOUT1DAT_LOW 
 
	#define GPT_GPTGPDAT_TIN1DAT_HIGH			(0x0001u) 
	#define GPT_GPTGPDAT_TIN1DAT_LOW			(000000u) 
	#define GPT_GPTGPDAT_TIN1DAT_DEFAULT		GPT_GPTGPDAT_TIN1DAT_LOW 
 
	#define GPT_GPTGPDAT0_TIN1DAT_HIGH			(0x0001u) 
	#define GPT_GPTGPDAT0_TIN1DAT_LOW			(000000u) 
	#define GPT_GPTGPDAT0_TIN1DAT_DEFAULT		GPT_GPTGPDAT_TIN1DAT_LOW 
 
	#define GPT_GPTGPDAT1_TIN1DAT_HIGH			(0x0001u) 
	#define GPT_GPTGPDAT1_TIN1DAT_LOW			(000000u) 
	#define GPT_GPTGPDAT1_TIN1DAT_DEFAULT		GPT_GPTGPDAT_TIN1DAT_LOW 
 
 
 
#define GPT_GPTGPDAT_RMK(tout1dat,tin1dat)\
 ((Uint16) ( \
  ( GPT_FMK(GPTGPDAT,TOUT1DAT,tout1dat))|\
  ( GPT_FMK(GPTGPDAT,TIN1DAT,tin1dat))\
)\
 ) 
 
#define GPT_GPTGPDAT_RMKS(tout1dat_sym,tin1dat_sym)\
 ((Uint16) ( \
  ( GPT_FMKS(GPTGPDAT,TOUT1DAT,tout1dat_sym))|\
  ( GPT_FMKS(GPTGPDAT,TIN1DAT,tin1dat_sym))\
)\
 ) 
 
/*  Default GPTGPDAT register value  */ 
 
/* ============================================================== */ 
 /* Make GPTGPDIR register values based on symbolic constants  */ 
 
/*  GPTGPDIR field values  */ 
 
	
	#define GPT_GPTGPDIR_TOUT1DIR_GPIO_INPUT			(000000u) 
	#define GPT_GPTGPDIR_TOUT1DIR_GPIO_OUTPUT			(0x0001u) 
	#define GPT_GPTGPDIR_TOUT1DIR_DEFAULT			GPT_GPTGPDIR_TOUT1DIR_GPIO_INPUT 
 
	#define GPT_GPTGPDIR0_TOUT1DIR_GPIO_INPUT			(000000u) 
	#define GPT_GPTGPDIR0_TOUT1DIR_GPIO_OUTPUT			(0x0001u) 
	#define GPT_GPTGPDIR0_TOUT1DIR_DEFAULT			GPT_GPTGPDIR_TOUT1DIR_GPIO_INPUT 
 
	#define GPT_GPTGPDIR1_TOUT1DIR_GPIO_INPUT			(000000u) 
	#define GPT_GPTGPDIR1_TOUT1DIR_GPIO_OUTPUT			(0x0001u) 
	#define GPT_GPTGPDIR1_TOUT1DIR_DEFAULT			GPT_GPTGPDIR_TOUT1DIR_GPIO_INPUT 
 
	#define GPT_GPTGPDIR_TIN1DIR_GPIO_INPUT				(000000u) 
	#define GPT_GPTGPDIR_TIN1DIR_GPIO_OUTPUT			(0x0001u) 
	#define GPT_GPTGPDIR_TIN1DIR_DEFAULT			GPT_GPTGPDIR_TIN1DIR_GPIO_INPUT 
 
	#define GPT_GPTGPDIR0_TIN1DIR_GPIO_INPUT			(000000u) 
	#define GPT_GPTGPDIR0_TIN1DIR_GPIO_OUTPUT			(0x0001u) 
	#define GPT_GPTGPDIR0_TIN1DIR_DEFAULT			GPT_GPTGPDIR_TIN1DIR_GPIO_INPUT 
 
	#define GPT_GPTGPDIR1_TIN1DIR_GPIO_INPUT			(000000u) 
	#define GPT_GPTGPDIR1_TIN1DIR_GPIO_OUTPUT			(0x0001u) 
	#define GPT_GPTGPDIR1_TIN1DIR_DEFAULT			GPT_GPTGPDIR_TIN1DIR_GPIO_INPUT 
 
#define GPT_GPTGPDIR_RMK(tout1dir,tin1dir)\
 ((Uint16) ( \
  ( GPT_FMK(GPTGPDIR,TOUT1DIR,tout1dir))|\
  ( GPT_FMK(GPTGPDIR,TIN1DIR,tin1dir))\
)\
 ) 
 
#define GPT_GPTGPDIR_RMKS(tout1dir_sym,tin1dir_sym)\
 ((Uint16) ( \
  ( GPT_FMKS(GPTGPDIR,TOUT1DIR,tout1dir_sym))|\
  ( GPT_FMKS(GPTGPDIR,TIN1DIR,tin1dir_sym))\
)\
 ) 
 
/*  Default GPTGPDIR register value  */ 
 
/* ============================================================== */ 
 /* Make GPTGPINT register values based on symbolic constants  */ 
 
/*  GPTGPINT field values  */ 
 
	
    #define GPT_GPTGPINT_TIN1INV_DISABLE			(0x0000u)  
	#define GPT_GPTGPINT_TIN1INV_ENABLE			(000001u) 
	#define GPT_GPTGPINT_TIN1INV_DEFAULT		GPT_GPTGPINT_TIN1INV_DISABLE
	
	
    #define GPT_GPTGPINT0_TIN1INV_DISABLE			(0x0000u)  
	#define GPT_GPTGPINT0_TIN1INV_ENABLE			(000001u) 
	#define GPT_GPTGPINT0_TIN1INV_DEFAULT		GPT_GPTGPINT_TIN10INV_DISABLE
	
	
    #define GPT_GPTGPINT1_TIN1INV_DISABLE			(0x0000u)  
	#define GPT_GPTGPINT1_TIN1INV_ENABLE			(000001u) 
	#define GPT_GPTGPINT1_TIN1INV_DEFAULT		GPT_GPTGPINT_TIN11INV_DISABLE
 
	#define GPT_GPTGPINT_TIN1INT_DISABLE			(0x0000u)  
	#define GPT_GPTGPINT_TIN1INT_ENABLE			(000001u) 
	#define GPT_GPTGPINT_TIN1INT_DEFAULT		GPT_GPTGPINT_TIN1INT_DISABLE
	
	
    #define GPT_GPTGPINT0_TIN1INT_DISABLE			(0x0000u)  
	#define GPT_GPTGPINT0_TIN1INT_ENABLE			(000001u) 
	#define GPT_GPTGPINT0_TIN1INT_DEFAULT		GPT_GPTGPINT_TIN10INT_DISABLE
	
	
    #define GPT_GPTGPINT1_TIN1INT_DISABLE			(0x0000u)  
	#define GPT_GPTGPINT1_TIN1INT_ENABLE			(000001u) 
	#define GPT_GPTGPINT1_TIN1INT_DEFAULT		GPT_GPTGPINT_TIN11INT_DISABLE
 
 
#define GPT_GPTGPINT_RMK(tin1inv,tin1int)\
 ((Uint16) ( \
  ( GPT_FMK(GPTGPINT,TIN1INV,tin1inv))|\
  ( GPT_FMK(GPTGPINT,TIN1INT,tin1int))\
)\
 ) 
 
#define GPT_GPTGPINT_RMKS(tin1inv_sym,tin1int_sym)\
 ((Uint16) ( \
  ( GPT_FMKS(GPTGPINT,TIN1INV,tin1inv_sym))|\
  ( GPT_FMKS(GPTGPINT,TIN1INT,tin1int_sym))\
)\
 ) 
 
/*  Default GPTGPINT register value  */ 
 
/* ============================================================== */ 
 /* Make GPTPID1 register values based on symbolic constants  */ 
 
/*  GPTPID1 field values  */ 
 
	#define GPT_GPTPID1_CLASS_CLASS			(000000u) 
	#define GPT_GPTPID1_CLASS_DEFAULT		GPT_GPTPID1_CLASS_CLASS 
 
	#define GPT_GPTPID10_CLASS_CLASS			(000000u) 
	#define GPT_GPTPID10_CLASS_DEFAULT		GPT_GPTPID1_CLASS_CLASS 
 
	#define GPT_GPTPID11_CLASS_CLASS			(000000u) 
	#define GPT_GPTPID11_CLASS_DEFAULT		GPT_GPTPID1_CLASS_CLASS 
 
	#define GPT_GPTPID1_REVISION_REVISION			(000000u) 
	#define GPT_GPTPID1_REVISION_DEFAULT		GPT_GPTPID1_REVISION_REVISION 
 
	#define GPT_GPTPID10_REVISION_REVISION			(000000u) 
	#define GPT_GPTPID10_REVISION_DEFAULT		GPT_GPTPID1_REVISION_REVISION 
 
	#define GPT_GPTPID11_REVISION_REVISION			(000000u) 
	#define GPT_GPTPID11_REVISION_DEFAULT		GPT_GPTPID1_REVISION_REVISION 
 
 
 
/*  Default GPTPID1 register value  */ 
 
/* ============================================================== */ 
 /* Make GPTPID2 register values based on symbolic constants  */ 
 
/*  GPTPID2 field values  */ 
 
	#define GPT_GPTPID2_TYPE_TYPE			(000000u) 
	#define GPT_GPTPID2_TYPE_DEFAULT		GPT_GPTPID2_TYPE_GPT_GPTPID2_TYPE_TYPE 
 
	#define GPT_GPTPID20_TYPE_TYPE			(000000u) 
	#define GPT_GPTPID20_TYPE_DEFAULT		GPT_GPTPID2_TYPE_GPT_GPTPID2_TYPE_TYPE 
 
	#define GPT_GPTPID21_TYPE_TYPE			(000000u) 
	#define GPT_GPTPID21_TYPE_DEFAULT		GPT_GPTPID2_TYPE_GPT_GPTPID2_TYPE_TYPE 
 
 
/*  Default GPTPID2 register value  */ 
 
/* ============================================================== */ 
 /* Make GPTPRD1 register values based on symbolic constants  */ 
 
/*  GPTPRD1 field values  */ 
 
	#define GPT_GPTPRD1_PRD1_OF(x)		((Uint16)(x)) 
	#define GPT_GPTPRD1_PRD1_DEFAULT		GPT_GPTPRD1_PRD1_OF(0) 
 
	#define GPT_GPTPRD10_PRD1_OF(x)		((Uint16)(x)) 
	#define GPT_GPTPRD10_PRD1_DEFAULT		GPT_GPTPRD1_PRD1_OF(0) 
 
	#define GPT_GPTPRD11_PRD1_OF(x)		((Uint16)(x)) 
	#define GPT_GPTPRD11_PRD1_DEFAULT		GPT_GPTPRD1_PRD1_OF(0) 
 
 
#define GPT_GPTPRD1_RMK(prd1)\
 ((Uint16) ( \
  ( GPT_FMK(GPTPRD1,PRD1,prd1))\
)\
 ) 
 
#define GPT_GPTPRD1_RMKS(prd1_sym)\
 ((Uint16) ( \
  ( GPT_FMKS(GPTPRD1,PRD1,prd1_sym))\
)\
 ) 
 
/*  Default GPTPRD1 register value  */ 
 
/* ============================================================== */ 
 /* Make GPTPRD2 register values based on symbolic constants  */ 
 
/*  GPTPRD2 field values  */ 
 
	#define GPT_GPTPRD2_PRD2_OF(x)		((Uint16)(x)) 
	#define GPT_GPTPRD2_PRD2_DEFAULT		GPT_GPTPRD2_PRD2_0x0000u 
 
	#define GPT_GPTPRD20_PRD2_OF(x)		((Uint16)(x)) 
	#define GPT_GPTPRD20_PRD2_DEFAULT		GPT_GPTPRD2_PRD2_0x0000u 
 
	#define GPT_GPTPRD21_PRD2_OF(x)		((Uint16)(x)) 
	#define GPT_GPTPRD21_PRD2_DEFAULT		GPT_GPTPRD2_PRD2_0x0000u 
 
 
#define GPT_GPTPRD2_RMK(prd2)\
 ((Uint16) ( \
  ( GPT_FMK(GPTPRD2,PRD2,prd2))\
)\
 ) 
 
#define GPT_GPTPRD2_RMKS(prd2_sym)\
 ((Uint16) ( \
  ( GPT_FMKS(GPTPRD2,PRD2,prd2_sym))\
)\
 ) 
 
/*  Default GPTPRD2 register value  */ 
 
/* ============================================================== */ 
 /* Make GPTPRD3 register values based on symbolic constants  */ 
 
/*  GPTPRD3 field values  */ 
 
	#define GPT_GPTPRD3_PRD3_OF(x)		((Uint16)(x)) 
	#define GPT_GPTPRD3_PRD3_DEFAULT		GPT_GPTPRD3_PRD3_OF(0) 
 
	#define GPT_GPTPRD30_PRD3_OF(x)		((Uint16)(x)) 
	#define GPT_GPTPRD30_PRD3_DEFAULT		GPT_GPTPRD3_PRD3_OF(0) 
 
	#define GPT_GPTPRD31_PRD3_OF(x)		((Uint16)(x)) 
	#define GPT_GPTPRD31_PRD3_DEFAULT		GPT_GPTPRD3_PRD3_OF(0) 
 
 
#define GPT_GPTPRD3_RMK(prd3)\
 ((Uint16) ( \
  ( GPT_FMK(GPTPRD3,PRD3,prd3))\
)\
 ) 
 
#define GPT_GPTPRD3_RMKS(prd3_sym)\
 ((Uint16) ( \
  ( GPT_FMKS(GPTPRD3,PRD3,prd3_sym))\
)\
 ) 
 
/*  Default GPTPRD3 register value  */ 
 
/* ============================================================== */ 
 /* Make GPTPRD4 register values based on symbolic constants  */ 
 
/*  GPTPRD4 field values  */ 
 
	#define GPT_GPTPRD4_PRD4_OF(x)		((Uint16)(x)) 
	#define GPT_GPTPRD4_PRD4_DEFAULT		GPT_GPTPRD4_PRD4_0x0000u 
 
	#define GPT_GPTPRD40_PRD4_OF(x)		((Uint16)(x)) 
	#define GPT_GPTPRD40_PRD4_DEFAULT		GPT_GPTPRD4_PRD4_0x0000u 
 
	#define GPT_GPTPRD41_PRD4_OF(x)		((Uint16)(x)) 
	#define GPT_GPTPRD41_PRD4_DEFAULT		GPT_GPTPRD4_PRD4_0x0000u 
 
 
#define GPT_GPTPRD4_RMK(prd4)\
 ((Uint16) ( \
  ( GPT_FMK(GPTPRD4,PRD4,prd4))\
)\
 ) 
 
#define GPT_GPTPRD4_RMKS(prd4_sym)\
 ((Uint16) ( \
  ( GPT_FMKS(GPTPRD4,PRD4,prd4_sym))\
)\
 ) 
 
/*  Default GPTPRD4 register value  */ 
/*************************************************\
 GPT global typedef declarations  
\*************************************************/ 
 
typedef struct { 
	Uint16 gptemu; 
	Uint16 gptgpint; 
	Uint16 gptgpen; 
	Uint16 gptgpdir; 
	Uint16 gptgpdat; 
	Uint16 gptprd1; 
	Uint16 gptprd2; 
	Uint16 gptprd3; 
	Uint16 gptprd4; 
	Uint16 gptctl1; 
	Uint16 gptctl2; 
	Uint16 gptgctl1; 
} GPT_Config; 
 
typedef struct { 
   Uint16 *privateObj; 
} GPT_Private; 
 
 
/*************************************************\
* GPT global variable declarations 
\*************************************************/ 
 
 
/*************************************************\
* GPT global function declarations 
\*************************************************/ 
 
CSLAPI GPT_Handle GPT_open(int devNum, Uint32 Flags); 

CSLAPI void GPT_close(GPT_Handle hGPT); 

CSLAPI void GPT_config(GPT_Handle hGPT, GPT_Config *myConfig); 

CSLAPI void GPT_configArgs(GPT_Handle hGpt, Uint16 gptemu,  
            Uint16 gptprd1,  Uint16 gptprd2, Uint16 gptprd3,  Uint16 gptprd4, 
            Uint16 gptgpint, Uint16 gptgpen, Uint16 gptgpdir, Uint16 gptgpdat, 
            Uint16 gptctl1,  Uint16 gptctl2, Uint16 gptgctl1); 

CSLAPI void GPT_initDual32(GPT_Handle hGpt, Uint16 dt1ctl, Uint16 dt2ctl,  
           Uint32 dt1prd, Uint32 dt2prd, Uint16 dt2prsc); 

CSLAPI void GPT_init64(GPT_Handle hGpt, Uint16 gptgctl, Uint16 dt12ctl, 
           Uint32 prdHigh, Uint32 prdLow); 

CSLAPI void GPT_initChained32(GPT_Handle hGpt, Uint16 gctl, Uint16 ctl1, 
           Uint32 prdHigh, Uint32 prdLow); 
 
 
/*************************************************\
* GPT inline function declarations 
\*************************************************/ 
 
 
#ifdef USEDEFS 
 
IDECL void GPT_getPID(GPT_Handle hGpt, Uint16 *_type, Uint16 *_class, 
                        Uint16 *revision); 
                        
IDECL void GPT_getCnt(GPT_Handle hGpt, Uint32 *tim34, Uint32 *tim12); 

IDECL void GPT_start12(GPT_Handle hGpt); 

IDECL void GPT_start34(GPT_Handle hGpt); 

IDECL void GPT_stop(GPT_Handle hGpt); 

IDECL void GPT_reset(GPT_Handle hGpt); 

IDECL void GPT_start(GPT_Handle hGpt); 
 
IDECL void GPT_stop12(GPT_Handle hGpt);

IDECL void GPT_stop34(GPT_Handle hGpt);
 
/*----------------------------------------------------------------------------*/ 
IDEF void GPT_getPID(GPT_Handle hGpt, Uint16 *_type, Uint16 *_class, 
                     Uint16 *revision) { 
     ioport GPT_RegObj *regPtr = ((GPT_PrivateObj *)hGpt)->regs; 
     Uint16 tmp; 
     tmp = (regPtr->gptpid1); 
     *_class = tmp & 0xFFu; 
     *_type = (tmp > 8) & 0xFFu; 
     *revision = (regPtr->gptpid2) & 0xFFu; 
} 
 
/*----------------------------------------------------------------------------*/ 
IDEF void GPT_getCnt (GPT_Handle hGpt, Uint32 *tim34, Uint32 *tim12) { 
   ioport GPT_RegObj *regPtr = ((GPT_PrivateObj *)hGpt)->regs; 
   Uint16 tim1,tim2,tim3,tim4; 
    
   // Access TIM1 first to cause copy of tim2/3/4 to 
   // shadow registers to preserve snapshot 
 
   tim1 = (regPtr->gptcnt1);   
   tim2 = (regPtr->gptcnt2); 
   tim3 = (regPtr->gptcnt3); 
   tim4 = (regPtr->gptcnt4); 
 
   *tim12 = ((Uint32)tim2 << 16u) | tim1; 
   *tim34 = ((Uint32)tim4 << 16u) | tim3; 
} 
/*----------------------------------------------------------------------------*/ 
 IDEF void GPT_start12(GPT_Handle hGpt) { 
   ioport GPT_RegObj *regPtr = ((GPT_PrivateObj *)hGpt)->regs; 
    
   (regPtr->gptgctl1) |= 0x1u; 
} 
/*----------------------------------------------------------------------------*/ 
 IDEF void GPT_start34(GPT_Handle hGpt) { 
   ioport GPT_RegObj *regPtr = ((GPT_PrivateObj *)hGpt)->regs; 
    
   (regPtr->gptgctl1) |= 0x2u; 
} 
/*----------------------------------------------------------------------------*/ 
IDEF void GPT_stop(GPT_Handle hGpt) { 
  int oldgie; 
  ioport GPT_RegObj *regPtr = ((GPT_PrivateObj *)hGpt)->regs; 
 
  oldgie = IRQ_globalDisable();  
     
  /* stop timer 12 and 34*/   
  (regPtr->gptgctl1) &= 0xFFFCu; 
 
  IRQ_globalRestore(oldgie); 
 
} 
/*----------------------------------------------------------------------------*/ 
IDEF void GPT_stop12(GPT_Handle hGpt) {
  int oldgie;
  ioport GPT_RegObj *regPtr = ((GPT_PrivateObj *)hGpt)->regs;

  oldgie = IRQ_globalDisable(); 
    
  /* stop timer 12 only*/  
  (regPtr->gptgctl1) &= 0xFFFEu;

  IRQ_globalRestore(oldgie);

}
/*----------------------------------------------------------------------------*/ 
IDEF void GPT_stop34(GPT_Handle hGpt) {
 
  int oldgie;
  ioport GPT_RegObj *regPtr = ((GPT_PrivateObj *)hGpt)->regs;

  oldgie = IRQ_globalDisable(); 
    
  /* stop timer 34 only*/  
  (regPtr->gptgctl1) &= 0xFFFDu;

  IRQ_globalRestore(oldgie);

}
/*----------------------------------------------------------------------------*/ 
IDEF void GPT_reset(GPT_Handle hGpt) { 
  int oldgie; 
  Uint16 EventId; 
  ioport GPT_RegObj *regPtr = ((GPT_PrivateObj *)hGpt)->regs; 
 
  oldgie = IRQ_globalDisable();   
     
  if (hGpt == INV) {     
  
      GPT_reset(GPT_hDev0); 
      GPT_reset(GPT_hDev1);   
        
  }  
  else { 
      EventId  = GPT_getEventId(hGpt); 
      /* stop timer */   
      (regPtr->gptgctl1) = 0x0000u;  
      /* Reset Period Value=0xFFFF */ 
      (regPtr->gptprd1) = 0x0000u; 
      (regPtr->gptprd2) = 0x0000u; 
      (regPtr->gptprd3) = 0x0000u; 
      (regPtr->gptprd4) = 0x0000u; 
      IRQ_disable(EventId); 
      IRQ_clear(EventId); 
  } 
  IRQ_globalRestore(oldgie); 
 
} 
/*----------------------------------------------------------------------------*/ 
IDEF void GPT_start(GPT_Handle hGpt) { 
  int oldgie; 
  ioport GPT_RegObj *regPtr = ((GPT_PrivateObj *)hGpt)->regs;  
 
  oldgie = IRQ_globalDisable();  
     
      /* Take Tim12 and Tim34 out of reset */ 
 
  (regPtr->gptgctl1) |= 0x3u; 
 
  IRQ_globalRestore(oldgie); 
 
} 
/*----------------------------------------------------------------------------*/ 
 
#endif /*USEDEFS */ 
 
#else 
    #ifndef _GPT_MOD_ 
	   #error GPT Hal Module Not Supported on Specified Target 
    #endif 
#endif  /* _GPT_SUPPORT  */ 
 
#endif  /* _CSL_GPTHAL_H  */ 
 
/******************************************************************************\
*      
*      End of csl_gpt.h  
* 
\******************************************************************************/ 
