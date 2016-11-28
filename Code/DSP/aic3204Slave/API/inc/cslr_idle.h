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
* file: cslr_idle_1.h
*
* Brief: This file contains the Register Description for idle
*
*********************************************************************/
#ifndef _CSLR_IDLE_1_H_
#define _CSLR_IDLE_1_H_

#include <cslr.h>

#include <tistdtypes.h>


/* Minimum unit = 2 bytes */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint16 RSVD0;
    volatile Uint16 ICR;
    volatile Uint16 ISR;
} CSL_IdleRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* ICR */


#define CSL_IDLE_ICR_HWAI_MASK           (0x0200u)
#define CSL_IDLE_ICR_HWAI_SHIFT          (0x0009u)
#define CSL_IDLE_ICR_HWAI_RESETVAL       (0x0000u)
/*----HWAI Tokens----*/
#define CSL_IDLE_ICR_HWAI_ACTIVE         (0x0000u)
#define CSL_IDLE_ICR_HWAI_IDLE           (0x0001u)

#define CSL_IDLE_ICR_IPORTI_MASK         (0x0100u)
#define CSL_IDLE_ICR_IPORTI_SHIFT        (0x0008u)
#define CSL_IDLE_ICR_IPORTI_RESETVAL     (0x0000u)
/*----IPORTI Tokens----*/
#define CSL_IDLE_ICR_IPORTI_ACTIVE       (0x0000u)
#define CSL_IDLE_ICR_IPORTI_IDLE         (0x0001u)

#define CSL_IDLE_ICR_MPORTI_MASK         (0x0080u)
#define CSL_IDLE_ICR_MPORTI_SHIFT        (0x0007u)
#define CSL_IDLE_ICR_MPORTI_RESETVAL     (0x0000u)
/*----MPORTI Tokens----*/
#define CSL_IDLE_ICR_MPORTI_ACTIVE       (0x0000u)
#define CSL_IDLE_ICR_MPORTI_IDLE         (0x0001u)

#define CSL_IDLE_ICR_XPORTI_MASK         (0x0040u)
#define CSL_IDLE_ICR_XPORTI_SHIFT        (0x0006u)
#define CSL_IDLE_ICR_XPORTI_RESETVAL     (0x0000u)
/*----XPORTI Tokens----*/
#define CSL_IDLE_ICR_XPORTI_ACTIVE       (0x0000u)
#define CSL_IDLE_ICR_XPORTI_IDLE         (0x0001u)

#define CSL_IDLE_ICR_DPORTI_MASK         (0x0020u)
#define CSL_IDLE_ICR_DPORTI_SHIFT        (0x0005u)
#define CSL_IDLE_ICR_DPORTI_RESETVAL     (0x0000u)
/*----DPORTI Tokens----*/
#define CSL_IDLE_ICR_DPORTI_ACTIVE       (0x0000u)
#define CSL_IDLE_ICR_DPORTI_IDLE         (0x0001u)


#define CSL_IDLE_ICR_CPUI_MASK           (0x0001u)
#define CSL_IDLE_ICR_CPUI_SHIFT          (0x0000u)
#define CSL_IDLE_ICR_CPUI_RESETVAL       (0x0000u)
/*----CPUI Tokens----*/
#define CSL_IDLE_ICR_CPUI_ACTIVE         (0x0000u)
#define CSL_IDLE_ICR_CPUI_IDLE           (0x0001u)

#define CSL_IDLE_ICR_RESETVAL            (0x0000u)

/* ISR */


#define CSL_IDLE_ISR_HWAIS_MASK          (0x0200u)
#define CSL_IDLE_ISR_HWAIS_SHIFT         (0x0009u)
#define CSL_IDLE_ISR_HWAIS_RESETVAL      (0x0000u)
/*----HWAIS Tokens----*/
#define CSL_IDLE_ISR_HWAIS_ACTIVE        (0x0000u)
#define CSL_IDLE_ISR_HWAIS_DISABLE       (0x0001u)

#define CSL_IDLE_ISR_IPORTIS_MASK        (0x0100u)
#define CSL_IDLE_ISR_IPORTIS_SHIFT       (0x0008u)
#define CSL_IDLE_ISR_IPORTIS_RESETVAL    (0x0000u)
/*----IPORTIS Tokens----*/
#define CSL_IDLE_ISR_IPORTIS_ACTIVE      (0x0000u)
#define CSL_IDLE_ISR_IPORTIS_DISABLE     (0x0001u)

#define CSL_IDLE_ISR_MPORTIS_MASK        (0x0080u)
#define CSL_IDLE_ISR_MPORTIS_SHIFT       (0x0007u)
#define CSL_IDLE_ISR_MPORTIS_RESETVAL    (0x0000u)
/*----MPORTIS Tokens----*/
#define CSL_IDLE_ISR_MPORTIS_ACTIVE      (0x0000u)
#define CSL_IDLE_ISR_MPORTIS_DISABLE     (0x0001u)

#define CSL_IDLE_ISR_XPORTIS_MASK        (0x0040u)
#define CSL_IDLE_ISR_XPORTIS_SHIFT       (0x0006u)
#define CSL_IDLE_ISR_XPORTIS_RESETVAL    (0x0000u)
/*----XPORTIS Tokens----*/
#define CSL_IDLE_ISR_XPORTIS_ACTIVE      (0x0000u)
#define CSL_IDLE_ISR_XPORTIS_DISABLE     (0x0001u)

#define CSL_IDLE_ISR_DPORTIS_MASK        (0x0020u)
#define CSL_IDLE_ISR_DPORTIS_SHIFT       (0x0005u)
#define CSL_IDLE_ISR_DPORTIS_RESETVAL    (0x0000u)
/*----DPORTIS Tokens----*/
#define CSL_IDLE_ISR_DPORTIS_ACTIVE      (0x0000u)
#define CSL_IDLE_ISR_DPORTIS_DISABLE     (0x0001u)


#define CSL_IDLE_ISR_CPUIS_MASK          (0x0001u)
#define CSL_IDLE_ISR_CPUIS_SHIFT         (0x0000u)
#define CSL_IDLE_ISR_CPUIS_RESETVAL      (0x0000u)
/*----CPUIS Tokens----*/
#define CSL_IDLE_ISR_CPUIS_ACTIVE        (0x0000u)
#define CSL_IDLE_ISR_CPUIS_DISABLE       (0x0001u)

#define CSL_IDLE_ISR_RESETVAL            (0x0000u)

#endif
