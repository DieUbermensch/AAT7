/****************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved 
*------------------------------------------------------------------------------
* MODULE NAME... HPI
* FILENAME...... csl_hpihal.h
* DATE CREATED.. Fri Mar 22 11:46:12 2002
* PROJECT....... Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS.. 
*------------------------------------------------------------------------------
*
* HISTORY:
*	 Created:		Fri Mar 22 11:46:12 2002 (Automatic generation)
*	 Last Modified:	3 Apr 2003 changed register and bit field names to match
*                                  datasheet (sprs166c and UG spru620A)
*                       24 June 2004 Added macros for the registers, HGPIODIR1,
*                                    HGPIODIR2,HGPIODIR3,HGPIODAT1,HGPIODAT2,HGPIODAT3
*
*------------------------------------------------------------------------------
* DESCRIPTION: CSL HAL interface file for the HPI module 
*
* Registers covered:
*
* 		 Note: Add registers description here
*	 PIDLSW	        	- 
*	 PIDMSW		        - 
*	 HPWREMU		- 
*	 HGPIOEN		- 
*	 HGPIODIR(HGPIODIR1)	- 
*	 HGPIODIR2              -
*	 HGPIODIR3              -
*	 HGPIODAT(HGPIODAT1)	- 
*	 HGPIODAT2              -
*	 HGPIODAT3              -
*	 HPIC		        - 
*	 HPIAW		        - 
*	 HPIAR		        - 
\*************************************************************************/

#ifndef _CSL_HPIHAL_H_
#define _CSL_HPIHAL_H_

#include <csl_chiphal.h>

#if (_HPI_SUPPORT) 

/*----------------------------------------------------------------*\
*	 HPI scope and inline control macros 			
\*----------------------------------------------------------------*/

#ifdef __cplusplus
#define CSLAPI extern "C"
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _HPI_MOD_
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
#define _HPI_BASE_ADDR                (0xA000u)
/*--------------------- Register: PIDLSW -----------------------*/
#define _HPI_PIDLSW_ADDR		(0xA000u)
#define _HPI_PIDLSW			PREG16(_HPI_PIDLSW_ADDR)
#define PIDLSW			_HPI_PIDLSW


/*--------------------- Register: PIDMSW -----------------------*/
#define _HPI_PIDMSW_ADDR		(0xA001u)
#define _HPI_PIDMSW			PREG16(_HPI_PIDMSW_ADDR)
#define PIDMSW			_HPI_PIDMSW


/*--------------------- Register: PWREMU -----------------------*/
#define _HPI_HPWREMU_ADDR		(0xA002u)
#define _HPI_HPWREMU			PREG16(_HPI_HPWREMU_ADDR)
#define PWREMU			_HPI_HPWREMU


/*--------------------- Register: HGPIOEN -----------------------*/
#define _HPI_HGPIOEN_ADDR		(0xA006u)
#define _HPI_HGPIOEN			PREG16(_HPI_HGPIOEN_ADDR)
#define HGPIOEN			_HPI_HGPIOEN


/*--------------------- Register: HGPIODIR -----------------------*/
#define _HPI_HGPIODIR_ADDR		(0xA008u)
#define _HPI_HGPIODIR			PREG16(_HPI_HGPIODIR_ADDR)
#define HGPIODIR			_HPI_HGPIODIR


/*--------------------- Register: HGPIODIR1 -----------------------*/
#define _HPI_HGPIODIR1_ADDR		(0xA008u)
#define _HPI_HGPIODIR1			PREG16(_HPI_HGPIODIR1_ADDR)
#define HGPIODIR1			_HPI_HGPIODIR1


/*--------------------- Register: HGPIODIR2 -----------------------*/
#define _HPI_HGPIODIR2_ADDR		(0xA00Cu)
#define _HPI_HGPIODIR2			PREG16(_HPI_HGPIODIR2_ADDR)
#define HGPIODIR2			_HPI_HGPIODIR2


/*--------------------- Register: HGPIODIR3 -----------------------*/
#define _HPI_HGPIODIR3_ADDR		(0xA010u)
#define _HPI_HGPIODIR3			PREG16(_HPI_HGPIODIR3_ADDR)
#define HGPIODIR3			_HPI_HGPIODIR3


/*--------------------- Register: HGPIODAT -----------------------*/
#define _HPI_HGPIODAT_ADDR		(0xA00Au)
#define _HPI_HGPIODAT			PREG16(_HPI_HGPIODAT_ADDR)
#define HGPIODAT			_HPI_HGPIODAT


/*--------------------- Register: HGPIODAT1 -----------------------*/
#define _HPI_HGPIODAT1_ADDR		(0xA00Au)
#define _HPI_HGPIODAT1			PREG16(_HPI_HGPIODAT1_ADDR)
#define HGPIODAT1			_HPI_HGPIODAT1


/*--------------------- Register: HGPIODAT2 -----------------------*/
#define _HPI_HGPIODAT2_ADDR		(0xA00Eu)
#define _HPI_HGPIODAT2			PREG16(_HPI_HGPIODAT2_ADDR)
#define HGPIODAT2			_HPI_HGPIODAT2


/*--------------------- Register: HGPIODAT3 -----------------------*/
#define _HPI_HGPIODAT3_ADDR		(0xA012u)
#define _HPI_HGPIODAT3			PREG16(_HPI_HGPIODAT3_ADDR)
#define HGPIODAT3			_HPI_HGPIODAT3


/*--------------------- Register: HPIC -----------------------*/
#define _HPI_HPIC_ADDR		(0xa018u)
#define _HPI_HPIC			PREG16(_HPI_HPIC_ADDR)
#define HPIC			_HPI_HPIC


/*--------------------- Register: HPIAW -----------------------*/
#define _HPI_HPIAW_ADDR		(0xA020)
#define _HPI_HPIAW			PREG16(_HPI_HPIAW_ADDR)
#define HPIAW			_HPI_HPIAW


/*--------------------- Register: HPIAR -----------------------*/
#define _HPI_HPIAR_ADDR		(0xA022)
#define _HPI_HPIAR			PREG16(_HPI_HPIAR_ADDR)
#define HPIAR			_HPI_HPIAR


/*----------------------------------------------------------------*\
*		 Register Macros		
\*----------------------------------------------------------------*/

#define HPI_ADDR(Reg)		  _HPI_##Reg##_ADDR
#define HPI_RGET(Reg)		  _HPI_##Reg##_GET
#define HPI_RSET(Reg,Val)		  _HPI_##Reg##_SET(Val)
#define HPI_FGET(Reg,Field)		  _HPI_##Reg##_FGET(Field)
#define HPI_FSET(Reg,Field,Val)		  _HPI_##Reg##_FSET(Field, Val)
#define HPI_FMK(Reg,Field,Val)		  _HPI_##Reg##_##Field##_MK(Val)
#define HPI_RAOI(Reg,AND,OR,INV)		  _HPI_##Reg##_AOI(AND,OR,INV)
#define HPI_FAOI(Reg,Field,AND,OR,INV)	  _HPI_##Reg##_FAOI(Field,AND,OR,INV)
#define HPI_FMKS(Reg,Field,Sym)\
	  _HPI_##Reg##_##Field##_MK(HPI_##Reg##_##Field##_##Sym)
#define HPI_FSETS(Reg,Field,Sym)\
	  _HPI_FSET(Reg,Field,HPI_##Reg##_##Field##_##Sym)

/*----------------------------------------------------------------*\
*		 Non-handle Registers Macros		
\*----------------------------------------------------------------*/


/*--------------------- Register: PIDLSW -----------------------*/
#define _HPI_PIDLSW_GET		  _PREG_GET(_HPI_PIDLSW_ADDR) 
#define _HPI_PIDLSW_SET(Val)		  _PREG_SET(_HPI_PIDLSW_ADDR,Val)
#define _HPI_PIDLSW_FGET(Field)	  _PFIELD_GET(_HPI_PIDLSW_ADDR, _HPI_PIDLSW_##Field)
#define _HPI_PIDLSW_FSET(Field,Val)	  _PFIELD_SET(_HPI_PIDLSW_ADDR, _HPI_PIDLSW_##Field, Val)
#define _HPI_PIDLSW_AOI(AND,OR,INV)	  _PREG_AOI(_HPI_PIDLSW_ADDR,AND,OR,INV)
#define _HPI_PIDLSW_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_HPI_PIDLSW_ADDR, _HPI_PIDLSW_##Field,AND,OR,INV)


/*--------------------- Register: PIDMSW -----------------------*/
#define _HPI_PIDMSW_GET		  _PREG_GET(_HPI_PIDMSW_ADDR) 
#define _HPI_PIDMSW_SET(Val)		  _PREG_SET(_HPI_PIDMSW_ADDR,Val)
#define _HPI_PIDMSW_FGET(Field)	  _PFIELD_GET(_HPI_PIDMSW_ADDR, _HPI_PIDMSW_##Field)
#define _HPI_PIDMSW_FSET(Field,Val)	  _PFIELD_SET(_HPI_PIDMSW_ADDR, _HPI_PIDMSW_##Field, Val)
#define _HPI_PIDMSW_AOI(AND,OR,INV)	  _PREG_AOI(_HPI_PIDMSW_ADDR,AND,OR,INV)
#define _HPI_PIDMSW_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_HPI_PIDMSW_ADDR, _HPI_PIDMSW_##Field,AND,OR,INV)


/*--------------------- Register: PWREMU -----------------------*/
#define _HPI_HPWREMU_GET		  _PREG_GET(_HPI_HPWREMU_ADDR) 
#define _HPI_HPWREMU_SET(Val)		  _PREG_SET(_HPI_HPWREMU_ADDR,Val)
#define _HPI_HPWREMU_FGET(Field)	  _PFIELD_GET(_HPI_HPWREMU_ADDR, _HPI_HPWREMU_##Field)
#define _HPI_HPWREMU_FSET(Field,Val)	  _PFIELD_SET(_HPI_HPWREMU_ADDR, _HPI_HPWREMU_##Field, Val)
#define _HPI_HPWREMU_AOI(AND,OR,INV)	  _PREG_AOI(_HPI_HPWREMU_ADDR,AND,OR,INV)
#define _HPI_HPWREMU_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_HPI_HPWREMU_ADDR, _HPI_HPWREMU_##Field,AND,OR,INV)


/*--------------------- Register: HGPIOEN -----------------------*/
#define _HPI_HGPIOEN_GET		  _PREG_GET(_HPI_HGPIOEN_ADDR) 
#define _HPI_HGPIOEN_SET(Val)		  _PREG_SET(_HPI_HGPIOEN_ADDR,Val)
#define _HPI_HGPIOEN_FGET(Field)	  _PFIELD_GET(_HPI_HGPIOEN_ADDR, _HPI_HGPIOEN_##Field)
#define _HPI_HGPIOEN_FSET(Field,Val)	  _PFIELD_SET(_HPI_HGPIOEN_ADDR, _HPI_HGPIOEN_##Field, Val)
#define _HPI_HGPIOEN_AOI(AND,OR,INV)	  _PREG_AOI(_HPI_HGPIOEN_ADDR,AND,OR,INV)
#define _HPI_HGPIOEN_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_HPI_HGPIOEN_ADDR, _HPI_HGPIOEN_##Field,AND,OR,INV)


/*--------------------- Register: HGPIODIR -----------------------*/
#define _HPI_HGPIODIR_GET		  _PREG_GET(_HPI_HGPIODIR_ADDR) 
#define _HPI_HGPIODIR_SET(Val)		  _PREG_SET(_HPI_HGPIODIR_ADDR,Val)
#define _HPI_HGPIODIR_FGET(Field)	  _PFIELD_GET(_HPI_HGPIODIR_ADDR, _HPI_HGPIODIR_##Field)
#define _HPI_HGPIODIR_FSET(Field,Val)	  _PFIELD_SET(_HPI_HGPIODIR_ADDR, _HPI_HGPIODIR_##Field, Val)
#define _HPI_HGPIODIR_AOI(AND,OR,INV)	  _PREG_AOI(_HPI_HGPIODIR_ADDR,AND,OR,INV)
#define _HPI_HGPIODIR_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_HPI_HGPIODIR_ADDR, _HPI_HGPIODIR_##Field,AND,OR,INV)

    
/*--------------------- Register: HGPIODIR1 -----------------------*/
#define _HPI_HGPIODIR1_GET		  _PREG_GET(_HPI_HGPIODIR1_ADDR) 
#define _HPI_HGPIODIR1_SET(Val)		  _PREG_SET(_HPI_HGPIODIR1_ADDR,Val)
#define _HPI_HGPIODIR1_FGET(Field)	  _PFIELD_GET(_HPI_HGPIODIR1_ADDR, _HPI_HGPIODIR1_##Field)
#define _HPI_HGPIODIR1_FSET(Field,Val)	  _PFIELD_SET(_HPI_HGPIODIR1_ADDR, _HPI_HGPIODIR1_##Field, Val)
#define _HPI_HGPIODIR1_AOI(AND,OR,INV)	  _PREG_AOI(_HPI_HGPIODIR1_ADDR,AND,OR,INV)
#define _HPI_HGPIODIR1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_HPI_HGPIODIR1_ADDR, _HPI_HGPIODIR1_##Field,AND,OR,INV)


/*--------------------- Register: HGPIODIR2 -----------------------*/
#define _HPI_HGPIODIR2_GET		  _PREG_GET(_HPI_HGPIODIR2_ADDR) 
#define _HPI_HGPIODIR2_SET(Val)		  _PREG_SET(_HPI_HGPIODIR2_ADDR,Val)
#define _HPI_HGPIODIR2_FGET(Field)	  _PFIELD_GET(_HPI_HGPIODIR2_ADDR, _HPI_HGPIODIR2_##Field)
#define _HPI_HGPIODIR2_FSET(Field,Val)	  _PFIELD_SET(_HPI_HGPIODIR2_ADDR, _HPI_HGPIODIR2_##Field, Val)
#define _HPI_HGPIODIR2_AOI(AND,OR,INV)	  _PREG_AOI(_HPI_HGPIODIR2_ADDR,AND,OR,INV)
#define _HPI_HGPIODIR2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_HPI_HGPIODIR2_ADDR, _HPI_HGPIODIR2_##Field,AND,OR,INV)


/*--------------------- Register: HGPIODIR3 -----------------------*/
#define _HPI_HGPIODIR3_GET		  _PREG_GET(_HPI_HGPIODIR3_ADDR) 
#define _HPI_HGPIODIR3_SET(Val)		  _PREG_SET(_HPI_HGPIODIR3_ADDR,Val)
#define _HPI_HGPIODIR3_FGET(Field)	  _PFIELD_GET(_HPI_HGPIODIR3_ADDR, _HPI_HGPIODIR3_##Field)
#define _HPI_HGPIODIR3_FSET(Field,Val)	  _PFIELD_SET(_HPI_HGPIODIR3_ADDR, _HPI_HGPIODIR3_##Field, Val)
#define _HPI_HGPIODIR3_AOI(AND,OR,INV)	  _PREG_AOI(_HPI_HGPIODIR3_ADDR,AND,OR,INV)
#define _HPI_HGPIODIR3_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_HPI_HGPIODIR3_ADDR, _HPI_HGPIODIR3_##Field,AND,OR,INV)



/*--------------------- Register: HGPIODAT -----------------------*/
#define _HPI_HGPIODAT_GET		  _PREG_GET(_HPI_HGPIODAT_ADDR) 
#define _HPI_HGPIODAT_SET(Val)		  _PREG_SET(_HPI_HGPIODAT_ADDR,Val)
#define _HPI_HGPIODAT_FGET(Field)	  _PFIELD_GET(_HPI_HGPIODAT_ADDR, _HPI_HGPIODAT_##Field)
#define _HPI_HGPIODAT_FSET(Field,Val)	  _PFIELD_SET(_HPI_HGPIODAT_ADDR, _HPI_HGPIODAT_##Field, Val)
#define _HPI_HGPIODAT_AOI(AND,OR,INV)	  _PREG_AOI(_HPI_HGPIODAT_ADDR,AND,OR,INV)
#define _HPI_HGPIODAT_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_HPI_HGPIODAT_ADDR, _HPI_HGPIODAT_##Field,AND,OR,INV)


/*--------------------- Register: HGPIODAT1 -----------------------*/
#define _HPI_HGPIODAT1_GET		  _PREG_GET(_HPI_HGPIODAT1_ADDR) 
#define _HPI_HGPIODAT1_SET(Val)		  _PREG_SET(_HPI_HGPIODAT1_ADDR,Val)
#define _HPI_HGPIODAT1_FGET(Field)	  _PFIELD_GET(_HPI_HGPIODAT1_ADDR, _HPI_HGPIODAT1_##Field)
#define _HPI_HGPIODAT1_FSET(Field,Val)	  _PFIELD_SET(_HPI_HGPIODAT1_ADDR, _HPI_HGPIODAT1_##Field, Val)
#define _HPI_HGPIODAT1_AOI(AND,OR,INV)	  _PREG_AOI(_HPI_HGPIODAT1_ADDR,AND,OR,INV)
#define _HPI_HGPIODAT1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_HPI_HGPIODAT1_ADDR, _HPI_HGPIODAT1_##Field,AND,OR,INV)


/*--------------------- Register: HGPIODAT2 -----------------------*/
#define _HPI_HGPIODAT2_GET		  _PREG_GET(_HPI_HGPIODAT2_ADDR) 
#define _HPI_HGPIODAT2_SET(Val)		  _PREG_SET(_HPI_HGPIODAT2_ADDR,Val)
#define _HPI_HGPIODAT2_FGET(Field)	  _PFIELD_GET(_HPI_HGPIODAT2_ADDR, _HPI_HGPIODAT2_##Field)
#define _HPI_HGPIODAT2_FSET(Field,Val)	  _PFIELD_SET(_HPI_HGPIODAT2_ADDR, _HPI_HGPIODAT2_##Field, Val)
#define _HPI_HGPIODAT2_AOI(AND,OR,INV)	  _PREG_AOI(_HPI_HGPIODAT2_ADDR,AND,OR,INV)
#define _HPI_HGPIODAT2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_HPI_HGPIODAT2_ADDR, _HPI_HGPIODAT2_##Field,AND,OR,INV)


/*--------------------- Register: HGPIODAT3 -----------------------*/
#define _HPI_HGPIODAT3_GET		  _PREG_GET(_HPI_HGPIODAT3_ADDR) 
#define _HPI_HGPIODAT3_SET(Val)		  _PREG_SET(_HPI_HGPIODAT3_ADDR,Val)
#define _HPI_HGPIODAT3_FGET(Field)	  _PFIELD_GET(_HPI_HGPIODAT3_ADDR, _HPI_HGPIODAT3_##Field)
#define _HPI_HGPIODAT3_FSET(Field,Val)	  _PFIELD_SET(_HPI_HGPIODAT3_ADDR, _HPI_HGPIODAT3_##Field, Val)
#define _HPI_HGPIODAT3_AOI(AND,OR,INV)	  _PREG_AOI(_HPI_HGPIODAT3_ADDR,AND,OR,INV)
#define _HPI_HGPIODAT3_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_HPI_HGPIODAT3_ADDR, _HPI_HGPIODAT3_##Field,AND,OR,INV)



/*--------------------- Register: HPIC -----------------------*/
#define _HPI_HPIC_GET		  _PREG_GET(_HPI_HPIC_ADDR) 
#define _HPI_HPIC_SET(Val)		  _PREG_SET(_HPI_HPIC_ADDR,Val)
#define _HPI_HPIC_FGET(Field)	  _PFIELD_GET(_HPI_HPIC_ADDR, _HPI_HPIC_##Field)
#define _HPI_HPIC_FSET(Field,Val)	  _PFIELD_SET(_HPI_HPIC_ADDR, _HPI_HPIC_##Field, Val)
#define _HPI_HPIC_AOI(AND,OR,INV)	  _PREG_AOI(_HPI_HPIC_ADDR,AND,OR,INV)
#define _HPI_HPIC_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_HPI_HPIC_ADDR, _HPI_HPIC_##Field,AND,OR,INV)


/*--------------------- Register: HPIAW -----------------------*/
#define _HPI_HPIAW_GET		  _PREG_GET(_HPI_HPIAW_ADDR) 
#define _HPI_HPIAW_SET(Val)		  _PREG_SET(_HPI_HPIAW_ADDR,Val)
#define _HPI_HPIAW_FGET(Field)	  _PFIELD_GET(_HPI_HPIAW_ADDR, _HPI_HPIAW_##Field)
#define _HPI_HPIAW_FSET(Field,Val)	  _PFIELD_SET(_HPI_HPIAW_ADDR, _HPI_HPIAW_##Field, Val)
#define _HPI_HPIAW_AOI(AND,OR,INV)	  _PREG_AOI(_HPI_HPIAW_ADDR,AND,OR,INV)
#define _HPI_HPIAW_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_HPI_HPIAW_ADDR, _HPI_HPIAW_##Field,AND,OR,INV)


/*--------------------- Register: HPIAR -----------------------*/
#define _HPI_HPIAR_GET		  _PREG_GET(_HPI_HPIAR_ADDR) 
#define _HPI_HPIAR_SET(Val)		  _PREG_SET(_HPI_HPIAR_ADDR,Val)
#define _HPI_HPIAR_FGET(Field)	  _PFIELD_GET(_HPI_HPIAR_ADDR, _HPI_HPIAR_##Field)
#define _HPI_HPIAR_FSET(Field,Val)	  _PFIELD_SET(_HPI_HPIAR_ADDR, _HPI_HPIAR_##Field, Val)
#define _HPI_HPIAR_AOI(AND,OR,INV)	  _PREG_AOI(_HPI_HPIAR_ADDR,AND,OR,INV)
#define _HPI_HPIAR_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_HPI_HPIAR_ADDR, _HPI_HPIAR_##Field,AND,OR,INV)



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the HPIAR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _HPI_HPIAR	 - Note: Add description here
*
* Fields:
*	(RW)   _HPI_HPIAR_HPIAR	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _HPI_HPIAR_HPIAR:	
\*----------------------------------------------------------------*/

#define _HPI_HPIAR_HPIAR_SHIFT		(000000u)
#define _HPI_HPIAR_HPIAR_MK(n)		(((Uint16)(n) & 0xffffu) << _HPI_HPIAR_HPIAR_SHIFT)
#define _HPI_HPIAR_HPIAR_MASK		(_HPI_HPIAR_HPIAR_MK(0xffffu))
#define _HPI_HPIAR_HPIAR_CLR		(~(_HPI_HPIAR_HPIAR_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the HPIC register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _HPI_HPIC	 - Note: Add description here
*
* Fields:
*	(RW)   _HPI_HPIC_BOB	
*	(R)    _HPI_HPIC_DSPINT	
*	(RW)   _HPI_HPIC_HINT	
*	(R)    _HPI_HPIC_HRDY	
*	(R)    _HPI_HPIC_FETCH	
*	(RW)   _HPI_HPIC_HPIRST	
*	(RW)   _HPI_HPIC_BOBSTAT	
*	(RW)   _HPI_HPIC_DUALHPIA	
*	(RW)   _HPI_HPIC_HPIASEL	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _HPI_HPIC_BOB:	
\*----------------------------------------------------------------*/

#define _HPI_HPIC_BOB_SHIFT		(000000u)
#define _HPI_HPIC_BOB_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HPIC_BOB_SHIFT)
#define _HPI_HPIC_BOB_MASK		(_HPI_HPIC_BOB_MK(0x0001u))
#define _HPI_HPIC_BOB_CLR		(~(_HPI_HPIC_BOB_MASK))



/*----------------------------------------------------------------*\
*   (R)  _HPI_HPIC_DSPINT:	
\*----------------------------------------------------------------*/

#define _HPI_HPIC_DSPINT_SHIFT		(0x0001u)
#define _HPI_HPIC_DSPINT_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HPIC_DSPINT_SHIFT)
#define _HPI_HPIC_DSPINT_MASK		(_HPI_HPIC_DSPINT_MK(0x0001u))
#define _HPI_HPIC_DSPINT_CLR		(~(_HPI_HPIC_DSPINT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HPIC_HINT:	
\*----------------------------------------------------------------*/

#define _HPI_HPIC_HINT_SHIFT		(0x0002u)
#define _HPI_HPIC_HINT_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HPIC_HINT_SHIFT)
#define _HPI_HPIC_HINT_MASK		(_HPI_HPIC_HINT_MK(0x0001u))
#define _HPI_HPIC_HINT_CLR		(~(_HPI_HPIC_HINT_MASK))



/*----------------------------------------------------------------*\
*   (R)  _HPI_HPIC_HRDY:	
\*----------------------------------------------------------------*/

#define _HPI_HPIC_HRDY_SHIFT		(0x0003u)
#define _HPI_HPIC_HRDY_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HPIC_HRDY_SHIFT)
#define _HPI_HPIC_HRDY_MASK		(_HPI_HPIC_HRDY_MK(0x0001u))
#define _HPI_HPIC_HRDY_CLR		(~(_HPI_HPIC_HRDY_MASK))



/*----------------------------------------------------------------*\
*   (R)  _HPI_HPIC_FETCH:	
\*----------------------------------------------------------------*/

#define _HPI_HPIC_FETCH_SHIFT		(0x0004u)
#define _HPI_HPIC_FETCH_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HPIC_FETCH_SHIFT)
#define _HPI_HPIC_FETCH_MASK		(_HPI_HPIC_FETCH_MK(0x0001u))
#define _HPI_HPIC_FETCH_CLR		(~(_HPI_HPIC_FETCH_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HPIC_HPIRST:	
\*----------------------------------------------------------------*/

#define _HPI_HPIC_HPIRST_SHIFT		(0x0007u)
#define _HPI_HPIC_HPIRST_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HPIC_HPIRST_SHIFT)
#define _HPI_HPIC_HPIRST_MASK		(_HPI_HPIC_HPIRST_MK(0x0001u))
#define _HPI_HPIC_HPIRST_CLR		(~(_HPI_HPIC_HPIRST_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HPIC_BOBSTAT:	
\*----------------------------------------------------------------*/

#define _HPI_HPIC_BOBSTAT_SHIFT		(0x0008u)
#define _HPI_HPIC_BOBSTAT_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HPIC_BOBSTAT_SHIFT)
#define _HPI_HPIC_BOBSTAT_MASK		(_HPI_HPIC_BOBSTAT_MK(0x0001u))
#define _HPI_HPIC_BOBSTAT_CLR		(~(_HPI_HPIC_BOBSTAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HPIC_DUALHPIA:	
\*----------------------------------------------------------------*/

#define _HPI_HPIC_DUALHPIA_SHIFT		(0x0009u)
#define _HPI_HPIC_DUALHPIA_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HPIC_DUALHPIA_SHIFT)
#define _HPI_HPIC_DUALHPIA_MASK		(_HPI_HPIC_DUALHPIA_MK(0x0001u))
#define _HPI_HPIC_DUALHPIA_CLR		(~(_HPI_HPIC_DUALHPIA_MASK))


/*----------------------------------------------------------------*\
*   (RW)  _HPI_HPIC_HPIASEL:	
\*----------------------------------------------------------------*/

#define _HPI_HPIC_HPIASEL_SHIFT		(0x000bu)
#define _HPI_HPIC_HPIASEL_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HPIC_HPIASEL_SHIFT)
#define _HPI_HPIC_HPIASEL_MASK		(_HPI_HPIC_HPIASEL_MK(0x0001u))
#define _HPI_HPIC_HPIASEL_CLR		(~(_HPI_HPIC_HPIASEL_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the XHPIAR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _HPI_XHPIAR	 - Note: Add description here
*
* Fields:
*	(RW)   _HPI_XHPIAR_XHPIAR	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _HPI_XHPIAR_XHPIAR:	
\*----------------------------------------------------------------*/

#define _HPI_XHPIAR_XHPIAR_SHIFT		(000000u)
#define _HPI_XHPIAR_XHPIAR_MK(n)		(((Uint16)(n) & 0xffffu) << _HPI_XHPIAR_XHPIAR_SHIFT)
#define _HPI_XHPIAR_XHPIAR_MASK		(_HPI_XHPIAR_XHPIAR_MK(0xffffu))
#define _HPI_XHPIAR_XHPIAR_CLR		(~(_HPI_XHPIAR_XHPIAR_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the HPIAW register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _HPI_HPIAW	 - Note: Add description here
*
* Fields:
*	(RW)   _HPI_HPIAW_HPIAW	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _HPI_HPIAW_HPIAW:	
\*----------------------------------------------------------------*/

#define _HPI_HPIAW_HPIAW_SHIFT		(000000u)
#define _HPI_HPIAW_HPIAW_MK(n)		(((Uint16)(n) & 0xffffu) << _HPI_HPIAW_HPIAW_SHIFT)
#define _HPI_HPIAW_HPIAW_MASK		(_HPI_HPIAW_HPIAW_MK(0xffffu))
#define _HPI_HPIAW_HPIAW_CLR		(~(_HPI_HPIAW_HPIAW_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the PWREMU register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _HPI_HPWREMU	 - Note: Add description here
*
* Fields:
*	(RW)   _HPI_HPWREMU_FREE	
*	(RW)   _HPI_HPWREMU_SOFT	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _HPI_HPWREMU_FREE:	
\*----------------------------------------------------------------*/

#define _HPI_HPWREMU_FREE_SHIFT		(000000u)
#define _HPI_HPWREMU_FREE_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HPWREMU_FREE_SHIFT)
#define _HPI_HPWREMU_FREE_MASK		(_HPI_HPWREMU_FREE_MK(0x0001u))
#define _HPI_HPWREMU_FREE_CLR		(~(_HPI_HPWREMU_FREE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HPWREMU_SOFT:	
\*----------------------------------------------------------------*/

#define _HPI_HPWREMU_SOFT_SHIFT		(0x0001u)
#define _HPI_HPWREMU_SOFT_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HPWREMU_SOFT_SHIFT)
#define _HPI_HPWREMU_SOFT_MASK		(_HPI_HPWREMU_SOFT_MK(0x0001u))
#define _HPI_HPWREMU_SOFT_CLR		(~(_HPI_HPWREMU_SOFT_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the XHPIAW register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _HPI_XHPIAW	 - Note: Add description here
*
* Fields:
*	(RW)   _HPI_XHPIAW_XHPIAW	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _HPI_XHPIAW_XHPIAW:	
\*----------------------------------------------------------------*/

#define _HPI_XHPIAW_XHPIAW_SHIFT		(000000u)
#define _HPI_XHPIAW_XHPIAW_MK(n)		(((Uint16)(n) & 0xffffu) << _HPI_XHPIAW_XHPIAW_SHIFT)
#define _HPI_XHPIAW_XHPIAW_MASK		(_HPI_XHPIAW_XHPIAW_MK(0xffffu))
#define _HPI_XHPIAW_XHPIAW_CLR		(~(_HPI_XHPIAW_XHPIAW_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the HGPIOEN register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _HPI_HGPIOEN	 - Note: Add description here
*
* Fields:
*	(RW)   _HPI_HGPIOEN_EN0	
*	(RW)   _HPI_HGPIOEN_EN1	
*	(RW)   _HPI_HGPIOEN_EN2	
*	(RW)   _HPI_HGPIOEN_EN4	
*	(RW)   _HPI_HGPIOEN_EN5	
*	(RW)   _HPI_HGPIOEN_EN6	
*	(RW)   _HPI_HGPIOEN_EN7	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIOEN_EN0:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIOEN_EN0_SHIFT		(000000u)
#define _HPI_HGPIOEN_EN0_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIOEN_EN0_SHIFT)
#define _HPI_HGPIOEN_EN0_MASK		(_HPI_HGPIOEN_EN0_MK(0x0001u))
#define _HPI_HGPIOEN_EN0_CLR		(~(_HPI_HGPIOEN_EN0_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIOEN_EN1:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIOEN_EN1_SHIFT		(0x0001u)
#define _HPI_HGPIOEN_EN1_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIOEN_EN1_SHIFT)
#define _HPI_HGPIOEN_EN1_MASK		(_HPI_HGPIOEN_EN1_MK(0x0001u))
#define _HPI_HGPIOEN_EN1_CLR		(~(_HPI_HGPIOEN_EN1_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIOEN_EN2:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIOEN_EN2_SHIFT		(0x0002u)
#define _HPI_HGPIOEN_EN2_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIOEN_EN2_SHIFT)
#define _HPI_HGPIOEN_EN2_MASK		(_HPI_HGPIOEN_EN2_MK(0x0001u))
#define _HPI_HGPIOEN_EN2_CLR		(~(_HPI_HGPIOEN_EN2_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIOEN_EN4:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIOEN_EN4_SHIFT		(0x0004u)
#define _HPI_HGPIOEN_EN4_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIOEN_EN4_SHIFT)
#define _HPI_HGPIOEN_EN4_MASK		(_HPI_HGPIOEN_EN4_MK(0x0001u))
#define _HPI_HGPIOEN_EN4_CLR		(~(_HPI_HGPIOEN_EN4_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIOEN_EN5:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIOEN_EN5_SHIFT		(0x0005u)
#define _HPI_HGPIOEN_EN5_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIOEN_EN5_SHIFT)
#define _HPI_HGPIOEN_EN5_MASK		(_HPI_HGPIOEN_EN5_MK(0x0001u))
#define _HPI_HGPIOEN_EN5_CLR		(~(_HPI_HGPIOEN_EN5_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIOEN_EN6:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIOEN_EN6_SHIFT		(0x0006u)
#define _HPI_HGPIOEN_EN6_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIOEN_EN6_SHIFT)
#define _HPI_HGPIOEN_EN6_MASK		(_HPI_HGPIOEN_EN6_MK(0x0001u))
#define _HPI_HGPIOEN_EN6_CLR		(~(_HPI_HGPIOEN_EN6_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIOEN_EN7:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIOEN_EN7_SHIFT		(0x0007u)
#define _HPI_HGPIOEN_EN7_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIOEN_EN7_SHIFT)
#define _HPI_HGPIOEN_EN7_MASK		(_HPI_HGPIOEN_EN7_MK(0x0001u))
#define _HPI_HGPIOEN_EN7_CLR		(~(_HPI_HGPIOEN_EN7_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the PIDLSW register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _HPI_PIDLSW	 - Note: Add description here
*
* Fields:
*	(R)   _HPI_PIDLSW_REV	
*	(R)   _HPI_PIDLSW_CLASS	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _HPI_PIDLSW_REV:	
\*----------------------------------------------------------------*/

#define _HPI_PIDLSW_REV_SHIFT		(000000u)
#define _HPI_PIDLSW_REV_MK(n)		(((Uint16)(n) & 0x00ffu) << _HPI_PIDLSW_REV_SHIFT)
#define _HPI_PIDLSW_REV_MASK		(_HPI_PIDLSW_REV_MK(0x00ffu))
#define _HPI_PIDLSW_REV_CLR		(~(_HPI_PIDLSW_REV_MASK))



/*----------------------------------------------------------------*\
*   (R)  _HPI_PIDLSW_CLASS:	
\*----------------------------------------------------------------*/

#define _HPI_PIDLSW_CLASS_SHIFT		(0x0008u)
#define _HPI_PIDLSW_CLASS_MK(n)		(((Uint16)(n) & 0x00ffu) << _HPI_PIDLSW_CLASS_SHIFT)
#define _HPI_PIDLSW_CLASS_MASK		(_HPI_PIDLSW_CLASS_MK(0x00ffu))
#define _HPI_PIDLSW_CLASS_CLR		(~(_HPI_PIDLSW_CLASS_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the HGPIODIR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _HPI_HGPIODIR	 - Note: Add description here
*
* Fields:
*	(RW)   _HPI_HGPIODIR_HD0	
*	(RW)   _HPI_HGPIODIR_HD1	
*	(RW)   _HPI_HGPIODIR_HD2	
*	(RW)   _HPI_HGPIODIR_HD3	
*	(RW)   _HPI_HGPIODIR_HD4	
*	(RW)   _HPI_HGPIODIR_HD5	
*	(RW)   _HPI_HGPIODIR_HD6	
*	(RW)   _HPI_HGPIODIR_HD7
*	(RW)   _HPI_HGPIODIR_HD8	
*	(RW)   _HPI_HGPIODIR_HD9	
*	(RW)   _HPI_HGPIODIR_HD10	
*	(RW)   _HPI_HGPIODIR_HD11	
*	(RW)   _HPI_HGPIODIR_HD12	
*	(RW)   _HPI_HGPIODIR_HD13	
*	(RW)   _HPI_HGPIODIR_HD14	
*	(RW)   _HPI_HGPIODIR_HD15	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR_HD0:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR_HD0_SHIFT		(000000u)
#define _HPI_HGPIODIR_HD0_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR_HD0_SHIFT)
#define _HPI_HGPIODIR_HD0_MASK		(_HPI_HGPIODIR_HD0_MK(0x0001u))
#define _HPI_HGPIODIR_HD0_CLR		(~(_HPI_HGPIODIR_HD0_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR_HD1:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR_HD1_SHIFT		(0x0001u)
#define _HPI_HGPIODIR_HD1_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR_HD1_SHIFT)
#define _HPI_HGPIODIR_HD1_MASK		(_HPI_HGPIODIR_HD1_MK(0x0001u))
#define _HPI_HGPIODIR_HD1_CLR		(~(_HPI_HGPIODIR_HD1_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR_HD2:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR_HD2_SHIFT		(0x0002u)
#define _HPI_HGPIODIR_HD2_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR_HD2_SHIFT)
#define _HPI_HGPIODIR_HD2_MASK		(_HPI_HGPIODIR_HD2_MK(0x0001u))
#define _HPI_HGPIODIR_HD2_CLR		(~(_HPI_HGPIODIR_HD2_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR_HD3:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR_HD3_SHIFT		(0x0003u)
#define _HPI_HGPIODIR_HD3_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR_HD3_SHIFT)
#define _HPI_HGPIODIR_HD3_MASK		(_HPI_HGPIODIR_HD3_MK(0x0001u))
#define _HPI_HGPIODIR_HD3_CLR		(~(_HPI_HGPIODIR_HD3_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR_HD4:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR_HD4_SHIFT		(0x0004u)
#define _HPI_HGPIODIR_HD4_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR_HD4_SHIFT)
#define _HPI_HGPIODIR_HD4_MASK		(_HPI_HGPIODIR_HD4_MK(0x0001u))
#define _HPI_HGPIODIR_HD4_CLR		(~(_HPI_HGPIODIR_HD4_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR_HD5:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR_HD5_SHIFT		(0x0005u)
#define _HPI_HGPIODIR_HD5_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR_HD5_SHIFT)
#define _HPI_HGPIODIR_HD5_MASK		(_HPI_HGPIODIR_HD5_MK(0x0001u))
#define _HPI_HGPIODIR_HD5_CLR		(~(_HPI_HGPIODIR_HD5_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR_HD6:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR_HD6_SHIFT		(0x0006u)
#define _HPI_HGPIODIR_HD6_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR_HD6_SHIFT)
#define _HPI_HGPIODIR_HD6_MASK		(_HPI_HGPIODIR_HD6_MK(0x0001u))
#define _HPI_HGPIODIR_HD6_CLR		(~(_HPI_HGPIODIR_HD6_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR_HD7:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR_HD7_SHIFT		(0x0007u)
#define _HPI_HGPIODIR_HD7_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR_HD7_SHIFT)
#define _HPI_HGPIODIR_HD7_MASK		(_HPI_HGPIODIR_HD7_MK(0x0001u))
#define _HPI_HGPIODIR_HD7_CLR		(~(_HPI_HGPIODIR_HD7_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR_HD8:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR_HD8_SHIFT		(0x0008u)
#define _HPI_HGPIODIR_HD8_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR_HD8_SHIFT)
#define _HPI_HGPIODIR_HD8_MASK		(_HPI_HGPIODIR_HD8_MK(0x0001u))
#define _HPI_HGPIODIR_HD8_CLR		(~(_HPI_HGPIODIR_HD8_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR_HD9:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR_HD9_SHIFT		(0x0009u)
#define _HPI_HGPIODIR_HD9_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR_HD9_SHIFT)
#define _HPI_HGPIODIR_HD9_MASK		(_HPI_HGPIODIR_HD9_MK(0x0001u))
#define _HPI_HGPIODIR_HD9_CLR		(~(_HPI_HGPIODIR_HD9_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR_HD10:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR_HD10_SHIFT		(0x000Au)
#define _HPI_HGPIODIR_HD10_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR_HD10_SHIFT)
#define _HPI_HGPIODIR_HD10_MASK		(_HPI_HGPIODIR_HD10_MK(0x0001u))
#define _HPI_HGPIODIR_HD10_CLR		(~(_HPI_HGPIODIR_HD10_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR_HD11:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR_HD11_SHIFT		(0x000Bu)
#define _HPI_HGPIODIR_HD11_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR_HD11_SHIFT)
#define _HPI_HGPIODIR_HD11_MASK		(_HPI_HGPIODIR_HD11_MK(0x0001u))
#define _HPI_HGPIODIR_HD11_CLR		(~(_HPI_HGPIODIR_HD11_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR_HD12:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR_HD12_SHIFT		(0x000Cu)
#define _HPI_HGPIODIR_HD12_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR_HD12_SHIFT)
#define _HPI_HGPIODIR_HD12_MASK		(_HPI_HGPIODIR_HD12_MK(0x0001u))
#define _HPI_HGPIODIR_HD12_CLR		(~(_HPI_HGPIODIR_HD12_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR_HD13:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR_HD13_SHIFT		(0x000Du)
#define _HPI_HGPIODIR_HD13_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR_HD13_SHIFT)
#define _HPI_HGPIODIR_HD13_MASK		(_HPI_HGPIODIR_HD13_MK(0x0001u))
#define _HPI_HGPIODIR_HD13_CLR		(~(_HPI_HGPIODIR_HD13_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR_HD14:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR_HD14_SHIFT		(0x000Eu)
#define _HPI_HGPIODIR_HD14_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR_HD14_SHIFT)
#define _HPI_HGPIODIR_HD14_MASK		(_HPI_HGPIODIR_HD14_MK(0x0001u))
#define _HPI_HGPIODIR_HD14_CLR		(~(_HPI_HGPIODIR_HD14_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR_HD15:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR_HD15_SHIFT		(0x000Fu)
#define _HPI_HGPIODIR_HD15_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR_HD15_SHIFT)
#define _HPI_HGPIODIR_HD15_MASK		(_HPI_HGPIODIR_HD15_MK(0x0001u))
#define _HPI_HGPIODIR_HD15_CLR		(~(_HPI_HGPIODIR_HD15_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the HGPIODIR1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _HPI_HGPIODIR1	 - Note: Add description here
*
* Fields:
*	(RW)   _HPI_HGPIODIR1_HD0	
*	(RW)   _HPI_HGPIODIR1_HD1	
*	(RW)   _HPI_HGPIODIR1_HD2	
*	(RW)   _HPI_HGPIODIR1_HD3	
*	(RW)   _HPI_HGPIODIR1_HD4	
*	(RW)   _HPI_HGPIODIR1_HD5	
*	(RW)   _HPI_HGPIODIR1_HD6	
*	(RW)   _HPI_HGPIODIR1_HD7
*	(RW)   _HPI_HGPIODIR1_HD8	
*	(RW)   _HPI_HGPIODIR1_HD9	
*	(RW)   _HPI_HGPIODIR1_HD10	
*	(RW)   _HPI_HGPIODIR1_HD11	
*	(RW)   _HPI_HGPIODIR1_HD12	
*	(RW)   _HPI_HGPIODIR1_HD13	
*	(RW)   _HPI_HGPIODIR1_HD14	
*	(RW)   _HPI_HGPIODIR1_HD15	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR1_HD0:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR1_HD0_SHIFT		(000000u)
#define _HPI_HGPIODIR1_HD0_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR1_HD0_SHIFT)
#define _HPI_HGPIODIR1_HD0_MASK		(_HPI_HGPIODIR1_HD0_MK(0x0001u))
#define _HPI_HGPIODIR1_HD0_CLR		(~(_HPI_HGPIODIR1_HD0_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR1_HD1:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR1_HD1_SHIFT		(0x0001u)
#define _HPI_HGPIODIR1_HD1_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR1_HD1_SHIFT)
#define _HPI_HGPIODIR1_HD1_MASK		(_HPI_HGPIODIR1_HD1_MK(0x0001u))
#define _HPI_HGPIODIR1_HD1_CLR		(~(_HPI_HGPIODIR1_HD1_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR1_HD2:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR1_HD2_SHIFT		(0x0002u)
#define _HPI_HGPIODIR1_HD2_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR1_HD2_SHIFT)
#define _HPI_HGPIODIR1_HD2_MASK		(_HPI_HGPIODIR1_HD2_MK(0x0001u))
#define _HPI_HGPIODIR1_HD2_CLR		(~(_HPI_HGPIODIR1_HD2_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR1_HD3:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR1_HD3_SHIFT		(0x0003u)
#define _HPI_HGPIODIR1_HD3_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR1_HD3_SHIFT)
#define _HPI_HGPIODIR1_HD3_MASK		(_HPI_HGPIODIR1_HD3_MK(0x0001u))
#define _HPI_HGPIODIR1_HD3_CLR		(~(_HPI_HGPIODIR1_HD3_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR1_HD4:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR1_HD4_SHIFT		(0x0004u)
#define _HPI_HGPIODIR1_HD4_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR1_HD4_SHIFT)
#define _HPI_HGPIODIR1_HD4_MASK		(_HPI_HGPIODIR1_HD4_MK(0x0001u))
#define _HPI_HGPIODIR1_HD4_CLR		(~(_HPI_HGPIODIR1_HD4_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR1_HD5:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR1_HD5_SHIFT		(0x0005u)
#define _HPI_HGPIODIR1_HD5_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR1_HD5_SHIFT)
#define _HPI_HGPIODIR1_HD5_MASK		(_HPI_HGPIODIR1_HD5_MK(0x0001u))
#define _HPI_HGPIODIR1_HD5_CLR		(~(_HPI_HGPIODIR1_HD5_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR1_HD6:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR1_HD6_SHIFT		(0x0006u)
#define _HPI_HGPIODIR1_HD6_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR1_HD6_SHIFT)
#define _HPI_HGPIODIR1_HD6_MASK		(_HPI_HGPIODIR1_HD6_MK(0x0001u))
#define _HPI_HGPIODIR1_HD6_CLR		(~(_HPI_HGPIODIR1_HD6_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR1_HD7:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR1_HD7_SHIFT		(0x0007u)
#define _HPI_HGPIODIR1_HD7_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR1_HD7_SHIFT)
#define _HPI_HGPIODIR1_HD7_MASK		(_HPI_HGPIODIR1_HD7_MK(0x0001u))
#define _HPI_HGPIODIR1_HD7_CLR		(~(_HPI_HGPIODIR1_HD7_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR1_HD8:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR1_HD8_SHIFT		(0x0008u)
#define _HPI_HGPIODIR1_HD8_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR1_HD8_SHIFT)
#define _HPI_HGPIODIR1_HD8_MASK		(_HPI_HGPIODIR1_HD8_MK(0x0001u))
#define _HPI_HGPIODIR1_HD8_CLR		(~(_HPI_HGPIODIR1_HD8_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR1_HD9:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR1_HD9_SHIFT		(0x0009u)
#define _HPI_HGPIODIR1_HD9_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR1_HD9_SHIFT)
#define _HPI_HGPIODIR1_HD9_MASK		(_HPI_HGPIODIR1_HD9_MK(0x0001u))
#define _HPI_HGPIODIR1_HD9_CLR		(~(_HPI_HGPIODIR1_HD9_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR1_HD10:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR1_HD10_SHIFT		(0x000Au)
#define _HPI_HGPIODIR1_HD10_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR1_HD10_SHIFT)
#define _HPI_HGPIODIR1_HD10_MASK		(_HPI_HGPIODIR1_HD10_MK(0x0001u))
#define _HPI_HGPIODIR1_HD10_CLR		(~(_HPI_HGPIODIR1_HD10_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR1_HD11:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR1_HD11_SHIFT		(0x000Bu)
#define _HPI_HGPIODIR1_HD11_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR1_HD11_SHIFT)
#define _HPI_HGPIODIR1_HD11_MASK		(_HPI_HGPIODIR1_HD11_MK(0x0001u))
#define _HPI_HGPIODIR1_HD11_CLR		(~(_HPI_HGPIODIR1_HD11_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR1_HD12:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR1_HD12_SHIFT		(0x000Cu)
#define _HPI_HGPIODIR1_HD12_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR1_HD12_SHIFT)
#define _HPI_HGPIODIR1_HD12_MASK		(_HPI_HGPIODIR1_HD12_MK(0x0001u))
#define _HPI_HGPIODIR1_HD12_CLR		(~(_HPI_HGPIODIR1_HD12_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR1_HD13:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR1_HD13_SHIFT		(0x000Du)
#define _HPI_HGPIODIR1_HD13_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR1_HD13_SHIFT)
#define _HPI_HGPIODIR1_HD13_MASK		(_HPI_HGPIODIR1_HD13_MK(0x0001u))
#define _HPI_HGPIODIR1_HD13_CLR		(~(_HPI_HGPIODIR1_HD13_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR1_HD14:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR1_HD14_SHIFT		(0x000Eu)
#define _HPI_HGPIODIR1_HD14_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR1_HD14_SHIFT)
#define _HPI_HGPIODIR1_HD14_MASK		(_HPI_HGPIODIR1_HD14_MK(0x0001u))
#define _HPI_HGPIODIR1_HD14_CLR		(~(_HPI_HGPIODIR1_HD14_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR1_HD15:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR1_HD15_SHIFT		(0x000Fu)
#define _HPI_HGPIODIR1_HD15_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR1_HD15_SHIFT)
#define _HPI_HGPIODIR1_HD15_MASK		(_HPI_HGPIODIR1_HD15_MK(0x0001u))
#define _HPI_HGPIODIR1_HD15_CLR		(~(_HPI_HGPIODIR1_HD15_MASK))




/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the HGPIODIR2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _HPI_HGPIODIR2	 - Note: Add description here
*
* Fields:
*	(RW)   _HPI_HGPIODIR2_HD0	
*	(RW)   _HPI_HGPIODIR2_HD1	
*	(RW)   _HPI_HGPIODIR2_HD2	
*	(RW)   _HPI_HGPIODIR2_HD3	
*	(RW)   _HPI_HGPIODIR2_HD4	
*	(RW)   _HPI_HGPIODIR2_HD5	
*	(RW)   _HPI_HGPIODIR2_HD6	
*	(RW)   _HPI_HGPIODIR2_HD7
*	(RW)   _HPI_HGPIODIR2_HD8	
*	(RW)   _HPI_HGPIODIR2_HD9	
*	(RW)   _HPI_HGPIODIR2_HD10	
*	(RW)   _HPI_HGPIODIR2_HD11	
*	(RW)   _HPI_HGPIODIR2_HD12	
*	(RW)   _HPI_HGPIODIR2_HD13	
*	(RW)   _HPI_HGPIODIR2_HD14	
*	(RW)   _HPI_HGPIODIR2_HD15	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR2_HD0:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR2_HD0_SHIFT		(000000u)
#define _HPI_HGPIODIR2_HD0_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR2_HD0_SHIFT)
#define _HPI_HGPIODIR2_HD0_MASK		(_HPI_HGPIODIR2_HD0_MK(0x0001u))
#define _HPI_HGPIODIR2_HD0_CLR		(~(_HPI_HGPIODIR2_HD0_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR2_HD1:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR2_HD1_SHIFT		(0x0001u)
#define _HPI_HGPIODIR2_HD1_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR2_HD1_SHIFT)
#define _HPI_HGPIODIR2_HD1_MASK		(_HPI_HGPIODIR2_HD1_MK(0x0001u))
#define _HPI_HGPIODIR2_HD1_CLR		(~(_HPI_HGPIODIR2_HD1_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR2_HD2:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR2_HD2_SHIFT		(0x0002u)
#define _HPI_HGPIODIR2_HD2_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR2_HD2_SHIFT)
#define _HPI_HGPIODIR2_HD2_MASK		(_HPI_HGPIODIR2_HD2_MK(0x0001u))
#define _HPI_HGPIODIR2_HD2_CLR		(~(_HPI_HGPIODIR2_HD2_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR2_HD3:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR2_HD3_SHIFT		(0x0003u)
#define _HPI_HGPIODIR2_HD3_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR2_HD3_SHIFT)
#define _HPI_HGPIODIR2_HD3_MASK		(_HPI_HGPIODIR2_HD3_MK(0x0001u))
#define _HPI_HGPIODIR2_HD3_CLR		(~(_HPI_HGPIODIR2_HD3_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR2_HD4:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR2_HD4_SHIFT		(0x0004u)
#define _HPI_HGPIODIR2_HD4_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR2_HD4_SHIFT)
#define _HPI_HGPIODIR2_HD4_MASK		(_HPI_HGPIODIR2_HD4_MK(0x0001u))
#define _HPI_HGPIODIR2_HD4_CLR		(~(_HPI_HGPIODIR2_HD4_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR2_HD5:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR2_HD5_SHIFT		(0x0005u)
#define _HPI_HGPIODIR2_HD5_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR2_HD5_SHIFT)
#define _HPI_HGPIODIR2_HD5_MASK		(_HPI_HGPIODIR2_HD5_MK(0x0001u))
#define _HPI_HGPIODIR2_HD5_CLR		(~(_HPI_HGPIODIR2_HD5_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR2_HD6:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR2_HD6_SHIFT		(0x0006u)
#define _HPI_HGPIODIR2_HD6_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR2_HD6_SHIFT)
#define _HPI_HGPIODIR2_HD6_MASK		(_HPI_HGPIODIR2_HD6_MK(0x0001u))
#define _HPI_HGPIODIR2_HD6_CLR		(~(_HPI_HGPIODIR2_HD6_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR2_HD7:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR2_HD7_SHIFT		(0x0007u)
#define _HPI_HGPIODIR2_HD7_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR2_HD7_SHIFT)
#define _HPI_HGPIODIR2_HD7_MASK		(_HPI_HGPIODIR2_HD7_MK(0x0001u))
#define _HPI_HGPIODIR2_HD7_CLR		(~(_HPI_HGPIODIR2_HD7_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR2_HD8:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR2_HD8_SHIFT		(0x0008u)
#define _HPI_HGPIODIR2_HD8_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR2_HD8_SHIFT)
#define _HPI_HGPIODIR2_HD8_MASK		(_HPI_HGPIODIR2_HD8_MK(0x0001u))
#define _HPI_HGPIODIR2_HD8_CLR		(~(_HPI_HGPIODIR2_HD8_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR2_HD9:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR2_HD9_SHIFT		(0x0009u)
#define _HPI_HGPIODIR2_HD9_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR2_HD9_SHIFT)
#define _HPI_HGPIODIR2_HD9_MASK		(_HPI_HGPIODIR2_HD9_MK(0x0001u))
#define _HPI_HGPIODIR2_HD9_CLR		(~(_HPI_HGPIODIR2_HD9_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR2_HD10:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR2_HD10_SHIFT		(0x000Au)
#define _HPI_HGPIODIR2_HD10_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR2_HD10_SHIFT)
#define _HPI_HGPIODIR2_HD10_MASK		(_HPI_HGPIODIR2_HD10_MK(0x0001u))
#define _HPI_HGPIODIR2_HD10_CLR		(~(_HPI_HGPIODIR2_HD10_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR2_HD11:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR2_HD11_SHIFT		(0x000Bu)
#define _HPI_HGPIODIR2_HD11_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR2_HD11_SHIFT)
#define _HPI_HGPIODIR2_HD11_MASK		(_HPI_HGPIODIR2_HD11_MK(0x0001u))
#define _HPI_HGPIODIR2_HD11_CLR		(~(_HPI_HGPIODIR2_HD11_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR2_HD12:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR2_HD12_SHIFT		(0x000Cu)
#define _HPI_HGPIODIR2_HD12_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR2_HD12_SHIFT)
#define _HPI_HGPIODIR2_HD12_MASK		(_HPI_HGPIODIR2_HD12_MK(0x0001u))
#define _HPI_HGPIODIR2_HD12_CLR		(~(_HPI_HGPIODIR2_HD12_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR2_HD13:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR2_HD13_SHIFT		(0x000Du)
#define _HPI_HGPIODIR2_HD13_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR2_HD13_SHIFT)
#define _HPI_HGPIODIR2_HD13_MASK		(_HPI_HGPIODIR2_HD13_MK(0x0001u))
#define _HPI_HGPIODIR2_HD13_CLR		(~(_HPI_HGPIODIR2_HD13_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR2_HD14:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR2_HD14_SHIFT		(0x000Eu)
#define _HPI_HGPIODIR2_HD14_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR2_HD14_SHIFT)
#define _HPI_HGPIODIR2_HD14_MASK		(_HPI_HGPIODIR2_HD14_MK(0x0001u))
#define _HPI_HGPIODIR2_HD14_CLR		(~(_HPI_HGPIODIR2_HD14_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR2_HD15:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR2_HD15_SHIFT		(0x000Fu)
#define _HPI_HGPIODIR2_HD15_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR2_HD15_SHIFT)
#define _HPI_HGPIODIR2_HD15_MASK		(_HPI_HGPIODIR2_HD15_MK(0x0001u))
#define _HPI_HGPIODIR2_HD15_CLR		(~(_HPI_HGPIODIR2_HD15_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the HGPIODIR3 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _HPI_HGPIODIR3	 - Note: Add description here
*
* Fields:
*	(RW)   _HPI_HGPIODIR3_HD0	
*	(RW)   _HPI_HGPIODIR3_HD1	
*	(RW)   _HPI_HGPIODIR3_HD2	
*	(RW)   _HPI_HGPIODIR3_HD3	
*	(RW)   _HPI_HGPIODIR3_HD4	
*	(RW)   _HPI_HGPIODIR3_HD5	
*	(RW)   _HPI_HGPIODIR3_HD6	
*	(RW)   _HPI_HGPIODIR3_HD7
*	(RW)   _HPI_HGPIODIR3_HD8	
*	(RW)   _HPI_HGPIODIR3_HD9	
*	(RW)   _HPI_HGPIODIR3_HD10	
*	(RW)   _HPI_HGPIODIR3_HD11	
*	(RW)   _HPI_HGPIODIR3_HD12	
*	(RW)   _HPI_HGPIODIR3_HD13	
*	(RW)   _HPI_HGPIODIR3_HD14	
*	(RW)   _HPI_HGPIODIR3_HD15	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR3_HD0:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR3_HD0_SHIFT		(000000u)
#define _HPI_HGPIODIR3_HD0_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR3_HD0_SHIFT)
#define _HPI_HGPIODIR3_HD0_MASK		(_HPI_HGPIODIR3_HD0_MK(0x0001u))
#define _HPI_HGPIODIR3_HD0_CLR		(~(_HPI_HGPIODIR3_HD0_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR3_HD1:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR3_HD1_SHIFT		(0x0001u)
#define _HPI_HGPIODIR3_HD1_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR3_HD1_SHIFT)
#define _HPI_HGPIODIR3_HD1_MASK		(_HPI_HGPIODIR3_HD1_MK(0x0001u))
#define _HPI_HGPIODIR3_HD1_CLR		(~(_HPI_HGPIODIR3_HD1_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR3_HD2:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR3_HD2_SHIFT		(0x0002u)
#define _HPI_HGPIODIR3_HD2_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR3_HD2_SHIFT)
#define _HPI_HGPIODIR3_HD2_MASK		(_HPI_HGPIODIR3_HD2_MK(0x0001u))
#define _HPI_HGPIODIR3_HD2_CLR		(~(_HPI_HGPIODIR3_HD2_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR3_HD3:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR3_HD3_SHIFT		(0x0003u)
#define _HPI_HGPIODIR3_HD3_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR3_HD3_SHIFT)
#define _HPI_HGPIODIR3_HD3_MASK		(_HPI_HGPIODIR3_HD3_MK(0x0001u))
#define _HPI_HGPIODIR3_HD3_CLR		(~(_HPI_HGPIODIR3_HD3_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR3_HD4:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR3_HD4_SHIFT		(0x0004u)
#define _HPI_HGPIODIR3_HD4_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR3_HD4_SHIFT)
#define _HPI_HGPIODIR3_HD4_MASK		(_HPI_HGPIODIR3_HD4_MK(0x0001u))
#define _HPI_HGPIODIR3_HD4_CLR		(~(_HPI_HGPIODIR3_HD4_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR3_HD5:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR3_HD5_SHIFT		(0x0005u)
#define _HPI_HGPIODIR3_HD5_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR3_HD5_SHIFT)
#define _HPI_HGPIODIR3_HD5_MASK		(_HPI_HGPIODIR3_HD5_MK(0x0001u))
#define _HPI_HGPIODIR3_HD5_CLR		(~(_HPI_HGPIODIR3_HD5_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR3_HD6:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR3_HD6_SHIFT		(0x0006u)
#define _HPI_HGPIODIR3_HD6_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR3_HD6_SHIFT)
#define _HPI_HGPIODIR3_HD6_MASK		(_HPI_HGPIODIR3_HD6_MK(0x0001u))
#define _HPI_HGPIODIR3_HD6_CLR		(~(_HPI_HGPIODIR3_HD6_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR3_HD7:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR3_HD7_SHIFT		(0x0007u)
#define _HPI_HGPIODIR3_HD7_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR3_HD7_SHIFT)
#define _HPI_HGPIODIR3_HD7_MASK		(_HPI_HGPIODIR3_HD7_MK(0x0001u))
#define _HPI_HGPIODIR3_HD7_CLR		(~(_HPI_HGPIODIR3_HD7_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR3_HD8:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR3_HD8_SHIFT		(0x0008u)
#define _HPI_HGPIODIR3_HD8_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR3_HD8_SHIFT)
#define _HPI_HGPIODIR3_HD8_MASK		(_HPI_HGPIODIR3_HD8_MK(0x0001u))
#define _HPI_HGPIODIR3_HD8_CLR		(~(_HPI_HGPIODIR3_HD8_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR3_HD9:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR3_HD9_SHIFT		(0x0009u)
#define _HPI_HGPIODIR3_HD9_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR3_HD9_SHIFT)
#define _HPI_HGPIODIR3_HD9_MASK		(_HPI_HGPIODIR3_HD9_MK(0x0001u))
#define _HPI_HGPIODIR3_HD9_CLR		(~(_HPI_HGPIODIR3_HD9_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR3_HD10:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR3_HD10_SHIFT		(0x000Au)
#define _HPI_HGPIODIR3_HD10_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR3_HD10_SHIFT)
#define _HPI_HGPIODIR3_HD10_MASK		(_HPI_HGPIODIR3_HD10_MK(0x0001u))
#define _HPI_HGPIODIR3_HD10_CLR		(~(_HPI_HGPIODIR3_HD10_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR3_HD11:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR3_HD11_SHIFT		(0x000Bu)
#define _HPI_HGPIODIR3_HD11_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR3_HD11_SHIFT)
#define _HPI_HGPIODIR3_HD11_MASK		(_HPI_HGPIODIR3_HD11_MK(0x0001u))
#define _HPI_HGPIODIR3_HD11_CLR		(~(_HPI_HGPIODIR3_HD11_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR3_HD12:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR3_HD12_SHIFT		(0x000Cu)
#define _HPI_HGPIODIR3_HD12_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR3_HD12_SHIFT)
#define _HPI_HGPIODIR3_HD12_MASK		(_HPI_HGPIODIR3_HD12_MK(0x0001u))
#define _HPI_HGPIODIR3_HD12_CLR		(~(_HPI_HGPIODIR3_HD12_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR3_HD13:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR3_HD13_SHIFT		(0x000Du)
#define _HPI_HGPIODIR3_HD13_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR3_HD13_SHIFT)
#define _HPI_HGPIODIR3_HD13_MASK		(_HPI_HGPIODIR3_HD13_MK(0x0001u))
#define _HPI_HGPIODIR3_HD13_CLR		(~(_HPI_HGPIODIR3_HD13_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR3_HD14:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR3_HD14_SHIFT		(0x000Eu)
#define _HPI_HGPIODIR3_HD14_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR3_HD14_SHIFT)
#define _HPI_HGPIODIR3_HD14_MASK		(_HPI_HGPIODIR3_HD14_MK(0x0001u))
#define _HPI_HGPIODIR3_HD14_CLR		(~(_HPI_HGPIODIR3_HD14_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODIR3_HD15:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODIR3_HD15_SHIFT		(0x000Fu)
#define _HPI_HGPIODIR3_HD15_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODIR3_HD15_SHIFT)
#define _HPI_HGPIODIR3_HD15_MASK		(_HPI_HGPIODIR3_HD15_MK(0x0001u))
#define _HPI_HGPIODIR3_HD15_CLR		(~(_HPI_HGPIODIR3_HD15_MASK))




   
   
/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the PIDMSW register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _HPI_PIDMSW	 - Note: Add description here
*
* Fields:
*	(R)   _HPI_PIDMSW_TYPE	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _HPI_PIDMSW_TYPE:	
\*----------------------------------------------------------------*/

#define _HPI_PIDMSW_TYPE_SHIFT		(000000u)
#define _HPI_PIDMSW_TYPE_MK(n)		(((Uint16)(n) & 0x00ffu) << _HPI_PIDMSW_TYPE_SHIFT)
#define _HPI_PIDMSW_TYPE_MASK		(_HPI_PIDMSW_TYPE_MK(0x00ffu))
#define _HPI_PIDMSW_TYPE_CLR		(~(_HPI_PIDMSW_TYPE_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the HGPIODAT register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _HPI_HGPIODAT	 - Note: Add description here
*
* Fields:
*	(RW)   _HPI_HGPIODAT_HD0	
*	(RW)   _HPI_HGPIODAT_HD1	
*	(RW)   _HPI_HGPIODAT_HD2	
*	(RW)   _HPI_HGPIODAT_HD3	
*	(RW)   _HPI_HGPIODAT_HD4	
*	(RW)   _HPI_HGPIODAT_HD5	
*	(RW)   _HPI_HGPIODAT_HD6	
*	(RW)   _HPI_HGPIODAT_HD7
*	(RW)   _HPI_HGPIODAT_HD8	
*	(RW)   _HPI_HGPIODAT_HD9	
*	(RW)   _HPI_HGPIODAT_HD10	
*	(RW)   _HPI_HGPIODAT_HD11	
*	(RW)   _HPI_HGPIODAT_HD12	
*	(RW)   _HPI_HGPIODAT_HD13	
*	(RW)   _HPI_HGPIODAT_HD14	
*	(RW)   _HPI_HGPIODAT_HD15	
*
\******************************************************************************/


/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT_HD0:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT_HD0_SHIFT		(000000u)
#define _HPI_HGPIODAT_HD0_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT_HD0_SHIFT)
#define _HPI_HGPIODAT_HD0_MASK		(_HPI_HGPIODAT_HD0_MK(0x0001u))
#define _HPI_HGPIODAT_HD0_CLR		      (~(_HPI_HGPIODAT_HD0_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT_HD1:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT_HD1_SHIFT		(0x0001u)
#define _HPI_HGPIODAT_HD1_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT_HD1_SHIFT)
#define _HPI_HGPIODAT_HD1_MASK		(_HPI_HGPIODAT_HD1_MK(0x0001u))
#define _HPI_HGPIODAT_HD1_CLR		(~(_HPI_HGPIODAT_HD1_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT_HD2:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT_HD2_SHIFT		(0x0002u)
#define _HPI_HGPIODAT_HD2_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT_HD2_SHIFT)
#define _HPI_HGPIODAT_HD2_MASK		(_HPI_HGPIODAT_HD2_MK(0x0001u))
#define _HPI_HGPIODAT_HD2_CLR		(~(_HPI_HGPIODAT_HD2_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT_HD3:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT_HD3_SHIFT		(0x0003u)
#define _HPI_HGPIODAT_HD3_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT_HD3_SHIFT)
#define _HPI_HGPIODAT_HD3_MASK		(_HPI_HGPIODAT_HD3_MK(0x0001u))
#define _HPI_HGPIODAT_HD3_CLR		(~(_HPI_HGPIODAT_HD3_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT_HD4:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT_HD4_SHIFT		(0x0004u)
#define _HPI_HGPIODAT_HD4_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT_HD4_SHIFT)
#define _HPI_HGPIODAT_HD4_MASK		(_HPI_HGPIODAT_HD4_MK(0x0001u))
#define _HPI_HGPIODAT_HD4_CLR		(~(_HPI_HGPIODAT_HD4_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT_HD5:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT_HD5_SHIFT		(0x0005u)
#define _HPI_HGPIODAT_HD5_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT_HD5_SHIFT)
#define _HPI_HGPIODAT_HD5_MASK		(_HPI_HGPIODAT_HD5_MK(0x0001u))
#define _HPI_HGPIODAT_HD5_CLR		(~(_HPI_HGPIODAT_HD5_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT_HD6:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT_HD6_SHIFT		(0x0006u)
#define _HPI_HGPIODAT_HD6_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT_HD6_SHIFT)
#define _HPI_HGPIODAT_HD6_MASK		(_HPI_HGPIODAT_HD6_MK(0x0001u))
#define _HPI_HGPIODAT_HD6_CLR		(~(_HPI_HGPIODAT_HD6_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT_HD7:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT_HD7_SHIFT		(0x0007u)
#define _HPI_HGPIODAT_HD7_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT_HD7_SHIFT)
#define _HPI_HGPIODAT_HD7_MASK		(_HPI_HGPIODAT_HD7_MK(0x0001u))
#define _HPI_HGPIODAT_HD7_CLR		(~(_HPI_HGPIODAT_HD7_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT_HD8:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT_HD8_SHIFT		(0x0008u)
#define _HPI_HGPIODAT_HD8_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT_HD8_SHIFT)
#define _HPI_HGPIODAT_HD8_MASK		(_HPI_HGPIODAT_HD8_MK(0x0001u))
#define _HPI_HGPIODAT_HD8_CLR		      (~(_HPI_HGPIODAT_HD8_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT_HD9:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT_HD9_SHIFT		(0x0009u)
#define _HPI_HGPIODAT_HD9_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT_HD9_SHIFT)
#define _HPI_HGPIODAT_HD9_MASK		(_HPI_HGPIODAT_HD9_MK(0x0001u))
#define _HPI_HGPIODAT_HD9_CLR		      (~(_HPI_HGPIODAT_HD9_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT_HD10:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT_HD10_SHIFT		(0x000Au)
#define _HPI_HGPIODAT_HD10_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT_HD10_SHIFT)
#define _HPI_HGPIODAT_HD10_MASK		(_HPI_HGPIODAT_HD10_MK(0x0001u))
#define _HPI_HGPIODAT_HD10_CLR		(~(_HPI_HGPIODAT_HD10_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT_HD11:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT_HD11_SHIFT		(0x000Bu)
#define _HPI_HGPIODAT_HD11_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT_HD11_SHIFT)
#define _HPI_HGPIODAT_HD11_MASK		(_HPI_HGPIODAT_HD11_MK(0x0001u))
#define _HPI_HGPIODAT_HD11_CLR		(~(_HPI_HGPIODAT_HD11_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT_HD12:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT_HD12_SHIFT		(0x000Cu)
#define _HPI_HGPIODAT_HD12_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT_HD12_SHIFT)
#define _HPI_HGPIODAT_HD12_MASK		(_HPI_HGPIODAT_HD12_MK(0x0001u))
#define _HPI_HGPIODAT_HD12_CLR		(~(_HPI_HGPIODAT_HD12_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT_HD13:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT_HD13_SHIFT		(0x000Du)
#define _HPI_HGPIODAT_HD13_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT_HD13_SHIFT)
#define _HPI_HGPIODAT_HD13_MASK		(_HPI_HGPIODAT_HD13_MK(0x0001u))
#define _HPI_HGPIODAT_HD13_CLR		(~(_HPI_HGPIODAT_HD13_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT_HD14:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT_HD14_SHIFT		(0x000Eu)
#define _HPI_HGPIODAT_HD14_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT_HD14_SHIFT)
#define _HPI_HGPIODAT_HD14_MASK		(_HPI_HGPIODAT_HD14_MK(0x0001u))
#define _HPI_HGPIODAT_HD14_CLR		(~(_HPI_HGPIODAT_HD14_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT_HD15:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT_HD15_SHIFT		(0x000Fu)
#define _HPI_HGPIODAT_HD15_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT_HD15_SHIFT)
#define _HPI_HGPIODAT_HD15_MASK		(_HPI_HGPIODAT_HD15_MK(0x0001u))
#define _HPI_HGPIODAT_HD15_CLR		(~(_HPI_HGPIODAT_HD15_MASK))




/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the HGPIODAT1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _HPI_HGPIODAT1	 - Note: Add description here
*
* Fields:
*	(RW)   _HPI_HGPIODAT1_HD0	
*	(RW)   _HPI_HGPIODAT1_HD1	
*	(RW)   _HPI_HGPIODAT1_HD2	
*	(RW)   _HPI_HGPIODAT1_HD3	
*	(RW)   _HPI_HGPIODAT1_HD4	
*	(RW)   _HPI_HGPIODAT1_HD5	
*	(RW)   _HPI_HGPIODAT1_HD6	
*	(RW)   _HPI_HGPIODAT1_HD7
*	(RW)   _HPI_HGPIODAT1_HD8	
*	(RW)   _HPI_HGPIODAT1_HD9	
*	(RW)   _HPI_HGPIODAT1_HD10	
*	(RW)   _HPI_HGPIODAT1_HD11	
*	(RW)   _HPI_HGPIODAT1_HD12	
*	(RW)   _HPI_HGPIODAT1_HD13	
*	(RW)   _HPI_HGPIODAT1_HD14	
*	(RW)   _HPI_HGPIODAT1_HD15	
*
\******************************************************************************/


/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT1_HD0:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT1_HD0_SHIFT		(000000u)
#define _HPI_HGPIODAT1_HD0_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT1_HD0_SHIFT)
#define _HPI_HGPIODAT1_HD0_MASK		(_HPI_HGPIODAT1_HD0_MK(0x0001u))
#define _HPI_HGPIODAT1_HD0_CLR		      (~(_HPI_HGPIODAT1_HD0_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT1_HD1:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT1_HD1_SHIFT		(0x0001u)
#define _HPI_HGPIODAT1_HD1_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT1_HD1_SHIFT)
#define _HPI_HGPIODAT1_HD1_MASK		(_HPI_HGPIODAT1_HD1_MK(0x0001u))
#define _HPI_HGPIODAT1_HD1_CLR		(~(_HPI_HGPIODAT1_HD1_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT1_HD2:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT1_HD2_SHIFT		(0x0002u)
#define _HPI_HGPIODAT1_HD2_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT1_HD2_SHIFT)
#define _HPI_HGPIODAT1_HD2_MASK		(_HPI_HGPIODAT1_HD2_MK(0x0001u))
#define _HPI_HGPIODAT1_HD2_CLR		(~(_HPI_HGPIODAT1_HD2_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT1_HD3:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT1_HD3_SHIFT		(0x0003u)
#define _HPI_HGPIODAT1_HD3_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT1_HD3_SHIFT)
#define _HPI_HGPIODAT1_HD3_MASK		(_HPI_HGPIODAT1_HD3_MK(0x0001u))
#define _HPI_HGPIODAT1_HD3_CLR		(~(_HPI_HGPIODAT1_HD3_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT1_HD4:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT1_HD4_SHIFT		(0x0004u)
#define _HPI_HGPIODAT1_HD4_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT1_HD4_SHIFT)
#define _HPI_HGPIODAT1_HD4_MASK		(_HPI_HGPIODAT1_HD4_MK(0x0001u))
#define _HPI_HGPIODAT1_HD4_CLR		(~(_HPI_HGPIODAT1_HD4_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT1_HD5:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT1_HD5_SHIFT		(0x0005u)
#define _HPI_HGPIODAT1_HD5_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT1_HD5_SHIFT)
#define _HPI_HGPIODAT1_HD5_MASK		(_HPI_HGPIODAT1_HD5_MK(0x0001u))
#define _HPI_HGPIODAT1_HD5_CLR		(~(_HPI_HGPIODAT1_HD5_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT1_HD6:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT1_HD6_SHIFT		(0x0006u)
#define _HPI_HGPIODAT1_HD6_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT1_HD6_SHIFT)
#define _HPI_HGPIODAT1_HD6_MASK		(_HPI_HGPIODAT1_HD6_MK(0x0001u))
#define _HPI_HGPIODAT1_HD6_CLR		(~(_HPI_HGPIODAT1_HD6_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT1_HD7:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT1_HD7_SHIFT		(0x0007u)
#define _HPI_HGPIODAT1_HD7_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT1_HD7_SHIFT)
#define _HPI_HGPIODAT1_HD7_MASK		(_HPI_HGPIODAT1_HD7_MK(0x0001u))
#define _HPI_HGPIODAT1_HD7_CLR		(~(_HPI_HGPIODAT1_HD7_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT1_HD8:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT1_HD8_SHIFT		(0x0008u)
#define _HPI_HGPIODAT1_HD8_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT1_HD8_SHIFT)
#define _HPI_HGPIODAT1_HD8_MASK		(_HPI_HGPIODAT1_HD8_MK(0x0001u))
#define _HPI_HGPIODAT1_HD8_CLR		      (~(_HPI_HGPIODAT1_HD8_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT1_HD9:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT1_HD9_SHIFT		(0x0009u)
#define _HPI_HGPIODAT1_HD9_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT1_HD9_SHIFT)
#define _HPI_HGPIODAT1_HD9_MASK		(_HPI_HGPIODAT1_HD9_MK(0x0001u))
#define _HPI_HGPIODAT1_HD9_CLR		      (~(_HPI_HGPIODAT1_HD9_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT1_HD10:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT1_HD10_SHIFT		(0x000Au)
#define _HPI_HGPIODAT1_HD10_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT1_HD10_SHIFT)
#define _HPI_HGPIODAT1_HD10_MASK		(_HPI_HGPIODAT1_HD10_MK(0x0001u))
#define _HPI_HGPIODAT1_HD10_CLR		(~(_HPI_HGPIODAT1_HD10_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT1_HD11:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT1_HD11_SHIFT		(0x000Bu)
#define _HPI_HGPIODAT1_HD11_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT1_HD11_SHIFT)
#define _HPI_HGPIODAT1_HD11_MASK		(_HPI_HGPIODAT1_HD11_MK(0x0001u))
#define _HPI_HGPIODAT1_HD11_CLR		(~(_HPI_HGPIODAT1_HD11_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT1_HD12:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT1_HD12_SHIFT		(0x000Cu)
#define _HPI_HGPIODAT1_HD12_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT1_HD12_SHIFT)
#define _HPI_HGPIODAT1_HD12_MASK		(_HPI_HGPIODAT1_HD12_MK(0x0001u))
#define _HPI_HGPIODAT1_HD12_CLR		(~(_HPI_HGPIODAT1_HD12_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT1_HD13:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT1_HD13_SHIFT		(0x000Du)
#define _HPI_HGPIODAT1_HD13_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT1_HD13_SHIFT)
#define _HPI_HGPIODAT1_HD13_MASK		(_HPI_HGPIODAT1_HD13_MK(0x0001u))
#define _HPI_HGPIODAT1_HD13_CLR		(~(_HPI_HGPIODAT1_HD13_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT1_HD14:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT1_HD14_SHIFT		(0x000Eu)
#define _HPI_HGPIODAT1_HD14_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT1_HD14_SHIFT)
#define _HPI_HGPIODAT1_HD14_MASK		(_HPI_HGPIODAT1_HD14_MK(0x0001u))
#define _HPI_HGPIODAT1_HD14_CLR		(~(_HPI_HGPIODAT1_HD14_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT1_HD15:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT1_HD15_SHIFT		(0x000Fu)
#define _HPI_HGPIODAT1_HD15_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT1_HD15_SHIFT)
#define _HPI_HGPIODAT1_HD15_MASK		(_HPI_HGPIODAT1_HD15_MK(0x0001u))
#define _HPI_HGPIODAT1_HD15_CLR		(~(_HPI_HGPIODAT1_HD15_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the HGPIODAT2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _HPI_HGPIODAT2	 - Note: Add description here
*
* Fields:
*	(RW)   _HPI_HGPIODAT2_HD0	
*	(RW)   _HPI_HGPIODAT2_HD1	
*	(RW)   _HPI_HGPIODAT2_HD2	
*	(RW)   _HPI_HGPIODAT2_HD3	
*	(RW)   _HPI_HGPIODAT2_HD4	
*	(RW)   _HPI_HGPIODAT2_HD5	
*	(RW)   _HPI_HGPIODAT2_HD6	
*	(RW)   _HPI_HGPIODAT2_HD7
*	(RW)   _HPI_HGPIODAT2_HD8	
*	(RW)   _HPI_HGPIODAT2_HD9	
*	(RW)   _HPI_HGPIODAT2_HD10	
*	(RW)   _HPI_HGPIODAT2_HD11	
*	(RW)   _HPI_HGPIODAT2_HD12	
*	(RW)   _HPI_HGPIODAT2_HD13	
*	(RW)   _HPI_HGPIODAT2_HD14	
*	(RW)   _HPI_HGPIODAT2_HD15	
*
\******************************************************************************/


/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT2_HD0:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT2_HD0_SHIFT		(000000u)
#define _HPI_HGPIODAT2_HD0_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT2_HD0_SHIFT)
#define _HPI_HGPIODAT2_HD0_MASK		(_HPI_HGPIODAT2_HD0_MK(0x0001u))
#define _HPI_HGPIODAT2_HD0_CLR		      (~(_HPI_HGPIODAT2_HD0_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT2_HD1:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT2_HD1_SHIFT		(0x0001u)
#define _HPI_HGPIODAT2_HD1_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT2_HD1_SHIFT)
#define _HPI_HGPIODAT2_HD1_MASK		(_HPI_HGPIODAT2_HD1_MK(0x0001u))
#define _HPI_HGPIODAT2_HD1_CLR		(~(_HPI_HGPIODAT2_HD1_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT2_HD2:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT2_HD2_SHIFT		(0x0002u)
#define _HPI_HGPIODAT2_HD2_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT2_HD2_SHIFT)
#define _HPI_HGPIODAT2_HD2_MASK		(_HPI_HGPIODAT2_HD2_MK(0x0001u))
#define _HPI_HGPIODAT2_HD2_CLR		(~(_HPI_HGPIODAT2_HD2_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT2_HD3:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT2_HD3_SHIFT		(0x0003u)
#define _HPI_HGPIODAT2_HD3_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT2_HD3_SHIFT)
#define _HPI_HGPIODAT2_HD3_MASK		(_HPI_HGPIODAT2_HD3_MK(0x0001u))
#define _HPI_HGPIODAT2_HD3_CLR		(~(_HPI_HGPIODAT2_HD3_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT2_HD4:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT2_HD4_SHIFT		(0x0004u)
#define _HPI_HGPIODAT2_HD4_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT2_HD4_SHIFT)
#define _HPI_HGPIODAT2_HD4_MASK		(_HPI_HGPIODAT2_HD4_MK(0x0001u))
#define _HPI_HGPIODAT2_HD4_CLR		(~(_HPI_HGPIODAT2_HD4_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT2_HD5:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT2_HD5_SHIFT		(0x0005u)
#define _HPI_HGPIODAT2_HD5_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT2_HD5_SHIFT)
#define _HPI_HGPIODAT2_HD5_MASK		(_HPI_HGPIODAT2_HD5_MK(0x0001u))
#define _HPI_HGPIODAT2_HD5_CLR		(~(_HPI_HGPIODAT2_HD5_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT2_HD6:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT2_HD6_SHIFT		(0x0006u)
#define _HPI_HGPIODAT2_HD6_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT2_HD6_SHIFT)
#define _HPI_HGPIODAT2_HD6_MASK		(_HPI_HGPIODAT2_HD6_MK(0x0001u))
#define _HPI_HGPIODAT2_HD6_CLR		(~(_HPI_HGPIODAT2_HD6_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT2_HD7:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT2_HD7_SHIFT		(0x0007u)
#define _HPI_HGPIODAT2_HD7_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT2_HD7_SHIFT)
#define _HPI_HGPIODAT2_HD7_MASK		(_HPI_HGPIODAT2_HD7_MK(0x0001u))
#define _HPI_HGPIODAT2_HD7_CLR		(~(_HPI_HGPIODAT2_HD7_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT2_HD8:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT2_HD8_SHIFT		(0x0008u)
#define _HPI_HGPIODAT2_HD8_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT2_HD8_SHIFT)
#define _HPI_HGPIODAT2_HD8_MASK		(_HPI_HGPIODAT2_HD8_MK(0x0001u))
#define _HPI_HGPIODAT2_HD8_CLR		      (~(_HPI_HGPIODAT2_HD8_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT2_HD9:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT2_HD9_SHIFT		(0x0009u)
#define _HPI_HGPIODAT2_HD9_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT2_HD9_SHIFT)
#define _HPI_HGPIODAT2_HD9_MASK		(_HPI_HGPIODAT2_HD9_MK(0x0001u))
#define _HPI_HGPIODAT2_HD9_CLR		      (~(_HPI_HGPIODAT2_HD9_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT2_HD10:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT2_HD10_SHIFT		(0x000Au)
#define _HPI_HGPIODAT2_HD10_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT2_HD10_SHIFT)
#define _HPI_HGPIODAT2_HD10_MASK		(_HPI_HGPIODAT2_HD10_MK(0x0001u))
#define _HPI_HGPIODAT2_HD10_CLR		(~(_HPI_HGPIODAT2_HD10_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT2_HD11:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT2_HD11_SHIFT		(0x000Bu)
#define _HPI_HGPIODAT2_HD11_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT2_HD11_SHIFT)
#define _HPI_HGPIODAT2_HD11_MASK		(_HPI_HGPIODAT2_HD11_MK(0x0001u))
#define _HPI_HGPIODAT2_HD11_CLR		(~(_HPI_HGPIODAT2_HD11_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT2_HD12:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT2_HD12_SHIFT		(0x000Cu)
#define _HPI_HGPIODAT2_HD12_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT2_HD12_SHIFT)
#define _HPI_HGPIODAT2_HD12_MASK		(_HPI_HGPIODAT2_HD12_MK(0x0001u))
#define _HPI_HGPIODAT2_HD12_CLR		(~(_HPI_HGPIODAT2_HD12_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT2_HD13:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT2_HD13_SHIFT		(0x000Du)
#define _HPI_HGPIODAT2_HD13_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT2_HD13_SHIFT)
#define _HPI_HGPIODAT2_HD13_MASK		(_HPI_HGPIODAT2_HD13_MK(0x0001u))
#define _HPI_HGPIODAT2_HD13_CLR		(~(_HPI_HGPIODAT2_HD13_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT2_HD14:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT2_HD14_SHIFT		(0x000Eu)
#define _HPI_HGPIODAT2_HD14_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT2_HD14_SHIFT)
#define _HPI_HGPIODAT2_HD14_MASK		(_HPI_HGPIODAT2_HD14_MK(0x0001u))
#define _HPI_HGPIODAT2_HD14_CLR		(~(_HPI_HGPIODAT2_HD14_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT2_HD15:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT2_HD15_SHIFT		(0x000Fu)
#define _HPI_HGPIODAT2_HD15_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT2_HD15_SHIFT)
#define _HPI_HGPIODAT2_HD15_MASK		(_HPI_HGPIODAT2_HD15_MK(0x0001u))
#define _HPI_HGPIODAT2_HD15_CLR		(~(_HPI_HGPIODAT2_HD15_MASK))

/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the HGPIODAT3 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _HPI_HGPIODAT3	 - Note: Add description here
*
* Fields:
*	(RW)   _HPI_HGPIODAT3_HD0	
*	(RW)   _HPI_HGPIODAT3_HD1	
*	(RW)   _HPI_HGPIODAT3_HD2	
*	(RW)   _HPI_HGPIODAT3_HD3	
*	(RW)   _HPI_HGPIODAT3_HD4	
*	(RW)   _HPI_HGPIODAT3_HD5	
*	(RW)   _HPI_HGPIODAT3_HD6	
*	(RW)   _HPI_HGPIODAT3_HD7
*	(RW)   _HPI_HGPIODAT3_HD8	
*	(RW)   _HPI_HGPIODAT3_HD9	
*	(RW)   _HPI_HGPIODAT3_HD10	
*	(RW)   _HPI_HGPIODAT3_HD11	
*	(RW)   _HPI_HGPIODAT3_HD12	
*	(RW)   _HPI_HGPIODAT3_HD13	
*	(RW)   _HPI_HGPIODAT3_HD14	
*	(RW)   _HPI_HGPIODAT3_HD15	
*
\******************************************************************************/


/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT3_HD0:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT3_HD0_SHIFT		(000000u)
#define _HPI_HGPIODAT3_HD0_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT3_HD0_SHIFT)
#define _HPI_HGPIODAT3_HD0_MASK		(_HPI_HGPIODAT3_HD0_MK(0x0001u))
#define _HPI_HGPIODAT3_HD0_CLR		      (~(_HPI_HGPIODAT3_HD0_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT3_HD1:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT3_HD1_SHIFT		(0x0001u)
#define _HPI_HGPIODAT3_HD1_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT3_HD1_SHIFT)
#define _HPI_HGPIODAT3_HD1_MASK		(_HPI_HGPIODAT3_HD1_MK(0x0001u))
#define _HPI_HGPIODAT3_HD1_CLR		(~(_HPI_HGPIODAT3_HD1_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT3_HD2:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT3_HD2_SHIFT		(0x0002u)
#define _HPI_HGPIODAT3_HD2_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT3_HD2_SHIFT)
#define _HPI_HGPIODAT3_HD2_MASK		(_HPI_HGPIODAT3_HD2_MK(0x0001u))
#define _HPI_HGPIODAT3_HD2_CLR		(~(_HPI_HGPIODAT3_HD2_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT3_HD3:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT3_HD3_SHIFT		(0x0003u)
#define _HPI_HGPIODAT3_HD3_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT3_HD3_SHIFT)
#define _HPI_HGPIODAT3_HD3_MASK		(_HPI_HGPIODAT3_HD3_MK(0x0001u))
#define _HPI_HGPIODAT3_HD3_CLR		(~(_HPI_HGPIODAT3_HD3_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT3_HD4:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT3_HD4_SHIFT		(0x0004u)
#define _HPI_HGPIODAT3_HD4_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT3_HD4_SHIFT)
#define _HPI_HGPIODAT3_HD4_MASK		(_HPI_HGPIODAT3_HD4_MK(0x0001u))
#define _HPI_HGPIODAT3_HD4_CLR		(~(_HPI_HGPIODAT3_HD4_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT3_HD5:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT3_HD5_SHIFT		(0x0005u)
#define _HPI_HGPIODAT3_HD5_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT3_HD5_SHIFT)
#define _HPI_HGPIODAT3_HD5_MASK		(_HPI_HGPIODAT3_HD5_MK(0x0001u))
#define _HPI_HGPIODAT3_HD5_CLR		(~(_HPI_HGPIODAT3_HD5_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT3_HD6:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT3_HD6_SHIFT		(0x0006u)
#define _HPI_HGPIODAT3_HD6_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT3_HD6_SHIFT)
#define _HPI_HGPIODAT3_HD6_MASK		(_HPI_HGPIODAT3_HD6_MK(0x0001u))
#define _HPI_HGPIODAT3_HD6_CLR		(~(_HPI_HGPIODAT3_HD6_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT3_HD7:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT3_HD7_SHIFT		(0x0007u)
#define _HPI_HGPIODAT3_HD7_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT3_HD7_SHIFT)
#define _HPI_HGPIODAT3_HD7_MASK		(_HPI_HGPIODAT3_HD7_MK(0x0001u))
#define _HPI_HGPIODAT3_HD7_CLR		(~(_HPI_HGPIODAT3_HD7_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT3_HD8:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT3_HD8_SHIFT		(0x0008u)
#define _HPI_HGPIODAT3_HD8_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT3_HD8_SHIFT)
#define _HPI_HGPIODAT3_HD8_MASK		(_HPI_HGPIODAT3_HD8_MK(0x0001u))
#define _HPI_HGPIODAT3_HD8_CLR		      (~(_HPI_HGPIODAT3_HD8_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT3_HD9:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT3_HD9_SHIFT		(0x0009u)
#define _HPI_HGPIODAT3_HD9_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT3_HD9_SHIFT)
#define _HPI_HGPIODAT3_HD9_MASK		(_HPI_HGPIODAT3_HD9_MK(0x0001u))
#define _HPI_HGPIODAT3_HD9_CLR		      (~(_HPI_HGPIODAT3_HD9_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT3_HD10:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT3_HD10_SHIFT		(0x000Au)
#define _HPI_HGPIODAT3_HD10_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT3_HD10_SHIFT)
#define _HPI_HGPIODAT3_HD10_MASK		(_HPI_HGPIODAT3_HD10_MK(0x0001u))
#define _HPI_HGPIODAT3_HD10_CLR		(~(_HPI_HGPIODAT3_HD10_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT3_HD11:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT3_HD11_SHIFT		(0x000Bu)
#define _HPI_HGPIODAT3_HD11_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT3_HD11_SHIFT)
#define _HPI_HGPIODAT3_HD11_MASK		(_HPI_HGPIODAT3_HD11_MK(0x0001u))
#define _HPI_HGPIODAT3_HD11_CLR		(~(_HPI_HGPIODAT3_HD11_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT3_HD12:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT3_HD12_SHIFT		(0x000Cu)
#define _HPI_HGPIODAT3_HD12_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT3_HD12_SHIFT)
#define _HPI_HGPIODAT3_HD12_MASK		(_HPI_HGPIODAT3_HD12_MK(0x0001u))
#define _HPI_HGPIODAT3_HD12_CLR		(~(_HPI_HGPIODAT3_HD12_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT3_HD13:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT3_HD13_SHIFT		(0x000Du)
#define _HPI_HGPIODAT3_HD13_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT3_HD13_SHIFT)
#define _HPI_HGPIODAT3_HD13_MASK		(_HPI_HGPIODAT3_HD13_MK(0x0001u))
#define _HPI_HGPIODAT3_HD13_CLR		(~(_HPI_HGPIODAT3_HD13_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT3_HD14:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT3_HD14_SHIFT		(0x000Eu)
#define _HPI_HGPIODAT3_HD14_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT3_HD14_SHIFT)
#define _HPI_HGPIODAT3_HD14_MASK		(_HPI_HGPIODAT3_HD14_MK(0x0001u))
#define _HPI_HGPIODAT3_HD14_CLR		(~(_HPI_HGPIODAT3_HD14_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _HPI_HGPIODAT3_HD15:	
\*----------------------------------------------------------------*/

#define _HPI_HGPIODAT3_HD15_SHIFT		(0x000Fu)
#define _HPI_HGPIODAT3_HD15_MK(n)		(((Uint16)(n) & 0x0001u) << _HPI_HGPIODAT3_HD15_SHIFT)
#define _HPI_HGPIODAT3_HD15_MASK		(_HPI_HGPIODAT3_HD15_MK(0x0001u))
#define _HPI_HGPIODAT3_HD15_CLR		(~(_HPI_HGPIODAT3_HD15_MASK))

   
#elif (!(_HPI_MOD))
	#error HPI Hal Module Not Supported on Specified Target
#endif  /* _HPI_SUPPORT  */

#endif  /* _CSL_HPIHAL_H  */

/******************************************************************************\
*     
*      End of csl_hpihal.h 
*
\******************************************************************************/
