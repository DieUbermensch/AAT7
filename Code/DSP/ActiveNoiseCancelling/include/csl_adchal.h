/****************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved 
*------------------------------------------------------------------------------
* MODULE NAME... ADC
* FILENAME...... csl_adchal.h
* DATE CREATED.. Fri Jun 29 15:39:48 2001
* PROJECT....... Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS.. 
*------------------------------------------------------------------------------
*
* HISTORY:
*	 Created:		Fri Jun 29 15:39:48 2001 (Automatic generation)
*	 Last Modified:	
*
*------------------------------------------------------------------------------
* DESCRIPTION: CSL HAL interface file for the ADC module 
*
* Registers covered:
*
* 		 Note: Add registers description here
*	 ADCCTL		- 
*	 ADCDATA		- 
*	 ADCCLKCTL		- 
*	 ADCCLKCTL		- 
*
\*************************************************************************/

#ifndef _CSL_ADCHAL_H_
#define _CSL_ADCHAL_H_

#include <csl_chiphal.h>

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
  #define USEDEFS
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

/*----------------------------------------------------------------*\
*		 Address Macros			
\*----------------------------------------------------------------*/

/*--------------------- Register: ADCCTL -----------------------*/
#define _ADC_ADCCTL_ADDR		(0x6800u)
#define _ADC_ADCCTL			PREG16(_ADC_ADCCTL_ADDR)
#define ADCCTL			_ADC_ADCCTL


/*--------------------- Register: ADCDATA -----------------------*/
#define _ADC_ADCDATA_ADDR		(0x6801u)
#define _ADC_ADCDATA			PREG16(_ADC_ADCDATA_ADDR)
#define ADCDATA			_ADC_ADCDATA


/*--------------------- Register: ADCCLKCTL -----------------------*/
#define _ADC_ADCCLKDIV_ADDR             (0x6802u)
#define _ADC_ADCCLKDIV                 PREG16(_ADC_ADCCLKDIV_ADDR)
#define ADCCLKDIV                       _ADC_ADCCLKDIV


/*--------------------- Register: ADCCLKCTL -----------------------*/
#define _ADC_ADCCLKCTL_ADDR		(0x6803u)
#define _ADC_ADCCLKCTL			PREG16(_ADC_ADCCLKCTL_ADDR)
#define ADCCLKCTL			_ADC_ADCCLKCTL



/*----------------------------------------------------------------*\
*		 Register Macros		
\*----------------------------------------------------------------*/

#define ADC_ADDR(Reg)		  _ADC_##Reg##_ADDR
#define ADC_RGET(Reg)		  _ADC_##Reg##_GET
#define ADC_RSET(Reg,Val)		  _ADC_##Reg##_SET(Val)
#define ADC_FGET(Reg,Field)		  _ADC_##Reg##_FGET(##Field)
#define ADC_FSET(Reg,Field,Val)		  _ADC_##Reg##_FSET(##Field, Val)
#define ADC_FMK(Reg,Field,Val)		  _ADC_##Reg##_##Field##_MK(Val)
#define ADC_RAOI(Reg,AND,OR,INV)		  _ADC_##Reg##_AOI(AND,OR,INV)
#define ADC_FAOI(Reg,Field,AND,OR,INV)	  _ADC_##Reg##_FAOI(##Field,AND,OR,INV)
#define ADC_FMKS(Reg,Field,Sym)\
	  _ADC_##Reg##_##Field##_MK(ADC_##Reg##_##Field##_##Sym)
#define ADC_FSETS(Reg,Field,Sym)\
	  _ADC_FSET(Reg,##Field,ADC_##Reg##_##Field##_##Sym)

/*----------------------------------------------------------------*\
*		 Non-handle Registers Macros		
\*----------------------------------------------------------------*/


/*--------------------- Register: ADCCTL -----------------------*/
#define _ADC_ADCCTL_GET		  _PREG_GET(_ADC_ADCCTL_ADDR) 
#define _ADC_ADCCTL_SET(Val)		  _PREG_SET(_ADC_ADCCTL_ADDR,Val)
#define _ADC_ADCCTL_FGET(Field)	  _PFIELD_GET(_ADC_ADCCTL_ADDR, _ADC_ADCCTL_##Field)
#define _ADC_ADCCTL_FSET(Field,Val)	  _PFIELD_SET(_ADC_ADCCTL_ADDR, _ADC_ADCCTL_##Field, Val)
#define _ADC_ADCCTL_AOI(AND,OR,INV)	  _PREG_AOI(_ADC_ADCCTL_ADDR,AND,OR,INV)
#define _ADC_ADCCTL_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_ADC_ADCCTL_ADDR, _ADC_ADCCTL_##Field,AND,OR,INV)


/*--------------------- Register: ADCDATA -----------------------*/
#define _ADC_ADCDATA_GET		  _PREG_GET(_ADC_ADCDATA_ADDR) 
#define _ADC_ADCDATA_SET(Val)		  _PREG_SET(_ADC_ADCDATA_ADDR,Val)
#define _ADC_ADCDATA_FGET(Field)	  _PFIELD_GET(_ADC_ADCDATA_ADDR, _ADC_ADCDATA_##Field)
#define _ADC_ADCDATA_FSET(Field,Val)	  _PFIELD_SET(_ADC_ADCDATA_ADDR, _ADC_ADCDATA_##Field, Val)
#define _ADC_ADCDATA_AOI(AND,OR,INV)	  _PREG_AOI(_ADC_ADCDATA_ADDR,AND,OR,INV)
#define _ADC_ADCDATA_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_ADC_ADCDATA_ADDR, _ADC_ADCDATA_##Field,AND,OR,INV)


/*--------------------- Register: ADCCLKCTL -----------------------*/
#define _ADC_ADCCLKCTL_GET		  _PREG_GET(_ADC_ADCCLKCTL_ADDR) 
#define _ADC_ADCCLKCTL_SET(Val)		  _PREG_SET(_ADC_ADCCLKCTL_ADDR,Val)
#define _ADC_ADCCLKCTL_FGET(Field)	  _PFIELD_GET(_ADC_ADCCLKCTL_ADDR, _ADC_ADCCLKCTL_##Field)
#define _ADC_ADCCLKCTL_FSET(Field,Val)	  _PFIELD_SET(_ADC_ADCCLKCTL_ADDR, _ADC_ADCCLKCTL_##Field, Val)
#define _ADC_ADCCLKCTL_AOI(AND,OR,INV)	  _PREG_AOI(_ADC_ADCCLKCTL_ADDR,AND,OR,INV)
#define _ADC_ADCCLKCTL_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_ADC_ADCCLKCTL_ADDR, _ADC_ADCCLKCTL_##Field,AND,OR,INV)


/*--------------------- Register: ADCCLKDIV -----------------------*/
#define _ADC_ADCCLKDIV_GET                _PREG_GET(_ADC_ADCCLKDIV_ADDR) 
#define _ADC_ADCCLKDIV_SET(Val)           _PREG_SET(_ADC_ADCCLKDIV_ADDR,Val)
#define _ADC_ADCCLKDIV_FGET(Field)        _PFIELD_GET(_ADC_ADCCLKDIV_ADDR, _ADC_ADCCLKDIV_##Field)
#define _ADC_ADCCLKDIV_FSET(Field,Val)    _PFIELD_SET(_ADC_ADCCLKDIV_ADDR, _ADC_ADCCLKDIV_##Field, Val)
#define _ADC_ADCCLKDIV_AOI(AND,OR,INV)    _PREG_AOI(_ADC_ADCCLKDIV_ADDR,AND,OR,INV)
#define _ADC_ADCCLKDIV_FAOI(Field,AND,OR,INV)\
        _PFIELD_AOI(_ADC_ADCCLKDIV_ADDR, _ADC_ADCCLKDIV_##Field,AND,OR,INV)



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the ADCCTL register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _ADC_ADCCTL	 - Note: Add description here
*
* Fields:
*	(RW)   _ADC_ADCCTL_CHSELECT	
*	(RW)   _ADC_ADCCTL_ADCSTART	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _ADC_ADCCTL_CHSELECT:	
\*----------------------------------------------------------------*/

#define _ADC_ADCCTL_CHSELECT_SHIFT		(0x000cu)
#define _ADC_ADCCTL_CHSELECT_MK(n)		(((Uint16)(n) & 0x0007u) << _ADC_ADCCTL_CHSELECT_SHIFT)
#define _ADC_ADCCTL_CHSELECT_MASK		(_ADC_ADCCTL_CHSELECT_MK(0x0007u))
#define _ADC_ADCCTL_CHSELECT_CLR		(~(_ADC_ADCCTL_CHSELECT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _ADC_ADCCTL_ADCSTART:	
\*----------------------------------------------------------------*/

#define _ADC_ADCCTL_ADCSTART_SHIFT		(0x000fu)
#define _ADC_ADCCTL_ADCSTART_MK(n)		(((Uint16)(n) & 0x0001u) << _ADC_ADCCTL_ADCSTART_SHIFT)
#define _ADC_ADCCTL_ADCSTART_MASK		(_ADC_ADCCTL_ADCSTART_MK(0x0001u))
#define _ADC_ADCCTL_ADCSTART_CLR		(~(_ADC_ADCCTL_ADCSTART_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the ADCDATA register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _ADC_ADCDATA	 - Note: Add description here
*
* Fields:
*	(R)   _ADC_ADCDATA_ADCDATA	
*	(RW)   _ADC_ADCDATA_CHSELECT	
*	(R)   _ADC_ADCDATA_ADCBUSY	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _ADC_ADCDATA_ADCDATA:	
\*----------------------------------------------------------------*/

#define _ADC_ADCDATA_ADCDATA_SHIFT		(000000u)
#define _ADC_ADCDATA_ADCDATA_MK(n)		(((Uint16)(n) & 0x03ffu) << _ADC_ADCDATA_ADCDATA_SHIFT)
#define _ADC_ADCDATA_ADCDATA_MASK		(_ADC_ADCDATA_ADCDATA_MK(0x03ffu))
#define _ADC_ADCDATA_ADCDATA_CLR		(~(_ADC_ADCDATA_ADCDATA_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _ADC_ADCDATA_CHSELECT:	
\*----------------------------------------------------------------*/

#define _ADC_ADCDATA_CHSELECT_SHIFT		(0x000cu)
#define _ADC_ADCDATA_CHSELECT_MK(n)		(((Uint16)(n) & 0x0007u) << _ADC_ADCDATA_CHSELECT_SHIFT)
#define _ADC_ADCDATA_CHSELECT_MASK		(_ADC_ADCDATA_CHSELECT_MK(0x0007u))
#define _ADC_ADCDATA_CHSELECT_CLR		(~(_ADC_ADCDATA_CHSELECT_MASK))



/*----------------------------------------------------------------*\
*   (R)  _ADC_ADCDATA_ADCBUSY:	
\*----------------------------------------------------------------*/

#define _ADC_ADCDATA_ADCBUSY_SHIFT		(0x000fu)
#define _ADC_ADCDATA_ADCBUSY_MK(n)		(((Uint16)(n) & 0x0001u) << _ADC_ADCDATA_ADCBUSY_SHIFT)
#define _ADC_ADCDATA_ADCBUSY_MASK		(_ADC_ADCDATA_ADCBUSY_MK(0x0001u))
#define _ADC_ADCDATA_ADCBUSY_CLR		(~(_ADC_ADCDATA_ADCBUSY_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the ADCCLKCTL register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _ADC_ADCCLKCTL	 - Note: Add description here
*
* Fields:
*       (RW)   _ADC_ADCCLKCTL_CPUCLKDIV 
*	(RW)   _ADC_ADCCLKCTL_IDLEEN	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _ADC_ADCCLKCTL_CPUCLKDIV: 
\*----------------------------------------------------------------*/

#define _ADC_ADCCLKCTL_CPUCLKDIV_SHIFT               (000000u)
#define _ADC_ADCCLKCTL_CPUCLKDIV_MK(n)               (((Uint16)(n) & 0x00ffu) << _ADC_ADCCLKCTL_CPUCLKDIV_SHIFT)
#define _ADC_ADCCLKCTL_CPUCLKDIV_MASK                (_ADC_ADCCLKCTL_CPUCLKDIV_MK(0x00ffu))
#define _ADC_ADCCLKCTL_CPUCLKDIV_CLR         (~(_ADC_ADCCLKCTL_CPUCLKDIV_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _ADC_ADCCLKCTL_IDLEEN:	
\*----------------------------------------------------------------*/

#define _ADC_ADCCLKCTL_IDLEEN_SHIFT		(0x0008u)
#define _ADC_ADCCLKCTL_IDLEEN_MK(n)		(((Uint16)(n) & 0x0001u) << _ADC_ADCCLKCTL_IDLEEN_SHIFT)
#define _ADC_ADCCLKCTL_IDLEEN_MASK		(_ADC_ADCCLKCTL_IDLEEN_MK(0x0001u))
#define _ADC_ADCCLKCTL_IDLEEN_CLR		(~(_ADC_ADCCLKCTL_IDLEEN_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the ADCCLKDIV register                
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _ADC_ADCCLKDIV         - Note: Add description here
*
* Fields:
*       (RW)   _ADC_ADCCLKDIV_CONVRATEDIV 
*       (RW)   _ADC_ADCCLKDIV_SAMPTIMEDIV 
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _ADC_ADCCLKDIV_CONVRATEDIV: 
\*----------------------------------------------------------------*/

#define _ADC_ADCCLKDIV_CONVRATEDIV_SHIFT                (000000u)
#define _ADC_ADCCLKDIV_CONVRATEDIV_MK(n)                (((Uint16)(n) & 0x001fu) << _ADC_ADCCLKDIV_CONVRATEDIV_SHIFT)
#define _ADC_ADCCLKDIV_CONVRATEDIV_MASK         (_ADC_ADCCLKDIV_CONVRATEDIV_MK(0x001fu))
#define _ADC_ADCCLKDIV_CONVRATEDIV_CLR          (~(_ADC_ADCCLKDIV_CONVRATEDIV_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _ADC_ADCCLKDIV_SAMPTIMEDIV: 
\*----------------------------------------------------------------*/

#define _ADC_ADCCLKDIV_SAMPTIMEDIV_SHIFT                (0x0008u)
#define _ADC_ADCCLKDIV_SAMPTIMEDIV_MK(n)                (((Uint16)(n) & 0x000fu) << _ADC_ADCCLKDIV_SAMPTIMEDIV_SHIFT)
#define _ADC_ADCCLKDIV_SAMPTIMEDIV_MASK         (_ADC_ADCCLKDIV_SAMPTIMEDIV_MK(0x000fu))
#define _ADC_ADCCLKDIV_SAMPTIMEDIV_CLR          (~(_ADC_ADCCLKDIV_SAMPTIMEDIV_MASK))


#else
   #ifndef _ADC_MOD_
	#error ADC Hal Module Not Supported on Specified Target
   #endif
#endif  /* _ADC_SUPPORT  */

#endif  /* _CSL_ADCHAL_H  */

/******************************************************************************\
*     
*      End of csl_ADChal.h 
*
\******************************************************************************/
