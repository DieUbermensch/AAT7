/****************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... PLL
* FILENAME...... csl_pllhal.h
* DATE CREATED.. Mon Jan 28 14:25:28 2002
* PROJECT....... Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS..
*------------------------------------------------------------------------------
*
* HISTORY:
*	 Created:		Mon Jan 28 14:25:28 2002 (Automatic generation)
*	 MODIFIED:  08/04/2003 Added CLKOUTSR, Renamed CLKMD0 to CLKMD
*		    09/25/2003 Renamed WAKEUP -> WKEN
*                   01/18/2004 Fixed the problem - C5502 CSL- PLL macros give
*                               error if register and field names are same           

*------------------------------------------------------------------------------
* DESCRIPTION: CSL HAL interface file for the PLL module
*
* Registers covered:
*
* 		 Note: Add registers description here
*	 PLLCSR
*	 PLLM
*	 PLLDIV0
*	 PLLDIV1
*	 PLLDIV2
*	 PLLDIV3
*	 OSCDIV1
*	 WKEN
*	 CLKMD
*    CK3SEL
*    CLKOUTSR
*
\*************************************************************************/

#ifndef _CSL_PLLBHAL_H_
#define _CSL_PLLBHAL_H_

#include <csl_chiphal.h>

#if (_PLLB_SUPPORT)

/*----------------------------------------------------------------*\
*	 PLL scope and inline control macros
\*----------------------------------------------------------------*/

#ifdef __cplusplus
#define CSLAPI extern "C"
#else
#define CSLAPI extern
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _PLL_MOD_
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

/*--------------------- Register: PLLCSR -----------------------*/
#define _PLL_PLLCSR_ADDR		(0x1c80u)
#define _PLL_PLLCSR			PREG16(_PLL_PLLCSR_ADDR)


/*--------------------- Register: PLLM -----------------------*/
#define _PLL_PLLM_ADDR		(0x1c88u)
#define _PLL_PLLM			PREG16(_PLL_PLLM_ADDR)


/*--------------------- Register: PLLDIV0 -----------------------*/
#define _PLL_PLLDIV0_ADDR		(0x1c8au)
#define _PLL_PLLDIV0			PREG16(_PLL_PLLDIV0_ADDR)


/*--------------------- Register: PLLDIV1 -----------------------*/
#define _PLL_PLLDIV1_ADDR		(0x1c8cu)
#define _PLL_PLLDIV1			PREG16(_PLL_PLLDIV1_ADDR)


/*--------------------- Register: PLLDIV2 -----------------------*/
#define _PLL_PLLDIV2_ADDR		(0x1c8eu)
#define _PLL_PLLDIV2			PREG16(_PLL_PLLDIV2_ADDR)


/*--------------------- Register: PLLDIV3 -----------------------*/
#define _PLL_PLLDIV3_ADDR		(0x1c90u)
#define _PLL_PLLDIV3			PREG16(_PLL_PLLDIV3_ADDR)


/*--------------------- Register: OSCDIV1 -----------------------*/
#define _PLL_OSCDIV1_ADDR		(0x1c92u)
#define _PLL_OSCDIV1			PREG16(_PLL_OSCDIV1_ADDR)


/*--------------------- Register: WKEN -----------------------*/
#define _PLL_WKEN_ADDR	(0x1c98u)
#define _PLL_WKEN			PREG16(_PLL_WKEN_ADDR)

/*--------------------- Register: CLKMD0 -----------------------*/
#define _PLL_CLKMD_ADDR		(0x8c00u)
#define _PLL_CLKMD			PREG16(_PLL_CLKMD_ADDR)

/*--------------------- Register: CK3SEL -----------------------*/
#define _PLL_CK3SEL_ADDR	(0x1c82u)
#define _PLL_CK3SEL			PREG16(_PLL_CK3SEL_ADDR)

/*--------------------- Register: CLKOUTSR  -----------------------*/
#define _PLL_CLKOUTSR_ADDR		(0x8400u)
#define _PLL_CLKOUTSR			PREG16(_PLL_CLKOUTSR_ADDR)

/*----------------------------------------------------------------*\
*		 Register Macros
\*----------------------------------------------------------------*/

#define PLL_ADDR(Reg)		  _PLL_##Reg##_ADDR
#define PLL_RGET(Reg)		  _PLL_##Reg##_GET
#define PLL_RSET(Reg,Val)		  _PLL_##Reg##_SET(Val)
#define PLL_FGET(Reg,Field)		  _PLL_##Reg##_FGET(Field)
#define PLL_FSET(Reg,Field,Val)		  _PLL_##Reg##_FSET(Field, Val)
#define PLL_FMK(Reg,Field,Val)		  _PLL_##Reg##_##Field##_MK(Val)
#define PLL_RAOI(Reg,AND,OR,INV)		  _PLL_##Reg##_AOI(AND,OR,INV)
#define PLL_FAOI(Reg,Field,AND,OR,INV)	  _PLL_##Reg##_FAOI(Field,AND,OR,INV)
#define PLL_FMKS(Reg,Field,Sym)\
	  _PLL_##Reg##_##Field##_MK(PLL_##Reg##_##Field##_##Sym)
#define PLL_FSETS(Reg,Field,Sym)\
	  _PLL_FSET(##Reg,##Field,PLL_##Reg##_##Field##_##Sym)

/*----------------------------------------------------------------*\
*		 Non-handle Registers Macros
\*----------------------------------------------------------------*/


/*--------------------- Register: PLLCSR -----------------------*/
#define _PLL_PLLCSR_GET		  _PREG_GET(_PLL_PLLCSR_ADDR)
#define _PLL_PLLCSR_SET(Val)		  _PREG_SET(_PLL_PLLCSR_ADDR,Val)
#define _PLL_PLLCSR_FGET(Field)	  _PFIELD_GET(_PLL_PLLCSR_ADDR, _PLL_PLLCSR_##Field)
#define _PLL_PLLCSR_FSET(Field,Val)	  _PFIELD_SET(_PLL_PLLCSR_ADDR, _PLL_PLLCSR_##Field, Val)
#define _PLL_PLLCSR_AOI(AND,OR,INV)	  _PREG_AOI(_PLL_PLLCSR_ADDR,AND,OR,INV)
#define _PLL_PLLCSR_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_PLL_PLLCSR_ADDR, _PLL_PLLCSR_##Field,AND,OR,INV)


/*--------------------- Register: PLLM -----------------------*/
#define _PLL_PLLM_GET		  _PREG_GET(_PLL_PLLM_ADDR)
#define _PLL_PLLM_SET(Val)		  _PREG_SET(_PLL_PLLM_ADDR,Val)
#define _PLL_PLLM_FGET(Field)	  _PFIELD_GET(_PLL_PLLM_ADDR, _PLL_PLLM_##Field)
#define _PLL_PLLM_FSET(Field,Val)	  _PFIELD_SET(_PLL_PLLM_ADDR, _PLL_PLLM_##Field, Val)
#define _PLL_PLLM_AOI(AND,OR,INV)	  _PREG_AOI(_PLL_PLLM_ADDR,AND,OR,INV)
#define _PLL_PLLM_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_PLL_PLLM_ADDR, _PLL_PLLM_##Field,AND,OR,INV)


/*--------------------- Register: PLLDIV0 -----------------------*/
#define _PLL_PLLDIV0_GET		  _PREG_GET(_PLL_PLLDIV0_ADDR)
#define _PLL_PLLDIV0_SET(Val)		  _PREG_SET(_PLL_PLLDIV0_ADDR,Val)
#define _PLL_PLLDIV0_FGET(Field)	  _PFIELD_GET(_PLL_PLLDIV0_ADDR, _PLL_PLLDIV0_##Field)
#define _PLL_PLLDIV0_FSET(Field,Val)	  _PFIELD_SET(_PLL_PLLDIV0_ADDR, _PLL_PLLDIV0_##Field, Val)
#define _PLL_PLLDIV0_AOI(AND,OR,INV)	  _PREG_AOI(_PLL_PLLDIV0_ADDR,AND,OR,INV)
#define _PLL_PLLDIV0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_PLL_PLLDIV0_ADDR, _PLL_PLLDIV0_##Field,AND,OR,INV)


/*--------------------- Register: PLLDIV1 -----------------------*/
#define _PLL_PLLDIV1_GET		  _PREG_GET(_PLL_PLLDIV1_ADDR)
#define _PLL_PLLDIV1_SET(Val)		  _PREG_SET(_PLL_PLLDIV1_ADDR,Val)
#define _PLL_PLLDIV1_FGET(Field)	  _PFIELD_GET(_PLL_PLLDIV1_ADDR, _PLL_PLLDIV1_##Field)
#define _PLL_PLLDIV1_FSET(Field,Val)	  _PFIELD_SET(_PLL_PLLDIV1_ADDR, _PLL_PLLDIV1_##Field, Val)
#define _PLL_PLLDIV1_AOI(AND,OR,INV)	  _PREG_AOI(_PLL_PLLDIV1_ADDR,AND,OR,INV)
#define _PLL_PLLDIV1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_PLL_PLLDIV1_ADDR, _PLL_PLLDIV1_##Field,AND,OR,INV)


/*--------------------- Register: PLLDIV2 -----------------------*/
#define _PLL_PLLDIV2_GET		  _PREG_GET(_PLL_PLLDIV2_ADDR)
#define _PLL_PLLDIV2_SET(Val)		  _PREG_SET(_PLL_PLLDIV2_ADDR,Val)
#define _PLL_PLLDIV2_FGET(Field)	  _PFIELD_GET(_PLL_PLLDIV2_ADDR, _PLL_PLLDIV2_##Field)
#define _PLL_PLLDIV2_FSET(Field,Val)	  _PFIELD_SET(_PLL_PLLDIV2_ADDR, _PLL_PLLDIV2_##Field, Val)
#define _PLL_PLLDIV2_AOI(AND,OR,INV)	  _PREG_AOI(_PLL_PLLDIV2_ADDR,AND,OR,INV)
#define _PLL_PLLDIV2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_PLL_PLLDIV2_ADDR, _PLL_PLLDIV2_##Field,AND,OR,INV)


/*--------------------- Register: PLLDIV3 -----------------------*/
#define _PLL_PLLDIV3_GET		  _PREG_GET(_PLL_PLLDIV3_ADDR)
#define _PLL_PLLDIV3_SET(Val)		  _PREG_SET(_PLL_PLLDIV3_ADDR,Val)
#define _PLL_PLLDIV3_FGET(Field)	  _PFIELD_GET(_PLL_PLLDIV3_ADDR, _PLL_PLLDIV3_##Field)
#define _PLL_PLLDIV3_FSET(Field,Val)	  _PFIELD_SET(_PLL_PLLDIV3_ADDR, _PLL_PLLDIV3_##Field, Val)
#define _PLL_PLLDIV3_AOI(AND,OR,INV)	  _PREG_AOI(_PLL_PLLDIV3_ADDR,AND,OR,INV)
#define _PLL_PLLDIV3_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_PLL_PLLDIV3_ADDR, _PLL_PLLDIV3_##Field,AND,OR,INV)


/*--------------------- Register: OSCDIV1 -----------------------*/
#define _PLL_OSCDIV1_GET		  _PREG_GET(_PLL_OSCDIV1_ADDR)
#define _PLL_OSCDIV1_SET(Val)		  _PREG_SET(_PLL_OSCDIV1_ADDR,Val)
#define _PLL_OSCDIV1_FGET(Field)	  _PFIELD_GET(_PLL_OSCDIV1_ADDR, _PLL_OSCDIV1_##Field)
#define _PLL_OSCDIV1_FSET(Field,Val)	  _PFIELD_SET(_PLL_OSCDIV1_ADDR, _PLL_OSCDIV1_##Field, Val)
#define _PLL_OSCDIV1_AOI(AND,OR,INV)	  _PREG_AOI(_PLL_OSCDIV1_ADDR,AND,OR,INV)
#define _PLL_OSCDIV1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_PLL_OSCDIV1_ADDR, _PLL_OSCDIV1_##Field,AND,OR,INV)


/*--------------------- Register: WKEN -----------------------*/
#define _PLL_WKEN_GET		  _PREG_GET(_PLL_WKEN_ADDR)
#define _PLL_WKEN_SET(Val)		  _PREG_SET(_PLL_WKEN_ADDR,Val)
#define _PLL_WKEN_FGET(Field)	  _PFIELD_GET(_PLL_WKEN_ADDR, _PLL_WKEN_##Field)
#define _PLL_WKEN_FSET(Field,Val)	  _PFIELD_SET(_PLL_WKEN_ADDR, _PLL_WKEN_##Field, Val)
#define _PLL_WKEN_AOI(AND,OR,INV)	  _PREG_AOI(_PLL_WKEN_ADDR,AND,OR,INV)
#define _PLL_WKEN_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_PLL_WKEN_ADDR, _PLL_WKEN_##Field,AND,OR,INV)


/*--------------------- Register:  -----------------------*/
#define _PLL_CLKMD_GET  	 _PREG_GET(_PLL_CLKMD_ADDR)
#define _PLL_CLKMD_SET(Val) 		 _PREG_SET(_PLL_CLKMD_ADDR,Val)
#define _PLL_CLKMD_FGET(Field)   _PFIELD_GET(_PLL_CLKMD_ADDR, _PLL_CLKMD_##Field)
#define _PLL_CLKMD_FSET(Field,Val)   _PFIELD_SET(_PLL_CLKMD_ADDR, _PLL_CLKMD_##Field, Val)
#define _PLL_CLKMD_AOI(AND,OR,INV)   _PREG_AOI(_PLL_CLKMD_ADDR,AND,OR,INV)
#define _PLL_CLKMD_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_PLL_CLKMD_ADDR, _PLL__##Field,AND,OR,INV)

/*--------------------- Register:  -----------------------*/
#define _PLL_CK3SEL_GET		  _PREG_GET(_PLL_CK3SEL_ADDR)
#define _PLL_CK3SEL_SET(Val)		  _PREG_SET(_PLL_CK3SEL_ADDR,Val)
#define _PLL_CK3SEL_FGET(Field)	  _PFIELD_GET(_PLL_CK3SEL_ADDR, _PLL_CK3SEL_##Field)
#define _PLL_CK3SEL_FSET(Field,Val)	  _PFIELD_SET(_PLL_CK3SEL_ADDR, _PLL_CK3SEL_##Field, Val)
#define _PLL_CK3SEL_AOI(AND,OR,INV)	  _PREG_AOI(_PLL_CK3SEL_ADDR,AND,OR,INV)
#define _PLL_CK3SEL_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_PLL_CK3SEL_ADDR, _PLL__##Field,AND,OR,INV)

/*--------------------- Register:  -----------------------*/
#define _PLL_CLKOUTSR_GET		        _PREG_GET(_PLL_CLKOUTSR_ADDR)
#define _PLL_CLKOUTSR_SET(Val)		  _PREG_SET(_PLL_CLKOUTSR_ADDR,Val)
#define _PLL_CLKOUTSR_FGET(Field)	        _PFIELD_GET(_PLL_CLKOUTSR_ADDR, _PLL_CLKOUTSR_##Field)
#define _PLL_CLKOUTSR_FSET(Field,Val)	  _PFIELD_SET(_PLL_CLKOUTSR_ADDR, _PLL_CLKOUTSR_##Field, Val)
#define _PLL_CLKOUTSR_AOI(AND,OR,INV)	  _PREG_AOI(_PLL_CLKOUTSR_ADDR,AND,OR,INV)
#define _PLL_CLKOUTSR_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_PLL_CLKOUTSR_ADDR, _PLL__##Field,AND,OR,INV)


/******************************************************************************\
*
* _PLL_CLKMD	 - Clock Mode Control Register
*
* Fields:
*	(RW)   _PLL_CLKMD_CLKMD0
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _PLL_CLKMD_CLKMD0:
\*----------------------------------------------------------------*/

#define _PLL_CLKMD_CLKMD0_SHIFT 	   (000000u)
#define _PLL_CLKMD_CLKMD0_MK(n) 	   (((Uint16)(n) & 0x0001u) << _PLL_CLKMD_CLKMD0_SHIFT)
#define _PLL_CLKMD_CLKMD0_MASK     (_PLL_CLKMD_CLKMD0_MK(0x0001u))
#define _PLL_CLKMD_CLKMD0_CLR	   (~(_PLL_CLKMD_CLKMD0_MASK))

/******************************************************************************\
*
* _PLL_CLKOUTSR	 - CLKOUT Selection Register
*
* Fields:
*	(RW)   _PLL_CLKOUTSR_CLKOUTDIS
*   (RW)   _PLL_CLKOUTSR_CLKOSEL
*
\******************************************************************************/

/*----------------------------------------------------------------*\
*   (RW)  _PLL_CLKOUTSR_CLKOUTDIS:
\*----------------------------------------------------------------*/

#define _PLL_CLKOUTSR_CLKOUTDIS_SHIFT		(000000u)
#define _PLL_CLKOUTSR_CLKOUTDIS_MK(n)		(((Uint16)(n) & 0x0001u) << _PLL_CLKOUTSR_CLKOUTDIS_SHIFT)
#define _PLL_CLKOUTSR_CLKOUTDIS_MASK		(_PLL_CLKOUTSR_CLKOUTDIS_MK(0x0001u))
#define _PLL_CLKOUTSR_CLKOUTDIS_CLR		(~(_PLL_CLKOUTSR_CLKOUTDIS_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _PLL_CLKOUTSR_CLKOSEL:
\*----------------------------------------------------------------*/

#define _PLL_CLKOUTSR_CLKOSEL_SHIFT		(000001u)
#define _PLL_CLKOUTSR_CLKOSEL_MK(n)		(((Uint16)(n) & 0x0003u) << _PLL_CLKOUTSR_CLKOSEL_SHIFT)
#define _PLL_CLKOUTSR_CLKOSEL_MASK		(_PLL_CLKOUTSR_CLKOSEL_MK(0x0003u))
#define _PLL_CLKOUTSR_CLKOSEL_CLR		(~(_PLL_CLKOUTSR_CLKOSEL_MASK))


/******************************************************************************\
*
* _PLL_CK3SEL	 - CLKOUT3 Select Register
*
* Fields:
*	(RW)   _PLL_CK3SEL_CK3SEL
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _PLL_CK3SEL_CK3SEL:
\*----------------------------------------------------------------*/

#define _PLL_CK3SEL_CK3SEL_SHIFT		(000000u)
#define _PLL_CK3SEL_CK3SEL_MK(n)		(((Uint16)(n) & 0x000fu) << _PLL_CK3SEL_CK3SEL_SHIFT)
#define _PLL_CK3SEL_CK3SEL_MASK		(_PLL_CK3SEL_CK3SEL_MK(0x000fu))
#define _PLL_CK3SEL_CK3SEL_CLR		(~(_PLL_CK3SEL_CK3SEL_MASK))




/******************************************************************************\
*
* _PLL_OSCDIV1	 - Oscillator divide down register
*
* Fields:
*	(RW)   _PLL_OSCDIV1_OSCDIV1
*	(RW)   _PLL_OSCDIV1_OD1EN
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _PLL_OSCDIV1_OSCDIV1:
\*----------------------------------------------------------------*/

#define _PLL_OSCDIV1_OSCDIV1_SHIFT		(000000u)
#define _PLL_OSCDIV1_OSCDIV1_MK(n)		(((Uint16)(n) & 0x001fu) << _PLL_OSCDIV1_OSCDIV1_SHIFT)
#define _PLL_OSCDIV1_OSCDIV1_MASK		(_PLL_OSCDIV1_OSCDIV1_MK(0x001fu))
#define _PLL_OSCDIV1_OSCDIV1_CLR		(~(_PLL_OSCDIV1_OSCDIV1_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _PLL_OSCDIV1_OD1EN:
\*----------------------------------------------------------------*/

#define _PLL_OSCDIV1_OD1EN_SHIFT		(0x000fu)
#define _PLL_OSCDIV1_OD1EN_MK(n)		(((Uint16)(n) & 0x0001u) << _PLL_OSCDIV1_OD1EN_SHIFT)
#define _PLL_OSCDIV1_OD1EN_MASK		(_PLL_OSCDIV1_OD1EN_MK(0x0001u))
#define _PLL_OSCDIV1_OD1EN_CLR		(~(_PLL_OSCDIV1_OD1EN_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the WKEN register
\*----------------------------------------------------------------*/

/******************************************************************************\
*
* _PLL_WKEN	 - Wakeup (powerdown) Control Register
*
* Fields:
*	(RW)   _PLL_WKEN_WKEN0
*	(RW)   _PLL_WKEN_WKEN1
*	(RW)   _PLL_WKEN_WKEN2
*	(RW)   _PLL_WKEN_WKEN3
*   (RW)   _PLL_WKEN_WKEN4
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _PLL_WKEN_WKEN0:
\*----------------------------------------------------------------*/

#define _PLL_WKEN_WKEN0_SHIFT		(000000u)
#define _PLL_WKEN_WKEN0_MK(n)		(((Uint16)(n) & 0x0001u) << _PLL_WKEN_WKEN0_SHIFT)
#define _PLL_WKEN_WKEN0_MASK		(_PLL_WKEN_WKEN0_MK(0x0001u))
#define _PLL_WKEN_WKEN0_CLR		(~(_PLL_WKEN_WKEN0_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _PLL_WKEN_WKEN1:
\*----------------------------------------------------------------*/

#define _PLL_WKEN_WKEN1_SHIFT		(0x0001u)
#define _PLL_WKEN_WKEN1_MK(n)		(((Uint16)(n) & 0x0001u) << _PLL_WKEN_WKEN1_SHIFT)
#define _PLL_WKEN_WKEN1_MASK		(_PLL_WKEN_WKEN1_MK(0x0001u))
#define _PLL_WKEN_WKEN1_CLR		(~(_PLL_WKEN_WKEN1_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _PLL_WKEN_WKEN2:
\*----------------------------------------------------------------*/

#define _PLL_WKEN_WKEN2_SHIFT		(0x0002u)
#define _PLL_WKEN_WKEN2_MK(n)		(((Uint16)(n) & 0x0001u) << _PLL_WKEN_WKEN2_SHIFT)
#define _PLL_WKEN_WKEN2_MASK		(_PLL_WKEN_WKEN2_MK(0x0001u))
#define _PLL_WKEN_WKEN2_CLR		(~(_PLL_WKEN_WKEN2_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _PLL_WKEN_WKEN3:
\*----------------------------------------------------------------*/

#define _PLL_WKEN_WKEN3_SHIFT		(0x0003u)
#define _PLL_WKEN_WKEN3_MK(n)		(((Uint16)(n) & 0x0001u) << _PLL_WKEN_WKEN3_SHIFT)
#define _PLL_WKEN_WKEN3_MASK		(_PLL_WKEN_WKEN3_MK(0x0001u))
#define _PLL_WKEN_WKEN3_CLR		(~(_PLL_WKEN_WKEN3_MASK))


/*----------------------------------------------------------------*\
*   (RW)  _PLL_WKEN_WKEN4:
\*----------------------------------------------------------------*/

#define _PLL_WKEN_WKEN4_SHIFT		(0x0004u)
#define _PLL_WKEN_WKEN4_MK(n)		(((Uint16)(n) & 0x0001u) << _PLL_WKEN_WKEN4_SHIFT)
#define _PLL_WKEN_WKEN4_MASK		(_PLL_WKEN_WKEN4_MK(0x0001u))
#define _PLL_WKEN_WKEN4_CLR		(~(_PLL_WKEN_WKEN4_MASK))


/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the PLLDIV0 register
\*----------------------------------------------------------------*/

/******************************************************************************\
*
* _PLL_PLLDIV0	 - Clock 0 Divide Down Register
*
* Fields:
*	(RW)   _PLL_PLLDIV0_PLLDIV0
*	(RW)   _PLL_PLLDIV0_D0EN
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _PLL_PLLDIV0_PLLDIV0:
\*----------------------------------------------------------------*/

#define _PLL_PLLDIV0_PLLDIV0_SHIFT		(000000u)
#define _PLL_PLLDIV0_PLLDIV0_MK(n)		(((Uint16)(n) & 0x001fu) << _PLL_PLLDIV0_PLLDIV0_SHIFT)
#define _PLL_PLLDIV0_PLLDIV0_MASK		(_PLL_PLLDIV0_PLLDIV0_MK(0x001fu))
#define _PLL_PLLDIV0_PLLDIV0_CLR		(~(_PLL_PLLDIV0_PLLDIV0_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _PLL_PLLDIV0_D0EN:
\*----------------------------------------------------------------*/

#define _PLL_PLLDIV0_D0EN_SHIFT		(0x000fu)
#define _PLL_PLLDIV0_D0EN_MK(n)		(((Uint16)(n) & 0x0001u) << _PLL_PLLDIV0_D0EN_SHIFT)
#define _PLL_PLLDIV0_D0EN_MASK		(_PLL_PLLDIV0_D0EN_MK(0x0001u))
#define _PLL_PLLDIV0_D0EN_CLR		      (~(_PLL_PLLDIV0_D0EN_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the PLLM register
\*----------------------------------------------------------------*/

/******************************************************************************\
*
* _PLL_PLLM	 - Clock 0 Multiplier Register
*
* Fields:
*	(RW)   _PLL_PLLM_PLLM
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _PLL_PLLM_PLLM:
\*----------------------------------------------------------------*/

#define _PLL_PLLM_PLLM_SHIFT		(000000u)
#define _PLL_PLLM_PLLM_MK(n)		(((Uint16)(n) & 0x001fu) << _PLL_PLLM_PLLM_SHIFT)
#define _PLL_PLLM_PLLM_MASK		(_PLL_PLLM_PLLM_MK(0x001fu))
#define _PLL_PLLM_PLLM_CLR		(~(_PLL_PLLM_PLLM_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the PLLDIV1 register
\*----------------------------------------------------------------*/

/******************************************************************************\
*
* _PLL_PLLDIV1	 - Sysclk 1 Divide Down Register
*
* Fields:
*	(RW)   _PLL_PLLDIV1_PLLDIV1
*	(RW)   _PLL_PLLDIV1_D1EN
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _PLL_PLLDIV1_PLLDIV1:
\*----------------------------------------------------------------*/

#define _PLL_PLLDIV1_PLLDIV1_SHIFT		(000000u)
#define _PLL_PLLDIV1_PLLDIV1_MK(n)		(((Uint16)(n) & 0x001fu) << _PLL_PLLDIV1_PLLDIV1_SHIFT)
#define _PLL_PLLDIV1_PLLDIV1_MASK		(_PLL_PLLDIV1_PLLDIV1_MK(0x001fu))
#define _PLL_PLLDIV1_PLLDIV1_CLR		(~(_PLL_PLLDIV1_PLLDIV1_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _PLL_PLLDIV1_D1EN:
\*----------------------------------------------------------------*/

#define _PLL_PLLDIV1_D1EN_SHIFT		(0x000fu)
#define _PLL_PLLDIV1_D1EN_MK(n)		(((Uint16)(n) & 0x0001u) << _PLL_PLLDIV1_D1EN_SHIFT)
#define _PLL_PLLDIV1_D1EN_MASK		(_PLL_PLLDIV1_D1EN_MK(0x0001u))
#define _PLL_PLLDIV1_D1EN_CLR		(~(_PLL_PLLDIV1_D1EN_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the PLLCSR register
\*----------------------------------------------------------------*/

/******************************************************************************\
*
* _PLL_PLLCSR	 - PLL Control Register
*
* Fields:
*	(RW)   _PLL_PLLCSR_PLLEN
*	(RW)   _PLL_PLLCSR_PLLPWRDN
*	(RW)   _PLL_PLLCSR_OSCPWRDN
*	(RW)   _PLL_PLLCSR_PLLRST
*	(R)   _PLL_PLLCSR_LOCK
*	(R)   _PLL_PLLCSR_STABLE
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _PLL_PLLCSR_PLLEN:
\*----------------------------------------------------------------*/

#define _PLL_PLLCSR_PLLEN_SHIFT		(000000u)
#define _PLL_PLLCSR_PLLEN_MK(n)		(((Uint16)(n) & 0x0001u) << _PLL_PLLCSR_PLLEN_SHIFT)
#define _PLL_PLLCSR_PLLEN_MASK		(_PLL_PLLCSR_PLLEN_MK(0x0001u))
#define _PLL_PLLCSR_PLLEN_CLR		(~(_PLL_PLLCSR_PLLEN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _PLL_PLLCSR_PLLPWRDN:
\*----------------------------------------------------------------*/

#define _PLL_PLLCSR_PLLPWRDN_SHIFT		(0x0001u)
#define _PLL_PLLCSR_PLLPWRDN_MK(n)		(((Uint16)(n) & 0x0001u) << _PLL_PLLCSR_PLLPWRDN_SHIFT)
#define _PLL_PLLCSR_PLLPWRDN_MASK		(_PLL_PLLCSR_PLLPWRDN_MK(0x0001u))
#define _PLL_PLLCSR_PLLPWRDN_CLR		(~(_PLL_PLLCSR_PLLPWRDN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _PLL_PLLCSR_OSCPWRDN:
\*----------------------------------------------------------------*/

#define _PLL_PLLCSR_OSCPWRDN_SHIFT		(0x0002u)
#define _PLL_PLLCSR_OSCPWRDN_MK(n)		(((Uint16)(n) & 0x0001u) << _PLL_PLLCSR_OSCPWRDN_SHIFT)
#define _PLL_PLLCSR_OSCPWRDN_MASK		(_PLL_PLLCSR_OSCPWRDN_MK(0x0001u))
#define _PLL_PLLCSR_OSCPWRDN_CLR		(~(_PLL_PLLCSR_OSCPWRDN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _PLL_PLLCSR_PLLRST:
\*----------------------------------------------------------------*/

#define _PLL_PLLCSR_PLLRST_SHIFT		(0x0003u)
#define _PLL_PLLCSR_PLLRST_MK(n)		(((Uint16)(n) & 0x0001u) << _PLL_PLLCSR_PLLRST_SHIFT)
#define _PLL_PLLCSR_PLLRST_MASK		(_PLL_PLLCSR_PLLRST_MK(0x0001u))
#define _PLL_PLLCSR_PLLRST_CLR		(~(_PLL_PLLCSR_PLLRST_MASK))



/*----------------------------------------------------------------*\
*   (R)  _PLL_PLLCSR_LOCK:
\*----------------------------------------------------------------*/

#define _PLL_PLLCSR_LOCK_SHIFT		(0x0005u)
#define _PLL_PLLCSR_LOCK_MK(n)		(((Uint16)(n) & 0x0001u) << _PLL_PLLCSR_LOCK_SHIFT)
#define _PLL_PLLCSR_LOCK_MASK		(_PLL_PLLCSR_LOCK_MK(0x0001u))
#define _PLL_PLLCSR_LOCK_CLR		(~(_PLL_PLLCSR_LOCK_MASK))



/*----------------------------------------------------------------*\
*   (R)  _PLL_PLLCSR_STABLE:
\*----------------------------------------------------------------*/

#define _PLL_PLLCSR_STABLE_SHIFT		(0x0006u)
#define _PLL_PLLCSR_STABLE_MK(n)		(((Uint16)(n) & 0x0001u) << _PLL_PLLCSR_STABLE_SHIFT)
#define _PLL_PLLCSR_STABLE_MASK		(_PLL_PLLCSR_STABLE_MK(0x0001u))
#define _PLL_PLLCSR_STABLE_CLR		(~(_PLL_PLLCSR_STABLE_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the PLLDIV2 register
\*----------------------------------------------------------------*/

/******************************************************************************\
*
* _PLL_PLLDIV2	 - Sysclk2 Divide Down Register
*
* Fields:
*	(RW)   _PLL_PLLDIV2_PLLDIV2
*	(RW)   _PLL_PLLDIV2_D2EN
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _PLL_PLLDIV2_PLLDIV2:
\*----------------------------------------------------------------*/

#define _PLL_PLLDIV2_PLLDIV2_SHIFT		(000000u)
#define _PLL_PLLDIV2_PLLDIV2_MK(n)		(((Uint16)(n) & 0x001fu) << _PLL_PLLDIV2_PLLDIV2_SHIFT)
#define _PLL_PLLDIV2_PLLDIV2_MASK		(_PLL_PLLDIV2_PLLDIV2_MK(0x001fu))
#define _PLL_PLLDIV2_PLLDIV2_CLR		(~(_PLL_PLLDIV2_PLLDIV2_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _PLL_PLLDIV2_D2EN:
\*----------------------------------------------------------------*/

#define _PLL_PLLDIV2_D2EN_SHIFT		(0x000fu)
#define _PLL_PLLDIV2_D2EN_MK(n)		(((Uint16)(n) & 0x0001u) << _PLL_PLLDIV2_D2EN_SHIFT)
#define _PLL_PLLDIV2_D2EN_MASK		(_PLL_PLLDIV2_D2EN_MK(0x0001u))
#define _PLL_PLLDIV2_D2EN_CLR		(~(_PLL_PLLDIV2_D2EN_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the PLLDIV3 register
\*----------------------------------------------------------------*/

/******************************************************************************\
*
* _PLL_PLLDIV3	 - Sysclk3 Divide Down Register
*
* Fields:
*	(RW)   _PLL_PLLDIV3_PLLDIV3
*	(RW)   _PLL_PLLDIV3_D3EN
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _PLL_PLLDIV3_PLLDIV3:
\*----------------------------------------------------------------*/

#define _PLL_PLLDIV3_PLLDIV3_SHIFT		(000000u)
#define _PLL_PLLDIV3_PLLDIV3_MK(n)		(((Uint16)(n) & 0x001fu) << _PLL_PLLDIV3_PLLDIV3_SHIFT)
#define _PLL_PLLDIV3_PLLDIV3_MASK		(_PLL_PLLDIV3_PLLDIV3_MK(0x001fu))
#define _PLL_PLLDIV3_PLLDIV3_CLR		(~(_PLL_PLLDIV3_PLLDIV3_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _PLL_PLLDIV3_D3EN:
\*----------------------------------------------------------------*/

#define _PLL_PLLDIV3_D3EN_SHIFT		(0x000fu)
#define _PLL_PLLDIV3_D3EN_MK(n)		(((Uint16)(n) & 0x0001u) << _PLL_PLLDIV3_D3EN_SHIFT)
#define _PLL_PLLDIV3_D3EN_MASK		(_PLL_PLLDIV3_D3EN_MK(0x0001u))
#define _PLL_PLLDIV3_D3EN_CLR		(~(_PLL_PLLDIV3_D3EN_MASK))


#elif (!(_PLL_MOD))
	#error PLL Hal Module Not Supported on Specified Target
#endif  /* _PLLB_SUPPORT  */

#endif  /* _CSL_PLLBHAL_H  */

/******************************************************************************\
*
*      End of csl_pllBhal.h
*
\******************************************************************************/
