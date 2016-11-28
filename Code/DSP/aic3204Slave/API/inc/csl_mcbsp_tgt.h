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


/** @file csl_mcbsp_tgt.h
 *
 *
 *  Path: \(CSLPATH)\ inc
 */

/* ============================================================================
 * Revision History
 * ================
 * 14-Oct-2010 Created
 * 06-Jul-2011 CSL v2.50 release
 * 13-Sep-2012 CSL v3.00 release
 * 20-Dec-2012 CSL v3.01 release
 * ============================================================================
 */

#include "cslr.h"
#include "csl_error.h"
#include "csl_types.h"
#include "cslr_mcbsp.h"
#include "soc.h"
#include "csl_intc.h"
#include "csl_general.h"


/****************************************\
* MCBSP Targets global macro declarations
\****************************************/

                                     // GPIO DATA in 16 bit format
                                     // gpio[9:6] is connected to Mcbsp targer
                                     // ---- --++ ++-- ----
#define MCBSP_TGT_NO_LB       0x0000 // 0000 0000 0000 0000
#define MCBSP_TGT_LB_MODE0    0x0040 // 0000 0000 0100 0000
#define MCBSP_TGT_LB_MODE1    0x00C0 // 0000 0000 1100 0000
#define MCBSP_TGT_LB_MODE2    0x0140 // 0000 0001 0100 0000
#define MCBSP_TGT_LB_MODE3    0x01C0 // 0000 0001 1100 0000
#define MCBSP_TGT_LB_MODE4    0x0240 // 0000 0010 0100 0000
#define MCBSP_TGT_LB_MODE5    0x02C0 // 0000 0010 1100 0000
#define MCBSP_TGT_LB_MODE6    0x0340 // 0000 0011 0100 0000
#define MCBSP_TGT_LB_MODE7    0x03C0 // 0000 0011 1100 0000



