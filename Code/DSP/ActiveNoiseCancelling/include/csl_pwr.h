/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... PWR
* FILENAME...... csl_pwr.h
* DATE CREATED.. Thu 11/11/1999
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... CSL service layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:       11/11/1999 Created
*   MODIFIED:      12/01/1999 Modified for TMS320C54xx
*                  04/16/2001 updated FILENAME and other header comments
*   			   08/21/2003 Added #if (CHIP_5502)
* LAST MODIFIED:   09/23/2003 PWR_powerDown function name typo error fix
*                  08/06/2004 Added 5501 support  
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the PWR module)
*
*
*
\******************************************************************************/
#ifndef _PWR_H_
#define _PWR_H_

#include <_csl.h>
#include <csl_pwrhal.h>

#if (_PWR_SUPPORT)
/****************************************\
* PWR scope and inline control macros
\****************************************/

#ifdef __cplusplus
#define CSLAPI extern "C"
#else
#define CSLAPI extern
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _PWR_MOD_
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
* PWR global macro declarations
\****************************************/
#define PWR_ERR_MAJOR         (ERR_BASE_PWR)
#define PWR_ERR_INVALID_MODE   (0x00000000)


#ifdef _MCRTE_DEBUG
  #define PWR_ASSERT_MODE(mode)\
   if((mode <1) || (mode >3)) {\
     ERR_submit(PWR_ERR_MAJOR, PWR_ERR_INVALID_MODE);\
     mode;\
   }
#else
  #define PWR_ASSERT_MODE(mode)
#endif
/*******************************************\
* PWR global macro definition : ROMABILITY
\*******************************************/
/* Reserved ROM Area for PWR Data */

#if (!((CHIP_5502) || (CHIP_5501)))

/*===========================================================================*\
* PWR ICR    - Idle Configuration Register Macros
*
* Fields:
*  (RW) EMIFI
*  (RW) CLKGENI
*  (RW) PERI
*  (RW) CACHEI
*  (RW) DMAI
*  (RW) CPUI
*
\*==========================================================================*/

#define PWR_ICR_EMIFI_EMIF_ACTIVE               (0u)
#define PWR_ICR_EMIFI_EMIF_DISABLED             (1u)
#define PWR_ICR_EMIFI_DEFAULT                   PWR_ICR_EMIFI_EMIF_ACTIVE

#define PWR_ICR_CLKGENI_CLKGEN_RUNNING          (0u)
#define PWR_ICR_CLKGENI_CLKGEN_OFF              (1u)
#define PWR_ICR_CLKGENI_DEFAULT                 PWR_ICR_CLKGENI_CLKGEN_RUNNING

#define PWR_ICR_PERI_ALL_ACTIVE                 (0u)
#define PWR_ICR_PERI_IDLE_ENABLE_BIT            (1u)
#define PWR_ICR_PERI_DEFAULT                    PWR_ICR_PERI_ALL_ACTIVE

#define PWR_ICR_CACHEI_CACHE_ACTIVE             (0u)
#define PWR_ICR_CACHEI_CACHE_DISABLED           (1u)
#define PWR_ICR_CACHEI_DEFAULT                  PWR_ICR_CACHEI_CACHE_ACTIVE

#define PWR_ICR_DMAI_DMA_ACTIVE                 (0u)
#define PWR_ICR_DMAI_DMA_DISABLED               (1u)
#define PWR_ICR_DMAI_DEFAULT                    PWR_ICR_DMAI_DMA_ACTIVE

#define PWR_ICR_CPUI_CPU_ACTIVE                 (0u)
#define PWR_ICR_CPUI_CPU_DISABLED               (1u)
#define PWR_ICR_CPUI_DEFAULT                    PWR_ICR_CPUI_CPU_ACTIVE


/*---------------------------------------*\
* PWR_ICR_MK Macro
\*---------------------------------------*/

#define PWR_ICR_RMK(emifi, clkgeni, peri, cachei, dmai,cpui)\
  (Uint16) ( PWR_FMK(ICR,EMIFI,emifi)|\
             PWR_FMK(ICR,CLKGENI,clkgeni)|\
             PWR_FMK(ICR,PERI,peri)|\
             PWR_FMK(ICR,CACHEI,cachei)|\
             PWR_FMK(ICR,DMAI,dmai)|\
             PWR_FMK(ICR,CPUI,cpui)\
             )

#define PWR_ICR_RMKS(emifi_s, clkgeni_s, peri_s, cachei_s, dmai_s, cpui_s)\
  (Uint16) ( PWR_FMKS(ICR,EMIFI,emifi_s)|\
             PWR_FMKS(ICR,CLKGENI,clkgeni_s)|\
             PWR_FMKS(ICR,PERI,peri_s)|\
             PWR_FMKS(ICR,CACHEI,cachei_s)|\
             PWR_FMKS(ICR,DMAI,dmai_s)|\
             PWR_FMKS(ICR,CPUI,cpui_s)\
             )



/*===========================================================================*\
*  PWR ISTR    - Idle Status Register
*
* Fields:
*  (R) EMIFIS
*  (R) CLKGENIS
*  (R) PERIS
*  (R) CACHEIS
*  (R) DMAIS
*  (R) CPUIS
*
\*==========================================================================*/

#define PWR_ISTR_EMIFIS_EMIF_ACTIVE               (0u)
#define PWR_ISTR_EMIFIS_EMIF_DISABLED             (1u)
#define PWR_ISTR_EMIFIS_DEFAULT                   PWR_ISTR_EMIFIS_EMIF_ACTIVE

#define PWR_ISTR_CLKGENIS_CLKGEN_RUNNING          (0u)
#define PWR_ISTR_CLKGENIS_CLKGEN_OFF              (1u)
#define PWR_ISTR_CLKGENIS_DEFAULT                 PWR_ISTR_CLKGENIS_CLKGEN_RUNNING

#define PWR_ISTR_PERIS_ALL_ACTIVE                 (0u)
#define PWR_ISTR_PERIS_IDLE_ENABLE_BIT            (1u)
#define PWR_ISTR_PERIS_DEFAULT                    PWR_ISTR_PERIS_ALL_ACTIVE

#define PWR_ISTR_CACHEIS_CACHE_ACTIVE             (0u)
#define PWR_ISTR_CACHEIS_CACHE_DISABLED           (1u)
#define PWR_ISTR_CACHEIS_DEFAULT                  PWR_ISTR_CACHEIS_CACHE_ACTIVE

#define PWR_ISTR_DMAIS_DMA_ACTIVE                 (0u)
#define PWR_ISTR_DMAIS_DMA_DISABLED               (1u)
#define PWR_ISTR_DMAIS_DEFAULT                    PWR_ISTR_DMAIS_DMA_ACTIVE

#define PWR_ISTR_CPUIS_CPU_ACTIVE                 (0u)
#define PWR_ISTR_CPUIS_CPU_DISABLED               (1u)
#define PWR_ISTR_CPUIS_DEFAULT                    PWR_ISTR_CPUIS_CPU_ACTIVE

/*---------------------------------------*\
* PWR_ISTR_MK Macro
\*---------------------------------------*/

#define PWR_ISTR_RMK(emifis, clkgenis, peris, cacheis, dmais,cpuis)\
(Uint16) ( PWR_FMK(ISTR,EMIFIS,emifis)|\
           PWR_FMK(ISTR,CLKGENIS,clkgenis)|\
           PWR_FMK(ISTR,PERIS,peris)|\
           PWR_FMK(ISTR,CACHEIS,cacheis)|\
           PWR_FMK(ISTR,DMAIS,dmais)|\
           PWR_FMK(ISTR,CPUIS,cpuis)\
)

#define PWR_ISTR_RMKS(emifis_s, clkgenis_s, peris_s, cacheis_s, dmais_s, cpuis_s)\
(Uint16) ( PWR_FMKS(ISTR,EMIFIS,emifis_s)|\
           PWR_FMKS(ISTR,CLKGENIS,clkgenis_s)|\
           PWR_FMKS(ISTR,PERIS,peris_s)|\
           PWR_FMKS(ISTR,CACHEIS,cacheis_s)|\
           PWR_FMKS(ISTR,DMAIS,dmais_s)|\
           PWR_FMKS(ISTR,CPUIS,cpuis_s)\
)



#define PWR_WAKEUP_MI                (1u)
#define PWR_WAKEUP_NMI               (0u)

/****************************************\
* PWR global typedef declarations
\****************************************/

/****************************************\
* PWR global variable declarations
\****************************************/

/****************************************\
* PWR global function declarations
\****************************************/

/****************************************\
* PWR inline function declarations
\****************************************/
IDECL void PWR_powerDown(Uint16 wakeUpMode);

/****************************************\
* PWR inline function definitions
\****************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
IDEF void PWR_powerDown(Uint16 wakeUpMode){
  if (wakeUpMode) {
    IRQ_globalEnable();
  }
  else {
    IRQ_globalDisable();
  }

  asm("\t IDLE   ;=====>NOTE: Automatic Cdoe Generated by CSL");
}

#endif /* USEDEFS */

#endif /* !CHIP_5502 || !CHIP_5501 */

#endif /* PWR_SUPPORT */
#endif /* _PWR_H_ */
/******************************************************************************\
* End of pwr.h
\******************************************************************************/

