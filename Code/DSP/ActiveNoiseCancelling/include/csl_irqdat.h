/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... IRQ
* FILENAME...... csl_irqdat.h
* DATE CREATED.. Thu 03/30/2000 
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... CSL service layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:       03/30/2000
*   MODIFIED:      06/19/2000
*   LAST MODIFIED: 04/16/2001 updated FILENAME and other header comments
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the IRQ module)
*       Reserved ROM Area for IRQ Data 
*
*
\******************************************************************************/
#ifndef _CSL_IRQ_DATA_H_
  #define _CSL_IRQ_DATA_H_ 

  #include <csl_std.h>
  #include <csl_stdhal.h>

  #define _IRQ_INT_CNT    (32)  /* number of interrupt events */
  #define IRQ_INT_CNT     (32)   /* number of physical interrupts */  
  #define IRQ_EVENT_CNT   (32)


typedef void (*IRQ_IsrPtr)(void);


typedef struct {
  IRQ_IsrPtr funcAddr;
  Uint32 ierMask;
  Uint32 cacheCtrl;
  Uint32 funcArg;
} _IRQ_Dispatch;


typedef struct {
  _IRQ_Dispatch *IrqDispatchTable;
  Uint16 *perRegs;
  Uint32 IrqIntTable[IRQ_INT_CNT];
  Uint32 IrqEventTable[IRQ_EVENT_CNT];
} CSL_IrqDataObj;

  #define CSL_IRQDATAINIT\
  {  (_IRQ_Dispatch *)0x0000u,\
     (Uint16 *)0x0003u,\
    /* IRQ Physical Interrupt Table */\
        0x00000000u,\
        0x00000001u,\
        0x00000002u,\
        0x00000003u,\
        0x00000004u,\
        0x00000005u,\
        0x00000006u,\
        0x00000007u,\
        0x00000008u,\
        0x00000009u,\
        0x0000000Au,\
        0x0000000Bu,\
        0x0000000Cu,\
        0x0000000Fu,\
        0x00000010u,\
        0x00000011u,\
        0x00000012u,\
        0x00000013u,\
        0x00000014u,\
        0x00000015u,\
        0x00000016u,\
        0x00000017u,\
        0x00000018u,\
        0x00000019u,\
        0x0000001Au,\
        0x0000001Bu,\
        0x0000001Cu,\
        0x0000001Du,\
        0x0000001Eu,\
        0x0000001Fu,\
      /* IRQ EventId Table */\
        0x00000000u,\
        0x00000001u,\
        0x00000002u,\
        0x00000004u,\
        0x00000008u,\
        0x00000010u,\
        0x00000020u,\
        0x00000040u,\
        0x00000080u,\
        0x00000100u,\
        0x00000200u,\
        0x00000400u,\
        0x00000800u,\
        0x00001000u,\
        0x00002000u,\
        0x00004000u,\
        0x00008000u,\
        0x00010000u,\
        0x00020000u,\
        0x00040000u,\
        0x00080000u,\
        0x00100000u,\
        0x00200000u,\
        0x00400000u,\
        0x00800000u,\
        0x01000000u,\
        0x02000000u,\
        0x04000000u,\
        0x08000000u,\
        0x10000000u,\
        0x20000000u,\
        0x40000000u}
 
extern CSL_IrqDataObj  CSL_IrqData;

#define CSL_IRQ_DATA   CSL_IrqData

#endif
