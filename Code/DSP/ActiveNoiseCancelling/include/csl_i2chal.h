/****************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved 
*------------------------------------------------------------------------------
* MODULE NAME... I2C
* FILENAME...... csl_I2Chal.h
* DATE CREATED.. Thu Aug 16 10:16:34 2001
* PROJECT....... Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS.. 
*------------------------------------------------------------------------------
*
* HISTORY:
*	 Created:		Thu Aug 16 10:16:34 2001 (Automatic generation)
*	 Last Modified:	
*
*------------------------------------------------------------------------------
* DESCRIPTION: CSL HAL interface file for the I2C module 
*
* Registers covered:
*
* 		 Note: Add registers description here
*	 I2COAR		- 
*	 I2CIER		- 
*	 I2CSTR		- 
*	 I2CCLKL		- 
*	 I2CCLKH		- 
*	 I2CCNT		- 
*	 I2CDRR		- 
*	 I2CSAR		- 
*	 I2CDXR		- 
*	 I2CMDR		- 
*	 I2CISRC		- 
*	 I2CGPIO		- 
*	 I2CPSC		- 
*
\*************************************************************************/

#ifndef _CSL_I2CHAL_H_
#define _CSL_I2CHAL_H_

#include <csl_chiphal.h>

#if (_I2C_SUPPORT) 

/*----------------------------------------------------------------*\
*	 I2C scope and inline control macros 			
\*----------------------------------------------------------------*/

#ifdef __cplusplus
#define CSLAPI extern "C"
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _I2C_MOD_
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

/*--------------------- Register: I2COAR -----------------------*/
#define _I2C_I2COAR_ADDR		(0x3C00u)
#define _I2C_I2COAR			PREG16(_I2C_I2COAR_ADDR)
#define I2COAR			_I2C_I2COAR


/*--------------------- Register: I2CIER -----------------------*/
#define _I2C_I2CIER_ADDR		(0x3C01u)
#define _I2C_I2CIER			PREG16(_I2C_I2CIER_ADDR)
#define I2CIER			_I2C_I2CIER


/*--------------------- Register: I2CSTR -----------------------*/
#define _I2C_I2CSTR_ADDR		(0x3C02u)
#define _I2C_I2CSTR			PREG16(_I2C_I2CSTR_ADDR)
#define I2CSTR			_I2C_I2CSTR


/*--------------------- Register: I2CCLKL -----------------------*/
#define _I2C_I2CCLKL_ADDR		(0x3C03u)
#define _I2C_I2CCLKL			PREG16(_I2C_I2CCLKL_ADDR)
#define I2CCLKL			_I2C_I2CCLKL


/*--------------------- Register: I2CCLKH -----------------------*/
#define _I2C_I2CCLKH_ADDR		(0x3C04u)
#define _I2C_I2CCLKH			PREG16(_I2C_I2CCLKH_ADDR)
#define I2CCLKH			_I2C_I2CCLKH


/*--------------------- Register: I2CCNT -----------------------*/
#define _I2C_I2CCNT_ADDR		(0x3C05u)
#define _I2C_I2CCNT			PREG16(_I2C_I2CCNT_ADDR)
#define I2CCNT			_I2C_I2CCNT


/*--------------------- Register: I2CDRR -----------------------*/
#define _I2C_I2CDRR_ADDR		(0x3C06u)
#define _I2C_I2CDRR			PREG16(_I2C_I2CDRR_ADDR)
#define I2CDRR			_I2C_I2CDRR


/*--------------------- Register: I2CSAR -----------------------*/
#define _I2C_I2CSAR_ADDR		(0x3C07u)
#define _I2C_I2CSAR			PREG16(_I2C_I2CSAR_ADDR)
#define I2CSAR			_I2C_I2CSAR


/*--------------------- Register: I2CDXR -----------------------*/
#define _I2C_I2CDXR_ADDR		(0x3C08u)
#define _I2C_I2CDXR			PREG16(_I2C_I2CDXR_ADDR)
#define I2CDXR			_I2C_I2CDXR


/*--------------------- Register: I2CMDR -----------------------*/
#define _I2C_I2CMDR_ADDR		(0x3C09u)
#define _I2C_I2CMDR			PREG16(_I2C_I2CMDR_ADDR)
#define I2CMDR			_I2C_I2CMDR


/*--------------------- Register: I2CISRC -----------------------*/
#define _I2C_I2CISRC_ADDR		(0x3C0Au)
#define _I2C_I2CISRC			PREG16(_I2C_I2CISRC_ADDR)
#define I2CISRC			_I2C_I2CISRC


/*--------------------- Register: I2CGPIO -----------------------*/
#define _I2C_I2CGPIO_ADDR		(0x3C0Bu)
#define _I2C_I2CGPIO			PREG16(_I2C_I2CGPIO_ADDR)
#define I2CGPIO			_I2C_I2CGPIO


/*--------------------- Register: I2CPSC -----------------------*/
#define _I2C_I2CPSC_ADDR		(0x3C0Cu)
#define _I2C_I2CPSC			PREG16(_I2C_I2CPSC_ADDR)
#define I2CPSC			_I2C_I2CPSC



/*----------------------------------------------------------------*\
*		 Register Macros		
\*----------------------------------------------------------------*/

#define I2C_ADDR(Reg)		  _I2C_##Reg##_ADDR
#define I2C_RGET(Reg)		  _I2C_##Reg##_GET
#define I2C_RSET(Reg,Val)		  _I2C_##Reg##_SET(Val)
#define I2C_FGET(Reg,Field)		  _I2C_##Reg##_FGET(##Field)
#define I2C_FSET(Reg,Field,Val)		  _I2C_##Reg##_FSET(##Field, Val)
#define I2C_FMK(Reg,Field,Val)		  _I2C_##Reg##_##Field##_MK(Val)
#define I2C_RAOI(Reg,AND,OR,INV)		  _I2C_##Reg##_AOI(AND,OR,INV)
#define I2C_FAOI(Reg,Field,AND,OR,INV)	  _I2C_##Reg##_FAOI(##Field,AND,OR,INV)
#define I2C_FMKS(Reg,Field,Sym)\
	  _I2C_##Reg##_##Field##_MK(I2C_##Reg##_##Field##_##Sym)
#define I2C_FSETS(Reg,Field,Sym)\
	  _I2C_FSET(##Reg,##Field,I2C_##Reg##_##Field##_##Sym)

/*----------------------------------------------------------------*\
*		 Non-handle Registers Macros		
\*----------------------------------------------------------------*/


/*--------------------- Register: I2COAR -----------------------*/
#define _I2C_I2COAR_GET		  _PREG_GET(_I2C_I2COAR_ADDR) 
#define _I2C_I2COAR_SET(Val)		  _PREG_SET(_I2C_I2COAR_ADDR,Val)
#define _I2C_I2COAR_FGET(Field)	  _PFIELD_GET(_I2C_I2COAR_ADDR, _I2C_I2COAR_##Field)
#define _I2C_I2COAR_FSET(Field,Val)	  _PFIELD_SET(_I2C_I2COAR_ADDR, _I2C_I2COAR_##Field, Val)
#define _I2C_I2COAR_AOI(AND,OR,INV)	  _PREG_AOI(_I2C_I2COAR_ADDR,AND,OR,INV)
#define _I2C_I2COAR_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_I2C_I2COAR_ADDR, _I2C_I2COAR_##Field,AND,OR,INV)


/*--------------------- Register: I2CIER -----------------------*/
#define _I2C_I2CIER_GET		  _PREG_GET(_I2C_I2CIER_ADDR) 
#define _I2C_I2CIER_SET(Val)		  _PREG_SET(_I2C_I2CIER_ADDR,Val)
#define _I2C_I2CIER_FGET(Field)	  _PFIELD_GET(_I2C_I2CIER_ADDR, _I2C_I2CIER_##Field)
#define _I2C_I2CIER_FSET(Field,Val)	  _PFIELD_SET(_I2C_I2CIER_ADDR, _I2C_I2CIER_##Field, Val)
#define _I2C_I2CIER_AOI(AND,OR,INV)	  _PREG_AOI(_I2C_I2CIER_ADDR,AND,OR,INV)
#define _I2C_I2CIER_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_I2C_I2CIER_ADDR, _I2C_I2CIER_##Field,AND,OR,INV)


/*--------------------- Register: I2CSTR -----------------------*/
#define _I2C_I2CSTR_GET		  _PREG_GET(_I2C_I2CSTR_ADDR) 
#define _I2C_I2CSTR_SET(Val)		  _PREG_SET(_I2C_I2CSTR_ADDR,Val)
#define _I2C_I2CSTR_FGET(Field)	  _PFIELD_GET(_I2C_I2CSTR_ADDR, _I2C_I2CSTR_##Field)
#define _I2C_I2CSTR_FSET(Field,Val)	  _PFIELD_SET(_I2C_I2CSTR_ADDR, _I2C_I2CSTR_##Field, Val)
#define _I2C_I2CSTR_AOI(AND,OR,INV)	  _PREG_AOI(_I2C_I2CSTR_ADDR,AND,OR,INV)
#define _I2C_I2CSTR_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_I2C_I2CSTR_ADDR, _I2C_I2CSTR_##Field,AND,OR,INV)


/*--------------------- Register: I2CCLKL -----------------------*/
#define _I2C_I2CCLKL_GET		  _PREG_GET(_I2C_I2CCLKL_ADDR) 
#define _I2C_I2CCLKL_SET(Val)		  _PREG_SET(_I2C_I2CCLKL_ADDR,Val)
#define _I2C_I2CCLKL_FGET(Field)	  _PFIELD_GET(_I2C_I2CCLKL_ADDR, _I2C_I2CCLKL_##Field)
#define _I2C_I2CCLKL_FSET(Field,Val)	  _PFIELD_SET(_I2C_I2CCLKL_ADDR, _I2C_I2CCLKL_##Field, Val)
#define _I2C_I2CCLKL_AOI(AND,OR,INV)	  _PREG_AOI(_I2C_I2CCLKL_ADDR,AND,OR,INV)
#define _I2C_I2CCLKL_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_I2C_I2CCLKL_ADDR, _I2C_I2CCLKL_##Field,AND,OR,INV)


/*--------------------- Register: I2CCLKH -----------------------*/
#define _I2C_I2CCLKH_GET		  _PREG_GET(_I2C_I2CCLKH_ADDR) 
#define _I2C_I2CCLKH_SET(Val)		  _PREG_SET(_I2C_I2CCLKH_ADDR,Val)
#define _I2C_I2CCLKH_FGET(Field)	  _PFIELD_GET(_I2C_I2CCLKH_ADDR, _I2C_I2CCLKH_##Field)
#define _I2C_I2CCLKH_FSET(Field,Val)	  _PFIELD_SET(_I2C_I2CCLKH_ADDR, _I2C_I2CCLKH_##Field, Val)
#define _I2C_I2CCLKH_AOI(AND,OR,INV)	  _PREG_AOI(_I2C_I2CCLKH_ADDR,AND,OR,INV)
#define _I2C_I2CCLKH_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_I2C_I2CCLKH_ADDR, _I2C_I2CCLKH_##Field,AND,OR,INV)


/*--------------------- Register: I2CCNT -----------------------*/
#define _I2C_I2CCNT_GET		  _PREG_GET(_I2C_I2CCNT_ADDR) 
#define _I2C_I2CCNT_SET(Val)		  _PREG_SET(_I2C_I2CCNT_ADDR,Val)
#define _I2C_I2CCNT_FGET(Field)	  _PFIELD_GET(_I2C_I2CCNT_ADDR, _I2C_I2CCNT_##Field)
#define _I2C_I2CCNT_FSET(Field,Val)	  _PFIELD_SET(_I2C_I2CCNT_ADDR, _I2C_I2CCNT_##Field, Val)
#define _I2C_I2CCNT_AOI(AND,OR,INV)	  _PREG_AOI(_I2C_I2CCNT_ADDR,AND,OR,INV)
#define _I2C_I2CCNT_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_I2C_I2CCNT_ADDR, _I2C_I2CCNT_##Field,AND,OR,INV)


/*--------------------- Register: I2CDRR -----------------------*/
#define _I2C_I2CDRR_GET		  _PREG_GET(_I2C_I2CDRR_ADDR) 
#define _I2C_I2CDRR_SET(Val)		  _PREG_SET(_I2C_I2CDRR_ADDR,Val)
#define _I2C_I2CDRR_FGET(Field)	  _PFIELD_GET(_I2C_I2CDRR_ADDR, _I2C_I2CDRR_##Field)
#define _I2C_I2CDRR_FSET(Field,Val)	  _PFIELD_SET(_I2C_I2CDRR_ADDR, _I2C_I2CDRR_##Field, Val)
#define _I2C_I2CDRR_AOI(AND,OR,INV)	  _PREG_AOI(_I2C_I2CDRR_ADDR,AND,OR,INV)
#define _I2C_I2CDRR_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_I2C_I2CDRR_ADDR, _I2C_I2CDRR_##Field,AND,OR,INV)


/*--------------------- Register: I2CSAR -----------------------*/
#define _I2C_I2CSAR_GET		  _PREG_GET(_I2C_I2CSAR_ADDR) 
#define _I2C_I2CSAR_SET(Val)		  _PREG_SET(_I2C_I2CSAR_ADDR,Val)
#define _I2C_I2CSAR_FGET(Field)	  _PFIELD_GET(_I2C_I2CSAR_ADDR, _I2C_I2CSAR_##Field)
#define _I2C_I2CSAR_FSET(Field,Val)	  _PFIELD_SET(_I2C_I2CSAR_ADDR, _I2C_I2CSAR_##Field, Val)
#define _I2C_I2CSAR_AOI(AND,OR,INV)	  _PREG_AOI(_I2C_I2CSAR_ADDR,AND,OR,INV)
#define _I2C_I2CSAR_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_I2C_I2CSAR_ADDR, _I2C_I2CSAR_##Field,AND,OR,INV)


/*--------------------- Register: I2CDXR -----------------------*/
#define _I2C_I2CDXR_GET		  _PREG_GET(_I2C_I2CDXR_ADDR) 
#define _I2C_I2CDXR_SET(Val)		  _PREG_SET(_I2C_I2CDXR_ADDR,Val)
#define _I2C_I2CDXR_FGET(Field)	  _PFIELD_GET(_I2C_I2CDXR_ADDR, _I2C_I2CDXR_##Field)
#define _I2C_I2CDXR_FSET(Field,Val)	  _PFIELD_SET(_I2C_I2CDXR_ADDR, _I2C_I2CDXR_##Field, Val)
#define _I2C_I2CDXR_AOI(AND,OR,INV)	  _PREG_AOI(_I2C_I2CDXR_ADDR,AND,OR,INV)
#define _I2C_I2CDXR_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_I2C_I2CDXR_ADDR, _I2C_I2CDXR_##Field,AND,OR,INV)


/*--------------------- Register: I2CMDR -----------------------*/
#define _I2C_I2CMDR_GET		  _PREG_GET(_I2C_I2CMDR_ADDR) 
#define _I2C_I2CMDR_SET(Val)		  _PREG_SET(_I2C_I2CMDR_ADDR,Val)
#define _I2C_I2CMDR_FGET(Field)	  _PFIELD_GET(_I2C_I2CMDR_ADDR, _I2C_I2CMDR_##Field)
#define _I2C_I2CMDR_FSET(Field,Val)	  _PFIELD_SET(_I2C_I2CMDR_ADDR, _I2C_I2CMDR_##Field, Val)
#define _I2C_I2CMDR_AOI(AND,OR,INV)	  _PREG_AOI(_I2C_I2CMDR_ADDR,AND,OR,INV)
#define _I2C_I2CMDR_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_I2C_I2CMDR_ADDR, _I2C_I2CMDR_##Field,AND,OR,INV)


/*--------------------- Register: I2CISRC -----------------------*/
#define _I2C_I2CISRC_GET		  _PREG_GET(_I2C_I2CISRC_ADDR) 
#define _I2C_I2CISRC_SET(Val)		  _PREG_SET(_I2C_I2CISRC_ADDR,Val)
#define _I2C_I2CISRC_FGET(Field)	  _PFIELD_GET(_I2C_I2CISRC_ADDR, _I2C_I2CISRC_##Field)
#define _I2C_I2CISRC_FSET(Field,Val)  _PFIELD_SET(_I2C_I2CISRC_ADDR, _I2C_I2CISRC_##Field, Val)
#define _I2C_I2CISRC_AOI(AND,OR,INV)  _PREG_AOI(_I2C_I2CISRC_ADDR,AND,OR,INV)
#define _I2C_I2CISRC_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_I2C_I2CISRC_ADDR, _I2C_I2CISRC_##Field,AND,OR,INV)


/*--------------------- Register: I2CGPIO -----------------------*/
#define _I2C_I2CGPIO_GET		  _PREG_GET(_I2C_I2CGPIO_ADDR) 
#define _I2C_I2CGPIO_SET(Val)		  _PREG_SET(_I2C_I2CGPIO_ADDR,Val)
#define _I2C_I2CGPIO_FGET(Field)	  _PFIELD_GET(_I2C_I2CGPIO_ADDR, _I2C_I2CGPIO_##Field)
#define _I2C_I2CGPIO_FSET(Field,Val)	  _PFIELD_SET(_I2C_I2CGPIO_ADDR, _I2C_I2CGPIO_##Field, Val)
#define _I2C_I2CGPIO_AOI(AND,OR,INV)	  _PREG_AOI(_I2C_I2CGPIO_ADDR,AND,OR,INV)
#define _I2C_I2CGPIO_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_I2C_I2CGPIO_ADDR, _I2C_I2CGPIO_##Field,AND,OR,INV)


/*--------------------- Register: I2CPSC -----------------------*/
#define _I2C_I2CPSC_GET		  _PREG_GET(_I2C_I2CPSC_ADDR) 
#define _I2C_I2CPSC_SET(Val)		  _PREG_SET(_I2C_I2CPSC_ADDR,Val)
#define _I2C_I2CPSC_FGET(Field)	  _PFIELD_GET(_I2C_I2CPSC_ADDR, _I2C_I2CPSC_##Field)
#define _I2C_I2CPSC_FSET(Field,Val)	  _PFIELD_SET(_I2C_I2CPSC_ADDR, _I2C_I2CPSC_##Field, Val)
#define _I2C_I2CPSC_AOI(AND,OR,INV)	  _PREG_AOI(_I2C_I2CPSC_ADDR,AND,OR,INV)
#define _I2C_I2CPSC_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_I2C_I2CPSC_ADDR, _I2C_I2CPSC_##Field,AND,OR,INV)



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the I2CIER register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _I2C_I2CIER	 - Note: Add description here
*
* Fields:
*	(RW)   _I2C_I2CIER_AL	
*	(RW)   _I2C_I2CIER_NACK	
*	(RW)   _I2C_I2CIER_ARDY	
*	(RW)   _I2C_I2CIER_RRDY	
*	(RW)   _I2C_I2CIER_XRDY	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CIER_AL:	
\*----------------------------------------------------------------*/

#define _I2C_I2CIER_AL_SHIFT		(000000u)
#define _I2C_I2CIER_AL_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CIER_AL_SHIFT)
#define _I2C_I2CIER_AL_MASK		(_I2C_I2CIER_AL_MK(0x0001u))
#define _I2C_I2CIER_AL_CLR		(~(_I2C_I2CIER_AL_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CIER_NACK:	
\*----------------------------------------------------------------*/

#define _I2C_I2CIER_NACK_SHIFT		(0x0001u)
#define _I2C_I2CIER_NACK_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CIER_NACK_SHIFT)
#define _I2C_I2CIER_NACK_MASK		      (_I2C_I2CIER_NACK_MK(0x0001u))
#define _I2C_I2CIER_NACK_CLR		      (~(_I2C_I2CIER_NACK_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CIER_ARDY:	
\*----------------------------------------------------------------*/

#define _I2C_I2CIER_ARDY_SHIFT		(0x0002u)
#define _I2C_I2CIER_ARDY_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CIER_ARDY_SHIFT)
#define _I2C_I2CIER_ARDY_MASK		      (_I2C_I2CIER_ARDY_MK(0x0001u))
#define _I2C_I2CIER_ARDY_CLR		      (~(_I2C_I2CIER_ARDY_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CIER_RRDY:	
\*----------------------------------------------------------------*/

#define _I2C_I2CIER_RRDY_SHIFT		(0x0003u)
#define _I2C_I2CIER_RRDY_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CIER_RRDY_SHIFT)
#define _I2C_I2CIER_RRDY_MASK		      (_I2C_I2CIER_RRDY_MK(0x0001u))
#define _I2C_I2CIER_RRDY_CLR		      (~(_I2C_I2CIER_RRDY_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CIER_XRDY:	
\*----------------------------------------------------------------*/

#define _I2C_I2CIER_XRDY_SHIFT		(0x0004u)
#define _I2C_I2CIER_XRDY_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CIER_XRDY_SHIFT)
#define _I2C_I2CIER_XRDY_MASK		      (_I2C_I2CIER_XRDY_MK(0x0001u))
#define _I2C_I2CIER_XRDY_CLR		      (~(_I2C_I2CIER_XRDY_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the I2CPSC register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _I2C_I2CPSC	 - Note: Add description here
*
* Fields:
*	(RW)   _I2C_I2CPSC_IPSC	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CPSC_IPSC:	
\*----------------------------------------------------------------*/

#define _I2C_I2CPSC_IPSC_SHIFT		(000000u)
#define _I2C_I2CPSC_IPSC_MK(n)		(((Uint16)(n) & 0x00ffu) << _I2C_I2CPSC_IPSC_SHIFT)
#define _I2C_I2CPSC_IPSC_MASK		      (_I2C_I2CPSC_IPSC_MK(0x00ffu))
#define _I2C_I2CPSC_IPSC_CLR		      (~(_I2C_I2CPSC_IPSC_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the I2CISRC register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _I2C_I2CISRC	 - Note: Add description here
*
* Fields:
*	(R)   _I2C_I2CISRC_INTCODE	
*	(RW)   _I2C_I2CISRC_TESTMD	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _I2C_I2CISRC_INTCODE:	
\*----------------------------------------------------------------*/

#define _I2C_I2CISRC_INTCODE_SHIFT		(000000u)
#define _I2C_I2CISRC_INTCODE_MK(n)		(((Uint16)(n) & 0x0007u) << _I2C_I2CISRC_INTCODE_SHIFT)
#define _I2C_I2CISRC_INTCODE_MASK		(_I2C_I2CISRC_INTCODE_MK(0x0007u))
#define _I2C_I2CISRC_INTCODE_CLR		(~(_I2C_I2CISRC_INTCODE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CISRC_TESTMD:	
\*----------------------------------------------------------------*/

#define _I2C_I2CISRC_TESTMD_SHIFT		(0x0008u)
#define _I2C_I2CISRC_TESTMD_MK(n)		(((Uint16)(n) & 0x000fu) << _I2C_I2CISRC_TESTMD_SHIFT)
#define _I2C_I2CISRC_TESTMD_MASK		(_I2C_I2CISRC_TESTMD_MK(0x000fu))
#define _I2C_I2CISRC_TESTMD_CLR		(~(_I2C_I2CISRC_TESTMD_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the I2CCNT register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _I2C_I2CCNT	 - Note: Add description here
*
* Fields:
*	(RW)   _I2C_I2CCNT_ICDC	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CCNT_ICDC:	
\*----------------------------------------------------------------*/

#define _I2C_I2CCNT_ICDC_SHIFT		(000000u)
#define _I2C_I2CCNT_ICDC_MK(n)		(((Uint16)(n) & 0xffffu) << _I2C_I2CCNT_ICDC_SHIFT)
#define _I2C_I2CCNT_ICDC_MASK		(_I2C_I2CCNT_ICDC_MK(0xffffu))
#define _I2C_I2CCNT_ICDC_CLR		(~(_I2C_I2CCNT_ICDC_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the I2CSAR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _I2C_I2CSAR	 - Note: Add description here
*
* Fields:
*	(RW)   _I2C_I2CSAR_SAR	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CSAR_SAR:	
\*----------------------------------------------------------------*/

#define _I2C_I2CSAR_SAR_SHIFT		(000000u)
#define _I2C_I2CSAR_SAR_MK(n)		(((Uint16)(n) & 0x03ffu) << _I2C_I2CSAR_SAR_SHIFT)
#define _I2C_I2CSAR_SAR_MASK		(_I2C_I2CSAR_SAR_MK(0x03ffu))
#define _I2C_I2CSAR_SAR_CLR		(~(_I2C_I2CSAR_SAR_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the I2CDXR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _I2C_I2CDXR	 - Note: Add description here
*
* Fields:
*	(R)   _I2C_I2CDXR_DATA	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _I2C_I2CDXR_DATA:	
\*----------------------------------------------------------------*/

#define _I2C_I2CDXR_DATA_SHIFT		(000000u)
#define _I2C_I2CDXR_DATA_MK(n)		(((Uint16)(n) & 0x00ffu) << _I2C_I2CDXR_DATA_SHIFT)
#define _I2C_I2CDXR_DATA_MASK		(_I2C_I2CDXR_DATA_MK(0x00ffu))
#define _I2C_I2CDXR_DATA_CLR		(~(_I2C_I2CDXR_DATA_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the I2CCLKH register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _I2C_I2CCLKH	 - Note: Add description here
*
* Fields:
*	(RW)   _I2C_I2CCLKH_ICCH	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CCLKH_ICCH:	
\*----------------------------------------------------------------*/

#define _I2C_I2CCLKH_ICCH_SHIFT		(000000u)
#define _I2C_I2CCLKH_ICCH_MK(n)		(((Uint16)(n) & 0xffffu) << _I2C_I2CCLKH_ICCH_SHIFT)
#define _I2C_I2CCLKH_ICCH_MASK		(_I2C_I2CCLKH_ICCH_MK(0xffffu))
#define _I2C_I2CCLKH_ICCH_CLR		(~(_I2C_I2CCLKH_ICCH_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the I2CMDR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _I2C_I2CMDR	 - Note: Add description here
*
* Fields:
*	(RW)   _I2C_I2CMDR_BC	
*	(RW)   _I2C_I2CMDR_FDF	
*	(RW)   _I2C_I2CMDR_STB	
*	(RW)   _I2C_I2CMDR_IRS	
*	(RW)   _I2C_I2CMDR_DLB	
*	(RW)   _I2C_I2CMDR_RM	
*	(RW)   _I2C_I2CMDR_XA	
*	(RW)   _I2C_I2CMDR_TRX	
*	(RW)   _I2C_I2CMDR_MST	
*	(RW)   _I2C_I2CMDR_STP	
*	(RW)   _I2C_I2CMDR_IDLEEN	
*	(RW)   _I2C_I2CMDR_STT	
*	(RW)   _I2C_I2CMDR_FREE	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CMDR_BC:	
\*----------------------------------------------------------------*/

#define _I2C_I2CMDR_BC_SHIFT		(000000u)
#define _I2C_I2CMDR_BC_MK(n)		(((Uint16)(n) & 0x0007u) << _I2C_I2CMDR_BC_SHIFT)
#define _I2C_I2CMDR_BC_MASK		(_I2C_I2CMDR_BC_MK(0x0007u))
#define _I2C_I2CMDR_BC_CLR		(~(_I2C_I2CMDR_BC_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CMDR_FDF:	
\*----------------------------------------------------------------*/

#define _I2C_I2CMDR_FDF_SHIFT		(0x0003u)
#define _I2C_I2CMDR_FDF_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CMDR_FDF_SHIFT)
#define _I2C_I2CMDR_FDF_MASK		(_I2C_I2CMDR_FDF_MK(0x0001u))
#define _I2C_I2CMDR_FDF_CLR		(~(_I2C_I2CMDR_FDF_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CMDR_STB:	
\*----------------------------------------------------------------*/

#define _I2C_I2CMDR_STB_SHIFT		(0x0004u)
#define _I2C_I2CMDR_STB_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CMDR_STB_SHIFT)
#define _I2C_I2CMDR_STB_MASK		(_I2C_I2CMDR_STB_MK(0x0001u))
#define _I2C_I2CMDR_STB_CLR		(~(_I2C_I2CMDR_STB_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CMDR_IRS:	
\*----------------------------------------------------------------*/

#define _I2C_I2CMDR_IRS_SHIFT		(0x0005u)
#define _I2C_I2CMDR_IRS_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CMDR_IRS_SHIFT)
#define _I2C_I2CMDR_IRS_MASK		(_I2C_I2CMDR_IRS_MK(0x0001u))
#define _I2C_I2CMDR_IRS_CLR		(~(_I2C_I2CMDR_IRS_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CMDR_DLB:	
\*----------------------------------------------------------------*/

#define _I2C_I2CMDR_DLB_SHIFT		(0x0006u)
#define _I2C_I2CMDR_DLB_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CMDR_DLB_SHIFT)
#define _I2C_I2CMDR_DLB_MASK		(_I2C_I2CMDR_DLB_MK(0x0001u))
#define _I2C_I2CMDR_DLB_CLR		(~(_I2C_I2CMDR_DLB_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CMDR_RM:	
\*----------------------------------------------------------------*/

#define _I2C_I2CMDR_RM_SHIFT		(0x0007u)
#define _I2C_I2CMDR_RM_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CMDR_RM_SHIFT)
#define _I2C_I2CMDR_RM_MASK		(_I2C_I2CMDR_RM_MK(0x0001u))
#define _I2C_I2CMDR_RM_CLR		(~(_I2C_I2CMDR_RM_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CMDR_XA:	
\*----------------------------------------------------------------*/

#define _I2C_I2CMDR_XA_SHIFT		(0x0008u)
#define _I2C_I2CMDR_XA_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CMDR_XA_SHIFT)
#define _I2C_I2CMDR_XA_MASK		(_I2C_I2CMDR_XA_MK(0x0001u))
#define _I2C_I2CMDR_XA_CLR		(~(_I2C_I2CMDR_XA_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CMDR_TRX:	
\*----------------------------------------------------------------*/

#define _I2C_I2CMDR_TRX_SHIFT		(0x0009u)
#define _I2C_I2CMDR_TRX_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CMDR_TRX_SHIFT)
#define _I2C_I2CMDR_TRX_MASK		(_I2C_I2CMDR_TRX_MK(0x0001u))
#define _I2C_I2CMDR_TRX_CLR		(~(_I2C_I2CMDR_TRX_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CMDR_MST:	
\*----------------------------------------------------------------*/

#define _I2C_I2CMDR_MST_SHIFT		(0x000au)
#define _I2C_I2CMDR_MST_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CMDR_MST_SHIFT)
#define _I2C_I2CMDR_MST_MASK		(_I2C_I2CMDR_MST_MK(0x0001u))
#define _I2C_I2CMDR_MST_CLR		(~(_I2C_I2CMDR_MST_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CMDR_STP:	
\*----------------------------------------------------------------*/

#define _I2C_I2CMDR_STP_SHIFT		(0x000bu)
#define _I2C_I2CMDR_STP_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CMDR_STP_SHIFT)
#define _I2C_I2CMDR_STP_MASK		(_I2C_I2CMDR_STP_MK(0x0001u))
#define _I2C_I2CMDR_STP_CLR		(~(_I2C_I2CMDR_STP_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CMDR_IDLEEN:	
\*----------------------------------------------------------------*/

#define _I2C_I2CMDR_IDLEEN_SHIFT		(0x000cu)
#define _I2C_I2CMDR_IDLEEN_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CMDR_IDLEEN_SHIFT)
#define _I2C_I2CMDR_IDLEEN_MASK		(_I2C_I2CMDR_IDLEEN_MK(0x0001u))
#define _I2C_I2CMDR_IDLEEN_CLR		(~(_I2C_I2CMDR_IDLEEN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CMDR_STT:	
\*----------------------------------------------------------------*/

#define _I2C_I2CMDR_STT_SHIFT		(0x000du)
#define _I2C_I2CMDR_STT_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CMDR_STT_SHIFT)
#define _I2C_I2CMDR_STT_MASK		(_I2C_I2CMDR_STT_MK(0x0001u))
#define _I2C_I2CMDR_STT_CLR		(~(_I2C_I2CMDR_STT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CMDR_FREE:	
\*----------------------------------------------------------------*/

#define _I2C_I2CMDR_FREE_SHIFT		(0x000eu)
#define _I2C_I2CMDR_FREE_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CMDR_FREE_SHIFT)
#define _I2C_I2CMDR_FREE_MASK		(_I2C_I2CMDR_FREE_MK(0x0001u))
#define _I2C_I2CMDR_FREE_CLR		(~(_I2C_I2CMDR_FREE_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the I2COAR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _I2C_I2COAR	 - Note: Add description here
*
* Fields:
*	(RW)   _I2C_I2COAR_OAR	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2COAR_OAR:	
\*----------------------------------------------------------------*/

#define _I2C_I2COAR_OAR_SHIFT		(000000u)
#define _I2C_I2COAR_OAR_MK(n)		(((Uint16)(n) & 0x03ffu) << _I2C_I2COAR_OAR_SHIFT)
#define _I2C_I2COAR_OAR_MASK		(_I2C_I2COAR_OAR_MK(0x03ffu))
#define _I2C_I2COAR_OAR_CLR		(~(_I2C_I2COAR_OAR_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the I2CCLKL register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _I2C_I2CCLKL	 - Note: Add description here
*
* Fields:
*	(RW)   _I2C_I2CCLKL_ICCL	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CCLKL_ICCL:	
\*----------------------------------------------------------------*/

#define _I2C_I2CCLKL_ICCL_SHIFT		(000000u)
#define _I2C_I2CCLKL_ICCL_MK(n)		(((Uint16)(n) & 0xffffu) << _I2C_I2CCLKL_ICCL_SHIFT)
#define _I2C_I2CCLKL_ICCL_MASK		(_I2C_I2CCLKL_ICCL_MK(0xffffu))
#define _I2C_I2CCLKL_ICCL_CLR		(~(_I2C_I2CCLKL_ICCL_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the I2CDRR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _I2C_I2CDRR	 - Note: Add description here
*
* Fields:
*	(R)   _I2C_I2CDRR_DATA	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _I2C_I2CDRR_DATA:	
\*----------------------------------------------------------------*/

#define _I2C_I2CDRR_DATA_SHIFT		(000000u)
#define _I2C_I2CDRR_DATA_MK(n)		(((Uint16)(n) & 0x00ffu) << _I2C_I2CDRR_DATA_SHIFT)
#define _I2C_I2CDRR_DATA_MASK		(_I2C_I2CDRR_DATA_MK(0x00ffu))
#define _I2C_I2CDRR_DATA_CLR		(~(_I2C_I2CDRR_DATA_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the I2CSTR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _I2C_I2CSTR	 - Note: Add description here
*
* Fields:
*	(R)   _I2C_I2CSTR_AL	
*	(R)   _I2C_I2CSTR_NACK	
*	(R)   _I2C_I2CSTR_ARDY	
*	(RW)   _I2C_I2CSTR_RRDY	
*	(R)   _I2C_I2CSTR_XRDY	
*	(R)   _I2C_I2CSTR_AD0	
*	(R)   _I2C_I2CSTR_AAS	
*	(R)   _I2C_I2CSTR_XSMT	
*	(R)   _I2C_I2CSTR_RSFULL	
*	(R)   _I2C_I2CSTR_BB	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _I2C_I2CSTR_AL:	
\*----------------------------------------------------------------*/

#define _I2C_I2CSTR_AL_SHIFT		(000000u)
#define _I2C_I2CSTR_AL_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CSTR_AL_SHIFT)
#define _I2C_I2CSTR_AL_MASK		(_I2C_I2CSTR_AL_MK(0x0001u))
#define _I2C_I2CSTR_AL_CLR		(~(_I2C_I2CSTR_AL_MASK))



/*----------------------------------------------------------------*\
*   (R)  _I2C_I2CSTR_NACK:	
\*----------------------------------------------------------------*/

#define _I2C_I2CSTR_NACK_SHIFT		(0x0001u)
#define _I2C_I2CSTR_NACK_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CSTR_NACK_SHIFT)
#define _I2C_I2CSTR_NACK_MASK		(_I2C_I2CSTR_NACK_MK(0x0001u))
#define _I2C_I2CSTR_NACK_CLR		(~(_I2C_I2CSTR_NACK_MASK))



/*----------------------------------------------------------------*\
*   (R)  _I2C_I2CSTR_ARDY:	
\*----------------------------------------------------------------*/

#define _I2C_I2CSTR_ARDY_SHIFT		(0x0002u)
#define _I2C_I2CSTR_ARDY_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CSTR_ARDY_SHIFT)
#define _I2C_I2CSTR_ARDY_MASK		(_I2C_I2CSTR_ARDY_MK(0x0001u))
#define _I2C_I2CSTR_ARDY_CLR		(~(_I2C_I2CSTR_ARDY_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _I2C_I2CSTR_RRDY:	
\*----------------------------------------------------------------*/

#define _I2C_I2CSTR_RRDY_SHIFT		(0x0003u)
#define _I2C_I2CSTR_RRDY_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CSTR_RRDY_SHIFT)
#define _I2C_I2CSTR_RRDY_MASK		(_I2C_I2CSTR_RRDY_MK(0x0001u))
#define _I2C_I2CSTR_RRDY_CLR		(~(_I2C_I2CSTR_RRDY_MASK))



/*----------------------------------------------------------------*\
*   (R)  _I2C_I2CSTR_XRDY:	
\*----------------------------------------------------------------*/

#define _I2C_I2CSTR_XRDY_SHIFT		(0x0004u)
#define _I2C_I2CSTR_XRDY_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CSTR_XRDY_SHIFT)
#define _I2C_I2CSTR_XRDY_MASK		(_I2C_I2CSTR_XRDY_MK(0x0001u))
#define _I2C_I2CSTR_XRDY_CLR		(~(_I2C_I2CSTR_XRDY_MASK))



/*----------------------------------------------------------------*\
*   (R)  _I2C_I2CSTR_AD0:	
\*----------------------------------------------------------------*/

#define _I2C_I2CSTR_AD0_SHIFT		(0x0008u)
#define _I2C_I2CSTR_AD0_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CSTR_AD0_SHIFT)
#define _I2C_I2CSTR_AD0_MASK		(_I2C_I2CSTR_AD0_MK(0x0001u))
#define _I2C_I2CSTR_AD0_CLR		(~(_I2C_I2CSTR_AD0_MASK))



/*----------------------------------------------------------------*\
*   (R)  _I2C_I2CSTR_AAS:	
\*----------------------------------------------------------------*/

#define _I2C_I2CSTR_AAS_SHIFT		(0x0009u)
#define _I2C_I2CSTR_AAS_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CSTR_AAS_SHIFT)
#define _I2C_I2CSTR_AAS_MASK		(_I2C_I2CSTR_AAS_MK(0x0001u))
#define _I2C_I2CSTR_AAS_CLR		(~(_I2C_I2CSTR_AAS_MASK))



/*----------------------------------------------------------------*\
*   (R)  _I2C_I2CSTR_XSMT:	
\*----------------------------------------------------------------*/

#define _I2C_I2CSTR_XSMT_SHIFT		(0x000au)
#define _I2C_I2CSTR_XSMT_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CSTR_XSMT_SHIFT)
#define _I2C_I2CSTR_XSMT_MASK		(_I2C_I2CSTR_XSMT_MK(0x0001u))
#define _I2C_I2CSTR_XSMT_CLR		(~(_I2C_I2CSTR_XSMT_MASK))



/*----------------------------------------------------------------*\
*   (R)  _I2C_I2CSTR_RSFULL:	
\*----------------------------------------------------------------*/

#define _I2C_I2CSTR_RSFULL_SHIFT		(0x000bu)
#define _I2C_I2CSTR_RSFULL_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CSTR_RSFULL_SHIFT)
#define _I2C_I2CSTR_RSFULL_MASK		(_I2C_I2CSTR_RSFULL_MK(0x0001u))
#define _I2C_I2CSTR_RSFULL_CLR		(~(_I2C_I2CSTR_RSFULL_MASK))



/*----------------------------------------------------------------*\
*   (R)  _I2C_I2CSTR_BB:	
\*----------------------------------------------------------------*/

#define _I2C_I2CSTR_BB_SHIFT		(0x000cu)
#define _I2C_I2CSTR_BB_MK(n)		(((Uint16)(n) & 0x0001u) << _I2C_I2CSTR_BB_SHIFT)
#define _I2C_I2CSTR_BB_MASK		(_I2C_I2CSTR_BB_MK(0x0001u))
#define _I2C_I2CSTR_BB_CLR		(~(_I2C_I2CSTR_BB_MASK))


#else
   #ifndef _I2C_MOD_
	#error I2C Hal Module Not Supported on Specified Target
   #endif
#endif  /* _I2C_SUPPORT  */

#endif  /* _CSL_I2CHAL_H  */

/******************************************************************************\
*     
*      End of csl_I2Chal.h 
*
\******************************************************************************/
