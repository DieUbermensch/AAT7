/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... DMA
* FILENAME...... csl_dmahal.h
* DATE CREATED.. Tues 05/30/2000
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS.. stdinc.h, chip.h
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:   05/30/2000  created
*   MODIFIED:  03/23/2001  modified to support 5510 PG2.0 DMA
*   MODIFIED:  04/16/2001  modified header comments
*   MODIFIED:  01/24/2002  fixed definition of DMA_FMKS macro (preceding
*                          underscore problem)
*   MODIFIED:  07/18/2002  fixed bad addresses for CDEI and CDFI regs
*   MODIFIED:  08/13/2002  reDid addresses for CDEI/CDFI regs and implemented
*                          some of the 5502 DMA changes for GSCR and GCR
*   MODIFIED:  06/19/2003  adding GTCR register
*   MODIFIED:  07/22/2003  Fixed bad addresses for CDEIx and CDFIx registers
*   MODIFIED:  01/08/2004  Added WP field to DMACCR register(5502)
*   MODIFIED:  08/02/2004  Added 5501 support 
*   MODIFIED:  09/15/2004  Added AERR field in DMACSR and AERRIE in DMACICR registers 
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the DMA module)
*
* Registers Covered:
*   (RW) _DMA_DMAGCR     -  Global Control Register
*   (RW) _DMA_DMACSDPn   -  Channel #n Source Destination Parameters Register
*   (RW) _DMA_DMACCRn    -  Channel #n Control Register
*   (RW) _DMA_DMACICRn   -  Channel #n Interrupt Control Register
*   (RW) _DMA_DMACSRn    -  Channel #n Status Register
*   (RW) _DMA_DMACSSALn  -  Channel #n Source Start Address ,lower 16 bits
*   (RW) _DMA_DMACSSAUn  -  Channel #n Source Start Address ,upper 8 bits
*   (RW) _DMA_DMACDSALn  -  Channel #n Destination Start Address, lower 16 bits
*   (RW) _DMA_DMACDSAUn  -  Channel #n Destination Start Address, upper 16 bits
*   (RW) _DMA_DMACENn    -  Channel #n Element Number/Count Register
*   (RW) _DMA_DMACFNn    -  Channel #n Frame Number/Count Register
*   (RW) _DMA_DMACFIn    -  Channel #n Frame Index Register
*   (RW) _DMA_DMACEIn    -  Channel #n Element Index Register
* For 5502,5501, 5510 PG2.0 and 5509A
*   (RW) _DMA_DMAGTCR    -  Timeout Control Register (compatability with PG1.0)
*   (RW) _DMA_DMAGSCR    -  Software Compatability Register (compatability with PG1.0)
*   (RW) _DMA_DMACSEI    -  Channel #n Source Element Index Register
*   (RW) _DMA_DMACSFI    -  Channel #n Source Frame Index Register
*   (RW) _DMA_DMACDEI    -  Channel #n Destination Element Index Register
*   (RW) _DMA_DMACDFI    -  Channel #n Destination Frame Index Register
*   (R)  _DMA_DMACSAC    -  Channel #n Source Address Counter Register (Read Only Status)
*   (R)  _DMA_DMACDAC    -  Channel #n Destination Address Counter Register (Status)
\******************************************************************************/
#ifndef _DMAHAL_H_
#define _DMAHAL_H_

#include <csl_std.h>
#include <csl_stdhal.h>
#include <csl_chiphal.h>


/*============================================================================*\
* DMA address, register, and field generic macros
\*============================================================================*/
#define _DMA_PFIELD_GET(RegAddr,Field)            _PFIELD_GET(RegAddr,Field)
#define _DMA_PFIELD_SET(RegAddr,Field,Val)        _PFIELD_SET(RegAddr,Field,Val)
#define _DMA_FSETS(Reg,Field,Sym)                 DMA_FSET(##Reg,##Field,Field##_##Sym)

#define DMA_ADDR(Reg)                  _DMA_##Reg##_ADDR
#define DMA_RGET(Reg)                  _PREG_GET(DMA_ADDR(##Reg))
#define DMA_RSET(Reg,Val)              _PREG_SET(DMA_ADDR(##Reg),Val)
#define DMA_RAOI(Reg,AND,OR,INV)       _PREG_AOI(DMA_ADDR(##Reg),AND,OR,INV)
#define DMA_FGET(Reg,Field)            _DMA_PFIELD_GET(DMA_ADDR(##Reg),_DMA_##Reg##_##Field)
#define DMA_FSET(Reg,Field,Val)        _DMA_PFIELD_SET(DMA_ADDR(##Reg),_DMA_##Reg##_##Field,Val)
#define DMA_FSETS(Reg,Field,Sym)       _DMA_FSETS(##Reg,_DMA_##Reg##_##Field,Sym)
#define DMA_FMK(Reg,Field,Val)         _DMA_##Reg##_##Field##_MK(Val)
#define DMA_FMKS(Reg,Field,Sym)        DMA_FMK(##Reg,##Field,DMA_##Reg##_##Field##_##Sym)
#define DMA_FAOI(Reg,AND,OR,INV)       _PFIELD_AOI(DMA_ADDR(##Reg),_DMA_##Reg##_##Field,AND,OR,INV)

#define DMA_ADDRH(h,Reg)              _DMA_##Reg##_ADDR(((DMA_PrivateObj*)(h))->DmaChaNum)
#define DMA_RGETH(h,Reg)              _PREG_GET(DMA_ADDRH(h,##Reg))
#define DMA_RSETH(h,Reg,Val)          _PREG_SET(DMA_ADDRH(h,##Reg),Val)
#define DMA_RAOIH(h,Reg,AND,OR,INV)   _PREG_AOI(DMA_ADDRH(h,##Reg),AND,OR,INV)
#define DMA_FGETH(h,Reg,Field)        _PFIELD_GET(DMA_ADDRH(h,##Reg),_DMA_##Reg##_##Field)
#define DMA_FSETH(h,Reg,Field,Val)    _PFIELD_SET(DMA_ADDRH(h,##Reg),_DMA_##Reg##_##Field,Val)
#define DMA_FSETSH(h,Reg,Field,Sym)   DMA_FSET(##Reg,##Field,_DMA_##Reg##_##Field##_##Sym)
#define DMA_FAOIH(h,Reg,AND,OR,INV)   _PFIELD_AOI(DMA_ADDRH(h,##Reg),_DMA_##Reg##_##Field,AND,OR,INV)

#define DMA_ADDR_H(h,Reg)              _DMA_##Reg##_ADDR(((DMA_PrivateObj*)(h))->DmaChaNum)
#define DMA_RGET_H(h,Reg)              _PREG_GET(DMA_ADDRH(h,##Reg))
#define DMA_RSET_H(h,Reg,Val)          _PREG_SET(DMA_ADDRH(h,##Reg),Val)
#define DMA_RAOI_H(h,Reg,AND,OR,INV)   _PREG_AOI(DMA_ADDRH(h,##Reg),AND,OR,INV)
#define DMA_FGET_H(h,Reg,Field)        _PFIELD_GET(DMA_ADDRH(h,##Reg),_DMA_##Reg##_##Field)
#define DMA_FSET_H(h,Reg,Field,Val)    _PFIELD_SET(DMA_ADDRH(h,##Reg),_DMA_##Reg##_##Field,Val)
#define DMA_FSETS_H(h,Reg,Field,Sym)   DMA_FSET(##Reg,##Field,_DMA_##Reg##_##Field##_##Sym)
#define DMA_FAOI_H(h,Reg,AND,OR,INV)   _PFIELD_AOI(DMA_ADDRH(h,##Reg),_DMA_##Reg##_##Field,AND,OR,INV)

/*===============================================================================*\
* DMA Channel Field Macros
\*===============================================================================*/
#define _DMA_DMACSDP0_DSTBEN                 _DMA_DMACSDP_DSTBEN
#define _DMA_DMACSDP1_DSTBEN                 _DMA_DMACSDP_DSTBEN
#define _DMA_DMACSDP2_DSTBEN                 _DMA_DMACSDP_DSTBEN
#define _DMA_DMACSDP3_DSTBEN                 _DMA_DMACSDP_DSTBEN
#define _DMA_DMACSDP4_DSTBEN                 _DMA_DMACSDP_DSTBEN
#define _DMA_DMACSDP5_DSTBEN                 _DMA_DMACSDP_DSTBEN

#define _DMA_DMACSDP0_DSTPACK                _DMA_DMACSDP_DSTPACK
#define _DMA_DMACSDP1_DSTPACK                _DMA_DMACSDP_DSTPACK
#define _DMA_DMACSDP2_DSTPACK                _DMA_DMACSDP_DSTPACK
#define _DMA_DMACSDP3_DSTPACK                _DMA_DMACSDP_DSTPACK
#define _DMA_DMACSDP4_DSTPACK                _DMA_DMACSDP_DSTPACK
#define _DMA_DMACSDP5_DSTPACK                _DMA_DMACSDP_DSTPACK

#define _DMA_DMACSDP0_DST              _DMA_DMACSDP_DST
#define _DMA_DMACSDP1_DST              _DMA_DMACSDP_DST
#define _DMA_DMACSDP2_DST              _DMA_DMACSDP_DST
#define _DMA_DMACSDP3_DST              _DMA_DMACSDP_DST
#define _DMA_DMACSDP4_DST              _DMA_DMACSDP_DST
#define _DMA_DMACSDP5_DST              _DMA_DMACSDP_DST

#define _DMA_DMACSDP0_SRCBEN           _DMA_DMACSDP_SRCBEN
#define _DMA_DMACSDP1_SRCBEN           _DMA_DMACSDP_SRCBEN
#define _DMA_DMACSDP2_SRCBEN           _DMA_DMACSDP_SRCBEN
#define _DMA_DMACSDP3_SRCBEN           _DMA_DMACSDP_SRCBEN
#define _DMA_DMACSDP4_SRCBEN           _DMA_DMACSDP_SRCBEN
#define _DMA_DMACSDP5_SRCBEN           _DMA_DMACSDP_SRCBEN

#define _DMA_DMACSDP0_SRCPACK          _DMA_DMACSDP_SRCPACK
#define _DMA_DMACSDP1_SRCPACK          _DMA_DMACSDP_SRCPACK
#define _DMA_DMACSDP2_SRCPACK          _DMA_DMACSDP_SRCPACK
#define _DMA_DMACSDP3_SRCPACK          _DMA_DMACSDP_SRCPACK
#define _DMA_DMACSDP4_SRCPACK          _DMA_DMACSDP_SRCPACK
#define _DMA_DMACSDP5_SRCPACK          _DMA_DMACSDP_SRCPACK

#define _DMA_DMACSDP0_SRC              _DMA_DMACSDP_SRC
#define _DMA_DMACSDP1_SRC              _DMA_DMACSDP_SRC
#define _DMA_DMACSDP2_SRC              _DMA_DMACSDP_SRC
#define _DMA_DMACSDP3_SRC              _DMA_DMACSDP_SRC
#define _DMA_DMACSDP4_SRC              _DMA_DMACSDP_SRC
#define _DMA_DMACSDP5_SRC              _DMA_DMACSDP_SRC

#define _DMA_DMACSDP0_DATATYPE         _DMA_DMACSDP_DATATYPE
#define _DMA_DMACSDP1_DATATYPE         _DMA_DMACSDP_DATATYPE
#define _DMA_DMACSDP2_DATATYPE         _DMA_DMACSDP_DATATYPE
#define _DMA_DMACSDP3_DATATYPE         _DMA_DMACSDP_DATATYPE
#define _DMA_DMACSDP4_DATATYPE         _DMA_DMACSDP_DATATYPE
#define _DMA_DMACSDP5_DATATYPE         _DMA_DMACSDP_DATATYPE

#define _DMA_DMACCR0_DSTAMODE           _DMA_DMACCR_DSTAMODE
#define _DMA_DMACCR1_DSTAMODE           _DMA_DMACCR_DSTAMODE
#define _DMA_DMACCR2_DSTAMODE           _DMA_DMACCR_DSTAMODE
#define _DMA_DMACCR3_DSTAMODE           _DMA_DMACCR_DSTAMODE
#define _DMA_DMACCR4_DSTAMODE           _DMA_DMACCR_DSTAMODE
#define _DMA_DMACCR5_DSTAMODE           _DMA_DMACCR_DSTAMODE

#define _DMA_DMACCR0_SRCAMODE           _DMA_DMACCR_SRCAMODE
#define _DMA_DMACCR1_SRCAMODE           _DMA_DMACCR_SRCAMODE
#define _DMA_DMACCR2_SRCAMODE           _DMA_DMACCR_SRCAMODE
#define _DMA_DMACCR3_SRCAMODE           _DMA_DMACCR_SRCAMODE
#define _DMA_DMACCR4_SRCAMODE           _DMA_DMACCR_SRCAMODE
#define _DMA_DMACCR5_SRCAMODE           _DMA_DMACCR_SRCAMODE

#define _DMA_DMACCR0_ENDPROG            _DMA_DMACCR_ENDPROG
#define _DMA_DMACCR1_ENDPROG            _DMA_DMACCR_ENDPROG
#define _DMA_DMACCR2_ENDPROG            _DMA_DMACCR_ENDPROG
#define _DMA_DMACCR3_ENDPROG            _DMA_DMACCR_ENDPROG
#define _DMA_DMACCR4_ENDPROG            _DMA_DMACCR_ENDPROG
#define _DMA_DMACCR5_ENDPROG            _DMA_DMACCR_ENDPROG

#if (CHIP_5502) || (CHIP_5501)

#define _DMA_DMACCR0_WP                 _DMA_DMACCR_WP
#define _DMA_DMACCR1_WP                 _DMA_DMACCR_WP
#define _DMA_DMACCR2_WP                 _DMA_DMACCR_WP
#define _DMA_DMACCR3_WP                 _DMA_DMACCR_WP
#define _DMA_DMACCR4_WP                 _DMA_DMACCR_WP
#define _DMA_DMACCR5_WP                 _DMA_DMACCR_WP

#endif

#define _DMA_DMACCR0_REPEAT             _DMA_DMACCR_REPEAT
#define _DMA_DMACCR1_REPEAT             _DMA_DMACCR_REPEAT
#define _DMA_DMACCR2_REPEAT             _DMA_DMACCR_REPEAT
#define _DMA_DMACCR3_REPEAT             _DMA_DMACCR_REPEAT
#define _DMA_DMACCR4_REPEAT             _DMA_DMACCR_REPEAT
#define _DMA_DMACCR5_REPEAT             _DMA_DMACCR_REPEAT

#define _DMA_DMACCR0_AUTOINIT           _DMA_DMACCR_AUTOINIT
#define _DMA_DMACCR1_AUTOINIT           _DMA_DMACCR_AUTOINIT
#define _DMA_DMACCR2_AUTOINIT           _DMA_DMACCR_AUTOINIT
#define _DMA_DMACCR3_AUTOINIT           _DMA_DMACCR_AUTOINIT
#define _DMA_DMACCR4_AUTOINIT           _DMA_DMACCR_AUTOINIT
#define _DMA_DMACCR5_AUTOINIT           _DMA_DMACCR_AUTOINIT


#define _DMA_DMACCR0_EN                 _DMA_DMACCR_EN
#define _DMA_DMACCR1_EN                 _DMA_DMACCR_EN
#define _DMA_DMACCR2_EN                 _DMA_DMACCR_EN
#define _DMA_DMACCR3_EN                 _DMA_DMACCR_EN
#define _DMA_DMACCR4_EN                 _DMA_DMACCR_EN
#define _DMA_DMACCR5_EN                 _DMA_DMACCR_EN

#define _DMA_DMACCR0_PRIO               _DMA_DMACCR_PRIO
#define _DMA_DMACCR1_PRIO               _DMA_DMACCR_PRIO
#define _DMA_DMACCR2_PRIO               _DMA_DMACCR_PRIO
#define _DMA_DMACCR3_PRIO               _DMA_DMACCR_PRIO
#define _DMA_DMACCR4_PRIO               _DMA_DMACCR_PRIO
#define _DMA_DMACCR5_PRIO               _DMA_DMACCR_PRIO

#define _DMA_DMACCR0_FS                 _DMA_DMACCR_FS
#define _DMA_DMACCR1_FS                 _DMA_DMACCR_FS
#define _DMA_DMACCR2_FS                 _DMA_DMACCR_FS
#define _DMA_DMACCR3_FS                 _DMA_DMACCR_FS
#define _DMA_DMACCR4_FS                 _DMA_DMACCR_FS
#define _DMA_DMACCR5_FS                 _DMA_DMACCR_FS

#define _DMA_DMACCR0_SYNC               _DMA_DMACCR_SYNC
#define _DMA_DMACCR1_SYNC               _DMA_DMACCR_SYNC
#define _DMA_DMACCR2_SYNC               _DMA_DMACCR_SYNC
#define _DMA_DMACCR3_SYNC               _DMA_DMACCR_SYNC
#define _DMA_DMACCR4_SYNC               _DMA_DMACCR_SYNC
#define _DMA_DMACCR5_SYNC               _DMA_DMACCR_SYNC

#define _DMA_DMACICR0_AERRIE           _DMA_DMACICR_AERRIE
#define _DMA_DMACICR1_AERRIE           _DMA_DMACICR_AERRIE
#define _DMA_DMACICR2_AERRIE           _DMA_DMACICR_AERRIE
#define _DMA_DMACICR3_AERRIE           _DMA_DMACICR_AERRIE
#define _DMA_DMACICR4_AERRIE           _DMA_DMACICR_AERRIE
#define _DMA_DMACICR5_AERRIE           _DMA_DMACICR_AERRIE

#define _DMA_DMACICR0_BLOCKIE          _DMA_DMACICR_BLOCKIE
#define _DMA_DMACICR1_BLOCKIE          _DMA_DMACICR_BLOCKIE
#define _DMA_DMACICR2_BLOCKIE          _DMA_DMACICR_BLOCKIE
#define _DMA_DMACICR3_BLOCKIE          _DMA_DMACICR_BLOCKIE
#define _DMA_DMACICR4_BLOCKIE          _DMA_DMACICR_BLOCKIE
#define _DMA_DMACICR5_BLOCKIE          _DMA_DMACICR_BLOCKIE

#define _DMA_DMACICR0_LASTIE           _DMA_DMACICR_LASTIE
#define _DMA_DMACICR1_LASTIE           _DMA_DMACICR_LASTIE
#define _DMA_DMACICR2_LASTIE           _DMA_DMACICR_LASTIE
#define _DMA_DMACICR3_LASTIE           _DMA_DMACICR_LASTIE
#define _DMA_DMACICR4_LASTIE           _DMA_DMACICR_LASTIE
#define _DMA_DMACICR5_LASTIE           _DMA_DMACICR_LASTIE

#define _DMA_DMACICR0_FRAMEIE          _DMA_DMACICR_FRAMEIE
#define _DMA_DMACICR1_FRAMEIE          _DMA_DMACICR_FRAMEIE
#define _DMA_DMACICR2_FRAMEIE          _DMA_DMACICR_FRAMEIE
#define _DMA_DMACICR3_FRAMEIE          _DMA_DMACICR_FRAMEIE
#define _DMA_DMACICR4_FRAMEIE          _DMA_DMACICR_FRAMEIE
#define _DMA_DMACICR5_FRAMEIE          _DMA_DMACICR_FRAMEIE

#define _DMA_DMACICR0_HALFIE      _DMA_DMACICR_HALFIE
#define _DMA_DMACICR1_HALFIE      _DMA_DMACICR_HALFIE
#define _DMA_DMACICR2_HALFIE      _DMA_DMACICR_HALFIE
#define _DMA_DMACICR3_HALFIE      _DMA_DMACICR_HALFIE
#define _DMA_DMACICR4_HALFIE      _DMA_DMACICR_HALFIE
#define _DMA_DMACICR5_HALFIE      _DMA_DMACICR_HALFIE

#define _DMA_DMACICR0_DROPIE           _DMA_DMACICR_DROPIE
#define _DMA_DMACICR1_DROPIE           _DMA_DMACICR_DROPIE
#define _DMA_DMACICR2_DROPIE           _DMA_DMACICR_DROPIE
#define _DMA_DMACICR3_DROPIE           _DMA_DMACICR_DROPIE
#define _DMA_DMACICR4_DROPIE           _DMA_DMACICR_DROPIE
#define _DMA_DMACICR5_DROPIE           _DMA_DMACICR_DROPIE

#define _DMA_DMACICR0_TIMEOUTIE        _DMA_DMACICR_TIMEOUTIE
#define _DMA_DMACICR1_TIMEOUTIE        _DMA_DMACICR_TIMEOUTIE
#define _DMA_DMACICR2_TIMEOUTIE        _DMA_DMACICR_TIMEOUTIE
#define _DMA_DMACICR3_TIMEOUTIE        _DMA_DMACICR_TIMEOUTIE
#define _DMA_DMACICR4_TIMEOUTIE        _DMA_DMACICR_TIMEOUTIE
#define _DMA_DMACICR5_TIMEOUTIE        _DMA_DMACICR_TIMEOUTIE

#define _DMA_DMACSR0_AERR                  _DMA_DMACSR_AERR
#define _DMA_DMACSR1_AERR                  _DMA_DMACSR_AERR
#define _DMA_DMACSR2_AERR                  _DMA_DMACSR_AERR
#define _DMA_DMACSR3_AERR                  _DMA_DMACSR_AERR
#define _DMA_DMACSR4_AERR                  _DMA_DMACSR_AERR
#define _DMA_DMACSR5_AERR                  _DMA_DMACSR_AERR

#define _DMA_DMACSR0_SYNC                  _DMA_DMACSR_SYNC
#define _DMA_DMACSR1_SYNC                  _DMA_DMACSR_SYNC
#define _DMA_DMACSR2_SYNC                  _DMA_DMACSR_SYNC
#define _DMA_DMACSR3_SYNC                  _DMA_DMACSR_SYNC
#define _DMA_DMACSR4_SYNC                  _DMA_DMACSR_SYNC
#define _DMA_DMACSR5_SYNC                  _DMA_DMACSR_SYNC

#define _DMA_DMACSR0_BLOCK                 _DMA_DMACSR_BLOCK
#define _DMA_DMACSR1_BLOCK                 _DMA_DMACSR_BLOCK
#define _DMA_DMACSR2_BLOCK                 _DMA_DMACSR_BLOCK
#define _DMA_DMACSR3_BLOCK                 _DMA_DMACSR_BLOCK
#define _DMA_DMACSR4_BLOCK                 _DMA_DMACSR_BLOCK
#define _DMA_DMACSR5_BLOCK                 _DMA_DMACSR_BLOCK

#define _DMA_DMACSR0_LAST                  _DMA_DMACSR_LAST
#define _DMA_DMACSR1_LAST                  _DMA_DMACSR_LAST
#define _DMA_DMACSR2_LAST                  _DMA_DMACSR_LAST
#define _DMA_DMACSR3_LAST                  _DMA_DMACSR_LAST
#define _DMA_DMACSR4_LAST                  _DMA_DMACSR_LAST
#define _DMA_DMACSR5_LAST                  _DMA_DMACSR_LAST

#define _DMA_DMACSR0_FRAME                 _DMA_DMACSR_FRAME
#define _DMA_DMACSR1_FRAME                 _DMA_DMACSR_FRAME
#define _DMA_DMACSR2_FRAME                 _DMA_DMACSR_FRAME
#define _DMA_DMACSR3_FRAME                 _DMA_DMACSR_FRAME
#define _DMA_DMACSR4_FRAME                 _DMA_DMACSR_FRAME
#define _DMA_DMACSR5_FRAME                 _DMA_DMACSR_FRAME

#define _DMA_DMACSR0_DROP                  _DMA_DMACSR_DROP
#define _DMA_DMACSR1_DROP                  _DMA_DMACSR_DROP
#define _DMA_DMACSR2_DROP                  _DMA_DMACSR_DROP
#define _DMA_DMACSR3_DROP                  _DMA_DMACSR_DROP
#define _DMA_DMACSR4_DROP                  _DMA_DMACSR_DROP
#define _DMA_DMACSR5_DROP                  _DMA_DMACSR_DROP

#define _DMA_DMACSR0_HALF                  _DMA_DMACSR_HALF
#define _DMA_DMACSR1_HALF                  _DMA_DMACSR_HALF
#define _DMA_DMACSR2_HALF                  _DMA_DMACSR_HALF
#define _DMA_DMACSR3_HALF                  _DMA_DMACSR_HALF
#define _DMA_DMACSR4_HALF                  _DMA_DMACSR_HALF
#define _DMA_DMACSR5_HALF                  _DMA_DMACSR_HALF

#define _DMA_DMACSR0_TIMEOUT               _DMA_DMACSR_TIMEOUT
#define _DMA_DMACSR1_TIMEOUT               _DMA_DMACSR_TIMEOUT
#define _DMA_DMACSR2_TIMEOUT               _DMA_DMACSR_TIMEOUT
#define _DMA_DMACSR3_TIMEOUT               _DMA_DMACSR_TIMEOUT
#define _DMA_DMACSR4_TIMEOUT               _DMA_DMACSR_TIMEOUT
#define _DMA_DMACSR5_TIMEOUT               _DMA_DMACSR_TIMEOUT

#define _DMA_DMACSSAL0_SSAL                _DMA_DMACSSAL_SSAL
#define _DMA_DMACSSAL1_SSAL                _DMA_DMACSSAL_SSAL
#define _DMA_DMACSSAL2_SSAL                _DMA_DMACSSAL_SSAL
#define _DMA_DMACSSAL3_SSAL                _DMA_DMACSSAL_SSAL
#define _DMA_DMACSSAL4_SSAL                _DMA_DMACSSAL_SSAL
#define _DMA_DMACSSAL5_SSAL                _DMA_DMACSSAL_SSAL

#define _DMA_DMACSSAU0_SSAU                _DMA_DMACSSAU_SSAU
#define _DMA_DMACSSAU1_SSAU                _DMA_DMACSSAU_SSAU
#define _DMA_DMACSSAU2_SSAU                _DMA_DMACSSAU_SSAU
#define _DMA_DMACSSAU3_SSAU                _DMA_DMACSSAU_SSAU
#define _DMA_DMACSSAU4_SSAU                _DMA_DMACSSAU_SSAU
#define _DMA_DMACSSAU5_SSAU                _DMA_DMACSSAU_SSAU

#define _DMA_DMACDSAL0_DSAL                _DMA_DMACDSAL_DSAL
#define _DMA_DMACDSAL1_DSAL                _DMA_DMACDSAL_DSAL
#define _DMA_DMACDSAL2_DSAL                _DMA_DMACDSAL_DSAL
#define _DMA_DMACDSAL3_DSAL                _DMA_DMACDSAL_DSAL
#define _DMA_DMACDSAL4_DSAL                _DMA_DMACDSAL_DSAL
#define _DMA_DMACDSAL5_DSAL                _DMA_DMACDSAL_DSAL

#define _DMA_DMACDSAU0_DSAU                _DMA_DMACDSAU_DSAU
#define _DMA_DMACDSAU1_DSAU                _DMA_DMACDSAU_DSAU
#define _DMA_DMACDSAU2_DSAU                _DMA_DMACDSAU_DSAU
#define _DMA_DMACDSAU3_DSAU                _DMA_DMACDSAU_DSAU
#define _DMA_DMACDSAU4_DSAU                _DMA_DMACDSAU_DSAU
#define _DMA_DMACDSAU5_DSAU                _DMA_DMACDSAU_DSAU

#define _DMA_DMACEN0_ELEMENTNUM            _DMA_DMACEN_ELEMENTNUM
#define _DMA_DMACEN1_ELEMENTNUM            _DMA_DMACEN_ELEMENTNUM
#define _DMA_DMACEN2_ELEMENTNUM            _DMA_DMACEN_ELEMENTNUM
#define _DMA_DMACEN3_ELEMENTNUM            _DMA_DMACEN_ELEMENTNUM
#define _DMA_DMACEN4_ELEMENTNUM            _DMA_DMACEN_ELEMENTNUM
#define _DMA_DMACEN5_ELEMENTNUM            _DMA_DMACEN_ELEMENTNUM

#define _DMA_DMACFN0_FRAMENUM              _DMA_DMACFN_FRAMENUM
#define _DMA_DMACFN1_FRAMENUM              _DMA_DMACFN_FRAMENUM
#define _DMA_DMACFN2_FRAMENUM              _DMA_DMACFN_FRAMENUM
#define _DMA_DMACFN3_FRAMENUM              _DMA_DMACFN_FRAMENUM
#define _DMA_DMACFN4_FRAMENUM              _DMA_DMACFN_FRAMENUM
#define _DMA_DMACFN5_FRAMENUM              _DMA_DMACFN_FRAMENUM

#define _DMA_DMACFI0_FRAMENDX              _DMA_DMACFI_FRAMENDX
#define _DMA_DMACFI1_FRAMENDX              _DMA_DMACFI_FRAMENDX
#define _DMA_DMACFI2_FRAMENDX              _DMA_DMACFI_FRAMENDX
#define _DMA_DMACFI3_FRAMENDX              _DMA_DMACFI_FRAMENDX
#define _DMA_DMACFI4_FRAMENDX              _DMA_DMACFI_FRAMENDX
#define _DMA_DMACFI5_FRAMENDX              _DMA_DMACFI_FRAMENDX

#define _DMA_DMACEI0_ELEMENTNDX            _DMA_DMACEI_ELEMENTNDX
#define _DMA_DMACEI1_ELEMENTNDX            _DMA_DMACEI_ELEMENTNDX
#define _DMA_DMACEI2_ELEMENTNDX            _DMA_DMACEI_ELEMENTNDX
#define _DMA_DMACEI3_ELEMENTNDX            _DMA_DMACEI_ELEMENTNDX
#define _DMA_DMACEI4_ELEMENTNDX            _DMA_DMACEI_ELEMENTNDX
#define _DMA_DMACEI5_ELEMENTNDX            _DMA_DMACEI_ELEMENTNDX

#define _DMA_DMACSFI0_FRAMENDX              _DMA_DMACSFI_FRAMENDX
#define _DMA_DMACSFI1_FRAMENDX              _DMA_DMACSFI_FRAMENDX
#define _DMA_DMACSFI2_FRAMENDX              _DMA_DMACSFI_FRAMENDX
#define _DMA_DMACSFI3_FRAMENDX              _DMA_DMACSFI_FRAMENDX
#define _DMA_DMACSFI4_FRAMENDX              _DMA_DMACSFI_FRAMENDX
#define _DMA_DMACSFI5_FRAMENDX              _DMA_DMACSFI_FRAMENDX

#define _DMA_DMACSEI0_ELEMENTNDX            _DMA_DMACSEI_ELEMENTNDX
#define _DMA_DMACSEI1_ELEMENTNDX            _DMA_DMACSEI_ELEMENTNDX
#define _DMA_DMACSEI2_ELEMENTNDX            _DMA_DMACSEI_ELEMENTNDX
#define _DMA_DMACSEI3_ELEMENTNDX            _DMA_DMACSEI_ELEMENTNDX
#define _DMA_DMACSEI4_ELEMENTNDX            _DMA_DMACSEI_ELEMENTNDX
#define _DMA_DMACSEI5_ELEMENTNDX            _DMA_DMACSEI_ELEMENTNDX

#define _DMA_DMACDFI0_FRAMENDX              _DMA_DMACDFI_FRAMENDX
#define _DMA_DMACDFI1_FRAMENDX              _DMA_DMACDFI_FRAMENDX
#define _DMA_DMACDFI2_FRAMENDX              _DMA_DMACDFI_FRAMENDX
#define _DMA_DMACDFI3_FRAMENDX              _DMA_DMACDFI_FRAMENDX
#define _DMA_DMACDFI4_FRAMENDX              _DMA_DMACDFI_FRAMENDX
#define _DMA_DMACDFI5_FRAMENDX              _DMA_DMACDFI_FRAMENDX

#define _DMA_DMACDEI0_ELEMENTNDX            _DMA_DMACDEI_ELEMENTNDX
#define _DMA_DMACDEI1_ELEMENTNDX            _DMA_DMACDEI_ELEMENTNDX
#define _DMA_DMACDEI2_ELEMENTNDX            _DMA_DMACDEI_ELEMENTNDX
#define _DMA_DMACDEI3_ELEMENTNDX            _DMA_DMACDEI_ELEMENTNDX
#define _DMA_DMACDEI4_ELEMENTNDX            _DMA_DMACDEI_ELEMENTNDX
#define _DMA_DMACDEI5_ELEMENTNDX            _DMA_DMACDEI_ELEMENTNDX



/*============================================================================*\
* misc declarations
\*============================================================================*/

#define DMA_DEVICE_CNT                 (6) 
#define _DMA_CHA_CNT                   (6)
#define _DMA_BASE_ADDR                 (0x0C00u)

#define _DMA_DMACSDP_OFFSET            (0x0000u)
#define _DMA_DMACCR_OFFSET             (0x0001u)
#define _DMA_DMACICR_OFFSET            (0x0002u)
#define _DMA_DMACSR_OFFSET             (0x0003u)
#define _DMA_DMACSSAL_OFFSET           (0x0004u)
#define _DMA_DMACSSAU_OFFSET           (0x0005u)
#define _DMA_DMACDSAL_OFFSET           (0x0006u)
#define _DMA_DMACDSAU_OFFSET           (0x0007u)
#define _DMA_DMACEN_OFFSET             (0x0008u)
#define _DMA_DMACFN_OFFSET             (0x0009u)
#define _DMA_DMACFI_OFFSET             (0x000Au)
#define _DMA_DMACEI_OFFSET             (0x000Bu)

#if _DMA_DST_AND_SRC_INDEX_SUPPORT
  #define _DMA_DMACSFI_OFFSET          (0x000Au)
  #define _DMA_DMACSEI_OFFSET          (0x000Bu)
  #define _DMA_DMACDFI_OFFSET          (0x000Fu)
  #define _DMA_DMACDEI_OFFSET          (0x000Eu)
  #define _DMA_DMACSAC_OFFSET          (0x000Cu)
  #define _DMA_DMACDAC_OFFSET          (0x000Du)
#endif

#define _DMA_CHAN_SZ                   (0x0020u)

#define _DMA_DMACSDP_ADDR(n)           (((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACSDP_OFFSET)
#define _DMA_DMACCR_ADDR(n)            (((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACCR_OFFSET)
#define _DMA_DMACICR_ADDR(n)           (((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACICR_OFFSET)
#define _DMA_DMACSR_ADDR(n)            (((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACSR_OFFSET)
#define _DMA_DMACSSAL_ADDR(n)          (((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACSSAL_OFFSET)        
#define _DMA_DMACSSAU_ADDR(n)          (((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACSSAU_OFFSET)        
#define _DMA_DMACDSAL_ADDR(n)          (((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACDSAL_OFFSET)
#define _DMA_DMACDSAU_ADDR(n)          (((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACDSAU_OFFSET)
#define _DMA_DMACEN_ADDR(n)            (((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACEN_OFFSET)
#define _DMA_DMACFN_ADDR(n)            (((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACFN_OFFSET)
#define _DMA_DMACFI_ADDR(n)            (((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACFI_OFFSET)
#define _DMA_DMACEI_ADDR(n)            (((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACEI_OFFSET)

#define _DMA_DMACSDP(n)                PREG16(((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACSDP_OFFSET)
#define _DMA_DMACCR(n)                 PREG16(((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACCR_OFFSET)
#define _DMA_DMACICR(n)                PREG16(((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACICR_OFFSET)
#define _DMA_DMACSR(n)                 PREG16(((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACSR_OFFSET)
#define _DMA_DMACSSAL(n)               PREG16(((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACSSAL_OFFSET)        
#define _DMA_DMACSSAU(n)               PREG16(((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACSSAU_OFFSET)        
#define _DMA_DMACDSAL(n)               PREG16(((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACDSAL_OFFSET)
#define _DMA_DMACDSAU(n)               PREG16(((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACDSAU_OFFSET)
#define _DMA_DMACEN(n)                 PREG16(((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACEN_OFFSET)
#define _DMA_DMACFN(n)                 PREG16(((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACFN_OFFSET)
#define _DMA_DMACFI(n)                 PREG16(((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACFI_OFFSET)
#define _DMA_DMACEI(n)                 PREG16(((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACEI_OFFSET)

#if _DMA_DST_AND_SRC_INDEX_SUPPORT        
#define _DMA_DMACSFI(n)                 PREG16(((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACSFI_OFFSET)
#define _DMA_DMACSEI(n)                 PREG16(((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACSEI_OFFSET)
#define _DMA_DMACDFI(n)                 PREG16(((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACDFI_OFFSET)
#define _DMA_DMACDEI(n)                 PREG16(((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACDEI_OFFSET)
#define _DMA_DMACSAC(n)                 PREG16(((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACSAC_OFFSET)
#define _DMA_DMACDAC(n)                 PREG16(((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACDAC_OFFSET)
#define _DMA_DMACDFI_ADDR(n)            (((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACDFI_OFFSET)
#define _DMA_DMACDEI_ADDR(n)            (((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACDEI_OFFSET)
#define _DMA_DMACSFI_ADDR(n)            (((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACSFI_OFFSET)
#define _DMA_DMACSEI_ADDR(n)            (((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACSEI_OFFSET)
#define _DMA_DMACSAC_ADDR(n)            (((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACSAC_OFFSET)
#define _DMA_DMACDAC_ADDR(n)            (((n) * _DMA_CHAN_SZ) + _DMA_BASE_ADDR + _DMA_DMACDAC_OFFSET)
#endif

/*============================================================================*\
* _DMA_DMAGCR:  Global Control Register
\*============================================================================*/
#define _DMA_DMAGCR_ADDR				(0x0E00u)
#define _DMA_DMAGCR                       	PREG16(_DMA_DMAGCR_ADDR)
#define DMA_DMAGCR                              _DMA_DMAGCR

/*============================================================================*\
* _DMA_DMAGCR_GET and _DMA_DMAGCR_SET
\*============================================================================*/
#define _DMA_DMAGCR_GET(RegAddr)  		_PREG_GET(RegAddr)
#define _DMA_DMAGCR_SET(RegAddr,Val)   	_PREG_SET(RegAddr,Val)

#if (_DMA_DST_AND_SRC_INDEX_SUPPORT)
  /*============================================================================*\
  * _DMA_DMAGTCR:  Global Timeout Counter Register
  \*============================================================================*/
  #if (CHIP_5502) || (CHIP_5501)
    #define _DMA_DMAGTCR_ADDR				(0x0E01u)
  #else
    #define _DMA_DMAGTCR_ADDR				(0x0E03u)
  #endif
  #define _DMA_DMAGTCR                       	PREG16(_DMA_DMAGTCR_ADDR)
  #define DMA_DMAGTCR                              _DMA_DMAGTCR

  /*============================================================================*\
  * _DMA_DMAGTCR_GET and _DMA_DMAGTCR_SET
  \*============================================================================*/
  #define _DMA_DMAGTCR_GET(RegAddr)  		_PREG_GET(RegAddr)
  #define _DMA_DMAGTCR_SET(RegAddr,Val)   	_PREG_SET(RegAddr,Val)
#endif

#if (_DMA_DST_AND_SRC_INDEX_SUPPORT) && (((CHIP_5502) || (CHIP_5501))==0)
  /*============================================================================*\
  * _DMA_DMAGSCR:  Global Software Compatability Register
  \*============================================================================*/
  #define _DMA_DMAGSCR_ADDR				(0x0E02u)
  #define _DMA_DMAGSCR                       	PREG16(_DMA_DMAGSCR_ADDR)
  #define DMA_DMAGSCR                              _DMA_DMAGSCR

  /*============================================================================*\
  * _DMA_DMAGSCR_GET and _DMA_DMAGSCR_SET
  \*============================================================================*/
  #define _DMA_DMAGSCR_GET(RegAddr)  		_PREG_GET(RegAddr)
  #define _DMA_DMAGSCR_SET(RegAddr,Val)   	_PREG_SET(RegAddr,Val)
#endif


/*============================================================================*\
*  DMA Channel #0 Channel Control Registers
\*============================================================================*/
#define _DMA_DMACSDP0_ADDR				(0x0C00u)
#define _DMA_DMACSDP0                       	PREG16(_DMA_DMACSDP0_ADDR)
#define DMA_DMACSDP0                            _DMA_DMACSDP0

#define _DMA_DMACCR0_ADDR				(0x0C01u)
#define _DMA_DMACCR0                      	PREG16(_DMA_DMACCR0_ADDR)
#define DMA_DMACCR0                             _DMA_DMACCR0

#define _DMA_DMACICR0_ADDR				(0x0C02u)
#define _DMA_DMACICR0                      	PREG16(_DMA_DMACICR0_ADDR)
#define DMA_DMACICR0                            _DMA_DMACICR0

#define _DMA_DMACSR0_ADDR				(0x0C03u)
#define _DMA_DMACSR0                      	PREG16(_DMA_DMACSR0_ADDR)
#define DMA_DMACSR0                            _DMA_DMACSR0

#define _DMA_DMACSSAL0_ADDR		   	     (0x0C04u)
#define _DMA_DMACSSAL0                         PREG16(_DMA_DMACSSAL0_ADDR)
#define DMA_DMACSSAL0                          _DMA_DMACSSAL0

#define _DMA_DMACSSAU0_ADDR                    (0x0C05)
#define _DMA_DMACSSAU0                          PREG16(_DMA_DMACSSAU0_ADDR)
#define DMA_DMACSSAU0                           _DMA_DMACSSAU0

#define _DMA_DMACDSAL0_ADDR                    (0x0C06u)
#define _DMA_DMACDSAL0                         PREG16(_DMA_DMACDSAL0_ADDR)
#define DMA_DMACDSAL0                          _DMA_DMACDSAL0

#define _DMA_DMACDSAU0_ADDR                    (0x0C07u)
#define _DMA_DMACDSAU0                         PREG16(_DMA_DMACDSAU0_ADDR)
#define DMA_DMACDSAU0                          _DMA_DMACDSAU0

#define _DMA_DMACEN0_ADDR                     (0x0C08u)
#define _DMA_DMACEN0                          PREG16(_DMA_DMACEN0_ADDR)
#define DMA_DMACEN0                           _DMA_DMACEN0

#define _DMA_DMACFN0_ADDR                     (0x0C09u)
#define _DMA_DMACFN0                           PREG16(_DMA_DMACFN0_ADDR)
#define DMA_DMACFN0                            _DMA_DMACFN0

#define _DMA_DMACFI0_ADDR                     (0x0C0Au)
#define _DMA_DMACFI0                          PREG16(_DMA_DMACFI0_ADDR)
#define DMA_DMACFI0                           _DMA_DMACFI0

#define _DMA_DMACEI0_ADDR                     (0x0C0Bu)
#define _DMA_DMACEI0                          PREG16(_DMA_DMACEI0_ADDR)
#define DMA_DMACEI0                           _DMA_DMACEI0

#if _DMA_DST_AND_SRC_INDEX_SUPPORT
  #define _DMA_DMACSFI0_ADDR                     (0x0C0Au)
  #define _DMA_DMACSFI0                          PREG16(_DMA_DMACSFI0_ADDR)
  #define DMA_DMACSFI0                           _DMA_DMACFI0

  #define _DMA_DMACSEI0_ADDR                     (0x0C0Bu)
  #define _DMA_DMACSEI0                          PREG16(_DMA_DMACSEI0_ADDR)
  #define DMA_DMACSEI0                           _DMA_DMACSEI0

  #define _DMA_DMACDFI0_ADDR                     (0x0C0Fu)
  #define _DMA_DMACDFI0                          PREG16(_DMA_DMACSFI0_ADDR)
  #define DMA_DMACDFI0                           _DMA_DMACFI0

  #define _DMA_DMACDEI0_ADDR                     (0x0C0Eu)
  #define _DMA_DMACDEI0                          PREG16(_DMA_DMACDEI0_ADDR)
  #define DMA_DMACDEI0                           _DMA_DMACDEI0

  #define _DMA_DMACDAC0_ADDR                     (0x0C0Du)
  #define _DMA_DMACDAC0                           PREG16(_DMA_DMACDAC0_ADDR)
  #define DMA_DMACDAC0                            _DMA_DMACDAC0

  #define _DMA_DMACSAC0_ADDR                     (0x0C0Cu)
  #define _DMA_DMACSAC0                           PREG16(_DMA_DMACSAC0_ADDR)
  #define DMA_DMACSAC0                            _DMA_DMACSAC0
#endif

/*============================================================================*\
*  DMA Channel #1 Channel Control Registers
\*============================================================================*/
#define _DMA_DMACSDP1_ADDR				(0x0C20u)
#define _DMA_DMACSDP1                       	PREG16(_DMA_DMACSDP1_ADDR)
#define DMA_DMACSDP1                            _DMA_DMACSDP1

#define _DMA_DMACCR1_ADDR				(0x0C21u)
#define _DMA_DMACCR1                      	PREG16(_DMA_DMACCR1_ADDR)
#define DMA_DMACCR1                             _DMA_DMACCR1

#define _DMA_DMACICR1_ADDR				(0x0C22u)
#define _DMA_DMACICR1                      	PREG16(_DMA_DMACICR1_ADDR)
#define DMA_DMACICR1                            _DMA_DMACICR1

#define _DMA_DMACSR1_ADDR				(0x0C23u)
#define _DMA_DMACSR1                      	PREG16(_DMA_DMACSR1_ADDR)
#define DMA_DMACSR1                             _DMA_DMACSR1

#define _DMA_DMACSSAL1_ADDR			      (0x0C24u)
#define _DMA_DMACSSAL1                          PREG16(_DMA_DMACSSAL1_ADDR)
#define DMA_DMACSSAL1                           _DMA_DMACSSAL1

#define _DMA_DMACSSAU1_ADDR			      (0x0C25)
#define _DMA_DMACSSAU1                     	PREG16(_DMA_DMACSSAU1_ADDR)
#define DMA_DMACSSAU1                           _DMA_DMACSSAU1

#define _DMA_DMACDSAL1_ADDR			      (0x0C26u)
#define _DMA_DMACDSAL1                          PREG16(_DMA_DMACDSAL1_ADDR)
#define DMA_DMACDSAL1                           _DMA_DMACDSAL1

#define _DMA_DMACDSAU1_ADDR			      (0x0C27u)
#define _DMA_DMACDSAU1                     	PREG16(_DMA_DMACDSAU1_ADDR)
#define DMA_DMACDSAU1                           _DMA_DMACDSAU1

#define _DMA_DMACEN1_ADDR			      (0x0C28u)
#define _DMA_DMACEN1                     	      PREG16(_DMA_DMACEN1_ADDR)
#define DMA_DMACEN1                             _DMA_DMACEN1

#define _DMA_DMACFN1_ADDR			      (0x0C29u)
#define _DMA_DMACFN1                     	      PREG16(_DMA_DMACFN1_ADDR)
#define DMA_DMACFN1                             _DMA_DMACFN1

#define _DMA_DMACFI1_ADDR			      (0x0C2Au)
#define _DMA_DMACFI1                     	      PREG16(_DMA_DMACFI1_ADDR)
#define DMA_DMACFI1                             _DMA_DMACFI1

#define _DMA_DMACEI1_ADDR			      (0x0C2Bu)
#define _DMA_DMACEI1                     	      PREG16(_DMA_DMACEI1_ADDR)
#define DMA_DMACEI1                             _DMA_DMACEI1

#if _DMA_DST_AND_SRC_INDEX_SUPPORT
  #define _DMA_DMACSFI1_ADDR                     (0x0C2Au)
  #define _DMA_DMACSFI1                          PREG16(_DMA_DMACSFI1_ADDR)
  #define DMA_DMACSFI1                           _DMA_DMACFI1

  #define _DMA_DMACSEI1_ADDR                     (0x0C2Bu)
  #define _DMA_DMACSEI1                          PREG16(_DMA_DMACSEI1_ADDR)
  #define DMA_DMACSEI1                           _DMA_DMACSEI1

  #define _DMA_DMACDFI1_ADDR                     (0x0C2Fu)
  #define _DMA_DMACDFI1                          PREG16(_DMA_DMACSFI1_ADDR)
  #define DMA_DMACDFI1                           _DMA_DMACFI1

  #define _DMA_DMACDEI1_ADDR                     (0x0C2Eu)
  #define _DMA_DMACDEI1                          PREG16(_DMA_DMACDEI1_ADDR)
  #define DMA_DMACDEI1                           _DMA_DMACDEI1

  #define _DMA_DMACDAC1_ADDR                     (0x0C2Du)
  #define _DMA_DMACDAC1                           PREG16(_DMA_DMACDAC1_ADDR)
  #define DMA_DMACDAC1                           _DMA_DMACDAC1

  #define _DMA_DMACSAC1_ADDR                      (0x0C2Cu)
  #define _DMA_DMACSAC1                           PREG16(_DMA_DMACSAC1_ADDR)
  #define DMA_DMACSAC1                           _DMA_DMACSAC1
#endif

/*============================================================================*\
*  DMA Channel #2 Channel Control Registers
\*============================================================================*/
#define _DMA_DMACSDP2_ADDR				(0x0C40u)
#define _DMA_DMACSDP2                       	PREG16(_DMA_DMACSDP2_ADDR)
#define DMA_DMACSDP2                            _DMA_DMACSDP2

#define _DMA_DMACCR2_ADDR				(0x0C41u)
#define _DMA_DMACCR2                      	PREG16(_DMA_DMACCR2_ADDR)
#define DMA_DMACCR2                             _DMA_DMACCR2

#define _DMA_DMACICR2_ADDR				(0x0C42u)
#define _DMA_DMACICR2                      	PREG16(_DMA_DMACICR2_ADDR)
#define DMA_DMACICR2                            _DMA_DMACICR2

#define _DMA_DMACSR2_ADDR				(0x0C43u)
#define _DMA_DMACSR2                      	PREG16(_DMA_DMACSR2_ADDR)
#define DMA_DMACSR2                             _DMA_DMACSR2

#define _DMA_DMACSSAL2_ADDR			      (0x0C44u)
#define _DMA_DMACSSAL2                          PREG16(_DMA_DMACSSAL2_ADDR)
#define DMA_DMACSSAL2                           _DMA_DMACSSAL2

#define _DMA_DMACSSAU2_ADDR			      (0x0C45)
#define _DMA_DMACSSAU2                     	PREG16(_DMA_DMACSSAU2_ADDR)
#define DMA_DMACSSAU2                           _DMA_DMACSSAU2

#define _DMA_DMACDSAL2_ADDR			      (0x0C46u)
#define _DMA_DMACDSAL2                          PREG16(_DMA_DMACDSAL2_ADDR)
#define DMA_DMACDSAL2                           _DMA_DMACDSAL2

#define _DMA_DMACDSAU2_ADDR			      (0x0C47u)
#define _DMA_DMACDSAU2                     	PREG16(_DMA_DMACDSAU2_ADDR)
#define DMA_DMACDSAU2                           _DMA_DMACDSAU2

#define _DMA_DMACEN2_ADDR			      (0x0C48u)
#define _DMA_DMACEN2                     	      PREG16(_DMA_DMACEN2_ADDR)
#define DMA_DMACEN2                             _DMA_DMACEN2

#define _DMA_DMACFN2_ADDR			      (0x0C49u)
#define _DMA_DMACFN2                     	      PREG16(_DMA_DMACFN2_ADDR)
#define DMA_DMACFN2                             _DMA_DMACFN2

#define _DMA_DMACFI2_ADDR			      (0x0C4Au)
#define _DMA_DMACFI2                     	      PREG16(_DMA_DMACFI2_ADDR)
#define DMA_DMACFI2                             _DMA_DMACFI2

#define _DMA_DMACEI2_ADDR			      (0x0C4Bu)
#define _DMA_DMACEI2                     	      PREG16(_DMA_DMACEI2_ADDR)
#define DMA_DMACEI2                             _DMA_DMACEI2

#if _DMA_DST_AND_SRC_INDEX_SUPPORT
  #define _DMA_DMACSFI2_ADDR                    (0x0C4Au)
  #define _DMA_DMACSFI2                         PREG16(_DMA_DMACSFI2_ADDR)
  #define DMA_DMACSFI2                          _DMA_DMACFI2

  #define _DMA_DMACSEI2_ADDR                    (0x0C4Bu)
  #define _DMA_DMACSEI2                         PREG16(_DMA_DMACSEI2_ADDR)
  #define DMA_DMACSEI2                          _DMA_DMACSEI2

  #define _DMA_DMACDFI2_ADDR                    (0x0C4Fu)
  #define _DMA_DMACDFI2                         PREG16(_DMA_DMACSFI2_ADDR)
  #define DMA_DMACDFI2                          _DMA_DMACFI2

  #define _DMA_DMACDEI2_ADDR                    (0x0C4Eu)
  #define _DMA_DMACDEI2                         PREG16(_DMA_DMACDEI2_ADDR)
  #define DMA_DMACDEI2                          _DMA_DMACDEI2

  #define _DMA_DMACDAC2_ADDR                    (0x0C4Du)
  #define _DMA_DMACDAC2                         PREG16(_DMA_DMACDAC2_ADDR)
  #define DMA_DMACDAC2                          _DMA_DMACDAC2

  #define _DMA_DMACSAC2_ADDR                    (0x0C4Cu)
  #define _DMA_DMACSAC2                         PREG16(_DMA_DMACSAC2_ADDR)
  #define DMA_DMACSAC2                          _DMA_DMACSAC2
#endif


/*============================================================================*\
*  DMA Channel #3 Channel Control Registers
\*============================================================================*/
#define _DMA_DMACSDP3_ADDR				(0x0C60u)
#define _DMA_DMACSDP3                       	PREG16(_DMA_DMACSDP3_ADDR)
#define DMA_DMACSDP3                            _DMA_DMACSDP3

#define _DMA_DMACCR3_ADDR				(0x0C61u)
#define _DMA_DMACCR3                      	PREG16(_DMA_DMACCR3_ADDR)
#define DMA_DMACCR3                             _DMA_DMACCR3

#define _DMA_DMACICR3_ADDR				(0x0C62u)
#define _DMA_DMACICR3                      	PREG16(_DMA_DMACICR2_ADDR)
#define DMA_DMACICR3                            _DMA_DMACICR3

#define _DMA_DMACSR3_ADDR				(0x0C63u)
#define _DMA_DMACSR3                      	PREG16(_DMA_DMACSR3_ADDR)
#define DMA_DMACSR3                             _DMA_DMACSR3

#define _DMA_DMACSSAL3_ADDR			      (0x0C64u)
#define _DMA_DMACSSAL3                          PREG16(_DMA_DMACSSAL3_ADDR)
#define DMA_DMACSSAL3                           _DMA_DMACSSAL3

#define _DMA_DMACSSAU3_ADDR			      (0x0C65)
#define _DMA_DMACSSAU3                     	PREG16(_DMA_DMACSSAU3_ADDR)
#define DMA_DMACSSAU3                           _DMA_DMACSSAU3

#define _DMA_DMACDSAL3_ADDR			      (0x0C66u)
#define _DMA_DMACDSAL3                          PREG16(_DMA_DMACDSAL3_ADDR)
#define DMA_DMACDSAL3                           _DMA_DMACDSAL3

#define _DMA_DMACDSAU3_ADDR			      (0x0C67u)
#define _DMA_DMACDSAU3                     	PREG16(_DMA_DMACDSAU3_ADDR)
#define DMA_DMACDSAU3                           _DMA_DMACDSAU3

#define _DMA_DMACEN3_ADDR			      (0x0C68u)
#define _DMA_DMACEN3                     	      PREG16(_DMA_DMACEN3_ADDR)
#define DMA_DMACEN3                             _DMA_DMACEN3

#define _DMA_DMACFN3_ADDR			      (0x0C69u)
#define _DMA_DMACFN3                     	      PREG16(_DMA_DMACFN3_ADDR)
#define DMA_DMACFN3                             _DMA_DMACFN3

#define _DMA_DMACFI3_ADDR			      (0x0C6Au)
#define _DMA_DMACFI3                     	      PREG16(_DMA_DMACFI3_ADDR)
#define DMA_DMACFI3                             _DMA_DMACFI3

#define _DMA_DMACEI3_ADDR			      (0x0C6Bu)
#define _DMA_DMACEI3                     	      PREG16(_DMA_DMACEI3_ADDR)
#define DMA_DMACEI3                             _DMA_DMACEI3

#if _DMA_DST_AND_SRC_INDEX_SUPPORT
  #define _DMA_DMACSFI3_ADDR                    (0x0C6Au)
  #define _DMA_DMACSFI3                         PREG16(_DMA_DMACSFI3_ADDR)
  #define DMA_DMACSFI3                          _DMA_DMACFI3

  #define _DMA_DMACSEI3_ADDR                    (0x0C6Bu)
  #define _DMA_DMACSEI3                         PREG16(_DMA_DMACSEI3_ADDR)
  #define DMA_DMACSEI3                          _DMA_DMACSEI3

  #define _DMA_DMACDFI3_ADDR                    (0x0C6Fu)
  #define _DMA_DMACDFI3                         PREG16(_DMA_DMACSFI3_ADDR)
  #define DMA_DMACDFI3                          _DMA_DMACFI3

  #define _DMA_DMACDEI3_ADDR                    (0x0C6Eu)
  #define _DMA_DMACDEI3                         PREG16(_DMA_DMACDEI3_ADDR)
  #define DMA_DMACDEI3                          _DMA_DMACDEI3

  #define _DMA_DMACDAC3_ADDR                    (0x0C6Du)
  #define _DMA_DMACDAC3                         PREG16(_DMA_DMACDAC3_ADDR)
  #define DMA_DMACDAC3                          _DMA_DMACDAC3

  #define _DMA_DMACSAC3_ADDR                    (0x0C6Cu)
  #define _DMA_DMACSAC3                         PREG16(_DMA_DMACSAC3_ADDR)
  #define DMA_DMACSAC3                          _DMA_DMACSAC3
#endif

/*============================================================================*\
*  DMA Channel #4 Channel Control Registers
\*============================================================================*/
#define _DMA_DMACSDP4_ADDR				(0x0C80u)
#define _DMA_DMACSDP4                       	PREG16(_DMA_DMACSDP4_ADDR)
#define DMA_DMACSDP4                            _DMA_DMACSDP4

#define _DMA_DMACCR4_ADDR				(0x0C81u)
#define _DMA_DMACCR4                      	PREG16(_DMA_DMACCR4_ADDR)
#define DMA_DMACCR4                             _DMA_DMACCR4

#define _DMA_DMACICR4_ADDR				(0x0C82u)
#define _DMA_DMACICR4                      	PREG16(_DMA_DMACICR2_ADDR)
#define DMA_DMACICR4                            _DMA_DMACICR4

#define _DMA_DMACSR4_ADDR				(0x0C83u)
#define _DMA_DMACSR4                      	PREG16(_DMA_DMACSR4_ADDR)
#define DMA_DMACSR4                             _DMA_DMACSR4

#define _DMA_DMACSSAL4_ADDR			      (0x0C84u)
#define _DMA_DMACSSAL4                          PREG16(_DMA_DMACSSAL4_ADDR)
#define DMA_DMACSSAL4                           _DMA_DMACSSAL4

#define _DMA_DMACSSAU4_ADDR			      (0x0C85u)
#define _DMA_DMACSSAU4                     	PREG16(_DMA_DMACSSAU4_ADDR)
#define DMA_DMACSSAU4                           _DMA_DMACSSAU4

#define _DMA_DMACDSAL4_ADDR			      (0x0C86u)
#define _DMA_DMACDSAL4                          PREG16(_DMA_DMACDSAL4_ADDR)
#define DMA_DMACDSAL4                           _DMA_DMACDSAL4

#define _DMA_DMACDSAU4_ADDR			      (0x0C87u)
#define _DMA_DMACDSAU4                     	PREG16(_DMA_DMACDSAU4_ADDR)
#define DMA_DMACDSAU4                           _DMA_DMACDSAU4

#define _DMA_DMACEN4_ADDR			      (0x0C88u)
#define _DMA_DMACEN4                     	      PREG16(_DMA_DMACEN4_ADDR)
#define DMA_DMACEN4                             _DMA_DMACEN4

#define _DMA_DMACFN4_ADDR			      (0x0C89u)
#define _DMA_DMACFN4                     	      PREG16(_DMA_DMACFN4_ADDR)
#define DMA_DMACFN4                             _DMA_DMACFN4

#define _DMA_DMACFI4_ADDR			      (0x0C8Au)
#define _DMA_DMACFI4                     	      PREG16(_DMA_DMACFI4_ADDR)
#define DMA_DMACFI4                             _DMA_DMACFI4

#define _DMA_DMACEI4_ADDR			      (0x0C8Bu)
#define _DMA_DMACEI4                     	       PREG16(_DMA_DMACEI4_ADDR)
#define DMA_DMACEI4                              _DMA_DMACEI4

#if _DMA_DST_AND_SRC_INDEX_SUPPORT
  #define _DMA_DMACSFI4_ADDR                    (0x0C8Au)
  #define _DMA_DMACSFI4                         PREG16(_DMA_DMACSFI4_ADDR)
  #define DMA_DMACSFI4                          _DMA_DMACFI4

  #define _DMA_DMACSEI4_ADDR                    (0x0C8Bu)
  #define _DMA_DMACSEI4                         PREG16(_DMA_DMACSEI4_ADDR)
  #define DMA_DMACSEI4                          _DMA_DMACSEI4

  #define _DMA_DMACDFI4_ADDR                    (0x0C8Fu)
  #define _DMA_DMACDFI4                         PREG16(_DMA_DMACSFI4_ADDR)
  #define DMA_DMACDFI4                          _DMA_DMACFI4

  #define _DMA_DMACDEI4_ADDR                    (0x0C8Eu)
  #define _DMA_DMACDEI4                         PREG16(_DMA_DMACDEI4_ADDR)
  #define DMA_DMACDEI4                          _DMA_DMACDEI4

  #define _DMA_DMACDAC4_ADDR                    (0x0C8Du)
  #define _DMA_DMACDAC4                         PREG16(_DMA_DMACDAC4_ADDR)
  #define DMA_DMACDAC4                          _DMA_DMACDAC4

  #define _DMA_DMACSAC4_ADDR                    (0x0C8Cu)
  #define _DMA_DMACSAC4                         PREG16(_DMA_DMACSAC4_ADDR)
  #define DMA_DMACSAC4                          _DMA_DMACSAC4
#endif

/*============================================================================*\
*  DMA Channel #5 Channel Control Registers
\*============================================================================*/
#define _DMA_DMACSDP5_ADDR			(0x0CA0u)
#define _DMA_DMACSDP5                     PREG16(_DMA_DMACSDP5_ADDR)
#define DMA_DMACSDP5                      _DMA_DMACSDP5

#define _DMA_DMACCR5_ADDR			(0x0CA1u)
#define _DMA_DMACCR5                      PREG16(_DMA_DMACCR5_ADDR)
#define DMA_DMACCR5                       _DMA_DMACCR5

#define _DMA_DMACICR5_ADDR			(0x0CA2u)
#define _DMA_DMACICR5                     PREG16(_DMA_DMACICR2_ADDR)
#define DMA_DMACICR5                       _DMA_DMACICR5

#define _DMA_DMACSR5_ADDR			(0x0CA3u)
#define _DMA_DMACSR5                       PREG16(_DMA_DMACSR5_ADDR)
#define DMA_DMACSR5                        _DMA_DMACSR5

#define _DMA_DMACSSAL5_ADDR			(0x0CA4u)
#define _DMA_DMACSSAL5                      PREG16(_DMA_DMACSSAL5_ADDR)
#define DMA_DMACSSAL5                       _DMA_DMACSSAL5

#define _DMA_DMACSSAU5_ADDR			(0x0CA5)
#define _DMA_DMACSSAU5                     	PREG16(_DMA_DMACSSAU5_ADDR)
#define DMA_DMACSSAU5                       _DMA_DMACSSAU5

#define _DMA_DMACDSAL5_ADDR			(0x0CA6u)
#define _DMA_DMACDSAL5                      PREG16(_DMA_DMACDSAL5_ADDR)
#define DMA_DMACDSAL5                       _DMA_DMACDSAL5

#define _DMA_DMACDSAU5_ADDR			(0x0CA7u)
#define _DMA_DMACDSAU5                     	PREG16(_DMA_DMACDSAU5_ADDR)
#define DMA_DMACDSAU5                       _DMA_DMACDSAU5

#define _DMA_DMACEN5_ADDR			      (0x0CA8u)
#define _DMA_DMACEN5                     	PREG16(_DMA_DMACEN5_ADDR)
#define DMA_DMACEN5                          _DMA_DMACEN5

#define _DMA_DMACFN5_ADDR			      (0x0CA9u)
#define _DMA_DMACFN5                     	PREG16(_DMA_DMACFN5_ADDR)
#define DMA_DMACFN5                          _DMA_DMACFN5

#define _DMA_DMACFI5_ADDR			      (0x0CAAu)
#define _DMA_DMACFI5                     	PREG16(_DMA_DMACFI5_ADDR)
#define DMA_DMACFI5                          _DMA_DMACFI5

#define _DMA_DMACEI5_ADDR			      (0x0CABu)
#define _DMA_DMACEI5                     	PREG16(_DMA_DMACEI5_ADDR)
#define DMA_DMACEI5                          _DMA_DMACEI5

#if _DMA_DST_AND_SRC_INDEX_SUPPORT
  #define _DMA_DMACSFI5_ADDR                    (0x0CAAu)
  #define _DMA_DMACSFI5                         PREG16(_DMA_DMACSFI5_ADDR)
  #define DMA_DMACSFI5                          _DMA_DMACFI5

  #define _DMA_DMACSEI5_ADDR                    (0x0CABu)
  #define _DMA_DMACSEI5                         PREG16(_DMA_DMACSEI5_ADDR)
  #define DMA_DMACSEI5                          _DMA_DMACSEI5

  #define _DMA_DMACDFI5_ADDR                    (0x0CAFu)
  #define _DMA_DMACDFI5                         PREG16(_DMA_DMACSFI5_ADDR)
  #define DMA_DMACDFI5                          _DMA_DMACFI5

  #define _DMA_DMACDEI5_ADDR                    (0x0CAEu)
  #define _DMA_DMACDEI5                         PREG16(_DMA_DMACDEI5_ADDR)
  #define DMA_DMACDEI5                          _DMA_DMACDEI5

  #define _DMA_DMACDAC5_ADDR                    (0x0CADu)
  #define _DMA_DMACDAC5                         PREG16(_DMA_DMACDAC5_ADDR)
  #define DMA_DMACDAC5                          _DMA_DMACDAC5

  #define _DMA_DMACSAC5_ADDR                    (0x0CACu)
  #define _DMA_DMACSAC5                         PREG16(_DMA_DMACSAC5_ADDR)
  #define DMA_DMACSAC5                          _DMA_DMACSAC5
#endif


/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*============================================================================*\
* _DMA_DMAGCR	   - Global Control Register
*
* Fields:
*  (RW) _DMA_DMAGCR_FREE
*  (RW) _DMA_DMAGCR_EHPIEXCL
*  (RW) _DMA_DMAGCR_EHPIPRIO
*  IF C550 PG2
*  (RW) _DMA_DMAGCR_AUTOGATING
*  
\*============================================================================*/

#if _DMA_DST_AND_SRC_INDEX_SUPPORT
  /*==========================================================================*\
  * (RW) _DMA_DMAGCR_AUTOGATING
  \*--------------------------------------------------------------------------*/
  #define _DMA_DMAGCR_AUTOGATING_SHIFT	 	(0x0003u)
  #define _DMA_DMAGCR_AUTOGATING_MK(n)            (((Uint16)(n) & 0x0001u) << _DMA_DMAGCR_AUTOGATING_SHIFT)
  #define _DMA_DMAGCR_AUTOGATING_MASK             (_DMA_DMAGCR_AUTOGATING_MK(0x0001u))
  #define _DMA_DMAGCR_AUTOGATING_CLR              (~(_DMA_DMAGCR_AUTOGATING_MASK))
#endif

/*==========================================================================*\
* (RW) _DMA_DMAGCR_FREE
\*--------------------------------------------------------------------------*/
#define _DMA_DMAGCR_FREE_SHIFT	 	(0x0002u)
#define _DMA_DMAGCR_FREE_MK(n)            (((Uint16)(n) & 0x0001u) << _DMA_DMAGCR_FREE_SHIFT)
#define _DMA_DMAGCR_FREE_MASK             (_DMA_DMAGCR_FREE_MK(0x0001u))
#define _DMA_DMAGCR_FREE_CLR              (~(_DMA_DMAGCR_FREE_MASK))

#if (((CHIP_5502) || (CHIP_5501))==0) 
/*==========================================================================*\
* (RW) _DMA_DMAGCR_EHPIEXCL
\*--------------------------------------------------------------------------*/
#define _DMA_DMAGCR_EHPIEXCL_SHIFT		(0x0001u)
#define _DMA_DMAGCR_EHPIEXCL_MK(n)           (((Uint16)(n) & 0x0001u) << _DMA_DMAGCR_EHPIEXCL_SHIFT)
#define _DMA_DMAGCR_EHPIEXCL_MASK            (_DMA_DMAGCR_EHPIEXCL_MK(0x0001u))
#define _DMA_DMAGCR_EHPIEXCL_CLR             (~(_DMA_DMAGCR_EHPIEXCL_MASK))

/*==========================================================================*\
* (RW) _DMA_DMAGCR_EHPIPRIO
\*--------------------------------------------------------------------------*/
#define _DMA_DMAGCR_EHPIPRIO_SHIFT		(0x0000u)
#define _DMA_DMAGCR_EHPIPRIO_MK(n)           (((Uint16)(n) & 0x0001u) << _DMA_DMAGCR_EHPIPRIO_SHIFT)
#define _DMA_DMAGCR_EHPIPRIO_MASK            (_DMA_DMAGCR_EHPIPRIO_MK(0x0001u))
#define _DMA_DMAGCR_EHPIPRIO_CLR             (~(_DMA_DMAGCR_EHPIPRIO_MASK))

  #if (_DMA_DST_AND_SRC_INDEX_SUPPORT)
    #define _DMA_DMAGCR_CFG(autogate,free, excl, prio)\
       _PREG_SET(_DMA_DMAGCR_ADDR,\
                 (Uint16)(_DMA_DMAGCR_AUTOGATING_MK(autogate)\
                          _DMA_DMAGCR_FREE_MK(free)     |\
                          _DMA_DMAGCR_EHPIEXCL_MK(excl) |\
                          _DMA_DMAGCR_EHPIPRIO_MK(prio)\
                         )\
       ) 
  #else
    #define _DMA_DMAGCR_CFG(free, excl, prio)\
       _PREG_SET(_DMA_DMAGCR_ADDR,\
                 (Uint16)(_DMA_DMAGCR_FREE_MK(free)     |\
                          _DMA_DMAGCR_EHPIEXCL_MK(excl) |\
                          _DMA_DMAGCR_EHPIPRIO_MK(prio)\
                         )\
       )
  #endif
#else
  #define _DMA_DMAGCR_CFG(autogate,free)\
     _PREG_SET(_DMA_DMAGCR_ADDR,\
               (Uint16)(_DMA_DMAGCR_AUTOGATING_MK(autogate)|\
                        _DMA_DMAGCR_FREE_MK(free)\
                       )\
     )
#endif     // (((CHIP_5502)||(CHIP_5501))==0)


/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*============================================================================*\
* _DMA_DMAGSCR	   - Global Software Compatability Register
*
* Fields:
*  (RW) _DMA_DMAGSCR_COMPMODE
*  
\*============================================================================*/

#if (_DMA_DST_AND_SRC_INDEX_SUPPORT) && (((CHIP_5502) || (CHIP_5501))==0) 
  /*==========================================================================*\
  * (RW) _DMA_DMAGSCR_SWMODE
  \*--------------------------------------------------------------------------*/
  #define _DMA_DMAGSCR_COMPMODE_SHIFT	 	(0x0003u)
  #define _DMA_DMAGSCR_COMPMODE_MK(n)            (((Uint16)(n) & 0x0001u) << _DMA_DMAGSCR_COMPMODE_SHIFT)
  #define _DMA_DMAGSCR_COMPMODE_MASK             (_DMA_DMAGSCR_COMPMODE_MK(0x0001u))
  #define _DMA_DMAGSCR_COMPMODE_CLR              (~(_DMA_DMAGSCR_COMPMODE_MASK))

  #define _DMA_DMAGSCR_SWMODE_SHIFT	 	      (0x0003u)
  #define _DMA_DMAGSCR_SWMODE_MK(n)             (((Uint16)(n) & 0x0001u) << _DMA_DMAGSCR_SWMODE_SHIFT)
  #define _DMA_DMAGSCR_SWMODE_MASK              (_DMA_DMAGSCR_SWMODE_MK(0x0001u))
  #define _DMA_DMAGSCR_SWMODE_CLR               (~(_DMA_DMAGSCR_SWMODE_MASK))


  #define _DMA_DMAGSCR_CFG(mode)\
     _PREG_SET(_DMA_DMAGCR_ADDR,(Uint16)(_DMA_DMAGSCR_COMPMODE_MK(mode)))

#endif



/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*============================================================================*\
* _DMA_DMAGTCR	   - Global Timeout Control Register
*
* Fields:
* IF 5502 || 5501
*  (RW) _DMA_DMAGTCR_ITE0
*  (RW) _DMA_DMAGTCR_ITE1
*  (RW) _DMA_DMAGTCR_ETE
*  (RW) _DMA_DMAGTCR_PTE
* ELSE
*  (RW) _DMA_DMAGTCR_STCE
*  (RW) _DMA_DMAGTCR_DTCE
\*============================================================================*/

#if (_DMA_DST_AND_SRC_INDEX_SUPPORT)
  #if (CHIP_5502) || (CHIP_5501)

    /*==========================================================================*\
    * (RW) _DMA_DMAGTCR_ITE0
    \*--------------------------------------------------------------------------*/
    #define _DMA_DMAGTCR_ITE0_SHIFT	 	  (0x0000u)
    #define _DMA_DMAGTCR_ITE0_MK(n)               (((Uint16)(n) & 0x0001u) << _DMA_DMAGTCR_ITE0_SHIFT)
    #define _DMA_DMAGTCR_ITE0_MASK                (_DMA_DMAGTCR_ITE0_MK(0x0001u))
    #define _DMA_DMAGTCR_ITE0_CLR                 (~(_DMA_DMAGTCR_ITE0_MASK))
  
    /*==========================================================================*\
    * (RW) _DMA_DMAGTCR_ITE1
    \*--------------------------------------------------------------------------*/
    #define _DMA_DMAGTCR_ITE1_SHIFT	 	  (0x0001u)
    #define _DMA_DMAGTCR_ITE1_MK(n)               (((Uint16)(n) & 0x0001u) << _DMA_DMAGTCR_ITE1_SHIFT)
    #define _DMA_DMAGTCR_ITE1_MASK                (_DMA_DMAGTCR_ITE1_MK(0x0001u))
    #define _DMA_DMAGTCR_ITE1_CLR                 (~(_DMA_DMAGTCR_ITE1_MASK))
  
    /*==========================================================================*\
    * (RW) _DMA_DMAGTCR_ETE
    \*--------------------------------------------------------------------------*/
    #define _DMA_DMAGTCR_ETE_SHIFT	 	  (0x0002u)
    #define _DMA_DMAGTCR_ETE_MK(n)               (((Uint16)(n) & 0x0001u) << _DMA_DMAGTCR_ETE_SHIFT)
    #define _DMA_DMAGTCR_ETE_MASK                (_DMA_DMAGTCR_ETE_MK(0x0001u))
    #define _DMA_DMAGTCR_ETE_CLR                 (~(_DMA_DMAGTCR_ETE_MASK))
  
    /*==========================================================================*\
    * (RW) _DMA_DMAGTCR_PTE
    \*--------------------------------------------------------------------------*/
    #define _DMA_DMAGTCR_PTE_SHIFT	 	  (0x0003u)
    #define _DMA_DMAGTCR_PTE_MK(n)               (((Uint16)(n) & 0x0001u) << _DMA_DMAGTCR_PTE_SHIFT)
    #define _DMA_DMAGTCR_PTE_MASK                (_DMA_DMAGTCR_PTE_MK(0x0001u))
    #define _DMA_DMAGTCR_PTE_CLR                 (~(_DMA_DMAGTCR_PTE_MASK))
  
  	
    #define _DMA_DMAGTCR_CFG(pte,ete,ite1,ite0)\
       _PREG_SET(_DMA_DMAGTCR_ADDR,\
                 (Uint16)(_DMA_DMAGTCR_PTE_MK(pte)|\
			  _DMA_DMAGTCR_ETE_MK(ete)|\
			  _DMA_DMAGTCR_ITE1_MK(ite1)|\
                          _DMA_DMAGTCR_ITE0_MK(ite0)\
                         )\
       )

  #else	

    /*==========================================================================*\
    * (RW) _DMA_DMAGTCR_STCE
    \*--------------------------------------------------------------------------*/
    #define _DMA_DMAGTCR_STCE_SHIFT	 	(0x0000u)
    #define _DMA_DMAGTCR_STCE_MK(n)               (((Uint16)(n) & 0x0001u) << _DMA_DMAGTCR_STCE_SHIFT)
    #define _DMA_DMAGTCR_STCE_MASK                (_DMA_DMAGTCR_STCE_MK(0x0001u))
    #define _DMA_DMAGTCR_STCE_CLR                 (~(_DMA_DMAGTCR_STCE_MASK))
  
    /*==========================================================================*\
    * (RW) _DMA_DMAGTCR_DTCE
    \*--------------------------------------------------------------------------*/
    #define _DMA_DMAGTCR_DTCE_SHIFT	 	(0x0001u)
    #define _DMA_DMAGTCR_DTCE_MK(n)               (((Uint16)(n) & 0x0001u) << _DMA_DMAGTCR_DTCE_SHIFT)
    #define _DMA_DMAGTCR_DTCE_MASK                (_DMA_DMAGTCR_DTCE_MK(0x0001u))
    #define _DMA_DMAGTCR_DTCE_CLR                 (~(_DMA_DMAGTCR_DTCE_MASK))
  
  	
    #define _DMA_DMAGTCR_CFG(dtce,stce)\
       _PREG_SET(_DMA_DMAGTCR_ADDR,\
                 (Uint16)(_DMA_DMAGTCR_DTCE_MK(dtce)|\
                          _DMA_DMAGTCR_STCE_MK(stce)\
                         )\
       )
  
  #endif   

#endif


	
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*============================================================================*\
* _DMA_DMACSDPn	   - Channel #n Source Destination Parameters Register
*
* Fields:
*  (RW) _DMA_DMACSDP_DSTBEN
*  (RW) _DMA_DMACSDP_DSTPACK
*  (RW) _DMA_DMACSDP_DST
*  (RW) _DMA_DMACSDP_SRCBEN
*  (RW) _DMA_DMACSDP_SRCPACK
*  (RW) _DMA_DMACSDP_SRC
*  (RW) _DMA_DMACSDP_DATATYPE
\*============================================================================*/




/*==========================================================================*\
* (RW) _DMA_DMACSDP_DSTBEN
\*--------------------------------------------------------------------------*/
#define _DMA_DMACSDP_DSTBEN_SHIFT           (0x000Eu)
#define _DMA_DMACSDP_DSTBEN_MK(n)           (((Uint16)(n) & 0x0003u) << _DMA_DMACSDP_DSTBEN_SHIFT)
#define _DMA_DMACSDP_DSTBEN_MASK            (_DMA_DMACSDP_DSTBEN_MK(0x0003u))
#define _DMA_DMACSDP_DSTBEN_CLR             (~(_DMA_DMACSDP_DSTBEN_MASK))

/*==========================================================================*\
* (RW) _DMA_DMACSDP_DSTPACK
\*--------------------------------------------------------------------------*/
#define _DMA_DMACSDP_DSTPACK_SHIFT          (0x000Du)
#define _DMA_DMACSDP_DSTPACK_MK(n)          (((Uint16)(n) & 0x0001u) << _DMA_DMACSDP_DSTPACK_SHIFT)
#define _DMA_DMACSDP_DSTPACK_MASK           (_DMA_DMACSDP_DSTPACK_MK(0x0001u))
#define _DMA_DMACSDP_DSTPACK_CLR            (~(_DMA_DMACSDP_DSTPACK_MASK))

/*==========================================================================*\
* (RW) _DMA_DMACSDP_DST
\*--------------------------------------------------------------------------*/
#define _DMA_DMACSDP_DST_SHIFT              (0x0009u)
#define _DMA_DMACSDP_DST_MK(n)              (((Uint16)(n) & 0x000Fu) << _DMA_DMACSDP_DST_SHIFT)
#define _DMA_DMACSDP_DST_MASK               (_DMA_DMACSDP_DST_MK(0x000Fu))
#define _DMA_DMACSDP_DST_CLR                (~(_DMA_DMACSDP_DST_MASK))

/*==========================================================================*\
* (RW) _DMA_DMACSDP_SRCBEN
\*--------------------------------------------------------------------------*/
#define _DMA_DMACSDP_SRCBEN_SHIFT           (0x0007u)
#define _DMA_DMACSDP_SRCBEN_MK(n)           (((Uint16)(n) & 0x0003u) << _DMA_DMACSDP_SRCBEN_SHIFT)
#define _DMA_DMACSDP_SRCBEN_MASK            (_DMA_DMACSDP_SRCBEN_MK(0x0003u))
#define _DMA_DMACSDP_SRCBEN_CLR             (~(_DMA_DMACSDP_SRCBEN_MASK))

/*==========================================================================*\
* (RW) _DMA_DMACSDP_SRCPACK
\*--------------------------------------------------------------------------*/
#define _DMA_DMACSDP_SRCPACK_SHIFT          (0x0006u)
#define _DMA_DMACSDP_SRCPACK_MK(n)          (((Uint16)(n) & 0x0001u) << _DMA_DMACSDP_SRCPACK_SHIFT)
#define _DMA_DMACSDP_SRCPACK_MASK           (_DMA_DMACSDP_SRCPACK_MK(0x0001u))
#define _DMA_DMACSDP_SRCPACK_CLR            (~(_DMA_DMACSDP_SRCPACK_MASK))

/*==========================================================================*\
* (RW) _DMA_DMACSDP_SRC
\*--------------------------------------------------------------------------*/
#define _DMA_DMACSDP_SRC_SHIFT              (0x0002u)
#define _DMA_DMACSDP_SRC_MK(n)              (((Uint16)(n) & 0x000Fu) << _DMA_DMACSDP_SRC_SHIFT)
#define _DMA_DMACSDP_SRC_MASK               (_DMA_DMACSDP_SRC_MK(0x000Fu))
#define _DMA_DMACSDP_SRC_CLR                (~(_DMA_DMACSDP_SRC_MASK))

/*==========================================================================*\
* (RW) _DMA_DMACSDP_DATATYPE
\*--------------------------------------------------------------------------*/
#define _DMA_DMACSDP_DATATYPE_SHIFT          (0x0000u)
#define _DMA_DMACSDP_DATATYPE_MK(n)          (((Uint16)(n) & 0x0003u) << _DMA_DMACSDP_DATATYPE_SHIFT)
#define _DMA_DMACSDP_DATATYPE_MASK           (_DMA_DMACSDP_DATATYPE_MK(0x0003u))
#define _DMA_DMACSDP_DATATYPE_CLR            (~(_DMA_DMACSDP_DATATYPE_MASK))


#define _DMA_DMACSDP_CFG(Ch, dstben, dstpack, dst, srcben, srcpack, src, datatype)\
   _PREG_SET(_DMA_DMACDSP_ADDR(Ch),\
             (Uint16) ( _DMA_DMACSDP_DSTBEN_MK(dstben)        |\
                        _DMA_DMACSDP_DSTPACK_MK(dstpack)      |\
                        _DMA_DMACSDP_DST_MK(dst)              |\
                        _DMA_DMACSDP_SRCBEN_MK(srcben)        |\
                        _DMA_DMACSDP_SRCPACK_MK(srcpack)      |\
                        _DMA_DMACSDP_SRC_MK(src)              |\
                        _DMA_DMACSDP_DATATYPE_MK(datatype)    \
                      )\
   )

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*============================================================================*\
* _DMA_DMACCRn	   - Channel #n Channel Control Register
*
* Fields:
*  (RW) _DMA_DMACCR_DSTAMODE
*  (RW) _DMA_DMACCR_SRCAMODE
*  (RW) _DMA_DMACCR_ENDPROG
*  (RW) _DMA_DMACCR_WP
*  (RW) _DMA_DMACCR_REPEAT
*  (RW) _DMA_DMACCR_AUTOINIT
*  (RW) _DMA_DMACCR_EN
*  (RW) _DMA_DMACCR_PRIO
*  (RW) _DMA_DMACCR_FS
*  (RW) _DMA_DMACCR_SYNC
\*============================================================================*/

/*==========================================================================*\
* (RW) _DMA_DMACCR_DSTAMODE
\*--------------------------------------------------------------------------*/
#define _DMA_DMACCR_DSTAMODE_SHIFT           (0x000Eu)
#define _DMA_DMACCR_DSTAMODE_MK(n)           (((Uint16)(n) & 0x0003u) << _DMA_DMACCR_DSTAMODE_SHIFT)
#define _DMA_DMACCR_DSTAMODE_MASK            (_DMA_DMACCR_DSTAMODE_MK(0x0003u))
#define _DMA_DMACCR_DSTAMODE_CLR             (~(_DMA_DMACCR_DSTAMODE_MASK))

/*==========================================================================*\
* (RW) _DMA_DMACCR_SRCAMODE
\*--------------------------------------------------------------------------*/
#define _DMA_DMACCR_SRCAMODE_SHIFT           (0x000Cu)
#define _DMA_DMACCR_SRCAMODE_MK(n)           (((Uint16)(n) & 0x0003u) << _DMA_DMACCR_SRCAMODE_SHIFT)
#define _DMA_DMACCR_SRCAMODE_MASK            (_DMA_DMACCR_SRCAMODE_MK(0x0003u))
#define _DMA_DMACCR_SRCAMODE_CLR             (~(_DMA_DMACCR_SRCAMODE_MASK))

/*==========================================================================*\
* (RW) _DMA_DMACCR_ENDPROG
\*--------------------------------------------------------------------------*/
#define _DMA_DMACCR_ENDPROG_SHIFT            (0x000Bu)
#define _DMA_DMACCR_ENDPROG_MK(n)            (((Uint16)(n) & 0x0001u) << _DMA_DMACCR_ENDPROG_SHIFT)
#define _DMA_DMACCR_ENDPROG_MASK             (_DMA_DMACCR_ENDPROG_MK(0x0001u))
#define _DMA_DMACCR_ENDPROG_CLR              (~(_DMA_DMACCR_ENDPROG_MASK))

#if (CHIP_5502) || (CHIP_5501)
/*==========================================================================*\
* (RW) _DMA_DMACCR_WP
\*--------------------------------------------------------------------------*/
#define _DMA_DMACCR_WP_SHIFT                 (0x000Au)
#define _DMA_DMACCR_WP_MK(n)                 (((Uint16)(n) & 0x0001u) << _DMA_DMACCR_WP_SHIFT)
#define _DMA_DMACCR_WP_MASK                  (_DMA_DMACCR_WP_MK(0x0001u))
#define _DMA_DMACCR_WP_CLR                   (~(_DMA_DMACCR_WP_MASK))

#endif


   
/*==========================================================================*\
* (RW) _DMA_DMACCR_REPEAT
\*--------------------------------------------------------------------------*/
#define _DMA_DMACCR_REPEAT_SHIFT             (0x0009u)
#define _DMA_DMACCR_REPEAT_MK(n)             (((Uint16)(n) & 0x0001u) << _DMA_DMACCR_REPEAT_SHIFT)
#define _DMA_DMACCR_REPEAT_MASK              (_DMA_DMACCR_REPEAT_MK(0x0001u))
#define _DMA_DMACCR_REPEAT_CLR               (~(_DMA_DMACCR_REPEAT_MASK))

/*==========================================================================*\
* (RW) _DMA_DMACCR_AUTOINIT
\*--------------------------------------------------------------------------*/
#define _DMA_DMACCR_AUTOINIT_SHIFT           (0x0008u)
#define _DMA_DMACCR_AUTOINIT_MK(n)           (((Uint16)(n) & 0x0001u) << _DMA_DMACCR_AUTOINIT_SHIFT)
#define _DMA_DMACCR_AUTOINIT_MASK            (_DMA_DMACCR_AUTOINIT_MK(0x0001u))
#define _DMA_DMACCR_AUTOINIT_CLR             (~(_DMA_DMACCR_AUTOINIT_MASK))

/*==========================================================================*\
* (RW) _DMA_DMACCR_EN
\*--------------------------------------------------------------------------*/
#define _DMA_DMACCR_EN_SHIFT                 (0x0007u)
#define _DMA_DMACCR_EN_MK(n)                 (((Uint16)(n) & 0x0001u) << _DMA_DMACCR_EN_SHIFT)
#define _DMA_DMACCR_EN_MASK                  (_DMA_DMACCR_EN_MK(0x0001u))
#define _DMA_DMACCR_EN_CLR                   (~(_DMA_DMACCR_EN_MASK))

/*==========================================================================*\
* (RW) _DMA_DMACCR_PRIO
\*--------------------------------------------------------------------------*/
#define _DMA_DMACCR_PRIO_SHIFT               (0x0006u)
#define _DMA_DMACCR_PRIO_MK(n)               (((Uint16)(n) & 0x0001u) << _DMA_DMACCR_PRIO_SHIFT)
#define _DMA_DMACCR_PRIO_MASK                (_DMA_DMACCR_PRIO_MK(0x0001u))
#define _DMA_DMACCR_PRIO_CLR                 (~(_DMA_DMACCR_PRIO_MASK))

/*==========================================================================*\
* (RW) _DMA_DMACCR_FS
\*--------------------------------------------------------------------------*/
#define _DMA_DMACCR_FS_SHIFT                 (0x0005u)
#define _DMA_DMACCR_FS_MK(n)                 (((Uint16)(n) & 0x0001u) << _DMA_DMACCR_FS_SHIFT)
#define _DMA_DMACCR_FS_MASK                  (_DMA_DMACCR_FS_MK(0x0001u))
#define _DMA_DMACCR_FS_CLR                   (~(_DMA_DMACCR_FS_MASK))

/*==========================================================================*\
* (RW) _DMA_DMACCR_SYNC
\*--------------------------------------------------------------------------*/
#define _DMA_DMACCR_SYNC_SHIFT               (0x0000u)
#define _DMA_DMACCR_SYNC_MK(n)               (((Uint16)(n) & 0x001Fu) << _DMA_DMACCR_SYNC_SHIFT)
#define _DMA_DMACCR_SYNC_MASK                (_DMA_DMACCR_SYNC_MK(0x001Fu))
#define _DMA_DMACCR_SYNC_CLR                 (~(_DMA_DMACCR_SYNC_MASK))

#if (CHIP_5502) || (CHIP_5501)

#define _DMA_DMACCR_CFG(Ch, dstamode, srcamode, endprog, wp, repeat, autoinit,\
                     en, prio, fs, sync)\
   _PREG_SET(_DMA_DMACCR_ADDR(Ch),\
             (Uint16) ( _DMA_DMACCR_DSTAMODE_MK(dstamode)      |\
                        _DMA_DMACCR_SRCAMODE_MK(srcamode)      |\
                        _DMA_DMACCR_ENDPROG_MK(endprog)        |\
                        _DMA_DMACCR_WP_MK(wp)                  |\
                        _DMA_DMACCR_REPEAT_MK(repeat)          |\
                        _DMA_DMACCR_AUTOINIT_MK(autoinit)      |\
                        _DMA_DMACCR_EN_MK(en)                  |\
                        _DMA_DMACCR_PRIO_MK(prio)              |\
                        _DMA_DMACCR_FS_MK(fs)                  |\
                        _DMA_DMACCR_SYNC_MK(sync)              \
                      )\
   )

#else
   
#define _DMA_DMACCR_CFG(Ch, dstamode, srcamode, endprog, repeat, autoinit,\
                     en, prio, fs, sync)\
   _PREG_SET(_DMA_DMACCR_ADDR(Ch),\
             (Uint16) ( _DMA_DMACCR_DSTAMODE_MK(dstamode)      |\
                        _DMA_DMACCR_SRCAMODE_MK(srcamode)      |\
                        _DMA_DMACCR_ENDPROG_MK(endprog)        |\
                        _DMA_DMACCR_REPEAT_MK(repeat)          |\
                        _DMA_DMACCR_AUTOINIT_MK(autoinit)      |\
                        _DMA_DMACCR_EN_MK(en)                  |\
                        _DMA_DMACCR_PRIO_MK(prio)              |\
                        _DMA_DMACCR_FS_MK(fs)                  |\
                        _DMA_DMACCR_SYNC_MK(sync)              \
                      )\
   )
#endif

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*========================================================================*\
* _DMA_DMACICRn	   - Channel #n Channel Interrupt Control Register
*
* Fields:
*  (RW) _DMA_DMACICR_AERRIE   ( For 5501 and 5502 only)
*  (RW) _DMA_DMACICR_BLOCKIE
*  (RW) _DMA_DMACICR_LASTIE
*  (RW) _DMA_DMACICR_FRAMEIE
*  (RW) _DMA_DMACICR_HALFIE
*  (RW) _DMA_DMACICR_DROPIE
*  (RW) _DMA_DMACICR_TIMEOUTIE
\*========================================================================*/

/*========================================================================*\
* (RW) _DMA_DMACICR_AERRIE
\*------------------------------------------------------------------------*/
#define _DMA_DMACICR_AERRIE_SHIFT           (0x0007u)
#define _DMA_DMACICR_AERRIE_MK(n)           (((Uint16)(n) & 0x0001u) << _DMA_DMACICR_AERRIE_SHIFT)
#define _DMA_DMACICR_AERRIE_MASK            (_DMA_DMACICR_AERRIE_MK(0x0001u))
#define _DMA_DMACICR_AERRIE_CLR             (~(_DMA_DMACICR_AERRIE_MASK))

/*========================================================================*\
* (RW) _DMA_DMACICR_BLOCKIE
\*------------------------------------------------------------------------*/
#define _DMA_DMACICR_BLOCKIE_SHIFT           (0x0005u)
#define _DMA_DMACICR_BLOCKIE_MK(n)           (((Uint16)(n) & 0x0001u) << _DMA_DMACICR_BLOCKIE_SHIFT)
#define _DMA_DMACICR_BLOCKIE_MASK            (_DMA_DMACICR_BLOCKIE_MK(0x0001u))
#define _DMA_DMACICR_BLOCKIE_CLR             (~(_DMA_DMACICR_BLOCKIE_MASK))

/*==========================================================================*\
* (RW) _DMA_DMACICR_LASTIE
\*--------------------------------------------------------------------------*/
#define _DMA_DMACICR_LASTIE_SHIFT            (0x0004u)
#define _DMA_DMACICR_LASTIE_MK(n)            (((Uint16)(n) & 0x0001u) << _DMA_DMACICR_LASTIE_SHIFT)
#define _DMA_DMACICR_LASTIE_MASK             (_DMA_DMACICR_LASTIE_MK(0x0001u))
#define _DMA_DMACICR_LASTIE_CLR              (~(_DMA_DMACICR_LASTIE_MASK))

/*==========================================================================*\
* (RW) _DMA_DMACICR_FRAMEIE
\*--------------------------------------------------------------------------*/
#define _DMA_DMACICR_FRAMEIE_SHIFT          (0x0003u)
#define _DMA_DMACICR_FRAMEIE_MK(n)          (((Uint16)(n) & 0x0001u) << _DMA_DMACICR_FRAMEIE_SHIFT)
#define _DMA_DMACICR_FRAMEIE_MASK           (_DMA_DMACICR_FRAMEIE_MK(0x0001u))
#define _DMA_DMACICR_FRAMEIE_CLR            (~(_DMA_DMACICR_FRAMEIE_MASK))

/*==========================================================================*\
* (RW) _DMA_DMACICR_HALFIE
\*--------------------------------------------------------------------------*/
#define _DMA_DMACICR_HALFIE_SHIFT      (0x0002u)
#define _DMA_DMACICR_HALFIE_MK(n)      (((Uint16)(n) & 0x0001u) << _DMA_DMACICR_HALFIE_SHIFT)
#define _DMA_DMACICR_HALFIE_MASK       (_DMA_DMACICR_HALFIE_MK(0x0001u))
#define _DMA_DMACICR_HALFIE_CLR        (~(_DMA_DMACICR_HALFIE_MASK))

/*==========================================================================*\
* (RW) _DMA_DMACICR_DROPIE
\*--------------------------------------------------------------------------*/
#define _DMA_DMACICR_DROPIE_SHIFT           (0x0001u)
#define _DMA_DMACICR_DROPIE_MK(n)           (((Uint16)(n) & 0x0001u) << _DMA_DMACICR_DROPIE_SHIFT)
#define _DMA_DMACICR_DROPIE_MASK            (_DMA_DMACICR_DROPIE_MK(0x0001u))
#define _DMA_DMACICR_DROPIE_CLR             (~(_DMA_DMACICR_DROPIE_MASK))

/*==========================================================================*\
* (RW) _DMA_DMACICR_TIMEOUTIE
\*--------------------------------------------------------------------------*/
#define _DMA_DMACICR_TIMEOUTIE_SHIFT        (0x0000u)
#define _DMA_DMACICR_TIMEOUTIE_MK(n)        (((Uint16)(n) & 0x0001u) << _DMA_DMACICR_TIMEOUTIE_SHIFT)
#define _DMA_DMACICR_TIMEOUTIE_MASK         (_DMA_DMACICR_TIMEOUTIE_MK(0x0001u))
#define _DMA_DMACICR_TIMEOUTIE_CLR          (~(_DMA_DMACICR_TIMEOUTIE_MASK))

#if (CHIP_5502) || (CHIP_5501)

#define _DMA_DMACICR_CFG(Ch, aerrie, blockie, lastie, frameie, halfie, dropie, timeoutie)\
   _PREG_SET(_DMA_DMACICR_ADDR(Ch),\
             (Uint16) ( _DMA_DMACICR_AERRIE_MK(aerrie)            |\
                        _DMA_DMACICR_BLOCKIE_MK(blockie)          |\
                        _DMA_DMACICR_LASTIE_MK(lastie)            |\
                        _DMA_DMACICR_FRAMEIE_MK(frameie)          |\
                        _DMA_DMACICR_HALFIE_MK(firsthalfie)       |\
                        _DMA_DMACICR_DROPIE_MK(dropie)            |\
                        _DMA_DMACICR_TIMEOUTIE_MK(timeoutie)      \
                      )\
   )
#else

#define _DMA_DMACICR_CFG(Ch, blockie, lastie, frameie, halfie, dropie, timeoutie)\
   _PREG_SET(_DMA_DMACICR_ADDR(Ch),\
             (Uint16) ( _DMA_DMACICR_BLOCKIE_MK(blockie)          |\
                        _DMA_DMACICR_LASTIE_MK(lastie)            |\
                        _DMA_DMACICR_FRAMEIE_MK(frameie)          |\
                        _DMA_DMACICR_HALFIE_MK(firsthalfie)       |\
                        _DMA_DMACICR_DROPIE_MK(dropie)            |\
                        _DMA_DMACICR_TIMEOUTIE_MK(timeoutie)      \
                      )\
   )

#endif /* 5502 || 5501 */
                       
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*========================================================================*\
* _DMA_DMACSRn	   - Channel #n Channel Status Register
*
* Fields:
*  (R) _DMA_DMACSR_AERR   (for 5501 and 5502 only)
*  (R) _DMA_DMACSR_SYNC
*  (R) _DMA_DMACSR_BLOCK
*  (R) _DMA_DMACSR_LAST
*  (R) _DMA_DMACSR_FRAME
*  (R) _DMA_DMACSR_HALF
*  (R) _DMA_DMACSR_DROP
*  (R) _DMA_DMACSR_TIMEOUT
\*========================================================================*/

/*========================================================================*\
* (R) _DMA_DMACSR_AERR
\*------------------------------------------------------------------------*/
#define _DMA_DMACSR_AERR_SHIFT            (0x0007u)
#define _DMA_DMACSR_AERR_MASK             (((Uint16)(1) & 0x0001u) << _DMA_DMACSR_AERR_SHIFT)
#define _DMA_DMACSR_AERR_MK(n)            (((Uint16)(n) & 0x0001u) << _DMA_DMACSR_AERR_SHIFT)
#define _DMA_DMACSR_AERR_CLR              (~(_DMA_DMACSR_AERR_MASK))

/*========================================================================*\
* (R) _DMA_DMACSR_SYNC
\*------------------------------------------------------------------------*/
#define _DMA_DMACSR_SYNC_SHIFT            (0x0006u)
#define _DMA_DMACSR_SYNC_MASK             (((Uint16)(1) & 0x0001u) << _DMA_DMACSR_SYNC_SHIFT)
#define _DMA_DMACSR_SYNC_MK(n)            (((Uint16)(n) & 0x0001u) << _DMA_DMACSR_SYNC_SHIFT)
#define _DMA_DMACSR_SYNC_CLR              (~(_DMA_DMACSR_SYNC_MASK))



/*========================================================================*\
* (R) _DMA_DMACSR_BLOCK
\*------------------------------------------------------------------------*/
#define _DMA_DMACSR_BLOCK_SHIFT           (0x0005u)
#define _DMA_DMACSR_BLOCK_MASK            (((Uint16)(1) & 0x0001u) << _DMA_DMACSR_BLOCK_SHIFT)
#define _DMA_DMACSR_BLOCK_MK(n)           (((Uint16)(n) & 0x0001u) << _DMA_DMACSR_BLOCK_SHIFT)
#define _DMA_DMACSR_BLOCK_CLR             (~(_DMA_DMACSR_BLOCK_MASK))

/*========================================================================*\
* (R) _DMA_DMACSR_LAST
\*------------------------------------------------------------------------*/
#define _DMA_DMACSR_LAST_SHIFT            (0x0004u)
#define _DMA_DMACSR_LAST_MASK             (((Uint16)(1) & 0x0001u) << _DMA_DMACSR_LAST_SHIFT)
#define _DMA_DMACSR_LAST_MK(n)            (((Uint16)(n) & 0x0001u) << _DMA_DMACSR_LAST_SHIFT)
#define _DMA_DMACSR_LAST_CLR              (~(_DMA_DMACSR_LAST_MASK))


/*========================================================================*\
* (R) _DMA_DMACSR_FRAME
\*------------------------------------------------------------------------*/
#define _DMA_DMACSR_FRAME_SHIFT           (0x0003u)
#define _DMA_DMACSR_FRAME_MASK            (((Uint16)(1) & 0x0001u) << _DMA_DMACSR_FRAME_SHIFT)
#define _DMA_DMACSR_FRAME_MK(n)           (((Uint16)(n) & 0x0001u) << _DMA_DMACSR_FRAME_SHIFT)
#define _DMA_DMACSR_FRAME_CLR             (~(_DMA_DMACSR_FRAME_MASK))


/*========================================================================*\
* (R) _DMA_DMACSR_HALF
\*------------------------------------------------------------------------*/
#define _DMA_DMACSR_HALF_SHIFT            (0x0002u)
#define _DMA_DMACSR_HALF_MASK             (((Uint16)(1) & 0x0001u) << _DMA_DMACSR_HALF_SHIFT)
#define _DMA_DMACSR_HALF_MK(n)            (((Uint16)(n) & 0x0001u) << _DMA_DMACSR_HALF_SHIFT)
#define _DMA_DMACSR_HALF_CLR              (~(_DMA_DMACSR_HALF_MASK))


/*========================================================================*\
* (R) _DMA_DMACSR_DROP
\*------------------------------------------------------------------------*/
#define _DMA_DMACSR_DROP_SHIFT            (0x0001u)
#define _DMA_DMACSR_DROP_MASK             (((Uint16)(1) & 0x0001u) << _DMA_DMACSR_DROP_SHIFT)
#define _DMA_DMACSR_DROP_MK(n)            (((Uint16)(n) & 0x0001u) << _DMA_DMACSR_DROP_SHIFT)
#define _DMA_DMACSR_DROP_CLR              (~(_DMA_DMACSR_DROP_MASK))


/*========================================================================*\
* (R) _DMA_DMACSR_TIMEOUT
\*------------------------------------------------------------------------*/
#define _DMA_DMACSR_TIMEOUT_SHIFT         (0x0000u)
#define _DMA_DMACSR_TIMEOUT_MASK          (((Uint16)(1) & 0x0001u) << _DMA_DMACSR_TIMEOUT_SHIFT)
#define _DMA_DMACSR_TIMEOUT_MK(n)         (((Uint16)(n) & 0x0001u) << _DMA_DMACSR_TIMEOUT_SHIFT)
#define _DMA_DMACSR_TIMEOUT_CLR           (~(_DMA_DMACSR_TIMEOUT_MASK))
        



/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*========================================================================*\
* _DMA_DMACSSALn	   - Channel #n Channel Source Start Address (lower 16 bits)
*
* Fields:
*  (RW) _DMA_DMACSSAL_SSAL       
\*========================================================================*/

/*========================================================================*\
* (RW) _DMA_DMACSSAL_SSAL
\*------------------------------------------------------------------------*/
#define _DMA_DMACSSAL_SSAL_SHIFT           (0x0000u)
#define _DMA_DMACSSAL_SSAL_MK(n)           (((Uint16)(n) & 0xFFFFu) << _DMA_DMACSSAL_SSAL_SHIFT)
#define _DMA_DMACSSAL_SSAL_MASK            (_DMA_DMACSSAL_SSAL_MK(0xFFFFu))
#define _DMA_DMACSSAL_SSAL_CLR             (~(_DMA_DMACSSAL_SSAL_MASK))

#define _DMA_DMACSSAL_SSAL_GET(RegAddr) \
   _PFIELD_GET(RegAddr,_DMA_DMACSSAL_SSAL)

#define _DMA_DMACSSAL_SSAL_SET(RegAddr,Val) \
   _PFIELD_SET(RegAddr,_DMA_DMACSSAL_SSAL,Val)

#define _DMA_DMACSSAL_CFG(RegAddr, ssal)   _PREG_SET(RegAddr, _DMA_CSSA_SSAL_MK(ssal))

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*============================================================================*\
* _DMA_DMACSSAUn	   - Channel #n Channel Source Start Address (lower 16 bits)
*
* Fields:
*  (RW) _DMA_DMACSSAU_SSAU       
\*============================================================================*/

/*==========================================================================*\
* (RW) _DMA_DMACSSAU_SSAU
\*--------------------------------------------------------------------------*/
#define _DMA_DMACSSAU_SSAU_SHIFT           (0x0000u)
#define _DMA_DMACSSAU_SSAU_MK(n)           (((Uint16)(n) & 0xFFFFu) << _DMA_DMACSSAU_SSAU_SHIFT)
#define _DMA_DMACSSAU_SSAU_MASK            (_DMA_DMACSSAU_SSAU_MK(0xFFFFu))
#define _DMA_DMACSSAU_SSAU_CLR             (~(_DMA_DMACSSAU_SSAU_MASK))

#define _DMA_DMACSSAU_CFG(Ch, ssau)   _PREG_SET(_DMA_DMACSSAU_ADDR(Ch), _DMA_DMACSSAU_SSAU_MK(ssau))

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*============================================================================*\
* _DMA_DMACDSALn	   - Channel #n Channel Source Start Address (lower 16 bits)
*
* Fields:
*  (RW) _DMA_DMACDSAL_DSAL       
\*============================================================================*/

/*==========================================================================*\
* (RW) _DMA_DMACDSAL_DSAL
\*--------------------------------------------------------------------------*/
#define _DMA_DMACDSAL_DSAL_SHIFT           (0x0000u)
#define _DMA_DMACDSAL_DSAL_MK(n)           (((Uint16)(n) & 0xFFFFu) << _DMA_DMACDSAL_DSAL_SHIFT)
#define _DMA_DMACDSAL_DSAL_MASK            (_DMA_DMACDSAL_DSAL_MK(0xFFFFu))
#define _DMA_DMACDSAL_DSAL_CLR             (~(_DMA_DMACDSAL_DSAL_MASK))

#define _DMA_DMACDSAL_CFG(Ch, dsal)   _PREG_SET(_DMA_DMACDSAL_ADDR(Ch), _DMA_DMACDSAL_DSAL_MK(dsal))

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*============================================================================*\
* _DMA_DMACDSAUn	   - Channel #n Channel Source Start Address (lower 16 bits)
*
* Fields:
*  (RW) _DMA_DMACDSAU_DSAU       
\*============================================================================*/

/*==========================================================================*\
* (RW) _DMA_DMACDSAU_DSAU
\*--------------------------------------------------------------------------*/
#define _DMA_DMACDSAU_DSAU_SHIFT           (0x0000u)
#define _DMA_DMACDSAU_DSAU_MK(n)           (((Uint16)(n) & 0xFFFFu) << _DMA_DMACDSAU_DSAU_SHIFT)
#define _DMA_DMACDSAU_DSAU_MASK            (_DMA_DMACDSAU_DSAU_MK(0xFFFFu))
#define _DMA_DMACDSAU_DSAU_CLR             (~(_DMA_DMACDSAU_DSAU_MASK))

#define _DMA_DMACDSAU_CFG(Ch, dsau)   _PREG_SET(_DMA_DMACDSAU_ADDR(Ch), _DMA_DMACDSAU_DSAU_MK(dsau))

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*========================================================================*\
* _DMA_DMACENn	   - Channel #n Channel Element Number Register
*
* Fields:
*  (RW) _DMA_DMACEN_ELEMENTNUM       
\*========================================================================*/

/*=========================================================================*\
* (RW) _DMA_DMACEN_ELEMENTNUM
\*-------------------------------------------------------------------------*/
#define _DMA_DMACEN_ELEMENTNUM_SHIFT           (0x0000u)
#define _DMA_DMACEN_ELEMENTNUM_MK(n)           (((Uint16)(n) & 0xFFFFu) << _DMA_DMACEN_ELEMENTNUM_SHIFT)
#define _DMA_DMACEN_ELEMENTNUM_MASK            (_DMA_DMACEN_ELEMENTNUM_MK(0xFFFFu))
#define _DMA_DMACEN_ELEMENTNUM_CLR             (~(_DMA_DMACEN_ELEMENTNUM_MASK))

#define _DMA_DMACEN_CFG(Ch, elementnum)  _PREG_SET(_DMA_DMACEN_ADDR(Ch), _DMA_DMACEN_ELEMENTNUM_MK(elementnum))

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*========================================================================*\
* _DMA_DMACFNn	   - Channel #n Channel Frame Number Register
*
* Fields:
*  (RW) _DMA_DMACFN_FRAMENUM      
\*========================================================================*/

/*========================================================================*\
* (RW) _DMA_DMACFN_FRAMENUM
\*------------------------------------------------------------------------*/
#define _DMA_DMACFN_FRAMENUM_SHIFT           (0x0000u)
#define _DMA_DMACFN_FRAMENUM_MK(n)           (((Uint16)(n) & 0xFFFFu) << _DMA_DMACFN_FRAMENUM_SHIFT)
#define _DMA_DMACFN_FRAMENUM_MASK            (_DMA_DMACFN_FRAMENUM_MK(0xFFFFu))
#define _DMA_DMACFN_FRAMENUM_CLR             (~(_DMA_DMACFN_FRAMENUM_MASK))

#define _DMA_DMACFN_CFG(Ch, framenum)   _PREG_SET(_DMA_DMACFN_ADDR(Ch), _DMA_DMACFN_FRAMENUM_MK(framenum))

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*========================================================================*\
* _DMA_DMACFIn	   - Channel #n Channel Frame Index Register
*
* Fields:
*  (RW) _DMA_DMACFI_FRAMENDX      
\*========================================================================*/

/*========================================================================*\
* (RW) _DMA_DMACFI_FRAMENDX
\*------------------------------------------------------------------------*/
#define _DMA_DMACFI_FRAMENDX_SHIFT           (0x0000u)
#define _DMA_DMACFI_FRAMENDX_MK(n)           (((Uint16)(n) & 0xFFFFu) << _DMA_DMACFI_FRAMENDX_SHIFT)
#define _DMA_DMACFI_FRAMENDX_MASK            (_DMA_DMACFI_FRAMENDX_MK(0xFFFFu))
#define _DMA_DMACFI_FRAMENDX_CLR             (~(_DMA_DMACFI_FRAMENDX_MASK))

#define _DMA_DMACFI_CFG(Ch, framendx)   _PREG_SET(_DMA_DMACFI_ADDR(Ch), _DMA_DMACFI_FRAMENDX_MK(framendx))

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*========================================================================*\
* _DMA_DMACEIn	   - Channel #n Channel Element Index Register
*
* Fields:
*  (RW) _DMA_DMACEI_ELEMENTNDX      
\*========================================================================*/

/*========================================================================*\
* (RW) _DMA_DMACEI_ELEMENTNDX
\*------------------------------------------------------------------------*/
#define _DMA_DMACEI_ELEMENTNDX_SHIFT           (0x0000u)
#define _DMA_DMACEI_ELEMENTNDX_MK(n)           (((Uint16)(n) & 0xFFFFu) << _DMA_DMACEI_ELEMENTNDX_SHIFT)
#define _DMA_DMACEI_ELEMENTNDX_MASK            (_DMA_DMACEI_ELEMENTNDX_MK(0xFFFFu))
#define _DMA_DMACEI_ELEMENTNDX_CLR             (~(_DMA_DMACEI_ELEMENTNDX_MASK))

#define _DMA_DMACEI_CFG(Ch, elementndx)   _PREG_SET(_DMA_DMACEI_ADDR(Ch), _DMA_DMACEI_ELEMENTNDX_MK(elementndx))

#if (_DMA_DST_AND_SRC_INDEX_SUPPORT)

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*========================================================================*\
* _DMA_DMACSFIn	   - Channel #n Channel Src Frame Index Register
*
* Fields:
*  (RW) _DMA_DMACSFI_FRAMENDX      
\*========================================================================*/

/*========================================================================*\
* (RW) _DMA_DMACSFI_FRAMENDX
\*------------------------------------------------------------------------*/
#define _DMA_DMACSFI_FRAMENDX_SHIFT           (0x0000u)
#define _DMA_DMACSFI_FRAMENDX_MK(n)           (((Uint16)(n) & 0xFFFFu) << _DMA_DMACSFI_FRAMENDX_SHIFT)
#define _DMA_DMACSFI_FRAMENDX_MASK            (_DMA_DMACSFI_FRAMENDX_MK(0xFFFFu))
#define _DMA_DMACSFI_FRAMENDX_CLR             (~(_DMA_DMACSFI_FRAMENDX_MASK))

#define _DMA_DMACSFI_CFG(Ch, framendx)   _PREG_SET(_DMA_DMACSFI_ADDR(Ch), _DMA_DMACSFI_FRAMENDX_MK(framendx))


/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*========================================================================*\
* _DMA_DMACSACn	   - Channel #n Channel Src Address Count Register
*
* Fields:
*  (RW) _DMA_DMACSAC_DMACSAC     
\*========================================================================*/

/*========================================================================*\
* (RW) _DMA_DMACSAC_DMACSAC
\*------------------------------------------------------------------------*/
#define _DMA_DMACSAC_DMACSAC_SHIFT           (0x0000u)
#define _DMA_DMACSAC_DMACSAC_MK(n)           (((Uint16)(n) & 0xFFFFu) << _DMA_DMACSAC_DMACSAC_SHIFT)
#define _DMA_DMACSAC_DMACSAC_MASK            (_DMA_DMACSAC_DMACSAC_MK(0xFFFFu))
#define _DMA_DMACSAC_DMACSAC_CLR             (~(_DMA_DMACSAC_DMACSAC_MASK))

#define _DMA_DMACSAC_CFG(Ch, dmacsac)   _PREG_SET(_DMA_DMACSAC_ADDR(Ch), _DMA_DMACSAC_DMACSAC_MK(dmacsac))

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*========================================================================*\
* _DMA_DMACDACn	   - Channel #n Channel Dst Address Count Register
*
* Fields:
*  (RW) _DMA_DMACDAC_DMACDAC     
\*========================================================================*/

/*========================================================================*\
* (RW) _DMA_DMACDAC_DMACDAC
\*------------------------------------------------------------------------*/
#define _DMA_DMACDAC_DMACDAC_SHIFT           (0x0000u)
#define _DMA_DMACDAC_DMACDAC_MK(n)           (((Uint16)(n) & 0xFFFFu) << _DMA_DMACDAC_DMACDAC_SHIFT)
#define _DMA_DMACDAC_DMACDAC_MASK            (_DMA_DMACDAC_DMACDAC_MK(0xFFFFu))
#define _DMA_DMACDAC_DMACDAC_CLR             (~(_DMA_DMACDAC_DMACDAC_MASK))

#define _DMA_DMACDAC_CFG(Ch, dmacdac)   _PREG_SET(_DMA_DMACDAC_ADDR(Ch), _DMA_DMACDAC_DMACDAC_MK(dmacdac))


/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*========================================================================*\
* _DMA_DMACSEIn	   - Channel #n Channel Src Element Index Register
*
* Fields:
*  (RW) _DMA_DMACSEI_ELEMENTNDX      
\*========================================================================*/

/*========================================================================*\
* (RW) _DMA_DMACSEI_ELEMENTNDX
\*------------------------------------------------------------------------*/
#define _DMA_DMACSEI_ELEMENTNDX_SHIFT           (0x0000u)
#define _DMA_DMACSEI_ELEMENTNDX_MK(n)           (((Uint16)(n) & 0xFFFFu) << _DMA_DMACSEI_ELEMENTNDX_SHIFT)
#define _DMA_DMACSEI_ELEMENTNDX_MASK            (_DMA_DMACSEI_ELEMENTNDX_MK(0xFFFFu))
#define _DMA_DMACSEI_ELEMENTNDX_CLR             (~(_DMA_DMACSEI_ELEMENTNDX_MASK))

#define _DMA_DMACSEI_CFG(Ch, elementndx)   _PREG_SET(_DMA_DMACSEI_ADDR(Ch), _DMA_DMACSEI_ELEMENTNDX_MK(elementndx))

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*========================================================================*\
* _DMA_DMACSFIn	   - Channel #n Channel Dst Frame Index Register
*
* Fields:
*  (RW) _DMA_DMACDFI_FRAMENDX      
\*========================================================================*/

/*========================================================================*\
* (RW) _DMA_DMACDFI_FRAMENDX
\*------------------------------------------------------------------------*/
#define _DMA_DMACDFI_FRAMENDX_SHIFT           (0x0000u)
#define _DMA_DMACDFI_FRAMENDX_MK(n)           (((Uint16)(n) & 0xFFFFu) << _DMA_DMACDFI_FRAMENDX_SHIFT)
#define _DMA_DMACDFI_FRAMENDX_MASK            (_DMA_DMACDFI_FRAMENDX_MK(0xFFFFu))
#define _DMA_DMACDFI_FRAMENDX_CLR             (~(_DMA_DMACDFI_FRAMENDX_MASK))

#define _DMA_DMACDFI_CFG(Ch, framendx)   _PREG_SET(_DMA_DMACDFI_ADDR(Ch), _DMA_DMACDFI_FRAMENDX_MK(framendx))

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*========================================================================*\
* _DMA_DMACDEIn	   - Channel #n Channel Dst Element Index Register
*
* Fields:
*  (RW) _DMA_DMACDEI_ELEMENTNDX      
\*========================================================================*/

/*========================================================================*\
* (RW) _DMA_DMACDEI_ELEMENTNDX
\*------------------------------------------------------------------------*/
#define _DMA_DMACDEI_ELEMENTNDX_SHIFT           (0x0000u)
#define _DMA_DMACDEI_ELEMENTNDX_MK(n)           (((Uint16)(n) & 0xFFFFu) << _DMA_DMACDEI_ELEMENTNDX_SHIFT)
#define _DMA_DMACDEI_ELEMENTNDX_MASK            (_DMA_DMACDEI_ELEMENTNDX_MK(0xFFFFu))
#define _DMA_DMACDEI_ELEMENTNDX_CLR             (~(_DMA_DMACDEI_ELEMENTNDX_MASK))

#define _DMA_DMACDEI_CFG(Ch, elementndx)   _PREG_SET(_DMA_DMACDEI_ADDR(Ch), _DMA_DMACDEI_ELEMENTNDX_MK(elementndx))


#endif /* _DMA_SRC_AND_DST_INDEX_SUPPORT */
#endif /* _DMAHAL_H_ */
