/****************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved 
*------------------------------------------------------------------------------
* MODULE NAME... RTC
* FILENAME...... csl_rtchal.h
* DATE CREATED.. Tue Apr 10 11:04:35 2001
* PROJECT....... Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS.. 
*------------------------------------------------------------------------------
*
* HISTORY:
*	 Created:		Tue Apr 10 11:04:35 2001 (Automatic generation)
*	 Last Modified:	
*
*------------------------------------------------------------------------------
* DESCRIPTION:	CSL HAL interface file for the RTC module 
*			Re-created to reflect the changes in the RTC documentation version 2.8
*
* Registers covered:
*
*	 RTCSEC		- Seconds
*	 RTCSECA		- Alarm Seconds
*	 RTCMIN		- Minutes
*	 RTCMINA		- Alarm Minutes
*	 RTCHOUR		- Hours
*	 RTCHOURA		- Alarm Hours
*	 RTCDAYW		- Day of the Week and Alarm Day of the Week
*	 RTCDAYM		- Day of month (date)
*	 RTCMONTH		- Month
*	 RTCYEAR		- Year
*	 RTCPINTR		- RTC Periodic Interrupt Selection
*	 RTCINTEN		- RTC Interrupt Enable
*	 RTCINTFL		- RTC Interrupt Flags
*
\*************************************************************************/

#ifndef _CSL_RTCHAL_H_
#define _CSL_RTCHAL_H_

#include <csl_chiphal.h>

#if (_RTC_SUPPORT) 

/*----------------------------------------------------------------*\
*	 RTC scope and inline control macros 			
\*----------------------------------------------------------------*/

#ifdef __cplusplus
#define CSLAPI extern "C"
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _RTC_MOD_
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

/*--------------------- Register: RTCSEC -----------------------*/
#define _RTC_RTCSEC_ADDR		(0x1800u)
#define _RTC_RTCSEC			PREG16(_RTC_RTCSEC_ADDR)
#define RTCSEC			_RTC_RTCSEC


/*--------------------- Register: RTCSECA -----------------------*/
#define _RTC_RTCSECA_ADDR		(0x1801u)
#define _RTC_RTCSECA			PREG16(_RTC_RTCSECA_ADDR)
#define RTCSECA			_RTC_RTCSECA


/*--------------------- Register: RTCMIN -----------------------*/
#define _RTC_RTCMIN_ADDR		(0x1802u)
#define _RTC_RTCMIN			PREG16(_RTC_RTCMIN_ADDR)
#define RTCMIN			_RTC_RTCMIN


/*--------------------- Register: RTCMINA -----------------------*/
#define _RTC_RTCMINA_ADDR		(0x1803u)
#define _RTC_RTCMINA			PREG16(_RTC_RTCMINA_ADDR)
#define RTCMINA			_RTC_RTCMINA


/*--------------------- Register: RTCHOUR -----------------------*/
#define _RTC_RTCHOUR_ADDR		(0x1804u)
#define _RTC_RTCHOUR			PREG16(_RTC_RTCHOUR_ADDR)
#define RTCHOUR			_RTC_RTCHOUR


/*--------------------- Register: RTCHOURA -----------------------*/
#define _RTC_RTCHOURA_ADDR		(0x1805u)
#define _RTC_RTCHOURA			PREG16(_RTC_RTCHOURA_ADDR)
#define RTCHOURA			_RTC_RTCHOURA


/*--------------------- Register: RTCDAYW -----------------------*/
#define _RTC_RTCDAYW_ADDR		(0x1806u)
#define _RTC_RTCDAYW			PREG16(_RTC_RTCDAYW_ADDR)
#define RTCDAYW			_RTC_RTCDAYW


/*--------------------- Register: RTCDAYM -----------------------*/
#define _RTC_RTCDAYM_ADDR		(0x1807u)
#define _RTC_RTCDAYM			PREG16(_RTC_RTCDAYM_ADDR)
#define RTCDAYM			_RTC_RTCDAYM


/*--------------------- Register: RTCMONTH -----------------------*/
#define _RTC_RTCMONTH_ADDR		(0x1808u)
#define _RTC_RTCMONTH			PREG16(_RTC_RTCMONTH_ADDR)
#define RTCMONTH			_RTC_RTCMONTH


/*--------------------- Register: RTCYEAR -----------------------*/
#define _RTC_RTCYEAR_ADDR		(0x1809u)
#define _RTC_RTCYEAR			PREG16(_RTC_RTCYEAR_ADDR)
#define RTCYEAR			_RTC_RTCYEAR


/*--------------------- Register: RTCPINTR -----------------------*/
#define _RTC_RTCPINTR_ADDR		(0x180au)
#define _RTC_RTCPINTR			PREG16(_RTC_RTCPINTR_ADDR)
#define RTCPINTR			_RTC_RTCPINTR


/*--------------------- Register: RTCINTEN -----------------------*/
#define _RTC_RTCINTEN_ADDR		(0x180bu)
#define _RTC_RTCINTEN			PREG16(_RTC_RTCINTEN_ADDR)
#define RTCINTEN			_RTC_RTCINTEN


/*--------------------- Register: RTCINTFL -----------------------*/
#define _RTC_RTCINTFL_ADDR		(0x180cu)
#define _RTC_RTCINTFL			PREG16(_RTC_RTCINTFL_ADDR)
#define RTCINTFL			_RTC_RTCINTFL



/*----------------------------------------------------------------*\
*		 Register Macros		
\*----------------------------------------------------------------*/

#define RTC_ADDR(Reg)		  _RTC_##Reg##_ADDR
#define RTC_RGET(Reg)		  _RTC_##Reg##_GET
#define RTC_RSET(Reg,Val)		  _RTC_##Reg##_SET(Val)
#define RTC_FGET(Reg,Field)		  _RTC_##Reg##_FGET(##Field)
#define RTC_FSET(Reg,Field,Val)		  _RTC_##Reg##_FSET(##Field, Val)
#define RTC_FMK(Reg,Field,Val)		  _RTC_##Reg##_##Field##_MK(Val)
#define RTC_RAOI(Reg,AND,OR,INV)		  _RTC_##Reg##_AOI(AND,OR,INV)
#define RTC_FAOI(Reg,Field,AND,OR,INV)	  _RTC_##Reg##_FAOI(##Field,AND,OR,INV)
#define RTC_FMKS(Reg,Field,Sym)\
	  _RTC_##Reg##_##Field##_MK(RTC_##Reg##_##Field##_##Sym)
#define RTC_FSETS(Reg,Field,Sym)\
	  _RTC_FSET(##Reg,##Field,RTC_##Reg##_##Field##_##Sym)

/*----------------------------------------------------------------*\
*		 Non-handle Registers Macros		
\*----------------------------------------------------------------*/


/*--------------------- Register: RTCSEC -----------------------*/
#define _RTC_RTCSEC_GET		  _PREG_GET(_RTC_RTCSEC_ADDR) 
#define _RTC_RTCSEC_SET(Val)		  _PREG_SET(_RTC_RTCSEC_ADDR,Val)
#define _RTC_RTCSEC_FGET(Field)	  _PFIELD_GET(_RTC_RTCSEC_ADDR, _RTC_RTCSEC_##Field)
#define _RTC_RTCSEC_FSET(Field,Val)	  _PFIELD_SET(_RTC_RTCSEC_ADDR, _RTC_RTCSEC_##Field, Val)
#define _RTC_RTCSEC_AOI(AND,OR,INV)	  _PREG_AOI(_RTC_RTCSEC_ADDR,AND,OR,INV)
#define _RTC_RTCSEC_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_RTC_RTCSEC_ADDR, _RTC_RTCSEC_##Field,AND,OR,INV)


/*--------------------- Register: RTCSECA -----------------------*/
#define _RTC_RTCSECA_GET		  _PREG_GET(_RTC_RTCSECA_ADDR) 
#define _RTC_RTCSECA_SET(Val)		  _PREG_SET(_RTC_RTCSECA_ADDR,Val)
#define _RTC_RTCSECA_FGET(Field)	  _PFIELD_GET(_RTC_RTCSECA_ADDR, _RTC_RTCSECA_##Field)
#define _RTC_RTCSECA_FSET(Field,Val)	  _PFIELD_SET(_RTC_RTCSECA_ADDR, _RTC_RTCSECA_##Field, Val)
#define _RTC_RTCSECA_AOI(AND,OR,INV)	  _PREG_AOI(_RTC_RTCSECA_ADDR,AND,OR,INV)
#define _RTC_RTCSECA_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_RTC_RTCSECA_ADDR, _RTC_RTCSECA_##Field,AND,OR,INV)


/*--------------------- Register: RTCMIN -----------------------*/
#define _RTC_RTCMIN_GET		  _PREG_GET(_RTC_RTCMIN_ADDR) 
#define _RTC_RTCMIN_SET(Val)		  _PREG_SET(_RTC_RTCMIN_ADDR,Val)
#define _RTC_RTCMIN_FGET(Field)	  _PFIELD_GET(_RTC_RTCMIN_ADDR, _RTC_RTCMIN_##Field)
#define _RTC_RTCMIN_FSET(Field,Val)	  _PFIELD_SET(_RTC_RTCMIN_ADDR, _RTC_RTCMIN_##Field, Val)
#define _RTC_RTCMIN_AOI(AND,OR,INV)	  _PREG_AOI(_RTC_RTCMIN_ADDR,AND,OR,INV)
#define _RTC_RTCMIN_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_RTC_RTCMIN_ADDR, _RTC_RTCMIN_##Field,AND,OR,INV)


/*--------------------- Register: RTCMINA -----------------------*/
#define _RTC_RTCMINA_GET		  _PREG_GET(_RTC_RTCMINA_ADDR) 
#define _RTC_RTCMINA_SET(Val)		  _PREG_SET(_RTC_RTCMINA_ADDR,Val)
#define _RTC_RTCMINA_FGET(Field)	  _PFIELD_GET(_RTC_RTCMINA_ADDR, _RTC_RTCMINA_##Field)
#define _RTC_RTCMINA_FSET(Field,Val)	  _PFIELD_SET(_RTC_RTCMINA_ADDR, _RTC_RTCMINA_##Field, Val)
#define _RTC_RTCMINA_AOI(AND,OR,INV)	  _PREG_AOI(_RTC_RTCMINA_ADDR,AND,OR,INV)
#define _RTC_RTCMINA_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_RTC_RTCMINA_ADDR, _RTC_RTCMINA_##Field,AND,OR,INV)


/*--------------------- Register: RTCHOUR -----------------------*/
#define _RTC_RTCHOUR_GET		  _PREG_GET(_RTC_RTCHOUR_ADDR) 
#define _RTC_RTCHOUR_SET(Val)		  _PREG_SET(_RTC_RTCHOUR_ADDR,Val)
#define _RTC_RTCHOUR_FGET(Field)	  _PFIELD_GET(_RTC_RTCHOUR_ADDR, _RTC_RTCHOUR_##Field)
#define _RTC_RTCHOUR_FSET(Field,Val)	  _PFIELD_SET(_RTC_RTCHOUR_ADDR, _RTC_RTCHOUR_##Field, Val)
#define _RTC_RTCHOUR_AOI(AND,OR,INV)	  _PREG_AOI(_RTC_RTCHOUR_ADDR,AND,OR,INV)
#define _RTC_RTCHOUR_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_RTC_RTCHOUR_ADDR, _RTC_RTCHOUR_##Field,AND,OR,INV)


/*--------------------- Register: RTCHOURA -----------------------*/
#define _RTC_RTCHOURA_GET		  _PREG_GET(_RTC_RTCHOURA_ADDR) 
#define _RTC_RTCHOURA_SET(Val)		  _PREG_SET(_RTC_RTCHOURA_ADDR,Val)
#define _RTC_RTCHOURA_FGET(Field)	  _PFIELD_GET(_RTC_RTCHOURA_ADDR, _RTC_RTCHOURA_##Field)
#define _RTC_RTCHOURA_FSET(Field,Val)	  _PFIELD_SET(_RTC_RTCHOURA_ADDR, _RTC_RTCHOURA_##Field, Val)
#define _RTC_RTCHOURA_AOI(AND,OR,INV)	  _PREG_AOI(_RTC_RTCHOURA_ADDR,AND,OR,INV)
#define _RTC_RTCHOURA_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_RTC_RTCHOURA_ADDR, _RTC_RTCHOURA_##Field,AND,OR,INV)


/*--------------------- Register: RTCDAYW -----------------------*/
#define _RTC_RTCDAYW_GET		  _PREG_GET(_RTC_RTCDAYW_ADDR) 
#define _RTC_RTCDAYW_SET(Val)		  _PREG_SET(_RTC_RTCDAYW_ADDR,Val)
#define _RTC_RTCDAYW_FGET(Field)	  _PFIELD_GET(_RTC_RTCDAYW_ADDR, _RTC_RTCDAYW_##Field)
#define _RTC_RTCDAYW_FSET(Field,Val)	  _PFIELD_SET(_RTC_RTCDAYW_ADDR, _RTC_RTCDAYW_##Field, Val)
#define _RTC_RTCDAYW_AOI(AND,OR,INV)	  _PREG_AOI(_RTC_RTCDAYW_ADDR,AND,OR,INV)
#define _RTC_RTCDAYW_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_RTC_RTCDAYW_ADDR, _RTC_RTCDAYW_##Field,AND,OR,INV)


/*--------------------- Register: RTCDAYM -----------------------*/
#define _RTC_RTCDAYM_GET		  _PREG_GET(_RTC_RTCDAYM_ADDR) 
#define _RTC_RTCDAYM_SET(Val)		  _PREG_SET(_RTC_RTCDAYM_ADDR,Val)
#define _RTC_RTCDAYM_FGET(Field)	  _PFIELD_GET(_RTC_RTCDAYM_ADDR, _RTC_RTCDAYM_##Field)
#define _RTC_RTCDAYM_FSET(Field,Val)	  _PFIELD_SET(_RTC_RTCDAYM_ADDR, _RTC_RTCDAYM_##Field, Val)
#define _RTC_RTCDAYM_AOI(AND,OR,INV)	  _PREG_AOI(_RTC_RTCDAYM_ADDR,AND,OR,INV)
#define _RTC_RTCDAYM_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_RTC_RTCDAYM_ADDR, _RTC_RTCDAYM_##Field,AND,OR,INV)


/*--------------------- Register: RTCMONTH -----------------------*/
#define _RTC_RTCMONTH_GET		  _PREG_GET(_RTC_RTCMONTH_ADDR) 
#define _RTC_RTCMONTH_SET(Val)		  _PREG_SET(_RTC_RTCMONTH_ADDR,Val)
#define _RTC_RTCMONTH_FGET(Field)	  _PFIELD_GET(_RTC_RTCMONTH_ADDR, _RTC_RTCMONTH_##Field)
#define _RTC_RTCMONTH_FSET(Field,Val)	  _PFIELD_SET(_RTC_RTCMONTH_ADDR, _RTC_RTCMONTH_##Field, Val)
#define _RTC_RTCMONTH_AOI(AND,OR,INV)	  _PREG_AOI(_RTC_RTCMONTH_ADDR,AND,OR,INV)
#define _RTC_RTCMONTH_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_RTC_RTCMONTH_ADDR, _RTC_RTCMONTH_##Field,AND,OR,INV)


/*--------------------- Register: RTCYEAR -----------------------*/
#define _RTC_RTCYEAR_GET		  _PREG_GET(_RTC_RTCYEAR_ADDR) 
#define _RTC_RTCYEAR_SET(Val)		  _PREG_SET(_RTC_RTCYEAR_ADDR,Val)
#define _RTC_RTCYEAR_FGET(Field)	  _PFIELD_GET(_RTC_RTCYEAR_ADDR, _RTC_RTCYEAR_##Field)
#define _RTC_RTCYEAR_FSET(Field,Val)	  _PFIELD_SET(_RTC_RTCYEAR_ADDR, _RTC_RTCYEAR_##Field, Val)
#define _RTC_RTCYEAR_AOI(AND,OR,INV)	  _PREG_AOI(_RTC_RTCYEAR_ADDR,AND,OR,INV)
#define _RTC_RTCYEAR_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_RTC_RTCYEAR_ADDR, _RTC_RTCYEAR_##Field,AND,OR,INV)


/*--------------------- Register: RTCPINTR -----------------------*/
#define _RTC_RTCPINTR_GET		  _PREG_GET(_RTC_RTCPINTR_ADDR) 
#define _RTC_RTCPINTR_SET(Val)		  _PREG_SET(_RTC_RTCPINTR_ADDR,Val)
#define _RTC_RTCPINTR_FGET(Field)	  _PFIELD_GET(_RTC_RTCPINTR_ADDR, _RTC_RTCPINTR_##Field)
#define _RTC_RTCPINTR_FSET(Field,Val)	  _PFIELD_SET(_RTC_RTCPINTR_ADDR, _RTC_RTCPINTR_##Field, Val)
#define _RTC_RTCPINTR_AOI(AND,OR,INV)	  _PREG_AOI(_RTC_RTCPINTR_ADDR,AND,OR,INV)
#define _RTC_RTCPINTR_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_RTC_RTCPINTR_ADDR, _RTC_RTCPINTR_##Field,AND,OR,INV)


/*--------------------- Register: RTCINTEN -----------------------*/
#define _RTC_RTCINTEN_GET		  _PREG_GET(_RTC_RTCINTEN_ADDR) 
#define _RTC_RTCINTEN_SET(Val)		  _PREG_SET(_RTC_RTCINTEN_ADDR,Val)
#define _RTC_RTCINTEN_FGET(Field)	  _PFIELD_GET(_RTC_RTCINTEN_ADDR, _RTC_RTCINTEN_##Field)
#define _RTC_RTCINTEN_FSET(Field,Val)	  _PFIELD_SET(_RTC_RTCINTEN_ADDR, _RTC_RTCINTEN_##Field, Val)
#define _RTC_RTCINTEN_AOI(AND,OR,INV)	  _PREG_AOI(_RTC_RTCINTEN_ADDR,AND,OR,INV)
#define _RTC_RTCINTEN_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_RTC_RTCINTEN_ADDR, _RTC_RTCINTEN_##Field,AND,OR,INV)


/*--------------------- Register: RTCINTFL -----------------------*/
#define _RTC_RTCINTFL_GET		  _PREG_GET(_RTC_RTCINTFL_ADDR) 
#define _RTC_RTCINTFL_SET(Val)		  _PREG_SET(_RTC_RTCINTFL_ADDR,Val)
#define _RTC_RTCINTFL_FGET(Field)	  _PFIELD_GET(_RTC_RTCINTFL_ADDR, _RTC_RTCINTFL_##Field)
#define _RTC_RTCINTFL_FSET(Field,Val)	  _PFIELD_SET(_RTC_RTCINTFL_ADDR, _RTC_RTCINTFL_##Field, Val)
#define _RTC_RTCINTFL_AOI(AND,OR,INV)	  _PREG_AOI(_RTC_RTCINTFL_ADDR,AND,OR,INV)
#define _RTC_RTCINTFL_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_RTC_RTCINTFL_ADDR, _RTC_RTCINTFL_##Field,AND,OR,INV)



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the RTCINTFL register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _RTC_RTCINTFL	 - Note: Add description here
*
* Fields:
*	(RW)   _RTC_RTCINTFL_UF	
*	(RW)   _RTC_RTCINTFL_AF	
*	(RW)   _RTC_RTCINTFL_PF	
*	(R)   _RTC_RTCINTFL_IRQF	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCINTFL_UF:	
\*----------------------------------------------------------------*/

#define _RTC_RTCINTFL_UF_SHIFT		(0x0004u)
#define _RTC_RTCINTFL_UF_MK(n)		(((Uint16)(n) & 0x0001u) << _RTC_RTCINTFL_UF_SHIFT)
#define _RTC_RTCINTFL_UF_MASK		(_RTC_RTCINTFL_UF_MK(0x0001u))
#define _RTC_RTCINTFL_UF_CLR		(~(_RTC_RTCINTFL_UF_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCINTFL_AF:	
\*----------------------------------------------------------------*/

#define _RTC_RTCINTFL_AF_SHIFT		(0x0005u)
#define _RTC_RTCINTFL_AF_MK(n)		(((Uint16)(n) & 0x0001u) << _RTC_RTCINTFL_AF_SHIFT)
#define _RTC_RTCINTFL_AF_MASK		(_RTC_RTCINTFL_AF_MK(0x0001u))
#define _RTC_RTCINTFL_AF_CLR		(~(_RTC_RTCINTFL_AF_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCINTFL_PF:	
\*----------------------------------------------------------------*/

#define _RTC_RTCINTFL_PF_SHIFT		(0x0006u)
#define _RTC_RTCINTFL_PF_MK(n)		(((Uint16)(n) & 0x0001u) << _RTC_RTCINTFL_PF_SHIFT)
#define _RTC_RTCINTFL_PF_MASK		(_RTC_RTCINTFL_PF_MK(0x0001u))
#define _RTC_RTCINTFL_PF_CLR		(~(_RTC_RTCINTFL_PF_MASK))



/*----------------------------------------------------------------*\
*   (R)  _RTC_RTCINTFL_IRQF:	
\*----------------------------------------------------------------*/

#define _RTC_RTCINTFL_IRQF_SHIFT		(0x0007u)
#define _RTC_RTCINTFL_IRQF_MK(n)		(((Uint16)(n) & 0x0001u) << _RTC_RTCINTFL_IRQF_SHIFT)
#define _RTC_RTCINTFL_IRQF_MASK		(_RTC_RTCINTFL_IRQF_MK(0x0001u))
#define _RTC_RTCINTFL_IRQF_CLR		(~(_RTC_RTCINTFL_IRQF_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the RTCINTEN register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _RTC_RTCINTEN	 - Note: Add description here
*
* Fields:
*	(RW)   _RTC_RTCINTEN_TM	
*	(RW)   _RTC_RTCINTEN_UIE	
*	(RW)   _RTC_RTCINTEN_AIE	
*	(RW)   _RTC_RTCINTEN_PIE	
*	(RW)   _RTC_RTCINTEN_SET	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCINTEN_TM:	
\*----------------------------------------------------------------*/

#define _RTC_RTCINTEN_TM_SHIFT		(0x0001u)
#define _RTC_RTCINTEN_TM_MK(n)		(((Uint16)(n) & 0x0001u) << _RTC_RTCINTEN_TM_SHIFT)
#define _RTC_RTCINTEN_TM_MASK		(_RTC_RTCINTEN_TM_MK(0x0001u))
#define _RTC_RTCINTEN_TM_CLR		(~(_RTC_RTCINTEN_TM_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCINTEN_UIE:	
\*----------------------------------------------------------------*/

#define _RTC_RTCINTEN_UIE_SHIFT		(0x0004u)
#define _RTC_RTCINTEN_UIE_MK(n)		(((Uint16)(n) & 0x0001u) << _RTC_RTCINTEN_UIE_SHIFT)
#define _RTC_RTCINTEN_UIE_MASK		(_RTC_RTCINTEN_UIE_MK(0x0001u))
#define _RTC_RTCINTEN_UIE_CLR		(~(_RTC_RTCINTEN_UIE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCINTEN_AIE:	
\*----------------------------------------------------------------*/

#define _RTC_RTCINTEN_AIE_SHIFT		(0x0005u)
#define _RTC_RTCINTEN_AIE_MK(n)		(((Uint16)(n) & 0x0001u) << _RTC_RTCINTEN_AIE_SHIFT)
#define _RTC_RTCINTEN_AIE_MASK		(_RTC_RTCINTEN_AIE_MK(0x0001u))
#define _RTC_RTCINTEN_AIE_CLR		(~(_RTC_RTCINTEN_AIE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCINTEN_PIE:	
\*----------------------------------------------------------------*/

#define _RTC_RTCINTEN_PIE_SHIFT		(0x0006u)
#define _RTC_RTCINTEN_PIE_MK(n)		(((Uint16)(n) & 0x0001u) << _RTC_RTCINTEN_PIE_SHIFT)
#define _RTC_RTCINTEN_PIE_MASK		(_RTC_RTCINTEN_PIE_MK(0x0001u))
#define _RTC_RTCINTEN_PIE_CLR		(~(_RTC_RTCINTEN_PIE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCINTEN_SET:	
\*----------------------------------------------------------------*/

#define _RTC_RTCINTEN_SET_SHIFT		(0x0007u)
#define _RTC_RTCINTEN_SET_MK(n)		(((Uint16)(n) & 0x0001u) << _RTC_RTCINTEN_SET_SHIFT)
#define _RTC_RTCINTEN_SET_MASK		(_RTC_RTCINTEN_SET_MK(0x0001u))
#define _RTC_RTCINTEN_SET_CLR		(~(_RTC_RTCINTEN_SET_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the RTCDAYM register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _RTC_RTCDAYM	 - Note: Add description here
*
* Fields:
*	(RW)   _RTC_RTCDAYM_DATE	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCDAYM_DATE:	
\*----------------------------------------------------------------*/

#define _RTC_RTCDAYM_DATE_SHIFT		(000000u)
#define _RTC_RTCDAYM_DATE_MK(n)		(((Uint16)(n) & 0x003fu) << _RTC_RTCDAYM_DATE_SHIFT)
#define _RTC_RTCDAYM_DATE_MASK		(_RTC_RTCDAYM_DATE_MK(0x003fu))
#define _RTC_RTCDAYM_DATE_CLR		(~(_RTC_RTCDAYM_DATE_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the RTCSECA register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _RTC_RTCSECA	 - Note: Add description here
*
* Fields:
*	(RW)   _RTC_RTCSECA_SAR	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCSECA_SAR:	
\*----------------------------------------------------------------*/

#define _RTC_RTCSECA_SAR_SHIFT		(000000u)
#define _RTC_RTCSECA_SAR_MK(n)		(((Uint16)(n) & 0x00ffu) << _RTC_RTCSECA_SAR_SHIFT)
#define _RTC_RTCSECA_SAR_MASK		(_RTC_RTCSECA_SAR_MK(0x00ffu))
#define _RTC_RTCSECA_SAR_CLR		(~(_RTC_RTCSECA_SAR_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the RTCYEAR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _RTC_RTCYEAR	 - Note: Add description here
*
* Fields:
*	(RW)   _RTC_RTCYEAR_YEAR	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCYEAR_YEAR:	
\*----------------------------------------------------------------*/

#define _RTC_RTCYEAR_YEAR_SHIFT		(000000u)
#define _RTC_RTCYEAR_YEAR_MK(n)		(((Uint16)(n) & 0x00ffu) << _RTC_RTCYEAR_YEAR_SHIFT)
#define _RTC_RTCYEAR_YEAR_MASK		(_RTC_RTCYEAR_YEAR_MK(0x00ffu))
#define _RTC_RTCYEAR_YEAR_CLR		(~(_RTC_RTCYEAR_YEAR_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the RTCHOUR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _RTC_RTCHOUR	 - Note: Add description here
*
* Fields:
*	(RW)   _RTC_RTCHOUR_HR	
*	(RW)   _RTC_RTCHOUR_AMPM	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCHOUR_HR:	
\*----------------------------------------------------------------*/

#define _RTC_RTCHOUR_HR_SHIFT		(000000u)
#define _RTC_RTCHOUR_HR_MK(n)		(((Uint16)(n) & 0x003fu) << _RTC_RTCHOUR_HR_SHIFT)
#define _RTC_RTCHOUR_HR_MASK		(_RTC_RTCHOUR_HR_MK(0x003fu))
#define _RTC_RTCHOUR_HR_CLR		(~(_RTC_RTCHOUR_HR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCHOUR_AMPM:	
\*----------------------------------------------------------------*/

#define _RTC_RTCHOUR_AMPM_SHIFT		(0x0007u)
#define _RTC_RTCHOUR_AMPM_MK(n)		(((Uint16)(n) & 0x0001u) << _RTC_RTCHOUR_AMPM_SHIFT)
#define _RTC_RTCHOUR_AMPM_MASK		(_RTC_RTCHOUR_AMPM_MK(0x0001u))
#define _RTC_RTCHOUR_AMPM_CLR		(~(_RTC_RTCHOUR_AMPM_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the RTCMINA register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _RTC_RTCMINA	 - Note: Add description here
*
* Fields:
*	(RW)   _RTC_RTCMINA_MAR	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCMINA_MAR:	
\*----------------------------------------------------------------*/

#define _RTC_RTCMINA_MAR_SHIFT		(000000u)
#define _RTC_RTCMINA_MAR_MK(n)		(((Uint16)(n) & 0x00ffu) << _RTC_RTCMINA_MAR_SHIFT)
#define _RTC_RTCMINA_MAR_MASK		(_RTC_RTCMINA_MAR_MK(0x00ffu))
#define _RTC_RTCMINA_MAR_CLR		(~(_RTC_RTCMINA_MAR_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the RTCDAYW register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _RTC_RTCDAYW	 - Note: Add description here
*
* Fields:
*	(RW)   _RTC_RTCDAYW_DAY	
*	(RW)   _RTC_RTCDAYW_DAEN	
*	(RW)   _RTC_RTCDAYW_DAR	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCDAYW_DAY:	
\*----------------------------------------------------------------*/

#define _RTC_RTCDAYW_DAY_SHIFT		(000000u)
#define _RTC_RTCDAYW_DAY_MK(n)		(((Uint16)(n) & 0x0007u) << _RTC_RTCDAYW_DAY_SHIFT)
#define _RTC_RTCDAYW_DAY_MASK		(_RTC_RTCDAYW_DAY_MK(0x0007u))
#define _RTC_RTCDAYW_DAY_CLR		(~(_RTC_RTCDAYW_DAY_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCDAYW_DAEN:	
\*----------------------------------------------------------------*/

#define _RTC_RTCDAYW_DAEN_SHIFT		(0x0003u)
#define _RTC_RTCDAYW_DAEN_MK(n)		(((Uint16)(n) & 0x0001u) << _RTC_RTCDAYW_DAEN_SHIFT)
#define _RTC_RTCDAYW_DAEN_MASK		(_RTC_RTCDAYW_DAEN_MK(0x0001u))
#define _RTC_RTCDAYW_DAEN_CLR		(~(_RTC_RTCDAYW_DAEN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCDAYW_DAR:	
\*----------------------------------------------------------------*/

#define _RTC_RTCDAYW_DAR_SHIFT		(0x0004u)
#define _RTC_RTCDAYW_DAR_MK(n)		(((Uint16)(n) & 0x000fu) << _RTC_RTCDAYW_DAR_SHIFT)
#define _RTC_RTCDAYW_DAR_MASK		(_RTC_RTCDAYW_DAR_MK(0x000fu))
#define _RTC_RTCDAYW_DAR_CLR		(~(_RTC_RTCDAYW_DAR_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the RTCSEC register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _RTC_RTCSEC	 - Note: Add description here
*
* Fields:
*	(RW)   _RTC_RTCSEC_SEC	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCSEC_SEC:	
\*----------------------------------------------------------------*/

#define _RTC_RTCSEC_SEC_SHIFT		(000000u)
#define _RTC_RTCSEC_SEC_MK(n)		(((Uint16)(n) & 0x007fu) << _RTC_RTCSEC_SEC_SHIFT)
#define _RTC_RTCSEC_SEC_MASK		(_RTC_RTCSEC_SEC_MK(0x007fu))
#define _RTC_RTCSEC_SEC_CLR		(~(_RTC_RTCSEC_SEC_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the RTCMIN register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _RTC_RTCMIN	 - Note: Add description here
*
* Fields:
*	(RW)   _RTC_RTCMIN_MIN	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCMIN_MIN:	
\*----------------------------------------------------------------*/

#define _RTC_RTCMIN_MIN_SHIFT		(000000u)
#define _RTC_RTCMIN_MIN_MK(n)		(((Uint16)(n) & 0x007fu) << _RTC_RTCMIN_MIN_SHIFT)
#define _RTC_RTCMIN_MIN_MASK		(_RTC_RTCMIN_MIN_MK(0x007fu))
#define _RTC_RTCMIN_MIN_CLR		(~(_RTC_RTCMIN_MIN_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the RTCMONTH register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _RTC_RTCMONTH	 - Note: Add description here
*
* Fields:
*	(RW)   _RTC_RTCMONTH_MONTH	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCMONTH_MONTH:	
\*----------------------------------------------------------------*/

#define _RTC_RTCMONTH_MONTH_SHIFT		(000000u)
#define _RTC_RTCMONTH_MONTH_MK(n)		(((Uint16)(n) & 0x001fu) << _RTC_RTCMONTH_MONTH_SHIFT)
#define _RTC_RTCMONTH_MONTH_MASK		(_RTC_RTCMONTH_MONTH_MK(0x001fu))
#define _RTC_RTCMONTH_MONTH_CLR		(~(_RTC_RTCMONTH_MONTH_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the RTCPINTR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _RTC_RTCPINTR	 - Note: Add description here
*
* Fields:
*	(RW)   _RTC_RTCPINTR_RS	
*	(R)   _RTC_RTCPINTR_UIP	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCPINTR_RS:	
\*----------------------------------------------------------------*/

#define _RTC_RTCPINTR_RS_SHIFT		(000000u)
#define _RTC_RTCPINTR_RS_MK(n)		(((Uint16)(n) & 0x001fu) << _RTC_RTCPINTR_RS_SHIFT)
#define _RTC_RTCPINTR_RS_MASK		(_RTC_RTCPINTR_RS_MK(0x001fu))
#define _RTC_RTCPINTR_RS_CLR		(~(_RTC_RTCPINTR_RS_MASK))



/*----------------------------------------------------------------*\
*   (R)  _RTC_RTCPINTR_UIP:	
\*----------------------------------------------------------------*/

#define _RTC_RTCPINTR_UIP_SHIFT		(0x0007u)
#define _RTC_RTCPINTR_UIP_MK(n)		(((Uint16)(n) & 0x0001u) << _RTC_RTCPINTR_UIP_SHIFT)
#define _RTC_RTCPINTR_UIP_MASK		(_RTC_RTCPINTR_UIP_MK(0x0001u))
#define _RTC_RTCPINTR_UIP_CLR		(~(_RTC_RTCPINTR_UIP_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the RTCHOURA register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _RTC_RTCHOURA	 - Note: Add description here
*
* Fields:
*	(RW)   _RTC_RTCHOURA_HAR	
*	(RW)   _RTC_RTCHOURA_AMPM	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCHOURA_HAR:	
\*----------------------------------------------------------------*/

#define _RTC_RTCHOURA_HAR_SHIFT		(000000u)
#define _RTC_RTCHOURA_HAR_MK(n)		(((Uint16)(n) & 0x007fu) << _RTC_RTCHOURA_HAR_SHIFT)
#define _RTC_RTCHOURA_HAR_MASK		(_RTC_RTCHOURA_HAR_MK(0x007fu))
#define _RTC_RTCHOURA_HAR_CLR		(~(_RTC_RTCHOURA_HAR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _RTC_RTCHOURA_AMPM:	
\*----------------------------------------------------------------*/

#define _RTC_RTCHOURA_AMPM_SHIFT		(0x0007u)
#define _RTC_RTCHOURA_AMPM_MK(n)		(((Uint16)(n) & 0x0001u) << _RTC_RTCHOURA_AMPM_SHIFT)
#define _RTC_RTCHOURA_AMPM_MASK		(_RTC_RTCHOURA_AMPM_MK(0x0001u))
#define _RTC_RTCHOURA_AMPM_CLR		(~(_RTC_RTCHOURA_AMPM_MASK))


#else
   #ifndef _RTC_MOD_
	#error RTC Hal Module Not Supported on Specified Target
   #endif
#endif  /* _RTC_SUPPORT  */

#endif  /* _CSL_RTCHAL_H  */

/******************************************************************************\
*     
*      End of csl_rtchal.h 
*
\******************************************************************************/
