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
* file: cslr_ldo_1.h
*
* Brief: This file contains the Register Description for ldo
*
*********************************************************************/
#ifndef _CSLR_LDO_1_H_
#define _CSLR_LDO_1_H_

#include <cslr.h>

#include <tistdtypes.h>


/* Minimum unit = 2 bytes */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint16 RSVD0[4];
    volatile Uint16 LDOCTRL;
} CSL_LdoRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* LDOCTRL */


#define CSL_LDO_LDOCTRL_DSPLDOCNTL_MASK  (0x0002u)
#define CSL_LDO_LDOCTRL_DSPLDOCNTL_SHIFT (0x0001u)
#define CSL_LDO_LDOCTRL_DSPLDOCNTL_RESETVAL (0x0000u)
/*----DSPLDOCNTL Tokens----*/
#define CSL_LDO_LDOCTRL_DSPLDOCNTL_1PT3V  (0x0000u)
#define CSL_LDO_LDOCTRL_DSPLDOCNTL_1PT05V (0x0001u)

#define CSL_LDO_LDOCTRL_USBLDOEN_MASK    (0x0001u)
#define CSL_LDO_LDOCTRL_USBLDOEN_SHIFT   (0x0000u)
#define CSL_LDO_LDOCTRL_USBLDOEN_RESETVAL (0x0000u)
/*----USBLDOEN Tokens----*/
#define CSL_LDO_LDOCTRL_USBLDOEN_DISABLED (0x0000u)
#define CSL_LDO_LDOCTRL_USBLDOEN_ENABLED (0x0001u)

#define CSL_LDO_LDOCTRL_RESETVAL         (0x0000u)

#endif
