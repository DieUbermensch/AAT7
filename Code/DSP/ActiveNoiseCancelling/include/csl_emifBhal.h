/****************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved 
*------------------------------------------------------------------------------
* MODULE NAME... EMIF
* FILENAME...... csl_emifhal.h
* DATE CREATED.. Mon Feb 11 15:35:20 2002
* PROJECT....... Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS.. 
*------------------------------------------------------------------------------
*
* HISTORY:
*	 Created:		Mon Feb 11 15:35:20 2002 (Automatic generation)
*	 Modified:	26 Mar 2003   Added definitions to bring in line with
*                               User Documentation SPRU621A
*
*------------------------------------------------------------------------------
* DESCRIPTION: CSL HAL interface file for the EMIF module 
*
* Registers covered:
*
* 		 Note: Add registers description here
*	 GBLCTL1		- EMIF Global Control Register 1
*	 GBLCTL2		- EMIF Global Control Register 2
*	 CE1CTL1		- CE1 Space Control Register 1
*	 CE1CTL2		- CE1 Space Control Register 2
*	 CE0CTL1		- CE0 Space Control Register 1
*	 CE0CTL2		- CE0 Space Control Register 2
*	 CE2CTL1		- CE2 Space Control Register 1
*	 CE2CTL2		- CE2 Space Control Register 2
*	 CE3CTL1		- CE3 Space Control Register 1
*	 CE3CTL2		- CE3 Space Control Register 2
*	 SDCTL1		- SDRAM Control Register 1
*	 SDCTL2		- SDRAM Control Register 2
*	 SDTIM1/SDRFR1	- SDRAM Refresh Control Register 1 Alternate naming Added 26 Mar 2003
*	 SDTIM2/SDRFR2	- SDRAM Refresh Control Register 2 Alternate naming Added 26 Mar 2003
*	 SDEXT1		- SDRAM Extension Register 1
*	 SDEXT2		- SDRAM Extension Register 2
*	 CE1SEC1		- CE1 Space Secondary Control Register 1
*	 CE0SEC1		- CE0 Space Secondary Control Register 1
*	 CE2SEC1		- CE2 Space Secondary Control Register 1
*	 CE3SEC1		- CE3 Space Secondary Control Register 1
*      CESCR            - CE Space Size Control Register (affects all CE spaces)
*                         Added 26 Mar 2003
*
\*************************************************************************/

#ifndef _CSL_EMIFBHAL_H_
#define _CSL_EMIFBHAL_H_

#include <csl_chiphal.h>

#if (_EMIFB_SUPPORT) 

/*----------------------------------------------------------------*\
*	 EMIF scope and inline control macros 			
\*----------------------------------------------------------------*/

#ifdef __cplusplus
#define CSLAPI extern "C"
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _EMIF_MOD_
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

/*--------------------- Register: GBLCTL1 -----------------------*/
#define _EMIF_GBLCTL1_ADDR		(0x0800u)
#define _EMIF_GBLCTL1			PREG16(_EMIF_GBLCTL1_ADDR)
#define _GBLCTL1			_EMIF_GBLCTL1


/*--------------------- Register: GBLCTL2 -----------------------*/
#define _EMIF_GBLCTL2_ADDR		(0x0801u)
#define _EMIF_GBLCTL2			PREG16(_EMIF_GBLCTL2_ADDR)
#define _GBLCTL2			_EMIF_GBLCTL2


/*--------------------- Register: CE1CTL1 -----------------------*/
#define _EMIF_CE1CTL1_ADDR		(0x0802u)
#define _EMIF_CE1CTL1			PREG16(_EMIF_CE1CTL1_ADDR)
#define _CE1CTL1			_EMIF_CE1CTL1


/*--------------------- Register: CE1CTL2 -----------------------*/
#define _EMIF_CE1CTL2_ADDR		(0x0803u)
#define _EMIF_CE1CTL2			PREG16(_EMIF_CE1CTL2_ADDR)
#define _CE1CTL2			_EMIF_CE1CTL2


/*--------------------- Register: CE0CTL1 -----------------------*/
#define _EMIF_CE0CTL1_ADDR		(0x0804u)
#define _EMIF_CE0CTL1			PREG16(_EMIF_CE0CTL1_ADDR)
#define _CE0CTL1			_EMIF_CE0CTL1


/*--------------------- Register: CE0CTL2 -----------------------*/
#define _EMIF_CE0CTL2_ADDR		(0x0805u)
#define _EMIF_CE0CTL2			PREG16(_EMIF_CE0CTL2_ADDR)
#define _CE0CTL2			_EMIF_CE0CTL2


/*--------------------- Register: CE2CTL1 -----------------------*/
#define _EMIF_CE2CTL1_ADDR		(0x0808u)
#define _EMIF_CE2CTL1			PREG16(_EMIF_CE2CTL1_ADDR)
#define _CE2CTL1			_EMIF_CE2CTL1


/*--------------------- Register: CE2CTL2 -----------------------*/
#define _EMIF_CE2CTL2_ADDR		(0x0809u)
#define _EMIF_CE2CTL2			PREG16(_EMIF_CE2CTL2_ADDR)
#define _CE2CTL2			_EMIF_CE2CTL2


/*--------------------- Register: CE3CTL1 -----------------------*/
#define _EMIF_CE3CTL1_ADDR		(0x080Au)
#define _EMIF_CE3CTL1			PREG16(_EMIF_CE3CTL1_ADDR)
#define _CE3CTL1			_EMIF_CE3CTL1


/*--------------------- Register: CE3CTL2 -----------------------*/
#define _EMIF_CE3CTL2_ADDR		(0x080Bu)
#define _EMIF_CE3CTL2			PREG16(_EMIF_CE3CTL2_ADDR)
#define _CE3CTL2			_EMIF_CE3CTL2


/*--------------------- Register: SDCTL1 -----------------------*/
#define _EMIF_SDCTL1_ADDR		(0x080Cu)
#define _EMIF_SDCTL1			PREG16(_EMIF_SDCTL1_ADDR)
#define _SDCTL1			_EMIF_SDCTL1


/*--------------------- Register: SDCTL2 -----------------------*/
#define _EMIF_SDCTL2_ADDR		(0x080Du)
#define _EMIF_SDCTL2			PREG16(_EMIF_SDCTL2_ADDR)
#define _SDCTL2			_EMIF_SDCTL2


/*--------------------- Register: SDTIM1 -----------------------*/
#define _EMIF_SDTIM1_ADDR		(0x080Eu)
#define _EMIF_SDTIM1			PREG16(_EMIF_SDTIM1_ADDR)
#define _SDTIM1			_EMIF_SDTIM1


/*--------------------- Register: SDTIM2 -----------------------*/
#define _EMIF_SDTIM2_ADDR		(0x080Fu)
#define _EMIF_SDTIM2			PREG16(_EMIF_SDTIM2_ADDR)
#define _SDTIM2			_EMIF_SDTIM2

/*--------------------- Register: SDRFR1 -----------------------*/
#define _EMIF_SDRFR1_ADDR		(0x080Eu)
#define _EMIF_SDRFR1			PREG16(_EMIF_SDRFR1_ADDR)
#define _SDRFR1			      _EMIF_SDRFR1


/*--------------------- Register: SDRFR2 -----------------------*/
#define _EMIF_SDRFR2_ADDR		(0x080Fu)
#define _EMIF_SDRFR2			PREG16(_EMIF_SDRFR2_ADDR)
#define _SDRFR2			      _EMIF_SDRFR2

/*--------------------- Register: SDEXT1 -----------------------*/
#define _EMIF_SDEXT1_ADDR		(0x0810u)
#define _EMIF_SDEXT1			PREG16(_EMIF_SDEXT1_ADDR)
#define _SDEXT1			_EMIF_SDEXT1


/*--------------------- Register: SDEXT2 -----------------------*/
#define _EMIF_SDEXT2_ADDR		(0x0811u)
#define _EMIF_SDEXT2			PREG16(_EMIF_SDEXT2_ADDR)
#define _SDEXT2			_EMIF_SDEXT2


/*--------------------- Register: CE1SEC1 -----------------------*/
#define _EMIF_CE1SEC1_ADDR		(0x0822u)
#define _EMIF_CE1SEC1			PREG16(_EMIF_CE1SEC1_ADDR)
#define _CE1SEC1			_EMIF_CE1SEC1


/*--------------------- Register: CE0SEC1 -----------------------*/
#define _EMIF_CE0SEC1_ADDR		(0x0824u)
#define _EMIF_CE0SEC1			PREG16(_EMIF_CE0SEC1_ADDR)
#define _CE0SEC1			_EMIF_CE0SEC1


/*--------------------- Register: CE2SEC1 -----------------------*/
#define _EMIF_CE2SEC1_ADDR		(0x0828u)
#define _EMIF_CE2SEC1			PREG16(_EMIF_CE2SEC1_ADDR)
#define _CE2SEC1			_EMIF_CE2SEC1


/*--------------------- Register: CE3SEC1 -----------------------*/
#define _EMIF_CE3SEC1_ADDR		(0x082Au)
#define _EMIF_CE3SEC1			PREG16(_EMIF_CE3SEC1_ADDR)
#define _CE3SEC1			_EMIF_CE3SEC1


/*--------------------- Register: CESCR -----------------------*/
#define _EMIF_CESCR_ADDR		(0x0840u)
#define _EMIF_CESCR			PREG16(_EMIF_CESCR_ADDR)
#define _CESCR				_EMIF_CESCR



/*----------------------------------------------------------------*\
*		 Register Macros		
\*----------------------------------------------------------------*/

#define EMIF_ADDR(Reg)		  _EMIF_##Reg##_ADDR
#define EMIF_RGET(Reg)		  _EMIF_##Reg##_GET
#define EMIF_RSET(Reg,Val)		  _EMIF_##Reg##_SET(Val)
#define EMIF_FGET(Reg,Field)		  _EMIF_##Reg##_FGET(Field)
#define EMIF_FSET(Reg,Field,Val)		  _EMIF_##Reg##_FSET(Field, Val)
#define EMIF_FMK(Reg,Field,Val)		  _EMIF_##Reg##_##Field##_MK(Val)
#define EMIF_RAOI(Reg,AND,OR,INV)		  _EMIF_##Reg##_AOI(AND,OR,INV)
#define EMIF_FAOI(Reg,Field,AND,OR,INV)	  _EMIF_##Reg##_FAOI(Field,AND,OR,INV)
#define EMIF_FMKS(Reg,Field,Sym)\
	  _EMIF_##Reg##_##Field##_MK(EMIF_##Reg##_##Field##_##Sym)
#define EMIF_FSETS(Reg,Field,Sym)\
	  _EMIF_FSET(Reg,Field,EMIF_##Reg##_##Field##_##Sym)

/*----------------------------------------------------------------*\
*		 Non-handle Registers Macros		
\*----------------------------------------------------------------*/


/*--------------------- Register: GBLCTL1 -----------------------*/
#define _EMIF_GBLCTL1_GET		  _PREG_GET(_EMIF_GBLCTL1_ADDR) 
#define _EMIF_GBLCTL1_SET(Val)		  _PREG_SET(_EMIF_GBLCTL1_ADDR,Val)
#define _EMIF_GBLCTL1_FGET(Field)	  _PFIELD_GET(_EMIF_GBLCTL1_ADDR, _EMIF_GBLCTL1_##Field)
#define _EMIF_GBLCTL1_FSET(Field,Val)	  _PFIELD_SET(_EMIF_GBLCTL1_ADDR, _EMIF_GBLCTL1_##Field, Val)
#define _EMIF_GBLCTL1_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_GBLCTL1_ADDR,AND,OR,INV)
#define _EMIF_GBLCTL1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_GBLCTL1_ADDR, _EMIF_GBLCTL1_##Field,AND,OR,INV)


/*--------------------- Register: GBLCTL2 -----------------------*/
#define _EMIF_GBLCTL2_GET		  _PREG_GET(_EMIF_GBLCTL2_ADDR) 
#define _EMIF_GBLCTL2_SET(Val)		  _PREG_SET(_EMIF_GBLCTL2_ADDR,Val)
#define _EMIF_GBLCTL2_FGET(Field)	  _PFIELD_GET(_EMIF_GBLCTL2_ADDR, _EMIF_GBLCTL2_##Field)
#define _EMIF_GBLCTL2_FSET(Field,Val)	  _PFIELD_SET(_EMIF_GBLCTL2_ADDR, _EMIF_GBLCTL2_##Field, Val)
#define _EMIF_GBLCTL2_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_GBLCTL2_ADDR,AND,OR,INV)
#define _EMIF_GBLCTL2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_GBLCTL2_ADDR, _EMIF_GBLCTL2_##Field,AND,OR,INV)


/*--------------------- Register: CE1CTL1 -----------------------*/
#define _EMIF_CE1CTL1_GET		  _PREG_GET(_EMIF_CE1CTL1_ADDR) 
#define _EMIF_CE1CTL1_SET(Val)		  _PREG_SET(_EMIF_CE1CTL1_ADDR,Val)
#define _EMIF_CE1CTL1_FGET(Field)	  _PFIELD_GET(_EMIF_CE1CTL1_ADDR, _EMIF_CE1CTL1_##Field)
#define _EMIF_CE1CTL1_FSET(Field,Val)	  _PFIELD_SET(_EMIF_CE1CTL1_ADDR, _EMIF_CE1CTL1_##Field, Val)
#define _EMIF_CE1CTL1_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_CE1CTL1_ADDR,AND,OR,INV)
#define _EMIF_CE1CTL1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_CE1CTL1_ADDR, _EMIF_CE1CTL1_##Field,AND,OR,INV)


/*--------------------- Register: CE1CTL2 -----------------------*/
#define _EMIF_CE1CTL2_GET		  _PREG_GET(_EMIF_CE1CTL2_ADDR) 
#define _EMIF_CE1CTL2_SET(Val)		  _PREG_SET(_EMIF_CE1CTL2_ADDR,Val)
#define _EMIF_CE1CTL2_FGET(Field)	  _PFIELD_GET(_EMIF_CE1CTL2_ADDR, _EMIF_CE1CTL2_##Field)
#define _EMIF_CE1CTL2_FSET(Field,Val)	  _PFIELD_SET(_EMIF_CE1CTL2_ADDR, _EMIF_CE1CTL2_##Field, Val)
#define _EMIF_CE1CTL2_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_CE1CTL2_ADDR,AND,OR,INV)
#define _EMIF_CE1CTL2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_CE1CTL2_ADDR, _EMIF_CE1CTL2_##Field,AND,OR,INV)


/*--------------------- Register: CE0CTL1 -----------------------*/
#define _EMIF_CE0CTL1_GET		  _PREG_GET(_EMIF_CE0CTL1_ADDR) 
#define _EMIF_CE0CTL1_SET(Val)		  _PREG_SET(_EMIF_CE0CTL1_ADDR,Val)
#define _EMIF_CE0CTL1_FGET(Field)	  _PFIELD_GET(_EMIF_CE0CTL1_ADDR, _EMIF_CE0CTL1_##Field)
#define _EMIF_CE0CTL1_FSET(Field,Val)	  _PFIELD_SET(_EMIF_CE0CTL1_ADDR, _EMIF_CE0CTL1_##Field, Val)
#define _EMIF_CE0CTL1_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_CE0CTL1_ADDR,AND,OR,INV)
#define _EMIF_CE0CTL1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_CE0CTL1_ADDR, _EMIF_CE0CTL1_##Field,AND,OR,INV)


/*--------------------- Register: CE0CTL2 -----------------------*/
#define _EMIF_CE0CTL2_GET		  _PREG_GET(_EMIF_CE0CTL2_ADDR) 
#define _EMIF_CE0CTL2_SET(Val)		  _PREG_SET(_EMIF_CE0CTL2_ADDR,Val)
#define _EMIF_CE0CTL2_FGET(Field)	  _PFIELD_GET(_EMIF_CE0CTL2_ADDR, _EMIF_CE0CTL2_##Field)
#define _EMIF_CE0CTL2_FSET(Field,Val)	  _PFIELD_SET(_EMIF_CE0CTL2_ADDR, _EMIF_CE0CTL2_##Field, Val)
#define _EMIF_CE0CTL2_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_CE0CTL2_ADDR,AND,OR,INV)
#define _EMIF_CE0CTL2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_CE0CTL2_ADDR, _EMIF_CE0CTL2_##Field,AND,OR,INV)


/*--------------------- Register: CE2CTL1 -----------------------*/
#define _EMIF_CE2CTL1_GET		  _PREG_GET(_EMIF_CE2CTL1_ADDR) 
#define _EMIF_CE2CTL1_SET(Val)		  _PREG_SET(_EMIF_CE2CTL1_ADDR,Val)
#define _EMIF_CE2CTL1_FGET(Field)	  _PFIELD_GET(_EMIF_CE2CTL1_ADDR, _EMIF_CE2CTL1_##Field)
#define _EMIF_CE2CTL1_FSET(Field,Val)	  _PFIELD_SET(_EMIF_CE2CTL1_ADDR, _EMIF_CE2CTL1_##Field, Val)
#define _EMIF_CE2CTL1_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_CE2CTL1_ADDR,AND,OR,INV)
#define _EMIF_CE2CTL1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_CE2CTL1_ADDR, _EMIF_CE2CTL1_##Field,AND,OR,INV)


/*--------------------- Register: CE2CTL2 -----------------------*/
#define _EMIF_CE2CTL2_GET		  _PREG_GET(_EMIF_CE2CTL2_ADDR) 
#define _EMIF_CE2CTL2_SET(Val)		  _PREG_SET(_EMIF_CE2CTL2_ADDR,Val)
#define _EMIF_CE2CTL2_FGET(Field)	  _PFIELD_GET(_EMIF_CE2CTL2_ADDR, _EMIF_CE2CTL2_##Field)
#define _EMIF_CE2CTL2_FSET(Field,Val)	  _PFIELD_SET(_EMIF_CE2CTL2_ADDR, _EMIF_CE2CTL2_##Field, Val)
#define _EMIF_CE2CTL2_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_CE2CTL2_ADDR,AND,OR,INV)
#define _EMIF_CE2CTL2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_CE2CTL2_ADDR, _EMIF_CE2CTL2_##Field,AND,OR,INV)


/*--------------------- Register: CE3CTL1 -----------------------*/
#define _EMIF_CE3CTL1_GET		  _PREG_GET(_EMIF_CE3CTL1_ADDR) 
#define _EMIF_CE3CTL1_SET(Val)		  _PREG_SET(_EMIF_CE3CTL1_ADDR,Val)
#define _EMIF_CE3CTL1_FGET(Field)	  _PFIELD_GET(_EMIF_CE3CTL1_ADDR, _EMIF_CE3CTL1_##Field)
#define _EMIF_CE3CTL1_FSET(Field,Val)	  _PFIELD_SET(_EMIF_CE3CTL1_ADDR, _EMIF_CE3CTL1_##Field, Val)
#define _EMIF_CE3CTL1_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_CE3CTL1_ADDR,AND,OR,INV)
#define _EMIF_CE3CTL1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_CE3CTL1_ADDR, _EMIF_CE3CTL1_##Field,AND,OR,INV)


/*--------------------- Register: CE3CTL2 -----------------------*/
#define _EMIF_CE3CTL2_GET		  _PREG_GET(_EMIF_CE3CTL2_ADDR) 
#define _EMIF_CE3CTL2_SET(Val)		  _PREG_SET(_EMIF_CE3CTL2_ADDR,Val)
#define _EMIF_CE3CTL2_FGET(Field)	  _PFIELD_GET(_EMIF_CE3CTL2_ADDR, _EMIF_CE3CTL2_##Field)
#define _EMIF_CE3CTL2_FSET(Field,Val)	  _PFIELD_SET(_EMIF_CE3CTL2_ADDR, _EMIF_CE3CTL2_##Field, Val)
#define _EMIF_CE3CTL2_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_CE3CTL2_ADDR,AND,OR,INV)
#define _EMIF_CE3CTL2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_CE3CTL2_ADDR, _EMIF_CE3CTL2_##Field,AND,OR,INV)

/*--------------------- Register: CESCR -----------------------*/
#define _EMIF_CESCR_GET		  _PREG_GET(_EMIF_CESCR_ADDR) 
#define _EMIF_CESCR_SET(Val)		  _PREG_SET(_EMIF_CESCR_ADDR,Val)
#define _EMIF_CESCR_FGET(Field)	  _PFIELD_GET(_EMIF_CESCR_ADDR, _EMIF_CESCR_##Field)
#define _EMIF_CESCR_FSET(Field,Val)	  _PFIELD_SET(_EMIF_CESCR_ADDR, _EMIF_CESCR_##Field, Val)
#define _EMIF_CESCR_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_CESCR_ADDR,AND,OR,INV)
#define _EMIF_CESCR_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_CESCR_ADDR, _EMIF_CESCR_##Field,AND,OR,INV)



/*--------------------- Register: SDCTL1 -----------------------*/
#define _EMIF_SDCTL1_GET		  _PREG_GET(_EMIF_SDCTL1_ADDR) 
#define _EMIF_SDCTL1_SET(Val)		  _PREG_SET(_EMIF_SDCTL1_ADDR,Val)
#define _EMIF_SDCTL1_FGET(Field)	  _PFIELD_GET(_EMIF_SDCTL1_ADDR, _EMIF_SDCTL1_##Field)
#define _EMIF_SDCTL1_FSET(Field,Val)	  _PFIELD_SET(_EMIF_SDCTL1_ADDR, _EMIF_SDCTL1_##Field, Val)
#define _EMIF_SDCTL1_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_SDCTL1_ADDR,AND,OR,INV)
#define _EMIF_SDCTL1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_SDCTL1_ADDR, _EMIF_SDCTL1_##Field,AND,OR,INV)


/*--------------------- Register: SDCTL2 -----------------------*/
#define _EMIF_SDCTL2_GET		  _PREG_GET(_EMIF_SDCTL2_ADDR) 
#define _EMIF_SDCTL2_SET(Val)		  _PREG_SET(_EMIF_SDCTL2_ADDR,Val)
#define _EMIF_SDCTL2_FGET(Field)	  _PFIELD_GET(_EMIF_SDCTL2_ADDR, _EMIF_SDCTL2_##Field)
#define _EMIF_SDCTL2_FSET(Field,Val)	  _PFIELD_SET(_EMIF_SDCTL2_ADDR, _EMIF_SDCTL2_##Field, Val)
#define _EMIF_SDCTL2_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_SDCTL2_ADDR,AND,OR,INV)
#define _EMIF_SDCTL2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_SDCTL2_ADDR, _EMIF_SDCTL2_##Field,AND,OR,INV)


/*--------------------- Register: SDTIM1 -----------------------*/
#define _EMIF_SDTIM1_GET		  _PREG_GET(_EMIF_SDTIM1_ADDR) 
#define _EMIF_SDTIM1_SET(Val)		  _PREG_SET(_EMIF_SDTIM1_ADDR,Val)
#define _EMIF_SDTIM1_FGET(Field)	  _PFIELD_GET(_EMIF_SDTIM1_ADDR, _EMIF_SDTIM1_##Field)
#define _EMIF_SDTIM1_FSET(Field,Val)	  _PFIELD_SET(_EMIF_SDTIM1_ADDR, _EMIF_SDTIM1_##Field, Val)
#define _EMIF_SDTIM1_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_SDTIM1_ADDR,AND,OR,INV)
#define _EMIF_SDTIM1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_SDTIM1_ADDR, _EMIF_SDTIM1_##Field,AND,OR,INV)


/*--------------------- Register: SDTIM2 -----------------------*/
#define _EMIF_SDTIM2_GET		  _PREG_GET(_EMIF_SDTIM2_ADDR) 
#define _EMIF_SDTIM2_SET(Val)		  _PREG_SET(_EMIF_SDTIM2_ADDR,Val)
#define _EMIF_SDTIM2_FGET(Field)	  _PFIELD_GET(_EMIF_SDTIM2_ADDR, _EMIF_SDTIM2_##Field)
#define _EMIF_SDTIM2_FSET(Field,Val)	  _PFIELD_SET(_EMIF_SDTIM2_ADDR, _EMIF_SDTIM2_##Field, Val)
#define _EMIF_SDTIM2_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_SDTIM2_ADDR,AND,OR,INV)
#define _EMIF_SDTIM2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_SDTIM2_ADDR, _EMIF_SDTIM2_##Field,AND,OR,INV)

/*--------------------- Register: SDRFR1 -----------------------*/
#define _EMIF_SDRFR1_GET		  _PREG_GET(_EMIF_SDRFR1_ADDR) 
#define _EMIF_SDRFR1_SET(Val)		  _PREG_SET(_EMIF_SDRFR1_ADDR,Val)
#define _EMIF_SDRFR1_FGET(Field)	  _PFIELD_GET(_EMIF_SDRFR1_ADDR, _EMIF_SDRFR1_##Field)
#define _EMIF_SDRFR1_FSET(Field,Val)	  _PFIELD_SET(_EMIF_SDRFR1_ADDR, _EMIF_SDRFR1_##Field, Val)
#define _EMIF_SDRFR1_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_SDRFR1_ADDR,AND,OR,INV)
#define _EMIF_SDRFR1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_SDRFR1_ADDR, _EMIF_SDRFR1_##Field,AND,OR,INV)


/*--------------------- Register: SDRFR2 -----------------------*/
#define _EMIF_SDRFR2_GET		  _PREG_GET(_EMIF_SDRFR2_ADDR) 
#define _EMIF_SDRFR2_SET(Val)		  _PREG_SET(_EMIF_SDRFR2_ADDR,Val)
#define _EMIF_SDRFR2_FGET(Field)	  _PFIELD_GET(_EMIF_SDRFR2_ADDR, _EMIF_SDRFR2_##Field)
#define _EMIF_SDRFR2_FSET(Field,Val)	  _PFIELD_SET(_EMIF_SDRFR2_ADDR, _EMIF_SDRFR2_##Field, Val)
#define _EMIF_SDRFR2_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_SDRFR2_ADDR,AND,OR,INV)
#define _EMIF_SDRFR2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_SDRFR2_ADDR, _EMIF_SDRFR2_##Field,AND,OR,INV)

/*--------------------- Register: SDEXT1 -----------------------*/
#define _EMIF_SDEXT1_GET		  _PREG_GET(_EMIF_SDEXT1_ADDR) 
#define _EMIF_SDEXT1_SET(Val)		  _PREG_SET(_EMIF_SDEXT1_ADDR,Val)
#define _EMIF_SDEXT1_FGET(Field)	  _PFIELD_GET(_EMIF_SDEXT1_ADDR, _EMIF_SDEXT1_##Field)
#define _EMIF_SDEXT1_FSET(Field,Val)	  _PFIELD_SET(_EMIF_SDEXT1_ADDR, _EMIF_SDEXT1_##Field, Val)
#define _EMIF_SDEXT1_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_SDEXT1_ADDR,AND,OR,INV)
#define _EMIF_SDEXT1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_SDEXT1_ADDR, _EMIF_SDEXT1_##Field,AND,OR,INV)


/*--------------------- Register: SDEXT2 -----------------------*/
#define _EMIF_SDEXT2_GET		  _PREG_GET(_EMIF_SDEXT2_ADDR) 
#define _EMIF_SDEXT2_SET(Val)		  _PREG_SET(_EMIF_SDEXT2_ADDR,Val)
#define _EMIF_SDEXT2_FGET(Field)	  _PFIELD_GET(_EMIF_SDEXT2_ADDR, _EMIF_SDEXT2_##Field)
#define _EMIF_SDEXT2_FSET(Field,Val)	  _PFIELD_SET(_EMIF_SDEXT2_ADDR, _EMIF_SDEXT2_##Field, Val)
#define _EMIF_SDEXT2_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_SDEXT2_ADDR,AND,OR,INV)
#define _EMIF_SDEXT2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_SDEXT2_ADDR, _EMIF_SDEXT2_##Field,AND,OR,INV)


/*--------------------- Register: CE1SEC1 -----------------------*/
#define _EMIF_CE1SEC1_GET		  _PREG_GET(_EMIF_CE1SEC1_ADDR) 
#define _EMIF_CE1SEC1_SET(Val)		  _PREG_SET(_EMIF_CE1SEC1_ADDR,Val)
#define _EMIF_CE1SEC1_FGET(Field)	  _PFIELD_GET(_EMIF_CE1SEC1_ADDR, _EMIF_CE1SEC1_##Field)
#define _EMIF_CE1SEC1_FSET(Field,Val)	  _PFIELD_SET(_EMIF_CE1SEC1_ADDR, _EMIF_CE1SEC1_##Field, Val)
#define _EMIF_CE1SEC1_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_CE1SEC1_ADDR,AND,OR,INV)
#define _EMIF_CE1SEC1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_CE1SEC1_ADDR, _EMIF_CE1SEC1_##Field,AND,OR,INV)


/*--------------------- Register: CE0SEC1 -----------------------*/
#define _EMIF_CE0SEC1_GET		  _PREG_GET(_EMIF_CE0SEC1_ADDR) 
#define _EMIF_CE0SEC1_SET(Val)		  _PREG_SET(_EMIF_CE0SEC1_ADDR,Val)
#define _EMIF_CE0SEC1_FGET(Field)	  _PFIELD_GET(_EMIF_CE0SEC1_ADDR, _EMIF_CE0SEC1_##Field)
#define _EMIF_CE0SEC1_FSET(Field,Val)	  _PFIELD_SET(_EMIF_CE0SEC1_ADDR, _EMIF_CE0SEC1_##Field, Val)
#define _EMIF_CE0SEC1_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_CE0SEC1_ADDR,AND,OR,INV)
#define _EMIF_CE0SEC1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_CE0SEC1_ADDR, _EMIF_CE0SEC1_##Field,AND,OR,INV)


/*--------------------- Register: CE2SEC1 -----------------------*/
#define _EMIF_CE2SEC1_GET		  _PREG_GET(_EMIF_CE2SEC1_ADDR) 
#define _EMIF_CE2SEC1_SET(Val)		  _PREG_SET(_EMIF_CE2SEC1_ADDR,Val)
#define _EMIF_CE2SEC1_FGET(Field)	  _PFIELD_GET(_EMIF_CE2SEC1_ADDR, _EMIF_CE2SEC1_##Field)
#define _EMIF_CE2SEC1_FSET(Field,Val)	  _PFIELD_SET(_EMIF_CE2SEC1_ADDR, _EMIF_CE2SEC1_##Field, Val)
#define _EMIF_CE2SEC1_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_CE2SEC1_ADDR,AND,OR,INV)
#define _EMIF_CE2SEC1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_CE2SEC1_ADDR, _EMIF_CE2SEC1_##Field,AND,OR,INV)


/*--------------------- Register: CE3SEC1 -----------------------*/
#define _EMIF_CE3SEC1_GET		  _PREG_GET(_EMIF_CE3SEC1_ADDR) 
#define _EMIF_CE3SEC1_SET(Val)		  _PREG_SET(_EMIF_CE3SEC1_ADDR,Val)
#define _EMIF_CE3SEC1_FGET(Field)	  _PFIELD_GET(_EMIF_CE3SEC1_ADDR, _EMIF_CE3SEC1_##Field)
#define _EMIF_CE3SEC1_FSET(Field,Val)	  _PFIELD_SET(_EMIF_CE3SEC1_ADDR, _EMIF_CE3SEC1_##Field, Val)
#define _EMIF_CE3SEC1_AOI(AND,OR,INV)	  _PREG_AOI(_EMIF_CE3SEC1_ADDR,AND,OR,INV)
#define _EMIF_CE3SEC1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_EMIF_CE3SEC1_ADDR, _EMIF_CE3SEC1_##Field,AND,OR,INV)



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the CE3CTL1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _EMIF_CE3CTL1	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_CE3CTL1_READ_HOLD	
*	(RW)   _EMIF_CE3CTL1_WRITE_HOLD_MSB	/ _EMIF_CE3CTL1_WRITE_HOLD Added 26 Mar 2003
*	(RW)   _EMIF_CE3CTL1_MTYPE	
*	(RW)   _EMIF_CE3CTL1_READ_STROBE	
*	(RW)   _EMIF_CE3CTL1_TA	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE3CTL1_READ_HOLD:	
\*----------------------------------------------------------------*/

#define _EMIF_CE3CTL1_READ_HOLD_SHIFT		(000000u)
#define _EMIF_CE3CTL1_READ_HOLD_MK(n)		(((Uint16)(n) & 0x0007u) << _EMIF_CE3CTL1_READ_HOLD_SHIFT)
#define _EMIF_CE3CTL1_READ_HOLD_MASK		(_EMIF_CE3CTL1_READ_HOLD_MK(0x0007u))
#define _EMIF_CE3CTL1_READ_HOLD_CLR		      (~(_EMIF_CE3CTL1_READ_HOLD_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE3CTL1_WRITE_HOLD_MSB:	
\*----------------------------------------------------------------*/

#define _EMIF_CE3CTL1_WRITE_HOLD_MSB_SHIFT      (0x0003u)
#define _EMIF_CE3CTL1_WRITE_HOLD_MSB_MK(n)	(((Uint16)(n) & 0x0001u) << _EMIF_CE3CTL1_WRITE_HOLD_MSB_SHIFT)
#define _EMIF_CE3CTL1_WRITE_HOLD_MSB_MASK		(_EMIF_CE3CTL1_WRITE_HOLD_MSB_MK(0x0001u))
#define _EMIF_CE3CTL1_WRITE_HOLD_MSB_CLR		(~(_EMIF_CE3CTL1_WRITE_HOLD_MSB_MASK))


/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE3CTL1_WRITE_HOLD:	
\*----------------------------------------------------------------*/

#define _EMIF_CE3CTL1_WRITE_HOLD_SHIFT		(0x0003u)
#define _EMIF_CE3CTL1_WRITE_HOLD_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE3CTL1_WRITE_HOLD_SHIFT)
#define _EMIF_CE3CTL1_WRITE_HOLD_MASK		(_EMIF_CE3CTL1_WRITE_HOLD_MK(0x0001u))
#define _EMIF_CE3CTL1_WRITE_HOLD_CLR		(~(_EMIF_CE3CTL1_WRITE_HOLD_MASK))


/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE3CTL1_MTYPE:	
\*----------------------------------------------------------------*/

#define _EMIF_CE3CTL1_MTYPE_SHIFT		(0x0004u)
#define _EMIF_CE3CTL1_MTYPE_MK(n)		(((Uint16)(n) & 0x000fu) << _EMIF_CE3CTL1_MTYPE_SHIFT)
#define _EMIF_CE3CTL1_MTYPE_MASK		(_EMIF_CE3CTL1_MTYPE_MK(0x000fu))
#define _EMIF_CE3CTL1_MTYPE_CLR		(~(_EMIF_CE3CTL1_MTYPE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE3CTL1_READ_STROBE:	
\*----------------------------------------------------------------*/

#define _EMIF_CE3CTL1_READ_STROBE_SHIFT		(0x0008u)
#define _EMIF_CE3CTL1_READ_STROBE_MK(n)		(((Uint16)(n) & 0x003fu) << _EMIF_CE3CTL1_READ_STROBE_SHIFT)
#define _EMIF_CE3CTL1_READ_STROBE_MASK		(_EMIF_CE3CTL1_READ_STROBE_MK(0x003fu))
#define _EMIF_CE3CTL1_READ_STROBE_CLR		(~(_EMIF_CE3CTL1_READ_STROBE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE3CTL1_TA:	
\*----------------------------------------------------------------*/

#define _EMIF_CE3CTL1_TA_SHIFT		(0x000eu)
#define _EMIF_CE3CTL1_TA_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE3CTL1_TA_SHIFT)
#define _EMIF_CE3CTL1_TA_MASK		(_EMIF_CE3CTL1_TA_MK(0x0003u))
#define _EMIF_CE3CTL1_TA_CLR		(~(_EMIF_CE3CTL1_TA_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the CE3SEC1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _EMIF_CE3SEC1	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_CE3SEC1_SYNCRL	
*	(RW)   _EMIF_CE3SEC1_SYNCWL	
*	(RW)   _EMIF_CE3SEC1_CEEXT	
*	(RW)   _EMIF_CE3SEC1_REN    / _EMIF_CE3SEC1_RENEN	Added 26 Mar 2003
*	(RW)   _EMIF_CE3SEC1_SNCCLK	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE3SEC1_SYNCRL:	
\*----------------------------------------------------------------*/

#define _EMIF_CE3SEC1_SYNCRL_SHIFT		(000000u)
#define _EMIF_CE3SEC1_SYNCRL_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE3SEC1_SYNCRL_SHIFT)
#define _EMIF_CE3SEC1_SYNCRL_MASK		(_EMIF_CE3SEC1_SYNCRL_MK(0x0003u))
#define _EMIF_CE3SEC1_SYNCRL_CLR		(~(_EMIF_CE3SEC1_SYNCRL_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE3SEC1_SYNCWL:	
\*----------------------------------------------------------------*/

#define _EMIF_CE3SEC1_SYNCWL_SHIFT		(0x0002u)
#define _EMIF_CE3SEC1_SYNCWL_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE3SEC1_SYNCWL_SHIFT)
#define _EMIF_CE3SEC1_SYNCWL_MASK		(_EMIF_CE3SEC1_SYNCWL_MK(0x0003u))
#define _EMIF_CE3SEC1_SYNCWL_CLR		(~(_EMIF_CE3SEC1_SYNCWL_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE3SEC1_CEEXT:	
\*----------------------------------------------------------------*/

#define _EMIF_CE3SEC1_CEEXT_SHIFT		(0x0004u)
#define _EMIF_CE3SEC1_CEEXT_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE3SEC1_CEEXT_SHIFT)
#define _EMIF_CE3SEC1_CEEXT_MASK		(_EMIF_CE3SEC1_CEEXT_MK(0x0001u))
#define _EMIF_CE3SEC1_CEEXT_CLR		(~(_EMIF_CE3SEC1_CEEXT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE3SEC1_REN:	
\*----------------------------------------------------------------*/

#define _EMIF_CE3SEC1_REN_SHIFT		(0x0005u)
#define _EMIF_CE3SEC1_REN_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE3SEC1_REN_SHIFT)
#define _EMIF_CE3SEC1_REN_MASK		(_EMIF_CE3SEC1_REN_MK(0x0001u))
#define _EMIF_CE3SEC1_REN_CLR		(~(_EMIF_CE3SEC1_REN_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE3SEC1_RENEN:	
\*----------------------------------------------------------------*/

#define _EMIF_CE3SEC1_RENEN_SHIFT		(0x0005u)
#define _EMIF_CE3SEC1_RENEN_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE3SEC1_RENEN_SHIFT)
#define _EMIF_CE3SEC1_RENEN_MASK		(_EMIF_CE3SEC1_RENEN_MK(0x0001u))
#define _EMIF_CE3SEC1_RENEN_CLR		(~(_EMIF_CE3SEC1_RENEN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE3SEC1_SNCCLK:	
\*----------------------------------------------------------------*/

#define _EMIF_CE3SEC1_SNCCLK_SHIFT		(0x0006u)
#define _EMIF_CE3SEC1_SNCCLK_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE3SEC1_SNCCLK_SHIFT)
#define _EMIF_CE3SEC1_SNCCLK_MASK		(_EMIF_CE3SEC1_SNCCLK_MK(0x0001u))
#define _EMIF_CE3SEC1_SNCCLK_CLR		(~(_EMIF_CE3SEC1_SNCCLK_MASK))


/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the CE3CTL2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _EMIF_CE3CTL2	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_CE3CTL2_READ_SETUP	
*	(RW)   _EMIF_CE3CTL2_WRITE_HOLD	
*	(RW)   _EMIF_CE3CTL2_WRITE_STROBE	
*	(RW)   _EMIF_CE3CTL2_WRITE_SETUP	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE3CTL2_READ_SETUP:	
\*----------------------------------------------------------------*/

#define _EMIF_CE3CTL2_READ_SETUP_SHIFT		(000000u)
#define _EMIF_CE3CTL2_READ_SETUP_MK(n)		(((Uint16)(n) & 0x000fu) << _EMIF_CE3CTL2_READ_SETUP_SHIFT)
#define _EMIF_CE3CTL2_READ_SETUP_MASK		(_EMIF_CE3CTL2_READ_SETUP_MK(0x000fu))
#define _EMIF_CE3CTL2_READ_SETUP_CLR		(~(_EMIF_CE3CTL2_READ_SETUP_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE3CTL2_WRITE_HOLD:	
\*----------------------------------------------------------------*/

#define _EMIF_CE3CTL2_WRITE_HOLD_SHIFT		(0x0004u)
#define _EMIF_CE3CTL2_WRITE_HOLD_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE3CTL2_WRITE_HOLD_SHIFT)
#define _EMIF_CE3CTL2_WRITE_HOLD_MASK		(_EMIF_CE3CTL2_WRITE_HOLD_MK(0x0003u))
#define _EMIF_CE3CTL2_WRITE_HOLD_CLR		(~(_EMIF_CE3CTL2_WRITE_HOLD_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE3CTL2_WRITE_STROBE:	
\*----------------------------------------------------------------*/

#define _EMIF_CE3CTL2_WRITE_STROBE_SHIFT		(0x0006u)
#define _EMIF_CE3CTL2_WRITE_STROBE_MK(n)		(((Uint16)(n) & 0x003fu) << _EMIF_CE3CTL2_WRITE_STROBE_SHIFT)
#define _EMIF_CE3CTL2_WRITE_STROBE_MASK		(_EMIF_CE3CTL2_WRITE_STROBE_MK(0x003fu))
#define _EMIF_CE3CTL2_WRITE_STROBE_CLR		(~(_EMIF_CE3CTL2_WRITE_STROBE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE3CTL2_WRITE_SETUP:	
\*----------------------------------------------------------------*/

#define _EMIF_CE3CTL2_WRITE_SETUP_SHIFT		(0x000cu)
#define _EMIF_CE3CTL2_WRITE_SETUP_MK(n)		(((Uint16)(n) & 0x000fu) << _EMIF_CE3CTL2_WRITE_SETUP_SHIFT)
#define _EMIF_CE3CTL2_WRITE_SETUP_MASK		(_EMIF_CE3CTL2_WRITE_SETUP_MK(0x000fu))
#define _EMIF_CE3CTL2_WRITE_SETUP_CLR		(~(_EMIF_CE3CTL2_WRITE_SETUP_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the CE0CTL1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _EMIF_CE0CTL1	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_CE0CTL1_READ_HOLD	
*	(RW)   _EMIF_CE0CTL1_WRITE_HOLD_MSB	/_EMIF_CE0CTL1_WRITE_HOLD
*	(RW)   _EMIF_CE0CTL1_MTYPE	
*	(RW)   _EMIF_CE0CTL1_READ_STROBE	
*	(RW)   _EMIF_CE0CTL1_TA	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE0CTL1_READ_HOLD:	
\*----------------------------------------------------------------*/

#define _EMIF_CE0CTL1_READ_HOLD_SHIFT		(000000u)
#define _EMIF_CE0CTL1_READ_HOLD_MK(n)		(((Uint16)(n) & 0x0007u) << _EMIF_CE0CTL1_READ_HOLD_SHIFT)
#define _EMIF_CE0CTL1_READ_HOLD_MASK		(_EMIF_CE0CTL1_READ_HOLD_MK(0x0007u))
#define _EMIF_CE0CTL1_READ_HOLD_CLR		(~(_EMIF_CE0CTL1_READ_HOLD_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE0CTL1_WRITE_HOLD:	
\*----------------------------------------------------------------*/

#define _EMIF_CE0CTL1_WRITE_HOLD_SHIFT		(0x0003u)
#define _EMIF_CE0CTL1_WRITE_HOLD_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE0CTL1_WRITE_HOLD_SHIFT)
#define _EMIF_CE0CTL1_WRITE_HOLD_MASK		(_EMIF_CE0CTL1_WRITE_HOLD_MK(0x0001u))
#define _EMIF_CE0CTL1_WRITE_HOLD_CLR		(~(_EMIF_CE0CTL1_WRITE_HOLD_MASK))


/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE0CTL1_WRITE_HOLD_MSB:	
\*----------------------------------------------------------------*/

#define _EMIF_CE0CTL1_WRITE_HOLD_MSB_SHIFT		(0x0003u)
#define _EMIF_CE0CTL1_WRITE_HOLD_MSB_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE0CTL1_WRITE_HOLD_MSB_SHIFT)
#define _EMIF_CE0CTL1_WRITE_HOLD_MSB_MASK		(_EMIF_CE0CTL1_WRITE_HOLD_MSB_MK(0x0001u))
#define _EMIF_CE0CTL1_WRITE_HOLD_MSB_CLR		(~(_EMIF_CE0CTL1_WRITE_HOLD_MSB_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE0CTL1_MTYPE:	
\*----------------------------------------------------------------*/

#define _EMIF_CE0CTL1_MTYPE_SHIFT		(0x0004u)
#define _EMIF_CE0CTL1_MTYPE_MK(n)		(((Uint16)(n) & 0x000fu) << _EMIF_CE0CTL1_MTYPE_SHIFT)
#define _EMIF_CE0CTL1_MTYPE_MASK		(_EMIF_CE0CTL1_MTYPE_MK(0x000fu))
#define _EMIF_CE0CTL1_MTYPE_CLR		(~(_EMIF_CE0CTL1_MTYPE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE0CTL1_READ_STROBE:	
\*----------------------------------------------------------------*/

#define _EMIF_CE0CTL1_READ_STROBE_SHIFT		(0x0008u)
#define _EMIF_CE0CTL1_READ_STROBE_MK(n)		(((Uint16)(n) & 0x003fu) << _EMIF_CE0CTL1_READ_STROBE_SHIFT)
#define _EMIF_CE0CTL1_READ_STROBE_MASK		(_EMIF_CE0CTL1_READ_STROBE_MK(0x003fu))
#define _EMIF_CE0CTL1_READ_STROBE_CLR		(~(_EMIF_CE0CTL1_READ_STROBE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE0CTL1_TA:	
\*----------------------------------------------------------------*/

#define _EMIF_CE0CTL1_TA_SHIFT		(0x000eu)
#define _EMIF_CE0CTL1_TA_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE0CTL1_TA_SHIFT)
#define _EMIF_CE0CTL1_TA_MASK		(_EMIF_CE0CTL1_TA_MK(0x0003u))
#define _EMIF_CE0CTL1_TA_CLR		(~(_EMIF_CE0CTL1_TA_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the CE0SEC1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _EMIF_CE0SEC1	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_CE0SEC1_SYNCRL	
*	(RW)   _EMIF_CE0SEC1_SYNCWL	
*	(RW)   _EMIF_CE0SEC1_CEEXT	
*	(RW)   _EMIF_CE0SEC1_REN	/ _EMIF_CE0SEC1_RENEN Added 26 Mar 2003
*	(RW)   _EMIF_CE0SEC1_SNCCLK	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE0SEC1_SYNCRL:	
\*----------------------------------------------------------------*/

#define _EMIF_CE0SEC1_SYNCRL_SHIFT		(000000u)
#define _EMIF_CE0SEC1_SYNCRL_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE0SEC1_SYNCRL_SHIFT)
#define _EMIF_CE0SEC1_SYNCRL_MASK		(_EMIF_CE0SEC1_SYNCRL_MK(0x0003u))
#define _EMIF_CE0SEC1_SYNCRL_CLR		(~(_EMIF_CE0SEC1_SYNCRL_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE0SEC1_SYNCWL:	
\*----------------------------------------------------------------*/

#define _EMIF_CE0SEC1_SYNCWL_SHIFT		(0x0002u)
#define _EMIF_CE0SEC1_SYNCWL_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE0SEC1_SYNCWL_SHIFT)
#define _EMIF_CE0SEC1_SYNCWL_MASK		(_EMIF_CE0SEC1_SYNCWL_MK(0x0003u))
#define _EMIF_CE0SEC1_SYNCWL_CLR		(~(_EMIF_CE0SEC1_SYNCWL_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE0SEC1_CEEXT:	
\*----------------------------------------------------------------*/

#define _EMIF_CE0SEC1_CEEXT_SHIFT		(0x0004u)
#define _EMIF_CE0SEC1_CEEXT_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE0SEC1_CEEXT_SHIFT)
#define _EMIF_CE0SEC1_CEEXT_MASK		(_EMIF_CE0SEC1_CEEXT_MK(0x0001u))
#define _EMIF_CE0SEC1_CEEXT_CLR		(~(_EMIF_CE0SEC1_CEEXT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE0SEC1_REN:	
\*----------------------------------------------------------------*/

#define _EMIF_CE0SEC1_REN_SHIFT		(0x0005u)
#define _EMIF_CE0SEC1_REN_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE0SEC1_REN_SHIFT)
#define _EMIF_CE0SEC1_REN_MASK		(_EMIF_CE0SEC1_REN_MK(0x0001u))
#define _EMIF_CE0SEC1_REN_CLR		(~(_EMIF_CE0SEC1_REN_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE0SEC1_RENEN:	
\*----------------------------------------------------------------*/

#define _EMIF_CE0SEC1_RENEN_SHIFT		(0x0005u)
#define _EMIF_CE0SEC1_RENEN_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE0SEC1_RENEN_SHIFT)
#define _EMIF_CE0SEC1_RENEN_MASK		(_EMIF_CE0SEC1_RENEN_MK(0x0001u))
#define _EMIF_CE0SEC1_RENEN_CLR		(~(_EMIF_CE0SEC1_RENEN_MASK))


/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE0SEC1_SNCCLK:	
\*----------------------------------------------------------------*/

#define _EMIF_CE0SEC1_SNCCLK_SHIFT		(0x0006u)
#define _EMIF_CE0SEC1_SNCCLK_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE0SEC1_SNCCLK_SHIFT)
#define _EMIF_CE0SEC1_SNCCLK_MASK		(_EMIF_CE0SEC1_SNCCLK_MK(0x0001u))
#define _EMIF_CE0SEC1_SNCCLK_CLR		(~(_EMIF_CE0SEC1_SNCCLK_MASK))


/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the CE0CTL2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _EMIF_CE0CTL2	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_CE0CTL2_READ_SETUP	
*	(RW)   _EMIF_CE0CTL2_WRITE_HOLD	
*	(RW)   _EMIF_CE0CTL2_WRITE_STROBE	
*	(RW)   _EMIF_CE0CTL2_WRITE_SETUP	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE0CTL2_READ_SETUP:	
\*----------------------------------------------------------------*/

#define _EMIF_CE0CTL2_READ_SETUP_SHIFT		(000000u)
#define _EMIF_CE0CTL2_READ_SETUP_MK(n)		(((Uint16)(n) & 0x000fu) << _EMIF_CE0CTL2_READ_SETUP_SHIFT)
#define _EMIF_CE0CTL2_READ_SETUP_MASK		(_EMIF_CE0CTL2_READ_SETUP_MK(0x000fu))
#define _EMIF_CE0CTL2_READ_SETUP_CLR		(~(_EMIF_CE0CTL2_READ_SETUP_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE0CTL2_WRITE_HOLD:	
\*----------------------------------------------------------------*/

#define _EMIF_CE0CTL2_WRITE_HOLD_SHIFT		(0x0004u)
#define _EMIF_CE0CTL2_WRITE_HOLD_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE0CTL2_WRITE_HOLD_SHIFT)
#define _EMIF_CE0CTL2_WRITE_HOLD_MASK		(_EMIF_CE0CTL2_WRITE_HOLD_MK(0x0003u))
#define _EMIF_CE0CTL2_WRITE_HOLD_CLR		(~(_EMIF_CE0CTL2_WRITE_HOLD_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE0CTL2_WRITE_STROBE:	
\*----------------------------------------------------------------*/

#define _EMIF_CE0CTL2_WRITE_STROBE_SHIFT		(0x0006u)
#define _EMIF_CE0CTL2_WRITE_STROBE_MK(n)		(((Uint16)(n) & 0x003fu) << _EMIF_CE0CTL2_WRITE_STROBE_SHIFT)
#define _EMIF_CE0CTL2_WRITE_STROBE_MASK		(_EMIF_CE0CTL2_WRITE_STROBE_MK(0x003fu))
#define _EMIF_CE0CTL2_WRITE_STROBE_CLR		(~(_EMIF_CE0CTL2_WRITE_STROBE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE0CTL2_WRITE_SETUP:	
\*----------------------------------------------------------------*/

#define _EMIF_CE0CTL2_WRITE_SETUP_SHIFT		(0x000cu)
#define _EMIF_CE0CTL2_WRITE_SETUP_MK(n)		(((Uint16)(n) & 0x000fu) << _EMIF_CE0CTL2_WRITE_SETUP_SHIFT)
#define _EMIF_CE0CTL2_WRITE_SETUP_MASK		(_EMIF_CE0CTL2_WRITE_SETUP_MK(0x000fu))
#define _EMIF_CE0CTL2_WRITE_SETUP_CLR		(~(_EMIF_CE0CTL2_WRITE_SETUP_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the SDCTL1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _EMIF_SDCTL1	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_SDCTL1_SLFRFR	
*	(RW)   _EMIF_SDCTL1_TRC	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDCTL1_SLFRFR:	
\*----------------------------------------------------------------*/

#define _EMIF_SDCTL1_SLFRFR_SHIFT		(000000u)
#define _EMIF_SDCTL1_SLFRFR_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_SDCTL1_SLFRFR_SHIFT)
#define _EMIF_SDCTL1_SLFRFR_MASK		(_EMIF_SDCTL1_SLFRFR_MK(0x0001u))
#define _EMIF_SDCTL1_SLFRFR_CLR		(~(_EMIF_SDCTL1_SLFRFR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDCTL1_TRC:	
\*----------------------------------------------------------------*/

#define _EMIF_SDCTL1_TRC_SHIFT		(0x000cu)
#define _EMIF_SDCTL1_TRC_MK(n)		(((Uint16)(n) & 0x000fu) << _EMIF_SDCTL1_TRC_SHIFT)
#define _EMIF_SDCTL1_TRC_MASK		(_EMIF_SDCTL1_TRC_MK(0x000fu))
#define _EMIF_SDCTL1_TRC_CLR		(~(_EMIF_SDCTL1_TRC_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the SDCTL2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _EMIF_SDCTL2	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_SDCTL2_TRP	
*	(RW)   _EMIF_SDCTL2_TRCD	
*	(RW)   _EMIF_SDCTL2_INIT	
*	(RW)   _EMIF_SDCTL2_RFEN	
*	(RW)   _EMIF_SDCTL2_SDWTH	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDCTL2_TRP:	
\*----------------------------------------------------------------*/

#define _EMIF_SDCTL2_TRP_SHIFT		(000000u)
#define _EMIF_SDCTL2_TRP_MK(n)		(((Uint16)(n) & 0x000fu) << _EMIF_SDCTL2_TRP_SHIFT)
#define _EMIF_SDCTL2_TRP_MASK		(_EMIF_SDCTL2_TRP_MK(0x000fu))
#define _EMIF_SDCTL2_TRP_CLR		(~(_EMIF_SDCTL2_TRP_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDCTL2_TRCD:	
\*----------------------------------------------------------------*/

#define _EMIF_SDCTL2_TRCD_SHIFT		(0x0004u)
#define _EMIF_SDCTL2_TRCD_MK(n)		(((Uint16)(n) & 0x000fu) << _EMIF_SDCTL2_TRCD_SHIFT)
#define _EMIF_SDCTL2_TRCD_MASK		(_EMIF_SDCTL2_TRCD_MK(0x000fu))
#define _EMIF_SDCTL2_TRCD_CLR		(~(_EMIF_SDCTL2_TRCD_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDCTL2_INIT:	
\*----------------------------------------------------------------*/

#define _EMIF_SDCTL2_INIT_SHIFT		(0x0008u)
#define _EMIF_SDCTL2_INIT_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_SDCTL2_INIT_SHIFT)
#define _EMIF_SDCTL2_INIT_MASK		(_EMIF_SDCTL2_INIT_MK(0x0001u))
#define _EMIF_SDCTL2_INIT_CLR		(~(_EMIF_SDCTL2_INIT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDCTL2_RFEN:	
\*----------------------------------------------------------------*/

#define _EMIF_SDCTL2_RFEN_SHIFT		(0x0009u)
#define _EMIF_SDCTL2_RFEN_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_SDCTL2_RFEN_SHIFT)
#define _EMIF_SDCTL2_RFEN_MASK		(_EMIF_SDCTL2_RFEN_MK(0x0001u))
#define _EMIF_SDCTL2_RFEN_CLR		(~(_EMIF_SDCTL2_RFEN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDCTL2_SDWTH:	
\*----------------------------------------------------------------*/

#define _EMIF_SDCTL2_SDWTH_SHIFT		(0x000au)
#define _EMIF_SDCTL2_SDWTH_MK(n)		(((Uint16)(n) & 0x001fu) << _EMIF_SDCTL2_SDWTH_SHIFT)
#define _EMIF_SDCTL2_SDWTH_MASK		(_EMIF_SDCTL2_SDWTH_MK(0x001fu))
#define _EMIF_SDCTL2_SDWTH_CLR		(~(_EMIF_SDCTL2_SDWTH_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the CE1CTL1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _EMIF_CE1CTL1	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_CE1CTL1_READ_HOLD	
*	(RW)   _EMIF_CE1CTL1_WRITE_HOLD_MSB	/ _EMIF_CE1CTL1_WRITE_HOLD
*	(RW)   _EMIF_CE1CTL1_MTYPE	
*	(RW)   _EMIF_CE1CTL1_READ_STROBE	
*	(RW)   _EMIF_CE1CTL1_TA	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE1CTL1_READ_HOLD:	
\*----------------------------------------------------------------*/

#define _EMIF_CE1CTL1_READ_HOLD_SHIFT		(000000u)
#define _EMIF_CE1CTL1_READ_HOLD_MK(n)		(((Uint16)(n) & 0x0007u) << _EMIF_CE1CTL1_READ_HOLD_SHIFT)
#define _EMIF_CE1CTL1_READ_HOLD_MASK		(_EMIF_CE1CTL1_READ_HOLD_MK(0x0007u))
#define _EMIF_CE1CTL1_READ_HOLD_CLR		(~(_EMIF_CE1CTL1_READ_HOLD_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE1CTL1_WRITE_HOLD_MSB:	
\*----------------------------------------------------------------*/

#define _EMIF_CE1CTL1_WRITE_HOLD_MSB_SHIFT		(0x0003u)
#define _EMIF_CE1CTL1_WRITE_HOLD_MSB_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE1CTL1_WRITE_HOLD_MSB_SHIFT)
#define _EMIF_CE1CTL1_WRITE_HOLD_MSB_MASK		(_EMIF_CE1CTL1_WRITE_HOLD_MSB_MK(0x0001u))
#define _EMIF_CE1CTL1_WRITE_HOLD_MSB_CLR		(~(_EMIF_CE1CTL1_WRITE_HOLD_MSB_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE1CTL1_WRITE_HOLD:	
\*----------------------------------------------------------------*/

#define _EMIF_CE1CTL1_WRITE_HOLD_SHIFT		(0x0003u)
#define _EMIF_CE1CTL1_WRITE_HOLD_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE1CTL1_WRITE_HOLD_SHIFT)
#define _EMIF_CE1CTL1_WRITE_HOLD_MASK		(_EMIF_CE1CTL1_WRITE_HOLD_MK(0x0001u))
#define _EMIF_CE1CTL1_WRITE_HOLD_CLR		(~(_EMIF_CE1CTL1_WRITE_HOLD_MASK))


/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE1CTL1_MTYPE:	
\*----------------------------------------------------------------*/

#define _EMIF_CE1CTL1_MTYPE_SHIFT		(0x0004u)
#define _EMIF_CE1CTL1_MTYPE_MK(n)		(((Uint16)(n) & 0x000fu) << _EMIF_CE1CTL1_MTYPE_SHIFT)
#define _EMIF_CE1CTL1_MTYPE_MASK		(_EMIF_CE1CTL1_MTYPE_MK(0x000fu))
#define _EMIF_CE1CTL1_MTYPE_CLR		(~(_EMIF_CE1CTL1_MTYPE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE1CTL1_READ_STROBE:	
\*----------------------------------------------------------------*/

#define _EMIF_CE1CTL1_READ_STROBE_SHIFT		(0x0008u)
#define _EMIF_CE1CTL1_READ_STROBE_MK(n)		(((Uint16)(n) & 0x003fu) << _EMIF_CE1CTL1_READ_STROBE_SHIFT)
#define _EMIF_CE1CTL1_READ_STROBE_MASK		(_EMIF_CE1CTL1_READ_STROBE_MK(0x003fu))
#define _EMIF_CE1CTL1_READ_STROBE_CLR		(~(_EMIF_CE1CTL1_READ_STROBE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE1CTL1_TA:	
\*----------------------------------------------------------------*/

#define _EMIF_CE1CTL1_TA_SHIFT		(0x000eu)
#define _EMIF_CE1CTL1_TA_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE1CTL1_TA_SHIFT)
#define _EMIF_CE1CTL1_TA_MASK		(_EMIF_CE1CTL1_TA_MK(0x0003u))
#define _EMIF_CE1CTL1_TA_CLR		(~(_EMIF_CE1CTL1_TA_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the CE1SEC1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _EMIF_CE1SEC1	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_CE1SEC1_SYNCRL	
*	(RW)   _EMIF_CE1SEC1_SYNCWL	
*	(RW)   _EMIF_CE1SEC1_CEEXT	
*	(RW)   _EMIF_CE1SEC1_REN   / _EMIF_CE1SEC1_RENEN   Added 26 Mar 2003	
*	(RW)   _EMIF_CE1SEC1_SNCCLK
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE1SEC1_SYNCRL:	
\*----------------------------------------------------------------*/

#define _EMIF_CE1SEC1_SYNCRL_SHIFT		(000000u)
#define _EMIF_CE1SEC1_SYNCRL_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE1SEC1_SYNCRL_SHIFT)
#define _EMIF_CE1SEC1_SYNCRL_MASK		(_EMIF_CE1SEC1_SYNCRL_MK(0x0003u))
#define _EMIF_CE1SEC1_SYNCRL_CLR		(~(_EMIF_CE1SEC1_SYNCRL_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE1SEC1_SYNCWL:	
\*----------------------------------------------------------------*/

#define _EMIF_CE1SEC1_SYNCWL_SHIFT		(0x0002u)
#define _EMIF_CE1SEC1_SYNCWL_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE1SEC1_SYNCWL_SHIFT)
#define _EMIF_CE1SEC1_SYNCWL_MASK		(_EMIF_CE1SEC1_SYNCWL_MK(0x0003u))
#define _EMIF_CE1SEC1_SYNCWL_CLR		(~(_EMIF_CE1SEC1_SYNCWL_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE1SEC1_CEEXT:	
\*----------------------------------------------------------------*/

#define _EMIF_CE1SEC1_CEEXT_SHIFT		(0x0004u)
#define _EMIF_CE1SEC1_CEEXT_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE1SEC1_CEEXT_SHIFT)
#define _EMIF_CE1SEC1_CEEXT_MASK		(_EMIF_CE1SEC1_CEEXT_MK(0x0001u))
#define _EMIF_CE1SEC1_CEEXT_CLR		(~(_EMIF_CE1SEC1_CEEXT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE1SEC1_REN:	
\*----------------------------------------------------------------*/

#define _EMIF_CE1SEC1_REN_SHIFT		(0x0005u)
#define _EMIF_CE1SEC1_REN_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE1SEC1_REN_SHIFT)
#define _EMIF_CE1SEC1_REN_MASK		(_EMIF_CE1SEC1_REN_MK(0x0001u))
#define _EMIF_CE1SEC1_REN_CLR		(~(_EMIF_CE1SEC1_REN_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE1SEC1_RENEN:	
\*----------------------------------------------------------------*/

#define _EMIF_CE1SEC1_RENEN_SHIFT		(0x0005u)
#define _EMIF_CE1SEC1_RENEN_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE1SEC1_RENEN_SHIFT)
#define _EMIF_CE1SEC1_RENEN_MASK		(_EMIF_CE1SEC1_RENEN_MK(0x0001u))
#define _EMIF_CE1SEC1_RENEN_CLR		(~(_EMIF_CE1SEC1_RENEN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE1SEC1_SNCCLK:	
\*----------------------------------------------------------------*/

#define _EMIF_CE1SEC1_SNCCLK_SHIFT		(0x0006u)
#define _EMIF_CE1SEC1_SNCCLK_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE1SEC1_SNCCLK_SHIFT)
#define _EMIF_CE1SEC1_SNCCLK_MASK		(_EMIF_CE1SEC1_SNCCLK_MK(0x0001u))
#define _EMIF_CE1SEC1_SNCCLK_CLR		(~(_EMIF_CE1SEC1_SNCCLK_MASK))


/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the SDEXT1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _EMIF_SDEXT1	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_SDEXT1_TCL	
*	(RW)   _EMIF_SDEXT1_TRAS	
*	(RW)   _EMIF_SDEXT1_TRRD	
*	(RW)   _EMIF_SDEXT1_TWR	
*	(RW)   _EMIF_SDEXT1_THZP	
*	(RW)   _EMIF_SDEXT1_RD2RD	
*	(RW)   _EMIF_SDEXT1_RD2DEAC	
*	(RW)   _EMIF_SDEXT1_RD2WR	
*	(RW)   _EMIF_SDEXT1_R2WDQM	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDEXT1_TCL:	
\*----------------------------------------------------------------*/

#define _EMIF_SDEXT1_TCL_SHIFT		(000000u)
#define _EMIF_SDEXT1_TCL_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_SDEXT1_TCL_SHIFT)
#define _EMIF_SDEXT1_TCL_MASK		(_EMIF_SDEXT1_TCL_MK(0x0001u))
#define _EMIF_SDEXT1_TCL_CLR		(~(_EMIF_SDEXT1_TCL_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDEXT1_TRAS:	
\*----------------------------------------------------------------*/

#define _EMIF_SDEXT1_TRAS_SHIFT		(0x0001u)
#define _EMIF_SDEXT1_TRAS_MK(n)		(((Uint16)(n) & 0x0007u) << _EMIF_SDEXT1_TRAS_SHIFT)
#define _EMIF_SDEXT1_TRAS_MASK		(_EMIF_SDEXT1_TRAS_MK(0x0007u))
#define _EMIF_SDEXT1_TRAS_CLR		(~(_EMIF_SDEXT1_TRAS_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDEXT1_TRRD:	
\*----------------------------------------------------------------*/

#define _EMIF_SDEXT1_TRRD_SHIFT		(0x0004u)
#define _EMIF_SDEXT1_TRRD_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_SDEXT1_TRRD_SHIFT)
#define _EMIF_SDEXT1_TRRD_MASK		(_EMIF_SDEXT1_TRRD_MK(0x0001u))
#define _EMIF_SDEXT1_TRRD_CLR		(~(_EMIF_SDEXT1_TRRD_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDEXT1_TWR:	
\*----------------------------------------------------------------*/

#define _EMIF_SDEXT1_TWR_SHIFT		(0x0005u)
#define _EMIF_SDEXT1_TWR_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_SDEXT1_TWR_SHIFT)
#define _EMIF_SDEXT1_TWR_MASK		(_EMIF_SDEXT1_TWR_MK(0x0003u))
#define _EMIF_SDEXT1_TWR_CLR		(~(_EMIF_SDEXT1_TWR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDEXT1_THZP:	
\*----------------------------------------------------------------*/

#define _EMIF_SDEXT1_THZP_SHIFT		(0x0007u)
#define _EMIF_SDEXT1_THZP_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_SDEXT1_THZP_SHIFT)
#define _EMIF_SDEXT1_THZP_MASK		(_EMIF_SDEXT1_THZP_MK(0x0003u))
#define _EMIF_SDEXT1_THZP_CLR		(~(_EMIF_SDEXT1_THZP_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDEXT1_RD2RD:	
\*----------------------------------------------------------------*/

#define _EMIF_SDEXT1_RD2RD_SHIFT		(0x0009u)
#define _EMIF_SDEXT1_RD2RD_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_SDEXT1_RD2RD_SHIFT)
#define _EMIF_SDEXT1_RD2RD_MASK		(_EMIF_SDEXT1_RD2RD_MK(0x0001u))
#define _EMIF_SDEXT1_RD2RD_CLR		(~(_EMIF_SDEXT1_RD2RD_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDEXT1_RD2DEAC:	
\*----------------------------------------------------------------*/

#define _EMIF_SDEXT1_RD2DEAC_SHIFT		(0x000au)
#define _EMIF_SDEXT1_RD2DEAC_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_SDEXT1_RD2DEAC_SHIFT)
#define _EMIF_SDEXT1_RD2DEAC_MASK		(_EMIF_SDEXT1_RD2DEAC_MK(0x0003u))
#define _EMIF_SDEXT1_RD2DEAC_CLR		(~(_EMIF_SDEXT1_RD2DEAC_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDEXT1_RD2WR:	
\*----------------------------------------------------------------*/

#define _EMIF_SDEXT1_RD2WR_SHIFT		(0x000cu)
#define _EMIF_SDEXT1_RD2WR_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_SDEXT1_RD2WR_SHIFT)
#define _EMIF_SDEXT1_RD2WR_MASK		(_EMIF_SDEXT1_RD2WR_MK(0x0003u))
#define _EMIF_SDEXT1_RD2WR_CLR		(~(_EMIF_SDEXT1_RD2WR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDEXT1_R2WDQM:	
\*----------------------------------------------------------------*/

#define _EMIF_SDEXT1_R2WDQM_SHIFT		(0x000fu)
#define _EMIF_SDEXT1_R2WDQM_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_SDEXT1_R2WDQM_SHIFT)
#define _EMIF_SDEXT1_R2WDQM_MASK		(_EMIF_SDEXT1_R2WDQM_MK(0x0001u))
#define _EMIF_SDEXT1_R2WDQM_CLR		(~(_EMIF_SDEXT1_R2WDQM_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the CE1CTL2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _EMIF_CE1CTL2	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_CE1CTL2_READ_SETUP	
*	(RW)   _EMIF_CE1CTL2_WRITE_HOLD	
*	(RW)   _EMIF_CE1CTL2_WRITE_STROBE	
*	(RW)   _EMIF_CE1CTL2_WRITE_SETUP	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE1CTL2_READ_SETUP:	
\*----------------------------------------------------------------*/

#define _EMIF_CE1CTL2_READ_SETUP_SHIFT		(000000u)
#define _EMIF_CE1CTL2_READ_SETUP_MK(n)		(((Uint16)(n) & 0x000fu) << _EMIF_CE1CTL2_READ_SETUP_SHIFT)
#define _EMIF_CE1CTL2_READ_SETUP_MASK		(_EMIF_CE1CTL2_READ_SETUP_MK(0x000fu))
#define _EMIF_CE1CTL2_READ_SETUP_CLR		(~(_EMIF_CE1CTL2_READ_SETUP_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE1CTL2_WRITE_HOLD:	
\*----------------------------------------------------------------*/

#define _EMIF_CE1CTL2_WRITE_HOLD_SHIFT		(0x0004u)
#define _EMIF_CE1CTL2_WRITE_HOLD_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE1CTL2_WRITE_HOLD_SHIFT)
#define _EMIF_CE1CTL2_WRITE_HOLD_MASK		(_EMIF_CE1CTL2_WRITE_HOLD_MK(0x0003u))
#define _EMIF_CE1CTL2_WRITE_HOLD_CLR		(~(_EMIF_CE1CTL2_WRITE_HOLD_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE1CTL2_WRITE_STROBE:	
\*----------------------------------------------------------------*/

#define _EMIF_CE1CTL2_WRITE_STROBE_SHIFT		(0x0006u)
#define _EMIF_CE1CTL2_WRITE_STROBE_MK(n)		(((Uint16)(n) & 0x003fu) << _EMIF_CE1CTL2_WRITE_STROBE_SHIFT)
#define _EMIF_CE1CTL2_WRITE_STROBE_MASK		(_EMIF_CE1CTL2_WRITE_STROBE_MK(0x003fu))
#define _EMIF_CE1CTL2_WRITE_STROBE_CLR		(~(_EMIF_CE1CTL2_WRITE_STROBE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE1CTL2_WRITE_SETUP:	
\*----------------------------------------------------------------*/

#define _EMIF_CE1CTL2_WRITE_SETUP_SHIFT		(0x000cu)
#define _EMIF_CE1CTL2_WRITE_SETUP_MK(n)		(((Uint16)(n) & 0x000fu) << _EMIF_CE1CTL2_WRITE_SETUP_SHIFT)
#define _EMIF_CE1CTL2_WRITE_SETUP_MASK		(_EMIF_CE1CTL2_WRITE_SETUP_MK(0x000fu))
#define _EMIF_CE1CTL2_WRITE_SETUP_CLR		(~(_EMIF_CE1CTL2_WRITE_SETUP_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the SDEXT2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _EMIF_SDEXT2	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_SDEXT2_R2WDQM	
*	(RW)   _EMIF_SDEXT2_WR2WR	
*	(RW)   _EMIF_SDEXT2_WR2DEAC	
*	(RW)   _EMIF_SDEXT2_WR2RD	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDEXT2_R2WDQM:	
\*----------------------------------------------------------------*/

#define _EMIF_SDEXT2_R2WDQM_SHIFT		(000000u)
#define _EMIF_SDEXT2_R2WDQM_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_SDEXT2_R2WDQM_SHIFT)
#define _EMIF_SDEXT2_R2WDQM_MASK		(_EMIF_SDEXT2_R2WDQM_MK(0x0001u))
#define _EMIF_SDEXT2_R2WDQM_CLR		(~(_EMIF_SDEXT2_R2WDQM_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDEXT2_WR2WR:	
\*----------------------------------------------------------------*/

#define _EMIF_SDEXT2_WR2WR_SHIFT		(0x0001u)
#define _EMIF_SDEXT2_WR2WR_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_SDEXT2_WR2WR_SHIFT)
#define _EMIF_SDEXT2_WR2WR_MASK		(_EMIF_SDEXT2_WR2WR_MK(0x0003u))
#define _EMIF_SDEXT2_WR2WR_CLR		(~(_EMIF_SDEXT2_WR2WR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDEXT2_WR2DEAC:	
\*----------------------------------------------------------------*/

#define _EMIF_SDEXT2_WR2DEAC_SHIFT		(0x0002u)
#define _EMIF_SDEXT2_WR2DEAC_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_SDEXT2_WR2DEAC_SHIFT)
#define _EMIF_SDEXT2_WR2DEAC_MASK		(_EMIF_SDEXT2_WR2DEAC_MK(0x0003u))
#define _EMIF_SDEXT2_WR2DEAC_CLR		(~(_EMIF_SDEXT2_WR2DEAC_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDEXT2_WR2RD:	
\*----------------------------------------------------------------*/

#define _EMIF_SDEXT2_WR2RD_SHIFT		(0x0004u)
#define _EMIF_SDEXT2_WR2RD_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_SDEXT2_WR2RD_SHIFT)
#define _EMIF_SDEXT2_WR2RD_MASK		(_EMIF_SDEXT2_WR2RD_MK(0x0001u))
#define _EMIF_SDEXT2_WR2RD_CLR		(~(_EMIF_SDEXT2_WR2RD_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the SDTIM1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _EMIF_SDTIM1	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_SDTIM1_PERIOD	
*	(R)   _EMIF_SDTIM1_COUNTER	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDTIM1_PERIOD:	
\*----------------------------------------------------------------*/

#define _EMIF_SDTIM1_PERIOD_SHIFT		(000000u)
#define _EMIF_SDTIM1_PERIOD_MK(n)		(((Uint16)(n) & 0x0fffu) << _EMIF_SDTIM1_PERIOD_SHIFT)
#define _EMIF_SDTIM1_PERIOD_MASK		(_EMIF_SDTIM1_PERIOD_MK(0x0fffu))
#define _EMIF_SDTIM1_PERIOD_CLR		(~(_EMIF_SDTIM1_PERIOD_MASK))



/*----------------------------------------------------------------*\
*   (R)  _EMIF_SDTIM1_COUNTER:	
\*----------------------------------------------------------------*/

#define _EMIF_SDTIM1_COUNTER_SHIFT		(0x000cu)
#define _EMIF_SDTIM1_COUNTER_MK(n)		(((Uint16)(n) & 0x000fu) << _EMIF_SDTIM1_COUNTER_SHIFT)
#define _EMIF_SDTIM1_COUNTER_MASK		(_EMIF_SDTIM1_COUNTER_MK(0x000fu))
#define _EMIF_SDTIM1_COUNTER_CLR		(~(_EMIF_SDTIM1_COUNTER_MASK))


/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the SDRFR1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _EMIF_SDRFR1	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_SDRFR1_PERIOD	
*	(R)   _EMIF_SDRFR1_COUNTER	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDRFR1_PERIOD:	
\*----------------------------------------------------------------*/

#define _EMIF_SDRFR1_PERIOD_SHIFT		(000000u)
#define _EMIF_SDRFR1_PERIOD_MK(n)		(((Uint16)(n) & 0x0fffu) << _EMIF_SDRFR1_PERIOD_SHIFT)
#define _EMIF_SDRFR1_PERIOD_MASK		(_EMIF_SDRFR1_PERIOD_MK(0x0fffu))
#define _EMIF_SDRFR1_PERIOD_CLR		(~(_EMIF_SDRFR1_PERIOD_MASK))



/*----------------------------------------------------------------*\
*   (R)  _EMIF_SDRFR1_COUNTER:	
\*----------------------------------------------------------------*/

#define _EMIF_SDRFR1_COUNTER_SHIFT		(0x000cu)
#define _EMIF_SDRFR1_COUNTER_MK(n)		(((Uint16)(n) & 0x000fu) << _EMIF_SDRFR1_COUNTER_SHIFT)
#define _EMIF_SDRFR1_COUNTER_MASK		(_EMIF_SDRFR1_COUNTER_MK(0x000fu))
#define _EMIF_SDRFR1_COUNTER_CLR		(~(_EMIF_SDRFR1_COUNTER_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the GBLCTL1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _EMIF_GBLCTL1	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_GBLCTL1_EK1EN	
*	(RW)   _EMIF_GBLCTL1_EK1HZ	
*	(RW)   _EMIF_GBLCTL1_NOHOLD	
*	(R)   _EMIF_GBLCTL1_HOLDA	
*	(R)   _EMIF_GBLCTL1_HOLD	
*	(R)   _EMIF_GBLCTL1_ARDY	
*
\******************************************************************************/





/*----------------------------------------------------------------*\
*   (RW)  _EMIF_GBLCTL1_EK1EN:	
\*----------------------------------------------------------------*/

#define _EMIF_GBLCTL1_EK1EN_SHIFT		(0x0005u)
#define _EMIF_GBLCTL1_EK1EN_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_GBLCTL1_EK1EN_SHIFT)
#define _EMIF_GBLCTL1_EK1EN_MASK		(_EMIF_GBLCTL1_EK1EN_MK(0x0001u))
#define _EMIF_GBLCTL1_EK1EN_CLR		(~(_EMIF_GBLCTL1_EK1EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_GBLCTL1_EK1HZ:	
\*----------------------------------------------------------------*/

#define _EMIF_GBLCTL1_EK1HZ_SHIFT		(0x0006u)
#define _EMIF_GBLCTL1_EK1HZ_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_GBLCTL1_EK1HZ_SHIFT)
#define _EMIF_GBLCTL1_EK1HZ_MASK		(_EMIF_GBLCTL1_EK1HZ_MK(0x0001u))
#define _EMIF_GBLCTL1_EK1HZ_CLR		(~(_EMIF_GBLCTL1_EK1HZ_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_GBLCTL1_NOHOLD:	
\*----------------------------------------------------------------*/

#define _EMIF_GBLCTL1_NOHOLD_SHIFT		(0x0007u)
#define _EMIF_GBLCTL1_NOHOLD_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_GBLCTL1_NOHOLD_SHIFT)
#define _EMIF_GBLCTL1_NOHOLD_MASK		(_EMIF_GBLCTL1_NOHOLD_MK(0x0001u))
#define _EMIF_GBLCTL1_NOHOLD_CLR		(~(_EMIF_GBLCTL1_NOHOLD_MASK))



/*----------------------------------------------------------------*\
*   (R)  _EMIF_GBLCTL1_HOLDA:	
\*----------------------------------------------------------------*/

#define _EMIF_GBLCTL1_HOLDA_SHIFT		(0x0008u)
#define _EMIF_GBLCTL1_HOLDA_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_GBLCTL1_HOLDA_SHIFT)
#define _EMIF_GBLCTL1_HOLDA_MASK		(_EMIF_GBLCTL1_HOLDA_MK(0x0001u))
#define _EMIF_GBLCTL1_HOLDA_CLR		(~(_EMIF_GBLCTL1_HOLDA_MASK))



/*----------------------------------------------------------------*\
*   (R)  _EMIF_GBLCTL1_HOLD:	
\*----------------------------------------------------------------*/

#define _EMIF_GBLCTL1_HOLD_SHIFT		(0x0009u)
#define _EMIF_GBLCTL1_HOLD_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_GBLCTL1_HOLD_SHIFT)
#define _EMIF_GBLCTL1_HOLD_MASK		(_EMIF_GBLCTL1_HOLD_MK(0x0001u))
#define _EMIF_GBLCTL1_HOLD_CLR		(~(_EMIF_GBLCTL1_HOLD_MASK))



/*----------------------------------------------------------------*\
*   (R)  _EMIF_GBLCTL1_ARDY:	
\*----------------------------------------------------------------*/

#define _EMIF_GBLCTL1_ARDY_SHIFT		(0x000au)
#define _EMIF_GBLCTL1_ARDY_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_GBLCTL1_ARDY_SHIFT)
#define _EMIF_GBLCTL1_ARDY_MASK		(_EMIF_GBLCTL1_ARDY_MK(0x0001u))
#define _EMIF_GBLCTL1_ARDY_CLR		(~(_EMIF_GBLCTL1_ARDY_MASK))


/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the SDTIM2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _EMIF_SDTIM2	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_SDTIM2_COUNTER	
*	(RW)   _EMIF_SDTIM2_EXTRA_REFRESHES	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDTIM2_COUNTER:	
\*----------------------------------------------------------------*/

#define _EMIF_SDTIM2_COUNTER_SHIFT		(000000u)
#define _EMIF_SDTIM2_COUNTER_MK(n)		(((Uint16)(n) & 0x00ffu) << _EMIF_SDTIM2_COUNTER_SHIFT)
#define _EMIF_SDTIM2_COUNTER_MASK		(_EMIF_SDTIM2_COUNTER_MK(0x00ffu))
#define _EMIF_SDTIM2_COUNTER_CLR		(~(_EMIF_SDTIM2_COUNTER_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDTIM2_EXTRA_REFRESHES:	
\*----------------------------------------------------------------*/

#define _EMIF_SDTIM2_EXTRA_REFRESHES_SHIFT		(0x0008u)
#define _EMIF_SDTIM2_EXTRA_REFRESHES_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_SDTIM2_EXTRA_REFRESHES_SHIFT)
#define _EMIF_SDTIM2_EXTRA_REFRESHES_MASK		(_EMIF_SDTIM2_EXTRA_REFRESHES_MK(0x0003u))
#define _EMIF_SDTIM2_EXTRA_REFRESHES_CLR		(~(_EMIF_SDTIM2_EXTRA_REFRESHES_MASK))


/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the SDRFR2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _EMIF_SDRFR2	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_SDRFR2_COUNTER	
*	(RW)   _EMIF_SDRFR2_EXTRA_REFRESHES	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDRFR2_COUNTER:	
\*----------------------------------------------------------------*/

#define _EMIF_SDRFR2_COUNTER_SHIFT		(000000u)
#define _EMIF_SDRFR2_COUNTER_MK(n)		(((Uint16)(n) & 0x00ffu) << _EMIF_SDRFR2_COUNTER_SHIFT)
#define _EMIF_SDRFR2_COUNTER_MASK		(_EMIF_SDRFR2_COUNTER_MK(0x00ffu))
#define _EMIF_SDRFR2_COUNTER_CLR		(~(_EMIF_SDRFR2_COUNTER_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_SDRFR2_EXTRA_REFRESHES:	
\*----------------------------------------------------------------*/

#define _EMIF_SDRFR2_EXTRA_REFRESHES_SHIFT		(0x0008u)
#define _EMIF_SDRFR2_EXTRA_REFRESHES_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_SDRFR2_EXTRA_REFRESHES_SHIFT)
#define _EMIF_SDRFR2_EXTRA_REFRESHES_MASK		(_EMIF_SDRFR2_EXTRA_REFRESHES_MK(0x0003u))
#define _EMIF_SDRFR2_EXTRA_REFRESHES_CLR		(~(_EMIF_SDRFR2_EXTRA_REFRESHES_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the GBLCTL2 register			
\*----------------------------------------------------------------*/


/******************************************************************************\
* 
* _EMIF_GBLCTL2	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_GBLCTL2_EK2EN	
*	(RW)   _EMIF_GBLCTL2_EK2HZ	
*	(RW)   _EMIF_GBLCTL2_EK2RATE	
*
\******************************************************************************/



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_GBLCTL2_EK2EN:	
\*----------------------------------------------------------------*/

#define _EMIF_GBLCTL2_EK2EN_SHIFT		(000000u)
#define _EMIF_GBLCTL2_EK2EN_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_GBLCTL2_EK2EN_SHIFT)
#define _EMIF_GBLCTL2_EK2EN_MASK		(_EMIF_GBLCTL2_EK2EN_MK(0x0001u))
#define _EMIF_GBLCTL2_EK2EN_CLR		(~(_EMIF_GBLCTL2_EK2EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_GBLCTL2_EK2HZ:	
\*----------------------------------------------------------------*/

#define _EMIF_GBLCTL2_EK2HZ_SHIFT		(0x0001u)
#define _EMIF_GBLCTL2_EK2HZ_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_GBLCTL2_EK2HZ_SHIFT)
#define _EMIF_GBLCTL2_EK2HZ_MASK		(_EMIF_GBLCTL2_EK2HZ_MK(0x0001u))
#define _EMIF_GBLCTL2_EK2HZ_CLR		(~(_EMIF_GBLCTL2_EK2HZ_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_GBLCTL2_EK2RATE:	
\*----------------------------------------------------------------*/

#define _EMIF_GBLCTL2_EK2RATE_SHIFT		(0x0002u)
#define _EMIF_GBLCTL2_EK2RATE_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_GBLCTL2_EK2RATE_SHIFT)
#define _EMIF_GBLCTL2_EK2RATE_MASK		(_EMIF_GBLCTL2_EK2RATE_MK(0x0003u))
#define _EMIF_GBLCTL2_EK2RATE_CLR		(~(_EMIF_GBLCTL2_EK2RATE_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the CE2CTL1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _EMIF_CE2CTL1	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_CE2CTL1_READ_HOLD	
*	(RW)   _EMIF_CE2CTL1_WRITE_HOLD_MSB	/ _EMIF_CE2CTL1_WRITE_HOLD
*	(RW)   _EMIF_CE2CTL1_MTYPE	
*	(RW)   _EMIF_CE2CTL1_READ_STROBE	
*	(RW)   _EMIF_CE2CTL1_TA	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE2CTL1_READ_HOLD:	
\*----------------------------------------------------------------*/

#define _EMIF_CE2CTL1_READ_HOLD_SHIFT		(000000u)
#define _EMIF_CE2CTL1_READ_HOLD_MK(n)		(((Uint16)(n) & 0x0007u) << _EMIF_CE2CTL1_READ_HOLD_SHIFT)
#define _EMIF_CE2CTL1_READ_HOLD_MASK		(_EMIF_CE2CTL1_READ_HOLD_MK(0x0007u))
#define _EMIF_CE2CTL1_READ_HOLD_CLR		(~(_EMIF_CE2CTL1_READ_HOLD_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE2CTL1_WRITE_HOLD_MSB:	
\*----------------------------------------------------------------*/

#define _EMIF_CE2CTL1_WRITE_HOLD_MSB_SHIFT		(0x0003u)
#define _EMIF_CE2CTL1_WRITE_HOLD_MSB_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE2CTL1_WRITE_HOLD_MSB_SHIFT)
#define _EMIF_CE2CTL1_WRITE_HOLD_MSB_MASK		(_EMIF_CE2CTL1_WRITE_HOLD_MSB_MK(0x0001u))
#define _EMIF_CE2CTL1_WRITE_HOLD_MSB_CLR		(~(_EMIF_CE2CTL1_WRITE_HOLD_MSB_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE2CTL1_WRITE_HOLD:	
\*----------------------------------------------------------------*/

#define _EMIF_CE2CTL1_WRITE_HOLD_SHIFT		(0x0003u)
#define _EMIF_CE2CTL1_WRITE_HOLD_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE2CTL1_WRITE_HOLD_SHIFT)
#define _EMIF_CE2CTL1_WRITE_HOLD_MASK		(_EMIF_CE2CTL1_WRITE_HOLD_MK(0x0001u))
#define _EMIF_CE2CTL1_WRITE_HOLD_CLR		(~(_EMIF_CE2CTL1_WRITE_HOLD_MASK))


/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE2CTL1_MTYPE:	
\*----------------------------------------------------------------*/

#define _EMIF_CE2CTL1_MTYPE_SHIFT		(0x0004u)
#define _EMIF_CE2CTL1_MTYPE_MK(n)		(((Uint16)(n) & 0x000fu) << _EMIF_CE2CTL1_MTYPE_SHIFT)
#define _EMIF_CE2CTL1_MTYPE_MASK		(_EMIF_CE2CTL1_MTYPE_MK(0x000fu))
#define _EMIF_CE2CTL1_MTYPE_CLR		(~(_EMIF_CE2CTL1_MTYPE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE2CTL1_READ_STROBE:	
\*----------------------------------------------------------------*/

#define _EMIF_CE2CTL1_READ_STROBE_SHIFT		(0x0008u)
#define _EMIF_CE2CTL1_READ_STROBE_MK(n)		(((Uint16)(n) & 0x003fu) << _EMIF_CE2CTL1_READ_STROBE_SHIFT)
#define _EMIF_CE2CTL1_READ_STROBE_MASK		(_EMIF_CE2CTL1_READ_STROBE_MK(0x003fu))
#define _EMIF_CE2CTL1_READ_STROBE_CLR		(~(_EMIF_CE2CTL1_READ_STROBE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE2CTL1_TA:	
\*----------------------------------------------------------------*/

#define _EMIF_CE2CTL1_TA_SHIFT		(0x000eu)
#define _EMIF_CE2CTL1_TA_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE2CTL1_TA_SHIFT)
#define _EMIF_CE2CTL1_TA_MASK		(_EMIF_CE2CTL1_TA_MK(0x0003u))
#define _EMIF_CE2CTL1_TA_CLR		(~(_EMIF_CE2CTL1_TA_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the CE2SEC1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _EMIF_CE2SEC1	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_CE2SEC1_SYNCRL	
*	(RW)   _EMIF_CE2SEC1_SYNCWL	
*	(RW)   _EMIF_CE2SEC1_CEEXT	
*	(RW)   _EMIF_CE2SEC1_REN	/ _EMIF_CE2SEC1_RENEN  Added 26 Mar 2003
*	(RW)   _EMIF_CE2SEC1_SNCCLK	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE2SEC1_SYNCRL:	
\*----------------------------------------------------------------*/

#define _EMIF_CE2SEC1_SYNCRL_SHIFT		(000000u)
#define _EMIF_CE2SEC1_SYNCRL_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE2SEC1_SYNCRL_SHIFT)
#define _EMIF_CE2SEC1_SYNCRL_MASK		(_EMIF_CE2SEC1_SYNCRL_MK(0x0003u))
#define _EMIF_CE2SEC1_SYNCRL_CLR		(~(_EMIF_CE2SEC1_SYNCRL_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE2SEC1_SYNCWL:	
\*----------------------------------------------------------------*/

#define _EMIF_CE2SEC1_SYNCWL_SHIFT		(0x0002u)
#define _EMIF_CE2SEC1_SYNCWL_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE2SEC1_SYNCWL_SHIFT)
#define _EMIF_CE2SEC1_SYNCWL_MASK		(_EMIF_CE2SEC1_SYNCWL_MK(0x0003u))
#define _EMIF_CE2SEC1_SYNCWL_CLR		(~(_EMIF_CE2SEC1_SYNCWL_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE2SEC1_CEEXT:	
\*----------------------------------------------------------------*/

#define _EMIF_CE2SEC1_CEEXT_SHIFT		(0x0004u)
#define _EMIF_CE2SEC1_CEEXT_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE2SEC1_CEEXT_SHIFT)
#define _EMIF_CE2SEC1_CEEXT_MASK		(_EMIF_CE2SEC1_CEEXT_MK(0x0001u))
#define _EMIF_CE2SEC1_CEEXT_CLR		(~(_EMIF_CE2SEC1_CEEXT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE2SEC1_REN:	
\*----------------------------------------------------------------*/

#define _EMIF_CE2SEC1_REN_SHIFT		(0x0005u)
#define _EMIF_CE2SEC1_REN_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE2SEC1_REN_SHIFT)
#define _EMIF_CE2SEC1_REN_MASK		(_EMIF_CE2SEC1_REN_MK(0x0001u))
#define _EMIF_CE2SEC1_REN_CLR		(~(_EMIF_CE2SEC1_REN_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE2SEC1_RENEN:	
\*----------------------------------------------------------------*/

#define _EMIF_CE2SEC1_RENEN_SHIFT		(0x0005u)
#define _EMIF_CE2SEC1_RENEN_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE2SEC1_RENEN_SHIFT)
#define _EMIF_CE2SEC1_RENEN_MASK		(_EMIF_CE2SEC1_RENEN_MK(0x0001u))
#define _EMIF_CE2SEC1_RENEN_CLR		(~(_EMIF_CE2SEC1_RENEN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE2SEC1_SNCCLK:	
\*----------------------------------------------------------------*/

#define _EMIF_CE2SEC1_SNCCLK_SHIFT		(0x0006u)
#define _EMIF_CE2SEC1_SNCCLK_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_CE2SEC1_SNCCLK_SHIFT)
#define _EMIF_CE2SEC1_SNCCLK_MASK		(_EMIF_CE2SEC1_SNCCLK_MK(0x0001u))
#define _EMIF_CE2SEC1_SNCCLK_CLR		(~(_EMIF_CE2SEC1_SNCCLK_MASK))

/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the CE2CTL2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _EMIF_CE2CTL2	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_CE2CTL2_READ_SETUP	
*	(RW)   _EMIF_CE2CTL2_WRITE_HOLD	
*	(RW)   _EMIF_CE2CTL2_WRITE_STROBE	
*	(RW)   _EMIF_CE2CTL2_WRITE_SETUP	
*
\******************************************************************************/


/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE2CTL2_READ_SETUP:	
\*----------------------------------------------------------------*/

#define _EMIF_CE2CTL2_READ_SETUP_SHIFT		(000000u)
#define _EMIF_CE2CTL2_READ_SETUP_MK(n)		(((Uint16)(n) & 0x000fu) << _EMIF_CE2CTL2_READ_SETUP_SHIFT)
#define _EMIF_CE2CTL2_READ_SETUP_MASK		(_EMIF_CE2CTL2_READ_SETUP_MK(0x000fu))
#define _EMIF_CE2CTL2_READ_SETUP_CLR		(~(_EMIF_CE2CTL2_READ_SETUP_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE2CTL2_WRITE_HOLD:	
\*----------------------------------------------------------------*/

#define _EMIF_CE2CTL2_WRITE_HOLD_SHIFT		(0x0004u)
#define _EMIF_CE2CTL2_WRITE_HOLD_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE2CTL2_WRITE_HOLD_SHIFT)
#define _EMIF_CE2CTL2_WRITE_HOLD_MASK		(_EMIF_CE2CTL2_WRITE_HOLD_MK(0x0003u))
#define _EMIF_CE2CTL2_WRITE_HOLD_CLR		(~(_EMIF_CE2CTL2_WRITE_HOLD_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE2CTL2_WRITE_STROBE:	
\*----------------------------------------------------------------*/

#define _EMIF_CE2CTL2_WRITE_STROBE_SHIFT		(0x0006u)
#define _EMIF_CE2CTL2_WRITE_STROBE_MK(n)		(((Uint16)(n) & 0x003fu) << _EMIF_CE2CTL2_WRITE_STROBE_SHIFT)
#define _EMIF_CE2CTL2_WRITE_STROBE_MASK		(_EMIF_CE2CTL2_WRITE_STROBE_MK(0x003fu))
#define _EMIF_CE2CTL2_WRITE_STROBE_CLR		(~(_EMIF_CE2CTL2_WRITE_STROBE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CE2CTL2_WRITE_SETUP:	
\*----------------------------------------------------------------*/

#define _EMIF_CE2CTL2_WRITE_SETUP_SHIFT		(0x000cu)
#define _EMIF_CE2CTL2_WRITE_SETUP_MK(n)		(((Uint16)(n) & 0x000fu) << _EMIF_CE2CTL2_WRITE_SETUP_SHIFT)
#define _EMIF_CE2CTL2_WRITE_SETUP_MASK		(_EMIF_CE2CTL2_WRITE_SETUP_MK(0x000fu))
#define _EMIF_CE2CTL2_WRITE_SETUP_CLR		(~(_EMIF_CE2CTL2_WRITE_SETUP_MASK))


/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the CESCR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _EMIF_CESCR	 - Note: Add description here
*
* Fields:
*	(RW)   _EMIF_CESCR_CES	
*
\******************************************************************************/

/*----------------------------------------------------------------*\
*   (RW)  _EMIF_CESCR_CES:	
\*----------------------------------------------------------------*/

#define _EMIF_CESCR_CES_SHIFT				(000000u)
#define _EMIF_CESCR_CES_MK(n)				(((Uint16)(n) & 0x0002u) << _EMIF_CESCR_CES_SHIFT)
#define _EMIF_CESCR_CES_MASK				(_EMIF_CESCR_CES_MK(0x0003u))
#define _EMIF_CESCR_CES_CLR				(~(_EMIF_CESCR_CES_MASK))


#elif (!(_EMIF_MOD))
	#error EMIF Hal Module Not Supported on Specified Target
#endif  /* _EMIF_SUPPORT  */

#endif  /* _CSL_EMIFHAL_H  */

/******************************************************************************\
*     
*      End of csl_emifhal.h 
*
\******************************************************************************/
