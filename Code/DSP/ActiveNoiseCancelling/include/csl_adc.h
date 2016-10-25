/****************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved 
*------------------------------------------------------------------------------
* MODULE NAME... ADC
* FILENAME...... csl_adc.h
* DATE CREATED.. Fri Jun 29 15:39:48 2001
* PROJECT....... Chip Support Library
* COMPONENT..... Service Layer
* PREREQUISITS.. 
*------------------------------------------------------------------------------
*
* HISTORY:
*   Created:  Fri Jun 29 15:39:48 2001 (Automatic generation)
*   Modified: 01/24/2002 Changed ADCCCR references to ADCCTL in
*                        symbolic constants	
*
*------------------------------------------------------------------------------
* DESCRIPTION: CSL Service Layer interface for the ADC module 
*
\*************************************************************************/

#ifndef _CSL_ADC_H_
#define _CSL_ADC_H_

#include <_csl.h>
#include <csl_adchal.h>
	 

#if (_ADC_SUPPORT) 

/*----------------------------------------------------------------*\
*	 ADC scope and inline control macros 			
\*----------------------------------------------------------------*/

#ifdef __cplusplus
#define CSLAPI extern "C"
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _ADC_MOD_
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
* ADC global macro declarations
\****************************************/

/* error codes */
#define ADC_ERR_MAJOR		   (ERR_BASE_ADC) 
#define ADC_ERR_ALLOC		   (0x00000000) 
#define ADC_ERR_INVALID_HANDLE  (0x00000001) 

/* ============================================================== */
 /* Make ADCCLKCTL register values based on symbolic constants  */

#define ADC_ADCCLKCTL_RMK(idleen,cpuclkdiv)\
 ((Uint16) ( \
  ( ADC_FMK(ADCCLKCTL,IDLEEN,idleen))|\
  ( ADC_FMK(ADCCLKCTL,CPUCLKDIV,cpuclkdiv))\
)\
 )

#define ADC_ADCCLKCTL_RMKS(idleen_sym,cpuclkdiv_sym)\
 ((Uint16) ( \
  ( ADC_FMKS(ADCCLKCTL,IDLEEN,idleen_sym))|\
  ( ADC_FMKS(ADCCLKCTL,CPUCLKDIV,cpuclkdiv_sym))\
)\
 )

/*  Default ADCCLKCTL register value  */

#define ADC_ADCCLKCTL_IDLEEN_NOIDLE             (0x0000u)
#define ADC_ADCCLKCTL_IDLEEN_IDLE               (0x0001u)
#define ADC_ADCCLKCTL_IDLEEN_DEFAULT            ADC_ADCCLKTCTL_IDLEN_NOIDLE

/*  ADCCLKCTL field values  */


/* ============================================================== */
 /* Make ADCCLKDIV register values based on symbolic constants  */

#define ADC_ADCCLKDIV_RMK(samptimediv,convratediv)\
 ((Uint16) ( \
  ( ADC_FMK(ADCCLKDIV,SAMPTIMEDIV,samptimediv))|\
  ( ADC_FMK(ADCCLKDIV,CONVRATEDIV,convratediv))\
)\
 )

#define ADC_ADCCLKDIV_RMKS(samptimediv_sym,convratediv_sym)\
 ((Uint16) ( \
  ( ADC_FMKS(ADCCLKDIV,SAMPTIMEDIV,samptimediv_sym))|\
  ( ADC_FMKS(ADCCLKDIV,CONVRATEDIV,convratediv_sym))\
)\
 )

/*  Default ADCCLKDIV register value  */

/*  ADCCLKDIV field values  */


/* ============================================================== */
 /* Make ADCCTL register values based on symbolic constants  */

#define ADC_ADCCTL_RMK(adcstart,chselect)\
 ((Uint16) ( \
  ( ADC_FMK(ADCCTL,ADCSTART,adcstart))|\
  ( ADC_FMK(ADCCTL,CHSELECT,chselect))\
)\
 )

#define ADC_ADCCTL_RMKS(adcstart_sym,chselect_sym)\
 ((Uint16) ( \
  ( ADC_FMKS(ADCCTL,ADCSTART,adcstart_sym))|\
  ( ADC_FMKS(ADCCTL,CHSELECT,chselect_sym))\
)\
 )

/*  Default ADCCTL register value  */

/*  ADCCTL field values  */


/* ============================================================== */
 /* Make ADCDATA register values based on symbolic constants  */

#define ADC_ADCDATA_RMK(chselect)\
 ((Uint16) ( \
  ( ADC_FMK(ADCDATA,CHSELECT,chselect))\
)\
 )

#define ADC_ADCDATA_RMKS(chselect_sym)\
 ((Uint16) ( \
  ( ADC_FMKS(ADCDATA,CHSELECT,chselect_sym))\
)\
 )

/*  ADCCDR field values  */

	#define ADC_ADCCDR_CONVRATEDIV_2DIV			(000000u)
	#define ADC_ADCCDR_CONVRATEDIV_4DIV			(0x0001u)
	#define ADC_ADCCDR_CONVRATEDIV_6DIV			(0x0002u)
	#define ADC_ADCCDR_CONVRATEDIV_8DIV			(0x0003u)
	#define ADC_ADCCDR_CONVRATEDIV_10DIV		(0x0004u)
	#define ADC_ADCCDR_CONVRATEDIV_12DIV		(0x0005u)
	#define ADC_ADCCDR_CONVRATEDIV_14DIV		(0x0006u)
	#define ADC_ADCCDR_CONVRATEDIV_16DIV		(0x0007u)
	#define ADC_ADCCDR_CONVRATEDIV_18DIV		(0x0008u)
	#define ADC_ADCCDR_CONVRATEDIV_20DIV		(0x0009u)
	#define ADC_ADCCDR_CONVRATEDIV_22DIV		(0x000au)
	#define ADC_ADCCDR_CONVRATEDIV_24DIV		(0x000bu)
	#define ADC_ADCCDR_CONVRATEDIV_26DIV		(0x000cu)
	#define ADC_ADCCDR_CONVRATEDIV_28DIV		(0x000du)
	#define ADC_ADCCDR_CONVRATEDIV_30DIV		(0x000eu)
	#define ADC_ADCCDR_CONVRATEDIV_32DIV		(0x000fu)
	#define ADC_ADCCDR_CONVRATEDIV_DEFAULT		ADC_ADCCDR_CONVRATEDIV_2DIV

	#define ADC_ADCCDR_SAMPTIMEDIV_OF(x)         ((Uint16)(x))


/*  ADCCTL field values  */

	#define ADC_ADCCTL_ADCSTART_OFF			(000000u)
	#define ADC_ADCCTL_ADCSTART_ON			(0x0001u)
	#define ADC_ADCCTL_ADCSTART_DEFAULT		ADC_ADCCTL_ADCSTART_OFF

	#define ADC_ADCCTL_CHSELECT_AIN0			(000000u)
	#define ADC_ADCCTL_CHSELECT_AIN1			(0x0001u)
	#define ADC_ADCCTL_CHSELECT_AIN2			(0x0002u)
	#define ADC_ADCCTL_CHSELECT_AIN3			(0x0003u)
      #define ADC_ADCCTL_CHSELECT_OFF                 (0x0007u)
	#define ADC_ADCCTL_CHSELECT_DEFAULT		ADC_ADCCTL_CHSELECT_OFF

/*  ADCDR field values  */

	#define ADC_ADCDR_ADCBUSY_AVAIL			(000000u)
	#define ADC_ADCDR_ADCBUSY_BUSY			(0x0001u)
	#define ADC_ADCDR_ADCBUSY_DEFAULT		ADC_ADCDR_ADCBUSY_AVAIL

	#define ADC_ADCDR_CHSELECT_AIN0			(000000u)
	#define ADC_ADCDR_CHSELECT_AIN1			(0x0001u)
	#define ADC_ADCDR_CHSELECT_AIN2			(0x0002u)
	#define ADC_ADCDR_CHSELECT_AIN3			(0x0003u)
      #define ADC_ADCDR_CHSELECT_OFF                  (0x0007u)
	#define ADC_ADCDR_CHSELECT_DEFAULT		ADC_ADCDR_CHSELECT_OFF

/*  ADCCCR field values  */

	#define ADC_ADCCCR_IDLEEN_ACTIVE			(000000u)
	#define ADC_ADCCCR_IDLEEN_DISABLE		      (0x0001u)
	#define ADC_ADCCCR_IDLEEN_DEFAULT		ADC_ADCCCR_IDLEEN_ACTIVE

      #define ADC_ADCCCR_IDLEEN_NOIDLE                (0x0000u)
      #define ADC_ADCCCR_IDLEEN_IDLE                  (0x0001u)

	#define ADC_ADCCCR_CPUCLKDIV_OF(x)              ((Uint16)(x))

/*************************************************\
 ADC global typedef declarations 
\*************************************************/

typedef struct {
	Uint16 adcctl;
	Uint16 adcclkdiv;
	Uint16 adcclkctl;
} ADC_Config;

/*************************************************\
* ADC global variable declarations
\*************************************************/


/*************************************************\
* ADC global function declarations
\*************************************************/




IDECL void ADC_config(ADC_Config *myConfig);
IDECL void ADC_configArgs(Uint16 adcctl,Uint16 adcclkdiv,Uint16 adcclkctl);
IDECL void ADC_getConfig(ADC_Config *myConfig);
CSLAPI void ADC_setFreq(int sysclkdiv, int convratediv, int sampletimediv);
CSLAPI void ADC_read(int channelnumber,Uint16 *data,int length);

/*************************************************\
* ADC inline function declarations
\*************************************************/


#ifdef USEDEFS



/*----------------------------------------------------------------------------*/

IDEF void ADC_config(ADC_Config *Config) {

int old_intm;

  old_intm = IRQ_globalDisable();  
  ADC_RSET(ADCCTL,Config->adcctl);
  ADC_RSET(ADCCLKDIV,Config->adcclkdiv);
  ADC_RSET(ADCCLKCTL,Config->adcclkctl);
  IRQ_globalRestore(old_intm);   


}

IDEF void ADC_getConfig(ADC_Config *Config) {

  int old_intm;

  old_intm = IRQ_globalDisable();
  Config->adcctl = ADC_RGET(ADCCTL);
  Config->adcclkdiv = ADC_RGET(ADCCLKDIV);
  Config->adcclkctl = ADC_RGET(ADCCLKCTL);
  IRQ_globalRestore(old_intm);   


}


IDEF void ADC_configArgs(Uint16 adcctl,Uint16 adcclkdiv,Uint16 adcclkctl) {

int old_intm;

  old_intm = IRQ_globalDisable();  
  ADC_RSET(ADCCTL,adcctl);
  ADC_RSET(ADCCLKDIV,adcclkdiv);	
  ADC_RSET(ADCCLKCTL,adcclkctl);
  IRQ_globalRestore(old_intm);   



}



/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/

#endif /*USEDEFS */

#else
   #ifndef _ADC_MOD_
	#error ADC Hal Module Not Supported on Specified Target
   #endif
#endif  /* _ADC_SUPPORT  */

#endif  /* _CSL_ADCHAL_H  */

/******************************************************************************\
*     
*      End of csl_adc.h 
*
\******************************************************************************/
