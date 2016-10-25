/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... ICACHE
* FILENAME...... csl_icachhal.h
* DATE CREATED.. Thu 08/19/1999 
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS.. 
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:          08/19/1999 Created
*   MODIFIED:         05/11/2000 modified for TMS320C55xx
*   LAST MODIFIED:    04/12/2001 changed FILENAME to match actual filename
*                     08/03/2004 Added 5501 support 
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the CHIP module)
* 
* ICACHE Control Registers Covered
*   _ICACHE_ICGC  - ICACHE global control register
*   _ICACHE_ICWC  - ICACHE N-way control register
*   _ICACHE_ICST  - ICACHE Status Register
*   _ICACHE_ICRC1 - ICACHE 1/2 ram-set 1 control register
*   _ICACHE_ICRTAG1 - ICACHE 1/2 ram-set 1 tag register
*   _ICACHE_ICRC2 - ICACHE 1/2 ram-set 2 control register
*   _ICACHE_ICRTAG2 - ICACHE 1/2 ram-set 2 tag register
\******************************************************************************/

#ifndef _ICACHEHAL_H_
#define _ICACHEHAL_H_
/****************************************\
* include files
\****************************************/    
#include <csl_chiphal.h>
#include <csl_std.h>
#include <csl_stdhal.h>

#if (_ICACHE_SUPPORT)

/*============================================================================*\
* Generic ICACHE register/field get/set macros
\*============================================================================*/

#define ICACHE_ADDR(Reg)                   _ICACHE_##Reg##_ADDR
#define ICACHE_RGET(Reg)                   _PREG_GET(ICACHE_ADDR(##Reg))
#define ICACHE_RSET(Reg,Val)               _PREG_SET(ICACHE_ADDR(##Reg),Val)
#define ICACHE_RAOI(Reg,AND,OR,INV)        _PREG_AOI(ICACHE_ADDR(##Reg),AND,OR,INV)
#define ICACHE_FGET(Reg,Field)             _PFIELD_GET(ICACHE_ADDR(##Reg),_ICACHE_##Reg##_##Field)

#define ICACHE_FSET(Reg,Field,Val)\
   _PFIELD_SET(ICACHE_ADDR(##Reg),_ICACHE_##Reg##_##Field,Val)

#define ICACHE_FSETS(Reg,Field,Sym)\
   ICACHE_FSET(##Reg,##Field,ICACHE_##Reg##_##Field##_##Sym)

#define ICACHE_FAOI(Reg,Field,AND,OR,INV)\
   _PFIELD_AOI(ICACHE_ADDR(##Reg),_ICACHE_##Reg##_##Field,AND,OR,INV)

#define ICACHE_FMK(Reg,Field,Val)          _ICACHE_##Reg##_##Field##_MK(Val)

#define ICACHE_FMKS(Reg,Field,Sym)\
  ICACHE_FMK(##Reg,##Field,ICACHE_##Reg##_##Field##_##Sym)

#if (CHIP_5510) | (CHIP_5510PG2_0)

/******************************************************************************\
* _ICACHE_ICGC - Icache global control register
*
* Fields:
*   (RW) _ICACHE_ICGC_RMODE	
*
\******************************************************************************/
#define _ICACHE_ICGC_ADDR    (0x1400u)
#define _ICACHE_ICGC          PREG16(_ICACHE_ICGC_ADDR)
#define _ICGC                 _ICACHE_ICGC


/*----------------------------------------------------------------------------*\
* (RW) _ICACHE_ICGC_RMODE :  Ramset Mode Configuration
\*----------------------------------------------------------------------------*/ 
#define _ICACHE_ICGC_RMODE_SHIFT        (0x0000u)
#define _ICACHE_ICGC_RMODE_MK(n)        (((Uint16)n & 0xFFFFu) << _ICACHE_ICGC_RMODE_SHIFT)
#define _ICACHE_ICGC_RMODE_MASK         (_ICACHE_ICGC_RMODE_MK(0xFFFFu))
#define _ICACHE_ICGC_RMODE_CLR          (~(_ICACHE_ICGC_RMODE_MASK))

#define _ICACHE_ICGC_CFG(rmode)\
  _PREG_SET(_ICACHE_ICGC_ADDR, _ICACHE_ICGC_RMODE_MK(rmode))

   
/******************************************************************************\
* _ICACHE_ICWC - ICache N-Way Control Register ICWC
*
* Fields:
*   (RW) _ICACHE_ICWC_WINIT
*
\******************************************************************************/
#define _ICACHE_ICWC_ADDR    (0x1403u)
#define _ICACHE_ICWC         PREG16(_ICACHE_ICWC_ADDR)
#define _ICWC                _ICACHE_ICWC


/*----------------------------------------------------------------------------*\
* (RW) _ICACHE_ICWC_WINIT : N-way mask init
\*----------------------------------------------------------------------------*/ 
#define _ICACHE_ICWC_WINIT_SHIFT           (0x0000u)
#define _ICACHE_ICWC_WINIT_MK(n)           (((Uint16)n & 0x000Fu) << _ICACHE_ICWC_WINIT_SHIFT)
#define _ICACHE_ICWC_WINIT_MASK            (_ICACHE_ICWC_WINIT_MK(0x000Fu))
#define _ICACHE_ICWC_WINIT_CLR             (~(_ICACHE_ICWC_WINIT_MASK))

#define _ICACHE_ICWC_CFG(winit)\
  _PREG_SET(_ICACHE_ICWC_ADDR, _ICACHE_ICWC_WINIT_MK(winit))


/******************************************************************************\
* _ICACHE_ICRC - 1/2 RamSet Control Register 1 & 2
*
* Fields:
*   (R ) _ICACHE_ICRC1_R1&2TVALID
*   (RW) _ICACHE_ICRC1_R1&2INIT
*
\******************************************************************************/
#define _ICACHE_ICRC1_ADDR    (0x1405u)
#define _ICACHE_ICRC1         PREG16(_ICACHE_ICRC1_ADDR)
#define _ICRC1                _ICACHE_ICRC1

#define _ICACHE_ICRC2_ADDR    (0x1407u)
#define _ICACHE_ICRC2         PREG16(_ICACHE_ICRC2_ADDR)
#define _ICRC2                _ICACHE_ICRC2

/*----------------------------------------------------------------------------*\
* (R) _ICACHE_ICRC1_R1TVALID : Tag Valid flag
\*----------------------------------------------------------------------------*/ 
#define _ICACHE_ICRC1_R1TVALID_SHIFT  (0x000Fu)
#define _ICACHE_ICRC1_R1TVALID_MK(n)  (((Uint16)n & 0x0001u) << _ICACHE_ICRC1_R1TVALID_SHIFT)
#define _ICACHE_ICRC1_R1TVALID_MASK   (_ICACHE_ICRC1_R1TVALID_MK(0x0001u))

/*----------------------------------------------------------------------------*\
* (RW) _ICACHE_ICRC1_R1INIT : Ramset 1 init mask
\*----------------------------------------------------------------------------*/ 
#define _ICACHE_ICRC1_R1INIT_SHIFT           (0x0000u)
#define _ICACHE_ICRC1_R1INIT_MK(n)           (((Uint16)n & 0x0003u) << _ICACHE_ICRC1_R1INIT_SHIFT)
#define _ICACHE_ICRC1_R1INIT_MASK            (_ICACHE_ICRC1_R1INIT_MK(0x0003u))
#define _ICACHE_ICRC1_R1INIT_CLR             (~(_ICACHE_ICRC1_R1INIT_MASK))


/*----------------------------------------------------------------------------*\
* (RW) _ICACHE_ICRC2_R2TVALID : Tag Valid flag
\*----------------------------------------------------------------------------*/ 
#define _ICACHE_ICRC2_R2TVALID_SHIFT  (0x000Fu)
#define _ICACHE_ICRC2_R2TVALID_MK(n)  (((Uint16)n & 0x0001u) << _ICACHE_ICRC2_R2TVALID_SHIFT)
#define _ICACHE_ICRC2_R2TVALID_MASK   (_ICACHE_ICRC2_R2TVALID_MK(0x0001u))

/*----------------------------------------------------------------------------*\
* (RW) _ICACHE_ICRC2_R2INIT : Ramset 2 init mask
\*----------------------------------------------------------------------------*/ 
#define _ICACHE_ICRC2_R2INIT_SHIFT           (0x0000u)
#define _ICACHE_ICRC2_R2INIT_MK(n)           (((Uint16)n & 0x0003u) << _ICACHE_ICRC2_R2INIT_SHIFT)
#define _ICACHE_ICRC2_R2INIT_MASK            (_ICACHE_ICRC2_R2INIT_MK(0x0003u))
#define _ICACHE_ICRC2_R2INIT_CLR             (~(_ICACHE_ICRC2_R2INIT_MASK))



#define _ICACHE_ICRC1_CFG(r1init)\
  _PREG_SET(_ICACHE_ICRC1_ADDR,_ICACHE_ICRC1_R1INIT_MK(r1init))

#define _ICACHE_ICRC2_CFG(r2init)\
  _PREG_SET(_ICACHE_ICRC2_ADDR,_ICACHE_ICRC2_R2INIT_MK(r2init))



/******************************************************************************\
* _ICACHE_ICRTAG1 - ICACHE 1/2 Ram-set Tag Register 1 & 2
*
* Fields:
*   (RW) _ICACHE_ICRTAG1_R1TAG
*
\******************************************************************************/
#define _ICACHE_ICRTAG1_ADDR    (0x1406u)
#define _ICACHE_ICRTAG1         PREG16(_ICACHE_ICRTAG1_ADDR)
#define _ICRTAG1                _ICACHE_ICRTAG1

#define _ICACHE_ICRTAG2_ADDR    (0x1408u)
#define _ICACHE_ICRTAG2         PREG16(_ICACHE_ICRTAG2_ADDR)
#define _ICRTAG2                _ICACHE_ICRTAG2

/*----------------------------------------------------------------------------*\
* (RW) _ICACHE_ICRTAG1_R1TAG : Tag
\*----------------------------------------------------------------------------*/ 
#define _ICACHE_ICRTAG1_R1TAG_SHIFT            (0x0000u)
#define _ICACHE_ICRTAG1_R1TAG_MK(n)            (((Uint16)n & 0x7FFFu) << _ICACHE_ICRTAG1_R1TAG_SHIFT)
#define _ICACHE_ICRTAG1_R1TAG_MASK             (_ICACHE_ICRTAG1_R1TAG_MK(0x7FFFu))
#define _ICACHE_ICRTAG1_R1TAG_CLR              (~(_ICACHE_ICRTAG1_R1TAG_MASK))

/*----------------------------------------------------------------------------*\
* (RW) _ICACHE_ICRTAG_R2TAG : Tag
\*----------------------------------------------------------------------------*/ 
#define _ICACHE_ICRTAG2_R2TAG_SHIFT            (0x0000u)
#define _ICACHE_ICRTAG2_R2TAG_MK(n)            (((Uint16)n & 0x7FFFu) << _ICACHE_ICRTAG2_R2TAG_SHIFT)
#define _ICACHE_ICRTAG2_R2TAG_MASK             (_ICACHE_ICRTAG2_R2TAG_MK(0x7FFFu))
#define _ICACHE_ICRTAG2_R2TAG_CLR              (~(_ICACHE_ICRTAG2_R2TAG_MASK))


#define _ICACHE_ICRTAG1_CFG(r1tag)\
  _PREG_SET(_ICACHE_ICRTAG1_ADDR, _ICACHE_ICRTAG1_R1TAG_MK(r1tag))

#define _ICACHE_ICRTAG2_CFG(r2tag)\
  _PREG_SET(_ICACHE_ICRTAG2_ADDR, _ICACHE_ICRTAG2_R2TAG_MK(r2tag))



/******************************************************************************\
* _ICACHE_ICST - ICACHE Status Register ICST
*
* Fields:
*   (R ) _ICACHE_ICST_IEN
*
\******************************************************************************/
#define _ICACHE_ICST_ADDR    (0x1404u)
#define _ICACHE_ICST         PREG16(_ICACHE_ICST_ADDR)
#define _ICST                _ICACHE_ICST

/*----------------------------------------------------------------------------*\
* (R) _ICACHE_ICST_IEN : Enable
\*----------------------------------------------------------------------------*/ 
#define _ICACHE_ICST_IEN_SHIFT          (0x0002u)
#define _ICACHE_ICST_IEN_MK(n)          (((Uint16)n & 0x0001u) << _ICACHE_ICST_IEN_SHIFT)
#define _ICACHE_ICST_IEN_MASK           (_ICACHE_ICST_IEN_MK(0x0001u))


#endif

#if (CHIP_5502) || (CHIP_5501)

/******************************************************************************\
* _ICACHE_ICGC - ICACHE global control register
*
* Fields:
*   (RW) _ICACHE_ICGC_FLUSHLINE
*
\******************************************************************************/
#define _ICACHE_ICGC_ADDR    (0x1400u)
#define _ICACHE_ICGC          PREG16(_ICACHE_ICGC_ADDR)
#define _ICGC                 _ICACHE_ICGC


/*----------------------------------------------------------------------------*\
* (RW) _ICACHE_ICGC_FLUSHLINE : Flush line specified in Flush Line Addr Register
\*----------------------------------------------------------------------------*/ 
#define _ICACHE_ICGC_FLUSHLINE_SHIFT        (0x000Cu)
#define _ICACHE_ICGC_FLUSHLINE_MK(n)        (((Uint16)n & 0x0001u) << _ICACHE_ICGC_FLUSHLINE_SHIFT)
#define _ICACHE_ICGC_FLUSHLINE_MASK         (_ICACHE_ICGC_FLUSHLINE_MK(1))
#define _ICACHE_ICGC_FLUSHLINE_CLR          (~(_ICACHE_ICGC_FLUSHLINE_MASK))


/******************************************************************************\
* _ICACHE_ICFLARL - ICACHE Flush Line Address Low Register 
*
* Fields:
*   (RW) _ICACHE_ICFLARL_LAL
*
\******************************************************************************/
#define _ICACHE_ICFLARL_ADDR    (0x1401u)
#define _ICACHE_ICFLARL         PREG16(_ICACHE_ICFLARL_ADDR)
#define _ICFLARL                _ICACHE_ICFLARL

/*----------------------------------------------------------------------------*\
* (RW) _ICACHE_ICFLARL_LAL : Lower 16 bits of line address to flush
\*----------------------------------------------------------------------------*/ 
#define _ICACHE_ICFLARL_LAL_SHIFT     (0x0000u)
#define _ICACHE_ICFLARL_LAL_MK(n)     (((Uint16)n & 0xFFFFu) << _ICACHE_ICFLARL_LAL_SHIFT)
#define _ICACHE_ICFLARL_LAL_MASK      (_ICACHE_ICFLARL_LAL_MK(0xFFFFu))
#define _ICACHE_ICFLARL_LAL_CLR       (~(_ICACHE_ICFLARL_LAL_MASK))

#define _ICACHE_ICFLARL_CFG(lineAddress)\
  _PREG_SET(_ICACHE_ICFLARL_ADDR, _ICACHE_ICFLARL_LAL_MK(lineAddress))

/******************************************************************************\
* _ICACHE_ICFLARH - ICACHE Flush Line Address High Register 1 
*                  (Upper 8 bits of flush line address)
*
* Fields:
*   (RW) _ICACHE_ICFLARH_LAH
*
\******************************************************************************/
#define _ICACHE_ICFLARH_ADDR    (0x1402u)
#define _ICACHE_ICFLARH         PREG16(_ICACHE_ICFLARH_ADDR)
#define _ICFLARH                _ICACHE_ICFLARH

/*----------------------------------------------------------------------------*\
* (RW) _ICACHE_ICFLARH_LAH : Upper 8 bits of line address to flush
\*----------------------------------------------------------------------------*/ 
#define _ICACHE_ICFLARH_LAH_SHIFT     (0x0000u)
#define _ICACHE_ICFLARH_LAH_MK(n)     (((Uint16)n & 0x00FFu) << _ICACHE_ICFLARH_LAH_SHIFT)
#define _ICACHE_ICFLARH_LAH_MASK      (_ICACHE_ICFLARH_LAH_MK(0x00FFu))
#define _ICACHE_ICFLARH_LAH_CLR       (~(_ICACHE_ICFLARH_LAH_MASK))

/******************************************************************************\
* _ICACHE_ICWMC - ICACHE N-Way Miss Counter Register
*
* Fields:
*
*   (RW ) _ICACHE_ICWMC_MISSCNT
*
\******************************************************************************/
#define _ICACHE_ICWMC_ADDR    (0x1409u)
#define _ICACHE_ICWMC         PREG16(_ICACHE_ICWMC_ADDR)
#define _ICWMC                _ICACHE_ICWMC

/*----------------------------------------------------------------------------*\
* (RW) _ICACHE_ICWMC_MISSCNT
\*----------------------------------------------------------------------------*/
#define _ICACHE_ICWMC_MISSCNT_SHIFT      (0x0000u)
#define _ICACHE_ICWMC_MISSCNT_MK(n)      (((Uint16)(n) & 0xffffu)<< _ICACHE_ICWMC_MISSCNT_SHIFT)
#define _ICACHE_ICWMC_MISSCNT_MASK       (_ICACHE_ICWMC_MISSCNT_MK(0xffffu))
#define _ICACHE_ICWMC_MISSCNT_CLR        (~(_ICACHE_ICWMC_MISSCNT_MASK))

#define _ICACHE_ICWMC_CFG(missCnt)\
  _PREG_SET(_ICACHE_ICWMC_ADDR, _ICACHE_ICWMC_MISSCNT_MK(missCnt))

#endif




#else

     #ifndef _ICACHE_MOD_
     #error ICACHE Module Not Supported on Specified Target
     #endif

#endif /* _ICACHE_SUPPORT */
#endif /* _ICACHEHAL_H_ */
/******************************************************************************\
* End of csl_icachhal.h
\******************************************************************************/

