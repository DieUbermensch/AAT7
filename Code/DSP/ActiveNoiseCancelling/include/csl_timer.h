/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... CSL_TIMER
* FILENAME...... csl_timer.h
* DATE CREATED.. Sun 06/20/1999 
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... service layer
* PREREQUISITE.. csl_timhal.h
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:  06/20/1999 Created for C6x.  
*   MODIFIED: 2/06/2000 Modification for C54x.
*   MODIFIED: 05/30/2000 C55x Version
*   MODIFIED: 07/13/2000 Final Version for C55x
*   MODIFIED: 04/16/2001 updated header comments
*   MODIFIED: 05/11/2001 updated for TIMER_getConfig()
*   MODIFIED: 06/28/2001 updated for new CSL initialization model
*   MODIFIED: 05/07/2002 Added TIMER_Private typedef to support
*                        C++ strict typing of TIMER_Handle
*   MODIFIED: 08/09/2004 Fixed TIMER_open implementation error.
*   MODIFIED: 08/24/2004 Removed IRQ_restoreGie() from 55x CSL
*------------------------------------------------------------------------------
* DESCRIPTION:  (interface file for the TIMER module)
\******************************************************************************/
#ifndef _CSL_TIMER_H_
#define _CSL_TIMER_H_

#include <csl.h>
#include <csl_timhal.h>


#if (_TIMER_SUPPORT)
/****************************************\
* TIMER scope and inline control macros
\****************************************/
#ifdef __cplusplus
#define CSLAPI extern "C"  
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _TIMER_MOD_
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
* TIMER global macro declarations
\****************************************/ 

/* TIMER_Open() flags */
#define TIMER_OPEN_RESET           (0x0001)
#define TIMER_OPEN_BIOS            (0x8000)

/* error codes */
#define TIMER_ERR_MAJOR            (ERR_BASE_TIMER) 
#define TIMER_ERR_ALLOC            (0x00000000)
#define TIMER_ERR_INVALID_HANDLE   (0x00000001)

/* device identifiers for TIMER_Open() */
#define TIMER_DEV_ANY  (-1)
#define TIMER_DEV0    (0)
#define TIMER_DEV1    (1)  


/*******************************************\
* TIMER global macro definition : ROMABILITY
\*******************************************/ 
/* Reserved ROM Area for timerData.h */
/* Data definition */   

/* Predefined Device Handlers */
#define TIMER_hDev0   ((TIMER_Handle)(&(CSL_TIMER_DATA.Timer[0])))
#define TIMER_hDev1   ((TIMER_Handle)(&(CSL_TIMER_DATA.Timer[1])))
#define TIMER_hDev(n) ((TIMER_Handle)(&(CSL_TIMER_DATA.Timer[n])))


/*-----------------------------------------------------------------------*/
/* The following macros are used to construct peripheral register        */
/* values based on symbolic constants. They will be useful to initialize */
/* the TIMER_Config structure in a readable way.                         */
/*-----------------------------------------------------------------------*/

/*===========================================================================*\
* HTIMER_TIM0    - Timer Register, Timer #0
* HTIMER_TIM1    - Timer Register, Timer #1
*
* Fields:
*  (RW) TIM
\*===========================================================================*/

/*===========================================================================*\
* TIMER_TIM_DEFAULT Values
\*===========================================================================*/

/* default TIM register value */
#define TIMER_TIM_DEFAULT                 (0xFFFF)

/* TIM field values */
#define TIMER_TIM_TIM_OF(x)              ((Uint16)(x))

/*===========================================================================*\
* TIMER_TIM_MK
\*===========================================================================*/

/* make TIM register value based on symbolic constants */

#define TIMER_TIM_RMK(tim) \
 ((Uint16) (TIMER_FMK(TIM,TIM,tim))\
)  

#define TIMER_TIM_RMKS(tim_s) \
 ((Uint16) (TIMER_FMKS(TIM,TIM,tim_s))\
)  

/*===========================================================================*\
* HTIMER_PRD0    - Period Register, Timer #0
* HTIMER_PRD1    - Period Register, Timer #1
*
* Fields:
*  (RW) PRD
\*===========================================================================*/

/*===========================================================================*\
* TIMER_PRD_DEFAULT Values
\*===========================================================================*/

/* default PRD register value */
#define TIMER_PRD_DEFAULT                 (0xFFFF)

/* PRD field values */
#define TIMER_PRD_PRD_OF(x)              ((Uint16)(x))

/*===========================================================================*\
* TIMER_PRD_MK
\*===========================================================================*/

/* make PRD register value based on symbolic constants */

#define TIMER_PRD_RMK(prd) \
 ((Uint16) (TIMER_FMK(PRD,PRD,prd))\
) 

#define TIMER_PRD_RMKS(prd_s) \
 ((Uint16) (TIMER_FMK(PRD,PRD,prd_s))\
)  
 
/*===========================================================================*\
* HTIMER_TCR0    - Control Register, Timer #0
* HTIMER_TCR1    - Control Register, Timer #1
*
* Fields:
*  (RW) IDLEEN
*  (R)  INTEXT
*  (R)  ERRTIM
*  (RW) FUNC
*  (RW) TLB
*  (RW) SOFT
*  (RW) FREE
*  (RW) PWID
*  (RW) ARB
*  (RW) TSS
*  (RW) CP
*  (RW) POLAR
*  (RW) DATOUT
\*===========================================================================*/

/*===========================================================================*\
* TIMER_TCR_DEFAULT Values
\*===========================================================================*/

/* default TCR register value */
#define TIMER_TCR_DEFAULT                 (0x0010)

/* TCR field values */
#define TIMER_TCR_IDLEEN_ENABLE           (0x0001u)
#define TIMER_TCR_IDLEEN_DISABLE          (0x0000u)
#define TIMER_TCR_IDLEEN_DEFAULT          TIMER_TCR_IDLEEN_DISABLE

#define TIMER_TCR_FUNC_OF(x)              ((Uint16)(x))
#define TIMER_TCR_FUNC_DEFAULT            TIMER_TCR_FUNC_OF(0)

#define TIMER_TCR_TLB_RESET		      (0x0001)
#define TIMER_TCR_TLB_NORESET      		(0x0000)
#define TIMER_TCR_TLB_DEFAULT             TIMER_TCR_TLB_NORESET      


#define TIMER_TCR_SOFT_BRKPTNOW           (0x0000)
#define TIMER_TCR_SOFT_WAITZERO           (0x0001)
#define TIMER_TCR_SOFT_DEFAULT            TIMER_TCR_SOFT_BRKPTNOW     
      
#define TIMER_TCR_FREE_WITHSOFT           (0x0000)
#define TIMER_TCR_FREE_NOSOFT             (0x0001)
#define TIMER_TCR_FREE_DEFAULT            TIMER_TCR_FREE_WITHSOFT           

#define TIMER_TCR_PWID_OF(x)              ((Uint16)(x))
#define TIMER_TCR_PWID_DEFAULT            TIMER_TCR_PWID_OF(0)              

#define TIMER_TCR_ARB_RESET               (0x0001)
#define TIMER_TCR_ARB_NORESET             (0x0000)
#define TIMER_TCR_ARB_DEFAULT             TIMER_TCR_ARB_NORESET             

#define TIMER_TCR_TSS_START               (0x0000)
#define TIMER_TCR_TSS_STOP                (0x0001)
#define TIMER_TCR_TSS_DEFAULT             TIMER_TCR_TSS_STOP                (0x0001)

#define TIMER_TCR_CP_PULSE                (0x0000)
#define TIMER_TCR_CP_CLOCK                (0x0001)
#define TIMER_TCR_CP_DEFAULT              TIMER_TCR_CP_PULSE                

#define TIMER_TCR_POLAR_LOW               (0x0000)
#define TIMER_TCR_POLAR_HIGH              (0x0001)
#define TIMER_TCR_POLAR_DEFAULT           TIMER_TCR_POLAR_LOW               

#define TIMER_TCR_DATOUT_0                (0x0000)
#define TIMER_TCR_DATOUT_1                (0x0001)
#define TIMER_TCR_DATOUT_DEFAULT          TIMER_TCR_DATOUT_0                



/*===========================================================================*\
* TIMER_TCR_MK
\*===========================================================================*/

/* make TCR register value based on symbolic constants */

#define TIMER_TCR_RMK(idleen,func,tlb,soft,free,pwid,arb,tss,cp,polar,datout) \
 ((Uint16) ( \
  (TIMER_FMK(TCR,IDLEEN,idleen))|\
  (TIMER_FMK(TCR,FUNC,func))|\
  (TIMER_FMK(TCR,TLB,tlb))|\
  (TIMER_FMK(TCR,SOFT,soft))|\
  (TIMER_FMK(TCR,FREE,free))|\
  (TIMER_FMK(TCR,PWID,pwid))|\
  (TIMER_FMK(TCR,ARB,arb))|\
  (TIMER_FMK(TCR,TSS,tss))|\
  (TIMER_FMK(TCR,CP,cp))|\
  (TIMER_FMK(TCR,POLAR,polar))|\
  (TIMER_FMK(TCR,DATOUT,datout))\
  )\
) 

#define TIMER_TCR_RMKS(idleen_s,func_s,tlb_s,soft_s,free_s,pwid_s,arb_s,tss_s,\
  cp_s,polar_s,datout_s) \
 ((Uint16) ( \
  (TIMER_FMKS(TCR,IDLEEN,idleen_s))|\
  (TIMER_FMKS(TCR,FUNC,func_s))|\
  (TIMER_FMKS(TCR,TLB,tlb_s))|\
  (TIMER_FMKS(TCR,SOFT,soft_s))|\
  (TIMER_FMKS(TCR,FREE,free_s))|\
  (TIMER_FMKS(TCR,PWID,pwid_s))|\
  (TIMER_FMKS(TCR,ARB,arb_s))|\
  (TIMER_FMKS(TCR,TSS,tss_s))|\
  (TIMER_FMKS(TCR,CP,cp_s))|\
  (TIMER_FMKS(TCR,POLAR,polar_s))|\
  (TIMER_FMKS(TCR,DATOUT,datout_s))\
  )\
)  
 
/*===========================================================================*\
* HTIMER_PRSC0    - Prescaler Register, Timer #0
* HTIMER_PRSC1    - Prescaler Register, Timer #1
*
* Fields:
*  (RW) TDDR
*  (RW) PSC
\*===========================================================================*/

/*===========================================================================*\
* TIMER_PRSC_DEFAULT Values
\*===========================================================================*/

/* default PRSC register value */
#define TIMER_PRSC_DEFAULT                 (0x0000)

/* TCR field values */
#define TIMER_PRSC_PSC_OF(x)               ((Uint16)(x))
#define TIMER_PRSC_TDDR_0F(x)		       ((Uint16)(x))

/*===========================================================================*\
* TIMER_PRSC_MK
\*===========================================================================*/

/* make PRSC register value based on symbolic constants */

#define TIMER_PRSC_RMK(psc,tddr) \
 ((Uint16) ( \
  ( TIMER_FMK(PRSC,PSC,psc))|\
  ( TIMER_FMK(PRSC,TDDR,tddr))\
  )\
)  

#define TIMER_PRSC_RMKS(psc_s,tddr_s) \
 ((Uint16) ( \
  ( TIMER_FMKS(PRSC,PSC,psc_s))|\
  ( TIMER_FMKS(PRSC,TDDR,tddr_s))|\
  )\
)  

/*******************************************/
/* Define a debuging assertion macro */ 
/* for validating device handles */
#ifdef _MCRTE_DEBUG
  #define TIMER_ASSERT_HANDLE(hTimer,RetExp) \
    if (hTimer == INV) { \
      ERR_submit(TIMER_ERR_MAJOR, TIMER_ERR_INVALID_HANDLE); \
      RetExp; \
    }
#else
  #define TIMER_ASSERT_HANDLE(hTimer,RetExp)
#endif


/* make CLKMD register value based on symbolic constants */

#define TIMER_CLKMD_RMK(pllndiv, pllonoff, pllcount, plldiv, pllmul)\
  ((Uint16) (   TIMER_FMK(CLKMD,PLLNDIV,pllndiv)    |\
                TIMER_FMK(CLKMD,PLLONOFF,pllonoff)  |\
                TIMER_FMK(CLKMD,PLLDIV,plldiv)      |\
                TIMER_FMK(CLKMD,PLLMUL,pllmul)\
           )\
  )

#define TIMER_CLKMD_RMKS(pllndiv_s, pllonoff_s, pllcount_s, plldiv_s, pllmul_s)\
  ((Uint16) (   TIMER_FMKS(CLKMD,PLLNDIV,pllndiv_s)    |\
                TIMER_FMKS(CLKMD,PLLONOFF,pllonoff_s)  |\
                TIMER_FMKS(CLKMD,PLLDIV,plldiv_s)      |\
                TIMER_FMKS(CLKMD,PLLMUL,pllmul_s)\
           )\
  )

/* Default CLKMD register values                         */

#define TIMER_CLKMD_DEFAULT               (0x0000u)

#define TIMER_CLKMD_PLLNDIV_OFF           (0x0000u)
#define TIMER_CLKMD_PLLNDIV_ON            (0x0001u)

#define TIMER_CLKMD_PLLONOFF_OFF          (0x0000u)
#define TIMER_CLKMD_PLLONOFF_ON           (0x0001u)

#define TIMER_CLKMD_PLLCOUNT_OF(x)        ((Uint16)x)

#define TIMER_CLKMD_PLLDIV_OFF            (0x0000u)
#define TIMER_CLKMD_PLLDIV_ON             (0x0001u)

#define TIMER_CLKMD_PLLMUL_OF(x)          ((Uint16)x)



#define TIMER_getEventId(hTimer) (\
	(Uint16)(((TIMER_PrivateObj*)hTimer)->EventId)\
)


/****************************************\
* TIMER global typedef declarations
\****************************************/
/* device handle type */

typedef struct {
  Uint16 Private;
} TIMER_Private, *TIMER_Handle;

/* device configuration structure */
typedef struct {
  Uint16 tcr;
  Uint16 prd;
  Uint16 prsc;
} TIMER_Config;

/****************************************\
* TIMER global variable declarations
\****************************************/ 
IDECL  void TIMER_close(TIMER_Handle hTimer);
IDECL  void TIMER_config(TIMER_Handle hTimer, TIMER_Config *Config);
IDECL  void TIMER_getConfig(TIMER_Handle hTimer, TIMER_Config *Config);
IDECL  void TIMER_configArgs(TIMER_Handle hTimer, Uint16 tcr, Uint16 prd, Uint16 prsc);
IDECL  TIMER_Handle TIMER_open(int DevNum, Uint16 Flags);
IDECL  void TIMER_start(TIMER_Handle hTimer);
IDECL  void TIMER_stop(TIMER_Handle hTimer);
IDECL  void TIMER_tintoutCfg(TIMER_Handle hTimer, Uint16 idleen, Uint16 func, Uint16 pwid, Uint16 cp, Uint16 polar);

/****************************************\
* TIMER global function declarations
\****************************************/
CSLAPI  void TIMER_reset(TIMER_Handle hTimer);

/****************************************\
* Timer Inline Functions
\****************************************/
#ifdef  USEDEFS
/*----------------------------------------------------------------------------*/
IDEF void TIMER_close(TIMER_Handle hTimer) {
  int oldgie;
  TIMER_ASSERT_HANDLE(hTimer,return);
    oldgie = IRQ_globalDisable(); 


  CSL_SYS_DATA.TimerAllocMask &= (~(1u<<((TIMER_PrivateObj*)hTimer)->Timer));   
  TIMER_reset(hTimer);
  IRQ_globalRestore(oldgie);

}
/*----------------------------------------------------------------------------*/
IDEF void TIMER_config(TIMER_Handle hTimer, TIMER_Config *Config) {
  int oldgie;
  TIMER_ASSERT_HANDLE(hTimer,return);

    oldgie = IRQ_globalDisable();  
 
  PREG16(((TIMER_PrivateObj*)hTimer)->TcrAddr) = 0x0010;  
  PREG16(((TIMER_PrivateObj*)hTimer)->PrdAddr) = Config->prd;
  PREG16(((TIMER_PrivateObj*)hTimer)->PrscAddr)= Config->prsc;
  TIMER_FSETH(hTimer,TCR,TLB,1);
  PREG16(((TIMER_PrivateObj*)hTimer)->TcrAddr) = Config->tcr | 0x0010;
 /* TIMER_FSETH(hTimer,TCR,TLB,0); */
  
  
  IRQ_globalRestore(oldgie); 
 
}
/*----------------------------------------------------------------------------*/
IDEF void TIMER_configArgs(TIMER_Handle hTimer, Uint16 tcr, Uint16 prd, Uint16 prsc) {
  int oldgie;
  TIMER_ASSERT_HANDLE(hTimer,return);
  oldgie = IRQ_globalDisable(); 
  

  PREG16(((TIMER_PrivateObj*)hTimer)->TcrAddr) = 0x0010;
  PREG16(((TIMER_PrivateObj*)hTimer)->PrdAddr) = prd;
  PREG16(((TIMER_PrivateObj*)hTimer)->PrscAddr) = prsc;
  TIMER_FSETH(hTimer,TCR,TLB,1);
  PREG16(((TIMER_PrivateObj*)hTimer)->TcrAddr) = tcr | 0x0010;   
  TIMER_FSETH(hTimer,TCR,TLB,0);
  
  IRQ_globalRestore(oldgie); 
}
/*----------------------------------------------------------------------------*/
IDEF void TIMER_getConfig(TIMER_Handle hTimer, TIMER_Config *Config) {
  int oldgie;
  TIMER_ASSERT_HANDLE(hTimer,return);

    oldgie = IRQ_globalDisable();  
 
  Config->tcr = PREG16(((TIMER_PrivateObj*)hTimer)->TcrAddr);  
  Config->prd = PREG16(((TIMER_PrivateObj*)hTimer)->PrdAddr);
  Config->prsc = PREG16(((TIMER_PrivateObj*)hTimer)->PrscAddr);
 
  IRQ_globalRestore(oldgie); 
 
}
/*----------------------------------------------------------------------------*/
IDEF TIMER_Handle TIMER_open(int DevNum, Uint16 Flags) {

  TIMER_Handle hTimer = INV;
  Uint16 dev  = DevNum;
  Uint16 allocMask;
  int oldgie;

  oldgie = IRQ_globalDisable();  
 
  allocMask = CSL_SYS_DATA.TimerAllocMask;

  #ifdef _MCRTE_DEBUG
  if ( !((DevNum == -1) || ((DevNum >= 0) && (DevNum < TIMER_DEVICE_CNT))) ) {
    ERR_submit(TIMER_ERR_MAJOR, TIMER_ERR_ALLOC);
     IRQ_globalRestore(oldgie);
    return (TIMER_Handle) INV;
  }
  #endif

  if (DevNum==-1) {
    for (dev=0; dev<TIMER_DEVICE_CNT; dev++) {
      if ((allocMask & (1u<<dev))==0){
        hTimer = TIMER_hDev(dev);
       break;
      }
    }
  } else if ((allocMask & (1u<<dev))==0){
    hTimer = TIMER_hDev(dev);
  }

  #ifdef _MCRTE_DEBUG
    if (hTimer == INV) {
      ERR_submit(TIMER_ERR_MAJOR, TIMER_ERR_INVALID_HANDLE);
      IRQ_globalRestore(oldgie);
      return (TIMER_Handle)INV;
  }
  #endif

  if (hTimer != INV) {
     CSL_SYS_DATA.TimerAllocMask |= 1u<<dev;     
     if (Flags & TIMER_OPEN_RESET) {
       TIMER_reset(hTimer);
     }
  }

  IRQ_globalRestore(oldgie);
  return hTimer;
}
/*----------------------------------------------------------------------------*/
IDEF void TIMER_start(TIMER_Handle hTimer) {
  int oldgie;
  Uint16 old_tcr;

  oldgie = IRQ_globalDisable(); 
    
      /* stop timer */  
  old_tcr = _PREG_GET(((TIMER_PrivateObj*)(hTimer))->TcrAddr);
  _PREG_SET(((TIMER_PrivateObj*)(hTimer))->TcrAddr, (old_tcr & (_TIMER_TCR_TLB_CLR & _TIMER_TCR_TSS_CLR)));
  IRQ_globalRestore(oldgie);

}
/*----------------------------------------------------------------------------*/
IDEF void TIMER_stop(TIMER_Handle hTimer) {
  int oldgie;

  oldgie = IRQ_globalDisable(); 
    
      /* stop timer */  
  TIMER_FSETH(hTimer,TCR,TSS,1);

  IRQ_globalRestore(oldgie);

}

/*----------------------------------------------------------------------------*/
IDEF void TIMER_tintoutCfg(TIMER_Handle hTimer, Uint16 idleen, Uint16 func, Uint16 pwid, Uint16 cp, Uint16 polar) {

  Uint16 tcrMask = TIMER_TCR_RMK(
                     idleen,
                     func,
                     0,             /* TLB    */
                     0,             /* SOFT   */
                     0,             /* FREE   */
                     pwid,          /* PWID   */
                     0,             /* ARB    */
                     0,             /* TSS    */
                     cp,            /* CP     */
                     polar,         /* POLAR  */
                     0);            /* DATOUT */
 
  int oldgie;

  oldgie = IRQ_globalDisable();

     ((TIMER_PrivateObj*)hTimer)->TcrAddr |= 0x0010;
     ((TIMER_PrivateObj*)hTimer)->TcrAddr |= tcrMask;

  IRQ_globalRestore(oldgie);
      
}
/*****************************************************************************\
\*****************************************************************************/
#endif /* UseDefs */
/******************************************************************************\
* End of timer.h
\******************************************************************************/
#endif /*TIMER_SUPPORT */
#endif /* _TIMER_H_ */    

