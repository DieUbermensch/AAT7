/****************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved 
*------------------------------------------------------------------------------
* MODULE NAME... BCT
* FILENAME...... csl_bcthal.h
* DATE CREATED.. Tue Feb 19 12:02:53 2002
* PROJECT....... Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS.. 
*------------------------------------------------------------------------------
*
* HISTORY:
*	 Created:		Tue Feb 19 12:02:53 2002 (Automatic generation)
*	 Last Modified:	
*
*------------------------------------------------------------------------------
* DESCRIPTION: CSL HAL interface file for the BCT module 
*
* Registers covered:
*
* 		 Note: Add registers description here
*	 BCTPID1		- 
*	 BCTPID1		- 
*	 BCTPID2		- 
*	 BCTPID2		- 
*	 BCTEMU		- 
*	 BCTEMU		- 
*	 BCTCLK		- 
*	 BCTCNT1		- 
*	 BCTCNT2		- 
*	 BCTCNT3		- 
*	 BCTCNT4		- 
*	 BCTPRD1		- 
*	 BCTPRD2		- 
*	 BCTPRD3		- 
*	 BCTPRD4		- 
*	 BCTCLK	    	- 
*	 BCTGPINT		- 
*	 BCTGPEN		- 
*	 BCTGPDIR		- 
*	 BCTGPDAT		- 
*	 BCTCTL1		- 
*	 BCTCTL2		- 
*	 BCTGCTL1		- 
*
\*************************************************************************/

#ifndef _CSL_BCTHAL_H_
#define _CSL_BCTHAL_H_

#include <csl_chiphal.h>

#if (_BCT_SUPPORT) 

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

/*----------------------------------------------------------------*\
*		 Address Macros			
\*----------------------------------------------------------------*/

/*--------------------- Register: BCTPID1 -----------------------*/
#define _BCT_BCTPID1_ADDR		(0x7800u)
#define _BCT_BCTPID1			PREG16(_BCT_BCTPID1_ADDR)
#define BCTPID1			_BCT_BCTPID1


/*--------------------- Register: BCTPID2 -----------------------*/
#define _BCT_BCTPID2_ADDR		(0x7801u)
#define _BCT_BCTPID2			PREG16(_BCT_BCTPID2_ADDR)
#define BCTPID2			_BCT_BCTPID2


/*--------------------- Register: BCTEMU -----------------------*/
#define _BCT_BCTEMU_ADDR		(0x7802u)
#define _BCT_BCTEMU			PREG16(_BCT_BCTEMU_ADDR)
#define BCTEMU			_BCT_BCTEMU


/*--------------------- Register: BCTCLK -----------------------*/
#define _BCT_BCTCLK_ADDR		(0x7803u)
#define _BCT_BCTCLK			PREG16(_BCT_BCTCLK_ADDR)
#define BCTCLK			_BCT_BCTCLK


/*--------------------- Register: BCTCNT1 -----------------------*/
#define _BCT_BCTCNT1_ADDR		(0x7808u)
#define _BCT_BCTCNT1			PREG16(_BCT_BCTCNT1_ADDR)
#define BCTCNT1			_BCT_BCTCNT1


/*--------------------- Register: BCTCNT2 -----------------------*/
#define _BCT_BCTCNT2_ADDR		(0x7809u)
#define _BCT_BCTCNT2			PREG16(_BCT_BCTCNT2_ADDR)
#define BCTCNT2			_BCT_BCTCNT2


/*--------------------- Register: BCTCNT3 -----------------------*/
#define _BCT_BCTCNT3_ADDR		(0x780Au)
#define _BCT_BCTCNT3			PREG16(_BCT_BCTCNT3_ADDR)
#define BCTCNT3			_BCT_BCTCNT3


/*--------------------- Register: BCTCNT4 -----------------------*/
#define _BCT_BCTCNT4_ADDR		(0x780Bu)
#define _BCT_BCTCNT4			PREG16(_BCT_BCTCNT4_ADDR)
#define BCTCNT4			_BCT_BCTCNT4


/*--------------------- Register: BCTPRD1 -----------------------*/
#define _BCT_BCTPRD1_ADDR		(0x780Cu)
#define _BCT_BCTPRD1			PREG16(_BCT_BCTPRD1_ADDR)
#define BCTPRD1			_BCT_BCTPRD1


/*--------------------- Register: BCTPRD2 -----------------------*/
#define _BCT_BCTPRD2_ADDR		(0x780Du)
#define _BCT_BCTPRD2			PREG16(_BCT_BCTPRD2_ADDR)
#define BCTPRD2			_BCT_BCTPRD2


/*--------------------- Register: BCTPRD3 -----------------------*/
#define _BCT_BCTPRD3_ADDR		(0x780Eu)
#define _BCT_BCTPRD3			PREG16(_BCT_BCTPRD3_ADDR)
#define BCTPRD3			_BCT_BCTPRD3


/*--------------------- Register: BCTPRD4 -----------------------*/
#define _BCT_BCTPRD4_ADDR		(0x780Fu)
#define _BCT_BCTPRD4			PREG16(_BCT_BCTPRD4_ADDR)
#define BCTPRD4			_BCT_BCTPRD4


/*--------------------- Register: BCTGPINT -----------------------*/
#define _BCT_BCTGPINT_ADDR		(0x7804u)
#define _BCT_BCTGPINT			PREG16(_BCT_BCTGPINT_ADDR)
#define BCTGPINT			_BCT_BCTGPINT


/*--------------------- Register: BCTGPEN -----------------------*/
#define _BCT_BCTGPEN_ADDR		(0x7805u)
#define _BCT_BCTGPEN			PREG16(_BCT_BCTGPEN_ADDR)
#define BCTGPEN			_BCT_BCTGPEN


/*--------------------- Register: BCTGPDIR -----------------------*/
#define _BCT_BCTGPDIR_ADDR		(0x7807u)
#define _BCT_BCTGPDIR			PREG16(_BCT_BCTGPDIR_ADDR)
#define BCTGPDIR			_BCT_BCTGPDIR


/*--------------------- Register: BCTGPDAT -----------------------*/
#define _BCT_BCTGPDAT_ADDR		(0x7806u)
#define _BCT_BCTGPDAT			PREG16(_BCT_BCTGPDAT_ADDR)
#define BCTGPDAT			_BCT_BCTGPDAT


/*--------------------- Register: BCTCTL1 -----------------------*/
#define _BCT_BCTCTL1_ADDR		(0x7810u)
#define _BCT_BCTCTL1			PREG16(_BCT_BCTCTL1_ADDR)
#define BCTCTL1     			_BCT_BCTCTL1


/*--------------------- Register: BCTCTL2 -----------------------*/
#define _BCT_BCTCTL2_ADDR		(0x7811u)
#define _BCT_BCTCTL2			PREG16(_BCT_BCTCTL2_ADDR)
#define BCTCTL2			        _BCT_BCTCTL2


/*--------------------- Register: BCTGCTL1 -----------------------*/
#define _BCT_BCTGCTL1_ADDR		(0x7812u)
#define _BCT_BCTGCTL1			PREG16(_BCT_BCTGCTL1_ADDR)
#define BCTGCTL1			_BCT_BCTGCTL1



/*----------------------------------------------------------------*\
*		 Register Macros		
\*----------------------------------------------------------------*/

#define BCT_ADDR(Reg)		  _BCT_##Reg##_ADDR
#define BCT_RGET(Reg)		  _BCT_##Reg##_GET
#define BCT_RSET(Reg,Val)		  _BCT_##Reg##_SET(Val)
#define BCT_FGET(Reg,Field)		  _BCT_##Reg##_FGET(Field)
#define BCT_FSET(Reg,Field,Val)		  _BCT_##Reg##_FSET(Field, Val)
#define BCT_FMK(Reg,Field,Val)		  _BCT_##Reg##_##Field##_MK(Val)
#define BCT_RAOI(Reg,AND,OR,INV)		  _BCT_##Reg##_AOI(AND,OR,INV)
#define BCT_FAOI(Reg,Field,AND,OR,INV)	  _BCT_##Reg##_FAOI(Field,AND,OR,INV)
#define BCT_FMKS(Reg,Field,Sym)\
	  _BCT_##Reg##_##Field##_MK(BCT_##Reg##_##Field##_##Sym)
#define BCT_FSETS(Reg,Field,Sym)\
	  _BCT_FSET(Reg,Field,BCT_##Reg##_##Field##_##Sym)

#define BCT_ADDRH(h,Reg)		  _BCT_##Reg##_ADDR
#define BCT_RGETH(h,Reg)		  _BCT_##Reg##_GET
#define BCT_RSETH(h,Reg,Val)		  _BCT_##Reg##_SET(Val)
#define BCT_FGETH(h,Reg,Field)		  _BCT_##Reg##_FGET(Field)
#define BCT_FSETH(h,Reg,Field,Val)		  _BCT_##Reg##_FSET(Field, Val)
#define BCT_FMKH(h,Reg,Field,Val)		  _BCT_##Reg##_##Field##_MK(Val)
#define BCT_RAOIH(h,Reg,AND,OR,INV)		  _BCT_##Reg##_AOI(AND,OR,INV)
#define BCT_FAOIH(h,Reg,Field,AND,OR,INV)	  _BCT_##Reg##_FAOI(Field,AND,OR,INV)
#define BCT_FMKSH(h,Reg,Field,Sym)\
	  _BCT_##Reg##_##Field##_MK(BCT_##Reg##_##Field##_##Sym)
#define BCT_FSETSH(h,Reg,Field,Sym)\
	  _BCT_FSET(Reg,Field,BCT_##Reg##_##Field##_##Sym)

/*----------------------------------------------------------------*\
*		 Non-handle Registers Macros		
\*----------------------------------------------------------------*/


/*--------------------- Register: BCTPID1 -----------------------*/
#define _BCT_BCTPID1_GET		  _PREG_GET(_BCT_BCTPID1_ADDR) 
#define _BCT_BCTPID1_SET(Val)		  _PREG_SET(_BCT_BCTPID1_ADDR,Val)
#define _BCT_BCTPID1_FGET(Field)	  _PFIELD_GET(_BCT_BCTPID1_ADDR, _BCT_BCTPID1_##Field)
#define _BCT_BCTPID1_FSET(Field,Val)	  _PFIELD_SET(_BCT_BCTPID1_ADDR, _BCT_BCTPID1_##Field, Val)
#define _BCT_BCTPID1_AOI(AND,OR,INV)	  _PREG_AOI(_BCT_BCTPID1_ADDR,AND,OR,INV)
#define _BCT_BCTPID1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_BCT_BCTPID1_ADDR, _BCT_BCTPID1_##Field,AND,OR,INV)


/*--------------------- Register: BCTPID1 -----------------------*/
#define _BCT_BCTPID1_GET		  _PREG_GET(_BCT_BCTPID1_ADDR) 
#define _BCT_BCTPID1_SET(Val)		  _PREG_SET(_BCT_BCTPID1_ADDR,Val)
#define _BCT_BCTPID1_FGET(Field)	  _PFIELD_GET(_BCT_BCTPID1_ADDR, _BCT_BCTPID1_##Field)
#define _BCT_BCTPID1_FSET(Field,Val)	  _PFIELD_SET(_BCT_BCTPID1_ADDR, _BCT_BCTPID1_##Field, Val)
#define _BCT_BCTPID1_AOI(AND,OR,INV)	  _PREG_AOI(_BCT_BCTPID1_ADDR,AND,OR,INV)
#define _BCT_BCTPID1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_BCT_BCTPID1_ADDR, _BCT_BCTPID1_##Field,AND,OR,INV)


/*--------------------- Register: BCTPID2 -----------------------*/
#define _BCT_BCTPID2_GET		  _PREG_GET(_BCT_BCTPID2_ADDR) 
#define _BCT_BCTPID2_SET(Val)		  _PREG_SET(_BCT_BCTPID2_ADDR,Val)
#define _BCT_BCTPID2_FGET(Field)	  _PFIELD_GET(_BCT_BCTPID2_ADDR, _BCT_BCTPID2_##Field)
#define _BCT_BCTPID2_FSET(Field,Val)	  _PFIELD_SET(_BCT_BCTPID2_ADDR, _BCT_BCTPID2_##Field, Val)
#define _BCT_BCTPID2_AOI(AND,OR,INV)	  _PREG_AOI(_BCT_BCTPID2_ADDR,AND,OR,INV)
#define _BCT_BCTPID2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_BCT_BCTPID2_ADDR, _BCT_BCTPID2_##Field,AND,OR,INV)


/*--------------------- Register: BCTPID2 -----------------------*/
#define _BCT_BCTPID2_GET		  _PREG_GET(_BCT_BCTPID2_ADDR) 
#define _BCT_BCTPID2_SET(Val)		  _PREG_SET(_BCT_BCTPID2_ADDR,Val)
#define _BCT_BCTPID2_FGET(Field)	  _PFIELD_GET(_BCT_BCTPID2_ADDR, _BCT_BCTPID2_##Field)
#define _BCT_BCTPID2_FSET(Field,Val)	  _PFIELD_SET(_BCT_BCTPID2_ADDR, _BCT_BCTPID2_##Field, Val)
#define _BCT_BCTPID2_AOI(AND,OR,INV)	  _PREG_AOI(_BCT_BCTPID2_ADDR,AND,OR,INV)
#define _BCT_BCTPID2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_BCT_BCTPID2_ADDR, _BCT_BCTPID2_##Field,AND,OR,INV)


/*--------------------- Register: BCTEMU -----------------------*/
#define _BCT_BCTEMU_GET		  _PREG_GET(_BCT_BCTEMU_ADDR) 
#define _BCT_BCTEMU_SET(Val)		  _PREG_SET(_BCT_BCTEMU_ADDR,Val)
#define _BCT_BCTEMU_FGET(Field)	  _PFIELD_GET(_BCT_BCTEMU_ADDR, _BCT_BCTEMU_##Field)
#define _BCT_BCTEMU_FSET(Field,Val)	  _PFIELD_SET(_BCT_BCTEMU_ADDR, _BCT_BCTEMU_##Field, Val)
#define _BCT_BCTEMU_AOI(AND,OR,INV)	  _PREG_AOI(_BCT_BCTEMU_ADDR,AND,OR,INV)
#define _BCT_BCTEMU_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_BCT_BCTEMU_ADDR, _BCT_BCTEMU_##Field,AND,OR,INV)


/*--------------------- Register: BCTEMU -----------------------*/
#define _BCT_BCTEMU_GET		  _PREG_GET(_BCT_BCTEMU_ADDR) 
#define _BCT_BCTEMU_SET(Val)		  _PREG_SET(_BCT_BCTEMU_ADDR,Val)
#define _BCT_BCTEMU_FGET(Field)	  _PFIELD_GET(_BCT_BCTEMU_ADDR, _BCT_BCTEMU_##Field)
#define _BCT_BCTEMU_FSET(Field,Val)	  _PFIELD_SET(_BCT_BCTEMU_ADDR, _BCT_BCTEMU_##Field, Val)
#define _BCT_BCTEMU_AOI(AND,OR,INV)	  _PREG_AOI(_BCT_BCTEMU_ADDR,AND,OR,INV)
#define _BCT_BCTEMU_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_BCT_BCTEMU_ADDR, _BCT_BCTEMU_##Field,AND,OR,INV)


/*--------------------- Register: BCTCLK -----------------------*/
#define _BCT_BCTCLK_GET		  _PREG_GET(_BCT_BCTCLK_ADDR) 
#define _BCT_BCTCLK_SET(Val)		  _PREG_SET(_BCT_BCTCLK_ADDR,Val)
#define _BCT_BCTCLK_FGET(Field)	  _PFIELD_GET(_BCT_BCTCLK_ADDR, _BCT_BCTCLK_##Field)
#define _BCT_BCTCLK_FSET(Field,Val)	  _PFIELD_SET(_BCT_BCTCLK_ADDR, _BCT_BCTCLK_##Field, Val)
#define _BCT_BCTCLK_AOI(AND,OR,INV)	  _PREG_AOI(_BCT_BCTCLK_ADDR,AND,OR,INV)
#define _BCT_BCTCLK_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_BCT_BCTCLK_ADDR, _BCT_BCTCLK_##Field,AND,OR,INV)


/*--------------------- Register: BCTCNT1 -----------------------*/
#define _BCT_BCTCNT1_GET		  _PREG_GET(_BCT_BCTCNT1_ADDR) 
#define _BCT_BCTCNT1_SET(Val)		  _PREG_SET(_BCT_BCTCNT1_ADDR,Val)
#define _BCT_BCTCNT1_FGET(Field)	  _PFIELD_GET(_BCT_BCTCNT1_ADDR, _BCT_BCTCNT1_##Field)
#define _BCT_BCTCNT1_FSET(Field,Val)	  _PFIELD_SET(_BCT_BCTCNT1_ADDR, _BCT_BCTCNT1_##Field, Val)
#define _BCT_BCTCNT1_AOI(AND,OR,INV)	  _PREG_AOI(_BCT_BCTCNT1_ADDR,AND,OR,INV)
#define _BCT_BCTCNT1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_BCT_BCTCNT1_ADDR, _BCT_BCTCNT1_##Field,AND,OR,INV)


/*--------------------- Register: BCTCNT2 -----------------------*/
#define _BCT_BCTCNT2_GET		  _PREG_GET(_BCT_BCTCNT2_ADDR) 
#define _BCT_BCTCNT2_SET(Val)		  _PREG_SET(_BCT_BCTCNT2_ADDR,Val)
#define _BCT_BCTCNT2_FGET(Field)	  _PFIELD_GET(_BCT_BCTCNT2_ADDR, _BCT_BCTCNT2_##Field)
#define _BCT_BCTCNT2_FSET(Field,Val)	  _PFIELD_SET(_BCT_BCTCNT2_ADDR, _BCT_BCTCNT2_##Field, Val)
#define _BCT_BCTCNT2_AOI(AND,OR,INV)	  _PREG_AOI(_BCT_BCTCNT2_ADDR,AND,OR,INV)
#define _BCT_BCTCNT2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_BCT_BCTCNT2_ADDR, _BCT_BCTCNT2_##Field,AND,OR,INV)


/*--------------------- Register: BCTCNT3 -----------------------*/
#define _BCT_BCTCNT3_GET		  _PREG_GET(_BCT_BCTCNT3_ADDR) 
#define _BCT_BCTCNT3_SET(Val)		  _PREG_SET(_BCT_BCTCNT3_ADDR,Val)
#define _BCT_BCTCNT3_FGET(Field)	  _PFIELD_GET(_BCT_BCTCNT3_ADDR, _BCT_BCTCNT3_##Field)
#define _BCT_BCTCNT3_FSET(Field,Val)	  _PFIELD_SET(_BCT_BCTCNT3_ADDR, _BCT_BCTCNT3_##Field, Val)
#define _BCT_BCTCNT3_AOI(AND,OR,INV)	  _PREG_AOI(_BCT_BCTCNT3_ADDR,AND,OR,INV)
#define _BCT_BCTCNT3_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_BCT_BCTCNT3_ADDR, _BCT_BCTCNT3_##Field,AND,OR,INV)


/*--------------------- Register: BCTCNT4 -----------------------*/
#define _BCT_BCTCNT4_GET		  _PREG_GET(_BCT_BCTCNT4_ADDR) 
#define _BCT_BCTCNT4_SET(Val)		  _PREG_SET(_BCT_BCTCNT4_ADDR,Val)
#define _BCT_BCTCNT4_FGET(Field)	  _PFIELD_GET(_BCT_BCTCNT4_ADDR, _BCT_BCTCNT4_##Field)
#define _BCT_BCTCNT4_FSET(Field,Val)	  _PFIELD_SET(_BCT_BCTCNT4_ADDR, _BCT_BCTCNT4_##Field, Val)
#define _BCT_BCTCNT4_AOI(AND,OR,INV)	  _PREG_AOI(_BCT_BCTCNT4_ADDR,AND,OR,INV)
#define _BCT_BCTCNT4_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_BCT_BCTCNT4_ADDR, _BCT_BCTCNT4_##Field,AND,OR,INV)


/*--------------------- Register: BCTPRD1 -----------------------*/
#define _BCT_BCTPRD1_GET		  _PREG_GET(_BCT_BCTPRD1_ADDR) 
#define _BCT_BCTPRD1_SET(Val)		  _PREG_SET(_BCT_BCTPRD1_ADDR,Val)
#define _BCT_BCTPRD1_FGET(Field)	  _PFIELD_GET(_BCT_BCTPRD1_ADDR, _BCT_BCTPRD1_##Field)
#define _BCT_BCTPRD1_FSET(Field,Val)	  _PFIELD_SET(_BCT_BCTPRD1_ADDR, _BCT_BCTPRD1_##Field, Val)
#define _BCT_BCTPRD1_AOI(AND,OR,INV)	  _PREG_AOI(_BCT_BCTPRD1_ADDR,AND,OR,INV)
#define _BCT_BCTPRD1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_BCT_BCTPRD1_ADDR, _BCT_BCTPRD1_##Field,AND,OR,INV)


/*--------------------- Register: BCTPRD2 -----------------------*/
#define _BCT_BCTPRD2_GET		  _PREG_GET(_BCT_BCTPRD2_ADDR) 
#define _BCT_BCTPRD2_SET(Val)		  _PREG_SET(_BCT_BCTPRD2_ADDR,Val)
#define _BCT_BCTPRD2_FGET(Field)	  _PFIELD_GET(_BCT_BCTPRD2_ADDR, _BCT_BCTPRD2_##Field)
#define _BCT_BCTPRD2_FSET(Field,Val)	  _PFIELD_SET(_BCT_BCTPRD2_ADDR, _BCT_BCTPRD2_##Field, Val)
#define _BCT_BCTPRD2_AOI(AND,OR,INV)	  _PREG_AOI(_BCT_BCTPRD2_ADDR,AND,OR,INV)
#define _BCT_BCTPRD2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_BCT_BCTPRD2_ADDR, _BCT_BCTPRD2_##Field,AND,OR,INV)


/*--------------------- Register: BCTPRD3 -----------------------*/
#define _BCT_BCTPRD3_GET		  _PREG_GET(_BCT_BCTPRD3_ADDR) 
#define _BCT_BCTPRD3_SET(Val)		  _PREG_SET(_BCT_BCTPRD3_ADDR,Val)
#define _BCT_BCTPRD3_FGET(Field)	  _PFIELD_GET(_BCT_BCTPRD3_ADDR, _BCT_BCTPRD3_##Field)
#define _BCT_BCTPRD3_FSET(Field,Val)	  _PFIELD_SET(_BCT_BCTPRD3_ADDR, _BCT_BCTPRD3_##Field, Val)
#define _BCT_BCTPRD3_AOI(AND,OR,INV)	  _PREG_AOI(_BCT_BCTPRD3_ADDR,AND,OR,INV)
#define _BCT_BCTPRD3_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_BCT_BCTPRD3_ADDR, _BCT_BCTPRD3_##Field,AND,OR,INV)


/*--------------------- Register: BCTPRD4 -----------------------*/
#define _BCT_BCTPRD4_GET		  _PREG_GET(_BCT_BCTPRD4_ADDR) 
#define _BCT_BCTPRD4_SET(Val)		  _PREG_SET(_BCT_BCTPRD4_ADDR,Val)
#define _BCT_BCTPRD4_FGET(Field)	  _PFIELD_GET(_BCT_BCTPRD4_ADDR, _BCT_BCTPRD4_##Field)
#define _BCT_BCTPRD4_FSET(Field,Val)	  _PFIELD_SET(_BCT_BCTPRD4_ADDR, _BCT_BCTPRD4_##Field, Val)
#define _BCT_BCTPRD4_AOI(AND,OR,INV)	  _PREG_AOI(_BCT_BCTPRD4_ADDR,AND,OR,INV)
#define _BCT_BCTPRD4_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_BCT_BCTPRD4_ADDR, _BCT_BCTPRD4_##Field,AND,OR,INV)


/*--------------------- Register: BCTGPINT -----------------------*/
#define _BCT_BCTGPINT_GET		  _PREG_GET(_BCT_BCTGPINT_ADDR) 
#define _BCT_BCTGPINT_SET(Val)		  _PREG_SET(_BCT_BCTGPINT_ADDR,Val)
#define _BCT_BCTGPINT_FGET(Field)	  _PFIELD_GET(_BCT_BCTGPINT_ADDR, _BCT_BCTGPINT_##Field)
#define _BCT_BCTGPINT_FSET(Field,Val)	  _PFIELD_SET(_BCT_BCTGPINT_ADDR, _BCT_BCTGPINT_##Field, Val)
#define _BCT_BCTGPINT_AOI(AND,OR,INV)	  _PREG_AOI(_BCT_BCTGPINT_ADDR,AND,OR,INV)
#define _BCT_BCTGPINT_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_BCT_BCTGPINT_ADDR, _BCT_BCTGPINT_##Field,AND,OR,INV)


/*--------------------- Register: BCTGPEN -----------------------*/
#define _BCT_BCTGPEN_GET		  _PREG_GET(_BCT_BCTGPEN_ADDR) 
#define _BCT_BCTGPEN_SET(Val)		  _PREG_SET(_BCT_BCTGPEN_ADDR,Val)
#define _BCT_BCTGPEN_FGET(Field)	  _PFIELD_GET(_BCT_BCTGPEN_ADDR, _BCT_BCTGPEN_##Field)
#define _BCT_BCTGPEN_FSET(Field,Val)	  _PFIELD_SET(_BCT_BCTGPEN_ADDR, _BCT_BCTGPEN_##Field, Val)
#define _BCT_BCTGPEN_AOI(AND,OR,INV)	  _PREG_AOI(_BCT_BCTGPEN_ADDR,AND,OR,INV)
#define _BCT_BCTGPEN_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_BCT_BCTGPEN_ADDR, _BCT_BCTGPEN_##Field,AND,OR,INV)



/*--------------------- Register: BCTGPDIR -----------------------*/
#define _BCT_BCTGPDIR_GET		  _PREG_GET(_BCT_BCTGPDIR_ADDR) 
#define _BCT_BCTGPDIR_SET(Val)		  _PREG_SET(_BCT_BCTGPDIR_ADDR,Val)
#define _BCT_BCTGPDIR_FGET(Field)	  _PFIELD_GET(_BCT_BCTGPDIR_ADDR, _BCT_BCTGPDIR_##Field)
#define _BCT_BCTGPDIR_FSET(Field,Val)	  _PFIELD_SET(_BCT_BCTGPDIR_ADDR, _BCT_BCTGPDIR_##Field, Val)
#define _BCT_BCTGPDIR_AOI(AND,OR,INV)	  _PREG_AOI(_BCT_BCTGPDIR_ADDR,AND,OR,INV)
#define _BCT_BCTGPDIR_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_BCT_BCTGPDIR_ADDR, _BCT_BCTGPDIR_##Field,AND,OR,INV)


/*--------------------- Register: BCTGPDAT -----------------------*/
#define _BCT_BCTGPDAT_GET		  _PREG_GET(_BCT_BCTGPDAT_ADDR) 
#define _BCT_BCTGPDAT_SET(Val)		  _PREG_SET(_BCT_BCTGPDAT_ADDR,Val)
#define _BCT_BCTGPDAT_FGET(Field)	  _PFIELD_GET(_BCT_BCTGPDAT_ADDR, _BCT_BCTGPDAT_##Field)
#define _BCT_BCTGPDAT_FSET(Field,Val)	  _PFIELD_SET(_BCT_BCTGPDAT_ADDR, _BCT_BCTGPDAT_##Field, Val)
#define _BCT_BCTGPDAT_AOI(AND,OR,INV)	  _PREG_AOI(_BCT_BCTGPDAT_ADDR,AND,OR,INV)
#define _BCT_BCTGPDAT_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_BCT_BCTGPDAT_ADDR, _BCT_BCTGPDAT_##Field,AND,OR,INV)


/*--------------------- Register: BCTCTL1 -----------------------*/
#define _BCT_BCTCTL1_GET		  _PREG_GET(_BCT_BCTCTL1_ADDR) 
#define _BCT_BCTCTL1_SET(Val)		  _PREG_SET(_BCT_BCTCTL1_ADDR,Val)
#define _BCT_BCTCTL1_FGET(Field)	  _PFIELD_GET(_BCT_BCTCTL1_ADDR, _BCT_BCTCTL1_##Field)
#define _BCT_BCTCTL1_FSET(Field,Val)	  _PFIELD_SET(_BCT_BCTCTL1_ADDR, _BCT_BCTCTL1_##Field, Val)
#define _BCT_BCTCTL1_AOI(AND,OR,INV)	  _PREG_AOI(_BCT_BCTCTL1_ADDR,AND,OR,INV)
#define _BCT_BCTCTL1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_BCT_BCTCTL1_ADDR, _BCT_BCTCTL1_##Field,AND,OR,INV)


/*--------------------- Register: BCTCTL2 -----------------------*/
#define _BCT_BCTCTL2_GET		  _PREG_GET(_BCT_BCTCTL2_ADDR) 
#define _BCT_BCTCTL2_SET(Val)		  _PREG_SET(_BCT_BCTCTL2_ADDR,Val)
#define _BCT_BCTCTL2_FGET(Field)	  _PFIELD_GET(_BCT_BCTCTL2_ADDR, _BCT_BCTCTL2_##Field)
#define _BCT_BCTCTL2_FSET(Field,Val)	  _PFIELD_SET(_BCT_BCTCTL2_ADDR, _BCT_BCTCTL2_##Field, Val)
#define _BCT_BCTCTL2_AOI(AND,OR,INV)	  _PREG_AOI(_BCT_BCTCTL2_ADDR,AND,OR,INV)
#define _BCT_BCTCTL2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_BCT_BCTCTL2_ADDR, _BCT_BCTCTL2_##Field,AND,OR,INV)


/*--------------------- Register: BCTGCTL1 -----------------------*/
#define _BCT_BCTGCTL1_GET		  _PREG_GET(_BCT_BCTGCTL1_ADDR) 
#define _BCT_BCTGCTL1_SET(Val)		  _PREG_SET(_BCT_BCTGCTL1_ADDR,Val)
#define _BCT_BCTGCTL1_FGET(Field)	  _PFIELD_GET(_BCT_BCTGCTL1_ADDR, _BCT_BCTGCTL1_##Field)
#define _BCT_BCTGCTL1_FSET(Field,Val)	  _PFIELD_SET(_BCT_BCTGCTL1_ADDR, _BCT_BCTGCTL1_##Field, Val)
#define _BCT_BCTGCTL1_AOI(AND,OR,INV)	  _PREG_AOI(_BCT_BCTGCTL1_ADDR,AND,OR,INV)
#define _BCT_BCTGCTL1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_BCT_BCTGCTL1_ADDR, _BCT_BCTGCTL1_##Field,AND,OR,INV)



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the BCTGCTL1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _BCT_BCTGCTL1	 - Note: Add description here
*
* Fields:
*	(RW)   _BCT_BCTGCTL1_TIM12RS	
*	(RW)   _BCT_BCTGCTL1_TIM34RS	
*	(RW)   _BCT_BCTGCTL1_TIMMODE	
*	(RW)   _BCT_BCTGCTL1_PSC34	
*	(R)   _BCT_BCTGCTL1_TDDR34	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTGCTL1_TIM12RS:	
\*----------------------------------------------------------------*/

#define _BCT_BCTGCTL1_TIM12RS_SHIFT		(000000u)
#define _BCT_BCTGCTL1_TIM12RS_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTGCTL1_TIM12RS_SHIFT)
#define _BCT_BCTGCTL1_TIM12RS_MASK		(_BCT_BCTGCTL1_TIM12RS_MK(0x0001u))
#define _BCT_BCTGCTL1_TIM12RS_CLR		(~(_BCT_BCTGCTL1_TIM12RS_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTGCTL1_TIM34RS:	
\*----------------------------------------------------------------*/

#define _BCT_BCTGCTL1_TIM34RS_SHIFT		(0x0001u)
#define _BCT_BCTGCTL1_TIM34RS_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTGCTL1_TIM34RS_SHIFT)
#define _BCT_BCTGCTL1_TIM34RS_MASK		(_BCT_BCTGCTL1_TIM34RS_MK(0x0001u))
#define _BCT_BCTGCTL1_TIM34RS_CLR		(~(_BCT_BCTGCTL1_TIM34RS_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTGCTL1_TIMMODE:	
\*----------------------------------------------------------------*/

#define _BCT_BCTGCTL1_TIMMODE_SHIFT		(0x0002u)
#define _BCT_BCTGCTL1_TIMMODE_MK(n)		(((Uint16)(n) & 0x0003u) << _BCT_BCTGCTL1_TIMMODE_SHIFT)
#define _BCT_BCTGCTL1_TIMMODE_MASK		(_BCT_BCTGCTL1_TIMMODE_MK(0x0003u))
#define _BCT_BCTGCTL1_TIMMODE_CLR		(~(_BCT_BCTGCTL1_TIMMODE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTGCTL1_PSC34:	
\*----------------------------------------------------------------*/

#define _BCT_BCTGCTL1_PSC34_SHIFT		(0x0008u)
#define _BCT_BCTGCTL1_PSC34_MK(n)		(((Uint16)(n) & 0x000fu) << _BCT_BCTGCTL1_PSC34_SHIFT)
#define _BCT_BCTGCTL1_PSC34_MASK		(_BCT_BCTGCTL1_PSC34_MK(0x000fu))
#define _BCT_BCTGCTL1_PSC34_CLR		(~(_BCT_BCTGCTL1_PSC34_MASK))



/*----------------------------------------------------------------*\
*   (R)  _BCT_BCTGCTL1_TDDR34:	
\*----------------------------------------------------------------*/

#define _BCT_BCTGCTL1_TDDR34_SHIFT		(0x000cu)
#define _BCT_BCTGCTL1_TDDR34_MK(n)		(((Uint16)(n) & 0x000fu) << _BCT_BCTGCTL1_TDDR34_SHIFT)
#define _BCT_BCTGCTL1_TDDR34_MASK		(_BCT_BCTGCTL1_TDDR34_MK(0x000fu))
#define _BCT_BCTGCTL1_TDDR34_CLR		(~(_BCT_BCTGCTL1_TDDR34_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the BCTGPDIR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _BCT_BCTGPDIR	 - Note: Add description here
*
* Fields:
*	(RW)   _BCT_BCTGPDIR_TIN1DIR	
*	(RW)   _BCT_BCTGPDIR_TOUT1DIR	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTGPDIR_TIN1DIR:	
\*----------------------------------------------------------------*/

#define _BCT_BCTGPDIR_TIN1DIR_SHIFT		(000000u)
#define _BCT_BCTGPDIR_TIN1DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTGPDIR_TIN1DIR_SHIFT)
#define _BCT_BCTGPDIR_TIN1DIR_MASK		(_BCT_BCTGPDIR_TIN1DIR_MK(0x0001u))
#define _BCT_BCTGPDIR_TIN1DIR_CLR		(~(_BCT_BCTGPDIR_TIN1DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTGPDIR_TOUT1DIR:	
\*----------------------------------------------------------------*/

#define _BCT_BCTGPDIR_TOUT1DIR_SHIFT		(0x0001u)
#define _BCT_BCTGPDIR_TOUT1DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTGPDIR_TOUT1DIR_SHIFT)
#define _BCT_BCTGPDIR_TOUT1DIR_MASK		(_BCT_BCTGPDIR_TOUT1DIR_MK(0x0001u))
#define _BCT_BCTGPDIR_TOUT1DIR_CLR		(~(_BCT_BCTGPDIR_TOUT1DIR_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the BCTPRD1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _BCT_BCTPRD1	 - Note: Add description here
*
* Fields:
*	(RW)   _BCT_BCTPRD1_PRD	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTPRD1_PRD:	
\*----------------------------------------------------------------*/

#define _BCT_BCTPRD1_PRD_SHIFT		(000000u)
#define _BCT_BCTPRD1_PRD_MK(n)		(((Uint16)(n) & 0xffffu) << _BCT_BCTPRD1_PRD_SHIFT)
#define _BCT_BCTPRD1_PRD_MASK		(_BCT_BCTPRD1_PRD_MK(0xffffu))
#define _BCT_BCTPRD1_PRD_CLR		(~(_BCT_BCTPRD1_PRD_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the BCTCNT1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _BCT_BCTCNT1	 - Note: Add description here
*
* Fields:
*	(RW)   _BCT_BCTCNT1_CNT	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTCNT1_CNT:	
\*----------------------------------------------------------------*/

#define _BCT_BCTCNT1_CNT_SHIFT		(000000u)
#define _BCT_BCTCNT1_CNT_MK(n)		(((Uint16)(n) & 0xffffu) << _BCT_BCTCNT1_CNT_SHIFT)
#define _BCT_BCTCNT1_CNT_MASK		(_BCT_BCTCNT1_CNT_MK(0xffffu))
#define _BCT_BCTCNT1_CNT_CLR		(~(_BCT_BCTCNT1_CNT_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the BCTPRD2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _BCT_BCTPRD2	 - Note: Add description here
*
* Fields:
*	(RW)   _BCT_BCTPRD2_PRD	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTPRD2_PRD:	
\*----------------------------------------------------------------*/

#define _BCT_BCTPRD2_PRD_SHIFT		(000000u)
#define _BCT_BCTPRD2_PRD_MK(n)		(((Uint16)(n) & 0xffffu) << _BCT_BCTPRD2_PRD_SHIFT)
#define _BCT_BCTPRD2_PRD_MASK		(_BCT_BCTPRD2_PRD_MK(0xffffu))
#define _BCT_BCTPRD2_PRD_CLR		(~(_BCT_BCTPRD2_PRD_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the BCTCNT2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _BCT_BCTCNT2	 - Note: Add description here
*
* Fields:
*	(RW)   _BCT_BCTCNT2_CNT	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTCNT2_CNT:	
\*----------------------------------------------------------------*/

#define _BCT_BCTCNT2_CNT_SHIFT		(000000u)
#define _BCT_BCTCNT2_CNT_MK(n)		(((Uint16)(n) & 0xffffu) << _BCT_BCTCNT2_CNT_SHIFT)
#define _BCT_BCTCNT2_CNT_MASK		(_BCT_BCTCNT2_CNT_MK(0xffffu))
#define _BCT_BCTCNT2_CNT_CLR		(~(_BCT_BCTCNT2_CNT_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the BCTCTL1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _BCT_BCTCTL1	 - Note: Add description here
*
* Fields:
*	(R)   _BCT_BCTCTL1_TSTAT	
*	(RW)   _BCT_BCTCTL1_INVOUT	
*	(RW)   _BCT_BCTCTL1_INVIN	
*	(RW)   _BCT_BCTCTL1_CP	
*	(RW)   _BCT_BCTCTL1_PWID	
*	(RW)   _BCT_BCTCTL1_ENAMODE	
*	(RW)   _BCT_BCTCTL1_CLKSRC	
*	(RW)   _BCT_BCTCTL1_TIEN	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _BCT_BCTCTL1_TSTAT:	
\*----------------------------------------------------------------*/

#define _BCT_BCTCTL1_TSTAT_SHIFT		(000000u)
#define _BCT_BCTCTL1_TSTAT_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTCTL1_TSTAT_SHIFT)
#define _BCT_BCTCTL1_TSTAT_MASK		(_BCT_BCTCTL1_TSTAT_MK(0x0001u))
#define _BCT_BCTCTL1_TSTAT_CLR		(~(_BCT_BCTCTL1_TSTAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTCTL1_INVOUTP:	
\*----------------------------------------------------------------*/

#define _BCT_BCTCTL1_INVOUT_SHIFT		(0x0001u)
#define _BCT_BCTCTL1_INVOUT_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTCTL1_INVOUT_SHIFT)
#define _BCT_BCTCTL1_INVOUT_MASK		(_BCT_BCTCTL1_INVOUT_MK(0x0001u))
#define _BCT_BCTCTL1_INVOUT_CLR		(~(_BCT_BCTCTL1_INVOUT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTCTL1_INVIN:	
\*----------------------------------------------------------------*/

#define _BCT_BCTCTL1_INVIN_SHIFT		(0x0002u)
#define _BCT_BCTCTL1_INVIN_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTCTL1_INVIN_SHIFT)
#define _BCT_BCTCTL1_INVIN_MASK		(_BCT_BCTCTL1_INVIN_MK(0x0001u))
#define _BCT_BCTCTL1_INVIN_CLR		(~(_BCT_BCTCTL1_INVIN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTCTL1_CP:	
\*----------------------------------------------------------------*/

#define _BCT_BCTCTL1_CP_SHIFT		(0x0003u)
#define _BCT_BCTCTL1_CP_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTCTL1_CP_SHIFT)
#define _BCT_BCTCTL1_CP_MASK		(_BCT_BCTCTL1_CP_MK(0x0001u))
#define _BCT_BCTCTL1_CP_CLR		(~(_BCT_BCTCTL1_CP_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTCTL1_PWID:	
\*----------------------------------------------------------------*/

#define _BCT_BCTCTL1_PWID_SHIFT		(0x0004u)
#define _BCT_BCTCTL1_PWID_MK(n)		(((Uint16)(n) & 0x0003u) << _BCT_BCTCTL1_PWID_SHIFT)
#define _BCT_BCTCTL1_PWID_MASK		(_BCT_BCTCTL1_PWID_MK(0x0003u))
#define _BCT_BCTCTL1_PWID_CLR		(~(_BCT_BCTCTL1_PWID_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTCTL1_ENAMODE:	
\*----------------------------------------------------------------*/

#define _BCT_BCTCTL1_ENAMODE_SHIFT		(0x0006u)
#define _BCT_BCTCTL1_ENAMODE_MK(n)		(((Uint16)(n) & 0x0003u) << _BCT_BCTCTL1_ENAMODE_SHIFT)
#define _BCT_BCTCTL1_ENAMODE_MASK		(_BCT_BCTCTL1_ENAMODE_MK(0x0003u))
#define _BCT_BCTCTL1_ENAMODE_CLR		(~(_BCT_BCTCTL1_ENAMODE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTCTL1_CLKSRC:	
\*----------------------------------------------------------------*/

#define _BCT_BCTCTL1_CLKSRC_SHIFT		(0x0008u)
#define _BCT_BCTCTL1_CLKSRC_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTCTL1_CLKSRC_SHIFT)
#define _BCT_BCTCTL1_CLKSRC_MASK		(_BCT_BCTCTL1_CLKSRC_MK(0x0001u))
#define _BCT_BCTCTL1_CLKSRC_CLR		(~(_BCT_BCTCTL1_CLKSRC_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTCTL1_TIEN:	
\*----------------------------------------------------------------*/

#define _BCT_BCTCTL1_TIEN_SHIFT		(0x0009u)
#define _BCT_BCTCTL1_TIEN_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTCTL1_TIEN_SHIFT)
#define _BCT_BCTCTL1_TIEN_MASK		(_BCT_BCTCTL1_TIEN_MK(0x0001u))
#define _BCT_BCTCTL1_TIEN_CLR		(~(_BCT_BCTCTL1_TIEN_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the BCTPRD3 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _BCT_BCTPRD3	 - Note: Add description here
*
* Fields:
*	(RW)   _BCT_BCTPRD3_PRD	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTPRD3_PRD:	
\*----------------------------------------------------------------*/

#define _BCT_BCTPRD3_PRD_SHIFT		(000000u)
#define _BCT_BCTPRD3_PRD_MK(n)		(((Uint16)(n) & 0xffffu) << _BCT_BCTPRD3_PRD_SHIFT)
#define _BCT_BCTPRD3_PRD_MASK		(_BCT_BCTPRD3_PRD_MK(0xffffu))
#define _BCT_BCTPRD3_PRD_CLR		(~(_BCT_BCTPRD3_PRD_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the BCTCNT3 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _BCT_BCTCNT3	 - Note: Add description here
*
* Fields:
*	(RW)   _BCT_BCTCNT3_CNT	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTCNT3_CNT:	
\*----------------------------------------------------------------*/

#define _BCT_BCTCNT3_CNT_SHIFT		(000000u)
#define _BCT_BCTCNT3_CNT_MK(n)		(((Uint16)(n) & 0xffffu) << _BCT_BCTCNT3_CNT_SHIFT)
#define _BCT_BCTCNT3_CNT_MASK		(_BCT_BCTCNT3_CNT_MK(0xffffu))
#define _BCT_BCTCNT3_CNT_CLR		(~(_BCT_BCTCNT3_CNT_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the BCTCLK register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _BCT_BCTCLK	 - Note: Add description here
*
* Fields:
*	(R)   _BCT_BCTCLK_VBUSCR	
*
\******************************************************************************/


/*----------------------------------------------------------------*\
*   (R)  _BCT_BCTCLK_VBUSCR:	
\*----------------------------------------------------------------*/

#define _BCT_BCTCLK_VBUSCR_SHIFT		(000000u)
#define _BCT_BCTCLK_VBUSCR_MK(n)		(((Uint16)(n) & 0x000fu) << _BCT_BCTCLK_VBUSCR_SHIFT)
#define _BCT_BCTCLK_VBUSCR_MASK		(_BCT_BCTCLK_VBUSCR_MK(0x000fu))
#define _BCT_BCTCLK_VBUSCR_CLR		(~(_BCT_BCTCLK_VBUSCR_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the BCTPRD4 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _BCT_BCTPRD4	 - Note: Add description here
*
* Fields:
*	(RW)   _BCT_BCTPRD4_PRD	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTPRD4_PRD:	
\*----------------------------------------------------------------*/

#define _BCT_BCTPRD4_PRD_SHIFT		(000000u)
#define _BCT_BCTPRD4_PRD_MK(n)		(((Uint16)(n) & 0xffffu) << _BCT_BCTPRD4_PRD_SHIFT)
#define _BCT_BCTPRD4_PRD_MASK		(_BCT_BCTPRD4_PRD_MK(0xffffu))
#define _BCT_BCTPRD4_PRD_CLR		(~(_BCT_BCTPRD4_PRD_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the BCTCNT4 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _BCT_BCTCNT4	 - Note: Add description here
*
* Fields:
*	(R)   _BCT_BCTCNT4_CNT	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _BCT_BCTCNT4_CNT:	
\*----------------------------------------------------------------*/

#define _BCT_BCTCNT4_CNT_SHIFT		(000000u)
#define _BCT_BCTCNT4_CNT_MK(n)		(((Uint16)(n) & 0xffffu) << _BCT_BCTCNT4_CNT_SHIFT)
#define _BCT_BCTCNT4_CNT_MASK		(_BCT_BCTCNT4_CNT_MK(0xffffu))
#define _BCT_BCTCNT4_CNT_CLR		(~(_BCT_BCTCNT4_CNT_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the BCTPID1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _BCT_BCTPID1	 - Note: Add description here
*
* Fields:
*	(R)   _BCT_BCTPID1_REVISION	
*	(R)   _BCT_BCTPID1_CLASS	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _BCT_BCTPID1_REVISION:	
\*----------------------------------------------------------------*/

#define _BCT_BCTPID1_REVISION_SHIFT		(000000u)
#define _BCT_BCTPID1_REVISION_MK(n)		(((Uint16)(n) & 0x00ffu) << _BCT_BCTPID1_REVISION_SHIFT)
#define _BCT_BCTPID1_REVISION_MASK		(_BCT_BCTPID1_REVISION_MK(0x00ffu))
#define _BCT_BCTPID1_REVISION_CLR		(~(_BCT_BCTPID1_REVISION_MASK))



/*----------------------------------------------------------------*\
*   (R)  _BCT_BCTPID1_CLASS:	
\*----------------------------------------------------------------*/

#define _BCT_BCTPID1_CLASS_SHIFT		(0x0008u)
#define _BCT_BCTPID1_CLASS_MK(n)		(((Uint16)(n) & 0x00ffu) << _BCT_BCTPID1_CLASS_SHIFT)
#define _BCT_BCTPID1_CLASS_MASK		(_BCT_BCTPID1_CLASS_MK(0x00ffu))
#define _BCT_BCTPID1_CLASS_CLR		(~(_BCT_BCTPID1_CLASS_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the BCTPID2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _BCT_BCTPID2	 - Note: Add description here
*
* Fields:
*	(R)   _BCT_BCTPID2_TYPE	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _BCT_BCTPID2_TYPE:	
\*----------------------------------------------------------------*/

#define _BCT_BCTPID2_TYPE_SHIFT		(000000u)
#define _BCT_BCTPID2_TYPE_MK(n)		(((Uint16)(n) & 0x007fu) << _BCT_BCTPID2_TYPE_SHIFT)
#define _BCT_BCTPID2_TYPE_MASK		(_BCT_BCTPID2_TYPE_MK(0x007fu))
#define _BCT_BCTPID2_TYPE_CLR		(~(_BCT_BCTPID2_TYPE_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the BCTCTL2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _BCT_BCTCTL2	 - Note: Add description here
*
* Fields:
*	(R)   _BCT_BCTCTL2_TSTAT	
*	(RW)   _BCT_BCTCTL2_INVOUT
*	(RW)   _BCT_BCTCTL2_INVIN	
*	(RW)   _BCT_BCTCTL2_CP	
*	(RW)   _BCT_BCTCTL2_PWID	
*	(RW)   _BCT_BCTCTL2_ENAMODE	
*	(RW)   _BCT_BCTCTL2_CLKSRC	
*	(RW)   _BCT_BCTCTL2_TIEN	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _BCT_BCTCTL2_TSTAT:	
\*----------------------------------------------------------------*/

#define _BCT_BCTCTL2_TSTAT_SHIFT		(000000u)
#define _BCT_BCTCTL2_TSTAT_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTCTL2_TSTAT_SHIFT)
#define _BCT_BCTCTL2_TSTAT_MASK		(_BCT_BCTCTL2_TSTAT_MK(0x0001u))
#define _BCT_BCTCTL2_TSTAT_CLR		(~(_BCT_BCTCTL2_TSTAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTCTL2_INVOUT:	
\*----------------------------------------------------------------*/

#define _BCT_BCTCTL2_INVOUT_SHIFT		(0x0001u)
#define _BCT_BCTCTL2_INVOUT_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTCTL2_INVOUT_SHIFT)
#define _BCT_BCTCTL2_INVOUT_MASK		(_BCT_BCTCTL2_INVOUT_MK(0x0001u))
#define _BCT_BCTCTL2_INVOUT_CLR		(~(_BCT_BCTCTL2_INVOUT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTCTL2_INVIN:	
\*----------------------------------------------------------------*/

#define _BCT_BCTCTL2_INVIN_SHIFT		(0x0002u)
#define _BCT_BCTCTL2_INVIN_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTCTL2_INVIN_SHIFT)
#define _BCT_BCTCTL2_INVIN_MASK		(_BCT_BCTCTL2_INVIN_MK(0x0001u))
#define _BCT_BCTCTL2_INVIN_CLR		(~(_BCT_BCTCTL2_INVIN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTCTL2_CP:	
\*----------------------------------------------------------------*/

#define _BCT_BCTCTL2_CP_SHIFT		(0x0003u)
#define _BCT_BCTCTL2_CP_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTCTL2_CP_SHIFT)
#define _BCT_BCTCTL2_CP_MASK		(_BCT_BCTCTL2_CP_MK(0x0001u))
#define _BCT_BCTCTL2_CP_CLR		(~(_BCT_BCTCTL2_CP_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTCTL2_PWID:	
\*----------------------------------------------------------------*/

#define _BCT_BCTCTL2_PWID_SHIFT		(0x0004u)
#define _BCT_BCTCTL2_PWID_MK(n)		(((Uint16)(n) & 0x0003u) << _BCT_BCTCTL2_PWID_SHIFT)
#define _BCT_BCTCTL2_PWID_MASK		(_BCT_BCTCTL2_PWID_MK(0x0003u))
#define _BCT_BCTCTL2_PWID_CLR		(~(_BCT_BCTCTL2_PWID_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTCTL2_ENAMODE:	
\*----------------------------------------------------------------*/

#define _BCT_BCTCTL2_ENAMODE_SHIFT		(0x0006u)
#define _BCT_BCTCTL2_ENAMODE_MK(n)		(((Uint16)(n) & 0x0003u) << _BCT_BCTCTL2_ENAMODE_SHIFT)
#define _BCT_BCTCTL2_ENAMODE_MASK		(_BCT_BCTCTL2_ENAMODE_MK(0x0003u))
#define _BCT_BCTCTL2_ENAMODE_CLR		(~(_BCT_BCTCTL2_ENAMODE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTCTL2_CLKSRC:	
\*----------------------------------------------------------------*/

#define _BCT_BCTCTL2_CLKSRC_SHIFT		(0x0008u)
#define _BCT_BCTCTL2_CLKSRC_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTCTL2_CLKSRC_SHIFT)
#define _BCT_BCTCTL2_CLKSRC_MASK		(_BCT_BCTCTL2_CLKSRC_MK(0x0001u))
#define _BCT_BCTCTL2_CLKSRC_CLR		(~(_BCT_BCTCTL2_CLKSRC_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTCTL2_TIEN:	
\*----------------------------------------------------------------*/

#define _BCT_BCTCTL2_TIEN_SHIFT		(0x0009u)
#define _BCT_BCTCTL2_TIEN_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTCTL2_TIEN_SHIFT)
#define _BCT_BCTCTL2_TIEN_MASK		(_BCT_BCTCTL2_TIEN_MK(0x0001u))
#define _BCT_BCTCTL2_TIEN_CLR		(~(_BCT_BCTCTL2_TIEN_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the BCTGPDAT register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _BCT_BCTGPDAT	 - Note: Add description here
*
* Fields:
*	(RW)   _BCT_BCTGPDAT_TIN1DAT	
*	(RW)   _BCT_BCTGPDAT_TOUT1DAT	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTGPDAT_TIN1DAT:	
\*----------------------------------------------------------------*/

#define _BCT_BCTGPDAT_TIN1DAT_SHIFT		(000000u)
#define _BCT_BCTGPDAT_TIN1DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTGPDAT_TIN1DAT_SHIFT)
#define _BCT_BCTGPDAT_TIN1DAT_MASK		(_BCT_BCTGPDAT_TIN1DAT_MK(0x0001u))
#define _BCT_BCTGPDAT_TIN1DAT_CLR		(~(_BCT_BCTGPDAT_TIN1DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTGPDAT_TOUT1DAT:	
\*----------------------------------------------------------------*/

#define _BCT_BCTGPDAT_TOUT1DAT_SHIFT		(000000u)
#define _BCT_BCTGPDAT_TOUT1DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTGPDAT_TOUT1DAT_SHIFT)
#define _BCT_BCTGPDAT_TOUT1DAT_MASK		(_BCT_BCTGPDAT_TOUT1DAT_MK(0x0001u))
#define _BCT_BCTGPDAT_TOUT1DAT_CLR		(~(_BCT_BCTGPDAT_TOUT1DAT_MASK))


/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the BCTGPEN register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _BCT_BCTGPEN	 - Note: Add description here
*
* Fields:
*	(RW)   _BCT_BCTGPEN_TIN1EN	
*	(RW)   _BCT_BCTGPEN_TOUT1EN	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTGPEN_TIN1EN:	
\*----------------------------------------------------------------*/

#define _BCT_BCTGPEN_TIN1EN_SHIFT		(000000u)
#define _BCT_BCTGPEN_TIN1EN_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTGPEN_TIN1EN_SHIFT)
#define _BCT_BCTGPEN_TIN1EN_MASK		(_BCT_BCTGPEN_TIN1EN_MK(0x0001u))
#define _BCT_BCTGPEN_TIN1EN_CLR		(~(_BCT_BCTGPEN_TIN1EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTGPEN_TOUT1EN:	
\*----------------------------------------------------------------*/

#define _BCT_BCTGPEN_TOUT1EN_SHIFT		(0x0001u)
#define _BCT_BCTGPEN_TOUT1EN_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTGPEN_TOUT1EN_SHIFT)
#define _BCT_BCTGPEN_TOUT1EN_MASK		(_BCT_BCTGPEN_TOUT1EN_MK(0x0001u))
#define _BCT_BCTGPEN_TOUT1EN_CLR		(~(_BCT_BCTGPEN_TOUT1EN_MASK))




/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the BCTEMU register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _BCT_BCTEMU	 - Note: Add description here
*
* Fields:
*	(R)   _BCT_BCTEMU_FREE	
*	(R)   _BCT_BCTEMU_SOFT
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _BCT_BCTEMU_FREE:	
\*----------------------------------------------------------------*/

#define _BCT_BCTEMU_FREE_SHIFT		(000000u)
#define _BCT_BCTEMU_FREE_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTEMU_FREE_SHIFT)
#define _BCT_BCTEMU_FREE_MASK		(_BCT_BCTEMU_FREE_MK(0x0001u))
#define _BCT_BCTEMU_FREE_CLR		(~(_BCT_BCTEMU_FREE_MASK))


/*----------------------------------------------------------------*\
*   (R)  _BCT_BCTEMU_SOFT:	
\*----------------------------------------------------------------*/

#define _BCT_BCTEMU_SOFT_SHIFT		(000001u)
#define _BCT_BCTEMU_SOFT_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTEMU_SOFT_SHIFT)
#define _BCT_BCTEMU_SOFT_MASK		(_BCT_BCTEMU_SOFT_MK(0x0001u))
#define _BCT_BCTEMU_SOFT_CLR		(~(_BCT_BCTEMU_SOFT_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the BCTGPINT register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _BCT_BCTGPINT	 - GPIO interrupt control register
*
* Fields:
*       (RW)   _BCT_BCTGPINT_TIN1INT	  
*       (RW)   _BCT_BCTGPINT_TIN1INV	  

\******************************************************************************/


/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTGPINT_TIN1INT:
\*----------------------------------------------------------------*/

#define _BCT_BCTGPINT_TIN1INT_SHIFT		(000000u)
#define _BCT_BCTGPINT_TIN1INT_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTGPINT_TIN1INT_SHIFT)
#define _BCT_BCTGPINT_TIN1INT_MASK		(_BCT_BCTGPINT_TIN1INT_MK(0x0001u))
#define _BCT_BCTGPINT_TIN1INT_CLR		(~(_BCT_BCTGPINT_TIN1INT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _BCT_BCTGPINT_TIN1INV:
\*----------------------------------------------------------------*/

#define _BCT_BCTGPINT_TIN1INV_SHIFT		(000004u)
#define _BCT_BCTGPINT_TIN1INV_MK(n)		(((Uint16)(n) & 0x0001u) << _BCT_BCTGPINT_TIN1INV_SHIFT)
#define _BCT_BCTGPINT_TIN1INV_MASK		(_BCT_BCTGPINT_TIN1INV_MK(0x0001u))
#define _BCT_BCTGPINT_TIN1INV_CLR		(~(_BCT_BCTGPINT_TIN1INV_MASK))






#elif (!(_BCT_MOD))
	#error BCT Hal Module Not Supported on Specified Target
#endif  /* _BCT_SUPPORT  */

#endif  /* _CSL_BCTHAL_H  */

/******************************************************************************\
*     
*      End of csl_bcthal.h 
*
\******************************************************************************/
