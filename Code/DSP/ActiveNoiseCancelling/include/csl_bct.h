/****************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved 
*------------------------------------------------------------------------------
* MODULE NAME... BCT
* FILENAME...... csl_bct.h
* DATE CREATED.. Tue Feb 19 12:02:53 2002
* PROJECT....... Chip Support Library
* COMPONENT..... Service Layer
* PREREQUISITS.. 
*------------------------------------------------------------------------------
*
* HISTORY:
*	 Created:		Tue Feb 19 12:02:53 2002 (Automatic generation)
*	 Modified:	    03/21/2003 Modified register names and fields
*                       as per SPRU618A. 
*
*	 Modified:	    06/09/2004 Fixed C++ compiler errors 
*------------------------------------------------------------------------------
* DESCRIPTION: CSL Service Layer interface for the BCT module 
*
\*************************************************************************/

#ifndef _CSL_BCT_H_
#define _CSL_BCT_H_

#include <csl.h>
#include <csl_std.h>
#include <csl_chiphal.h>

#if ((_BCT_SUPPORT) & (BIOS_CNT))

#include <csl_bcthal.h>
#include <csl_gpt.h>

/*----------------------------------------------------------------*\
*	 BCT scope and inline control macros 			
\*----------------------------------------------------------------*/

#ifdef __cplusplus
#define CSLAPI extern "C"
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _BCT_MOD_
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
* BCT global macro declarations
\****************************************/

/* error codes */
#define BCT_ERR_MAJOR		   (ERR_BASE_BCT) 
#define BCT_ERR_ALLOC		   (0x00000000) 
#define BCT_ERR_INVALID_HANDLE  (0x00000001) 


#define _BCT_Obj                (CSL_BCT_DATA)

/* ============================================================== */
 /* Make BCTCLK register values based on symbolic constants  */

/*  BCTCLK field values  */

	#define BCT_BCTCLK_CLKDIV_DIV0	       (0x0000u) 
	#define BCT_BCTCLK_CLKDIV_DIV1	       (0x0001u) 
	#define BCT_BCTCLK_CLKDIV_DIV2	       (0x0002u) 
	#define BCT_BCTCLK_CLKDIV_DIV4	       (0x0004u) 
	#define BCT_BCTCLK_CLKDIV_DIV8	       (0x0008u)
	#define BCT_BCTCLK_CLKDIV_DEFAULT      BCT_BCTCLK_CLKDIV_DIV0


/*  Default BCTCLK register value  */

/* ============================================================== */
 /* Make BCTCNT1 register values based on symbolic constants  */

/*  BCTCNT1 field values  */

	#define BCT_BCTCNT1_CNT_OF(x)			((Uint16)(x))
	#define BCT_BCTCNT1_CNT_DEFAULT		BCT_BCTCNT1_CNT_OF(0x0000u)


#define BCT_BCTCNT1_RMK(cnt)\
 ((Uint16) ( \
  ( BCT_FMK(BCTCNT1,CNT,cnt))\
)\
 )

#define BCT_BCTCNT1_RMKS(cnt_sym)\
 ((Uint16) ( \
  ( BCT_FMKS(BCTCNT1,CNT,cnt_sym))\
)\
 )

/*  Default BCTCNT1 register value  */

/* ============================================================== */
 /* Make BCTCNT2 register values based on symbolic constants  */

/*  BCTCNT2 field values  */

	#define BCT_BCTCNT2_CNT_OF(x)			((Uint16)(x))
	#define BCT_BCTCNT2_CNT_DEFAULT		BCT_BCTCNT2_CNT_OF(0x0000u)


#define BCT_BCTCNT2_RMK(cnt)\
 ((Uint16) ( \
  ( BCT_FMK(BCTCNT2,CNT,cnt))\
)\
 )

#define BCT_BCTCNT2_RMKS(cnt_sym)\
 ((Uint16) ( \
  ( BCT_FMKS(BCTCNT2,CNT,cnt_sym))\
)\
 )

/*  Default BCTCNT2 register value  */

/* ============================================================== */
 /* Make BCTCNT3 register values based on symbolic constants  */

/*  BCTCNT3 field values  */

	#define BCT_BCTCNT3_CNT_OF(x)			((Uint16)(x))
	#define BCT_BCTCNT3_CNT_DEFAULT		BCT_BCTCNT3_CNT_OF(0x0000u)


#define BCT_BCTCNT3_RMK(cnt)\
 ((Uint16) ( \
  ( BCT_FMK(BCTCNT3,CNT,cnt))\
)\
 )

#define BCT_BCTCNT3_RMKS(cnt_sym)\
 ((Uint16) ( \
  ( BCT_FMKS(BCTCNT3,CNT,cnt_sym))\
)\
 )

/*  Default BCTCNT3 register value  */

/* ============================================================== */
 /* Make BCTCNT4 register values based on symbolic constants  */

/*  BCTCNT4 field values  */

	#define BCT_BCTCNT4_CNT_OF(x)			((Uint16)(x))
	#define BCT_BCTCNT4_CNT_DEFAULT		BCT_BCTCNT4_CNT_OF(0x0000u)

#define BCT_BCTCNT4_RMK(cnt)\
 ((Uint16) ( \
  ( BCT_FMK(BCTCNT4,CNT,cnt))\
)\
 )

#define BCT_BCTCNT4_RMKS(cnt_sym)\
 ((Uint16) ( \
  ( BCT_FMKS(BCTCNT4,CNT,cnt_sym))\
)\
 )

/*  Default BCTCNT4 register value  */

/* ============================================================== */
 /* Make BCTCTL1 register values based on symbolic constants  */

/*  BCTCTL1 field values  */

	#define BCT_BCTCTL1_TIEN_NOT_GATED			(000000u) 
	#define BCT_BCTCTL1_TIEN_GATED_BY_TINP			(0x0001u) 
	#define BCT_BCTCTL1_TIEN_DEFAULT		BCT_BCTCTL1_TIEN_NOT_GATED 

	#define BCT_BCTCTL1_CLKSRC_VBUS				(000000u) 
	#define BCT_BCTCTL1_CLKSRC_INPUT_PIN			(0x0001u) 
	#define BCT_BCTCTL1_CLKSRC_DEFAULT		BCT_BCTCTL1_CLKSRC_VBUS 

	#define BCT_BCTCTL1_ENAMODE_DISABLED			(000000u) 
	#define BCT_BCTCTL1_ENAMODE_ONCE			(0x0001u) 
	#define BCT_BCTCTL1_ENAMODE_CONTINUOUS			(0x0002u) 
	#define BCT_BCTCTL1_ENAMODE_DEFAULT		BCT_BCTCTL1_ENAMODE_DISABLED 

	#define BCT_BCTCTL1_PWID_INACTIVE_1CYCLE		(000000u) 
	#define BCT_BCTCTL1_PWID_INACTIVE_2CYCLES		(0x0001u) 
	#define BCT_BCTCTL1_PWID_INACTIVE_3CYCLES		(0x0002u) 
	#define BCT_BCTCTL1_PWID_INACTIVE_4CYCLES		(0x0003u) 
	#define BCT_BCTCTL1_PWID_DEFAULT		BCT_BCTCTL1_PWID_INACTIVE_1CYCLES 

	#define BCT_BCTCTL1_CP_CLOCK_MODE			(0x0001u) 
	#define BCT_BCTCTL1_CP_PULSE_MODE			(000000u) 
	#define BCT_BCTCTL1_CP_DEFAULT			BCT_BCTCTL1_CP_PULSE_MODE 

	#define BCT_BCTCTL1_INVIN_INVERT_OUTPUT			(0x0001u) 
	#define BCT_BCTCTL1_INVIN_DONT_INVERT_OUTPUT		(000000u) 
	#define BCT_BCTCTL1_INVIN_DEFAULT		BCT_BCTCTL1_INVIN_DONT_INVERT_OUTPUT 

	#define BCT_BCTCTL1_INVOUT_INVERT_OUTPUT		(0x0001u) 
	#define BCT_BCTCTL1_INVOUT_DONT_INVERT_OUTPUT		(000000u) 
	#define BCT_BCTCTL1_INVOUT_DEFAULT		BCT_BCTCTL1_INVOUT_DONT_INVERT_OUTPUT 

	#define BCT_BCTCTL1_TSTAT_HIGH				(0x0001u) 
	#define BCT_BCTCTL1_TSTAT_LOW				(000000u) 
 
#define BCT_BCTCTL1_RMK(tien,clksrc,enamode,pwid,cp,invin,invout)\
 ((Uint16) ( \
  ( BCT_FMK(BCTCTL1,TIEN,tien))|\
  ( BCT_FMK(BCTCTL1,CLKSRC,clksrc))|\
  ( BCT_FMK(BCTCTL1,ENAMODE,enamode))|\
  ( BCT_FMK(BCTCTL1,PWID,pwid))|\
  ( BCT_FMK(BCTCTL1,CP,cp))|\
  ( BCT_FMK(BCTCTL1,INVIN,invin))|\
  ( BCT_FMK(BCTCTL1,INVOUT,invout))\
)\
 ) 
 
#define BCT_BCTCTL1_RMKS(tien_sym,clksrc_sym,enamode_sym,pwid_sym,cp_sym,invin_sym,invout_sym)\
 ((Uint16) ( \
  ( BCT_FMKS(BCTCTL1,TIEN,tien_sym))|\
  ( BCT_FMKS(BCTCTL1,CLKSRC,clksrc_sym))|\
  ( BCT_FMKS(BCTCTL1,ENAMODE,enamode_sym))|\
  ( BCT_FMKS(BCTCTL1,PWID,pwid_sym))|\
  ( BCT_FMKS(BCTCTL1,CP,cp_sym))|\
  ( BCT_FMKS(BCTCTL1,INVIN,invin_sym))|\
  ( BCT_FMKS(BCTCTL1,INVOUT,invout_sym))\
)\
 ) 
 
/*  Default BCTCTL1 register value  */ 




/* ============================================================== */
 /* Make BCTCTL2 register values based on symbolic constants  */

/*  BCTCTL2 field values  */


/* ============================================================== */

	#define BCT_BCTCTL2_TIEN_NOT_GATED			(000000u) 
	#define BCT_BCTCTL2_TIEN_GATED_BY_TINP			(0x0001u) 
	#define BCT_BCTCTL2_TIEN_DEFAULT		BCT_BCTCTL2_TIEN_NOT_GATED 
 
	#define BCT_BCTCTL2_CLKSRC_VBUS				(000000u) 
	#define BCT_BCTCTL2_CLKSRC_INPUT_PIN			(0x0001u) 
	#define BCT_BCTCTL2_CLKSRC_DEFAULT		BCT_BCTCTL2_CLKSRC_VBUS 
 
	#define BCT_BCTCTL2_ENAMODE_DISABLED			(000000u) 
	#define BCT_BCTCTL2_ENAMODE_ONCE			(0x0001u) 
	#define BCT_BCTCTL2_ENAMODE_CONTINUOUS			(0x0002u) 
	#define BCT_BCTCTL2_ENAMODE_DEFAULT		BCT_BCTCTL2_ENAMODE_DISABLED 
 
	#define BCT_BCTCTL2_PWID_INACTIVE_1CYCLE		(000000u) 
	#define BCT_BCTCTL2_PWID_INACTIVE_2CYCLES		(0x0001u) 
	#define BCT_BCTCTL2_PWID_INACTIVE_3CYCLES		(0x0002u) 
	#define BCT_BCTCTL2_PWID_INACTIVE_4CYCLES		(0x0003u) 
	#define BCT_BCTCTL2_PWID_DEFAULT		BCT_BCTCTL2_PWID_INACTIVE_1CYCLE 
 
	#define BCT_BCTCTL2_CP_CLOCK_MODE			(0x0001u) 
	#define BCT_BCTCTL2_CP_PULSE_MODE			(000000u) 
	#define BCT_BCTCTL2_CP_DEFAULT			BCT_BCTCTL2_CP_PULSE_MODE 
 
	#define BCT_BCTCTL2_INVIN_INVERT_OUTPUT			(0x0001u) 
	#define BCT_BCTCTL2_INVIN_DONT_INVERT_OUTPUT		(000000u) 
	#define BCT_BCTCTL2_INVIN_DEFAULT		BCT_BCTCTL2_INVIN_DONT_INVERT_OUTPUT 
 
	#define BCT_BCTCTL2_INVOUT_INVERT_OUTPUT		(0x0001u) 
	#define BCT_BCTCTL2_INVOUT_DONT_INVERT_OUTPUT		(000000u) 
	#define BCT_BCTCTL2_INVOUT_DEFAULT		BCT_BCTCTL2_INVOUT_DONT_INVERT_OUTPUT 
 
	#define BCT_BCTCTL2_TSTAT_HIGH				(0x0001u) 
	#define BCT_BCTCTL2_TSTAT_LOW				(000000u) 
 
 
#define BCT_BCTCTL2_RMK(tien,clksrc,enamode,pwid,cp,invin,invout)\
 ((Uint16) ( \
  ( BCT_FMK(BCTCTL2,TIEN,tien))|\
  ( BCT_FMK(BCTCTL2,CLKSRC,clksrc))|\
  ( BCT_FMK(BCTCTL2,ENAMODE,enamode))|\
  ( BCT_FMK(BCTCTL2,PWID,pwid))|\
  ( BCT_FMK(BCTCTL2,CP,cp))|\
  ( BCT_FMK(BCTCTL2,INVIN,invin))|\
  ( BCT_FMK(BCTCTL2,INVOUT,invout))\
)\
 ) 
 
#define BCT_BCTCTL2_RMKS(tien_sym,clksrc_sym,enamode_sym,pwid_sym,cp_sym,invin_sym,invout_sym)\
 ((Uint16) ( \
  ( BCT_FMKS(BCTCTL2,TIEN,tien_sym))|\
  ( BCT_FMKS(BCTCTL2,CLKSRC,clksrc_sym))|\
  ( BCT_FMKS(BCTCTL2,ENAMODE,enamode_sym))|\
  ( BCT_FMKS(BCTCTL2,PWID,pwid_sym))|\
  ( BCT_FMKS(BCTCTL2,CP,cp_sym))|\
  ( BCT_FMKS(BCTCTL2,INVIN,invin_sym))|\
  ( BCT_FMKS(BCTCTL2,INVOUT,invout_sym))\
)\
 ) 
 
/*  Default BCTCTL2 register value  */ 
 
/* ============================================================== */ 
/* Make BCTEMU register values based on symbolic constants  */ 
 
/*  BCTEMU field values  */ 
 
	#define BCT_BCTEMU_FREE_ON  		(000000u) 
	#define BCT_BCTEMU_FREE_OFF			(000001u) 
    #define BCT_BCTEMU_FREE_DEFAULT     BCT_BCTEMU_FREE_ON 
          
    #define BCT_BCTEMU_SOFT_ON  		(000000u) 
	#define BCT_BCTEMU_SOFT_OFF			(000001u) 
    #define BCT_BCTEMU_SOFT_DEFAULT     BCT_BCTEMU_SOFT_ON 
         

/*  Default BCTEMU register value  */

/* ============================================================== */ 
/* Make BCTGPEN register values based on symbolic constants  */ 
 
/*  BCTGPEN field values  */ 
 
	#define BCT_BCTGPEN_TOUT1EN_TIMER_OUTPUT		(000000u) 
	#define BCT_BCTGPEN_TOUT1EN_GPIO_PIN			(0x0001u) 
	#define BCT_BCTGPEN_TOUT1EN_DEFAULT		    BCT_BCTGPEN_TOUT1EN_TIMER_OUTPUT 
 
	#define BCT_BCTGPEN_TIN1EN_TIMER_INPUT			(000000u) 
	#define BCT_BCTGPEN_TIN1EN_GPIO_PIN			    (0x0001u) 
	#define BCT_BCTGPEN_TIN1EN_DEFAULT		    BCT_BCTGPEN_TIN1EN_TIMER_INPUT 
 
 
#define BCT_BCTGPEN_RMK(tout1en,tin1en)\
 ((Uint16) ( \
  ( BCT_FMK(BCTGPEN,TOUT1EN,tout1en))|\
  ( BCT_FMK(BCTGPEN,TIN1EN,tin1en))\
)\
 ) 
 
#define BCT_BCTGPEN_RMKS(tout1en_sym,tin1en_sym)\
 ((Uint16) ( \
  ( BCT_FMKS(BCTGPEN,TOUT1EN,tout1en_sym))|\
  ( BCT_FMKS(BCTGPEN,TIN1EN,tin1en_sym))\
)\
 ) 
 
/*  Default BCTGPEN register value  */ 
 
 
/* ============================================================== */
 /* Make BCTGCTL1 register values based on symbolic constants  */

/*  BCTGCTL1 field values  */

	#define BCT_BCTGCTL1_TDDR34_OF(x)		((Uint16)(x))
	#define BCT_BCTGCTL1_TDDR34_DEFAULT		BCT_BCTGCTL1_TDDR34_OF(0)

	#define BCT_BCTGCTL1_PSC34_OF(x)		((Uint16)(x))
	#define BCT_BCTGCTL1_PSC34_DEFAULT		BCT_BCTGCTL1_PSC34_OF(0)

	#define BCT_BCTGCTL1_TIMMODE_64BIT_GPTIM			(000000u)
	#define BCT_BCTGCTL1_TIMMODE_32BIT_DUAL			(0x0001u)
	#define BCT_BCTGCTL1_TIMMODE_32BIT_CHAINED			(0x0003u)
	#define BCT_BCTGCTL1_TIMMODE_DEFAULT		BCT_BCTGCTL1_TIMMODE_64BIT_GPTIM

	#define BCT_BCTGCTL1_TIM34RS_IN_RESET			(000000u)
	#define BCT_BCTGCTL1_TIM34RS_NOT_IN_RESET			(0x0001u)
	#define BCT_BCTGCTL1_TIM34RS_DEFAULT		BCT_BCTGCTL1_TIM34RS_IN_RESET

	#define BCT_BCTGCTL1_TIM12RS_IN_RESET			(000000u)
	#define BCT_BCTGCTL1_TIM12RS_NOT_IN_RESET			(0x0001u)
	#define BCT_BCTGCTL1_TIM12RS_DEFAULT		BCT_BCTGCTL1_TIM12RS_IN_RESET


#define BCT_BCTGCTL1_RMK(psc34,timmode,tim34rs,tim12rs)\
 ((Uint16) ( \
  ( BCT_FMK(BCTGCTL1,PSC34,psc34))|\
  ( BCT_FMK(BCTGCTL1,TIMMODE,timmode))|\
  ( BCT_FMK(BCTGCTL1,TIM34RS,tim34rs))|\
  ( BCT_FMK(BCTGCTL1,TIM12RS,tim12rs))\
)\
 )

#define BCT_BCTGCTL1_RMKS(psc34_sym,timmode_sym,tim34rs_sym,tim12rs_sym)\
 ((Uint16) ( \
  ( BCT_FMKS(BCTGCTL1,PSC34,psc34_sym))|\
  ( BCT_FMKS(BCTGCTL1,TIMMODE,timmode_sym))|\
  ( BCT_FMKS(BCTGCTL1,TIM34RS,tim34rs_sym))|\
  ( BCT_FMKS(BCTGCTL1,TIM12RS,tim12rs_sym))\
)\
 )

/*  Default BCTGCTL1 register value  */

/* ============================================================== */

/* Make BCTGPDAT register values based on symbolic constants  */ 
 
/*  BCTGPDAT field values  */ 
 

	#define BCT_BCTGPDAT_TOUT1DAT_HIGH			(0x0001u) 
	#define BCT_BCTGPDAT_TOUT1DAT_LOW			(000000u) 
	#define BCT_BCTGPDAT_TOUT1DAT_DEFAULT		BCT_BCTGPDAT_TOUT1DAT_LOW 
 
	#define BCT_BCTGPDAT_TIN1DAT_HIGH			(0x0001u) 
	#define BCT_BCTGPDAT_TIN1DAT_LOW			(000000u) 
	#define BCT_BCTGPDAT_TIN1DAT_DEFAULT		BCT_BCTGPDAT_TIN1DAT_LOW 
 
#define BCT_BCTGPDAT_RMK(tout1dat,tin1dat)\
 ((Uint16) ( \
  ( BCT_FMK(BCTGPDAT,TOUT1DAT,tout1dat))|\
  ( BCT_FMK(BCTGPDAT,TIN1DAT,tin1dat))\
)\
 ) 
 
#define BCT_BCTGPDAT_RMKS(tout1dat_sym,tin1dat_sym)\
 ((Uint16) ( \
  ( BCT_FMKS(BCTGPDAT,TOUT1DAT,tout1dat_sym))|\
  ( BCT_FMKS(BCTGPDAT,TIN1DAT,tin1dat_sym))\
)\
 ) 


/*  Default BCTGPDAT register value  */

/* ============================================================== */

/* Make BCTGPDIR register values based on symbolic constants  */ 
 
/*  BCTGPDIR field values  */ 
 
	
	#define BCT_BCTGPDIR_TOUT1DIR_GPIO_INPUT			(000000u) 
	#define BCT_BCTGPDIR_TOUT1DIR_GPIO_OUTPUT			(0x0001u) 
	#define BCT_BCTGPDIR_TOUT1DIR_DEFAULT			BCT_BCTGPDIR_TOUT1DIR_GPIO_INPUT 
 
	#define BCT_BCTGPDIR_TIN1DIR_GPIO_INPUT				(000000u) 
	#define BCT_BCTGPDIR_TIN1DIR_GPIO_OUTPUT			(0x0001u) 
	#define BCT_BCTGPDIR_TIN1DIR_DEFAULT			BCT_BCTGPDIR_TIN1DIR_GPIO_INPUT 
 
#define BCT_BCTGPDIR_RMK(tout1dir,tin1dir)\
 ((Uint16) ( \
  ( BCT_FMK(BCTGPDIR,TOUT1DIR,tout1dir))|\
  ( BCT_FMK(BCTGPDIR,TIN1DIR,tin1dir))\
)\
 ) 
 
#define BCT_BCTGPDIR_RMKS(tout1dir_sym,tin1dir_sym)\
 ((Uint16) ( \
  ( BCT_FMKS(BCTGPDIR,TOUT1DIR,tout1dir_sym))|\
  ( BCT_FMKS(BCTGPDIR,TIN1DIR,tin1dir_sym))\
)\
 ) 

/*  Default BCTGPDIR register value  */

/* ============================================================== */

 /* Make BCTGPINT register values based on symbolic constants  */ 
 
/*  BCTGPINT field values  */ 
 
	
    #define BCT_BCTGPINT_TIN1INV_DISABLE		(0x0000u)  
	#define BCT_BCTGPINT_TIN1INV_ENABLE			(000001u) 
	#define BCT_BCTGPINT_TIN1INV_DEFAULT		BCT_BCTGPINT_TIN1INV_DISABLE
 
	#define BCT_BCTGPINT_TIN1INT_DISABLE		(0x0000u)  
	#define BCT_BCTGPINT_TIN1INT_ENABLE			(000001u) 
	#define BCT_BCTGPINT_TIN1INT_DEFAULT		BCT_BCTGPINT_TIN1INT_DISABLE
	
	
#define BCT_BCTGPINT_RMK(tin1inv,tin1int)\
 ((Uint16) ( \
  ( BCT_FMK(BCTGPINT,TIN1INV,tin1inv))|\
  ( BCT_FMK(BCTGPINT,TIN1INT,tin1int))\
)\
 ) 
 
#define BCT_BCTGPINT_RMKS(tin1inv_sym,tin1int_sym)\
 ((Uint16) ( \
  ( BCT_FMKS(BCTGPINT,TIN1INV,tin1inv_sym))|\
  ( BCT_FMKS(BCTGPINT,TIN1INT,tin1int_sym))\
)\
 ) 
 

/*  Default BCTGPINT register value  */

/* ============================================================== */
 /* Make BCTPID1 register values based on symbolic constants  */

/*  BCTPID1 field values  */

	#define BCT_BCTPID1_CLASS_CLASS			(000000u)
	#define BCT_BCTPID1_CLASS_DEFAULT		BCT_BCTPID1_CLASS_CLASS

	#define BCT_BCTPID1_REVISION_REVISION			(000000u)
	#define BCT_BCTPID1_REVISION_DEFAULT		BCT_BCTPID1_REVISION_REVISION


/*  Default BCTPID1 register value  */

/* ============================================================== */
 /* Make BCTPID2 register values based on symbolic constants  */

/*  BCTPID2 field values  */

	#define BCT_BCTPID2_TYPE_TYPE			(000000u)
	#define BCT_BCTPID2_TYPE_DEFAULT		BCT_BCTPID2_TYPE_TYPE


/*  Default BCTPID2 register value  */

/* ============================================================== */
 /* Make BCTPRD1 register values based on symbolic constants  */

/*  BCTPRD1 field values  */

	#define BCT_BCTPRD1_PRD_OF(x)			((Uint16)(x))
	#define BCT_BCTPRD1_PRD_DEFAULT		BCT_BCTPRD1_PRD_OF(x)


#define BCT_BCTPRD1_RMK(prd)\
 ((Uint16) ( \
  ( BCT_FMK(BCTPRD1,PRD,prd))\
)\
 )

#define BCT_BCTPRD1_RMKS(prd_sym)\
 ((Uint16) ( \
  ( BCT_FMKS(BCTPRD1,PRD,prd_sym))\
)\
 )

/*  Default BCTPRD1 register value  */

/* ============================================================== */
 /* Make BCTPRD2 register values based on symbolic constants  */

/*  BCTPRD2 field values  */

	#define BCT_BCTPRD2_PRD_OF(x)			((Uint16)(x))
	#define BCT_BCTPRD2_PRD_DEFAULT		BCT_BCTPRD2_PRD_OF(x)


#define BCT_BCTPRD2_RMK(prd)\
 ((Uint16) ( \
  ( BCT_FMK(BCTPRD2,PRD,prd))\
)\
 )

#define BCT_BCTPRD2_RMKS(prd_sym)\
 ((Uint16) ( \
  ( BCT_FMKS(BCTPRD2,PRD,prd_sym))\
)\
 )

/*  Default BCTPRD2 register value  */

/* ============================================================== */
 /* Make BCTPRD3 register values based on symbolic constants  */

/*  BCTPRD3 field values  */

	#define BCT_BCTPRD3_PRD_OF(x)			((Uint16)(x))
	#define BCT_BCTPRD3_PRD_DEFAULT		BCT_BCTPRD3_PRD_OF(x)


#define BCT_BCTPRD3_RMK(prd)\
 ((Uint16) ( \
  ( BCT_FMK(BCTPRD3,PRD,prd))\
)\
 )

#define BCT_BCTPRD3_RMKS(prd_sym)\
 ((Uint16) ( \
  ( BCT_FMKS(BCTPRD3,PRD,prd_sym))\
)\
 )

/*  Default BCTPRD3 register value  */

/* ============================================================== */
/* Make BCTPRD4 register values based on symbolic constants  */

/*  BCTPRD4 field values  */

	#define BCT_BCTPRD4_PRD_OF(x)			((Uint16)(x))
	#define BCT_BCTPRD4_PRD_DEFAULT		BCT_BCTPRD4_PRD_OF(x)


#define BCT_BCTPRD4_RMK(prd)\
 ((Uint16) ( \
  ( BCT_FMK(BCTPRD4,PRD,prd))\
)\
 )

#define BCT_BCTPRD4_RMKS(prd_sym)\
 ((Uint16) ( \
  ( BCT_FMKS(BCTPRD4,PRD,prd_sym))\
)\
 )

/*  Default BCTPRD4 register value  */
/*************************************************\
 BCT global typedef declarations 
\*************************************************/

typedef struct {
	Uint16 bctemu;
	Uint16 bctgpint;
	Uint16 bctgpen;
	Uint16 bctgpdir;
	Uint16 bctgpdat;
	Uint16 bctprd1;
	Uint16 bctprd2;
	Uint16 bctprd3;
	Uint16 bctprd4;
	Uint16 bctctl1;
	Uint16 bctctl2;
	Uint16 bctgctl1;
} BCT_Config;

typedef struct {
       Uint16 Private;
} BCT_Private, *BCT_Handle;

/*************************************************\
* BCT global variable declarations
\*************************************************/


/*************************************************\
* BCT global function declarations
\*************************************************/


#define BCT_initDual32(h, dt1ctl, dt2ctl,dt1prd, dt2prd, dt2prsc)\
  GPT_initDual32((GPT_Handle)(h), dt1ctl, dt2ctl, dt1prd, dt2prd, dt2prsc)

#define BCT_init64(h,gptgctl,dt12ctl,prdHigh,prdLow)\
  GPT_init64((GPT_Handle)(h),gptgctl,dt12ctl,prdHigh,prdLow)

#define BCT_initChained32(h,gctl, ctl1, prdHigh, prdLow)\
  GPT_initChained32((GPT_Handle)(h), (Uint16)(gctl), (Uint16)(ctl1),\
                     (Uint32)(prdHigh), (Uint32)(prdLow))

#define BCT_getPID(h,type,class,revision)\
  GPT_getPID((GPT_Handle)(h), (Uint16 *)(type), (Uint16 *)(class),\
             (Uint16 *)(revision))

#define BCT_getCnt(h,hi32, lo32)\
  GPT_getCnt((GPT_Handle)(h),(Uint32*) hi32, (Uint32*) lo32)

#define BCT_start12(h)\
  GPT_start12((GPT_Handle)(h))

#define BCT_start34(h)\
  GPT_start34((GPT_Handle)(h))

#define BCT_stop(h)\
  GPT_stop((GPT_Handle)(h))

#define BCT_stop12(h)\
  GPT_stop12((GPT_Handle)(h))

#define BCT_stop34(h)\
  GPT_stop34((GPT_Handle)(h))

#define BCT_config(h,myConfig)\
  GPT_config((GPT_Handle)(h),(GPT_Config *)myConfig)

#define BCT_configArgs(h,bctemu,\
             bctprd1,  bctprd2,  bctprd3,  bctprd4,\
             bctgpint, bctgpen,  bctgpdir, bctgpdat,\
             bctctl1,  bctctl2,  bctgctl1)\
   GPT_configArgs((GPT_Handle)(h), bctemu,\
             bctprd1,  bctprd2,  bctprd3,  bctprd4,\
             bctgpint, bctgpen,  bctgpdir, bctgpdat,\
             bctctl1,  bctctl2,  bctgctl1)

#define BCT_getConfig(h,myConfig)\
    GPT_getConfig((GPT_Handle)h, myConfig)

/*************************************************\
* BCT inline function declarations
\*************************************************/

IDECL BCT_Handle BCT_open(void);
IDECL void BCT_close(BCT_Handle h);

#ifdef USEDEFS


/*----------------------------------------------------------------------------*/
IDECL BCT_Handle BCT_open(){
   CSL_SYS_DATA.BctAllocMask = 1;
   return (BCT_Handle)(&(CSL_BCT_DATA));
}
/*----------------------------------------------------------------------------*/
IDECL void BCT_close(BCT_Handle h){
   CSL_SYS_DATA.BctAllocMask = 0;
}
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/

#endif /*USEDEFS */

#else
  #ifndef _BCT_MOD_
    	#error BCT Hal Module Not Supported on Specified Target
  #endif
#endif  /* _BCT_SUPPORT  */

#endif  /* _CSL_BCTHAL_H  */

/******************************************************************************\
*     
*      End of csl_bct.h 
*
\******************************************************************************/
