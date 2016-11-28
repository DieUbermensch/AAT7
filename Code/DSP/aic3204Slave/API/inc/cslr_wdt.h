/* ============================================================================
 * Copyright (c) 2008-2012 Texas Instruments Incorporated.
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/


/*********************************************************************
* file: cslr_wdt.h
*
* Brief: This file contains the Register Description for wdt
*
*********************************************************************/
#ifndef _CSLR_WDT_H_
#define _CSLR_WDT_H_

#include <cslr.h>

#include <tistdtypes.h>
#include <csl_general.h>


/* Minimum unit = 2 bytes */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint16 WDKCKLK;
    volatile Uint16 RSVD0;
    volatile Uint16 WDKICK;
    volatile Uint16 RSVD1;
    volatile Uint16 WDSVLR;
    volatile Uint16 RSVD2;
    volatile Uint16 WDSVR;
    volatile Uint16 RSVD3;
    volatile Uint16 WDENLOK;
    volatile Uint16 RSVD4;
    volatile Uint16 WDEN;
    volatile Uint16 RSVD5;
    volatile Uint16 WDPSLR;
    volatile Uint16 RSVD6;
    volatile Uint16 WDPS;
} CSL_WdtRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* WDKCKLK */

#define CSL_WDT_WDKCKLK_KICKLOK_MASK     (0xFFFFu)
#define CSL_WDT_WDKCKLK_KICKLOK_SHIFT    (0x0000u)
#define CSL_WDT_WDKCKLK_KICKLOK_RESETVAL (0x0000u)

#define CSL_WDT_WDKCKLK_RESETVAL         (0x0000u)

/* WDKICK */

#define CSL_WDT_WDKICK_KICK_MASK         (0xFFFFu)
#define CSL_WDT_WDKICK_KICK_SHIFT        (0x0000u)
#define CSL_WDT_WDKICK_KICK_RESETVAL     (0x0000u)

#define CSL_WDT_WDKICK_RESETVAL          (0x0000u)

/* WDSVLR */

#define CSL_WDT_WDSVLR_STVALLOK_MASK     (0xFFFFu)
#define CSL_WDT_WDSVLR_STVALLOK_SHIFT    (0x0000u)
#define CSL_WDT_WDSVLR_STVALLOK_RESETVAL (0x0000u)

#define CSL_WDT_WDSVLR_RESETVAL          (0x0000u)

/* WDSVR */

#define CSL_WDT_WDSVR_STRTVAL_MASK       (0xFFFFu)
#define CSL_WDT_WDSVR_STRTVAL_SHIFT      (0x0000u)
#define CSL_WDT_WDSVR_STRTVAL_RESETVAL   (0x0000u)

#define CSL_WDT_WDSVR_RESETVAL           (0x0000u)

/* WDENLOK */

#define CSL_WDT_WDENLOK_ENLOK_MASK       (0xFFFFu)
#define CSL_WDT_WDENLOK_ENLOK_SHIFT      (0x0000u)
#define CSL_WDT_WDENLOK_ENLOK_RESETVAL   (0x0000u)

#define CSL_WDT_WDENLOK_RESETVAL         (0x0000u)

/* WDEN */

#define CSL_WDT_WDEN_RSV_MASK            (0xFFFEu)
#define CSL_WDT_WDEN_RSV_SHIFT           (0x0001u)
#define CSL_WDT_WDEN_RSV_RESETVAL        (0x0000u)

#define CSL_WDT_WDEN_EN_MASK             (0x0001u)
#define CSL_WDT_WDEN_EN_SHIFT            (0x0000u)
#define CSL_WDT_WDEN_EN_RESETVAL         (0x0000u)
/*----EN Tokens----*/
#define CSL_WDT_WDEN_EN_DISABLE          (0x0000u)
#define CSL_WDT_WDEN_EN_ENABLE           (0x0001u)

#define CSL_WDT_WDEN_RESETVAL            (0x0000u)

/* WDPSLR */

#define CSL_WDT_WDPSLR_PSLOK_MASK        (0xFFFFu)
#define CSL_WDT_WDPSLR_PSLOK_SHIFT       (0x0000u)
#define CSL_WDT_WDPSLR_PSLOK_RESETVAL    (0x0000u)

#define CSL_WDT_WDPSLR_RESETVAL          (0x0000u)

/* WDPS */

#define CSL_WDT_WDPS_PS_MASK             (0xFFFFu)
#define CSL_WDT_WDPS_PS_SHIFT            (0x0000u)
#define CSL_WDT_WDPS_PS_RESETVAL         (0x0000u)

#define CSL_WDT_WDPS_RESETVAL            (0x0000u)

#endif
