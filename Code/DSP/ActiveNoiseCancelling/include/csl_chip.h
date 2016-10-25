/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... CHIP
* FILENAME...... csl_chip.h
* DATE CREATED.. Thu 08/19/1999 
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... 
* PREREQUISITS.. csl_stdinc.h, csl_stdinchal.h, csl_chiphal.h
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:        08/19/1999 Created
*   MODIFIED:       11/23/1999 Modified for TMS320C54xx
*                   7/27/2000  Modified for TMS320C55xx
*                   04/12/2001 updated header comments
*                   08/21/2003 Modified CLKOFF bit ENABLE/DISABLE macros
*   LAST MODIFIED:  08/19/2004 Adding symbolic constants and make macros for SYSR,
*                              SROM,XBCR,TSSR and CLKOSR registers
*   
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the CHIP module)
*
*
*
\******************************************************************************/
#ifndef _CHIP_H_
#define _CHIP_H_
 
#include <csl_std.h>
#include <csl_chiphal.h>
 
#if (_CHIP_SUPPORT)
/****************************************\
* CHIP scope and inline control macros
\****************************************/

#ifdef __cplusplus
#define CSLAPI extern "C"  
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _DMA_MOD_
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
/****************************************\
* CHIP global macro declarations
\****************************************/
#define CHIP_ENDIAN_LITTLE 1

// Make Macros for IER0

#define CHIP_IER0_DMAC5_ENABLE  (0x1u)
#define CHIP_IER0_DMAC5_DISABLE (0x0u)
#define CHIP_IER0_DMAC5_DEFAULT (CHIP_IER0_DMAC5_DISABLE)

#define CHIP_IER0_DMAC4_ENABLE  (0x1u)
#define CHIP_IER0_DMAC4_DISABLE (0x0u)
#define CHIP_IER0_DMAC4_DEFAULT (CHIP_IER0_DMAC4_DISABLE)

#define CHIP_IER0_XINT2_ENABLE  (0x1u)
#define CHIP_IER0_XINT2_DISABLE (0x0u)
#define CHIP_IER0_XINT2_DEFAULT (CHIP_IER0_XINT2_DISABLE)

#define CHIP_IER0_RINT2_ENABLE  (0x1u)
#define CHIP_IER0_RINT2_DISABLE (0x0u)
#define CHIP_IER0_RINT2_DEFAULT (CHIP_IER0_RINT2_DISABLE)

#define CHIP_IER0_INT3_ENABLE  (0x1u)
#define CHIP_IER0_INT3_DISABLE (0x0u)
#define CHIP_IER0_INT3_DEFAULT (CHIP_IER0_INT3_DISABLE)

#define CHIP_IER0_DSPINT_ENABLE  (0x1u)
#define CHIP_IER0_DSPINT_DISABLE (0x0u)
#define CHIP_IER0_DSPINT_DEFAULT (CHIP_IER0_DSPINT_DISABLE)

#define CHIP_IER0_DMAC1_ENABLE  (0x1u)
#define CHIP_IER0_DMAC1_DISABLE (0x0u)
#define CHIP_IER0_DMAC1_DEFAULT (CHIP_IER0_DMAC1_DISABLE)

#define CHIP_IER0_XINT1_ENABLE  (0x1u)
#define CHIP_IER0_XINT1_DISABLE (0x0u)
#define CHIP_IER0_XINT1_DEFAULT (CHIP_IER0_XINT1_DISABLE)

#define CHIP_IER0_RINT1_ENABLE  (0x1u)
#define CHIP_IER0_RINT1_DISABLE (0x0u)
#define CHIP_IER0_RINT1_DEFAULT (CHIP_IER0_RINT1_DISABLE)

#define CHIP_IER0_RINT0_ENABLE  (0x1u)
#define CHIP_IER0_RINT0_DISABLE (0x0u)
#define CHIP_IER0_RINT0_DEFAULT (CHIP_IER0_RINT0_DISABLE)

#define CHIP_IER0_TINT0_ENABLE  (0x1u)
#define CHIP_IER0_TINT0_DISABLE (0x0u)
#define CHIP_IER0_TINT0_DEFAULT (CHIP_IER0_TINT0_DISABLE)

#define CHIP_IER0_INT2_ENABLE  (0x1u)
#define CHIP_IER0_INT2_DISABLE (0x0u)
#define CHIP_IER0_INT2_DEFAULT (CHIP_IER0_INT2_DISABLE)

#define CHIP_IER0_INT0_ENABLE  (0x1u)
#define CHIP_IER0_INT0_DISABLE (0x0u)
#define CHIP_IER0_INT0_DEFAULT (CHIP_IER0_INT0_DISABLE)

#define CHIP_IER0_RMK(dmac5, dmac4, xint2, rint2, int3, dspint, dmac1,\
                       xint1, rint1, rint0, tint0, int2, int0)(\
  (Uint16) ( CHIP_FMK(IER0,DMAC5,dmac5)   |\
             CHIP_FMK(IER0,DMAC4,dmac4)   |\
             CHIP_FMK(IER0,XINT2,xint2)   |\
             CHIP_FMK(IER0,RINT2,rint2)   |\
             CHIP_FMK(IER0,INT3,int3)     |\
             CHIP_FMK(IER0,DSPINT,dspint) |\
             CHIP_FMK(IER0,DMAC1,dmac1)   |\
             CHIP_FMK(IER0,XINT1,xint1)   |\
             CHIP_FMK(IER0,RINT1,rint1)   |\
             CHIP_FMK(IER0,RINT0,rint0)   |\
             CHIP_FMK(IER0,TINT0,tint0)   |\
             CHIP_FMK(IER0,INT2,int2)     |\
             CHIP_FMK(IER0,INT0,int0)     )\
 )


#define CHIP_IER0_RMKS(dmac5_s, dmac4_s, xint2_s, rint2_s, int3_s, dspint_s, dmac1_s,\
                       xint1_s, rint1_s, rint0_s, tint0_s, int2_s, int0_s)(\
  (Uint16) ( CHIP_FMKS(IER0,DMAC5,dmac5_s)   |\
             CHIP_FMKS(IER0,DMAC4,dmac4_s)   |\
             CHIP_FMKS(IER0,XINT2,xint2_s)   |\
             CHIP_FMKS(IER0,RINT2,rint2_s)   |\
             CHIP_FMKS(IER0,INT3,int3_s)     |\
             CHIP_FMKS(IER0,DSPINT,dspint_s) |\
             CHIP_FMKS(IER0,DMAC1,dmac1_s)   |\
             CHIP_FMKS(IER0,XINT1,xint1_s)   |\
             CHIP_FMKS(IER0,RINT1,rint1_s)   |\
             CHIP_FMKS(IER0,RINT0,rint0_s)   |\
             CHIP_FMKS(IER0,TINT0,tint0_s)   |\
             CHIP_FMKS(IER0,INT2,int2_s)     |\
             CHIP_FMKS(IER0,INT0,int0_s)     )\
 )

// Make Macros For IER1

#define CHIP_IER1_INT5_ENABLE   (0x1u)
#define CHIP_IER1_INT5_DISABLE  (0x0u)
#define CHIP_IER1_INT5_DEFAULT  (CHIP_IER1_INT5_DISABLE)

#define CHIP_IER1_TINT1_ENABLE   (0x1u)
#define CHIP_IER1_TINT1_DISABLE  (0x0u)
#define CHIP_IER1_TINT1_DEFAULT  (CHIP_IER1_TINT1_DISABLE)

#define CHIP_IER1_DMAC3_ENABLE   (0x1u)
#define CHIP_IER1_DMAC3_DISABLE  (0x0u)
#define CHIP_IER1_DMAC3_DEFAULT  (CHIP_IER1_DMAC3_DISABLE)

#define CHIP_IER1_DMAC2_ENABLE   (0x1u)
#define CHIP_IER1_DMAC2_DISABLE  (0x0u)
#define CHIP_IER1_DMAC2_DEFAULT  (CHIP_IER1_DMAC2_DISABLE)

#define CHIP_IER1_INT4_ENABLE   (0x1u)
#define CHIP_IER1_INT4_DISABLE  (0x0u)
#define CHIP_IER1_INT4_DEFAULT  (CHIP_IER1_INT4_DISABLE)

#define CHIP_IER1_DMAC0_ENABLE   (0x1u)
#define CHIP_IER1_DMAC0_DISABLE  (0x0u)
#define CHIP_IER1_DMAC0_DEFAULT  (CHIP_IER1_DMAC0_DISABLE)

#define CHIP_IER1_XINT0_ENABLE   (0x1u)
#define CHIP_IER1_XINT0_DISABLE  (0x0u)
#define CHIP_IER1_XINT0_DEFAULT  (CHIP_IER1_XINT0_DISABLE)

#define CHIP_IER1_INT1_ENABLE   (0x1u)
#define CHIP_IER1_INT1_DISABLE  (0x0u)
#define CHIP_IER1_INT1_DEFAULT  (CHIP_IER1_INT1_DISABLE)


#define CHIP_IER1_RMK(int5, tint1, dmac3, dmac2, int4, dmac0, xint0, int1)(\
  (Uint16)( CHIP_FMK(IER1,INT5,int5)   |\
            CHIP_FMK(IER1,TINT1,tint1) |\
            CHIP_FMK(IER1,DMAC3,dmac3) |\
            CHIP_FMK(IER1,DMAC2,dmac2) |\
            CHIP_FMK(IER1,INT4,int4)   |\
            CHIP_FMK(IER1,DMAC0,dmac0) |\
            CHIP_FMK(IER1,XINT0,xint0) |\
            CHIP_FMK(IER1,INT1,int1)   )\
)

#define CHIP_IER1_RMKS(int5_s, tint1_s, dmac3_s, dmac2_s, int4_s, dmac0_s, xint0_s, int1_s)(\
  (Uint16)( CHIP_FMKS(IER1,INT5,int5_s)   |\
            CHIP_FMKS(IER1,TINT1,tint1_s) |\
            CHIP_FMKS(IER1,DMAC3,dmac3_s) |\
            CHIP_FMKS(IER1,DMAC2,dmac2_s) |\
            CHIP_FMKS(IER1,INT4,int4_s)   |\
            CHIP_FMKS(IER1,DMAC0,dmac0_s) |\
            CHIP_FMKS(IER1,XINT0,xint0_s) |\
            CHIP_FMKS(IER1,INT1,int1_s)   )\
)
// Make Macros for IFR0

#define CHIP_IFR0_DMAC5_ENABLE  (0x1u)
#define CHIP_IFR0_DMAC5_DISABLE (0x0u)
#define CHIP_IFR0_DMAC5_DEFAULT (CHIP_IFR0_DMAC5_DISABLE)

#define CHIP_IFR0_DMAC4_ENABLE  (0x1u)
#define CHIP_IFR0_DMAC4_DISABLE (0x0u)
#define CHIP_IFR0_DMAC4_DEFAULT (CHIP_IFR0_DMAC4_DISABLE)

#define CHIP_IFR0_XINT2_ENABLE  (0x1u)
#define CHIP_IFR0_XINT2_DISABLE (0x0u)
#define CHIP_IFR0_XINT2_DEFAULT (CHIP_IFR0_XINT2_DISABLE)

#define CHIP_IFR0_RINT2_ENABLE  (0x1u)
#define CHIP_IFR0_RINT2_DISABLE (0x0u)
#define CHIP_IFR0_RINT2_DEFAULT (CHIP_IFR0_RINT2_DISABLE)

#define CHIP_IFR0_INT3_ENABLE  (0x1u)
#define CHIP_IFR0_INT3_DISABLE (0x0u)
#define CHIP_IFR0_INT3_DEFAULT (CHIP_IFR0_INT3_DISABLE)

#define CHIP_IFR0_DSPINT_ENABLE  (0x1u)
#define CHIP_IFR0_DSPINT_DISABLE (0x0u)
#define CHIP_IFR0_DSPINT_DEFAULT (CHIP_IFR0_DSPINT_DISABLE)

#define CHIP_IFR0_DMAC1_ENABLE  (0x1u)
#define CHIP_IFR0_DMAC1_DISABLE (0x0u)
#define CHIP_IFR0_DMAC1_DEFAULT (CHIP_IFR0_DMAC1_DISABLE)

#define CHIP_IFR0_XINT1_ENABLE  (0x1u)
#define CHIP_IFR0_XINT1_DISABLE (0x0u)
#define CHIP_IFR0_XINT1_DEFAULT (CHIP_IFR0_XINT1_DISABLE)

#define CHIP_IFR0_RINT1_ENABLE  (0x1u)
#define CHIP_IFR0_RINT1_DISABLE (0x0u)
#define CHIP_IFR0_RINT1_DEFAULT (CHIP_IFR0_RINT1_DISABLE)

#define CHIP_IFR0_RINT0_ENABLE  (0x1u)
#define CHIP_IFR0_RINT0_DISABLE (0x0u)
#define CHIP_IFR0_RINT0_DEFAULT (CHIP_IFR0_RINT0_DISABLE)

#define CHIP_IFR0_TINT0_ENABLE  (0x1u)
#define CHIP_IFR0_TINT0_DISABLE (0x0u)
#define CHIP_IFR0_TINT0_DEFAULT (CHIP_IFR0_TINT0_DISABLE)

#define CHIP_IFR0_INT2_ENABLE  (0x1u)
#define CHIP_IFR0_INT2_DISABLE (0x0u)
#define CHIP_IFR0_INT2_DEFAULT (CHIP_IFR0_INT2_DISABLE)

#define CHIP_IFR0_INT0_ENABLE  (0x1u)
#define CHIP_IFR0_INT0_DISABLE (0x0u)
#define CHIP_IFR0_INT0_DEFAULT (CHIP_IFR0_INT0_DISABLE)

#define CHIP_IFR0_RMK(dmac5, dmac4, xint2, rint2, int3, dspint, dmac1,\
                       xint1, rint1, rint0, tint0, int2, int0)(\
  (Uint16) ( CHIP_FMK(IFR0,DMAC5,dmac5)   |\
             CHIP_FMK(IFR0,DMAC4,dmac4)   |\
             CHIP_FMK(IFR0,XINT2,xint2)   |\
             CHIP_FMK(IFR0,RINT2,rint2)   |\
             CHIP_FMK(IFR0,INT3,int3)     |\
             CHIP_FMK(IFR0,DSPINT,dspint) |\
             CHIP_FMK(IFR0,DMAC1,dmac1)   |\
             CHIP_FMK(IFR0,XINT1,xint1)   |\
             CHIP_FMK(IFR0,RINT1,rint1)   |\
             CHIP_FMK(IFR0,RINT0,rint0)   |\
             CHIP_FMK(IFR0,TINT0,tint0)   |\
             CHIP_FMK(IFR0,INT2,int2)     |\
             CHIP_FMK(IFR0,INT0,int0)     )\
 )


#define CHIP_IFR0_RMKS(dmac5_s, dmac4_s, xint2_s, rint2_s, int3_s, dspint_s, dmac1_s,\
                       xint1_s, rint1_s, rint0_s, tint0_s, int2_s, int0_s)(\
  (Uint16) ( CHIP_FMKS(IFR0,DMAC5,dmac5_s)   |\
             CHIP_FMKS(IFR0,DMAC4,dmac4_s)   |\
             CHIP_FMKS(IFR0,XINT2,xint2_s)   |\
             CHIP_FMKS(IFR0,RINT2,rint2_s)   |\
             CHIP_FMKS(IFR0,INT3,int3_s)     |\
             CHIP_FMKS(IFR0,DSPINT,dspint_s) |\
             CHIP_FMKS(IFR0,DMAC1,dmac1_s)   |\
             CHIP_FMKS(IFR0,XINT1,xint1_s)   |\
             CHIP_FMKS(IFR0,RINT1,rint1_s)   |\
             CHIP_FMKS(IFR0,RINT0,rint0_s)   |\
             CHIP_FMKS(IFR0,TINT0,tint0_s)   |\
             CHIP_FMKS(IFR0,INT2,int2_s)     |\
             CHIP_FMKS(IFR0,INT0,int0_s)     )\
 )

// Make Macros For IFR1

#define CHIP_IFR1_INT5_ENABLE   (0x1u)
#define CHIP_IFR1_INT5_DISABLE  (0x0u)
#define CHIP_IFR1_INT5_DEFAULT  (CHIP_IFR1_INT5_DISABLE)

#define CHIP_IFR1_TINT1_ENABLE   (0x1u)
#define CHIP_IFR1_TINT1_DISABLE  (0x0u)
#define CHIP_IFR1_TINT1_DEFAULT  (CHIP_IFR1_TINT1_DISABLE)

#define CHIP_IFR1_DMAC3_ENABLE   (0x1u)
#define CHIP_IFR1_DMAC3_DISABLE  (0x0u)
#define CHIP_IFR1_DMAC3_DEFAULT  (CHIP_IFR1_DMAC3_DISABLE)

#define CHIP_IFR1_DMAC2_ENABLE   (0x1u)
#define CHIP_IFR1_DMAC2_DISABLE  (0x0u)
#define CHIP_IFR1_DMAC2_DEFAULT  (CHIP_IFR1_DMAC2_DISABLE)

#define CHIP_IFR1_INT4_ENABLE   (0x1u)
#define CHIP_IFR1_INT4_DISABLE  (0x0u)
#define CHIP_IFR1_INT4_DEFAULT  (CHIP_IFR1_INT4_DISABLE)

#define CHIP_IFR1_DMAC0_ENABLE   (0x1u)
#define CHIP_IFR1_DMAC0_DISABLE  (0x0u)
#define CHIP_IFR1_DMAC0_DEFAULT  (CHIP_IFR1_DMAC0_DISABLE)

#define CHIP_IFR1_XINT0_ENABLE   (0x1u)
#define CHIP_IFR1_XINT0_DISABLE  (0x0u)
#define CHIP_IFR1_XINT0_DEFAULT  (CHIP_IFR1_XINT0_DISABLE)

#define CHIP_IFR1_INT1_ENABLE   (0x1u)
#define CHIP_IFR1_INT1_DISABLE  (0x0u)
#define CHIP_IFR1_INT1_DEFAULT  (CHIP_IFR1_INT1_DISABLE)


#define CHIP_IFR1_RMK(int5, tint1, dmac3, dmac2, int4, dmac0, xint0, int1)\
  (Uint16)( CHIP_FMK(IFR1,INT5,int5)   |\
            CHIP_FMK(IFR1,TINT1,tint1) |\
            CHIP_FMK(IFR1,DMAC3,dmac3) |\
            CHIP_FMK(IFR1,DMAC2,dmac2) |\
            CHIP_FMK(IFR1,INT4,int4)   |\
            CHIP_FMK(IFR1,DMAC0,dmac0) |\
            CHIP_FMK(IFR1,XINT0,xint0) |\
            CHIP_FMK(IFR1,INT1,int1)   \
)

#define CHIP_IFR1_RMKS(int5_s, tint1_s, dmac3_s, dmac2_s, int4_s, dmac0_s, xint0_s, int1_s)\
  (Uint16)( CHIP_FMKS(IFR1,INT5,int5_s)   |\
            CHIP_FMKS(IFR1,TINT1,tint1_s) |\
            CHIP_FMKS(IFR1,DMAC3,dmac3_s) |\
            CHIP_FMKS(IFR1,DMAC2,dmac2_s) |\
            CHIP_FMKS(IFR1,INT4,int4_s)   |\
            CHIP_FMKS(IFR1,DMAC0,dmac0_s) |\
            CHIP_FMKS(IFR1,XINT0,xint0_s) |\
            CHIP_FMKS(IFR1,INT1,int1_s)   \
)

// Make Macros for ST0

#define CHIP_ST0_55_ACOV2_ON      (0x1u)
#define CHIP_ST0_55_ACOV2_OFF     (0x0u)
#define CHIP_ST0_55_ACOV2_DEFAULT  CHIP_ST0_55_ACOV2_OFF

#define CHIP_ST0_55_ACOV3_ON      (0x1u)
#define CHIP_ST0_55_ACOV3_OFF     (0x0u)
#define CHIP_ST0_55_ACOV3_DEFAULT  CHIP_ST0_55_ACOV3_OFF

#define CHIP_ST0_55_TC1_ON        (0x1u)
#define CHIP_ST0_55_TC1_OFF       (0x0u)
#define CHIP_ST0_55_TC1_DEFAULT   CHIP_ST0_55_TC1_OFF

#define CHIP_ST0_55_TC2_ON        (0x1u)
#define CHIP_ST0_55_TC2_OFF       (0x0u)
#define CHIP_ST0_55_TC2_DEFAULT   CHIP_ST0_55_TC2_OFF

#define CHIP_ST0_55_CARRY_ON      (0x1u)
#define CHIP_ST0_55_CARRY_OFF     (0x0u)
#define CHIP_ST0_55_CARRY_DEFAULT  CHIP_ST0_55_CARRY_OFF

#define CHIP_ST0_55_ACOV0_ON      (0x1u)
#define CHIP_ST0_55_ACOV0_OFF     (0x0u)
#define CHIP_ST0_55_ACOV0_DEFAULT  CHIP_ST0_55_ACOV0_OFF

#define CHIP_ST0_55_ACOV1_ON      (0x1u)
#define CHIP_ST0_55_ACOV1_OFF     (0x0u)
#define CHIP_ST0_55_ACOV1_DEFAULT  CHIP_ST0_55_ACOV1_OFF

#define CHIP_ST0_55_DP_OF(x)      ((Uint16)(x))
#define CHIP_ST0_55_DP_DEFAULT    (0x0u)


#define CHIP_ST0_55_RMK(acov2, acov3, tc1, tc2, carry, acov0, acov1, dp)(\
(Uint16) ( CHIP_FMK(ST0_55,ACOV2,acov2)   |\
           CHIP_FMK(ST0_55,ACOV3,acov3)   |\
           CHIP_FMK(ST0_55,TC1,tc1)       |\
           CHIP_FMK(ST0_55,TC2,tc2)       |\
           CHIP_FMK(ST0_55,CARRY,carry)   |\
           CHIP_FMK(ST0_55,ACOV0,acov0)   |\
           CHIP_FMK(ST0_55,ACOV1,acov1)   |\
           CHIP_FMK(ST0_55,DP,dp)         )\
)

#define CHIP_ST0_55_RMKS(acov2_s, acov3_s, tc1_s, tc2_s, carry_s, acov0_s, acov1_s, dp_s)(\
(Uint16) ( CHIP_FMK(ST0_55,ACOV2,acov2_s)   |\
           CHIP_FMK(ST0_55,ACOV3,acov3_s)   |\
           CHIP_FMK(ST0_55,TC1,tc1_s)       |\
           CHIP_FMK(ST0_55,TC2,tc2_s)       |\
           CHIP_FMK(ST0_55,CARRY,carry_s)   |\
           CHIP_FMK(ST0_55,ACOV0,acov0_s)   |\
           CHIP_FMK(ST0_55,ACOV1,acov1_s)   |\
           CHIP_FMK(ST0_55,DP,dp_s) )       \
)


// Make Macros for ST1

#define CHIP_ST1_55_BRAF_ON       (0x1u)
#define CHIP_ST1_55_BRAF_OFF      (0x0u)
#define CHIP_ST1_55_BRAF_DEFAULT  CHIP_ST1_55_BRAF_OFF

#define CHIP_ST1_55_CPL_ON        (0x1u)
#define CHIP_ST1_55_CPL_OFF       (0x0u)
#define CHIP_ST1_55_CPL_DEFAULT   CHIP_ST1_55_CPL_OFF

#define CHIP_ST1_55_XF_ON         (0x1u)
#define CHIP_ST1_55_XF_OFF        (0x0u)
#define CHIP_ST1_55_XF_DEFAULT    CHIP_ST1_55_XF_OFF

#define CHIP_ST1_55_HM_ON         (0x1u)
#define CHIP_ST1_55_HM_OFF        (0x0u)
#define CHIP_ST1_55_HM_DEFAULT    CHIP_ST1_55_HM_OFF


#define CHIP_ST1_55_INTM_ON       (0x1u)
#define CHIP_ST1_55_INTM_OFF      (0x0u)
#define CHIP_ST1_55_INTM_DEFAULT  CHIP_ST1_55_INTM_OFF

#define CHIP_ST1_55_M40_ON        (0x1u)
#define CHIP_ST1_55_M40_OFF       (0x0u)
#define CHIP_ST1_55_M40_DEFAULT   CHIP_ST1_55_M40_OFF

#define CHIP_ST1_55_SATD_ON       (0x1u)
#define CHIP_ST1_55_SATD_OFF      (0x0u)
#define CHIP_ST1_55_SATD_DEFAULT  CHIP_ST1_55_SATD_OFF

#define CHIP_ST1_55_SXMD_ON       (0x1u)
#define CHIP_ST1_55_SXMD_OFF      (0x0u)
#define CHIP_ST1_55_SXMD_DEFAULT  CHIP_ST1_55_SXMD_OFF

#define CHIP_ST1_55_C16_ON        (0x1u)
#define CHIP_ST1_55_C16_OFF       (0x0u)
#define CHIP_ST1_55_C16_DEFAULT   CHIP_ST1_55_C16_OFF

#define CHIP_ST1_55_FRCT_ON        (0x1u)
#define CHIP_ST1_55_FRCT_OFF       (0x0u)
#define CHIP_ST1_55_FRCT_DEFAULT   CHIP_ST1_55_FRCT_OFF

#define CHIP_ST1_55_C54CM_ON        (0x1u)
#define CHIP_ST1_55_C54CM_OFF       (0x0u)
#define CHIP_ST1_55_C54CM_DEFAULT   CHIP_ST1_55_C54CM_OFF

#define CHIP_ST1_55_ASM_OF(x)       ((Uint16)(x))
#define CHIP_ST1_55_ASM_DEFAULT     (0x0u)


#define CHIP_ST1_55_RMK(braf, cpl, xf, hm, intm, m40, satd, sxmd, c16, frct,\
                         c54cm, asm)(\
(Uint16) (CHIP_FMK(ST1_55,BRAF,braf)   |\
          CHIP_FMK(ST1_55,CPL,cpl)     |\
          CHIP_FMK(ST1_55,XF,xf)       |\
          CHIP_FMK(ST1_55,HM,hm)       |\
          CHIP_FMK(ST1_55,INTM,intm)   |\
          CHIP_FMK(ST1_55,M40,m40)     |\
          CHIP_FMK(ST1_55,SATD,satd)   |\
          CHIP_FMK(ST1_55,SXMD,sxmd)   |\
          CHIP_FMK(ST1_55,C16,c16)     |\
          CHIP_FMK(ST1_55,FRCT,frct)   |\
          CHIP_FMK(ST1_55,C54CM,c54cm) |\
          CHIP_FMK(ST1_55,ASM,asm) )    \
)

#define CHIP_ST1_55_RMKS(braf_s, cpl_s, xf_s, hm_s, intm_s, m40_s, satd_s, sxmd_s, c16_s, frct_s,\
                         c54cm_s, asm_s)(\
(Uint16) (CHIP_FMK(ST1_55,BRAF,braf_s)   |\
          CHIP_FMK(ST1_55,CPL,cpl_s)     |\
          CHIP_FMK(ST1_55,XF,xf_s)       |\
          CHIP_FMK(ST1_55,HM,hm_s)       |\
          CHIP_FMK(ST1_55,INTM,intm_s)   |\
          CHIP_FMK(ST1_55,M40,m40_s)     |\
          CHIP_FMK(ST1_55,SATD,satd_s)   |\
          CHIP_FMK(ST1_55,SXMD,sxmd_s)   |\
          CHIP_FMK(ST1_55,C16,c16_s)     |\
          CHIP_FMK(ST1_55,FRCT,frct_s)   |\
          CHIP_FMK(ST1_55,C54CM,c54cm_s) |\
          CHIP_FMK(ST1_55,ASM,asm_s) )   \
)

// Make Macros for ST2

#define CHIP_ST2_55_ARMS_ON         (0x1u)
#define CHIP_ST2_55_ARMS_OFF        (0x0u)
#define CHIP_ST2_55_ARMS_DEFAULT    CHIP_ST2_55_ARMS_OFF

#define CHIP_ST2_55_DBGM_ON         (0x1u)
#define CHIP_ST2_55_DBGM_OFF        (0x0u)
#define CHIP_ST2_55_DBGM_DEFAULT    CHIP_ST2_55_DBGM_OFF

#define CHIP_ST2_55_EALLOW_ON       (0x1u)
#define CHIP_ST2_55_EALLOW_OFF      (0x0u)
#define CHIP_ST2_55_EALLOW_DEFAULT  CHIP_ST2_55_EALLOW_OFF

#define CHIP_ST2_55_RDM_ON          (0x1u)
#define CHIP_ST2_55_RDM_OFF         (0x0u)
#define CHIP_ST2_55_RDM_DEFAULT     CHIP_ST2_55_RDM_OFF

#define CHIP_ST2_55_CDPLC_ON        (0x1u)
#define CHIP_ST2_55_CDPLC_OFF       (0x0u)
#define CHIP_ST2_55_CDPLC_DEFAULT   CHIP_ST2_55_CDPLC_OFF

#define CHIP_ST2_55_AR7LC_ON        (0x1u)
#define CHIP_ST2_55_AR7LC_OFF       (0x0u)
#define CHIP_ST2_55_AR7LC_DEFAULT   CHIP_ST2_55_AR7LC_OFF

#define CHIP_ST2_55_AR6LC_ON        (0x1u)
#define CHIP_ST2_55_AR6LC_OFF       (0x0u)
#define CHIP_ST2_55_AR6LC_DEFAULT   CHIP_ST2_55_AR6LC_OFF

#define CHIP_ST2_55_AR5LC_ON        (0x1u)
#define CHIP_ST2_55_AR5LC_OFF       (0x0u)
#define CHIP_ST2_55_AR5LC_DEFAULT   CHIP_ST2_55_AR5LC_OFF

#define CHIP_ST2_55_AR4LC_ON        (0x1u)
#define CHIP_ST2_55_AR4LC_OFF       (0x0u)
#define CHIP_ST2_55_AR4LC_DEFAULT   CHIP_ST2_55_AR4LC_OFF

#define CHIP_ST2_55_AR3LC_ON        (0x1u)
#define CHIP_ST2_55_AR3LC_OFF       (0x0u)
#define CHIP_ST2_55_AR3LC_DEFAULT   CHIP_ST2_55_AR3LC_OFF

#define CHIP_ST2_55_AR2LC_ON        (0x1u)
#define CHIP_ST2_55_AR2LC_OFF       (0x0u)
#define CHIP_ST2_55_AR2LC_DEFAULT   CHIP_ST2_55_AR2LC_OFF

#define CHIP_ST2_55_AR1LC_ON        (0x1u)
#define CHIP_ST2_55_AR1LC_OFF       (0x0u)
#define CHIP_ST2_55_AR1LC_DEFAULT   CHIP_ST2_55_AR1LC_OFF

#define CHIP_ST2_55_AR0LC_ON        (0x1u)
#define CHIP_ST2_55_AR0LC_OFF       (0x0u)
#define CHIP_ST2_55_AR0LC_DEFAULT   CHIP_ST2_55_AR0LC_OFF

#define CHIP_ST2_55_RMK(arms, dbgm, eallow, rdm, cdplc, ar7lc, ar6lc, ar5lc,\
                         ar4lc, ar3lc,ar2lc,ar1lc,ar0lc)(\
(Uint16) ( CHIP_FMK(ST2_55,ARMS,arms)     |\
           CHIP_FMK(ST2_55,DBGM,dbgm)     |\
           CHIP_FMK(ST2_55,EALLOW,eallow) |\
           CHIP_FMK(ST2_55,RDM,rdm)       |\
           CHIP_FMK(ST2_55,CDPLC,cdplc)   |\
           CHIP_FMK(ST2_55,AR7LC,ar7lc)   |\
           CHIP_FMK(ST2_55,AR6LC,ar6lc)   |\
           CHIP_FMK(ST2_55,AR5LC,ar5lc)   |\
           CHIP_FMK(ST2_55,AR4LC,ar4lc)   |\
           CHIP_FMK(ST2_55,AR3LC,ar3lc)   |\
           CHIP_FMK(ST2_55,AR2LC,ar2lc)   |\
           CHIP_FMK(ST2_55,AR1LC,ar1lc)   |\
           CHIP_FMK(ST2_55,AR0LC,ar0lc)   )\
)

#define CHIP_ST2_55_RMKS(arms_s, dbgm_s, eallow_s, rdm_s, cdplc_s,\
                          ar7lc_s, ar6lc_s, ar5lc_s, ar4lc_s, ar3lc_s,\
                          ar2lc_s,ar1lc_s,ar0lc_s)(\
(Uint16) ( CHIP_FMKS(ST2_55,ARMS,arms_s)     |\
           CHIP_FMKS(ST2_55,DBGM,dbgm_s)     |\
           CHIP_FMKS(ST2_55,EALLOW,eallow_s) |\
           CHIP_FMKS(ST2_55,RDM,rdm_s)       |\
           CHIP_FMKS(ST2_55,CDPLC,cdplc_s)   |\
           CHIP_FMKS(ST2_55,AR7LC,ar7lc_s)   |\
           CHIP_FMKS(ST2_55,AR6LC,ar6lc_s)   |\
           CHIP_FMKS(ST2_55,AR5LC,ar5lc_s)   |\
           CHIP_FMKS(ST2_55,AR4LC,ar4lc_s)   |\
           CHIP_FMKS(ST2_55,AR3LC,ar3lc_s)   |\
           CHIP_FMKS(ST2_55,AR2LC,ar2lc_s)   |\
           CHIP_FMKS(ST2_55,AR1LC,ar1lc_s)   |\
           CHIP_FMKS(ST2_55,AR0LC,ar0lc_s)   )\
)

// Make Macros for ST3

#define CHIP_ST3_55_CAFRZ_ENABLE    (0x1u)
#define CHIP_ST3_55_CAFRZ_DISABLE   (0x0u)
#define CHIP_ST3_55_CAFRZ_DEFAULT   CHIP_ST3_55_CAFRZ_DISABLE

#define CHIP_ST3_55_CAEN_ON         (0x1u)
#define CHIP_ST3_55_CAEN_OFF        (0x0u)
#define CHIP_ST3_55_CAEN_DEFAULT    CHIP_ST3_55_CAEN_OFF

#define CHIP_ST3_55_CACLR_ENABLE    (0x1u)
#define CHIP_ST3_55_CACLR_DISABLE   (0x0u)
#define CHIP_ST3_55_CACLR_DEFAULT   CHIP_ST3_55_CACLR_DISABLE

#define CHIP_ST3_55_HINT_ENABLE     (0x1u)
#define CHIP_ST3_55_HINT_DISABLE    (0x0u)
#define CHIP_ST3_55_HINT_DEFAULT    CHIP_ST3_55_HINT_DISABLE

#define CHIP_ST3_55_CBERR_ON        (0x1u)
#define CHIP_ST3_55_CBERR_OFF       (0x0u)
#define CHIP_ST3_55_CBERR_DEFAULT   CHIP_ST3_55_CBERR_OFF

#define CHIP_ST3_55_MPNMC_ON        (0x1u)
#define CHIP_ST3_55_MPNMC_OFF       (0x0u)
#define CHIP_ST3_55_MPNMC_DEFAULT   CHIP_ST3_55_MPNMC_OFF

#define CHIP_ST3_55_SATA_ON         (0x1u)
#define CHIP_ST3_55_SATA_OFF        (0x0u)
#define CHIP_ST3_55_SATA_DEFAULT    CHIP_ST3_55_SATA_OFF

#define CHIP_ST3_55_AVIS_ON         (0x1u)
#define CHIP_ST3_55_AVIS_OFF        (0x0u)
#define CHIP_ST3_55_AVIS_DEFAULT    CHIP_ST3_55_AVIS_OFF

#define CHIP_ST3_55_CLKOFF_ENABLE   (0x0u)
#define CHIP_ST3_55_CLKOFF_DISABLE  (0x1u)
#define CHIP_ST3_55_CLKOFF_DEFAULT  CHIP_ST3_55_CLKOFF_ENABLE

#define CHIP_ST3_55_SMUL_ON         (0x1u)
#define CHIP_ST3_55_SMUL_OFF        (0x0u)
#define CHIP_ST3_55_SMUL_DEFAULT    CHIP_ST3_55_SMUL_OFF

#define CHIP_ST3_55_SST_ON          (0x1u)
#define CHIP_ST3_55_SST_OFF         (0x0u)
#define CHIP_ST3_55_SST_DEFAULT     CHIP_ST3_55_SST_OFF

#define CHIP_ST3_55_RMK(cafrz, caen, caclr, hint, cberr, mpnmc, sata, avis,\
                        clkoff, smul, sst)\
(Uint16) ( CHIP_FMK(ST3_55,CAFRZ,cafrz)   |\
           CHIP_FMK(ST3_55,CAEN,caen)     |\
           CHIP_FMK(ST3_55,CACLR,caclr)   |\
           CHIP_FMK(ST3_55,HINT,hint)     |\
           CHIP_FMK(ST3_55,CBERR,cberr)   |\
           CHIP_FMK(ST3_55,MPNMC,mpnmc)   |\
           CHIP_FMK(ST3_55,SATA,sata)     |\
           CHIP_FMK(ST3_55,AVIS,avis)     |\
           CHIP_FMK(ST3_55,CLKOFF,clkoff) |\
           CHIP_FMK(ST3_55,SMUL,smul)     |\
           CHIP_FMK(ST3_55,SST,sst)        \
)

#define CHIP_ST3_55_RMKS(cafrz, caen, caclr, hint, cberr, mpnmc, sata, avis,\
                         clkoff, smul, sst)\
(Uint16) ( CHIP_FMKS(ST3_55,CAFRZ,cafrz)   |\
           CHIP_FMKS(ST3_55,CAEN,caen)     |\
           CHIP_FMKS(ST3_55,CACLR,calcr)   |\
           CHIP_FMKS(ST3_55,HINT,hint)     |\
           CHIP_FMKS(ST3_55,CBERR,cberr)   |\
           CHIP_FMKS(ST3_55,MPNMC,mpnmc)   |\
           CHIP_FMKS(ST3_55,SATA,sata)     |\
           CHIP_FMKS(ST3_55,AVIS,avis)     |\
           CHIP_FMKS(ST3_55,CLKOFF,clkoff) |\
           CHIP_FMKS(ST3_55,SMUL,smul)     |\
           CHIP_FMKS(ST3_55,SST,sst)        \
)

// Make Macros for IVPD

#define CHIP_IVPD_IVPD_OF(x)            ((Uint16)(x))

#define CHIP_IVPD_RMK(ivpd)             (Uint16) (CHIP_FMK(IVPD,IVPD,ivpd))  
#define CHIP_IVPD_RMKS(ivpd)            (Uint16) (CHIP_FMKS(IVPD,IVPD,ivpd)) 

// Make Macros for IVPH

#define CHIP_IVPH_IVPH_OF(x)            ((Uint16)(x))

#define CHIP_IVPH_RMK(ivph)             (Uint16) (CHIP_FMK(IVPH,IVPH,ivph))  
#define CHIP_IVPH_RMKS(ivph)            (Uint16) (CHIP_FMKS(IVPH,IVPH,ivph)) 

// Make macros for PDP

#define CHIP_PDP_PDP_OF(x)              ((Uint16)(x))

#define CHIP_PDP_RMK(pdp)               (Uint16) (CHIP_FMK(PDP,PDP,pdp))  
#define CHIP_PDP_RMKS(pdp)              (Uint16) (CHIP_FMKS(PDP,PDP,pdp)) 


#define CHIP_DIEIDL_ADDR                (0x3800u)
#define CHIP_DIEIDH_ADDR                (0x3802u)
#define CHIP_REVID_ADDR                 (0x3804u)

#define CHIP_REVID_5509PG1_0            (0x8050u)
#define CHIP_REVID_5509                 (0x2502u)


#define   CHIP_getDieId_Low32()         ((Uint32) _PREG32_GET(CHIP_DIEIDL_ADDR))

#define   CHIP_getDieId_High32()        ((Uint32) _PREG32_GET(CHIP_DIEIDH_ADDR))

#define   CHIP_getRevId()               ((Uint16) _PREG_GET(CHIP_REVID_ADDR))


#define  CHIP_getEndian {\
        CHIP_ENDIAN_LITTLE\
}


// Make macros for XBSR

#if (CHIP_5509) || (CHIP_5509A)

#define CHIP_XBSR_CLKOUT_DISABLE    (0x0001)
#define CHIP_XBSR_CLKOUT_ENABLE     (0x0000)
#define CHIP_XBSR_CLKOUT_DEFAULT    (CHIP_XBSR_CLKOUT_ENABLE)

#define CHIP_XBSR_OSCDIS_DISABLE    (0x0001)
#define CHIP_XBSR_OSCDIS_ENABLE     (0x0000)
#define CHIP_XBSR_OSCDIS_DEFAULT    (CHIP_XBSR_OSCDIS_ENABLE)

#define CHIP_XBSR_HIDL_IDLE         (0x0001)
#define CHIP_XBSR_HIDL_ENABLE       (0x0000)
#define CHIP_XBSR_HIDL_DEFAULT      (CHIP_XBSR_HIDL_ENABLE)

#define CHIP_XBSR_BKE_DISABLE       (0x0001)
#define CHIP_XBSR_BKE_ENABLE        (0x0000)
#define CHIP_XBSR_BKE_DEFAULT       (CHIP_XBSR_BKE_ENABLE)

#define CHIP_XBSR_HLD_HOLD          (0x0001)
#define CHIP_XBSR_HLD_RELEASE       (0x0000)
#define CHIP_XBSR_HLD_DEFAULT       (CHIP_XBSR_HLD_RELEASE)

#define CHIP_XBSR_HLDA_NO            (0x0001)
#define CHIP_XBSR_HLDA_YES           (0x0000)
#define CHIP_XBSR_HLDA_DEFAULT       (CHIP_XBSR_HLDA_YES)

#define CHIP_XBSR_SP2_MCBSP          (0x0000u)
#define CHIP_XBSR_SP2_MST            (0x0003u)
#define CHIP_XBSR_SP2_MMC            (0x0002u)
#define CHIP_XBSR_SP2_DEFAULT        (CHIP_XBSR_SP2_MCBSP)


#define CHIP_XBSR_SP1_MCBSP          (0x0000u)
#define CHIP_XBSR_SP1_MST            (0x0003u)
#define CHIP_XBSR_SP1_MMC            (0x0002u)
#define CHIP_XBSR_SP1_DEFAULT        (CHIP_XBSR_SP1_MCBSP)

#define CHIP_XBSR_PP_EMIF            (0x0001u)
#define CHIP_XBSR_PP_GPIO            (0x0002u)
#define CHIP_XBSR_PP_EHPI            (0x0002u)


#define CHIP_XBSR_DEFAULT            (0x0003u)


#endif  // (CHIP_5509) || (CHIP_5509A)

#if (CHIP_5509)

#define CHIP_XBSR_EMIFX2_OTHER       (0x0000u)
#define CHIP_XBSR_EMIFX2_DIV2        (0x0001u)
#define CHIP_XBSR_EMIFX2_DEFAULT     (CHIP_XBSR_EMIFX2_OTHER)

#define CHIP_XBSR_RMK(clkout, oscdis, hidl, bke, emifx2, hld, hlda, sp2, sp1, pp)\
 (Uint16) (  _CHIP_XBSR_CLKOUT_MK(clkout)  |\
             _CHIP_XBSR_OSCDIS_MK(oscdis)  |\
             _CHIP_XBSR_HIDL_MK(hidl)      |\
             _CHIP_XBSR_BKE_MK(bke)        |\
             _CHIP_XBSR_EMIFX2_MK(emifx2)  |\
             _CHIP_XBSR_HLD_MK(hld)        |\
             _CHIP_XBSR_HLDA_MK(hlda)      |\
             _CHIP_XBSR_SP2_MK(sp2)        |\
             _CHIP_XBSR_SP1_MK(sp1)        |\
             _CHIP_XBSR_PP_MK(pp)          \
          )


#define CHIP_XBSR_RMKS(clkout_s, oscdis_s, hidl_s, bke_s, emifx2_s, hld_s, hlda_s, sp2_s, sp1_s, pp_s)\
 (Uint16) (  _CHIP_FMKS(XBSR,CLKOUT,clkout_s)  |\
             _CHIP_FMKS(XBSR,OSCDIS,oscdis_s)  |\
             _CHIP_FMKS(XBSR,HIDL,hidl_s)      |\
             _CHIP_FMKS(XBSR,BKE,bke_s)        |\
             _CHIP_FMKS(XBSR,EMIFX2,emifx2_s)  |\
             _CHIP_FMKS(XBSR,HLD,hld_s)        |\
             _CHIP_FMKS(XBSR,HLDA,hlda_s)      |\
             _CHIP_FMKS(XBSR,SP2,sp2_s)        |\
             _CHIP_FMKS(XBSR,SP1,sp1_s)        |\
             _CHIP_FMKS(XBSR,PP,pp_s)          \
          )

#endif // (CHIP_5509)

#if (CHIP_5509A)

#define CHIP_XBSR_SRSTAT_ENABLE          (0x0001u)
#define CHIP_XBSR_SRSTAT_DISABLE         (0x0000u)
#define CHIP_XBSR_SRSTAT_DEFAULT         (CHIP_XBSR_SRSTAT_DISABLE)

#define CHIP_XBSR_CKE_XF                 (0x0000u)
#define CHIP_XBSR_CKE_GPIO4              (0x0001u)
#define CHIP_XBSR_CKE_DEFAULT            (CHIP_XBSR_CKE_DEFAULT)

#define CHIP_XBSR_CKEEN_NORMAL           (0x0000u)
#define CHIP_XBSR_CKEEN_CKE              (0x0001u)
#define CHIP_XBSR_CKEEN_DEFAULT          (CHIP_XBSR_CKEEN_NORMAL)

#define CHIP_XBSR_SRCOM_ENABLE           (0x0001u)
#define CHIP_XBSR_SRCOM_DISABLE          (0x0000u)
#define CHIP_XBSR_SRCOM_EHPI             (CHIP_XBSR_SRCOM_DISABLE)

#define CHIP_XBSR_RMK(clkout, oscdis, hidl, bke, srstat, hld, hlda, cke, ckeen, srcom, sp2, sp1, pp)\
 (Uint16) (  _CHIP_XBSR_CLKOUT_MK(clkout)  |\
             _CHIP_XBSR_OSCDIS_MK(oscdis)  |\
             _CHIP_XBSR_HIDL_MK(hidl)      |\
             _CHIP_XBSR_BKE_MK(bke)        |\
             _CHIP_XBSR_SRSTAT_MK(srstat)  |\
             _CHIP_XBSR_HLD_MK(hld)        |\
             _CHIP_XBSR_HLDA_MK(hlda)      |\
             _CHIP_XBSR_CKE_MK(CKE)        |\
             _CHIP_XBSR_CKEEN_MK(ckeen)    |\
             _CHIP_XBSR_SRCOM_MK(srcom)    |\
             _CHIP_XBSR_SP2_MK(sp2)        |\
             _CHIP_XBSR_SP1_MK(sp1)        |\
             _CHIP_XBSR_PP_MK(pp)          \
          )


#define CHIP_XBSR_RMKS(clkout_s, oscdis_s, hidl_s, bke_s, srstat_s, hld_s, hlda_s, cke_s, ckeen_s,\
                               srcom_s, sp2_s, sp1_s, pp_s)\
 (Uint16) (  _CHIP_FMKS(XBSR,CLKOUT,clkout_s)  |\
             _CHIP_FMKS(XBSR,OSCDIS,oscdis_s)  |\
             _CHIP_FMKS(XBSR,HIDL,hidl_s)      |\
             _CHIP_FMKS(XBSR,BKE,bke_s)        |\
             _CHIP_FMKS(XBSR,SRSTAT,srstat_s)  |\
             _CHIP_FMKS(XBSR,HLD,hld_s)        |\
             _CHIP_FMKS(XBSR,HLDA,hlda_s)      |\
             _CHIP_FMKS(XBSR,CKE,cke_s)        |\
             _CHIP_FMKS(XBSR,CKEEN,ckeen_s)    |\
             _CHIP_FMKS(XBSR,SRCOM,srcom_s)    |\
             _CHIP_FMKS(XBSR,SP2,sp2_s)        |\
             _CHIP_FMKS(XBSR,SP1,sp1_s)        |\
             _CHIP_FMKS(XBSR,PP,pp_s)          \
          )

#endif // (CHIP_5509A)

#if (CHIP_5502)

#define CHIP_XBSR_SP2MODE_UART      (0x0000)
#define CHIP_XBSR_SP2MODE_GPIO      (0x0000)
#define CHIP_XBSR_SP2MODE_MCBSP     (0x0001)


#define CHIP_XBSR_PPMODE_PPXHPI     (0x0000)
#define CHIP_XBSR_PPMODE_PPXPGPIO   (0x0000)
#define CHIP_XBSR_PPMODE_HPXPGPIO   (0x0000)

#define CHIP_XBSR_PPMODE_PPXEMIF    (0x0001)
#define CHIP_XBSR_PPMODE_HPXHPI     (0x0001)

#define CHIP_XBSR_RMK(sp2mode,ppmode)\
   (Uint16) (   _CHIP_XBSR_SP2MODE_MK(sp2mode)   |\
                _CHIP_XBSR_PPMODE_MK(ppmode)\
            )

#define CHIP_XBSR_RMKS(sp2mode_s,ppmode_s)\
   (Uint16) (   _CHIP_XBSR_FMKS(SP2MODE,sp2mode_s)   |\
                _CHIP_XBSR_FMKS(PPMODE,ppmode_s)\
            )

#endif

#if (CHIP_5501)

#define CHIP_XBSR_PPMODE_PPXPGPIO   (0x0000)
#define CHIP_XBSR_PPMODE_HPXPGPIO   (0x0000)

#define CHIP_XBSR_PPMODE_PPXEMIF    (0x0001)
#define CHIP_XBSR_PPMODE_HPXHPI     (0x0001)

#define CHIP_XBSR_RMK(ppmode)\
   (Uint16) (_CHIP_XBSR_PPMODE_MK(ppmode))

#define CHIP_XBSR_RMKS(ppmode_s)\
   (Uint16) ( _CHIP_XBSR_FMKS(PPMODE,ppmode_s))

#endif

// Make macros for SYSR

#if (CHIP_5510PG2_0)

#define CHIP_SYSR_HPE_ENABLE     (0x1u)
#define CHIP_SYSR_HPE_DISABLE    (0x0u)
#define CHIP_SYSR_HPE_DEFAULT    (CHIP_SYSR_HPE_ENABLE)

#define CHIP_SYSR_BH_ENABLE      (0x1u)
#define CHIP_SYSR_BH_DISABLE     (0x0u)
#define CHIP_SYSR_BH_DEFAULT     (CHIP_SYSR_BH_DISABLE)

#define CHIP_SYSR_HBH_ENABLE     (0x1u) 
#define CHIP_SYSR_HBH_DISABLE    (0x0u)
#define CHIP_SYSR_HBH_DEFAULT    (CHIP_SYSR_HBH_DISABLE)

#define CHIP_SYSR_BOOTM3_DEFAULT (0x0u)

#define CHIP_SYSR_CLKDIV_DIV1    (0x0u)
#define CHIP_SYSR_CLKDIV_DIV2    (0x1u)
#define CHIP_SYSR_CLKDIV_DIV4    (0x2u)
#define CHIP_SYSR_CLKDIV_DIV6    (0x3u)
#define CHIP_SYSR_CLKDIV_DIV8    (0x4u)
#define CHIP_SYSR_CLKDIV_DIV10   (0x5u)
#define CHIP_SYSR_CLKDIV_DIV12   (0x6u)
#define CHIP_SYSR_CLKDIV_DIV14   (0x7u)
#define CHIP_SYSR_CLKDIV_DEFAULT (CHIP_SYSR_CLKDIV_DIV1)

#define CHIP_SYSR_RMK(hpe, bh, hbh, clkdiv)\
  (Uint16)( CHIP_FMK(SYSR,HPE,hpe)       |\
            CHIP_FMK(SYSR,BH,bh)         |\
            CHIP_FMK(SYSR,HBH,hbh)       |\
            CHIP_FMK(SYSR,CLKDIV,clkdiv) \
          )

#define CHIP_SYSR_RMKS(hpe_s, bh_s, hbh_s, clkdiv_s)\
  (Uint16)( CHIP_FMKS(SYSR,HPE,hpe_s)       |\
            CHIP_FMKS(SYSR,BH,bh_s)         |\
            CHIP_FMKS(SYSR,HBH,hbh_s)       |\
            CHIP_FMKS(SYSR,CLKDIV,clkdiv_s) \
          )

#define CHIP_SYSR_DEFAULT       (0x0200u)

#endif

#if (CHIP_5509A)

#define CHIP_SYSR_CLKDIV_DIV1    (0x0u)
#define CHIP_SYSR_CLKDIV_DIV2    (0x1u)
#define CHIP_SYSR_CLKDIV_DIV4    (0x2u)
#define CHIP_SYSR_CLKDIV_DIV6    (0x3u)
#define CHIP_SYSR_CLKDIV_DIV8    (0x4u)
#define CHIP_SYSR_CLKDIV_DIV10   (0x5u)
#define CHIP_SYSR_CLKDIV_DIV12   (0x6u)
#define CHIP_SYSR_CLKDIV_DIV14   (0x7u)
#define CHIP_SYSR_CLKDIV_DEFAULT (CHIP_SYSR_CLKDIV_DIV1)

#define CHIP_SYSR_RMK(clkdiv)\
  (Uint16)(CHIP_FMK(SYSR,CLKDIV,clkdiv))

#define CHIP_SYSR_RMKS(clkdiv_s)\
  (Uint16)(CHIP_FMKS(SYSR,CLKDIV,clkdiv_s))

#define CHIP_SYSR_DEFAULT       (0x0000u)

#endif


// Make macros for SROM
#if (CHIP_5509) || (CHIP_5509A)

#define CHIP_SROM_SROM_DISABLE        (0x1u)
#define CHIP_SROM_SROM_ENABLE         (0x0u)
#define CHIP_SROM_SROM_DEFAULT        (CHIP_SROM_SROM_ENABLE)
   
#define CHIP_SROM_RMK(srom)\
  (Uint16)(CHIP_FMK(SROM,SROM,srom))
#define CHIP_SROM_RMKS(srom_s)\
  (Uint16)(CHIP_FMKS(SROM,SROM,srom_s))
   
#define CHIP_SROM_DEFAULT             (0x0000u)

#endif
   
// Make macros for XBCR

#if (CHIP_5502) || (CHIP_5501)

#define CHIP_XBCR_EMU_ENABLE     (0x0u)
#define CHIP_XBCR_EMU_DISABLE    (0x1u)
#define CHIP_XBCR_EMU_DEFAULT    (CHIP_XBCR_EMU_ENABLE)

#define CHIP_XBCR_TEST_ENABLE    (0x0u)
#define CHIP_XBCR_TEST_DISABLE   (0x1u)
#define CHIP_XBCR_TEST_DEFAULT   (CHIP_XBCR_TEST_ENABLE)

#define CHIP_XBCR_WDT_ENABLE     (0x0u)
#define CHIP_XBCR_WDT_DISABLE    (0x1u)
#define CHIP_XBCR_WDT_DEFAULT    (CHIP_XBCR_WDT_ENABLE)

#define CHIP_XBCR_HCH_ENABLE     (0x0u)
#define CHIP_XBCR_HCH_DISABLE    (0x1u)
#define CHIP_XBCR_HCH_DEFAULT    (CHIP_XBCR_HCH_ENABLE)

#define CHIP_XBCR_HDH_ENABLE     (0x0u)
#define CHIP_XBCR_HDH_DISABLE    (0x1u)
#define CHIP_XBCR_HDH_DEFAULT    (CHIP_XBCR_HDH_ENABLE)

#define CHIP_XBCR_PCH_ENABLE     (0x0u)
#define CHIP_XBCR_PCH_DISABLE    (0x1u)
#define CHIP_XBCR_PCH_DEFAULT    (CHIP_XBCR_PCH_ENABLE)

#define CHIP_XBCR_PDH_ENABLE     (0x0u)
#define CHIP_XBCR_PDH_DISABLE    (0x1u)
#define CHIP_XBCR_PDH_DEFAULT    (CHIP_XBCR_PDH_ENABLE)

#define CHIP_XBCR_PAH_ENABLE     (0x0u)
#define CHIP_XBCR_PAH_DISABLE    (0x1u)
#define CHIP_XBCR_PAH_DEFAULT    (CHIP_XBCR_PAH_ENABLE)


#define CHIP_XBCR_RMK(emu, test, wdt, hch, hdh, pch, pdh, pah)\
  (Uint16)( CHIP_FMK(XBCR,EMU,emu)       |\
            CHIP_FMK(XBCR,TEST,test)     |\
            CHIP_FMK(XBCR,WDT,wdt)       |\
            CHIP_FMK(XBCR,HCH,hch)       |\
            CHIP_FMK(XBCR,HDH,hdh)       |\
            CHIP_FMK(XBCR,PCH,pch)       |\
            CHIP_FMK(XBCR,PDH,pdh)       |\
            CHIP_FMK(XBCR,PAH,pah)       \
          )

#define CHIP_XBCR_RMKS(emu_s, test_s, wdt_s, hch_s, hdh_s, pch_s, pdh_s, pah_s)\
  (Uint16)( CHIP_FMKS(XBCR,EMU,emu_s)       |\
            CHIP_FMKS(XBCR,TEST,test_s)     |\
            CHIP_FMKS(XBCR,WDT,wdt_s)       |\
            CHIP_FMKS(XBCR,HCH,hch_s)       |\
            CHIP_FMKS(XBCR,HDH,hdh_s)       |\
            CHIP_FMKS(XBCR,PCH,pch_s)       |\
            CHIP_FMKS(XBCR,PDH,pdh_s)       |\
            CHIP_FMKS(XBCR,PAH,pah_s)       \
          )

#define CHIP_XBCR_DEFAULT       (0x0000u)


// Make macros for TSSR

#define CHIP_TSSR_TIM2MODE_IN         (0x0000)
#define CHIP_TSSR_TIM2MODE_OUT        (0x0001)
#define CHIP_TSSR_TIM2MODE_DEFAULT    (CHIP_TSSR_TIM2MODE_IN)

#define CHIP_TSSR_TIM1MODE_IN         (0x0000)
#define CHIP_TSSR_TIM1MODE_OUT        (0x0001)
#define CHIP_TSSR_TIM1MODE_DEFAULT    (CHIP_TSSR_TIM1MODE_IN)

#define CHIP_TSSR_TIM0MODE_IN         (0x0000)
#define CHIP_TSSR_TIM0MODE_OUT        (0x0001)
#define CHIP_TSSR_TIM0MODE_DEFAULT    (CHIP_TSSR_TIM0MODE_IN)

#define CHIP_TSSR_IWCON_NONE          (0x0000)
#define CHIP_TSSR_IWCON_RESET         (0x0001)
#define CHIP_TSSR_IWCON_NMI           (0x0002)
#define CHIP_TSSR_IWCON_INT3          (0x0003)
#define CHIP_TSSR_IWCON_DEFAULT       (CHIP_TSSR_IWCON_NONE)

#define CHIP_TSSR_NMISEL_WDTOUT       (0x0000)
#define CHIP_TSSR_NMISEL_NMI          (0x0001)
#define CHIP_TSSR_NMISEL_DEFAULT      (CHIP_TSSR_NMISEL_NMI)


#define CHIP_TSSR_RMK(tim2mode, tim1mode, tim0mode, iwcon, nmisel)\
  (Uint16)( CHIP_FMK(TSSR,TIM2MODE,tim2mode)       |\
            CHIP_FMK(TSSR,TIM1MODE,tim1mode)       |\
            CHIP_FMK(TSSR,TIM0MODE,tim0mode)       |\
            CHIP_FMK(TSSR,IWCON,iwcon)             |\
            CHIP_FMK(TSSR,NMISEL,nmisel)           \
          )

#define CHIP_TSSR_RMKS(tim2mode_s, tim1mode_s, tim0mode_s, iwcon_s, nmisel_s)\
  (Uint16)( CHIP_FMKS(TSSR,TIM2MODE,tim2mode_s)       |\
            CHIP_FMKS(TSSR,TIM1MODE,tim1mode_s)       |\
            CHIP_FMKS(TSSR,TIM0MODE,tim0mode_s)       |\
            CHIP_FMKS(TSSR,IWCON,iwcon_s)             |\
            CHIP_FMKS(TSSR,NMISEL,nmisel_s)           \
          )

#define CHIP_TSSR_DEFAULT              (0x0001u)


// Make macros for CLKOSR


#define CHIP_CLKOSR_CKOSEL_SYSCLK1     (0x0001)
#define CHIP_CLKOSR_CKOSEL_SYSCLK2     (0x0002)
#define CHIP_CLKOSR_CKOSEL_SYSCLK3     (0x0003)
#define CHIP_CLKOSR_CKOSEL_DEFAULT     (CHIP_CLKOSR_CKOSEL_SYSCLK1)

#define CHIP_CLKOSR_CKODIS_ENABLE      (0x0000)
#define CHIP_CLKOSR_CKODIS_DISABLE     (0x0001)
#define CHIP_CLKOSR_CKODIS_DEFAULT     (CHIP_CLKOSR_CKODIS_ENABLE)

#define CHIP_CLKOSR_RMK(ckosel, ckodis)\
  (Uint16)( CHIP_FMK(CLKOSR,CKOSEL,ckosel) |\
            CHIP_FMK(CLKOSR,CKODIS,ckodis) \
          )

#define CHIP_CLKOSR_RMKS(ckosel_s, ckodis_s)\
  (Uint16)( CHIP_FMKS(CLKOSR,CKOSEL,ckosel_s) |\
            CHIP_FMKS(CLKOSR,CKODIS,ckodis_s) \
          )

#endif
 
/*******************************************\
* CHIP global macro definition : ROMABILITY
\*******************************************/ 
/* Reserved ROM Area for Chip Data */
            
/* None Data used by CHIP functions */

/****************************************\
* CHIP global typedef declarations
\****************************************/

/****************************************\
* CHIP global variable declarations
\****************************************/

/****************************************\
* CHIP global function declarations
\****************************************/

/****************************************\
* CHIP inline function declarations
\****************************************/

/****************************************\
* CHIP inline function definitions
\****************************************/

#endif /* _CHIP_SUPPORT */
#endif /* _CHIP_H_ */
/******************************************************************************\
* End of CHIP.h
\******************************************************************************/

