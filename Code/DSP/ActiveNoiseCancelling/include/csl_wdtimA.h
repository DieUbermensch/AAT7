/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... WATCHDOG TIMER
* FILENAME...... csl_wdtim.h
* DATE CREATED.. Sun 06/20/1999 
* PROJECT....... Chip Support Library
* COMPONENT..... service layer
* PREREQUISITS.. cslhal.h
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED : 06/20/1999 (BWC) Created for C6x.  
*   		: 12/06/2000 (FSCA) Modification for C54x.
*   		: 02/18/2000 (FSCA) C54x Romability.
*   		: 06/19/2000 make #ifdefs consistent with new csl_ header names,
*                        cpluplus compatability
*   		: 12/22/2000 (IM) Modified for Amadeus.
*   		: 12/02/2003 Removed 'wdtim' member from Config structure
*
*------------------------------------------------------------------------------
* DESCRIPTION:  (interface file for the WATCHDOG TIMER module)
*
*
*
\******************************************************************************/
#ifndef _CSL_WDTIMA_H_
#define _CSL_WDTIMA_H_


#include <_csl.h>
#include <csl_wdtimAhal.h>

#if (_WDTIMA_SUPPORT)
/****************************************\
* WDTIMER scope and inline control macros
\****************************************/
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
#define WDTIM_ERR_MAJOR            (ERR_BASE_WDTIM) 
#define WDTIM_ERR_ALLOC            (0x00000000)
#define WDTIM_ERR_INVALID_HANDLE   (0x00000001)



/*******************************************\
* WDTIM global macro definition : ROMABILITY
\*******************************************/ 
/* Reserved ROM Area for timerData.h */
/* Data definition */   
#define WdTimer_Initialized              WDTIM_SYM(0)


/*-----------------------------------------------------------------------*/
/* The following macros are used to construct peripheral register        */
/* values based on symbolic constants. They will be useful to initialize */
/* the WDTIM_Config structure in a readable way.                         */
/*-----------------------------------------------------------------------*/

/* make TCR register value based on symbolic constants */

#define WDTIM_WDTCR_RMK(wdout,soft,free,tddr) \
 ((Uint16) ( \
  ( WDTIM_FMK(WDTCR,WDOUT,wdout))|\
  ( WDTIM_FMK(WDTCR,SOFT,soft))|\
  ( WDTIM_FMK(WDTCR,FREE,free))|\
  ( WDTIM_FMK(WDTCR,TDDR,tddr))\
  )\
)  

#define WDTIM_WDTCR_RMKS(wdout_sym,soft_sym,free_sym,tddr_sym) \
 ((Uint16) ( \
  ( WDTIM_FMKS(WDTCR,WDOUT,wdout_sym))|\
  ( WDTIM_FMKS(WDTCR,SOFT,soft_sym))|\
  ( WDTIM_FMKS(WDTCR,FREE,free_sym))|\
  ( WDTIM_FMKS(WDTCR,TDDR,tddr_sym))\
  )\
)  

/* default WDTCR register value */
#define WDTIM_WDTCR_DEFAULT                 (0x0000)

/* WDTCR field values */
#define WDTIM_WDTCR_WDOUT_WDTINT		  (0x0000)
#define WDTIM_WDTCR_WDOUT_NMI			  (0x0001)
#define WDTIM_WDTCR_WDOUT_RESET		  (0x0002)
#define WDTIM_WDTCR_WDOUT_NOCONNECT		  (0x0003)
#define WDTIM_WDTCR_WDOUT_DEFAULT		  WDTIM_WDTCR_WDOUT_NOCONNECT

#define WDTIM_WDTCR_SOFT_BRKPTNOW           (0x0000)
#define WDTIM_WDTCR_SOFT_WAITZERO           (0x0001)
#define WDTIM_WDTCR_SOFT_DEFAULT            WDTIM_WDTCR_SOFT_BRKPTNOW

#define WDTIM_WDTCR_FREE_WITHSOFT           (0x0000)
#define WDTIM_WDTCR_FREE_NOSOFT             (0x0001)
#define WDTIM_WDTCR_FREE_DEFAULT            WDTIM_WDTCR_FREE_WITHSOFT

#define WDTIM_WDTCR_TDDR_OF(x)              ((Uint16)x)


/* WDTCR2 register */

#define WDTIM_WDTCR2_RMK(wdflag,wden,premd,wdkey) \
 ((Uint16) ( \
  ( WDTIM_FMK(WDTCR2,WDFLAG,wdflag))|\
  ( WDTIM_FMK(WDTCR2,WDEN,wden))|\
  ( WDTIM_FMK(WDTCR2,PREMD,premd))|\
  ( WDTIM_FMK(WDTCR2,WDKEY,wdkey))\
  )\
)  

#define WDTIM_WDTCR2_RMKS(wdflag_s,wden_s,premd_s,wdkey_s) \
 ((Uint16) ( \
  ( WDTIM_FMKS(WDTCR2,WDFLAG,wdflag_s))|\
  ( WDTIM_FMKS(WDTCR2,WDEN,wden_s))|\
  ( WDTIM_FMKS(WDTCR2,PREMD,premd_s))|\
  ( WDTIM_FMKS(WDTCR2,WDKEY,wdkey_s))\
  )\
)  

/* WDTCR2 field values */

#define WDTIM_WDTCR2_WDFLAG_TIMEOUT         (0x0001u)
#define WDTIM_WDTCR2_WDFLAG_NOTIMEOUT       (0x0000u)
#define WDTIM_WDTCR2_WDFLAG_DEFAULT         WDTIM_WDTCR2_WDFLAG_NOTIMEOUT

#define WDTIM_WDTCR2_WDEN_ENABLE            (0x0001u)
#define WDTIM_WDTCR2_WDEN_DISABLE           (0x0000u)
#define WDTIM_WDTCR2_WDEN_DEFAULT           WDTIM_WDTCR2_WDEN_DISABLE

#define WDTIM_WDTCR2_PREMD_DIRECT           (0x0000u)
#define WDTIM_WDTCR2_PREMD_INDIRECT         (0x0001u)
#define WDTIM_WDTCR2_PREMD_DEFAULT          WDTIM_WDTCR2_PREMD_DIRECT

#define WDTIM_WDTCR2_WDKEY_PREACTIVE        (0x05C6u)
#define WDTIM_WDTCR2_WDKEY_ACTIVE           (0x0A7Eu)
#define WDTIM_WDTCR2_WDKEY_DEFAULT          (0x0000u)


/* WDPRD register */

#define WDTIM_WDPRD_RMK(prd) \
 ((Uint16)(WDTIM_FMK(WDPRD,PRD,prd)))  

#define WDTIM_WDPRD_RMKS(prd_s) \
 ((Uint16)(WDTIM_FMK(WDPRD,PRD,prd_s)))  


#define WDTIM_WDPRD_PRD_OF(x)               ((Uint16)(x))
#define WDTIM_WDPRD_DEFAULT                 (0xFFFFu)


/* WDTIM register */

#define WDTIM_WDTIM_RMK(tim) \
 ((Uint16)(WDTIM_FMK(WDTIM,TIM,tim)))  

#define WDTIM_WDTIM_RMKS(tim_s) \
 ((Uint16)(WDTIM_FMK(WDTIM,PRD,tim_s)))  


#define WDTIM_WDTIM_TIM_OF(x)               ((Uint16)(x))
#define WDTIM_WDTIM_DEFAULT                 (0xFFFFu)


/****************************************\
* WDTIMER global typedef declarations
\****************************************/


/* device configuration structure */
typedef struct {
  Uint16 wdprd;
  Uint16 wdtcr;
  Uint16 wdtcr2;
} WDTIM_Config;

/****************************************\
* WDTIMER global variable declarations
\****************************************/ 


/****************************************\
* WDTIMER global function declarations
\****************************************/

/****************************************\
* WDTIMER inline function declarations
\****************************************/

IDECL void WDTIM_config(WDTIM_Config *Config);
IDECL void WDTIM_configArgs(Uint16 wdtcr, Uint16 wdtcr2, Uint16 wdprd);
IDECL void WDTIM_getConfig(WDTIM_Config *Config);

IDECL void WDTIM_service();
IDECL void WDTIM_start();

/****************************************\
* WDTIMER inline function definitions
\****************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF void WDTIM_config(WDTIM_Config *Config) {
  int old_intm;
  Uint16 tcr2_val = Config->wdtcr2 & (_WDTIM_WDTCR2_WDKEY_CLR & _WDTIM_WDTCR2_WDEN_CLR);

  old_intm = IRQ_globalDisable();  
  WDTIM_RSET(WDTCR,Config->wdtcr);
  WDTIM_RSET(WDPRD,Config->wdprd);
  WDTIM_RSET(WDTCR2,tcr2_val);
  IRQ_globalRestore(old_intm);   

}
/*----------------------------------------------------------------------------*/
IDEF void WDTIM_getConfig(WDTIM_Config *Config) {
  int old_intm;
  old_intm = IRQ_globalDisable();  
  Config->wdtcr2 = WDTIM_RGET(WDTCR2);
  Config->wdprd = WDTIM_RGET(WDPRD);
  Config->wdtcr = WDTIM_RGET(WDTCR);
  Config->wdtim = WDTIM_RGET(WDTIM);   
  IRQ_globalRestore(old_intm);   
}

/*----------------------------------------------------------------------------*/
IDEF void WDTIM_configArgs(Uint16 wdtcr, Uint16 wdtcr2, Uint16 wdprd) {
  int old_intm;
  Uint16 tcr2_val = wdtcr2 & (_WDTIM_WDTCR2_WDEN_CLR & _WDTIM_WDTCR2_WDKEY_CLR);

   old_intm = IRQ_globalDisable(); 
    
   WDTIM_RSET(WDPRD,wdprd);
   WDTIM_RSET(WDTCR,wdtcr); 
   WDTIM_RSET(WDTCR2,tcr2_val);
  
  IRQ_globalRestore(old_intm);   
}

/*----------------------------------------------------------------------------*/
IDEF void WDTIM_service() {
 Uint16 old_wdtcr2;
 int old_intm;

  old_intm = IRQ_globalDisable();

  old_wdtcr2 = WDTIM_RGET(WDTCR2);

   WDTIM_FSET(WDTCR2,WDKEY,WDTIM_WDTCR2_WDKEY_PREACTIVE); 
      
    ((old_wdtcr2 & _WDTIM_WDTCR2_WDKEY_CLR) | _WDTIM_WDTCR2_WDEN_MK(WDTIM_WDTCR2_WDEN_ENABLE) | 
      _WDTIM_WDTCR2_WDKEY_MK(WDTIM_WDTCR2_WDKEY_ACTIVE)));

  IRQ_globalRestore(old_intm);
}

/*----------------------------------------------------------------------------*/
IDEF void WDTIM_start() {
 Uint16 old_wdtcr2;
 int old_intm;

  old_intm = IRQ_globalDisable();

  old_wdtcr2 = WDTIM_RGET(WDTCR2);

  WDTIM_FSETS(WDTCR2,WDKEY,PREACTIVE);
  WDTIM_RSET(WDTCR2,
    ((old_wdtcr2 & _WDTIM_WDTCR2_WDKEY_CLR) | WDTIM_WDTCR2_WDEN_ENABLE | WDTIM_WDTCR2_WDKEY_ACTIVE));


  IRQ_globalRestore(old_intm);

}


#endif /*USEDEFS */
#else
  #ifndef _WDTIM_MOD_ 
    #error Watchdog Timer Module Not Supported on Specified Target
  #endif
#endif /*_WDTIMA_SUPPORT */

#endif /* _CSL_WDTIMA_H_ */                
/******************************************************************************\
* End of csl_wdtimA.h
\******************************************************************************/

