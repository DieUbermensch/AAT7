/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME......  csl_irq.h
*-------------------------------------------------------------------------------
* HISTORY
*   CREATED  07/10/2000
*   MODIFIED 03/22/2001
*   MODIFIED 06/28/2001 updated to support new CSL initialization model
*   MODIFIED 08/01/2001 removed IVPH from irq_setvecs function def and added
*                       support for 5509 interrupts (I2C,USB,RTC,ADC,...)
*   MODIFIED 01/18/2002 fixed IRQ mapping problem for INT1
*   MODIFIED 02/15/2002 added support for 5502 (setPriority)
*   MODIFIED 10 April 2003 added #include for csl_irqdat.h
\******************************************************************************/
#ifndef _CSL_IRQ_H_
#define _CSL_IRQ_H_

#include <_csl.h>
#include <csl_irqhal.h>
#include <csl_irqdat.h>


#if (_IRQ_SUPPORT)
/****************************************\
* IRQ scope and inline control macros
\****************************************/
#ifdef __cplusplus
#define CSLAPI extern "C"  
#else
#define CSLAPI extern
#endif 

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _IRQ_MOD_
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
* IRQ global macro declarations
\****************************************/
/* misc global settings */

#define IRQ_GIEROUTINES_IN_ASSEMBLY 0
#define IRQ_EVENT_NOT_MAPPED_ERROR  0x00001u

/*Hardware Interrupts */
#define IRQ_EVT_RESET        (0)
#define IRQ_EVT_NMI          (1)

#define IRQ_EVT_INT0         (2)
#define IRQ_EVT_INT2         (3)
#define IRQ_EVT_TINT0        (4)
#define IRQ_EVT_RINT0        (5)
#define IRQ_EVT_RINT1        (6)

#define IRQ_EVT_XINT1        (7)
#define IRQ_EVT_MMC0         (7)
#define IRQ_EVT_MST0         (7)

#define IRQ_EVT_USB          (8)
#define IRQ_EVT_LCKINT       (8)

#define IRQ_EVT_DMAC1        (9)
#define IRQ_EVT_DSPINT       (10)

#define IRQ_EVT_INT3         (11)
#define IRQ_EVT_WDTIM        (11)
#define IRQ_EVT_TINT2        (11)

#define IRQ_EVT_RINT2        (12)
#define IRQ_EVT_UART         (12)

#define IRQ_EVT_XINT2        (13)
#define IRQ_EVT_MMC1         (13)
#define IRQ_EVT_MST1         (13)

#define IRQ_EVT_DMAC4        (14)
#define IRQ_EVT_DMAC5        (15)
#define IRQ_EVT_INT1         (16)
#define IRQ_EVT_XINT0        (17)
#define IRQ_EVT_DMAC0        (18)

#define IRQ_EVT_INT4         (19)
#define IRQ_EVT_RTC          (19)

#define IRQ_EVT_DMAC2        (20)
#define IRQ_EVT_DMAC3        (21)
#define IRQ_EVT_TINT1        (22)

#define IRQ_EVT_INT5         (23)
#define IRQ_EVT_I2C          (23)

  
/* Mask for IMR and IFR */
#define IRQ_MASK_NA (0x0000)
#define IRQ_MASK_00 (0x0001)
#define IRQ_MASK_01 (0x0002)
#define IRQ_MASK_02 (0x0004)
#define IRQ_MASK_03 (0x0008)
#define IRQ_MASK_04 (0x0010)
#define IRQ_MASK_05 (0x0020)
#define IRQ_MASK_06 (0x0040)
#define IRQ_MASK_07 (0x0080)
#define IRQ_MASK_08 (0x0100)
#define IRQ_MASK_09 (0x0200)
#define IRQ_MASK_10 (0x0400)
#define IRQ_MASK_11 (0x0800)
#define IRQ_MASK_12 (0x1000)
#define IRQ_MASK_13 (0x2000)
#define IRQ_MASK_14 (0x4000)
#define IRQ_MASK_15 (0x8000) 

/* Mask for IERMASK for DSPBIOS Dispatch Table */
#define IRQ_IEMASK_ALL      (0x0000FFFFu)
#define IRQ_IEMASK_SELF     (0x80000000u)
#define IRQ_IEMASK_DEFAULT  IRQ_IEMASK_DEFAULT

/* Macro for Converting Data Addresses for Vector Table */
#define IRQ_DAT2PRG(n)      ((Uint32)n<<2)

/* Allows to mask the bit "x"*/
/* of IFR or IMR registers */ 
#define IRQ_MASK32(x)          ((Uint32)(0x1ul<<x))     
#define IRQ_MASK16(x)          ((Uint16)(0x1ul<<x))  
#define IRQ_IER_MASK(x)        (IRQ_MASK32(x))   

#define _IRQ_DISPATCHTBL_CNT   (IRQ_EVENT_CNT+1)
#define _IRQ_EVENT2INTTBL_CNT  (IRQ_EVENT_CNT+1)
#define _IRQ_INT2EVENTTBL_CNT  (IRQ_INT_CNT)

/****************************************\
* IRQ global typedef declarations
\****************************************/


/****************************************\
* IRQ global typedef declarations
\****************************************/

typedef struct {
IRQ_IsrPtr funcAddr;
Uint32 ierMask;
Uint32 cacheCtrl;
Uint32 funcArg;
} IRQ_Config;



/****************************************\
* IRQ global variable declarations
\****************************************/

CSLAPI CSLInt  IRQ_plug(Uint16 EventId, IRQ_IsrPtr funcAddr);
CSLAPI CSLInt  _IRQ_plug(Uint16 EventId, IRQ_IsrPtr funcAddr);


/****************************************\
* IRQ inline function declarations
\****************************************/
IDECL void    IRQ_clear(Uint16 EventId);
IDECL void    IRQ_config(Uint16 EventId, IRQ_Config *Config);
IDECL void    IRQ_configArgs(Uint16 EventId, IRQ_IsrPtr funcAddr, Uint32 funcArg , Uint32 ierMask, Uint32 cacheCtrl);
IDECL int     IRQ_disable(Uint16 EventId);
IDECL int     IRQ_enable(Uint16 EventId);
IDECL void    IRQ_restore(Uint16 EventId, Uint16 Old_flag);
IDECL Uint32  IRQ_getArg(Uint16 EventId);
IDECL void    IRQ_getConfig(Uint16 EventId, IRQ_Config *Config);
CSLAPI int    IRQ_globalDisable();
CSLAPI int    IRQ_globalEnable();
CSLAPI void   IRQ_globalRestore(int gie);
IDECL void    _IRQ_init(_IRQ_Dispatch *dispatch_table, Uint16 bios_present);

IDECL void    IRQ_map(Uint16 EventId);
IDECL void    IRQ_setArg(Uint16 EventId, Uint32 val);
IDECL int     IRQ_setVecs(Uint32 Ivpd);
IDECL CSLBool IRQ_test(Uint16 EventId);

/****************************************\
* IRQ inline function definitions
\****************************************/
#ifdef USEDEFS
/*----------------------------------------------------------------------------*/
  IDEF int IRQ_enable(Uint16 EventId) {
   Uint16 bit,reg,prev,value,mask;
   int old_intm, old_flag;

   bit= EventId & 0xfu; 
   reg=((EventId & 0x10) >> 4);
   mask= IRQ_MASK16(bit);
   old_intm = IRQ_globalDisable();
   prev = (reg) ? CHIP_RGET(IER1) : CHIP_RGET(IER0);
   old_flag = (prev & mask)>>bit;
   value= (prev | mask);
   if (reg) 
     _IER1 = value;
   else 
    _IER0 = value; 
   IRQ_globalRestore(old_intm);
   return old_flag;
} 
/*----------------------------------------------------------------------------*/
  IDEF void IRQ_restore(Uint16 EventId, Uint16 Old_flag) {
   Uint16 bit,reg,prev,value,mask;
   int old_intm;

   bit= EventId & 0xfu; 
   reg=((EventId & 0x10) >> 4);
   mask= IRQ_MASK16(bit);
   old_intm = IRQ_globalDisable();
   prev = (reg) ? CHIP_RGET(IER1) : CHIP_RGET(IER0);
   value= (prev & (~mask)) | (Old_flag << bit);
   if (reg) 
     _IER1 = value;
   else 
    _IER0  = value; 
   IRQ_globalRestore(old_intm);
} 
/*----------------------------------------------------------------------------*/
 IDEF int IRQ_disable(Uint16 EventId) { 
  Uint16 bit,reg,mask,prev;
  int old_intm,old_flag;

  bit= EventId & 0xfu; 
  reg=((EventId & 0x10) >> 4);
  mask=IRQ_MASK16(bit);
  old_intm = IRQ_globalDisable();
  prev = (reg) ? CHIP_RGET(IER1) : CHIP_RGET(IER0);
  old_flag = (prev & mask) >> bit;
  if (reg) 
    _IER1 &= ~mask;
  else 
    _IER0 &= ~mask; 
  IRQ_globalRestore(old_intm);
  return old_flag;
}                                 
/*----------------------------------------------------------------------------*/
 IDEF void IRQ_clear(Uint16 EventId) {   
  Uint16 bit, reg, mask;
  int old_intm;
  bit= EventId & 0xfu; 
  reg=((EventId & 0x10) >> 4);
  mask=IRQ_MASK16(bit);
  old_intm = IRQ_globalDisable();
  if (reg)
    _IFR1 = mask;
  else
    _IFR0 = mask;
  IRQ_globalRestore(old_intm);
}
/*----------------------------------------------------------------------------*/
 IDEF void _IRQ_init(_IRQ_Dispatch *dispatchTable, Uint16 biosPresent){
   Uint16 i; 

   if (dispatchTable != INV) {
     CSL_IRQ_DATA.IrqDispatchTable = dispatchTable;
   }

   for (i=0; i<=IRQ_EVENT_CNT-1; i++)
    CSL_IRQ_DATA.IrqIntTable[i] = i;
   
   for(i=0; i<= IRQ_EVENT_CNT-1; i++)
    CSL_IRQ_DATA.IrqEventTable[i] = IRQ_MASK32(i);

    CSL_SYS_DATA.OsPresent = biosPresent;               
 }     
/*----------------------------------------------------------------------------*/
IDEF CSLBool IRQ_test(Uint16 EventId) {
  Uint16 bit,reg,mask;
  int old_intm;
  bit= EventId & 0xfu; 
  reg=((EventId & 0x10) >> 4);
  mask=IRQ_MASK16(bit);
  old_intm = IRQ_globalDisable();
  bit = (CSLBool)((reg?(_IFR1 & mask): (_IFR0 & mask)) != 0);
  IRQ_globalRestore(old_intm);
  return bit;
}
/*----------------------------------------------------------------------------*/
 IDEF void IRQ_config(Uint16 EventId, IRQ_Config *Config) {
    CSL_IRQ_DATA.IrqDispatchTable[EventId].funcAddr = Config->funcAddr;
    CSL_IRQ_DATA.IrqDispatchTable[EventId].ierMask = (Config->ierMask == IRQ_IEMASK_SELF)? 
                                                                  ((Uint32)1u<<EventId) : Config->ierMask;
    CSL_IRQ_DATA.IrqDispatchTable[EventId].cacheCtrl = Config->cacheCtrl;
    CSL_IRQ_DATA.IrqDispatchTable[EventId].funcArg = Config->funcArg;
  
}
/*----------------------------------------------------------------------------*/
IDEF void IRQ_configArgs(Uint16 EventId, IRQ_IsrPtr funcAddr, Uint32 funcArg, Uint32 ierMask, Uint32 cacheCtrl) {
    CSL_IRQ_DATA.IrqDispatchTable[EventId].funcAddr = funcAddr;
    CSL_IRQ_DATA.IrqDispatchTable[EventId].ierMask = (ierMask == IRQ_IEMASK_SELF)?
                                                                 ((Uint32)1u<<EventId): ierMask;
    CSL_IRQ_DATA.IrqDispatchTable[EventId].cacheCtrl = cacheCtrl;
    CSL_IRQ_DATA.IrqDispatchTable[EventId].funcArg = funcArg; 
}

/*----------------------------------------------------------------------------*/
IDEF Uint32 IRQ_getArg(Uint16 EventId){
 return (CSL_IRQ_DATA.IrqDispatchTable[EventId].funcArg);
}
/*----------------------------------------------------------------------------*/
IDEF void IRQ_setArg(Uint16 EventId, Uint32 val){
 CSL_IRQ_DATA.IrqDispatchTable[EventId].funcArg = val;
}
/*----------------------------------------------------------------------------*/
IDEF void IRQ_map(Uint16 EventId){
  CSL_IRQ_DATA.IrqEventTable[EventId] = IRQ_MASK32(EventId);
}
/*----------------------------------------------------------------------------*/
IDEF void IRQ_getConfig(Uint16 EventId, IRQ_Config *Config) {
   Config->funcAddr = (IRQ_IsrPtr)(CSL_IRQ_DATA.IrqDispatchTable[EventId].funcAddr);
   Config->ierMask =  CSL_IRQ_DATA.IrqDispatchTable[EventId].ierMask;
   Config->cacheCtrl = CSL_IRQ_DATA.IrqDispatchTable[EventId].cacheCtrl;
   Config->funcArg = CSL_IRQ_DATA.IrqDispatchTable[EventId].funcArg; 
}
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
 IDEF int IRQ_setVecs(Uint32 Ivpd) {
   int old_intm;
   Uint16 old_ivpd;
   Uint16 val = (Uint16)((Ivpd & 0xFFFFFF00)>>8);
   old_intm = IRQ_globalDisable();
   old_ivpd = _IVPD;
   _IVPD = val;
   _IVPH = val;
   IRQ_globalRestore(old_intm);
   return old_ivpd;
 }  

#endif /* USEDEFS */

#elif (!(_IRQ_MOD_)) /* IRQ_SUPPORT */
  #error IRQ HAL Module Not Supported on Specified Target
#endif /* IRQ_SUPPORT */
#endif /* _CSL_IRQ_H_ */
/******************************************************************************\
* End of csl_irq.h
\******************************************************************************/

