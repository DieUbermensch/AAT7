/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... TIMER
* FILENAME...... csl_timhal.h
* DATE CREATED.. Tues 05/23/2000 
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS.. stdinc.h, chip.h
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:       05/23/2000 (AP) created  
*   MODIFIED:      07/20/2000 (NNS) modified
*   LAST MODIFIED: 04/16/2001 updated FILENAME and other header comments
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the TIMER module)
*
* Registers Covered:
*   (RW) _TIMER_TCR0  -  Timer 0 control register
*   (RW) _TIMER_TCR1  -  Timer 1 control register
*   (RW) _TIMER_PRD0  -  Timer 0 period register
*   (RW) _TIMER_PRD1  -  Timer 1 perid register
*   (RW) _TIMER_PRSC0 -  Timer 0 prescaler register
*   (RW) _TIMER_PRSC1 -  Timer 1 prescaler register
*   (RW) _TIMER_TIM0  -  Timer 0 count register
*   (RW) _TIMER_TIM1  -  Timer 1 count register
*
\******************************************************************************/
#ifndef _CSL_TIMERHAL_H_
#define _CSL_TIMERHAL_H_

#include <csl_chiphal.h>

#if (_TIMER_SUPPORT)

/****************************************\
* _TIMER scope and inline control macros
\****************************************/
#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#define IDECL static inline
#define USEDEFS
#define IDEF  static inline

/*============================================================================*\
* misc declarations
\*============================================================================*/

#define _TIMER_DEVICE_CNT			(2)

/*============================================================================*\
* Generic Timer register/field set/get macros
\*============================================================================*/

#define TIMER_ADDR(Reg)                  _TIMER_##Reg##_ADDR
#define TIMER_RGET(Reg)                  _PREG_GET(TIMER_ADDR(##Reg))
#define TIMER_RSET(Reg,Val)              _PREG_SET(TIMER_ADDR(##Reg),Val)
#define TIMER_RAOI(Reg,AND,OR,INV)       _PREG_AOI(TIMER_ADDR(##Reg),AND,OR,INV)

#define TIMER_FGET(Reg,Field)           _TIMER_##Reg##_FGET(##Field)
#define TIMER_FSET(Reg,Field,Val)       _TIMER_##Reg##_FSET(##Field,Val)

#define TIMER_FAOI(Reg,Field,AND,OR,INV) _TIMER_##Reg##_FAOI(##Field,AND,OR,INV)
#define TIMER_FMK(Reg,Field,Val)         _TIMER_##Reg##_##Field##_MK(Val)
#define TIMER_FMKS(Reg,Field,Sym)        TIMER_FMK(##Reg,##Field,TIMER_##Reg##_##Field##_##Sym)

#define TIMER_ADDRH(Handle,Reg)         _TIMER_##Reg##_ADDR(((TIMER_PrivateObj*)(Handle))->Timer)
#define TIMER_RGETH(Handle,Reg)         _PREG_GET(TIMER_ADDRH(Handle,##Reg))
#define TIMER_RSETH(Handle,Reg,Val)     _PREG_SET(TIMER_ADDRH(Handle,##Reg),Val)

#define TIMER_FSETS(Reg,Field,Sym)       _TIMER_##Reg##_FSETS(##Reg,##Field,Sym)

#define TIMER_RAOIH(Handle,Reg,AND,OR,INV)\
  _PREG_AOI(TIMER_ADDRH(Handle,##Reg),AND,OR,INV)

#define TIMER_FGETH(Handle,Reg,Field)\
   _TIMER_##Reg##_FGET(((TIMER_PrivateObj*)(Handle))->Timer,##Field)

#define TIMER_FSETH(Handle,Reg,Field,Val)\
   _TIMER_##Reg##_FSET(((TIMER_PrivateObj*)(Handle))->Timer,##Field,Val)

#define TIMER_FSETSH(Handle,Reg,Field,Sym)\
   TIMER_FSET(((TIMER_PrivateObj*)(Handle))->Timer,##Reg,##Field,TIMER_##Reg##_##Field##_##Sym)

#define TIMER_FAOIH(Handle,Reg,Field,AND,OR,INV)\
   _TIMER_##Reg##_FAOI(((TIMER_PrivateObj*)(Handle))->Timer,##Field,AND,OR,INV)

#define TIMER_ADDR_H(Handle,Reg)         _TIMER_##Reg##_ADDR(((TIMER_PrivateObj*)(Handle))->Timer)
#define TIMER_RGET_H(Handle,Reg)         _PREG_GET(TIMER_ADDRH(Handle,##Reg))
#define TIMER_RSET_H(Handle,Reg,Val)     _PREG_SET(TIMER_ADDRH(Handle,##Reg),Val)

#define TIMER_FSETS(Reg,Field,Sym)       _TIMER_##Reg##_FSETS(##Reg,##Field,Sym)

#define TIMER_RAOI_H(Handle,Reg,AND,OR,INV)\
  _PREG_AOI(TIMER_ADDRH(Handle,##Reg),AND,OR,INV)

#define TIMER_FGET_H(Handle,Reg,Field)\
   _TIMER_##Reg##_FGET(((TIMER_PrivateObj*)(Handle))->Timer,##Field)

#define TIMER_FSET_H(Handle,Reg,Field,Val)\
   _TIMER_##Reg##_FSET(((TIMER_PrivateObj*)(Handle))->Timer,##Field,Val)

#define TIMER_FSETS_H(Handle,Reg,Field,Sym)\
   TIMER_FSET(((TIMER_PrivateObj*)(Handle))->Timer,##Reg,##Field,TIMER_##Reg##_##Field##_##Sym)

#define TIMER_FAOI_H(Handle,Reg,Field,AND,OR,INV)\
   _TIMER_##Reg##_FAOI(((TIMER_PrivateObj*)(Handle))->Timer,##Field,AND,OR,INV)


/*============================================================================*\
* _TIMER_TCR0:  Timer Control Register for Timer #0
\*============================================================================*/
#define _TIMER_TCR0_ADDR			(0x1002u)
#define _TIMER_TCR0                       PREG16(_TIMER_TCR0_ADDR)
#define _TCR0                              _TIMER_TCR0

#define _TIMER_TCR1_ADDR			(0x2402u)
#define _TIMER_TCR1				PREG16(_TIMER_TCR1_ADDR)
#define _TCR1					_TIMER_TCR1

#define _TIMER_TCR_BASE                  (0x1002u)
#define _TIMER_TCR_ADDR(Timer)           ((Timer*0x1400) + _TIMER_TCR_BASE)

/*============================================================================*\
* _TIMER_PRD0:  Period Register, Timer #0
\*============================================================================*/
#define _TIMER_PRD0_ADDR                  (0x1001u)
#define _TIMER_PRD0                       PREG16(_TIMER_PRD0_ADDR)
#define _PRD0                              _TIMER_PRD0

/*============================================================================
* _TIMER_PRD1:  Period Register, TImer #1
\*============================================================================*/
#define _TIMER_PRD1_ADDR			(0x2401u)
#define _TIMER_PRD1				PREG16(_TIMER_PRD1_ADDR)
#define _PRD1					_TIMER_PRD1

#define _TIMER_PRD_BASE                   (0x1001u)
#define _TIMER_PRD_ADDR(Timer)            ((Timer*0x1400u)+_TIMER_PRD_BASE)

/*============================================================================*\
* _TIMER_PRSC0:  Timer Prescalar Register, Timer #0
\*============================================================================*/
#define _TIMER_PRSC0_ADDR			(0x1003u)
#define _TIMER_PRSC0				PREG16(_TIMER_PRSC0_ADDR)
#define _PRSC0                                   _TIMER_PRSC0

/*============================================================================*\
* _TIMER_PRSC1:  Timer Prescalar Register, Timer #1
\*============================================================================*/
#define _TIMER_PRSC1_ADDR			(0x2403u)
#define _TIMER_PRSC1				PREG16(_TIMER_PRSC1_ADDR)
#define _PRSC1                                   _TIMER_PRSC1

#define _TIMER_PRSC_BASE                  (0x1003u)
#define _TIMER_PRSC_ADDR(Timer)           ((Timer*0x1400u)+_TIMER_PRSC_BASE)

/*============================================================================*\
* _TIMER_TIM0:  Timer Count Register, Timer #0
\*============================================================================*/
#define _TIMER_TIM0_ADDR			(0x1000u)
#define _TIMER_TIM0				PREG16(_TIMER_TIM0_ADDR)
#define _TIM0					_TIMER_TIM0

#define _TIMER_TIM1_ADDR			(0x2400u)
#define _TIMER_TIM1				PREG16(_TIMER_TIM1_ADDR)
#define _TIM1					_TIMER_TIM1

#define _TIMER_TIM_BASE                  (0x1000u)
#define _TIMER_TIM_ADDR(Timer)           ((Timer*0x1400u)+_TIMER_TIM_BASE)
             
/*============================================================================
* _TIMER_TCR_GET and _TIMER_TCR_SET
*============================================================================*/
#define _TIMER_TCR_GET(Timer)           _PREG_GET(_TIMER_TCR_ADDR(Timer))
#define _TIMER_TCR_SET(Timer,Val)       _PREG_SET(_TIMER_TCR_ADDR(Timer),Val)

#define _TIMER_TCR_AOI(Timer,AND,OR,INV)\
  _PREG_AOI(_TIMER_TCR_ADDR(Timer),AND,OR,INV)

#define _TIMER_TCR_FGET(Timer,Field)\
   _PFIELD_GET(_TIMER_TCR_ADDR(Timer),_TIMER_TCR_##Field)

#define _TIMER_TCR_FSET(Timer,Field,Val)\
   _PFIELD_SET(_TIMER_TCR_ADDR(Timer),_TIMER_TCR_##Field,Val)

#define _TIMER_TCR_FAOI(Timer,Field,AND,OR,INV)\
   _PFIELD_AOI(_TIMER_TCR_ADDR(Timer),_TIMER_TCR_##Field,AND,OR,INV)

#define _TIMER_TCR0_FGET(Field)             _TIMER_TCR_FGET(0,##Field)
#define _TIMER_TCR0_FSET(Field,Val)         _TIMER_TCR_FSET(0,##Field,Val)
#define _TIMER_TCR0_FAOI(Field,AND,OR,INV)  _TIMER_TCR_FAOI(0,##Field,AND,OR,INV)


#define _TIMER_TCR1_FGET(Field)             _TIMER_TCR_FGET(0,##Field)
#define _TIMER_TCR1_FSET(Field,Val)         _TIMER_TCR_FSET(1,##Field,Val)
#define _TIMER_TCR1_FAOI(Field,AND,OR,INV)  _TIMER_TCR_FAOI(0,##Field,AND,OR,INV)


/*============================================================================
* _TIMER_PRD_GET and _TIMER_PRD_SET macros
\*============================================================================*/
#define _TIMER_PRD_GET(Timer)           _PREG_GET(_TIMER_PRD_ADDR(Timer))
#define _TIMER_PRD_SET(Timer,Val)       _PREG_SET(_TIMER_PRD_ADDR(Timer),Val)

#define _TIMER_PRD_AOI(Timer,AND,OR,INV)\
  _PREG_AOI(_TIMER_PRD_ADDR(Timer),AND,OR,INV)

#define _TIMER_PRD_FGET(Timer,Field)\
   _PFIELD_GET(_TIMER_PRD_ADDR(Timer),_TIMER_PRD_##Field)

#define _TIMER_PRD_FSET(Timer,Field,Val)\
   _PFIELD_SET(_TIMER_PRD_ADDR(Timer),_TIMER_PRD_##Field,Val)

#define _TIMER_PRD_FAOI(Timer,Field,AND,OR,INV)\
   _PFIELD_AOI(_TIMER_PRD_ADDR(Timer),_TIMER_PRD_##Field,AND,OR,INV)

#define _TIMER_PRD0_FGET(Field)             _TIMER_PRD_FGET(0,##Field)
#define _TIMER_PRD0_FSET(Field,Val)         _TIMER_PRD_FSET(1,##Field,Val)
#define _TIMER_PRD0_FAOI(Field,AND,OR,INV)  _TIMER_PRD_FAOI(0,##Field,AND,OR,INV)

#define _TIMER_PRD1_FGET(Field)             _TIMER_PRD_FGET(0,##Field)
#define _TIMER_PRD1_FSET(Field,Val)         _TIMER_PRD_FSET(1,##Field,Val)
#define _TIMER_PRD1_FAOI(Field,AND,OR,INV)  _TIMER_PRD_FAOI(0,##Field,AND,OR,INV)

/*============================================================================*\
* _TIMER_PRSC_GET and _TIMER_PRSC_SET
\*============================================================================*/
#define _TIMER_PRSC_GET(Timer)           _PREG_GET(_TIMER_PRSC_ADDR(Timer))
#define _TIMER_PRSC_SET(Timer,Val)       _PREG_SET(_TIMER_PRSC_ADDR(Timer),Val)

#define _TIMER_PRSC_AOI(Timer,AND,OR,INV)\
  _PREG_AOI(_TIMER_PRSC_ADDR(Timer),AND,OR,INV)

#define _TIMER_PRSC_FGET(Timer,Field)\
   _PFIELD_GET(_TIMER_PRSC_ADDR(Timer),_TIMER_PRSC_##Field)

#define _TIMER_PRSC_FSET(Timer,Field,Val)\
   _PFIELD_SET(_TIMER_PRSC_ADDR(Timer),_TIMER_PRSC_##Field,Val)

#define _TIMER_PRSC_FAOI(Timer,Field,AND,OR,INV)\
   _PFIELD_AOI(_TIMER_PRSC_ADDR(Timer),_TIMER_PRSC_##Field,AND,OR,INV)

#define _TIMER_PRSC0_FGET(Field)             _TIMER_PRSC_FGET(0,##Field)
#define _TIMER_PRSC0_FSET(Field,Val)         _TIMER_PRSC_FSET(1,##Field,Val)
#define _TIMER_PRSC0_FAOI(Field,AND,OR,INV)  _TIMER_PRSC_FAOI(0,##Field,AND,OR,INV)

#define _TIMER_PRSC1_FGET(Field)             _TIMER_PRSC_FGET(0,##Field)
#define _TIMER_PRSC1_FSET(Field,Val)         _TIMER_PRSC_FSET(1,##Field,Val)
#define _TIMER_PRSC1_FAOI(Field,AND,OR,INV)  _TIMER_PRSC_FAOI(0,##Field,AND,OR,INV)

/*============================================================================*\
* _TIMER_TIM_GET and _TIMER_TIM_SET
\*============================================================================*/
#define _TIMER_TIM_GET(Timer)           _PREG_GET(_TIMER_TIM_ADDR(Timer))
#define _TIMER_TIM_SET(Timer,Val)       _PREG_SET(_TIMER_TIM_ADDR(Timer),Val)

#define _TIMER_TIM_AOI(Timer,AND,OR,INV)\
  _PREG_AOI(_TIMER_TIM_ADDR(Timer),AND,OR,INV)

#define _TIMER_TIM_FGET(Timer,Field)\
   _PFIELD_GET(_TIMER_TIM_ADDR(Timer),_TIMER_TIM_##Field)

#define _TIMER_TIM_FSET(Timer,Field,Val)\
   _PFIELD_SET(_TIMER_TIM_ADDR(Timer),_TIMER_TIM_##Field,Val)

#define _TIMER_TIM_FAOI(Timer,Field,AND,OR,INV)\
   _PFIELD_AOI(_TIMER_TIM_ADDR(Timer),_TIMER_TIM_##Field,AND,OR,INV)

#define _TIMER_TIM0_FGET(Field)             _TIMER_TIM_FGET(0,##Field)
#define _TIMER_TIM0_FSET(Field,Val)         _TIMER_TIM_FSET(1,##Field,Val)
#define _TIMER_TIM0_FAOI(Field,AND,OR,INV)  _TIMER_TIM_FAOI(0,##Field,AND,OR,INV)

#define _TIMER_TIM1_FGET(Field)             _TIMER_TIM_FGET(0,##Field)
#define _TIMER_TIM1_FSET(Field,Val)         _TIMER_TIM_FSET(1,##Field,Val)
#define _TIMER_TIM1_FAOI(Field,AND,OR,INV)  _TIMER_TIM_FAOI(0,##Field,AND,OR,INV)


/*===========================================================================*\
* _TIMER_TCR0    - Control Register, Timer #0
* _TIMER_TCR1    - Control Register, Timer #1
*
* Fields:
*  (RW) _TIMER_TCR_IDLEEN
*  (R) _TIMER_TCR_INTEXT
*  (R) _TIMER_TCR_ERRTIM
*  (RW) _TIMER_TCR_FUNC
*  (RW) _TIMER_TCR_TLB
*  (RW) _TIMER_TCR_SOFT
*  (RW) _TIMER_TCR_FREE
*  (RW) _TIMER_TCR_PWID
*  (RW) _TIMER_TCR_ARB
*  (RW) _TIMER_TCR_TSS
*  (RW) _TIMER_TCR_CP
*  (RW) _TIMER_TCR_POLAR
*  (RW) _TIMER_TCR_DATOUT
\*==========================================================================*/

/*==========================================================================*\
* (RW) _TIMER_TCR_IDLEEN
\*--------------------------------------------------------------------------*/
#define _TIMER_TCR_IDLEEN_SHIFT		(0x000Fu)
#define _TIMER_TCR_IDLEEN_MK(n)           (((Uint16)(n) & 0x0001u) << _TIMER_TCR_IDLEEN_SHIFT)
#define _TIMER_TCR_IDLEEN_MASK            (_TIMER_TCR_IDLEEN_MK(1))
#define _TIMER_TCR_IDLEEN_CLR             (~(_TIMER_TCR_IDLEEN_MK(1)))

/*==========================================================================*\
* (RW) _TIMER_TCR_INTEXT
\*--------------------------------------------------------------------------*/
#define _TIMER_TCR_INTEXT_SHIFT		(0x000Eu)
#define _TIMER_TCR_INTEXT_MK(n)		(((Uint16)(n) & 0x0001u) << _TIMER_TCR_INTEXT_SHIFT)
#define _TIMER_TCR_INTEXT_MASK		(_TIMER_TCR_INTEXT_MK(1))
#define _TIMER_TCR_INTEXT_CLR			(~(_TIMER_TCR_INTEXT_MK(1)))

/*==========================================================================*\
* (RW) _TIMER_TCR_ERRTIM
\*--------------------------------------------------------------------------*/
#define _TIMER_TCR_ERRTIM_SHIFT		(0x000Du)
#define _TIMER_TCR_ERRTIM_MK(n)		(((Uint16)(n) & 0x0001u) << _TIMER_TCR_ERRTIM_SHIFT)
#define _TIMER_TCR_ERRTIM_MASK		(_TIMER_TCR_ERRTIM_MK(1))
#define _TIMER_TCR_ERRTIM_CLR			(~(_TIMER_TCR_ERRTIM_MK(1)))

/*==========================================================================*\
* (RW) _TIMER_TCR_FUNC
\*--------------------------------------------------------------------------*/
#define _TIMER_TCR_FUNC_SHIFT			(0x000Bu)
#define _TIMER_TCR_FUNC_MK(n)			(((Uint16)(n) & 0x0003u) << _TIMER_TCR_FUNC_SHIFT)
#define _TIMER_TCR_FUNC_MASK			(_TIMER_TCR_FUNC_MK(0x0003u))
#define _TIMER_TCR_FUNC_CLR			(~(_TIMER_TCR_FUNC_MK(0x0003u)))

/*==========================================================================*\
* (RW) _TIMER_TCR_TLB
\*--------------------------------------------------------------------------*/
#define _TIMER_TCR_TLB_SHIFT			(0x000Au)
#define _TIMER_TCR_TLB_MK(n)			(((Uint16)(n) & 0x0001u) << _TIMER_TCR_TLB_SHIFT)
#define _TIMER_TCR_TLB_MASK			(_TIMER_TCR_TLB_MK(1))
#define _TIMER_TCR_TLB_CLR			(~(_TIMER_TCR_TLB_MK(1)))

/*==========================================================================*\
* (RW) _TIMER_TCR_SOFT
\*--------------------------------------------------------------------------*/
#define _TIMER_TCR_SOFT_SHIFT			(0x0009u)
#define _TIMER_TCR_SOFT_MK(n)			(((Uint16)(n) & 0x0001u) << _TIMER_TCR_SOFT_SHIFT)
#define _TIMER_TCR_SOFT_MASK			(_TIMER_TCR_SOFT_MK(1))
#define _TIMER_TCR_SOFT_CLR			(~(_TIMER_TCR_SOFT_MK(1)))

/*==========================================================================*\
* (RW) _TIMER_TCR_FREE
\*--------------------------------------------------------------------------*/
#define _TIMER_TCR_FREE_SHIFT			(0x0008u)
#define _TIMER_TCR_FREE_MK(n)			(((Uint16)(n) & 0x0001u) << _TIMER_TCR_FREE_SHIFT)
#define _TIMER_TCR_FREE_MASK			(_TIMER_TCR_FREE_MK(1))
#define _TIMER_TCR_FREE_CLR			(~(_TIMER_TCR_FREE_MK(1)))

/*==========================================================================*\
* (RW) _TIMER_TCR_PWID
\*--------------------------------------------------------------------------*/
#define _TIMER_TCR_PWID_SHIFT			(0x0006u)
#define _TIMER_TCR_PWID_MK(n)			(((Uint16)(n) & 0x0003u) << _TIMER_TCR_PWID_SHIFT)
#define _TIMER_TCR_PWID_MASK			(_TIMER_TCR_PWID_MK(0x0003u))
#define _TIMER_TCR_PWID_CLR			(~(_TIMER_TCR_PWID_MK(0x0003u)))

/*==========================================================================*\
* (RW) _TIMER_TCR_ARB
\*--------------------------------------------------------------------------*/
#define _TIMER_TCR_ARB_SHIFT			(0x0005u)
#define _TIMER_TCR_ARB_MK(n)			(((Uint16)(n) & 0x0001u) << _TIMER_TCR_ARB_SHIFT)
#define _TIMER_TCR_ARB_MASK			(_TIMER_TCR_ARB_MK(1))
#define _TIMER_TCR_ARB_CLR			(~(_TIMER_TCR_ARB_MK(1)))

/*==========================================================================*\
* (RW) _TIMER_TCR_TSS
\*--------------------------------------------------------------------------*/
#define _TIMER_TCR_TSS_SHIFT			(0x0004u)
#define _TIMER_TCR_TSS_MK(n)			(((Uint16)(n) & 0x0001u) << _TIMER_TCR_TSS_SHIFT)
#define _TIMER_TCR_TSS_MASK			(_TIMER_TCR_TSS_MK(1))
#define _TIMER_TCR_TSS_CLR			(~(_TIMER_TCR_TSS_MK(1)))

/*==========================================================================*\
* (RW) _TIMER_TCR_CP
\*--------------------------------------------------------------------------*/
#define _TIMER_TCR_CP_SHIFT			(0x0003u)
#define _TIMER_TCR_CP_MK(n)			(((Uint16)(n) & 0x0001u) << _TIMER_TCR_CP_SHIFT)
#define _TIMER_TCR_CP_MASK			(_TIMER_TCR_CP_MK(1))
#define _TIMER_TCR_CP_CLR			(~(_TIMER_TCR_CP_MK(1)))

/*==========================================================================*\
* (RW) _TIMER_TCR_POLAR
\*--------------------------------------------------------------------------*/
#define _TIMER_TCR_POLAR_SHIFT		(0x0002u)
#define _TIMER_TCR_POLAR_MK(n)		(((Uint16)(n) & 0x0001u) << _TIMER_TCR_POLAR_SHIFT)
#define _TIMER_TCR_POLAR_MASK			(_TIMER_TCR_POLAR_MK(1))
#define _TIMER_TCR_POLAR_CLR			(~(_TIMER_TCR_POLAR_MK(1)))

/*==========================================================================*\
* (RW) _TIMER_TCR_DATOUT
\*--------------------------------------------------------------------------*/
#define _TIMER_TCR_DATOUT_SHIFT		(0x0001u)
#define _TIMER_TCR_DATOUT_MK(n)		(((Uint16)(n) & 0x0001u) << _TIMER_TCR_DATOUT_SHIFT)
#define _TIMER_TCR_DATOUT_MASK		(_TIMER_TCR_DATOUT_MK(1))
#define _TIMER_TCR_DATOUT_CLR			(~(_TIMER_TCR_DATOUT_MK(1)))

/*==========================================================================*\
* Timer Control #1 and Timer Control #2 Config
\*--------------------------------------------------------------------------*/

#define _TIMER_TCR0_CFG(idleen,intext,errtim,func,tlb,soft,free,pwid,arb,tss, \
		cp,polar,dataout) \
	_PREG_SET(_TIMER_TCR0_ADDR, \
    		(Uint16) (	_TIMER_TCR_IDLEEN_MK(idleen) 	|	\
            	    	_TIMER_TCR_INTEXT_MK(intext) 	|	\
			    	_TIMER_TCR_ERRTIM_MK(errtim) 	|	\
			    	_TIMER_TCR_FUNC_MK(func) 	|	\
			    	_TIMER_TCR_TLB_MK(tlb)		|	\
			    	_TIMER_TCR_SOFT_MK(soft) 	|	\
				_TIMER_TCR_FREE_MK(free) 	|	\
				_TIMER_TCR_PWID_MK(pwid) 	|	\
				_TIMER_TCR_ARB_MK(arb) 		|	\
				_TIMER_TCR_TSS_MK(tss)	 	|	\
				_TIMER_TCR_CP_MK(cp)	 	|	\
				_TIMER_TCR_POLAR_MK(polar) 	|	\
				_TIMER_TCR_DATOUT_MK(DATOUT) 		\
             ))

#define _TIMER_TCR1_CFG(idleen,intext,errtim,func,tlb,soft,free,pwid,arb,tss, \
		cp,polar,dataout) \
	_PREG_SET(_TIMER_TCR1_ADDR, \
    		(Uint16) (	_TIMER_TCR_IDLEEN_MK(idleen) 	|	\
            	    	_TIMER_TCR_INTEXT_MK(intext) 	|	\
			    	_TIMER_TCR_ERRTIM_MK(errtim) 	|	\
			    	_TIMER_TCR_FUNC_MK(func) 	|	\
			    	_TIMER_TCR_TLB_MK(tlb)		|	\
			    	_TIMER_TCR_SOFT_MK(soft) 	|	\
				_TIMER_TCR_FREE_MK(free) 	|	\
				_TIMER_TCR_PWID_MK(pwid) 	|	\
				_TIMER_TCR_ARB_MK(arb) 		|	\
				_TIMER_TCR_TSS_MK(tss)	 	|	\
				_TIMER_TCR_CP_MK(cp)	 	|	\
				_TIMER_TCR_POLAR_MK(polar) 	|	\
				_TIMER_TCR_DATOUT_MK(DATOUT) 		\
             ))


/*===========================================================================*\
* _TIMER_PRD0    - Timer Period Register, Timer #0
* _TIMER_PRD1    - Timer Period Register, Timer #1
*
* Fields:
*  (RW) _TIMER_PRD_PRD
\*==========================================================================*/


/*==========================================================================*\
* (RW) _TIMER_PRD_PRD
\*--------------------------------------------------------------------------*/
#define _TIMER_PRD_PRD_SHIFT		(0x0000u)
#define _TIMER_PRD_PRD_MK(n)		(((Uint16)(n) & 0xFFFFu) << _TIMER_PRD_PRD_SHIFT)
#define _TIMER_PRD_PRD_MASK		(_TIMER_PRD_PRD_MK(0xFFFFu))
#define _TIMER_PRD_PRD_CLR		(~(_TIMER_PRD_PRD_MK(0xFFFFu)))

/*==========================================================================*\
* PRD Config, Timer #1 and #2
\*--------------------------------------------------------------------------*/
#define _TIMER_PRD0_CFG(tim) \
	_PREG_SET(_TIMER_PRD0_ADDR,(Uint16)_TIMER_PRD_PRD_MK(n)(tim))

#define _TIMER_PRD1_CFG(tim) \
	_PREG_SET(_TIMER_PRD1_ADDR,(Uint16)_TIMER_PRD_PRD_MK(n)(tim))


/*===========================================================================*\
* _TIMER_TIM0    - Timer Register, Timer #0
* _TIMER_TIM1    - Timer Register, Timer #1
*
* Fields:
*  (RW) _TIMER_TIM_TIM
\*==========================================================================*/


/*==========================================================================*\
* (RW) _TIMER_TIM_TIM
\*--------------------------------------------------------------------------*/
#define _TIMER_TIM_TIM_SHIFT		(0x0000u)
#define _TIMER_TIM_TIM_MK(n)		(((Uint16)(n) & 0xFFFFu) << _TIMER_TIM_TIM_SHIFT)
#define _TIMER_TIM_TIM_MASK		(_TIMER_TIM_TIM_MK(0xFFFFu))
#define _TIMER_TIM_TIM_CLR		(~(_TIMER_TIM_TIM_MK(0xFFFFu)))

/*==========================================================================*\
* TIM Config, Timer #1 and #2
\*--------------------------------------------------------------------------*/
#define _TIMER_TIM0_CFG(tim) \
	_PREG_SET(_TIMER_TIM0_ADDR,(Uint16)_TIMER_TIM_TIM_MK(tim))

#define _TIMER_TIM1_CFG(tim) \
	_PREG_SET(_TIMER_TIM1_ADDR,(Uint16)_TIMER_TIM_TIM_MK(tim))


/*===========================================================================*\
* _TIMER_PRSC0    - Time Prescalar Register, Timer #0
* _TIMER_PRSC1    - Time Prescalar Register, Timer #1
*
* Fields:
*  (RW) _TIMER_PRSC_PSC
*  (RW) _TIMER_PRSC_TDDR
\*==========================================================================*/


/*==========================================================================*\
* (RW) _TIMER_PRSC_PSC
\*--------------------------------------------------------------------------*/
#define _TIMER_PRSC_PSC_SHIFT		(0x0006u)
#define _TIMER_PRSC_PSC_MK(n)		(((Uint16)(n) & 0x000Fu) << _TIMER_PRSC_PSC_SHIFT)
#define _TIMER_PRSC_PSC_MASK		(_TIMER_PRSC_PSC_MK(0x000Fu))
#define _TIMER_PRSC_PSC_CLR		(~(_TIMER_PRSC_PSC_MK(0x000Fu)))

/*==========================================================================*\
* (RW) _TIMER_PRSC_TDDR
\*--------------------------------------------------------------------------*/
#define _TIMER_PRSC_TDDR_SHIFT	(0x0000u)
#define _TIMER_PRSC_TDDR_MK(n)	(((Uint16)(n) & 0x000Fu) << _TIMER_PRSC_TDDR_SHIFT)
#define _TIMER_PRSC_TDDR_MASK		(_TIMER_PRSC_TDDR_MK(0x000Fu))
#define _TIMER_PRSC_TDDR_CLR		(~(_TIMER_PRSC_TDDR_MK(0x000Fu)))

/*==========================================================================*\
* Timer Prescalar Register #1 and #2 Config
\*--------------------------------------------------------------------------*/
#define _TIMER_PRSC0_CFG(psc,tddr) \
	_PREG_SET(_TIMER_PRSC0_ADDR, \
		(Uint16)	_TIMER_PRSC_PSC_MK(tim)		| 	\
				_TIMER_PRSC_TDDR_MK(tddr) 		\
		))
		
#define _TIMER_PRSC1_CFG(psc,tddr) \
	_PREG_SET(_TIMER_PRSC1_ADDR, \
		(Uint16)	_TIMER_PRSC_PSC_MK(tim)		| 	\
				_TIMER_PRSC_TDDR_MK(tddr) 		\
		))


#elif (!(_TIMER_MOD_))
	#error TIMER Hal Module Not Supported on Specified Target
#endif
#endif
