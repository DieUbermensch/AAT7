/****************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved 
*------------------------------------------------------------------------------
* MODULE NAME... MMC
* FILENAME...... csl_mmchal.h
* DATE CREATED.. Thu May 24 14:48:09 2001
* PROJECT....... Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS.. 
*------------------------------------------------------------------------------
*
* HISTORY:
*	 Created:		Thu May 24 14:48:09 2001 (Automatic generation)
*	 Modified:	      Wed April 9 2003 Updated register names as per SPSR163D
*
*------------------------------------------------------------------------------
* DESCRIPTION: CSL HAL interface file for the MMC module 
*
* Registers covered:
*
* 		 Note: Add registers description here
*	 MMCCTL		- 
*	 MMCFCLK
*	 MMCCLK		- 
*	 MMCIE
*	 MMCTOR		- 
*	 MMCTOD		- 
*	 MMCBLEN		- 
*	 MMCNBLK		- 
*	 MMCST0		- 
*	 MMCST1		- 
*	 MMCNBLC		- 
*	 MMCDRR		- 
*	 MMCDXR		- 
*	 MMCCMD		- 
*	 MMCARGL		- 
*	 MMCARGH		- 
*	 MMCRSP0		- 
*	 MMCRSP0		- 
*	 MMCRSP1		- 
*	 MMCRSP2		- 
*	 MMCRSP3		- 
*	 MMCRSP4		- 
*	 MMCRSP5		- 
*	 MMCRSP6		- 
*	 MMCRSP7		- 
*	 MMCDRSP		- 
*	 MMCCIDX		- 
*
\*************************************************************************/

#ifndef _CSL_MMCHAL_H_
#define _CSL_MMCHAL_H_

#include <csl_chiphal.h>

#if (_MMC_SUPPORT) 

/*----------------------------------------------------------------*\
*	 MMC scope and inline control macros 			
\*----------------------------------------------------------------*/

#ifdef __cplusplus
#define CSLAPI extern "C"
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _MMC_MOD_
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

#define _MMC_BASE_ADDR		(0x4800)


/*--------------------- Register: MMCCTL -----------------------*/
#define _MMC_MMCCTL0_ADDR		 _MMC_MMCCTL_ADDR(0)
#define _MMC_MMCCTL0			PREG16(_MMC_MMCCTL0_ADDR)
#define MMCCTL0				_MMC_MMCCTL0

#define _MMC_MMCCTL1_ADDR		 _MMC_MMCCTL_ADDR(1)
#define _MMC_MMCCTL1			PREG16(_MMC_MMCCTL1_ADDR)
#define MMCCTL1				_MMC_MMCCTL1

#define _MMC_MMCCTL_BASE			 (0x4801)
#define _MMC_MMCCTL_ADDR(n)		 (_MMC_MMCCTL_BASE + ((n)*0x400))
#define _MMC_MMCCTL(n)			 PREG16(_MMC_MMCCTL_ADDR(n))
#define _MMC_MMCCTL_ADDR_H(devNum)	 _MMC_MMCCTL_ADDR(devNum)

/*--------------------- Register: MMCFCLK -----------------------*/
#define _MMC_MMCFCLK0_ADDR		 _MMC_MMCFCLK_ADDR(0)
#define _MMC_MMCFCLK0			PREG16(_MMC_MMCFCLK0_ADDR)
#define MMCFCLK0				_MMC_MMCFCLK0

#define _MMC_MMCFCLK1_ADDR		 _MMC_MMCFCLK_ADDR(1)
#define _MMC_MMCFCLK1			PREG16(_MMC_MMCFCLK1_ADDR)
#define MMCFCLK1				_MMC_MMCFCLK1

#define _MMC_MMCFCLK_BASE			 (0x4800)
#define _MMC_MMCFCLK_ADDR(n)		 (_MMC_MMCFCLK_BASE + ((n)*0x400))
#define _MMC_MMCFCLK(n)			 PREG16(_MMC_MMCFCLK_ADDR(n))
#define _MMC_MMCFCLK_ADDR_H(devNum)	 _MMC_MMCFCLK_ADDR(devNum)

/*--------------------- Register: MMCCLK -----------------------*/
#define _MMC_MMCCLK0_ADDR		 _MMC_MMCCLK_ADDR(0)
#define _MMC_MMCCLK0			PREG16(_MMC_MMCCLK0_ADDR)
#define MMCCLK0				_MMC_MMCCLK0

#define _MMC_MMCCLK1_ADDR		 _MMC_MMCCLK_ADDR(1)
#define _MMC_MMCCLK1			PREG16(_MMC_MMCCLK1_ADDR)
#define MMCCLK1				_MMC_MMCCLK1

#define _MMC_MMCCLK_BASE			 (0x4802)
#define _MMC_MMCCLK_ADDR(n)		 (_MMC_MMCCLK_BASE + ((n)*0x400))
#define _MMC_MMCCLK(n)			 PREG16(_MMC_MMCCLK_ADDR(n))
#define _MMC_MMCCLK_ADDR_H(devNum)	 _MMC_MMCCLK_ADDR(devNum)




/*--------------------- Register: MMCIE -----------------------*/
#define _MMC_MMCIE0_ADDR		 _MMC_MMCIE_ADDR(0)
#define _MMC_MMCIE0			PREG16(_MMC_MMCIE0_ADDR)
#define MMCIE0				_MMC_MMCIE0

#define _MMC_MMCIE1_ADDR		 _MMC_MMCIE_ADDR(1)
#define _MMC_MMCIE1			PREG16(_MMC_MMCIE1_ADDR)
#define MMCIE1				_MMC_MMCIE1

#define _MMC_MMCIE_BASE			 (0x4805)
#define _MMC_MMCIE_ADDR(n)		 (_MMC_MMCIE_BASE + ((n)*0x400))
#define _MMC_MMCIE(n)			 PREG16(_MMC_MMCIE_ADDR(n))
#define _MMC_MMCIE_ADDR_H(devNum)	 _MMC_MMCIE_ADDR(devNum)


/*--------------------- Register: MMCTOR -----------------------*/
#define _MMC_MMCTOR0_ADDR		 _MMC_MMCTOR_ADDR(0)
#define _MMC_MMCTOR0			PREG16(_MMC_MMCTOR0_ADDR)
#define MMCTOR0				_MMC_MMCTOR0

#define _MMC_MMCTOR1_ADDR		 _MMC_MMCTOR_ADDR(1)
#define _MMC_MMCTOR1			PREG16(_MMC_MMCTOR1_ADDR)
#define MMCTOR1				_MMC_MMCTOR1

#define _MMC_MMCTOR_BASE			 (0x4806)
#define _MMC_MMCTOR_ADDR(n)		 (_MMC_MMCTOR_BASE + ((n)*0x400))
#define _MMC_MMCTOR(n)			 PREG16(_MMC_MMCTOR_ADDR(n))
#define _MMC_MMCTOR_ADDR_H(devNum)	 _MMC_MMCTOR_ADDR(devNum)

/*--------------------- Register: MMCTOD -----------------------*/
#define _MMC_MMCTOD0_ADDR		 _MMC_MMCTOD_ADDR(0)
#define _MMC_MMCTOD0			PREG16(_MMC_MMCTOD0_ADDR)
#define MMCTOD0				_MMC_MMCTOD0

#define _MMC_MMCTOD1_ADDR		 _MMC_MMCTOD_ADDR(1)
#define _MMC_MMCTOD1			PREG16(_MMC_MMCTOD1_ADDR)
#define MMCTOD1				_MMC_MMCTOD1

#define _MMC_MMCTOD_BASE			 (0x4807)
#define _MMC_MMCTOD_ADDR(n)		 (_MMC_MMCTOD_BASE + ((n)*0x400))
#define _MMC_MMCTOD(n)			 PREG16(_MMC_MMCTOD_ADDR(n))
#define _MMC_MMCTOD_ADDR_H(devNum)	 _MMC_MMCTOD_ADDR(devNum)

/*--------------------- Register: MMCBLEN -----------------------*/
#define _MMC_MMCBLEN0_ADDR		 _MMC_MMCBLEN_ADDR(0)
#define _MMC_MMCBLEN0			PREG16(_MMC_MMCBLEN0_ADDR)
#define MMCBLEN0				_MMC_MMCBLEN0

#define _MMC_MMCBLEN1_ADDR		 _MMC_MMCBLEN_ADDR(1)
#define _MMC_MMCBLEN1			PREG16(_MMC_MMCBLEN1_ADDR)
#define MMCBLEN1				_MMC_MMCBLEN1

#define _MMC_MMCBLEN_BASE			 (0x4808)
#define _MMC_MMCBLEN_ADDR(n)		 (_MMC_MMCBLEN_BASE + ((n)*0x400))
#define _MMC_MMCBLEN(n)			 PREG16(_MMC_MMCBLEN_ADDR(n))
#define _MMC_MMCBLEN_ADDR_H(devNum)	 _MMC_MMCBLEN_ADDR(devNum)

/*--------------------- Register: MMCNBLK -----------------------*/
#define _MMC_MMCNBLK0_ADDR		 _MMC_MMCNBLK_ADDR(0)
#define _MMC_MMCNBLK0			PREG16(_MMC_MMCNBLK0_ADDR)
#define MMCNBLK0				_MMC_MMCNBLK0

#define _MMC_MMCNBLK1_ADDR		 _MMC_MMCNBLK_ADDR(1)
#define _MMC_MMCNBLK1			PREG16(_MMC_MMCNBLK1_ADDR)
#define MMCNBLK1				_MMC_MMCNBLK1

#define _MMC_MMCNBLK_BASE			 (0x4809)
#define _MMC_MMCNBLK_ADDR(n)		 (_MMC_MMCNBLK_BASE + ((n)*0x400))
#define _MMC_MMCNBLK(n)			 PREG16(_MMC_MMCNBLK_ADDR(n))
#define _MMC_MMCNBLK_ADDR_H(devNum)	 _MMC_MMCNBLK_ADDR(devNum)

/*--------------------- Register: MMCST0 -----------------------*/
#define _MMC_MMCST00_ADDR		 _MMC_MMCST0_ADDR(0)
#define _MMC_MMCST00			PREG16(_MMC_MMCST00_ADDR)
#define MMCST00				_MMC_MMCST00

#define _MMC_MMCST01_ADDR		 _MMC_MMCST0_ADDR(1)
#define _MMC_MMCST01			PREG16(_MMC_MMCST01_ADDR)
#define MMCST01				_MMC_MMCST01

#define _MMC_MMCST0_BASE			 (0x4803)
#define _MMC_MMCST0_ADDR(n)		 (_MMC_MMCST0_BASE + ((n)*0x400))
#define _MMC_MMCST0(n)			 PREG16(_MMC_MMCST0_ADDR(n))
#define _MMC_MMCST0_ADDR_H(devNum)	 _MMC_MMCST0_ADDR(devNum)

/*--------------------- Register: MMCST1 -----------------------*/
#define _MMC_MMCST10_ADDR		 _MMC_MMCST1_ADDR(0)
#define _MMC_MMCST10			PREG16(_MMC_MMCST10_ADDR)
#define MMCST10				_MMC_MMCST10

#define _MMC_MMCST11_ADDR		 _MMC_MMCST1_ADDR(1)
#define _MMC_MMCST11			PREG16(_MMC_MMCST11_ADDR)
#define MMCST11				_MMC_MMCST11

#define _MMC_MMCST1_BASE			 (0x4804)
#define _MMC_MMCST1_ADDR(n)		 (_MMC_MMCST1_BASE + ((n)*0x400))
#define _MMC_MMCST1(n)			 PREG16(_MMC_MMCST1_ADDR(n))
#define _MMC_MMCST1_ADDR_H(devNum)	 _MMC_MMCST1_ADDR(devNum)

/*--------------------- Register: MMCNBLC -----------------------*/
#define _MMC_MMCNBLC0_ADDR		 _MMC_MMCNBLC_ADDR(0)
#define _MMC_MMCNBLC0			PREG16(_MMC_MMCNBLC0_ADDR)
#define MMCNBLC0				_MMC_MMCNBLC0

#define _MMC_MMCNBLC1_ADDR		 _MMC_MMCNBLC_ADDR(1)
#define _MMC_MMCNBLC1			PREG16(_MMC_MMCNBLC1_ADDR)
#define MMCNBLC1				_MMC_MMCNBLC1

#define _MMC_MMCNBLC_BASE			 (0x480A)
#define _MMC_MMCNBLC_ADDR(n)		 (_MMC_MMCNBLC_BASE + ((n)*0x400))
#define _MMC_MMCNBLC(n)			 PREG16(_MMC_MMCNBLC_ADDR(n))
#define _MMC_MMCNBLC_ADDR_H(devNum)	 _MMC_MMCNBLC_ADDR(devNum)

/*--------------------- Register: MMCDRR -----------------------*/
#define _MMC_MMCDRR0_ADDR		 _MMC_MMCDRR_ADDR(0)
#define _MMC_MMCDRR0			PREG16(_MMC_MMCDRR0_ADDR)
#define MMCDRR0				_MMC_MMCDRR0

#define _MMC_MMCDRR1_ADDR		 _MMC_MMCDRR_ADDR(1)
#define _MMC_MMCDRR1			PREG16(_MMC_MMCDRR1_ADDR)
#define MMCDRR1				_MMC_MMCDRR1

#define _MMC_MMCDRR_BASE			 (0x480B)
#define _MMC_MMCDRR_ADDR(n)		 (_MMC_MMCDRR_BASE + ((n)*0x400))
#define _MMC_MMCDRR(n)			 PREG16(_MMC_MMCDRR_ADDR(n))
#define _MMC_MMCDRR_ADDR_H(devNum)	 _MMC_MMCDRR_ADDR(devNum)

/*--------------------- Register: MMCDXR -----------------------*/
#define _MMC_MMCDXR0_ADDR		 _MMC_MMCDXR_ADDR(0)
#define _MMC_MMCDXR0			PREG16(_MMC_MMCDXR0_ADDR)
#define MMCDXR0				_MMC_MMCDXR0

#define _MMC_MMCDXR1_ADDR		 _MMC_MMCDXR_ADDR(1)
#define _MMC_MMCDXR1			PREG16(_MMC_MMCDXR1_ADDR)
#define MMCDXR1				_MMC_MMCDXR1

#define _MMC_MMCDXR_BASE			 (0x480C)
#define _MMC_MMCDXR_ADDR(n)		 (_MMC_MMCDXR_BASE + ((n)*0x400))
#define _MMC_MMCDXR(n)			 PREG16(_MMC_MMCDXR_ADDR(n))
#define _MMC_MMCDXR_ADDR_H(devNum)	 _MMC_MMCDXR_ADDR(devNum)

/*--------------------- Register: MMCCMD -----------------------*/
#define _MMC_MMCCMD0_ADDR		 _MMC_MMCCMD_ADDR(0)
#define _MMC_MMCCMD0			PREG16(_MMC_MMCCMD0_ADDR)
#define MMCCMD0				_MMC_MMCCMD0

#define _MMC_MMCCMD1_ADDR		 _MMC_MMCCMD_ADDR(1)
#define _MMC_MMCCMD1			PREG16(_MMC_MMCCMD1_ADDR)
#define MMCCMD1				_MMC_MMCCMD1

#define _MMC_MMCCMD_BASE			 (0x480D)
#define _MMC_MMCCMD_ADDR(n)		 (_MMC_MMCCMD_BASE + ((n)*0x400))
#define _MMC_MMCCMD(n)			 PREG16(_MMC_MMCCMD_ADDR(n))
#define _MMC_MMCCMD_ADDR_H(devNum)	 _MMC_MMCCMD_ADDR(devNum)

/*--------------------- Register: MMCARGL -----------------------*/
#define _MMC_MMCARGL0_ADDR		 _MMC_MMCARGL_ADDR(0)
#define _MMC_MMCARGL0			PREG16(_MMC_MMCARGL0_ADDR)
#define MMCARGL0				_MMC_MMCARGL0

#define _MMC_MMCARGL1_ADDR		 _MMC_MMCARGL_ADDR(1)
#define _MMC_MMCARGL1			PREG16(_MMC_MMCARGL1_ADDR)
#define MMCARGL1				_MMC_MMCARGL1

#define _MMC_MMCARGL_BASE			 (0x480E)
#define _MMC_MMCARGL_ADDR(n)		 (_MMC_MMCARGL_BASE + ((n)*0x400))
#define _MMC_MMCARGL(n)			 PREG16(_MMC_MMCARGL_ADDR(n))
#define _MMC_MMCARGL_ADDR_H(devNum)	 _MMC_MMCARGL_ADDR(devNum)

/*--------------------- Register: MMCARGH -----------------------*/
#define _MMC_MMCARGH0_ADDR		 _MMC_MMCARGH_ADDR(0)
#define _MMC_MMCARGH0			PREG16(_MMC_MMCARGH0_ADDR)
#define MMCARGH0				_MMC_MMCARGH0

#define _MMC_MMCARGH1_ADDR		 _MMC_MMCARGH_ADDR(1)
#define _MMC_MMCARGH1			PREG16(_MMC_MMCARGH1_ADDR)
#define MMCARGH1				_MMC_MMCARGH1

#define _MMC_MMCARGH_BASE			 (0x480F)
#define _MMC_MMCARGH_ADDR(n)		 (_MMC_MMCARGH_BASE + ((n)*0x400))
#define _MMC_MMCARGH(n)			 PREG16(_MMC_MMCARGH_ADDR(n))
#define _MMC_MMCARGH_ADDR_H(devNum)	 _MMC_MMCARGH_ADDR(devNum)

/*--------------------- Register: MMCRSP0 -----------------------*/
#define _MMC_MMCRSP00_ADDR		 _MMC_MMCRSP0_ADDR(0)
#define _MMC_MMCRSP00			PREG16(_MMC_MMCRSP00_ADDR)
#define MMCRSP00				_MMC_MMCRSP00

#define _MMC_MMCRSP01_ADDR		 _MMC_MMCRSP0_ADDR(1)
#define _MMC_MMCRSP01			PREG16(_MMC_MMCRSP01_ADDR)
#define MMCRSP01				_MMC_MMCRSP01

#define _MMC_MMCRSP0_BASE			 (0x4810)
#define _MMC_MMCRSP0_ADDR(n)		 (_MMC_MMCRSP0_BASE + ((n)*0x400))
#define _MMC_MMCRSP0(n)			 PREG16(_MMC_MMCRSP0_ADDR(n))
#define _MMC_MMCRSP0_ADDR_H(devNum)	 _MMC_MMCRSP0_ADDR(devNum)

/*--------------------- Register: MMCRSP0 -----------------------*/
#define _MMC_MMCRSP00_ADDR		 _MMC_MMCRSP0_ADDR(0)
#define _MMC_MMCRSP00			PREG16(_MMC_MMCRSP00_ADDR)
#define MMCRSP00				_MMC_MMCRSP00

#define _MMC_MMCRSP01_ADDR		 _MMC_MMCRSP0_ADDR(1)
#define _MMC_MMCRSP01			PREG16(_MMC_MMCRSP01_ADDR)
#define MMCRSP01				_MMC_MMCRSP01

#define _MMC_MMCRSP0_BASE			 (0x4810)
#define _MMC_MMCRSP0_ADDR(n)		 (_MMC_MMCRSP0_BASE + ((n)*0x400))
#define _MMC_MMCRSP0(n)			 PREG16(_MMC_MMCRSP0_ADDR(n))
#define _MMC_MMCRSP0_ADDR_H(devNum)	 _MMC_MMCRSP0_ADDR(devNum)

/*--------------------- Register: MMCRSP1 -----------------------*/
#define _MMC_MMCRSP10_ADDR		 _MMC_MMCRSP1_ADDR(0)
#define _MMC_MMCRSP10			PREG16(_MMC_MMCRSP10_ADDR)
#define MMCRSP10				_MMC_MMCRSP10

#define _MMC_MMCRSP11_ADDR		 _MMC_MMCRSP1_ADDR(1)
#define _MMC_MMCRSP11			PREG16(_MMC_MMCRSP11_ADDR)
#define MMCRSP11				_MMC_MMCRSP11

#define _MMC_MMCRSP1_BASE			 (0x4811)
#define _MMC_MMCRSP1_ADDR(n)		 (_MMC_MMCRSP1_BASE + ((n)*0x400))
#define _MMC_MMCRSP1(n)			 PREG16(_MMC_MMCRSP1_ADDR(n))
#define _MMC_MMCRSP1_ADDR_H(devNum)	 _MMC_MMCRSP1_ADDR(devNum)

/*--------------------- Register: MMCRSP2 -----------------------*/
#define _MMC_MMCRSP20_ADDR		 _MMC_MMCRSP2_ADDR(0)
#define _MMC_MMCRSP20			PREG16(_MMC_MMCRSP20_ADDR)
#define MMCRSP20				_MMC_MMCRSP20

#define _MMC_MMCRSP21_ADDR		 _MMC_MMCRSP2_ADDR(1)
#define _MMC_MMCRSP21			PREG16(_MMC_MMCRSP21_ADDR)
#define MMCRSP21				_MMC_MMCRSP21

#define _MMC_MMCRSP2_BASE			 (0x4812)
#define _MMC_MMCRSP2_ADDR(n)		 (_MMC_MMCRSP2_BASE + ((n)*0x400))
#define _MMC_MMCRSP2(n)			 PREG16(_MMC_MMCRSP2_ADDR(n))
#define _MMC_MMCRSP2_ADDR_H(devNum)	 _MMC_MMCRSP2_ADDR(devNum)

/*--------------------- Register: MMCRSP3 -----------------------*/
#define _MMC_MMCRSP30_ADDR		 _MMC_MMCRSP3_ADDR(0)
#define _MMC_MMCRSP30			PREG16(_MMC_MMCRSP30_ADDR)
#define MMCRSP30				_MMC_MMCRSP30

#define _MMC_MMCRSP31_ADDR		 _MMC_MMCRSP3_ADDR(1)
#define _MMC_MMCRSP31			PREG16(_MMC_MMCRSP31_ADDR)
#define MMCRSP31				_MMC_MMCRSP31

#define _MMC_MMCRSP3_BASE			 (0x4813)
#define _MMC_MMCRSP3_ADDR(n)		 (_MMC_MMCRSP3_BASE + ((n)*0x400))
#define _MMC_MMCRSP3(n)			 PREG16(_MMC_MMCRSP3_ADDR(n))
#define _MMC_MMCRSP3_ADDR_H(devNum)	 _MMC_MMCRSP3_ADDR(devNum)

/*--------------------- Register: MMCRSP4 -----------------------*/
#define _MMC_MMCRSP40_ADDR		 _MMC_MMCRSP4_ADDR(0)
#define _MMC_MMCRSP40			PREG16(_MMC_MMCRSP40_ADDR)
#define MMCRSP40				_MMC_MMCRSP40

#define _MMC_MMCRSP41_ADDR		 _MMC_MMCRSP4_ADDR(1)
#define _MMC_MMCRSP41			PREG16(_MMC_MMCRSP41_ADDR)
#define MMCRSP41				_MMC_MMCRSP41

#define _MMC_MMCRSP4_BASE			 (0x4814)
#define _MMC_MMCRSP4_ADDR(n)		 (_MMC_MMCRSP4_BASE + ((n)*0x400))
#define _MMC_MMCRSP4(n)			 PREG16(_MMC_MMCRSP4_ADDR(n))
#define _MMC_MMCRSP4_ADDR_H(devNum)	 _MMC_MMCRSP4_ADDR(devNum)

/*--------------------- Register: MMCRSP5 -----------------------*/
#define _MMC_MMCRSP50_ADDR		 _MMC_MMCRSP5_ADDR(0)
#define _MMC_MMCRSP50			PREG16(_MMC_MMCRSP50_ADDR)
#define MMCRSP50				_MMC_MMCRSP50

#define _MMC_MMCRSP51_ADDR		 _MMC_MMCRSP5_ADDR(1)
#define _MMC_MMCRSP51			PREG16(_MMC_MMCRSP51_ADDR)
#define MMCRSP51				_MMC_MMCRSP51

#define _MMC_MMCRSP5_BASE			 (0x4815)
#define _MMC_MMCRSP5_ADDR(n)		 (_MMC_MMCRSP5_BASE + ((n)*0x400))
#define _MMC_MMCRSP5(n)			 PREG16(_MMC_MMCRSP5_ADDR(n))
#define _MMC_MMCRSP5_ADDR_H(devNum)	 _MMC_MMCRSP5_ADDR(devNum)

/*--------------------- Register: MMCRSP6 -----------------------*/
#define _MMC_MMCRSP60_ADDR		 _MMC_MMCRSP6_ADDR(0)
#define _MMC_MMCRSP60			PREG16(_MMC_MMCRSP60_ADDR)
#define MMCRSP60				_MMC_MMCRSP60

#define _MMC_MMCRSP61_ADDR		 _MMC_MMCRSP6_ADDR(1)
#define _MMC_MMCRSP61			PREG16(_MMC_MMCRSP61_ADDR)
#define MMCRSP61				_MMC_MMCRSP61

#define _MMC_MMCRSP6_BASE			 (0x4816)
#define _MMC_MMCRSP6_ADDR(n)		 (_MMC_MMCRSP6_BASE + ((n)*0x400))
#define _MMC_MMCRSP6(n)			 PREG16(_MMC_MMCRSP6_ADDR(n))
#define _MMC_MMCRSP6_ADDR_H(devNum)	 _MMC_MMCRSP6_ADDR(devNum)

/*--------------------- Register: MMCRSP7 -----------------------*/
#define _MMC_MMCRSP70_ADDR		 _MMC_MMCRSP7_ADDR(0)
#define _MMC_MMCRSP70			PREG16(_MMC_MMCRSP70_ADDR)
#define MMCRSP70				_MMC_MMCRSP70

#define _MMC_MMCRSP71_ADDR		 _MMC_MMCRSP7_ADDR(1)
#define _MMC_MMCRSP71			PREG16(_MMC_MMCRSP71_ADDR)
#define MMCRSP71				_MMC_MMCRSP71

#define _MMC_MMCRSP7_BASE			 (0x4817)
#define _MMC_MMCRSP7_ADDR(n)		 (_MMC_MMCRSP7_BASE + ((n)*0x400))
#define _MMC_MMCRSP7(n)			 PREG16(_MMC_MMCRSP7_ADDR(n))
#define _MMC_MMCRSP7_ADDR_H(devNum)	 _MMC_MMCRSP7_ADDR(devNum)

/*--------------------- Register: MMCDRSP -----------------------*/
#define _MMC_MMCDRSP0_ADDR		 _MMC_MMCDRSP_ADDR(0)
#define _MMC_MMCDRSP0			PREG16(_MMC_MMCDRSP0_ADDR)
#define MMCDRSP0				_MMC_MMCDRSP0

#define _MMC_MMCDRSP1_ADDR		 _MMC_MMCDRSP_ADDR(1)
#define _MMC_MMCDRSP1			PREG16(_MMC_MMCDRSP1_ADDR)
#define MMCDRSP1				_MMC_MMCDRSP1

#define _MMC_MMCDRSP_BASE			 (0x4818)
#define _MMC_MMCDRSP_ADDR(n)		 (_MMC_MMCDRSP_BASE + ((n)*0x400))
#define _MMC_MMCDRSP(n)			 PREG16(_MMC_MMCDRSP_ADDR(n))
#define _MMC_MMCDRSP_ADDR_H(devNum)	 _MMC_MMCDRSP_ADDR(devNum)

/*--------------------- Register: MMCCIDX -----------------------*/
#define _MMC_MMCCIDX0_ADDR		 _MMC_MMCCIDX_ADDR(0)
#define _MMC_MMCCIDX0			PREG16(_MMC_MMCCIDX0_ADDR)
#define MMCCIDX0				_MMC_MMCCIDX0

#define _MMC_MMCCIDX1_ADDR		 _MMC_MMCCIDX_ADDR(1)
#define _MMC_MMCCIDX1			PREG16(_MMC_MMCCIDX1_ADDR)
#define MMCCIDX1				_MMC_MMCCIDX1

#define _MMC_MMCCIDX_BASE			 (0x481A)
#define _MMC_MMCCIDX_ADDR(n)		 (_MMC_MMCCIDX_BASE + ((n)*0x400))
#define _MMC_MMCCIDX(n)			 PREG16(_MMC_MMCCIDX_ADDR(n))
#define _MMC_MMCCIDX_ADDR_H(devNum)	 _MMC_MMCCIDX_ADDR(devNum)


/*----------------------------------------------------------------*\
*		 Register Macros		
\*----------------------------------------------------------------*/

#define MMC_ADDR(Reg)		        _MMC_##Reg##_ADDR
#define MMC_RGET(Reg)		        _MMC_##Reg##_GET
#define MMC_RSET(Reg,Val)		  _MMC_##Reg##_SET(Val)
#define MMC_FGET(Reg,Field)		  _MMC_##Reg##_FGET(##Field)
#define MMC_FSET(Reg,Field,Val)		  _MMC_##Reg##_FSET(##Field, Val)
#define MMC_FMK(Reg,Field,Val)		  _MMC_##Reg##_##Field##_MK(Val)
#define MMC_RAOI(Reg,AND,OR,INV)		  _MMC_##Reg##_AOI(AND,OR,INV)
#define MMC_FAOI(Reg,Field,AND,OR,INV)	  _MMC_##Reg##_FAOI(##Field,AND,OR,INV)
#define MMC_FMKS(Reg,Field,Sym)\
	  _MMC_##Reg##_##Field##_MK(MMC_##Reg##_##Field##_##Sym)
#define MMC_FSETS(Reg,Field,Sym)\
	  _MMC_FSET(##Reg,##Field,MMC_##Reg##_##Field##_##Sym)

#define MMC_ADDR_H(Handle,Reg)		  _MMC_##Reg##_ADDR_H(((MMC_PrivateObj*)(Handle))->devNum)
#define MMC_RGET_H(Handle,Reg)		  _MMC_##Reg##_GET(((MMC_PrivateObj*)(Handle))->devNum)
#define MMC_RSET_H(Handle,Reg,Val)		  _MMC_##Reg##_SET((((MMC_PrivateObj*)(Handle))->devNum),Val)
#define MMC_FGET_H(Handle,Reg,Field)	  _MMC_##Reg##_FGET((((MMC_PrivateObj*)(Handle))->devNum),Field)
#define MMC_FSET_H(Handle,Reg,Field,Val)	  _MMC_##Reg##_FSET((((MMC_PrivateObj*)(Handle))->devNum),Field,Val)
#define MMC_FMK_H(Handle,Reg,Field,Val)	  _MMC_##Reg##_##Field##_MK(Val)

#define MMC_RAOI_H(Handle,Reg,AND,OR,INV)	  _MMC_##Reg##_AOI((((MMC_PrivateObj*)(Handle))->devNum),AND,OR,INV)
#define MMC_FAOI_H(Handle,Reg,Field,AND,OR,INV)\
	  _MMC_##Reg##_FAOI((((MMC_PrivateObj*)(Handle))->devNum),##Field,AND,OR,INV)
#define MMC_FMKS_H(Handle,Reg,Field,Sym)\
	   _MMC_##Reg##_##Field##_MK(MMC_##Reg##_##Field##_##Sym)
#define MMC_FSETS_H(Handle,Reg,Field,Sym)\
	 _MMC_##Reg##_FSET(Handle,##Field,MMC_##Reg##_##Field##_##Sym)



/*----------------------------------------------------------------*\
*		 Handle Registers Macros		
\*----------------------------------------------------------------*/


/*--------------------- Register: MMCCTL -----------------------*/
#define _MMC_MMCCTL_GET(devNum)			  _PREG_GET(_MMC_MMCCTL_ADDR(devNum)) 
#define _MMC_MMCCTL_SET(devNum,Val)		  _PREG_SET(_MMC_MMCCTL_ADDR(devNum),Val)
#define _MMC_MMCCTL_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCCTL_ADDR(devNum), _MMC_MMCCTL_##Field)
#define _MMC_MMCCTL_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCCTL_ADDR(devNum), _MMC_MMCCTL_##Field, Val)
#define _MMC_MMCCTL_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCCTL_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCCTL_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCCTL_ADDR(devNum), _MMC_MMCCTL_##Field,AND,OR,INV)

#define _MMC_MMCCTL0_GET		  _PREG_GET(_MMC_MMCCTL_ADDR(0)) 
#define _MMC_MMCCTL0_SET(Val)		  _PREG_SET(_MMC_MMCCTL_ADDR(0),Val)
#define _MMC_MMCCTL0_FGET(Field)	  _PFIELD_GET(_MMC_MMCCTL_ADDR(0), _MMC_MMCCTL_##Field)
#define _MMC_MMCCTL0_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCCTL_ADDR(0), _MMC_MMCCTL_##Field, Val)
#define _MMC_MMCCTL0_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCCTL_ADDR(0),AND,OR,INV)
#define _MMC_MMCCTL0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCCTL_ADDR(0), _MMC_MMCCTL_##Field,AND,OR,INV)

#define _MMC_MMCCTL1_GET		  _PREG_GET(_MMC_MMCCTL_ADDR(1)) 
#define _MMC_MMCCTL1_SET(Val)		  _PREG_SET(_MMC_MMCCTL_ADDR(1),Val)
#define _MMC_MMCCTL1_FGET(Field)	  _PFIELD_GET(_MMC_MMCCTL_ADDR(1), _MMC_MMCCTL_##Field)
#define _MMC_MMCCTL1_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCCTL_ADDR(1), _MMC_MMCCTL_##Field, Val)
#define _MMC_MMCCTL1_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCCTL_ADDR(1),AND,OR,INV)
#define _MMC_MMCCTL1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCCTL_ADDR(1), _MMC_MMCCTL_##Field,AND,OR,INV)


/*--------------------- Register: MMCFCLK -----------------------*/
#define _MMC_MMCFCLK_GET(devNum)			  _PREG_GET(_MMC_MMCFCLK_ADDR(devNum)) 
#define _MMC_MMCFCLK_SET(devNum,Val)		  _PREG_SET(_MMC_MMCFCLK_ADDR(devNum),Val)
#define _MMC_MMCFCLK_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCFCLK_ADDR(devNum), _MMC_MMCFCLK_##Field)
#define _MMC_MMCFCLK_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCFCLK_ADDR(devNum), _MMC_MMCFCLK_##Field, Val)
#define _MMC_MMCFCLK_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCFCLK_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCFCLK_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCFCLK_ADDR(devNum), _MMC_MMCFCLK_##Field,AND,OR,INV)

#define _MMC_MMCFCLK0_GET		  _PREG_GET(_MMC_MMCFCLK_ADDR(0)) 
#define _MMC_MMCFCLK0_SET(Val)		  _PREG_SET(_MMC_MMCFCLK_ADDR(0),Val)
#define _MMC_MMCFCLK0_FGET(Field)	  _PFIELD_GET(_MMC_MMCFCLK_ADDR(0), _MMC_MMCFCLK_##Field)
#define _MMC_MMCFCLK0_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCFCLK_ADDR(0), _MMC_MMCFCLK_##Field, Val)
#define _MMC_MMCFCLK0_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCFCLK_ADDR(0),AND,OR,INV)
#define _MMC_MMCFCLK0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCFCLK_ADDR(0), _MMC_MMCFCLK_##Field,AND,OR,INV)

#define _MMC_MMCFCLK1_GET		  _PREG_GET(_MMC_MMCFCLK_ADDR(1)) 
#define _MMC_MMCFCLK1_SET(Val)		  _PREG_SET(_MMC_MMCFCLK_ADDR(1),Val)
#define _MMC_MMCFCLK1_FGET(Field)	  _PFIELD_GET(_MMC_MMCFCLK_ADDR(1), _MMC_MMCFCLK_##Field)
#define _MMC_MMCFCLK1_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCFCLK_ADDR(1), _MMC_MMCFCLK_##Field, Val)
#define _MMC_MMCFCLK1_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCFCLK_ADDR(1),AND,OR,INV)
#define _MMC_MMCFCLK1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCFCLK_ADDR(1), _MMC_MMCFCLK_##Field,AND,OR,INV)


/*--------------------- Register: MMCCLK -----------------------*/
#define _MMC_MMCCLK_GET(devNum)			  _PREG_GET(_MMC_MMCCLK_ADDR(devNum)) 
#define _MMC_MMCCLK_SET(devNum,Val)		  _PREG_SET(_MMC_MMCCLK_ADDR(devNum),Val)
#define _MMC_MMCCLK_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCCLK_ADDR(devNum), _MMC_MMCCLK_##Field)
#define _MMC_MMCCLK_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCCLK_ADDR(devNum), _MMC_MMCCLK_##Field, Val)
#define _MMC_MMCCLK_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCCLK_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCCLK_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCCLK_ADDR(devNum), _MMC_MMCCLK_##Field,AND,OR,INV)

#define _MMC_MMCCLK0_GET		  _PREG_GET(_MMC_MMCCLK_ADDR(0)) 
#define _MMC_MMCCLK0_SET(Val)		  _PREG_SET(_MMC_MMCCLK_ADDR(0),Val)
#define _MMC_MMCCLK0_FGET(Field)	  _PFIELD_GET(_MMC_MMCCLK_ADDR(0), _MMC_MMCCLK_##Field)
#define _MMC_MMCCLK0_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCCLK_ADDR(0), _MMC_MMCCLK_##Field, Val)
#define _MMC_MMCCLK0_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCCLK_ADDR(0),AND,OR,INV)
#define _MMC_MMCCLK0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCCLK_ADDR(0), _MMC_MMCCLK_##Field,AND,OR,INV)

#define _MMC_MMCCLK1_GET		  _PREG_GET(_MMC_MMCCLK_ADDR(1)) 
#define _MMC_MMCCLK1_SET(Val)		  _PREG_SET(_MMC_MMCCLK_ADDR(1),Val)
#define _MMC_MMCCLK1_FGET(Field)	  _PFIELD_GET(_MMC_MMCCLK_ADDR(1), _MMC_MMCCLK_##Field)
#define _MMC_MMCCLK1_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCCLK_ADDR(1), _MMC_MMCCLK_##Field, Val)
#define _MMC_MMCCLK1_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCCLK_ADDR(1),AND,OR,INV)
#define _MMC_MMCCLK1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCCLK_ADDR(1), _MMC_MMCCLK_##Field,AND,OR,INV)





/*--------------------- Register: MMCIE -----------------------*/
#define _MMC_MMCIE_GET(devNum)			  _PREG_GET(_MMC_MMCIE_ADDR(devNum)) 
#define _MMC_MMCIE_SET(devNum,Val)		  _PREG_SET(_MMC_MMCIE_ADDR(devNum),Val)
#define _MMC_MMCIE_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCIE_ADDR(devNum), _MMC_MMCIE_##Field)
#define _MMC_MMCIE_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCIE_ADDR(devNum), _MMC_MMCIE_##Field, Val)
#define _MMC_MMCIE_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCIE_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCIE_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCIE_ADDR(devNum), _MMC_MMCIE_##Field,AND,OR,INV)

#define _MMC_MMCIE0_GET		  _PREG_GET(_MMC_MMCIE_ADDR(0)) 
#define _MMC_MMCIE0_SET(Val)		  _PREG_SET(_MMC_MMCIE_ADDR(0),Val)
#define _MMC_MMCIE0_FGET(Field)	  _PFIELD_GET(_MMC_MMCIE_ADDR(0), _MMC_MMCIE_##Field)
#define _MMC_MMCIE0_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCIE_ADDR(0), _MMC_MMCIE_##Field, Val)
#define _MMC_MMCIE0_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCIE_ADDR(0),AND,OR,INV)
#define _MMC_MMCIE0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCIE_ADDR(0), _MMC_MMCIE_##Field,AND,OR,INV)

#define _MMC_MMCIE1_GET		  _PREG_GET(_MMC_MMCIE_ADDR(1)) 
#define _MMC_MMCIE1_SET(Val)		  _PREG_SET(_MMC_MMCIE_ADDR(1),Val)
#define _MMC_MMCIE1_FGET(Field)	  _PFIELD_GET(_MMC_MMCIE_ADDR(1), _MMC_MMCIE_##Field)
#define _MMC_MMCIE1_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCIE_ADDR(1), _MMC_MMCIE_##Field, Val)
#define _MMC_MMCIE1_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCIE_ADDR(1),AND,OR,INV)
#define _MMC_MMCIE1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCIE_ADDR(1), _MMC_MMCIE_##Field,AND,OR,INV)



/*--------------------- Register: MMCTOR -----------------------*/
#define _MMC_MMCTOR_GET(devNum)			  _PREG_GET(_MMC_MMCTOR_ADDR(devNum)) 
#define _MMC_MMCTOR_SET(devNum,Val)		  _PREG_SET(_MMC_MMCTOR_ADDR(devNum),Val)
#define _MMC_MMCTOR_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCTOR_ADDR(devNum), _MMC_MMCTOR_##Field)
#define _MMC_MMCTOR_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCTOR_ADDR(devNum), _MMC_MMCTOR_##Field, Val)
#define _MMC_MMCTOR_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCTOR_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCTOR_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCTOR_ADDR(devNum), _MMC_MMCTOR_##Field,AND,OR,INV)

#define _MMC_MMCTOR0_GET		  _PREG_GET(_MMC_MMCTOR_ADDR(0)) 
#define _MMC_MMCTOR0_SET(Val)		  _PREG_SET(_MMC_MMCTOR_ADDR(0),Val)
#define _MMC_MMCTOR0_FGET(Field)	  _PFIELD_GET(_MMC_MMCTOR_ADDR(0), _MMC_MMCTOR_##Field)
#define _MMC_MMCTOR0_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCTOR_ADDR(0), _MMC_MMCTOR_##Field, Val)
#define _MMC_MMCTOR0_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCTOR_ADDR(0),AND,OR,INV)
#define _MMC_MMCTOR0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCTOR_ADDR(0), _MMC_MMCTOR_##Field,AND,OR,INV)

#define _MMC_MMCTOR1_GET		  _PREG_GET(_MMC_MMCTOR_ADDR(1)) 
#define _MMC_MMCTOR1_SET(Val)		  _PREG_SET(_MMC_MMCTOR_ADDR(1),Val)
#define _MMC_MMCTOR1_FGET(Field)	  _PFIELD_GET(_MMC_MMCTOR_ADDR(1), _MMC_MMCTOR_##Field)
#define _MMC_MMCTOR1_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCTOR_ADDR(1), _MMC_MMCTOR_##Field, Val)
#define _MMC_MMCTOR1_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCTOR_ADDR(1),AND,OR,INV)
#define _MMC_MMCTOR1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCTOR_ADDR(1), _MMC_MMCTOR_##Field,AND,OR,INV)


/*--------------------- Register: MMCTOD -----------------------*/
#define _MMC_MMCTOD_GET(devNum)			  _PREG_GET(_MMC_MMCTOD_ADDR(devNum)) 
#define _MMC_MMCTOD_SET(devNum,Val)		  _PREG_SET(_MMC_MMCTOD_ADDR(devNum),Val)
#define _MMC_MMCTOD_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCTOD_ADDR(devNum), _MMC_MMCTOD_##Field)
#define _MMC_MMCTOD_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCTOD_ADDR(devNum), _MMC_MMCTOD_##Field, Val)
#define _MMC_MMCTOD_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCTOD_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCTOD_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCTOD_ADDR(devNum), _MMC_MMCTOD_##Field,AND,OR,INV)

#define _MMC_MMCTOD0_GET		  _PREG_GET(_MMC_MMCTOD_ADDR(0)) 
#define _MMC_MMCTOD0_SET(Val)		  _PREG_SET(_MMC_MMCTOD_ADDR(0),Val)
#define _MMC_MMCTOD0_FGET(Field)	  _PFIELD_GET(_MMC_MMCTOD_ADDR(0), _MMC_MMCTOD_##Field)
#define _MMC_MMCTOD0_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCTOD_ADDR(0), _MMC_MMCTOD_##Field, Val)
#define _MMC_MMCTOD0_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCTOD_ADDR(0),AND,OR,INV)
#define _MMC_MMCTOD0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCTOD_ADDR(0), _MMC_MMCTOD_##Field,AND,OR,INV)

#define _MMC_MMCTOD1_GET		  _PREG_GET(_MMC_MMCTOD_ADDR(1)) 
#define _MMC_MMCTOD1_SET(Val)		  _PREG_SET(_MMC_MMCTOD_ADDR(1),Val)
#define _MMC_MMCTOD1_FGET(Field)	  _PFIELD_GET(_MMC_MMCTOD_ADDR(1), _MMC_MMCTOD_##Field)
#define _MMC_MMCTOD1_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCTOD_ADDR(1), _MMC_MMCTOD_##Field, Val)
#define _MMC_MMCTOD1_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCTOD_ADDR(1),AND,OR,INV)
#define _MMC_MMCTOD1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCTOD_ADDR(1), _MMC_MMCTOD_##Field,AND,OR,INV)


/*--------------------- Register: MMCBLEN -----------------------*/
#define _MMC_MMCBLEN_GET(devNum)			  _PREG_GET(_MMC_MMCBLEN_ADDR(devNum)) 
#define _MMC_MMCBLEN_SET(devNum,Val)		  _PREG_SET(_MMC_MMCBLEN_ADDR(devNum),Val)
#define _MMC_MMCBLEN_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCBLEN_ADDR(devNum), _MMC_MMCBLEN_##Field)
#define _MMC_MMCBLEN_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCBLEN_ADDR(devNum), _MMC_MMCBLEN_##Field, Val)
#define _MMC_MMCBLEN_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCBLEN_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCBLEN_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCBLEN_ADDR(devNum), _MMC_MMCBLEN_##Field,AND,OR,INV)

#define _MMC_MMCBLEN0_GET		  _PREG_GET(_MMC_MMCBLEN_ADDR(0)) 
#define _MMC_MMCBLEN0_SET(Val)		  _PREG_SET(_MMC_MMCBLEN_ADDR(0),Val)
#define _MMC_MMCBLEN0_FGET(Field)	  _PFIELD_GET(_MMC_MMCBLEN_ADDR(0), _MMC_MMCBLEN_##Field)
#define _MMC_MMCBLEN0_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCBLEN_ADDR(0), _MMC_MMCBLEN_##Field, Val)
#define _MMC_MMCBLEN0_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCBLEN_ADDR(0),AND,OR,INV)
#define _MMC_MMCBLEN0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCBLEN_ADDR(0), _MMC_MMCBLEN_##Field,AND,OR,INV)

#define _MMC_MMCBLEN1_GET		  _PREG_GET(_MMC_MMCBLEN_ADDR(1)) 
#define _MMC_MMCBLEN1_SET(Val)		  _PREG_SET(_MMC_MMCBLEN_ADDR(1),Val)
#define _MMC_MMCBLEN1_FGET(Field)	  _PFIELD_GET(_MMC_MMCBLEN_ADDR(1), _MMC_MMCBLEN_##Field)
#define _MMC_MMCBLEN1_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCBLEN_ADDR(1), _MMC_MMCBLEN_##Field, Val)
#define _MMC_MMCBLEN1_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCBLEN_ADDR(1),AND,OR,INV)
#define _MMC_MMCBLEN1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCBLEN_ADDR(1), _MMC_MMCBLEN_##Field,AND,OR,INV)


/*--------------------- Register: MMCNBLK -----------------------*/
#define _MMC_MMCNBLK_GET(devNum)			  _PREG_GET(_MMC_MMCNBLK_ADDR(devNum)) 
#define _MMC_MMCNBLK_SET(devNum,Val)		  _PREG_SET(_MMC_MMCNBLK_ADDR(devNum),Val)
#define _MMC_MMCNBLK_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCNBLK_ADDR(devNum), _MMC_MMCNBLK_##Field)
#define _MMC_MMCNBLK_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCNBLK_ADDR(devNum), _MMC_MMCNBLK_##Field, Val)
#define _MMC_MMCNBLK_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCNBLK_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCNBLK_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCNBLK_ADDR(devNum), _MMC_MMCNBLK_##Field,AND,OR,INV)

#define _MMC_MMCNBLK0_GET		  _PREG_GET(_MMC_MMCNBLK_ADDR(0)) 
#define _MMC_MMCNBLK0_SET(Val)		  _PREG_SET(_MMC_MMCNBLK_ADDR(0),Val)
#define _MMC_MMCNBLK0_FGET(Field)	  _PFIELD_GET(_MMC_MMCNBLK_ADDR(0), _MMC_MMCNBLK_##Field)
#define _MMC_MMCNBLK0_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCNBLK_ADDR(0), _MMC_MMCNBLK_##Field, Val)
#define _MMC_MMCNBLK0_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCNBLK_ADDR(0),AND,OR,INV)
#define _MMC_MMCNBLK0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCNBLK_ADDR(0), _MMC_MMCNBLK_##Field,AND,OR,INV)

#define _MMC_MMCNBLK1_GET		  _PREG_GET(_MMC_MMCNBLK_ADDR(1)) 
#define _MMC_MMCNBLK1_SET(Val)		  _PREG_SET(_MMC_MMCNBLK_ADDR(1),Val)
#define _MMC_MMCNBLK1_FGET(Field)	  _PFIELD_GET(_MMC_MMCNBLK_ADDR(1), _MMC_MMCNBLK_##Field)
#define _MMC_MMCNBLK1_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCNBLK_ADDR(1), _MMC_MMCNBLK_##Field, Val)
#define _MMC_MMCNBLK1_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCNBLK_ADDR(1),AND,OR,INV)
#define _MMC_MMCNBLK1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCNBLK_ADDR(1), _MMC_MMCNBLK_##Field,AND,OR,INV)


/*--------------------- Register: MMCST0 -----------------------*/
#define _MMC_MMCST0_GET(devNum)			  _PREG_GET(_MMC_MMCST0_ADDR(devNum)) 
#define _MMC_MMCST0_SET(devNum,Val)		  _PREG_SET(_MMC_MMCST0_ADDR(devNum),Val)
#define _MMC_MMCST0_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCST0_ADDR(devNum), _MMC_MMCST0_##Field)
#define _MMC_MMCST0_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCST0_ADDR(devNum), _MMC_MMCST0_##Field, Val)
#define _MMC_MMCST0_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCST0_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCST0_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCST0_ADDR(devNum), _MMC_MMCST0_##Field,AND,OR,INV)

#define _MMC_MMCST00_GET		  _PREG_GET(_MMC_MMCST0_ADDR(0)) 
#define _MMC_MMCST00_SET(Val)		  _PREG_SET(_MMC_MMCST0_ADDR(0),Val)
#define _MMC_MMCST00_FGET(Field)	  _PFIELD_GET(_MMC_MMCST0_ADDR(0), _MMC_MMCST0_##Field)
#define _MMC_MMCST00_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCST0_ADDR(0), _MMC_MMCST0_##Field, Val)
#define _MMC_MMCST00_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCST0_ADDR(0),AND,OR,INV)
#define _MMC_MMCST00_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCST0_ADDR(0), _MMC_MMCST0_##Field,AND,OR,INV)

#define _MMC_MMCST01_GET		  _PREG_GET(_MMC_MMCST0_ADDR(1)) 
#define _MMC_MMCST01_SET(Val)		  _PREG_SET(_MMC_MMCST0_ADDR(1),Val)
#define _MMC_MMCST01_FGET(Field)	  _PFIELD_GET(_MMC_MMCST0_ADDR(1), _MMC_MMCST0_##Field)
#define _MMC_MMCST01_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCST0_ADDR(1), _MMC_MMCST0_##Field, Val)
#define _MMC_MMCST01_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCST0_ADDR(1),AND,OR,INV)
#define _MMC_MMCST01_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCST0_ADDR(1), _MMC_MMCST0_##Field,AND,OR,INV)


/*--------------------- Register: MMCST1 -----------------------*/
#define _MMC_MMCST1_GET(devNum)			  _PREG_GET(_MMC_MMCST1_ADDR(devNum)) 
#define _MMC_MMCST1_SET(devNum,Val)		  _PREG_SET(_MMC_MMCST1_ADDR(devNum),Val)
#define _MMC_MMCST1_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCST1_ADDR(devNum), _MMC_MMCST1_##Field)
#define _MMC_MMCST1_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCST1_ADDR(devNum), _MMC_MMCST1_##Field, Val)
#define _MMC_MMCST1_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCST1_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCST1_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCST1_ADDR(devNum), _MMC_MMCST1_##Field,AND,OR,INV)

#define _MMC_MMCST10_GET		  _PREG_GET(_MMC_MMCST1_ADDR(0)) 
#define _MMC_MMCST10_SET(Val)		  _PREG_SET(_MMC_MMCST1_ADDR(0),Val)
#define _MMC_MMCST10_FGET(Field)	  _PFIELD_GET(_MMC_MMCST1_ADDR(0), _MMC_MMCST1_##Field)
#define _MMC_MMCST10_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCST1_ADDR(0), _MMC_MMCST1_##Field, Val)
#define _MMC_MMCST10_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCST1_ADDR(0),AND,OR,INV)
#define _MMC_MMCST10_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCST1_ADDR(0), _MMC_MMCST1_##Field,AND,OR,INV)

#define _MMC_MMCST11_GET		  _PREG_GET(_MMC_MMCST1_ADDR(1)) 
#define _MMC_MMCST11_SET(Val)		  _PREG_SET(_MMC_MMCST1_ADDR(1),Val)
#define _MMC_MMCST11_FGET(Field)	  _PFIELD_GET(_MMC_MMCST1_ADDR(1), _MMC_MMCST1_##Field)
#define _MMC_MMCST11_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCST1_ADDR(1), _MMC_MMCST1_##Field, Val)
#define _MMC_MMCST11_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCST1_ADDR(1),AND,OR,INV)
#define _MMC_MMCST11_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCST1_ADDR(1), _MMC_MMCST1_##Field,AND,OR,INV)


/*--------------------- Register: MMCNBLC -----------------------*/
#define _MMC_MMCNBLC_GET(devNum)			  _PREG_GET(_MMC_MMCNBLC_ADDR(devNum)) 
#define _MMC_MMCNBLC_SET(devNum,Val)		  _PREG_SET(_MMC_MMCNBLC_ADDR(devNum),Val)
#define _MMC_MMCNBLC_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCNBLC_ADDR(devNum), _MMC_MMCNBLC_##Field)
#define _MMC_MMCNBLC_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCNBLC_ADDR(devNum), _MMC_MMCNBLC_##Field, Val)
#define _MMC_MMCNBLC_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCNBLC_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCNBLC_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCNBLC_ADDR(devNum), _MMC_MMCNBLC_##Field,AND,OR,INV)

#define _MMC_MMCNBLC0_GET		  _PREG_GET(_MMC_MMCNBLC_ADDR(0)) 
#define _MMC_MMCNBLC0_SET(Val)		  _PREG_SET(_MMC_MMCNBLC_ADDR(0),Val)
#define _MMC_MMCNBLC0_FGET(Field)	  _PFIELD_GET(_MMC_MMCNBLC_ADDR(0), _MMC_MMCNBLC_##Field)
#define _MMC_MMCNBLC0_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCNBLC_ADDR(0), _MMC_MMCNBLC_##Field, Val)
#define _MMC_MMCNBLC0_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCNBLC_ADDR(0),AND,OR,INV)
#define _MMC_MMCNBLC0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCNBLC_ADDR(0), _MMC_MMCNBLC_##Field,AND,OR,INV)

#define _MMC_MMCNBLC1_GET		  _PREG_GET(_MMC_MMCNBLC_ADDR(1)) 
#define _MMC_MMCNBLC1_SET(Val)		  _PREG_SET(_MMC_MMCNBLC_ADDR(1),Val)
#define _MMC_MMCNBLC1_FGET(Field)	  _PFIELD_GET(_MMC_MMCNBLC_ADDR(1), _MMC_MMCNBLC_##Field)
#define _MMC_MMCNBLC1_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCNBLC_ADDR(1), _MMC_MMCNBLC_##Field, Val)
#define _MMC_MMCNBLC1_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCNBLC_ADDR(1),AND,OR,INV)
#define _MMC_MMCNBLC1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCNBLC_ADDR(1), _MMC_MMCNBLC_##Field,AND,OR,INV)


/*--------------------- Register: MMCDRR -----------------------*/
#define _MMC_MMCDRR_GET(devNum)			  _PREG_GET(_MMC_MMCDRR_ADDR(devNum)) 
#define _MMC_MMCDRR_SET(devNum,Val)		  _PREG_SET(_MMC_MMCDRR_ADDR(devNum),Val)
#define _MMC_MMCDRR_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCDRR_ADDR(devNum), _MMC_MMCDRR_##Field)
#define _MMC_MMCDRR_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCDRR_ADDR(devNum), _MMC_MMCDRR_##Field, Val)
#define _MMC_MMCDRR_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCDRR_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCDRR_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCDRR_ADDR(devNum), _MMC_MMCDRR_##Field,AND,OR,INV)

#define _MMC_MMCDRR0_GET		  _PREG_GET(_MMC_MMCDRR_ADDR(0)) 
#define _MMC_MMCDRR0_SET(Val)		  _PREG_SET(_MMC_MMCDRR_ADDR(0),Val)
#define _MMC_MMCDRR0_FGET(Field)	  _PFIELD_GET(_MMC_MMCDRR_ADDR(0), _MMC_MMCDRR_##Field)
#define _MMC_MMCDRR0_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCDRR_ADDR(0), _MMC_MMCDRR_##Field, Val)
#define _MMC_MMCDRR0_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCDRR_ADDR(0),AND,OR,INV)
#define _MMC_MMCDRR0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCDRR_ADDR(0), _MMC_MMCDRR_##Field,AND,OR,INV)

#define _MMC_MMCDRR1_GET		  _PREG_GET(_MMC_MMCDRR_ADDR(1)) 
#define _MMC_MMCDRR1_SET(Val)		  _PREG_SET(_MMC_MMCDRR_ADDR(1),Val)
#define _MMC_MMCDRR1_FGET(Field)	  _PFIELD_GET(_MMC_MMCDRR_ADDR(1), _MMC_MMCDRR_##Field)
#define _MMC_MMCDRR1_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCDRR_ADDR(1), _MMC_MMCDRR_##Field, Val)
#define _MMC_MMCDRR1_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCDRR_ADDR(1),AND,OR,INV)
#define _MMC_MMCDRR1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCDRR_ADDR(1), _MMC_MMCDRR_##Field,AND,OR,INV)


/*--------------------- Register: MMCDXR -----------------------*/
#define _MMC_MMCDXR_GET(devNum)			  _PREG_GET(_MMC_MMCDXR_ADDR(devNum)) 
#define _MMC_MMCDXR_SET(devNum,Val)		  _PREG_SET(_MMC_MMCDXR_ADDR(devNum),Val)
#define _MMC_MMCDXR_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCDXR_ADDR(devNum), _MMC_MMCDXR_##Field)
#define _MMC_MMCDXR_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCDXR_ADDR(devNum), _MMC_MMCDXR_##Field, Val)
#define _MMC_MMCDXR_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCDXR_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCDXR_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCDXR_ADDR(devNum), _MMC_MMCDXR_##Field,AND,OR,INV)

#define _MMC_MMCDXR0_GET		  _PREG_GET(_MMC_MMCDXR_ADDR(0)) 
#define _MMC_MMCDXR0_SET(Val)		  _PREG_SET(_MMC_MMCDXR_ADDR(0),Val)
#define _MMC_MMCDXR0_FGET(Field)	  _PFIELD_GET(_MMC_MMCDXR_ADDR(0), _MMC_MMCDXR_##Field)
#define _MMC_MMCDXR0_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCDXR_ADDR(0), _MMC_MMCDXR_##Field, Val)
#define _MMC_MMCDXR0_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCDXR_ADDR(0),AND,OR,INV)
#define _MMC_MMCDXR0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCDXR_ADDR(0), _MMC_MMCDXR_##Field,AND,OR,INV)

#define _MMC_MMCDXR1_GET		  _PREG_GET(_MMC_MMCDXR_ADDR(1)) 
#define _MMC_MMCDXR1_SET(Val)		  _PREG_SET(_MMC_MMCDXR_ADDR(1),Val)
#define _MMC_MMCDXR1_FGET(Field)	  _PFIELD_GET(_MMC_MMCDXR_ADDR(1), _MMC_MMCDXR_##Field)
#define _MMC_MMCDXR1_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCDXR_ADDR(1), _MMC_MMCDXR_##Field, Val)
#define _MMC_MMCDXR1_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCDXR_ADDR(1),AND,OR,INV)
#define _MMC_MMCDXR1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCDXR_ADDR(1), _MMC_MMCDXR_##Field,AND,OR,INV)


/*--------------------- Register: MMCCMD -----------------------*/
#define _MMC_MMCCMD_GET(devNum)			  _PREG_GET(_MMC_MMCCMD_ADDR(devNum)) 
#define _MMC_MMCCMD_SET(devNum,Val)		  _PREG_SET(_MMC_MMCCMD_ADDR(devNum),Val)
#define _MMC_MMCCMD_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCCMD_ADDR(devNum), _MMC_MMCCMD_##Field)
#define _MMC_MMCCMD_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCCMD_ADDR(devNum), _MMC_MMCCMD_##Field, Val)
#define _MMC_MMCCMD_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCCMD_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCCMD_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCCMD_ADDR(devNum), _MMC_MMCCMD_##Field,AND,OR,INV)

#define _MMC_MMCCMD0_GET		  _PREG_GET(_MMC_MMCCMD_ADDR(0)) 
#define _MMC_MMCCMD0_SET(Val)		  _PREG_SET(_MMC_MMCCMD_ADDR(0),Val)
#define _MMC_MMCCMD0_FGET(Field)	  _PFIELD_GET(_MMC_MMCCMD_ADDR(0), _MMC_MMCCMD_##Field)
#define _MMC_MMCCMD0_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCCMD_ADDR(0), _MMC_MMCCMD_##Field, Val)
#define _MMC_MMCCMD0_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCCMD_ADDR(0),AND,OR,INV)
#define _MMC_MMCCMD0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCCMD_ADDR(0), _MMC_MMCCMD_##Field,AND,OR,INV)

#define _MMC_MMCCMD1_GET		  _PREG_GET(_MMC_MMCCMD_ADDR(1)) 
#define _MMC_MMCCMD1_SET(Val)		  _PREG_SET(_MMC_MMCCMD_ADDR(1),Val)
#define _MMC_MMCCMD1_FGET(Field)	  _PFIELD_GET(_MMC_MMCCMD_ADDR(1), _MMC_MMCCMD_##Field)
#define _MMC_MMCCMD1_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCCMD_ADDR(1), _MMC_MMCCMD_##Field, Val)
#define _MMC_MMCCMD1_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCCMD_ADDR(1),AND,OR,INV)
#define _MMC_MMCCMD1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCCMD_ADDR(1), _MMC_MMCCMD_##Field,AND,OR,INV)


/*--------------------- Register: MMCARGL -----------------------*/
#define _MMC_MMCARGL_GET(devNum)			  _PREG_GET(_MMC_MMCARGL_ADDR(devNum)) 
#define _MMC_MMCARGL_SET(devNum,Val)		  _PREG_SET(_MMC_MMCARGL_ADDR(devNum),Val)
#define _MMC_MMCARGL_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCARGL_ADDR(devNum), _MMC_MMCARGL_##Field)
#define _MMC_MMCARGL_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCARGL_ADDR(devNum), _MMC_MMCARGL_##Field, Val)
#define _MMC_MMCARGL_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCARGL_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCARGL_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCARGL_ADDR(devNum), _MMC_MMCARGL_##Field,AND,OR,INV)

#define _MMC_MMCARGL0_GET		  _PREG_GET(_MMC_MMCARGL_ADDR(0)) 
#define _MMC_MMCARGL0_SET(Val)		  _PREG_SET(_MMC_MMCARGL_ADDR(0),Val)
#define _MMC_MMCARGL0_FGET(Field)	  _PFIELD_GET(_MMC_MMCARGL_ADDR(0), _MMC_MMCARGL_##Field)
#define _MMC_MMCARGL0_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCARGL_ADDR(0), _MMC_MMCARGL_##Field, Val)
#define _MMC_MMCARGL0_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCARGL_ADDR(0),AND,OR,INV)
#define _MMC_MMCARGL0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCARGL_ADDR(0), _MMC_MMCARGL_##Field,AND,OR,INV)

#define _MMC_MMCARGL1_GET		  _PREG_GET(_MMC_MMCARGL_ADDR(1)) 
#define _MMC_MMCARGL1_SET(Val)		  _PREG_SET(_MMC_MMCARGL_ADDR(1),Val)
#define _MMC_MMCARGL1_FGET(Field)	  _PFIELD_GET(_MMC_MMCARGL_ADDR(1), _MMC_MMCARGL_##Field)
#define _MMC_MMCARGL1_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCARGL_ADDR(1), _MMC_MMCARGL_##Field, Val)
#define _MMC_MMCARGL1_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCARGL_ADDR(1),AND,OR,INV)
#define _MMC_MMCARGL1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCARGL_ADDR(1), _MMC_MMCARGL_##Field,AND,OR,INV)


/*--------------------- Register: MMCARGH -----------------------*/
#define _MMC_MMCARGH_GET(devNum)			  _PREG_GET(_MMC_MMCARGH_ADDR(devNum)) 
#define _MMC_MMCARGH_SET(devNum,Val)		  _PREG_SET(_MMC_MMCARGH_ADDR(devNum),Val)
#define _MMC_MMCARGH_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCARGH_ADDR(devNum), _MMC_MMCARGH_##Field)
#define _MMC_MMCARGH_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCARGH_ADDR(devNum), _MMC_MMCARGH_##Field, Val)
#define _MMC_MMCARGH_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCARGH_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCARGH_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCARGH_ADDR(devNum), _MMC_MMCARGH_##Field,AND,OR,INV)

#define _MMC_MMCARGH0_GET		  _PREG_GET(_MMC_MMCARGH_ADDR(0)) 
#define _MMC_MMCARGH0_SET(Val)		  _PREG_SET(_MMC_MMCARGH_ADDR(0),Val)
#define _MMC_MMCARGH0_FGET(Field)	  _PFIELD_GET(_MMC_MMCARGH_ADDR(0), _MMC_MMCARGH_##Field)
#define _MMC_MMCARGH0_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCARGH_ADDR(0), _MMC_MMCARGH_##Field, Val)
#define _MMC_MMCARGH0_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCARGH_ADDR(0),AND,OR,INV)
#define _MMC_MMCARGH0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCARGH_ADDR(0), _MMC_MMCARGH_##Field,AND,OR,INV)

#define _MMC_MMCARGH1_GET		  _PREG_GET(_MMC_MMCARGH_ADDR(1)) 
#define _MMC_MMCARGH1_SET(Val)		  _PREG_SET(_MMC_MMCARGH_ADDR(1),Val)
#define _MMC_MMCARGH1_FGET(Field)	  _PFIELD_GET(_MMC_MMCARGH_ADDR(1), _MMC_MMCARGH_##Field)
#define _MMC_MMCARGH1_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCARGH_ADDR(1), _MMC_MMCARGH_##Field, Val)
#define _MMC_MMCARGH1_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCARGH_ADDR(1),AND,OR,INV)
#define _MMC_MMCARGH1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCARGH_ADDR(1), _MMC_MMCARGH_##Field,AND,OR,INV)


/*--------------------- Register: MMCRSP0 -----------------------*/
#define _MMC_MMCRSP0_GET(devNum)			  _PREG_GET(_MMC_MMCRSP0_ADDR(devNum)) 
#define _MMC_MMCRSP0_SET(devNum,Val)		  _PREG_SET(_MMC_MMCRSP0_ADDR(devNum),Val)
#define _MMC_MMCRSP0_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCRSP0_ADDR(devNum), _MMC_MMCRSP0_##Field)
#define _MMC_MMCRSP0_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCRSP0_ADDR(devNum), _MMC_MMCRSP0_##Field, Val)
#define _MMC_MMCRSP0_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP0_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCRSP0_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP0_ADDR(devNum), _MMC_MMCRSP0_##Field,AND,OR,INV)

#define _MMC_MMCRSP00_GET		  _PREG_GET(_MMC_MMCRSP0_ADDR(0)) 
#define _MMC_MMCRSP00_SET(Val)		  _PREG_SET(_MMC_MMCRSP0_ADDR(0),Val)
#define _MMC_MMCRSP00_FGET(Field)	  _PFIELD_GET(_MMC_MMCRSP0_ADDR(0), _MMC_MMCRSP0_##Field)
#define _MMC_MMCRSP00_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCRSP0_ADDR(0), _MMC_MMCRSP0_##Field, Val)
#define _MMC_MMCRSP00_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP0_ADDR(0),AND,OR,INV)
#define _MMC_MMCRSP00_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP0_ADDR(0), _MMC_MMCRSP0_##Field,AND,OR,INV)

#define _MMC_MMCRSP01_GET		  _PREG_GET(_MMC_MMCRSP0_ADDR(1)) 
#define _MMC_MMCRSP01_SET(Val)		  _PREG_SET(_MMC_MMCRSP0_ADDR(1),Val)
#define _MMC_MMCRSP01_FGET(Field)	  _PFIELD_GET(_MMC_MMCRSP0_ADDR(1), _MMC_MMCRSP0_##Field)
#define _MMC_MMCRSP01_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCRSP0_ADDR(1), _MMC_MMCRSP0_##Field, Val)
#define _MMC_MMCRSP01_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP0_ADDR(1),AND,OR,INV)
#define _MMC_MMCRSP01_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP0_ADDR(1), _MMC_MMCRSP0_##Field,AND,OR,INV)


/*--------------------- Register: MMCRSP0 -----------------------*/
#define _MMC_MMCRSP0_GET(devNum)			  _PREG_GET(_MMC_MMCRSP0_ADDR(devNum)) 
#define _MMC_MMCRSP0_SET(devNum,Val)		  _PREG_SET(_MMC_MMCRSP0_ADDR(devNum),Val)
#define _MMC_MMCRSP0_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCRSP0_ADDR(devNum), _MMC_MMCRSP0_##Field)
#define _MMC_MMCRSP0_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCRSP0_ADDR(devNum), _MMC_MMCRSP0_##Field, Val)
#define _MMC_MMCRSP0_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP0_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCRSP0_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP0_ADDR(devNum), _MMC_MMCRSP0_##Field,AND,OR,INV)

#define _MMC_MMCRSP00_GET		  _PREG_GET(_MMC_MMCRSP0_ADDR(0)) 
#define _MMC_MMCRSP00_SET(Val)		  _PREG_SET(_MMC_MMCRSP0_ADDR(0),Val)
#define _MMC_MMCRSP00_FGET(Field)	  _PFIELD_GET(_MMC_MMCRSP0_ADDR(0), _MMC_MMCRSP0_##Field)
#define _MMC_MMCRSP00_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCRSP0_ADDR(0), _MMC_MMCRSP0_##Field, Val)
#define _MMC_MMCRSP00_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP0_ADDR(0),AND,OR,INV)
#define _MMC_MMCRSP00_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP0_ADDR(0), _MMC_MMCRSP0_##Field,AND,OR,INV)

#define _MMC_MMCRSP01_GET		  _PREG_GET(_MMC_MMCRSP0_ADDR(1)) 
#define _MMC_MMCRSP01_SET(Val)		  _PREG_SET(_MMC_MMCRSP0_ADDR(1),Val)
#define _MMC_MMCRSP01_FGET(Field)	  _PFIELD_GET(_MMC_MMCRSP0_ADDR(1), _MMC_MMCRSP0_##Field)
#define _MMC_MMCRSP01_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCRSP0_ADDR(1), _MMC_MMCRSP0_##Field, Val)
#define _MMC_MMCRSP01_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP0_ADDR(1),AND,OR,INV)
#define _MMC_MMCRSP01_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP0_ADDR(1), _MMC_MMCRSP0_##Field,AND,OR,INV)


/*--------------------- Register: MMCRSP1 -----------------------*/
#define _MMC_MMCRSP1_GET(devNum)			  _PREG_GET(_MMC_MMCRSP1_ADDR(devNum)) 
#define _MMC_MMCRSP1_SET(devNum,Val)		  _PREG_SET(_MMC_MMCRSP1_ADDR(devNum),Val)
#define _MMC_MMCRSP1_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCRSP1_ADDR(devNum), _MMC_MMCRSP1_##Field)
#define _MMC_MMCRSP1_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCRSP1_ADDR(devNum), _MMC_MMCRSP1_##Field, Val)
#define _MMC_MMCRSP1_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP1_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCRSP1_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP1_ADDR(devNum), _MMC_MMCRSP1_##Field,AND,OR,INV)

#define _MMC_MMCRSP10_GET		  _PREG_GET(_MMC_MMCRSP1_ADDR(0)) 
#define _MMC_MMCRSP10_SET(Val)		  _PREG_SET(_MMC_MMCRSP1_ADDR(0),Val)
#define _MMC_MMCRSP10_FGET(Field)	  _PFIELD_GET(_MMC_MMCRSP1_ADDR(0), _MMC_MMCRSP1_##Field)
#define _MMC_MMCRSP10_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCRSP1_ADDR(0), _MMC_MMCRSP1_##Field, Val)
#define _MMC_MMCRSP10_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP1_ADDR(0),AND,OR,INV)
#define _MMC_MMCRSP10_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP1_ADDR(0), _MMC_MMCRSP1_##Field,AND,OR,INV)

#define _MMC_MMCRSP11_GET		  _PREG_GET(_MMC_MMCRSP1_ADDR(1)) 
#define _MMC_MMCRSP11_SET(Val)		  _PREG_SET(_MMC_MMCRSP1_ADDR(1),Val)
#define _MMC_MMCRSP11_FGET(Field)	  _PFIELD_GET(_MMC_MMCRSP1_ADDR(1), _MMC_MMCRSP1_##Field)
#define _MMC_MMCRSP11_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCRSP1_ADDR(1), _MMC_MMCRSP1_##Field, Val)
#define _MMC_MMCRSP11_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP1_ADDR(1),AND,OR,INV)
#define _MMC_MMCRSP11_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP1_ADDR(1), _MMC_MMCRSP1_##Field,AND,OR,INV)


/*--------------------- Register: MMCRSP2 -----------------------*/
#define _MMC_MMCRSP2_GET(devNum)			  _PREG_GET(_MMC_MMCRSP2_ADDR(devNum)) 
#define _MMC_MMCRSP2_SET(devNum,Val)		  _PREG_SET(_MMC_MMCRSP2_ADDR(devNum),Val)
#define _MMC_MMCRSP2_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCRSP2_ADDR(devNum), _MMC_MMCRSP2_##Field)
#define _MMC_MMCRSP2_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCRSP2_ADDR(devNum), _MMC_MMCRSP2_##Field, Val)
#define _MMC_MMCRSP2_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP2_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCRSP2_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP2_ADDR(devNum), _MMC_MMCRSP2_##Field,AND,OR,INV)

#define _MMC_MMCRSP20_GET		  _PREG_GET(_MMC_MMCRSP2_ADDR(0)) 
#define _MMC_MMCRSP20_SET(Val)		  _PREG_SET(_MMC_MMCRSP2_ADDR(0),Val)
#define _MMC_MMCRSP20_FGET(Field)	  _PFIELD_GET(_MMC_MMCRSP2_ADDR(0), _MMC_MMCRSP2_##Field)
#define _MMC_MMCRSP20_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCRSP2_ADDR(0), _MMC_MMCRSP2_##Field, Val)
#define _MMC_MMCRSP20_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP2_ADDR(0),AND,OR,INV)
#define _MMC_MMCRSP20_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP2_ADDR(0), _MMC_MMCRSP2_##Field,AND,OR,INV)

#define _MMC_MMCRSP21_GET		  _PREG_GET(_MMC_MMCRSP2_ADDR(1)) 
#define _MMC_MMCRSP21_SET(Val)		  _PREG_SET(_MMC_MMCRSP2_ADDR(1),Val)
#define _MMC_MMCRSP21_FGET(Field)	  _PFIELD_GET(_MMC_MMCRSP2_ADDR(1), _MMC_MMCRSP2_##Field)
#define _MMC_MMCRSP21_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCRSP2_ADDR(1), _MMC_MMCRSP2_##Field, Val)
#define _MMC_MMCRSP21_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP2_ADDR(1),AND,OR,INV)
#define _MMC_MMCRSP21_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP2_ADDR(1), _MMC_MMCRSP2_##Field,AND,OR,INV)


/*--------------------- Register: MMCRSP3 -----------------------*/
#define _MMC_MMCRSP3_GET(devNum)			  _PREG_GET(_MMC_MMCRSP3_ADDR(devNum)) 
#define _MMC_MMCRSP3_SET(devNum,Val)		  _PREG_SET(_MMC_MMCRSP3_ADDR(devNum),Val)
#define _MMC_MMCRSP3_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCRSP3_ADDR(devNum), _MMC_MMCRSP3_##Field)
#define _MMC_MMCRSP3_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCRSP3_ADDR(devNum), _MMC_MMCRSP3_##Field, Val)
#define _MMC_MMCRSP3_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP3_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCRSP3_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP3_ADDR(devNum), _MMC_MMCRSP3_##Field,AND,OR,INV)

#define _MMC_MMCRSP30_GET		  _PREG_GET(_MMC_MMCRSP3_ADDR(0)) 
#define _MMC_MMCRSP30_SET(Val)		  _PREG_SET(_MMC_MMCRSP3_ADDR(0),Val)
#define _MMC_MMCRSP30_FGET(Field)	  _PFIELD_GET(_MMC_MMCRSP3_ADDR(0), _MMC_MMCRSP3_##Field)
#define _MMC_MMCRSP30_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCRSP3_ADDR(0), _MMC_MMCRSP3_##Field, Val)
#define _MMC_MMCRSP30_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP3_ADDR(0),AND,OR,INV)
#define _MMC_MMCRSP30_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP3_ADDR(0), _MMC_MMCRSP3_##Field,AND,OR,INV)

#define _MMC_MMCRSP31_GET		  _PREG_GET(_MMC_MMCRSP3_ADDR(1)) 
#define _MMC_MMCRSP31_SET(Val)		  _PREG_SET(_MMC_MMCRSP3_ADDR(1),Val)
#define _MMC_MMCRSP31_FGET(Field)	  _PFIELD_GET(_MMC_MMCRSP3_ADDR(1), _MMC_MMCRSP3_##Field)
#define _MMC_MMCRSP31_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCRSP3_ADDR(1), _MMC_MMCRSP3_##Field, Val)
#define _MMC_MMCRSP31_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP3_ADDR(1),AND,OR,INV)
#define _MMC_MMCRSP31_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP3_ADDR(1), _MMC_MMCRSP3_##Field,AND,OR,INV)


/*--------------------- Register: MMCRSP4 -----------------------*/
#define _MMC_MMCRSP4_GET(devNum)			  _PREG_GET(_MMC_MMCRSP4_ADDR(devNum)) 
#define _MMC_MMCRSP4_SET(devNum,Val)		  _PREG_SET(_MMC_MMCRSP4_ADDR(devNum),Val)
#define _MMC_MMCRSP4_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCRSP4_ADDR(devNum), _MMC_MMCRSP4_##Field)
#define _MMC_MMCRSP4_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCRSP4_ADDR(devNum), _MMC_MMCRSP4_##Field, Val)
#define _MMC_MMCRSP4_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP4_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCRSP4_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP4_ADDR(devNum), _MMC_MMCRSP4_##Field,AND,OR,INV)

#define _MMC_MMCRSP40_GET		  _PREG_GET(_MMC_MMCRSP4_ADDR(0)) 
#define _MMC_MMCRSP40_SET(Val)		  _PREG_SET(_MMC_MMCRSP4_ADDR(0),Val)
#define _MMC_MMCRSP40_FGET(Field)	  _PFIELD_GET(_MMC_MMCRSP4_ADDR(0), _MMC_MMCRSP4_##Field)
#define _MMC_MMCRSP40_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCRSP4_ADDR(0), _MMC_MMCRSP4_##Field, Val)
#define _MMC_MMCRSP40_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP4_ADDR(0),AND,OR,INV)
#define _MMC_MMCRSP40_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP4_ADDR(0), _MMC_MMCRSP4_##Field,AND,OR,INV)

#define _MMC_MMCRSP41_GET		  _PREG_GET(_MMC_MMCRSP4_ADDR(1)) 
#define _MMC_MMCRSP41_SET(Val)		  _PREG_SET(_MMC_MMCRSP4_ADDR(1),Val)
#define _MMC_MMCRSP41_FGET(Field)	  _PFIELD_GET(_MMC_MMCRSP4_ADDR(1), _MMC_MMCRSP4_##Field)
#define _MMC_MMCRSP41_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCRSP4_ADDR(1), _MMC_MMCRSP4_##Field, Val)
#define _MMC_MMCRSP41_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP4_ADDR(1),AND,OR,INV)
#define _MMC_MMCRSP41_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP4_ADDR(1), _MMC_MMCRSP4_##Field,AND,OR,INV)


/*--------------------- Register: MMCRSP5 -----------------------*/
#define _MMC_MMCRSP5_GET(devNum)			  _PREG_GET(_MMC_MMCRSP5_ADDR(devNum)) 
#define _MMC_MMCRSP5_SET(devNum,Val)		  _PREG_SET(_MMC_MMCRSP5_ADDR(devNum),Val)
#define _MMC_MMCRSP5_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCRSP5_ADDR(devNum), _MMC_MMCRSP5_##Field)
#define _MMC_MMCRSP5_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCRSP5_ADDR(devNum), _MMC_MMCRSP5_##Field, Val)
#define _MMC_MMCRSP5_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP5_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCRSP5_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP5_ADDR(devNum), _MMC_MMCRSP5_##Field,AND,OR,INV)

#define _MMC_MMCRSP50_GET		  _PREG_GET(_MMC_MMCRSP5_ADDR(0)) 
#define _MMC_MMCRSP50_SET(Val)		  _PREG_SET(_MMC_MMCRSP5_ADDR(0),Val)
#define _MMC_MMCRSP50_FGET(Field)	  _PFIELD_GET(_MMC_MMCRSP5_ADDR(0), _MMC_MMCRSP5_##Field)
#define _MMC_MMCRSP50_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCRSP5_ADDR(0), _MMC_MMCRSP5_##Field, Val)
#define _MMC_MMCRSP50_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP5_ADDR(0),AND,OR,INV)
#define _MMC_MMCRSP50_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP5_ADDR(0), _MMC_MMCRSP5_##Field,AND,OR,INV)

#define _MMC_MMCRSP51_GET		  _PREG_GET(_MMC_MMCRSP5_ADDR(1)) 
#define _MMC_MMCRSP51_SET(Val)		  _PREG_SET(_MMC_MMCRSP5_ADDR(1),Val)
#define _MMC_MMCRSP51_FGET(Field)	  _PFIELD_GET(_MMC_MMCRSP5_ADDR(1), _MMC_MMCRSP5_##Field)
#define _MMC_MMCRSP51_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCRSP5_ADDR(1), _MMC_MMCRSP5_##Field, Val)
#define _MMC_MMCRSP51_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP5_ADDR(1),AND,OR,INV)
#define _MMC_MMCRSP51_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP5_ADDR(1), _MMC_MMCRSP5_##Field,AND,OR,INV)


/*--------------------- Register: MMCRSP6 -----------------------*/
#define _MMC_MMCRSP6_GET(devNum)			  _PREG_GET(_MMC_MMCRSP6_ADDR(devNum)) 
#define _MMC_MMCRSP6_SET(devNum,Val)		  _PREG_SET(_MMC_MMCRSP6_ADDR(devNum),Val)
#define _MMC_MMCRSP6_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCRSP6_ADDR(devNum), _MMC_MMCRSP6_##Field)
#define _MMC_MMCRSP6_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCRSP6_ADDR(devNum), _MMC_MMCRSP6_##Field, Val)
#define _MMC_MMCRSP6_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP6_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCRSP6_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP6_ADDR(devNum), _MMC_MMCRSP6_##Field,AND,OR,INV)

#define _MMC_MMCRSP60_GET		  _PREG_GET(_MMC_MMCRSP6_ADDR(0)) 
#define _MMC_MMCRSP60_SET(Val)		  _PREG_SET(_MMC_MMCRSP6_ADDR(0),Val)
#define _MMC_MMCRSP60_FGET(Field)	  _PFIELD_GET(_MMC_MMCRSP6_ADDR(0), _MMC_MMCRSP6_##Field)
#define _MMC_MMCRSP60_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCRSP6_ADDR(0), _MMC_MMCRSP6_##Field, Val)
#define _MMC_MMCRSP60_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP6_ADDR(0),AND,OR,INV)
#define _MMC_MMCRSP60_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP6_ADDR(0), _MMC_MMCRSP6_##Field,AND,OR,INV)

#define _MMC_MMCRSP61_GET		  _PREG_GET(_MMC_MMCRSP6_ADDR(1)) 
#define _MMC_MMCRSP61_SET(Val)		  _PREG_SET(_MMC_MMCRSP6_ADDR(1),Val)
#define _MMC_MMCRSP61_FGET(Field)	  _PFIELD_GET(_MMC_MMCRSP6_ADDR(1), _MMC_MMCRSP6_##Field)
#define _MMC_MMCRSP61_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCRSP6_ADDR(1), _MMC_MMCRSP6_##Field, Val)
#define _MMC_MMCRSP61_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP6_ADDR(1),AND,OR,INV)
#define _MMC_MMCRSP61_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP6_ADDR(1), _MMC_MMCRSP6_##Field,AND,OR,INV)


/*--------------------- Register: MMCRSP7 -----------------------*/
#define _MMC_MMCRSP7_GET(devNum)			  _PREG_GET(_MMC_MMCRSP7_ADDR(devNum)) 
#define _MMC_MMCRSP7_SET(devNum,Val)		  _PREG_SET(_MMC_MMCRSP7_ADDR(devNum),Val)
#define _MMC_MMCRSP7_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCRSP7_ADDR(devNum), _MMC_MMCRSP7_##Field)
#define _MMC_MMCRSP7_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCRSP7_ADDR(devNum), _MMC_MMCRSP7_##Field, Val)
#define _MMC_MMCRSP7_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP7_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCRSP7_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP7_ADDR(devNum), _MMC_MMCRSP7_##Field,AND,OR,INV)

#define _MMC_MMCRSP70_GET		  _PREG_GET(_MMC_MMCRSP7_ADDR(0)) 
#define _MMC_MMCRSP70_SET(Val)		  _PREG_SET(_MMC_MMCRSP7_ADDR(0),Val)
#define _MMC_MMCRSP70_FGET(Field)	  _PFIELD_GET(_MMC_MMCRSP7_ADDR(0), _MMC_MMCRSP7_##Field)
#define _MMC_MMCRSP70_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCRSP7_ADDR(0), _MMC_MMCRSP7_##Field, Val)
#define _MMC_MMCRSP70_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP7_ADDR(0),AND,OR,INV)
#define _MMC_MMCRSP70_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP7_ADDR(0), _MMC_MMCRSP7_##Field,AND,OR,INV)

#define _MMC_MMCRSP71_GET		  _PREG_GET(_MMC_MMCRSP7_ADDR(1)) 
#define _MMC_MMCRSP71_SET(Val)		  _PREG_SET(_MMC_MMCRSP7_ADDR(1),Val)
#define _MMC_MMCRSP71_FGET(Field)	  _PFIELD_GET(_MMC_MMCRSP7_ADDR(1), _MMC_MMCRSP7_##Field)
#define _MMC_MMCRSP71_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCRSP7_ADDR(1), _MMC_MMCRSP7_##Field, Val)
#define _MMC_MMCRSP71_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCRSP7_ADDR(1),AND,OR,INV)
#define _MMC_MMCRSP71_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCRSP7_ADDR(1), _MMC_MMCRSP7_##Field,AND,OR,INV)


/*--------------------- Register: MMCDRSP -----------------------*/
#define _MMC_MMCDRSP_GET(devNum)			  _PREG_GET(_MMC_MMCDRSP_ADDR(devNum)) 
#define _MMC_MMCDRSP_SET(devNum,Val)		  _PREG_SET(_MMC_MMCDRSP_ADDR(devNum),Val)
#define _MMC_MMCDRSP_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCDRSP_ADDR(devNum), _MMC_MMCDRSP_##Field)
#define _MMC_MMCDRSP_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCDRSP_ADDR(devNum), _MMC_MMCDRSP_##Field, Val)
#define _MMC_MMCDRSP_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCDRSP_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCDRSP_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCDRSP_ADDR(devNum), _MMC_MMCDRSP_##Field,AND,OR,INV)

#define _MMC_MMCDRSP0_GET		  _PREG_GET(_MMC_MMCDRSP_ADDR(0)) 
#define _MMC_MMCDRSP0_SET(Val)		  _PREG_SET(_MMC_MMCDRSP_ADDR(0),Val)
#define _MMC_MMCDRSP0_FGET(Field)	  _PFIELD_GET(_MMC_MMCDRSP_ADDR(0), _MMC_MMCDRSP_##Field)
#define _MMC_MMCDRSP0_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCDRSP_ADDR(0), _MMC_MMCDRSP_##Field, Val)
#define _MMC_MMCDRSP0_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCDRSP_ADDR(0),AND,OR,INV)
#define _MMC_MMCDRSP0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCDRSP_ADDR(0), _MMC_MMCDRSP_##Field,AND,OR,INV)

#define _MMC_MMCDRSP1_GET		  _PREG_GET(_MMC_MMCDRSP_ADDR(1)) 
#define _MMC_MMCDRSP1_SET(Val)		  _PREG_SET(_MMC_MMCDRSP_ADDR(1),Val)
#define _MMC_MMCDRSP1_FGET(Field)	  _PFIELD_GET(_MMC_MMCDRSP_ADDR(1), _MMC_MMCDRSP_##Field)
#define _MMC_MMCDRSP1_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCDRSP_ADDR(1), _MMC_MMCDRSP_##Field, Val)
#define _MMC_MMCDRSP1_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCDRSP_ADDR(1),AND,OR,INV)
#define _MMC_MMCDRSP1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCDRSP_ADDR(1), _MMC_MMCDRSP_##Field,AND,OR,INV)


/*--------------------- Register: MMCCIDX -----------------------*/
#define _MMC_MMCCIDX_GET(devNum)			  _PREG_GET(_MMC_MMCCIDX_ADDR(devNum)) 
#define _MMC_MMCCIDX_SET(devNum,Val)		  _PREG_SET(_MMC_MMCCIDX_ADDR(devNum),Val)
#define _MMC_MMCCIDX_FGET(devNum,Field)	  _PFIELD_GET(_MMC_MMCCIDX_ADDR(devNum), _MMC_MMCCIDX_##Field)
#define _MMC_MMCCIDX_FSET(devNum,Field,Val)	  _PFIELD_SET(_MMC_MMCCIDX_ADDR(devNum), _MMC_MMCCIDX_##Field, Val)
#define _MMC_MMCCIDX_AOI(devNum,AND,OR,INV)	  _PREG_AOI(_MMC_MMCCIDX_ADDR(devNum),AND,OR,INV)
#define _MMC_MMCCIDX_FAOI(devNum,Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCCIDX_ADDR(devNum), _MMC_MMCCIDX_##Field,AND,OR,INV)

#define _MMC_MMCCIDX0_GET		  _PREG_GET(_MMC_MMCCIDX_ADDR(0)) 
#define _MMC_MMCCIDX0_SET(Val)		  _PREG_SET(_MMC_MMCCIDX_ADDR(0),Val)
#define _MMC_MMCCIDX0_FGET(Field)	  _PFIELD_GET(_MMC_MMCCIDX_ADDR(0), _MMC_MMCCIDX_##Field)
#define _MMC_MMCCIDX0_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCCIDX_ADDR(0), _MMC_MMCCIDX_##Field, Val)
#define _MMC_MMCCIDX0_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCCIDX_ADDR(0),AND,OR,INV)
#define _MMC_MMCCIDX0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCCIDX_ADDR(0), _MMC_MMCCIDX_##Field,AND,OR,INV)

#define _MMC_MMCCIDX1_GET		  _PREG_GET(_MMC_MMCCIDX_ADDR(1)) 
#define _MMC_MMCCIDX1_SET(Val)		  _PREG_SET(_MMC_MMCCIDX_ADDR(1),Val)
#define _MMC_MMCCIDX1_FGET(Field)	  _PFIELD_GET(_MMC_MMCCIDX_ADDR(1), _MMC_MMCCIDX_##Field)
#define _MMC_MMCCIDX1_FSET(Field,Val)	  _PFIELD_SET(_MMC_MMCCIDX_ADDR(1), _MMC_MMCCIDX_##Field, Val)
#define _MMC_MMCCIDX1_AOI(AND,OR,INV)	  _PREG_AOI(_MMC_MMCCIDX_ADDR(1),AND,OR,INV)
#define _MMC_MMCCIDX1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_MMC_MMCCIDX_ADDR(1), _MMC_MMCCIDX_##Field,AND,OR,INV)



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCRSP7 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCRSP7	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCRSP7_RSP	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCRSP7_RSP:	
\*----------------------------------------------------------------*/

#define _MMC_MMCRSP7_RSP_SHIFT		(000000u)
#define _MMC_MMCRSP7_RSP_MK(n)		(((Uint16)(n) & 0xffffu) << _MMC_MMCRSP7_RSP_SHIFT)
#define _MMC_MMCRSP7_RSP_MASK		(_MMC_MMCRSP7_RSP_MK(0xffffu))
#define _MMC_MMCRSP7_RSP_CLR		(~(_MMC_MMCRSP7_RSP_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCNBLC register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCNBLC	 - Note: Add description here
*
* Fields:
*	(R)   _MMC_MMCNBLC_NBLC	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _MMC_MMCNBLC_NBLC:	
\*----------------------------------------------------------------*/

#define _MMC_MMCNBLC_NBLC_SHIFT		(000000u)
#define _MMC_MMCNBLC_NBLC_MK(n)		(((Uint16)(n) & 0xffffu) << _MMC_MMCNBLC_NBLC_SHIFT)
#define _MMC_MMCNBLC_NBLC_MASK		(_MMC_MMCNBLC_NBLC_MK(0xffffu))
#define _MMC_MMCNBLC_NBLC_CLR		(~(_MMC_MMCNBLC_NBLC_MASK))


/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCDRSP register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCDRSP	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCDRSP_DRSP	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCDRSP_DRSP:	
\*----------------------------------------------------------------*/

#define _MMC_MMCDRSP_DRSP_SHIFT		(000000u)
#define _MMC_MMCDRSP_DRSP_MK(n)		(((Uint16)(n) & 0x00ffu) << _MMC_MMCDRSP_DRSP_SHIFT)
#define _MMC_MMCDRSP_DRSP_MASK		(_MMC_MMCDRSP_DRSP_MK(0x00ffu))
#define _MMC_MMCDRSP_DRSP_CLR		(~(_MMC_MMCDRSP_DRSP_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCCTL register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCCTL	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCCTL_CLKPRE	
*	(RW)   _MMC_MMCCTL_CLKPST	
*	(RW)   _MMC_MMCCTL_NACSKP	
*	(RW)   _MMC_MMCCTL_DMAEN	
*	(RW)   _MMC_MMCCTL_DATEG	
*	(RW)   _MMC_MMCCTL_WIDTH	
*	(RW)   _MMC_MMCCTL_CMDRST	
*	(RW)   _MMC_MMCCTL_DATRST	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCCTL_CLKPRE:	
\*----------------------------------------------------------------*/

#define _MMC_MMCCTL_CLKPRE_SHIFT		(0x000bu)
#define _MMC_MMCCTL_CLKPRE_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCCTL_CLKPRE_SHIFT)
#define _MMC_MMCCTL_CLKPRE_MASK		(_MMC_MMCCTL_CLKPRE_MK(0x0001u))
#define _MMC_MMCCTL_CLKPRE_CLR		(~(_MMC_MMCCTL_CLKPRE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCCTL_CLKPST:	
\*----------------------------------------------------------------*/

#define _MMC_MMCCTL_CLKPST_SHIFT		(0x000au)
#define _MMC_MMCCTL_CLKPST_MK(n)		(((Uint16)(n) & 000000u) << _MMC_MMCCTL_CLKPST_SHIFT)
#define _MMC_MMCCTL_CLKPST_MASK		(_MMC_MMCCTL_CLKPST_MK(000000u))
#define _MMC_MMCCTL_CLKPST_CLR		(~(_MMC_MMCCTL_CLKPST_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCCTL_NACSKP:	
\*----------------------------------------------------------------*/

#define _MMC_MMCCTL_NACSKP_SHIFT		(0x0009u)
#define _MMC_MMCCTL_NACSKP_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCCTL_NACSKP_SHIFT)
#define _MMC_MMCCTL_NACSKP_MASK		(_MMC_MMCCTL_NACSKP_MK(0x0001u))
#define _MMC_MMCCTL_NACSKP_CLR		(~(_MMC_MMCCTL_NACSKP_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCCTL_DMAEN:	
\*----------------------------------------------------------------*/

#define _MMC_MMCCTL_DMAEN_SHIFT		(0x0008u)
#define _MMC_MMCCTL_DMAEN_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCCTL_DMAEN_SHIFT)
#define _MMC_MMCCTL_DMAEN_MASK		(_MMC_MMCCTL_DMAEN_MK(0x0001u))
#define _MMC_MMCCTL_DMAEN_CLR		(~(_MMC_MMCCTL_DMAEN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCCTL_DATEG:	
\*----------------------------------------------------------------*/

#define _MMC_MMCCTL_DATEG_SHIFT		(0x0006u)
#define _MMC_MMCCTL_DATEG_MK(n)		(((Uint16)(n) & 0x0003u) << _MMC_MMCCTL_DATEG_SHIFT)
#define _MMC_MMCCTL_DATEG_MASK		(_MMC_MMCCTL_DATEG_MK(0x0003u))
#define _MMC_MMCCTL_DATEG_CLR		      (~(_MMC_MMCCTL_DATEG_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCCTL_CSEN:	
\*----------------------------------------------------------------*/

#define _MMC_MMCCTL_CSEN_SHIFT		(0x0004u)
#define _MMC_MMCCTL_CSEN_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCCTL_CSEN_SHIFT)
#define _MMC_MMCCTL_CSEN_MASK		      (_MMC_MMCCTL_CSEN_MK(0x0001u))
#define _MMC_MMCCTL_CSEN_CLR		      (~(_MMC_MMCCTL_CSEN_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCCTL_WIDTH:	
\*----------------------------------------------------------------*/

#define _MMC_MMCCTL_WIDTH_SHIFT		(0x0002u)
#define _MMC_MMCCTL_WIDTH_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCCTL_WIDTH_SHIFT)
#define _MMC_MMCCTL_WIDTH_MASK		(_MMC_MMCCTL_WIDTH_MK(0x0001u))
#define _MMC_MMCCTL_WIDTH_CLR		      (~(_MMC_MMCCTL_WIDTH_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCCTL_CMDRST:	
\*----------------------------------------------------------------*/

#define _MMC_MMCCTL_CMDRST_SHIFT		(0x0001u)
#define _MMC_MMCCTL_CMDRST_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCCTL_CMDRST_SHIFT)
#define _MMC_MMCCTL_CMDRST_MASK		(_MMC_MMCCTL_CMDRST_MK(0x0001u))
#define _MMC_MMCCTL_CMDRST_CLR		(~(_MMC_MMCCTL_CMDRST_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCCTL_DATRST:	
\*----------------------------------------------------------------*/

#define _MMC_MMCCTL_DATRST_SHIFT		(000000u)
#define _MMC_MMCCTL_DATRST_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCCTL_DATRST_SHIFT)
#define _MMC_MMCCTL_DATRST_MASK		(_MMC_MMCCTL_DATRST_MK(0x0001u))
#define _MMC_MMCCTL_DATRST_CLR		(~(_MMC_MMCCTL_DATRST_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCTOD register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCTOD	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCTOD_TOD	
*
\******************************************************************************/

/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCTOD_TOD:	
\*----------------------------------------------------------------*/

#define _MMC_MMCTOD_TOD_SHIFT		(000000u)
#define _MMC_MMCTOD_TOD_MK(n)		(((Uint16)(n) & 0xffffu) << _MMC_MMCTOD_TOD_SHIFT)
#define _MMC_MMCTOD_TOD_MASK		(_MMC_MMCTOD_TOD_MK(0xffffu))
#define _MMC_MMCTOD_TOD_CLR		(~(_MMC_MMCTOD_TOD_MASK))

/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCIE register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCIE	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCIE_DATEG	
*	(RW)   _MMC_MMCIE_DRRDY	
*	(RW)   _MMC_MMCIE_DXRDY	
*	(RW)   _MMC_MMCIE_CRCRS	
*	(RW)   _MMC_MMCIE_CRCRD	
*	(RW)   _MMC_MMCIE_CRCWR	
*	(RW)   _MMC_MMCIE_TOUTRS	
*	(RW)   _MMC_MMCIE_TOUTRD	
*	(RW)   _MMC_MMCIE_RSPDNE	
*	(RW)   _MMC_MMCIE_BSYDNE	
*	(RW)   _MMC_MMCIE_DATDNE	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCIE_DATEG:	
\*----------------------------------------------------------------*/

#define _MMC_MMCIE_DATEG_SHIFT		(0x000bu)
#define _MMC_MMCIE_DATEG_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCIE_DATEG_SHIFT)
#define _MMC_MMCIE_DATEG_MASK		(_MMC_MMCIE_DATEG_MK(0x0001u))
#define _MMC_MMCIE_DATEG_CLR		(~(_MMC_MMCIE_DATEG_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCIE_DRRDY:	
\*----------------------------------------------------------------*/

#define _MMC_MMCIE_DRRDY_SHIFT		(0x000au)
#define _MMC_MMCIE_DRRDY_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCIE_DRRDY_SHIFT)
#define _MMC_MMCIE_DRRDY_MASK		(_MMC_MMCIE_DRRDY_MK(0x0001u))
#define _MMC_MMCIE_DRRDY_CLR		(~(_MMC_MMCIE_DRRDY_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCIE_DXRDY:	
\*----------------------------------------------------------------*/

#define _MMC_MMCIE_DXRDY_SHIFT		(0x0009u)
#define _MMC_MMCIE_DXRDY_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCIE_DXRDY_SHIFT)
#define _MMC_MMCIE_DXRDY_MASK		(_MMC_MMCIE_DXRDY_MK(0x0001u))
#define _MMC_MMCIE_DXRDY_CLR		(~(_MMC_MMCIE_DXRDY_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCIE_CRCRS:	
\*----------------------------------------------------------------*/

#define _MMC_MMCIE_CRCRS_SHIFT		(0x0007u)
#define _MMC_MMCIE_CRCRS_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCIE_CRCRS_SHIFT)
#define _MMC_MMCIE_CRCRS_MASK		(_MMC_MMCIE_CRCRS_MK(0x0001u))
#define _MMC_MMCIE_CRCRS_CLR		(~(_MMC_MMCIE_CRCRS_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCIE_CRCRD:	
\*----------------------------------------------------------------*/

#define _MMC_MMCIE_CRCRD_SHIFT		(0x0006u)
#define _MMC_MMCIE_CRCRD_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCIE_CRCRD_SHIFT)
#define _MMC_MMCIE_CRCRD_MASK		(_MMC_MMCIE_CRCRD_MK(0x0001u))
#define _MMC_MMCIE_CRCRD_CLR		(~(_MMC_MMCIE_CRCRD_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCIE_CRCWR:	
\*----------------------------------------------------------------*/

#define _MMC_MMCIE_CRCWR_SHIFT		(0x0005u)
#define _MMC_MMCIE_CRCWR_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCIE_CRCWR_SHIFT)
#define _MMC_MMCIE_CRCWR_MASK		(_MMC_MMCIE_CRCWR_MK(0x0001u))
#define _MMC_MMCIE_CRCWR_CLR		(~(_MMC_MMCIE_CRCWR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCIE_TOUTRS:	
\*----------------------------------------------------------------*/

#define _MMC_MMCIE_TOUTRS_SHIFT		(0x0004u)
#define _MMC_MMCIE_TOUTRS_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCIE_TOUTRS_SHIFT)
#define _MMC_MMCIE_TOUTRS_MASK		(_MMC_MMCIE_TOUTRS_MK(0x0001u))
#define _MMC_MMCIE_TOUTRS_CLR		(~(_MMC_MMCIE_TOUTRS_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCIE_TOUTRD:	
\*----------------------------------------------------------------*/

#define _MMC_MMCIE_TOUTRD_SHIFT		(0x0003u)
#define _MMC_MMCIE_TOUTRD_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCIE_TOUTRD_SHIFT)
#define _MMC_MMCIE_TOUTRD_MASK		(_MMC_MMCIE_TOUTRD_MK(0x0001u))
#define _MMC_MMCIE_TOUTRD_CLR		(~(_MMC_MMCIE_TOUTRD_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCIE_RSPDNE:	
\*----------------------------------------------------------------*/

#define _MMC_MMCIE_RSPDNE_SHIFT		(0x0002u)
#define _MMC_MMCIE_RSPDNE_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCIE_RSPDNE_SHIFT)
#define _MMC_MMCIE_RSPDNE_MASK		(_MMC_MMCIE_RSPDNE_MK(0x0001u))
#define _MMC_MMCIE_RSPDNE_CLR		(~(_MMC_MMCIE_RSPDNE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCIE_BSYDNE:	
\*----------------------------------------------------------------*/

#define _MMC_MMCIE_BSYDNE_SHIFT		(0x0001u)
#define _MMC_MMCIE_BSYDNE_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCIE_BSYDNE_SHIFT)
#define _MMC_MMCIE_BSYDNE_MASK		(_MMC_MMCIE_BSYDNE_MK(0x0001u))
#define _MMC_MMCIE_BSYDNE_CLR		(~(_MMC_MMCIE_BSYDNE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCIE_DATDNE:	
\*----------------------------------------------------------------*/

#define _MMC_MMCIE_DATDNE_SHIFT		(000000u)
#define _MMC_MMCIE_DATDNE_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCIE_DATDNE_SHIFT)
#define _MMC_MMCIE_DATDNE_MASK		(_MMC_MMCIE_DATDNE_MK(0x0001u))
#define _MMC_MMCIE_DATDNE_CLR		(~(_MMC_MMCIE_DATDNE_MASK))




/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCNBLK register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCNBLK	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCNBLK_NBLK	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCNBLK_NBLK:	
\*----------------------------------------------------------------*/

#define _MMC_MMCNBLK_NBLK_SHIFT		(000000u)
#define _MMC_MMCNBLK_NBLK_MK(n)		(((Uint16)(n) & 0xffffu) << _MMC_MMCNBLK_NBLK_SHIFT)
#define _MMC_MMCNBLK_NBLK_MASK		(_MMC_MMCNBLK_NBLK_MK(0xffffu))
#define _MMC_MMCNBLK_NBLK_CLR		(~(_MMC_MMCNBLK_NBLK_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCDRR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCDRR	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCDRR_DRR	
*
\******************************************************************************/


/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCDRR_DRR:	
\*----------------------------------------------------------------*/

#define _MMC_MMCDRR_DRR_SHIFT		(000000u)
#define _MMC_MMCDRR_DRR_MK(n)		(((Uint16)(n) & 0xffffu) << _MMC_MMCDRR_DRR_SHIFT)
#define _MMC_MMCDRR_DRR_MASK		(_MMC_MMCDRR_DRR_MK(0xffffu))
#define _MMC_MMCDRR_DRR_CLR		(~(_MMC_MMCDRR_DRR_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCFCLK register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCFCLK	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCFCLK_IDLEEN	
*	(RW)   _MMC_MMCFCLK_FDIV	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCFCLK_IDLEEN:	
\*----------------------------------------------------------------*/

#define _MMC_MMCFCLK_IDLEEN_SHIFT		(0x0008u)
#define _MMC_MMCFCLK_IDLEEN_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCFCLK_IDLEEN_SHIFT)
#define _MMC_MMCFCLK_IDLEEN_MASK		(_MMC_MMCFCLK_IDLEEN_MK(0x0001u))
#define _MMC_MMCFCLK_IDLEEN_CLR		(~(_MMC_MMCFCLK_IDLEEN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCFCLK_FDIV:	
\*----------------------------------------------------------------*/

#define _MMC_MMCFCLK_FDIV_SHIFT		(000000u)
#define _MMC_MMCFCLK_FDIV_MK(n)		(((Uint16)(n) & 0x00ffu) << _MMC_MMCFCLK_FDIV_SHIFT)
#define _MMC_MMCFCLK_FDIV_MASK		(_MMC_MMCFCLK_FDIV_MK(0x00ffu))
#define _MMC_MMCFCLK_FDIV_CLR		(~(_MMC_MMCFCLK_FDIV_MASK))

/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCBLEN register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCBLEN	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCBLEN_BLEN	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCBLEN_BLEN:	
\*----------------------------------------------------------------*/

#define _MMC_MMCBLEN_BLEN_SHIFT		(000000u)
#define _MMC_MMCBLEN_BLEN_MK(n)		(((Uint16)(n) & 0x0fffu) << _MMC_MMCBLEN_BLEN_SHIFT)
#define _MMC_MMCBLEN_BLEN_MASK		(_MMC_MMCBLEN_BLEN_MK(0x0fffu))
#define _MMC_MMCBLEN_BLEN_CLR		(~(_MMC_MMCBLEN_BLEN_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCCIDX register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCCIDX	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCCIDX_CIDX	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCCIDX_CIDX:	
\*----------------------------------------------------------------*/

#define _MMC_MMCCIDX_CIDX_SHIFT		(000000u)
#define _MMC_MMCCIDX_CIDX_MK(n)		(((Uint16)(n) & 0x00ffu) << _MMC_MMCCIDX_CIDX_SHIFT)
#define _MMC_MMCCIDX_CIDX_MASK		(_MMC_MMCCIDX_CIDX_MK(0x00ffu))
#define _MMC_MMCCIDX_CIDX_CLR		(~(_MMC_MMCCIDX_CIDX_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCCMD register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCCMD	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCCMD_DCLR	
*	(RW)   _MMC_MMCCMD_INIT	
*	(RW)   _MMC_MMCCMD_DATA	
*	(RW)   _MMC_MMCCMD_STREAM	
*	(RW)   _MMC_MMCCMD_WRITE	
*	(RW)   _MMC_MMCCMD_RSPFMT	
*	(RW)   _MMC_MMCCMD_BSYEXP	
*	(RW)   _MMC_MMCCMD_CMD	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCCMD_DCLR:	
\*----------------------------------------------------------------*/

#define _MMC_MMCCMD_DCLR_SHIFT		(0x000fu)
#define _MMC_MMCCMD_DCLR_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCCMD_DCLR_SHIFT)
#define _MMC_MMCCMD_DCLR_MASK		(_MMC_MMCCMD_DCLR_MK(0x0001u))
#define _MMC_MMCCMD_DCLR_CLR		(~(_MMC_MMCCMD_DCLR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCCMD_INIT:	
\*----------------------------------------------------------------*/

#define _MMC_MMCCMD_INIT_SHIFT		(0x000eu)
#define _MMC_MMCCMD_INIT_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCCMD_INIT_SHIFT)
#define _MMC_MMCCMD_INIT_MASK		(_MMC_MMCCMD_INIT_MK(0x0001u))
#define _MMC_MMCCMD_INIT_CLR		(~(_MMC_MMCCMD_INIT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCCMD_DATA:	
\*----------------------------------------------------------------*/

#define _MMC_MMCCMD_DATA_SHIFT		(0x000du)
#define _MMC_MMCCMD_DATA_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCCMD_DATA_SHIFT)
#define _MMC_MMCCMD_DATA_MASK		(_MMC_MMCCMD_DATA_MK(0x0001u))
#define _MMC_MMCCMD_DATA_CLR		(~(_MMC_MMCCMD_DATA_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCCMD_STREAM:	
\*----------------------------------------------------------------*/

#define _MMC_MMCCMD_STREAM_SHIFT		(0x000cu)
#define _MMC_MMCCMD_STREAM_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCCMD_STREAM_SHIFT)
#define _MMC_MMCCMD_STREAM_MASK		(_MMC_MMCCMD_STREAM_MK(0x0001u))
#define _MMC_MMCCMD_STREAM_CLR		(~(_MMC_MMCCMD_STREAM_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCCMD_WRITE:	
\*----------------------------------------------------------------*/

#define _MMC_MMCCMD_WRITE_SHIFT		(0x000bu)
#define _MMC_MMCCMD_WRITE_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCCMD_WRITE_SHIFT)
#define _MMC_MMCCMD_WRITE_MASK		(_MMC_MMCCMD_WRITE_MK(0x0001u))
#define _MMC_MMCCMD_WRITE_CLR		(~(_MMC_MMCCMD_WRITE_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCCMD_RSPFMT:	
\*----------------------------------------------------------------*/

#define _MMC_MMCCMD_RSPFMT_SHIFT		(0x0009u)
#define _MMC_MMCCMD_RSPFMT_MK(n)		(((Uint16)(n) & 0x0003u) << _MMC_MMCCMD_RSPFMT_SHIFT)
#define _MMC_MMCCMD_RSPFMT_MASK		(_MMC_MMCCMD_RSPFMT_MK(0x0003u))
#define _MMC_MMCCMD_RSPFMT_CLR		(~(_MMC_MMCCMD_RSPFMT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCCMD_BSYEXP:	
\*----------------------------------------------------------------*/

#define _MMC_MMCCMD_BSYEXP_SHIFT		(0x0008u)
#define _MMC_MMCCMD_BSYEXP_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCCMD_BSYEXP_SHIFT)
#define _MMC_MMCCMD_BSYEXP_MASK		(_MMC_MMCCMD_BSYEXP_MK(0x0001u))
#define _MMC_MMCCMD_BSYEXP_CLR		(~(_MMC_MMCCMD_BSYEXP_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCCMD_CMD:	
\*----------------------------------------------------------------*/

#define _MMC_MMCCMD_CMD_SHIFT		(000000u)
#define _MMC_MMCCMD_CMD_MK(n)		(((Uint16)(n) & 0x003fu) << _MMC_MMCCMD_CMD_SHIFT)
#define _MMC_MMCCMD_CMD_MASK		(_MMC_MMCCMD_CMD_MK(0x003fu))
#define _MMC_MMCCMD_CMD_CLR		(~(_MMC_MMCCMD_CMD_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCCLK register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCCLK	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCCLK_CLKEN	
*	(RW)   _MMC_MMCCLK_CDIV	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCCLK_CLKEN:	
\*----------------------------------------------------------------*/

#define _MMC_MMCCLK_CLKEN_SHIFT		(0x0008u)
#define _MMC_MMCCLK_CLKEN_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCCLK_CLKEN_SHIFT)
#define _MMC_MMCCLK_CLKEN_MASK		(_MMC_MMCCLK_CLKEN_MK(0x0001u))
#define _MMC_MMCCLK_CLKEN_CLR		(~(_MMC_MMCCLK_CLKEN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCCLK_CDIV:	
\*----------------------------------------------------------------*/

#define _MMC_MMCCLK_CDIV_SHIFT		(000000u)
#define _MMC_MMCCLK_CDIV_MK(n)		(((Uint16)(n) & 0x000fu) << _MMC_MMCCLK_CDIV_SHIFT)
#define _MMC_MMCCLK_CDIV_MASK		(_MMC_MMCCLK_CDIV_MK(0x000fu))
#define _MMC_MMCCLK_CDIV_CLR		(~(_MMC_MMCCLK_CDIV_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCTOR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCTOR	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCTOR_TOR	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCTOR_TOR:	
\*----------------------------------------------------------------*/

#define _MMC_MMCTOR_TOR_SHIFT		(000000u)
#define _MMC_MMCTOR_TOR_MK(n)		(((Uint16)(n) & 0x00ffu) << _MMC_MMCTOR_TOR_SHIFT)
#define _MMC_MMCTOR_TOR_MASK		(_MMC_MMCTOR_TOR_MK(0x00ffu))
#define _MMC_MMCTOR_TOR_CLR		(~(_MMC_MMCTOR_TOR_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCDXR register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCDXR	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCDXR_DXR	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCDXR_DXR:	
\*----------------------------------------------------------------*/

#define _MMC_MMCDXR_DXR_SHIFT		(000000u)
#define _MMC_MMCDXR_DXR_MK(n)		(((Uint16)(n) & 0xffffu) << _MMC_MMCDXR_DXR_SHIFT)
#define _MMC_MMCDXR_DXR_MASK		(_MMC_MMCDXR_DXR_MK(0xffffu))
#define _MMC_MMCDXR_DXR_CLR		(~(_MMC_MMCDXR_DXR_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCARGH register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCARGH	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCARGH_ARGH	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCARGH_ARGH:	
\*----------------------------------------------------------------*/

#define _MMC_MMCARGH_ARGH_SHIFT		(000000u)
#define _MMC_MMCARGH_ARGH_MK(n)		(((Uint16)(n) & 0xffffu) << _MMC_MMCARGH_ARGH_SHIFT)
#define _MMC_MMCARGH_ARGH_MASK		(_MMC_MMCARGH_ARGH_MK(0xffffu))
#define _MMC_MMCARGH_ARGH_CLR		(~(_MMC_MMCARGH_ARGH_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCST0 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCST0	 - Note: Add description here
*
* Fields:
*	(R)   _MMC_MMCST0_DATEG	
*	(R)   _MMC_MMCST0_DRRDY	
*	(R)   _MMC_MMCST0_DXRDY	
*	(R)   _MMC_MMCST0_CRCRS	
*	(R)   _MMC_MMCST0_CRCRD	
*	(R)   _MMC_MMCST0_CRCWR	
*	(R)   _MMC_MMCST0_TOUTRS	
*	(R)   _MMC_MMCST0_TOUTRD	
*	(R)   _MMC_MMCST0_RSPDNE	
*	(R)   _MMC_MMCST0_BSYDNE	
*	(R)   _MMC_MMCST0_DATDNE	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _MMC_MMCST0_DATEG:	
\*----------------------------------------------------------------*/

#define _MMC_MMCST0_DATEG_SHIFT		(0x000bu)
#define _MMC_MMCST0_DATEG_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCST0_DATEG_SHIFT)
#define _MMC_MMCST0_DATEG_MASK		(_MMC_MMCST0_DATEG_MK(0x0001u))
#define _MMC_MMCST0_DATEG_CLR		(~(_MMC_MMCST0_DATEG_MASK))



/*----------------------------------------------------------------*\
*   (R)  _MMC_MMCST0_DRRDY:	
\*----------------------------------------------------------------*/

#define _MMC_MMCST0_DRRDY_SHIFT		(0x000au)
#define _MMC_MMCST0_DRRDY_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCST0_DRRDY_SHIFT)
#define _MMC_MMCST0_DRRDY_MASK		(_MMC_MMCST0_DRRDY_MK(0x0001u))
#define _MMC_MMCST0_DRRDY_CLR		(~(_MMC_MMCST0_DRRDY_MASK))



/*----------------------------------------------------------------*\
*   (R)  _MMC_MMCST0_DXRDY:	
\*----------------------------------------------------------------*/

#define _MMC_MMCST0_DXRDY_SHIFT		(0x0009u)
#define _MMC_MMCST0_DXRDY_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCST0_DXRDY_SHIFT)
#define _MMC_MMCST0_DXRDY_MASK		(_MMC_MMCST0_DXRDY_MK(0x0001u))
#define _MMC_MMCST0_DXRDY_CLR		(~(_MMC_MMCST0_DXRDY_MASK))


/*----------------------------------------------------------------*\
*   (R)  _MMC_MMCST0_CRCRS:	
\*----------------------------------------------------------------*/

#define _MMC_MMCST0_CRCRS_SHIFT		(0x0007u)
#define _MMC_MMCST0_CRCRS_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCST0_CRCRS_SHIFT)
#define _MMC_MMCST0_CRCRS_MASK		(_MMC_MMCST0_CRCRS_MK(0x0001u))
#define _MMC_MMCST0_CRCRS_CLR		      (~(_MMC_MMCST0_CRCRS_MASK))



/*----------------------------------------------------------------*\
*   (R)  _MMC_MMCST0_CRCRD:	
\*----------------------------------------------------------------*/

#define _MMC_MMCST0_CRCRD_SHIFT		(0x0006u)
#define _MMC_MMCST0_CRCRD_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCST0_CRCRD_SHIFT)
#define _MMC_MMCST0_CRCRD_MASK		(_MMC_MMCST0_CRCRD_MK(0x0001u))
#define _MMC_MMCST0_CRCRD_CLR		(~(_MMC_MMCST0_CRCRD_MASK))



/*----------------------------------------------------------------*\
*   (R)  _MMC_MMCST0_CRCWR:	
\*----------------------------------------------------------------*/

#define _MMC_MMCST0_CRCWR_SHIFT		(0x0005u)
#define _MMC_MMCST0_CRCWR_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCST0_CRCWR_SHIFT)
#define _MMC_MMCST0_CRCWR_MASK		(_MMC_MMCST0_CRCWR_MK(0x0001u))
#define _MMC_MMCST0_CRCWR_CLR		(~(_MMC_MMCST0_CRCWR_MASK))



/*----------------------------------------------------------------*\
*   (R)  _MMC_MMCST0_TOUTRS:	
\*----------------------------------------------------------------*/

#define _MMC_MMCST0_TOUTRS_SHIFT		(0x0004u)
#define _MMC_MMCST0_TOUTRS_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCST0_TOUTRS_SHIFT)
#define _MMC_MMCST0_TOUTRS_MASK		(_MMC_MMCST0_TOUTRS_MK(0x0001u))
#define _MMC_MMCST0_TOUTRS_CLR		(~(_MMC_MMCST0_TOUTRS_MASK))



/*----------------------------------------------------------------*\
*   (R)  _MMC_MMCST0_TOUTRD:	
\*----------------------------------------------------------------*/

#define _MMC_MMCST0_TOUTRD_SHIFT		(0x0003u)
#define _MMC_MMCST0_TOUTRD_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCST0_TOUTRD_SHIFT)
#define _MMC_MMCST0_TOUTRD_MASK		(_MMC_MMCST0_TOUTRD_MK(0x0001u))
#define _MMC_MMCST0_TOUTRD_CLR		(~(_MMC_MMCST0_TOUTRD_MASK))



/*----------------------------------------------------------------*\
*   (R)  _MMC_MMCST0_RSPDNE:	
\*----------------------------------------------------------------*/

#define _MMC_MMCST0_RSPDNE_SHIFT		(0x0002u)
#define _MMC_MMCST0_RSPDNE_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCST0_RSPDNE_SHIFT)
#define _MMC_MMCST0_RSPDNE_MASK		(_MMC_MMCST0_RSPDNE_MK(0x0001u))
#define _MMC_MMCST0_RSPDNE_CLR		(~(_MMC_MMCST0_RSPDNE_MASK))



/*----------------------------------------------------------------*\
*   (R)  _MMC_MMCST0_BSYDNE:	
\*----------------------------------------------------------------*/

#define _MMC_MMCST0_BSYDNE_SHIFT		(0x0001u)
#define _MMC_MMCST0_BSYDNE_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCST0_BSYDNE_SHIFT)
#define _MMC_MMCST0_BSYDNE_MASK		(_MMC_MMCST0_BSYDNE_MK(0x0001u))
#define _MMC_MMCST0_BSYDNE_CLR		(~(_MMC_MMCST0_BSYDNE_MASK))



/*----------------------------------------------------------------*\
*   (R)  _MMC_MMCST0_DATDNE:	
\*----------------------------------------------------------------*/

#define _MMC_MMCST0_DATDNE_SHIFT		(0x0000u)
#define _MMC_MMCST0_DATDNE_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCST0_DATDNE_SHIFT)
#define _MMC_MMCST0_DATDNE_MASK		(_MMC_MMCST0_DATDNE_MK(0x0001u))
#define _MMC_MMCST0_DATDNE_CLR		(~(_MMC_MMCST0_DATDNE_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCRSP0 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCRSP0	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCRSP0_RSP	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCRSP0_RSP:	
\*----------------------------------------------------------------*/

#define _MMC_MMCRSP0_RSP_SHIFT		(000000u)
#define _MMC_MMCRSP0_RSP_MK(n)		(((Uint16)(n) & 0xffffu) << _MMC_MMCRSP0_RSP_SHIFT)
#define _MMC_MMCRSP0_RSP_MASK		(_MMC_MMCRSP0_RSP_MK(0xffffu))
#define _MMC_MMCRSP0_RSP_CLR		(~(_MMC_MMCRSP0_RSP_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCST1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCST1	 - Note: Add description here
*
* Fields:
*	(R)   _MMC_MMCST1_DAT	
*	(R)   _MMC_MMCST1_DXEMP	
*	(R)   _MMC_MMCST1_DRFUL	
*	(R)   _MMC_MMCST1_CLKSTP	
*	(R)   _MMC_MMCST1_BUSY	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (R)  _MMC_MMCST1_DAT:	
\*----------------------------------------------------------------*/

#define _MMC_MMCST1_DAT_SHIFT		(0x0004u)
#define _MMC_MMCST1_DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCST1_DAT_SHIFT)
#define _MMC_MMCST1_DAT_MASK		(_MMC_MMCST1_DAT_MK(0x0001u))
#define _MMC_MMCST1_DAT_CLR		(~(_MMC_MMCST1_DAT_MASK))



/*----------------------------------------------------------------*\
*   (R)  _MMC_MMCST1_DXEMP:	
\*----------------------------------------------------------------*/

#define _MMC_MMCST1_DXEMP_SHIFT		(0x0003u)
#define _MMC_MMCST1_DXEMP_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCST1_DXEMP_SHIFT)
#define _MMC_MMCST1_DXEMP_MASK		(_MMC_MMCST1_DXEMP_MK(0x0001u))
#define _MMC_MMCST1_DXEMP_CLR		(~(_MMC_MMCST1_DXEMP_MASK))



/*----------------------------------------------------------------*\
*   (R)  _MMC_MMCST1_DRFUL:	
\*----------------------------------------------------------------*/

#define _MMC_MMCST1_DRFUL_SHIFT		(0x0002u)
#define _MMC_MMCST1_DRFUL_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCST1_DRFUL_SHIFT)
#define _MMC_MMCST1_DRFUL_MASK		(_MMC_MMCST1_DRFUL_MK(0x0001u))
#define _MMC_MMCST1_DRFUL_CLR		(~(_MMC_MMCST1_DRFUL_MASK))



/*----------------------------------------------------------------*\
*   (R)  _MMC_MMCST1_CLKSTP:	
\*----------------------------------------------------------------*/

#define _MMC_MMCST1_CLKSTP_SHIFT		(0x0001u)
#define _MMC_MMCST1_CLKSTP_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCST1_CLKSTP_SHIFT)
#define _MMC_MMCST1_CLKSTP_MASK		(_MMC_MMCST1_CLKSTP_MK(0x0001u))
#define _MMC_MMCST1_CLKSTP_CLR		(~(_MMC_MMCST1_CLKSTP_MASK))



/*----------------------------------------------------------------*\
*   (R)  _MMC_MMCST1_BUSY:	
\*----------------------------------------------------------------*/

#define _MMC_MMCST1_BUSY_SHIFT		(000000u)
#define _MMC_MMCST1_BUSY_MK(n)		(((Uint16)(n) & 0x0001u) << _MMC_MMCST1_BUSY_SHIFT)
#define _MMC_MMCST1_BUSY_MASK		(_MMC_MMCST1_BUSY_MK(0x0001u))
#define _MMC_MMCST1_BUSY_CLR		(~(_MMC_MMCST1_BUSY_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCRSP1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCRSP1	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCRSP1_RSP	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCRSP1_RSP:	
\*----------------------------------------------------------------*/

#define _MMC_MMCRSP1_RSP_SHIFT		(000000u)
#define _MMC_MMCRSP1_RSP_MK(n)		(((Uint16)(n) & 0xffffu) << _MMC_MMCRSP1_RSP_SHIFT)
#define _MMC_MMCRSP1_RSP_MASK		(_MMC_MMCRSP1_RSP_MK(0xffffu))
#define _MMC_MMCRSP1_RSP_CLR		(~(_MMC_MMCRSP1_RSP_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCRSP2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCRSP2	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCRSP2_RSP	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCRSP2_RSP:	
\*----------------------------------------------------------------*/

#define _MMC_MMCRSP2_RSP_SHIFT		(000000u)
#define _MMC_MMCRSP2_RSP_MK(n)		(((Uint16)(n) & 0xffffu) << _MMC_MMCRSP2_RSP_SHIFT)
#define _MMC_MMCRSP2_RSP_MASK		(_MMC_MMCRSP2_RSP_MK(0xffffu))
#define _MMC_MMCRSP2_RSP_CLR		(~(_MMC_MMCRSP2_RSP_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCARGL register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCARGL	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCARGL_ARGL	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCARGL_ARGL:	
\*----------------------------------------------------------------*/

#define _MMC_MMCARGL_ARGL_SHIFT		(000000u)
#define _MMC_MMCARGL_ARGL_MK(n)		(((Uint16)(n) & 0xffffu) << _MMC_MMCARGL_ARGL_SHIFT)
#define _MMC_MMCARGL_ARGL_MASK		(_MMC_MMCARGL_ARGL_MK(0xffffu))
#define _MMC_MMCARGL_ARGL_CLR		(~(_MMC_MMCARGL_ARGL_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCRSP3 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCRSP3	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCRSP3_RSP	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCRSP3_RSP:	
\*----------------------------------------------------------------*/

#define _MMC_MMCRSP3_RSP_SHIFT		(000000u)
#define _MMC_MMCRSP3_RSP_MK(n)		(((Uint16)(n) & 0xffffu) << _MMC_MMCRSP3_RSP_SHIFT)
#define _MMC_MMCRSP3_RSP_MASK		(_MMC_MMCRSP3_RSP_MK(0xffffu))
#define _MMC_MMCRSP3_RSP_CLR		(~(_MMC_MMCRSP3_RSP_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCRSP4 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCRSP4	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCRSP4_RSP	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCRSP4_RSP:	
\*----------------------------------------------------------------*/

#define _MMC_MMCRSP4_RSP_SHIFT		(000000u)
#define _MMC_MMCRSP4_RSP_MK(n)		(((Uint16)(n) & 0xffffu) << _MMC_MMCRSP4_RSP_SHIFT)
#define _MMC_MMCRSP4_RSP_MASK		(_MMC_MMCRSP4_RSP_MK(0xffffu))
#define _MMC_MMCRSP4_RSP_CLR		(~(_MMC_MMCRSP4_RSP_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCRSP5 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCRSP5	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCRSP5_RSP	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCRSP5_RSP:	
\*----------------------------------------------------------------*/

#define _MMC_MMCRSP5_RSP_SHIFT		(000000u)
#define _MMC_MMCRSP5_RSP_MK(n)		(((Uint16)(n) & 0xffffu) << _MMC_MMCRSP5_RSP_SHIFT)
#define _MMC_MMCRSP5_RSP_MASK		(_MMC_MMCRSP5_RSP_MK(0xffffu))
#define _MMC_MMCRSP5_RSP_CLR		(~(_MMC_MMCRSP5_RSP_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the MMCRSP6 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _MMC_MMCRSP6	 - Note: Add description here
*
* Fields:
*	(RW)   _MMC_MMCRSP6_RSP	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _MMC_MMCRSP6_RSP:	
\*----------------------------------------------------------------*/

#define _MMC_MMCRSP6_RSP_SHIFT		(000000u)
#define _MMC_MMCRSP6_RSP_MK(n)		(((Uint16)(n) & 0xffffu) << _MMC_MMCRSP6_RSP_SHIFT)
#define _MMC_MMCRSP6_RSP_MASK		(_MMC_MMCRSP6_RSP_MK(0xffffu))
#define _MMC_MMCRSP6_RSP_CLR		(~(_MMC_MMCRSP6_RSP_MASK))


#endif  /* _MMC_SUPPORT  */

#endif  /* _CSL_MMCHAL_H  */

/******************************************************************************\
*     
*      End of csl_mmchal.h 
*
\******************************************************************************/
