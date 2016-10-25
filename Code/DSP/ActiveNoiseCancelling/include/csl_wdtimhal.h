/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... WDTIM
* FILENAME...... csl_wdtimhal.h
* DATE CREATED.. Tues 10/26/1999 
* PROJECT....... Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS.. 
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:      	07/28/2000 
*   LAST MODIFIED:	12/22/2000 (IM) Modified for Amadeus
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the Watch Dog TIMER module)
*
* Registers Covered:
*   (RW) _WDTIM_WDTCR - watchdog timer control register
*   (RW) _WDTIM_WDTCR2 - watchdog timer control register 2
*   (RW) _WDTIM_WDPRD - watchdog timer period register
*   (RW) _WDTIM_WDTIM - watchdog timer count register
*
\******************************************************************************/
#ifndef _CSL_WDTIMHAL_H_
#define _CSL_WDTIMHAL_H_


#include <csl_chiphal.h>

#if (_WDTIM_SUPPORT)
/****************************************\
* TIMER scope and inline control macros
\****************************************/

/*----------------------------------------------------------------------------*\
* Register Macros:
\*----------------------------------------------------------------------------*/
#define WDTIM_ADDR(Reg)               _WDTIM_##Reg##_ADDR
#define WDTIM_RGET(Reg)               _WDTIM_##Reg##_GET
#define WDTIM_RSET(Reg,Val)           _WDTIM_##Reg##_SET(Val)
#define WDTIM_RAOI(Reg,AND,OR,INV)    _WDTIM_##Reg##_AOI(AND,OR,INV)
#define WDTIM_FGET(Reg,Field)         _WDTIM_##Reg##_FGET(##Field)
#define WDTIM_FSET(Reg,Field,Val)     _WDTIM_##Reg##_FSET(##Field,Val)
#define WDTIM_FSETS(Reg,Field,Sym)    WDTIM_FSET(Reg,Field,WDTIM_##Reg##_##Field##_##Sym)
#define WDTIM_FAOI(Reg,Field,AND,OR,INV)\
  _WDTIM_##Reg##_FAOI(Field,AND,OR,INV)
#define WDTIM_FMK(Reg,Field,Val)      _WDTIM_##Reg##_##Field##_MK(Val)
#define WDTIM_FMKS(Reg,Field,Sym)     WDTIM_FMK(##Reg,##Field,WDTIM_##Reg##_##Field##_##Sym)


/******************************************************************************\
* _WDTIM_WDTIM - Watch Dog Timer Timer/Count register
*
* Fields:
*   (RW) TIM
*
\******************************************************************************/


#define _WDTIM_DEVICE_CNT        	  1

#define _WDTIM_WDTIM_ADDR             (0x4000u)
#define _WDTIM_WDTIM                  PREG16(_WDTIM_WDTIM_ADDR)
#define _WDTIM                         _WDTIM_WDTIM


/*----------------------------------------------------------------------------*\
* (RW) _WDTIM_WDTIM_TIM
\*----------------------------------------------------------------------------*/
#define _WDTIM_WDTIM_TIM_SHIFT       (0x0000u)
#define _WDTIM_WDTIM_TIM_MK(n)       (((Uint16)(n) & 0xffffu)<< _WDTIM_WDTIM_TIM_SHIFT)
#define _WDTIM_WDTIM_TIM_MASK        (_WDTIM_WDTIM_TIM_MK(0xffffu))
#define _WDTIM_WDTIM_TIM_CLR         (~(_WDTIM_WDTIM_TIM_MASK))

/*----------------------------------------------------------------------------*\
* Register Macros:
\*----------------------------------------------------------------------------*/


#define _WDTIM_WDTIM_GET              _PREG_GET(_WDTIM_WDTIM_ADDR)
#define _WDTIM_WDTIM_SET(Val)         _PREG_SET(_WDTIM_WDTIM_ADDR,Val)
#define _WDTIM_WDTIM_AOI(AND,OR,INV)  _PREG_AOI(_WDTIM_WDTIM_ADDR,AND,OR,INV)
#define _WDTIM_WDTIM_FGET(Field)      _PFIELD_GET(_WDTIM_WDTIM_ADDR,_WDTIM_WDTIM_##Field)
#define _WDTIM_WDTIM_FSET(Field,Val)  _PFIELD_SET(_WDTIM_WDTIM_ADDR,_WDTIM_WDTIM_##Field,Val)
#define _WDTIM_WDTIM_FSETS(Field,Sym) _WDTIM_WDPRD_FSETS(##Field,WDTIM_WDTIM_##Field##_##Sym)
#define _WDTIM_WDTIM_FAOI(Field,AND,OR,INV)\
   _PFIELD_FAOI(_WDTIM_WDPRD_ADDR,_WDTIM_WDPRD_##Field,AND,OR,INV)


/******************************************************************************\
* _WDTIM_WDPRD - Watch Dog Timer Period Register
*
* Fields:
*   (RW) PRD
*
\******************************************************************************/

#define _WDTIM_WDPRD_ADDR             (0x4001u)
#define _WDTIM_WDPRD                  PREG16(_WDTIM_WDPRD_ADDR)
#define _WDPRD                         _WDTIM_WDPRD

/*----------------------------------------------------------------------------*\
* (RW) WDTIM_WDPRD_PRD
\*----------------------------------------------------------------------------*/
#define _WDTIM_WDPRD_PRD_SHIFT       (0x0000u)
#define _WDTIM_WDPRD_PRD_MK(n)       (((Uint16)(n) & 0xffffu)<< _WDTIM_WDPRD_PRD_SHIFT)
#define _WDTIM_WDPRD_PRD_MASK        (_WDTIM_WDPRD_PRD_MK(0xffffu))
#define _WDTIM_WDPRD_PRD_CLR         (~(_WDTIM_WDPRD_PRD_MASK))

/*----------------------------------------------------------------------------*\
* Register Macros:
\*----------------------------------------------------------------------------*/


#define _WDTIM_WDPRD_GET              _PREG_GET(_WDTIM_WDPRD_ADDR)
#define _WDTIM_WDPRD_SET(Val)         _PREG_SET(_WDTIM_WDPRD_ADDR,Val)
#define _WDTIM_WDPRD_AOI(AND,OR,INV)  _PREG_AOI(_WDTIM_WDPRD_ADDR,AND,OR,INV)
#define _WDTIM_WDPRD_FGET(Field)      _PFIELD_GET(_WDTIM_WDPRD_ADDR,_WDTIM_WDPRD_##Field)
#define _WDTIM_WDPRD_FSET(Field,Val)  _PFIELD_SET(_WDTIM_WDPRD_ADDR,_WDTIM_WDPRD_##Field,Val)
#define _WDTIM_WDPRD_FSETS(Field,Sym) _WDTIM_WDPRD_FSETS(##Field,WDTIM_WDPRD_##Field##_##Sym)
#define _WDTIM_WDPRD_FAOI(Field,AND,OR,INV)\
   _PFIELD_FAOI(_WDTIM_WDPRD_ADDR,_WDTIM_WDPRD_##Field,AND,OR,INV)

/******************************************************************************\
* _WDTIM_TCR 
*
* Fields:
*   (RW) _WDTIM_WDTCR_WDOUT
*   (RW) _WDTIM_WDTCR_SOFT
*   (RW) _WDTIM_WDTCR_FREE
*   (R)  _WDTIM_WDTCR_PSC
*   (RW) _WDTIM_WDTCR_TDDR
*
\******************************************************************************/

#define _WDTIM_WDTCR_ADDR             (0x4002u)
#define _WDTIM_WDTCR                  PREG16(_WDTIM_WDTCR_ADDR)
#define _WDTCR                         _WDTIM_WDTCR

/*----------------------------------------------------------------------------*\
* Watch Dog Timer Control Register (WDTCR) bit/field definitions
\*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*\
* (RW) WDTIM_WDTCR_WDOUT
\*----------------------------------------------------------------------------*/
#define _WDTIM_WDTCR_WDOUT_SHIFT       (0x000cu)
#define _WDTIM_WDTCR_WDOUT_MK(n)       (((Uint16)(n) & 0x0003u)<< _WDTIM_WDTCR_WDOUT_SHIFT)
#define _WDTIM_WDTCR_WDOUT_MASK        (_WDTIM_WDTCR_WDOUT_MK(3))
#define _WDTIM_WDTCR_WDOUT_CLR         (~(_WDTIM_WDTCR_WDOUT_MASK))

/*----------------------------------------------------------------------------*\
* (RW) WDTIM_WDTCR_SOFT
\*----------------------------------------------------------------------------*/
#define _WDTIM_WDTCR_SOFT_SHIFT       (0x000bu)
#define _WDTIM_WDTCR_SOFT_MK(n)       (((Uint16)(n) & 0x0001u)<< _WDTIM_WDTCR_SOFT_SHIFT)
#define _WDTIM_WDTCR_SOFT_MASK        (_WDTIM_WDTCR_SOFT_MK(1))
#define _WDTIM_WDTCR_SOFT_CLR         (~(_WDTIM_WDTCR_SOFT_MASK))

/*----------------------------------------------------------------------------*\
* (RW) WDTIM_WDTCR_FREE
\*----------------------------------------------------------------------------*/
#define _WDTIM_WDTCR_FREE_SHIFT       (0x000au)
#define _WDTIM_WDTCR_FREE_MK(n)       (((Uint16)(n) &0x0001u) << _WDTIM_WDTCR_FREE_SHIFT)
#define _WDTIM_WDTCR_FREE_MASK        (_WDTIM_WDTCR_FREE_MK(1))
#define _WDTIM_WDTCR_FREE_CLR         (~(_WDTIM_WDTCR_FREE_MASK))

/*----------------------------------------------------------------------------*\
* (R) WDTIM_WDTCR_PSC
\*----------------------------------------------------------------------------*/
#define _WDTIM_WDTCR_PSC_SHIFT        (0x0006u)
#define _WDTIM_WDTCR_PSC_MK(n)     	(((Uint16)(n) & 0x000fu) << 6)
#define _WDTIM_WDTCR_PSC_MASK     	(_WDTIM_WDTCR_PSC_MK(0x000fu))
#define _WDTIM_WDTCR_PSC_CLR     	(~_WDTIM_WDTCR_PSC_MK(0x000fu))

/*----------------------------------------------------------------------------*\
* (RW) WDTIM_WDTCR_TDDR
\*----------------------------------------------------------------------------*/
#define _WDTIM_WDTCR_TDDR_SHIFT       (0x0000u)
#define _WDTIM_WDTCR_TDDR_MK(n)       (((Uint16)(n) & 0x000fu)<< _WDTIM_WDTCR_TDDR_SHIFT)
#define _WDTIM_WDTCR_TDDR_MASK	  (_WDTIM_WDTCR_TDDR_MK(0x000fu))
#define _WDTIM_WDTCR_TDDR_CLR	 	  (~(_WDTIM_WDTCR_TDDR_MASK))

/*----------------------------------------------------------------------------*\
* Register Macros:
\*----------------------------------------------------------------------------*/

#define _WDTIM_WDTCR_SET(Val)         _PREG_SET(_WDTIM_WDTCR_ADDR,Val)
#define _WDTIM_WDTCR_GET              _PREG_GET(_WDTIM_WDTCR_ADDR)
#define _WDTIM_WDTCR_AOI(AND,OR,INV)  _PREG_AOI(_WDTIM_WDTCR_ADDR,AND,OR,INV)
#define _WDTIM_WDTCR_FGET(Field)      _PFIELD_GET(_WDTIM_WDTCR_ADDR,_WDTIM_WDTCR_##Field)
#define _WDTIM_WDTCR_FSET(Field,Val)  _PFIELD_SET(_WDTIM_WDTCR_ADDR,_WDTIM_WDTCR_##Field,Val)
#define _WDTIM_WDTCR_FSETS(Field,Sym) _WDTIM_WDTCR_FSETS(##Field,WDTIM_WDTCR_##Field##_##Sym)
#define _WDTIM_WDTCR_FAOI(Field,AND,OR,INV)\
   _PFIELD_FAOI(_WDTIM_WDTCR_ADDR,_WDTIM_WDTCR_##Field,AND,OR,INV)

/******************************************************************************\
* _WDTIM_WDTCR2 - Watch Dog Timer Secondary Control Register
*
* Fields:
*   (RW) WDTCR2_WDFLAG
*   (RW) WDTCR2_WDEN
*   (RW) WDTCR2_PREMD
*   (RW) WDTCR2_WDKEY
*
\******************************************************************************/


#define _WDTIM_WDTCR2_ADDR            (0x4003u)
#define _WDTIM_WDTCR2                 PREG16(_WDTIM_WDTCR2_ADDR)
#define _WDTCR2                        _WDTIM_WDTCR2


/*----------------------------------------------------------------------------*\
* (RW) HWDTCR2_WDFLAG - Watch Dog Timeout flag
\*----------------------------------------------------------------------------*/
#define _WDTIM_WDTCR2_WDFLAG_SHIFT      (0x000fu)
#define _WDTIM_WDTCR2_WDFLAG_MK(n)      (((Uint16)(n) & 0x0001u)<< _WDTIM_WDTCR2_WDFLAG_SHIFT)
#define _WDTIM_WDTCR2_WDFLAG_MASK       (_WDTIM_WDTCR2_WDFLAG_MK(0x0001u))
#define _WDTIM_WDTCR2_WDFLAG_CLR        (~(_WDTIM_WDTCR2_WDFLAG_MASK))

/*----------------------------------------------------------------------------*\
* (RW) HWDTCR2_WDEN - Watch Dog Timer Enable Bit
\*----------------------------------------------------------------------------*/
#define _WDTIM_WDTCR2_WDEN_SHIFT       (0x000eu)
#define _WDTIM_WDTCR2_WDEN_MK(n)       (((Uint16)(n) & 0x0001u)<< _WDTIM_WDTCR2_WDEN_SHIFT)
#define _WDTIM_WDTCR2_WDEN_MASK        (_WDTIM_WDTCR2_WDEN_MK(0x0001u))
#define _WDTIM_WDTCR2_WDEN_CLR         (~(_WDTIM_WDTCR2_WDEN_MASK))

/*----------------------------------------------------------------------------*\
* (RW) HWDTCR2_PREMD - Watch Dog Timer Pre-scaler Mode Bit
\*----------------------------------------------------------------------------*/
#define _WDTIM_WDTCR2_PREMD_SHIFT      (0x000cu)
#define _WDTIM_WDTCR2_PREMD_MK(n)      (((Uint16)(n) & 0x0001u)<< _WDTIM_WDTCR2_PREMD_SHIFT)
#define _WDTIM_WDTCR2_PREMD_MASK       (_WDTIM_WDTCR2_PREMD_MK(0x0001u))
#define _WDTIM_WDTCR2_PREMD_CLR        (~(_WDTIM_WDTCR2_PREMD_MASK))

/*----------------------------------------------------------------------------*\
* (RW) HWDTCR2_WDKEY - Watch Dog Timer Pre-scaler Mode Bit
\*----------------------------------------------------------------------------*/
#define _WDTIM_WDTCR2_WDKEY_SHIFT      (0x0000u)
#define _WDTIM_WDTCR2_WDKEY_MK(n)      (((Uint16)(n) & 0xFFFu)<< _WDTIM_WDTCR2_WDKEY_SHIFT)
#define _WDTIM_WDTCR2_WDKEY_MASK       (_WDTIM_WDTCR2_WDKEY_MK(0xFFFu))
#define _WDTIM_WDTCR2_WDKEY_CLR        (~(_WDTIM_WDTCR2_WDKEY_MASK))

/*----------------------------------------------------------------------------*\
* Register Macros:
\*----------------------------------------------------------------------------*/

#define _WDTIM_WDTCR2_GET              _PREG_GET(_WDTIM_WDTCR2_ADDR)
#define _WDTIM_WDTCR2_SET(Val)         _PREG_SET(_WDTIM_WDTCR2_ADDR,Val)
#define _WDTIM_WDTCR2_AOI(AND,OR,INV)  _PREG_AOI(_WDTIM_WDTCR2_ADDR,AND,OR,INV)
#define _WDTIM_WDTCR2_FGET(Field)      _PFIELD_GET(_WDTIM_WDTCR2_ADDR,_WDTIM_WDTCR2_##Field)
#define _WDTIM_WDTCR2_FSET(Field,Val)  _PFIELD_SET(_WDTIM_WDTCR2_ADDR,_WDTIM_WDTCR2_##Field,Val)
#define _WDTIM_WDTCR2_FSETS(Field,Sym) _WDTIM_WDTCR2_FSETS(##Field,WDTIM_WDTCR2_##Field##_##Sym)
#define _WDTIM_WDTCR2_FAOI(Field,AND,OR,INV)\
   _PFIELD_FAOI(_WDTIM_WDTCR2_ADDR,_WDTIM_WDTCR2_##Field,AND,OR,INV)


#else
  #ifndef _WDTIM_MOD_ /* _WDTIMHAL_H_ */
     #error WatchDog Timer HAL Module Not Supported on Specified Target
  #endif
#endif  
#endif /* _CSL_WDTIMHAL_H_ */
/******************************************************************************\
* End of csl_wdtimhal.h
\******************************************************************************/
