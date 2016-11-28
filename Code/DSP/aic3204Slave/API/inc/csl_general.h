/* ============================================================================
 * Copyright (c) 2008-2016 Texas Instruments Incorporated.
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


/** @file csl_general.h
 *
 *  @brief CSL general header file
 *
 *  This file contains the general CSL macros or definitions that are required
 *  to enable few functionalities specific to the chip revision. This file is
 *  included in all the cslr files. All the CSL applications should include
 *  this file.
 *
 *  Path: \(CSLPATH)\ inc
 */

/* ============================================================================
 * Revision History
 * ================
 * 07-Jan-2009 Created
 * 28-Apr-2010 Added new macro definitions
 * 30-Jun-2010 Added new macro definitions for platforms
 * 13-Aug-2010 CSL v2.10 release
 * 06-Jul-2011 CSL v2.50 release
 * 20-Jun-2012 Removed VC5504/05 chip versions and added C5517 chip version
 * 13-Sep-2012 CSL v3.00 release
 * 20-Dec-2012 CSL v3.01 release
 * 23-Feb-2016 CSL v3.05 release
 * 04-Apr-2016 CSL v3.06 release
 * ============================================================================
 */

#ifndef _CSL_GENERAL_H_
#define _CSL_GENERAL_H_

#ifdef __cplusplus
extern "C" {
#endif

/*
 ******************************************************
 * CAUTION: DEFINE EITHER THE MACROS IN PART1 OR PART2.
 * DO NOT DEFINE MACROS IN BOTH PARTS.
 ******************************************************
 */

/** ***************************************************************************
 * --------------------------------------------------
 * PART1: CHIP VERSION MACRO DEFINITION FOR PG2.1 CSL
 * --------------------------------------------------
 *
 * Below macros are used to enable the source code specific to chip version
 * TMS320C5517.
 *
 * 'CHIP_C5517' indicates TMS320C5517 DSP.
 *
 * Defining the macro below will enable the code for the DSP TMS320C5517.
 */

/* TMS320C5517 */
//#define CHIP_C5517


/******************************* END OF PART1 *******************************/


/** ***************************************************************************
 * --------------------------------------------------
 * PART2: CHIP VERSION MACRO DEFINITION FOR PG2.0 CSL
 * --------------------------------------------------
 *
 * Below macros are used to enable the source code specific to chip versions
 * TMS320C5505, TMS320C5515, TMS320C5504, and TMS320C5514.
 * Design revision(DesignRev) of the DIE ID regsiter(0x1C43 & 0x1C44) will have
 * the value '5' for this chip set.
 *
 * 'CHIP_C5505_C5515' indicates TMS320C5505 and TMS320C5515.
 * 'CHIP_C5504_C5514' indicates TMS320C5504 and TMS320C5514.
 *
 * DSPs TMS320C5505 and TMS320C5515 are similar but certain LDOs not bonded out
 * for TMS320C5505 DSP.
 * DSPs TMS320C5504 and TMS320C5514 are similar but certain LDOs not bonded out
 * for TMS320C5504 DSP.
 *
 * DSPs TMS320C55x5 and TMS320C55x4 are having the same peripherals but
 * they differ in the internal memory available. 'x' stands for 0 or 1.
 *
 * Defining any of the below macros will enable the code for all the DSPs
 * TMS320C5504, TMS320C5505, TMS320C5514 and TMS320C5515.
 * Current CSL software does not have the code that is specific to TMS320C5504
 * and TMS320C5514 DSPs.
 */

#ifndef CHIP_C5517

/* TMS320C5505 and TMS320C5515 */
#define CHIP_C5505_C5515

/** TMS320C5504 and TMS320C5514 */
//#define CHIP_C5504_C5514

#if ((!defined(CHIP_C5505_C5515))&&(!defined(CHIP_C5504_C5514)))

/* TMS320C5535 or TMS320C5545 */
#define CHIP_C5535

#if (!defined(CHIP_C5535))
#define CHIP_C5545
#endif
#endif

#endif

/******************************* END OF PART2 *******************************/


/** ***************************************************************************
 * -----------------------------------------------------------
 * PART3: EVM VERSION MACRO DEFINITION FOR PG2.0 and PG2.1 CSL
 * -----------------------------------------------------------
 *
 * Below macros are used to enable the source code specific to EVM versions
 */

#if (defined(CHIP_C5517))
/** Macro to define platform as C5517 */
#define C5517_EVM

#else // (!defined(CHIP_C5517))
#if (defined(CHIP_C5505_C5515)||defined(CHIP_C5504_C5514))
/** Macro to define platform as C5515 */
//#define C5515_EVM

#if (!(defined(C5515_EVM)))
/** Macro to define platform as C5515 eZdsp */
#define C5515_EZDSP

#endif // !(defined(C5515_EVM))
#else // (!(defined(CHIP_C5517)||defined(CHIP_C5505_C5515)||(defined(CHIP_C5504_C5514))

#if (defined(CHIP_C5535))
/** Macro to define platform as C5535 eZdsp */
#define C5535_EZDSP
#endif

#if (!defined(C5535_EZDSP))
/** Macro to define platform as C5545 BoosterPack */
#define C5545_BSTPCK
#endif // !(defined(C5535_EZDSP))
#endif // ((defined(CHIP_C5505_C5515))||(defined(CHIP_C5504_C5514)))

#endif // (defined(CHIP_C5517))
/******************************* END OF PART3 *******************************/

#ifdef __cplusplus
}
#endif

#endif    // _CSL_GENERAL_H_

