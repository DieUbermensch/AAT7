/****************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved 
*------------------------------------------------------------------------------
* MODULE NAME... WDTIM
* FILENAME...... csl_wdtimBhal.h
* DATE CREATED.. Wed Feb 13 11:06:40 2002
* PROJECT....... Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS.. 
*------------------------------------------------------------------------------
*
* HISTORY:
*	 Created:		Wed Feb 13 11:06:40 2002 (Automatic generation)
*	 Last Modified:	
*
*------------------------------------------------------------------------------
* DESCRIPTION: CSL HAL interface file for the WDTIM module 
*
* Registers covered:
*              WDTPID1		- 
*	           WDTPID2		- 
*	           WDTEMU		- Emulation management register
*	           WDTCLK		- Timer clock speed register
*	           WDTCNT1		- Timer count register 1
*	           WDTCNT2		- Timer count register 2
*	           WDTCNT3		- Timer count register 3
*	           WDTCNT4		- Timer count register 4
*	           WDTPRD1		- Timer period register 1
*	           WDTPRD2		- Timer period register 2
*	           WDTPRD3		- Timer period register 3
*	           WDTPRD4		- Timer period register 4
*	           WDTGPINT		- GPIO interrupt control register
*	           WDTGPEN		- GPIO enable register
*	           WDTGPDIR		- GPIO direction register
*	           WDTGPDAT		- GPIO data register
*	           WDTCTL1		- Timer control register 1
*	           WDTCTL2		- Timer control register 2
*	           WDTGCTL1		- Global timer control register
*              WDTWCTL1     - Watch dog timer control register 1    
*              WDTWCTL2     - Watch dog timer control register 2
*
\*************************************************************************/

#ifndef _CSL_WDTIMBHAL_H_
#define _CSL_WDTIMBHAL_H_

#include <csl_chiphal.h>

#if (_WDTIMB_SUPPORT) 

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

/*----------------------------------------------------------------*\
*		 Address Macros			
\*----------------------------------------------------------------*/

/*--------------------- Register: WDTPID1 -----------------------*/
#define _WDTIM_WDTPID1_ADDR		(0x4000u)
#define _WDTIM_WDTPID1			PREG16(_WDTIM_WDTPID1_ADDR)
#define WDTPID1			_WDTIM_WDTPID1


/*--------------------- Register: WDTPID2 -----------------------*/
#define _WDTIM_WDTPID2_ADDR		(0x4001u)
#define _WDTIM_WDTPID2			PREG16(_WDTIM_WDTPID2_ADDR)
#define WDTPID2			_WDTIM_WDTPID2


/*--------------------- Register: WDTEMU -----------------------*/
#define _WDTIM_WDTEMU_ADDR		(0x4002u)
#define _WDTIM_WDTEMU			PREG16(_WDTIM_WDTEMU_ADDR)
#define WDTEMU			_WDTIM_WDTEMU


/*--------------------- Register: WDTCLK -----------------------*/
#define _WDTIM_WDTCLK_ADDR		(0x4003u)
#define _WDTIM_WDTCLK			PREG16(_WDTIM_WDTCLK_ADDR)
#define WDTCLK			_WDTIM_WDTCLK


/*--------------------- Register: WDTCNT1  -----------------------*/
#define _WDTIM_WDTCNT1_ADDR		(0x4008u)
#define _WDTIM_WDTCNT1 			PREG16(_WDTIM_WDTCNT1_ADDR)
#define WDTCNT1 			_WDTIM_WDTCNT1 


/*--------------------- Register: WDTCNT2  -----------------------*/
#define _WDTIM_WDTCNT2_ADDR		(0x4009u)
#define _WDTIM_WDTCNT2 			PREG16(_WDTIM_WDTCNT2_ADDR)
#define WDTCNT2 			_WDTIM_WDTCNT2 


/*--------------------- Register: WDTCNT3 -----------------------*/
#define _WDTIM_WDTCNT3_ADDR		(0x400Au)
#define _WDTIM_WDTCNT3			PREG16(_WDTIM_WDTCNT3_ADDR)
#define WDTCNT3			_WDTIM_WDTCNT3


/*--------------------- Register: WDTCNT4 -----------------------*/
#define _WDTIM_WDTCNT4_ADDR		(0x400Bu)
#define _WDTIM_WDTCNT4			PREG16(_WDTIM_WDTCNT4_ADDR)
#define WDTCNT4			_WDTIM_WDTCNT4


/*--------------------- Register: WDTPRD1 -----------------------*/
#define _WDTIM_WDTPRD1_ADDR		(0x400Cu)
#define _WDTIM_WDTPRD1			PREG16(_WDTIM_WDTPRD1_ADDR)
#define WDTPRD1			_WDTIM_WDTPRD1


/*--------------------- Register: WDTPRD2 -----------------------*/
#define _WDTIM_WDTPRD2_ADDR		(0x400Du)
#define _WDTIM_WDTPRD2			PREG16(_WDTIM_WDTPRD2_ADDR)
#define WDTPRD2			_WDTIM_WDTPRD2


/*--------------------- Register: WDTPRD3 -----------------------*/
#define _WDTIM_WDTPRD3_ADDR		(0x400Eu)
#define _WDTIM_WDTPRD3			PREG16(_WDTIM_WDTPRD3_ADDR)
#define WDTPRD3			_WDTIM_WDTPRD3


/*--------------------- Register: WDTPRD4 -----------------------*/
#define _WDTIM_WDTPRD4_ADDR		(0x400Fu)
#define _WDTIM_WDTPRD4			PREG16(_WDTIM_WDTPRD4_ADDR)
#define WDTPRD4			_WDTIM_WDTPRD4


/*--------------------- Register: WDTGPINT -----------------------*/
#define _WDTIM_WDTGPINT_ADDR		(0x4004u)
#define _WDTIM_WDTGPINT			PREG16(_WDTIM_WDTGPINT_ADDR)
#define WDTGPINT			_WDTIM_WDTGPINT


/*--------------------- Register: WDTGPEN -----------------------*/
#define _WDTIM_WDTGPEN_ADDR		(0x4005u)
#define _WDTIM_WDTGPEN			PREG16(_WDTIM_WDTGPEN_ADDR)
#define WDTGPEN			_WDTIM_WDTGPEN


/*--------------------- Register: WDTGPDIR -----------------------*/
#define _WDTIM_WDTGPDIR_ADDR		(0x4007u)
#define _WDTIM_WDTGPDIR			PREG16(_WDTIM_WDTGPDIR_ADDR)
#define WDTGPDIR			_WDTIM_WDTGPDIR


/*--------------------- Register: WDTGPDAT -----------------------*/
#define _WDTIM_WDTGPDAT_ADDR		(0x4006u)
#define _WDTIM_WDTGPDAT			PREG16(_WDTIM_WDTGPDAT_ADDR)
#define WDTGPDAT			_WDTIM_WDTGPDAT


/*--------------------- Register: WDTCTL1  -----------------------*/
#define _WDTIM_WDTCTL1_ADDR		(0x4010u)
#define _WDTIM_WDTCTL1			PREG16(_WDTIM_WDTCTL1_ADDR)
#define WDTCTL1			        _WDTIM_WDTCTL1


/*--------------------- Register: WDTCTL2 -----------------------*/
#define _WDTIM_WDTCTL2_ADDR		(0x4011u)
#define _WDTIM_WDTCTL2			PREG16(_WDTIM_WDTCTL2_ADDR)
#define WDTCTL2			        _WDTIM_WDTCTL2


/*--------------------- Register: WDTGCTL1 -----------------------*/
#define _WDTIM_WDTGCTL1_ADDR		(0x4012u)
#define _WDTIM_WDTGCTL1			PREG16(_WDTIM_WDTGCTL1_ADDR)
#define WDTGCTL1			_WDTIM_WDTGCTL1


/*--------------------- Register: WDTWCTL1 -----------------------*/
#define _WDTIM_WDTWCTL1_ADDR		(0x4014u)
#define _WDTIM_WDTWCTL1			PREG16(_WDTIM_WDTWCTL1_ADDR)
#define WDTWCTL1			_WDTIM_WDTWCTL1


/*--------------------- Register: WDTWCTL2 -----------------------*/
#define _WDTIM_WDTWCTL2_ADDR		(0x4015u)
#define _WDTIM_WDTWCTL2			PREG16(_WDTIM_WDTWCTL2_ADDR)
#define WDTWCTL2			_WDTIM_WDTWCTL2



/*----------------------------------------------------------------*\
*		 Register Macros		
\*----------------------------------------------------------------*/

#define WDTIM_ADDR(Reg)		  _WDTIM_##Reg##_ADDR
#define WDTIM_RGET(Reg)		  _WDTIM_##Reg##_GET
#define WDTIM_RSET(Reg,Val)		  _WDTIM_##Reg##_SET(Val)
#define WDTIM_FGET(Reg,Field)		  _WDTIM_##Reg##_FGET(Field)
#define WDTIM_FSET(Reg,Field,Val)		  _WDTIM_##Reg##_FSET(Field, Val)
#define WDTIM_FMK(Reg,Field,Val)		  _WDTIM_##Reg##_##Field##_MK(Val)
#define WDTIM_RAOI(Reg,AND,OR,INV)		  _WDTIM_##Reg##_AOI(AND,OR,INV)
#define WDTIM_FAOI(Reg,Field,AND,OR,INV)	  _WDTIM_##Reg##_FAOI(Field,AND,OR,INV)
#define WDTIM_FMKS(Reg,Field,Sym)\
	  _WDTIM_##Reg##_##Field##_MK(WDTIM_##Reg##_##Field##_##Sym)
#define WDTIM_FSETS(Reg,Field,Sym)\
        _WDTIM_##Reg##_FSET(Field,WDTIM_##Reg##_##Field##_##Sym)

#define WDTIM_ADDRH(h,Reg)		  _WDTIM_##Reg##_ADDR
#define WDTIM_RGETH(h,Reg)		  _WDTIM_##Reg##_GET
#define WDTIM_RSETH(h,Reg,Val)		  _WDTIM_##Reg##_SET(Val)
#define WDTIM_FGETH(h,Reg,Field)		  _WDTIM_##Reg##_FGET(Field)
#define WDTIM_FSETH(h,Reg,Field,Val)		  _WDTIM_##Reg##_FSET(Field, Val)
#define WDTIM_FMKH(h,Reg,Field,Val)		  _WDTIM_##Reg##_##Field##_MK(Val)
#define WDTIM_RAOIH(h,Reg,AND,OR,INV)		  _WDTIM_##Reg##_AOI(AND,OR,INV)
#define WDTIM_FAOIH(h,Reg,Field,AND,OR,INV)	  _WDTIM_##Reg##_FAOI(Field,AND,OR,INV)
#define WDTIM_FMKSH(h,Reg,Field,Sym)\
	  _WDTIM_##Reg##_##Field##_MK(WDTIM_##Reg##_##Field##_##Sym)
#define WDTIM_FSETSH(h,Reg,Field,Sym)\
        _WDTIM_##Reg##_FSET(Field,WDTIM_##Reg##_##Field##_##Sym)

/*----------------------------------------------------------------*\
*		 Non-handle Registers Macros		
\*----------------------------------------------------------------*/


/*--------------------- Register: WDTPID1 -----------------------*/
#define _WDTIM_WDTPID1_GET		  _PREG_GET(_WDTIM_WDTPID1_ADDR) 
#define _WDTIM_WDTPID1_SET(Val)		  _PREG_SET(_WDTIM_WDTPID1_ADDR,Val)
#define _WDTIM_WDTPID1_FGET(Field)	  _PFIELD_GET(_WDTIM_WDTPID1_ADDR, _WDTIM_WDTPID1_##Field)
#define _WDTIM_WDTPID1_FSET(Field,Val)	  _PFIELD_SET(_WDTIM_WDTPID1_ADDR, _WDTIM_WDTPID1_##Field, Val)
#define _WDTIM_WDTPID1_AOI(AND,OR,INV)	  _PREG_AOI(_WDTIM_WDTPID1_ADDR,AND,OR,INV)
#define _WDTIM_WDTPID1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_WDTIM_WDTPID1_ADDR, _WDTIM_WDTPID1_##Field,AND,OR,INV)


/*--------------------- Register: WDTPID2 -----------------------*/
#define _WDTIM_WDTPID2_GET		  _PREG_GET(_WDTIM_WDTPID2_ADDR) 
#define _WDTIM_WDTPID2_SET(Val)		  _PREG_SET(_WDTIM_WDTPID2_ADDR,Val)
#define _WDTIM_WDTPID2_FGET(Field)	  _PFIELD_GET(_WDTIM_WDTPID2_ADDR, _WDTIM_WDTPID2_##Field)
#define _WDTIM_WDTPID2_FSET(Field,Val)	  _PFIELD_SET(_WDTIM_WDTPID2_ADDR, _WDTIM_WDTPID2_##Field, Val)
#define _WDTIM_WDTPID2_AOI(AND,OR,INV)	  _PREG_AOI(_WDTIM_WDTPID2_ADDR,AND,OR,INV)
#define _WDTIM_WDTPID2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_WDTIM_WDTPID2_ADDR, _WDTIM_WDTPID2_##Field,AND,OR,INV)


/*--------------------- Register: WDTEMU -----------------------*/
#define _WDTIM_WDTEMU_GET		  _PREG_GET(_WDTIM_WDTEMU_ADDR) 
#define _WDTIM_WDTEMU_SET(Val)		  _PREG_SET(_WDTIM_WDTEMU_ADDR,Val)
#define _WDTIM_WDTEMU_FGET(Field)	  _PFIELD_GET(_WDTIM_WDTEMU_ADDR, _WDTIM_WDTEMU_##Field)
#define _WDTIM_WDTEMU_FSET(Field,Val)	  _PFIELD_SET(_WDTIM_WDTEMU_ADDR, _WDTIM_WDTEMU_##Field, Val)
#define _WDTIM_WDTEMU_AOI(AND,OR,INV)	  _PREG_AOI(_WDTIM_WDTEMU_ADDR,AND,OR,INV)
#define _WDTIM_WDTEMU_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_WDTIM_WDTEMU_ADDR, _WDTIM_WDTEMU_##Field,AND,OR,INV)


/*--------------------- Register: WDTCLK -----------------------*/
#define _WDTIM_WDTCLK_GET		  _PREG_GET(_WDTIM_WDTCLK_ADDR) 
#define _WDTIM_WDTCLK_SET(Val)		  _PREG_SET(_WDTIM_WDTCLK_ADDR,Val)
#define _WDTIM_WDTCLK_FGET(Field)	  _PFIELD_GET(_WDTIM_WDTCLK_ADDR, _WDTIM_WDTCLK_##Field)
#define _WDTIM_WDTCLK_FSET(Field,Val)	  _PFIELD_SET(_WDTIM_WDTCLK_ADDR, _WDTIM_WDTCLK_##Field, Val)
#define _WDTIM_WDTCLK_AOI(AND,OR,INV)	  _PREG_AOI(_WDTIM_WDTCLK_ADDR,AND,OR,INV)
#define _WDTIM_WDTCLK_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_WDTIM_WDTCLK_ADDR, _WDTIM_WDTCLK_##Field,AND,OR,INV)


/*--------------------- Register: WDTCNT1  -----------------------*/
#define _WDTIM_WDTCNT1_GET		  _PREG_GET(_WDTIM_WDTCNT1_ADDR) 
#define _WDTIM_WDTCNT1_SET(Val)		  _PREG_SET(_WDTIM_WDTCNT1_ADDR,Val)
#define _WDTIM_WDTCNT1_FGET(Field)	  _PFIELD_GET(_WDTIM_WDTCNT1_ADDR, _WDTIM_WDTCNT1_##Field)
#define _WDTIM_WDTCNT1_FSET(Field,Val)	  _PFIELD_SET(_WDTIM_WDTCNT1_ADDR, _WDTIM_WDTCNT1_##Field, Val)
#define _WDTIM_WDTCNT1_AOI(AND,OR,INV)	  _PREG_AOI(_WDTIM_WDTCNT1_ADDR,AND,OR,INV)
#define _WDTIM_WDTCNT1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_WDTIM_WDTCNT1_ADDR, _WDTIM_WDTCNT1_##Field,AND,OR,INV)


/*--------------------- Register: WDTCNT2  -----------------------*/
#define _WDTIM_WDTCNT2_GET		  _PREG_GET(_WDTIM_WDTCNT2_ADDR) 
#define _WDTIM_WDTCNT2_SET(Val)		  _PREG_SET(_WDTIM_WDTCNT2_ADDR,Val)
#define _WDTIM_WDTCNT2_FGET(Field)	  _PFIELD_GET(_WDTIM_WDTCNT2_ADDR, _WDTIM_WDTCNT2_##Field)
#define _WDTIM_WDTCNT2_FSET(Field,Val)	  _PFIELD_SET(_WDTIM_WDTCNT2_ADDR, _WDTIM_WDTCNT2_##Field, Val)
#define _WDTIM_WDTCNT2_AOI(AND,OR,INV)	  _PREG_AOI(_WDTIM_WDTCNT2_ADDR,AND,OR,INV)
#define _WDTIM_WDTCNT2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_WDTIM_WDTCNT2_ADDR, _WDTIM_WDTCNT2_##Field,AND,OR,INV)


/*--------------------- Register: WDTCNT3 -----------------------*/
#define _WDTIM_WDTCNT3_GET		  _PREG_GET(_WDTIM_WDTCNT3_ADDR) 
#define _WDTIM_WDTCNT3_SET(Val)		  _PREG_SET(_WDTIM_WDTCNT3_ADDR,Val)
#define _WDTIM_WDTCNT3_FGET(Field)	  _PFIELD_GET(_WDTIM_WDTCNT3_ADDR, _WDTIM_WDTCNT3_##Field)
#define _WDTIM_WDTCNT3_FSET(Field,Val)	  _PFIELD_SET(_WDTIM_WDTCNT3_ADDR, _WDTIM_WDTCNT3_##Field, Val)
#define _WDTIM_WDTCNT3_AOI(AND,OR,INV)	  _PREG_AOI(_WDTIM_WDTCNT3_ADDR,AND,OR,INV)
#define _WDTIM_WDTCNT3_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_WDTIM_WDTCNT3_ADDR, _WDTIM_WDTCNT3_##Field,AND,OR,INV)


/*--------------------- Register: WDTCNT4 -----------------------*/
#define _WDTIM_WDTCNT4_GET		  _PREG_GET(_WDTIM_WDTCNT4_ADDR) 
#define _WDTIM_WDTCNT4_SET(Val)		  _PREG_SET(_WDTIM_WDTCNT4_ADDR,Val)
#define _WDTIM_WDTCNT4_FGET(Field)	  _PFIELD_GET(_WDTIM_WDTCNT4_ADDR, _WDTIM_WDTCNT4_##Field)
#define _WDTIM_WDTCNT4_FSET(Field,Val)	  _PFIELD_SET(_WDTIM_WDTCNT4_ADDR, _WDTIM_WDTCNT4_##Field, Val)
#define _WDTIM_WDTCNT4_AOI(AND,OR,INV)	  _PREG_AOI(_WDTIM_WDTCNT4_ADDR,AND,OR,INV)
#define _WDTIM_WDTCNT4_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_WDTIM_WDTCNT4_ADDR, _WDTIM_WDTCNT4_##Field,AND,OR,INV)


/*--------------------- Register: WDTPRD1 -----------------------*/
#define _WDTIM_WDTPRD1_GET		  _PREG_GET(_WDTIM_WDTPRD1_ADDR) 
#define _WDTIM_WDTPRD1_SET(Val)		  _PREG_SET(_WDTIM_WDTPRD1_ADDR,Val)
#define _WDTIM_WDTPRD1_FGET(Field)	  _PFIELD_GET(_WDTIM_WDTPRD1_ADDR, _WDTIM_WDTPRD1_##Field)
#define _WDTIM_WDTPRD1_FSET(Field,Val)	  _PFIELD_SET(_WDTIM_WDTPRD1_ADDR, _WDTIM_WDTPRD1_##Field, Val)
#define _WDTIM_WDTPRD1_AOI(AND,OR,INV)	  _PREG_AOI(_WDTIM_WDTPRD1_ADDR,AND,OR,INV)
#define _WDTIM_WDTPRD1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_WDTIM_WDTPRD1_ADDR, _WDTIM_WDTPRD1_##Field,AND,OR,INV)


/*--------------------- Register: WDTPRD2 -----------------------*/
#define _WDTIM_WDTPRD2_GET		  _PREG_GET(_WDTIM_WDTPRD2_ADDR) 
#define _WDTIM_WDTPRD2_SET(Val)		  _PREG_SET(_WDTIM_WDTPRD2_ADDR,Val)
#define _WDTIM_WDTPRD2_FGET(Field)	  _PFIELD_GET(_WDTIM_WDTPRD2_ADDR, _WDTIM_WDTPRD2_##Field)
#define _WDTIM_WDTPRD2_FSET(Field,Val)	  _PFIELD_SET(_WDTIM_WDTPRD2_ADDR, _WDTIM_WDTPRD2_##Field, Val)
#define _WDTIM_WDTPRD2_AOI(AND,OR,INV)	  _PREG_AOI(_WDTIM_WDTPRD2_ADDR,AND,OR,INV)
#define _WDTIM_WDTPRD2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_WDTIM_WDTPRD2_ADDR, _WDTIM_WDTPRD2_##Field,AND,OR,INV)


/*--------------------- Register: WDTPRD3 -----------------------*/
#define _WDTIM_WDTPRD3_GET		  _PREG_GET(_WDTIM_WDTPRD3_ADDR) 
#define _WDTIM_WDTPRD3_SET(Val)		  _PREG_SET(_WDTIM_WDTPRD3_ADDR,Val)
#define _WDTIM_WDTPRD3_FGET(Field)	  _PFIELD_GET(_WDTIM_WDTPRD3_ADDR, _WDTIM_WDTPRD3_##Field)
#define _WDTIM_WDTPRD3_FSET(Field,Val)	  _PFIELD_SET(_WDTIM_WDTPRD3_ADDR, _WDTIM_WDTPRD3_##Field, Val)
#define _WDTIM_WDTPRD3_AOI(AND,OR,INV)	  _PREG_AOI(_WDTIM_WDTPRD3_ADDR,AND,OR,INV)
#define _WDTIM_WDTPRD3_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_WDTIM_WDTPRD3_ADDR, _WDTIM_WDTPRD3_##Field,AND,OR,INV)


/*--------------------- Register: WDTPRD4 -----------------------*/
#define _WDTIM_WDTPRD4_GET		  _PREG_GET(_WDTIM_WDTPRD4_ADDR) 
#define _WDTIM_WDTPRD4_SET(Val)		  _PREG_SET(_WDTIM_WDTPRD4_ADDR,Val)
#define _WDTIM_WDTPRD4_FGET(Field)	  _PFIELD_GET(_WDTIM_WDTPRD4_ADDR, _WDTIM_WDTPRD4_##Field)
#define _WDTIM_WDTPRD4_FSET(Field,Val)	  _PFIELD_SET(_WDTIM_WDTPRD4_ADDR, _WDTIM_WDTPRD4_##Field, Val)
#define _WDTIM_WDTPRD4_AOI(AND,OR,INV)	  _PREG_AOI(_WDTIM_WDTPRD4_ADDR,AND,OR,INV)
#define _WDTIM_WDTPRD4_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_WDTIM_WDTPRD4_ADDR, _WDTIM_WDTPRD4_##Field,AND,OR,INV)


/*--------------------- Register: WDTGPINT -----------------------*/
#define _WDTIM_WDTGPINT_GET		  _PREG_GET(_WDTIM_WDTGPINT_ADDR) 
#define _WDTIM_WDTGPINT_SET(Val)		  _PREG_SET(_WDTIM_WDTGPINT_ADDR,Val)
#define _WDTIM_WDTGPINT_FGET(Field)	  _PFIELD_GET(_WDTIM_WDTGPINT_ADDR, _WDTIM_WDTGPINT_##Field)
#define _WDTIM_WDTGPINT_FSET(Field,Val)	  _PFIELD_SET(_WDTIM_WDTGPINT_ADDR, _WDTIM_WDTGPINT_##Field, Val)
#define _WDTIM_WDTGPINT_AOI(AND,OR,INV)	  _PREG_AOI(_WDTIM_WDTGPINT_ADDR,AND,OR,INV)
#define _WDTIM_WDTGPINT_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_WDTIM_WDTGPINT_ADDR, _WDTIM_WDTGPINT_##Field,AND,OR,INV)


/*--------------------- Register: WDTGPEN -----------------------*/
#define _WDTIM_WDTGPEN_GET		  _PREG_GET(_WDTIM_WDTGPEN_ADDR) 
#define _WDTIM_WDTGPEN_SET(Val)		  _PREG_SET(_WDTIM_WDTGPEN_ADDR,Val)
#define _WDTIM_WDTGPEN_FGET(Field)	  _PFIELD_GET(_WDTIM_WDTGPEN_ADDR, _WDTIM_WDTGPEN_##Field)
#define _WDTIM_WDTGPEN_FSET(Field,Val)	  _PFIELD_SET(_WDTIM_WDTGPEN_ADDR, _WDTIM_WDTGPEN_##Field, Val)
#define _WDTIM_WDTGPEN_AOI(AND,OR,INV)	  _PREG_AOI(_WDTIM_WDTGPEN_ADDR,AND,OR,INV)
#define _WDTIM_WDTGPEN_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_WDTIM_WDTGPEN_ADDR, _WDTIM_WDTGPEN_##Field,AND,OR,INV)


/*--------------------- Register: WDTGPDIR -----------------------*/
#define _WDTIM_WDTGPDIR_GET		  _PREG_GET(_WDTIM_WDTGPDIR_ADDR) 
#define _WDTIM_WDTGPDIR_SET(Val)		  _PREG_SET(_WDTIM_WDTGPDIR_ADDR,Val)
#define _WDTIM_WDTGPDIR_FGET(Field)	  _PFIELD_GET(_WDTIM_WDTGPDIR_ADDR, _WDTIM_WDTGPDIR_##Field)
#define _WDTIM_WDTGPDIR_FSET(Field,Val)	  _PFIELD_SET(_WDTIM_WDTGPDIR_ADDR, _WDTIM_WDTGPDIR_##Field, Val)
#define _WDTIM_WDTGPDIR_AOI(AND,OR,INV)	  _PREG_AOI(_WDTIM_WDTGPDIR_ADDR,AND,OR,INV)
#define _WDTIM_WDTGPDIR_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_WDTIM_WDTGPDIR_ADDR, _WDTIM_WDTGPDIR_##Field,AND,OR,INV)


/*--------------------- Register: WDTGPDAT -----------------------*/
#define _WDTIM_WDTGPDAT_GET		  _PREG_GET(_WDTIM_WDTGPDAT_ADDR) 
#define _WDTIM_WDTGPDAT_SET(Val)		  _PREG_SET(_WDTIM_WDTGPDAT_ADDR,Val)
#define _WDTIM_WDTGPDAT_FGET(Field)	  _PFIELD_GET(_WDTIM_WDTGPDAT_ADDR, _WDTIM_WDTGPDAT_##Field)
#define _WDTIM_WDTGPDAT_FSET(Field,Val)	  _PFIELD_SET(_WDTIM_WDTGPDAT_ADDR, _WDTIM_WDTGPDAT_##Field, Val)
#define _WDTIM_WDTGPDAT_AOI(AND,OR,INV)	  _PREG_AOI(_WDTIM_WDTGPDAT_ADDR,AND,OR,INV)
#define _WDTIM_WDTGPDAT_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_WDTIM_WDTGPDAT_ADDR, _WDTIM_WDTGPDAT_##Field,AND,OR,INV)


/*--------------------- Register: WDTCTL1 -----------------------*/
#define _WDTIM_WDTCTL1_GET		  _PREG_GET(_WDTIM_WDTCTL1_ADDR) 
#define _WDTIM_WDTCTL1_SET(Val)		  _PREG_SET(_WDTIM_WDTCTL1_ADDR,Val)
#define _WDTIM_WDTCTL1_FGET(Field)	  _PFIELD_GET(_WDTIM_WDTCTL1_ADDR, _WDTIM_WDTCTL1_##Field)
#define _WDTIM_WDTCTL1_FSET(Field,Val)	  _PFIELD_SET(_WDTIM_WDTCTL1_ADDR, _WDTIM_WDTCTL1_##Field, Val)
#define _WDTIM_WDTCTL1_AOI(AND,OR,INV)	  _PREG_AOI(_WDTIM_WDTCTL1_ADDR,AND,OR,INV)
#define _WDTIM_WDTCTL1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_WDTIM_WDTCTL1_ADDR, _WDTIM_WDTCTL1_##Field,AND,OR,INV)


/*--------------------- Register: WDTCTL2 -----------------------*/
#define _WDTIM_WDTCTL2_GET		  _PREG_GET(_WDTIM_WDTCTL2_ADDR) 
#define _WDTIM_WDTCTL2_SET(Val)		  _PREG_SET(_WDTIM_WDTCTL2_ADDR,Val)
#define _WDTIM_WDTCTL2_FGET(Field)	  _PFIELD_GET(_WDTIM_WDTCTL2_ADDR, _WDTIM_WDTCTL2_##Field)
#define _WDTIM_WDTCTL2_FSET(Field,Val)	  _PFIELD_SET(_WDTIM_WDTCTL2_ADDR, _WDTIM_WDTCTL2_##Field, Val)
#define _WDTIM_WDTCTL2_AOI(AND,OR,INV)	  _PREG_AOI(_WDTIM_WDTCTL2_ADDR,AND,OR,INV)
#define _WDTIM_WDTCTL2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_WDTIM_WDTCTL2_ADDR, _WDTIM_WDTCTL2_##Field,AND,OR,INV)


/*--------------------- Register: WDTGCTL1 -----------------------*/
#define _WDTIM_WDTGCTL1_GET		  _PREG_GET(_WDTIM_WDTGCTL1_ADDR) 
#define _WDTIM_WDTGCTL1_SET(Val)		  _PREG_SET(_WDTIM_WDTGCTL1_ADDR,Val)
#define _WDTIM_WDTGCTL1_FGET(Field)	  _PFIELD_GET(_WDTIM_WDTGCTL1_ADDR, _WDTIM_WDTGCTL1_##Field)
#define _WDTIM_WDTGCTL1_FSET(Field,Val)	  _PFIELD_SET(_WDTIM_WDTGCTL1_ADDR, _WDTIM_WDTGCTL1_##Field, Val)
#define _WDTIM_WDTGCTL1_AOI(AND,OR,INV)	  _PREG_AOI(_WDTIM_WDTGCTL1_ADDR,AND,OR,INV)
#define _WDTIM_WDTGCTL1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_WDTIM_WDTGCTL1_ADDR, _WDTIM_WDTGCTL1_##Field,AND,OR,INV)


/*--------------------- Register: WDTWCTL1 -----------------------*/
#define _WDTIM_WDTWCTL1_GET		  _PREG_GET(_WDTIM_WDTWCTL1_ADDR) 
#define _WDTIM_WDTWCTL1_SET(Val)		  _PREG_SET(_WDTIM_WDTWCTL1_ADDR,Val)
#define _WDTIM_WDTWCTL1_FGET(Field)	  _PFIELD_GET(_WDTIM_WDTWCTL1_ADDR, _WDTIM_WDTWCTL1_##Field)
#define _WDTIM_WDTWCTL1_FSET(Field,Val)	  _PFIELD_SET(_WDTIM_WDTWCTL1_ADDR, _WDTIM_WDTWCTL1_##Field, Val)
#define _WDTIM_WDTWCTL1_AOI(AND,OR,INV)	  _PREG_AOI(_WDTIM_WDTWCTL1_ADDR,AND,OR,INV)
#define _WDTIM_WDTWCTL1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_WDTIM_WDTWCTL1_ADDR, _WDTIM_WDTWCTL1_##Field,AND,OR,INV)


/*--------------------- Register: WDTWCTL2 -----------------------*/
#define _WDTIM_WDTWCTL2_GET		  _PREG_GET(_WDTIM_WDTWCTL2_ADDR) 
#define _WDTIM_WDTWCTL2_SET(Val)		  _PREG_SET(_WDTIM_WDTWCTL2_ADDR,Val)
#define _WDTIM_WDTWCTL2_FGET(Field)	  _PFIELD_GET(_WDTIM_WDTWCTL2_ADDR, _WDTIM_WDTWCTL2_##Field)
#define _WDTIM_WDTWCTL2_FSET(Field,Val)	  _PFIELD_SET(_WDTIM_WDTWCTL2_ADDR, _WDTIM_WDTWCTL2_##Field, Val)
#define _WDTIM_WDTWCTL2_AOI(AND,OR,INV)	  _PREG_AOI(_WDTIM_WDTWCTL2_ADDR,AND,OR,INV)
#define _WDTIM_WDTWCTL2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_WDTIM_WDTWCTL2_ADDR, _WDTIM_WDTWCTL2_##Field,AND,OR,INV)



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the WDTPID1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _WDTIM_WDTPID1	 - Note: Add description here
*
* Fields:
*	(R)   _WDTIM_WDTPID1_REVISION	
*	(R)   _WDTIM_WDTPID1_CLASS	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _WDTIM_WDTPID1_REVISION:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTPID1_REVISION_SHIFT		(000000u)
#define _WDTIM_WDTPID1_REVISION_MK(n)		(((Uint16)(n) & 0x00ffu) << _WDTIM_WDTPID1_REVISION_SHIFT)
#define _WDTIM_WDTPID1_REVISION_MASK		(_WDTIM_WDTPID1_REVISION_MK(0x00ffu))
#define _WDTIM_WDTPID1_REVISION_CLR		(~(_WDTIM_WDTPID1_REVISION_MASK))



/*----------------------------------------------------------------*\
*   (R)  _WDTIM_WDTPID1_CLASS:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTPID1_CLASS_SHIFT		(0x0008u)
#define _WDTIM_WDTPID1_CLASS_MK(n)		(((Uint16)(n) & 0x00ffu) << _WDTIM_WDTPID1_CLASS_SHIFT)
#define _WDTIM_WDTPID1_CLASS_MASK		(_WDTIM_WDTPID1_CLASS_MK(0x00ffu))
#define _WDTIM_WDTPID1_CLASS_CLR		(~(_WDTIM_WDTPID1_CLASS_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the WDTPID2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _WDTIM_WDTPID2	 - Note: Add description here
*
* Fields:
*	(R)   _WDTIM_WDTPID2_TYPE	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _WDTIM_WDTPID2_TYPE:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTPID2_TYPE_SHIFT		(000000u)
#define _WDTIM_WDTPID2_TYPE_MK(n)		(((Uint16)(n) & 0x007fu) << _WDTIM_WDTPID2_TYPE_SHIFT)
#define _WDTIM_WDTPID2_TYPE_MASK		(_WDTIM_WDTPID2_TYPE_MK(0x007fu))
#define _WDTIM_WDTPID2_TYPE_CLR		(~(_WDTIM_WDTPID2_TYPE_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the WDTWCTL1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _WDTIM_WDTWCTL1	 - Note: Add description here
*
* Fields:
*	(RW)   _WDTIM_WDTWCTL1_WDIKEY	
*	(RW)   _WDTIM_WDTWCTL1_WDEN	
*	(RW)   _WDTIM_WDTWCTL1_WDFLAG	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTWCTL1_WDIKEY:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTWCTL1_WDIKEY_SHIFT		(0x000cu)
#define _WDTIM_WDTWCTL1_WDIKEY_MK(n)		(((Uint16)(n) & 0x0003u) << _WDTIM_WDTWCTL1_WDIKEY_SHIFT)
#define _WDTIM_WDTWCTL1_WDIKEY_MASK		(_WDTIM_WDTWCTL1_WDIKEY_MK(0x0003u))
#define _WDTIM_WDTWCTL1_WDIKEY_CLR		(~(_WDTIM_WDTWCTL1_WDIKEY_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTWCTL1_WDEN:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTWCTL1_WDEN_SHIFT		(0x000eu)
#define _WDTIM_WDTWCTL1_WDEN_MK(n)		(((Uint16)(n) & 0x0001u) << _WDTIM_WDTWCTL1_WDEN_SHIFT)
#define _WDTIM_WDTWCTL1_WDEN_MASK		(_WDTIM_WDTWCTL1_WDEN_MK(0x0001u))
#define _WDTIM_WDTWCTL1_WDEN_CLR		(~(_WDTIM_WDTWCTL1_WDEN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTWCTL1_WDFLAG:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTWCTL1_WDFLAG_SHIFT		(0x000fu)
#define _WDTIM_WDTWCTL1_WDFLAG_MK(n)		(((Uint16)(n) & 0x0001u) << _WDTIM_WDTWCTL1_WDFLAG_SHIFT)
#define _WDTIM_WDTWCTL1_WDFLAG_MASK		(_WDTIM_WDTWCTL1_WDFLAG_MK(0x0001u))
#define _WDTIM_WDTWCTL1_WDFLAG_CLR		(~(_WDTIM_WDTWCTL1_WDFLAG_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the WDTGCTL1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _WDTIM_WDTGCTL1	 - Note: Add description here
*
* Fields:
*	(RW)   _WDTIM_WDTGCTL1_TIM12RS	
*	(RW)   _WDTIM_WDTGCTL1_TIM34RS	
*	(RW)   _WDTIM_WDTGCTL1_TIMMODE	
*	(RW)   _WDTIM_WDTGCTL1_PSC34	
*	(R)   _WDTIM_WDTGCTL1_TDDR34	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTGCTL1_TIM12RS:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTGCTL1_TIM12RS_SHIFT		(000000u)
#define _WDTIM_WDTGCTL1_TIM12RS_MK(n)		(((Uint16)(n) & 0x0001u) << _WDTIM_WDTGCTL1_TIM12RS_SHIFT)
#define _WDTIM_WDTGCTL1_TIM12RS_MASK		(_WDTIM_WDTGCTL1_TIM12RS_MK(0x0001u))
#define _WDTIM_WDTGCTL1_TIM12RS_CLR		(~(_WDTIM_WDTGCTL1_TIM12RS_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTGCTL1_TIM34RS:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTGCTL1_TIM34RS_SHIFT		(0x0001u)
#define _WDTIM_WDTGCTL1_TIM34RS_MK(n)		(((Uint16)(n) & 0x0001u) << _WDTIM_WDTGCTL1_TIM34RS_SHIFT)
#define _WDTIM_WDTGCTL1_TIM34RS_MASK		(_WDTIM_WDTGCTL1_TIM34RS_MK(0x0001u))
#define _WDTIM_WDTGCTL1_TIM34RS_CLR		(~(_WDTIM_WDTGCTL1_TIM34RS_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTGCTL1_TIMMODE:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTGCTL1_TIMMODE_SHIFT		(0x0002u)
#define _WDTIM_WDTGCTL1_TIMMODE_MK(n)		(((Uint16)(n) & 0x0003u) << _WDTIM_WDTGCTL1_TIMMODE_SHIFT)
#define _WDTIM_WDTGCTL1_TIMMODE_MASK		(_WDTIM_WDTGCTL1_TIMMODE_MK(0x0003u))
#define _WDTIM_WDTGCTL1_TIMMODE_CLR		(~(_WDTIM_WDTGCTL1_TIMMODE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTGCTL1_PSC34:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTGCTL1_PSC34_SHIFT		(0x0008u)
#define _WDTIM_WDTGCTL1_PSC34_MK(n)		(((Uint16)(n) & 0x000fu) << _WDTIM_WDTGCTL1_PSC34_SHIFT)
#define _WDTIM_WDTGCTL1_PSC34_MASK		(_WDTIM_WDTGCTL1_PSC34_MK(0x000fu))
#define _WDTIM_WDTGCTL1_PSC34_CLR		(~(_WDTIM_WDTGCTL1_PSC34_MASK))



/*----------------------------------------------------------------*\
*   (R)  _WDTIM_WDTGCTL1_TDDR34:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTGCTL1_TDDR34_SHIFT		(0x000cu)
#define _WDTIM_WDTGCTL1_TDDR34_MK(n)		(((Uint16)(n) & 0x000fu) << _WDTIM_WDTGCTL1_TDDR34_SHIFT)
#define _WDTIM_WDTGCTL1_TDDR34_MASK		(_WDTIM_WDTGCTL1_TDDR34_MK(0x000fu))
#define _WDTIM_WDTGCTL1_TDDR34_CLR		(~(_WDTIM_WDTGCTL1_TDDR34_MASK))





/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the WDTGPDIR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _WDTIM_WDTGPDIR	 - GPIO direction register
*
* Fields:
*	(RW)   _WDTIM_WDTGPDIR_TIN1DIR
*	(RW)   _WDTIM_WDTGPDIR_TOUT1DIR	

\******************************************************************************/


/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTGPDIR_TIN1DIR:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTGPDIR_TIN1DIR_SHIFT		(000000u)
#define _WDTIM_WDTGPDIR_TIN1DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _WDTIM_WDTGPDIR_TIN1DIR_SHIFT)
#define _WDTIM_WDTGPDIR_TIN1DIR_MASK		(_WDTIM_WDTGPDIR_TIN1DIR_MK(0x0001u))
#define _WDTIM_WDTGPDIR_TIN1DIR_CLR		(~(_WDTIM_WDTGPDIR_TIN1DIR_MASK))


/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTGPDIR_TOUT1DIR:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTGPDIR_TOUT1DIR_SHIFT		(000001u)
#define _WDTIM_WDTGPDIR_TOUT1DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _WDTIM_WDTGPDIR_TOUT1DIR_SHIFT)
#define _WDTIM_WDTGPDIR_TOUT1DIR_MASK		(_WDTIM_WDTGPDIR_TOUT1DIR_MK(0x0001u))
#define _WDTIM_WDTGPDIR_TOUT1DIR_CLR		(~(_WDTIM_WDTGPDIR_TOUT1DIR_MASK))




/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the WDTCNT1  register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _WDTIM_WDTCNT1 	 - Note: Add description here
*
* Fields:
*	(RW)   _WDTIM_WDTCNT1_CNT	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTCNT1_CNT:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTCNT1_CNT_SHIFT		(000000u)
#define _WDTIM_WDTCNT1_CNT_MK(n)		(((Uint16)(n) & 0xffffu) << _WDTIM_WDTCNT1_CNT_SHIFT)
#define _WDTIM_WDTCNT1_CNT_MASK		(_WDTIM_WDTCNT1_CNT_MK(0xffffu))
#define _WDTIM_WDTCNT1_CNT_CLR		(~(_WDTIM_WDTCNT1_CNT_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the WDTWCTL2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _WDTIM_WDTWCTL2	 - Note: Add description here
*
* Fields:
*	(RW)   _WDTIM_WDTWCTL2_WDKEY	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTWCTL2_WDKEY:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTWCTL2_WDKEY_SHIFT		(000000u)
#define _WDTIM_WDTWCTL2_WDKEY_MK(n)		(((Uint16)(n) & 0xffffu) << _WDTIM_WDTWCTL2_WDKEY_SHIFT)
#define _WDTIM_WDTWCTL2_WDKEY_MASK		(_WDTIM_WDTWCTL2_WDKEY_MK(0xffffu))
#define _WDTIM_WDTWCTL2_WDKEY_CLR		(~(_WDTIM_WDTWCTL2_WDKEY_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the WDTGPDAT register			
\*----------------------------------------------------------------*/



/******************************************************************************\
* 
* _WDTIM_WDTGPDAT	 - GPIO data register
*
* Fields:
*	(RW)   _WDTIM_WDTGPDAT_TIN1DAT	
*	(RW)   _WDTIM_WDTGPDAT_TOUT1DAT	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTGPDAT_TIN1DAT:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTGPDAT_TIN1DAT_SHIFT		(000000u)
#define _WDTIM_WDTGPDAT_TIN1DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _WDTIM_WDTGPDAT_TIN1DAT_SHIFT)
#define _WDTIM_WDTGPDAT_TIN1DAT_MASK		(_WDTIM_WDTGPDAT_TIN1DAT_MK(0x0001u))
#define _WDTIM_WDTGPDAT_TIN1DAT_CLR		(~(_WDTIM_WDTGPDAT_TIN1DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTGPDAT_TOUT1DAT:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTGPDAT_TOUT1DAT_SHIFT		(000001u)
#define _WDTIM_WDTGPDAT_TOUT1DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _WDTIM_WDTGPDAT_TOUT1DAT_SHIFT)
#define _WDTIM_WDTGPDAT_TOUT1DAT_MASK		(_WDTIM_WDTGPDAT_TOUT1DAT_MK(0x0001u))
#define _WDTIM_WDTGPDAT_TOUT1DAT_CLR		(~(_WDTIM_WDTGPDAT_TOUT1DAT_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the WDTGPEN register			
\*----------------------------------------------------------------*/




/******************************************************************************\
* 
* _WDTIM_WDTGPEN	 - GPIO enable register
*
* Fields:
*       (RW)   _WDTIM_WDTGPEN_TIN1EN
*       (RW)   _WDTIM_WDTGPEN_TOUT1EN

\******************************************************************************/

/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTGPEN_TIN12EN:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTGPEN_TIN1EN_SHIFT		(000000u)
#define _WDTIM_WDTGPEN_TIN1EN_MK(n)		(((Uint16)(n) & 0x0001u) << _WDTIM_WDTGPEN_TIN1EN_SHIFT)
#define _WDTIM_WDTGPEN_TIN1EN_MASK		(_WDTIM_WDTGPEN_TIN1EN_MK(0x0001u))
#define _WDTIM_WDTGPEN_TIN1EN_CLR		        (~(_WDTIM_WDTGPEN_TIN1EN_MASK))


/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTGPEN_TOUT1EN:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTGPEN_TOUT1EN_SHIFT		(000001u)
#define _WDTIM_WDTGPEN_TOUT1EN_MK(n)		(((Uint16)(n) & 0x0001u) << _WDTIM_WDTGPEN_TOUT1EN_SHIFT)
#define _WDTIM_WDTGPEN_TOUT1EN_MASK		(_WDTIM_WDTGPEN_TOUT1EN_MK(0x0001u))
#define _WDTIM_WDTGPEN_TOUT1EN_CLR		(~(_WDTIM_WDTGPEN_TOUT1EN_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the WDTCTL1 register			
\*----------------------------------------------------------------*/



/******************************************************************************\
* 
* _WDTIM_WDTCTL1	 - Timer control register 1
*
* Fields:
*	(R)   _WDTIM_WDTCTL1_TSTAT	
*	(RW)   _WDTIM_WDTCTL1_INVOUT	
*	(RW)   _WDTIM_WDTCTL1_INVIN	
*	(RW)   _WDTIM_WDTCTL1_CP	
*	(RW)   _WDTIM_WDTCTL1_PWID	
*	(RW)   _WDTIM_WDTCTL1_ENAMODE	
*	(RW)   _WDTIM_WDTCTL1_CLKSRC	
*	(RW)   _WDTIM_WDTCTL1_TIEN	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _WDTIM_WDTCTL1_TSTAT:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTCTL1_TSTAT_SHIFT		(000000u)
#define _WDTIM_WDTCTL1_TSTAT_MK(n)		(((Uint16)(n) & 0x0001u) << _WDTIM_WDTCTL1_TSTAT_SHIFT)
#define _WDTIM_WDTCTL1_TSTAT_MASK		        (_WDTIM_WDTCTL1_TSTAT_MK(0x0001u))
#define _WDTIM_WDTCTL1_TSTAT_CLR		        (~(_WDTIM_WDTCTL1_TSTAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTCTL1_INVOUT:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTCTL1_INVOUT_SHIFT		(0x0001u)
#define _WDTIM_WDTCTL1_INVOUT_MK(n)		(((Uint16)(n) & 0x0001u) << _WDTIM_WDTCTL1_INVOUT_SHIFT)
#define _WDTIM_WDTCTL1_INVOUT_MASK		(_WDTIM_WDTCTL1_INVOUT_MK(0x0001u))
#define _WDTIM_WDTCTL1_INVOUT_CLR		        (~(_WDTIM_WDTCTL1_INVOUT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTCTL1_INVIN:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTCTL1_INVIN_SHIFT		(0x0002u)
#define _WDTIM_WDTCTL1_INVIN_MK(n)		(((Uint16)(n) & 0x0001u) << _WDTIM_WDTCTL1_INVIN_SHIFT)
#define _WDTIM_WDTCTL1_INVIN_MASK			(_WDTIM_WDTCTL1_INVIN_MK(0x0001u))
#define _WDTIM_WDTCTL1_INVIN_CLR			(~(_WDTIM_WDTCTL1_INVIN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTCTL1_CP:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTCTL1_CP_SHIFT			(0x0003u)
#define _WDTIM_WDTCTL1_CP_MK(n)			(((Uint16)(n) & 0x0001u) << _WDTIM_WDTCTL1_CP_SHIFT)
#define _WDTIM_WDTCTL1_CP_MASK			(_WDTIM_WDTCTL1_CP_MK(0x0001u))
#define _WDTIM_WDTCTL1_CP_CLR			(~(_WDTIM_WDTCTL1_CP_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTCTL1_PWID:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTCTL1_PWID_SHIFT			(0x0004u)
#define _WDTIM_WDTCTL1_PWID_MK(n)			(((Uint16)(n) & 0x0003u) << _WDTIM_WDTCTL1_PWID_SHIFT)
#define _WDTIM_WDTCTL1_PWID_MASK			(_WDTIM_WDTCTL1_PWID_MK(0x0003u))
#define _WDTIM_WDTCTL1_PWID_CLR			(~(_WDTIM_WDTCTL1_PWID_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTCTL1_ENAMODE:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTCTL1_ENAMODE_SHIFT		(0x0006u)
#define _WDTIM_WDTCTL1_ENAMODE_MK(n)		(((Uint16)(n) & 0x0003u) << _WDTIM_WDTCTL1_ENAMODE_SHIFT)
#define _WDTIM_WDTCTL1_ENAMODE_MASK		(_WDTIM_WDTCTL1_ENAMODE_MK(0x0003u))
#define _WDTIM_WDTCTL1_ENAMODE_CLR		(~(_WDTIM_WDTCTL1_ENAMODE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTCTL1_CLKSRC:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTCTL1_CLKSRC_SHIFT		(0x0008u)
#define _WDTIM_WDTCTL1_CLKSRC_MK(n)		(((Uint16)(n) & 0x0001u) << _WDTIM_WDTCTL1_CLKSRC_SHIFT)
#define _WDTIM_WDTCTL1_CLKSRC_MASK		(_WDTIM_WDTCTL1_CLKSRC_MK(0x0001u))
#define _WDTIM_WDTCTL1_CLKSRC_CLR 		(~(_WDTIM_WDTCTL1_CLKSRC_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTCTL1_TIEN:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTCTL1_TIEN_SHIFT			(0x0009u)
#define _WDTIM_WDTCTL1_TIEN_MK(n)			(((Uint16)(n) & 0x0001u) << _WDTIM_WDTCTL1_TIEN_SHIFT)
#define _WDTIM_WDTCTL1_TIEN_MASK			(_WDTIM_WDTCTL1_TIEN_MK(0x0001u))
#define _WDTIM_WDTCTL1_TIEN_CLR			(~(_WDTIM_WDTCTL1_TIEN_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the WDTCNT2  register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _WDTIM_WDTCNT2 	 - Note: Add description here
*
* Fields:
*	(RW)   _WDTIM_WDTCNT2_CNT	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTCNT2_CNT:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTCNT2_CNT_SHIFT		(000000u)
#define _WDTIM_WDTCNT2_CNT_MK(n)		(((Uint16)(n) & 0xffffu) << _WDTIM_WDTCNT2_CNT_SHIFT)
#define _WDTIM_WDTCNT2_CNT_MASK		(_WDTIM_WDTCNT2_CNT_MK(0xffffu))
#define _WDTIM_WDTCNT2_CNT_CLR		(~(_WDTIM_WDTCNT2_CNT_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the WDTCLK register			
\*----------------------------------------------------------------*/


/******************************************************************************\
* 
* _WDTIM_WDTCLK	 - Timer clock speed register
*
* Fields:
*	(R)   _WDTIM_WDTCLK_CLKDIV
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _WDTIM_WDTCLK_CLKDIV:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTCLK_CLKDIV_SHIFT		(000000u)
#define _WDTIM_WDTCLK_CLKDIV_MK(n)		(((Uint16)(n) & 0x000fu) << _WDTIM_WDTCLK_CLKDIV_SHIFT)
#define _WDTIM_WDTCLK_CLKDIV_MASK		        (_WDTIM_WDTCLK_CLKDIV_MK(0x000fu))
#define _WDTIM_WDTCLK_CLKDIV_CLR		        (~(_WDTIM_WDTCLK_CLKDIV_MASK))


/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the WDTCTL2 register			
\*----------------------------------------------------------------*/



/******************************************************************************\
* 
* _WDTIM_WDTCTL2	 - Timer control register 2
*
* Fields:
*	(R)    _WDTIM_WDTCTL2_TSTAT	
*	(RW)   _WDTIM_WDTCTL2_INVOUT	
*	(RW)   _WDTIM_WDTCTL2_INVIN	
*	(RW)   _WDTIM_WDTCTL2_CP	
*	(RW)   _WDTIM_WDTCTL2_PWID	
*	(RW)   _WDTIM_WDTCTL2_ENAMODE	
*	(RW)   _WDTIM_WDTCTL2_CLKSRC	
*	(RW)   _WDTIM_WDTCTL2_TIEN	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _WDTIM_WDTCTL2_TSTAT:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTCTL2_TSTAT_SHIFT		(000000u)
#define _WDTIM_WDTCTL2_TSTAT_MK(n)		(((Uint16)(n) & 0x0001u) << _WDTIM_WDTCTL2_TSTAT_SHIFT)
#define _WDTIM_WDTCTL2_TSTAT_MASK		        (_WDTIM_WDTCTL2_TSTAT_MK(0x0001u))
#define _WDTIM_WDTCTL2_TSTAT_CLR		        (~(_WDTIM_WDTCTL2_TSTAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTCTL2_INVOUT:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTCTL2_INVOUT_SHIFT		(0x0001u)
#define _WDTIM_WDTCTL2_INVOUT_MK(n)		(((Uint16)(n) & 0x0001u) << _WDTIM_WDTCTL2_INVOUT_SHIFT)
#define _WDTIM_WDTCTL2_INVOUT_MASK		(_WDTIM_WDTCTL2_INVOUT_MK(0x0001u))
#define _WDTIM_WDTCTL2_INVOUT_CLR		        (~(_WDTIM_WDTCTL2_INVOUT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTCTL2_INVIN:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTCTL2_INVIN_SHIFT		(0x0002u)
#define _WDTIM_WDTCTL2_INVIN_MK(n)		(((Uint16)(n) & 0x0001u) << _WDTIM_WDTCTL2_INVIN_SHIFT)
#define _WDTIM_WDTCTL2_INVIN_MASK			(_WDTIM_WDTCTL2_INVIN_MK(0x0001u))
#define _WDTIM_WDTCTL2_INVIN_CLR			(~(_WDTIM_WDTCTL2_INVIN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTCTL2_CP:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTCTL2_CP_SHIFT			(0x0003u)
#define _WDTIM_WDTCTL2_CP_MK(n)			(((Uint16)(n) & 0x0001u) << _WDTIM_WDTCTL2_CP_SHIFT)
#define _WDTIM_WDTCTL2_CP_MASK			(_WDTIM_WDTCTL2_CP_MK(0x0001u))
#define _WDTIM_WDTCTL2_CP_CLR			(~(_WDTIM_WDTCTL2_CP_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTCTL2_PWID:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTCTL2_PWID_SHIFT			(0x0004u)
#define _WDTIM_WDTCTL2_PWID_MK(n)			(((Uint16)(n) & 0x0003u) << _WDTIM_WDTCTL2_PWID_SHIFT)
#define _WDTIM_WDTCTL2_PWID_MASK			(_WDTIM_WDTCTL2_PWID_MK(0x0003u))
#define _WDTIM_WDTCTL2_PWID_CLR			(~(_WDTIM_WDTCTL2_PWID_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTCTL2_ENAMODE:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTCTL2_ENAMODE_SHIFT		(0x0006u)
#define _WDTIM_WDTCTL2_ENAMODE_MK(n)		(((Uint16)(n) & 0x0003u) << _WDTIM_WDTCTL2_ENAMODE_SHIFT)
#define _WDTIM_WDTCTL2_ENAMODE_MASK		(_WDTIM_WDTCTL2_ENAMODE_MK(0x0003u))
#define _WDTIM_WDTCTL2_ENAMODE_CLR		(~(_WDTIM_WDTCTL2_ENAMODE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTCTL2_CLKSRC:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTCTL2_CLKSRC_SHIFT		(0x0008u)
#define _WDTIM_WDTCTL2_CLKSRC_MK(n)		(((Uint16)(n) & 0x0001u) << _WDTIM_WDTCTL2_CLKSRC_SHIFT)
#define _WDTIM_WDTCTL2_CLKSRC_MASK		(_WDTIM_WDTCTL2_CLKSRC_MK(0x0001u))
#define _WDTIM_WDTCTL2_CLKSRC_CLR 		(~(_WDTIM_WDTCTL2_CLKSRC_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTCTL2_TIEN:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTCTL2_TIEN_SHIFT			(0x0009u)
#define _WDTIM_WDTCTL2_TIEN_MK(n)			(((Uint16)(n) & 0x0001u) << _WDTIM_WDTCTL2_TIEN_SHIFT)
#define _WDTIM_WDTCTL2_TIEN_MASK			(_WDTIM_WDTCTL2_TIEN_MK(0x0001u))
#define _WDTIM_WDTCTL2_TIEN_CLR			(~(_WDTIM_WDTCTL2_TIEN_MASK))




/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the WDTEMU register			
\*----------------------------------------------------------------*/


/******************************************************************************\
* 
* _WDTIM_WDTEMU	 - Emulation management register
*
* Fields:
*	(R)   _WDTIM_WDTEMU_FREE
*   (R)   _WDTIM_WDTEMU_SOFT 	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _WDTIM_WDTEMU_FREE:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTEMU_FREE_SHIFT		(000000u)
#define _WDTIM_WDTEMU_FREE_MK(n)		(((Uint16)(n) & 0x0001u) << _WDTIM_WDTEMU_FREE_SHIFT)
#define _WDTIM_WDTEMU_FREE_MASK		(_WDTIM_WDTEMU_FREE_MK(0x0001u))
#define _WDTIM_WDTEMU_FREE_CLR		(~(_WDTIM_WDTEMU_FREE_MASK))

/*----------------------------------------------------------------*\
*   (R)  _WDTIM_WDTEMU_SOFT:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTEMU_SOFT_SHIFT		(000001u)
#define _WDTIM_WDTEMU_SOFT_MK(n)		(((Uint16)(n) & 0x0001u) << _WDTIM_WDTEMU_SOFT_SHIFT)
#define _WDTIM_WDTEMU_SOFT_MASK		(_WDTIM_WDTEMU_SOFT_MK(0x0001u))
#define _WDTIM_WDTEMU_SOFT_CLR		(~(_WDTIM_WDTEMU_SOFT_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the WDTPRD1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _WDTIM_WDTPRD1	 - Note: Add description here
*
* Fields:
*	(RW)   _WDTIM_WDTPRD1_PRD	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTPRD1_PRD:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTPRD1_PRD_SHIFT		(000000u)
#define _WDTIM_WDTPRD1_PRD_MK(n)		(((Uint16)(n) & 0xffffu) << _WDTIM_WDTPRD1_PRD_SHIFT)
#define _WDTIM_WDTPRD1_PRD_MASK		(_WDTIM_WDTPRD1_PRD_MK(0xffffu))
#define _WDTIM_WDTPRD1_PRD_CLR		(~(_WDTIM_WDTPRD1_PRD_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the WDTGPINT register			
\*----------------------------------------------------------------*/



/******************************************************************************\
* 
* _WDTIM_WDTGPINT	 - GPIO interrupt control register
*
* Fields:
*       (RW)   _WDTIM_WDTGPINT_TIN1INT	  
*       (RW)   _WDTIM_WDTGPINT_TIN1INV	  

\******************************************************************************/


/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTGPINT_TIN1INT:
\*----------------------------------------------------------------*/

#define _WDTIM_WDTGPINT_TIN1INT_SHIFT		(000000u)
#define _WDTIM_WDTGPINT_TIN1INT_MK(n)		(((Uint16)(n) & 0x0001u) << _WDTIM_WDTGPINT_TIN1INT_SHIFT)
#define _WDTIM_WDTGPINT_TIN1INT_MASK		(_WDTIM_WDTGPINT_TIN1INT_MK(0x0001u))
#define _WDTIM_WDTGPINT_TIN1INT_CLR		(~(_WDTIM_WDTGPINT_TIN1INT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTGPINT_TIN1INV:
\*----------------------------------------------------------------*/

#define _WDTIM_WDTGPINT_TIN1INV_SHIFT		(000004u)
#define _WDTIM_WDTGPINT_TIN1INV_MK(n)		(((Uint16)(n) & 0x0001u) << _WDTIM_WDTGPINT_TIN1INV_SHIFT)
#define _WDTIM_WDTGPINT_TIN1INV_MASK		(_WDTIM_WDTGPINT_TIN1INV_MK(0x0001u))
#define _WDTIM_WDTGPINT_TIN1INV_CLR		(~(_WDTIM_WDTGPINT_TIN1INV_MASK))




/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the WDTPRD2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _WDTIM_WDTPRD2	 - Note: Add description here
*
* Fields:
*	(RW)   _WDTIM_WDTPRD2_PRD	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTPRD2_PRD:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTPRD2_PRD_SHIFT		(000000u)
#define _WDTIM_WDTPRD2_PRD_MK(n)		(((Uint16)(n) & 0xffffu) << _WDTIM_WDTPRD2_PRD_SHIFT)
#define _WDTIM_WDTPRD2_PRD_MASK		(_WDTIM_WDTPRD2_PRD_MK(0xffffu))
#define _WDTIM_WDTPRD2_PRD_CLR		(~(_WDTIM_WDTPRD2_PRD_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the WDTPRD3 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _WDTIM_WDTPRD3	 - Note: Add description here
*
* Fields:
*	(RW)   _WDTIM_WDTPRD3_PRD	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTPRD3_PRD:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTPRD3_PRD_SHIFT		(000000u)
#define _WDTIM_WDTPRD3_PRD_MK(n)		(((Uint16)(n) & 0xffffu) << _WDTIM_WDTPRD3_PRD_SHIFT)
#define _WDTIM_WDTPRD3_PRD_MASK		(_WDTIM_WDTPRD3_PRD_MK(0xffffu))
#define _WDTIM_WDTPRD3_PRD_CLR		(~(_WDTIM_WDTPRD3_PRD_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the WDTCNT3 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _WDTIM_WDTCNT3	 - Note: Add description here
*
* Fields:
*	(RW)   _WDTIM_WDTCNT3_CNT	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTCNT3_CNT:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTCNT3_CNT_SHIFT		(000000u)
#define _WDTIM_WDTCNT3_CNT_MK(n)		(((Uint16)(n) & 0xffffu) << _WDTIM_WDTCNT3_CNT_SHIFT)
#define _WDTIM_WDTCNT3_CNT_MASK		(_WDTIM_WDTCNT3_CNT_MK(0xffffu))
#define _WDTIM_WDTCNT3_CNT_CLR		(~(_WDTIM_WDTCNT3_CNT_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the WDTPRD4 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _WDTIM_WDTPRD4	 - Note: Add description here
*
* Fields:
*	(RW)   _WDTIM_WDTPRD4_PRD	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _WDTIM_WDTPRD4_PRD:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTPRD4_PRD_SHIFT		(000000u)
#define _WDTIM_WDTPRD4_PRD_MK(n)		(((Uint16)(n) & 0xffffu) << _WDTIM_WDTPRD4_PRD_SHIFT)
#define _WDTIM_WDTPRD4_PRD_MASK		(_WDTIM_WDTPRD4_PRD_MK(0xffffu))
#define _WDTIM_WDTPRD4_PRD_CLR		(~(_WDTIM_WDTPRD4_PRD_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the WDTCNT4 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _WDTIM_WDTCNT4	 - Note: Add description here
*
* Fields:
*	(R)   _WDTIM_WDTCNT4_CNT	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _WDTIM_WDTCNT4_CNT:	
\*----------------------------------------------------------------*/

#define _WDTIM_WDTCNT4_CNT_SHIFT		(000000u)
#define _WDTIM_WDTCNT4_CNT_MK(n)		(((Uint16)(n) & 0xffffu) << _WDTIM_WDTCNT4_CNT_SHIFT)
#define _WDTIM_WDTCNT4_CNT_MASK		(_WDTIM_WDTCNT4_CNT_MK(0xffffu))
#define _WDTIM_WDTCNT4_CNT_CLR		(~(_WDTIM_WDTCNT4_CNT_MASK))


#elif (!(_WDTIM_MOD))
	#error WDTIM Hal Module Not Supported on Specified Target
#endif  /* _WDTIM_SUPPORT  */

#endif  /* _CSL_WDTIMHAL_H  */

/******************************************************************************\
*     
*      End of csl_wdtimhal.h 
*
\******************************************************************************/
