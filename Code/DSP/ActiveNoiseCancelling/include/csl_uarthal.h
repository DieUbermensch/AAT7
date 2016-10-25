/****************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved 
*------------------------------------------------------------------------------
* MODULE NAME... UART
* FILENAME...... csl_UARThal.h
* DATE CREATED.. Tue Jan 15 10:10:25 2002
* PROJECT....... Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS.. 
*------------------------------------------------------------------------------
*
* HISTORY:
*	 Created:		Tue Jan 15 10:10:25 2002 (Automatic generation)
*	 Last Modified:	
*
*------------------------------------------------------------------------------
* DESCRIPTION: CSL HAL interface file for the UART module 
*
* Registers covered:
*
*	 URRBR		- Receive Buffer Register
*	 URTHR		- Transmit Holding Register
*	 URIER		- Interrupt Enable Register
*	 URIIR		- Interrupt Identification Register
*	 URFCR		- FIFO Control Register
*	 URLCR		- Line Control Register
*	 URMCR		- Modem Control Register
*	 URLSR		- Line Status Register
*	 URMSR		- Modem Status Register
*	 URSCR		- Scratch Register
*	 URDLL		- Divisor Latch LSB Register
*	 URDLM		- Divisor Latch MSB Register
*	 URPIDL		- PID LSW
*	 URPIDH		- PID MSW
*	 URPECR		- Power and Emulation Control Register
*
\*************************************************************************/

#ifndef _CSL_UARTHAL_H_
#define _CSL_UARTHAL_H_

#include <csl_chiphal.h>

#if (_UART_SUPPORT) 

/*----------------------------------------------------------------*\
*	 UART scope and inline control macros 			
\*----------------------------------------------------------------*/

#ifdef __cplusplus
#define CSLAPI extern "C"
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _UART_MOD_
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


#define UART_HIGHBYTE_MASK         (0x00FFu)
#define UART_HIGHBYTE_SHIFT        (0x0008u)

/*----------------------------------------------------------------*\
*		 Address Macros			
\*----------------------------------------------------------------*/

/*--------------------- Register: URRBR -----------------------*/
#define _UART_URRBR_ADDR        (0x9c00u)
#define _UART_URRBR             PREG16(_UART_URRBR_ADDR)
#define URRBR                   _UART_URRBR


/*--------------------- Register: URTHR -----------------------*/
#define _UART_URTHR_ADDR        (0x9c00u)
#define _UART_URTHR             PREG16(_UART_URTHR_ADDR)
#define URTHR                   _UART_URTHR


/*--------------------- Register: URIER -----------------------*/
#define _UART_URIER_ADDR        (0x9c01u)
#define _UART_URIER	            PREG16(_UART_URIER_ADDR)
#define URIER                   _UART_URIER


/*--------------------- Register: URIIR -----------------------*/
#define _UART_URIIR_ADDR        (0x9c02u)
#define _UART_URIIR	            PREG16(_UART_URIIR_ADDR)
#define URIIR                   _UART_URIIR


/*--------------------- Register: URFCR -----------------------*/
#define _UART_URFCR_ADDR        (0x9c02u)
#define _UART_URFCR	            PREG16(_UART_URFCR_ADDR)
#define URFCR                   _UART_URFCR


/*--------------------- Register: URLCR -----------------------*/
#define _UART_URLCR_ADDR        (0x9c03u)
#define _UART_URLCR             PREG16(_UART_URLCR_ADDR)
#define URLCR                   _UART_URLCR


/*--------------------- Register: URMCR -----------------------*/
#define _UART_URMCR_ADDR        (0x9c04u)
#define _UART_URMCR             PREG16(_UART_URMCR_ADDR)
#define URMCR                   _UART_URMCR


/*--------------------- Register: URLSR -----------------------*/
#define _UART_URLSR_ADDR        (0x9c05u)
#define _UART_URLSR             PREG16(_UART_URLSR_ADDR)
#define URLSR                   _UART_URLSR


/*--------------------- Register: URMSR -----------------------*/
#define _UART_URMSR_ADDR        (0x9c06u)
#define _UART_URMSR	            PREG16(_UART_URMSR_ADDR)
#define URMSR                   _UART_URMSR


/*--------------------- Register: URSCR -----------------------*/
#define _UART_URSCR_ADDR        (0x9c07u)
#define _UART_URSCR             PREG16(_UART_URSCR_ADDR)
#define URSCR                   _UART_URSCR


/*--------------------- Register: URDLL -----------------------*/
//#define _UART_URDLL_ADDR		(0x9c08u)
#define _UART_URDLL_ADDR        (0x9c00u)
#define _UART_URDLL	            PREG16(_UART_URDLL_ADDR)
#define URDLL                   _UART_URDLL


/*--------------------- Register: URDLM -----------------------*/
//#define _UART_URDLM_ADDR		(0x9c09u)
#define _UART_URDLM_ADDR        (0x9c01u)
#define _UART_URDLM             PREG16(_UART_URDLM_ADDR)
#define URDLM                   _UART_URDLM


/*--------------------- Register: URPIDL -----------------------*/
#define _UART_URPIDL_ADDR       (0x9c0au)
#define _UART_URPIDL            PREG16(_UART_URPIDL_ADDR)
#define URPIDL                  _UART_URPIDL


/*--------------------- Register: URPIDH -----------------------*/
#define _UART_URPIDH_ADDR       (0x9c0bu)
#define _UART_URPIDH            PREG16(_UART_URPIDH_ADDR)
#define URPIDH                  _UART_URPIDH


/*--------------------- Register: URPECR -----------------------*/
#define _UART_URPECR_ADDR       (0x9c0cu)
#define _UART_URPECR            PREG16(_UART_URPECR_ADDR)
#define URPECR                  _UART_URPECR



/*----------------------------------------------------------------*\
*		 Register Macros		
\*----------------------------------------------------------------*/

#define UART_ADDR(Reg)                    _UART_##Reg##_ADDR
#define UART_RGET(Reg)                    _UART_##Reg##_GET
#define UART_RSET(Reg,Val)                _UART_##Reg##_SET(Val)
#define UART_FGET(Reg,Field)              _UART_##Reg##_FGET(Field)
#define UART_FSET(Reg,Field,Val)          _UART_##Reg##_FSET(Field, Val)
#define UART_FMK(Reg,Field,Val)           _UART_##Reg##_##Field##_MK(Val)
#define UART_RAOI(Reg,AND,OR,INV)		  _UART_##Reg##_AOI(AND,OR,INV)
#define UART_FAOI(Reg,Field,AND,OR,INV)	  _UART_##Reg##_FAOI(Field,AND,OR,INV)
#define UART_FMKS(Reg,Field,Sym)\
         _UART_##Reg##_##Field##_MK(UART_##Reg##_##Field##_##Sym)
#define UART_FSETS(Reg,Field,Sym)\
         _UART_##Reg##_FSET(Field,UART_##Reg##_##Field##_##Sym)


/*----------------------------------------------------------------*\
*		 UART HPIGPIO mapped Register Macros		
\*----------------------------------------------------------------*/
#define UART_HPIRGET(Reg)                _UART_##Reg##_GET
#define UART_HPIRSET(Reg,Val)            _UART_##Reg##_SET(Val)
#define UART_HPIFGET(Reg,Field)          _UART_##Reg##_FGET(Field)
#define UART_HPIFSET(Reg,Field,Val)      _UART_##Reg##_FSET(Field,Val)


/*----------------------------------------------------------------*\
*		 Non-handle Registers Macros		
\*----------------------------------------------------------------*/


/*--------------------- Register: URRBR -----------------------*/
#define _UART_URRBR_GET               _PREG_GET(_UART_URRBR_ADDR) 
#define _UART_URRBR_SET(Val)          _PREG_SET(_UART_URRBR_ADDR,Val)
#define _UART_URRBR_FGET(Field)       _PFIELD_GET(_UART_URRBR_ADDR, _UART_URRBR_##Field)
#define _UART_URRBR_FSET(Field,Val)	  _PFIELD_SET(_UART_URRBR_ADDR, _UART_URRBR_##Field, Val)
#define _UART_URRBR_AOI(AND,OR,INV)	  _PREG_AOI(_UART_URRBR_ADDR,AND,OR,INV)
#define _UART_URRBR_FAOI(Field,AND,OR,INV)\
         _PFIELD_AOI(_UART_URRBR_ADDR, _UART_URRBR_##Field,AND,OR,INV)


/*--------------------- Register: URTHR -----------------------*/
#define _UART_URTHR_GET               _PREG_GET(_UART_URTHR_ADDR) 
#define _UART_URTHR_SET(Val)		  _PREG_SET(_UART_URTHR_ADDR,Val)
#define _UART_URTHR_FGET(Field)       _PFIELD_GET(_UART_URTHR_ADDR, _UART_URTHR_##Field)
#define _UART_URTHR_FSET(Field,Val)	  _PFIELD_SET(_UART_URTHR_ADDR, _UART_URTHR_##Field, Val)
#define _UART_URTHR_AOI(AND,OR,INV)	  _PREG_AOI(_UART_URTHR_ADDR,AND,OR,INV)
#define _UART_URTHR_FAOI(Field,AND,OR,INV)\
         _PFIELD_AOI(_UART_URTHR_ADDR, _UART_URTHR_##Field,AND,OR,INV)


/*--------------------- Register: URIER -----------------------*/
#define _UART_URIER_GET               _PREG_GET(_UART_URIER_ADDR) 
#define _UART_URIER_SET(Val)          _PREG_SET(_UART_URIER_ADDR,Val)
#define _UART_URIER_FGET(Field)       _PFIELD_GET(_UART_URIER_ADDR, _UART_URIER_##Field)
#define _UART_URIER_FSET(Field,Val)	  _PFIELD_SET(_UART_URIER_ADDR, _UART_URIER_##Field, Val)
#define _UART_URIER_AOI(AND,OR,INV)	  _PREG_AOI(_UART_URIER_ADDR,AND,OR,INV)
#define _UART_URIER_FAOI(Field,AND,OR,INV)\
         _PFIELD_AOI(_UART_URIER_ADDR, _UART_URIER_##Field,AND,OR,INV)


/*--------------------- Register: URIIR -----------------------*/
#define _UART_URIIR_GET               _PREG_GET(_UART_URIIR_ADDR) 
#define _UART_URIIR_FGET(Field)       _PFIELD_GET(_UART_URIIR_ADDR, _UART_URIIR_##Field)
//
// URIIR is a read only register so setting and mainipulation of this reg or the individual fields
// by these macros is not practical
//
//#define _UART_URIIR_SET(Val)          _PREG_SET(_UART_URIIR_ADDR,Val)
//#define _UART_URIIR_FSET(Field,Val)	  _PFIELD_SET(_UART_URIIR_ADDR, _UART_URIIR_##Field, Val)
//#define _UART_URIIR_AOI(AND,OR,INV)	  _PREG_AOI(_UART_URIIR_ADDR,AND,OR,INV)
//#define _UART_URIIR_FAOI(Field,AND,OR,INV)\
//         _PFIELD_AOI(_UART_URIIR_ADDR, _UART_URIIR_##Field,AND,OR,INV)


/*--------------------- Register: URFCR -----------------------*/
#define _UART_URFCR_SET(Val)          _PREG_SET(_UART_URFCR_ADDR,Val)
//
// URFCR is a write only register so setting and mainipulation of individual fields
// by these macros is not practical
//
//#define _UART_URFCR_GET               _PREG_GET(_UART_URFCR_ADDR) 
//#define _UART_URFCR_FGET(Field)       _PFIELD_GET(_UART_URFCR_ADDR, _UART_URFCR_##Field)
//#define _UART_URFCR_FSET(Field,Val)	  _PFIELD_SET(_UART_URFCR_ADDR, _UART_URFCR_##Field, Val)
//#define _UART_URFCR_AOI(AND,OR,INV)	  _PREG_AOI(_UART_URFCR_ADDR,AND,OR,INV)
//#define _UART_URFCR_FAOI(Field,AND,OR,INV)\
//         _PFIELD_AOI(_UART_URFCR_ADDR, _UART_URFCR_##Field,AND,OR,INV)


/*--------------------- Register: URLCR -----------------------*/
#define _UART_URLCR_GET               _PREG_GET(_UART_URLCR_ADDR) 
#define _UART_URLCR_SET(Val)          _PREG_SET(_UART_URLCR_ADDR,Val)
#define _UART_URLCR_FGET(Field)       _PFIELD_GET(_UART_URLCR_ADDR, _UART_URLCR_##Field)
#define _UART_URLCR_FSET(Field,Val)   _PFIELD_SET(_UART_URLCR_ADDR, _UART_URLCR_##Field, Val)
#define _UART_URLCR_AOI(AND,OR,INV)	  _PREG_AOI(_UART_URLCR_ADDR,AND,OR,INV)
#define _UART_URLCR_FAOI(Field,AND,OR,INV)\
         _PFIELD_AOI(_UART_URLCR_ADDR, _UART_URLCR_##Field,AND,OR,INV)


/*--------------------- Register: URMCR -----------------------*/
#define _UART_URMCR_GET               _PREG_GET(_UART_URMCR_ADDR) 
#define _UART_URMCR_SET(Val)          _PREG_SET(_UART_URMCR_ADDR,Val)
#define _UART_URMCR_FGET(Field)       _PFIELD_GET(_UART_URMCR_ADDR, _UART_URMCR_##Field)
#define _UART_URMCR_FSET(Field,Val)   _PFIELD_SET(_UART_URMCR_ADDR, _UART_URMCR_##Field, Val)
#define _UART_URMCR_AOI(AND,OR,INV)	  _PREG_AOI(_UART_URMCR_ADDR,AND,OR,INV)
#define _UART_URMCR_FAOI(Field,AND,OR,INV)\
         _PFIELD_AOI(_UART_URMCR_ADDR, _UART_URMCR_##Field,AND,OR,INV)


/*--------------------- Register: URLSR -----------------------*/
#define _UART_URLSR_GET               _PREG_GET(_UART_URLSR_ADDR) 
#define _UART_URLSR_SET(Val)          _PREG_SET(_UART_URLSR_ADDR,Val)
#define _UART_URLSR_FGET(Field)       _PFIELD_GET(_UART_URLSR_ADDR, _UART_URLSR_##Field)
#define _UART_URLSR_FSET(Field,Val)	  _PFIELD_SET(_UART_URLSR_ADDR, _UART_URLSR_##Field, Val)
#define _UART_URLSR_AOI(AND,OR,INV)	  _PREG_AOI(_UART_URLSR_ADDR,AND,OR,INV)
#define _UART_URLSR_FAOI(Field,AND,OR,INV)\
         _PFIELD_AOI(_UART_URLSR_ADDR, _UART_URLSR_##Field,AND,OR,INV)



/*--------------------- Register: URSCR -----------------------*/
#define _UART_URSCR_GET               _PREG_GET(_UART_URSCR_ADDR) 
#define _UART_URSCR_SET(Val)          _PREG_SET(_UART_URSCR_ADDR,Val)
#define _UART_URSCR_FGET(Field)       _PFIELD_GET(_UART_URSCR_ADDR, _UART_URSCR_##Field)
#define _UART_URSCR_FSET(Field,Val)	  _PFIELD_SET(_UART_URSCR_ADDR, _UART_URSCR_##Field, Val)
#define _UART_URSCR_AOI(AND,OR,INV)	  _PREG_AOI(_UART_URSCR_ADDR,AND,OR,INV)
#define _UART_URSCR_FAOI(Field,AND,OR,INV)\
         _PFIELD_AOI(_UART_URSCR_ADDR, _UART_URSCR_##Field,AND,OR,INV)


/*--------------------- Register: URDLL -----------------------*/
#define _UART_URDLL_GET               _PREG_GET(_UART_URDLL_ADDR) 
#define _UART_URDLL_SET(Val)          _PREG_SET(_UART_URDLL_ADDR,Val)
#define _UART_URDLL_FGET(Field)       _PFIELD_GET(_UART_URDLL_ADDR, _UART_URDLL_##Field)
#define _UART_URDLL_FSET(Field,Val)	  _PFIELD_SET(_UART_URDLL_ADDR, _UART_URDLL_##Field, Val)
#define _UART_URDLL_AOI(AND,OR,INV)	  _PREG_AOI(_UART_URDLL_ADDR,AND,OR,INV)
#define _UART_URDLL_FAOI(Field,AND,OR,INV)\
         _PFIELD_AOI(_UART_URDLL_ADDR, _UART_URDLL_##Field,AND,OR,INV)


/*--------------------- Register: URDLM -----------------------*/
#define _UART_URDLM_GET               _PREG_GET(_UART_URDLM_ADDR) 
#define _UART_URDLM_SET(Val)          _PREG_SET(_UART_URDLM_ADDR,Val)
#define _UART_URDLM_FGET(Field)       _PFIELD_GET(_UART_URDLM_ADDR, _UART_URDLM_##Field)
#define _UART_URDLM_FSET(Field,Val)	  _PFIELD_SET(_UART_URDLM_ADDR, _UART_URDLM_##Field, Val)
#define _UART_URDLM_AOI(AND,OR,INV)	  _PREG_AOI(_UART_URDLM_ADDR,AND,OR,INV)
#define _UART_URDLM_FAOI(Field,AND,OR,INV)\
         _PFIELD_AOI(_UART_URDLM_ADDR, _UART_URDLM_##Field,AND,OR,INV)


/*--------------------- Register: URPECR -----------------------*/
#define _UART_URPECR_GET              _PREG_GET(_UART_URPECR_ADDR) 
#define _UART_URPECR_SET(Val)         _PREG_SET(_UART_URPECR_ADDR,Val)
#define _UART_URPECR_FGET(Field)      _PFIELD_GET(_UART_URPECR_ADDR, _UART_URPECR_##Field)
#define _UART_URPECR_FSET(Field,Val)  _PFIELD_SET(_UART_URPECR_ADDR, _UART_URPECR_##Field, Val)
#define _UART_URPECR_AOI(AND,OR,INV)  _PREG_AOI(_UART_URPECR_ADDR,AND,OR,INV)
#define _UART_URPECR_FAOI(Field,AND,OR,INV)\
         _PFIELD_AOI(_UART_URPECR_ADDR, _UART_URPECR_##Field,AND,OR,INV)



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the URLSR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
*
* Fields:
*	(R)   _UART_URLSR_DR	
*	(R)   _UART_URLSR_OE	
*	(R)   _UART_URLSR_PE	
*	(R)   _UART_URLSR_FE	
*	(R)   _UART_URLSR_BI	
*	(R)   _UART_URLSR_THRE	
*	(R)   _UART_URLSR_TEMT	
*	(R)   _UART_URLSR_RFIER	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _UART_URLSR_DR:	
\*----------------------------------------------------------------*/

#define _UART_URLSR_DR_SHIFT		(000000u)
#define _UART_URLSR_DR_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URLSR_DR_SHIFT)
#define _UART_URLSR_DR_MASK		(_UART_URLSR_DR_MK(0x0001u))
#define _UART_URLSR_DR_CLR		(~(_UART_URLSR_DR_MASK))



/*----------------------------------------------------------------*\
*   (R)  _UART_URLSR_OE:	
\*----------------------------------------------------------------*/

#define _UART_URLSR_OE_SHIFT		(0x0001u)
#define _UART_URLSR_OE_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URLSR_OE_SHIFT)
#define _UART_URLSR_OE_MASK		(_UART_URLSR_OE_MK(0x0001u))
#define _UART_URLSR_OE_CLR		(~(_UART_URLSR_OE_MASK))



/*----------------------------------------------------------------*\
*   (R)  _UART_URLSR_PE:	
\*----------------------------------------------------------------*/

#define _UART_URLSR_PE_SHIFT		(0x0002u)
#define _UART_URLSR_PE_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URLSR_PE_SHIFT)
#define _UART_URLSR_PE_MASK		(_UART_URLSR_PE_MK(0x0001u))
#define _UART_URLSR_PE_CLR		(~(_UART_URLSR_PE_MASK))



/*----------------------------------------------------------------*\
*   (R)  _UART_URLSR_FE:	
\*----------------------------------------------------------------*/

#define _UART_URLSR_FE_SHIFT		(0x0003u)
#define _UART_URLSR_FE_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URLSR_FE_SHIFT)
#define _UART_URLSR_FE_MASK		(_UART_URLSR_FE_MK(0x0001u))
#define _UART_URLSR_FE_CLR		(~(_UART_URLSR_FE_MASK))



/*----------------------------------------------------------------*\
*   (R)  _UART_URLSR_BI:	
\*----------------------------------------------------------------*/

#define _UART_URLSR_BI_SHIFT		(0x0004u)
#define _UART_URLSR_BI_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URLSR_BI_SHIFT)
#define _UART_URLSR_BI_MASK		(_UART_URLSR_BI_MK(0x0001u))
#define _UART_URLSR_BI_CLR		(~(_UART_URLSR_BI_MASK))



/*----------------------------------------------------------------*\
*   (R)  _UART_URLSR_THRE:	
\*----------------------------------------------------------------*/

#define _UART_URLSR_THRE_SHIFT		(0x0005u)
#define _UART_URLSR_THRE_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URLSR_THRE_SHIFT)
#define _UART_URLSR_THRE_MASK		(_UART_URLSR_THRE_MK(0x0001u))
#define _UART_URLSR_THRE_CLR		(~(_UART_URLSR_THRE_MASK))



/*----------------------------------------------------------------*\
*   (R)  _UART_URLSR_TEMT:	
\*----------------------------------------------------------------*/

#define _UART_URLSR_TEMT_SHIFT		(0x0006u)
#define _UART_URLSR_TEMT_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URLSR_TEMT_SHIFT)
#define _UART_URLSR_TEMT_MASK		(_UART_URLSR_TEMT_MK(0x0001u))
#define _UART_URLSR_TEMT_CLR		(~(_UART_URLSR_TEMT_MASK))



/*----------------------------------------------------------------*\
*   (R)  _UART_URLSR_RFIER:	
\*----------------------------------------------------------------*/

#define _UART_URLSR_RFIER_SHIFT		(0x0007u)
#define _UART_URLSR_RFIER_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URLSR_RFIER_SHIFT)
#define _UART_URLSR_RFIER_MASK		(_UART_URLSR_RFIER_MK(0x0001u))
#define _UART_URLSR_RFIER_CLR		(~(_UART_URLSR_RFIER_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the URLCR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _UART_URLCR	 - Note: Add description here
*
* Fields:
*	(RW)   _UART_URLCR_WLS	
*	(RW)   _UART_URLCR_STB	
*	(RW)   _UART_URLCR_PEN	
*	(RW)   _UART_URLCR_EPS	
*	(RW)   _UART_URLCR_STPAR	
*	(RW)   _UART_URLCR_DLAB	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _UART_URLCR_WLS:	
\*----------------------------------------------------------------*/

#define _UART_URLCR_WLS_SHIFT		(000000u)
#define _UART_URLCR_WLS_MK(n)		(((Uint16)(n) & 0x0003u) << _UART_URLCR_WLS_SHIFT)
#define _UART_URLCR_WLS_MASK		(_UART_URLCR_WLS_MK(0x0003u))
#define _UART_URLCR_WLS_CLR		(~(_UART_URLCR_WLS_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _UART_URLCR_STB:	
\*----------------------------------------------------------------*/

#define _UART_URLCR_STB_SHIFT		(0x0002u)
#define _UART_URLCR_STB_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URLCR_STB_SHIFT)
#define _UART_URLCR_STB_MASK		(_UART_URLCR_STB_MK(0x0001u))
#define _UART_URLCR_STB_CLR		(~(_UART_URLCR_STB_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _UART_URLCR_PEN:	
\*----------------------------------------------------------------*/

#define _UART_URLCR_PEN_SHIFT		(0x0003u)
#define _UART_URLCR_PEN_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URLCR_PEN_SHIFT)
#define _UART_URLCR_PEN_MASK		(_UART_URLCR_PEN_MK(0x0001u))
#define _UART_URLCR_PEN_CLR		(~(_UART_URLCR_PEN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _UART_URLCR_EPS:	
\*----------------------------------------------------------------*/

#define _UART_URLCR_EPS_SHIFT		(0x0004u)
#define _UART_URLCR_EPS_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URLCR_EPS_SHIFT)
#define _UART_URLCR_EPS_MASK		(_UART_URLCR_EPS_MK(0x0001u))
#define _UART_URLCR_EPS_CLR		(~(_UART_URLCR_EPS_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _UART_URLCR_STPAR:	
\*----------------------------------------------------------------*/

#define _UART_URLCR_STPAR_SHIFT		(0x0005u)
#define _UART_URLCR_STPAR_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URLCR_STPAR_SHIFT)
#define _UART_URLCR_STPAR_MASK		(_UART_URLCR_STPAR_MK(0x0001u))
#define _UART_URLCR_STPAR_CLR		(~(_UART_URLCR_STPAR_MASK))


/*----------------------------------------------------------------*\
*   (RW)  _UART_URLCR_BC:	
\*----------------------------------------------------------------*/

#define _UART_URLCR_BC_SHIFT		(0x0006u)
#define _UART_URLCR_BC_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URLCR_BC_SHIFT)
#define _UART_URLCR_BC_MASK		    (_UART_URLCR_BC_MK(0x0001u))
#define _UART_URLCR_BC_CLR		    (~(_UART_URLCR_BC_MASK))


/*----------------------------------------------------------------*\
*   (RW)  _UART_URLCR_DLAB:	
\*----------------------------------------------------------------*/

#define _UART_URLCR_DLAB_SHIFT		(0x0007u)
#define _UART_URLCR_DLAB_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URLCR_DLAB_SHIFT)
#define _UART_URLCR_DLAB_MASK		(_UART_URLCR_DLAB_MK(0x0001u))
#define _UART_URLCR_DLAB_CLR		(~(_UART_URLCR_DLAB_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the URMCR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _UART_URMCR	 - Note: Add description here
*
* Fields:
*	(RW)   _UART_URMCR_LOOP	
*
\******************************************************************************/

/*----------------------------------------------------------------*\
*   (RW)  _UART_URMCR_LOOP:	
\*----------------------------------------------------------------*/

#define _UART_URMCR_LOOP_SHIFT		(0x0004u)
#define _UART_URMCR_LOOP_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URMCR_LOOP_SHIFT)
#define _UART_URMCR_LOOP_MASK		(_UART_URMCR_LOOP_MK(0x0001u))
#define _UART_URMCR_LOOP_CLR		(~(_UART_URMCR_LOOP_MASK))

/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the URIIR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _UART_URIIR	 - Note: Add description here
*
* Fields:
*	(R)   _UART_URIIR_IP	
*	(R)   _UART_URIIR_IID	
*	(R)   _UART_URIIR_FIENR	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _UART_URIIR_IP:	
\*----------------------------------------------------------------*/

#define _UART_URIIR_IP_SHIFT		(000000u)
#define _UART_URIIR_IP_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URIIR_IP_SHIFT)
#define _UART_URIIR_IP_MASK		(_UART_URIIR_IP_MK(0x0001u))
#define _UART_URIIR_IP_CLR		(~(_UART_URIIR_IP_MASK))



/*----------------------------------------------------------------*\
*   (R)  _UART_URIIR_IID:	
\*----------------------------------------------------------------*/

#define _UART_URIIR_IID_SHIFT		(0x0001u)
#define _UART_URIIR_IID_MK(n)		(((Uint16)(n) & 0x0007u) << _UART_URIIR_IID_SHIFT)
#define _UART_URIIR_IID_MASK		(_UART_URIIR_IID_MK(0x0001u))
#define _UART_URIIR_IID_CLR		(~(_UART_URIIR_IID_MASK))



/*----------------------------------------------------------------*\
*   (R)  _UART_URIIR_FIENR:	
\*----------------------------------------------------------------*/

#define _UART_URIIR_FIENR_SHIFT		(0x0006u)
#define _UART_URIIR_FIENR_MK(n)		(((Uint16)(n) & 0x0003u) << _UART_URIIR_FIENR_SHIFT)
#define _UART_URIIR_FIENR_MASK		(_UART_URIIR_FIENR_MK(0x0003u))
#define _UART_URIIR_FIENR_CLR		(~(_UART_URIIR_FIENR_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the URIER register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _UART_URIER	 - Note: Add description here
*
* Fields:
*	(RW)   _UART_URIER_ERBI	
*	(RW)   _UART_URIER_ETBEI	
*	(RW)   _UART_URIER_ELSI	
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _UART_URIER_ERBI:	
\*----------------------------------------------------------------*/

#define _UART_URIER_ERBI_SHIFT		(000000u)
#define _UART_URIER_ERBI_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URIER_ERBI_SHIFT)
#define _UART_URIER_ERBI_MASK		(_UART_URIER_ERBI_MK(0x0001u))
#define _UART_URIER_ERBI_CLR		(~(_UART_URIER_ERBI_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _UART_URIER_ETBEI:	
\*----------------------------------------------------------------*/

#define _UART_URIER_ETBEI_SHIFT		(0x0001u)
#define _UART_URIER_ETBEI_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URIER_ETBEI_SHIFT)
#define _UART_URIER_ETBEI_MASK		(_UART_URIER_ETBEI_MK(0x0001u))
#define _UART_URIER_ETBEI_CLR		(~(_UART_URIER_ETBEI_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _UART_URIER_ELSI:	
\*----------------------------------------------------------------*/

#define _UART_URIER_ELSI_SHIFT		(0x0002u)
#define _UART_URIER_ELSI_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URIER_ELSI_SHIFT)
#define _UART_URIER_ELSI_MASK		(_UART_URIER_ELSI_MK(0x0001u))
#define _UART_URIER_ELSI_CLR		(~(_UART_URIER_ELSI_MASK))


/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the URFCR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _UART_URFCR	 - Note: Add description here
*
* Fields:
*	(W)   _UART_URFCR_FIEN	
*	(W)   _UART_URFCR_RFIRS	
*	(W)   _UART_URFCR_TFIRS	
*	(W)   _UART_URFCR_DMAMD	
*	(W)   _UART_URFCR_RFITR	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (W)  _UART_URFCR_FIEN:	
\*----------------------------------------------------------------*/

#define _UART_URFCR_FIEN_SHIFT		(000000u)
#define _UART_URFCR_FIEN_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URFCR_FIEN_SHIFT)
#define _UART_URFCR_FIEN_MASK		(_UART_URFCR_FIEN_MK(0x0001u))
#define _UART_URFCR_FIEN_CLR		(~(_UART_URFCR_FIEN_MASK))



/*----------------------------------------------------------------*\
*   (W)  _UART_URFCR_RFIRS:	
\*----------------------------------------------------------------*/

#define _UART_URFCR_RFIRS_SHIFT		(0x0001u)
#define _UART_URFCR_RFIRS_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URFCR_RFIRS_SHIFT)
#define _UART_URFCR_RFIRS_MASK		(_UART_URFCR_RFIRS_MK(0x0001u))
#define _UART_URFCR_RFIRS_CLR		(~(_UART_URFCR_RFIRS_MASK))



/*----------------------------------------------------------------*\
*   (W)  _UART_URFCR_TFIRS:	
\*----------------------------------------------------------------*/

#define _UART_URFCR_TFIRS_SHIFT		(0x0002u)
#define _UART_URFCR_TFIRS_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URFCR_TFIRS_SHIFT)
#define _UART_URFCR_TFIRS_MASK		(_UART_URFCR_TFIRS_MK(0x0001u))
#define _UART_URFCR_TFIRS_CLR		(~(_UART_URFCR_TFIRS_MASK))



/*----------------------------------------------------------------*\
*   (W)  _UART_URFCR_DMAMD:	
\*----------------------------------------------------------------*/

#define _UART_URFCR_DMAMD_SHIFT		(0x0003u)
#define _UART_URFCR_DMAMD_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URFCR_DMAMD_SHIFT)
#define _UART_URFCR_DMAMD_MASK		(_UART_URFCR_DMAMD_MK(0x0001u))
#define _UART_URFCR_DMAMD_CLR		(~(_UART_URFCR_DMAMD_MASK))



/*----------------------------------------------------------------*\
*   (W)  _UART_URFCR_RFITR:	
\*----------------------------------------------------------------*/

#define _UART_URFCR_RFITR_SHIFT		(0x0006u)
#define _UART_URFCR_RFITR_MK(n)		(((Uint16)(n) & 0x0003u) << _UART_URFCR_RFITR_SHIFT)
#define _UART_URFCR_RFITR_MASK		(_UART_URFCR_RFITR_MK(0x0003u))
#define _UART_URFCR_RFITR_CLR		(~(_UART_URFCR_RFITR_MASK))


/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the URMCR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _UART_URPECR	 - Note: Add description here
*
* Fields:
*	(RW)   _UART_URPECR_URST	
*	(RW)   _UART_URPECR_SOFT	
*	(RW)   _UART_URPECR_FREE	
*
\******************************************************************************/

/*----------------------------------------------------------------*\
*   (RW)  _UART_URPECR_FREE:	
\*----------------------------------------------------------------*/
#define _UART_URPECR_FREE_SHIFT		(0x0000u)
#define _UART_URPECR_FREE_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URPECR_FREE_SHIFT)
#define _UART_URPECR_FREE_MASK		(_UART_URPECR_FREE_MK(0x0001u))
#define _UART_URPECR_FREE_CLR		(~(_UART_URPECR_FREE_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _UART_URPECR_URST:	
\*----------------------------------------------------------------*/
#define _UART_URPECR_URST_SHIFT		(0x000Fu)
#define _UART_URPECR_URST_MK(n)		(((Uint16)(n) & 0x0001u) << _UART_URPECR_URST_SHIFT)
#define _UART_URPECR_URST_MASK		(_UART_URPECR_URST_MK(0x0001u))
#define _UART_URPECR_URST_CLR		(~(_UART_URPECR_URST_MASK))




#elif (!(_UART_MOD))
	#error UART Hal Module Not Supported on Specified Target
#endif  /* _UART_SUPPORT  */

#endif  /* _CSL_UARTHAL_H  */

/******************************************************************************\
*     
*      End of csl_UARThal.h 
*
\******************************************************************************/
