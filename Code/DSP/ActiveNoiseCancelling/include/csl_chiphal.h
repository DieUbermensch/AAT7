/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... CHIP
* FILENAME...... csl_chiphal.h
* DATE CREATED.. Thu 08/19/1999
* PROJECT....... Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:   08/19/1999 Created
*   MODIFIED:  05/11/2000 modified for TMS320C55xx
*   MODIFIED:  04/16 2001 modified for 5510PG2
*   MODIFIED:  07/02/2001 modifid for 5509PG1 & PG2
*   MODIFIED:  04/04/2002 added ICACHE support
*   MODIFIED:  07/26/2002 added 5510PG2_1, 5510PG2_2 support
*   MODIFIED:  09/17/2002 fixed problem with #ifdef CHIP_TYPE inconsistencies
*   MODIFIED:  10/23/2002 Added 5509PG1_0, 5509PG2_0 CHIPTYPES for c035 support
*   MODIFIED:  11/22/2002 Removed 5509PG1_0 support, changed 5509PG2_0 support
*                         to 5509A; added entries to XBSR register for new
*                         EMIF refresh enable fields.
*   MODIFIED:  11/26/2002 Added _EMIF_SELFREFRESH_SUPPORT
*   MODIFIED:  04/23/2002 modified for 5502
*   MODIFIED:  12/09/2002 merged 5510/5509 CSL with 5502 CSL
*   MOIDIFED:  03/18/2003 added _BCT_SUPPORT definition to SUPPORT matrix
*   MODIFIED:  07/03/2003 Removed c16*CHIP_NONE to avoid remarks.
*   MODIFIED:  10/06/2003 Corrected _CHIP_XBCR_ADDR 
*   MODIFIED:  07/28/2004 Added 5501 support 
*   MODIFIED:  08/20/2004 Corrected the inconsistancies between CSL and Data Sheets
*------------------------------------------------------------------------------
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the CHIP module)
* 
* CHIP Control Registers Covered
*   CHIP_ST0_55  - control status register 0
*   CHIP_ST1_55  - control status register 1
*   CHIP_ST2_55  - control status register 2
*   CHIP_ST3_55  - control status register 3
*   CHIP_IFR0    - interrupt flag register 0
*   CHIP_IFR1    - interrupt flag register 1
*   CHIP_PDP     - peripheral data page register
*   CHIP_SYSR    - System Control Register (PG2 5510)
*   CHIP_IER0    - Interrupt enable /mask register 0
*   CHIP_IER1    - Interrupt enable / mask register 1
*   CHIP_IVPD    - Interrupt vector pointer(0-15,24-31)
*   CHIP_IVPH    - Interrupt vector pointer(16,23)
*   CHIP_REVID   - Chip revision ID register
*   CHIP_REVIDL  - Revision ID (LSW) register (5501 and 5502)
*   CHIP_REVIDH  - Revision ID (MSW) register (5501 and 5502)
*   CHIP_SUBID   - Subsystem ID register (5501 & 5502)
*   CHIP_CATID   - Catalog ID register (5502)
*   CHIP_DIEIDH  - Die ID (MSW) register
*   CHIP_DIEIDL  - Die ID (LSW) register
*   CHIP_XBSR    - External Bus Select Register
*   CHIP_SROM    - Secure ROM register ( 5509 and 5509A) 
*   CHIP_CONFIG  - System configuration register (5501 and 5502) 
*   CHIP_XBCR    - External Bus Control Register (5501 and 5502) 
*   CHIP_TSSR    - Timer signal selection register (5501 and 5502) 
*   CHIP_CLKOSR  - CLKOUT selection register  (5501 and 5502)
\******************************************************************************/
#ifndef _CHIPHAL_H_
#define _CHIPHAL_H_
/****************************************\
* include files
\****************************************/
#include <csl_std.h>
#include <csl_stdhal.h>

#ifdef CHIP_5501
   #undef CHIP_5501
   #define CHIP_5501 1
#else
   #define CHIP_5501 0
#endif

#ifdef CHIP_5502
   #undef CHIP_5502
   #define CHIP_5502 1
#else
   #define CHIP_5502 0
#endif


#ifdef CHIP_5509
   #undef CHIP_5509
   #define CHIP_5509 1
#else
   #define CHIP_5509 0
#endif

#ifdef CHIP_5509A
   #undef CHIP_5509A
   #define CHIP_5509A 1
#else
   #define CHIP_5509A 0
#endif


#ifdef CHIP_5510
   #undef CHIP_5510
   #define CHIP_5510 1
#else
   #define CHIP_5510 0
#endif

#ifdef CHIP_5510PG1_0
   #undef CHIP_5510PG1_0
   #define CHIP_5510PG1_0 1
#else
   #define CHIP_5510PG1_0 0
#endif

#ifdef CHIP_5510PG2_0
   #undef CHIP_5510PG2_0
   #define CHIP_5510PG2_0 1
#else
   #define CHIP_5510PG2_0 0
#endif


#ifdef CHIP_5510PG2_1
   #undef CHIP_5510PG2_1
   #define CHIP_5510PG2_1 1
#else
   #define CHIP_5510PG2_1 0
#endif

#ifdef CHIP_5510PG2_2
   #undef CHIP_5510PG2_2
   #define CHIP_5510PG2_2 1
#else
   #define CHIP_5510PG2_2 0
#endif

#ifdef CHIP_5510PG1_2
   #undef CHIP_5510PG1_2
   #define CHIP_5510PG1_2 1
#else
   #define CHIP_5510PG1_2 0
#endif

#if CHIP_5510PG1_0
  #undef CHIP_5510
  #define CHIP_5510    1
#endif

#if CHIP_5510PG1_2
#undef CHIP_5510
#define CHIP_5510 1
#endif

#if (CHIP_5510PG2_1) || (CHIP_5510PG2_2)
  #undef CHIP_5510PG2_0
  #define CHIP_5510PG2_0 1
#endif


#ifndef BIOS_CNT
   #define BIOS_CNT 0
#endif

#ifndef OS_BIOS
#define OS_BIOS 0
#endif

#ifndef OS_SPOX
#define OS_SPOX 0
#endif

#ifndef OS_BARACUDA
#define OS_BARACUDA 0
#endif

#if ((CHIP_5510)==0) & ((CHIP_5510PG1_0)==0) & ((CHIP_5510PG1_2)==0) & ((CHIP_5510PG2_0)==0) 
  #define CSL_CHIP_GRPA 0
  #define CHIP_5510_FAMILY 0
#else
  #define CSL_CHIP_GRPA 1
  #define CHIP_5510_FAMILY 1
#endif

#if ((CHIP_5509)==0) & ((CHIP_5509A)==0)
  #define CSL_CHIP_GRPB 0
  #define CHIP_5509_FAMILY 0
#else
  #define CSL_CHIP_GRPB 1
  #define CHIP_5509_FAMILY 1
#endif

#if ((CHIP_5502==0) & (CHIP_5501==0))
  #define CSL_CHIP_GRPC 0
  #define CHIP_5502_FAMILY 0
#else
  #define CSL_CHIP_GRPC 1
  #define CHIP_5502_FAMILY 1
#endif

#if (CSL_CHIP_GRPA == 0) & (CSL_CHIP_GRPB == 0) & (CSL_CHIP_GRPC == 0)
#error NO CHIP DEFINED
#endif

#define CHIP_NONE 0

#define SUPPORT(c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15)\
 ( c0*CHIP_5510 ||\
   c1*CHIP_5510PG1_2 ||\
   c2*CHIP_5510PG2_0 ||\
   c3*CHIP_5509 ||\
   c4*CHIP_5509A ||\
   c5*CHIP_5502 ||\
   c6*CHIP_5501 ||\
   c7*CHIP_NONE ||\
   c8*CHIP_NONE ||\
   c9*CHIP_NONE ||\
   c10*CHIP_NONE ||\
   c11*CHIP_NONE ||\
   c12*CHIP_NONE ||\
   c13*CHIP_NONE ||\
   c14*CHIP_NONE ||\
   c15*CHIP_NONE\
   )



/*----------------------------------------------------------------*/
/*                                  5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 */
/*                                  5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 */
/*                                  1 1 1 0 0 0 0 x x x x x x x x */
/*                                  0 0 9 9 9 2 1 x x x x x x x x */
/*                                  P P P x A x x x x x x x x x x */
/*                                  x 1 2 x x x x x x x x x x x x */
/*                                  x 2 0 x x x x x x x x x x x x */
/*----------------------------------------------------------------*/
#define _CHIP_55XX          SUPPORT(1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0)
#define _CHIP_SUPPORT       SUPPORT(1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0)
#define _CHIP_CPU_ID        SUPPORT(1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0)
#define _ICACHE_SUPPORT     SUPPORT(1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0)
#define _CSLINIT_SUPPORT    SUPPORT(1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0)
#define _CSLLIB_SUPPORT     SUPPORT(1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0)
#define _DMA_SUPPORT        SUPPORT(1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0)
#define _DMA_DST_AND_SRC_INDEX_SUPPORT\
                            SUPPORT(0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0)
#define _ERR_SUPPORT        SUPPORT(1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0)
#define _EBSEL_SUPPORT      SUPPORT(0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0)
#define _GPIO_SUPPORT       SUPPORT(1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0)
#define _GPIO_PARALLEL_SUPPORT\
                            SUPPORT(0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0)
#define _GPIO_PGPIO_SUPPORT\
                            SUPPORT(0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0)
#define _GPIO_AGPIO_SUPPORT\
                            SUPPORT(0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0)
#define _HPI_SUPPORT        SUPPORT(0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0)
#define _IRQ_SUPPORT        SUPPORT(1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0)
#define _MCBSP_SUPPORT      SUPPORT(1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0)
#define _SIG_SUPPORT        SUPPORT(1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0)
#define _TIMER_SUPPORT      SUPPORT(1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0)
#define _GPT_SUPPORT        SUPPORT(0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0)
#define _BCT_SUPPORT        SUPPORT(0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0)
#define _EMIF_SUPPORT       SUPPORT(1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0)
#define _EMIFA_SUPPORT      SUPPORT(1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0)
#define _EMIFB_SUPPORT      SUPPORT(0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0)
#define _EMIF_SELFREFRESH_SUPPORT\
                            SUPPORT(0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0)

#define _DAT_SUPPORT        SUPPORT(1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0)
#define _PWR_SUPPORT        SUPPORT(1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0)
#define _SECUREID_SUPPORT   SUPPORT(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)
#define _WDTIM_SUPPORT      SUPPORT(0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0)
#define _WDTIMA_SUPPORT     SUPPORT(0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0)
#define _WDTIMB_SUPPORT     SUPPORT(0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0)
#define _I2C_SUPPORT        SUPPORT(0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0)
#define _UART_SUPPORT       SUPPORT(0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0)
/*#define _UHPI_SUPPORT       SUPPORT(0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0)*/
#define _USB_SUPPORT        SUPPORT(0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0)
#define _PLL_SUPPORT        SUPPORT(1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0)
#define _PLLA_SUPPORT       SUPPORT(1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0)
#define _PLLB_SUPPORT       SUPPORT(0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0)
#define _PLL_DIGITAL_SUPPORT\
                            SUPPORT(0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0)
#define _PLL_CLKDIV_SUPPORT\
                            SUPPORT(0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0)
#define _PLL_ANALOG_SUPPORT\
                            SUPPORT(1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0)
#define _CSIDR_SUPPORT      SUPPORT(1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0)
#define _MMC_SUPPORT        SUPPORT(0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0)
#define _MST_SUPPORT        SUPPORT(0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0)
#define _ADC_SUPPORT        SUPPORT(0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0)
#define _RTC_SUPPORT        SUPPORT(0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0)
#define _MMC_SUPPORT        SUPPORT(0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0)
#define _MST_SUPPORT        SUPPORT(0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0)
#define _ADC_SUPPORT        SUPPORT(0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0)
#define _RTC_SUPPORT        SUPPORT(0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0)

/*----------------------------------------------------------------*/

/******************************************************************\
* Generic Reigster and Bit Field Manipulation Macros
\******************************************************************/
#define CHIP_ADDR(Reg)               _CHIP_##Reg##_ADDR
#define CHIP_RGET(Reg)               _CHIP_##Reg##_GET
#define CHIP_RSET(Reg,Val)           _CHIP_##Reg##_SET(Val)
#define CHIP_FGET(Reg,Field)         _CHIP_##Reg##_FGET(##Field)
#define CHIP_FSET(Reg,Field,Val)     _CHIP_##Reg##_FSET(##Field,Val)
#define CHIP_FMK(Reg,Field,Val)      _CHIP_##Reg##_##Field##_MK(Val)
#define CHIP_FMKS(Reg,Field,Sym)     CHIP_FMK(##Reg,##Field,##Reg##_##Field##_##Sym)
 
/******************************************************************\
* Bit Field Manipulation and Data Type Definition Macros
\******************************************************************/

/******************************************************************************\
* _CHIP_ST0_55 - control status register 0
*
* Fields:
*   (RW) _CHIP_ST0_55_ACOV2
*   (RW) _CHIP_ST0_55_ACOV3
*   (RW) _CHIP_ST0_55_TC1
*   (RW) _CHIP_ST0_55_TC2
*   (RW) _CHIP_ST0_55_CARRY
*   (RW) _CHIP_ST0_55_ACOV0
*   (RW) _CHIP_ST0_55_ACOV1
*   (RW) _CHIP_ST0_55_DP
*
\******************************************************************************/
#define _CHIP_ST0_55_ADDR     (0x0002u)
#define _CHIP_ST0_55          REG16(_CHIP_ST0_55_ADDR)
#define _ST0_55                _CHIP_ST0_55

#define _CHIP_ST0_55_GET\
   _REG_GET(CHIP_ADDR(ST0_55))

#define _CHIP_ST0_55_SET(Val)\
   _REG_SET(CHIP_ADDR(ST0_55), Val)

#define _CHIP_ST0_55_FGET(Field)\
 _FIELD_GET(CHIP_ADDR(ST0_55),_CHIP_ST0_55_##Field)

#define _CHIP_ST0_55_FSET(Field,Val)\
 _FIELD_SET(CHIP_ADDR(ST0_55),_CHIP_ST0_55_##Field,Val)


/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST0_55_ACOV2: overflow flag fr Acc #2
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST0_55_ACOV2_SHIFT          (0x000Fu)
#define _CHIP_ST0_55_ACOV2_MK(n)          (((Uint16)(n) & 0x0001u) << _CHIP_ST0_55_ACOV2_SHIFT)
#define _CHIP_ST0_55_ACOV2_MASK           (_CHIP_ST0_55_ACOV2_MK(1))
#define _CHIP_ST0_55_ACOV2_CLR            (~(_CHIP_ST0_55_ACOV2_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST0_55_ACOV3: overflow flag fr Acc #3
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST0_55_ACOV3_SHIFT          (0x000Eu)
#define _CHIP_ST0_55_ACOV3_MK(n)          (((Uint16)(n) & 0x0001u) << _CHIP_ST0_55_ACOV3_SHIFT)
#define _CHIP_ST0_55_ACOV3_MASK           (_CHIP_ST0_55_ACOV3_MK(1))
#define _CHIP_ST0_55_ACOV3_CLR            (~(_CHIP_ST0_55_ACOV3_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST0_55_TC1: test bit 1
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST0_55_TC1_SHIFT           (0x000Du)
#define _CHIP_ST0_55_TC1_MK(n)           (((Uint16)(n) & 0x0001u) << _CHIP_ST0_55_TC1_SHIFT)
#define _CHIP_ST0_55_TC1_MASK            (_CHIP_ST0_55_TC1_MK(1))
#define _CHIP_ST0_55_TC1_CLR             (~(_CHIP_ST0_55_TC1_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST0_55_TC2: test bit 2
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST0_55_TC2_SHIFT           (0x000Cu)
#define _CHIP_ST0_55_TC2_MK(n)           (((Uint16)(n) & 0x0001u) << _CHIP_ST0_55_TC2_SHIFT)
#define _CHIP_ST0_55_TC2_MASK            (_CHIP_ST0_55_TC2_MK(1))
#define _CHIP_ST0_55_TC2_CLR             (~(_CHIP_ST0_55_TC2_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST0_55_CARRY: test bit 2
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST0_55_CARRY_SHIFT         (0x000Bu)
#define _CHIP_ST0_55_CARRY_MK(n)         (((Uint16)(n) & 0x0001u) << _CHIP_ST0_55_CARRY_SHIFT)
#define _CHIP_ST0_55_CARRY_MASK          (_CHIP_ST0_55_CARRY_MK(1))
#define _CHIP_ST0_55_CARRY_CLR           (~(_CHIP_ST0_55_CARRY_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST0_55_ACOV0: overflow flag fr Acc #3
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST0_55_ACOV0_SHIFT         (0x000Au)
#define _CHIP_ST0_55_ACOV0_MK(n)         (((Uint16)(n) & 0x0001u) << _CHIP_ST0_55_ACOV0_SHIFT)
#define _CHIP_ST0_55_ACOV0_MASK          (_CHIP_ST0_55_ACOV0_MK(1))
#define _CHIP_ST0_55_ACOV0_CLR           (~(_CHIP_ST0_55_ACOV0_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST0_55_ACOV1: overflow flag fr Acc #3
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST0_55_ACOV1_SHIFT          (0x0009u)
#define _CHIP_ST0_55_ACOV1_MK(n)          (((Uint16)(n) & 0x0001u) << _CHIP_ST0_55_ACOV1_SHIFT)
#define _CHIP_ST0_55_ACOV1_MASK           (_CHIP_ST0_55_ACOV1_MK(1))
#define _CHIP_ST0_55_ACOV1_CLR            (~(_CHIP_ST0_55_ACOV1_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST0_55_DP: overflow flag fr Acc #3
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST0_55_DP_SHIFT            (0x0000u)
#define _CHIP_ST0_55_DP_MK(n)            (((Uint16)(n) & 0x00FFu) << _CHIP_ST0_55_DP_SHIFT)
#define _CHIP_ST0_55_DP_MASK             (_CHIP_ST0_55_DP_MK(0x00FFu))
#define _CHIP_ST0_55_DP_CLR              (~(_CHIP_ST0_55_DP_MASK))

#define _CHIP_ST0_55_CFG(acov2, acov3, tc1, tc2, carry, acov0, acov1, dp)\
 _ST0_55 = (Uint16) ( _CHIP_ST0_55_ACOV2_MK(acov2)   |\
                      _CHIP_ST0_55_ACOV3_MK(acov3)   |\
                      _CHIP_ST0_55_TC1_MK(tc1)       |\
                      _CHIP_ST0_55_TC2_MK(tc2)       |\
                      _CHIP_ST0_55_CARRY_MK(carry)   |\
                      _CHIP_ST0_55_ACOV0_MK(acov0)   |\
                      _CHIP_ST0_55_ACOV1_MK(acov1)   |\
                      _CHIP_ST0_55_DP_MK(dp)         \
           )


/******************************************************************************\
* _CHIP_ST1_55 - control status register 0
*
* Fields:
*   (RW) _CHIP_ST1_55_BRAF
*   (RW) _CHIP_ST1_55_CPL
*   (RW) _CHIP_ST1_55_XF
*   (RW) _CHIP_ST1_55_HM
*   (RW) _CHIP_ST1_55_INTM
*   (RW) _CHIP_ST1_55_M40
*   (RW) _CHIP_ST1_55_SATD
*   (RW) _CHIP_ST1_55_SXMD
*   (RW) _CHIP_ST1_55_C16
*   (RW) _CHIP_ST1_55_FRCT
*   (RW) _CHIP_ST1_55_C54CM
*   (RW) _CHIP_ST1_55_ASM
*
\******************************************************************************/
#define _CHIP_ST1_55_ADDR     (0x0003u)
#define _CHIP_ST1_55          REG16(_CHIP_ST1_55_ADDR)
#define _ST1_55                _CHIP_ST1_55

#define _CHIP_ST1_55_GET\
   _REG_GET(CHIP_ADDR(ST1_55))

#define _CHIP_ST1_55_SET(Val)\
   _REG_SET(CHIP_ADDR(ST1_55), Val)

#define _CHIP_ST1_55_FGET(Field)\
 _FIELD_GET(CHIP_ADDR(ST1_55),_CHIP_ST1_55_##Field)

#define _CHIP_ST1_55_FSET(Field,Val)\
 _FIELD_SET(CHIP_ADDR(ST1_55),_CHIP_ST1_55_##Field,Val)
  

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST1_55_BRAF: overflow flag fr Acc #3
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST1_55_BRAF_SHIFT            (0x000Fu)
#define _CHIP_ST1_55_BRAF_MK(n)            (((Uint16)(n) & 0x0001u) << _CHIP_ST1_55_BRAF_SHIFT)
#define _CHIP_ST1_55_BRAF_MASK             (_CHIP_ST1_55_BRAF_MK(1))
#define _CHIP_ST1_55_BRAF_CLR              (~(_CHIP_ST1_55_BRAF_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST1_55_CPL: overflow flag fr Acc #3
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST1_55_CPL_SHIFT             (0x000Eu)
#define _CHIP_ST1_55_CPL_MK(n)             (((Uint16)(n) & 0x0001u) << _CHIP_ST1_55_CPL_SHIFT)
#define _CHIP_ST1_55_CPL_MASK              (_CHIP_ST1_55_CPL_MK(1))
#define _CHIP_ST1_55_CPL_CLR               (~(_CHIP_ST1_55_CPL_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST1_55_XF: overflow flag fr Acc #3
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST1_55_XF_SHIFT              (0x000Du)
#define _CHIP_ST1_55_XF_MK(n)              (((Uint16)(n) & 0x0001u) << _CHIP_ST1_55_XF_SHIFT)
#define _CHIP_ST1_55_XF_MASK               (_CHIP_ST1_55_XF_MK(1))
#define _CHIP_ST1_55_XF_CLR                (~(_CHIP_ST1_55_XF_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST1_55_HM: overflow flag fr Acc #3
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST1_55_HM_SHIFT              (0x000Cu)
#define _CHIP_ST1_55_HM_MK(n)              (((Uint16)(n) & 0x0001u) << _CHIP_ST1_55_HM_SHIFT)
#define _CHIP_ST1_55_HM_MASK               (_CHIP_ST1_55_HM_MK(1))
#define _CHIP_ST1_55_HM_CLR                (~(_CHIP_ST1_55_HM_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST1_55_INTM: global maksable interrupt enable/disable
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST1_55_INTM_SHIFT            (0x000Bu)
#define _CHIP_ST1_55_INTM_MK(n)            (((Uint16)(n) & 0x0001u) << _CHIP_ST1_55_INTM_SHIFT)
#define _CHIP_ST1_55_INTM_MASK             (_CHIP_ST1_55_INTM_MK(1))
#define _CHIP_ST1_55_INTM_CLR              (~(_CHIP_ST1_55_INTM_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST1_55_M40: 40 bit arithmetic
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST1_55_M40_SHIFT             (0x000Au)
#define _CHIP_ST1_55_M40_MK(n)             (((Uint16)(n) & 0x0001u) << _CHIP_ST1_55_M40_SHIFT)
#define _CHIP_ST1_55_M40_MASK              (_CHIP_ST1_55_M40_MK(1))
#define _CHIP_ST1_55_M40_CLR               (~(_CHIP_ST1_55_M40_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST1_55_SATD: perform saturation on overflow/underflow
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST1_55_SATD_SHIFT           (0x0009u)
#define _CHIP_ST1_55_SATD_MK(n)           (((Uint16)(n) & 0x0001u) << _CHIP_ST1_55_SATD_SHIFT)
#define _CHIP_ST1_55_SATD_MASK            (_CHIP_ST1_55_SATD_MK(1))
#define _CHIP_ST1_55_SATD_CLR             (~(_CHIP_ST1_55_SATD_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST1_55_SXMD: sign extension mode bit
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST1_55_SXMD_SHIFT           (0x0008u)
#define _CHIP_ST1_55_SXMD_MK(n)           (((Uint16)(n) & 0x0001u) << _CHIP_ST1_55_SXMD_SHIFT)
#define _CHIP_ST1_55_SXMD_MASK            (_CHIP_ST1_55_SXMD_MK(1))
#define _CHIP_ST1_55_SXMD_CLR             (~(_CHIP_ST1_55_SXMD_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST1_55_C16: dual mode 16 bit arithmetic
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST1_55_C16_SHIFT            (0x0007u)
#define _CHIP_ST1_55_C16_MK(n)            (((Uint16)(n) & 0x0001u) << _CHIP_ST1_55_C16_SHIFT)
#define _CHIP_ST1_55_C16_MASK             (_CHIP_ST1_55_C16_MK(1))
#define _CHIP_ST1_55_C16_CLR              (~(_CHIP_ST1_55_C16_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST1_55_FRCT: left shift by one on multiply (fractional math)
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST1_55_FRCT_SHIFT            (0x0006u)
#define _CHIP_ST1_55_FRCT_MK(n)            (((Uint16)(n) & 0x0001u) << _CHIP_ST1_55_FRCT_SHIFT)
#define _CHIP_ST1_55_FRCT_MASK             (_CHIP_ST1_55_FRCT_MK(1))
#define _CHIP_ST1_55_FRCT_CLR              (~(_CHIP_ST1_55_FRCT_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST1_55_C54CM: C54x compatability mode bit
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST1_55_C54CM_SHIFT          (0x0005u)
#define _CHIP_ST1_55_C54CM_MK(n)          (((Uint16)(n) & 0x0001u) << _CHIP_ST1_55_C54CM_SHIFT)
#define _CHIP_ST1_55_C54CM_MASK           (_CHIP_ST1_55_C54CM_MK(1))
#define _CHIP_ST1_55_C54CM_CLR            (~(_CHIP_ST1_55_C54CM_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST1_55_ASM: arithmetic shift
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST1_55_ASM_SHIFT          (0x0000u)
#define _CHIP_ST1_55_ASM_MK(n)          (((Uint16)(n) & 0x001Fu) << _CHIP_ST1_55_ASM_SHIFT)
#define _CHIP_ST1_55_ASM_MASK           (_CHIP_ST1_55_ASM_MK(0x001Fu))
#define _CHIP_ST1_55_ASM_CLR            (~(_CHIP_ST1_55_ASM_MASK))

#define _CHIP_ST1_55_CFG(braf, cpl, xf, hm, intm, m40, satd, sxmd, c16, frct,\
                         c54cm, asm)\
  _ST1_55 = (Uint16) (_CHIP_ST1_55_BRAF_MK(braf)   |\
                      _CHIP_ST1_55_CPL_MK(cpl)     |\
                      _CHIP_ST1_55_XF_MK(xf)       |\
                      _CHIP_ST1_55_HM_MK(hm)       |\
                      _CHIP_ST1_55_INTM_MK(intm)   |\
                      _CHIP_ST1_55_M40_MK(m40)     |\
                      _CHIP_ST1_55_SATD_MK(satd)   |\
                      _CHIP_ST1_55_SXMD_MK(sxmd)   |\
                      _CHIP_ST1_55_C16_MK(c16)     |\
                      _CHIP_ST1_55_FRCT_MK(frct)   |\
                      _CHIP_ST1_55_C54CM_MK(c54cm) |\
                      _CHIP_ST1_55_ASM_MK(asm)     \
           )


/******************************************************************************\
* _CHIP_ST2_55 - control status register 2
*
* Fields:
*   (RW) _CHIP_ST2_55_ARMS
*   (RW) _CHIP_ST2_55_DBGM
*   (RW) _CHIP_ST2_55_EALLOW
*   (RW) _CHIP_ST2_55_EALLOW
*   (RW) _CHIP_ST2_55_RDM
*   (RW) _CHIP_ST2_55_CDPLC
*   (RW) _CHIP_ST2_55_AR7LC
*   (RW) _CHIP_ST2_55_AR6LC
*   (RW) _CHIP_ST2_55_AR5LC
*   (RW) _CHIP_ST2_55_AR4LC
*   (RW) _CHIP_ST2_55_AR3LC
*   (RW) _CHIP_ST2_55_AR2LC
*   (RW) _CHIP_ST2_55_AR1LC
*   (RW) _CHIP_ST2_55_AR0LC
*
\******************************************************************************/
#define _CHIP_ST2_55_ADDR     (0x004Bu)
#define _CHIP_ST2_55          REG16(_CHIP_ST2_55_ADDR)
#define _ST2_55                _CHIP_ST2_55

#define _CHIP_ST2_55_GET\
   _REG_GET(CHIP_ADDR(ST2_55))

#define _CHIP_ST2_55_SET(Val)\
   _REG_SET(CHIP_ADDR(ST2_55), Val)

#define _CHIP_ST2_55_FGET(Field)\
 _FIELD_GET(CHIP_ADDR(ST2_55),_CHIP_ST2_55_##Field)

#define _CHIP_ST2_55_FSET(Field,Val)\
 _FIELD_SET(CHIP_ADDR(ST2_55),_CHIP_ST2_55_##Field,Val)


/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST2_55_ARMS: overflow flag fr Acc #3
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST2_55_ARMS_SHIFT            (0x000Fu)
#define _CHIP_ST2_55_ARMS_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_ST2_55_ARMS_SHIFT)
#define _CHIP_ST2_55_ARMS_MASK             (_CHIP_ST2_55_ARMS_MK(1))
#define _CHIP_ST2_55_ARMS_CLR              (~(_CHIP_ST2_55_ARMS_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST2_55_DBGM: overflow flag fr Acc #3
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST2_55_DBGM_SHIFT            (0x000Cu)
#define _CHIP_ST2_55_DBGM_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_ST2_55_DBGM_SHIFT)
#define _CHIP_ST2_55_DBGM_MASK             (_CHIP_ST2_55_DBGM_MK(1))
#define _CHIP_ST2_55_DBGM_CLR              (~(_CHIP_ST2_55_DBGM_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST2_55_EALLOW: overflow flag fr Acc #3
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST2_55_EALLOW_SHIFT           (0x000Bu)
#define _CHIP_ST2_55_EALLOW_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_ST2_55_EALLOW_SHIFT)
#define _CHIP_ST2_55_EALLOW_MASK            (_CHIP_ST2_55_EALLOW_MK(1))
#define _CHIP_ST2_55_EALLOW_CLR             (~(_CHIP_ST2_55_EALLOW_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST2_55_RDM: overflow flag fr Acc #3
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST2_55_RDM_SHIFT             (0x000Au)
#define _CHIP_ST2_55_RDM_MK(n)             (((Uint16)n & 0x0001u) << _CHIP_ST2_55_RDM_SHIFT)
#define _CHIP_ST2_55_RDM_MASK              (_CHIP_ST2_55_RDM_MK(1))
#define _CHIP_ST2_55_RDM_CLR               (~(_CHIP_ST2_55_RDM_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST2_55_CDPLC: overflow flag fr Acc #3
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST2_55_CDPLC_SHIFT           (0x0008u)
#define _CHIP_ST2_55_CDPLC_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_ST2_55_CDPLC_SHIFT)
#define _CHIP_ST2_55_CDPLC_MASK            (_CHIP_ST2_55_CDPLC_MK(1))
#define _CHIP_ST2_55_CDPLC_CLR             (~(_CHIP_ST2_55_CDPLC_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST2_55_CDPLC: overflow flag fr Acc #3
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST2_55_CDPLC_SHIFT           (0x0008u)
#define _CHIP_ST2_55_CDPLC_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_ST2_55_CDPLC_SHIFT)
#define _CHIP_ST2_55_CDPLC_MASK            (_CHIP_ST2_55_CDPLC_MK(1))
#define _CHIP_ST2_55_CDPLC_CLR             (~(_CHIP_ST2_55_CDPLC_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST2_55_AR7LC: overflow flag fr Acc #3
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST2_55_AR7LC_SHIFT           (0x0007u)
#define _CHIP_ST2_55_AR7LC_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_ST2_55_AR7LC_SHIFT)
#define _CHIP_ST2_55_AR7LC_MASK            (_CHIP_ST2_55_AR7LC_MK(1))
#define _CHIP_ST2_55_AR7LC_CLR             (~(_CHIP_ST2_55_AR7LC_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST2_55_AR6LC: overflow flag fr Acc #3
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST2_55_AR6LC_SHIFT           (0x0006u)
#define _CHIP_ST2_55_AR6LC_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_ST2_55_AR6LC_SHIFT)
#define _CHIP_ST2_55_AR6LC_MASK            (_CHIP_ST2_55_AR6LC_MK(1))
#define _CHIP_ST2_55_AR6LC_CLR             (~(_CHIP_ST2_55_AR6LC_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST2_55_AR5LC: overflow flag fr Acc #3
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST2_55_AR5LC_SHIFT           (0x0005u)
#define _CHIP_ST2_55_AR5LC_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_ST2_55_AR5LC_SHIFT)
#define _CHIP_ST2_55_AR5LC_MASK            (_CHIP_ST2_55_AR5LC_MK(1))
#define _CHIP_ST2_55_AR5LC_CLR             (~(_CHIP_ST2_55_AR5LC_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST2_55_AR4LC: overflow flag fr Acc #3
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST2_55_AR4LC_SHIFT           (0x0004u)
#define _CHIP_ST2_55_AR4LC_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_ST2_55_AR4LC_SHIFT)
#define _CHIP_ST2_55_AR4LC_MASK            (_CHIP_ST2_55_AR4LC_MK(1))
#define _CHIP_ST2_55_AR4LC_CLR             (~(_CHIP_ST2_55_AR4LC_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST2_55_AR3LC: overflow flag fr Acc #3
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST2_55_AR3LC_SHIFT           (0x0003u)
#define _CHIP_ST2_55_AR3LC_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_ST2_55_AR3LC_SHIFT)
#define _CHIP_ST2_55_AR3LC_MASK            (_CHIP_ST2_55_AR3LC_MK(1))
#define _CHIP_ST2_55_AR3LC_CLR             (~(_CHIP_ST2_55_AR3LC_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST2_55_AR2LC: overflow flag fr Acc #3
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST2_55_AR2LC_SHIFT           (0x0002u)
#define _CHIP_ST2_55_AR2LC_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_ST2_55_AR2LC_SHIFT)
#define _CHIP_ST2_55_AR2LC_MASK            (_CHIP_ST2_55_AR2LC_MK(1))
#define _CHIP_ST2_55_AR2LC_CLR             (~(_CHIP_ST2_55_AR2LC_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST2_55_AR1LC: overflow flag fr Acc #3
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST2_55_AR1LC_SHIFT           (0x0001u)
#define _CHIP_ST2_55_AR1LC_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_ST2_55_AR1LC_SHIFT)
#define _CHIP_ST2_55_AR1LC_MASK            (_CHIP_ST2_55_AR1LC_MK(1))
#define _CHIP_ST2_55_AR1LC_CLR             (~(_CHIP_ST2_55_AR1LC_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST2_55_AR0LC: overflow flag fr Acc #3
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST2_55_AR0LC_SHIFT           (0x0000u)
#define _CHIP_ST2_55_AR0LC_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_ST2_55_AR0LC_SHIFT)
#define _CHIP_ST2_55_AR0LC_MASK            (_CHIP_ST2_55_AR0LC_MK(1))
#define _CHIP_ST2_55_AR0LC_CLR             (~(_CHIP_ST2_55_AR0LC_MASK))

#define _CHIP_ST2_55_CFG(arms, dbgm, eallow, rdm, cdplc, ar7lc, ar6lc, ar5lc,\
                         ar4lc, ar3lc,ar2lc,ar1lc,ar0lc)\
  _ST2_55 = (Uint16) ( _CHIP_ST2_55_ARMS_MK(arms)     |\
                      _CHIP_ST2_55_DBGM_Mk(dbgm)     |\
                      _CHIP_ST2_55_EALLOW_MK(eallow) |\
                      _CHIP_ST2_55_RDM_MK(rdm)       |\
                      _CHIP_ST2_55_CDPLC_MK(cdplc)   |\
                      _CHIP_ST2_55_AR7LC_MK(ar7lc)   |\
                      _CHIP_ST2_55_AR6LC_MK(ar6lc)   |\
                      _CHIP_ST2_55_AR5LC_MK(ar5lc)   |\
                      _CHIP_ST2_55_AR4LC_MK(ar4lc)   |\
                      _CHIP_ST2_55_AR3LC_MK(ar3lc)   |\
                      _CHIP_ST2_55_AR2LC_MK(ar2lc)   |\
                      _CHIP_ST2_55_AR1LC_MK(ar1lc)   |\
                      _CHIP_ST2_55_AR0LC_MK(ar0lc)   |\
           )


/******************************************************************************\
* _CHIP_ST3_55 - control status register 2
*
* Fields:
*   (RW) _CHIP_ST3_55_CAFRZ
*   (RW) _CHIP_ST3_55_CAEN
*   (RW) _CHIP_ST3_55_CACLR
*   (RW) _CHIP_ST3_55_HINT
*   (RW) _CHIP_ST3_55_CBERR
*   (RW) _CHIP_ST3_55_MPNMC
*   (RW) _CHIP_ST3_55_SATA
*   (RW) _CHIP_ST3_55_AVIS
*   (RW) _CHIP_ST3_55_CLKOFF
*   (RW) _CHIP_ST3_55_SMUL
*   (RW) _CHIP_ST3_55_SST
*
\******************************************************************************/
#define _CHIP_ST3_55_ADDR     (0x004u)
#define _CHIP_ST3_55          REG16(_CHIP_ST3_55_ADDR)
#define _ST3_55                _CHIP_ST3_55

#define _CHIP_ST3_55_GET\
   _REG_GET(_CHIP_ST3_55_ADDR)

#define _CHIP_ST3_55_SET(Val)\
   _REG_SET(_CHIP_ST3_55_ADDR, Val)

#define _CHIP_ST3_55_FGET(Field)\
 _FIELD_GET(CHIP_ADDR(ST3_55),_CHIP_ST3_55_##Field)

#define _CHIP_ST3_55_FSET(Field,Val)\
 _FIELD_SET(CHIP_ADDR(ST3_55),_CHIP_ST3_55_##Field,Val)
  


/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST3_55_CAFRZ: CACHE FREEZE
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST3_55_CAFRZ_SHIFT            (0x000Fu)
#define _CHIP_ST3_55_CAFRZ_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_ST3_55_CAFRZ_SHIFT)
#define _CHIP_ST3_55_CAFRZ_MASK             (_CHIP_ST3_55_CAFRZ_MK(1))
#define _CHIP_ST3_55_CAFRZ_CLR              (~(_CHIP_ST3_55_CAFRZ_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST3_55_CAEN: CACHE ENABLE
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST3_55_CAEN_SHIFT             (0x000Eu)
#define _CHIP_ST3_55_CAEN_MK(n)             (((Uint16)n & 0x0001u) << _CHIP_ST3_55_CAEN_SHIFT)
#define _CHIP_ST3_55_CAEN_MASK              (_CHIP_ST3_55_CAEN_MK(1))
#define _CHIP_ST3_55_CAEN_CLR               (~(_CHIP_ST3_55_CAEN_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST3_55_CACLR: CACHE CLEAR
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST3_55_CACLR_SHIFT            (0x000Du)
#define _CHIP_ST3_55_CACLR_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_ST3_55_CACLR_SHIFT)
#define _CHIP_ST3_55_CACLR_MASK             (_CHIP_ST3_55_CACLR_MK(1))
#define _CHIP_ST3_55_CACLR_CLR              (~(_CHIP_ST3_55_CACLR_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST3_55_HINT: HOST INTERRUPT?
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST3_55_HINT_SHIFT             (0x000Cu)
#define _CHIP_ST3_55_HINT_MK(n)             (((Uint16)n & 0x0001u) << _CHIP_ST3_55_HINT_SHIFT)
#define _CHIP_ST3_55_HINT_MASK              (_CHIP_ST3_55_HINT_MK(1))
#define _CHIP_ST3_55_HINT_CLR               (~(_CHIP_ST3_55_HINT_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST3_55_CBERR: CACHE BOUNDARY ERROR
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST3_55_CBERR_SHIFT            (0x0007u)
#define _CHIP_ST3_55_CBERR_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_ST3_55_CBERR_SHIFT)
#define _CHIP_ST3_55_CBERR_MASK             (_CHIP_ST3_55_CBERR_MK(1))
#define _CHIP_ST3_55_CBERR_CLR              (~(_CHIP_ST3_55_CBERR_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST3_55_MPNMC: CACHE BOUNDARY ERROR
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST3_55_MPNMC_SHIFT            (0x0006u)
#define _CHIP_ST3_55_MPNMC_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_ST3_55_MPNMC_SHIFT)
#define _CHIP_ST3_55_MPNMC_MASK             (_CHIP_ST3_55_MPNMC_MK(1))
#define _CHIP_ST3_55_MPNMC_CLR              (~(_CHIP_ST3_55_MPNMC_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST3_55_SATA: CACHE BOUNDARY ERROR
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST3_55_SATA_SHIFT           (0x0005u)
#define _CHIP_ST3_55_SATA_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_ST3_55_SATA_SHIFT)
#define _CHIP_ST3_55_SATA_MASK            (_CHIP_ST3_55_SATA_MK(1))
#define _CHIP_ST3_55_SATA_CLR             (~(_CHIP_ST3_55_SATA_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST3_55_AVIS: CACHE BOUNDARY ERROR
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST3_55_AVIS_SHIFT           (0x0004u)
#define _CHIP_ST3_55_AVIS_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_ST3_55_AVIS_SHIFT)
#define _CHIP_ST3_55_AVIS_MASK            (_CHIP_ST3_55_AVIS_MK(1))
#define _CHIP_ST3_55_AVIS_CLR             (~(_CHIP_ST3_55_AVIS_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST3_55_CLKOFF: CACHE BOUNDARY ERROR
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST3_55_CLKOFF_SHIFT         (0x0002u)
#define _CHIP_ST3_55_CLKOFF_MK(n)         (((Uint16)n & 0x0001u) << _CHIP_ST3_55_CLKOFF_SHIFT)
#define _CHIP_ST3_55_CLKOFF_MASK          (_CHIP_ST3_55_CLKOFF_MK(1))
#define _CHIP_ST3_55_CLKOFF_CLR           (~(_CHIP_ST3_55_CLKOFF_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST3_55_SMUL: CACHE BOUNDARY ERROR
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST3_55_SMUL_SHIFT           (0x0001u)
#define _CHIP_ST3_55_SMUL_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_ST3_55_SMUL_SHIFT)
#define _CHIP_ST3_55_SMUL_MASK            (_CHIP_ST3_55_SMUL_MK(1))
#define _CHIP_ST3_55_SMUL_CLR             (~(_CHIP_ST3_55_SMUL_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_ST3_55_SST: CACHE BOUNDARY ERROR
\*----------------------------------------------------------------------------*/ 
#define _CHIP_ST3_55_SST_SHIFT           (0x0000u)
#define _CHIP_ST3_55_SST_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_ST3_55_SST_SHIFT)
#define _CHIP_ST3_55_SST_MASK            (_CHIP_ST3_55_SST_MK(1))
#define _CHIP_ST3_55_SST_CLR             (~(_CHIP_ST3_55_SST_MASK))

#define _CHIP_ST3_55_CFG(cafrz, caen, caclr, hint, cberr, mpnmc, sata, avis,\
                         clkoff, smul, sst)\
  _ST3_55 =   (Uint16) ( _CHIP_ST3_55_CAFRZ_MK(cafrz)   |\
                        _CHIP_ST3_55_CAEN_MK(caen)     |\
                        _CHIP_ST3_55_CACLR_MK(calcr)   |\
                        _CHIP_ST3_55_HINT_MK(hint)     |\
                        _CHIP_ST3_55_CBERR_MK(cberr)   |\
                        _CHIP_ST3_55_MPNMC_MK(mpnmc)   |\
                        _CHIP_ST3_55_SATA_MK(sata)     |\
                        _CHIP_ST3_55_AVIS_MK(avis)     |\
                        _CHIP_ST3_55_CLKOFF_MK(clkoff) |\
                        _CHIP_ST3_55_SMUL_MK(smul)     |\
                        _CHIP_ST3_55_SST_MK(sst)        \
             )

/******************************************************************************\
* _CHIP_IER0 - INTERRUPT ENABLE/MASK REGISTER #0
*
* Fields:
*   (RW) _CHIP_IER0_DMAC5
*   (RW) _CHIP_IER0_DMAC4
*   (RW) _CHIP_IER0_XINT2
*   (RW) _CHIP_IER0_RINT2
*   (RW) _CHIP_IER0_INT3
*   (RW) _CHIP_IER0_DSPINT
*   (RW) _CHIP_IER0_DMAC1
*   (RW) _CHIP_IER0_XINT1
*   (RW) _CHIP_IER0_RINT1
*   (RW) _CHIP_IER0_RINT0
*   (RW) _CHIP_IER0_TINT0
*   (RW) _CHIP_IER0_INT2
*   (RW) _CHIP_IER0_INT0
*
\******************************************************************************/
#define _CHIP_IER0_ADDR     (0x0000u)
#define _CHIP_IER0          REG16(_CHIP_IER0_ADDR)
#define _IER0                _CHIP_IER0

#define _CHIP_IER0_GET\
   _REG_GET(CHIP_ADDR(IER0))

#define _CHIP_IER0_SET(Val)\
   _REG_SET(CHIP_ADDR(IER0), Val)

#define _CHIP_IER0_FGET(Field)\
 _FIELD_GET(CHIP_ADDR(IER0),_CHIP_IER0_##Field)

#define _CHIP_IER0_FSET(Field,Val)\
 _FIELD_SET(CHIP_ADDR(IER0),_CHIP_IER0_##Field,Val)
  

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IER0_DMAC5: DMA CHANNEL 5 INTERRUPT ENABLE BIT
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IER0_DMAC5_SHIFT            (0x000Fu)
#define _CHIP_IER0_DMAC5_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_IER0_DMAC5_SHIFT)
#define _CHIP_IER0_DMAC5_MASK             (_CHIP_IER0_DMAC5_MK(1))
#define _CHIP_IER0_DMAC5_CLR              (~(_CHIP_IER0_DMAC5_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IER0_DMAC4: DMA CHANNEL 4 INTERRUPT ENABLE BIT
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IER0_DMAC4_SHIFT            (0x000Eu)
#define _CHIP_IER0_DMAC4_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_IER0_DMAC4_SHIFT)
#define _CHIP_IER0_DMAC4_MASK             (_CHIP_IER0_DMAC4_MK(1))
#define _CHIP_IER0_DMAC4_CLR              (~(_CHIP_IER0_DMAC4_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IER0_XINT2: SERIAL PORT #2 TRANSMIT INTERRUPT ENABLE
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IER0_XINT2_SHIFT            (0x000Du)
#define _CHIP_IER0_XINT2_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_IER0_XINT2_SHIFT)
#define _CHIP_IER0_XINT2_MASK             (_CHIP_IER0_XINT2_MK(1))
#define _CHIP_IER0_XINT2_CLR              (~(_CHIP_IER0_XINT2_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IER0_RINT2: SERIAL PORT #2 RECEIVE INTERRUPT ENABLE
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IER0_RINT2_SHIFT            (0x000Cu)
#define _CHIP_IER0_RINT2_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_IER0_RINT2_SHIFT)
#define _CHIP_IER0_RINT2_MASK             (_CHIP_IER0_RINT2_MK(1))
#define _CHIP_IER0_RINT2_CLR              (~(_CHIP_IER0_RINT2_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IER0_INT3: EXTERNAL USER INTERRUPT #3 ENABLE
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IER0_INT3_SHIFT             (0x000Bu)
#define _CHIP_IER0_INT3_MK(n)             (((Uint16)n & 0x0001u) << _CHIP_IER0_INT3_SHIFT)
#define _CHIP_IER0_INT3_MASK              (_CHIP_IER0_INT3_MK(1))
#define _CHIP_IER0_INT3_CLR               (~(_CHIP_IER0_INT3_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IER0_DSPINT: HOST TO DSP INTERRUPT ENABLE
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IER0_DSPINT_SHIFT          (0x000Au)
#define _CHIP_IER0_DSPINT_MK(n)          (((Uint16)n & 0x0001u) << _CHIP_IER0_DSPINT_SHIFT)
#define _CHIP_IER0_DSPINT_MASK           (_CHIP_IER0_DSPINT_MK(1))
#define _CHIP_IER0_DSPINT_CLR            (~(_CHIP_IER0_DSPINT_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IER0_DMAC1: DMA CHANNEL #1 INTERRUPT ENABLE
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IER0_DMAC1_SHIFT           (0x0009u)
#define _CHIP_IER0_DMAC1_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_IER0_DMAC1_SHIFT)
#define _CHIP_IER0_DMAC1_MASK            (_CHIP_IER0_DMAC1_MK(1))
#define _CHIP_IER0_DMAC1_CLR             (~(_CHIP_IER0_DMAC1_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IER0_XINT1: SERIAL PORT #1 TRANSMIT INTERRUPT ENABLE
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IER0_XINT1_SHIFT           (0x0007u)
#define _CHIP_IER0_XINT1_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_IER0_XINT1_SHIFT)
#define _CHIP_IER0_XINT1_MASK            (_CHIP_IER0_XINT1_MK(1))
#define _CHIP_IER0_XINT1_CLR             (~(_CHIP_IER0_XINT1_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IER0_RINT1: SERIAL PORT #1 RECEIVE INTERRUPT ENABLE
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IER0_RINT1_SHIFT           (0x0006u)
#define _CHIP_IER0_RINT1_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_IER0_RINT1_SHIFT)
#define _CHIP_IER0_RINT1_MASK            (_CHIP_IER0_RINT1_MK(1))
#define _CHIP_IER0_RINT1_CLR             (~(_CHIP_IER0_RINT1_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IER0_RINT0: SERIAL PORT #0 INTERRUPT ENABLE
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IER0_RINT0_SHIFT           (0x0005u)
#define _CHIP_IER0_RINT0_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_IER0_RINT0_SHIFT)
#define _CHIP_IER0_RINT0_MASK            (_CHIP_IER0_RINT0_MK(1))
#define _CHIP_IER0_RINT0_CLR             (~(_CHIP_IER0_RINT0_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IER0_TINT0: TIMER #0 INTERRUPT ENABLE
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IER0_TINT0_SHIFT           (0x0004u)
#define _CHIP_IER0_TINT0_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_IER0_TINT0_SHIFT)
#define _CHIP_IER0_TINT0_MASK            (_CHIP_IER0_TINT0_MK(1))
#define _CHIP_IER0_TINT0_CLR             (~(_CHIP_IER0_TINT0_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IER0_INT2: EXTERNAL USER #2 INTERRUPT ENABLE
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IER0_INT2_SHIFT            (0x0003u)
#define _CHIP_IER0_INT2_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_IER0_INT2_SHIFT)
#define _CHIP_IER0_INT2_MASK             (_CHIP_IER0_INT2_MK(1))
#define _CHIP_IER0_INT2_CLR              (~(_CHIP_IER0_INT2_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IER0_INT0: EXTERNAL USER #1 INTERRUPT ENABLE
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IER0_INT0_SHIFT            (0x0002u)
#define _CHIP_IER0_INT0_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_IER0_INT0_SHIFT)
#define _CHIP_IER0_INT0_MASK             (_CHIP_IER0_INT0_MK(1))
#define _CHIP_IER0_INT0_CLR              (~(_CHIP_IER0_INT0_MASK))

#define _CHIP_IER0_CFG(dmac5, dmac4, xint2, rint2, int3, dspint, dmac1,\
                       xint1, rint1, rint0, tint0, int2, int0)\
 _IER0 = (Uint16) ( _CHIP_IER0_DMAC5_MK(dmac5)   |\
                    _CHIP_IER0_DMAC4_MK(dmac4)   |\
                    _CHIP_IER0_XINT2_MK(xint2)   |\
                    _CHIP_IER0_RINT2_MK(rint2)   |\
                    _CHIP_IER0_INT3_MK(int3)     |\
                    _CHIP_IER0_DSPINT_MK(dspint) |\
                    _CHIP_IER0_DMAC1_MK(dmac1)   |\
                    _CHIP_IER0_XINT1_MK(xint1)   |\
                    _CHIP_IER0_RINT1_MK(rint1)   |\
                    _CHIP_IER0_RINT0_MK(rint0)   |\
                    _CHIP_IER0_TINT0_MK(tint0)   |\
                    _CHIP_IER0_INT2_MK(int2)     |\
                    _CHIP_IER0_INT0_MK(int0)     \
        )


/******************************************************************************\
* _CHIP_IER1 - control status register 2
*
* Fields:
*   (RW) _CHIP_IER1_INT5
*   (RW) _CHIP_IER1_TINT1
*   (RW) _CHIP_IER1_DMAC3
*   (RW) _CHIP_IER1_DMAC2
*   (RW) _CHIP_IER1_INT4
*   (RW) _CHIP_IER1_DMAC0
*   (RW) _CHIP_IER1_XINT0
*   (RW) _CHIP_IER1_INT1
*
\******************************************************************************/
#define _CHIP_IER1_ADDR     (0x0045u)
#define _CHIP_IER1          REG16(_CHIP_IER1_ADDR)
#define _IER1                _CHIP_IER1

#define _CHIP_IER1_GET\
   _REG_GET(CHIP_ADDR(IER1))

#define _CHIP_IER1_SET(Val)\
   _REG_SET(CHIP_ADDR(IER1),Val)

#define _CHIP_IER1_FGET(Field)\
 _FIELD_GET(CHIP_ADDR(IER1),_CHIP_IER1_##Field)

#define _CHIP_IER1_FSET(Field,Val)\
 _FIELD_SET(CHIP_ADDR(IER1),_CHIP_IER1_##Field,Val)
  

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IER1_INT5: EXTERNAL USER #5 INTERRUPT ENABLE BIT
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IER1_INT5_SHIFT            (0x0007u)
#define _CHIP_IER1_INT5_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_IER1_INT5_SHIFT)
#define _CHIP_IER1_INT5_MASK             (_CHIP_IER1_INT5_MK(1))
#define _CHIP_IER1_INT5_CLR              (~(_CHIP_IER1_INT5_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IER1_TINT1: TIMER #1 INTERRUPT ENABLE BIT
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IER1_TINT1_SHIFT            (0x0006u)
#define _CHIP_IER1_TINT1_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_IER1_TINT1_SHIFT)
#define _CHIP_IER1_TINT1_MASK             (_CHIP_IER1_TINT1_MK(1))
#define _CHIP_IER1_TINT1_CLR              (~(_CHIP_IER1_TINT1_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IER1_DMAC3: DMA CHANNEL #3 INTERRUPT ENABLE BIT
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IER1_DMAC3_SHIFT            (0x0005u)
#define _CHIP_IER1_DMAC3_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_IER1_DMAC3_SHIFT)
#define _CHIP_IER1_DMAC3_MASK             (_CHIP_IER1_DMAC3_MK(1))
#define _CHIP_IER1_DMAC3_CLR              (~(_CHIP_IER1_DMAC3_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IER1_DMAC2: DMA CHANNEL #2 INTERRUPT ENABLE BIT
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IER1_DMAC2_SHIFT            (0x0004u)
#define _CHIP_IER1_DMAC2_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_IER1_DMAC2_SHIFT)
#define _CHIP_IER1_DMAC2_MASK             (_CHIP_IER1_DMAC2_MK(1))
#define _CHIP_IER1_DMAC2_CLR              (~(_CHIP_IER1_DMAC2_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IER1_INT4: EXTERNAL USER #4 INTERRUPT ENABLE BIT
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IER1_INT4_SHIFT             (0x0003u)
#define _CHIP_IER1_INT4_MK(n)             (((Uint16)n & 0x0001u) << _CHIP_IER1_INT4_SHIFT)
#define _CHIP_IER1_INT4_MASK              (_CHIP_IER1_INT4_MK(1))
#define _CHIP_IER1_INT4_CLR               (~(_CHIP_IER1_INT4_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IER1_DMAC0: DMA CHANNEL #0 INTERRUPT ENABLE BIT
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IER1_DMAC0_SHIFT             (0x0002u)
#define _CHIP_IER1_DMAC0_MK(n)             (((Uint16)n & 0x0001u) << _CHIP_IER1_DMAC0_SHIFT)
#define _CHIP_IER1_DMAC0_MASK              (_CHIP_IER1_DMAC0_MK(1))
#define _CHIP_IER1_DMAC0_CLR               (~(_CHIP_IER1_DMAC0_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IER1_XINT0: SERIAL PORT #0 TRANSMIT INTERRUPT ENABLE BIT
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IER1_XINT0_SHIFT             (0x0001u)
#define _CHIP_IER1_XINT0_MK(n)             (((Uint16)n & 0x0001u) << _CHIP_IER1_XINT0_SHIFT)
#define _CHIP_IER1_XINT0_MASK              (_CHIP_IER1_XINT0_MK(1))
#define _CHIP_IER1_XINT0_CLR               (~(_CHIP_IER1_XINT0_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IER1_INT1: EXTERNAL USER #1 INTERRUPT ENABLE BIT
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IER1_INT1_SHIFT              (0x0000u)
#define _CHIP_IER1_INT1_MK(n)              (((Uint16)n & 0x0001u) << _CHIP_IER1_INT1_SHIFT)
#define _CHIP_IER1_INT1_MASK               (_CHIP_IER1_INT1_MK(1))
#define _CHIP_IER1_INT1_CLR                (~(_CHIP_IER1_INT1_MASK))

#define _CHIP_IER1_CFG(int5, tint1, dmac3, dmac2, int4, dmac0, xint0, int1)\
  _IER1 =  (Uint16)( _CHIP_IER1_INT5_MK(int5)   |\
                     _CHIP_IER1_TINT1_MK(tint1) |\
                     _CHIP_IER1_DMAC3_MK(dmac3) |\
                     _CHIP_IER1_DMAC2_MK(dmac2) |\
                     _CHIP_IER1_INT4_MK(int4)   |\
                     _CHIP_IER1_DMAC0_MK(dmac0) |\
                     _CHIP_IER1_XINT0_MK(xint0) |\
                     _CHIP_IER1_INT1_MK(int1)   \
          )

 
/******************************************************************************\
* _CHIP_IFR0 - INTERRUPT FLAG REGISTER #0
*
* Fields:
*   (RW) _CHIP_IFR0_DMAC5
*   (RW) _CHIP_IFR0_DMAC4
*   (RW) _CHIP_IFR0_XINT2
*   (RW) _CHIP_IFR0_RINT2
*   (RW) _CHIP_IFR0_INT3
*   (RW) _CHIP_IFR0_DSPINT
*   (RW) _CHIP_IFR0_DMAC1
*   (RW) _CHIP_IFR0_XINT1
*   (RW) _CHIP_IFR0_RINT1
*   (RW) _CHIP_IFR0_RINT0
*   (RW) _CHIP_IFR0_TINT0
*   (RW) _CHIP_IFR0_INT2
*   (RW) _CHIP_IFR0_INT0
*
\******************************************************************************/
#define _CHIP_IFR0_ADDR     (0x0001u)
#define _CHIP_IFR0          REG16(_CHIP_IFR0_ADDR)
#define _IFR0                _CHIP_IFR0

#define _CHIP_IFR0_GET\
   _REG_GET(CHIP_ADDR(IFR0))

#define _CHIP_IFR0_SET(Val)\
   _REG_SET(CHIP_ADDR(IFR0), Val)

#define _CHIP_IFR0_FGET(Field)\
 _FIELD_GET(CHIP_ADDR(IFR0),_CHIP_IFR0_##Field)

#define _CHIP_IFR0_FSET(Field,Val)\
 _FIELD_SET(CHIP_ADDR(IFR0),_CHIP_IFR0_##Field,Val)
  

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IFR0_DMAC5: DMA CHANNEL 5 INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IFR0_DMAC5_SHIFT            (0x000Fu)
#define _CHIP_IFR0_DMAC5_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_IFR0_DMAC5_SHIFT)
#define _CHIP_IFR0_DMAC5_MASK             (_CHIP_IFR0_DMAC5_MK(1))
#define _CHIP_IFR0_DMAC5_CLR              (~(_CHIP_IFR0_DMAC5_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IFR0_DMAC4: DMA CHANNEL 4 INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IFR0_DMAC4_SHIFT            (0x000Eu)
#define _CHIP_IFR0_DMAC4_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_IFR0_DMAC4_SHIFT)
#define _CHIP_IFR0_DMAC4_MASK             (_CHIP_IFR0_DMAC4_MK(1))
#define _CHIP_IFR0_DMAC4_CLR              (~(_CHIP_IFR0_DMAC4_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IFR0_XINT2: SERIAL PORT #2 TRANSMIT INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IFR0_XINT2_SHIFT            (0x000Du)
#define _CHIP_IFR0_XINT2_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_IFR0_XINT2_SHIFT)
#define _CHIP_IFR0_XINT2_MASK             (_CHIP_IFR0_XINT2_MK(1))
#define _CHIP_IFR0_XINT2_CLR              (~(_CHIP_IFR0_XINT2_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IFR0_RINT2: SERIAL PORT #2 RECEIVE INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IFR0_RINT2_SHIFT            (0x000Cu)
#define _CHIP_IFR0_RINT2_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_IFR0_RINT2_SHIFT)
#define _CHIP_IFR0_RINT2_MASK             (_CHIP_IFR0_RINT2_MK(1))
#define _CHIP_IFR0_RINT2_CLR              (~(_CHIP_IFR0_RINT2_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IFR0_INT3: EXTERNAL USER INTERRUPT #3 FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IFR0_INT3_SHIFT             (0x000Bu)
#define _CHIP_IFR0_INT3_MK(n)             (((Uint16)n & 0x0001u) << _CHIP_IFR0_INT3_SHIFT)
#define _CHIP_IFR0_INT3_MASK              (_CHIP_IFR0_INT3_MK(1))
#define _CHIP_IFR0_INT3_CLR               (~(_CHIP_IFR0_INT3_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IFR0_DSPINT: HOST TO DSP INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IFR0_DSPINT_SHIFT          (0x000Au)
#define _CHIP_IFR0_DSPINT_MK(n)          (((Uint16)n & 0x0001u) << _CHIP_IFR0_DSPINT_SHIFT)
#define _CHIP_IFR0_DSPINT_MASK           (_CHIP_IFR0_DSPINT_MK(1))
#define _CHIP_IFR0_DSPINT_CLR            (~(_CHIP_IFR0_DSPINT_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IFR0_DMAC1: DMA CHANNEL #1 INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IFR0_DMAC1_SHIFT           (0x0009u)
#define _CHIP_IFR0_DMAC1_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_IFR0_DMAC1_SHIFT)
#define _CHIP_IFR0_DMAC1_MASK            (_CHIP_IFR0_DMAC1_MK(1))
#define _CHIP_IFR0_DMAC1_CLR             (~(_CHIP_IFR0_DMAC1_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IFR0_XINT1: SERIAL PORT #1 TRANSMIT INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IFR0_XINT1_SHIFT           (0x0007u)
#define _CHIP_IFR0_XINT1_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_IFR0_XINT1_SHIFT)
#define _CHIP_IFR0_XINT1_MASK            (_CHIP_IFR0_XINT1_MK(1))
#define _CHIP_IFR0_XINT1_CLR             (~(_CHIP_IFR0_XINT1_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IFR0_RINT1: SERIAL PORT #1 RECEIVE INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IFR0_RINT1_SHIFT           (0x0006u)
#define _CHIP_IFR0_RINT1_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_IFR0_RINT1_SHIFT)
#define _CHIP_IFR0_RINT1_MASK            (_CHIP_IFR0_RINT1_MK(1))
#define _CHIP_IFR0_RINT1_CLR             (~(_CHIP_IFR0_RINT1_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IFR0_RINT0: SERIAL PORT #0 INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IFR0_RINT0_SHIFT           (0x0005u)
#define _CHIP_IFR0_RINT0_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_IFR0_RINT0_SHIFT)
#define _CHIP_IFR0_RINT0_MASK            (_CHIP_IFR0_RINT0_MK(1))
#define _CHIP_IFR0_RINT0_CLR             (~(_CHIP_IFR0_RINT0_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IFR0_TINT0: TIMER #0 INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IFR0_TINT0_SHIFT           (0x0004u)
#define _CHIP_IFR0_TINT0_MK(n)           (((Uint16)n & 0x0001u) << _CHIP_IFR0_TINT0_SHIFT)
#define _CHIP_IFR0_TINT0_MASK            (_CHIP_IFR0_TINT0_MK(1))
#define _CHIP_IFR0_TINT0_CLR             (~(_CHIP_IFR0_TINT0_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IFR0_INT2: EXTERNAL USER #2 INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IFR0_INT2_SHIFT            (0x0003u)
#define _CHIP_IFR0_INT2_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_IFR0_INT2_SHIFT)
#define _CHIP_IFR0_INT2_MASK             (_CHIP_IFR0_INT2_MK(1))
#define _CHIP_IFR0_INT2_CLR              (~(_CHIP_IFR0_INT2_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IFR0_INT0: EXTERNAL USER #1 INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IFR0_INT0_SHIFT            (0x0002u)
#define _CHIP_IFR0_INT0_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_IFR0_INT0_SHIFT)
#define _CHIP_IFR0_INT0_MASK             (_CHIP_IFR0_INT0_MK(1))
#define _CHIP_IFR0_INT0_CLR              (~(_CHIP_IFR0_INT0_MASK))

#define _CHIP_IFR0_CFG(dmac5, dmac4, xint2, rint2, int3, dspint, dmac1,\
                       xint1, rint1, rint0, tint0, int2, int0)\
  _IFR0 = (Uint16) ( _CHIP_IFR0_DMAC5_MK(dmac5)   |\
                     _CHIP_IFR0_DMAC4_MK(dmac4)   |\
                     _CHIP_IFR0_XINT2_MK(xint2)   |\
                     _CHIP_IFR0_RINT2_MK(rint2)   |\
                     _CHIP_IFR0_INT3_MK(int3)     |\
                     _CHIP_IFR0_DSPINT_MK(dspint) |\
                     _CHIP_IFR0_DMAC1_MK(dmac1)   |\
                     _CHIP_IFR0_XINT1_MK(xint1)   |\
                     _CHIP_IFR0_RINT1_MK(rint1)   |\
                     _CHIP_IFR0_RINT0_MK(rint0)   |\
                     _CHIP_IFR0_TINT0_MK(tint0)   |\
                     _CHIP_IFR0_INT2_MK(int2)     |\
                     _CHIP_IFR0_INT0_MK(int0)     \
         )


/******************************************************************************\
* _CHIP_IFR1 - control status register 2
*
* Fields:
*   (RW) _CHIP_IFR1_INT5
*   (RW) _CHIP_IFR1_TINT1
*   (RW) _CHIP_IFR1_DMAC3
*   (RW) _CHIP_IFR1_DMAC2
*   (RW) _CHIP_IFR1_INT4
*   (RW) _CHIP_IFR1_DMAC0
*   (RW) _CHIP_IFR1_XINT0
*   (RW) _CHIP_IFR1_INT1
*
\******************************************************************************/
#define _CHIP_IFR1_ADDR     (0x0046u)
#define _CHIP_IFR1          REG16(_CHIP_IFR1_ADDR)
#define _IFR1                _CHIP_IFR1

#define _CHIP_IFR1_GET\
   _REG_GET(CHIP_ADDR(IFR1))

#define _CHIP_IFR1_SET(Val)\
   _REG_SET(CHIP_ADDR(IFR1), Val)

#define _CHIP_IFR1_FGET(Field)\
 _FIELD_GET(CHIP_ADDR(IFR1),_CHIP_IFR1_##Field)

#define _CHIP_IFR1_FSET(Field,Val)\
 _FIELD_SET(CHIP_ADDR(IFR1),_CHIP_IFR1_##Field,Val)
  

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IFR1_INT5: EXTERNAL USER #5 INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IFR1_INT5_SHIFT            (0x0007u)
#define _CHIP_IFR1_INT5_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_IFR1_INT5_SHIFT)
#define _CHIP_IFR1_INT5_MASK             (_CHIP_IFR1_INT5_MK(1))
#define _CHIP_IFR1_INT5_CLR              (~(_CHIP_IFR1_INT5_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IFR1_TINT1: TIMER #1 INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IFR1_TINT1_SHIFT            (0x0006u)
#define _CHIP_IFR1_TINT1_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_IFR1_TINT1_SHIFT)
#define _CHIP_IFR1_TINT1_MASK             (_CHIP_IFR1_TINT1_MK(1))
#define _CHIP_IFR1_TINT1_CLR              (~(_CHIP_IFR1_TINT1_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IFR1_DMAC3: DMA CHANNEL #3 INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IFR1_DMAC3_SHIFT            (0x0005u)
#define _CHIP_IFR1_DMAC3_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_IFR1_DMAC3_SHIFT)
#define _CHIP_IFR1_DMAC3_MASK             (_CHIP_IFR1_DMAC3_MK(1))
#define _CHIP_IFR1_DMAC3_CLR              (~(_CHIP_IFR1_DMAC3_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IFR1_DMAC2: DMA CHANNEL #2 INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IFR1_DMAC2_SHIFT            (0x0004u)
#define _CHIP_IFR1_DMAC2_MK(n)            (((Uint16)n & 0x0001u) << _CHIP_IFR1_DMAC2_SHIFT)
#define _CHIP_IFR1_DMAC2_MASK             (_CHIP_IFR1_DMAC2_MK(1))
#define _CHIP_IFR1_DMAC2_CLR              (~(_CHIP_IFR1_DMAC2_MASK))


/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IFR1_INT4: EXTERNAL USER #4 INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IFR1_INT4_SHIFT             (0x0003u)
#define _CHIP_IFR1_INT4_MK(n)             (((Uint16)n & 0x0001u) << _CHIP_IFR1_INT4_SHIFT)
#define _CHIP_IFR1_INT4_MASK              (_CHIP_IFR1_INT4_MK(1))
#define _CHIP_IFR1_INT4_CLR               (~(_CHIP_IFR1_INT4_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IFR1_DMAC0: DMA CHANNEL #0 INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IFR1_DMAC0_SHIFT             (0x0002u)
#define _CHIP_IFR1_DMAC0_MK(n)             (((Uint16)n & 0x0001u) << _CHIP_IFR1_DMAC0_SHIFT)
#define _CHIP_IFR1_DMAC0_MASK              (_CHIP_IFR1_DMAC0_MK(1))
#define _CHIP_IFR1_DMAC0_CLR               (~(_CHIP_IFR1_DMAC0_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IFR1_XINT0: SERIAL PORT #0 TRANSMIT INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IFR1_XINT0_SHIFT             (0x0001u)
#define _CHIP_IFR1_XINT0_MK(n)             (((Uint16)n & 0x0001u) << _CHIP_IFR1_XINT0_SHIFT)
#define _CHIP_IFR1_XINT0_MASK              (_CHIP_IFR1_XINT0_MK(1))
#define _CHIP_IFR1_XINT0_CLR               (~(_CHIP_IFR1_XINT0_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IFR1_INT1: EXTERNAL USER #1 INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IFR1_INT1_SHIFT              (0x0000u)
#define _CHIP_IFR1_INT1_MK(n)              (((Uint16)n & 0x0001u) << _CHIP_IFR1_INT1_SHIFT)
#define _CHIP_IFR1_INT1_MASK               (_CHIP_IFR1_INT1_MK(1))
#define _CHIP_IFR1_INT1_CLR                (~(_CHIP_IFR1_INT1_MASK))

#define _CHIP_IFR1_CFG(int5, tint1, dmac3, dmac2, int4, dmac0, xint0, int1)\
  _IFR1 = (Uint16)( _CHIP_IFR1_INT5_MK(int5)   |\
                    _CHIP_IFR1_TINT1_MK(tint1) |\
                    _CHIP_IFR1_DMAC3_MK(dmac3) |\
                    _CHIP_IFR1_DMAC2_MK(dmac2) |\
                    _CHIP_IFR1_INT4_MK(int4)   |\
                    _CHIP_IFR1_DMAC0_MK(dmac0) |\
                    _CHIP_IFR1_XINT0_MK(xint0) |\
                    _CHIP_IFR1_INT1_MK(int1)   \
         )

  

/******************************************************************************\
* _CHIP_IVPD - control status register 2
*
* Fields:
*   (RW) _CHIP_IVPD_IVPD
*
\******************************************************************************/
#define _CHIP_IVPD_ADDR     (0x0049u)
#define _CHIP_IVPD          REG16(_CHIP_IVPD_ADDR)
#define _IVPD                _CHIP_IVPD

#define _CHIP_IVPD_GET\
   _REG_GET(CHIP_ADDR(IVPD))

#define _CHIP_IVPD_SET(Val)\
   _REG_SET(CHIP_ADDR(IVPD), Val)

#define _CHIP_IVPD_FGET(Field)\
 _FIELD_GET(CHIP_ADDR(IVPD),_CHIP_IVPD_##Field)

#define _CHIP_IVPD_FSET(Field,Val)\
 _FIELD_SET(CHIP_ADDR(IVPD),_CHIP_IVPD_##Field,Val)


/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IVPD_IVPD: EXTERNAL USER #1 INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IVPD_IVPD_SHIFT              (0x0000u)
#define _CHIP_IVPD_IVPD_MK(n)              (((Uint16)n & 0xFFFFu) << _CHIP_IVPD_IVPD_SHIFT)
#define _CHIP_IVPD_IVPD_MASK               (_CHIP_IVPD_IVPD_MK(0xFFFFu))
#define _CHIP_IVPD_IVPD_CLR                (~(_CHIP_IVPD_IVPD_MASK))

#define _CHIP_IVPD_CFG(ivpd)\
 _REG_SET(CHIP_ADDR(IVPD),ivpd)  
  
/******************************************************************************\
* _CHIP_IVPH - control status register 2
*
* Fields:
*   (RW) _CHIP_IVPH_IVPH
*
\******************************************************************************/
#define _CHIP_IVPH_ADDR     (0x004Au)
#define _CHIP_IVPH          REG16(_CHIP_IVPH_ADDR)
#define _IVPH                _CHIP_IVPH

#define _CHIP_IVPH_GET\
   _REG_GET(CHIP_ADDR(IVPH))

#define _CHIP_IVPH_SET(Val)\
   _REG_SET(CHIP_ADDR(IVPH),Val)

#define _CHIP_IVPH_FGET(Field)\
 _FIELD_GET(CHIP_ADDR(IVPH),_CHIP_IVPH_##Field)

#define _CHIP_IVPH_FSET(Field, Val)\
 _FIELD_SET(CHIP_ADDR(IVPH),_CHIP_IVPH_##Field,Val)


/*----------------------------------------------------------------------------*\
* (RW) _CHIP_IVPH_IVPH: EXTERNAL USER #1 INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_IVPH_IVPH_SHIFT              (0x0000u)
#define _CHIP_IVPH_IVPH_MK(n)              (((Uint16)n & 0xFFFFu) << _CHIP_IVPH_IVPH_SHIFT)
#define _CHIP_IVPH_IVPH_MASK               (_CHIP_IVPH_IVPH_MK(0xFFFFu))
#define _CHIP_IVPH_IVPH_CLR                (~(_CHIP_IVPH_IVPH_MASK))

#define _CHIP_IVPH_CFG(ivph)\
 _REG_SET(CHIP_ADDR(IVPH), ivph)  

/******************************************************************************\
* _CHIP_PDP - peripheral data page register
*
* Fields:
*   (RW) _CHIP_PDP_PDP
*
\******************************************************************************/
#define _CHIP_PDP_ADDR     (0x002Fu)
#define _CHIP_PDP          REG16(_CHIP_PDP_ADDR)
#define _PDP                _CHIP_PDP

#define _CHIP_PDP_GET\
   _REG_GET(CHIP_ADDR(PDP))

#define _CHIP_PDP_SET(Val)\
   _REG_SET(CHIP_ADDR(PDP), Val)

#define _CHIP_PDP_FGET(Field)\
 _FIELD_GET(CHIP_ADDR(PDP),_CHIP_PDP_##Field)

#define _CHIP_PDP_FSET(Field,Val)\
 _FIELD_SET(CHIP_ADDR(PDP),_CHIP_PDP_##Field,Val)

/*----------------------------------------------------------------------------*\
* (RW) _CHIP_PDP_PDP: EXTERNAL USER #1 INTERRUPT FLAG
\*----------------------------------------------------------------------------*/ 
#define _CHIP_PDP_PDP_SHIFT              (0x0000u)
#define _CHIP_PDP_PDP_MK(n)              (((Uint16)n & 0x00FFu) << _CHIP_PDP_PDP_SHIFT)
#define _CHIP_PDP_PDP_MASK               (_CHIP_PDP_PDP_MK(0xFF))
#define _CHIP_PDP_PDP_CLR                (~(_CHIP_PDP_PDP_MASK))

#define _CHIP_PDP_CFG(pdp)\
 _REG_SET(CHIP_ADDR(PDP),pdp)  

/******************************************************************************\
* _CHIP_REVID - Revison ID Register
*
\******************************************************************************/
#define _CHIP_REVID_ADDR     (0x3804u)

#define _CHIP_REVID_GET\
  _PREG_GET(CHIP_ADDR(REVID))

#if (CHIP_5502) || (CHIP_5501)
/******************************************************************************\
* _CHIP_REVIDL - Revison ID Register
*
\******************************************************************************/
#define _CHIP_REVIDL_ADDR     (0x3804u)

#define _CHIP_REVIDL_GET\
  _PREG_GET(CHIP_ADDR(REVIDL))

/******************************************************************************\
* _CHIP_REVIDH - Revison ID Register
*
\******************************************************************************/
#define _CHIP_REVIDH_ADDR     (0x3805u)

#define _CHIP_REVIDH_GET\
  _PREG_GET(CHIP_ADDR(REVIDH))

/******************************************************************************\
* _CHIP_SUBID - Revison ID Register
*
\******************************************************************************/
#define _CHIP_SUBID_ADDR     (0x3806u)

#define _CHIP_SUBID_GET\
  _PREG_GET(CHIP_ADDR(SUBID))

#endif /*(CHIP_5502) || (CHIP_5501) */

#if (CHIP_5502)
/******************************************************************************\
* _CHIP_CATID - Catalog Device ID Register
*
\******************************************************************************/
#define _CHIP_CATID_ADDR     (0x3807u)

#define _CHIP_CATID_GET\
  _PREG_GET(CHIP_ADDR(CATID))

#endif


/******************************************************************************\
* The DIEID Register is 64-bit. In order to manipulate it we define:
*             DIEIDH: the high 32 bits
*             DIEIDL: the low 32 bits
*
*
*
* _CHIP_DIEIDH - High 32 bits of DieID register
* _CHIP_DIEIDL - Low 32 bits of the DieID register
*
\******************************************************************************/

#define _CHIP_DIEIDH_ADDR     (0x3800u)
#define _CHIP_DIEIDL_ADDR     (0x3802u)


#define _CHIP_DIEIDL_GET\
  _PREG16_GET(CHIP_ADR(DIEIDL))

#define _CHIP_DIEIDH_GET\
  _PREG16_GET(CHIP_ADR(DIEIDH))

#define _CHIP_DIEID_GET\
  _PREG32_GET(CHIP_ADDR(DIEIDH))

#if (CHIP_5510PG2_0)  || (CHIP_5509A)
  /******************************************************************************\
  * _CHIP_SYSR - System Control Register
  *
  * Fields:
  *   (RW) _CHIP_SYSR_HPE
  *   (RW) _CHIP_SYSR_BH
  *   (RW) _CHIP_SYSR_HBH
  *   (R)  _CHIP_SYSR_BOOTM3
  *   (RW) _CHIP_SYSR_CLKDIV
  *
  \******************************************************************************/
  #define _CHIP_SYSR_ADDR       (0x07FDu)
  #define _CHIP_SYSR            PREG16(_CHIP_SYSR_ADDR)
  #define _SYSR                 _SYSR

  #define _CHIP_SYSR_GET\
     _PREG_GET(CHIP_ADDR(SYSR))

  #define _CHIP_SYSR_SET(Val)\
     _PREG_SET(CHIP_ADDR(SYSR), Val)

  #define _CHIP_SYSR_FGET(Field)\
   _PFIELD_GET(CHIP_ADDR(SYSR),_CHIP_SYSR_##Field)

  #define _CHIP_SYSR_FSET(Field,Val)\
   _PFIELD_SET(CHIP_ADDR(SYSR),_CHIP_SYSR_##Field,Val)


  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_SYSR_HPE: Host Port Internal Pull-up Control Enable
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_SYSR_HPE_SHIFT         (0x0009u)
  #define _CHIP_SYSR_HPE_MK(n)         (((Uint16)n & 0x001u) << _CHIP_SYSR_HPE_SHIFT)
  #define _CHIP_SYSR_HPE_MASK          (_CHIP_SYSR_HPE_MK(0x1))
  #define _CHIP_SYSR_HPE_CLR           (~(_CHIP_SYSR_HPE_MASK))

  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_SYSR_BH: Enable/disable EMIF bus holders
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_SYSR_BH_SHIFT          (0x0008u)
  #define _CHIP_SYSR_BH_MK(n)          (((Uint16)n & 0x001u) << _CHIP_SYSR_BH_SHIFT)
  #define _CHIP_SYSR_BH_MASK           (_CHIP_SYSR_BH_MK(0x1))
  #define _CHIP_SYSR_BH_CLR            (~(_CHIP_SYSR_BH_MASK))

  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_SYSR_HBH: Enable/disable Host Port bus holders
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_SYSR_HBH_SHIFT         (0x0007u)
  #define _CHIP_SYSR_HBH_MK(n)         (((Uint16)n & 0x001u) << _CHIP_SYSR_HBH_SHIFT)
  #define _CHIP_SYSR_HBH_MASK          (_CHIP_SYSR_HBH_MK(0x1))
  #define _CHIP_SYSR_HBH_CLR           (~(_CHIP_SYSR_HBH_MASK))

  /*----------------------------------------------------------------------------*\
  * (R) _CHIP_SYSR_BOOTM3: Boot mode select status
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_SYSR_BOOTM3_SHIFT      (0x0006u)
  #define _CHIP_SYSR_BOOTM3_MK(n)      (((Uint16)n & 0x001u) << _CHIP_SYSR_BOOTM3_SHIFT)
  #define _CHIP_SYSR_BOOTM3_MASK       (_CHIP_SYSR_BOOTM3_MK(0x1))
  #define _CHIP_SYSR_BOOTM3_CLR        (~(_CHIP_SYSR_BOOTM3_MASK))

  /*----------------------------------------------------------------------------*\
  * (R) _CHIP_SYSR_CLKDIV: Clockout divide down factor relative to CPU clock
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_SYSR_CLKDIV_SHIFT      (0x0000u)
  #define _CHIP_SYSR_CLKDIV_MK(n)      (((Uint16)n & 0x007u) << _CHIP_SYSR_CLKDIV_SHIFT)
  #define _CHIP_SYSR_CLKDIV_MASK       (_CHIP_SYSR_CLKDIV_MK(0x7))
  #define _CHIP_SYSR_CLKDIV_CLR        (~(_CHIP_SYSR_CLKDIV_MASK))

  #define _CHIP_SYSR_CFG(hpe, bh, hbh, clkdiv)\
    _SYSR = (Uint16)( _CHIP_SYSR_HPE_MK(hpe)      |\
                      _CHIP_SYSR_BH_MK(bh)        |\
                      _CHIP_SYSR_HBH_MK(hbh)      |\
                      _CHIP_SYSR_CLKDIV_MK(clkdiv) \
           )

#endif /* (CHIP_5510PG2_0) || (CHIP_5509A)*/

#if (CHIP_5509) || (CHIP_5509A) 
  /******************************************************************************\
  * _CHIP_XBSR - External Bus Select Register
  *
  * Fields:
  *   (RW) _CHIP_XBSR_CLKOUT     Enable/disable clkout 
  *   (RW) _CHIP_XBSR_OSCDIS     OSCDIS Enable/disable 
  *   (RW) _CHIP_XBSR_HIDL       Host mode idle bit
  *   (RW) _CHIP_XBSR_BKE        Bus keep enable bit
  *   (RW) _CHIP_XBSR_EMIFX2     EMIF SDRAM divide-by-2 mode (5509 only)
  *   (RW) _CHIP_XBSR_SRSTAT     SDRAM self refresh status bit (5509A only)
  *   (RW) _CHIP_XBSR_HLD        EMIF hold bit
  *   (RW) _CHIP_XBSR_HLDA       EMIF hold acknowledge bit
  *   (RW) _CHIP_XBSR_CKE        EMIF SDRAM clock/refresh pin select (5509A only)
  *   (RW) _CHIP_XBSR_CKEEN      EMIF SDRAM CKE enable bit (5509A only)
  *   (RW) _CHIP_XBSR_SRCOM      EMIF Self-refresh Command (5509A only)
  *   (RW) _CHIP_XBSR_SP2        Serial Port 2 Mode
  *   (RW) _CHIP_XBSR_SP1        Serial Port 1 Mode
  *   (RW) _CHIP_XBSR_PP         Parallel Port Mode
  *
  \******************************************************************************/
  #define _CHIP_XBSR_ADDR       (0x6C00u)
  #define _CHIP_XBSR             PREG16(_CHIP_XBSR_ADDR)
  #define _XBSR                 _CHIP_XBSR

  #define _CHIP_XBSR_GET\
     _PREG_GET(_CHIP_XBSR_ADDR)

  #define _CHIP_XBSR_SET(Val)\
     _PREG_SET(_CHIP_XBSR_ADDR, Val)

  #define _CHIP_XBSR_FGET(Field)\
   _PFIELD_GET(_CHIP_XBSR_ADDR,_CHIP_XBSR_##Field)

  #define _CHIP_XBSR_FSET(Field,Val)\
   _PFIELD_SET(_CHIP_XBSR_ADDR,_CHIP_XBSR_##Field,Val)

  /*----------------------------------------------------------------------------*\
  * (R) _CHIP_XBSR_CLKOUT: CLKOUT Enable/disable 
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBSR_CLKOUT_SHIFT      (0x000Fu)
  #define _CHIP_XBSR_CLKOUT_MK(n)      (((Uint16)n & 0x001u) << _CHIP_XBSR_CLKOUT_SHIFT)
  #define _CHIP_XBSR_CLKOUT_MASK       (_CHIP_XBSR_CLKOUT_MK(0x1))
  #define _CHIP_XBSR_CLKOUT_CLR        (~(_CHIP_XBSR_CLKOUT_MASK))

  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_XBSR_OSCDIS: OSCDIS Enable/disable 
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBSR_OSCDIS_SHIFT      (0x000Eu)
  #define _CHIP_XBSR_OSCDIS_MK(n)      (((Uint16)n & 0x001u) << _CHIP_XBSR_OSCDIS_SHIFT)
  #define _CHIP_XBSR_OSCDIS_MASK       (_CHIP_XBSR_OSCDIS_MK(0x1))
  #define _CHIP_XBSR_OSCDIS_CLR        (~(_CHIP_XBSR_OSCDIS_MASK))

  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_XBSR_HIDL: Host mode idle bit
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBSR_HIDL_SHIFT        (0x000Du)
  #define _CHIP_XBSR_HIDL_MK(n)        (((Uint16)n & 0x001u) << _CHIP_XBSR_HIDL_SHIFT)
  #define _CHIP_XBSR_HIDL_MASK         (_CHIP_XBSR_HIDL_MK(0x1))
  #define _CHIP_XBSR_HIDL_CLR          (~(_CHIP_XBSR_HIDL_MASK))

  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_XBSR_BKE: Bus Keep Enable bit
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBSR_BKE_SHIFT         (0x000Cu)
  #define _CHIP_XBSR_BKE_MK(n)         (((Uint16)n & 0x001u) << _CHIP_XBSR_BKE_SHIFT)
  #define _CHIP_XBSR_BKE_MASK          (_CHIP_XBSR_BKE_MK(0x1))
  #define _CHIP_XBSR_BKE_CLR           (~(_CHIP_XBSR_BKE_MASK))

  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_XBSR_EMIFX2: EMIFX2 Enable/disable (5509 only) 
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBSR_EMIFX2_SHIFT      (0x000Bu)
  #define _CHIP_XBSR_EMIFX2_MK(n)      (((Uint16)n & 0x001u) << _CHIP_XBSR_EMIFX2_SHIFT)
  #define _CHIP_XBSR_EMIFX2_MASK       (_CHIP_XBSR_EMIFX2_MK(0x1))
  #define _CHIP_XBSR_EMIFX2_CLR        (~(_CHIP_XBSR_EMIFX2_MASK))

  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_XBSR_SRSTAT: SDRAM self refresh status bit (5509A only)
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBSR_SRSTAT_SHIFT      (0x000Bu)
  #define _CHIP_XBSR_SRSTAT_MK(n)      (((Uint16)n & 0x001u) << _CHIP_XBSR_SRSTAT_SHIFT)
  #define _CHIP_XBSR_SRSTAT_MASK       (_CHIP_XBSR_SRSTAT_MK(0x1))
  #define _CHIP_XBSR_SRSTAT_CLR        (~(_CHIP_XBSR_SRSTAT_MASK))
 
  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_XBSR_HLD: EMIF hold bit (5509A only)
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBSR_HLD_SHIFT         (0x000Au)
  #define _CHIP_XBSR_HLD_MK(n)         (((Uint16)n & 0x001u) << _CHIP_XBSR_HLD_SHIFT)
  #define _CHIP_XBSR_HLD_MASK          (_CHIP_XBSR_HLD_MK(0x1))
  #define _CHIP_XBSR_HLD_CLR           (~(_CHIP_XBSR_HLD_MASK))
 
  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_XBSR_HLDA: EMIF hold acknowledge bit(5509A only)
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBSR_HLDA_SHIFT        (0x0009u)
  #define _CHIP_XBSR_HLDA_MK(n)        (((Uint16)n & 0x001u) << _CHIP_XBSR_HLDA_SHIFT)
  #define _CHIP_XBSR_HLDA_MASK         (_CHIP_XBSR_HLDA_MK(0x1))
  #define _CHIP_XBSR_HLDA_CLR          (~(_CHIP_XBSR_HLDA_MASK))

  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_XBSR_CKE: EMIFX2 clock pin select
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBSR_CKE_SHIFT         (0x0008u)
  #define _CHIP_XBSR_CKE_MK(n)         (((Uint16)n & 0x001u) << _CHIP_XBSR_CKE_SHIFT)
  #define _CHIP_XBSR_CKE_MASK          (_CHIP_XBSR_CKE_MK(0x1))
  #define _CHIP_XBSR_CKE_CLR           (~(_CHIP_XBSR_CKE_MASK))

  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_XBSR_CKE: EMIFX2 SDRAM clock enable
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBSR_CKEEN_SHIFT       (0x0007u)
  #define _CHIP_XBSR_CKEEN_MK(n)       (((Uint16)n & 0x001u) << _CHIP_XBSR_CKEEN_SHIFT)
  #define _CHIP_XBSR_CKEEN_MASK        (_CHIP_XBSR_CKEEN_MK(0x1))
  #define _CHIP_XBSR_CKEEN_CLR         (~(_CHIP_XBSR_CKEEN_MASK))

  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_XBSR_CKE: EMIFX2 SDRAM refresh command
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBSR_SRCOM_SHIFT       (0x0006u)
  #define _CHIP_XBSR_SRCOM_MK(n)       (((Uint16)n & 0x001u) << _CHIP_XBSR_SRCOM_SHIFT)
  #define _CHIP_XBSR_SRCOM_MASK        (_CHIP_XBSR_SRCOM_MK(0x1))
  #define _CHIP_XBSR_SRCOM_CLR         (~(_CHIP_XBSR_SRCOM_MASK))


  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_XBSR_SP2: Serial Port #2 Mode Select SP/MMC/MS
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBSR_SP2_SHIFT         (0x0004u)
  #define _CHIP_XBSR_SP2_MK(n)         (((Uint16)n & 0x003u) << _CHIP_XBSR_SP2_SHIFT)
  #define _CHIP_XBSR_SP2_MASK          (_CHIP_XBSR_SP2_MK(0x3))
  #define _CHIP_XBSR_SP2_CLR           (~(_CHIP_XBSR_SP2_MASK))

  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_XBSR_SP1: Serial Port #1 Mode Select SP/MMC/MS
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBSR_SP1_SHIFT         (0x0002u)
  #define _CHIP_XBSR_SP1_MK(n)         (((Uint16)n & 0x003u) << _CHIP_XBSR_SP1_SHIFT)
  #define _CHIP_XBSR_SP1_MASK          (_CHIP_XBSR_SP1_MK(0x3))
  #define _CHIP_XBSR_SP1_CLR           (~(_CHIP_XBSR_SP1_MASK))

  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_XBSR_PP: Parallel Port Mode Select
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBSR_PP_SHIFT          (0x0000u)
  #define _CHIP_XBSR_PP_MK(n)          (((Uint16)n & 0x003u) << _CHIP_XBSR_PP_SHIFT)
  #define _CHIP_XBSR_PP_MASK           (_CHIP_XBSR_PP_MK(0x3))
  #define _CHIP_XBSR_PP_CLR            (~(_CHIP_XBSR_PP_MASK))

  #if (CHIP_5509) /*(CHIP_5509)*/

  #define _CHIP_XBSR_CFG(clkout, osc, hidl, bke, emifx2, hld, hlda, sp2mode,sp1mode,ppmode)\
    _CHIP = (Uint16)( _CHIP_XBSR_CLKOUT_MK(clkout)           |\
                          _CHIP_XBSR_OSCDIS_MK(osc)          |\
                          _CHIP_XBSR_HIDL_MK(hidl)           |\
                          _CHIP_XBSR_BKE_MK(bke)             |\
                          _CHIP_XBSR_EMIFX2_MK(emifx2)       |\
                          _CHIP_XBSR_HLD_MK(hld)             |\
                          _CHIP_XBSR_HLDA_MK(hlda)           |\
                          _CHIP_XBSR_SP2_MK(sp2mode)         |\
                          _CHIP_XBSR_SP1_MK(sp1mode)         |\
                          _CHIP_XBSR_PP_MK(ppmode)            \
           )
  #endif /*(CHIP_5509)*/

  #if (CHIP_5509A) /*(CHIP_5509A)*/
  
  #define _CHIP_XBSR_CFG(clkout, osc, hidl, bke, srstat, hld, hlda, cke, ckeen, srcom, sp2mode,sp1mode,ppmode)\
    _CHIP = (Uint16)( _CHIP_XBSR_CLKOUT_MK(clkout)           |\
                          _CHIP_XBSR_OSCDIS_MK(osc)          |\
                          _CHIP_XBSR_HIDL_MK(hidl)           |\
                          _CHIP_XBSR_BKE_MK(bke)             |\
                          _CHIP_XBSR_SRSTAT_MK(srstat)       |\
                          _CHIP_XBSR_HLD_MK(hld)             |\
                          _CHIP_XBSR_HLDA_MK(hlda)           |\
                          _CHIP_XBSR_CKE_MK(cke)             |\
                          _CHIP_XBSR_CKEEN_MK(ckeen)         |\
                          _CHIP_XBSR_SRCOM_MK(srcom)         |\
                          _CHIP_XBSR_SP2_MK(sp2mode)         |\
                          _CHIP_XBSR_SP1_MK(sp1mode)         |\
                          _CHIP_XBSR_PP_MK(ppmode)            \
           )

   #endif /*(CHIP_5509A)*/




  /******************************************************************************\
  * _CHIP_SROM - Secure ROM Register
  *
  * Fields:
  *   (RW) _CHIP_SROM
  *
  \******************************************************************************/
  #define _CHIP_SROM_ADDR       (0x7400u)
  #define _CHIP_SROM             PREG16(_CHIP_SROM_ADDR)
  #define _SROM                 _SROM

  #define _CHIP_SROM_GET\
     _PREG_GET(CHIP_ADDR(SROM))

  #define _CHIP_SROM_SET(Val)\
     _PREG_SET(CHIP_ADDR(SROM), Val)

  #define _CHIP_SROM_FGET(Field)\
    _PFIELD_GET(CHIP_ADDR(SROM),_CHIP_SROM_##Field)

  #define _CHIP_SROM_FSET(Field,Val)\
    _PFIELD_SET(CHIP_ADDR(SROM),_CHIP_SROM_##Field,Val)
 
#endif  // (CHIP_5509) || (CHIP_5509A) 

#if (CHIP_5502) || (CHIP_5501)
 
 /******************************************************************************\
  * _CHIP_CONFIG-System Configuration register 
  *
  * Fields:
  *   (R)  _CHIP_CONFIG_CACHEPRES
  *
  \******************************************************************************/
  #define _CHIP_CONFIG_ADDR       (0x07FDu)
  #define _CHIP_CONFIG          PREG16(_CHIP_CONFIG_ADDR)
  #define _CONFIG               _CONFIG

  #define _CHIP_CONFIG_GET\
     _PREG_GET(CHIP_ADDR(CONFIG))

  #define _CHIP_CONFIG_SET(Val)\
     _PREG_SET(CHIP_ADDR(CONFIG), Val)

  #define _CHIP_CONFIG_FGET(Field)\
   _PFIELD_GET(CHIP_ADDR(CONFIG),_CHIP_CONFIG_##Field)

  #define _CHIP_CONFIG_FSET(Field,Val)\
   _PFIELD_SET(CHIP_ADDR(CONFIG),_CHIP_CONFIG_##Field,Val)


  /*----------------------------------------------------------------------------*\
  * (R) _CHIP_CONFIG_CACHEPRES: ICACHE Preset
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_CONFIG_CACHEPRES_SHIFT         (0x0005u)
  #define _CHIP_CONFIG_CACHEPRES_MK(n)         (((Uint16)n & 0x001u) << _CHIP_CONFIG_CACHEPRES_SHIFT)
  #define _CHIP_CONFIG_CACHEPRES_MASK          (_CHIP_CONFIG_CACHEPRES_MK(0x1))
  #define _CHIP_CONFIG_CACHEPRES_CLR           (~(_CHIP_CONFIG_CACHEPRES_MASK))



  /******************************************************************************\
  * _CHIP_XBSR - External Bus Select Register
  *
  * Fields:
  *   (RW) _CHIP_XBSR_SP2MODE    Serial Port 2 Mode (For 5502 device only)
  *   (RW) _CHIP_XBSR_PPMODE     Parallel Port Mode  
  *
  \******************************************************************************/
  #define _CHIP_XBSR_ADDR       (0x6C00u)
  #define _CHIP_XBSR             PREG16(_CHIP_XBSR_ADDR)
  #define _XBSR                 _CHIP_XBSR

  #define _CHIP_XBSR_GET\
     _PREG_GET(_CHIP_XBSR_ADDR)

  #define _CHIP_XBSR_SET(Val)\
     _PREG_SET(_CHIP_XBSR_ADDR, Val)

  #define _CHIP_XBSR_FGET(Field)\
   _PFIELD_GET(_CHIP_XBSR_ADDR,_CHIP_XBSR_##Field)

  #define _CHIP_XBSR_FSET(Field,Val)\
   _PFIELD_SET(_CHIP_XBSR_ADDR,_CHIP_XBSR_##Field,Val)


  /*----------------------------------------------------------------------------*\
  * (R) _CHIP_XBSR_PPMODE
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBSR_PPMODE_SHIFT      (0x0000u)
  #define _CHIP_XBSR_PPMODE_MK(n)      (((Uint16)n & 0x001u) << _CHIP_XBSR_PPMODE_SHIFT)
  #define _CHIP_XBSR_PPMODE_MASK       (_CHIP_XBSR_PPMODE_MK(0x1))
  #define _CHIP_XBSR_PPMODE_CLR        (~(_CHIP_XBSR_PPMODE_MASK))


  #if (CHIP_5502)

  /*----------------------------------------------------------------------------*\
  * (R) _CHIP_XBSR_PPMODE
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBSR_SP2MODE_SHIFT      (0x0002u)
  #define _CHIP_XBSR_SP2MODE_MK(n)      (((Uint16)n & 0x001u) << _CHIP_XBSR_SP2MODE_SHIFT)
  #define _CHIP_XBSR_SP2MODE_MASK       (_CHIP_XBSR_SP2MODE_MK(0x1))
  #define _CHIP_XBSR_SP2MODE_CLR        (~(_CHIP_XBSR_SP2MODE_MASK))

  #endif // CHIP_5502
	
  /******************************************************************************\
  * _CHIP_XBCR - External Bus Control Register
  *
  * Fields:
  *   (RW) _CHIP_XBCR_PAH        
  *   (RW) _CHIP_XBCR_PDH 
  *   (RW) _CHIP_XBCR_PCH        
  *   (RW) _CHIP_XBCR_HDH        
  *   (RW) _CHIP_XBCR_HCH        
  *   (RW) _CHIP_XBCR_WDT
  *   (RW) _CHIP_XBCR_TEST
  *   (RW) _CHIP_XBCR_EMU
  \******************************************************************************/
  #define _CHIP_XBCR_ADDR       (0x8800u)
  #define _CHIP_XBCR             PREG16(_CHIP_XBCR_ADDR)
  #define _XBCR                 _CHIP_XBCR

  #define _CHIP_XBCR_GET\
     _PREG_GET(_CHIP_XBCR_ADDR)

  #define _CHIP_XBCR_SET(Val)\
     _PREG_SET(_CHIP_XBCR_ADDR, Val)

  #define _CHIP_XBCR_FGET(Field)\
   _PFIELD_GET(_CHIP_XBCR_ADDR,_CHIP_XBCR_##Field)

  #define _CHIP_XBCR_FSET(Field,Val)\
   _PFIELD_SET(_CHIP_XBCR_ADDR,_CHIP_XBCR_##Field,Val)

  /*----------------------------------------------------------------------------*\
  * (R) _CHIP_XBCR_PAH
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBCR_PAH_SHIFT      (0x0000u)
  #define _CHIP_XBCR_PAH_MK(n)      (((Uint16)n & 0x001u) << _CHIP_XBCR_PAH_SHIFT)
  #define _CHIP_XBCR_PAH_MASK       (_CHIP_XBCR_PAH_MK(0x1))
  #define _CHIP_XBCR_PAH_CLR        (~(_CHIP_XBCR_PAH_MASK))

  /*----------------------------------------------------------------------------*\
  * (R) _CHIP_XBCR_PDH
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBCR_PDH_SHIFT      (0x0001u)
  #define _CHIP_XBCR_PDH_MK(n)      (((Uint16)n & 0x001u) << _CHIP_XBCR_PDH_SHIFT)
  #define _CHIP_XBCR_PDH_MASK       (_CHIP_XBCR_PDH_MK(0x1))
  #define _CHIP_XBCR_PDH_CLR        (~(_CHIP_XBCR_PDH_MASK))

  /*----------------------------------------------------------------------------*\
  * (R) _CHIP_XBCR_PCH
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBCR_PCH_SHIFT      (0x0002u)
  #define _CHIP_XBCR_PCH_MK(n)      (((Uint16)n & 0x001u) << _CHIP_XBCR_PCH_SHIFT)
  #define _CHIP_XBCR_PCH_MASK       (_CHIP_XBCR_PCH_MK(0x1))
  #define _CHIP_XBCR_PCH_CLR        (~(_CHIP_XBCR_PCH_MASK))

  /*----------------------------------------------------------------------------*\
  * (R) _CHIP_XBCR_HDH
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBCR_HDH_SHIFT      (0x0003u)
  #define _CHIP_XBCR_HDH_MK(n)      (((Uint16)n & 0x001u) << _CHIP_XBCR_HDH_SHIFT)
  #define _CHIP_XBCR_HDH_MASK       (_CHIP_XBCR_HDH_MK(0x1))
  #define _CHIP_XBCR_HDH_CLR        (~(_CHIP_XBCR_HDH_MASK))

  /*----------------------------------------------------------------------------*\
  * (R) _CHIP_XBCR_HCH
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBCR_HCH_SHIFT      (0x0004u)
  #define _CHIP_XBCR_HCH_MK(n)      (((Uint16)n & 0x001u) << _CHIP_XBCR_HCH_SHIFT)
  #define _CHIP_XBCR_HCH_MASK       (_CHIP_XBCR_HCH_MK(0x1))
  #define _CHIP_XBCR_HCH_CLR        (~(_CHIP_XBCR_HCH_MASK))

  /*----------------------------------------------------------------------------*\
  * (R) _CHIP_XBCR_WDT
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBCR_WDT_SHIFT      (0x0005u)
  #define _CHIP_XBCR_WDT_MK(n)      (((Uint16)n & 0x001u) << _CHIP_XBCR_WDT_SHIFT)
  #define _CHIP_XBCR_WDT_MASK       (_CHIP_XBCR_WDT_MK(0x1))
  #define _CHIP_XBCR_WDT_CLR        (~(_CHIP_XBCR_WDT_MASK))

  /*----------------------------------------------------------------------------*\
  * (R) _CHIP_XBCR_TEST
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBCR_TEST_SHIFT      (0x0006u)
  #define _CHIP_XBCR_TEST_MK(n)      (((Uint16)n & 0x001u) << _CHIP_XBCR_TEST_SHIFT)
  #define _CHIP_XBCR_TEST_MASK       (_CHIP_XBCR_TEST_MK(0x1))
  #define _CHIP_XBCR_TEST_CLR        (~(_CHIP_XBCR_TEST_MASK))

  /*----------------------------------------------------------------------------*\
  * (R) _CHIP_XBCR_EMU
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_XBCR_EMU_SHIFT      (0x0007u)
  #define _CHIP_XBCR_EMU_MK(n)      (((Uint16)n & 0x001u) << _CHIP_XBCR_EMU_SHIFT)
  #define _CHIP_XBCR_EMU_MASK       (_CHIP_XBCR_EMU_MK(0x1))
  #define _CHIP_XBCR_EMU_CLR        (~(_CHIP_XBCR_EMU_MASK))


  /******************************************************************************\
  * _CHIP_TSSR - Timer signal selection register 
  *
  * Fields:
  *   (RW) _CHIP_TSSR_NMISEL        
  *   (RW) _CHIP_TSSR_IWCON
  *   (RW) _CHIP_TSSR_TIM0MODE      
  *   (RW) _CHIP_TSSR_TIM1MODE        
  *   (RW) _CHIP_TSSR_TIM2MODE        
  \******************************************************************************/
  #define _CHIP_TSSR_ADDR       (0x8000u)
  #define _CHIP_TSSR             PREG16(_CHIP_TSSR_ADDR)
  #define _TSSR                 _CHIP_TSSR

  #define _CHIP_TSSR_GET\
     _PREG_GET(_CHIP_TSSR_ADDR)

  #define _CHIP_TSSR_SET(Val)\
     _PREG_SET(_CHIP_TSSR_ADDR, Val)

  #define _CHIP_TSSR_FGET(Field)\
   _PFIELD_GET(_CHIP_TSSR_ADDR,_CHIP_TSSR_##Field)

  #define _CHIP_TSSR_FSET(Field,Val)\
   _PFIELD_SET(_CHIP_TSSR_ADDR,_CHIP_TSSR_##Field,Val)

  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_TSSR_NMISEL
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_TSSR_NMISEL_SHIFT      (0x0000u)
  #define _CHIP_TSSR_NMISEL_MK(n)      (((Uint16)n & 0x001u) << _CHIP_TSSR_NMISEL_SHIFT)
  #define _CHIP_TSSR_NMISEL_MASK       (_CHIP_TSSR_NMISEL_MK(0x1))
  #define _CHIP_TSSR_NMISEL_CLR        (~(_CHIP_TSSR_NMISEL_MASK))

  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_TSSR_IWCON
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_TSSR_IWCON_SHIFT      (0x0001u)
  #define _CHIP_TSSR_IWCON_MK(n)      (((Uint16)n & 0x003u) << _CHIP_TSSR_IWCON_SHIFT)
  #define _CHIP_TSSR_IWCON_MASK       (_CHIP_TSSR_IWCON_MK(0x3))
  #define _CHIP_TSSR_IWCON_CLR        (~(_CHIP_TSSR_IWCON_MASK))

  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_TSSR_TIM0MODE
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_TSSR_TIM0MODE_SHIFT      (0x0003u)
  #define _CHIP_TSSR_TIM0MODE_MK(n)      (((Uint16)n & 0x001u) << _CHIP_TSSR_TIM0MODE_SHIFT)
  #define _CHIP_TSSR_TIM0MODE_MASK       (_CHIP_TSSR_TIM0MODE_MK(0x1))
  #define _CHIP_TSSR_TIM0MODE_CLR        (~(_CHIP_TSSR_TIM0MODE_MASK))

  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_TSSR_TIM1MODE
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_TSSR_TIM1MODE_SHIFT      (0x0004u)
  #define _CHIP_TSSR_TIM1MODE_MK(n)      (((Uint16)n & 0x001u) << _CHIP_TSSR_TIM1MODE_SHIFT)
  #define _CHIP_TSSR_TIM1MODE_MASK       (_CHIP_TSSR_TIM1MODE_MK(0x1))
  #define _CHIP_TSSR_TIM1MODE_CLR        (~(_CHIP_TSSR_TIM1MODE_MASK))

  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_TSSR_TIM2MODE
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_TSSR_TIM2MODE_SHIFT      (0x0005u)
  #define _CHIP_TSSR_TIM2MODE_MK(n)      (((Uint16)n & 0x001u) << _CHIP_TSSR_TIM2MODE_SHIFT)
  #define _CHIP_TSSR_TIM2MODE_MASK       (_CHIP_TSSR_TIM2MODE_MK(0x1))
  #define _CHIP_TSSR_TIM2MODE_CLR        (~(_CHIP_TSSR_TIM2MODE_MASK))

  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_TSSR_IWCON
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_TSSR_IWCON_SHIFT      (0x0001u)
  #define _CHIP_TSSR_IWCON_MK(n)      (((Uint16)n & 0x003u) << _CHIP_TSSR_IWCON_SHIFT)
  #define _CHIP_TSSR_IWCON_MASK       (_CHIP_TSSR_IWCON_MK(0x3))
  #define _CHIP_TSSR_IWCON_CLR        (~(_CHIP_TSSR_IWCON_MASK))


  /******************************************************************************\
  * _CHIP_CLKOSR - CLKOUT Selection Register
  *
  * Fields:
  *   (RW) _CHIP_CLKOSR_CKODIS        
  *   (RW) _CHIP_CLKOSR_CKOSEL
  \******************************************************************************/
  #define _CHIP_CLKOSR_ADDR       (0x8400u)
  #define _CHIP_CLKOSR             PREG16(_CHIP_CLKOSR_ADDR)
  #define _CLKOSR                 _CHIP_CLKOSR

  #define _CHIP_CLKOSR_GET\
     _PREG_GET(_CHIP_CLKOSR_ADDR)

  #define _CHIP_CLKOSR_SET(Val)\
     _PREG_SET(_CHIP_CLKOSR_ADDR, Val)

  #define _CHIP_CLKOSR_FGET(Field)\
   _PFIELD_GET(_CHIP_CLKOSR_ADDR,_CHIP_CLKOSR_##Field)

  #define _CHIP_CLKOSR_FSET(Field,Val)\
   _PFIELD_SET(_CHIP_CLKOSR_ADDR,_CHIP_CLKOSR_##Field,Val)

  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_CLKOSR_CKODIS
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_CLKOSR_CKODIS_SHIFT      (0x0000u)
  #define _CHIP_CLKOSR_CKODIS_MK(n)      (((Uint16)n & 0x001u) << _CHIP_CLKOSR_CKODIS_SHIFT)
  #define _CHIP_CLKOSR_CKODIS_MASK       (_CHIP_CLKOSR_CKODIS_MK(0x1))
  #define _CHIP_CLKOSR_CKODIS_CLR        (~(_CHIP_CLKOSR_CKODIS_MASK))

  /*----------------------------------------------------------------------------*\
  * (RW) _CHIP_CLKOSR_CKOSEL
  \*----------------------------------------------------------------------------*/ 
  #define _CHIP_CLKOSR_CKOSEL_SHIFT      (0x0000u)
  #define _CHIP_CLKOSR_CKOSEL_MK(n)      (((Uint16)n & 0x001u) << _CHIP_CLKOSR_CKOSEL_SHIFT)
  #define _CHIP_CLKOSR_CKOSEL_MASK       (_CHIP_CLKOSR_CKOSEL_MK(0x1))
  #define _CHIP_CLKOSR_CKOSEL_CLR        (~(_CHIP_CLKOSR_CKOSEL_MASK))


#endif // CHIP_5502 || CHIP_5501
#endif /* _CHIPHAL_H_ */
/******************************************************************************\
* End of CHIPhal.h
\******************************************************************************/

