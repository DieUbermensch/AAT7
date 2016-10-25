/****************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved 
*------------------------------------------------------------------------------
* MODULE NAME... MMC
* FILENAME...... csl_mmcdat.h
* DATE CREATED.. Thu May 24 14:48:09 2001
* PROJECT....... Chip Support Library
* COMPONENT..... Service Layer
* PREREQUISITS.. 
*------------------------------------------------------------------------------
*
* HISTORY:
*	 Created:		Thu May 24 14:48:09 2001 (Automatic generation)
*	 Modified:	      Wed April 9 2003 change register names MMCCIE ===> MMCIM
*                       MMCFCLK ===>MMCFCLKCTL to match SPRS163D
*
*------------------------------------------------------------------------------
* DESCRIPTION: CSL Service Layer interface for the MMC module 
*
\*************************************************************************/

#ifndef _CSL_MMCDAT_H_
#define _CSL_MMCDAT_H_

#if (_MMC_SUPPORT) 
#include <csl_std.h>

//---------------------------------------------------
// MMC Module Global Data Initialization
//---------------------------------------------------

/*************************************************\
 MMC global typedef declarations 
\*************************************************/
typedef void (*MMC_CallBackPtr)(void);
typedef interrupt void(*MMC_IsrPtr)(void);


extern void interrupt MMC_dispatch0(void);
extern void interrupt MMC_dispatch1(void);

#define MMC_DEV_CNT     2

typedef struct {
   MMC_CallBackPtr isr[12];
} MMC_CallBackObj;

typedef struct {
  Uint32 mfgId;                    /* 24 bit Manufacturer and OEM ID */
  char productName[8];             /* 48 bit Product name */
  Uint16 hwRev;                    /* 4 bit Hardware  Revision Number */
  Uint16 fwRev;                    /* 4 bit Firmware Revision Number */
  Uint32 serialNumber;             /* 32 bit Serial Number */
  Uint16 monthCode;                /* 4 bit Manufacturing Date (Month) */
  Uint16 yearCode;                 /* 4 bit Manufacturing Date (Year) in case of MMC (Year 0 = 1997). SD has an 8 bit year field. (Year 0 = 2000) */
  Uint16 checksum;                 /* 7 bit crc */
} MMC_CardIdObj;

typedef struct {
  Uint16 csdStructure;             /* 2 bit structure type field */
  Uint16 mmcProt;                  /* 2 bit MMC protocol */
  Uint16 taac;                     /* 8 bit TAAC */
  Uint16 nsac;                     /* 8 bit NSAC */
  Uint16 tranSpeed;                /* 8 bit max data transmission speed */
  Uint16 ccc;                      /* 12 bit card command classes */
  Uint16 readBlLen;                /* 4 bit maximum Read Block Length */
  Uint16 readBlPartial;            /* 1 bit indicates if partial read blocks allowed */
  Uint16 writeBlkMisalign;         /* 1 bit flag indicates write block misalignment */
  Uint16 readBlkMisalign;          /* 1 bit flag indicates read block misalignment */
  Uint16 dsrImp;                   /* 1 bit flag indicates whether card has DSR reg */
  Uint16 cSize;                    /* 12 bit device size */
  Uint16 vddRCurrMin;              /* 3 bit Max. Read Current @ Vdd Min  */
  Uint16 vddRCurrMax;              /* 3 bit Max. Read Current @ Vdd Max */
  Uint16 vddWCurrMin;              /* 3 bit Max. Write Current @ Vdd Min */
  Uint16 vddWCurrMax;              /* 3 bit Max. Write Current @ Vdd Max */
  Uint16 cSizeMult;                /* 3 bit device size multiplier */
  Uint16 eraseGrpSize;             /* 5 bit erase sector size */
  Uint16 eraseGrpMult;             /* 5 bit erase group multiplier */
  Uint16 wpGrpSize;                /* 5 bit write protect group size */
  Uint16 wpGrpEnable;              /* 1 bit write protect enable flag */    
  Uint16 defaultEcc;               /* 2 bit Manufacturer Default ECC */
  Uint16 r2wFactor;                /* 3 bit stream write factor */
  Uint16 writeBlLen;               /* 4 bit maximum write block length */
  Uint16 writeBlPartial;           /* 1 bit indicates if partial write blocks allowed */
  Uint16 fileFmtGrp;               /* 1 bit file format group */
  Uint16 copy;                     /* 1 bit copy flag */
  Uint16 permWriteProtect;         /* 1 bit to dis/en-able permanent write protection */
  Uint16 tmpWriteProtect;          /* 1 bit to dis/en-able temporary write protection */
  Uint16 fileFmt;                  /* 2 bit file format */
  Uint16 ecc;                      /* 2 bit ECC code */
  Uint16 crc;                      /* 7 bit r/w/e redundancy check */
} MMC_CardCsdObj;

typedef struct {
  Uint16 csdStructure;             /* 2 bit structure type field */
  Uint16 taac;                     /* 8 bit TAAC */
  Uint16 nsac;                     /* 8 bit NSAC */
  Uint16 tranSpeed;                /* 8 bit max data transmission speed */
  Uint16 ccc;                      /* 12 bit card command classes */
  Uint16 readBlLen;                /* 4 bit maximum Read Block Length */
  Uint16 readBlPartial;            /* 1 bit indicates if partial read blocks allowed */
  Uint16 writeBlkMisalign;         /* 1 bit flag indicates write block misalignment */
  Uint16 readBlkMisalign;          /* 1 bit flag indicates read block misalignment */
  Uint16 dsrImp;                   /* 1 bit flag indicates whether card has DSR reg */
  Uint16 cSize;                    /* 12 bit device size */
  Uint16 vddRCurrMin;              /* 3 bit Max. Read Current @ Vdd Min  */
  Uint16 vddRCurrMax;              /* 3 bit Max. Read Current @ Vdd Max */
  Uint16 vddWCurrMin;              /* 3 bit Max. Write Current @ Vdd Min */
  Uint16 vddWCurrMax;              /* 3 bit Max. Write Current @ Vdd Max */
  Uint16 cSizeMult;                /* 3 bit device size multiplier */
  Uint16 eraseBlkEn;               /* 1 bit erase single block enable */
  Uint16 sectorSize;               /* 7 bit erase group size */
  Uint16 wpGrpSize;                /* 7 bit write protect group size */
  Uint16 wpGrpEnable;              /* 1 bit write protect enable flag */    
  Uint16 r2wFactor;                /* 3 bit stream write factor */
  Uint16 writeBlLen;               /* 4 bit maximum write block length */
  Uint16 writeBlPartial;           /* 1 bit indicates if partial write blocks allowed */
  Uint16 fileFmtGrp;               /* 1 bit file format group */
  Uint16 copy;                     /* 1 bit copy flag */
  Uint16 permWriteProtect;         /* 1 bit to dis/en-able permanent write protection */
  Uint16 tmpWriteProtect;          /* 1 bit to dis/en-able temporary write protection */
  Uint16 fileFmt;                  /* 2 bit file format */
  Uint16 crc;                      /* 7 bit r/w/e redundancy check */
} SD_CardCsdObj;

typedef struct {
  Uint16 securitySysId;           /* Security System ID */
  Uint16 securitySysVers;         /* Security System Version */
  Uint16 maxLicenses;             /* Maximum number of storable licenses */
  Uint32 xStatus;                 /* Extended status bits */
} MMC_CardXCsdObj;


typedef struct {
  Uint32 rca;                  /* User assigned relative card address (RCA) 
                                  MMC mode or GPIO pin mapping associated with 
                                  Chip Select in SPI mode */
  Uint16 status;               /* Last read status value */
  Uint16 cardIndex;            /* MMC module assignd index for card */
  Uint16 cardType;             /* MMC or SD */
  Uint32 maxXfrRate;           /* Maximum transfer rate */
  Uint32 readAccessTime;       /* TAAC - exp * mantissa */
  Uint32 cardCapacity;         /* Total memory available on card */
  Uint32 lastAddrRead;         /* Last Address Read from memory card */
  Uint32 lastAddrWritten;      /* Last Address written to on memory card */

  MMC_CardIdObj cid;           /* Manufacturers Card ID */
  MMC_CardCsdObj *MMC_csd;         /* Card specific data */
  SD_CardCsdObj *SD_csd;          /* card would be either sd or mmc, we will use the appropriate csd.
                                  currently, just make both members of this structure */
  MMC_CardXCsdObj *xcsd;       /* Extended CSD      */
} MMC_CardObj;


typedef struct {
  Uint16 argh;                 /* High part of command argument */
  Uint16 argl;                 /* Low part of command argument */
  Uint16 cmd;                  /* MMC command */
} MMC_CmdObj;
             
typedef struct {
  Uint16 dmaEnable;            /* Enable/disable DMA for data read/write */
  Uint16 dat3EdgeDetection;    /* Set level of edge detection for DAT3 pin */
  Uint16 goIdle;               /* Determines if MMC goes IDLE during IDLE instr */
  Uint16 enableClkPin;         /* Memory clk reflected on CLK Pin */
  Uint32 fdiv;                 /* CPU CLK to MMC function clk divide down */
  Uint32 cdiv;                 /* MMC function clk to memory clk divide down */
  Uint16 rspTimeout;           /* No. memory clks to wait before response timeout */
  Uint16 dataTimeout;          /* No. memory clks to wait before data timeout */
  Uint16 blockLen;             /* Block Length must be same as CSD */
} MMC_SetupNative, MMC_InitObj;

typedef struct {
  Uint16 rsp0;              /* Response register 0-7 */
  Uint16 rsp1;              
  Uint16 rsp2;              
  Uint16 rsp3;              
  Uint16 rsp4;              
  Uint16 rsp5;              
  Uint16 rsp6;              
  Uint16 rsp7;              
} MMC_RspRegObj;

typedef struct {
  Uint16 mmcfclk;              /* MMCFCLK register */
  Uint16 mmcctl;               /* MMCCTL register     */
  Uint16 mmcclk;               /* MMCCLK register     */
  Uint16 mmcst0;               /* MMCST0 register     */
  Uint16 mmcst1;               /* MMCST1 register     */
  Uint16 mmcie;                /* MMCIE register     */
  Uint16 mmctor;               /* MMCTOR register     */
  Uint16 mmctod;               /* MMCTOD register     */
  Uint16 mmcblen;              /* MMCBLEN register    */
  Uint16 mmcnblk;              /* MMCNBLK register    */
  Uint16 mmcnblc;              /* MMCNBLC register    */
  Uint16 mmcdrr;               /* MMCDRR register     */
  Uint16 mmcdxr;               /* MMCDXR register     */
  Uint16 mmccmd;               /* MMCCMD register     */
  Uint16 mmcargl;              /* MMCARGL register    */
  Uint16 mmcargh;              /* MMCARGH register    */
  MMC_RspRegObj mmcrsp;        /* MMCRSP registers    */
  Uint16 mmcdrsp;              /* MMCDRSP register    */
  Uint16 mmccidx;              /* MMCCIDX register    */
} MMC_MmcRegObj;


 typedef struct {
   Uint16 dev;                         /* MMC device number 0,1 */
   ioport MMC_MmcRegObj *mmcRegs;      /* Pointer to MMC regs for this device */
   Uint16 nextIndex;                   /* Next index to assign to an attached card */
   Uint16 currentCard;                 /* Index of currently addressed card */
   Uint16 numCards;                    /* Total Number of Cards */
   Uint16 numCardsActive;              /* Number of cards active/ready */
   Uint16 numCardsInactive;            /* Number of inactive cards */
   MMC_CardObj *cards;                 /* Pointer to card Objects */ 
} MMC_StatusObj;


/*************************************************\
 MMC global typedef declarations 
\*************************************************/

typedef struct {
  Uint16 mmcctl;
  Uint16 mmcfclk;
  Uint16 mmcclk;
  Uint16 mmcie;
  Uint16 mmctor;
  Uint16 mmctod;
  Uint16 mmcblen;
  Uint16 mmcnblk;
} MMC_Config;


typedef struct {
   Uint16 devNum;                      /* MMC device number 0,1 */
   Uint16 eventId;                     /* MMC eventId (IMR/IFR) */
   Uint16 status;                      /* MMC status */
   MMC_IsrPtr mmcDispatch;             /* Default MMC ISR dispatcher */
   MMC_MmcRegObj *mmcRegs;             /* Pointer to MMC regs for this device */
   Uint16 nextIndex;                   /* Next index to assign to an attached card */
   Uint16 currentCard;                 /* Index of currently addressed card */
   Uint16 numCards;                    /* Total Number of Cards */
   Uint16 numCardsActive;              /* Number of cards active/ready */
   Uint16 numCardsInactive;            /* Number of inactive cards */
   MMC_CardObj *cards;                 /* Pointer to card Objects */
   MMC_CallBackObj *callBackTbl;        /* Pointer to call back table obj */ 
} MMC_ControllerObj, MMC_PrivateObj, *MMC_Handle;

typedef struct {
 MMC_ControllerObj mmc[MMC_DEV_CNT];
}CSL_MmcDataObj;

extern CSL_MmcDataObj CSL_MmcData;

#define CSL_MMC_DATA  CSL_MmcData

#endif //#if (_MMC_SUPPORT)
#endif
