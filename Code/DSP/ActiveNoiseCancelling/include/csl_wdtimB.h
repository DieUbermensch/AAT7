/****************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved 
*------------------------------------------------------------------------------
* MODULE NAME... WDTIM
* FILENAME...... csl_wdtim.h
* DATE CREATED.. Wed Feb 13 11:06:40 2002
* PROJECT....... Chip Support Library
* COMPONENT..... Service Layer
* PREREQUISITS.. 
*------------------------------------------------------------------------------
*
* HISTORY:
*	 Created: Wed Feb 13 11:06:40 2002 (Automatic generation)
*	 	: 10/28/2003 Fixed few typos, corrected the sequence to start
*                            watchdog timer, added WDTIM_start
*		: 12/02/2003 Removed APIs for dual 32-bit mode
*               : 06/09/2004 Fixed C++ compiler errors
*
*------------------------------------------------------------------------------
* DESCRIPTION: CSL Service Layer interface for the WDTIM module 
*
\*************************************************************************/

#ifndef _CSL_WDTIMB_H_
#define _CSL_WDTIMB_H_

#include <_csl.h>
#include <csl_chiphal.h>

#if (_WDTIMB_SUPPORT) 

#include <csl_wdtimBhal.h>
#include <csl_gpt.h>

/*----------------------------------------------------------------*\
*	 WDTIM scope and inline control macros 			
\*----------------------------------------------------------------*/

#ifdef __cplusplus
#define CSLAPI extern "C"
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _WDTIM_MOD_
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
* WDTIM global macro declarations
\****************************************/

/* error codes */
#define WDTIM_ERR_MAJOR		   (ERR_BASE_WDTIM) 
#define WDTIM_ERR_ALLOC		   (0x00000000) 
#define WDTIM_ERR_INVALID_HANDLE  (0x00000001) 


#define WDTIM_getEventId           (11)

/* ============================================================== */
 /* Make WDTCLK register values based on symbolic constants  */

/*  WDTCLK field values  */

	#define WDTIM_WDTCLK_CLKDIV_DIV0	       (0x0000u) 
	#define WDTIM_WDTCLK_CLKDIV_DIV1	       (0x0001u) 
	#define WDTIM_WDTCLK_CLKDIV_DIV2	       (0x0002u) 
	#define WDTIM_WDTCLK_CLKDIV_DIV4	       (0x0004u) 
	#define WDTIM_WDTCLK_CLKDIV_DIV8	       (0x0008u)
	#define WDTIM_WDTCLK_CLKDIV_DEFAULT      WDTIM_WDTCLK_CLKDIV_DIV0


/*  Default WDTCLK register value  */

/* ============================================================== */
 /* Make WDTCNT1  register values based on symbolic constants  */

/*  WDTCNT1  field values  */

	#define WDTIM_WDTCNT1_CNT_OF(x)	      ((Uint16)(x))
	#define WDTIM_WDTCNT1_CNT_DEFAULT		WDTIM_WDTCNT1_CNT_OF(0x0000u)


#define WDTIM_WDTCNT1_RMK(cnt)\
 ((Uint16) ( \
  ( WDTIM_FMK(WDTCNT1 ,CNT,cnt))\
)\
 )

#define WDTIM_WDTCNT1_RMKS(cnt_sym)\
 ((Uint16) ( \
  ( WDTIM_FMKS(WDTCNT1 ,CNT,cnt_sym))\
)\
 )

/*  Default WDTCNT1  register value  */

/* ============================================================== */
 /* Make WDTCNT2  register values based on symbolic constants  */

/*  WDTCNT2  field values  */

	#define WDTIM_WDTCNT2_CNT_OF(x)	      ((Uint16)(x))
	#define WDTIM_WDTCNT2_CNT_DEFAULT		WDTIM_WDTCNT2_CNT_OF(0x0000u)


#define WDTIM_WDTCNT2_RMK(cnt)\
 ((Uint16) ( \
  ( WDTIM_FMK(WDTCNT2,CNT,cnt))\
)\
 )

#define WDTIM_WDTCNT2_RMKS(cnt_sym)\
 ((Uint16) ( \
  ( WDTIM_FMKS(WDTCNT2,CNT,cnt_sym))\
)\
 )

/*  Default WDTCNT2  register value  */

/* ============================================================== */
 /* Make WDTCNT3 register values based on symbolic constants  */

/*  WDTCNT3 field values  */

	#define WDTIM_WDTCNT3_CNT_OF(x)		((Uint16)(x))
	#define WDTIM_WDTCNT3_CNT_DEFAULT		WDTIM_WDTCNT3_CNT_OF(0x0000u)


#define WDTIM_WDTCNT3_RMK(cnt)\
 ((Uint16) ( \
  ( WDTIM_FMK(WDTCNT3,CNT,cnt))\
)\
 )

#define WDTIM_WDTCNT3_RMKS(cnt_sym)\
 ((Uint16) ( \
  ( WDTIM_FMKS(WDTCNT3,CNT,cnt_sym))\
)\
 )

/*  Default WDTCNT3 register value  */

/* ============================================================== */
 /* Make WDTCNT4 register values based on symbolic constants  */

/*  WDTCNT4 field values  */

	#define WDTIM_WDTCNT4_CNT_OF(x)	      ((Uint16)(x))
	#define WDTIM_WDTCNT4_CNT_DEFAULT		WDTIM_WDTCNT4_CNT_OF(0x0000u)


#define WDTIM_WDTCNT4_RMK(cnt)\
 ((Uint16) ( \
  ( WDTIM_FMK(WDTCNT4,CNT,cnt))\
)\
 )

#define WDTIM_WDTCNT4_RMKS(cnt_sym)\
 ((Uint16) ( \
  ( WDTIM_FMKS(WDTCNT4,CNT,cnt_sym))\
)\
 )

/*  Default WDTCNT4 register value  */

/* ============================================================== */
 /* Make WDTCTL1 register values based on symbolic constants  */

/*  WDTCTL1 field values  */

	#define WDTIM_WDTCTL1_TIEN_NOT_GATED			(000000u) 
	#define WDTIM_WDTCTL1_TIEN_GATED_BY_TINP			(0x0001u) 
	#define WDTIM_WDTCTL1_TIEN_DEFAULT		WDTIM_WDTCTL1_TIEN_NOT_GATED 

	#define WDTIM_WDTCTL1_CLKSRC_VBUS				(000000u) 
	#define WDTIM_WDTCTL1_CLKSRC_INPUT_PIN			(0x0001u) 
	#define WDTIM_WDTCTL1_CLKSRC_DEFAULT		WDTIM_WDTCTL1_CLKSRC_VBUS 

	#define WDTIM_WDTCTL1_ENAMODE_DISABLED			(000000u) 
	#define WDTIM_WDTCTL1_ENAMODE_ONCE			(0x0001u) 
	#define WDTIM_WDTCTL1_ENAMODE_CONTINUOUS			(0x0002u) 
	#define WDTIM_WDTCTL1_ENAMODE_DEFAULT		WDTIM_WDTCTL1_ENAMODE_DISABLED 

	#define WDTIM_WDTCTL1_PWID_INACTIVE_1CYCLE		(000000u) 
	#define WDTIM_WDTCTL1_PWID_INACTIVE_2CYCLES		(0x0001u) 
	#define WDTIM_WDTCTL1_PWID_INACTIVE_3CYCLES		(0x0002u) 
	#define WDTIM_WDTCTL1_PWID_INACTIVE_4CYCLES		(0x0003u) 
	#define WDTIM_WDTCTL1_PWID_DEFAULT		WDTIM_WDTCTL1_PWID_INACTIVE_1CYCLE 

	#define WDTIM_WDTCTL1_CP_CLOCK_MODE			(0x0001u) 
	#define WDTIM_WDTCTL1_CP_PULSE_MODE			(000000u) 
	#define WDTIM_WDTCTL1_CP_DEFAULT			WDTIM_WDTCTL1_CP_PULSE_MODE 

	#define WDTIM_WDTCTL1_INVIN_INVERT_OUTPUT			(0x0001u) 
	#define WDTIM_WDTCTL1_INVIN_DONT_INVERT_OUTPUT		(000000u) 
	#define WDTIM_WDTCTL1_INVIN_DEFAULT		WDTIM_WDTCTL1_INVIN_DONT_INVERT_OUTPUT 

	#define WDTIM_WDTCTL1_INVOUT_INVERT_OUTPUT		(0x0001u) 
	#define WDTIM_WDTCTL1_INVOUT_DONT_INVERT_OUTPUT		(000000u) 
	#define WDTIM_WDTCTL1_INVOUT_DEFAULT		WDTIM_WDTCTL1_INVOUT_DONT_INVERT_OUTPUT 

	#define WDTIM_WDTCTL1_TSTAT_HIGH				(0x0001u) 
	#define WDTIM_WDTCTL1_TSTAT_LOW				(000000u) 
 
#define WDTIM_WDTCTL1_RMK(tien,clksrc,enamode,pwid,cp,invin,invout)\
 ((Uint16) ( \
  ( WDTIM_FMK(WDTCTL1,TIEN,tien))|\
  ( WDTIM_FMK(WDTCTL1,CLKSRC,clksrc))|\
  ( WDTIM_FMK(WDTCTL1,ENAMODE,enamode))|\
  ( WDTIM_FMK(WDTCTL1,PWID,pwid))|\
  ( WDTIM_FMK(WDTCTL1,CP,cp))|\
  ( WDTIM_FMK(WDTCTL1,INVIN,invin))|\
  ( WDTIM_FMK(WDTCTL1,INVOUT,invout))\
)\
 ) 
 
#define WDTIM_WDTCTL1_RMKS(tien_sym,clksrc_sym,enamode_sym,pwid_sym,cp_sym,invin_sym,invout_sym)\
 ((Uint16) ( \
  ( WDTIM_FMKS(WDTCTL1,TIEN,tien_sym))|\
  ( WDTIM_FMKS(WDTCTL1,CLKSRC,clksrc_sym))|\
  ( WDTIM_FMKS(WDTCTL1,ENAMODE,enamode_sym))|\
  ( WDTIM_FMKS(WDTCTL1,PWID,pwid_sym))|\
  ( WDTIM_FMKS(WDTCTL1,CP,cp_sym))|\
  ( WDTIM_FMKS(WDTCTL1,INVIN,invin_sym))|\
  ( WDTIM_FMKS(WDTCTL1,INVOUT,invout_sym))\
)\
 ) 

/*  Default WDTCTL1 register value  */

/* ============================================================== */
 /* Make WDTCTL2 register values based on symbolic constants  */

/*  WDTCTL2 field values  */


	#define WDTIM_WDTCTL2_TIEN_NOT_GATED			(000000u) 
	#define WDTIM_WDTCTL2_TIEN_GATED_BY_TINP			(0x0001u) 
	#define WDTIM_WDTCTL2_TIEN_DEFAULT		WDTIM_WDTCTL2_TIEN_NOT_GATED 
 
	#define WDTIM_WDTCTL2_CLKSRC_VBUS				(000000u) 
	#define WDTIM_WDTCTL2_CLKSRC_INPUT_PIN			(0x0001u) 
	#define WDTIM_WDTCTL2_CLKSRC_DEFAULT		WDTIM_WDTCTL2_CLKSRC_VBUS 
 
	#define WDTIM_WDTCTL2_ENAMODE_DISABLED			(000000u) 
	#define WDTIM_WDTCTL2_ENAMODE_ONCE			(0x0001u) 
	#define WDTIM_WDTCTL2_ENAMODE_CONTINUOUS			(0x0002u) 
	#define WDTIM_WDTCTL2_ENAMODE_DEFAULT		WDTIM_WDTCTL2_ENAMODE_DISABLED 
 
	#define WDTIM_WDTCTL2_PWID_INACTIVE_1CYCLE		(000000u) 
	#define WDTIM_WDTCTL2_PWID_INACTIVE_2CYCLES		(0x0001u) 
	#define WDTIM_WDTCTL2_PWID_INACTIVE_3CYCLES		(0x0002u) 
	#define WDTIM_WDTCTL2_PWID_INACTIVE_4CYCLES		(0x0003u) 
	#define WDTIM_WDTCTL2_PWID_DEFAULT		WDTIM_WDTCTL2_PWID_INACTIVE_1CYCLE 
 
	#define WDTIM_WDTCTL2_CP_CLOCK_MODE			(0x0001u) 
	#define WDTIM_WDTCTL2_CP_PULSE_MODE			(000000u) 
	#define WDTIM_WDTCTL2_CP_DEFAULT			WDTIM_WDTCTL2_CP_PULSE_MODE 
 
	#define WDTIM_WDTCTL2_INVIN_INVERT_OUTPUT			(0x0001u) 
	#define WDTIM_WDTCTL2_INVIN_DONT_INVERT_OUTPUT		(000000u) 
	#define WDTIM_WDTCTL2_INVIN_DEFAULT		WDTIM_WDTCTL2_INVIN_DONT_INVERT_OUTPUT 
 
	#define WDTIM_WDTCTL2_INVOUT_INVERT_OUTPUT		(0x0001u) 
	#define WDTIM_WDTCTL2_INVOUT_DONT_INVERT_OUTPUT		(000000u) 
	#define WDTIM_WDTCTL2_INVOUT_DEFAULT		WDTIM_WDTCTL2_INVOUT_DONT_INVERT_OUTPUT 
 
	#define WDTIM_WDTCTL2_TSTAT_HIGH				(0x0001u) 
	#define WDTIM_WDTCTL2_TSTAT_LOW				(000000u) 
 
 
#define WDTIM_WDTCTL2_RMK(tien,clksrc,enamode,pwid,cp,invin,invout)\
 ((Uint16) ( \
  ( WDTIM_FMK(WDTCTL2,TIEN,tien))|\
  ( WDTIM_FMK(WDTCTL2,CLKSRC,clksrc))|\
  ( WDTIM_FMK(WDTCTL2,ENAMODE,enamode))|\
  ( WDTIM_FMK(WDTCTL2,PWID,pwid))|\
  ( WDTIM_FMK(WDTCTL2,CP,cp))|\
  ( WDTIM_FMK(WDTCTL2,INVIN,invin))|\
  ( WDTIM_FMK(WDTCTL2,INVOUT,invout))\
)\
 ) 
 
#define WDTIM_WDTCTL2_RMKS(tien_sym,clksrc_sym,enamode_sym,pwid_sym,cp_sym,invin_sym,invout_sym)\
 ((Uint16) ( \
  ( WDTIM_FMKS(WDTCTL2,TIEN,tien_sym))|\
  ( WDTIM_FMKS(WDTCTL2,CLKSRC,clksrc_sym))|\
  ( WDTIM_FMKS(WDTCTL2,ENAMODE,enamode_sym))|\
  ( WDTIM_FMKS(WDTCTL2,PWID,pwid_sym))|\
  ( WDTIM_FMKS(WDTCTL2,CP,cp_sym))|\
  ( WDTIM_FMKS(WDTCTL2,INVIN,invin_sym))|\
  ( WDTIM_FMKS(WDTCTL2,INVOUT,invout_sym))\
)\
 ) 


/*  Default WDTCTL2 register value  */

/* ============================================================== */
 /* Make WDTEMU register values based on symbolic constants  */

/*  WDTEMU field values  */

	#define WDTIM_WDTEMU_FREE_ON  		(000000u) 
	#define WDTIM_WDTEMU_FREE_OFF			(000001u) 
    #define WDTIM_WDTEMU_FREE_DEFAULT     WDTIM_WDTEMU_FREE_ON 
          
    #define WDTIM_WDTEMU_SOFT_ON  		(000000u) 
	#define WDTIM_WDTEMU_SOFT_OFF			(000001u) 
    #define WDTIM_WDTEMU_SOFT_DEFAULT     WDTIM_WDTEMU_SOFT_ON 
         

/*  Default WDTEMU register value  */



/* ============================================================== */
 /* Make WDTGPEN register values based on symbolic constants  */

/*  WDTGPEN field values  */

	#define WDTIM_WDTGPEN_TOUT1EN_TIMER_OUTPUT		(000000u) 
	#define WDTIM_WDTGPEN_TOUT1EN_GPIO_PIN			(0x0001u) 
	#define WDTIM_WDTGPEN_TOUT1EN_DEFAULT		    WDTIM_WDTGPEN_TOUT1EN_TIMER_OUTPUT 
 
	#define WDTIM_WDTGPEN_TIN1EN_TIMER_INPUT			(000000u) 
	#define WDTIM_WDTGPEN_TIN1EN_GPIO_PIN			    (0x0001u) 
	#define WDTIM_WDTGPEN_TIN1EN_DEFAULT		    WDTIM_WDTGPEN_TIN1EN_TIMER_INPUT 
 
 
#define WDTIM_WDTGPEN_RMK(tout1en,tin1en)\
 ((Uint16) ( \
  ( WDTIM_FMK(WDTGPEN,TOUT1EN,tout1en))|\
  ( WDTIM_FMK(WDTGPEN,TIN1EN,tin1en))\
)\
 ) 
 
#define WDTIM_WDTGPEN_RMKS(tout1en_sym,tin1en_sym)\
 ((Uint16) ( \
  ( WDTIM_FMKS(WDTGPEN,TOUT1EN,tout1en_sym))|\
  ( WDTIM_FMKS(WDTGPEN,TIN1EN,tin1en_sym))\
)\
 ) 


/*  Default WDTGPEN register value  */

/* ============================================================== */
 /* Make WDTGCTL1 register values based on symbolic constants  */

/*  WDTGCTL1 field values  */


	#define WDTIM_WDTGCTL1_TDDR34_OF(x)		      ((Uint16)(x))
	#define WDTIM_WDTGCTL1_TDDR34_DEFAULT		WDTIM_WDTGCTL1_TDDR34_OF(0x0000u)

	#define WDTIM_WDTGCTL1_PSC34_OF(x)			((Uint16)(x))
	#define WDTIM_WDTGCTL1_PSC34_DEFAULT		WDTIM_WDTGCTL1_PSC34_OF(0x0000u)

	#define WDTIM_WDTGCTL1_TIMMODE_64BIT_GPTIM	      (0x0000u)
	#define WDTIM_WDTGCTL1_TIMMODE_64BIT_WDTIM		(0x0002u)
	#define WDTIM_WDTGCTL1_TIMMODE_32BIT_DUAL			(0x0001u)
	#define WDTIM_WDTGCTL1_TIMMODE_32BIT_CHAINED		(0x0003u)
	#define WDTIM_WDTGCTL1_TIMMODE_DEFAULT		WDTIM_WDTGCTL1_TIMMODE_64BIT_GPTIM

	#define WDTIM_WDTGCTL1_TIM34RS_IN_RESET			(000000u)
	#define WDTIM_WDTGCTL1_TIM34RS_NOT_IN_RESET			(0x0001u)
	#define WDTIM_WDTGCTL1_TIM34RS_DEFAULT		WDTIM_WDTGCTL1_TIM34RS_IN_RESET

	#define WDTIM_WDTGCTL1_TIM12RS_IN_RESET			(000000u)
	#define WDTIM_WDTGCTL1_TIM12RS_NOT_IN_RESET			(0x0001u)
	#define WDTIM_WDTGCTL1_TIM12RS_DEFAULT		WDTIM_WDTGCTL1_TIM12RS_IN_RESET


#define WDTIM_WDTGCTL1_RMK(tddr34,psc34,timmode,tim34rs,tim12rs)\
 ((Uint16) ( \
  ( WDTIM_FMK(WDTGCTL1,TDDR34,tddr34))|\
  ( WDTIM_FMK(WDTGCTL1,PSC34,psc34))|\
  ( WDTIM_FMK(WDTGCTL1,TIMMODE,timmode))|\
  ( WDTIM_FMK(WDTGCTL1,TIM34RS,tim34rs))|\
  ( WDTIM_FMK(WDTGCTL1,TIM12RS,tim12rs))\
)\
 )

#define WDTIM_WDTGCTL1_RMKS(tddr34_sym,psc34_sym,timmode_sym,tim34rs_sym,tim12rs_sym)\
 ((Uint16) ( \
  ( WDTIM_FMKS(WDTGCTL1,TDDR34,tddr34_sym))|\
  ( WDTIM_FMKS(WDTGCTL1,PSC34,psc34_sym))|\
  ( WDTIM_FMKS(WDTGCTL1,TIMMODE,timmode_sym))|\
  ( WDTIM_FMKS(WDTGCTL1,TIM34RS,tim34rs_sym))|\
  ( WDTIM_FMKS(WDTGCTL1,TIM12RS,tim12rs_sym))\
)\
 )

/*  Default WDTGCTL1 register value  */

/* ============================================================== */
 /* Make WDTGPDAT register values based on symbolic constants  */

/*  WDTGPDAT field values  */

	#define WDTIM_WDTGPDAT_TOUT1DAT_HIGH			(0x0001u) 
	#define WDTIM_WDTGPDAT_TOUT1DAT_LOW			(000000u) 
	#define WDTIM_WDTGPDAT_TOUT1DAT_DEFAULT		WDTIM_WDTGPDAT_TOUT1DAT_LOW 
 
	#define WDTIM_WDTGPDAT_TIN1DAT_HIGH			(0x0001u) 
	#define WDTIM_WDTGPDAT_TIN1DAT_LOW			(000000u) 
	#define WDTIM_WDTGPDAT_TIN1DAT_DEFAULT		WDTIM_WDTGPDAT_TIN1DAT_LOW 
 
#define WDTIM_WDTGPDAT_RMK(tout1dat,tin1dat)\
 ((Uint16) ( \
  ( WDTIM_FMK(WDTGPDAT,TOUT1DAT,tout1dat))|\
  ( WDTIM_FMK(WDTGPDAT,TIN1DAT,tin1dat))\
)\
 ) 
 
#define WDTIM_WDTGPDAT_RMKS(tout1dat_sym,tin1dat_sym)\
 ((Uint16) ( \
  ( WDTIM_FMKS(WDTGPDAT,TOUT1DAT,tout1dat_sym))|\
  ( WDTIM_FMKS(WDTGPDAT,TIN1DAT,tin1dat_sym))\
)\
 ) 


/*  Default WDTGPDAT register value  */

/* ============================================================== */
 /* Make WDTGPDIR register values based on symbolic constants  */

/*  WDTGPDIR field values  */


	
	#define WDTIM_WDTGPDIR_TOUT1DIR_GPIO_INPUT			(000000u) 
	#define WDTIM_WDTGPDIR_TOUT1DIR_GPIO_OUTPUT			(0x0001u) 
	#define WDTIM_WDTGPDIR_TOUT1DIR_DEFAULT			WDTIM_WDTGPDIR_TOUT1DIR_GPIO_INPUT 
 
	#define WDTIM_WDTGPDIR_TIN1DIR_GPIO_INPUT				(000000u) 
	#define WDTIM_WDTGPDIR_TIN1DIR_GPIO_OUTPUT			(0x0001u) 
	#define WDTIM_WDTGPDIR_TIN1DIR_DEFAULT			WDTIM_WDTGPDIR_TIN1DIR_GPIO_INPUT 
 
#define WDTIM_WDTGPDIR_RMK(tout1dir,tin1dir)\
 ((Uint16) ( \
  ( WDTIM_FMK(WDTGPDIR,TOUT1DIR,tout1dir))|\
  ( WDTIM_FMK(WDTGPDIR,TIN1DIR,tin1dir))\
)\
 ) 
 
#define WDTIM_WDTGPDIR_RMKS(tout1dir_sym,tin1dir_sym)\
 ((Uint16) ( \
  ( WDTIM_FMKS(WDTGPDIR,TOUT1DIR,tout1dir_sym))|\
  ( WDTIM_FMKS(WDTGPDIR,TIN1DIR,tin1dir_sym))\
)\
 ) 


/*  Default WDTGPDIR register value  */

/* ============================================================== */
 /* Make WDTGPINT register values based on symbolic constants  */

/*  WDTGPINT field values  */

	
    #define WDTIM_WDTGPINT_TIN1INV_DISABLE		(0x0000u)  
	#define WDTIM_WDTGPINT_TIN1INV_ENABLE			(000001u) 
	#define WDTIM_WDTGPINT_TIN1INV_DEFAULT		WDTIM_WDTGPINT_TIN1INV_DISABLE
 
	#define WDTIM_WDTGPINT_TIN1INT_DISABLE		(0x0000u)  
	#define WDTIM_WDTGPINT_TIN1INT_ENABLE			(000001u) 
	#define WDTIM_WDTGPINT_TIN1INT_DEFAULT		WDTIM_WDTGPINT_TIN1INT_DISABLE
	
	
#define WDTIM_WDTGPINT_RMK(tin1inv,tin1int)\
 ((Uint16) ( \
  ( WDTIM_FMK(WDTGPINT,TIN1INV,tin1inv))|\
  ( WDTIM_FMK(WDTGPINT,TIN1INT,tin1int))\
)\
 ) 
 
#define WDTIM_WDTGPINT_RMKS(tin1inv_sym,tin1int_sym)\
 ((Uint16) ( \
  ( WDTIM_FMKS(WDTGPINT,TIN1INV,tin1inv_sym))|\
  ( WDTIM_FMKS(WDTGPINT,TIN1INT,tin1int_sym))\
)\
 ) 


/*  Default WDTGPINT register value  */

/* ============================================================== */
/* Make WDTPID1 register values based on symbolic constants  */

/*  WDTPID1 field values  */

	#define WDTIM_WDTPID1_CLASS_CLASS			(000000u)
	#define WDTIM_WDTPID1_CLASS_DEFAULT		WDTIM_WDTPID1_CLASS_CLASS

	#define WDTIM_WDTPID1_REVISION_REVISION			(000000u)
	#define WDTIM_WDTPID1_REVISION_DEFAULT		WDTIM_WDTPID1_REVISION_REVISION


/*  Default WDTPID1 register value  */

/* ============================================================== */
 /* Make WDTPID2 register values based on symbolic constants  */

/*  WDTPID2 field values  */

	#define WDTIM_WDTPID2_TYPE_TYPE			(000000u)
	#define WDTIM_WDTPID2_TYPE_DEFAULT		WDTIM_WDTPID2_TYPE_TYPE


/*  Default WDTPID2 register value  */

/* ============================================================== */
 /* Make WDTPRD1 register values based on symbolic constants  */

/*  WDTPRD1 field values  */

	#define WDTIM_WDTPRD1_PRD_OF(x)	      ((Uint16)(x))
	#define WDTIM_WDTPRD1_PRD_DEFAULT		WDTIM_WDTPRD1_PRD_OF(0x0000u)


#define WDTIM_WDTPRD1_RMK(prd)\
 ((Uint16) ( \
  ( WDTIM_FMK(WDTPRD1,PRD,prd))\
)\
 )

#define WDTIM_WDTPRD1_RMKS(prd_sym)\
 ((Uint16) ( \
  ( WDTIM_FMKS(WDTPRD1,PRD,prd_sym))\
)\
 )

/*  Default WDTPRD1 register value  */

/* ============================================================== */
 /* Make WDTPRD2 register values based on symbolic constants  */

/*  WDTPRD2 field values  */

	#define WDTIM_WDTPRD2_PRD_OF(x)		((Uint16)(x))
	#define WDTIM_WDTPRD2_PRD_DEFAULT		WDTIM_WDTPRD2_PRD_OF(0x0000u)


#define WDTIM_WDTPRD2_RMK(prd)\
 ((Uint16) ( \
  ( WDTIM_FMK(WDTPRD2,PRD,prd))\
)\
 )

#define WDTIM_WDTPRD2_RMKS(prd_sym)\
 ((Uint16) ( \
  ( WDTIM_FMKS(WDTPRD2,PRD,prd_sym))\
)\
 )

/*  Default WDTPRD2 register value  */

/* ============================================================== */
 /* Make WDTPRD3 register values based on symbolic constants  */

/*  WDTPRD3 field values  */

	#define WDTIM_WDTPRD3_PRD_OF(x)		((Uint16)(x))
	#define WDTIM_WDTPRD3_PRD_DEFAULT		WDTIM_WDTPRD3_PRD_OF(0x0000u)


#define WDTIM_WDTPRD3_RMK(prd)\
 ((Uint16) ( \
  ( WDTIM_FMK(WDTPRD3,PRD,prd))\
)\
 )

#define WDTIM_WDTPRD3_RMKS(prd_sym)\
 ((Uint16) ( \
  ( WDTIM_FMKS(WDTPRD3,PRD,prd_sym))\
)\
 )

/*  Default WDTPRD3 register value  */

/* ============================================================== */
 /* Make WDTPRD4 register values based on symbolic constants  */

/*  WDTPRD4 field values  */

	#define WDTIM_WDTPRD4_PRD_OF(x)		((Uint16)(x))
	#define WDTIM_WDTPRD4_PRD_DEFAULT		WDTIM_WDTPRD4_PRD_OF(0x0000u)


#define WDTIM_WDTPRD4_RMK(prd)\
 ((Uint16) ( \
  ( WDTIM_FMK(WDTPRD4,PRD,prd))\
)\
 )

#define WDTIM_WDTPRD4_RMKS(prd_sym)\
 ((Uint16) ( \
  ( WDTIM_FMKS(WDTPRD4,PRD,prd_sym))\
)\
 )

/*  Default WDTPRD4 register value  */

/* ============================================================== */
 /* Make WDTWCTL1 register values based on symbolic constants  */

/*  WDTWCTL1 field values  */

	#define WDTIM_WDTWCTL1_WDFLAG_TIMEOUT			(0x0001u)
	#define WDTIM_WDTWCTL1_WDFLAG_NO_TIMEOUT		(000000u)
	#define WDTIM_WDTWCTL1_WDFLAG_DEFAULT			WDTIM_WDTWCTL1_WDFLAG_NO_TIMEOUT

	#define WDTIM_WDTWCTL1_WDEN_ENABLE			(0x0001u)
	#define WDTIM_WDTWCTL1_WDEN_DISABLE			(000000u)
	#define WDTIM_WDTWCTL1_WDEN_DEFAULT			WDTIM_WDTWCTL1_WDEN_DISABLE

	#define WDTIM_WDTWCTL1_WDIKEY_NO_IDLE			(0x0000u)
	#define WDTIM_WDTWCTL1_WDIKEY_GO_IDLE_START		(000001u)
	#define WDTIM_WDTWCTL1_WDIKEY_GO_IDLE			(0x0002u)
	#define WDTIM_WDTWCTL1_WDIKEY_DEFAULT			WDTIM_WDTWCTL1_WDIKEY_GO_IDLE_START


#define WDTIM_WDTWCTL1_RMK(wdflag,wden,wdikey)\
 ((Uint16) ( \
  ( WDTIM_FMK(WDTWCTL1,WDFLAG,wdflag))|\
  ( WDTIM_FMK(WDTWCTL1,WDEN,wden))|\
  ( WDTIM_FMK(WDTWCTL1,WDIKEY,wdikey))\
)\
 )

#define WDTIM_WDTWCTL1_RMKS(wdflag_sym,wden_sym,wdikey_sym)\
 ((Uint16) ( \
  ( WDTIM_FMKS(WDTWCTL1,WDFLAG,wdflag_sym))|\
  ( WDTIM_FMKS(WDTWCTL1,WDEN,wden_sym))|\
  ( WDTIM_FMKS(WDTWCTL1,WDIKEY,wdikey_sym))\
)\
 )

/*  Default WDTWCTL1 register value  */

/* ============================================================== */
 /* Make WDTWCTL2 register values based on symbolic constants  */

/*  WDTWCTL2 field values  */

	#define WDTIM_WDTWCTL2_WDKEY_PREACTIVE          (0xA5C6u)
	#define WDTIM_WDTWCTL2_WDKEY_ACTIVE             (0xDA7Eu)
	#define WDTIM_WDTWCTL2_WDKEY_DEFAULT		(0x0000u)


#define WDTIM_WDTWCTL2_RMK(wdkey)\
 ((Uint16) ( \
  ( WDTIM_FMK(WDTWCTL2,WDKEY,wdkey))\
)\
 )

#define WDTIM_WDTWCTL2_RMKS(wdkey_sym)\
 ((Uint16) ( \
  ( WDTIM_FMKS(WDTWCTL2,WDKEY,wdkey_sym))\
)\
 )

/*  Default WDTWCTL2 register value  */
/*************************************************\
 WDTIM global typedef declarations 
\*************************************************/

typedef struct {
	Uint16 wdtemu;
	Uint16 wdtgpint;
	Uint16 wdtgpen;
	Uint16 wdtgpdir;
	Uint16 wdtgpdat;
	Uint16 wdtprd1;
	Uint16 wdtprd2;
	Uint16 wdtprd3;
	Uint16 wdtprd4;
	Uint16 wdtctl1;
	Uint16 wdtctl2;
	Uint16 wdtgctl1;
	Uint16 wdtwctl1;
	Uint16 wdtwctl2;
} WDTIM_Config;


typedef struct {
       Uint16 Private;
} *WDTIM_Handle;

/*************************************************\
* WDTIM global variable declarations
\*************************************************/
#define _WDT_Obj        (&(CSL_WDTIM_DATA))

/*************************************************\
* WDTIM global function declarations
\*************************************************/

#define WDTIM_init64(h,gptgctl,dt12ctl,prdHigh,prdLow)\
  GPT_init64((GPT_Handle)(h),gptgctl,dt12ctl,prdHigh,prdLow)

#define WDTIM_getPID(h,type,class,revision)\
  GPT_getPID((GPT_Handle)(h), (Uint16 *)(type), (Uint16 *)(class),\
             (Uint16 *)(revision))

#define WDTIM_getCnt(h,hi32, lo32)\
  GPT_getCnt((GPT_Handle)(h),(Uint32*) hi32, (Uint32*) lo32)

#define WDTIM_start(h)\
  GPT_start((GPT_Handle)(h));

#define WDTIM_stop(h)\
  GPT_stop((GPT_Handle)(h));

CSLAPI void WDTIM_config(WDTIM_Handle hWdt, WDTIM_Config *myConfig);
CSLAPI void WDTIM_configArgs(WDTIM_Handle hWdt,Uint16 wdtemu,Uint16 wdtprd1,Uint16 wdtprd2,
        Uint16 wdtprd3,Uint16 wdtprd4,Uint16 wdtgpint,Uint16 wdtgpen,Uint16 wdtgpdir,Uint16
        wdtgpdat,Uint16 wdtctl1,Uint16 wdtctl2,Uint16 wdtgctl1,Uint16 wdtwctl1,Uint16 wdtwctl2);

/*************************************************\
* WDTIM inline function declarations
\*************************************************/

IDECL WDTIM_Handle WDTIM_open(void);
IDECL void WDTIM_close(WDTIM_Handle h);
IDECL void WDTIM_wdStart(WDTIM_Handle hWdt);
IDECL void WDTIM_service(WDTIM_Handle hWdt);


#ifdef USEDEFS


/*----------------------------------------------------------------------------*/
IDEF WDTIM_Handle WDTIM_open(void) {
  CSL_SYS_DATA.WdtAllocMask = 0x0001u;
  return (WDTIM_Handle)(&(CSL_WDTIM_DATA));
}
/*----------------------------------------------------------------------------*/
IDEF void WDTIM_close(WDTIM_Handle h) {
  CSL_SYS_DATA.WdtAllocMask = 0x0000u;
}
/*----------------------------------------------------------------------------*/
IDEF void WDTIM_wdStart(WDTIM_Handle hWdt) {
 int old_intm;
  ioport WDTIM_RegObj *regPtr =((CSL_WdtimDataObj *)(hWdt))->regs;

  old_intm = IRQ_globalDisable();

  regPtr->wdtwctl1 |= _WDTIM_WDTWCTL1_WDEN_MK(1);
  regPtr->wdtwctl2 = WDTIM_WDTWCTL2_WDKEY_PREACTIVE;
  regPtr->wdtwctl2 = WDTIM_WDTWCTL2_WDKEY_ACTIVE;  
  IRQ_globalRestore(old_intm);
}
/*----------------------------------------------------------------------------*/
IDEF void WDTIM_service(WDTIM_Handle hWdt) {
 int old_intm;
  ioport WDTIM_RegObj *regPtr =((CSL_WdtimDataObj *)(hWdt))->regs;

  old_intm = IRQ_globalDisable();

 
  regPtr->wdtwctl2 = WDTIM_WDTWCTL2_WDKEY_PREACTIVE;
  regPtr->wdtwctl2 = WDTIM_WDTWCTL2_WDKEY_ACTIVE;  
  IRQ_globalRestore(old_intm);
}
/*----------------------------------------------------------------------------*/

#endif /*USEDEFS */

#elif (!(_WDTIM_MOD))
	#error WDTIM Hal Module Not Supported on Specified Target
#endif  /* _WDTIMB_SUPPORT  */

#endif  /* _CSL_WDTIMB_H_  */

/******************************************************************************\
*     
*      End of csl_wdtimB.h 
*
\******************************************************************************/
