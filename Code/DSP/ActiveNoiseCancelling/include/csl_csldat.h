/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... CSL - chip support library service layer interface
* FILENAME...... csldata.h
* DATE CREATED.. Fri 06/11/1999 
* PROJECT....... Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS.. 
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED: 02/04/2000 
*   LAST MODIFIED: 06/19/2000  incorporate cpluplus compatability
*   MODIFIED: 10 April 2003  updated data structure for .csldata size fix
*------------------------------------------------------------------------------
* DESCRIPTION:  (Global/Static Data Table to Support ROMability of CSL modules)
*
*
*
\******************************************************************************/
#ifndef _CSL_CSLDATA_H_
#define _CSL_CSLDATA_H_

#include <csl_cslhal.h>
#include <csl_datasz.h>

/****************************************\
* CSL scope and inline control macros
\****************************************/
#ifdef __cplusplus
#define CSLAPI extern "C"  
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _CSL_MOD_
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


/*============================================================*/
/*============= Defines ======================================*/
/*============================================================*/
#define CSL_SYSDATAINIT\
   { /* CSL Global System Data Initialization       */\
       (0x00000000ul),            /* Reserved Word                      */\
       (0x00000000ul),            /* CSL Data Ptr                       */\
       (0x00000000ul),            /* Ptr to DSPBIOS Dispatch Table      */\
       (char *)(0x0000u),         /* Char Ptr to CSL Version            */\
       (char *)(0x0000u),         /* Char Ptr to CSL Time/Date Stamp    */\
       (0x0000u),                 /* DSPBIOS present flag               */\
       (0x0000u),                 /* DMA Channel Allocation Mask        */\
       (0x0000u),                 /* DMA Global Regs Alocation Mask     */\
       (0x0000u),                 /* DMA Global Regs Used Mask          */\
       (0x0000u),                 /* Dat Alloc Mask                     */\
       (0x0000u),                 /* CSL DAT Module Open flag           */\
       (0x0000u),                 /* CSL DAT Module Submit Mask         */\
       (0x0000u),                 /* DAT Module Submit Request Priority */\
       (0x0000u),                 /* MCBSP Module Port Allocation Mask  */\
       (0x0000u),                 /* MMC Port Allocation Mask           */\
       (0x0000u),                 /* TIMER Allocation Mask              */\
       (0x0000u),                 /* GPT Timer Allocation Mask          */\
       (0x0000u),                 /* PLL Allocation Mask                */\
       (0x0000u),                 /* UART Allocation Mask               */\
       (0x0000u),                 /* Wdt Allocation Mask                */\
       (0x0000u),                 /* Bct Allocation Mask                */\
       (0x0000u),                 /* Gpio Allocation Masks              */\
       (0x0000u),                 \
       (0x0000u),                 \
       (0x0000u),                 \
       (0x0000u),                 /* Error Count                        */\
       (0x00000000ul) }           /* Error Handler                      */

/*****************************************************************************\
* Macro to declare symbols
\*****************************************************************************/


/*============================================================*/
/*============= Structure Definitions ========================*/
/*============================================================*/
typedef struct {
	Uint32 Reserved;
      Uint32 DataPtr;
      Uint32 DispatchTablePtr;
      char * Version;
      char * DateStamp;
      Uint16 OsPresent;
      Uint16 DmaAllocMask;
      Uint16 DmaGblAllocMask;
      Uint16 DmaGblRegMask;
      Uint16 DatAllocMask;
      Uint16 DatOpenFlag;
      Uint16 DatSubmitMask;
      Uint16 DatChaPriority;
      Uint16 McbspPortAllocMask;
      Uint16 MmcAllocMask;
      Uint16 TimerAllocMask;
      Uint16 GptAllocMask;
      Uint16 PllAllocMask;
      Uint16 UartAllocMask;
      Uint16 WdtAllocMask;
      Uint16 BctAllocMask;
      Uint16 GpioAllocMask[4];
      Uint16 ErrCnt;
      Uint32 ErrFunc;
} CSL_SysDataObj;

/******************************************************************************\
* Table of contents for Global/Static data array
\******************************************************************************/
extern CSL_SysDataObj         CSL_SysData;
#define CSL_SYS_DATA          CSL_SysData


#endif /* _CSL_CSLDATA_H_ */
/******************************************************************************\
* End of csl_csldat.h
\******************************************************************************/

