/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... MCBSP
* FILENAME...... csl_mcbsphal.h
* DATE CREATED.. Wed 05/31/2000
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS.. csl_stdinc.h, csl_chip.h
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:        05/31/2000 created
*   MODIFIED:       04/16/2001 updated FILENAME and other header comments
*   LAST MODIFIED:  05/23/2001 fixed _MCBSP_DXR/DRR base address macros
*                   08/03/2004 Added 5501 support  
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the MCBSP module)
*
* Registers Covered:
*   (RW) _MCBSP_SPCR10 -  Serial Port Control Register 1, McBSP #0
*   (RW) _MCBSP_SPCR20 -  Serial Port Control Register 2, McBSP #0
*   (RW) _MCBSP_SPCR11 -  Serial Port Control Register 1, McBSP #1
*   (RW) _MCBSP_SPCR21 -  Serial Port Control Register 2, McBSP #1
*   (RW) _MCBSP_SPCR12 -  Serial Port Control Register 1, McBSP #2
*   (RW) _MCBSP_SPCR22_ -  Serial Port Control Register 2, McBSP #2
*   (RW) _MCBSP_PCR0    -  Pin Control Register, McBSP #0
*   (RW) _MCBSP_PCR1    -  Pin Control Register, McBSP #1
*   (RW) _MCBSP_PCR2    -  Pin Control Register, McBSP #2
*   (RW) _MCBSP_RCR10  -  Receive and Transmit Control Register 1, McBSP #0
*   (RW) _MCBSP_RCR20  -  Receive and Transmit Control Register 2, McBSP #0
*   (RW) _MCBSP_RCR11  -  Receive and Transmit Control Register 1, McBSP #1
*   (RW) _MCBSP_RCR21  -  Receive and Transmit Control Register 2, McBSP #1
*   (RW) _MCBSP_RCR12  -  Receive and Transmit Control Register 1, McBSP #2
*   (RW) _MCBSP_RCR22  -  Receive and Transmit Control Register 2, McBSP #2
*   (RW) _MCBSP_XCR10  -  Transmit Control Register 1, McBSP #0
*   (RW) _MCBSP_XCR20  -  Transmit Control Register 2, McBSP #0
*   (RW) _MCBSP_XCR11  -  Transmit Control Register 1, McBSP #1
*   (RW) _MCBSP_XCR21  -  Transmit Control Register 2, McBSP #1
*   (RW) _MCBSP_XCR12  -  Transmit Control Register 1, McBSP #2
*   (RW) _MCBSP_XCR22  -  Transmit Control Register 2, McBSP #2
*   (RW) _MCBSP_SRGR10 -  Sample Rate Generator Register 1, McBSP #0
*   (RW) _MCBSP_SRGR20 -  Sample Rate Generator Register 2, McBSP #0
*   (RW) _MCBSP_SRGR11 -  Sample Rate Generator Register 1, McBSP #1
*   (RW) _MCBSP_SRGR21 -  Sample Rate Generator Register 2, McBSP #1
*   (RW) _MCBSP_SRGR12 -  Sample Rate Generator Register 1, McBSP #2
*   (RW) _MCBSP_SRGR22 -  Sample Rate Generator Register 2, McBSP #2
*   (RW) _MCBSP_MCR10  -  Multi-channel Control Register 1, McBSP #0
*   (RW) _MCBSP_MCR20  -  Multi-channel Control Register 2, McBSP #0
*   (RW) _MCBSP_MCR11  -  Multi-channel Control Register 1, McBSP #1
*   (RW) _MCBSP_MCR21  -  Multi-channel Control Register 2, McBSP #1
*   (RW) _MCBSP_MCR12  -  Multi-channel Control Register 1, McBSP #2
*   (RW) _MCBSP_MCR22  -  Multi-channel Control Register 2, McBSP #2
*   (RW) _MCBSP_XCERA0 -  Transmit Channel Enable Register Partition A, McBSP #0
*   (RW) _MCBSP_XCERB0 -  Transmit Channel Enable Register Partition B, McBSP #0
*   (RW) _MCBSP_XCERC0 -  Additional Transmit Channel Enable Register for 128 channel selection, McBSP #0
*   (RW) _MCBSP_XCERD0 -  Additional Transmit Channel Enable Register for 128 channel selection, McBSP #0
*   (RW) _MCBSP_XCERE0 -  Additional Transmit Channel Enable Register for 128 channel selection, McBSP #0
*   (RW) _MCBSP_XCERF0 -  Additional Transmit Channel Enable Register for 128 channel selection, McBSP #0
*   (RW) _MCBSP_XCERG0 -  Additional Transmit Channel Enable Register for 128 channel selection, McBSP #0
*   (RW) _MCBSP_XCERH0 -  Additional Transmit Channel Enable Register for 128 channel selection, McBSP #0
*   (RW) _MCBSP_XCERA1 -  Transmit Channel Enable Register Partition A, McBSP #1
*   (RW) _MCBSP_XCERB1 -  Transmit Channel Enable Register Partition B, McBSP #1
*   (RW) _MCBSP_XCERC1 -  Additional Transmit Channel Enable Register for 128 channel selection, McBSP #1
*   (RW) _MCBSP_XCERD1 -  Additional Transmit Channel Enable Register for 128 channel selection, McBSP #1
*   (RW) _MCBSP_XCERE1 -  Additional Transmit Channel Enable Register for 128 channel selection, McBSP #1
*   (RW) _MCBSP_XCERF1 -  Additional Transmit Channel Enable Register for 128 channel selection, McBSP #1
*   (RW) _MCBSP_XCERG1 -  Additional Transmit Channel Enable Register for 128 channel selection, McBSP #1
*   (RW) _MCBSP_XCERH1 -  Additional Transmit Channel Enable Register for 128 channel selection, McBSP #1
*   (RW) _MCBSP_XCERA2 -  Transmit Channel Enable Register Partition A, McBSP #2
*   (RW) _MCBSP_XCERB2 -  Transmit Channel Enable Register Partition B, McBSP #2
*   (RW) _MCBSP_XCERC2 -  Additional Transmit Channel Enable Register for 128 channel selection, McBSP #2
*   (RW) _MCBSP_XCERD2 -  Additional Transmit Channel Enable Register for 128 channel selection, McBSP #2
*   (RW) _MCBSP_XCERE2 -  Additional Transmit Channel Enable Register for 128 channel selection, McBSP #2
*   (RW) _MCBSP_XCERF2 -  Additional Transmit Channel Enable Register for 128 channel selection, McBSP #2
*   (RW) _MCBSP_XCERG2 -  Additional Transmit Channel Enable Register for 128 channel selection, McBSP #2
*   (RW) _MCBSP_XCERH2 -  Additional Transmit Channel Enable Register for 128 channel selection, McBSP #2
*   (RW) _MCBSP_RCERA0 -  Receive Channel Enable Register Partition A, McBSP #0
*   (RW) _MCBSP_RCERB0 -  Receive Channel Enable Register Partition A, McBSP #0
*   (RW) _MCBSP_RCERC0 -  Additional Receive Channel Enable Register for 128 channel selection, McBSP #0
*   (RW) _MCBSP_RCERD0 -  Additional Receive Channel Enable Register for 128 channel selection, McBSP #0
*   (RW) _MCBSP_RCERE0 -  Additional Receive Channel Enable Register for 128 channel selection, McBSP #0
*   (RW) _MCBSP_RCERF0 -  Additional Receive Channel Enable Register for 128 channel selection, McBSP #0
*   (RW) _MCBSP_RCERG0 -  Additional Receive Channel Enable Register for 128 channel selection, McBSP #0
*   (RW) _MCBSP_RCERH0 -  Additional Receive Channel Enable Register for 128 channel selection, McBSP #0
*   (RW) _MCBSP_RCERA1 -  Receive Channel Enable Register Partition A, McBSP #1
*   (RW) _MCBSP_RCERB1 -  Receive Channel Enable Register Partition A, McBSP #1
*   (RW) _MCBSP_RCERC1 -  Additional Receive Channel Enable Register for 128 channel selection, McBSP #1
*   (RW) _MCBSP_RCERD1 -  Additional Receive Channel Enable Register for 128 channel selection, McBSP #1
*   (RW) _MCBSP_RCERE1 -  Additional Receive Channel Enable Register for 128 channel selection, McBSP #1
*   (RW) _MCBSP_RCERF1 -  Additional Receive Channel Enable Register for 128 channel selection, McBSP #1
*   (RW) _MCBSP_RCERG1 -  Additional Receive Channel Enable Register for 128 channel selection, McBSP #1
*   (RW) _MCBSP_RCERH1 -  Additional Receive Channel Enable Register for 128 channel selection, McBSP #1
*   (RW) _MCBSP_RCERA2 -  Receive Channel Enable Register Partition A, McBSP #2
*   (RW) _MCBSP_RCERB2 -  Receive Channel Enable Register Partition A, McBSP #2
*   (RW) _MCBSP_RCERC2 -  Additional Receive Channel Enable Register for 128 channel selection, McBSP #2
*   (RW) _MCBSP_RCERD2 -  Additional Receive Channel Enable Register for 128 channel selection, McBSP #2
*   (RW) _MCBSP_RCERE2 -  Additional Receive Channel Enable Register for 128 channel selection, McBSP #2
*   (RW) _MCBSP_RCERF2 -  Additional Receive Channel Enable Register for 128 channel selection, McBSP #2
*   (RW) _MCBSP_RCERG2 -  Additional Receive Channel Enable Register for 128 channel selection, McBSP #2
*   (RW) _MCBSP_RCERH2 -  Additional Receive Channel Enable Register for 128 channel selection, McBSP #2
*   (RW) _MCBSP_DRR10  -  Data Receive Register 1, McBSP #0
*   (RW) _MCBSP_DRR20  -  Data Receive Register 2, McBSP #0
*   (RW) _MCBSP_DRR11  -  Data Receive Register 1, McBSP #1
*   (RW) _MCBSP_DRR21  -  Data Receive Register 2, McBSP #1
*   (RW) _MCBSP_DRR12  -  Data Receive Register 1, McBSP #2
*   (RW) _MCBSP_DRR22  -  Data Receive Register 2, McBSP #2
*   (RW) _MCBSP_DXR10  -  Data Transmit Register 1, McBSP #0
*   (RW) _MCBSP_DXR20  -  Data Transmist Register 2, McBSP #0
*   (RW) _MCBSP_DXR11  -  Data Transmit Register 1, McBSP #1
*   (RW) _MCBSP_DXR21  -  Data Transmist Register 2, McBSP #1
*   (RW) _MCBSP_DXR12  -  Data Transmit Register 1, McBSP #2
*   (RW) _MCBSP_DXR22  -  Data Transmist Register 2, McBSP #2
\******************************************************************************/
#ifndef _MCBSPHAL_H_
#define _MCBSPHAL_H_

#include <csl_chiphal.h>

#if (_MCBSP_SUPPORT)

/*============================================================================*\
* misc declarations
\*============================================================================*/
#define _MCBSP_DEVICE_CNT			(3)

/*============================================================================*\
* memory mapped register addresses
\*============================================================================*/

#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_DRR20_ADDR			(0x2800u)
  #define _MCBSP_DRR10_ADDR			(0x2801u)
  #define _MCBSP_DXR20_ADDR               (0x2802u)
  #define _MCBSP_DXR10_ADDR               (0x2803u)

  #define _MCBSP_DRR21_ADDR			(0x2C00u)
  #define _MCBSP_DRR11_ADDR			(0x2C01u)
  #define _MCBSP_DXR21_ADDR               (0x2C02u)
  #define _MCBSP_DXR11_ADDR               (0x2C03u)

  #define _MCBSP_DRR22_ADDR			(0x3000u)
  #define _MCBSP_DRR12_ADDR			(0x3001u)
  #define _MCBSP_DXR22_ADDR			(0x3002u)
  #define _MCBSP_DXR12_ADDR			(0x3003u)

  #define _MCBSP_DRR1_BASE_ADDR             (0x2801u)
  #define _MCBSP_DRR2_BASE_ADDR             (0x2800u)
  #define _MCBSP_DXR1_BASE_ADDR             (0x2803u)
  #define _MCBSP_DXR2_BASE_ADDR             (0x2802u)

  #define _MCBSP_SPCR1_BASE_ADDR            (0x2805u)
  #define _MCBSP_SPCR2_BASE_ADDR            (0x2804u)
  #define _MCBSP_PCR_BASE_ADDR              (0x2812u)
  #define _MCBSP_RCR1_BASE_ADDR             (0x2807u)
  #define _MCBSP_RCR2_BASE_ADDR             (0x2806u)
  #define _MCBSP_XCR1_BASE_ADDR             (0x2809u)
  #define _MCBSP_XCR2_BASE_ADDR             (0x2808u)
  #define _MCBSP_SRGR1_BASE_ADDR            (0x280Bu)
  #define _MCBSP_SRGR2_BASE_ADDR            (0x280Au)
  #define _MCBSP_MCR1_BASE_ADDR             (0x280Du)
  #define _MCBSP_MCR2_BASE_ADDR             (0x280Cu)

  #define _MCBSP_XCERA_BASE_ADDR            (0x2810u)
  #define _MCBSP_XCERB_BASE_ADDR            (0x2811u)
  #define _MCBSP_XCERC_BASE_ADDR            (0x2815u)
  #define _MCBSP_XCERD_BASE_ADDR            (0x2816u)
  #define _MCBSP_XCERE_BASE_ADDR            (0x2819u)
  #define _MCBSP_XCERF_BASE_ADDR            (0x281Au)
  #define _MCBSP_XCERG_BASE_ADDR            (0x281Du)
  #define _MCBSP_XCERH_BASE_ADDR            (0x281Eu)

  #define _MCBSP_RCERA_BASE_ADDR            (0x280Eu)
  #define _MCBSP_RCERB_BASE_ADDR            (0x280Fu)
  #define _MCBSP_RCERC_BASE_ADDR            (0x2813u)
  #define _MCBSP_RCERD_BASE_ADDR            (0x2814u)
  #define _MCBSP_RCERE_BASE_ADDR            (0x2817u)
  #define _MCBSP_RCERF_BASE_ADDR            (0x2818u)
  #define _MCBSP_RCERG_BASE_ADDR            (0x281Bu)
  #define _MCBSP_RCERH_BASE_ADDR            (0x281Cu)
#else
  #define _MCBSP_DRR10_ADDR			(0x2800u)
  #define _MCBSP_DRR20_ADDR			(0x2801u)
  #define _MCBSP_DXR10_ADDR               (0x2802u)
  #define _MCBSP_DXR20_ADDR               (0x2803u)

  #define _MCBSP_DRR11_ADDR			(0x2C00u)
  #define _MCBSP_DRR21_ADDR			(0x2C01u)
  #define _MCBSP_DXR11_ADDR               (0x2C02u)
  #define _MCBSP_DXR21_ADDR               (0x2C03u)

  #define _MCBSP_DRR12_ADDR			(0x3000u)
  #define _MCBSP_DRR22_ADDR			(0x3001u)
  #define _MCBSP_DXR12_ADDR			(0x3002u)
  #define _MCBSP_DXR22_ADDR			(0x3003u)

  #define _MCBSP_DRR2_BASE_ADDR             (0x2801u)
  #define _MCBSP_DRR1_BASE_ADDR             (0x2800u)
  #define _MCBSP_DXR2_BASE_ADDR             (0x2803u)
  #define _MCBSP_DXR1_BASE_ADDR             (0x2802u)

  #define _MCBSP_SPCR2_BASE_ADDR            (0x2805u)
  #define _MCBSP_SPCR1_BASE_ADDR            (0x2804u)
  #define _MCBSP_PCR_BASE_ADDR              (0x2812u)
  #define _MCBSP_RCR2_BASE_ADDR             (0x2807u)
  #define _MCBSP_RCR1_BASE_ADDR             (0x2806u)
  #define _MCBSP_XCR2_BASE_ADDR             (0x2809u)
  #define _MCBSP_XCR1_BASE_ADDR             (0x2808u)
  #define _MCBSP_SRGR2_BASE_ADDR            (0x280Bu)
  #define _MCBSP_SRGR1_BASE_ADDR            (0x280Au)
  #define _MCBSP_MCR2_BASE_ADDR             (0x280Du)
  #define _MCBSP_MCR1_BASE_ADDR             (0x280Cu)

  #define _MCBSP_XCERA_BASE_ADDR            (0x2810u)
  #define _MCBSP_XCERB_BASE_ADDR            (0x2811u)
  #define _MCBSP_XCERC_BASE_ADDR            (0x2816u)
  #define _MCBSP_XCERD_BASE_ADDR            (0x2817u)
  #define _MCBSP_XCERE_BASE_ADDR            (0x281Au)
  #define _MCBSP_XCERF_BASE_ADDR            (0x281Bu)
  #define _MCBSP_XCERG_BASE_ADDR            (0x281Eu)
  #define _MCBSP_XCERH_BASE_ADDR            (0x281Fu)

  #define _MCBSP_RCERA_BASE_ADDR            (0x280Eu)
  #define _MCBSP_RCERB_BASE_ADDR            (0x280Fu)
  #define _MCBSP_RCERC_BASE_ADDR            (0x2814u)
  #define _MCBSP_RCERD_BASE_ADDR            (0x2815u)
  #define _MCBSP_RCERE_BASE_ADDR            (0x2818u)
  #define _MCBSP_RCERF_BASE_ADDR            (0x2819u)
  #define _MCBSP_RCERG_BASE_ADDR            (0x281Cu)
  #define _MCBSP_RCERH_BASE_ADDR            (0x281Du)
#endif
#define _MCBSP_RCERA_ADDR(Port)           ((Port * 0x0400u) + _MCBSP_RCERA_BASE_ADDR)
#define _MCBSP_RCERB_ADDR(Port)           ((Port * 0x0400u) + _MCBSP_RCERB_BASE_ADDR)
#define _MCBSP_RCERC_ADDR(Port)           ((Port * 0x0400u) + _MCBSP_RCERC_BASE_ADDR)
#define _MCBSP_RCERD_ADDR(Port)           ((Port * 0x0400u) + _MCBSP_RCERD_BASE_ADDR)
#define _MCBSP_RCERE_ADDR(Port)           ((Port * 0x0400u) + _MCBSP_RCERE_BASE_ADDR)
#define _MCBSP_RCERF_ADDR(Port)           ((Port * 0x0400u) + _MCBSP_RCERF_BASE_ADDR)
#define _MCBSP_RCERG_ADDR(Port)           ((Port * 0x0400u) + _MCBSP_RCERG_BASE_ADDR)
#define _MCBSP_RCERH_ADDR(Port)           ((Port * 0x0400u) + _MCBSP_RCERH_BASE_ADDR)

#define _MCBSP_XCERA_ADDR(Port)           ((Port * 0x0400u) + _MCBSP_XCERA_BASE_ADDR)
#define _MCBSP_XCERB_ADDR(Port)           ((Port * 0x0400u) + _MCBSP_XCERB_BASE_ADDR)
#define _MCBSP_XCERC_ADDR(Port)           ((Port * 0x0400u) + _MCBSP_XCERC_BASE_ADDR)
#define _MCBSP_XCERD_ADDR(Port)           ((Port * 0x0400u) + _MCBSP_XCERD_BASE_ADDR)
#define _MCBSP_XCERE_ADDR(Port)           ((Port * 0x0400u) + _MCBSP_XCERE_BASE_ADDR)
#define _MCBSP_XCERF_ADDR(Port)           ((Port * 0x0400u) + _MCBSP_XCERF_BASE_ADDR)
#define _MCBSP_XCERG_ADDR(Port)           ((Port * 0x0400u) + _MCBSP_XCERG_BASE_ADDR)
#define _MCBSP_XCERH_ADDR(Port)           ((Port * 0x0400u) + _MCBSP_XCERH_BASE_ADDR)


#define _MCBSP_SPCR1_ADDR(Port)           ((Port * 0x0400u) + _MCBSP_SPCR1_BASE_ADDR)
#define _MCBSP_SPCR2_ADDR(Port)           ((Port * 0x0400u) + _MCBSP_SPCR2_BASE_ADDR)
#define _MCBSP_RCR1_ADDR(Port)            ((Port * 0x0400u) + _MCBSP_RCR1_BASE_ADDR)
#define _MCBSP_RCR2_ADDR(Port)            ((Port * 0x0400u) + _MCBSP_RCR2_BASE_ADDR)
#define _MCBSP_XCR1_ADDR(Port)            ((Port * 0x0400u) + _MCBSP_XCR1_BASE_ADDR)
#define _MCBSP_XCR2_ADDR(Port)            ((Port * 0x0400u) + _MCBSP_XCR2_BASE_ADDR)
#define _MCBSP_MCR1_ADDR(Port)            ((Port * 0x0400u) + _MCBSP_MCR1_BASE_ADDR)
#define _MCBSP_MCR2_ADDR(Port)            ((Port * 0x0400u) + _MCBSP_MCR2_BASE_ADDR)
#define _MCBSP_SRGR1_ADDR(Port)           ((Port * 0x0400u) + _MCBSP_SRGR1_BASE_ADDR)
#define _MCBSP_SRGR2_ADDR(Port)           ((Port * 0x0400u) + _MCBSP_SRGR2_BASE_ADDR)
#define _MCBSP_PCR_ADDR(Port)             ((Port * 0x0400u) + _MCBSP_PCR_BASE_ADDR)


#define _MCBSP_DRR1_ADDR(Port)            ((Port * 0x0400u) + _MCBSP_DRR1_BASE_ADDR)
#define _MCBSP_DRR2_ADDR(Port)            ((Port * 0x0400u) + _MCBSP_DRR2_BASE_ADDR)
#define _MCBSP_DXR1_ADDR(Port)            ((Port * 0x0400u) + _MCBSP_DXR1_BASE_ADDR)
#define _MCBSP_DXR2_ADDR(Port)            ((Port * 0x0400u) + _MCBSP_DXR2_BASE_ADDR)


#define MCBSP_ADDR(Reg)                   (_MCBSP_##Reg##_ADDR)
#define MCBSP_RGET(Reg)                    _PREG_GET(MCBSP_ADDR(##Reg))
#define MCBSP_RSET(Reg,Val)                _PREG_SET(MCBSP_ADDR(##Reg),Val)
#define MCBSP_RAOI(Reg,AND,OR,INV)         _PREG_AOI(MCBSP_ADDR(##Reg),AND,OR,INV)

#define MCBSP_FGET(Reg,Field)              _MCBSP_##Reg##_FGET(##Field)
#define MCBSP_FSET(Reg,Field,Val)          _MCBSP_##Reg##_FSET(##Field,Val)
#define MCBSP_FMK(Reg,Field,Val)           _MCBSP_##Reg##_FMK(##Field,Val)
#define MCBSP_FMKS(Reg,Field,Sym)          _MCBSP_##Reg##_FMKS(##Field,Sym)
#define MCBSP_FAOI(Reg,Field,AND,OR,INV)   _MCBSP_##Reg##_FAOI(##Field,AND,OR,INV)

#define MCBSP_ADDRH(Handle,Reg)            (_MCBSP_##Reg##_ADDR(((MCBSP_PrivateObj*)(Handle))->Port))
#define MCBSP_RGETH(Handle,Reg)             _PREG_GET(MCBSP_ADDRH(Handle,##Reg))
#define MCBSP_RSETH(Handle,Reg,Val)         _PREG_SET(MCBSP_ADDRH(Handle,##Reg),Val)
#define MCBSP_RAOIH(Handle,Reg,AND,OR,INV)  _PREG_AOI(MCBSP_ADDRH(Handle,##Reg),AND,OR,INV)

#define MCBSP_FGETH(Handle,Reg,Field)       _MCBSP_##Reg##_FGET(((MCBSP_PrivateObj*)(Handle))->Port,##Field)
#define MCBSP_FSETH(Handle,Reg,Field,Val)   _MCBSP_##Reg##_FSET(((MCBSP_PrivateObj*)(Handle))->Port,##Field,Val)
#define MCBSP_FAOIH(Reg,Field,AND,OR,INV)\
   _PFIELD_AOI(MCBSP_ADDRH(Handle,##Reg),_MCBSP_##Reg##_##Field,AND,OR,INV)

#define MCBSP_ADDR_H(Handle,Reg)            (_MCBSP_##Reg##_ADDR(((MCBSP_PrivateObj*)(Handle))->Port))
#define MCBSP_RGET_H(Handle,Reg)             _PREG_GET(MCBSP_ADDRH(Handle,##Reg))
#define MCBSP_RSET_H(Handle,Reg,Val)         _PREG_SET(MCBSP_ADDRH(Handle,##Reg),Val)
#define MCBSP_RAOI_H(Handle,Reg,AND,OR,INV)  _PREG_AOI(MCBSP_ADDRH(Handle,##Reg),AND,OR,INV)

#define MCBSP_FGET_H(Handle,Reg,Field)       _MCBSP_##Reg##_FGET(((MCBSP_PrivateObj*)(Handle))->Port,##Field)
#define MCBSP_FSET_H(Handle,Reg,Field,Val)   _MCBSP_##Reg##_FSET(((MCBSP_PrivateObj*)(Handle))->Port,##Field,Val)
#define MCBSP_FAOI_H(Reg,Field,AND,OR,INV)\
   _PFIELD_AOI(MCBSP_ADDR_H(Handle,##Reg),_MCBSP_##Reg##_##Field,AND,OR,INV)

#define _MCBSP_SPCR1_FGET(Port,Field)      _PFIELD_GET(_MCBSP_SPCR1_ADDR(Port),_MCBSP_SPCR1_##Field)
#define _MCBSP_SPCR1_FSET(Port,Field,Val)  _PFIELD_SET(_MCBSP_SPCR1_ADDR(Port),_MCBSP_SPCR1_##Field,Val)
#define _MCBSP_SPCR1_FSETS(Port,Field,Sym)\
  MCBSP_SPCR1_FSET(Port,##Field,MCBSP_SPCR1_##Field##_##Sym)

#define _MCBSP_SPCR1_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_SET(_MCBSP_SPCR1_ADDR(Port),_MCBSP_SPCR1_##Field,AND,OR,INV)
#define _MCBSP_SPCR1_FMK(Field,Val)        _MCBSP_SPCR1_##Field##_MK(Val)
#define _MCBSP_SPCR1_FMKS(Field,Sym)       _MCBSP_SPCR1_##Field##_MK(MCBSP_SPCR1_##Field##_##Sym)

#define _MCBSP_SPCR10_FGET(Field)            _MCBSP_SPCR1_FGET(0,##Field)
#define _MCBSP_SPCR11_FGET(Field)            _MCBSP_SPCR1_FGET(1,##Field)
#define _MCBSP_SPCR12_FGET(Field)            _MCBSP_SPCR1_FGET(2,##Field)
#define _MCBSP_SPCR10_FSET(Field,Val)        _MCBSP_SPCR1_FSET(0,##Field,Val)
#define _MCBSP_SPCR11_FSET(Field,Val)        _MCBSP_SPCR1_FSET(1,##Field,Val)
#define _MCBSP_SPCR12_FSET(Field,Val)        _MCBSP_SPCR1_FSET(2,##Field,Val)
#define _MCBSP_SPCR10_FSETS(Field,Sym)       _MCBSP_SPCR1_FSETS(0,##Field,Sym)
#define _MCBSP_SPCR11_FSETS(Field,Sym)       _MCBSP_SPCR1_FSETS(1,##Field,Sym)
#define _MCBSP_SPCR12_FSETS(Field,Sym)       _MCBSP_SPCR1_FSETS(2,##Field,Sym)
#define _MCBSP_SPCR10_FAOI(Field,AND,OR,INV) _MCBSP_SPCR1_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_SPCR11_FAOI(Field,AND,OR,INV) _MCBSP_SPCR1_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_SPCR12_FAOI(Field,AND,OR,INV) _MCBSP_SPCR1_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_SPCR10_FMK(Field,Val)         _MCBSP_SPCR1_##Field##_MK(Val)
#define _MCBSP_SPCR11_FMK(Field,Val)         _MCBSP_SPCR1_##Field##_MK(Val)
#define _MCBSP_SPCR12_FMK(Field,Val)         _MCBSP_SPCR1_##Field##_MK(Val)
#define _MCBSP_SPCR10_FMKS(Field,Sym)        _MCBSP_SPCR1_##Field##_MK(MCBSP_SPCR1_##Field##_##Sym)
#define _MCBSP_SPCR11_FMKS(Field,Sym)        _MCBSP_SPCR1_##Field##_MK(MCBSP_SPCR1_##Field##_##Sym)
#define _MCBSP_SPCR12_FMKS(Field,Sym)        _MCBSP_SPCR1_##Field##_MK(MCBSP_SPCR1_##Field##_##Sym)

#define _MCBSP_SPCR2_FGET(Port,Field)      _PFIELD_GET(_MCBSP_SPCR2_ADDR(Port),_MCBSP_SPCR2_##Field)
#define _MCBSP_SPCR2_FSET(Port,Field,Val)  _PFIELD_SET(_MCBSP_SPCR2_ADDR(Port),_MCBSP_SPCR2_##Field,Val)
#define _MCBSP_SPCR2_FSETS(Port,Field,Sym)\
  MCBSP_SPCR2_FSET(Port,##Field,MCBSP_SPCR2_##Field##_##Sym)

#define _MCBSP_SPCR2_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_SET(_MCBSP_SPCR2_ADDR(Port),_MCBSP_SPCR2_##Field,AND,OR,INV)
#define _MCBSP_SPCR2_FMK(Field,Val)        _MCBSP_SPCR2_##Field##_MK(Val)
#define _MCBSP_SPCR2_FMKS(Field,Sym)       _MCBSP_SPCR2_##Field##_MK(MCBSP_SPCR2_##Field##_##Sym)

#define _MCBSP_SPCR20_FGET(Field)         _MCBSP_SPCR2_FGET(0,##Field)
#define _MCBSP_SPCR21_FGET(Field)         _MCBSP_SPCR2_FGET(1,##Field)
#define _MCBSP_SPCR22_FGET(Field)         _MCBSP_SPCR2_FGET(2,##Field)
#define _MCBSP_SPCR20_FSET(Field,Val)     _MCBSP_SPCR2_FSET(0,##Field,Val)
#define _MCBSP_SPCR21_FSET(Field,Val)     _MCBSP_SPCR2_FSET(1,##Field,Val)
#define _MCBSP_SPCR22_FSET(Field,Val)     _MCBSP_SPCR2_FSET(2,##Field,Val)
#define _MCBSP_SPCR20_FSETS(Field,Sym)    _MCBSP_SPCR2_FSETS(0,##Field,Sym)
#define _MCBSP_SPCR21_FSETS(Field,Sym)    _MCBSP_SPCR2_FSETS(1,##Field,Sym)
#define _MCBSP_SPCR22_FSETS(Field,Sym)    _MCBSP_SPCR2_FSETS(2,##Field,Sym)
#define _MCBSP_SPCR20_FAOI(Field,AND,OR,INV) _MCBSP_SPCR2_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_SPCR21_FAOI(Field,AND,OR,INV) _MCBSP_SPCR2_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_SPCR22_FAOI(Field,AND,OR,INV) _MCBSP_SPCR2_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_SPCR20_FMK(Field,Val)      _MCBSP_SPCR2_##Field##_MK(Val)
#define _MCBSP_SPCR21_FMK(Field,Val)      _MCBSP_SPCR2_##Field##_MK(Val)
#define _MCBSP_SPCR22_FMK(Field,Val)      _MCBSP_SPCR2_##Field##_MK(Val)
#define _MCBSP_SPCR20_FMKS(Field,Sym)     _MCBSP_SPCR2_##Field##_MK(MCBSP_SPCR2_##Field##_##Sym)
#define _MCBSP_SPCR21_FMKS(Field,Sym)     _MCBSP_SPCR2_##Field##_MK(MCBSP_SPCR2_##Field##_##Sym)
#define _MCBSP_SPCR22_FMKS(Field,Sym)     _MCBSP_SPCR2_##Field##_MK(MCBSP_SPCR2_##Field##_##Sym)

#define _MCBSP_SRGR1_FGET(Port,Field)      _PFIELD_GET(_MCBSP_SRGR1_ADDR(Port),_MCBSP_SRGR1_##Field)
#define _MCBSP_SRGR1_FSET(Port,Field,Val)  _PFIELD_SET(_MCBSP_SRGR1_ADDR(Port),_MCBSP_SRGR1_##Field,Val)
#define _MCBSP_SRGR1_FSETS(Port,Field,Sym)\
  MCBSP_SRGR1_FSET(Port,##Field,MCBSP_SRGR1_##Field##_##Sym)

#define _MCBSP_SRGR1_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_SET(_MCBSP_SRGR1_ADDR(Port),_MCBSP_SRGR1_##Field,AND,OR,INV)
#define _MCBSP_SRGR1_FMK(Field,Val)        _MCBSP_SRGR1_##Field##_MK(Val)
#define _MCBSP_SRGR1_FMKS(Field,Sym)       _MCBSP_SRGR1_##Field##_MK(MCBSP_SRGR1_##Field##_##Sym)

#define _MCBSP_SRGR10_FGET(Field)         _MCBSP_SRGR1_FGET(0,##Field)
#define _MCBSP_SRGR11_FGET(Field)         _MCBSP_SRGR1_FGET(1,##Field)
#define _MCBSP_SRGR12_FGET(Field)         _MCBSP_SRGR1_FGET(2,##Field)
#define _MCBSP_SRGR10_FSET(Field,Val)     _MCBSP_SRGR1_FSET(0,##Field,Val)
#define _MCBSP_SRGR11_FSET(Field,Val)     _MCBSP_SRGR1_FSET(1,##Field,Val)
#define _MCBSP_SRGR12_FSET(Field,Val)     _MCBSP_SRGR1_FSET(2,##Field,Val)
#define _MCBSP_SRGR10_FSETS(Field,Sym)    _MCBSP_SRGR1_FSETS(0,##Field,Sym)
#define _MCBSP_SRGR11_FSETS(Field,Sym)    _MCBSP_SRGR1_FSETS(1,##Field,Sym)
#define _MCBSP_SRGR12_FSETS(Field,Sym)    _MCBSP_SRGR1_FSETS(2,##Field,Sym)
#define _MCBSP_SRGR10_FAOI(Field,AND,OR,INV) _MCBSP_SRGR1_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_SRGR11_FAOI(Field,AND,OR,INV) _MCBSP_SRGR1_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_SRGR12_FAOI(Field,AND,OR,INV) _MCBSP_SRGR1_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_SRGR10_FMK(Field,Val)      _MCBSP_SRGR1_##Field##_MK(Val)
#define _MCBSP_SRGR11_FMK(Field,Val)      _MCBSP_SRGR1_##Field##_MK(Val)
#define _MCBSP_SRGR12_FMK(Field,Val)      _MCBSP_SRGR1_##Field##_MK(Val)
#define _MCBSP_SRGR10_FMKS(Field,Sym)     _MCBSP_SRGR1_##Field##_MK(MCBSP_SRGR1_##Field##_##Sym)
#define _MCBSP_SRGR11_FMKS(Field,Sym)     _MCBSP_SRGR1_##Field##_MK(MCBSP_SRGR1_##Field##_##Sym)
#define _MCBSP_SRGR12_FMKS(Field,Sym)     _MCBSP_SRGR1_##Field##_MK(MCBSP_SRGR1_##Field##_##Sym)

#define _MCBSP_SRGR2_FGET(Port,Field)      _PFIELD_GET(_MCBSP_SRGR2_ADDR(Port),_MCBSP_SRGR2_##Field)
#define _MCBSP_SRGR2_FSET(Port,Field,Val)  _PFIELD_SET(_MCBSP_SRGR2_ADDR(Port),_MCBSP_SRGR2_##Field,Val)
#define _MCBSP_SRGR2_FSETS(Port,Field,Sym)\
  MCBSP_SRGR2_FSET(Port,##Field,MCBSP_SRGR2_##Field##_##Sym)

#define _MCBSP_SRGR2_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_SET(_MCBSP_SRGR2_ADDR(Port),_MCBSP_SRGR2_##Field,AND,OR,INV)
#define _MCBSP_SRGR2_FMK(Field,Val)        _MCBSP_SRGR2_##Field##_MK(Val)
#define _MCBSP_SRGR2_FMKS(Field,Sym)       _MCBSP_SRGR2_##Field##_MK(MCBSP_SRGR2_##Field##_##Sym)

#define _MCBSP_SRGR20_FGET(Field)         _MCBSP_SRGR2_FGET(0,##Field)
#define _MCBSP_SRGR21_FGET(Field)         _MCBSP_SRGR2_FGET(1,##Field)
#define _MCBSP_SRGR22_FGET(Field)         _MCBSP_SRGR2_FGET(2,##Field)
#define _MCBSP_SRGR20_FSET(Field,Val)     _MCBSP_SRGR2_FSET(0,##Field,Val)
#define _MCBSP_SRGR21_FSET(Field,Val)     _MCBSP_SRGR2_FSET(1,##Field,Val)
#define _MCBSP_SRGR22_FSET(Field,Val)     _MCBSP_SRGR2_FSET(2,##Field,Val)
#define _MCBSP_SRGR20_FSETS(Field,Sym)    _MCBSP_SRGR2_FSETS(0,##Field,Sym)
#define _MCBSP_SRGR21_FSETS(Field,Sym)    _MCBSP_SRGR2_FSETS(1,##Field,Sym)
#define _MCBSP_SRGR22_FSETS(Field,Sym)    _MCBSP_SRGR2_FSETS(2,##Field,Sym)
#define _MCBSP_SRGR20_FAOI(Field,AND,OR,INV) _MCBSP_SRGR2_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_SRGR21_FAOI(Field,AND,OR,INV) _MCBSP_SRGR2_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_SRGR22_FAOI(Field,AND,OR,INV) _MCBSP_SRGR2_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_SRGR20_FMK(Field,Val)      _MCBSP_SRGR2_##Field##_MK(Val)
#define _MCBSP_SRGR21_FMK(Field,Val)      _MCBSP_SRGR2_##Field##_MK(Val)
#define _MCBSP_SRGR22_FMK(Field,Val)      _MCBSP_SRGR2_##Field##_MK(Val)
#define _MCBSP_SRGR20_FMKS(Field,Sym)     _MCBSP_SRGR2_##Field##_MK(MCBSP_SRGR2_##Field##_##Sym)
#define _MCBSP_SRGR21_FMKS(Field,Sym)     _MCBSP_SRGR2_##Field##_MK(MCBSP_SRGR2_##Field##_##Sym)
#define _MCBSP_SRGR22_FMKS(Field,Sym)     _MCBSP_SRGR2_##Field##_MK(MCBSP_SRGR2_##Field##_##Sym)

#define _MCBSP_RCR1_FGET(Port,Field)      _PFIELD_GET(_MCBSP_RCR1_ADDR(Port),_MCBSP_RCR1_##Field)
#define _MCBSP_RCR1_FSET(Port,Field,Val)  _PFIELD_SET(_MCBSP_RCR1_ADDR(Port),_MCBSP_RCR1_##Field,Val)
#define _MCBSP_RCR1_FSETS(Port,Field,Sym)\
  MCBSP_RCR1_FSET(Port,##Field,MCBSP_RCR1_##Field##_##Sym)

#define _MCBSP_RCR1_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_SET(_MCBSP_RCR1_ADDR(Port),_MCBSP_RCR1_##Field,AND,OR,INV)
#define _MCBSP_RCR1_FMK(Field,Val)        _MCBSP_RCR1_##Field##_MK(Val)
#define _MCBSP_RCR1_FMKS(Field,Sym)       _MCBSP_RCR1_##Field##_MK(MCBSP_RCR1_##Field##_##Sym)

#define _MCBSP_RCR10_FGET(Field)         _MCBSP_RCR1_FGET(0,##Field)
#define _MCBSP_RCR11_FGET(Field)         _MCBSP_RCR1_FGET(1,##Field)
#define _MCBSP_RCR12_FGET(Field)         _MCBSP_RCR1_FGET(2,##Field)
#define _MCBSP_RCR10_FSET(Field,Val)     _MCBSP_RCR1_FSET(0,##Field,Val)
#define _MCBSP_RCR11_FSET(Field,Val)     _MCBSP_RCR1_FSET(1,##Field,Val)
#define _MCBSP_RCR12_FSET(Field,Val)     _MCBSP_RCR1_FSET(2,##Field,Val)
#define _MCBSP_RCR10_FSETS(Field,Sym)    _MCBSP_RCR1_FSETS(0,##Field,Sym)
#define _MCBSP_RCR11_FSETS(Field,Sym)    _MCBSP_RCR1_FSETS(1,##Field,Sym)
#define _MCBSP_RCR12_FSETS(Field,Sym)    _MCBSP_RCR1_FSETS(2,##Field,Sym)
#define _MCBSP_RCR10_FAOI(Field,AND,OR,INV) _MCBSP_RCR1_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_RCR11_FAOI(Field,AND,OR,INV) _MCBSP_RCR1_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_RCR12_FAOI(Field,AND,OR,INV) _MCBSP_RCR1_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_RCR10_FMK(Field,Val)      _MCBSP_RCR1_##Field##_MK(Val)
#define _MCBSP_RCR11_FMK(Field,Val)      _MCBSP_RCR1_##Field##_MK(Val)
#define _MCBSP_RCR12_FMK(Field,Val)      _MCBSP_RCR1_##Field##_MK(Val)
#define _MCBSP_RCR10_FMKS(Field,Sym)     _MCBSP_RCR1_##Field##_MK(MCBSP_RCR1_##Field##_##Sym)
#define _MCBSP_RCR11_FMKS(Field,Sym)     _MCBSP_RCR1_##Field##_MK(MCBSP_RCR1_##Field##_##Sym)
#define _MCBSP_RCR12_FMKS(Field,Sym)     _MCBSP_RCR1_##Field##_MK(MCBSP_RCR1_##Field##_##Sym)

#define _MCBSP_RCR2_FGET(Port,Field)      _PFIELD_GET(_MCBSP_RCR2_ADDR(Port),_MCBSP_RCR2_##Field)
#define _MCBSP_RCR2_FSET(Port,Field,Val)  _PFIELD_SET(_MCBSP_RCR2_ADDR(Port),_MCBSP_RCR2_##Field,Val)
#define _MCBSP_RCR2_FSETS(Port,Field,Sym)\
  MCBSP_RCR2_FSET(Port,##Field,MCBSP_RCR2_##Field##_##Sym)

#define _MCBSP_RCR2_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_SET(_MCBSP_RCR2_ADDR(Port),_MCBSP_RCR2_##Field,AND,OR,INV)
#define _MCBSP_RCR2_FMK(Field,Val)        _MCBSP_RCR2_##Field##_MK(Val)
#define _MCBSP_RCR2_FMKS(Field,Sym)       _MCBSP_RCR2_##Field##_MK(MCBSP_RCR2_##Field##_##Sym)

#define _MCBSP_RCR20_FGET(Field)         _MCBSP_RCR2_FGET(0,##Field)
#define _MCBSP_RCR21_FGET(Field)         _MCBSP_RCR2_FGET(1,##Field)
#define _MCBSP_RCR22_FGET(Field)         _MCBSP_RCR2_FGET(2,##Field)
#define _MCBSP_RCR20_FSET(Field,Val)     _MCBSP_RCR2_FSET(0,##Field,Val)
#define _MCBSP_RCR21_FSET(Field,Val)     _MCBSP_RCR2_FSET(1,##Field,Val)
#define _MCBSP_RCR22_FSET(Field,Val)     _MCBSP_RCR2_FSET(2,##Field,Val)
#define _MCBSP_RCR20_FSETS(Field,Sym)    _MCBSP_RCR2_FSETS(0,##Field,Sym)
#define _MCBSP_RCR21_FSETS(Field,Sym)    _MCBSP_RCR2_FSETS(1,##Field,Sym)
#define _MCBSP_RCR22_FSETS(Field,Sym)    _MCBSP_RCR2_FSETS(2,##Field,Sym)
#define _MCBSP_RCR20_FAOI(Field,AND,OR,INV) _MCBSP_RCR2_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_RCR21_FAOI(Field,AND,OR,INV) _MCBSP_RCR2_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_RCR22_FAOI(Field,AND,OR,INV) _MCBSP_RCR2_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_RCR20_FMK(Field,Val)      _MCBSP_RCR2_##Field##_MK(Val)
#define _MCBSP_RCR21_FMK(Field,Val)      _MCBSP_RCR2_##Field##_MK(Val)
#define _MCBSP_RCR22_FMK(Field,Val)      _MCBSP_RCR2_##Field##_MK(Val)
#define _MCBSP_RCR20_FMKS(Field,Sym)     _MCBSP_RCR2_##Field##_MK(MCBSP_RCR2_##Field##_##Sym)
#define _MCBSP_RCR21_FMKS(Field,Sym)     _MCBSP_RCR2_##Field##_MK(MCBSP_RCR2_##Field##_##Sym)
#define _MCBSP_RCR22_FMKS(Field,Sym)     _MCBSP_RCR2_##Field##_MK(MCBSP_RCR2_##Field##_##Sym)

#define _MCBSP_XCR1_FGET(Port,Field)      _PFIELD_GET(_MCBSP_XCR1_ADDR(Port),_MCBSP_XCR1_##Field)
#define _MCBSP_XCR1_FSET(Port,Field,Val)  _PFIELD_SET(_MCBSP_XCR1_ADDR(Port),_MCBSP_XCR1_##Field,Val)
#define _MCBSP_XCR1_FSETS(Port,Field,Sym)\
  MCBSP_XCR1_FSET(Port,##Field,MCBSP_XCR1_##Field##_##Sym)

#define _MCBSP_XCR1_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_SET(_MCBSP_XCR1_ADDR(Port),_MCBSP_XCR1_##Field,AND,OR,INV)
#define _MCBSP_XCR1_FMK(Field,Val)        _MCBSP_XCR1_##Field##_MK(Val)
#define _MCBSP_XCR1_FMKS(Field,Sym)       _MCBSP_XCR1_##Field##_MK(MCBSP_XCR1_##Field##_##Sym)

#define _MCBSP_XCR10_FGET(Field)         _MCBSP_XCR1_FGET(0,##Field)
#define _MCBSP_XCR11_FGET(Field)         _MCBSP_XCR1_FGET(1,##Field)
#define _MCBSP_XCR12_FGET(Field)         _MCBSP_XCR1_FGET(2,##Field)
#define _MCBSP_XCR10_FSET(Field,Val)     _MCBSP_XCR1_FSET(0,##Field,Val)
#define _MCBSP_XCR11_FSET(Field,Val)     _MCBSP_XCR1_FSET(1,##Field,Val)
#define _MCBSP_XCR12_FSET(Field,Val)     _MCBSP_XCR1_FSET(2,##Field,Val)
#define _MCBSP_XCR10_FSETS(Field,Sym)    _MCBSP_XCR1_FSETS(0,##Field,Sym)
#define _MCBSP_XCR11_FSETS(Field,Sym)    _MCBSP_XCR1_FSETS(1,##Field,Sym)
#define _MCBSP_XCR12_FSETS(Field,Sym)    _MCBSP_XCR1_FSETS(2,##Field,Sym)
#define _MCBSP_XCR10_FAOI(Field,AND,OR,INV) _MCBSP_XCR1_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_XCR11_FAOI(Field,AND,OR,INV) _MCBSP_XCR1_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_XCR12_FAOI(Field,AND,OR,INV) _MCBSP_XCR1_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_XCR10_FMK(Field,Val)      _MCBSP_XCR1_##Field##_MK(Val)
#define _MCBSP_XCR11_FMK(Field,Val)      _MCBSP_XCR1_##Field##_MK(Val)
#define _MCBSP_XCR12_FMK(Field,Val)      _MCBSP_XCR1_##Field##_MK(Val)
#define _MCBSP_XCR10_FMKS(Field,Sym)     _MCBSP_XCR1_##Field##_MK(MCBSP_XCR1_##Field##_##Sym)
#define _MCBSP_XCR11_FMKS(Field,Sym)     _MCBSP_XCR1_##Field##_MK(MCBSP_XCR1_##Field##_##Sym)
#define _MCBSP_XCR12_FMKS(Field,Sym)     _MCBSP_XCR1_##Field##_MK(MCBSP_XCR1_##Field##_##Sym)

#define _MCBSP_XCR2_FGET(Port,Field)      _PFIELD_GET(_MCBSP_XCR2_ADDR(Port),_MCBSP_XCR2_##Field)
#define _MCBSP_XCR2_FSET(Port,Field,Val)  _PFIELD_SET(_MCBSP_XCR2_ADDR(Port),_MCBSP_XCR2_##Field,Val)
#define _MCBSP_XCR2_FSETS(Port,Field,Sym)\
  MCBSP_XCR2_FSET(Port,##Field,MCBSP_XCR2_##Field##_##Sym)

#define _MCBSP_XCR2_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_SET(_MCBSP_XCR2_ADDR(Port),_MCBSP_XCR2_##Field,AND,OR,INV)
#define _MCBSP_XCR2_FMK(Field,Val)        _MCBSP_XCR2_##Field##_MK(Val)
#define _MCBSP_XCR2_FMKS(Field,Sym)       _MCBSP_XCR2_##Field##_MK(MCBSP_XCR2_##Field##_##Sym)

#define _MCBSP_XCR20_FGET(Field)         _MCBSP_XCR2_FGET(0,##Field)
#define _MCBSP_XCR21_FGET(Field)         _MCBSP_XCR2_FGET(1,##Field)
#define _MCBSP_XCR22_FGET(Field)         _MCBSP_XCR2_FGET(2,##Field)
#define _MCBSP_XCR20_FSET(Field,Val)     _MCBSP_XCR2_FSET(0,##Field,Val)
#define _MCBSP_XCR21_FSET(Field,Val)     _MCBSP_XCR2_FSET(1,##Field,Val)
#define _MCBSP_XCR22_FSET(Field,Val)     _MCBSP_XCR2_FSET(2,##Field,Val)
#define _MCBSP_XCR20_FSETS(Field,Sym)    _MCBSP_XCR2_FSETS(0,##Field,Sym)
#define _MCBSP_XCR21_FSETS(Field,Sym)    _MCBSP_XCR2_FSETS(1,##Field,Sym)
#define _MCBSP_XCR22_FSETS(Field,Sym)    _MCBSP_XCR2_FSETS(2,##Field,Sym)
#define _MCBSP_XCR20_FAOI(Field,AND,OR,INV) _MCBSP_XCR2_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_XCR21_FAOI(Field,AND,OR,INV) _MCBSP_XCR2_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_XCR22_FAOI(Field,AND,OR,INV) _MCBSP_XCR2_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_XCR20_FMK(Field,Val)      _MCBSP_XCR2_##Field##_MK(Val)
#define _MCBSP_XCR21_FMK(Field,Val)      _MCBSP_XCR2_##Field##_MK(Val)
#define _MCBSP_XCR22_FMK(Field,Val)      _MCBSP_XCR2_##Field##_MK(Val)
#define _MCBSP_XCR20_FMKS(Field,Sym)     _MCBSP_XCR2_##Field##_MK(MCBSP_XCR2_##Field##_##Sym)
#define _MCBSP_XCR21_FMKS(Field,Sym)     _MCBSP_XCR2_##Field##_MK(MCBSP_XCR2_##Field##_##Sym)
#define _MCBSP_XCR22_FMKS(Field,Sym)     _MCBSP_XCR2_##Field##_MK(MCBSP_XCR2_##Field##_##Sym)


#define _MCBSP_MCR1_FGET(Port,Field)      _PFIELD_GET(_MCBSP_MCR1_ADDR(Port),_MCBSP_MCR1_##Field)
#define _MCBSP_MCR1_FSET(Port,Field,Val)  _PFIELD_SET(_MCBSP_MCR1_ADDR(Port),_MCBSP_MCR1_##Field,Val)
#define _MCBSP_MCR1_FSETS(Port,Field,Sym)\
  MCBSP_MCR1_FSET(Port,##Field,MCBSP_MCR1_##Field##_##Sym)

#define _MCBSP_MCR1_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_SET(_MCBSP_MCR1_ADDR(Port),_MCBSP_MCR1_##Field,AND,OR,INV)
#define _MCBSP_MCR1_FMK(Field,Val)        _MCBSP_MCR1_##Field##_MK(Val)
#define _MCBSP_MCR1_FMKS(Field,Sym)       _MCBSP_MCR1_##Field##_MK(MCBSP_MCR1_##Field##_##Sym)

#define _MCBSP_MCR10_FGET(Field)         _MCBSP_MCR1_FGET(0,##Field)
#define _MCBSP_MCR11_FGET(Field)         _MCBSP_MCR1_FGET(1,##Field)
#define _MCBSP_MCR12_FGET(Field)         _MCBSP_MCR1_FGET(2,##Field)
#define _MCBSP_MCR10_FSET(Field,Val)     _MCBSP_MCR1_FSET(0,##Field,Val)
#define _MCBSP_MCR11_FSET(Field,Val)     _MCBSP_MCR1_FSET(1,##Field,Val)
#define _MCBSP_MCR12_FSET(Field,Val)     _MCBSP_MCR1_FSET(2,##Field,Val)
#define _MCBSP_MCR10_FSETS(Field,Sym)    _MCBSP_MCR1_FSET(0,##Field,Sym)
#define _MCBSP_MCR11_FSETS(Field,Sym)    _MCBSP_MCR1_FSET(1,##Field,Sym)
#define _MCBSP_MCR12_FSETS(Field,Sym)    _MCBSP_MCR1_FSET(2,##Field,Sym)
#define _MCBSP_MCR10_FAOI(Field,AND,OR,INV) _MCBSP_MCR_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_MCR11_FAOI(Field,AND,OR,INV) _MCBSP_MCR_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_MCR12_FAOI(Field,AND,OR,INV) _MCBSP_MCR_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_MCR10_FMK(Field,Val)      _MCBSP_MCR1_##Field##_MK(Val)
#define _MCBSP_MCR11_FMK(Field,Val)      _MCBSP_MCR1_##Field##_MK(Val)
#define _MCBSP_MCR12_FMK(Field,Val)      _MCBSP_MCR1_##Field##_MK(Val)
#define _MCBSP_MCR10_FMKS(Field,Sym)     _MCBSP_MCR1_##Field##_MK(MCBSP_MCR1_##Field##_##Sym)
#define _MCBSP_MCR11_FMKS(Field,Sym)     _MCBSP_MCR1_##Field##_MK(MCBSP_MCR1_##Field##_##Sym)
#define _MCBSP_MCR12_FMKS(Field,Sym)     _MCBSP_MCR1_##Field##_MK(MCBSP_MCR1_##Field##_##Sym)


#define _MCBSP_MCR2_FGET(Port,Field)      _PFIELD_GET(_MCBSP_MCR2_ADDR(Port),_MCBSP_MCR2_##Field)
#define _MCBSP_MCR2_FSET(Port,Field,Val)  _PFIELD_SET(_MCBSP_MCR2_ADDR(Port),_MCBSP_MCR2_##Field,Val)
#define _MCBSP_MCR2_FSETS(Port,Field,Sym)\
  MCBSP_MCR2_FSET(Port,##Field,MCBSP_MCR2_##Field##_##Sym)

#define _MCBSP_MCR2_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_SET(_MCBSP_MCR2_ADDR(Port),_MCBSP_MCR2_##Field,AND,OR,INV)
#define _MCBSP_MCR2_FMK(Field,Val)        _MCBSP_MCR2_##Field##_MK(Val)
#define _MCBSP_MCR2_FMKS(Field,Sym)       _MCBSP_MCR2_##Field##_MK(MCBSP_MCR2_##Field##_##Sym)

#define _MCBSP_MCR20_FGET(Field)         _MCBSP_MCR2_FGET(0,##Field)
#define _MCBSP_MCR21_FGET(Field)         _MCBSP_MCR2_FGET(1,##Field)
#define _MCBSP_MCR22_FGET(Field)         _MCBSP_MCR2_FGET(2,##Field)
#define _MCBSP_MCR20_FSET(Field,Val)     _MCBSP_MCR2_FSET(0,##Field,Val)
#define _MCBSP_MCR21_FSET(Field,Val)     _MCBSP_MCR2_FSET(1,##Field,Val)
#define _MCBSP_MCR22_FSET(Field,Val)     _MCBSP_MCR2_FSET(2,##Field,Val)
#define _MCBSP_MCR20_FSETS(Field,Sym)    _MCBSP_MCR2_FSETS(0,##Field,Sym)
#define _MCBSP_MCR21_FSETS(Field,Sym)    _MCBSP_MCR2_FSETS(1,##Field,Sym)
#define _MCBSP_MCR22_FSETS(Field,Sym)    _MCBSP_MCR2_FSETS(2,##Field,Sym)
#define _MCBSP_MCR20_FAOI(Field,AND,OR,INV) _MCBSP_MCR_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_MCR21_FAOI(Field,AND,OR,INV) _MCBSP_MCR_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_MCR22_FAOI(Field,AND,OR,INV) _MCBSP_MCR_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_MCR20_FMK(Field,Val)      _MCBSP_MCR2_##Field##_MK(Val)
#define _MCBSP_MCR21_FMK(Field,Val)      _MCBSP_MCR2_##Field##_MK(Val)
#define _MCBSP_MCR22_FMK(Field,Val)      _MCBSP_MCR2_##Field##_MK(Val)
#define _MCBSP_MCR20_FMKS(Field,Sym)     _MCBSP_MCR2_##Field##_MK(MCBSP_MCR2_##Field##_##Sym)
#define _MCBSP_MCR21_FMKS(Field,Sym)     _MCBSP_MCR2_##Field##_MK(MCBSP_MCR2_##Field##_##Sym)
#define _MCBSP_MCR22_FMKS(Field,Sym)     _MCBSP_MCR2_##Field##_MK(MCBSP_MCR2_##Field##_##Sym)


#define _MCBSP_PCR_FGET(Port,Field)      _PFIELD_GET(_MCBSP_PCR_ADDR(Port),_MCBSP_PCR_##Field)
#define _MCBSP_PCR_FSET(Port,Field,Val)  _PFIELD_SET(_MCBSP_PCR_ADDR(Port),_MCBSP_PCR_##Field,Val)
#define _MCBSP_PCR_FSETS(Port,Field,Sym)\
  MCBSP_PCR_FSET(Port,##Field,MCBSP_PCR_##Field##_##Sym)

#define _MCBSP_PCR_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_SET(_MCBSP_PCR_ADDR(Port),_MCBSP_PCR_##Field,AND,OR,INV)
#define _MCBSP_PCR_FMK(Field,Val)        _MCBSP_PCR_##Field##_MK(Val)
#define _MCBSP_PCR_FMKS(Field,Sym)       _MCBSP_PCR_##Field##_MK(MCBSP_PCR_##Field##_##Sym)

#define _MCBSP_PCR0_FGET(Field)            _MCBSP_PCR_FGET(0,##Field)
#define _MCBSP_PCR1_FGET(Field)            _MCBSP_PCR_FGET(1,##Field)
#define _MCBSP_PCR2_FGET(Field)            _MCBSP_PCR_FGET(2,##Field)
#define _MCBSP_PCR0_FSET(Field,Val)        _MCBSP_PCR_FSET(0,##Field,Val)
#define _MCBSP_PCR1_FSET(Field,Val)        _MCBSP_PCR_FSET(1,##Field,Val)
#define _MCBSP_PCR2_FSET(Field,Val)        _MCBSP_PCR_FSET(2,##Field,Val)
#define _MCBSP_PCR0_FSETS(Field,Sym)       _MCBSP_PCR_FSET(0,##Field,Sym)
#define _MCBSP_PCR1_FSETS(Field,Sym)       _MCBSP_PCR_FSET(1,##Field,Sym)
#define _MCBSP_PCR2_FSETS(Field,Sym)       _MCBSP_PCR_FSET(2,##Field,Sym)
#define _MCBSP_PCR0_FAOI(Field,AND,OR,INV) _MCBSP_PCR_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_PCR1_FAOI(Field,AND,OR,INV) _MCBSP_PCR_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_PCR2_FAOI(Field,AND,OR,INV) _MCBSP_PCR_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_PCR0_FMK(Field,Val)         _MCBSP_PCR_##Field##_MK(Val)
#define _MCBSP_PCR1_FMK(Field,Val)         _MCBSP_PCR_##Field##_MK(Val)
#define _MCBSP_PCR2_FMK(Field,Val)         _MCBSP_PCR_##Field##_MK(Val)
#define _MCBSP_PCR0_FMKS(Field,Sym)        _MCBSP_PCR_##Field##_MK(MCBSP_PCR_##Field##_##Sym)
#define _MCBSP_PCR1_FMKS(Field,Sym)        _MCBSP_PCR_##Field##_MK(MCBSP_PCR_##Field##_##Sym)
#define _MCBSP_PCR2_FMKS(Field,Sym)        _MCBSP_PCR_##Field##_MK(MCBSP_PCR_##Field##_##Sym)

#define _MCBSP_RCERA_FGET(Port,Field)     _PFIELD_GET(_MCBSP_RCERA_ADDR(Port),_MCBSP_RCER_##Field)
#define _MCBSP_RCERA_FSET(Port,Field,Val) _PFIELD_SET(_MCBSP_RCERA_ADDR(Port),_MCBSP_RCER_##Field,Val)
#define _MCBSP_RCERA_FSETS(Port,Field,Sym)\
  _PFIELD_SET(_MCBSP_RCERA_ADDR(Port),_MCBSP_RCER_##Field,MCBSP_RCER_##Field##_##Sym)
#define _MCBSP_RCERA_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_AOI(_MCBSP_RCERA_ADDR(Port),_MCBSP_RCER_##Field,AND,OR,INV)

#define _MCBSP_RCERA_FMK(Field,Val)          _MCBSP_RCER_##Field##_MK(Val)
#define _MCBSP_RCERA_FMKS(Field,Sym)         _MCBSP_RCER_##Field##_MK(MCBSP_RCER_##Field##_##Sym)

#define _MCBSP_RCERA0_FGET(Field)            _MCBSP_RCERA_FGET(0,##Field)
#define _MCBSP_RCERA1_FGET(Field)            _MCBSP_RCERA_FGET(1,##Field)
#define _MCBSP_RCERA2_FGET(Field)            _MCBSP_RCERA_FGET(2,##Field)
#define _MCBSP_RCERA0_FSET(Field,Val)        _MCBSP_RCERA_FSET(0,##Field,Val)
#define _MCBSP_RCERA1_FSET(Field,Val)        _MCBSP_RCERA_FSET(1,##Field,Val)
#define _MCBSP_RCERA2_FSET(Field,Val)        _MCBSP_RCERA_FSET(2,##Field,Val)
#define _MCBSP_RCERA0_FSETS(Field,Sym)       _MCBSP_RCERA_FSETS(0,##Field,Sym)
#define _MCBSP_RCERA1_FSETS(Field,Sym)       _MCBSP_RCERA_FSETS(1,##Field,Sym)
#define _MCBSP_RCERA2_FSETS(Field,Sym)       _MCBSP_RCERA_FSETS(2,##Field,Sym)
#define _MCBSP_RCERA0_FAOI(Field,AND,OR,INV) _MCBSP_RCERA_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_RCERA1_FAOI(Field,AND,OR,INV) _MCBSP_RCERA_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_RCERA2_FAOI(Field,AND,OR,INV) _MCBSP_RCERA_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_RCERA0_FMK(Field,Val)         _MCBSP_RCERA_FMK(##Field,Val)
#define _MCBSP_RCERA1_FMK(Field,Val)         _MCBSP_RCERA_FMK(##Field,Val)
#define _MCBSP_RCERA2_FMK(Field,Val)         _MCBSP_RCERA_FMK(##Field,Val)
#define _MCBSP_RCERA0_FMKS(Field,Sym)        _MCBSP_RCERA_FMKS(##Field,Sym)
#define _MCBSP_RCERA1_FMKS(Field,Sym)        _MCBSP_RCERA_FMKS(##Field,Sym)
#define _MCBSP_RCERA2_FMKS(Field,Sym)        _MCBSP_RCERA_FMKS(##Field,Sym)

#define _MCBSP_RCERB_FGET(Port,Field)     _PFIELD_GET(_MCBSP_RCERB_ADDR(Port),_MCBSP_RCER_##Field)
#define _MCBSP_RCERB_FSET(Port,Field,Val) _PFIELD_SET(_MCBSP_RCERB_ADDR(Port),_MCBSP_RCER_##Field,Val)
#define _MCBSP_RCERB_FSETS(Port,Field,Sym)\
  _PFIELD_SET(_MCBSP_RCERB_ADDR(Port),_MCBSP_RCER_##Field,MCBSP_RCER_##Field##_##Sym)
#define _MCBSP_RCERB_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_AOI(_MCBSP_RCERB_ADDR(Port),_MCBSP_RCER_##Field,AND,OR,INV)
#define _MCBSP_RCERB_FMK(Field,Val)          _MCBSP_RCER_##Field##_MK(Val)
#define _MCBSP_RCERB_FMKS(Field,Sym)         _MCBSP_RCER_##Field##_MK(MCBSP_RCER_##Field##_##Sym)

#define _MCBSP_RCERB0_FGET(Field)            _MCBSP_RCERB_FGET(0,##Field)
#define _MCBSP_RCERB1_FGET(Field)            _MCBSP_RCERB_FGET(1,##Field)
#define _MCBSP_RCERB2_FGET(Field)            _MCBSP_RCERB_FGET(2,##Field)
#define _MCBSP_RCERB0_FSET(Field,Val)        _MCBSP_RCERB_FSET(0,##Field,Val)
#define _MCBSP_RCERB1_FSET(Field,Val)        _MCBSP_RCERB_FSET(1,##Field,Val)
#define _MCBSP_RCERB2_FSET(Field,Val)        _MCBSP_RCERB_FSET(2,##Field,Val)
#define _MCBSP_RCERB0_FSETS(Field,Sym)       _MCBSP_RCERB_FSETS(0,##Field,Sym)
#define _MCBSP_RCERB1_FSETS(Field,Sym)       _MCBSP_RCERB_FSETS(1,##Field,Sym)
#define _MCBSP_RCERB2_FSETS(Field,Sym)       _MCBSP_RCERB_FSETS(2,##Field,Sym)
#define _MCBSP_RCERB0_FAOI(Field,AND,OR,INV) _MCBSP_RCERB_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_RCERB1_FAOI(Field,AND,OR,INV) _MCBSP_RCERB_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_RCERB2_FAOI(Field,AND,OR,INV) _MCBSP_RCERB_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_RCERB0_FMK(Field,Val)         _MCBSP_RCERB_FMK(##Field,Val)
#define _MCBSP_RCERB1_FMK(Field,Val)         _MCBSP_RCERB_FMK(##Field,Val)
#define _MCBSP_RCERB2_FMK(Field,Val)         _MCBSP_RCERB_FMK(##Field,Val)
#define _MCBSP_RCERB0_FMKS(Field,Sym)        _MCBSP_RCERB_FMKS(##Field,Sym)
#define _MCBSP_RCERB1_FMKS(Field,Sym)        _MCBSP_RCERB_FMKS(##Field,Sym)
#define _MCBSP_RCERB2_FMKS(Field,Sym)        _MCBSP_RCERB_FMKS(##Field,Sym)

#define _MCBSP_RCERC_FGET(Port,Field)     _PFIELD_GET(_MCBSP_RCERC_ADDR(Port),_MCBSP_RCER_##Field)
#define _MCBSP_RCERC_FSET(Port,Field,Val) _PFIELD_SET(_MCBSP_RCERC_ADDR(Port),_MCBSP_RCER_##Field,Val)
#define _MCBSP_RCERC_FSETS(Port,Field,Sym)\
  _PFIELD_SET(_MCBSP_RCERC_ADDR(Port),_MCBSP_RCER_##Field,MCBSP_RCER_##Field##_##Sym)
#define _MCBSP_RCERC_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_AOI(_MCBSP_RCERC_ADDR(Port),_MCBSP_RCER_##Field,AND,OR,INV)
#define _MCBSP_RCERC_FMK(Field,Val)          _MCBSP_RCER_##Field##_MK(Val)
#define _MCBSP_RCERC_FMKS(Field,Sym)         _MCBSP_RCER_##Field##_MK(MCBSP_RCER_##Field##_##Sym)

#define _MCBSP_RCERC0_FGET(Field)            _MCBSP_RCERC_FGET(0,##Field)
#define _MCBSP_RCERC1_FGET(Field)            _MCBSP_RCERC_FGET(1,##Field)
#define _MCBSP_RCERC2_FGET(Field)            _MCBSP_RCERC_FGET(2,##Field)
#define _MCBSP_RCERC0_FSET(Field,Val)        _MCBSP_RCERC_FSET(0,##Field,Val)
#define _MCBSP_RCERC1_FSET(Field,Val)        _MCBSP_RCERC_FSET(1,##Field,Val)
#define _MCBSP_RCERC2_FSET(Field,Val)        _MCBSP_RCERC_FSET(2,##Field,Val)
#define _MCBSP_RCERC0_FSETS(Field,Sym)       _MCBSP_RCERC_FSETS(0,##Field,Sym)
#define _MCBSP_RCERC1_FSETS(Field,Sym)       _MCBSP_RCERC_FSETS(1,##Field,Sym)
#define _MCBSP_RCERC2_FSETS(Field,Sym)       _MCBSP_RCERC_FSETS(2,##Field,Sym)
#define _MCBSP_RCERC0_FAOI(Field,AND,OR,INV) _MCBSP_RCERC_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_RCERC1_FAOI(Field,AND,OR,INV) _MCBSP_RCERC_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_RCERC2_FAOI(Field,AND,OR,INV) _MCBSP_RCERC_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_RCERC0_FMK(Field,Val)         _MCBSP_RCERC_FMK(##Field,Val)
#define _MCBSP_RCERC1_FMK(Field,Val)         _MCBSP_RCERC_FMK(##Field,Val)
#define _MCBSP_RCERC2_FMK(Field,Val)         _MCBSP_RCERC_FMK(##Field,Val)
#define _MCBSP_RCERC0_FMKS(Field,Sym)        _MCBSP_RCERC_FMKS(##Field,Sym)
#define _MCBSP_RCERC1_FMKS(Field,Sym)        _MCBSP_RCERC_FMKS(##Field,Sym)
#define _MCBSP_RCERC2_FMKS(Field,Sym)        _MCBSP_RCERC_FMKS(##Field,Sym)


#define _MCBSP_RCERD_FGET(Port,Field)     _PFIELD_GET(_MCBSP_RCERD_ADDR(Port),_MCBSP_RCER_##Field)
#define _MCBSP_RCERD_FSET(Port,Field,Val) _PFIELD_SET(_MCBSP_RCERD_ADDR(Port),_MCBSP_RCER_##Field,Val)
#define _MCBSP_RCERD_FSETS(Port,Field,Sym)\
  _PFIELD_SET(_MCBSP_RCERD_ADDR(Port),_MCBSP_RCER_##Field,MCBSP_RCER_##Field##_##Sym)
#define _MCBSP_RCERD_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_AOI(_MCBSP_RCERD_ADDR(Port),_MCBSP_RCER_##Field,AND,OR,INV)
#define _MCBSP_RCERD_FMK(Field,Val)          _MCBSP_RCER_##Field##_MK(Val)
#define _MCBSP_RCERD_FMKS(Field,Sym)         _MCBSP_RCER_##Field##_MK(MCBSP_RCER_##Field##_##Sym)

#define _MCBSP_RCERD0_FGET(Field)            _MCBSP_RCERD_FGET(0,##Field)
#define _MCBSP_RCERD1_FGET(Field)            _MCBSP_RCERD_FGET(1,##Field)
#define _MCBSP_RCERD2_FGET(Field)            _MCBSP_RCERD_FGET(2,##Field)
#define _MCBSP_RCERD0_FSET(Field,Val)        _MCBSP_RCERD_FSET(0,##Field,Val)
#define _MCBSP_RCERD1_FSET(Field,Val)        _MCBSP_RCERD_FSET(1,##Field,Val)
#define _MCBSP_RCERD2_FSET(Field,Val)        _MCBSP_RCERD_FSET(2,##Field,Val)
#define _MCBSP_RCERD0_FSETS(Field,Sym)       _MCBSP_RCERD_FSETS(0,##Field,Sym)
#define _MCBSP_RCERD1_FSETS(Field,Sym)       _MCBSP_RCERD_FSETS(1,##Field,Sym)
#define _MCBSP_RCERD2_FSETS(Field,Sym)       _MCBSP_RCERD_FSETS(2,##Field,Sym)
#define _MCBSP_RCERD0_FAOI(Field,AND,OR,INV) _MCBSP_RCERD_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_RCERD1_FAOI(Field,AND,OR,INV) _MCBSP_RCERD_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_RCERD2_FAOI(Field,AND,OR,INV) _MCBSP_RCERD_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_RCERD0_FMK(Field,Val)         _MCBSP_RCERD_FMK(##Field,Val)
#define _MCBSP_RCERD1_FMK(Field,Val)         _MCBSP_RCERD_FMK(##Field,Val)
#define _MCBSP_RCERD2_FMK(Field,Val)         _MCBSP_RCERD_FMK(##Field,Val)
#define _MCBSP_RCERD0_FMKS(Field,Sym)        _MCBSP_RCERD_FMKS(##Field,Sym)
#define _MCBSP_RCERD1_FMKS(Field,Sym)        _MCBSP_RCERD_FMKS(##Field,Sym)
#define _MCBSP_RCERD2_FMKS(Field,Sym)        _MCBSP_RCERD_FMKS(##Field,Sym)


#define _MCBSP_RCERE_FGET(Port,Field)     _PFIELD_GET(_MCBSP_RCERE_ADDR(Port),_MCBSP_RCER_##Field)
#define _MCBSP_RCERE_FSET(Port,Field,Val) _PFIELD_SET(_MCBSP_RCERE_ADDR(Port),_MCBSP_RCER_##Field,Val)
#define _MCBSP_RCERE_FSETS(Port,Field,Sym)\
  _PFIELD_SET(_MCBSP_RCERE_ADDR(Port),_MCBSP_RCER_##Field,MCBSP_RCER_##Field##_##Sym)
#define _MCBSP_RCERE_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_AOI(_MCBSP_RCERE_ADDR(Port),_MCBSP_RCER_##Field,AND,OR,INV)
#define _MCBSP_RCERE_FMK(Field,Val)          _MCBSP_RCER_##Field##_MK(Val)
#define _MCBSP_RCERE_FMKS(Field,Sym)         _MCBSP_RCER_##Field##_MK(MCBSP_RCER_##Field##_##Sym)

#define _MCBSP_RCERE0_FGET(Field)            _MCBSP_RCERE_FGET(0,##Field)
#define _MCBSP_RCERE1_FGET(Field)            _MCBSP_RCERE_FGET(1,##Field)
#define _MCBSP_RCERE2_FGET(Field)            _MCBSP_RCERE_FGET(2,##Field)
#define _MCBSP_RCERE0_FSET(Field,Val)        _MCBSP_RCERE_FSET(0,##Field,Val)
#define _MCBSP_RCERE1_FSET(Field,Val)        _MCBSP_RCERE_FSET(1,##Field,Val)
#define _MCBSP_RCERE2_FSET(Field,Val)        _MCBSP_RCERE_FSET(2,##Field,Val)
#define _MCBSP_RCERE0_FSETS(Field,Sym)       _MCBSP_RCERE_FSETS(0,##Field,Sym)
#define _MCBSP_RCERE1_FSETS(Field,Sym)       _MCBSP_RCERE_FSETS(1,##Field,Sym)
#define _MCBSP_RCERE2_FSETS(Field,Sym)       _MCBSP_RCERE_FSETS(2,##Field,Sym)
#define _MCBSP_RCERE0_FAOI(Field,AND,OR,INV) _MCBSP_RCERE_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_RCERE1_FAOI(Field,AND,OR,INV) _MCBSP_RCERE_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_RCERE2_FAOI(Field,AND,OR,INV) _MCBSP_RCERE_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_RCERE0_FMK(Field,Val)         _MCBSP_RCERE_FMK(##Field,Val)
#define _MCBSP_RCERE1_FMK(Field,Val)         _MCBSP_RCERE_FMK(##Field,Val)
#define _MCBSP_RCERE2_FMK(Field,Val)         _MCBSP_RCERE_FMK(##Field,Val)
#define _MCBSP_RCERE0_FMKS(Field,Sym)        _MCBSP_RCERE_FMKS(##Field,Sym)
#define _MCBSP_RCERE1_FMKS(Field,Sym)        _MCBSP_RCERE_FMKS(##Field,Sym)
#define _MCBSP_RCERE2_FMKS(Field,Sym)        _MCBSP_RCERE_FMKS(##Field,Sym)

#define _MCBSP_RCERF_FGET(Port,Field)     _PFIELD_GET(_MCBSP_RCERF_ADDR(Port),_MCBSP_RCER_##Field)
#define _MCBSP_RCERF_FSET(Port,Field,Val) _PFIELD_SET(_MCBSP_RCERF_ADDR(Port),_MCBSP_RCER_##Field,Val)
#define _MCBSP_RCERF_FSETS(Port,Field,Sym)\
  _PFIELD_SET(_MCBSP_RCERF_ADDR(Port),_MCBSP_RCER_##Field,MCBSP_RCER_##Field##_##Sym)
#define _MCBSP_RCERF_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_AOI(_MCBSP_RCERF_ADDR(Port),_MCBSP_RCER_##Field,AND,OR,INV)
#define _MCBSP_RCERF_FMK(Field,Val)          _MCBSP_RCER_##Field##_MK(Val)
#define _MCBSP_RCERF_FMKS(Field,Sym)         _MCBSP_RCER_##Field##_MK(MCBSP_RCER_##Field##_##Sym)

#define _MCBSP_RCERF0_FGET(Field)            _MCBSP_RCERF_FGET(0,##Field)
#define _MCBSP_RCERF1_FGET(Field)            _MCBSP_RCERF_FGET(1,##Field)
#define _MCBSP_RCERF2_FGET(Field)            _MCBSP_RCERF_FGET(2,##Field)
#define _MCBSP_RCERF0_FSET(Field,Val)        _MCBSP_RCERF_FSET(0,##Field,Val)
#define _MCBSP_RCERF1_FSET(Field,Val)        _MCBSP_RCERF_FSET(1,##Field,Val)
#define _MCBSP_RCERF2_FSET(Field,Val)        _MCBSP_RCERF_FSET(2,##Field,Val)
#define _MCBSP_RCERF0_FSETS(Field,Sym)       _MCBSP_RCERF_FSETS(0,##Field,Sym)
#define _MCBSP_RCERF1_FSETS(Field,Sym)       _MCBSP_RCERF_FSETS(1,##Field,Sym)
#define _MCBSP_RCERF2_FSETS(Field,Sym)       _MCBSP_RCERF_FSETS(2,##Field,Sym)
#define _MCBSP_RCERF0_FAOI(Field,AND,OR,INV) _MCBSP_RCERF_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_RCERF1_FAOI(Field,AND,OR,INV) _MCBSP_RCERF_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_RCERF2_FAOI(Field,AND,OR,INV) _MCBSP_RCERF_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_RCERF0_FMK(Field,Val)         _MCBSP_RCERF_FMK(##Field,Val)
#define _MCBSP_RCERF1_FMK(Field,Val)         _MCBSP_RCERF_FMK(##Field,Val)
#define _MCBSP_RCERF2_FMK(Field,Val)         _MCBSP_RCERF_FMK(##Field,Val)
#define _MCBSP_RCERF0_FMKS(Field,Sym)        _MCBSP_RCERF_FMKS(##Field,Sym)
#define _MCBSP_RCERF1_FMKS(Field,Sym)        _MCBSP_RCERF_FMKS(##Field,Sym)
#define _MCBSP_RCERF2_FMKS(Field,Sym)        _MCBSP_RCERF_FMKS(##Field,Sym)


#define _MCBSP_RCERG_FGET(Port,Field)     _PFIELD_GET(_MCBSP_RCERG_ADDR(Port),_MCBSP_RCER_##Field)
#define _MCBSP_RCERG_FSET(Port,Field,Val) _PFIELD_SET(_MCBSP_RCERG_ADDR(Port),_MCBSP_RCER_##Field,Val)
#define _MCBSP_RCERG_FSETS(Port,Field,Sym)\
  _PFIELD_SET(_MCBSP_RCERG_ADDR(Port),_MCBSP_RCER_##Field,MCBSP_RCER_##Field##_##Sym)
#define _MCBSP_RCERG_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_AOI(_MCBSP_RCERG_ADDR(Port),_MCBSP_RCER_##Field,AND,OR,INV)
#define _MCBSP_RCERG_FMK(Field,Val)          _MCBSP_RCER_##Field##_MK(Val)
#define _MCBSP_RCERG_FMKS(Field,Sym)         _MCBSP_RCER_##Field##_MK(MCBSP_RCER_##Field##_##Sym)

#define _MCBSP_RCERG0_FGET(Field)            _MCBSP_RCERG_FGET(0,##Field)
#define _MCBSP_RCERG1_FGET(Field)            _MCBSP_RCERG_FGET(1,##Field)
#define _MCBSP_RCERG2_FGET(Field)            _MCBSP_RCERG_FGET(2,##Field)
#define _MCBSP_RCERG0_FSET(Field,Val)        _MCBSP_RCERG_FSET(0,##Field,Val)
#define _MCBSP_RCERG1_FSET(Field,Val)        _MCBSP_RCERG_FSET(1,##Field,Val)
#define _MCBSP_RCERG2_FSET(Field,Val)        _MCBSP_RCERG_FSET(2,##Field,Val)
#define _MCBSP_RCERG0_FSETS(Field,Sym)       _MCBSP_RCERG_FSETS(0,##Field,Sym)
#define _MCBSP_RCERG1_FSETS(Field,Sym)       _MCBSP_RCERG_FSETS(1,##Field,Sym)
#define _MCBSP_RCERG2_FSETS(Field,Sym)       _MCBSP_RCERG_FSETS(2,##Field,Sym)
#define _MCBSP_RCERG0_FAOI(Field,AND,OR,INV) _MCBSP_RCERG_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_RCERG1_FAOI(Field,AND,OR,INV) _MCBSP_RCERG_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_RCERG2_FAOI(Field,AND,OR,INV) _MCBSP_RCERG_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_RCERG0_FMK(Field,Val)         _MCBSP_RCERG_FMK(##Field,Val)
#define _MCBSP_RCERG1_FMK(Field,Val)         _MCBSP_RCERG_FMK(##Field,Val)
#define _MCBSP_RCERG2_FMK(Field,Val)         _MCBSP_RCERG_FMK(##Field,Val)
#define _MCBSP_RCERG0_FMKS(Field,Sym)        _MCBSP_RCERG_FMKS(##Field,Sym)
#define _MCBSP_RCERG1_FMKS(Field,Sym)        _MCBSP_RCERG_FMKS(##Field,Sym)
#define _MCBSP_RCERG2_FMKS(Field,Sym)        _MCBSP_RCERG_FMKS(##Field,Sym)


#define _MCBSP_RCERH_FGET(Port,Field)     _PFIELD_GET(_MCBSP_RCERH_ADDR(Port),_MCBSP_RCER_##Field)
#define _MCBSP_RCERH_FSET(Port,Field,Val) _PFIELD_SET(_MCBSP_RCERH_ADDR(Port),_MCBSP_RCER_##Field,Val)
#define _MCBSP_RCERH_FSETS(Port,Field,Sym)\
  _PFIELD_SET(_MCBSP_RCERH_ADDR(Port),_MCBSP_RCER_##Field,MCBSP_RCER_##Field##_##Sym)
#define _MCBSP_RCERH_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_AOI(_MCBSP_RCERH_ADDR(Port),_MCBSP_RCER_##Field,AND,OR,INV)
#define _MCBSP_RCERH_FMK(Field,Val)          _MCBSP_RCER_##Field##_MK(Val)
#define _MCBSP_RCERH_FMKS(Field,Sym)         _MCBSP_RCER_##Field##_MK(MCBSP_RCER_##Field##_##Sym)

#define _MCBSP_RCERH0_FGET(Field)            _MCBSP_RCERH_FGET(0,##Field)
#define _MCBSP_RCERH1_FGET(Field)            _MCBSP_RCERH_FGET(1,##Field)
#define _MCBSP_RCERH2_FGET(Field)            _MCBSP_RCERH_FGET(2,##Field)
#define _MCBSP_RCERH0_FSET(Field,Val)        _MCBSP_RCERH_FSET(0,##Field,Val)
#define _MCBSP_RCERH1_FSET(Field,Val)        _MCBSP_RCERH_FSET(1,##Field,Val)
#define _MCBSP_RCERH2_FSET(Field,Val)        _MCBSP_RCERH_FSET(2,##Field,Val)
#define _MCBSP_RCERH0_FSETS(Field,Sym)       _MCBSP_RCERH_FSETS(0,##Field,Sym)
#define _MCBSP_RCERH1_FSETS(Field,Sym)       _MCBSP_RCERH_FSETS(1,##Field,Sym)
#define _MCBSP_RCERH2_FSETS(Field,Sym)       _MCBSP_RCERH_FSETS(2,##Field,Sym)
#define _MCBSP_RCERH0_FAOI(Field,AND,OR,INV) _MCBSP_RCERH_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_RCERH1_FAOI(Field,AND,OR,INV) _MCBSP_RCERH_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_RCERH2_FAOI(Field,AND,OR,INV) _MCBSP_RCERH_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_RCERH0_FMK(Field,Val)         _MCBSP_RCERH_FMK(##Field,Val)
#define _MCBSP_RCERH1_FMK(Field,Val)         _MCBSP_RCERH_FMK(##Field,Val)
#define _MCBSP_RCERH2_FMK(Field,Val)         _MCBSP_RCERH_FMK(##Field,Val)
#define _MCBSP_RCERH0_FMKS(Field,Sym)        _MCBSP_RCERH_FMKS(##Field,Sym)
#define _MCBSP_RCERH1_FMKS(Field,Sym)        _MCBSP_RCERH_FMKS(##Field,Sym)
#define _MCBSP_RCERH2_FMKS(Field,Sym)        _MCBSP_RCERH_FMKS(##Field,Sym)
#define _MCBSP_XCERA_FGET(Port,Field)       _PFIELD_GET(_MCBSP_XCERA_ADDR(Port),_MCBSP_XCER_##Field)

#define _MCBSP_XCERA_FSET(Port,Field,Val)   _PFIELD_SET(_MCBSP_XCERA_ADDR(Port),_MCBSP_XCER_##Field,Val)
#define _MCBSP_XCERA_FSETS(Port,Field,Sym)\
  _PFIELD_SET(_MCBSP_XCERA_ADDR(Port),_MCBSP_XCER_##Field,MCBSP_XCER_##Field##_##Sym)
#define _MCBSP_XCERA_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_AOI(_MCBSP_XCERA_ADDR(Port),_MCBSP_XCER_##Field,AND,OR,INV)
#define _MCBSP_XCERA_FMK(Field,Val)       _MCBSP_XCER_##Field##_MK(Val)
#define _MCBSP_XCERA_FMKS(Port,Field,Sym) _MCBSP_XCER_##Field##_MK(MCBSP_XCER_##Field##_##Sym)

#define _MCBSP_XCERA0_FGET(Field)            _MCBSP_XCERA_FGET(0,##Field)
#define _MCBSP_XCERA1_FGET(Field)            _MCBSP_XCERA_FGET(1,##Field)
#define _MCBSP_XCERA2_FGET(Field)            _MCBSP_XCERA_FGET(2,##Field)
#define _MCBSP_XCERA0_FSET(Field,Val)        _MCBSP_XCERA_FSET(0,##Field,Val)
#define _MCBSP_XCERA1_FSET(Field,Val)        _MCBSP_XCERA_FSET(1,##Field,Val)
#define _MCBSP_XCERA2_FSET(Field,Val)        _MCBSP_XCERA_FSET(2,##Field,Val)
#define _MCBSP_XCERA0_FSETS(Field,Sym)       _MCBSP_XCERA_FSETS(0,##Field,Sym)
#define _MCBSP_XCERA1_FSETS(Field,Sym)       _MCBSP_XCERA_FSETS(1,##Field,Sym)
#define _MCBSP_XCERA2_FSETS(Field,Sym)       _MCBSP_XCERA_FSETS(2,##Field,Sym)
#define _MCBSP_XCERA0_FAOI(Field,AND,OR,INV) _MCBSP_XCERA_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_XCERA1_FAOI(Field,AND,OR,INV) _MCBSP_XCERA_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_XCERA2_FAOI(Field,AND,OR,INV) _MCBSP_XCERA_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_XCERA0_FMK(Field,Val)         _MCBSP_XCERA_FMK(##Field,Val)
#define _MCBSP_XCERA1_FMK(Field,Val)         _MCBSP_XCERA_FMK(##Field,Val)
#define _MCBSP_XCERA2_FMK(Field,Val)         _MCBSP_XCERA_FMK(##Field,Val)
#define _MCBSP_XCERA0_FMKS(Field,Sym)        _MCBSP_XCERA_FMKS(##Field,Sym)
#define _MCBSP_XCERA1_FMKS(Field,Sym)        _MCBSP_XCERA_FMKS(##Field,Sym)
#define _MCBSP_XCERA2_FMKS(Field,Sym)        _MCBSP_XCERA_FMKS(##Field,Sym)

#define _MCBSP_XCERB_FGET(Port,Field)     _PFIELD_GET(_MCBSP_XCERB_ADDR(Port),_MCBSP_XCER_##Field)
#define _MCBSP_XCERB_FSET(Port,Field,Val) _PFIELD_SET(_MCBSP_XCERB_ADDR(Port),_MCBSP_XCER_##Field,Val)
#define _MCBSP_XCERB_FSETS(Port,Field,Sym)\
  _PFIELD_SET(_MCBSP_XCERB_ADDR(Port),_MCBSP_XCER_##Field,MCBSP_XCER_##Field##_##Sym)
#define _MCBSP_XCERB_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_AOI(_MCBSP_XCERB_ADDR(Port),_MCBSP_XCER_##Field,AND,OR,INV)
#define _MCBSP_XCERB_FMK(Field,Val)  _MCBSP_XCER_##Field##_MK(Val)
#define _MCBSP_XCERB_FMKS(Field,Sym) _MCBSP_XCER_##Field##_MK(MCBSP_XCER_##Field##_##Sym)

#define _MCBSP_XCERB0_FGET(Field)            _MCBSP_XCERB_FGET(0,##Field)
#define _MCBSP_XCERB1_FGET(Field)            _MCBSP_XCERB_FGET(1,##Field)
#define _MCBSP_XCERB2_FGET(Field)            _MCBSP_XCERB_FGET(2,##Field)
#define _MCBSP_XCERB0_FSET(Field,Val)        _MCBSP_XCERB_FSET(0,##Field,Val)
#define _MCBSP_XCERB1_FSET(Field,Val)        _MCBSP_XCERB_FSET(1,##Field,Val)
#define _MCBSP_XCERB2_FSET(Field,Val)        _MCBSP_XCERB_FSET(2,##Field,Val)
#define _MCBSP_XCERB0_FSETS(Field,Sym)       _MCBSP_XCERB_FSETS(0,##Field,Sym)
#define _MCBSP_XCERB1_FSETS(Field,Sym)       _MCBSP_XCERB_FSETS(1,##Field,Sym)
#define _MCBSP_XCERB2_FSETS(Field,Sym)       _MCBSP_XCERB_FSETS(2,##Field,Sym)
#define _MCBSP_XCERB0_FAOI(Field,AND,OR,INV) _MCBSP_XCERB_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_XCERB1_FAOI(Field,AND,OR,INV) _MCBSP_XCERB_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_XCERB2_FAOI(Field,AND,OR,INV) _MCBSP_XCERB_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_XCERB0_FMK(Field,Val)         _MCBSP_XCERB_FMK(##Field,Val)
#define _MCBSP_XCERB1_FMK(Field,Val)         _MCBSP_XCERB_FMK(##Field,Val)
#define _MCBSP_XCERB2_FMK(Field,Val)         _MCBSP_XCERB_FMK(##Field,Val)
#define _MCBSP_XCERB0_FMKS(Field,Sym)        _MCBSP_XCERB_FMKS(##Field,Sym)
#define _MCBSP_XCERB1_FMKS(Field,Sym)        _MCBSP_XCERB_FMKS(##Field,Sym)
#define _MCBSP_XCERB2_FMKS(Field,Sym)        _MCBSP_XCERB_FMKS(##Field,Sym)

#define _MCBSP_XCERC_FGET(Port,Field)     _PFIELD_GET(_MCBSP_XCERC_ADDR(Port),_MCBSP_XCER_##Field)
#define _MCBSP_XCERC_FSET(Port,Field,Val) _PFIELD_SET(_MCBSP_XCERC_ADDR(Port),_MCBSP_XCER_##Field,Val)
#define _MCBSP_XCERC_FSETS(Port,Field,Sym)\
  _PFIELD_SET(_MCBSP_XCERC_ADDR(Port),_MCBSP_XCER_##Field,MCBSP_XCER_##Field##_##Sym)
#define _MCBSP_XCERC_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_AOI(_MCBSP_XCERC_ADDR(Port),_MCBSP_XCER_##Field,AND,OR,INV)
#define _MCBSP_XCERC_FMK(Field,Val)         _MCBSP_XCER_##Field##_MK(Val)
#define _MCBSP_XCERC_FMKS(Field,Sym)        _MCBSP_XCER_##Field##_MK(MCBSP_XCER_##Field##_##Sym)


#define _MCBSP_XCERC0_FGET(Field)            _MCBSP_XCERC_FGET(0,##Field)
#define _MCBSP_XCERC1_FGET(Field)            _MCBSP_XCERC_FGET(1,##Field)
#define _MCBSP_XCERC2_FGET(Field)            _MCBSP_XCERC_FGET(2,##Field)
#define _MCBSP_XCERC0_FSET(Field,Val)        _MCBSP_XCERC_FSET(0,##Field,Val)
#define _MCBSP_XCERC1_FSET(Field,Val)        _MCBSP_XCERC_FSET(1,##Field,Val)
#define _MCBSP_XCERC2_FSET(Field,Val)        _MCBSP_XCERC_FSET(2,##Field,Val)
#define _MCBSP_XCERC0_FSETS(Field,Sym)       _MCBSP_XCERC_FSETS(0,##Field,Sym)
#define _MCBSP_XCERC1_FSETS(Field,Sym)       _MCBSP_XCERC_FSETS(1,##Field,Sym)
#define _MCBSP_XCERC2_FSETS(Field,Sym)       _MCBSP_XCERC_FSETS(2,##Field,Sym)
#define _MCBSP_XCERC0_FAOI(Field,AND,OR,INV) _MCBSP_XCERC_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_XCERC1_FAOI(Field,AND,OR,INV) _MCBSP_XCERC_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_XCERC2_FAOI(Field,AND,OR,INV) _MCBSP_XCERC_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_XCERC0_FMK(Field,Val)         _MCBSP_XCERC_FMK(##Field,Val)
#define _MCBSP_XCERC1_FMK(Field,Val)         _MCBSP_XCERC_FMK(##Field,Val)
#define _MCBSP_XCERC2_FMK(Field,Val)         _MCBSP_XCERC_FMK(##Field,Val)
#define _MCBSP_XCERC0_FMKS(Field,Sym)        _MCBSP_XCERC_FMKS(##Field,Sym)
#define _MCBSP_XCERC1_FMKS(Field,Sym)        _MCBSP_XCERC_FMKS(##Field,Sym)
#define _MCBSP_XCERC2_FMKS(Field,Sym)        _MCBSP_XCERC_FMKS(##Field,Sym)


#define _MCBSP_XCERD_FGET(Port,Field)     _PFIELD_GET(_MCBSP_XCERD_ADDR(Port),_MCBSP_XCER_##Field)
#define _MCBSP_XCERD_FSET(Port,Field,Val) _PFIELD_SET(_MCBSP_XCERD_ADDR(Port),_MCBSP_XCER_##Field,Val)
#define _MCBSP_XCERD_FSETS(Port,Field,Sym)\
  _PFIELD_SET(_MCBSP_XCERD_ADDR(Port),_MCBSP_XCER_##Field,MCBSP_XCER_##Field##_##Sym)
#define _MCBSP_XCERD_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_AOI(_MCBSP_XCERD_ADDR(Port),_MCBSP_XCER_##Field,AND,OR,INV)
#define _MCBSP_XCERD_FMK(Field,Val)       _MCBSP_XCER_##Field##_MK(Val)
#define _MCBSP_XCERD_FMKS(Field,Sym)      _MCBSP_XCER_##Field##_MK(MCBSP_XCER_##Field##_##Sym)

#define _MCBSP_XCERD0_FGET(Field)            _MCBSP_XCERD_FGET(0,##Field)
#define _MCBSP_XCERD1_FGET(Field)            _MCBSP_XCERD_FGET(1,##Field)
#define _MCBSP_XCERD2_FGET(Field)            _MCBSP_XCERD_FGET(2,##Field)
#define _MCBSP_XCERD0_FSET(Field,Val)        _MCBSP_XCERD_FSET(0,##Field,Val)
#define _MCBSP_XCERD1_FSET(Field,Val)        _MCBSP_XCERD_FSET(1,##Field,Val)
#define _MCBSP_XCERD2_FSET(Field,Val)        _MCBSP_XCERD_FSET(2,##Field,Val)
#define _MCBSP_XCERD0_FSETS(Field,Sym)       _MCBSP_XCERD_FSETS(0,##Field,Sym)
#define _MCBSP_XCERD1_FSETS(Field,Sym)       _MCBSP_XCERD_FSETS(1,##Field,Sym)
#define _MCBSP_XCERD2_FSETS(Field,Sym)       _MCBSP_XCERD_FSETS(2,##Field,Sym)
#define _MCBSP_XCERD0_FAOI(Field,AND,OR,INV) _MCBSP_XCERD_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_XCERD1_FAOI(Field,AND,OR,INV) _MCBSP_XCERD_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_XCERD2_FAOI(Field,AND,OR,INV) _MCBSP_XCERD_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_XCERD0_FMK(Field,Val)         _MCBSP_XCERD_FMK(##Field,Val)
#define _MCBSP_XCERD1_FMK(Field,Val)         _MCBSP_XCERD_FMK(##Field,Val)
#define _MCBSP_XCERD2_FMK(Field,Val)         _MCBSP_XCERD_FMK(##Field,Val)
#define _MCBSP_XCERD0_FMKS(Field,Sym)        _MCBSP_XCERD_FMKS(##Field,Sym)
#define _MCBSP_XCERD1_FMKS(Field,Sym)        _MCBSP_XCERD_FMKS(##Field,Sym)
#define _MCBSP_XCERD2_FMKS(Field,Sym)        _MCBSP_XCERD_FMKS(##Field,Sym)


#define _MCBSP_XCERE_FGET(Port,Field)     _PFIELD_GET(_MCBSP_XCERE_ADDR(Port),_MCBSP_XCER_##Field)
#define _MCBSP_XCERE_FSET(Port,Field,Val) _PFIELD_SET(_MCBSP_XCERE_ADDR(Port),_MCBSP_XCER_##Field,Val)
#define _MCBSP_XCERE_FSETS(Port,Field,Sym)\
  _PFIELD_SET(_MCBSP_XCERE_ADDR(Port),_MCBSP_XCER_##Field,MCBSP_XCER_##Field##_##Sym)
#define _MCBSP_XCERE_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_AOI(_MCBSP_XCERE_ADDR(Port),_MCBSP_XCER_##Field,AND,OR,INV)
#define _MCBSP_XCERE_FMK(Field,Val)       _MCBSP_XCER_##Field##_MK(Val)
#define _MCBSP_XCERE_FMKS(Field,Sym)      _MCBSP_XCER_##Field##_MK(MCBSP_XCER_##Field##_##Sym)

#define _MCBSP_XCERE0_FGET(Field)         _MCBSP_XCERE_FGET(0,##Field)
#define _MCBSP_XCERE1_FGET(Field)         _MCBSP_XCERE_FGET(1,##Field)
#define _MCBSP_XCERE2_FGET(Field)         _MCBSP_XCERE_FGET(2,##Field)
#define _MCBSP_XCERE0_FSET(Field,Val)     _MCBSP_XCERE_FSET(0,##Field,Val)
#define _MCBSP_XCERE1_FSET(Field,Val)     _MCBSP_XCERE_FSET(1,##Field,Val)
#define _MCBSP_XCERE2_FSET(Field,Val)     _MCBSP_XCERE_FSET(2,##Field,Val)
#define _MCBSP_XCERE0_FSETS(Field,Sym)    _MCBSP_XCERE_FSETS(0,##Field,Sym)
#define _MCBSP_XCERE1_FSETS(Field,Sym)    _MCBSP_XCERE_FSETS(1,##Field,Sym)
#define _MCBSP_XCERE2_FSETS(Field,Sym)    _MCBSP_XCERE_FSETS(2,##Field,Sym)
#define _MCBSP_XCERE0_FAOI(Field,AND,OR,INV) _MCBSP_XCERE_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_XCERE1_FAOI(Field,AND,OR,INV) _MCBSP_XCERE_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_XCERE2_FAOI(Field,AND,OR,INV) _MCBSP_XCERE_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_XCERE0_FMK(Field,Val)         _MCBSP_XCERE_FMK(##Field,Val)
#define _MCBSP_XCERE1_FMK(Field,Val)         _MCBSP_XCERE_FMK(##Field,Val)
#define _MCBSP_XCERE2_FMK(Field,Val)         _MCBSP_XCERE_FMK(##Field,Val)
#define _MCBSP_XCERE0_FMKS(Field,Sym)        _MCBSP_XCERE_FMKS(##Field,Sym)
#define _MCBSP_XCERE1_FMKS(Field,Sym)        _MCBSP_XCERE_FMKS(##Field,Sym)
#define _MCBSP_XCERE2_FMKS(Field,Sym)        _MCBSP_XCERE_FMKS(##Field,Sym)


#define _MCBSP_XCERF_FGET(Port,Field)     _PFIELD_GET(_MCBSP_XCERF_ADDR(Port),_MCBSP_XCER_##Field)
#define _MCBSP_XCERF_FSET(Port,Field,Val) _PFIELD_SET(_MCBSP_XCERF_ADDR(Port),_MCBSP_XCER_##Field,Val)
#define _MCBSP_XCERF_FSETS(Port,Field,Sym)\
  _PFIELD_SET(_MCBSP_XCERF_ADDR(Port),_MCBSP_XCER_##Field,MCBSP_XCER_##Field##_##Sym)
#define _MCBSP_XCERF_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_AOI(_MCBSP_XCERF_ADDR(Port),_MCBSP_XCER_##Field,AND,OR,INV)
#define _MCBSP_XCERF_FMK(Field,Val)       _MCBSP_XCER_##Field##_MK(Val)
#define _MCBSP_XCERF_FMKS(Field,Sym)      _MCBSP_XCER_##Field##_MK(MCBSP_XCER_##Field##_##Sym)

#define _MCBSP_XCERF0_FGET(Field)         _MCBSP_XCERF_FGET(0,##Field)
#define _MCBSP_XCERF1_FGET(Field)         _MCBSP_XCERF_FGET(1,##Field)
#define _MCBSP_XCERF2_FGET(Field)         _MCBSP_XCERF_FGET(2,##Field)
#define _MCBSP_XCERF0_FSET(Field,Val)     _MCBSP_XCERF_FSET(0,##Field,Val)
#define _MCBSP_XCERF1_FSET(Field,Val)     _MCBSP_XCERF_FSET(1,##Field,Val)
#define _MCBSP_XCERF2_FSET(Field,Val)     _MCBSP_XCERF_FSET(2,##Field,Val)
#define _MCBSP_XCERF0_FSETS(Field,Sym)    _MCBSP_XCERF_FSETS(0,##Field,Sym)
#define _MCBSP_XCERF1_FSETS(Field,Sym)    _MCBSP_XCERF_FSETS(1,##Field,Sym)
#define _MCBSP_XCERF2_FSETS(Field,Sym)    _MCBSP_XCERF_FSETS(2,##Field,Sym)
#define _MCBSP_XCERF0_FAOI(Field,AND,OR,INV) _MCBSP_XCERF_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_XCERF1_FAOI(Field,AND,OR,INV) _MCBSP_XCERF_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_XCERF2_FAOI(Field,AND,OR,INV) _MCBSP_XCERF_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_XCERF0_FMK(Field,Val)         _MCBSP_XCERF_FMK(##Field,Val)
#define _MCBSP_XCERF1_FMK(Field,Val)         _MCBSP_XCERF_FMK(##Field,Val)
#define _MCBSP_XCERF2_FMK(Field,Val)         _MCBSP_XCERF_FMK(##Field,Val)
#define _MCBSP_XCERF0_FMKS(Field,Sym)        _MCBSP_XCERF_FMKS(##Field,Sym)
#define _MCBSP_XCERF1_FMKS(Field,Sym)        _MCBSP_XCERF_FMKS(##Field,Sym)
#define _MCBSP_XCERF2_FMKS(Field,Sym)        _MCBSP_XCERF_FMKS(##Field,Sym)

#define _MCBSP_XCERG_FGET(Port,Field)     _PFIELD_GET(_MCBSP_XCERG_ADDR(Port),_MCBSP_XCER_##Field)
#define _MCBSP_XCERG_FSET(Port,Field,Val) _PFIELD_SET(_MCBSP_XCERG_ADDR(Port),_MCBSP_XCER_##Field,Val)
#define _MCBSP_XCERG_FSETS(Port,Field,Sym)\
  _PFIELD_SET(_MCBSP_XCERG_ADDR(Port),_MCBSP_XCER_##Field,MCBSP_XCER_##Field##_##Sym)
#define _MCBSP_XCERG_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_AOI(_MCBSP_XCERG_ADDR(Port),_MCBSP_XCER_##Field,AND,OR,INV)
#define _MCBSP_XCERG_FMK(Field,Val)       _MCBSP_XCER_##Field##_MK(Val)
#define _MCBSP_XCERG_FMKS(Field,Sym)      _MCBSP_XCER_##Field##_MK(MCBSP_XCER_##Field##_##Sym)

#define _MCBSP_XCERG0_FGET(Field)         _MCBSP_XCERG_FGET(0,##Field)
#define _MCBSP_XCERG1_FGET(Field)         _MCBSP_XCERG_FGET(1,##Field)
#define _MCBSP_XCERG2_FGET(Field)         _MCBSP_XCERG_FGET(2,##Field)
#define _MCBSP_XCERG0_FSET(Field,Val)     _MCBSP_XCERG_FSET(0,##Field,Val)
#define _MCBSP_XCERG1_FSET(Field,Val)     _MCBSP_XCERG_FSET(1,##Field,Val)
#define _MCBSP_XCERG2_FSET(Field,Val)     _MCBSP_XCERG_FSET(2,##Field,Val)
#define _MCBSP_XCERG0_FSETS(Field,Sym)    _MCBSP_XCERG_FSETS(0,##Field,Sym)
#define _MCBSP_XCERG1_FSETS(Field,Sym)    _MCBSP_XCERG_FSETS(1,##Field,Sym)
#define _MCBSP_XCERG2_FSETS(Field,Sym)    _MCBSP_XCERG_FSETS(2,##Field,Sym)
#define _MCBSP_XCERG0_FAOI(Field,AND,OR,INV) _MCBSP_XCERG_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_XCERG1_FAOI(Field,AND,OR,INV) _MCBSP_XCERG_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_XCERG2_FAOI(Field,AND,OR,INV) _MCBSP_XCERG_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_XCERG0_FMK(Field,Val)         _MCBSP_XCERG_FMK(##Field,Val)
#define _MCBSP_XCERG1_FMK(Field,Val)         _MCBSP_XCERG_FMK(##Field,Val)
#define _MCBSP_XCERG2_FMK(Field,Val)         _MCBSP_XCERG_FMK(##Field,Val)
#define _MCBSP_XCERG0_FMKS(Field,Sym)        _MCBSP_XCERG_FMKS(##Field,Sym)
#define _MCBSP_XCERG1_FMKS(Field,Sym)        _MCBSP_XCERG_FMKS(##Field,Sym)
#define _MCBSP_XCERG2_FMKS(Field,Sym)        _MCBSP_XCERG_FMKS(##Field,Sym)

#define _MCBSP_XCERH_FGET(Port,Field)     _PFIELD_GET(_MCBSP_XCERH_ADDR(Port),_MCBSP_XCER_##Field)
#define _MCBSP_XCERH_FSET(Port,Field,Val) _PFIELD_SET(_MCBSP_XCERH_ADDR(Port),_MCBSP_XCER_##Field,Val)
#define _MCBSP_XCERH_FSETS(Port,Field,Sym)\
  _PFIELD_SET(_MCBSP_XCERH_ADDR(Port),_MCBSP_XCER_##Field,MCBSP_XCER_##Field##_##Sym)
#define _MCBSP_XCERH_FAOI(Port,Field,AND,OR,INV)\
  _PFIELD_AOI(_MCBSP_XCERH_ADDR(Port),_MCBSP_XCER_##Field,AND,OR,INV)
#define _MCBSP_XCERH_FMK(Field,Val)       _MCBSP_XCER_##Field##_MK(Val)
#define _MCBSP_XCERH_FMKS(Field,Sym)      _MCBSP_XCER_##Field##_MK(MCBSP_XCER_##Field##_##Sym)

#define _MCBSP_XCERH0_FGET(Field)         _MCBSP_XCERH_FGET(0,##Field)
#define _MCBSP_XCERH1_FGET(Field)         _MCBSP_XCERH_FGET(1,##Field)
#define _MCBSP_XCERH2_FGET(Field)         _MCBSP_XCERH_FGET(2,##Field)
#define _MCBSP_XCERH0_FSET(Field,Val)     _MCBSP_XCERH_FSET(0,##Field,Val)
#define _MCBSP_XCERH1_FSET(Field,Val)     _MCBSP_XCERH_FSET(1,##Field,Val)
#define _MCBSP_XCERH2_FSET(Field,Val)     _MCBSP_XCERH_FSET(2,##Field,Val)
#define _MCBSP_XCERH0_FSETS(Field,Sym)    _MCBSP_XCERH_FSETS(0,##Field,Sym)
#define _MCBSP_XCERH1_FSETS(Field,Sym)    _MCBSP_XCERH_FSETS(1,##Field,Sym)
#define _MCBSP_XCERH2_FSETS(Field,Sym)    _MCBSP_XCERH_FSETS(2,##Field,Sym)
#define _MCBSP_XCERH0_FAOI(Field,AND,OR,INV) _MCBSP_XCERH_FAOI(0,##Field,AND,OR,INV)
#define _MCBSP_XCERH1_FAOI(Field,AND,OR,INV) _MCBSP_XCERH_FAOI(1,##Field,AND,OR,INV)
#define _MCBSP_XCERH2_FAOI(Field,AND,OR,INV) _MCBSP_XCERH_FAOI(2,##Field,AND,OR,INV)
#define _MCBSP_XCERH0_FMK(Field,Val)         _MCBSP_XCERH_FMK(##Field,Val)
#define _MCBSP_RCERH1_FMK(Field,Val)         _MCBSP_RCERH_FMK(##Field,Val)
#define _MCBSP_RCERH2_FMK(Field,Val)         _MCBSP_RCERH_FMK(##Field,Val)
#define _MCBSP_RCERH0_FMKS(Field,Sym)        _MCBSP_RCERH_FMKS(##Field,Sym)
#define _MCBSP_RCERH1_FMKS(Field,Sym)        _MCBSP_RCERH_FMKS(##Field,Sym)
#define _MCBSP_RCERH2_FMKS(Field,Sym)        _MCBSP_RCERH_FMKS(##Field,Sym)

/*============================================================================*\
* (RW) _MCBSP_SPCR10 -  Serial Port Control Register 1, McBSP #0
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_SPCR10_ADDR				(0x2805u)
  #define _MCBSP_SPCR10                       	PREG16(_MCBSP_SPCR10_ADDR)
  #define _SPCR10                              	_MCBSP_SPCR10
#else
  #define _MCBSP_SPCR10_ADDR				(0x2804u)
  #define _MCBSP_SPCR10                       	PREG16(_MCBSP_SPCR10_ADDR)
  #define _SPCR10                              	_MCBSP_SPCR10
#endif
/*============================================================================*\
* (RW) _MCBSP_SPCR11 -  Serial Port Control Register 1, McBSP #1
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_SPCR11_ADDR				(0x2C05u)
  #define _MCBSP_SPCR11                       	PREG16(_MCBSP_SPCR11_ADDR)
  #define _SPCR11                              	_MCBSP_SPCR11
#else
  #define _MCBSP_SPCR11_ADDR				(0x2C04u)
  #define _MCBSP_SPCR11                       	PREG16(_MCBSP_SPCR11_ADDR)
  #define _SPCR11                              	_MCBSP_SPCR11
#endif

/*============================================================================*\
* (RW) _MCBSP_SPCR12 -  Serial Port Control Register 1, McBSP #2
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_SPCR12_ADDR				(0x3005)
  #define _MCBSP_SPCR12                       	PREG16(_MCBSP_SPCR12_ADDR)
  #define _SPCR12                              	_MCBSP_SPCR12
#else
  #define _MCBSP_SPCR12_ADDR				(0x3004)
  #define _MCBSP_SPCR12                       	PREG16(_MCBSP_SPCR12_ADDR)
  #define _SPCR12                              	_MCBSP_SPCR12
#endif
/*============================================================================*\
 _MCBSP_SPCR1_GET and _MCBSP_SPCR1_SET
\*============================================================================*/
#define _MCBSP_SPCR1_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_SPCR1_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_SPCR20 -  Serial Port Control Register 2, McBSP #0
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_SPCR20_ADDR				(0x2804u)
  #define _MCBSP_SPCR20                       	PREG16(_MCBSP_SPCR20_ADDR)
  #define _SPCR20                              	_MCBSP_SPCR20
#else
  #define _MCBSP_SPCR20_ADDR				(0x2805u)
  #define _MCBSP_SPCR20                       	PREG16(_MCBSP_SPCR20_ADDR)
  #define _SPCR20                              	_MCBSP_SPCR20
#endif

/*============================================================================*\
* (RW) _MCBSP_SPCR21_ -  Serial Port Control Register 2, McBSP #1
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_SPCR21_ADDR				(0x2C04u)
  #define _MCBSP_SPCR21                       	PREG16(_MCBSP_SPCR21_ADDR)
  #define _SPCR21                              	_MCBSP_SPCR21
#else
  #define _MCBSP_SPCR21_ADDR				(0x2C05u)
  #define _MCBSP_SPCR21                       	PREG16(_MCBSP_SPCR21_ADDR)
  #define _SPCR21                              	_MCBSP_SPCR21
#endif
/*============================================================================*\
* (RW) _MCBSP_SPCR22_ -  Serial Port Control Register 2, McBSP #2
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_SPCR22_ADDR				(0x3004)
  #define _MCBSP_SPCR22_                       	PREG16(_MCBSP_SPCR22_ADDR)
  #define _SPCR22_                              	_MCBSP_SPCR22_
#else
  #define _MCBSP_SPCR22_ADDR				(0x3005)
  #define _MCBSP_SPCR22_                       	PREG16(_MCBSP_SPCR22_ADDR)
  #define _SPCR22_                              	_MCBSP_SPCR22_
#endif
/*============================================================================*\
* _MCBSP_SPCR2_GET and _MCBSP_SPCR2_SET
\*============================================================================*/
#define _MCBSP_SPCR2_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_SPCR2_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_PCR0  -  Pin Control Register, McBSP #0
\*============================================================================*/
  #define _MCBSP_PCR0_ADDR				(0x2812u)
  #define _MCBSP_PCR0                       	PREG16(_MCBSP_PCR0_ADDR)
  #define _PCR0                              	_MCBSP_PCR0

/*============================================================================*\
* (RW) _MCBSP_PCR1  -  Pin Control Register, McBSP #1
\*============================================================================*/
  #define _MCBSP_PCR1_ADDR				(0x2C12u)
  #define _MCBSP_PCR1                       	PREG16(_MCBSP_PCR1_ADDR)
  #define _PCR1                              	_MCBSP_PCR1

/*============================================================================*\
* (RW) _MCBSP_PCR2  -  Pin Control Register, McBSP #2
\*============================================================================*/
  #define _MCBSP_PCR2_ADDR				(0x3012)
  #define _MCBSP_PCR2                       	PREG16(_MCBSP_PCR2_ADDR)
  #define _PCR2                              	_MCBSP_PCR2

/*============================================================================*\
* _MCBSP_PCR_GET and _MCBSP_PCR_SET
\*============================================================================*/
#define _MCBSP_PCR_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_PCR_SET(RegAddr,Val)			_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_RCR10  -  Receive and Transmit Control Register 1, McBSP #0
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCR10_ADDR				(0x2807u)
  #define _MCBSP_RCR10					PREG16(_MCBSP_RCR10_ADDR)
  #define _RCR10						_MCBSP_RCR10
#else
  #define _MCBSP_RCR10_ADDR				(0x2806u)
  #define _MCBSP_RCR10					PREG16(_MCBSP_RCR10_ADDR)
  #define _RCR10						_MCBSP_RCR10
#endif
/*============================================================================*\
* (RW) _MCBSP_RCR11  -  Receive and Transmit Control Register 1, McBSP #1
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCR11_ADDR				(0x2C07u)
  #define _MCBSP_RCR11					PREG16(_MCBSP_RCR11_ADDR)
  #define _RCR11						_MCBSP_RCR11
#else
  #define _MCBSP_RCR11_ADDR				(0x2C06u)
  #define _MCBSP_RCR11					PREG16(_MCBSP_RCR11_ADDR)
  #define _RCR11						_MCBSP_RCR11
#endif

/*============================================================================*\
* (RW) _MCBSP_RCR12  -  Receive and Transmit Control Register 1, McBSP #2
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCR12_ADDR				(0x3007u)
  #define _MCBSP_RCR12					PREG16(_MCBSP_RCR12_ADDR)
  #define _RCR12						_MCBSP_RCR12
#else
  #define _MCBSP_RCR12_ADDR				(0x3006u)
  #define _MCBSP_RCR12					PREG16(_MCBSP_RCR12_ADDR)
  #define _RCR12						_MCBSP_RCR12
#endif
/*============================================================================*\
* _MCBSP_RCR1_GET and _MCBSP_RCR1_SET
\*============================================================================*/
#define _MCBSP_RCR1_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_RCR1_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_RCR20  -  Receive and Transmit Control Register 2, McBSP #0
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCR20_ADDR				(0x2806u)
  #define _MCBSP_RCR20					PREG16(_MCBSP_RCR20_ADDR)
  #define _RCR20						_MCBSP_RCR20
#else
  #define _MCBSP_RCR20_ADDR				(0x2807u)
  #define _MCBSP_RCR20					PREG16(_MCBSP_RCR20_ADDR)
  #define _RCR20						_MCBSP_RCR20
#endif

/*============================================================================*\
* (RW) _MCBSP_RCR21  -  Receive and Transmit Control Register 2, McBSP #1
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCR21_ADDR				(0x2C06u)
  #define _MCBSP_RCR21					PREG16(_MCBSP_RCR21_ADDR)
  #define _RCR21						_MCBSP_RCR21
#else
  #define _MCBSP_RCR21_ADDR				(0x2C07u)
  #define _MCBSP_RCR21					PREG16(_MCBSP_RCR21_ADDR)
  #define _RCR21						_MCBSP_RCR21
#endif

/*============================================================================*\
* (RW) _MCBSP_RCR22  -  Receive and Transmit Control Register 2, McBSP #2
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCR22_ADDR				(0x3006u)
  #define _MCBSP_RCR22					PREG16(_MCBSP_RCR22_ADDR)
  #define _RCR22						_MCBSP_RCR22
#else
  #define _MCBSP_RCR22_ADDR				(0x3007u)
  #define _MCBSP_RCR22					PREG16(_MCBSP_RCR22_ADDR)
  #define _RCR22						_MCBSP_RCR22
#endif

/*============================================================================*\
* _MCBSP_RCR2_GET and _MCBSP_RCR2_SET
\*============================================================================*/
#define _MCBSP_RCR2_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_RCR2_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_XCR10  -  Transmit Control Register 1, McBSP #0
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCR10_ADDR				(0x2809u)
  #define _MCBSP_XCR10					PREG16(_MCBSP_XCR10_ADDR)
  #define _XCR10						_MCBSP_XCR10
#else
  #define _MCBSP_XCR10_ADDR				(0x2808u)
  #define _MCBSP_XCR10					PREG16(_MCBSP_XCR10_ADDR)
  #define _XCR10						_MCBSP_XCR10
#endif

/*============================================================================*\
* (RW) _MCBSP_XCR11  -  Transmit Control Register 1, McBSP #1
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCR11_ADDR				(0x2C09u)
  #define _MCBSP_XCR11					PREG16(_MCBSP_XCR11_ADDR)
  #define _XCR11						_MCBSP_XCR11
#else
  #define _MCBSP_XCR11_ADDR				(0x2C08u)
  #define _MCBSP_XCR11					PREG16(_MCBSP_XCR11_ADDR)
  #define _XCR11						_MCBSP_XCR11
#endif

/*============================================================================*\
* (RW) _MCBSP_XCR12  -  Transmit Control Register 1, McBSP #2
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCR12_ADDR				(0x3009u)
  #define _MCBSP_XCR12					PREG16(_MCBSP_XCR12_ADDR)
  #define _XCR12						_MCBSP_XCR12
#else
  #define _MCBSP_XCR12_ADDR				(0x3008u)
  #define _MCBSP_XCR12					PREG16(_MCBSP_XCR12_ADDR)
  #define _XCR12						_MCBSP_XCR12
#endif

/*============================================================================*\
* _MCBSP_XCR1_GET and _MCBSP_XCR1_SET
\*============================================================================*/
#define _MCBSP_XCR1_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_XCR1_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_XCR20  -  Transmit Control Register 2, McBSP #0
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCR20_ADDR				(0x2808u)
  #define _MCBSP_XCR20					PREG16(_MCBSP_XCR20_ADDR)
  #define _XCR20						_MCBSP_XCR20
#else
  #define _MCBSP_XCR20_ADDR				(0x2809u)
  #define _MCBSP_XCR20					PREG16(_MCBSP_XCR20_ADDR)
  #define _XCR20						_MCBSP_XCR20
#endif

/*============================================================================*\
* (RW) _MCBSP_XCR21  -  Transmit Control Register 2, McBSP #1
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCR21_ADDR				(0x2C08u)
  #define _MCBSP_XCR21					PREG16(_MCBSP_XCR21_ADDR)
  #define _XCR21						_MCBSP_XCR21
#else
  #define _MCBSP_XCR21_ADDR				(0x2C09u)
  #define _MCBSP_XCR21					PREG16(_MCBSP_XCR21_ADDR)
  #define _XCR21						_MCBSP_XCR21
#endif

/*============================================================================*\
* (RW) _MCBSP_XCR22  -  Transmit Control Register 2, McBSP #2
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCR22_ADDR				(0x3008u)
  #define _MCBSP_XCR22					PREG16(_MCBSP_XCR22_ADDR)
  #define _XCR22						_MCBSP_XCR22
#else
  #define _MCBSP_XCR22_ADDR				(0x3009u)
  #define _MCBSP_XCR22					PREG16(_MCBSP_XCR22_ADDR)
  #define _XCR22						_MCBSP_XCR22
#endif
/*============================================================================*\
* _MCBSP_XCR2_GET and _MCBSP_XCR2_SET
\*============================================================================*/
#define _MCBSP_XCR2_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_XCR2_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_SRGR10 -  Sample Rate Generator Register 1, McBSP #0
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_SRGR10_ADDR				(0x280Bu)
  #define _MCBSP_SRGR10					PREG16(_MCBSP_SRGR10_ADDR)
  #define _SRGR10						_MCBSP_SRGR10
#else
  #define _MCBSP_SRGR10_ADDR				(0x280Au)
  #define _MCBSP_SRGR10					PREG16(_MCBSP_SRGR10_ADDR)
  #define _SRGR10						_MCBSP_SRGR10
#endif

/*============================================================================*\
* (RW) _MCBSP_SRGR11 -  Sample Rate Generator Register 1, McBSP #1
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_SRGR11_ADDR				(0x2C0Bu)
  #define _MCBSP_SRGR11					PREG16(_MCBSP_SRGR11_ADDR)
  #define _SRGR11						_MCBSP_SRGR11
#else
  #define _MCBSP_SRGR11_ADDR				(0x2C0Au)
  #define _MCBSP_SRGR11					PREG16(_MCBSP_SRGR11_ADDR)
  #define _SRGR11						_MCBSP_SRGR11
#endif

/*============================================================================*\
* (RW) _MCBSP_SRGR12 -  Sample Rate Generator Register 1, McBSP #2
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_SRGR12_ADDR				(0x300Bu)
  #define _MCBSP_SRGR12					PREG16(_MCBSP_SRGR12_ADDR)
  #define _SRGR12						_MCBSP_SRGR12
#else
  #define _MCBSP_SRGR12_ADDR				(0x300Au)
  #define _MCBSP_SRGR12					PREG16(_MCBSP_SRGR12_ADDR)
  #define _SRGR12						_MCBSP_SRGR12
#endif

/*============================================================================*\
* _MCBSP_SRGR1_GET and _MCBSP_SRGR1_SET
\*============================================================================*/
#define _MCBSP_SRGR1_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_SRGR1_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_SRGR20 -  Sample Rate Generator Register 2, McBSP #0
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_SRGR20_ADDR				(0x280Au)
  #define _MCBSP_SRGR20					PREG16(_MCBSP_SRGR20_ADDR)
  #define _SRGR20						_MCBSP_SRGR20
#else
  #define _MCBSP_SRGR20_ADDR				(0x280Bu)
  #define _MCBSP_SRGR20					PREG16(_MCBSP_SRGR20_ADDR)
  #define _SRGR20						_MCBSP_SRGR20
#endif

/*============================================================================*\
* (RW) _MCBSP_SRGR21 -  Sample Rate Generator Register 2, McBSP #1
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_SRGR21_ADDR				(0x2C0Au)
  #define _MCBSP_SRGR21					PREG16(_MCBSP_SRGR21_ADDR)
  #define _SRGR21						_MCBSP_SRGR21
#else
  #define _MCBSP_SRGR21_ADDR				(0x2C0Bu)
  #define _MCBSP_SRGR21					PREG16(_MCBSP_SRGR21_ADDR)
  #define _SRGR21						_MCBSP_SRGR21
#endif

/*============================================================================*\
* (RW) _MCBSP_SRGR22 -  Sample Rate Generator Register 2, McBSP #2
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_SRGR22_ADDR				(0x300Au)
  #define _MCBSP_SRGR22					PREG16(_MCBSP_SRGR22_ADDR)
  #define _SRGR22						_MCBSP_SRGR22
#else
  #define _MCBSP_SRGR22_ADDR				(0x300Bu)
  #define _MCBSP_SRGR22					PREG16(_MCBSP_SRGR22_ADDR)
  #define _SRGR22						_MCBSP_SRGR22
#endif

/*============================================================================*\
* _MCBSP_SRGR2_GET and _MCBSP_SRGR2_SET
\*============================================================================*/
#define _MCBSP_SRGR2_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_SRGR2_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_MCR10  -  Multi-channel Control Register 1, McBSP #0
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_MCR10_ADDR				(0x280Du)
  #define _MCBSP_MCR10					PREG16(_MCBSP_MCR10_ADDR)
  #define _MCR10						_MCBSP_MCR10
#else
  #define _MCBSP_MCR10_ADDR				(0x280Cu)
  #define _MCBSP_MCR10					PREG16(_MCBSP_MCR10_ADDR)
  #define _MCR10						_MCBSP_MCR10
#endif

/*============================================================================*\
* (RW) _MCBSP_MCR11  -  Multi-channel Control Register 1, McBSP #1
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_MCR11_ADDR				(0x2C0Du)
  #define _MCBSP_MCR11					PREG16(_MCBSP_MCR11_ADDR)
  #define _MCR11						_MCBSP_MCR11
#else
  #define _MCBSP_MCR11_ADDR				(0x2C0Cu)
  #define _MCBSP_MCR11					PREG16(_MCBSP_MCR11_ADDR)
  #define _MCR11						_MCBSP_MCR11
#endif

/*============================================================================*\
* (RW) _MCBSP_MCR12  -  Multi-channel Control Register 1, McBSP #2
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_MCR12_ADDR				(0x300Du)
  #define _MCBSP_MCR12					PREG16(_MCBSP_MCR12_ADDR)
  #define _MCR12						_MCBSP_MCR12
#else
  #define _MCBSP_MCR12_ADDR				(0x300Cu)
  #define _MCBSP_MCR12					PREG16(_MCBSP_MCR12_ADDR)
  #define _MCR12						_MCBSP_MCR12
#endif

/*============================================================================*\
* _MCBSP_MCR1_GET and _MCBSP_MCR1_SET
\*============================================================================*/
#define _MCBSP_MCR1_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_MCR1_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_MCR20  -  Multi-channel Control Register 2, McBSP #0
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_MCR20_ADDR				(0x280Cu)
  #define _MCBSP_MCR20					PREG16(_MCBSP_MCR20_ADDR)
  #define _MCR20						_MCBSP_MCR20
#else
  #define _MCBSP_MCR20_ADDR				(0x280Du)
  #define _MCBSP_MCR20					PREG16(_MCBSP_MCR20_ADDR)
  #define _MCR20						_MCBSP_MCR20
#endif

/*============================================================================*\
* (RW) _MCBSP_MCR21  -  Multi-channel Control Register 2, McBSP #1
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_MCR21_ADDR				(0x2C0Cu)
  #define _MCBSP_MCR21					PREG16(_MCBSP_MCR21_ADDR)
  #define _MCR21						_MCBSP_MCR21
#else
  #define _MCBSP_MCR21_ADDR				(0x2C0Du)
  #define _MCBSP_MCR21					PREG16(_MCBSP_MCR21_ADDR)
  #define _MCR21						_MCBSP_MCR21
#endif

/*============================================================================*\
* (RW) _MCBSP_MCR22  -  Multi-channel Control Register 2, McBSP #2
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_MCR22_ADDR				(0x300Cu)
  #define _MCBSP_MCR22					PREG16(_MCBSP_MCR22_ADDR)
  #define _MCR22						_MCBSP_MCR22
#else
  #define _MCBSP_MCR22_ADDR				(0x300Du)
  #define _MCBSP_MCR22					PREG16(_MCBSP_MCR22_ADDR)
  #define _MCR22						_MCBSP_MCR22
#endif

/*============================================================================*\
* _MCBSP_MCR2_GET and _MCBSP_MCR2_SET
\*============================================================================*/
#define _MCBSP_MCR2_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_MCR2_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_XCERA0 -  Transmit Channel Enable Register Partition A, McBSP #0
\*============================================================================*/
  #define _MCBSP_XCERA0_ADDR				(0x2810u)
  #define _MCBSP_XCERA0					PREG16(_MCBSP_XCERA0_ADDR)
  #define _XCERA0						_MCBSP_XCERA0

/*============================================================================*\
* (RW) _MCBSP_XCERA1 -  Transmit Channel Enable Register Partition A, McBSP #1
\*============================================================================*/
#define _MCBSP_XCERA1_ADDR				(0x2C10u)
#define _MCBSP_XCERA1					PREG16(_MCBSP_XCERA1_ADDR)
#define _XCERA1						_MCBSP_XCERA1

/*============================================================================*\
* (RW) _MCBSP_XCERA2 -  Transmit Channel Enable Register Partition A, McBSP #2
\*============================================================================*/
#define _MCBSP_XCERA2_ADDR				(0x3010u)
#define _MCBSP_XCERA2					PREG16(_MCBSP_XCERA2_ADDR)
#define _XCERA2						_MCBSP_XCERA2

/*============================================================================*\
* _MCBSP_XCERA_GET and _MCBSP_XCERA_SET
\*============================================================================*/
#define _MCBSP_XCERA_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_XCERA_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_XCERB0 -  Transmit Channel Enable Register Partition B, McBSP #0
\*============================================================================*/
#define _MCBSP_XCERB0_ADDR				(0x2811u)
#define _MCBSP_XCERB0					PREG16(_MCBSP_XCERB0_ADDR)
#define _XCERB0						_MCBSP_XCERB0

/*============================================================================*\
* (RW) _MCBSP_XCERB1 -  Transmit Channel Enable Register Partition B, McBSP #1
\*============================================================================*/
#define _MCBSP_XCERB1_ADDR				(0x2C11u)
#define _MCBSP_XCERB1					PREG16(_MCBSP_XCERB1_ADDR)
#define _XCERB1						_MCBSP_XCERB1

/*============================================================================*\
* (RW) _MCBSP_XCERB2 -  Transmit Channel Enable Register Partition B, McBSP #2
\*============================================================================*/
#define _MCBSP_XCERB2_ADDR				(0x3011u)
#define _MCBSP_XCERB2					PREG16(_MCBSP_XCERB2_ADDR)
#define _XCERB2						_MCBSP_XCERB2

/*============================================================================*\
* _MCBSP_XCERB_GET and _MCBSP_XCERB_SET
\*============================================================================*/
#define _MCBSP_XCERB_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_XCERB_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_XCERC0 -  Transmit Channel Enable Register Partition C, McBSP #0
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCERC0_ADDR				(0x2815u)
  #define _MCBSP_XCERC0					PREG16(_MCBSP_XCERC0_ADDR)
  #define _XCERC0						_MCBSP_XCERC0
#else
  #define _MCBSP_XCERC0_ADDR				(0x2816u)
  #define _MCBSP_XCERC0					PREG16(_MCBSP_XCERC0_ADDR)
  #define _XCERC0						_MCBSP_XCERC0
#endif

/*============================================================================*\
* (RW) _MCBSP_XCERC1 -  Transmit Channel Enable Register Partition C, McBSP #1
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCERC1_ADDR				(0x2C15u)
  #define _MCBSP_XCERC1					PREG16(_MCBSP_XCERC1_ADDR)
  #define _XCERC1						_MCBSP_XCERC1
#else
  #define _MCBSP_XCERC1_ADDR				(0x2C16u)
  #define _MCBSP_XCERC1					PREG16(_MCBSP_XCERC1_ADDR)
  #define _XCERC1						_MCBSP_XCERC1
#endif

/*============================================================================*\
* (RW) _MCBSP_XCERC2 -  Transmit Channel Enable Register Partition C, McBSP #2
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCERC2_ADDR				(0x3015u)
  #define _MCBSP_XCERC2					PREG16(_MCBSP_XCERC2_ADDR)
  #define _XCERC2						_MCBSP_XCERC2
#else
  #define _MCBSP_XCERC2_ADDR				(0x3016u)
  #define _MCBSP_XCERC2					PREG16(_MCBSP_XCERC2_ADDR)
  #define _XCERC2						_MCBSP_XCERC2
#endif

/*============================================================================*\
* _MCBSP_XCERC_GET and _MCBSP_XCERC_SET
\*============================================================================*/
#define _MCBSP_XCERC_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_XCERC_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_XCERD0 -  Transmit Channel Enable Register Partition D, McBSP #0
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCERD0_ADDR				(0x2816u)
  #define _MCBSP_XCERD0					PREG16(_MCBSP_XCERD0_ADDR)
  #define _XCERD0						_MCBSP_XCERD0
#else
  #define _MCBSP_XCERD0_ADDR				(0x2817u)
  #define _MCBSP_XCERD0					PREG16(_MCBSP_XCERD0_ADDR)
  #define _XCERD0						_MCBSP_XCERD0
#endif

/*============================================================================*\
* (RW) _MCBSP_XCERD1 -  Transmit Channel Enable Register Partition D, McBSP #1
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCERD1_ADDR				(0x2C16u)
  #define _MCBSP_XCERD1					PREG16(_MCBSP_XCERD1_ADDR)
  #define _XCERD1						_MCBSP_XCERD1
#else
  #define _MCBSP_XCERD1_ADDR				(0x2C17u)
  #define _MCBSP_XCERD1					PREG16(_MCBSP_XCERD1_ADDR)
  #define _XCERD1						_MCBSP_XCERD1
#endif

/*============================================================================*\
* (RW) _MCBSP_XCERD2 -  Transmit Channel Enable Register Partition D, McBSP #2
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCERD2_ADDR				(0x3016u)
  #define _MCBSP_XCERD2					PREG16(_MCBSP_XCERD2_ADDR)
  #define _XCERD2						_MCBSP_XCERD2
#else
  #define _MCBSP_XCERD2_ADDR				(0x3017u)
  #define _MCBSP_XCERD2					PREG16(_MCBSP_XCERD2_ADDR)
  #define _XCERD2						_MCBSP_XCERD2
#endif

/*============================================================================*\
* _MCBSP_XCERD_GET and _MCBSP_XCERD_SET
\*============================================================================*/
#define _MCBSP_XCERD_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_XCERD_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_XCERE0 -  Transmit Channel Enable Register Partition E, McBSP #0
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCERE0_ADDR				(0x2819u)
  #define _MCBSP_XCERE0					PREG16(_MCBSP_XCERE0_ADDR)
  #define _XCERE0						_MCBSP_XCERE0
#else
  #define _MCBSP_XCERE0_ADDR				(0x281Au)
  #define _MCBSP_XCERE0					PREG16(_MCBSP_XCERE0_ADDR)
  #define _XCERE0						_MCBSP_XCERE0
#endif

/*============================================================================*\
* (RW) _MCBSP_XCERE1 -  Transmit Channel Enable Register Partition E, McBSP #1
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCERE1_ADDR				(0x2C19u)
  #define _MCBSP_XCERE1					PREG16(_MCBSP_XCERE1_ADDR)
  #define _XCERE1						_MCBSP_XCERE1
#else
  #define _MCBSP_XCERE1_ADDR				(0x2C1Au)
  #define _MCBSP_XCERE1					PREG16(_MCBSP_XCERE1_ADDR)
  #define _XCERE1						_MCBSP_XCERE1
#endif

/*============================================================================*\
* (RW) _MCBSP_XCERE2 -  Transmit Channel Enable Register Partition E, McBSP #2
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCERE2_ADDR				(0x3019u)
  #define _MCBSP_XCERE2					PREG16(_MCBSP_XCERE2_ADDR)
  #define _XCERE2						_MCBSP_XCERE2
#else
  #define _MCBSP_XCERE2_ADDR				(0x301Au)
  #define _MCBSP_XCERE2					PREG16(_MCBSP_XCERE2_ADDR)
  #define _XCERE2						_MCBSP_XCERE2
#endif

/*============================================================================*\
* _MCBSP_XCERE_GET and _MCBSP_XCERE_SET
\*============================================================================*/
#define _MCBSP_XCERE_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_XCERE_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_XCERF0 -  Transmit Channel Enable Register Partition F, McBSP #0
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCERF0_ADDR				(0x281Au)
  #define _MCBSP_XCERF0					PREG16(_MCBSP_XCERF0_ADDR)
  #define _XCERF0						_MCBSP_XCERF0
#else
  #define _MCBSP_XCERF0_ADDR				(0x281Bu)
  #define _MCBSP_XCERF0					PREG16(_MCBSP_XCERF0_ADDR)
  #define _XCERF0						_MCBSP_XCERF0
#endif

/*============================================================================*\
* (RW) _MCBSP_XCERF1 -  Transmit Channel Enable Register Partition F, McBSP #1
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCERF1_ADDR				(0x2C1Au)
  #define _MCBSP_XCERF1					PREG16(_MCBSP_XCERF1_ADDR)
  #define _XCERF1						_MCBSP_XCERF1
#else
  #define _MCBSP_XCERF1_ADDR				(0x2C1Bu)
  #define _MCBSP_XCERF1					PREG16(_MCBSP_XCERF1_ADDR)
  #define _XCERF1						_MCBSP_XCERF1
#endif

/*============================================================================*\
* (RW) _MCBSP_XCERF2 -  Transmit Channel Enable Register Partition F, McBSP #2
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCERF2_ADDR				(0x301Au)
  #define _MCBSP_XCERF2					PREG16(_MCBSP_XCERF2_ADDR)
  #define _XCERF2						_MCBSP_XCERF2
#else
  #define _MCBSP_XCERF2_ADDR				(0x301Bu)
  #define _MCBSP_XCERF2					PREG16(_MCBSP_XCERF2_ADDR)
  #define _XCERF2						_MCBSP_XCERF2
#endif

/*============================================================================*\
* _MCBSP_XCERF_GET and _MCBSP_XCERF_SET
\*============================================================================*/
#define _MCBSP_XCERF_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_XCERF_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_XCERG0 -  Transmit Channel Enable Register Partition G, McBSP #0
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCERG0_ADDR				(0x281Du)
  #define _MCBSP_XCERG0					PREG16(_MCBSP_XCERG0_ADDR)
  #define _XCERG0						_MCBSP_XCERG0
#else
  #define _MCBSP_XCERG0_ADDR				(0x281Eu)
  #define _MCBSP_XCERG0					PREG16(_MCBSP_XCERG0_ADDR)
  #define _XCERG0						_MCBSP_XCERG0
#endif

/*============================================================================*\
* (RW) _MCBSP_XCERG1 -  Transmit Channel Enable Register Partition G, McBSP #1
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCERG1_ADDR				(0x2C1Du)
  #define _MCBSP_XCERG1					PREG16(_MCBSP_XCERG1_ADDR)
  #define _XCERG1						_MCBSP_XCERG1
#else
  #define _MCBSP_XCERG1_ADDR				(0x2C1Eu)
  #define _MCBSP_XCERG1					PREG16(_MCBSP_XCERG1_ADDR)
  #define _XCERG1						_MCBSP_XCERG1
#endif

/*============================================================================*\
* (RW) _MCBSP_XCERG2 -  Transmit Channel Enable Register Partition G, McBSP #2
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCERG2_ADDR				(0x301Du)
  #define _MCBSP_XCERG2					PREG16(_MCBSP_XCERG2_ADDR)
  #define _XCERG2						_MCBSP_XCERG2
#else
  #define _MCBSP_XCERG2_ADDR				(0x301Eu)
  #define _MCBSP_XCERG2					PREG16(_MCBSP_XCERG2_ADDR)
  #define _XCERG2						_MCBSP_XCERG2
#endif

/*============================================================================*\
* _MCBSP_XCERG_GET and _MCBSP_XCERG_SET
\*============================================================================*/
#define _MCBSP_XCERG_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_XCERG_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_XCERH0 -  Transmit Channel Enable Register Partition H, McBSP #0
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCERH0_ADDR				(0x281Eu)
  #define _MCBSP_XCERH0					PREG16(_MCBSP_XCERH0_ADDR)
  #define _XCERH0						_MCBSP_XCERH0
#else
  #define _MCBSP_XCERH0_ADDR				(0x281Fu)
  #define _MCBSP_XCERH0					PREG16(_MCBSP_XCERH0_ADDR)
  #define _XCERH0						_MCBSP_XCERH0
#endif

/*============================================================================*\
* (RW) _MCBSP_XCERH1 -  Transmit Channel Enable Register Partition H, McBSP #1
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCERH1_ADDR				(0x2C1Eu)
  #define _MCBSP_XCERH1					PREG16(_MCBSP_XCERH1_ADDR)
  #define _XCERH1						_MCBSP_XCERH1
#else
  #define _MCBSP_XCERH1_ADDR				(0x2C1Fu)
  #define _MCBSP_XCERH1					PREG16(_MCBSP_XCERH1_ADDR)
  #define _XCERH1						_MCBSP_XCERH1
#endif

/*============================================================================*\
* (RW) _MCBSP_XCERH2 -  Transmit Channel Enable Register Partition H, McBSP #2
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_XCERH2_ADDR				(0x301Eu)
  #define _MCBSP_XCERH2					PREG16(_MCBSP_XCERH2_ADDR)
  #define _XCERH2						_MCBSP_XCERH2
#else
  #define _MCBSP_XCERH2_ADDR				(0x301Fu)
  #define _MCBSP_XCERH2					PREG16(_MCBSP_XCERH2_ADDR)
  #define _XCERH2						_MCBSP_XCERH2
#endif

/*============================================================================*\
* _MCBSP_XCERH_GET and _MCBSP_XCERH_SET
\*============================================================================*/
#define _MCBSP_XCERH_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_XCERH_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_RCERA0 -  Receive Channel Enable Register Partition A, McBSP #0
\*============================================================================*/
  #define _MCBSP_RCERA0_ADDR				(0x280Eu)
  #define _MCBSP_RCERA0					PREG16(_MCBSP_RCERA0_ADDR)
  #define _RCERA0						_MCBSP_RCERA0

/*============================================================================*\
* (RW) _MCBSP_RCERA1 -  Receive Channel Enable Register Partition A, McBSP #1
\*============================================================================*/
#define _MCBSP_RCERA1_ADDR				(0x2C0Eu)
#define _MCBSP_RCERA1					PREG16(_MCBSP_RCERA1_ADDR)
#define _RCERA1						_MCBSP_RCERA1

/*============================================================================*\
* (RW) _MCBSP_RCERA2 -  Receive Channel Enable Register Partition A, McBSP #2
\*============================================================================*/
#define _MCBSP_RCERA2_ADDR				(0x300Eu)
#define _MCBSP_RCERA2					PREG16(_MCBSP_RCERA2_ADDR)
#define _RCERA2						_MCBSP_RCERA2

/*============================================================================*\
* _MCBSP_RCERA_GET and _MCBSP_RCERA_SET
\*============================================================================*/
#define _MCBSP_RCERA_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_RCERA_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_RCERB0 -  Receive Channel Enable Register Partition B, McBSP #0
\*============================================================================*/
#define _MCBSP_RCERB0_ADDR				(0x280Fu)
#define _MCBSP_RCERB0					PREG16(_MCBSP_RCERB0_ADDR)
#define _RCERB0						_MCBSP_RCERB0

/*============================================================================*\
* (RW) _MCBSP_RCERB1 -  Receive Channel Enable Register Partition B, McBSP #1
\*============================================================================*/
#define _MCBSP_RCERB1_ADDR				(0x2C0Fu)
#define _MCBSP_RCERB1					PREG16(_MCBSP_RCERB1_ADDR)
#define _RCERB1						_MCBSP_RCERB1

/*============================================================================*\
* (RW) _MCBSP_RCERB2 -  Receive Channel Enable Register Partition B, McBSP #2
\*============================================================================*/
#define _MCBSP_RCERB2_ADDR				(0x300Fu)
#define _MCBSP_RCERB2					PREG16(_MCBSP_RCERB2_ADDR)
#define _RCERB2						_MCBSP_RCERB2

/*============================================================================*\
* _MCBSP_RCERB_GET and _MCBSP_RCERB_SET
\*============================================================================*/
#define _MCBSP_RCERB_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_RCERB_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_RCERC0 -  Receive Channel Enable Register Partition C, McBSP #0
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCERC0_ADDR				(0x2813u)
  #define _MCBSP_RCERC0					PREG16(_MCBSP_RCERC0_ADDR)
  #define _RCERC0						_MCBSP_RCERC0
#else
  #define _MCBSP_RCERC0_ADDR				(0x2814u)
  #define _MCBSP_RCERC0					PREG16(_MCBSP_RCERC0_ADDR)
  #define _RCERC0						_MCBSP_RCERC0
#endif

/*============================================================================*\
* (RW) _MCBSP_RCERC1 -  Receive Channel Enable Register Partition C, McBSP #1
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCERC1_ADDR				(0x2C13u)
  #define _MCBSP_RCERC1					PREG16(_MCBSP_RCERC1_ADDR)
  #define _RCERC1						_MCBSP_RCERC1
#else
  #define _MCBSP_RCERC1_ADDR				(0x2C14u)
  #define _MCBSP_RCERC1					PREG16(_MCBSP_RCERC1_ADDR)
  #define _RCERC1						_MCBSP_RCERC1
#endif

/*============================================================================*\
* (RW) _MCBSP_RCERC2 -  Receive Channel Enable Register Partition C, McBSP #2
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCERC2_ADDR				(0x3013u)
  #define _MCBSP_RCERC2					PREG16(_MCBSP_RCERC2_ADDR)
  #define _RCERC2						_MCBSP_RCERC2
#else
  #define _MCBSP_RCERC2_ADDR				(0x3014u)
  #define _MCBSP_RCERC2					PREG16(_MCBSP_RCERC2_ADDR)
  #define _RCERC2						_MCBSP_RCERC2
#endif

/*============================================================================*\
* _MCBSP_RCERC_GET and _MCBSP_RCERC_SET
\*============================================================================*/
#define _MCBSP_RCERC_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_RCERC_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_RCERD0 -  Receive Channel Enable Register Partition D, McBSP #0
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCERD0_ADDR				(0x2814u)
  #define _MCBSP_RCERD0					PREG16(_MCBSP_RCERD0_ADDR)
  #define _RCERD0						_MCBSP_RCERD0
#else
  #define _MCBSP_RCERD0_ADDR				(0x2815u)
  #define _MCBSP_RCERD0					PREG16(_MCBSP_RCERD0_ADDR)
  #define _RCERD0						_MCBSP_RCERD0
#endif

/*============================================================================*\
* (RW) _MCBSP_RCERD1 -  Receive Channel Enable Register Partition D, McBSP #1
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCERD1_ADDR				(0x2C14u)
  #define _MCBSP_RCERD1					PREG16(_MCBSP_RCERD1_ADDR)
  #define _RCERD1						_MCBSP_RCERD1
#else
  #define _MCBSP_RCERD1_ADDR				(0x2C15u)
  #define _MCBSP_RCERD1					PREG16(_MCBSP_RCERD1_ADDR)
  #define _RCERD1						_MCBSP_RCERD1
#endif

/*============================================================================*\
* (RW) _MCBSP_RCERD2 -  Receive Channel Enable Register Partition D, McBSP #2
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCERD2_ADDR				(0x3014u)
  #define _MCBSP_RCERD2					PREG16(_MCBSP_RCERD2_ADDR)
  #define _RCERD2						_MCBSP_RCERD2
#else
  #define _MCBSP_RCERD2_ADDR				(0x3015u)
  #define _MCBSP_RCERD2					PREG16(_MCBSP_RCERD2_ADDR)
  #define _RCERD2						_MCBSP_RCERD2
#endif

/*============================================================================*\
* _MCBSP_RCERD_GET and _MCBSP_RCERD_SET
\*============================================================================*/
#define _MCBSP_RCERD_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_RCERD_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_RCERE0 -  Receive Channel Enable Register Partition E, McBSP #0
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCERE0_ADDR				(0x2817u)
  #define _MCBSP_RCERE0					PREG16(_MCBSP_RCERE0_ADDR)
  #define _RCERE0						_MCBSP_RCERE0
#else
  #define _MCBSP_RCERE0_ADDR				(0x2818u)
  #define _MCBSP_RCERE0					PREG16(_MCBSP_RCERE0_ADDR)
  #define _RCERE0						_MCBSP_RCERE0
#endif

/*============================================================================*\
* (RW) _MCBSP_RCERE1 -  Receive Channel Enable Register Partition E, McBSP #1
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCERE1_ADDR				(0x2C17u)
  #define _MCBSP_RCERE1					PREG16(_MCBSP_RCERE1_ADDR)
  #define _RCERE1						_MCBSP_RCERE1
#else
  #define _MCBSP_RCERE1_ADDR				(0x2C18u)
  #define _MCBSP_RCERE1					PREG16(_MCBSP_RCERE1_ADDR)
  #define _RCERE1						_MCBSP_RCERE1
#endif

/*============================================================================*\
* (RW) _MCBSP_RCERE2 -  Receive Channel Enable Register Partition E, McBSP #2
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCERE2_ADDR				(0x3017u)
  #define _MCBSP_RCERE2					PREG16(_MCBSP_RCERE2_ADDR)
  #define _RCERE2						_MCBSP_RCERE2
#else
  #define _MCBSP_RCERE2_ADDR				(0x3018u)
  #define _MCBSP_RCERE2					PREG16(_MCBSP_RCERE2_ADDR)
  #define _RCERE2						_MCBSP_RCERE2
#endif

/*============================================================================*\
* _MCBSP_RCERE_GET and _MCBSP_RCERE_SET
\*============================================================================*/
#define _MCBSP_RCERE_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_RCERE_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_RCERF0 -  Receive Channel Enable Register Partition F, McBSP #0
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCERF0_ADDR				(0x2818u)
  #define _MCBSP_RCERF0					PREG16(_MCBSP_RCERF0_ADDR)
  #define _RCERF0						_MCBSP_RCERF0
#else
  #define _MCBSP_RCERF0_ADDR				(0x2819u)
  #define _MCBSP_RCERF0					PREG16(_MCBSP_RCERF0_ADDR)
  #define _RCERF0						_MCBSP_RCERF0
#endif

/*============================================================================*\
* (RW) _MCBSP_RCERF1 -  Receive Channel Enable Register Partition F, McBSP #1
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCERF1_ADDR				(0x2C18u)
  #define _MCBSP_RCERF1					PREG16(_MCBSP_RCERF1_ADDR)
  #define _RCERF1						_MCBSP_RCERF1
#else
  #define _MCBSP_RCERF1_ADDR				(0x2C19u)
  #define _MCBSP_RCERF1					PREG16(_MCBSP_RCERF1_ADDR)
  #define _RCERF1						_MCBSP_RCERF1
#endif

/*============================================================================*\
* (RW) _MCBSP_RCERF2 -  Receive Channel Enable Register Partition F, McBSP #2
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCERF2_ADDR				(0x3018u)
  #define _MCBSP_RCERF2					PREG16(_MCBSP_RCERF2_ADDR)
  #define _RCERF2						_MCBSP_RCERF2
#else
  #define _MCBSP_RCERF2_ADDR				(0x3019u)
  #define _MCBSP_RCERF2					PREG16(_MCBSP_RCERF2_ADDR)
  #define _RCERF2						_MCBSP_RCERF2
#endif

/*============================================================================*\
* _MCBSP_RCERF_GET and _MCBSP_RCERF_SET
\*============================================================================*/
#define _MCBSP_RCERF_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_RCERF_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_RCERG0 -  Receive Channel Enable Register Partition G, McBSP #0
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCERG0_ADDR				(0x281Bu)
  #define _MCBSP_RCERG0					PREG16(_MCBSP_RCERG0_ADDR)
  #define _RCERG0						_MCBSP_RCERG0
#else
  #define _MCBSP_RCERG0_ADDR				(0x281Cu)
  #define _MCBSP_RCERG0					PREG16(_MCBSP_RCERG0_ADDR)
  #define _RCERG0						_MCBSP_RCERG0
#endif

/*============================================================================*\
* (RW) _MCBSP_RCERG1 -  Receive Channel Enable Register Partition G, McBSP #1
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCERG1_ADDR				(0x2C1Bu)
  #define _MCBSP_RCERG1					PREG16(_MCBSP_RCERG1_ADDR)
  #define _RCERG1						_MCBSP_RCERG1
#else
  #define _MCBSP_RCERG1_ADDR				(0x2C1Cu)
  #define _MCBSP_RCERG1					PREG16(_MCBSP_RCERG1_ADDR)
  #define _RCERG1						_MCBSP_RCERG1
#endif

/*============================================================================*\
* (RW) _MCBSP_RCERG2 -  Receive Channel Enable Register Partition G, McBSP #2
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCERG2_ADDR				(0x301Bu)
  #define _MCBSP_RCERG2					PREG16(_MCBSP_RCERG2_ADDR)
  #define _RCERG2						_MCBSP_RCERG2
#else
  #define _MCBSP_RCERG2_ADDR				(0x301Cu)
  #define _MCBSP_RCERG2					PREG16(_MCBSP_RCERG2_ADDR)
  #define _RCERG2						_MCBSP_RCERG2
#endif

/*============================================================================*\
* _MCBSP_RCERG_GET and _MCBSP_RCERG_SET
\*============================================================================*/
#define _MCBSP_RCERG_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_RCERG_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_RCERH0 -  Receive Channel Enable Register Partition H, McBSP #0
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCERH0_ADDR				(0x281Cu)
  #define _MCBSP_RCERH0					PREG16(_MCBSP_RCERH0_ADDR)
  #define _RCERH0						_MCBSP_RCERH0
#else
  #define _MCBSP_RCERH0_ADDR				(0x281Du)
  #define _MCBSP_RCERH0					PREG16(_MCBSP_RCERH0_ADDR)
  #define _RCERH0						_MCBSP_RCERH0
#endif

/*============================================================================*\
* (RW) _MCBSP_RCERH1 -  Receive Channel Enable Register Partition H, McBSP #1
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCERH1_ADDR				(0x2C1Cu)
  #define _MCBSP_RCERH1					PREG16(_MCBSP_RCERH1_ADDR)
  #define _RCERH1						_MCBSP_RCERH1
#else
  #define _MCBSP_RCERH1_ADDR				(0x2C1Du)
  #define _MCBSP_RCERH1					PREG16(_MCBSP_RCERH1_ADDR)
  #define _RCERH1						_MCBSP_RCERH1
#endif

/*============================================================================*\
* (RW) _MCBSP_RCERH2 -  Receive Channel Enable Register Partition H, McBSP #2
\*============================================================================*/
#if (!((CHIP_5502) || (CHIP_5501)))
  #define _MCBSP_RCERH2_ADDR				(0x301Cu)
  #define _MCBSP_RCERH2					PREG16(_MCBSP_RCERH2_ADDR)
  #define _RCERH2						_MCBSP_RCERH2
#else
  #define _MCBSP_RCERH2_ADDR				(0x301Du)
  #define _MCBSP_RCERH2					PREG16(_MCBSP_RCERH2_ADDR)
  #define _RCERH2						_MCBSP_RCERH2
#endif

/*============================================================================*\
* _MCBSP_RCERH_GET and _MCBSP_RCERH_SET
\*============================================================================*/
#define _MCBSP_RCERH_GET(RegAddr)			_PREG_GET(RegAddr)
#define _MCBSP_RCERH_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_DRR10  -  Data Receive Register 1, McBSP #0
\*============================================================================*/
#define _MCBSP_DRR10					PREG16(_MCBSP_DRR10_ADDR)
#define _DRR10						_MCBSP_DRR10

/*============================================================================*\
* (RW) _MCBSP_DRR11  -  Data Receive Register 1, McBSP #1
\*============================================================================*/
#define _MCBSP_DRR11					PREG16(_MCBSP_DRR11_ADDR)
#define _DRR11						_MCBSP_DRR11

/*============================================================================*\
* (RW) _MCBSP_DRR12  -  Data Receive Register 1, McBSP #2
\*============================================================================*/
#define _MCBSP_DRR12					PREG16(_MCBSP_DRR12_ADDR)
#define _DRR12						_MCBSP_DRR12

/*============================================================================*\
* _MCBSP_DRR1_GET and _MCBSP_DRR1_SET
\*============================================================================*/
#define _MCBSP_DRR1_GET(RegAddr)		_PREG_GET(RegAddr)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_DRR20  -  Data Receive Register 2, McBSP #0
\*============================================================================*/
#define _MCBSP_DRR20					PREG16(_MCBSP_DRR20_ADDR)
#define _DRR20						_MCBSP_DRR20

/*============================================================================*\
* (RW) _MCBSP_DRR21  -  Data Receive Register 2, McBSP #1
\*============================================================================*/
#define _MCBSP_DRR21					PREG16(_MCBSP_DRR21_ADDR)
#define _DRR21						_MCBSP_DRR21

/*============================================================================*\
* (RW) _MCBSP_DRR22  -  Data Receive Register 2, McBSP #2
\*============================================================================*/
#define _MCBSP_DRR22					PREG16(_MCBSP_DRR22_ADDR)
#define _DRR22						_MCBSP_DRR22

/*============================================================================*\
* _MCBSP_DRR2_GET
\*============================================================================*/
#define _MCBSP_DRR2_GET(RegAddr)			_PREG_GET(RegAddr)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_DXR10  -  Data Transmit Register 1, McBSP #0
\*============================================================================*/
#define _MCBSP_DXR10					PREG16(_MCBSP_DXR10_ADDR)
#define _DXR10						_MCBSP_DXR10

/*============================================================================*\
* (RW) _MCBSP_DXR11  -  Data Transmit Register 1, McBSP #0
\*============================================================================*/
#define _MCBSP_DXR11					PREG16(_MCBSP_DXR11_ADDR)
#define _DXR11						_MCBSP_DXR11

/*============================================================================*\
* (RW) _MCBSP_DXR12  -  Data Transmit Register 1, McBSP #0
\*============================================================================*/
#define _MCBSP_DXR12					PREG16(_MCBSP_DXR12_ADDR)
#define _DXR12						_MCBSP_DXR12

/*============================================================================*\
* _MCBSP_DXR1_SET
\*============================================================================*/
#define _MCBSP_DXR1_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _MCBSP_DXR20  -  Data Transmit Register 2, McBSP #0
\*============================================================================*/
#define _MCBSP_DXR20					PREG16(_MCBSP_DXR20_ADDR)
#define _DXR20						_MCBSP_DXR20

/*============================================================================*\
* (RW) _MCBSP_DXR21  -  Data Transmit Register 2, McBSP #0
\*============================================================================*/
#define _MCBSP_DXR21					PREG16(_MCBSP_DXR21_ADDR)
#define _DXR21						_MCBSP_DXR21

/*============================================================================*\
* (RW) _MCBSP_DXR22  -  Data Transmit Register 2, McBSP #0
\*============================================================================*/
#define _MCBSP_DXR22					PREG16(_MCBSP_DXR22_ADDR)
#define _DXR22						_MCBSP_DXR22

/*============================================================================*\
* _MCBSP_DXR2_GET and _MCBSP_DXR2_SET
\*============================================================================*/
#define _MCBSP_DXR2_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/*===========================================================================*\
* _MCBSP_SPCR1   - Serial Port Control Register 1
*
* Fields:
*  (RW) _MCBSP_SPCR1_DLB
*  (RW) _MCBSP_SPCR1_RJUST
*  (RW) _MCBSP_SPCR1_CLKSTP
*  (RW) _MCBSP_SPCR1_DXENA
*  (RW) _MCBSP_SPCR1_ABIS
*  (RW) _MCBSP_SPCR1_RINTM
*  (RW) _MCBSP_SPCR1_RSYNCERR
*  (R)  _MCBSP_SPCR1_RFULL
*  (R)  _MCBSP_SPCR1_RRDY
*  (RW) _MCBSP_SPCR1_RRST
\*==========================================================================*/

/*==========================================================================*\
* (RW) _MCBSP_SPCR1_DLB
\*--------------------------------------------------------------------------*/
#define _MCBSP_SPCR1_DLB_SHIFT		(0x000Fu)
#define _MCBSP_SPCR1_DLB_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_SPCR1_DLB_SHIFT)
#define _MCBSP_SPCR1_DLB_MASK       	(_MCBSP_SPCR1_DLB_MK(0x0001u))
#define _MCBSP_SPCR1_DLB_CLR        	(~(_MCBSP_SPCR1_DLB_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_SPCR1_RJUST
\*--------------------------------------------------------------------------*/
#define _MCBSP_SPCR1_RJUST_SHIFT		(0x000Du)
#define _MCBSP_SPCR1_RJUST_MK(n)		(((Uint16)(n) & 0x0003u) << _MCBSP_SPCR1_RJUST_SHIFT)
#define _MCBSP_SPCR1_RJUST_MASK       	(_MCBSP_SPCR1_RJUST_MK(0x0003u))
#define _MCBSP_SPCR1_RJUST_CLR        	(~(_MCBSP_SPCR1_RJUST_MK(0x0003u)))

/*==========================================================================*\
* (RW) _MCBSP_SPCR1_CLKSTP
\*--------------------------------------------------------------------------*/
#define _MCBSP_SPCR1_CLKSTP_SHIFT		(0x000Bu)
#define _MCBSP_SPCR1_CLKSTP_MK(n)		(((Uint16)(n) & 0x0003u) << _MCBSP_SPCR1_CLKSTP_SHIFT)
#define _MCBSP_SPCR1_CLKSTP_MASK       	(_MCBSP_SPCR1_CLKSTP_MK(0x0003u))
#define _MCBSP_SPCR1_CLKSTP_CLR        	(~(_MCBSP_SPCR1_CLKSTP_MK(0x0003u)))

/*==========================================================================*\
* (RW) _MCBSP_SPCR1_DXENA
\*--------------------------------------------------------------------------*/
#define _MCBSP_SPCR1_DXENA_SHIFT		(0x0007u)
#define _MCBSP_SPCR1_DXENA_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_SPCR1_DXENA_SHIFT)
#define _MCBSP_SPCR1_DXENA_MASK       	(_MCBSP_SPCR1_DXENA_MK(0x0001u))
#define _MCBSP_SPCR1_DXENA_CLR        	(~(_MCBSP_SPCR1_DXENA_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_SPCR1_ABIS
\*--------------------------------------------------------------------------*/
#define _MCBSP_SPCR1_ABIS_SHIFT		(0x0006u)
#define _MCBSP_SPCR1_ABIS_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_SPCR1_ABIS_SHIFT)
#define _MCBSP_SPCR1_ABIS_MASK       	(_MCBSP_SPCR1_ABIS_MK(0x0001u))
#define _MCBSP_SPCR1_ABIS_CLR        	(~(_MCBSP_SPCR1_ABIS_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_SPCR1_RINTM
\*--------------------------------------------------------------------------*/
#define _MCBSP_SPCR1_RINTM_SHIFT		(0x0004u)
#define _MCBSP_SPCR1_RINTM_MK(n)		(((Uint16)(n) & 0x0003u) << _MCBSP_SPCR1_RINTM_SHIFT)
#define _MCBSP_SPCR1_RINTM_MASK       	(_MCBSP_SPCR1_RINTM_MK(0x0003u))
#define _MCBSP_SPCR1_RINTM_CLR        	(~(_MCBSP_SPCR1_RINTM_MK(0x0003u)))

/*==========================================================================*\
* (RW) _MCBSP_SPCR1_RSYNCERR
\*--------------------------------------------------------------------------*/
#define _MCBSP_SPCR1_RSYNCERR_SHIFT		(0x0003u)
#define _MCBSP_SPCR1_RSYNCERR_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_SPCR1_RSYNCERR_SHIFT)
#define _MCBSP_SPCR1_RSYNCERR_MASK       	(_MCBSP_SPCR1_RSYNCERR_MK(0x0001u))
#define _MCBSP_SPCR1_RSYNCERR_CLR        	(~(_MCBSP_SPCR1_RSYNCERR_MK(0x0001u)))

/*==========================================================================*\
* (R)  _MCBSP_SPCR1_RFULL
\*--------------------------------------------------------------------------*/
#define _MCBSP_SPCR1_RFULL_SHIFT		(0x0002u)
#define _MCBSP_SPCR1_RFULL_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_SPCR1_RFULL_SHIFT)
#define _MCBSP_SPCR1_RFULL_MASK       	(_MCBSP_SPCR1_RFULL_MK(0x0001u))
#define _MCBSP_SPCR1_RFULL_CLR            (~(_MCBSP_SPCR1_RFULL_MASK))

/*==========================================================================*\
* (R)  _MCBSP_SPCR1_RRDY
\*--------------------------------------------------------------------------*/
#define _MCBSP_SPCR1_RRDY_SHIFT		(0x0001u)
#define _MCBSP_SPCR1_RRDY_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_SPCR1_RRDY_SHIFT)
#define _MCBSP_SPCR1_RRDY_MASK       	(_MCBSP_SPCR1_RRDY_MK(0x0001u))
#define _MCBSP_SPCR1_RRDY_CLR             (~(_MCBSP_SPCR1_RRDY_MASK))

/*==========================================================================*\
* (RW) _MCBSP_SPCR1_RRST
\*--------------------------------------------------------------------------*/
#define _MCBSP_SPCR1_RRST_SHIFT		(0x0000u)
#define _MCBSP_SPCR1_RRST_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_SPCR1_RRST_SHIFT)
#define _MCBSP_SPCR1_RRST_MASK       	(_MCBSP_SPCR1_RRST_MK(0x0001u))
#define _MCBSP_SPCR1_RRST_CLR        	(~(_MCBSP_SPCR1_RRST_MK(0x0001u)))

/*==========================================================================*\
* _MCBSP_SPCR1		- Serial Port Control Register 1
\*--------------------------------------------------------------------------*/
#define _MCBSP_SPCR1_CFG(RegAddr,dlb,rjust,clkstp,dxena,abis,rintm,rsyncerr, \
				rrst) \
	_PREG_SET(RegAddr,							\
    		(Uint16) (	_MCBSP_SPCR1_DLB_MK(dlb) 		|	\
				_MCBSP_SPCR1_RJUST_MK(rjust) 		|	\
				_MCBSP_SPCR1_CLKSTP_MK(clkstp)	|	\
				_MCBSP_SPCR1_DXENA_MK(dxena) 		|	\
				_MCBSP_SPCR1_ABIS_MK(abis) 		|	\
				_MCBSP_SPCR1_RINTM_MK(rintm) 		|	\
				_MCBSP_SPCR1_RSYNCERR_MK(rsyncerr) 	|	\
				_MCBSP_SPCR1_RRST_MK(rrst) 			\
             ))


/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/*===========================================================================*\
* _MCBSP_SPCR2   - Serial Port Control Register 2
*
* Fields:
*  (RW) _MCBSP_SPCR2_FREE
*  (RW) _MCBSP_SPCR2_SOFT
*  (RW) _MCBSP_SPCR2_FRST
*  (RW) _MCBSP_SPCR2_GRST
*  (RW) _MCBSP_SPCR2_XINTM
*  (RW) _MCBSP_SPCR2_XSYNCERR
*  (R)  _MCBSP_SPCR2_XEMPTY
*  (R)  _MCBSP_SPCR2_XRDY
*  (RW) _MCBSP_SPCR2_XRST
\*==========================================================================*/

/*==========================================================================*\
* (RW) _MCBSP_SPCR2_FREE
\*--------------------------------------------------------------------------*/
#define _MCBSP_SPCR2_FREE_SHIFT		(0x0009u)
#define _MCBSP_SPCR2_FREE_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_SPCR2_FREE_SHIFT)
#define _MCBSP_SPCR2_FREE_MASK       	(_MCBSP_SPCR2_FREE_MK(0x0001u))
#define _MCBSP_SPCR2_FREE_CLR        	(~(_MCBSP_SPCR2_FREE_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_SPCR2_SOFT
\*--------------------------------------------------------------------------*/
#define _MCBSP_SPCR2_SOFT_SHIFT		(0x0008u)
#define _MCBSP_SPCR2_SOFT_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_SPCR2_SOFT_SHIFT)
#define _MCBSP_SPCR2_SOFT_MASK       	(_MCBSP_SPCR2_SOFT_MK(0x0001u))
#define _MCBSP_SPCR2_SOFT_CLR        	(~(_MCBSP_SPCR2_SOFT_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_SPCR2_FRST
\*--------------------------------------------------------------------------*/
#define _MCBSP_SPCR2_FRST_SHIFT		(0x0007u)
#define _MCBSP_SPCR2_FRST_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_SPCR2_FRST_SHIFT)
#define _MCBSP_SPCR2_FRST_MASK       	(_MCBSP_SPCR2_FRST_MK(0x0001u))
#define _MCBSP_SPCR2_FRST_CLR        	(~(_MCBSP_SPCR2_FRST_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_SPCR2_GRST
\*--------------------------------------------------------------------------*/
#define _MCBSP_SPCR2_GRST_SHIFT		(0x0006u)
#define _MCBSP_SPCR2_GRST_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_SPCR2_GRST_SHIFT)
#define _MCBSP_SPCR2_GRST_MASK       	(_MCBSP_SPCR2_GRST_MK(0x0001u))
#define _MCBSP_SPCR2_GRST_CLR        	(~(_MCBSP_SPCR2_GRST_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_SPCR2_XINTM
\*--------------------------------------------------------------------------*/
#define _MCBSP_SPCR2_XINTM_SHIFT		(0x0004u)
#define _MCBSP_SPCR2_XINTM_MK(n)		(((Uint16)(n) & 0x0003u) << _MCBSP_SPCR2_XINTM_SHIFT)
#define _MCBSP_SPCR2_XINTM_MASK       	(_MCBSP_SPCR2_XINTM_MK(0x0003u))
#define _MCBSP_SPCR2_XINTM_CLR        	(~(_MCBSP_SPCR2_XINTM_MK(0x0003u)))

/*==========================================================================*\
* (RW) _MCBSP_SPCR2_XSYNCERR
\*--------------------------------------------------------------------------*/
#define _MCBSP_SPCR2_XSYNCERR_SHIFT		(0x0003u)
#define _MCBSP_SPCR2_XSYNCERR_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_SPCR2_XSYNCERR_SHIFT)
#define _MCBSP_SPCR2_XSYNCERR_MASK       	(_MCBSP_SPCR2_XSYNCERR_MK(0x0001u))
#define _MCBSP_SPCR2_XSYNCERR_CLR        	(~(_MCBSP_SPCR2_XSYNCERR_MK(0x0001u)))

/*==========================================================================*\
* (R) _MCBSP_SPCR2_XEMPTY
\*--------------------------------------------------------------------------*/
#define _MCBSP_SPCR2_XEMPTY_SHIFT		(0x0002u)
#define _MCBSP_SPCR2_XEMPTY_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_SPCR2_XEMPTY_SHIFT)
#define _MCBSP_SPCR2_XEMPTY_MASK       	(_MCBSP_SPCR2_XEMPTY_MK(0x0001u))
#define _MCBSP_SPCR2_XEMPTY_CLR           (~(_MCBSP_SPCR2_XEMPTY_MASK))

/*==========================================================================*\
* (R) _MCBSP_SPCR2_XRDY
\*--------------------------------------------------------------------------*/
#define _MCBSP_SPCR2_XRDY_SHIFT		(0x0001u)
#define _MCBSP_SPCR2_XRDY_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_SPCR2_XRDY_SHIFT)
#define _MCBSP_SPCR2_XRDY_MASK       	(_MCBSP_SPCR2_XRDY_MK(0x0001u))
#define _MCBSP_SPCR2_XRDY_CLR        	(~(_MCBSP_SPCR2_XRDY_MASK))

/*==========================================================================*\
* (RW) _MCBSP_SPCR2_XRST
\*--------------------------------------------------------------------------*/
#define _MCBSP_SPCR2_XRST_SHIFT		(0x0000u)
#define _MCBSP_SPCR2_XRST_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_SPCR2_XRST_SHIFT)
#define _MCBSP_SPCR2_XRST_MASK       	(_MCBSP_SPCR2_XRST_MK(0x0001u))
#define _MCBSP_SPCR2_XRST_CLR        	(~(_MCBSP_SPCR2_XRST_MK(0x0001u)))

/*==========================================================================*\
* _MCBSP_SPCR2		- Serial Port Control Register 2
\*--------------------------------------------------------------------------*/
#define _MCBSP_SPCR2_CFG(RegAddr,free,soft,frst,grst,xintm,xsyncerr,xrst) \
	_PREG_SET(RegAddr,							\
    		(Uint16) (	_MCBSP_SPCR2_FREE_MK(free) 		|	\
				_MCBSP_SPCR2_SOFT_MK(soft) 		|	\
				_MCBSP_SPCR2_FRST_MK(frst)		|	\
				_MCBSP_SPCR2_GRST_MK(grst) 		|	\
				_MCBSP_SPCR2_XINTM_MK(xintm) 		|	\
				_MCBSP_SPCR2_XSYNCERR_MK(xsyncerr) 	|	\
				_MCBSP_SPCR2_XRST_MK(xrst) 			\
             ))


/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/*===========================================================================/
* _MCBSP_PCR   - Pin Control Register
*
* Fields:
*  (RW) _MCBSP_PCR_SCLKME
*  (R)  _MCBSP_PCR_CLKSSTAT
*  (RW) _MCBSP_PCR_DXSTAT
*  (R)  _MCBSP_PCR_DRSTAT
*  (RW) _MCBSP_PCR_FSXP
*  (RW) _MCBSP_PCR_FSRP
*  (RW) _MCBSP_PCR_CLKXP
*  (RW) _MCBSP_PCR_CLKRP
*  (RW) _MCBSP_PCR_IDLEEN
*  (RW) _MCBSP_PCR_XIOEN
*  (RW) _MCBSP_PCR_RIOEN
*  (RW) _MCBSP_PCR_FSXM
*  (RW) _MCBSP_PCR_FSRM
*  (RW) _MCBSP_PCR_CLKXM
*  (RW) _MCBSP_PCR_CLKRM
\*==========================================================================*/

/*==========================================================================*\
* (RW) _MCBSP_PCR_SCLKME
\*--------------------------------------------------------------------------*/
#define _MCBSP_PCR_SCLKME_SHIFT		(0x0007u)
#define _MCBSP_PCR_SCLKME_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_PCR_SCLKME_SHIFT)
#define _MCBSP_PCR_SCLKME_MASK       	(_MCBSP_PCR_SCLKME_MK(0x0001u))
#define _MCBSP_PCR_SCLKME_CLR        	(~(_MCBSP_PCR_SCLKME_MK(0x0001u)))

/*==========================================================================*\
* (R)  _MCBSP_PCR_CLKSSTAT
\*--------------------------------------------------------------------------*/
#define _MCBSP_PCR_CLKSSTAT_SHIFT		(0x0006u)
#define _MCBSP_PCR_CLKSSTAT_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_PCR_CLKSSTAT_SHIFT)
#define _MCBSP_PCR_CLKSSTAT_MASK       	(_MCBSP_PCR_CLKSSTAT_MK(0x0001u))
#define _MCBSP_PCR_CLKSSTAT_CLR       	(~(_MCBSP_PCR_CLKSSTAT_MASK))

/*==========================================================================*\
* (RW) _MCBSP_PCR_DXSTAT
\*--------------------------------------------------------------------------*/
#define _MCBSP_PCR_DXSTAT_SHIFT		(0x0005u)
#define _MCBSP_PCR_DXSTAT_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_PCR_DXSTAT_SHIFT)
#define _MCBSP_PCR_DXSTAT_MASK       	(_MCBSP_PCR_DXSTAT_MK(0x0001u))
#define _MCBSP_PCR_DXSTAT_CLR        	(~(_MCBSP_PCR_DXSTAT_MK(0x0001u)))

/*==========================================================================*\
* (R)  _MCBSP_PCR_DRSTAT
\*--------------------------------------------------------------------------*/
#define _MCBSP_PCR_DRSTAT_SHIFT		(0x0004u)
#define _MCBSP_PCR_DRSTAT_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_PCR_DRSTAT_SHIFT)
#define _MCBSP_PCR_DRSTAT_MASK       	(_MCBSP_PCR_DRSTAT_MK(0x0001u))
#define _MCBSP_PCR_DRSTAT_CLR       	(~(_MCBSP_PCR_DRSTAT_MASK))

/*==========================================================================*\
* (RW) _MCBSP_PCR_FSXP
\*--------------------------------------------------------------------------*/
#define _MCBSP_PCR_FSXP_SHIFT		(0x0003u)
#define _MCBSP_PCR_FSXP_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_PCR_FSXP_SHIFT)
#define _MCBSP_PCR_FSXP_MASK       	(_MCBSP_PCR_FSXP_MK(0x0001u))
#define _MCBSP_PCR_FSXP_CLR        	(~(_MCBSP_PCR_FSXP_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_PCR_FSRP
\*--------------------------------------------------------------------------*/
#define _MCBSP_PCR_FSRP_SHIFT		(0x0002u)
#define _MCBSP_PCR_FSRP_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_PCR_FSRP_SHIFT)
#define _MCBSP_PCR_FSRP_MASK       	(_MCBSP_PCR_FSRP_MK(0x0001u))
#define _MCBSP_PCR_FSRP_CLR        	(~(_MCBSP_PCR_FSRP_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_PCR_CLKXP
\*--------------------------------------------------------------------------*/
#define _MCBSP_PCR_CLKXP_SHIFT		(0x0001u)
#define _MCBSP_PCR_CLKXP_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_PCR_CLKXP_SHIFT)
#define _MCBSP_PCR_CLKXP_MASK       	(_MCBSP_PCR_CLKXP_MK(0x0001u))
#define _MCBSP_PCR_CLKXP_CLR        	(~(_MCBSP_PCR_CLKXP_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_PCR_CLKRP
\*--------------------------------------------------------------------------*/
#define _MCBSP_PCR_CLKRP_SHIFT		(0x0000u)
#define _MCBSP_PCR_CLKRP_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_PCR_CLKRP_SHIFT)
#define _MCBSP_PCR_CLKRP_MASK       	(_MCBSP_PCR_CLKRP_MK(0x0001u))
#define _MCBSP_PCR_CLKRP_CLR        	(~(_MCBSP_PCR_CLKRP_MK(0x0001u)))

#if (!((CHIP_5502) || (CHIP_5501)))

/*==========================================================================*\
* (RW) _MCBSP_PCR_IDLEEN
\*--------------------------------------------------------------------------*/
#define _MCBSP_PCR_IDLEEN_SHIFT		(0x000Eu)
#define _MCBSP_PCR_IDLEEN_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_PCR_IDLEEN_SHIFT)
#define _MCBSP_PCR_IDLEEN_MASK       	(_MCBSP_PCR_IDLEEN_MK(0x0001u))
#define _MCBSP_PCR_IDLEEN_CLR        	(~(_MCBSP_PCR_IDLEEN_MK(0x0001u)))

#endif

/*==========================================================================*\
* (RW) _MCBSP_PCR_XIOEN
\*--------------------------------------------------------------------------*/
#define _MCBSP_PCR_XIOEN_SHIFT		(0x000Du)
#define _MCBSP_PCR_XIOEN_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_PCR_XIOEN_SHIFT)
#define _MCBSP_PCR_XIOEN_MASK       	(_MCBSP_PCR_XIOEN_MK(0x0001u))
#define _MCBSP_PCR_XIOEN_CLR        	(~(_MCBSP_PCR_XIOEN_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_PCR_RIOEN
\*--------------------------------------------------------------------------*/
#define _MCBSP_PCR_RIOEN_SHIFT		(0x000Cu)
#define _MCBSP_PCR_RIOEN_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_PCR_RIOEN_SHIFT)
#define _MCBSP_PCR_RIOEN_MASK       	(_MCBSP_PCR_RIOEN_MK(0x0001u))
#define _MCBSP_PCR_RIOEN_CLR        	(~(_MCBSP_PCR_RIOEN_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_PCR_FSXM
\*--------------------------------------------------------------------------*/
#define _MCBSP_PCR_FSXM_SHIFT		(0x000Bu)
#define _MCBSP_PCR_FSXM_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_PCR_FSXM_SHIFT)
#define _MCBSP_PCR_FSXM_MASK       	(_MCBSP_PCR_FSXM_MK(0x0001u))
#define _MCBSP_PCR_FSXM_CLR        	(~(_MCBSP_PCR_FSXM_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_PCR_FSRM
\*--------------------------------------------------------------------------*/
#define _MCBSP_PCR_FSRM_SHIFT		(0x000Au)
#define _MCBSP_PCR_FSRM_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_PCR_FSRM_SHIFT)
#define _MCBSP_PCR_FSRM_MASK       	(_MCBSP_PCR_FSRM_MK(0x0001u))
#define _MCBSP_PCR_FSRM_CLR        	(~(_MCBSP_PCR_FSRM_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_PCR_CLKXM
\*--------------------------------------------------------------------------*/
#define _MCBSP_PCR_CLKXM_SHIFT		(0x0009u)
#define _MCBSP_PCR_CLKXM_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_PCR_CLKXM_SHIFT)
#define _MCBSP_PCR_CLKXM_MASK       	(_MCBSP_PCR_CLKXM_MK(0x0001u))
#define _MCBSP_PCR_CLKXM_CLR        	(~(_MCBSP_PCR_CLKXM_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_PCR_CLKRM
\*--------------------------------------------------------------------------*/
#define _MCBSP_PCR_CLKRM_SHIFT		(0x0008u)
#define _MCBSP_PCR_CLKRM_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_PCR_CLKRM_SHIFT)
#define _MCBSP_PCR_CLKRM_MASK       	(_MCBSP_PCR_CLKRM_MK(0x0001u))
#define _MCBSP_PCR_CLKRM_CLR        	(~(_MCBSP_PCR_CLKRM_MK(0x0001u)))

/*==========================================================================*\
* _MCBSP_PCR		- Pin Control Register
\*--------------------------------------------------------------------------*/
#if (CHIP_5502) || (CHIP_5501)

#define _MCBSP_PCR_CFG(RegAddr,xioen,rioen,fsxm,fsrm,clkxm,clkrm,\
						sclkme,dxstat,fsxp,fsrp,clkxp,clkrp) \
	_PREG_SET(RegAddr,							\
    		(Uint16) (	_MCBSP_PCR_SCLKME_MK(sclkme) 		|	\
				_MCBSP_PCR_DXSTAT_MK(dxstat) 		|	\
				_MCBSP_PCR_FSXP_MK(fsxp) 		|	\
				_MCBSP_PCR_FSRP_MK(fsrp) 		|	\
				_MCBSP_PCR_CLKXP_MK(clkxp) 		|	\
				_MCBSP_PCR_CLKRP_MK(clkrp) 		|	\
				_MCBSP_PCR_XIOEN_MK(xioen) 		|	\
				_MCBSP_PCR_RIOEN_MK(rioen) 		|	\
				_MCBSP_PCR_FSXM_MK(fsxm) 		|	\
				_MCBSP_PCR_FSRM_MK(fsrm) 		|	\
				_MCBSP_PCR_CLKXM_MK(clkxm) 		|	\
				_MCBSP_PCR_CLKRM_MK(clkrm) 			\
             ))

#else

#define _MCBSP_PCR_CFG(RegAddr,idleen,xioen,rioen,fsxm,fsrm,clkxm,clkrm,\
						sclkme,dxstat,fsxp,fsrp,clkxp,clkrp) \
	_PREG_SET(RegAddr,							\
    		(Uint16) (	_MCBSP_PCR_SCLKME_MK(sclkme) 		|	\
				_MCBSP_PCR_DXSTAT_MK(dxstat) 		|	\
				_MCBSP_PCR_FSXP_MK(fsxp) 		|	\
				_MCBSP_PCR_FSRP_MK(fsrp) 		|	\
				_MCBSP_PCR_CLKXP_MK(clkxp) 		|	\
				_MCBSP_PCR_CLKRP_MK(clkrp) 		|	\
				_MCBSP_PCR_IDLEEN_MK(idleen) 		|	\
				_MCBSP_PCR_XIOEN_MK(xioen) 		|	\
				_MCBSP_PCR_RIOEN_MK(rioen) 		|	\
				_MCBSP_PCR_FSXM_MK(fsxm) 		|	\
				_MCBSP_PCR_FSRM_MK(fsrm) 		|	\
				_MCBSP_PCR_CLKXM_MK(clkxm) 		|	\
				_MCBSP_PCR_CLKRM_MK(clkrm) 			\
             ))

#endif

/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/*===========================================================================*\
* _MCBSP_RCR1   - Receive Control Register 2
*
* Fields:
*  (RW) _MCBSP_RCR1_RFRLEN1
*  (RW) _MCBSP_RCR1_RWDLEN1
\*==========================================================================*/

/*==========================================================================*\
* (RW) _MCBSP_RCR1_RFRLEN1
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCR1_RFRLEN1_SHIFT		(0x0008u)
#define _MCBSP_RCR1_RFRLEN1_MK(n)		(((Uint16)(n) & 0x007Fu) << _MCBSP_RCR1_RFRLEN1_SHIFT)
#define _MCBSP_RCR1_RFRLEN1_MASK       	(_MCBSP_RCR1_RFRLEN1_MK(0x007Fu))
#define _MCBSP_RCR1_RFRLEN1_CLR        	(~(_MCBSP_RCR1_RFRLEN1_MK(0x007Fu)))

/*==========================================================================*\
* (RW) _MCBSP_RCR1_RWDLEN1
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCR1_RWDLEN1_SHIFT		(0x0005u)
#define _MCBSP_RCR1_RWDLEN1_MK(n)		(((Uint16)(n) & 0x0007u) << _MCBSP_RCR1_RWDLEN1_SHIFT)
#define _MCBSP_RCR1_RWDLEN1_MASK       	(_MCBSP_RCR1_RWDLEN1_MK(0x0007u))
#define _MCBSP_RCR1_RWDLEN1_CLR        	(~(_MCBSP_RCR1_RWDLEN1_MK(0x0007u)))

/*==========================================================================*\
* _MCBSP_RCR1		- Receive Control Register 1 Config
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCR1_CFG(RegAddr,rfrlen1,rwdlen1) \
	_PREG_SET(RegAddr,							\
    		(Uint16) (	_MCBSP_RCR1_RFRLEN1_MK(rfrlen1) 		|	\
				_MCBSP_RCR1_RWDLEN1_MK(rwdlen1) 			\
             ))

/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/*===========================================================================*\
* _MCBSP_RCR2   - Receive Control Register 2
*
* Fields:
*  (RW) _MCBSP_RCR2_RPHASE
*  (RW) _MCBSP_RCR2_RFRLEN2
*  (RW) _MCBSP_RCR2_RWDLEN2
*  (RW) _MCBSP_RCR2_RCOMPAND
*  (RW) _MCBSP_RCR2_RFIG
*  (RW) _MCBSP_RCR2_RDATDLY
\*==========================================================================*/

/*==========================================================================*\
* (RW) _MCBSP_RCR2_RPHASE
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCR2_RPHASE_SHIFT		(0x000Fu)
#define _MCBSP_RCR2_RPHASE_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_RCR2_RPHASE_SHIFT)
#define _MCBSP_RCR2_RPHASE_MASK       	(_MCBSP_RCR2_RPHASE_MK(0x0001u))
#define _MCBSP_RCR2_RPHASE_CLR        	(~(_MCBSP_RCR2_RPHASE_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_RCR2_RFRLEN2
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCR2_RFRLEN2_SHIFT		(0x0008u)
#define _MCBSP_RCR2_RFRLEN2_MK(n)		(((Uint16)(n) & 0x007Fu) << _MCBSP_RCR2_RFRLEN2_SHIFT)
#define _MCBSP_RCR2_RFRLEN2_MASK       	(_MCBSP_RCR2_RFRLEN2_MK(0x007Fu))
#define _MCBSP_RCR2_RFRLEN2_CLR        	(~(_MCBSP_RCR2_RFRLEN2_MK(0x007Fu)))

/*==========================================================================*\
* (RW) _MCBSP_RCR2_RWDLEN2
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCR2_RWDLEN2_SHIFT		(0x0005u)
#define _MCBSP_RCR2_RWDLEN2_MK(n)		(((Uint16)(n) & 0x0007u) << _MCBSP_RCR2_RWDLEN2_SHIFT)
#define _MCBSP_RCR2_RWDLEN2_MASK       	(_MCBSP_RCR2_RWDLEN2_MK(0x0007u))
#define _MCBSP_RCR2_RWDLEN2_CLR        	(~(_MCBSP_RCR2_RWDLEN2_MK(0x0007u)))

/*==========================================================================*\
* (RW) _MCBSP_RCR2_RCOMPAND
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCR2_RCOMPAND_SHIFT		(0x0003u)
#define _MCBSP_RCR2_RCOMPAND_MK(n)		(((Uint16)(n) & 0x0003u) << _MCBSP_RCR2_RCOMPAND_SHIFT)
#define _MCBSP_RCR2_RCOMPAND_MASK       	(_MCBSP_RCR2_RCOMPAND_MK(0x0003u))
#define _MCBSP_RCR2_RCOMPAND_CLR        	(~(_MCBSP_RCR2_RCOMPAND_MK(0x0003u)))

/*==========================================================================*\
* (RW) _MCBSP_RCR2_RFIG
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCR2_RFIG_SHIFT		(0x0002u)
#define _MCBSP_RCR2_RFIG_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_RCR2_RFIG_SHIFT)
#define _MCBSP_RCR2_RFIG_MASK       	(_MCBSP_RCR2_RFIG_MK(0x0001u))
#define _MCBSP_RCR2_RFIG_CLR        	(~(_MCBSP_RCR2_RFIG_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_RCR2_RDATDLY
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCR2_RDATDLY_SHIFT		(0x0000u)
#define _MCBSP_RCR2_RDATDLY_MK(n)		(((Uint16)(n) & 0x0003u) << _MCBSP_RCR2_RDATDLY_SHIFT)
#define _MCBSP_RCR2_RDATDLY_MASK       	(_MCBSP_RCR2_RDATDLY_MK(0x0003u))
#define _MCBSP_RCR2_RDATDLY_CLR        	(~(_MCBSP_RCR2_RDATDLY_MK(0x0003u)))

/*==========================================================================*\
* _MCBSP_RCR2		- Receive Control Register 2 Config
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCR2_CFG(RegAddr,rphase,rfrlen2,rwdlen2,rcompand,rfig,rdatdly) \
	_PREG_SET(RegAddr,							\
    		(Uint16) (	_MCBSP_RCR2_RPHASE_MK(rphase)	 		|	\
				_MCBSP_RCR2_RFRLEN2_MK(rfrlen2) 		|	\
				_MCBSP_RCR2_RWDLEN2_MK(rwdlen2) 		|	\
				_MCBSP_RCR2_RCOMPAND_MK(rcompand) 		|	\
				_MCBSP_RCR2_RFIG_MK(rfig) 			|	\
				_MCBSP_RCR2_RDATDLY_MK(rdatdly) 			\
             ))


/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/*===========================================================================*\
* _MCBSP_XCR1   - Transmit Control Register 1
*
* Fields:
*  (RW) _MCBSP_XCR1_XFRLEN1
*  (RW) _MCBSP_XCR1_XWDLEN1
\*==========================================================================*/

/*==========================================================================*\
* (RW) _MCBSP_XCR1_XFRLEN1
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCR1_XFRLEN1_SHIFT		(0x0008u)
#define _MCBSP_XCR1_XFRLEN1_MK(n)		(((Uint16)(n) & 0x007Fu) << _MCBSP_XCR1_XFRLEN1_SHIFT)
#define _MCBSP_XCR1_XFRLEN1_MASK       	(_MCBSP_XCR1_XFRLEN1_MK(0x007Fu))
#define _MCBSP_XCR1_XFRLEN1_CLR        	(~(_MCBSP_XCR1_XFRLEN1_MK(0x007Fu)))

/*==========================================================================*\
* (RW) _MCBSP_XCR1_XWDLEN1
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCR1_XWDLEN1_SHIFT		(0x0005u)
#define _MCBSP_XCR1_XWDLEN1_MK(n)		(((Uint16)(n) & 0x0007u) << _MCBSP_XCR1_XWDLEN1_SHIFT)
#define _MCBSP_XCR1_XWDLEN1_MASK       	(_MCBSP_XCR1_XWDLEN1_MK(0x0007u))
#define _MCBSP_XCR1_XWDLEN1_CLR        	(~(_MCBSP_XCR1_XWDLEN1_MK(0x0007u)))

/*==========================================================================*\
* _MCBSP_XCR1	- Transmit Control Register 1
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCR1_CFG(RegAddr,xfrlen1,xwdlen1) \
	_PREG_SET(RegAddr,							\
    		(Uint16) (	_MCBSP_XCR1_XFRLEN1_MK(xfrlen1)	|	\
				_MCBSP_XCR1_XWDLEN1_MK(xwdlen1)		\
             ))


/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/*===========================================================================*\
* _MCBSP_XCR2   - Transmit Control Register 2
*
* Fields:
*  (RW) _MCBSP_XCR2_XPHASE
*  (RW) _MCBSP_XCR2_XFRLEN2
*  (RW) _MCBSP_XCR2_XWDLEN2
*  (RW) _MCBSP_XCR2_XCOMPAND
*  (RW) _MCBSP_XCR2_XFIG
*  (RW) _MCBSP_XCR2_XDATDLY
\*==========================================================================*/

/*==========================================================================*\
* (RW) _MCBSP_XCR2_XPHASE
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCR2_XPHASE_SHIFT		(0x000Fu)
#define _MCBSP_XCR2_XPHASE_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_XCR2_XPHASE_SHIFT)
#define _MCBSP_XCR2_XPHASE_MASK       	(_MCBSP_XCR2_XPHASE_MK(0x0001u))
#define _MCBSP_XCR2_XPHASE_CLR        	(~(_MCBSP_XCR2_XPHASE_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_XCR2_XFRLEN2
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCR2_XFRLEN2_SHIFT		(0x0008u)
#define _MCBSP_XCR2_XFRLEN2_MK(n)		(((Uint16)(n) & 0x007Fu) << _MCBSP_XCR2_XFRLEN2_SHIFT)
#define _MCBSP_XCR2_XFRLEN2_MASK       	(_MCBSP_XCR2_XFRLEN2_MK(0x007Fu))
#define _MCBSP_XCR2_XFRLEN2_CLR        	(~(_MCBSP_XCR2_XFRLEN2_MK(0x007Fu)))

/*==========================================================================*\
* (RW) _MCBSP_XCR2_XWDLEN2
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCR2_XWDLEN2_SHIFT		(0x0005u)
#define _MCBSP_XCR2_XWDLEN2_MK(n)		(((Uint16)(n) & 0x0007u) << _MCBSP_XCR2_XWDLEN2_SHIFT)
#define _MCBSP_XCR2_XWDLEN2_MASK       	(_MCBSP_XCR2_XWDLEN2_MK(0x0007u))
#define _MCBSP_XCR2_XWDLEN2_CLR        	(~(_MCBSP_XCR2_XWDLEN2_MK(0x0007u)))

/*==========================================================================*\
* (RW) _MCBSP_XCR2_XCOMPAND
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCR2_XCOMPAND_SHIFT		(0x0003u)
#define _MCBSP_XCR2_XCOMPAND_MK(n)		(((Uint16)(n) & 0x0003u) << _MCBSP_XCR2_XCOMPAND_SHIFT)
#define _MCBSP_XCR2_XCOMPAND_MASK       	(_MCBSP_XCR2_XCOMPAND_MK(0x0003u))
#define _MCBSP_XCR2_XCOMPAND_CLR        	(~(_MCBSP_XCR2_XCOMPAND_MK(0x0003u)))

/*==========================================================================*\
* (RW) _MCBSP_XCR2_XFIG
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCR2_XFIG_SHIFT		(0x0002u)
#define _MCBSP_XCR2_XFIG_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_XCR2_XFIG_SHIFT)
#define _MCBSP_XCR2_XFIG_MASK       	(_MCBSP_XCR2_XFIG_MK(0x0001u))
#define _MCBSP_XCR2_XFIG_CLR        	(~(_MCBSP_XCR2_XFIG_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_XCR2_XDATDLY
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCR2_XDATDLY_SHIFT		(0x0000u)
#define _MCBSP_XCR2_XDATDLY_MK(n)		(((Uint16)(n) & 0x0003u) << _MCBSP_XCR2_XDATDLY_SHIFT)
#define _MCBSP_XCR2_XDATDLY_MASK       	(_MCBSP_XCR2_XDATDLY_MK(0x0003u))
#define _MCBSP_XCR2_XDATDLY_CLR        	(~(_MCBSP_XCR2_XDATDLY_MK(0x0003u)))

/*==========================================================================*\
* _MCBSP_XCR2	- Transmit Control Register 2
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCR2_CFG(RegAddr,xphase,xfrlen2,xwdlen2,xcompand,xfig,xdatdly) \
	_PREG_SET(RegAddr,							\
    		(Uint16) (	_MCBSP_XCR2_XPHASE_MK(xphase)	|	\
				_MCBSP_XCR2_XFRLEN2_MK(xfrlen2)	|	\
				_MCBSP_XCR2_XWDLEN2_MK(xwdlen2)	|	\
				_MCBSP_XCR2_XCOMPAND_MK(xcompand)	|	\
				_MCBSP_XCR2_XFIG_MK(xfig)		|	\
				_MCBSP_XCR2_XDATDLY_MK(xdatdly)		\
             ))


/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/*===========================================================================*\
* _MCBSP_SRGR1 -  Sample Rate Generator Register 1
*
* Fields:
*  (RW) _MCBSP_SRGR1_FWID
*  (RW) _MCBSP_SRGR1_CLKGDV
\*==========================================================================*/

/*==========================================================================*\
* (RW) _MCBSP_SRGR1_FWID
\*--------------------------------------------------------------------------*/
#define _MCBSP_SRGR1_FWID_SHIFT		(0x0008u)
#define _MCBSP_SRGR1_FWID_MK(n)		(((Uint16)(n) & 0x00FFu) << _MCBSP_SRGR1_FWID_SHIFT)
#define _MCBSP_SRGR1_FWID_MASK       	(_MCBSP_SRGR1_FWID_MK(0x00FFu))
#define _MCBSP_SRGR1_FWID_CLR        	(~(_MCBSP_SRGR1_FWID_MK(0x00FFu)))

/*==========================================================================*\
* (RW) _MCBSP_SRGR1_CLKGDV
\*--------------------------------------------------------------------------*/
#define _MCBSP_SRGR1_CLKGDV_SHIFT		(0x0000u)
#define _MCBSP_SRGR1_CLKGDV_MK(n)		(((Uint16)(n) & 0x00FFu) << _MCBSP_SRGR1_CLKGDV_SHIFT)
#define _MCBSP_SRGR1_CLKGDV_MASK       	(_MCBSP_SRGR1_CLKGDV_MK(0x00FFu))
#define _MCBSP_SRGR1_CLKGDV_CLR        	(~(_MCBSP_SRGR1_CLKGDV_MK(0x00FFu)))

/*==========================================================================*\
* _MCBSP_SRGR1	- Sample Rate Generator Register 1
\*--------------------------------------------------------------------------*/
#define _MCBSP_SRGR1_CFG(RegAddr,fwid,clkgdv) \
	_PREG_SET(RegAddr,							\
    		(Uint16) (	_MCBSP_SRGR1_FWID_MK(fwid)		|	\
				_MCBSP_SRGR1_CLKGDV_MK(clkgdv)		\
             ))

/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/*===========================================================================*\
* _MCBSP_SRGR2 -  Sample Rate Generator Register 2
*
* Fields:
*  (RW) _MCBSP_SRGR2_GSYNC
*  (RW) _MCBSP_SRGR2_CLKSP
*  (RW) _MCBSP_SRGR2_CLKSM
*  (RW) _MCBSP_SRGR2_FSGM
*  (RW) _MCBSP_SRGR2_FPER
\*==========================================================================*/

/*==========================================================================*\
* (RW) _MCBSP_SRGR2_GSYNC
\*--------------------------------------------------------------------------*/
#define _MCBSP_SRGR2_GSYNC_SHIFT		(0x000Fu)
#define _MCBSP_SRGR2_GSYNC_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_SRGR2_GSYNC_SHIFT)
#define _MCBSP_SRGR2_GSYNC_MASK       	(_MCBSP_SRGR2_GSYNC_MK(0x0001u))
#define _MCBSP_SRGR2_GSYNC_CLR        	(~(_MCBSP_SRGR2_GSYNC_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_SRGR2_CLKSP
\*--------------------------------------------------------------------------*/
#define _MCBSP_SRGR2_CLKSP_SHIFT		(0x000Eu)
#define _MCBSP_SRGR2_CLKSP_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_SRGR2_CLKSP_SHIFT)
#define _MCBSP_SRGR2_CLKSP_MASK       	(_MCBSP_SRGR2_CLKSP_MK(0x0001u))
#define _MCBSP_SRGR2_CLKSP_CLR        	(~(_MCBSP_SRGR2_CLKSP_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_SRGR2_CLKSM
\*--------------------------------------------------------------------------*/
#define _MCBSP_SRGR2_CLKSM_SHIFT		(0x000Du)
#define _MCBSP_SRGR2_CLKSM_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_SRGR2_CLKSM_SHIFT)
#define _MCBSP_SRGR2_CLKSM_MASK       	(_MCBSP_SRGR2_CLKSM_MK(0x0001u))
#define _MCBSP_SRGR2_CLKSM_CLR        	(~(_MCBSP_SRGR2_CLKSM_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_SRGR2_FSGM
\*--------------------------------------------------------------------------*/
#define _MCBSP_SRGR2_FSGM_SHIFT		(0x000Cu)
#define _MCBSP_SRGR2_FSGM_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_SRGR2_FSGM_SHIFT)
#define _MCBSP_SRGR2_FSGM_MASK       	(_MCBSP_SRGR2_FSGM_MK(0x0001u))
#define _MCBSP_SRGR2_FSGM_CLR        	(~(_MCBSP_SRGR2_FSGM_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_SRGR2_FPER
\*--------------------------------------------------------------------------*/
#define _MCBSP_SRGR2_FPER_SHIFT		(0x0000u)
#define _MCBSP_SRGR2_FPER_MK(n)		(((Uint16)(n) & 0x0FFFu) << _MCBSP_SRGR2_FPER_SHIFT)
#define _MCBSP_SRGR2_FPER_MASK       	(_MCBSP_SRGR2_FPER_MK(0x0FFFu))
#define _MCBSP_SRGR2_FPER_CLR        	(~(_MCBSP_SRGR2_FPER_MK(0x0FFFu)))

/*==========================================================================*\
* _MCBSP_SRGR2	- Sample Rate Generator Register 2
\*--------------------------------------------------------------------------*/
#define _MCBSP_SRGR2_CFG(RegAddr,gsync,clksp,clksm,fsgm,fper) \
	_PREG_SET(RegAddr,							\
    		(Uint16) (	_MCBSP_SRGR2_GSYNC_MK(gsync)		|	\
				_MCBSP_SRGR2_CLKSP_MK(clksp)		|	\
				_MCBSP_SRGR2_CLKSM_MK(clksm)		|	\
				_MCBSP_SRGR2_FSGM_MK(fsgm)		|	\
				_MCBSP_SRGR2_FPER_MK(fper)			\
             ))

/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/*===========================================================================*\
* _MCBSP_MCR1 -  Multi-channel Control Register 1
*
* Fields:
*  (RW) _MCBSP_MCR1_RMCME
*  (RW) _MCBSP_MCR1_RPBBLK
*  (RW) _MCBSP_MCR1_RPABLK
*  (R)  _MCBSP_MCR1_RCBLK
*  (RW) _MCBSP_MCR1_RMCM
\*==========================================================================*/

/*==========================================================================*\
* (RW) _MCBSP_MCR1_RMCME
\*--------------------------------------------------------------------------*/
#define _MCBSP_MCR1_RMCME_SHIFT		(0x0009u)
#define _MCBSP_MCR1_RMCME_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_MCR1_RMCME_SHIFT)
#define _MCBSP_MCR1_RMCME_MASK       	(_MCBSP_MCR1_RMCME_MK(0x0001u))
#define _MCBSP_MCR1_RMCME_CLR        	(~(_MCBSP_MCR1_RMCME_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_MCR1_RPBBLK
\*--------------------------------------------------------------------------*/
#define _MCBSP_MCR1_RPBBLK_SHIFT		(0x0007u)
#define _MCBSP_MCR1_RPBBLK_MK(n)		(((Uint16)(n) & 0x0003u) << _MCBSP_MCR1_RPBBLK_SHIFT)
#define _MCBSP_MCR1_RPBBLK_MASK       	(_MCBSP_MCR1_RPBBLK_MK(0x0003u))
#define _MCBSP_MCR1_RPBBLK_CLR        	(~(_MCBSP_MCR1_RPBBLK_MK(0x0003u)))

/*==========================================================================*\
* (RW) _MCBSP_MCR1_RPABLK
\*--------------------------------------------------------------------------*/
#define _MCBSP_MCR1_RPABLK_SHIFT		(0x0005u)
#define _MCBSP_MCR1_RPABLK_MK(n)		(((Uint16)(n) & 0x0003u) << _MCBSP_MCR1_RPABLK_SHIFT)
#define _MCBSP_MCR1_RPABLK_MASK       	(_MCBSP_MCR1_RPABLK_MK(0x0003u))
#define _MCBSP_MCR1_RPABLK_CLR        	(~(_MCBSP_MCR1_RPABLK_MK(0x0003u)))

/*==========================================================================*\
* (R) _MCBSP_MCR1_RCBLK
\*--------------------------------------------------------------------------*/
#define _MCBSP_MCR1_RCBLK_SHIFT		(0x0002u)
#define _MCBSP_MCR1_RCBLK_MK(n)		(((Uint16)(n) & 0x0007u) << _MCBSP_MCR1_RCBLK_SHIFT)
#define _MCBSP_MCR1_RCBLK_MASK       	(_MCBSP_MCR1_RCBLK_MK(0x0007u))
#define _MCBSP_MCR1_RCBLK_CLR       	(~(_MCBSP_MCR1_RCBLK_MASK))

/*==========================================================================*\
* (RW) _MCBSP_MCR1_RMCM
\*--------------------------------------------------------------------------*/
#define _MCBSP_MCR1_RMCM_SHIFT		(0x0000u)
#define _MCBSP_MCR1_RMCM_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_MCR1_RMCM_SHIFT)
#define _MCBSP_MCR1_RMCM_MASK       	(_MCBSP_MCR1_RMCM_MK(0x0001u))
#define _MCBSP_MCR1_RMCM_CLR        	(~(_MCBSP_MCR1_RMCM_MK(0x0001u)))

/*==========================================================================*\
* _MCBSP_MCR1	- Mutli-channel Control Register 1 Config
\*--------------------------------------------------------------------------*/
#define _MCBSP_MCR1_CFG(RegAddr,rmcme,rpbblk,rpablk,rmcm) \
	_PREG_SET(RegAddr,							\
    		(Uint16) (	_MCBSP_MCR1_RMCME_MK(rmcme)		|	\
				_MCBSP_MCR1_RPBBLK_MK(rpbblk)		|	\
				_MCBSP_MCR1_RPABLK_MK(rpablk)		|	\
				_MCBSP_MCR1_RMCM_MK(rmcm)			\
             ))

/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/*===========================================================================*\
* _MCBSP_MCR2 -  Multi-channel Control Register 2
*
* Fields:
*  (RW) _MCBSP_MCR2_XMCME
*  (RW) _MCBSP_MCR2_XPBBLK
*  (RW) _MCBSP_MCR2_XPABLK
*  (R)  _MCBSP_MCR2_XCBLK
*  (RW) _MCBSP_MCR2_XMCM
\*==========================================================================*/

/*==========================================================================*\
* (RW) _MCBSP_MCR2_XMCME
\*--------------------------------------------------------------------------*/
#define _MCBSP_MCR2_XMCME_SHIFT		(0x0009u)
#define _MCBSP_MCR2_XMCME_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_MCR2_XMCME_SHIFT)
#define _MCBSP_MCR2_XMCME_MASK       	(_MCBSP_MCR2_XMCME_MK(0x0001u))
#define _MCBSP_MCR2_XMCME_CLR        	(~(_MCBSP_MCR2_XMCME_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_MCR2_XPBBLK
\*--------------------------------------------------------------------------*/
#define _MCBSP_MCR2_XPBBLK_SHIFT		(0x0007u)
#define _MCBSP_MCR2_XPBBLK_MK(n)		(((Uint16)(n) & 0x0003u) << _MCBSP_MCR2_XPBBLK_SHIFT)
#define _MCBSP_MCR2_XPBBLK_MASK       	(_MCBSP_MCR2_XPBBLK_MK(0x0003u))
#define _MCBSP_MCR2_XPBBLK_CLR        	(~(_MCBSP_MCR2_XPBBLK_MK(0x0003u)))

/*==========================================================================*\
* (RW) _MCBSP_MCR2_XPABLK
\*--------------------------------------------------------------------------*/
#define _MCBSP_MCR2_XPABLK_SHIFT		(0x0005u)
#define _MCBSP_MCR2_XPABLK_MK(n)		(((Uint16)(n) & 0x0003u) << _MCBSP_MCR2_XPABLK_SHIFT)
#define _MCBSP_MCR2_XPABLK_MASK       	(_MCBSP_MCR2_XPABLK_MK(0x0003u))
#define _MCBSP_MCR2_XPABLK_CLR        	(~(_MCBSP_MCR2_XPABLK_MK(0x0003u)))

/*==========================================================================*\
* (RW) _MCBSP_MCR2_XCBLK
\*--------------------------------------------------------------------------*/
#define _MCBSP_MCR2_XCBLK_SHIFT		(0x0002u)
#define _MCBSP_MCR2_XCBLK_MK(n)		(((Uint16)(n) & 0x0007u) << _MCBSP_MCR2_XCBLK_SHIFT)
#define _MCBSP_MCR2_XCBLK_MASK       	(_MCBSP_MCR2_XCBLK_MK(0x0007u))
#define _MCBSP_MCR2_XCBLK_CLR        	(~(_MCBSP_MCR2_XCBLK_MK(0x0007u)))

/*==========================================================================*\
* (RW) _MCBSP_MCR2_XMCM
\*--------------------------------------------------------------------------*/
#define _MCBSP_MCR2_XMCM_SHIFT		(0x0000u)
#define _MCBSP_MCR2_XMCM_MK(n)		(((Uint16)(n) & 0x0003u) << _MCBSP_MCR2_XMCM_SHIFT)
#define _MCBSP_MCR2_XMCM_MASK       	(_MCBSP_MCR2_XMCM_MK(0x0003u))
#define _MCBSP_MCR2_XMCM_CLR        	(~(_MCBSP_MCR2_XMCM_MK(0x0003u)))

/*==========================================================================*\
* _MCBSP_MCR2	- Mutli-channel Control Register 2 Config
\*--------------------------------------------------------------------------*/
#define _MCBSP_MCR2_CFG(RegAddr,xmcme,xpbblk,xpablk,xmcm) \
	_PREG_SET(RegAddr,							\
    		(Uint16) (	_MCBSP_MCR2_XMCME_MK(xmcme)		|	\
				_MCBSP_MCR2_XPBBLK_MK(xpbblk)		|	\
				_MCBSP_MCR2_XPABLK_MK(xpablk)		|	\
				_MCBSP_MCR2_XMCM_MK(xmcm)			\
             ))

/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/* //////////////////////////////////////////////////////////////////////////// */
/*===========================================================================*\
* _MCBSP_XCER -  Transmit Channel Enable Registers
*
* Fields:
*  (RW) _MCBSP_XCER_xce15
*  (RW) _MCBSP_XCER_xce14
*  (RW) _MCBSP_XCER_xce13
*  (RW) _MCBSP_XCER_xce12
*  (RW) _MCBSP_XCER_xce11
*  (RW) _MCBSP_XCER_xce10
*  (RW) _MCBSP_XCER_xce9
*  (RW) _MCBSP_XCER_xce8
*  (RW) _MCBSP_XCER_xce7
*  (RW) _MCBSP_XCER_xce6
*  (RW) _MCBSP_XCER_XCE5
*  (RW) _MCBSP_XCER_XCE4
*  (RW) _MCBSP_XCER_XCE3
*  (RW) _MCBSP_XCER_XCE2
*  (RW) _MCBSP_XCER_XCE1
*  (RW) _MCBSP_XCER_XCE0
\*==========================================================================*/

/*==========================================================================*\
* (RW) _MCBSP_XCER_XCE15
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCER_XCE15_SHIFT		(0x000Fu)
#define _MCBSP_XCER_XCE15_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_XCER_XCE15_SHIFT)
#define _MCBSP_XCER_XCE15_MASK       	(_MCBSP_XCER_XCE15_MK(0x0001u))
#define _MCBSP_XCER_XCE15_CLR        	(~(_MCBSP_XCER_XCE15_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_XCER_XCE14
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCER_XCE14_SHIFT		(0x000Eu)
#define _MCBSP_XCER_XCE14_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_XCER_XCE14_SHIFT)
#define _MCBSP_XCER_XCE14_MASK       	(_MCBSP_XCER_XCE14_MK(0x0001u))
#define _MCBSP_XCER_XCE14_CLR        	(~(_MCBSP_XCER_XCE14_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_XCER_XCE13
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCER_XCE13_SHIFT		(0x000Du)
#define _MCBSP_XCER_XCE13_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_XCER_XCE13_SHIFT)
#define _MCBSP_XCER_XCE13_MASK       	(_MCBSP_XCER_XCE13_MK(0x0001u))
#define _MCBSP_XCER_XCE13_CLR        	(~(_MCBSP_XCER_XCE13_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_XCER_XCE12
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCER_XCE12_SHIFT		(0x000Cu)
#define _MCBSP_XCER_XCE12_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_XCER_XCE12_SHIFT)
#define _MCBSP_XCER_XCE12_MASK       	(_MCBSP_XCER_XCE12_MK(0x0001u))
#define _MCBSP_XCER_XCE12_CLR        	(~(_MCBSP_XCER_XCE12_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_XCER_XCE11
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCER_XCE11_SHIFT		(0x000Bu)
#define _MCBSP_XCER_XCE11_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_XCER_XCE11_SHIFT)
#define _MCBSP_XCER_XCE11_MASK       	(_MCBSP_XCER_XCE11_MK(0x0001u))
#define _MCBSP_XCER_XCE11_CLR        	(~(_MCBSP_XCER_XCE11_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_XCER_XCE10
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCER_XCE10_SHIFT		(0x000Au)
#define _MCBSP_XCER_XCE10_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_XCER_XCE10_SHIFT)
#define _MCBSP_XCER_XCE10_MASK       	(_MCBSP_XCER_XCE10_MK(0x0001u))
#define _MCBSP_XCER_XCE10_CLR        	(~(_MCBSP_XCER_XCE10_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_XCER_XCE9
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCER_XCE9_SHIFT		(0x0009u)
#define _MCBSP_XCER_XCE9_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_XCER_XCE9_SHIFT)
#define _MCBSP_XCER_XCE9_MASK       	(_MCBSP_XCER_XCE9_MK(0x0001u))
#define _MCBSP_XCER_XCE9_CLR        	(~(_MCBSP_XCER_XCE9_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_XCER_XCE8
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCER_XCE8_SHIFT		(0x0008u)
#define _MCBSP_XCER_XCE8_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_XCER_XCE8_SHIFT)
#define _MCBSP_XCER_XCE8_MASK       	(_MCBSP_XCER_XCE8_MK(0x0001u))
#define _MCBSP_XCER_XCE8_CLR        	(~(_MCBSP_XCER_XCE8_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_XCER_XCE7
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCER_XCE7_SHIFT		(0x0007u)
#define _MCBSP_XCER_XCE7_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_XCER_XCE7_SHIFT)
#define _MCBSP_XCER_XCE7_MASK       	(_MCBSP_XCER_XCE7_MK(0x0001u))
#define _MCBSP_XCER_XCE7_CLR        	(~(_MCBSP_XCER_XCE7_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_XCER_XCE6
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCER_XCE6_SHIFT		(0x0006u)
#define _MCBSP_XCER_XCE6_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_XCER_XCE6_SHIFT)
#define _MCBSP_XCER_XCE6_MASK       	(_MCBSP_XCER_XCE6_MK(0x0001u))
#define _MCBSP_XCER_XCE6_CLR        	(~(_MCBSP_XCER_XCE6_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_XCER_XCE5
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCER_XCE5_SHIFT		(0x0005u)
#define _MCBSP_XCER_XCE5_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_XCER_XCE5_SHIFT)
#define _MCBSP_XCER_XCE5_MASK       	(_MCBSP_XCER_XCE5_MK(0x0001u))
#define _MCBSP_XCER_XCE5_CLR        	(~(_MCBSP_XCER_XCE5_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_XCER_XCE4
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCER_XCE4_SHIFT		(0x0004u)
#define _MCBSP_XCER_XCE4_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_XCER_XCE4_SHIFT)
#define _MCBSP_XCER_XCE4_MASK       	(_MCBSP_XCER_XCE4_MK(0x0001u))
#define _MCBSP_XCER_XCE4_CLR        	(~(_MCBSP_XCER_XCE4_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_XCER_XCE3
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCER_XCE3_SHIFT		(0x0003u)
#define _MCBSP_XCER_XCE3_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_XCER_XCE3_SHIFT)
#define _MCBSP_XCER_XCE3_MASK       	(_MCBSP_XCER_XCE3_MK(0x0001u))
#define _MCBSP_XCER_XCE3_CLR        	(~(_MCBSP_XCER_XCE3_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_XCER_XCE2
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCER_XCE2_SHIFT		(0x0002u)
#define _MCBSP_XCER_XCE2_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_XCER_XCE2_SHIFT)
#define _MCBSP_XCER_XCE2_MASK       	(_MCBSP_XCER_XCE2_MK(0x0001u))
#define _MCBSP_XCER_XCE2_CLR        	(~(_MCBSP_XCER_XCE2_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_XCER_XCE1
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCER_XCE1_SHIFT		(0x0001u)
#define _MCBSP_XCER_XCE1_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_XCER_XCE1_SHIFT)
#define _MCBSP_XCER_XCE1_MASK       	(_MCBSP_XCER_XCE1_MK(0x0001u))
#define _MCBSP_XCER_XCE1_CLR        	(~(_MCBSP_XCER_XCE1_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_XCER_XCE0
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCER_XCE0_SHIFT		(0x0000u)
#define _MCBSP_XCER_XCE0_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_XCER_XCE0_SHIFT)
#define _MCBSP_XCER_XCE0_MASK       	(_MCBSP_XCER_XCE0_MK(0x0001u))
#define _MCBSP_XCER_XCE0_CLR        	(~(_MCBSP_XCER_XCE0_MK(0x0001u)))

/*==========================================================================*\
*  _MCBSP_XCER  -  Transmit Channel Enable Config
\*--------------------------------------------------------------------------*/
#define _MCBSP_XCER_CFG(RegAddr,xcey15,xcey14,xcey13,xcey12,xcey11,xcey10,xcey9,\
				xcey8,xcey7,xcey6,xcey5,xcey4,xcey3,xcey2,xcey1,xcey0)  \
	_PREG_SET(RegAddr,							\
		(Uint16) (	_MCBSP_XCER_XCE15_MK(xcey15) 	|	\
				_MCBSP_XCER_XCE14_MK(xcey14) 	|	\
				_MCBSP_XCER_XCE13_MK(xcey13) 	|	\
				_MCBSP_XCER_XCE12_MK(xcey12) 	|	\
				_MCBSP_XCER_XCE11_MK(xcey11) 	|	\
				_MCBSP_XCER_XCE10_MK(xcey10) 	|	\
				_MCBSP_XCER_XCE9_MK(xcey9) 		|	\
				_MCBSP_XCER_XCE8_MK(xcey8) 		|	\
				_MCBSP_XCER_XCE7_MK(xcey7) 		|	\
				_MCBSP_XCER_XCE6_MK(xcey6) 		|	\
				_MCBSP_XCER_XCE5_MK(xcey5) 		|	\
				_MCBSP_XCER_XCE4_MK(xcey4) 		|	\
				_MCBSP_XCER_XCE3_MK(xcey3) 		|	\
				_MCBSP_XCER_XCE2_MK(xcey2) 		|	\
				_MCBSP_XCER_XCE1_MK(xcey1) 		|	\
				_MCBSP_XCER_XCE0_MK(xcey0) 			\
             ))


/* ////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////// */
/* /////////////////////////////////////////////////////////////////////////// */
/*===========================================================================
* _MCBSP_RCER -  Receive Channel Enable Registers
*
* Fields:
*  (RW) _MCBSP_RCER_RCE15
*  (RW) _MCBSP_RCER_RCE14
*  (RW) _MCBSP_RCER_RCE13
*  (RW) _MCBSP_RCER_RCE12
*  (RW) _MCBSP_RCER_RCE11
*  (RW) _MCBSP_RCER_RCE10
*  (RW) _MCBSP_RCER_RCE9
*  (RW) _MCBSP_RCER_RCE8
*  (RW) _MCBSP_RCER_RCE7
*  (RW) _MCBSP_RCER_RCE6
*  (RW) _MCBSP_RCER_RCE5
*  (RW) _MCBSP_RCER_RCE4
*  (RW) _MCBSP_RCER_RCE3
*  (RW) _MCBSP_RCER_RCE2
*  (RW) _MCBSP_RCER_RCE1
*  (RW) _MCBSP_RCER_RCE0
\*==========================================================================*/

/*==========================================================================*\
* (RW) _MCBSP_RCER_RCE15
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCER_RCE15_SHIFT		(0x000Fu)
#define _MCBSP_RCER_RCE15_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_RCER_RCE15_SHIFT)
#define _MCBSP_RCER_RCE15_MASK       	(_MCBSP_RCER_RCE15_MK(0x0001u))
#define _MCBSP_RCER_RCE15_CLR        	(~(_MCBSP_RCER_RCE15_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_RCER_RCE14
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCER_RCE14_SHIFT		(0x000Eu)
#define _MCBSP_RCER_RCE14_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_RCER_RCE14_SHIFT)
#define _MCBSP_RCER_RCE14_MASK       	(_MCBSP_RCER_RCE14_MK(0x0001u))
#define _MCBSP_RCER_RCE14_CLR        	(~(_MCBSP_RCER_RCE14_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_RCER_RCE13
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCER_RCE13_SHIFT		(0x000Du)
#define _MCBSP_RCER_RCE13_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_RCER_RCE13_SHIFT)
#define _MCBSP_RCER_RCE13_MASK       	(_MCBSP_RCER_RCE13_MK(0x0001u))
#define _MCBSP_RCER_RCE13_CLR        	(~(_MCBSP_RCER_RCE13_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_RCER_RCE12
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCER_RCE12_SHIFT		(0x000Cu)
#define _MCBSP_RCER_RCE12_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_RCER_RCE12_SHIFT)
#define _MCBSP_RCER_RCE12_MASK       	(_MCBSP_RCER_RCE12_MK(0x0001u))
#define _MCBSP_RCER_RCE12_CLR        	(~(_MCBSP_RCER_RCE12_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_RCER_RCE11
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCER_RCE11_SHIFT		(0x000Bu)
#define _MCBSP_RCER_RCE11_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_RCER_RCE11_SHIFT)
#define _MCBSP_RCER_RCE11_MASK       	(_MCBSP_RCER_RCE11_MK(0x0001u))
#define _MCBSP_RCER_RCE11_CLR        	(~(_MCBSP_RCER_RCE11_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_RCER_RCE10
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCER_RCE10_SHIFT		(0x000Au)
#define _MCBSP_RCER_RCE10_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_RCER_RCE10_SHIFT)
#define _MCBSP_RCER_RCE10_MASK       	(_MCBSP_RCER_RCE10_MK(0x0001u))
#define _MCBSP_RCER_RCE10_CLR        	(~(_MCBSP_RCER_RCE10_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_RCER_RCE9
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCER_RCE9_SHIFT		(0x0009u)
#define _MCBSP_RCER_RCE9_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_RCER_RCE9_SHIFT)
#define _MCBSP_RCER_RCE9_MASK       	(_MCBSP_RCER_RCE9_MK(0x0001u))
#define _MCBSP_RCER_RCE9_CLR        	(~(_MCBSP_RCER_RCE9_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_RCER_RCE8
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCER_RCE8_SHIFT		(0x0008u)
#define _MCBSP_RCER_RCE8_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_RCER_RCE8_SHIFT)
#define _MCBSP_RCER_RCE8_MASK       	(_MCBSP_RCER_RCE8_MK(0x0001u))
#define _MCBSP_RCER_RCE8_CLR        	(~(_MCBSP_RCER_RCE8_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_RCER_RCE7
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCER_RCE7_SHIFT		(0x0007u)
#define _MCBSP_RCER_RCE7_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_RCER_RCE7_SHIFT)
#define _MCBSP_RCER_RCE7_MASK       	(_MCBSP_RCER_RCE7_MK(0x0001u))
#define _MCBSP_RCER_RCE7_CLR        	(~(_MCBSP_RCER_RCE7_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_RCER_RCE6
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCER_RCE6_SHIFT		(0x0006u)
#define _MCBSP_RCER_RCE6_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_RCER_RCE6_SHIFT)
#define _MCBSP_RCER_RCE6_MASK       	(_MCBSP_RCER_RCE6_MK(0x0001u))
#define _MCBSP_RCER_RCE6_CLR        	(~(_MCBSP_RCER_RCE6_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_RCER_RCE5
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCER_RCE5_SHIFT		(0x0005u)
#define _MCBSP_RCER_RCE5_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_RCER_RCE5_SHIFT)
#define _MCBSP_RCER_RCE5_MASK       	(_MCBSP_RCER_RCE5_MK(0x0001u))
#define _MCBSP_RCER_RCE5_CLR        	(~(_MCBSP_RCER_RCE5_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_RCER_RCE4
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCER_RCE4_SHIFT		(0x0004u)
#define _MCBSP_RCER_RCE4_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_RCER_RCE4_SHIFT)
#define _MCBSP_RCER_RCE4_MASK       	(_MCBSP_RCER_RCE4_MK(0x0001u))
#define _MCBSP_RCER_RCE4_CLR        	(~(_MCBSP_RCER_RCE4_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_RCER_RCE3
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCER_RCE3_SHIFT		(0x0003u)
#define _MCBSP_RCER_RCE3_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_RCER_RCE3_SHIFT)
#define _MCBSP_RCER_RCE3_MASK       	(_MCBSP_RCER_RCE3_MK(0x0001u))
#define _MCBSP_RCER_RCE3_CLR        	(~(_MCBSP_RCER_RCE3_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_RCER_RCE2
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCER_RCE2_SHIFT		(0x0002u)
#define _MCBSP_RCER_RCE2_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_RCER_RCE2_SHIFT)
#define _MCBSP_RCER_RCE2_MASK       	(_MCBSP_RCER_RCE2_MK(0x0001u))
#define _MCBSP_RCER_RCE2_CLR        	(~(_MCBSP_RCER_RCE2_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_RCER_RCE1
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCER_RCE1_SHIFT		(0x0001u)
#define _MCBSP_RCER_RCE1_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_RCER_RCE1_SHIFT)
#define _MCBSP_RCER_RCE1_MASK       	(_MCBSP_RCER_RCE1_MK(0x0001u))
#define _MCBSP_RCER_RCE1_CLR        	(~(_MCBSP_RCER_RCE1_MK(0x0001u)))

/*==========================================================================*\
* (RW) _MCBSP_RCER_RCE0
\*--------------------------------------------------------------------------*/
#define _MCBSP_RCER_RCE0_SHIFT		(0x0000u)
#define _MCBSP_RCER_RCE0_MK(n)		(((Uint16)(n) & 0x0001u) << _MCBSP_RCER_RCE0_SHIFT)
#define _MCBSP_RCER_RCE0_MASK       	(_MCBSP_RCER_RCE0_MK(0x0001u))
#define _MCBSP_RCER_RCE0_CLR        	(~(_MCBSP_RCER_RCE0_MK(0x0001u)))

/*==========================================================================*\
*  _MCBSP_RCER  -  Receive Channel Enable Config
\*--------------------------------------------------------------------------*/

#define MCBSP_RCER_CFG(RegAddr,rcey15,rcey14,rcey13,rcey12,rcey11,rcey10,rcey9,\
				rcey8,rcey7,rcey6,rcey5,rcey4,rcey3,rcey2,rcey1,rcey0)  \
	_PREG_SET(RegAddr,							\
		(Uint16) (	_MCBSP_RCER_RCE15_MK(rcey15) 	|	\
				_MCBSP_RCER_RCE14_MK(rcey14) 	|	\
				_MCBSP_RCER_RCE13_MK(rcey13) 	|	\
				_MCBSP_RCER_RCE12_MK(rcey12) 	|	\
				_MCBSP_RCER_RCE11_MK(rcey11) 	|	\
				_MCBSP_RCER_RCE10_MK(rcey10) 	|	\
				_MCBSP_RCER_RCE9_MK(rcey9) 		|	\
				_MCBSP_RCER_RCE8_MK(rcey8) 		|	\
				_MCBSP_RCER_RCE7_MK(rcey7) 		|	\
				_MCBSP_RCER_RCE6_MK(rcey6) 		|	\
				_MCBSP_RCER_RCE5_MK(rcey5) 		|	\
				_MCBSP_RCER_RCE4_MK(rcey4) 		|	\
				_MCBSP_RCER_RCE3_MK(rcey3) 		|	\
				_MCBSP_RCER_RCE2_MK(rcey2) 		|	\
				_MCBSP_RCER_RCE1_MK(rcey1) 		|	\
				_MCBSP_RCER_RCE0_MK(rcey0) 			\
             ))

#define MCBSP_RCERA_CFG(Port,rcey15,rcey14,rcey13,rcey12,rcey11,rcey10,rcey9,\
				rcey8,rcey7,rcey6,rcey5,rcey4,rcey3,rcey2,rcey1,rcey0)\
 MCBSP_RCER_CFG(_MCBSP_RCERA_ADDR(Port),rcey15,rcey14,rcey13,rcey12,rcey11,rcey10,rcey9,\
				rcey8,rcey7,rcey6,rcey5,rcey4,rcey3,rcey2,rcey1,rcey0)

#define MCBSP_RCERB_CFG(Port,rcey15,rcey14,rcey13,rcey12,rcey11,rcey10,rcey9,\
				rcey8,rcey7,rcey6,rcey5,rcey4,rcey3,rcey2,rcey1,rcey0)\
 MCBSP_RCER_CFG(_MCBSP_RCERB_ADDR(Port),rcey15,rcey14,rcey13,rcey12,rcey11,rcey10,rcey9,\
				rcey8,rcey7,rcey6,rcey5,rcey4,rcey3,rcey2,rcey1,rcey0)

#define MCBSP_RCERC_CFG(Port,rcey15,rcey14,rcey13,rcey12,rcey11,rcey10,rcey9,\
				rcey8,rcey7,rcey6,rcey5,rcey4,rcey3,rcey2,rcey1,rcey0)\
 MCBSP_RCER_CFG(_MCBSP_RCERC_ADDR(Port),rcey15,rcey14,rcey13,rcey12,rcey11,rcey10,rcey9,\
				rcey8,rcey7,rcey6,rcey5,rcey4,rcey3,rcey2,rcey1,rcey0)

#define MCBSP_RCERD_CFG(Port,rcey15,rcey14,rcey13,rcey12,rcey11,rcey10,rcey9,\
				rcey8,rcey7,rcey6,rcey5,rcey4,rcey3,rcey2,rcey1,rcey0)\
 MCBSP_RCER_CFG(_MCBSP_RCERD_ADDR(Port),rcey15,rcey14,rcey13,rcey12,rcey11,rcey10,rcey9,\
				rcey8,rcey7,rcey6,rcey5,rcey4,rcey3,rcey2,rcey1,rcey0)

#define MCBSP_RCERE_CFG(Port,rcey15,rcey14,rcey13,rcey12,rcey11,rcey10,rcey9,\
				rcey8,rcey7,rcey6,rcey5,rcey4,rcey3,rcey2,rcey1,rcey0)\
 MCBSP_RCER_CFG(_MCBSP_RCERE_ADDR(Port),rcey15,rcey14,rcey13,rcey12,rcey11,rcey10,rcey9,\
				rcey8,rcey7,rcey6,rcey5,rcey4,rcey3,rcey2,rcey1,rcey0)

#define MCBSP_RCERF_CFG(Port,rcey15,rcey14,rcey13,rcey12,rcey11,rcey10,rcey9,\
				rcey8,rcey7,rcey6,rcey5,rcey4,rcey3,rcey2,rcey1,rcey0)\
 MCBSP_RCER_CFG(_MCBSP_RCERF_ADDR(Port),rcey15,rcey14,rcey13,rcey12,rcey11,rcey10,rcey9,\
				rcey8,rcey7,rcey6,rcey5,rcey4,rcey3,rcey2,rcey1,rcey0)

#define MCBSP_RCERG_CFG(Port,rcey15,rcey14,rcey13,rcey12,rcey11,rcey10,rcey9,\
				rcey8,rcey7,rcey6,rcey5,rcey4,rcey3,rcey2,rcey1,rcey0)\
 MCBSP_RCER_CFG(_MCBSP_RCERG_ADDR(Port),rcey15,rcey14,rcey13,rcey12,rcey11,rcey10,rcey9,\
				rcey8,rcey7,rcey6,rcey5,rcey4,rcey3,rcey2,rcey1,rcey0)

#define MCBSP_RCERH_CFG(Port,rcey15,rcey14,rcey13,rcey12,rcey11,rcey10,rcey9,\
				rcey8,rcey7,rcey6,rcey5,rcey4,rcey3,rcey2,rcey1,rcey0)\
 MCBSP_RCER_CFG(_MCBSP_RCERH_ADDR(Port),rcey15,rcey14,rcey13,rcey12,rcey11,rcey10,rcey9,\
				rcey8,rcey7,rcey6,rcey5,rcey4,rcey3,rcey2,rcey1,rcey0)

/*==========================================================================*\
*  _MCBSP_XCER  -  Receive Channel Enable Config
\*--------------------------------------------------------------------------*/

#define MCBSP_XCER_CFG(RegAddr,xcey15,xcey14,xcey13,xcey12,xcey11,xcey10,xcey9,\
				xcey8,xcey7,xcey6,xcey5,xcey4,xcey3,xcey2,xcey1,xcey0)  \
	_PREG_SET(RegAddr,							\
		(Uint16) (	_MCBSP_XCER_XCE15_MK(xcey15) 	|	\
				_MCBSP_XCER_XCE14_MK(xcey14) 	|	\
				_MCBSP_XCER_XCE13_MK(xcey13) 	|	\
				_MCBSP_XCER_XCE12_MK(xcey12) 	|	\
				_MCBSP_XCER_XCE11_MK(xcey11) 	|	\
				_MCBSP_XCER_XCE10_MK(xcey10) 	|	\
				_MCBSP_XCER_XCE9_MK(xcey9) 		|	\
				_MCBSP_XCER_XCE8_MK(xcey8) 		|	\
				_MCBSP_XCER_XCE7_MK(xcey7) 		|	\
				_MCBSP_XCER_XCE6_MK(xcey6) 		|	\
				_MCBSP_XCER_XCE5_MK(xcey5) 		|	\
				_MCBSP_XCER_XCE4_MK(xcey4) 		|	\
				_MCBSP_XCER_XCE3_MK(xcey3) 		|	\
				_MCBSP_XCER_XCE2_MK(xcey2) 		|	\
				_MCBSP_XCER_XCE1_MK(xcey1) 		|	\
				_MCBSP_XCER_XCE0_MK(xcey0) 			\
             ))


#define MCBSP_XCERA_CFG(Port,xcey15,xcey14,xcey13,xcey12,xcey11,xcey10,xcey9,\
				xcey8,xcey7,xcey6,xcey5,xcey4,xcey3,xcey2,xcey1,xcey0)\
 MCBSP_XCER_CFG(_MCBSP_XCERA_ADDR(Port),xcey15,xcey14,xcey13,xcey12,xcey11,xcey10,xcey9,\
				xcey8,xcey7,xcey6,xcey5,xcey4,xcey3,xcey2,xcey1,xcey0)

#define MCBSP_XCERB_CFG(Port,xcey15,xcey14,xcey13,xcey12,xcey11,xcey10,xcey9,\
				xcey8,xcey7,xcey6,xcey5,xcey4,xcey3,xcey2,xcey1,xcey0)\
 MCBSP_XCER_CFG(_MCBSP_XCERB_ADDR(Port),xcey15,xcey14,xcey13,xcey12,xcey11,xcey10,xcey9,\
				xcey8,xcey7,xcey6,xcey5,xcey4,xcey3,xcey2,xcey1,xcey0)

#define MCBSP_XCERC_CFG(Port,xcey15,xcey14,xcey13,xcey12,xcey11,xcey10,xcey9,\
				xcey8,xcey7,xcey6,xcey5,xcey4,xcey3,xcey2,xcey1,xcey0)\
 MCBSP_XCER_CFG(_MCBSP_XCERC_ADDR(Port),xcey15,xcey14,xcey13,xcey12,xcey11,xcey10,xcey9,\
				xcey8,xcey7,xcey6,xcey5,xcey4,xcey3,xcey2,xcey1,xcey0)

#define MCBSP_XCERD_CFG(Port,xcey15,xcey14,xcey13,xcey12,xcey11,xcey10,xcey9,\
				xcey8,xcey7,xcey6,xcey5,xcey4,xcey3,xcey2,xcey1,xcey0)\
 MCBSP_XCER_CFG(_MCBSP_XCERD_ADDR(Port),xcey15,xcey14,xcey13,xcey12,xcey11,xcey10,xcey9,\
				xcey8,xcey7,xcey6,xcey5,xcey4,xcey3,xcey2,xcey1,xcey0)

#define MCBSP_XCERE_CFG(Port,xcey15,xcey14,xcey13,xcey12,xcey11,xcey10,xcey9,\
				xcey8,xcey7,xcey6,xcey5,xcey4,xcey3,xcey2,xcey1,xcey0)\
 MCBSP_XCER_CFG(_MCBSP_XCERE_ADDR(Port),xcey15,xcey14,xcey13,xcey12,xcey11,xcey10,xcey9,\
				xcey8,xcey7,xcey6,xcey5,xcey4,xcey3,xcey2,xcey1,xcey0)

#define MCBSP_XCERF_CFG(Port,xcey15,xcey14,xcey13,xcey12,xcey11,xcey10,xcey9,\
				xcey8,xcey7,xcey6,xcey5,xcey4,xcey3,xcey2,xcey1,xcey0)\
 MCBSP_XCER_CFG(_MCBSP_XCERF_ADDR(Port),xcey15,xcey14,xcey13,xcey12,xcey11,xcey10,xcey9,\
				xcey8,xcey7,xcey6,xcey5,xcey4,xcey3,xcey2,xcey1,xcey0)

#define MCBSP_XCERG_CFG(Port,xcey15,xcey14,xcey13,xcey12,xcey11,xcey10,xcey9,\
				xcey8,xcey7,xcey6,xcey5,xcey4,xcey3,xcey2,xcey1,xcey0)\
 MCBSP_XCER_CFG(_MCBSP_XCERG_ADDR(Port),xcey15,xcey14,xcey13,xcey12,xcey11,xcey10,xcey9,\
				xcey8,xcey7,xcey6,xcey5,xcey4,xcey3,xcey2,xcey1,xcey0)

#define MCBSP_XCERH_CFG(Port,xcey15,xcey14,xcey13,xcey12,xcey11,xcey10,xcey9,\
				xcey8,xcey7,xcey6,xcey5,xcey4,xcey3,xcey2,xcey1,xcey0)\
 MCBSP_XCER_CFG(_MCBSP_XCERH_ADDR(Port),xcey15,xcey14,xcey13,xcey12,xcey11,xcey10,xcey9,\
				xcey8,xcey7,xcey6,xcey5,xcey4,xcey3,xcey2,xcey1,xcey0)

#elif (!(_MCBSP_MOD))
	#error McBSP Hal Module Not Supported on Specified Target
#endif

#endif




