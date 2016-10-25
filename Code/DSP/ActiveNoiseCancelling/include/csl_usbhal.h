/******************************************************************************/
/* $Id: csl_usbhal.h,v 1.1.1.1 2001/08/16 16:12:41 a0323633 Exp $          */
/*                                                                            */
/* This is proprietary information, not to be published -- TI INTERNAL DATA   */
/* Copyright (C) 2000, Texas Instruments, Inc.  All Rights Reserved.          */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* Author :   Jason Kridner                                                   */
/* Date   :   October 23, 2000                                                */
/* Updates:                                                                   */
/*                                                                            */
/* 05/17/01 $MH$                                                              */
/*                                                                            */
/* Fixed PSOFTMR address                                                      */ 
/*                                                                            */
/******************************************************************************/
/* Modified last: Ruchika Agarwal 6 May 2002                                  */
/* Change: Addition of USBALT resister                                        */
/******************************************************************************/


#ifndef _CSL_USBHAL_H
#define _CSL_USBHAL_H

#include <_csl.h>

#if (_USB_SUPPORT)


/* -----------------10/23/2000 2:50PM----------------
;
; Values for USBINTSRC Register
;
 --------------------------------------------------*/
//02/27/01 $MH$ replaced names with the new ones (customer doc)
 
#define USBINTSRC_NONE         0x00
#define USBINTSRC_OEP0         0x02
#define USBINTSRC_IEP0         0x04
#define USBINTSRC_RSTR         0x06
#define USBINTSRC_SUSR         0x08
#define USBINTSRC_RESR         0x0A
#define USBINTSRC_SETUP        0x0C
#define USBINTSRC_STPOW        0x0E
#define USBINTSRC_SOF          0x10    /* phase III only */
#define USBINTSRC_PRESOF       0x11    /* phase III only */
#define USBINTSRC_OEP1         0x12
#define USBINTSRC_OEP2         0x14
#define USBINTSRC_OEP3         0x16
#define USBINTSRC_OEP4         0x18
#define USBINTSRC_OEP5         0x1A
#define USBINTSRC_OEP6         0x1C
#define USBINTSRC_OEP7         0x1E
#define USBINTSRC_IEP1         0x22
#define USBINTSRC_IEP2         0x24
#define USBINTSRC_IEP3         0x26
#define USBINTSRC_IEP4         0x28
#define USBINTSRC_IEP5         0x2A
#define USBINTSRC_IEP6         0x2C
#define USBINTSRC_IEP7         0x2E
#define USBINTSRC_ODMARLD1     0x32
#define USBINTSRC_ODMAGO1      0x33
#define USBINTSRC_ODMARLD2     0x34
#define USBINTSRC_ODMAGO2      0x35
#define USBINTSRC_ODMARLD3     0x36
#define USBINTSRC_ODMAGO3      0x37
#define USBINTSRC_ODMARLD4     0x38
#define USBINTSRC_ODMAGO4      0x39
#define USBINTSRC_ODMARLD5     0x3A
#define USBINTSRC_ODMAGO5      0x3B
#define USBINTSRC_ODMARLD6     0x3C
#define USBINTSRC_ODMAGO6      0x3D
#define USBINTSRC_ODMARLD7     0x3E
#define USBINTSRC_ODMAGO7      0x3F
#define USBINTSRC_IDMARLD1     0x42
#define USBINTSRC_IDMAGO1      0x43
#define USBINTSRC_IDMARLD2     0x44
#define USBINTSRC_IDMAGO2      0x45
#define USBINTSRC_IDMARLD3     0x46
#define USBINTSRC_IDMAGO3      0x47
#define USBINTSRC_IDMARLD4     0x48
#define USBINTSRC_IDMAGO4      0x49
#define USBINTSRC_IDMARLD5     0x4A
#define USBINTSRC_IDMAGO5      0x4B
#define USBINTSRC_IDMARLD6     0x4C
#define USBINTSRC_IDMAGO6      0x4D
#define USBINTSRC_IDMARLD7     0x4E
#define USBINTSRC_IDMAGO7      0x4F
#define USBINTSRC_HINT         0x50      /* phase III only */
#define USBINTSRC_HERR         0x52      /* phase III only */


#define USBINTSRC_DMA_START    0x30
#define USBINTSRC_DMA_END      0x4F
/*
12/02/00 $MH$: to include host dma interrupt in the handler table
#define USB_INTV_DMA_END      0x50
*/

/* -----------------10/23/2000 2:52PM----------------
;
; Register locations
;
 --------------------------------------------------*/
// 02/27/01 $MH$ replace register name with the new ones (customer doc)
/*  
#define USB_REG_DMA_O1    0x5808
#define USB_REG_DMA_O2    0x5810
#define USB_REG_DMA_O3    0x5818
#define USB_REG_DMA_O4    0x5820
#define USB_REG_DMA_O5    0x5828
#define USB_REG_DMA_O6    0x5830
#define USB_REG_DMA_O7    0x5838
#define USB_REG_DMA_I1    0x5848
#define USB_REG_DMA_I2    0x5850
#define USB_REG_DMA_I3    0x5858
#define USB_REG_DMA_I4    0x5860
#define USB_REG_DMA_I5    0x5868
#define USB_REG_DMA_I6    0x5870
#define USB_REG_DMA_I7    0x5878
*/

#define USBALT_ADDR      0x5840  /* Added New Entry - Ruchika */

#define USBODMA1_BASE    0x5808
#define USBODMA2_BASE    0x5810
#define USBODMA3_BASE    0x5818
#define USBODMA4_BASE    0x5820
#define USBODMA5_BASE    0x5828
#define USBODMA6_BASE    0x5830
#define USBODMA7_BASE    0x5838
#define USBIDMA1_BASE    0x5848
#define USBIDMA2_BASE    0x5850
#define USBIDMA3_BASE    0x5858
#define USBIDMA4_BASE    0x5860
#define USBIDMA5_BASE    0x5868
#define USBIDMA6_BASE    0x5870
#define USBIDMA7_BASE    0x5878

// 02/27/01 $MH$ replace register name with the new ones (customer doc)
/*
#ifdef usb_phase3
#define USB_REG_OEB_0     0x6680   // OUT ENDPT0 buffer base addr
#define USB_REG_IEB_0     0x66C0   // IN ENDPT0 buffer base addr
#else  
#define USB_REG_OEB_0     0x66F8   // EP0 IN and OUT buffer orders are reversed
#define USB_REG_IEB_0     0x66F0   // in phase II and phase III design         
#endif
#define USB_REG_SUP_0     0x6700
*/

//#ifdef usb_phase3

#define USBOEP0_BUF     0x6680  // OUT ENDPT0 buffer base addr
#define USBIEP0_BUF     0x66C0  // IN ENDPT0 buffer base addr

//#else 
 
//#define USBOEP0_BUF     0x66F8   /* EP0 IN and OUT buffer orders are reversed  */
//#define USBIEP0_BUF     0x66F0   /* in phase II and phase III design           */

//#endif

#define USBSUP_BUF      0x6700   // SETUP packet receive buffer

// 02/27/01 $MH$ replace register name with the new ones (customer doc)
/*
#define USB_REG_OEDB_1    0x6708
#define USB_REG_OEDB_2    0x6710
#define USB_REG_OEDB_3    0x6718
#define USB_REG_OEDB_4    0x6720
#define USB_REG_OEDB_5    0x6728
#define USB_REG_OEDB_6    0x6730
#define USB_REG_OEDB_7    0x6738
#define USB_REG_IEDB_1    0x6748
#define USB_REG_IEDB_2    0x6750
#define USB_REG_IEDB_3    0x6758
#define USB_REG_IEDB_4    0x6760
#define USB_REG_IEDB_5    0x6768
#define USB_REG_IEDB_6    0x6770
#define USB_REG_IEDB_7    0x6778
*/

#define USBOEDB1_BASE    0x6708  // base addr - IN ENDPT1 descriptor block
#define USBOEDB2_BASE    0x6710
#define USBOEDB3_BASE    0x6718
#define USBOEDB4_BASE    0x6720
#define USBOEDB5_BASE    0x6728
#define USBOEDB6_BASE    0x6730
#define USBOEDB7_BASE    0x6738
#define USBIEDB1_BASE    0x6748
#define USBIEDB2_BASE    0x6750
#define USBIEDB3_BASE    0x6758
#define USBIEDB4_BASE    0x6760
#define USBIEDB5_BASE    0x6768
#define USBIEDB6_BASE    0x6770
#define USBIEDB7_BASE    0x6778

// 02/27/01 $MH$ replace register name with the new ones (customer doc)
/*
#define USB_REG_IEPCNF_0  0x6780
#define USB_REG_IEPBCNT_0 0x6781
#define USB_REG_OEPCNF_0  0x6782
#define USB_REG_OEPBCNT_0 0x6783
*/

#define USBICNF0_ADDR  0x6780  // IN ENDPT0 Config reg addr
#define USBICT0_ADDR   0x6781  // IN ENDPT0 byte cnt reg addr
#define USBOCNF0_ADDR  0x6782
#define USBOCT0_ADDR   0x6783

// 02/27/01 $MH$ replace register name with the new ones (customer doc)
/*
#define USB_REG_GLOBCTL   0x6791
#define USB_REG_VECINT    0x6792
#define USB_REG_IEPINT    0x6793
#define USB_REG_OEPINT    0x6794
#define USB_REG_IDMARINT  0x6795
#define USB_REG_ODMARINT  0x6796
#define USB_REG_IDMAGINT  0x6797
#define USB_REG_ODMAGINT  0x6798
#define USB_REG_IDMAMSK   0x6799
#define USB_REG_ODMAMSK   0x679A
#define USB_REG_IEDBMSK   0x679B
#define USB_REG_OEDBMSK   0x679C
*/

#define USBGCTL_ADDR    0x6791
#define USBINTSRC_ADDR  0x6792
#define USBIEPIF_ADDR   0x6793
#define USBOEPIF_ADDR   0x6794
#define USBIDRIF_ADDR   0x6795
#define USBODRIF_ADDR   0x6796
#define USBIDGIF_ADDR   0x6797
#define USBODGIF_ADDR   0x6798
#define USBIDIE_ADDR    0x6799
#define USBODIE_ADDR    0x679A
#define USBIEPIE_ADDR   0x679B
#define USBOEPIE_ADDR   0x679C

/*
12/06/00 $MH$
#define USB_REG_HOSTEN    0x67A0
#define USB_REG_HOSTEP    0x67A1
#define USB_REG_HOSTTIME  0x67A2

//02/27/01 $MH$ replace register name with the new ones (customer doc)
#define USB_REG_HOSTCTL   0x67A0
#define USB_REG_HOSTEP    0x67A1
#define USB_REG_HOSTSTAT  0x67A2
*/

#define USBHCTL_ADDR      0x67A0
#define USBHEPSEL_ADDR    0x67A1
#define USBHSTAT_ADDR     0x67A2

/*
12/06/00 $MH$
//02/27/01 $MH$ replace register name with the new ones (customer doc)

#define USB_REG_FNUML     0x67F8    // phase III only
#define USB_REG_FNUMH     0x67F9    // phase III only
#define USB_REG_PSOFTMR   0x67A2    // phase III only
*/

#define USBFNUML_ADDR     0x67F8    // phase III only
#define USBFNUMH_ADDR     0x67F9    // phase III only
//#define USBPSOFTMR_ADDR   0x67A2  // phase III only -- error
#define USBPSOFTMR_ADDR   0x67FA    // bug fix 05/17/01 $MH$


/*
//02/27/01 $MH$ replace register name with the new ones (customer doc)
#define USB_REG_USBCTL    0x67FC
#define USB_REG_USBMSK    0x67FD
#define USB_REG_USBSTA    0x67FE
#define USB_REG_FUNADR    0x67FF
*/

#define USBCTL_ADDR       0x67FC
#define USBIE_ADDR        0x67FD
#define USBIF_ADDR        0x67FE
#define USBADDR_ADDR      0x67FF

/*
#define USBRTC_REG_IDLE   0x7000   // why RTC check with JDK
#define USBRTC_REG_STAT   0x7001   // why RTC check with JDK
*/

// renaming the above regs
#define USBIDLCTL_ADDR    0x7000   // USB Idle Control Reg
#define USBIDLSTAT_ADDR   0x7001   // USB Idle Status Reg

/* #define USB_REG_X4PLL     0x1E00     USB clk gen pll reg */

/*
bit address for USB module in USB Idle Control Reg
*/
//#define USBRTC_IDLE_USBPLL_ACTIVE 0x0001
//#define USBRTC_IDLE_USBEN         0x0004

// 02/27/01 $MH$
#define USBIDLCTL_USBPLL_ACTIVE 0x0001
#define USBIDLCTL_USBEN         0x0004

/*
bit address for USB global reset in USB_REG_GLOBCTL
*/
// #define USB_GLOB_RESET 0x0001

#define USBGCTL_RST 0x0001

/* -----------------12/06/00 $MH$ ----------------
SRAM bytes reserved for USB driver use
--------------------------------------------------*/
 
 #define USB_SRAM_DRVR     0x0100  /* 256 bytes reserved for driver */

/* -----------------10/23/2000 3:00PM----------------
General locations of memory/register blocks
 --------------------------------------------------*/ 
#define USB_DMA_REG_START 0x5800
#define USB_DMA_REG_END   0x587F
#define USB_SRAM_START    0x5880
// #if usb_phase3
// #define USB_SRAM_END      0x667F - 256 (bytes reserved for driver)
// #define USB_SRAM_END      0x667F - USB_SRAM_DRVR
// #else 
// #define USB_SRAM_END      0x66EF - 256 (bytes reserved for driver)
// #define USB_SRAM_END      0x66EF - USB_SRAM_DRVR
// #endif
#define USB_SRAM_END      0x667F - USB_SRAM_DRVR

#define USB_EDB_START     0x6700
//#define USB_UBM_REG_START 0x6780
//#define USB_UBM_REG_END   0x67FF

/* -----------------10/23/2000 3:11PM----------------
USBMSK and USBSTA bit fields (interrupt mask and status)
 --------------------------------------------------*/
#define USB_INT_STPOW 0x0001
#define USB_INT_SETUP 0x0004
#define USB_INT_PSOF  0x0008
#define USB_INT_SOF   0x0010
#define USB_INT_RESR  0x0020
#define USB_INT_SUSR  0x0040
#define USB_INT_RSTR  0x0080

/* -----------------10/23/2000 3:01PM----------------
DMA Context (DMA) structure
 --------------------------------------------------*/
/*
12/20/00 $MH$: temporarily assigning register structure to data
data memory 0x5800 to 0x7000 for debugging with 5510 simulator

typedef struct
{
  Uint16 DMACTL;
  Uint16 DMASIZ;
  Uint16 DMADL;
  Uint16 DMADH;
  Uint16 DMACNT;
  Uint16 DMALSZ;
  Uint16 DMALAL;
  Uint16 DMALAH;
} USB_DMA_Context, USB_DMARegBlk;

*/
 
//02/27/01 $MH$ replaced names with the new ones (customer doc)

typedef ioport struct
{
  Uint16 DCTL;
  Uint16 DSIZ;
  Uint16 DADL;
  Uint16 DADH;
  Uint16 DCT;
  Uint16 DRSZ;
  Uint16 DRAL;
  Uint16 DRAH;
} USB_DMA_Context, USB_DMARegBlk;


/* -----------------10/23/2000 3:02PM----------------
USB DMA Control reg bit fields
 --------------------------------------------------*/
// 02/27/01 $MH$ replace register bit names with the new ones (customer doc)
 
#define USBDCTL_GO  0x0001
#define USBDCTL_STP 0x0002
#define USBDCTL_RLD 0x0004
#define USBDCTL_OVF 0x0008
#define USBDCTL_END 0x0010
#define USBDCTL_CAT 0x0020
#define USBDCTL_SHT 0x0040
/*
Phase3 control bits
*/
#define USBDCTL_EM 0x0080
#define USBDCTL_PM 0x0100

/* -----------------10/23/2000 3:01PM----------------
Endpoint Descriptor Block (EDB) structure
 --------------------------------------------------*/
 
   
/*12/06/00 $MH$
Need to redefine EDB structure for phase III 
*/

//#ifdef usb_phase3
/*12/06/00 $MH$
Need to redefine EDB structure for phase III 
*/

//02/27/01 $MH$ replaced names with the new ones (customer doc)
typedef ioport struct   // reg blk for bulk, intr, and hostport endpt
{
  Uint16 CNF;
  Uint16 BAX;
  Uint16 CTX;
  Uint16 unused1;
  Uint16 SIZ;
  Uint16 BAY;
  Uint16 CTY;
  Uint16 unused2;
  
} USB_EDRegBlk;

typedef ioport struct   // reg blk for iso in endpts
{
  Uint16 CNF;
  Uint16 BAX;
  Uint16 CTX;
  Uint16 SIZH;
  Uint16 SIZ;
  Uint16 BAY;
  Uint16 CTY;
  Uint16 unused2;
  
} USB_IsoInRegBlk;

typedef ioport struct   // reg blk for iso out endpts
{
  Uint16 CNF;
  Uint16 BAX;
  Uint16 CTX;
  Uint16 CTXH;
  Uint16 SIZ;
  Uint16 BAY;
  Uint16 CTY;
  Uint16 CTYH;
  
} USB_IsoOutRegBlk;

//#else
/* 
EDB struct for phase 2
*/

//typedef ioport struct
//{
//  Uint16 CNF;
//  Uint16 BAX;
//  Uint16 CTX;
//  Uint16 unused1;
//  Uint16 unused2;
//  Uint16 BAY;
//  Uint16 CTY;
//  Uint16 SIZ;
//} USB_EDRegBlk;
//
//#endif
/*
12/20/00 $MH$: temporarily assigning register structure to data
data memory 0x5800 to 0x7000 for debugging with 5510 simulator

typedef struct
{
  Uint16 EPCNF;
  Uint16 X_BASE;
  Uint16 X_EPBCNT;
#if 0
  Uint16 unused1;
  Uint16 unused2;
#else
  Uint16 Events;
  Uint16 unused;
#endif
  Uint16 Y_BASE;
  Uint16 Y_EPBCNT;
  Uint16 XY_SIZE;
} USB_Endpoint_Descriptor_Block, USB_EDRegBlk;
*/
/* ----------------- 11/27/00 $MH$ ----------------
Endpoint 0 register block structure
 --------------------------------------------------*/
/*
12/20/00 $MH$: temporarily assigning register structure to data
data memory 0x5800 to 0x7000 for debugging with 5510 simulator

typedef struct
{
  Uint16 EPCNF;
  Uint16 EPBCNT;

} USB_EP0_RegBlk, *pUSPB_EP0_RegBlk;
*/

//02/27/01 $MH$ replaced names with the new ones (customer doc)

typedef ioport struct
{
  Uint16 CNF;
  Uint16 CT;

} USB_EP0_RegBlk, *pUSPB_EP0_RegBlk;


/* -----------------10/23/2000 3:04PM----------------
EPCNF bit fields
 --------------------------------------------------*/
//02/27/01 $MH$ replaced names with the new ones (customer doc) 
#define USBEPCNF_USBIE  0x0004
#define USBEPCNF_STALL  0x0008
#define USBEPCNF_DBUF   0x0010
#define USBEPCNF_TOGGLE 0x0020
#define USBEPCNF_OVF    0x0020
#define USBEPCNF_ISO    0x0040
#define USBEPCNF_UBME   0x0080

/* -----------------10/23/2000 3:06PM----------------
EPBCNT bit fields
 --------------------------------------------------*/
//#define USB_EPBCNT_CNT 0x000F
#define USBEPCT_NAK 0x0080

/* -----------------10/23/2000 3:08PM----------------
USBCTL bit fields
 --------------------------------------------------*/
//02/27/01 $MH$ replaced names with the new ones (customer doc) 
#define USBCTL_DIR    0x01
#define USBCTL_SETUP  0x02
#define USBCTL_FRSTE  0x10
#define USBCTL_RWUP   0x20
#define USBCTL_FEN    0x40
#define USBCTL_CONN   0x80

/* USB Memory registers */
/*
12/20/00 $MH$: temporarily assigning register structure to data
data memory 0x5800 to 0x7000 for debugging with 5510 simulator

#define USB_IN_EP0_CONF         *(ioport Uint16 *)USB_REG_IEPCNF_0
#define USB_IN_EP0_BYTE_CNT     *(ioport Uint16 *)USB_REG_IEPBCNT_0
#define USB_OUT_EP0_CONF        *(ioport Uint16 *)USB_REG_OEPCNF_0
#define USB_OUT_EP0_BYTE_CNT    *(ioport Uint16 *)USB_REG_OEPBCNT_0
#define USB_VECTOR_ADDRESS      *(ioport Uint16 *)USB_REG_VECINT
#define USB_CTL                 *(ioport Uint16 *)USB_REG_USBCTL
#define USB_IMR                 *(ioport Uint16 *)USB_REG_USBMSK
#define USB_STATUS              *(ioport Uint16 *)USB_REG_USBSTA
#define USB_DEV_ADDR            *(ioport Uint16 *)USB_REG_FUNADR
#define USB_GLOB_CTL            *(ioport Uint16 *)USB_REG_GLOBCTL
*/

/*
#define USB_IN_EP0_CONF         *(Uint16 *)USB_REG_IEPCNF_0
#define USB_IN_EP0_BYTE_CNT     *(Uint16 *)USB_REG_IEPBCNT_0
#define USB_OUT_EP0_CONF        *(Uint16 *)USB_REG_OEPCNF_0
#define USB_OUT_EP0_BYTE_CNT    *(Uint16 *)USB_REG_OEPBCNT_0
#define USB_VECTOR_ADDRESS      *(Uint16 *)USB_REG_VECINT
#define USB_CTL                 *(Uint16 *)USB_REG_USBCTL
#define USB_IMR                 *(Uint16 *)USB_REG_USBMSK
#define USB_STATUS              *(Uint16 *)USB_REG_USBSTA
#define USB_DEV_ADDR            *(Uint16 *)USB_REG_FUNADR
#define USB_GLOB_CTL            *(Uint16 *)USB_REG_GLOBCTL
*/

#define USBALT       *(ioport Uint16 *)USBALT_ADDR /* Added Ruchika */

//02/27/01 $MH$ replace register name with the new ones (customer doc)
#define USBICNF0     *(ioport Uint16 *)USBICNF0_ADDR
#define USBICT0      *(ioport Uint16 *)USBICT0_ADDR
#define USBOCNF0     *(ioport Uint16 *)USBOCNF0_ADDR
#define USBOCT0      *(ioport Uint16 *)USBOCT0_ADDR
#define USBINTSRC    *(ioport Uint16 *)USBINTSRC_ADDR
#define USBCTL       *(ioport Uint16 *)USBCTL_ADDR
#define USBIE        *(ioport Uint16 *)USBIE_ADDR
#define USBIF        *(ioport Uint16 *)USBIF_ADDR
#define USBADDR      *(ioport Uint16 *)USBADDR_ADDR
#define USBGCTL      *(ioport Uint16 *)USBGCTL_ADDR

/*
12/08/00 $MH$
*/
/*
12/20/00 $MH$: temporarily assigning register structure to data
data memory 0x5800 to 0x7000 for debugging with 5510 simulator
*/
//02/27/01 $MH$ replace register name with the new ones (customer doc)
#define USBIEPIF     *(ioport Uint16 *)USBIEPIF_ADDR  
#define USBOEPIF     *(ioport Uint16 *)USBOEPIF_ADDR  
#define USBIDRIF     *(ioport Uint16 *)USBIDRIF_ADDR
#define USBODRIF     *(ioport Uint16 *)USBODRIF_ADDR
#define USBIDGIF     *(ioport Uint16 *)USBIDGIF_ADDR
#define USBODGIF     *(ioport Uint16 *)USBODGIF_ADDR
#define USBIDIE      *(ioport Uint16 *)USBIDIE_ADDR 
#define USBODIE      *(ioport Uint16 *)USBODIE_ADDR 
#define USBIEPIE     *(ioport Uint16 *)USBIEPIE_ADDR 
#define USBOEPIE     *(ioport Uint16 *)USBOEPIE_ADDR

/*
#define USB_IN_EP_INTR_FLAG            *(Uint16 *)USB_REG_IEPINT  
#define USB_OUT_EP_INTR_FLAG           *(Uint16 *)USB_REG_OEPINT  
#define USB_IN_EP_DMA_RLD_INTR_FLAG    *(Uint16 *)USB_REG_IDMARINT
#define USB_OUT_EP_DMA_RLD_INTR_FLAG   *(Uint16 *)USB_REG_ODMARINT
#define USB_IN_EP_DMA_G0_INTR_FLAG     *(Uint16 *)USB_REG_IDMAGINT
#define USB_OUT_EP_DMA_GO_INTR_FLAG    *(Uint16 *)USB_REG_ODMAGINT
#define USB_IN_EP_DMA_INTR_MASK        *(Uint16 *)USB_REG_IDMAMSK 
#define USB_OUT_EP_DMA_INTR_MASK       *(Uint16 *)USB_REG_ODMAMSK 
#define USB_IN_EP_INTR_MASK            *(Uint16 *)USB_REG_IEDBMSK 
#define USB_OUT_EP_INTR_MASK           *(Uint16 *)USBOEPIE_ADDR
*/

/*
12/08/00 $MH$
phase III only
*/
/*
12/20/00 $MH$: temporarily assigning register structure to data
data memory 0x5800 to 0x7000 for debugging with 5510 simulator
*/
//02/27/01 $MH$ replace register name with the new ones (customer doc)
#define USBFNUML        *(ioport Uint16 *)USBFNUML_ADDR   
#define USBFNUMH        *(ioport Uint16 *)USBFNUMH_ADDR   
#define USBPSOFTMR      *(ioport Uint16 *)USBPSOFTMR_ADDR

/*
#define USB_FRM_NUML        *(Uint16 *)USB_REG_FNUML   
#define USB_FRM_NUMH        *(Uint16 *)USB_REG_FNUMH   
#define USB_PSOF_TIMER      *(Uint16 *)USB_REG_PSOFTMR
*/

/*
12/08/00 $MH$
Host Control Registers - phase III only
*/
/*
12/20/00 $MH$: temporarily assigning register structure to data
memory 0x5800 to 0x7000 for debugging with 5510 simulator
*/
//02/27/01 $MH$ replace register name with the new ones (customer doc)
#define USBHCTL       *(ioport Uint16 *)USBHCTL_ADDR 
#define USBHEPSEL     *(ioport Uint16 *)USBHEPSEL_ADDR  
#define USBHSTAT       *(ioport Uint16 *)USBHSTAT_ADDR

/*
#define USB_HOST_CTRL       *(Uint16 *)USB_REG_HOSTCTL 
#define USB_HOST_EP_SEL     *(Uint16 *)USB_REG_HOSTEP  
#define USB_HOST_STAT       *(Uint16 *)USB_REG_HOSTSTAT
*/

//02/26/01 $MH$
//02/27/01 $MH$ replace register bit name with the new ones (customer doc)
#define USBHCTL_EN         0x01
#define USBHCTL_HIE        0x02
#define USBHCTL_HERRIE     0x04

#define USBHSTAT_DIS       0x01
#define USBHSTAT_HIF       0x02
#define USBHSTAT_HERRIF    0x04

/*
12/24/00 $MH$
USB Idle Control regs, USB PLL control reg.
temporarily assigning register structure to data memory
0x5800 to 0x7000 for debugging with 5510 simulator
*/
//02/27/01 $MH$ replace register name with the new ones (customer doc)
#define USBIDLCTL   *(ioport Uint16 *)USBIDLCTL_ADDR
#define USBIDLSTAT  *(ioport Uint16 *)USBIDLSTAT_ADDR                    
//#define USB_X4PLL   *(ioport Uint16 *)USB_REG_X4PLL

/*
#define USB_IDLE_CTL   *(Uint16 *)USBRTC_REG_IDLE
#define USB_IDLE_STAT  *(Uint16 *)USBRTC_REG_STAT                    
#define USB_X4PLL      *(Uint16 *)USB_REG_X4PLL
*/

/*
12/08/00 $MH$
USB ENDPT and DMA interrupt enable and flag register bit fields
*/ 
#define USB_INTR_EP0   0x01
#define USB_INTR_EP1   0x02
#define USB_INTR_EP2   0x04
#define USB_INTR_EP3   0x08
#define USB_INTR_EP4   0x10
#define USB_INTR_EP5   0x20
#define USB_INTR_EP6   0x40
#define USB_INTR_EP7   0x80

// 05/01/01 $MH$ usb pll reg and bit fields moved from usb_clk.h file
/*********************************************************************/
/* Data bitfields for USB Clock Mode Register (USB_CLKMD)            */
/*********************************************************************/
#define USB_PLL_IAI				14
#define USB_PLL_IOB				13
#define USB_PLL_MULT		     7
#define USB_PLL_DIV			     5
#define USB_PLL_ENABLE	 	     4
#define USB_PLL_BYPASS_DIV	 	 2
#define USB_PLL_BREAKLN 		 1
#define USB_PLL_LOCK	 		 0

/*********************************************************************/
/* Define bit fields for USB Clock Mode Register (CLKMD)             */
/*********************************************************************/
/*
#define USB_X4PLL_LOCK    0x0001
#define USB_X4PLL_EN      0x0010
#define USB_X4PLL_IOB     0x2000
#define USB_X4PLL_IAI     0x4000
*/
/*********************************************************************/
/* USB CLOCK MODE REGISTER ADDRESS                                   */
/* Defined for VC5509                                                */
/*********************************************************************/
#define USB_CLKMD_ADDR  0x1E00
#define USB_CLKMD       *(ioport volatile Uint16 *)USB_CLKMD_ADDR

#endif

#else /* _USB_SUPPORT */
   #ifndef _USB_MOD
      error USB Module Not Supported for Specified Target Device
   #endif
#endif
