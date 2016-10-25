/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... PLL
* FILENAME...... pllhal.h
* DATE CREATED.. Mon 06/05/2000
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS.. stdinc.h, chip.h
*------------------------------------------------------------------------------
* HISTORY:
*   06/05/2000 (AP) created
*   07/05/2001 (IM) Modified to include support for both DPLL and APLL
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the PLL module)
*
* Registers Covered:
*   (RW) _PLL_CLKMD
\******************************************************************************/

#ifndef _PLLHAL_H_
#define _PLLHAL_H_

#include <csl_chiphal.h>

#if (_PLL_SUPPORT)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _PLL_CLKMD
\*============================================================================*/
#define _PLL_CLKMD_ADDR					(0x1C00u)
#define _PLL_CLKMD                       		PREG16(_PLL_CLKMD_ADDR)
#define _CLKMD                              	_PLL_CLKMD

/*===========================================================================*\
* Generic PLL register/field get/set macros
\*===========================================================================*/

#define PLL_ADDR(Reg)                     _PLL_##Reg##_ADDR
#define PLL_RGET(Reg)                     _PREG_GET(PLL_ADDR(##Reg))
#define PLL_RSET(Reg,Val)                 _PREG_SET(PLL_ADDR(##Reg),Val)
#define PLL_RAOI(Reg,AND,OR,INV)          _PREG_AOI(PLL_ADDR(##Reg),AND,OR,INV)
#define PLL_FGET(Reg,Field)               _PFIELD_GET(PLL_ADDR(##Reg),_PLL_##Reg##_##Field)
#define PLL_FSET(Reg,Field,Val)\
  _PFIELD_SET(PLL_ADDR(##Reg),_PLL_##Reg##_##Field,Val)

#define PLL_FSETS(Reg,Field,Sym)\
  PLL_FSET(##Reg,##Field,PLL_##Reg##_##Field##_##Sym)

#define PLL_FAOI(Reg,Field,AND,OR,INV)\
  _PFIELD_AOI(PLL_ADDR(##Reg),_PLL_##Reg##_##Feld,AND,OR,INV)

#define PLL_FMK(Reg,Field,Val)            _PLL_##Reg##_##Field##_MK(Val)
#define PLL_FMKS(Reg,Field,Sym)           PLL_FMK(##Reg,##Field,PLL_##Reg##_##Field##_##Sym)


#if (!(_PLL_ANALOG_SUPPORT))	//Digital PLL

/*===========================================================================*\
* _PLL_CLKMD
*
* Fields:
*  (RW) _PLL_CLKMD_IAI
*  (RW) _PLL_CLKMD_IOB
*  (RW) _PLL_CLKMD_TEST
*  (RW) _PLL_CLKMD_PLLMULT
*  (RW) _PLL_CLKMD_PLLDIV
*  (RW) _PLL_CLKMD_PLLENABLE
*  (RW) _PLL_CLKMD_BYPASSDIV
*   (R) _PLL_CLKMD_BREAKLN
*   (R) _PLL_CLKMD_LOCK
\*==========================================================================*/

/*==========================================================================*\
* (RW) _PLL_CLKMD_IAI	- Initialize After Idle
\*--------------------------------------------------------------------------*/
#define _PLL_CLKMD_IAI_SHIFT			(0x000Eu)
#define _PLL_CLKMD_IAI_MK(n)			(((Uint16)(n) & 0x0001u) << _PLL_CLKMD_IAI_SHIFT)
#define _PLL_CLKMD_IAI_MASK       		(_PLL_CLKMD_IAI_MK(0x0001u))
#define _PLL_CLKMD_IAI_CLR        		(~(_PLL_CLKMD_IAI_MK(0x0001u)))

/*==========================================================================*\
* (RW) _PLL_CLKMD_IOB	- Initialize on Break
\*--------------------------------------------------------------------------*/
#define _PLL_CLKMD_IOB_SHIFT			(0x000Du)
#define _PLL_CLKMD_IOB_MK(n)			(((Uint16)(n) & 0x0001u) << _PLL_CLKMD_IOB_SHIFT)
#define _PLL_CLKMD_IOB_MASK       		(_PLL_CLKMD_IOB_MK(0x0001u))
#define _PLL_CLKMD_IOB_CLR        		(~(_PLL_CLKMD_IOB_MK(0x0001u)))

/*==========================================================================*\
* (RW) _PLL_CLKMD_TEST	- Test
\*--------------------------------------------------------------------------*/
#define _PLL_CLKMD_TEST_SHIFT			(0x000Cu)
#define _PLL_CLKMD_TEST_MK(n)			(((Uint16)(n) & 0x0001u) << _PLL_CLKMD_TEST_SHIFT)
#define _PLL_CLKMD_TEST_MASK       		(_PLL_CLKMD_TEST_MK(0x0001u))
#define _PLL_CLKMD_TEST_CLR        		(~(_PLL_CLKMD_TEST_MK(0x0001u)))

/*==========================================================================*\
* (RW) _PLL_CLKMD_PLLMULT	- PLL Multiply Value
\*--------------------------------------------------------------------------*/
#define _PLL_CLKMD_PLLMULT_SHIFT		(0x0007u)
#define _PLL_CLKMD_PLLMULT_MK(n)		(((Uint16)(n) & 0x001Fu) << _PLL_CLKMD_PLLMULT_SHIFT)
#define _PLL_CLKMD_PLLMULT_MASK       	(_PLL_CLKMD_PLLMULT_MK(0x001Fu))
#define _PLL_CLKMD_PLLMULT_CLR        	(~(_PLL_CLKMD_PLLMULT_MK(0x001Fu)))

/*==========================================================================*\
* (RW) _PLL_CLKMD_PLLDIV	- PLL Divide Value
\*--------------------------------------------------------------------------*/
#define _PLL_CLKMD_PLLDIV_SHIFT		(0x0005u)
#define _PLL_CLKMD_PLLDIV_MK(n)		(((Uint16)(n) & 0x0003u) << _PLL_CLKMD_PLLDIV_SHIFT)
#define _PLL_CLKMD_PLLDIV_MASK       	(_PLL_CLKMD_PLLDIV_MK(0x0003u))
#define _PLL_CLKMD_PLLDIV_CLR        	(~(_PLL_CLKMD_PLLDIV_MK(0x0003u)))

/*==========================================================================*\
* (RW) _PLL_CLKMD_PLLENABLE	- PLL Enable Bit
\*--------------------------------------------------------------------------*/
#define _PLL_CLKMD_PLLENABLE_SHIFT		(0x0004u)
#define _PLL_CLKMD_PLLENABLE_MK(n)		(((Uint16)(n) & 0x0001u) << _PLL_CLKMD_PLLENABLE_SHIFT)
#define _PLL_CLKMD_PLLENABLE_MASK       	(_PLL_CLKMD_PLLENABLE_MK(0x0001u))
#define _PLL_CLKMD_PLLENABLE_CLR        	(~(_PLL_CLKMD_PLLENABLE_MK(0x0001u)))

/*==========================================================================*\
* (RW) _PLL_CLKMD_BYPASSDIV	- Determines CLKOUT Frequency
\*--------------------------------------------------------------------------*/
#define _PLL_CLKMD_BYPASSDIV_SHIFT		(0x0002u)
#define _PLL_CLKMD_BYPASSDIV_MK(n)		(((Uint16)(n) & 0x0003u) << _PLL_CLKMD_BYPASSDIV_SHIFT)
#define _PLL_CLKMD_BYPASSDIV_MASK       	(_PLL_CLKMD_BYPASSDIV_MK(0x0003u))
#define _PLL_CLKMD_BYPASSDIV_CLR        	(~(_PLL_CLKMD_BYPASSDIV_MK(0x0003u)))

/*==========================================================================*\
* (R) _PLL_CLKMD_BREAKLN	- Broken Lock Bit
\*--------------------------------------------------------------------------*/
#define _PLL_CLKMD_BREAKLN_SHIFT		(0x0001u)
#define _PLL_CLKMD_BREAKLN_MK(n)		(((Uint16)(n) & 0x0001u) << _PLL_CLKMD_BREAKLN_SHIFT)
#define _PLL_CLKMD_BREAKLN_MASK       	(_PLL_CLKMD_BREAKLN_MK(0x0001u))

/*==========================================================================*\
* (R) _PLL_CLKMD_LOCK	- Lock Mode Bit
\*--------------------------------------------------------------------------*/
#define _PLL_CLKMD_LOCK_SHIFT			(0x0000u)
#define _PLL_CLKMD_LOCK_MK(n)			(((Uint16)(n) & 0x0001u) << _PLL_CLKMD_LOCK_SHIFT)
#define _PLL_CLKMD_LOCK_MASK       		(_PLL_CLKMD_LOCK_MK(0x0001u))

/*==========================================================================*\
* _PLL_CLKMD 	- Config
\*--------------------------------------------------------------------------*/
#define _PLL_CLKMD_CFG(iai,iob,test,pllmult,plldiv,pllenable,bypassdiv)  \
	_PREG_SET(_PLL_CLKMD_ADDR,							\
    		(Uint16) (	_PLL_CLKMD_IAI_MK(iai) 				|	\
				_PLL_CLKMD_IOB_MK(iob) 				|	\
				_PLL_CLKMD_TEST_MK(test) 			|	\
				_PLL_CLKMD_PLLMULT_MK(pllmult) 		|	\
				_PLL_CLKMD_PLLDIV_MK(plldiv) 			|	\
				_PLL_CLKMD_PLLENABLE_MK(pllenable) 		|	\
				_PLL_CLKMD_BYPASSDIV_MK(bypassdiv) 			\
	             ))

#else			// Analog PLL

/******************************************************************************\
* 
* _PLL_CLKMD	 - Note: Add description here
*
* Fields:
*	(RW)   _PLL_CLKMD_PLLENABLE	
*	(RW)   _PLL_CLKMD_PLLDIV	
*	(RW)   _PLL_CLKMD_PLLMULT	
*	(RW)   _PLL_CLKMD_VCOONOFF	
*
\******************************************************************************/


/*----------------------------------------------------------------*\
*   (RW)  _PLL_CLKMD_PLLENABLE:	
\*----------------------------------------------------------------*/

#define _PLL_CLKMD_PLLENABLE_SHIFT		(0x0004u)
#define _PLL_CLKMD_PLLENABLE_MK(n)		(((Uint16)(n) & 0x0001u) << _PLL_CLKMD_PLLENABLE_SHIFT)
#define _PLL_CLKMD_PLLENABLE_MASK		(_PLL_CLKMD_PLLENABLE_MK(0x0001u))
#define _PLL_CLKMD_PLLENABLE_CLR		(~(_PLL_CLKMD_PLLENABLE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _PLL_CLKMD_PLLDIV:	
\*----------------------------------------------------------------*/

#define _PLL_CLKMD_PLLDIV_SHIFT		(0x0005u)
#define _PLL_CLKMD_PLLDIV_MK(n)		(((Uint16)(n) & 0x0003u) << _PLL_CLKMD_PLLDIV_SHIFT)
#define _PLL_CLKMD_PLLDIV_MASK		(_PLL_CLKMD_PLLDIV_MK(0x0003u))
#define _PLL_CLKMD_PLLDIV_CLR		(~(_PLL_CLKMD_PLLDIV_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _PLL_CLKMD_PLLMULT:	
\*----------------------------------------------------------------*/

#define _PLL_CLKMD_PLLMULT_SHIFT		(0x0007u)
#define _PLL_CLKMD_PLLMULT_MK(n)		(((Uint16)(n) & 0x000fu) << _PLL_CLKMD_PLLMULT_SHIFT)
#define _PLL_CLKMD_PLLMULT_MASK		(_PLL_CLKMD_PLLMULT_MK(0x000fu))
#define _PLL_CLKMD_PLLMULT_CLR		(~(_PLL_CLKMD_PLLMULT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _PLL_CLKMD_VCOONOFF:	
\*----------------------------------------------------------------*/

#define _PLL_CLKMD_VCOONOFF_SHIFT		(0x000bu)
#define _PLL_CLKMD_VCOONOFF_MK(n)		(((Uint16)(n) & 0x0001u) << _PLL_CLKMD_VCOONOFF_SHIFT)
#define _PLL_CLKMD_VCOONOFF_MASK		(_PLL_CLKMD_VCOONOFF_MK(0x0001u))
#define _PLL_CLKMD_VCOONOFF_CLR		(~(_PLL_CLKMD_VCOONOFF_MASK))

/*==========================================================================*\
* _PLL_CLKMD 	- Config
\*--------------------------------------------------------------------------*/
#define _PLL_CLKMD_CFG(vcoonoff,pllmult,plldiv,pllenable)  \
	_PREG_SET(_PLL_CLKMD_ADDR,							\
    		(Uint16) (	_PLL_CLKMD_VCOONOFF_MK(vcoonoff) 			|	\
				_PLL_CLKMD_PLLMULT_MK(pllmult) 		|	\
				_PLL_CLKMD_PLLDIV_MK(plldiv) 			|	\
				_PLL_CLKMD_PLLENABLE_MK(pllenable) 			\
	             ))

#endif

#else
   #ifndef _PLL_MOD_
     #error CLKMD Hal Module Not Supported on Specified Target
   #endif
#endif
#endif    

