/****************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved 
*------------------------------------------------------------------------------
* MODULE NAME... GPT 
* FILENAME...... csl_gpthal.h
* DATE CREATED.. Sat Feb  9 16:13:17 2002
* PROJECT....... Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS..  
*------------------------------------------------------------------------------
*
* HISTORY:
*	 Created:		Sat Feb  9 16:13:17 2002 (Automatic generation)
*	 Last Modified:	        03/11/2003 Modified register names and fields
*                               as per SPRU618A.   
*
*------------------------------------------------------------------------------
* DESCRIPTION: CSL HAL interface file for the GPT module 
*
* Registers covered:
*                  GPTPID1		- 
*	           GPTPID2		- 
*	           GPTEMU		- Emulation management register
*	           GPTCLK		- Timer clock speed register
*	           GPTCNT1		- Timer count register 1
*	           GPTCNT2		- Timer count register 2
*	           GPTCNT3		- Timer count register 3
*	           GPTCNT4		- Timer count register 4
*	           GPTPRD1		- Timer period register 1
*	           GPTPRD2		- Timer period register 2
*	           GPTPRD3		- Timer period register 3
*	           GPTPRD4		- Timer period register 4
*	           GPTGPINT		- GPIO interrupt control register
*	           GPTGPEN		- GPIO enable register
*	           GPTGPDIR		- GPIO direction register
*	           GPTGPDAT		- GPIO data register
*	           GPTCTL1		- Timer control register 1
*	           GPTCTL2		- Timer control register 2
*	           GPTGCTL1		- Global timer control register
*
\*************************************************************************/
  
#ifndef _CSL_GPTHAL_H_
#define _CSL_GPTHAL_H_

#include <csl_chiphal.h>

#if (_GPT_SUPPORT) 

/*----------------------------------------------------------------*\
*	 GPT scope and inline control macros 			
\*----------------------------------------------------------------*/

#ifdef __cplusplus
#define CSLAPI extern "C"
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _GPT_MOD_
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

// #define _GPT_BASE_ADDRn(n)		(_TIMERB_BASE_ADDR + (n * 0x1400u))

#define _GPT_BASE_ADDR		        (0x1000u)
//#define _GPT_BASE_ADDR			(0x0800u)

#define _GPT_BASE_ADDRn(n)		(_GPT_BASE_ADDR + (n * 0x1400u))

/*--------------------- Register: GPTPID1 -----------------------*/
#define _GPT_GPTPID10_ADDR		(_GPT_GPTPID1_ADDR(0))
#define _GPT_GPTPID10			PREG16(_GPT_GPTPID10_ADDR)
#define GPTPID10				_GPT_GPTPID10

#define _GPT_GPTPID11_ADDR		(_GPT_GPTPID1_ADDR(1))
#define _GPT_GPTPID11			PREG16(_GPT_GPTPID11_ADDR)
#define GPTPID11				_GPT_GPTPID11

#define _GPT_GPTPID1_BASE			 (0)
#define _GPT_GPTPID1_ADDR(n)		 ((_GPT_GPTPID1_BASE) + (_GPT_BASE_ADDRn(n)))
#define _GPT_GPTPID1(n)			 PREG16(_GPT_GPTPID1_ADDR(n))
#define _GPT_GPTPID1_ADDR_H(devNum)	 _GPT_GPTPID1_ADDR(devNum)
#define _GPT_GPTPID1_ADDRH(devNum)	 _GPT_GPTPID1_ADDR(devNum)

/*--------------------- Register: GPTPID2 -----------------------*/
#define _GPT_GPTPID20_ADDR		(_GPT_GPTPID2_ADDR(0))
#define _GPT_GPTPID20			PREG16(_GPT_GPTPID20_ADDR)
#define GPTPID20				_GPT_GPTPID20

#define _GPT_GPTPID21_ADDR		(_GPT_GPTPID2_ADDR(1))
#define _GPT_GPTPID21			PREG16(_GPT_GPTPID21_ADDR)
#define GPTPID21				_GPT_GPTPID21

#define _GPT_GPTPID2_BASE			 (0x1u)
#define _GPT_GPTPID2_ADDR(n)		 ((_GPT_GPTPID2_BASE) + (_GPT_BASE_ADDRn(n)))
#define _GPT_GPTPID2(n)			 PREG16(_GPT_GPTPID2_ADDR(n))
#define _GPT_GPTPID2_ADDR_H(devNum)	 _GPT_GPTPID2_ADDR(devNum)
#define _GPT_GPTPID2_ADDRH(devNum)	 _GPT_GPTPID2_ADDR(devNum)

/*--------------------- Register: GPTEMU -----------------------*/
#define _GPT_GPTEMU0_ADDR		(_GPT_GPTEMU_ADDR(0))
#define _GPT_GPTEMU0			PREG16(_GPT_GPTEMU0_ADDR)
#define GPTEMU0				_GPT_GPTEMU0

#define _GPT_GPTEMU1_ADDR		(_GPT_GPTEMU_ADDR(1))
#define _GPT_GPTEMU1			PREG16(_GPT_GPTEMU1_ADDR)
#define GPTEMU1				_GPT_GPTEMU1

#define _GPT_GPTEMU_BASE			 (0x2u)
#define _GPT_GPTEMU_ADDR(n)		 ((_GPT_GPTEMU_BASE) + (_GPT_BASE_ADDRn(n)))
#define _GPT_GPTEMU(n)			 PREG16(_GPT_GPTEMU_ADDR(n))
#define _GPT_GPTEMU_ADDR_H(devNum)	 _GPT_GPTEMU_ADDR(devNum)
#define _GPT_GPTEMU_ADDRH(devNum)	 _GPT_GPTEMU_ADDR(devNum)

/*--------------------- Register: GPTCLK -----------------------*/
#define _GPT_GPTCLK0_ADDR		(_GPT_GPTCLK_ADDR(0))
#define _GPT_GPTCLK0			PREG16(_GPT_GPTCLK0_ADDR)
#define GPTCLK0				_GPT_GPTCLK0

#define _GPT_GPTCLK1_ADDR		(_GPT_GPTCLK_ADDR(1))
#define _GPT_GPTCLK1			PREG16(_GPT_GPTCLK1_ADDR)
#define GPTCLK1				_GPT_GPTCLK1

#define _GPT_GPTCLK_BASE			 (0x3u)
#define _GPT_GPTCLK_ADDR(n)		 ((_GPT_GPTCLK_BASE) + (_GPT_BASE_ADDRn(n)))
#define _GPT_GPTCLK(n)			 PREG16(_GPT_GPTCLK_ADDR(n))
#define _GPT_GPTCLK_ADDR_H(devNum)	 _GPT_GPTCLK_ADDR(devNum)
#define _GPT_GPTCLK_ADDRH(devNum)	 _GPT_GPTCLK_ADDR(devNum)

/*--------------------- Register: GPTCNT1 -----------------------*/
#define _GPT_GPTCNT10_ADDR		(_GPT_GPTCNT1_ADDR(0))
#define _GPT_GPTCNT10			PREG16(_GPT_GPTCNT10_ADDR)
#define GPTCNT10				_GPT_GPTCNT10

#define _GPT_GPTCNT11_ADDR		(_GPT_GPTCNT1_ADDR(1))
#define _GPT_GPTCNT11			PREG16(_GPT_GPTCNT11_ADDR)
#define GPTCNT11				_GPT_GPTCNT11

#define _GPT_GPTCNT1_BASE			 (0x8u)
#define _GPT_GPTCNT1_ADDR(n)		 ((_GPT_GPTCNT1_BASE) + (_GPT_BASE_ADDRn(n)))
#define _GPT_GPTCNT1(n)			 PREG16(_GPT_GPTCNT1_ADDR(n))
#define _GPT_GPTCNT1_ADDR_H(devNum)	 _GPT_GPTCNT1_ADDR(devNum)
#define _GPT_GPTCNT1_ADDRH(devNum)	 _GPT_GPTCNT1_ADDR(devNum)

/*--------------------- Register: GPTCNT2 -----------------------*/
#define _GPT_GPTCNT20_ADDR		(_GPT_GPTCNT2_ADDR(0))
#define _GPT_GPTCNT20			PREG16(_GPT_GPTCNT20_ADDR)
#define GPTCNT20				_GPT_GPTCNT20

#define _GPT_GPTCNT21_ADDR		(_GPT_GPTCNT2_ADDR(1))
#define _GPT_GPTCNT21			PREG16(_GPT_GPTCNT21_ADDR)
#define GPTCNT21				_GPT_GPTCNT21

#define _GPT_GPTCNT2_BASE			 (0x9u)
#define _GPT_GPTCNT2_ADDR(n)		 ((_GPT_GPTCNT2_BASE) + (_GPT_BASE_ADDRn(n)))
#define _GPT_GPTCNT2(n)			 PREG16(_GPT_GPTCNT2_ADDR(n))
#define _GPT_GPTCNT2_ADDR_H(devNum)	 _GPT_GPTCNT2_ADDR(devNum)
#define _GPT_GPTCNT2_ADDRH(devNum)	 _GPT_GPTCNT2_ADDR(devNum)

/*--------------------- Register: GPTCNT3 -----------------------*/
#define _GPT_GPTCNT30_ADDR		(_GPT_GPTCNT3_ADDR(0))
#define _GPT_GPTCNT30			PREG16(_GPT_GPTCNT30_ADDR)
#define GPTCNT30				_GPT_GPTCNT30

#define _GPT_GPTCNT31_ADDR		(_GPT_GPTCNT3_ADDR(1))
#define _GPT_GPTCNT31			PREG16(_GPT_GPTCNT31_ADDR)
#define GPTCNT31				_GPT_GPTCNT31

#define _GPT_GPTCNT3_BASE			 (0xAu)
#define _GPT_GPTCNT3_ADDR(n)		 ((_GPT_GPTCNT3_BASE) + (_GPT_BASE_ADDRn(n)))
#define _GPT_GPTCNT3(n)			 PREG16(_GPT_GPTCNT3_ADDR(n))
#define _GPT_GPTCNT3_ADDR_H(devNum)	 _GPT_GPTCNT3_ADDR(devNum)
#define _GPT_GPTCNT3_ADDRH(devNum)	 _GPT_GPTCNT3_ADDR(devNum)

/*--------------------- Register: GPTCNT4 -----------------------*/
#define _GPT_GPTCNT40_ADDR		(_GPT_GPTCNT4_ADDR(0))
#define _GPT_GPTCNT40			PREG16(_GPT_GPTCNT40_ADDR)
#define GPTCNT40				_GPT_GPTCNT40

#define _GPT_GPTCNT41_ADDR		(_GPT_GPTCNT4_ADDR(1))
#define _GPT_GPTCNT41			PREG16(_GPT_GPTCNT41_ADDR)
#define GPTCNT41				_GPT_GPTCNT41

#define _GPT_GPTCNT4_BASE			 (0xBu)
#define _GPT_GPTCNT4_ADDR(n)		 ((_GPT_GPTCNT4_BASE) + (_GPT_BASE_ADDRn(n)))
#define _GPT_GPTCNT4(n)			 PREG16(_GPT_GPTCNT4_ADDR(n))
#define _GPT_GPTCNT4_ADDR_H(devNum)	 _GPT_GPTCNT4_ADDR(devNum)
#define _GPT_GPTCNT4_ADDRH(devNum)	 _GPT_GPTCNT4_ADDR(devNum)

/*--------------------- Register: GPTPRD1 -----------------------*/
#define _GPT_GPTPRD10_ADDR		(_GPT_GPTPRD1_ADDR(0))
#define _GPT_GPTPRD10			PREG16(_GPT_GPTPRD10_ADDR)
#define GPTPRD10				_GPT_GPTPRD10

#define _GPT_GPTPRD11_ADDR		(_GPT_GPTPRD1_ADDR(1))
#define _GPT_GPTPRD11			PREG16(_GPT_GPTPRD11_ADDR)
#define GPTPRD11				_GPT_GPTPRD11

#define _GPT_GPTPRD1_BASE			 (0xCu)
#define _GPT_GPTPRD1_ADDR(n)		 ((_GPT_GPTPRD1_BASE) + (_GPT_BASE_ADDRn(n)))
#define _GPT_GPTPRD1(n)			 PREG16(_GPT_GPTPRD1_ADDR(n))
#define _GPT_GPTPRD1_ADDR_H(devNum)	 _GPT_GPTPRD1_ADDR(devNum)
#define _GPT_GPTPRD1_ADDRH(devNum)	 _GPT_GPTPRD1_ADDR(devNum)

/*--------------------- Register: GPTPRD2 -----------------------*/
#define _GPT_GPTPRD20_ADDR		(_GPT_GPTPRD2_ADDR(0))
#define _GPT_GPTPRD20			PREG16(_GPT_GPTPRD20_ADDR)
#define GPTPRD20				_GPT_GPTPRD20

#define _GPT_GPTPRD21_ADDR		(_GPT_GPTPRD2_ADDR(1))
#define _GPT_GPTPRD21			PREG16(_GPT_GPTPRD21_ADDR)
#define GPTPRD21				_GPT_GPTPRD21

#define _GPT_GPTPRD2_BASE			 (0xDu)
#define _GPT_GPTPRD2_ADDR(n)		 ((_GPT_GPTPRD2_BASE) + (_GPT_BASE_ADDRn(n)))
#define _GPT_GPTPRD2(n)			 PREG16(_GPT_GPTPRD2_ADDR(n))
#define _GPT_GPTPRD2_ADDR_H(devNum)	 _GPT_GPTPRD2_ADDR(devNum)
#define _GPT_GPTPRD2_ADDRH(devNum)	 _GPT_GPTPRD2_ADDR(devNum)

/*--------------------- Register: GPTPRD3 -----------------------*/
#define _GPT_GPTPRD30_ADDR		(_GPT_GPTPRD3_ADDR(0))
#define _GPT_GPTPRD30			PREG16(_GPT_GPTPRD30_ADDR)
#define GPTPRD30				_GPT_GPTPRD30

#define _GPT_GPTPRD31_ADDR		(_GPT_GPTPRD3_ADDR(1))
#define _GPT_GPTPRD31			PREG16(_GPT_GPTPRD31_ADDR)
#define GPTPRD31				_GPT_GPTPRD31

#define _GPT_GPTPRD3_BASE			 (0xEu)
#define _GPT_GPTPRD3_ADDR(n)		 ((_GPT_GPTPRD3_BASE) + (_GPT_BASE_ADDRn(n)))
#define _GPT_GPTPRD3(n)			 PREG16(_GPT_GPTPRD3_ADDR(n))
#define _GPT_GPTPRD3_ADDR_H(devNum)	 _GPT_GPTPRD3_ADDR(devNum)
#define _GPT_GPTPRD3_ADDRH(devNum)	 _GPT_GPTPRD3_ADDR(devNum)

/*--------------------- Register: GPTPRD4 -----------------------*/
#define _GPT_GPTPRD40_ADDR		(_GPT_GPTPRD4_ADDR(0))
#define _GPT_GPTPRD40			PREG16(_GPT_GPTPRD40_ADDR)
#define GPTPRD40				_GPT_GPTPRD40

#define _GPT_GPTPRD41_ADDR		(_GPT_GPTPRD4_ADDR(1))
#define _GPT_GPTPRD41			PREG16(_GPT_GPTPRD41_ADDR)
#define GPTPRD41				_GPT_GPTPRD41

#define _GPT_GPTPRD4_BASE			 (0xFu)
#define _GPT_GPTPRD4_ADDR(n)		 ((_GPT_GPTPRD4_BASE) + (_GPT_BASE_ADDRn(n)))
#define _GPT_GPTPRD4(n)			 PREG16(_GPT_GPTPRD4_ADDR(n))
#define _GPT_GPTPRD4_ADDR_H(devNum)	 _GPT_GPTPRD4_ADDR(devNum)
#define _GPT_GPTPRD4_ADDRH(devNum)	 _GPT_GPTPRD4_ADDR(devNum)

/*--------------------- Register: GPTGPINT -----------------------*/
#define _GPT_GPTGPINT0_ADDR		(_GPT_GPTGPINT_ADDR(0))
#define _GPT_GPTGPINT0			PREG16(_GPT_GPTGPINT0_ADDR)
#define GPTGPINT0				_GPT_GPTGPINT0

#define _GPT_GPTGPINT1_ADDR		(_GPT_GPTGPINT_ADDR(1))
#define _GPT_GPTGPINT1			PREG16(_GPT_GPTGPINT1_ADDR)
#define GPTGPINT1				_GPT_GPTGPINT1

#define _GPT_GPTGPINT_BASE			 (0x4u)
#define _GPT_GPTGPINT_ADDR(n)		 ((_GPT_GPTGPINT_BASE) + (_GPT_BASE_ADDRn(n)))
#define _GPT_GPTGPINT(n)			 PREG16(_GPT_GPTGPINT_ADDR(n))
#define _GPT_GPTGPINT_ADDR_H(devNum)	 _GPT_GPTGPINT_ADDR(devNum)
#define _GPT_GPTGPINT_ADDRH(devNum)	 _GPT_GPTGPINT_ADDR(devNum)

/*--------------------- Register: GPTGPEN -----------------------*/
#define _GPT_GPTGPEN0_ADDR		(_GPT_GPTGPEN_ADDR(0))
#define _GPT_GPTGPEN0			PREG16(_GPT_GPTGPEN0_ADDR)
#define GPTGPEN0				_GPT_GPTGPEN0

#define _GPT_GPTGPEN1_ADDR		(_GPT_GPTGPEN_ADDR(1))
#define _GPT_GPTGPEN1			PREG16(_GPT_GPTGPEN1_ADDR)
#define GPTGPEN1				_GPT_GPTGPEN1

#define _GPT_GPTGPEN_BASE			 (0x5u)
#define _GPT_GPTGPEN_ADDR(n)		 ((_GPT_GPTGPEN_BASE) + (_GPT_BASE_ADDRn(n)))
#define _GPT_GPTGPEN(n)			 PREG16(_GPT_GPTGPEN_ADDR(n))
#define _GPT_GPTGPEN_ADDR_H(devNum)	 _GPT_GPTGPEN_ADDR(devNum)
#define _GPT_GPTGPEN_ADDRH(devNum)	 _GPT_GPTGPEN_ADDR(devNum)

/*--------------------- Register: GPTGPDIR -----------------------*/
#define _GPT_GPTGPDIR0_ADDR		(_GPT_GPTGPDIR_ADDR(0))
#define _GPT_GPTGPDIR0			PREG16(_GPT_GPTGPDIR0_ADDR)
#define GPTGPDIR0				_GPT_GPTGPDIR0

#define _GPT_GPTGPDIR1_ADDR		(_GPT_GPTGPDIR_ADDR(1))
#define _GPT_GPTGPDIR1			PREG16(_GPT_GPTGPDIR1_ADDR)
#define GPTGPDIR1				_GPT_GPTGPDIR1

#define _GPT_GPTGPDIR_BASE			 (0x7u)
#define _GPT_GPTGPDIR_ADDR(n)		 ((_GPT_GPTGPDIR_BASE) + (_GPT_BASE_ADDRn(n)))
#define _GPT_GPTGPDIR(n)			 PREG16(_GPT_GPTGPDIR_ADDR(n))
#define _GPT_GPTGPDIR_ADDR_H(devNum)	 _GPT_GPTGPDIR_ADDR(devNum)
#define _GPT_GPTGPDIR_ADDRH(devNum)	 _GPT_GPTGPDIR_ADDR(devNum)

/*--------------------- Register: GPTGPDAT -----------------------*/
#define _GPT_GPTGPDAT0_ADDR		(_GPT_GPTGPDAT_ADDR(0))
#define _GPT_GPTGPDAT0			PREG16(_GPT_GPTGPDAT0_ADDR)
#define GPTGPDAT0				_GPT_GPTGPDAT0

#define _GPT_GPTGPDAT1_ADDR		(_GPT_GPTGPDAT_ADDR(1))
#define _GPT_GPTGPDAT1			PREG16(_GPT_GPTGPDAT1_ADDR)
#define GPTGPDAT1				_GPT_GPTGPDAT1

#define _GPT_GPTGPDAT_BASE			 (0x6u)
#define _GPT_GPTGPDAT_ADDR(n)		 ((_GPT_GPTGPDAT_BASE) + (_GPT_BASE_ADDRn(n)))
#define _GPT_GPTGPDAT(n)			 PREG16(_GPT_GPTGPDAT_ADDR(n))
#define _GPT_GPTGPDAT_ADDR_H(devNum)	 _GPT_GPTGPDAT_ADDR(devNum)
#define _GPT_GPTGPDAT_ADDRH(devNum)	 _GPT_GPTGPDAT_ADDR(devNum)

/*--------------------- Register: GPTCTL1 -----------------------*/
#define _GPT_GPTCTL10_ADDR		(_GPT_GPTCTL1_ADDR(0))
#define _GPT_GPTCTL10			PREG16(_GPT_GPTCTL10_ADDR)
#define GPTCTL10				_GPT_GPTCTL10

#define _GPT_GPTCTL11_ADDR		(_GPT_GPTCTL1_ADDR(1))
#define _GPT_GPTCTL11			PREG16(_GPT_GPTCTL11_ADDR)
#define GPTCTL11				_GPT_GPTCTL11

#define _GPT_GPTCTL1_BASE			 (0x10u)
#define _GPT_GPTCTL1_ADDR(n)		 ((_GPT_GPTCTL1_BASE) + (_GPT_BASE_ADDRn(n)))
#define _GPT_GPTCTL1(n)			 PREG16(_GPT_GPTCTL1_ADDR(n))
#define _GPT_GPTCTL1_ADDR_H(devNum)	 _GPT_GPTCTL1_ADDR(devNum)
#define _GPT_GPTCTL1_ADDRH(devNum)	 _GPT_GPTCTL1_ADDR(devNum)

/*--------------------- Register: GPTCTL2 -----------------------*/
#define _GPT_GPTCTL20_ADDR		(_GPT_GPTCTL2_ADDR(0))
#define _GPT_GPTCTL20			PREG16(_GPT_GPTCTL20_ADDR)
#define GPTCTL20				_GPT_GPTCTL20

#define _GPT_GPTCTL21_ADDR		(_GPT_GPTCTL2_ADDR(1))
#define _GPT_GPTCTL21			PREG16(_GPT_GPTCTL21_ADDR)
#define GPTCTL21				_GPT_GPTCTL21

#define _GPT_GPTCTL2_BASE			 (0x11u)
#define _GPT_GPTCTL2_ADDR(n)		 ((_GPT_GPTCTL2_BASE) + (_GPT_BASE_ADDRn(n)))
#define _GPT_GPTCTL2(n)			 PREG16(_GPT_GPTCTL2_ADDR(n))
#define _GPT_GPTCTL2_ADDR_H(devNum)	 _GPT_GPTCTL2_ADDR(devNum)
#define _GPT_GPTCTL2_ADDRH(devNum)	 _GPT_GPTCTL2_ADDR(devNum)

/*--------------------- Register: GPTGCTL1 -----------------------*/
#define _GPT_GPTGCTL10_ADDR		(_GPT_GPTGCTL1_ADDR(0))
#define _GPT_GPTGCTL10			PREG16(_GPT_GPTGCTL10_ADDR)
#define GPTGCTL10				_GPT_GPTGCTL10

#define _GPT_GPTGCTL11_ADDR		(_GPT_GPTGCTL1_ADDR(1))
#define _GPT_GPTGCTL11			PREG16(_GPT_GPTGCTL11_ADDR)
#define GPTGCTL11				_GPT_GPTGCTL11

#define _GPT_GPTGCTL1_BASE			 (0x12u)
#define _GPT_GPTGCTL1_ADDR(n)		 ((_GPT_GPTGCTL1_BASE) + (_GPT_BASE_ADDRn(n)))
#define _GPT_GPTGCTL1(n)			 PREG16(_GPT_GPTGCTL1_ADDR(n))
#define _GPT_GPTGCTL1_ADDR_H(devNum)	 _GPT_GPTGCTL1_ADDR(devNum)
#define _GPT_GPTGCTL1_ADDRH(devNum)	 _GPT_GPTGCTL1_ADDR(devNum)


/*----------------------------------------------------------------*\
*		 Register Macros		
\*----------------------------------------------------------------*/

#define GPT_ADDR(Reg)		  _GPT_##Reg##_ADDR
#define GPT_RGET(Reg)		  _GPT_##Reg##_GET
#define GPT_RSET(Reg,Val)		  _GPT_##Reg##_SET(Val)
#define GPT_FGET(Reg,Field)		  _GPT_##Reg##_FGET(Field)
#define GPT_FSET(Reg,Field,Val)		  _GPT_##Reg##_FSET(Field, Val)
#define GPT_FMK(Reg,Field,Val)		  _GPT_##Reg##_##Field##_MK(Val)
#define GPT_RAOI(Reg,AND,OR,INV)		  _GPT_##Reg##_AOI(AND,OR,INV)
#define GPT_FAOI(Reg,Field,AND,OR,INV)	  _GPT_##Reg##_FAOI(Field,AND,OR,INV)
#define GPT_FMKS(Reg,Field,Sym)\
	  _GPT_##Reg##_##Field##_MK(GPT_##Reg##_##Field##_##Sym)
#define GPT_FSETS(Reg,Field,Sym)\
	 _GPT_##Reg##_FSET(Field,GPT_##Reg##_##Field##_##Sym)

#define GPT_ADDR_H(Handle,Reg)		  _GPT_##Reg##_ADDR_H(((GPT_PrivateObj*)(Handle))->devNum)
#define GPT_RGET_H(Handle,Reg)		  _GPT_##Reg##_GET(((GPT_PrivateObj*)(Handle))->devNum)
#define GPT_RSET_H(Handle,Reg,Val)		  _GPT_##Reg##_SET((((GPT_PrivateObj*)(Handle))->devNum),Val)
#define GPT_FGET_H(Handle,Reg,Field)	  _GPT_##Reg##_FGET((((GPT_PrivateObj*)(Handle))->devNum),Field)
#define GPT_FSET_H(Handle,Reg,Field,Val)	  _GPT_##Reg##_FSET((((GPT_PrivateObj*)(Handle))->devNum),Field,Val)
#define GPT_FMK_H(Handle,Reg,Field,Val)	  _GPT_##Reg##_##Field##_MK(Val)


#define GPT_ADDRH(Handle,Reg)		  _GPT_##Reg##_ADDRH(((GPT_PrivateObj*)(Handle))->devNum)
#define GPT_RGETH(Handle,Reg)		  _GPT_##Reg##_GET(((GPT_PrivateObj*)(Handle))->devNum)
#define GPT_RSETH(Handle,Reg,Val)		  _GPT_##Reg##_SET((((GPT_PrivateObj*)(Handle))->devNum),Val)
#define GPT_FGETH(Handle,Reg,Field)	  _GPT_##Reg##_FGET((((GPT_PrivateObj*)(Handle))->devNum),Field)
#define GPT_FSETH(Handle,Reg,Field,Val)	  _GPT_##Reg##_FSET((((GPT_PrivateObj*)(Handle))->devNum),Field,Val)
#define GPT_FMKH(Handle,Reg,Field,Val)	  _GPT_##Reg##_##Field##_MK(Val)

#define GPT_RAOI_H(Handle,Reg,AND,OR,INV)	  _GPT_##Reg##_AOI((((GPT_PrivateObj*)(Handle))->devNum),AND,OR,INV)
#define GPT_FAOI_H(Handle,Reg,Field,AND,OR,INV)\
	  _GPT_##Reg##_FAOI((((GPT_PrivateObj*)(Handle))->devNum),Field,AND,OR,INV)
#define GPT_FMKS_H(Handle,Reg,Field,Sym)\
	   _GPT_##Reg##_##Field##_MK(GPT_##Reg##_##Field##_##Sym)
#define GPT_FSETS_H(Handle,Reg,Field,Sym)\
	 _GPT_##Reg##_FSET(Handle,Field,GPT_##Reg##_##Field##_##Sym)


#define GPT_RAOIH(Handle,Reg,AND,OR,INV)	  _GPT_##Reg##_AOI((((GPT_PrivateObj*)(Handle))->devNum),AND,OR,INV)
#define GPT_FAOIH(Handle,Reg,Field,AND,OR,INV)\
	  _GPT_##Reg##_FAOI((((GPT_PrivateObj*)(Handle))->devNum),Field,AND,OR,INV)
#define GPT_FMKSH(Handle,Reg,Field,Sym)\
	   _GPT_##Reg##_##Field##_MK(GPT_##Reg##_##Field##_##Sym)
#define GPT_FSETSH(Handle,Reg,Field,Sym)\
	 _GPT_##Reg##_FSET(Handle,Field,GPT_##Reg##_##Field##_##Sym)



/*----------------------------------------------------------------*\
*		 Handle Registers Macros		
\*----------------------------------------------------------------*/


/*--------------------- Register: GPTPID1 -----------------------*/
#define _GPT_GPTPID1_GET(devNum)		  _PREG_GET(_GPT_GPTPID1_ADDR(devNum)) 
#define _GPT_GPTPID1_SET(devNum,Val)		  _PREG_SET(_GPT_GPTPID1_ADDR(devNum),Val)
#define _GPT_GPTPID1_FGET(devNum,Field)	          _PFIELD_GET(_GPT_GPTPID1_ADDR(devNum), _GPT_GPTPID1_##Field)
#define _GPT_GPTPID1_FSET(devNum,Field,Val)	  _PFIELD_SET(_GPT_GPTPID1_ADDR(devNum), _GPT_GPTPID1_##Field, Val)
#define _GPT_GPTPID1_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_GPT_GPTPID1_ADDR(devNum),AND,OR,INV)
#define _GPT_GPTPID1_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTPID1_ADDR(devNum), _GPT_GPTPID1_##Field,AND,OR,INV)

#define _GPT_GPTPID10_GET		  _PREG_GET(_GPT_GPTPID1_ADDR(0)) 
#define _GPT_GPTPID10_SET(Val)		  _PREG_SET(_GPT_GPTPID1_ADDR(0),Val)
#define _GPT_GPTPID10_FGET(Field)	  _PFIELD_GET(_GPT_GPTPID1_ADDR(0), _GPT_GPTPID1_##Field)
#define _GPT_GPTPID10_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTPID1_ADDR(0), _GPT_GPTPID1_##Field, Val)
#define _GPT_GPTPID10_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTPID1_ADDR(0),AND,OR,INV)
#define _GPT_GPTPID10_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTPID1_ADDR(0), _GPT_GPTPID1_##Field,AND,OR,INV)

#define _GPT_GPTPID11_GET		  _PREG_GET(_GPT_GPTPID1_ADDR(1)) 
#define _GPT_GPTPID11_SET(Val)		  _PREG_SET(_GPT_GPTPID1_ADDR(1),Val)
#define _GPT_GPTPID11_FGET(Field)	  _PFIELD_GET(_GPT_GPTPID1_ADDR(1), _GPT_GPTPID1_##Field)
#define _GPT_GPTPID11_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTPID1_ADDR(1), _GPT_GPTPID1_##Field, Val)
#define _GPT_GPTPID11_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTPID1_ADDR(1),AND,OR,INV)
#define _GPT_GPTPID11_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTPID1_ADDR(1), _GPT_GPTPID1_##Field,AND,OR,INV)


/*--------------------- Register: GPTPID2 -----------------------*/
#define _GPT_GPTPID2_GET(devNum)			  _PREG_GET(_GPT_GPTPID2_ADDR(devNum)) 
#define _GPT_GPTPID2_SET(devNum,Val)		  _PREG_SET(_GPT_GPTPID2_ADDR(devNum),Val)
#define _GPT_GPTPID2_FGET(devNum,Field)	  _PFIELD_GET(_GPT_GPTPID2_ADDR(devNum), _GPT_GPTPID2_##Field)
#define _GPT_GPTPID2_FSET(devNum,Field,Val)	  _PFIELD_SET(_GPT_GPTPID2_ADDR(devNum), _GPT_GPTPID2_##Field, Val)
#define _GPT_GPTPID2_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_GPT_GPTPID2_ADDR(devNum),AND,OR,INV)
#define _GPT_GPTPID2_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTPID2_ADDR(devNum), _GPT_GPTPID2_##Field,AND,OR,INV)

#define _GPT_GPTPID20_GET		  _PREG_GET(_GPT_GPTPID2_ADDR(0)) 
#define _GPT_GPTPID20_SET(Val)		  _PREG_SET(_GPT_GPTPID2_ADDR(0),Val)
#define _GPT_GPTPID20_FGET(Field)	  _PFIELD_GET(_GPT_GPTPID2_ADDR(0), _GPT_GPTPID2_##Field)
#define _GPT_GPTPID20_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTPID2_ADDR(0), _GPT_GPTPID2_##Field, Val)
#define _GPT_GPTPID20_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTPID2_ADDR(0),AND,OR,INV)
#define _GPT_GPTPID20_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTPID2_ADDR(0), _GPT_GPTPID2_##Field,AND,OR,INV)

#define _GPT_GPTPID21_GET		  _PREG_GET(_GPT_GPTPID2_ADDR(1)) 
#define _GPT_GPTPID21_SET(Val)		  _PREG_SET(_GPT_GPTPID2_ADDR(1),Val)
#define _GPT_GPTPID21_FGET(Field)	  _PFIELD_GET(_GPT_GPTPID2_ADDR(1), _GPT_GPTPID2_##Field)
#define _GPT_GPTPID21_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTPID2_ADDR(1), _GPT_GPTPID2_##Field, Val)
#define _GPT_GPTPID21_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTPID2_ADDR(1),AND,OR,INV)
#define _GPT_GPTPID21_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTPID2_ADDR(1), _GPT_GPTPID2_##Field,AND,OR,INV)


/*--------------------- Register: GPTEMU -----------------------*/
#define _GPT_GPTEMU_GET(devNum)			  _PREG_GET(_GPT_GPTEMU_ADDR(devNum)) 
#define _GPT_GPTEMU_SET(devNum,Val)		  _PREG_SET(_GPT_GPTEMU_ADDR(devNum),Val)
#define _GPT_GPTEMU_FGET(devNum,Field)	  _PFIELD_GET(_GPT_GPTEMU_ADDR(devNum), _GPT_GPTEMU_##Field)
#define _GPT_GPTEMU_FSET(devNum,Field,Val)	  _PFIELD_SET(_GPT_GPTEMU_ADDR(devNum), _GPT_GPTEMU_##Field, Val)
#define _GPT_GPTEMU_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_GPT_GPTEMU_ADDR(devNum),AND,OR,INV)
#define _GPT_GPTEMU_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTEMU_ADDR(devNum), _GPT_GPTEMU_##Field,AND,OR,INV)

#define _GPT_GPTEMU0_GET		  _PREG_GET(_GPT_GPTEMU_ADDR(0)) 
#define _GPT_GPTEMU0_SET(Val)		  _PREG_SET(_GPT_GPTEMU_ADDR(0),Val)
#define _GPT_GPTEMU0_FGET(Field)	  _PFIELD_GET(_GPT_GPTEMU_ADDR(0), _GPT_GPTEMU_##Field)
#define _GPT_GPTEMU0_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTEMU_ADDR(0), _GPT_GPTEMU_##Field, Val)
#define _GPT_GPTEMU0_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTEMU_ADDR(0),AND,OR,INV)
#define _GPT_GPTEMU0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTEMU_ADDR(0), _GPT_GPTEMU_##Field,AND,OR,INV)

#define _GPT_GPTEMU1_GET		  _PREG_GET(_GPT_GPTEMU_ADDR(1)) 
#define _GPT_GPTEMU1_SET(Val)		  _PREG_SET(_GPT_GPTEMU_ADDR(1),Val)
#define _GPT_GPTEMU1_FGET(Field)	  _PFIELD_GET(_GPT_GPTEMU_ADDR(1), _GPT_GPTEMU_##Field)
#define _GPT_GPTEMU1_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTEMU_ADDR(1), _GPT_GPTEMU_##Field, Val)
#define _GPT_GPTEMU1_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTEMU_ADDR(1),AND,OR,INV)
#define _GPT_GPTEMU1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTEMU_ADDR(1), _GPT_GPTEMU_##Field,AND,OR,INV)


/*--------------------- Register: GPTCLK -----------------------*/
#define _GPT_GPTCLK_GET(devNum)			  _PREG_GET(_GPT_GPTCLK_ADDR(devNum)) 
#define _GPT_GPTCLK_SET(devNum,Val)		  _PREG_SET(_GPT_GPTCLK_ADDR(devNum),Val)
#define _GPT_GPTCLK_FGET(devNum,Field)	  _PFIELD_GET(_GPT_GPTCLK_ADDR(devNum), _GPT_GPTCLK_##Field)
#define _GPT_GPTCLK_FSET(devNum,Field,Val)	  _PFIELD_SET(_GPT_GPTCLK_ADDR(devNum), _GPT_GPTCLK_##Field, Val)
#define _GPT_GPTCLK_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_GPT_GPTCLK_ADDR(devNum),AND,OR,INV)
#define _GPT_GPTCLK_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTCLK_ADDR(devNum), _GPT_GPTCLK_##Field,AND,OR,INV)

#define _GPT_GPTCLK0_GET		  _PREG_GET(_GPT_GPTCLK_ADDR(0)) 
#define _GPT_GPTCLK0_SET(Val)		  _PREG_SET(_GPT_GPTCLK_ADDR(0),Val)
#define _GPT_GPTCLK0_FGET(Field)	  _PFIELD_GET(_GPT_GPTCLK_ADDR(0), _GPT_GPTCLK_##Field)
#define _GPT_GPTCLK0_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTCLK_ADDR(0), _GPT_GPTCLK_##Field, Val)
#define _GPT_GPTCLK0_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTCLK_ADDR(0),AND,OR,INV)
#define _GPT_GPTCLK0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTCLK_ADDR(0),  _GPT_GPTCLK_##Field,AND,OR,INV)

#define _GPT_GPTCLK1_GET		  _PREG_GET(_GPT_GPTCLK_ADDR(1)) 
#define _GPT_GPTCLK1_SET(Val)		  _PREG_SET(_GPT_GPTCLK_ADDR(1),Val)
#define _GPT_GPTCLK1_FGET(Field)	  _PFIELD_GET(_GPT_GPTCLK_ADDR(1), _GPT_GPTCLK_##Field)
#define _GPT_GPTCLK1_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTCLK_ADDR(1), _GPT_GPTCLK_##Field, Val)
#define _GPT_GPTCLK1_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTCLK_ADDR(1),AND,OR,INV)
#define _GPT_GPTCLK1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTCLK_ADDR(1),  _GPT_GPTCLK_##Field,AND,OR,INV)


/*--------------------- Register: GPTCNT1 -----------------------*/
#define _GPT_GPTCNT1_GET(devNum)			  _PREG_GET(_GPT_GPTCNT1_ADDR(devNum)) 
#define _GPT_GPTCNT1_SET(devNum,Val)		  _PREG_SET(_GPT_GPTCNT1_ADDR(devNum),Val)
#define _GPT_GPTCNT1_FGET(devNum,Field)	  _PFIELD_GET(_GPT_GPTCNT1_ADDR(devNum), _GPT_GPTCNT1_##Field)
#define _GPT_GPTCNT1_FSET(devNum,Field,Val)	  _PFIELD_SET(_GPT_GPTCNT1_ADDR(devNum), _GPT_GPTCNT1_##Field, Val)
#define _GPT_GPTCNT1_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_GPT_GPTCNT1_ADDR(devNum),AND,OR,INV)
#define _GPT_GPTCNT1_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTCNT1_ADDR(devNum), _GPT_GPTCNT1_##Field,AND,OR,INV)

#define _GPT_GPTCNT10_GET		  _PREG_GET(_GPT_GPTCNT1_ADDR(0)) 
#define _GPT_GPTCNT10_SET(Val)		  _PREG_SET(_GPT_GPTCNT1_ADDR(0),Val)
#define _GPT_GPTCNT10_FGET(Field)	  _PFIELD_GET(_GPT_GPTCNT1_ADDR(0), _GPT_GPTCNT1_##Field)
#define _GPT_GPTCNT10_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTCNT1_ADDR(0), _GPT_GPTCNT1_##Field, Val)
#define _GPT_GPTCNT10_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTCNT1_ADDR(0),AND,OR,INV)
#define _GPT_GPTCNT10_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTCNT1_ADDR(0), _GPT_GPTCNT1_##Field,AND,OR,INV)

#define _GPT_GPTCNT11_GET		  _PREG_GET(_GPT_GPTCNT1_ADDR(1)) 
#define _GPT_GPTCNT11_SET(Val)		  _PREG_SET(_GPT_GPTCNT1_ADDR(1),Val)
#define _GPT_GPTCNT11_FGET(Field)	  _PFIELD_GET(_GPT_GPTCNT1_ADDR(1), _GPT_GPTCNT1_##Field)
#define _GPT_GPTCNT11_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTCNT1_ADDR(1), _GPT_GPTCNT1_##Field, Val)
#define _GPT_GPTCNT11_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTCNT1_ADDR(1),AND,OR,INV)
#define _GPT_GPTCNT11_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTCNT1_ADDR(1), _GPT_GPTCNT1_##Field,AND,OR,INV)


/*--------------------- Register: GPTCNT2 -----------------------*/
#define _GPT_GPTCNT2_GET(devNum)	       _PREG_GET(_GPT_GPTCNT2_ADDR(devNum)) 
#define _GPT_GPTCNT2_SET(devNum,Val)	       _PREG_SET(_GPT_GPTCNT2_ADDR(devNum),Val)
#define _GPT_GPTCNT2_FGET(devNum,Field)	       _PFIELD_GET(_GPT_GPTCNT2_ADDR(devNum), _GPT_GPTCNT2_##Field)
#define _GPT_GPTCNT2_FSET(devNum,Field,Val)    _PFIELD_SET(_GPT_GPTCNT2_ADDR(devNum), _GPT_GPTCNT2_##Field, Val)
#define _GPT_GPTCNT2_AOI(devNum,AND,OR,INV)    _PREG_AOI(_GPT_GPTCNT2_ADDR(devNum),AND,OR,INV)
#define _GPT_GPTCNT2_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTCNT2_ADDR(devNum), _GPT_GPTCNT2_##Field,AND,OR,INV)

#define _GPT_GPTCNT20_GET		  _PREG_GET(_GPT_GPTCNT2_ADDR(0)) 
#define _GPT_GPTCNT20_SET(Val)		  _PREG_SET(_GPT_GPTCNT2_ADDR(0),Val)
#define _GPT_GPTCNT20_FGET(Field)	  _PFIELD_GET(_GPT_GPTCNT2_ADDR(0), _GPT_GPTCNT2_##Field)
#define _GPT_GPTCNT20_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTCNT2_ADDR(0), _GPT_GPTCNT2_##Field, Val)
#define _GPT_GPTCNT20_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTCNT2_ADDR(0),AND,OR,INV)
#define _GPT_GPTCNT20_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTCNT2_ADDR(0), _GPT_GPTCNT2_##Field,AND,OR,INV)

#define _GPT_GPTCNT21_GET		  _PREG_GET(_GPT_GPTCNT2_ADDR(1)) 
#define _GPT_GPTCNT21_SET(Val)		  _PREG_SET(_GPT_GPTCNT2_ADDR(1),Val)
#define _GPT_GPTCNT21_FGET(Field)	  _PFIELD_GET(_GPT_GPTCNT2_ADDR(1), _GPT_GPTCNT2_##Field)
#define _GPT_GPTCNT21_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTCNT2_ADDR(1), _GPT_GPTCNT2_##Field, Val)
#define _GPT_GPTCNT21_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTCNT2_ADDR(1),AND,OR,INV)
#define _GPT_GPTCNT21_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTCNT2_ADDR(1), _GPT_GPTCNT2_##Field,AND,OR,INV)


/*--------------------- Register: GPTCNT3 -----------------------*/
#define _GPT_GPTCNT3_GET(devNum)	  _PREG_GET(_GPT_GPTCNT3_ADDR(devNum)) 
#define _GPT_GPTCNT3_SET(devNum,Val)	  _PREG_SET(_GPT_GPTCNT3_ADDR(devNum),Val)
#define _GPT_GPTCNT3_FGET(devNum,Field)	  _PFIELD_GET(_GPT_GPTCNT3_ADDR(devNum), _GPT_GPTCNT3_##Field)
#define _GPT_GPTCNT3_FSET(devNum,Field,Val)	  _PFIELD_SET(_GPT_GPTCNT3_ADDR(devNum), _GPT_GPTCNT3_##Field, Val)
#define _GPT_GPTCNT3_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_GPT_GPTCNT3_ADDR(devNum),AND,OR,INV)
#define _GPT_GPTCNT3_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTCNT3_ADDR(devNum),    _GPT_GPTCNT3_##Field,AND,OR,INV)

#define _GPT_GPTCNT30_GET		  _PREG_GET(_GPT_GPTCNT3_ADDR(0)) 
#define _GPT_GPTCNT30_SET(Val)		  _PREG_SET(_GPT_GPTCNT3_ADDR(0),Val)
#define _GPT_GPTCNT30_FGET(Field)	  _PFIELD_GET(_GPT_GPTCNT3_ADDR(0), _GPT_GPTCNT3_##Field)
#define _GPT_GPTCNT30_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTCNT3_ADDR(0), _GPT_GPTCNT3_##Field, Val)
#define _GPT_GPTCNT30_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTCNT3_ADDR(0),AND,OR,INV)
#define _GPT_GPTCNT30_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTCNT3_ADDR(0), _GPT_GPTCNT3_##Field,AND,OR,INV)

#define _GPT_GPTCNT31_GET		  _PREG_GET(_GPT_GPTCNT3_ADDR(1)) 
#define _GPT_GPTCNT31_SET(Val)		  _PREG_SET(_GPT_GPTCNT3_ADDR(1),Val)
#define _GPT_GPTCNT31_FGET(Field)	  _PFIELD_GET(_GPT_GPTCNT3_ADDR(1), _GPT_GPTCNT3_##Field)
#define _GPT_GPTCNT31_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTCNT3_ADDR(1), _GPT_GPTCNT3_##Field, Val)
#define _GPT_GPTCNT31_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTCNT3_ADDR(1),AND,OR,INV)
#define _GPT_GPTCNT31_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTCNT3_ADDR(1), _GPT_GPTCNT3_##Field,AND,OR,INV)


/*--------------------- Register: GPTCNT4 -----------------------*/
#define _GPT_GPTCNT4_GET(devNum)			  _PREG_GET(_GPT_GPTCNT4_ADDR(devNum)) 
#define _GPT_GPTCNT4_SET(devNum,Val)		  _PREG_SET(_GPT_GPTCNT4_ADDR(devNum),Val)
#define _GPT_GPTCNT4_FGET(devNum,Field)	  _PFIELD_GET(_GPT_GPTCNT4_ADDR(devNum), _GPT_GPTCNT4_##Field)
#define _GPT_GPTCNT4_FSET(devNum,Field,Val)	  _PFIELD_SET(_GPT_GPTCNT4_ADDR(devNum), _GPT_GPTCNT4_##Field, Val)
#define _GPT_GPTCNT4_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_GPT_GPTCNT4_ADDR(devNum),AND,OR,INV)
#define _GPT_GPTCNT4_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTCNT4_ADDR(devNum), _GPT_GPTCNT4_##Field,AND,OR,INV)

#define _GPT_GPTCNT40_GET		  _PREG_GET(_GPT_GPTCNT4_ADDR(0)) 
#define _GPT_GPTCNT40_SET(Val)		  _PREG_SET(_GPT_GPTCNT4_ADDR(0),Val)
#define _GPT_GPTCNT40_FGET(Field)	  _PFIELD_GET(_GPT_GPTCNT4_ADDR(0), _GPT_GPTCNT4_##Field)
#define _GPT_GPTCNT40_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTCNT4_ADDR(0), _GPT_GPTCNT4_##Field, Val)
#define _GPT_GPTCNT40_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTCNT4_ADDR(0),AND,OR,INV)
#define _GPT_GPTCNT40_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTCNT4_ADDR(0), _GPT_GPTCNT4_##Field,AND,OR,INV)

#define _GPT_GPTCNT41_GET		  _PREG_GET(_GPT_GPTCNT4_ADDR(1)) 
#define _GPT_GPTCNT41_SET(Val)		  _PREG_SET(_GPT_GPTCNT4_ADDR(1),Val)
#define _GPT_GPTCNT41_FGET(Field)	  _PFIELD_GET(_GPT_GPTCNT4_ADDR(1), _GPT_GPTCNT4_##Field)
#define _GPT_GPTCNT41_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTCNT4_ADDR(1), _GPT_GPTCNT4_##Field, Val)
#define _GPT_GPTCNT41_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTCNT4_ADDR(1),AND,OR,INV)
#define _GPT_GPTCNT41_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTCNT4_ADDR(1), _GPT_GPTCNT4_##Field,AND,OR,INV)


/*--------------------- Register: GPTPRD1 -----------------------*/
#define _GPT_GPTPRD1_GET(devNum)	  _PREG_GET(_GPT_GPTPRD1_ADDR(devNum)) 
#define _GPT_GPTPRD1_SET(devNum,Val)	  _PREG_SET(_GPT_GPTPRD1_ADDR(devNum),Val)
#define _GPT_GPTPRD1_FGET(devNum,Field)	  _PFIELD_GET(_GPT_GPTPRD1_ADDR(devNum), _GPT_GPTPRD1_##Field)
#define _GPT_GPTPRD1_FSET(devNum,Field,Val)	  _PFIELD_SET(_GPT_GPTPRD1_ADDR(devNum), _GPT_GPTPRD1_##Field, Val)
#define _GPT_GPTPRD1_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_GPT_GPTPRD1_ADDR(devNum),AND,OR,INV)
#define _GPT_GPTPRD1_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTPRD1_ADDR(devNum), _GPT_GPTPRD1_##Field,AND,OR,INV)

#define _GPT_GPTPRD10_GET		  _PREG_GET(_GPT_GPTPRD1_ADDR(0)) 
#define _GPT_GPTPRD10_SET(Val)		  _PREG_SET(_GPT_GPTPRD1_ADDR(0),Val)
#define _GPT_GPTPRD10_FGET(Field)	  _PFIELD_GET(_GPT_GPTPRD1_ADDR(0), _GPT_GPTPRD1_##Field)
#define _GPT_GPTPRD10_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTPRD1_ADDR(0), _GPT_GPTPRD1_##Field, Val)
#define _GPT_GPTPRD10_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTPRD1_ADDR(0),AND,OR,INV)
#define _GPT_GPTPRD10_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTPRD1_ADDR(0), _GPT_GPTPRD1_##Field,AND,OR,INV)

#define _GPT_GPTPRD11_GET		  _PREG_GET(_GPT_GPTPRD1_ADDR(1)) 
#define _GPT_GPTPRD11_SET(Val)		  _PREG_SET(_GPT_GPTPRD1_ADDR(1),Val)
#define _GPT_GPTPRD11_FGET(Field)	  _PFIELD_GET(_GPT_GPTPRD1_ADDR(1), _GPT_GPTPRD1_##Field)
#define _GPT_GPTPRD11_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTPRD1_ADDR(1), _GPT_GPTPRD1_##Field, Val)
#define _GPT_GPTPRD11_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTPRD1_ADDR(1),AND,OR,INV)
#define _GPT_GPTPRD11_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTPRD1_ADDR(1), _GPT_GPTPRD1_##Field,AND,OR,INV)


/*--------------------- Register: GPTPRD2 -----------------------*/
#define _GPT_GPTPRD2_GET(devNum)	  _PREG_GET(_GPT_GPTPRD2_ADDR(devNum)) 
#define _GPT_GPTPRD2_SET(devNum,Val)	  _PREG_SET(_GPT_GPTPRD2_ADDR(devNum),Val)
#define _GPT_GPTPRD2_FGET(devNum,Field)	  _PFIELD_GET(_GPT_GPTPRD2_ADDR(devNum), _GPT_GPTPRD2_##Field)
#define _GPT_GPTPRD2_FSET(devNum,Field,Val)	  _PFIELD_SET(_GPT_GPTPRD2_ADDR(devNum), _GPT_GPTPRD2_##Field, Val)
#define _GPT_GPTPRD2_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_GPT_GPTPRD2_ADDR(devNum),AND,OR,INV)
#define _GPT_GPTPRD2_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTPRD2_ADDR(devNum), _GPT_GPTPRD2_##Field,AND,OR,INV)

#define _GPT_GPTPRD20_GET		  _PREG_GET(_GPT_GPTPRD2_ADDR(0)) 
#define _GPT_GPTPRD20_SET(Val)		  _PREG_SET(_GPT_GPTPRD2_ADDR(0),Val)
#define _GPT_GPTPRD20_FGET(Field)	  _PFIELD_GET(_GPT_GPTPRD2_ADDR(0), _GPT_GPTPRD2_##Field)
#define _GPT_GPTPRD20_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTPRD2_ADDR(0), _GPT_GPTPRD2_##Field, Val)
#define _GPT_GPTPRD20_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTPRD2_ADDR(0),AND,OR,INV)
#define _GPT_GPTPRD20_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTPRD2_ADDR(0), _GPT_GPTPRD2_##Field,AND,OR,INV)

#define _GPT_GPTPRD21_GET		  _PREG_GET(_GPT_GPTPRD2_ADDR(1)) 
#define _GPT_GPTPRD21_SET(Val)		  _PREG_SET(_GPT_GPTPRD2_ADDR(1),Val)
#define _GPT_GPTPRD21_FGET(Field)	  _PFIELD_GET(_GPT_GPTPRD2_ADDR(1), _GPT_GPTPRD2_##Field)
#define _GPT_GPTPRD21_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTPRD2_ADDR(1), _GPT_GPTPRD2_##Field, Val)
#define _GPT_GPTPRD21_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTPRD2_ADDR(1),AND,OR,INV)
#define _GPT_GPTPRD21_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTPRD2_ADDR(1), _GPT_GPTPRD2_##Field,AND,OR,INV)


/*--------------------- Register: GPTPRD3 -----------------------*/
#define _GPT_GPTPRD3_GET(devNum)	  _PREG_GET(_GPT_GPTPRD3_ADDR(devNum)) 
#define _GPT_GPTPRD3_SET(devNum,Val)	  _PREG_SET(_GPT_GPTPRD3_ADDR(devNum),Val)
#define _GPT_GPTPRD3_FGET(devNum,Field)	  _PFIELD_GET(_GPT_GPTPRD3_ADDR(devNum), _GPT_GPTPRD3_##Field)
#define _GPT_GPTPRD3_FSET(devNum,Field,Val)	  _PFIELD_SET(_GPT_GPTPRD3_ADDR(devNum), _GPT_GPTPRD3_##Field, Val)
#define _GPT_GPTPRD3_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_GPT_GPTPRD3_ADDR(devNum),AND,OR,INV)
#define _GPT_GPTPRD3_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTPRD3_ADDR(devNum), _GPT_GPTPRD3_##Field,AND,OR,INV)

#define _GPT_GPTPRD30_GET		  _PREG_GET(_GPT_GPTPRD3_ADDR(0)) 
#define _GPT_GPTPRD30_SET(Val)		  _PREG_SET(_GPT_GPTPRD3_ADDR(0),Val)
#define _GPT_GPTPRD30_FGET(Field)	  _PFIELD_GET(_GPT_GPTPRD3_ADDR(0), _GPT_GPTPRD3_##Field)
#define _GPT_GPTPRD30_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTPRD3_ADDR(0), _GPT_GPTPRD3_##Field, Val)
#define _GPT_GPTPRD30_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTPRD3_ADDR(0),AND,OR,INV)
#define _GPT_GPTPRD30_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTPRD3_ADDR(0), _GPT_GPTPRD3_##Field,AND,OR,INV)

#define _GPT_GPTPRD31_GET		  _PREG_GET(_GPT_GPTPRD3_ADDR(1)) 
#define _GPT_GPTPRD31_SET(Val)		  _PREG_SET(_GPT_GPTPRD3_ADDR(1),Val)
#define _GPT_GPTPRD31_FGET(Field)	  _PFIELD_GET(_GPT_GPTPRD3_ADDR(1), _GPT_GPTPRD3_##Field)
#define _GPT_GPTPRD31_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTPRD3_ADDR(1), _GPT_GPTPRD3_##Field, Val)
#define _GPT_GPTPRD31_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTPRD3_ADDR(1),AND,OR,INV)
#define _GPT_GPTPRD31_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTPRD3_ADDR(1), _GPT_GPTPRD3_##Field,AND,OR,INV)


/*--------------------- Register: GPTPRD4 -----------------------*/
#define _GPT_GPTPRD4_GET(devNum)	  _PREG_GET(_GPT_GPTPRD4_ADDR(devNum)) 
#define _GPT_GPTPRD4_SET(devNum,Val)	  _PREG_SET(_GPT_GPTPRD4_ADDR(devNum),Val)
#define _GPT_GPTPRD4_FGET(devNum,Field)	  _PFIELD_GET(_GPT_GPTPRD4_ADDR(devNum), _GPT_GPTPRD4_##Field)
#define _GPT_GPTPRD4_FSET(devNum,Field,Val)	  _PFIELD_SET(_GPT_GPTPRD4_ADDR(devNum), _GPT_GPTPRD4_##Field, Val)
#define _GPT_GPTPRD4_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_GPT_GPTPRD4_ADDR(devNum),AND,OR,INV)
#define _GPT_GPTPRD4_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTPRD4_ADDR(devNum), _GPT_GPTPRD4_##Field,AND,OR,INV)

#define _GPT_GPTPRD40_GET		  _PREG_GET(_GPT_GPTPRD4_ADDR(0)) 
#define _GPT_GPTPRD40_SET(Val)		  _PREG_SET(_GPT_GPTPRD4_ADDR(0),Val)
#define _GPT_GPTPRD40_FGET(Field)	  _PFIELD_GET(_GPT_GPTPRD4_ADDR(0), _GPT_GPTPRD4_##Field)
#define _GPT_GPTPRD40_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTPRD4_ADDR(0), _GPT_GPTPRD4_##Field, Val)
#define _GPT_GPTPRD40_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTPRD4_ADDR(0),AND,OR,INV)
#define _GPT_GPTPRD40_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTPRD4_ADDR(0), _GPT_GPTPRD4_##Field,AND,OR,INV)

#define _GPT_GPTPRD41_GET		  _PREG_GET(_GPT_GPTPRD4_ADDR(1)) 
#define _GPT_GPTPRD41_SET(Val)		  _PREG_SET(_GPT_GPTPRD4_ADDR(1),Val)
#define _GPT_GPTPRD41_FGET(Field)	  _PFIELD_GET(_GPT_GPTPRD4_ADDR(1), _GPT_GPTPRD4_##Field)
#define _GPT_GPTPRD41_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTPRD4_ADDR(1), _GPT_GPTPRD4_##Field, Val)
#define _GPT_GPTPRD41_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTPRD4_ADDR(1),AND,OR,INV)
#define _GPT_GPTPRD41_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTPRD4_ADDR(1), _GPT_GPTPRD4_##Field,AND,OR,INV)


/*--------------------- Register: GPTGPINT -----------------------*/
#define _GPT_GPTGPINT_GET(devNum)		  _PREG_GET(_GPT_GPTGPINT_ADDR(devNum)) 
#define _GPT_GPTGPINT_SET(devNum,Val)		  _PREG_SET(_GPT_GPTGPINT_ADDR(devNum),Val)
#define _GPT_GPTGPINT_FGET(devNum,Field)	  _PFIELD_GET(_GPT_GPTGPINT_ADDR(devNum), _GPT_GPTGPINT_##Field)
#define _GPT_GPTGPINT_FSET(devNum,Field,Val)	  _PFIELD_SET(_GPT_GPTGPINT_ADDR(devNum), _GPT_GPTGPINT_##Field, Val)
#define _GPT_GPTGPINT_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_GPT_GPTGPINT_ADDR(devNum),AND,OR,INV)
#define _GPT_GPTGPINT_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTGPINT_ADDR(devNum), _GPT_GPTGPINT_##Field,AND,OR,INV)

#define _GPT_GPTGPINT0_GET		  _PREG_GET(_GPT_GPTGPINT_ADDR(0)) 
#define _GPT_GPTGPINT0_SET(Val)		  _PREG_SET(_GPT_GPTGPINT_ADDR(0),Val)
#define _GPT_GPTGPINT0_FGET(Field)	  _PFIELD_GET(_GPT_GPTGPINT_ADDR(0), _GPT_GPTGPINT_##Field)
#define _GPT_GPTGPINT0_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTGPINT_ADDR(0), _GPT_GPTGPINT_##Field, Val)
#define _GPT_GPTGPINT0_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTGPINT_ADDR(0),AND,OR,INV)
#define _GPT_GPTGPINT0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTGPINT_ADDR(0), _GPT_GPTGPINT_##Field,AND,OR,INV)

#define _GPT_GPTGPINT1_GET		  _PREG_GET(_GPT_GPTGPINT_ADDR(1)) 
#define _GPT_GPTGPINT1_SET(Val)		  _PREG_SET(_GPT_GPTGPINT_ADDR(1),Val)
#define _GPT_GPTGPINT1_FGET(Field)	  _PFIELD_GET(_GPT_GPTGPINT_ADDR(1), _GPT_GPTGPINT_##Field)
#define _GPT_GPTGPINT1_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTGPINT_ADDR(1), _GPT_GPTGPINT_##Field, Val)
#define _GPT_GPTGPINT1_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTGPINT_ADDR(1),AND,OR,INV)
#define _GPT_GPTGPINT1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTGPINT_ADDR(1), _GPT_GPTGPINT_##Field,AND,OR,INV)


/*--------------------- Register: GPTGPEN -----------------------*/
#define _GPT_GPTGPEN_GET(devNum)		  _PREG_GET(_GPT_GPTGPEN_ADDR(devNum)) 
#define _GPT_GPTGPEN_SET(devNum,Val)		  _PREG_SET(_GPT_GPTGPEN_ADDR(devNum),Val)
#define _GPT_GPTGPEN_FGET(devNum,Field)	          _PFIELD_GET(_GPT_GPTGPEN_ADDR(devNum), _GPT_GPTGPEN_##Field)
#define _GPT_GPTGPEN_FSET(devNum,Field,Val)	  _PFIELD_SET(_GPT_GPTGPEN_ADDR(devNum), _GPT_GPTGPEN_##Field, Val)
#define _GPT_GPTGPEN_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_GPT_GPTGPEN_ADDR(devNum),AND,OR,INV)
#define _GPT_GPTGPEN_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTGPEN_ADDR(devNum), _GPT_GPTGPEN_##Field,AND,OR,INV)

#define _GPT_GPTGPEN0_GET		  _PREG_GET(_GPT_GPTGPEN_ADDR(0)) 
#define _GPT_GPTGPEN0_SET(Val)		  _PREG_SET(_GPT_GPTGPEN_ADDR(0),Val)
#define _GPT_GPTGPEN0_FGET(Field)	  _PFIELD_GET(_GPT_GPTGPEN_ADDR(0), _GPT_GPTGPEN_##Field)
#define _GPT_GPTGPEN0_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTGPEN_ADDR(0), _GPT_GPTGPEN_##Field, Val)
#define _GPT_GPTGPEN0_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTGPEN_ADDR(0),AND,OR,INV)
#define _GPT_GPTGPEN0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTGPEN_ADDR(0), _GPT_GPTGPEN_##Field,AND,OR,INV)

#define _GPT_GPTGPEN1_GET		  _PREG_GET(_GPT_GPTGPEN_ADDR(1)) 
#define _GPT_GPTGPEN1_SET(Val)		  _PREG_SET(_GPT_GPTGPEN_ADDR(1),Val)
#define _GPT_GPTGPEN1_FGET(Field)	  _PFIELD_GET(_GPT_GPTGPEN_ADDR(1), _GPT_GPTGPEN_##Field)
#define _GPT_GPTGPEN1_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTGPEN_ADDR(1), _GPT_GPTGPEN_##Field, Val)
#define _GPT_GPTGPEN1_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTGPEN_ADDR(1),AND,OR,INV)
#define _GPT_GPTGPEN1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTGPEN_ADDR(1), _GPT_GPTGPEN_##Field,AND,OR,INV)


/*--------------------- Register: GPTGPDIR -----------------------*/
#define _GPT_GPTGPDIR_GET(devNum)		  _PREG_GET(_GPT_GPTGPDIR_ADDR(devNum)) 
#define _GPT_GPTGPDIR_SET(devNum,Val)		  _PREG_SET(_GPT_GPTGPDIR_ADDR(devNum),Val)
#define _GPT_GPTGPDIR_FGET(devNum,Field)	  _PFIELD_GET(_GPT_GPTGPDIR_ADDR(devNum), _GPT_GPTGPDIR_##Field)
#define _GPT_GPTGPDIR_FSET(devNum,Field,Val)	  _PFIELD_SET(_GPT_GPTGPDIR_ADDR(devNum), _GPT_GPTGPDIR_##Field, Val)
#define _GPT_GPTGPDIR_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_GPT_GPTGPDIR_ADDR(devNum),AND,OR,INV)
#define _GPT_GPTGPDIR_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTGPDIR_ADDR(devNum), _GPT_GPTGPDIR_##Field,AND,OR,INV)

#define _GPT_GPTGPDIR0_GET		  _PREG_GET(_GPT_GPTGPDIR_ADDR(0)) 
#define _GPT_GPTGPDIR0_SET(Val)		  _PREG_SET(_GPT_GPTGPDIR_ADDR(0),Val)
#define _GPT_GPTGPDIR0_FGET(Field)	  _PFIELD_GET(_GPT_GPTGPDIR_ADDR(0), _GPT_GPTGPDIR_##Field)
#define _GPT_GPTGPDIR0_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTGPDIR_ADDR(0), _GPT_GPTGPDIR_##Field, Val)
#define _GPT_GPTGPDIR0_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTGPDIR_ADDR(0),AND,OR,INV)
#define _GPT_GPTGPDIR0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTGPDIR_ADDR(0), _GPT_GPTGPDIR_##Field,AND,OR,INV)

#define _GPT_GPTGPDIR1_GET		  _PREG_GET(_GPT_GPTGPDIR_ADDR(1)) 
#define _GPT_GPTGPDIR1_SET(Val)		  _PREG_SET(_GPT_GPTGPDIR_ADDR(1),Val)
#define _GPT_GPTGPDIR1_FGET(Field)	  _PFIELD_GET(_GPT_GPTGPDIR_ADDR(1), _GPT_GPTGPDIR_##Field)
#define _GPT_GPTGPDIR1_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTGPDIR_ADDR(1), _GPT_GPTGPDIR_##Field, Val)
#define _GPT_GPTGPDIR1_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTGPDIR_ADDR(1),AND,OR,INV)
#define _GPT_GPTGPDIR1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTGPDIR_ADDR(1), _GPT_GPTGPDIR_##Field,AND,OR,INV)


/*--------------------- Register: GPTGPDAT -----------------------*/
#define _GPT_GPTGPDAT_GET(devNum)		  _PREG_GET(_GPT_GPTGPDAT_ADDR(devNum)) 
#define _GPT_GPTGPDAT_SET(devNum,Val)		  _PREG_SET(_GPT_GPTGPDAT_ADDR(devNum),Val)
#define _GPT_GPTGPDAT_FGET(devNum,Field)	  _PFIELD_GET(_GPT_GPTGPDAT_ADDR(devNum), _GPT_GPTGPDAT_##Field)
#define _GPT_GPTGPDAT_FSET(devNum,Field,Val)	  _PFIELD_SET(_GPT_GPTGPDAT_ADDR(devNum), _GPT_GPTGPDAT_##Field, Val)
#define _GPT_GPTGPDAT_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_GPT_GPTGPDAT_ADDR(devNum),AND,OR,INV)
#define _GPT_GPTGPDAT_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTGPDAT_ADDR(devNum), _GPT_GPTGPDAT_##Field,AND,OR,INV)

#define _GPT_GPTGPDAT0_GET		  _PREG_GET(_GPT_GPTGPDAT_ADDR(0)) 
#define _GPT_GPTGPDAT0_SET(Val)		  _PREG_SET(_GPT_GPTGPDAT_ADDR(0),Val)
#define _GPT_GPTGPDAT0_FGET(Field)	  _PFIELD_GET(_GPT_GPTGPDAT_ADDR(0), _GPT_GPTGPDAT_##Field)
#define _GPT_GPTGPDAT0_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTGPDAT_ADDR(0), _GPT_GPTGPDAT_##Field, Val)
#define _GPT_GPTGPDAT0_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTGPDAT_ADDR(0),AND,OR,INV)
#define _GPT_GPTGPDAT0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTGPDAT_ADDR(0), _GPT_GPTGPDAT_##Field,AND,OR,INV)

#define _GPT_GPTGPDAT1_GET		  _PREG_GET(_GPT_GPTGPDAT_ADDR(1)) 
#define _GPT_GPTGPDAT1_SET(Val)		  _PREG_SET(_GPT_GPTGPDAT_ADDR(1),Val)
#define _GPT_GPTGPDAT1_FGET(Field)	  _PFIELD_GET(_GPT_GPTGPDAT_ADDR(1), _GPT_GPTGPDAT_##Field)
#define _GPT_GPTGPDAT1_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTGPDAT_ADDR(1), _GPT_GPTGPDAT_##Field, Val)
#define _GPT_GPTGPDAT1_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTGPDAT_ADDR(1),AND,OR,INV)
#define _GPT_GPTGPDAT1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTGPDAT_ADDR(1), _GPT_GPTGPDAT_##Field,AND,OR,INV)


/*--------------------- Register: GPTCTL1 -----------------------*/
#define _GPT_GPTCTL1_GET(devNum)	    _PREG_GET(_GPT_GPTCTL1_ADDR(devNum)) 
#define _GPT_GPTCTL1_SET(devNum,Val)	    _PREG_SET(_GPT_GPTCTL1_ADDR(devNum),Val)
#define _GPT_GPTCTL1_FGET(devNum,Field)	    _PFIELD_GET(_GPT_GPTCTL1_ADDR(devNum), _GPT_GPTCTL1_##Field)
#define _GPT_GPTCTL1_FSET(devNum,Field,Val) _PFIELD_SET(_GPT_GPTCTL1_ADDR(devNum), _GPT_GPTCTL1_##Field, Val)
#define _GPT_GPTCTL1_AOI(devNum,AND,OR,INV) _PREG_AOI(_GPT_GPTCTL1_ADDR(devNum),AND,OR,INV)
#define _GPT_GPTCTL1_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTCTL1_ADDR(devNum), _GPT_GPTCTL1_##Field,AND,OR,INV)

#define _GPT_GPTCTL10_GET		  _PREG_GET(_GPT_GPTCTL1_ADDR(0)) 
#define _GPT_GPTCTL10_SET(Val)		  _PREG_SET(_GPT_GPTCTL1_ADDR(0),Val)
#define _GPT_GPTCTL10_FGET(Field)	  _PFIELD_GET(_GPT_GPTCTL1_ADDR(0), _GPT_GPTCTL1_##Field)
#define _GPT_GPTCTL10_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTCTL1_ADDR(0), _GPT_GPTCTL1_##Field, Val)
#define _GPT_GPTCTL10_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTCTL1_ADDR(0),AND,OR,INV)
#define _GPT_GPTCTL10_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTCTL1_ADDR(0), _GPT_GPTCTL1_##Field,AND,OR,INV)

#define _GPT_GPTCTL11_GET		  _PREG_GET(_GPT_GPTCTL1_ADDR(1)) 
#define _GPT_GPTCTL11_SET(Val)		  _PREG_SET(_GPT_GPTCTL1_ADDR(1),Val)
#define _GPT_GPTCTL11_FGET(Field)	  _PFIELD_GET(_GPT_GPTCTL1_ADDR(1), _GPT_GPTCTL1_##Field)
#define _GPT_GPTCTL11_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTCTL1_ADDR(1), _GPT_GPTCTL1_##Field, Val)
#define _GPT_GPTCTL11_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTCTL1_ADDR(1),AND,OR,INV)
#define _GPT_GPTCTL11_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTCTL1_ADDR(1), _GPT_GPTCTL1_##Field,AND,OR,INV)


/*--------------------- Register: GPTCTL2 -----------------------*/
#define _GPT_GPTCTL2_GET(devNum)	        _PREG_GET(_GPT_GPTCTL2_ADDR(devNum)) 
#define _GPT_GPTCTL2_SET(devNum,Val)	        _PREG_SET(_GPT_GPTCTL2_ADDR(devNum),Val)
#define _GPT_GPTCTL2_FGET(devNum,Field)	        _PFIELD_GET(_GPT_GPTCTL2_ADDR(devNum), _GPT_GPTCTL2_##Field)
#define _GPT_GPTCTL2_FSET(devNum,Field,Val)	_PFIELD_SET(_GPT_GPTCTL2_ADDR(devNum), _GPT_GPTCTL2_##Field, Val)
#define _GPT_GPTCTL2_AOI(devNum,AND,OR,INV)	_PREG_AOI(_GPT_GPTCTL2_ADDR(devNum),AND,OR,INV)
#define _GPT_GPTCTL2_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTCTL2_ADDR(devNum), _GPT_GPTCTL2_##Field,AND,OR,INV)

#define _GPT_GPTCTL20_GET		  _PREG_GET(_GPT_GPTCTL2_ADDR(0)) 
#define _GPT_GPTCTL20_SET(Val)		  _PREG_SET(_GPT_GPTCTL2_ADDR(0),Val)
#define _GPT_GPTCTL20_FGET(Field)	  _PFIELD_GET(_GPT_GPTCTL2_ADDR(0), _GPT_GPTCTL2_##Field)
#define _GPT_GPTCTL20_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTCTL2_ADDR(0), _GPT_GPTCTL2_##Field, Val)
#define _GPT_GPTCTL20_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTCTL2_ADDR(0),AND,OR,INV)
#define _GPT_GPTCTL20_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTCTL2_ADDR(0), _GPT_GPTCTL2_##Field,AND,OR,INV)

#define _GPT_GPTCTL21_GET		  _PREG_GET(_GPT_GPTCTL2_ADDR(1)) 
#define _GPT_GPTCTL21_SET(Val)		  _PREG_SET(_GPT_GPTCTL2_ADDR(1),Val)
#define _GPT_GPTCTL21_FGET(Field)	  _PFIELD_GET(_GPT_GPTCTL2_ADDR(1), _GPT_GPTCTL2_##Field)
#define _GPT_GPTCTL21_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTCTL2_ADDR(1), _GPT_GPTCTL2_##Field, Val)
#define _GPT_GPTCTL21_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTCTL2_ADDR(1),AND,OR,INV)
#define _GPT_GPTCTL21_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTCTL2_ADDR(1), _GPT_GPTCTL2_##Field,AND,OR,INV)


/*--------------------- Register: GPTGCTL1 -----------------------*/
#define _GPT_GPTGCTL1_GET(devNum)		  _PREG_GET(_GPT_GPTGCTL1_ADDR(devNum)) 
#define _GPT_GPTGCTL1_SET(devNum,Val)		  _PREG_SET(_GPT_GPTGCTL1_ADDR(devNum),Val)
#define _GPT_GPTGCTL1_FGET(devNum,Field)	  _PFIELD_GET(_GPT_GPTGCTL1_ADDR(devNum), _GPT_GPTGCTL1_##Field)
#define _GPT_GPTGCTL1_FSET(devNum,Field,Val)	  _PFIELD_SET(_GPT_GPTGCTL1_ADDR(devNum), _GPT_GPTGCTL1_##Field, Val)
#define _GPT_GPTGCTL1_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_GPT_GPTGCTL1_ADDR(devNum),AND,OR,INV)
#define _GPT_GPTGCTL1_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTGCTL1_ADDR(devNum),   _GPT_GPTGCTL1_##Field,AND,OR,INV)

#define _GPT_GPTGCTL10_GET		  _PREG_GET(_GPT_GPTGCTL1_ADDR(0)) 
#define _GPT_GPTGCTL10_SET(Val)		  _PREG_SET(_GPT_GPTGCTL1_ADDR(0),Val)
#define _GPT_GPTGCTL10_FGET(Field)	  _PFIELD_GET(_GPT_GPTGCTL1_ADDR(0), _GPT_GPTGCTL1_##Field)
#define _GPT_GPTGCTL10_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTGCTL1_ADDR(0), _GPT_GPTGCTL1_##Field, Val)
#define _GPT_GPTGCTL10_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTGCTL1_ADDR(0),AND,OR,INV)
#define _GPT_GPTGCTL10_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTGCTL1_ADDR(0), _GPT_GPTGCTL1_##Field,AND,OR,INV)

#define _GPT_GPTGCTL11_GET		  _PREG_GET(_GPT_GPTGCTL1_ADDR(1)) 
#define _GPT_GPTGCTL11_SET(Val)		  _PREG_SET(_GPT_GPTGCTL1_ADDR(1),Val)
#define _GPT_GPTGCTL11_FGET(Field)	  _PFIELD_GET(_GPT_GPTGCTL1_ADDR(1), _GPT_GPTGCTL1_##Field)
#define _GPT_GPTGCTL11_FSET(Field,Val)	  _PFIELD_SET(_GPT_GPTGCTL1_ADDR(1), _GPT_GPTGCTL1_##Field, Val)
#define _GPT_GPTGCTL11_AOI(AND,OR,INV)	  _PREG_AOI(_GPT_GPTGCTL1_ADDR(1),AND,OR,INV)
#define _GPT_GPTGCTL11_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPT_GPTGCTL1_ADDR(1), _GPT_GPTGCTL1_##Field,AND,OR,INV)



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the GPTGPINT register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPT_GPTGPINT	 - GPIO interrupt control register
*
* Fields:
*       (RW)   _GPT_GPTGPINT_TIN1INT	  
*       (RW)   _GPT_GPTGPINT_TIN1INV	  

\******************************************************************************/


/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTGPINT_TIN1INT:
\*----------------------------------------------------------------*/

#define _GPT_GPTGPINT_TIN1INT_SHIFT		(000000u)
#define _GPT_GPTGPINT_TIN1INT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPT_GPTGPINT_TIN1INT_SHIFT)
#define _GPT_GPTGPINT_TIN1INT_MASK		(_GPT_GPTGPINT_TIN1INT_MK(0x0001u))
#define _GPT_GPTGPINT_TIN1INT_CLR		(~(_GPT_GPTGPINT_TIN1INT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTGPINT_TIN1INV:
\*----------------------------------------------------------------*/

#define _GPT_GPTGPINT_TIN1INV_SHIFT		(000004u)
#define _GPT_GPTGPINT_TIN1INV_MK(n)		(((Uint16)(n) & 0x0001u) << _GPT_GPTGPINT_TIN1INV_SHIFT)
#define _GPT_GPTGPINT_TIN1INV_MASK		(_GPT_GPTGPINT_TIN1INV_MK(0x0001u))
#define _GPT_GPTGPINT_TIN1INV_CLR		(~(_GPT_GPTGPINT_TIN1INV_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the GPTGPEN register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPT_GPTGPEN	 - GPIO enable register
*
* Fields:
*       (RW)   _GPT_GPTGPEN_TIN1EN
*       (RW)   _GPT_GPTGPEN_TOUT1EN

\******************************************************************************/

/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTGPEN_TIN12EN:	
\*----------------------------------------------------------------*/

#define _GPT_GPTGPEN_TIN1EN_SHIFT		(000000u)
#define _GPT_GPTGPEN_TIN1EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPT_GPTGPEN_TIN1EN_SHIFT)
#define _GPT_GPTGPEN_TIN1EN_MASK		(_GPT_GPTGPEN_TIN1EN_MK(0x0001u))
#define _GPT_GPTGPEN_TIN1EN_CLR		        (~(_GPT_GPTGPEN_TIN1EN_MASK))


/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTGPEN_TOUT1EN:	
\*----------------------------------------------------------------*/

#define _GPT_GPTGPEN_TOUT1EN_SHIFT		(000001u)
#define _GPT_GPTGPEN_TOUT1EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPT_GPTGPEN_TOUT1EN_SHIFT)
#define _GPT_GPTGPEN_TOUT1EN_MASK		(_GPT_GPTGPEN_TOUT1EN_MK(0x0001u))
#define _GPT_GPTGPEN_TOUT1EN_CLR		(~(_GPT_GPTGPEN_TOUT1EN_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the GPTCLK register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPT_GPTCLK	 - Timer clock speed register
*
* Fields:
*	(R)   _GPT_GPTCLK_CLKDIV
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _GPT_GPTCLK_CLKDIV:	
\*----------------------------------------------------------------*/

#define _GPT_GPTCLK_CLKDIV_SHIFT		(000000u)
#define _GPT_GPTCLK_CLKDIV_MK(n)		(((Uint16)(n) & 0x000fu) << _GPT_GPTCLK_CLKDIV_SHIFT)
#define _GPT_GPTCLK_CLKDIV_MASK		        (_GPT_GPTCLK_CLKDIV_MK(0x000fu))
#define _GPT_GPTCLK_CLKDIV_CLR		        (~(_GPT_GPTCLK_CLKDIV_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the GPTGCTL1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPT_GPTGCTL1	 - Note: Add description here
*
* Fields:
*	(RW)   _GPT_GPTGCTL1_TIM12RS	
*	(RW)   _GPT_GPTGCTL1_TIM34RS	
*	(RW)   _GPT_GPTGCTL1_TIMMODE	
*	(RW)   _GPT_GPTGCTL1_PSC34	
*	(R)   _GPT_GPTGCTL1_TDDR34	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTGCTL1_TIM12RS:	
\*----------------------------------------------------------------*/

#define _GPT_GPTGCTL1_TIM12RS_SHIFT		(000000u)
#define _GPT_GPTGCTL1_TIM12RS_MK(n)		(((Uint16)(n) & 0x0001u) << _GPT_GPTGCTL1_TIM12RS_SHIFT)
#define _GPT_GPTGCTL1_TIM12RS_MASK		(_GPT_GPTGCTL1_TIM12RS_MK(0x0001u))
#define _GPT_GPTGCTL1_TIM12RS_CLR		(~(_GPT_GPTGCTL1_TIM12RS_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTGCTL1_TIM34RS:	
\*----------------------------------------------------------------*/

#define _GPT_GPTGCTL1_TIM34RS_SHIFT		(0x0001u)
#define _GPT_GPTGCTL1_TIM34RS_MK(n)		(((Uint16)(n) & 0x0001u) << _GPT_GPTGCTL1_TIM34RS_SHIFT)
#define _GPT_GPTGCTL1_TIM34RS_MASK		(_GPT_GPTGCTL1_TIM34RS_MK(0x0001u))
#define _GPT_GPTGCTL1_TIM34RS_CLR		(~(_GPT_GPTGCTL1_TIM34RS_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTGCTL1_TIMMODE:	
\*----------------------------------------------------------------*/

#define _GPT_GPTGCTL1_TIMMODE_SHIFT		(0x0002u)
#define _GPT_GPTGCTL1_TIMMODE_MK(n)		(((Uint16)(n) & 0x0003u) << _GPT_GPTGCTL1_TIMMODE_SHIFT)
#define _GPT_GPTGCTL1_TIMMODE_MASK		(_GPT_GPTGCTL1_TIMMODE_MK(0x0003u))
#define _GPT_GPTGCTL1_TIMMODE_CLR		(~(_GPT_GPTGCTL1_TIMMODE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTGCTL1_PSC34:	
\*----------------------------------------------------------------*/

#define _GPT_GPTGCTL1_PSC34_SHIFT		(0x0008u)
#define _GPT_GPTGCTL1_PSC34_MK(n)		(((Uint16)(n) & 0x000fu) << _GPT_GPTGCTL1_PSC34_SHIFT)
#define _GPT_GPTGCTL1_PSC34_MASK		(_GPT_GPTGCTL1_PSC34_MK(0x000fu))
#define _GPT_GPTGCTL1_PSC34_CLR		        (~(_GPT_GPTGCTL1_PSC34_MASK))



/*----------------------------------------------------------------*\
*   (R)  _GPT_GPTGCTL1_TDDR34:	
\*----------------------------------------------------------------*/

#define _GPT_GPTGCTL1_TDDR34_SHIFT		(0x000cu)
#define _GPT_GPTGCTL1_TDDR34_MK(n)		(((Uint16)(n) & 0x000fu) << _GPT_GPTGCTL1_TDDR34_SHIFT)
#define _GPT_GPTGCTL1_TDDR34_MASK		(_GPT_GPTGCTL1_TDDR34_MK(0x000fu))
#define _GPT_GPTGCTL1_TDDR34_CLR		(~(_GPT_GPTGCTL1_TDDR34_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the GPTGPDIR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPT_GPTGPDIR	 - GPIO direction register
*
* Fields:
*	(RW)   _GPT_GPTGPDIR_TIN1DIR
*	(RW)   _GPT_GPTGPDIR_TOUT1DIR	

\******************************************************************************/


/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTGPDIR_TIN1DIR:	
\*----------------------------------------------------------------*/

#define _GPT_GPTGPDIR_TIN1DIR_SHIFT		(000000u)
#define _GPT_GPTGPDIR_TIN1DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPT_GPTGPDIR_TIN1DIR_SHIFT)
#define _GPT_GPTGPDIR_TIN1DIR_MASK		(_GPT_GPTGPDIR_TIN1DIR_MK(0x0001u))
#define _GPT_GPTGPDIR_TIN1DIR_CLR		(~(_GPT_GPTGPDIR_TIN1DIR_MASK))


/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTGPDIR_TOUT1DIR:	
\*----------------------------------------------------------------*/

#define _GPT_GPTGPDIR_TOUT1DIR_SHIFT		(000001u)
#define _GPT_GPTGPDIR_TOUT1DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPT_GPTGPDIR_TOUT1DIR_SHIFT)
#define _GPT_GPTGPDIR_TOUT1DIR_MASK		(_GPT_GPTGPDIR_TOUT1DIR_MK(0x0001u))
#define _GPT_GPTGPDIR_TOUT1DIR_CLR		(~(_GPT_GPTGPDIR_TOUT1DIR_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the GPTCTL1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPT_GPTCTL1	 - Timer control register 1
*
* Fields:
*	(R)   _GPT_GPTCTL1_TSTAT	
*	(RW)   _GPT_GPTCTL1_INVOUT	
*	(RW)   _GPT_GPTCTL1_INVIN	
*	(RW)   _GPT_GPTCTL1_CP	
*	(RW)   _GPT_GPTCTL1_PWID	
*	(RW)   _GPT_GPTCTL1_ENAMODE	
*	(RW)   _GPT_GPTCTL1_CLKSRC	
*	(RW)   _GPT_GPTCTL1_TIEN	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _GPT_GPTCTL1_TSTAT:	
\*----------------------------------------------------------------*/

#define _GPT_GPTCTL1_TSTAT_SHIFT		(000000u)
#define _GPT_GPTCTL1_TSTAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPT_GPTCTL1_TSTAT_SHIFT)
#define _GPT_GPTCTL1_TSTAT_MASK		        (_GPT_GPTCTL1_TSTAT_MK(0x0001u))
#define _GPT_GPTCTL1_TSTAT_CLR		        (~(_GPT_GPTCTL1_TSTAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTCTL1_INVOUT:	
\*----------------------------------------------------------------*/

#define _GPT_GPTCTL1_INVOUT_SHIFT		(0x0001u)
#define _GPT_GPTCTL1_INVOUT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPT_GPTCTL1_INVOUT_SHIFT)
#define _GPT_GPTCTL1_INVOUT_MASK		(_GPT_GPTCTL1_INVOUT_MK(0x0001u))
#define _GPT_GPTCTL1_INVOUT_CLR		        (~(_GPT_GPTCTL1_INVOUT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTCTL1_INVIN:	
\*----------------------------------------------------------------*/

#define _GPT_GPTCTL1_INVIN_SHIFT		(0x0002u)
#define _GPT_GPTCTL1_INVIN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPT_GPTCTL1_INVIN_SHIFT)
#define _GPT_GPTCTL1_INVIN_MASK			(_GPT_GPTCTL1_INVIN_MK(0x0001u))
#define _GPT_GPTCTL1_INVIN_CLR			(~(_GPT_GPTCTL1_INVIN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTCTL1_CP:	
\*----------------------------------------------------------------*/

#define _GPT_GPTCTL1_CP_SHIFT			(0x0003u)
#define _GPT_GPTCTL1_CP_MK(n)			(((Uint16)(n) & 0x0001u) << _GPT_GPTCTL1_CP_SHIFT)
#define _GPT_GPTCTL1_CP_MASK			(_GPT_GPTCTL1_CP_MK(0x0001u))
#define _GPT_GPTCTL1_CP_CLR			(~(_GPT_GPTCTL1_CP_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTCTL1_PWID:	
\*----------------------------------------------------------------*/

#define _GPT_GPTCTL1_PWID_SHIFT			(0x0004u)
#define _GPT_GPTCTL1_PWID_MK(n)			(((Uint16)(n) & 0x0003u) << _GPT_GPTCTL1_PWID_SHIFT)
#define _GPT_GPTCTL1_PWID_MASK			(_GPT_GPTCTL1_PWID_MK(0x0003u))
#define _GPT_GPTCTL1_PWID_CLR			(~(_GPT_GPTCTL1_PWID_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTCTL1_ENAMODE:	
\*----------------------------------------------------------------*/

#define _GPT_GPTCTL1_ENAMODE_SHIFT		(0x0006u)
#define _GPT_GPTCTL1_ENAMODE_MK(n)		(((Uint16)(n) & 0x0003u) << _GPT_GPTCTL1_ENAMODE_SHIFT)
#define _GPT_GPTCTL1_ENAMODE_MASK		(_GPT_GPTCTL1_ENAMODE_MK(0x0003u))
#define _GPT_GPTCTL1_ENAMODE_CLR		(~(_GPT_GPTCTL1_ENAMODE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTCTL1_CLKSRC:	
\*----------------------------------------------------------------*/

#define _GPT_GPTCTL1_CLKSRC_SHIFT		(0x0008u)
#define _GPT_GPTCTL1_CLKSRC_MK(n)		(((Uint16)(n) & 0x0001u) << _GPT_GPTCTL1_CLKSRC_SHIFT)
#define _GPT_GPTCTL1_CLKSRC_MASK		(_GPT_GPTCTL1_CLKSRC_MK(0x0001u))
#define _GPT_GPTCTL1_CLKSRC_CLR 		(~(_GPT_GPTCTL1_CLKSRC_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTCTL1_TIEN:	
\*----------------------------------------------------------------*/

#define _GPT_GPTCTL1_TIEN_SHIFT			(0x0009u)
#define _GPT_GPTCTL1_TIEN_MK(n)			(((Uint16)(n) & 0x0001u) << _GPT_GPTCTL1_TIEN_SHIFT)
#define _GPT_GPTCTL1_TIEN_MASK			(_GPT_GPTCTL1_TIEN_MK(0x0001u))
#define _GPT_GPTCTL1_TIEN_CLR			(~(_GPT_GPTCTL1_TIEN_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the GPTCTL2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPT_GPTCTL2	 - Timer control register 2
*
* Fields:
*	(R)    _GPT_GPTCTL2_TSTAT	
*	(RW)   _GPT_GPTCTL2_INVOUT	
*	(RW)   _GPT_GPTCTL2_INVIN	
*	(RW)   _GPT_GPTCTL2_CP	
*	(RW)   _GPT_GPTCTL2_PWID	
*	(RW)   _GPT_GPTCTL2_ENAMODE	
*	(RW)   _GPT_GPTCTL2_CLKSRC	
*	(RW)   _GPT_GPTCTL2_TIEN	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _GPT_GPTCTL2_TSTAT:	
\*----------------------------------------------------------------*/

#define _GPT_GPTCTL2_TSTAT_SHIFT		(000000u)
#define _GPT_GPTCTL2_TSTAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPT_GPTCTL2_TSTAT_SHIFT)
#define _GPT_GPTCTL2_TSTAT_MASK		        (_GPT_GPTCTL2_TSTAT_MK(0x0001u))
#define _GPT_GPTCTL2_TSTAT_CLR		        (~(_GPT_GPTCTL2_TSTAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTCTL2_INVOUT:	
\*----------------------------------------------------------------*/

#define _GPT_GPTCTL2_INVOUT_SHIFT		(0x0001u)
#define _GPT_GPTCTL2_INVOUT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPT_GPTCTL2_INVOUT_SHIFT)
#define _GPT_GPTCTL2_INVOUT_MASK		(_GPT_GPTCTL2_INVOUT_MK(0x0001u))
#define _GPT_GPTCTL2_INVOUT_CLR		        (~(_GPT_GPTCTL2_INVOUT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTCTL2_INVIN:	
\*----------------------------------------------------------------*/

#define _GPT_GPTCTL2_INVIN_SHIFT		(0x0002u)
#define _GPT_GPTCTL2_INVIN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPT_GPTCTL2_INVIN_SHIFT)
#define _GPT_GPTCTL2_INVIN_MASK			(_GPT_GPTCTL2_INVIN_MK(0x0001u))
#define _GPT_GPTCTL2_INVIN_CLR			(~(_GPT_GPTCTL2_INVIN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTCTL2_CP:	
\*----------------------------------------------------------------*/

#define _GPT_GPTCTL2_CP_SHIFT			(0x0003u)
#define _GPT_GPTCTL2_CP_MK(n)			(((Uint16)(n) & 0x0001u) << _GPT_GPTCTL2_CP_SHIFT)
#define _GPT_GPTCTL2_CP_MASK			(_GPT_GPTCTL2_CP_MK(0x0001u))
#define _GPT_GPTCTL2_CP_CLR			(~(_GPT_GPTCTL2_CP_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTCTL2_PWID:	
\*----------------------------------------------------------------*/

#define _GPT_GPTCTL2_PWID_SHIFT			(0x0004u)
#define _GPT_GPTCTL2_PWID_MK(n)			(((Uint16)(n) & 0x0003u) << _GPT_GPTCTL2_PWID_SHIFT)
#define _GPT_GPTCTL2_PWID_MASK			(_GPT_GPTCTL2_PWID_MK(0x0003u))
#define _GPT_GPTCTL2_PWID_CLR			(~(_GPT_GPTCTL2_PWID_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTCTL2_ENAMODE:	
\*----------------------------------------------------------------*/

#define _GPT_GPTCTL2_ENAMODE_SHIFT		(0x0006u)
#define _GPT_GPTCTL2_ENAMODE_MK(n)		(((Uint16)(n) & 0x0003u) << _GPT_GPTCTL2_ENAMODE_SHIFT)
#define _GPT_GPTCTL2_ENAMODE_MASK		(_GPT_GPTCTL2_ENAMODE_MK(0x0003u))
#define _GPT_GPTCTL2_ENAMODE_CLR		(~(_GPT_GPTCTL2_ENAMODE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTCTL2_CLKSRC:	
\*----------------------------------------------------------------*/

#define _GPT_GPTCTL2_CLKSRC_SHIFT		(0x0008u)
#define _GPT_GPTCTL2_CLKSRC_MK(n)		(((Uint16)(n) & 0x0001u) << _GPT_GPTCTL2_CLKSRC_SHIFT)
#define _GPT_GPTCTL2_CLKSRC_MASK		(_GPT_GPTCTL2_CLKSRC_MK(0x0001u))
#define _GPT_GPTCTL2_CLKSRC_CLR 		(~(_GPT_GPTCTL2_CLKSRC_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTCTL2_TIEN:	
\*----------------------------------------------------------------*/

#define _GPT_GPTCTL2_TIEN_SHIFT			(0x0009u)
#define _GPT_GPTCTL2_TIEN_MK(n)			(((Uint16)(n) & 0x0001u) << _GPT_GPTCTL2_TIEN_SHIFT)
#define _GPT_GPTCTL2_TIEN_MASK			(_GPT_GPTCTL2_TIEN_MK(0x0001u))
#define _GPT_GPTCTL2_TIEN_CLR			(~(_GPT_GPTCTL2_TIEN_MASK))


/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the GPTCNT1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPT_GPTCNT1	 - Timer count register 1
*
* Fields:
*	(RW)   _GPT_GPTCNT1_CNT1	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTCNT1_CNT1:	
\*----------------------------------------------------------------*/

#define _GPT_GPTCNT1_CNT1_SHIFT		(000000u)
#define _GPT_GPTCNT1_CNT1_MK(n)		(((Uint16)(n) & 0xffffu) << _GPT_GPTCNT1_CNT1_SHIFT)
#define _GPT_GPTCNT1_CNT1_MASK		(_GPT_GPTCNT1_CNT1_MK(0xffffu))
#define _GPT_GPTCNT1_CNT1_CLR		(~(_GPT_GPTCNT1_CNT1_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the GPTPRD1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPT_GPTPRD1	 - Note: Add description here
*
* Fields:
*	(RW)   _GPT_GPTPRD1_PRD1	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTPRD1_PRD1:	
\*----------------------------------------------------------------*/

#define _GPT_GPTPRD1_PRD1_SHIFT		(000000u)
#define _GPT_GPTPRD1_PRD1_MK(n)		(((Uint16)(n) & 0xffffu) << _GPT_GPTPRD1_PRD1_SHIFT)
#define _GPT_GPTPRD1_PRD1_MASK		(_GPT_GPTPRD1_PRD1_MK(0xffffu))
#define _GPT_GPTPRD1_PRD1_CLR		(~(_GPT_GPTPRD1_PRD1_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the GPTCNT2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPT_GPTCNT2	 - Timer count register 2
*
* Fields:
*	(RW)   _GPT_GPTCNT2_CNT2	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTCNT2_CNT2:	
\*----------------------------------------------------------------*/

#define _GPT_GPTCNT2_CNT2_SHIFT		(000000u)
#define _GPT_GPTCNT2_CNT2_MK(n)		(((Uint16)(n) & 0xffffu) << _GPT_GPTCNT2_CNT2_SHIFT)
#define _GPT_GPTCNT2_CNT2_MASK		(_GPT_GPTCNT2_CNT2_MK(0xffffu))
#define _GPT_GPTCNT2_CNT2_CLR		(~(_GPT_GPTCNT2_CNT2_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the GPTPRD2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPT_GPTPRD2	 - Note: Add description here
*
* Fields:
*	(RW)   _GPT_GPTPRD2_PRD2	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTPRD2_PRD2:	
\*----------------------------------------------------------------*/

#define _GPT_GPTPRD2_PRD2_SHIFT		(000000u)
#define _GPT_GPTPRD2_PRD2_MK(n)		(((Uint16)(n) & 0xffffu) << _GPT_GPTPRD2_PRD2_SHIFT)
#define _GPT_GPTPRD2_PRD2_MASK		(_GPT_GPTPRD2_PRD2_MK(0xffffu))
#define _GPT_GPTPRD2_PRD2_CLR		(~(_GPT_GPTPRD2_PRD2_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the GPTEMU register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPT_GPTEMU	 - Emulation management register
*
* Fields:
*	(R)   _GPT_GPTEMU_FREE
        (R)   _GPT_GPTEMU_SOFT 	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _GPT_GPTEMU_FREE:	
\*----------------------------------------------------------------*/

#define _GPT_GPTEMU_FREE_SHIFT		(000000u)
#define _GPT_GPTEMU_FREE_MK(n)		(((Uint16)(n) & 0x0001u) << _GPT_GPTEMU_FREE_SHIFT)
#define _GPT_GPTEMU_FREE_MASK		(_GPT_GPTEMU_FREE_MK(0x0001u))
#define _GPT_GPTEMU_FREE_CLR		(~(_GPT_GPTEMU_FREE_MASK))

/*----------------------------------------------------------------*\
*   (R)  _GPT_GPTEMU_SOFT:	
\*----------------------------------------------------------------*/

#define _GPT_GPTEMU_SOFT_SHIFT		(000001u)
#define _GPT_GPTEMU_SOFT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPT_GPTEMU_SOFT_SHIFT)
#define _GPT_GPTEMU_SOFT_MASK		(_GPT_GPTEMU_SOFT_MK(0x0001u))
#define _GPT_GPTEMU_SOFT_CLR		(~(_GPT_GPTEMU_SOFT_MASK))





/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the GPTCNT3 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPT_GPTCNT3	 - Timer count register 3
*
* Fields:
*	(RW)   _GPT_GPTCNT3_CNT3	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTCNT3_CNT3:	
\*----------------------------------------------------------------*/

#define _GPT_GPTCNT3_CNT3_SHIFT		(000000u)
#define _GPT_GPTCNT3_CNT3_MK(n)		(((Uint16)(n) & 0xffffu) << _GPT_GPTCNT3_CNT3_SHIFT)
#define _GPT_GPTCNT3_CNT3_MASK		(_GPT_GPTCNT3_CNT3_MK(0xffffu))
#define _GPT_GPTCNT3_CNT3_CLR		(~(_GPT_GPTCNT3_CNT3_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the GPTPRD3 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPT_GPTPRD3	 - Note: Add description here
*
* Fields:
*	(RW)   _GPT_GPTPRD3_PRD3	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTPRD3_PRD3:	
\*----------------------------------------------------------------*/

#define _GPT_GPTPRD3_PRD3_SHIFT		(000000u)
#define _GPT_GPTPRD3_PRD3_MK(n)		(((Uint16)(n) & 0xffffu) << _GPT_GPTPRD3_PRD3_SHIFT)
#define _GPT_GPTPRD3_PRD3_MASK		(_GPT_GPTPRD3_PRD3_MK(0xffffu))
#define _GPT_GPTPRD3_PRD3_CLR		(~(_GPT_GPTPRD3_PRD3_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the GPTCNT4 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPT_GPTCNT4	 - Timer count register 4
*
* Fields:
*	(R)   _GPT_GPTCNT4_CNT4	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _GPT_GPTCNT4_CNT4:	
\*----------------------------------------------------------------*/

#define _GPT_GPTCNT4_CNT4_SHIFT		(000000u)
#define _GPT_GPTCNT4_CNT4_MK(n)		(((Uint16)(n) & 0xffffu) << _GPT_GPTCNT4_CNT4_SHIFT)
#define _GPT_GPTCNT4_CNT4_MASK		(_GPT_GPTCNT4_CNT4_MK(0xffffu))
#define _GPT_GPTCNT4_CNT4_CLR		(~(_GPT_GPTCNT4_CNT4_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the GPTPRD4 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPT_GPTPRD4	 - Note: Add description here
*
* Fields:
*	(RW)   _GPT_GPTPRD4_PRD4	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTPRD4_PRD4:	
\*----------------------------------------------------------------*/

#define _GPT_GPTPRD4_PRD4_SHIFT		(000000u)
#define _GPT_GPTPRD4_PRD4_MK(n)		(((Uint16)(n) & 0xffffu) << _GPT_GPTPRD4_PRD4_SHIFT)
#define _GPT_GPTPRD4_PRD4_MASK		(_GPT_GPTPRD4_PRD4_MK(0xffffu))
#define _GPT_GPTPRD4_PRD4_CLR		(~(_GPT_GPTPRD4_PRD4_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the GPTGPDAT register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPT_GPTGPDAT	 - GPIO data register
*
* Fields:
*	(RW)   _GPT_GPTGPDAT_TIN1DAT	
*	(RW)   _GPT_GPTGPDAT_TOUT1DAT	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTGPDAT_TIN1DAT:	
\*----------------------------------------------------------------*/

#define _GPT_GPTGPDAT_TIN1DAT_SHIFT		(000000u)
#define _GPT_GPTGPDAT_TIN1DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPT_GPTGPDAT_TIN1DAT_SHIFT)
#define _GPT_GPTGPDAT_TIN1DAT_MASK		(_GPT_GPTGPDAT_TIN1DAT_MK(0x0001u))
#define _GPT_GPTGPDAT_TIN1DAT_CLR		(~(_GPT_GPTGPDAT_TIN1DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPT_GPTGPDAT_TOUT1DAT:	
\*----------------------------------------------------------------*/

#define _GPT_GPTGPDAT_TOUT1DAT_SHIFT		(000001u)
#define _GPT_GPTGPDAT_TOUT1DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPT_GPTGPDAT_TOUT1DAT_SHIFT)
#define _GPT_GPTGPDAT_TOUT1DAT_MASK		(_GPT_GPTGPDAT_TOUT1DAT_MK(0x0001u))
#define _GPT_GPTGPDAT_TOUT1DAT_CLR		(~(_GPT_GPTGPDAT_TOUT1DAT_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the GPTPID1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPT_GPTPID1	 - Note: Add description here
*
* Fields:
*	(R)   _GPT_GPTPID1_REVISION	
*	(R)   _GPT_GPTPID1_CLASS	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _GPT_GPTPID1_REVISION:	
\*----------------------------------------------------------------*/

#define _GPT_GPTPID1_REVISION_SHIFT		(000000u)
#define _GPT_GPTPID1_REVISION_MK(n)		(((Uint16)(n) & 0x00ffu) << _GPT_GPTPID1_REVISION_SHIFT)
#define _GPT_GPTPID1_REVISION_MASK		(_GPT_GPTPID1_REVISION_MK(0x00ffu))
#define _GPT_GPTPID1_REVISION_CLR		(~(_GPT_GPTPID1_REVISION_MASK))



/*----------------------------------------------------------------*\
*   (R)  _GPT_GPTPID1_CLASS:	
\*----------------------------------------------------------------*/

#define _GPT_GPTPID1_CLASS_SHIFT		(0x0008u)
#define _GPT_GPTPID1_CLASS_MK(n)		(((Uint16)(n) & 0x00ffu) << _GPT_GPTPID1_CLASS_SHIFT)
#define _GPT_GPTPID1_CLASS_MASK		(_GPT_GPTPID1_CLASS_MK(0x00ffu))
#define _GPT_GPTPID1_CLASS_CLR		(~(_GPT_GPTPID1_CLASS_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the GPTPID2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPT_GPTPID2	 - Note: Add description here
*
* Fields:
*	(R)   _GPT_GPTPID2_TYPE	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _GPT_GPTPID2_TYPE:	
\*----------------------------------------------------------------*/

#define _GPT_GPTPID2_TYPE_SHIFT		(000000u)
#define _GPT_GPTPID2_TYPE_MK(n)		(((Uint16)(n) & 0x007fu) << _GPT_GPTPID2_TYPE_SHIFT)
#define _GPT_GPTPID2_TYPE_MASK		(_GPT_GPTPID2_TYPE_MK(0x007fu))
#define _GPT_GPTPID2_TYPE_CLR		(~(_GPT_GPTPID2_TYPE_MASK))


#else
    #ifndef _GPT_MOD_
	  #error GPT Hal Module Not Supported on Specified Target
    #endif
#endif  /* _GPT_SUPPORT  */

#endif  /* _CSL_GPTHAL_H  */

/******************************************************************************\
*     
*      End of csl_gpthal.h 
*
\******************************************************************************/
