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


/** @file csl_sysctrl.h
 *
 *  @brief Functional layer API header file for System CSL
 *
 *  Path: \(CSLPATH)/inc
 */

/* ============================================================================
 * Revision History
 * ================
 * 08-Nov-2012 Added for CSL.
 * 20-Dec-2012 CSL v3.01 release
 * ============================================================================
 */
/** @defgroup CSL_SYSCTRL_API SYSCTRL
 *
 * @section Introduction
 *
 * @subsection xxx Overview
 */


#ifndef _CSL_SYSCTRL_H_
#define _CSL_SYSCTRL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <cslr.h>
#include <csl_general.h>
#include <soc.h>
#include <cslr_sysctrl.h>
#include <tistdtypes.h>
#include <csl_types.h>
#include <csl_error.h>

//#define CSL_SYS_RST_PG4_FLAG
//#define CSL_SYS_RST_PG3_FLAG
//#define CSL_SYS_RST_PG1_FLAG

/**
 * \brief Pin Muxing(Modes) Fields for EBSR setting.
 */
typedef enum
{
    CSL_EBSR_FIELD_PPMODE,
    CSL_EBSR_FIELD_SP1MODE,
    CSL_EBSR_FIELD_SP0MODE,
    CSL_EBSR_FIELD_A20MODE,
    CSL_EBSR_FIELD_A19MODE,
    CSL_EBSR_FIELD_A18MODE,
    CSL_EBSR_FIELD_A17MODE,
    CSL_EBSR_FIELD_A16MODE,
    CSL_EBSR_FIELD_A15MODE,
    CSL_EBSR_FIELD_MAX
} CSL_SysEbsrMode;

/**
 * \brief PPMODE values used to configure EBSR registers.
 */
typedef enum
{
    CSL_EBSR_PPMODE_0,
    CSL_EBSR_PPMODE_1,
    CSL_EBSR_PPMODE_2,
    CSL_EBSR_PPMODE_3,
    CSL_EBSR_PPMODE_4,
    CSL_EBSR_PPMODE_5,
    CSL_EBSR_PPMODE_6,
    CSL_EBSR_PPMODE_MAX
} CSL_EBSR_PPMODE_VALUE;

/**
 * \brief SP1MODE values used to configure EBSR registers.
 */
typedef enum
{
    CSL_EBSR_SP1MODE_0,
    CSL_EBSR_SP1MODE_1,
    CSL_EBSR_SP1MODE_2,
    CSL_EBSR_SP1MODE_3,
    CSL_EBSR_SP1MODE_MAX
} CSL_EBSR_SP1MODE_VALUE;

/**
 * \brief SP0MODE values used to configure EBSR registers.
 */
typedef enum
{
    CSL_EBSR_SP0MODE_0,
    CSL_EBSR_SP0MODE_1,
    CSL_EBSR_SP0MODE_2,
    CSL_EBSR_SP0MODE_3,
    CSL_EBSR_SP0MODE_MAX
} CSL_EBSR_SP0MODE_VALUE;

/**
 * \brief A15 to A20 MODE values used to configure EBSR registers.
 */
typedef enum
{
    CSL_EBSR_A_MODE_0,
    CSL_EBSR_A_MODE_1,
    CSL_EBSR_A_MODE_MAX
} CSL_EBSR_A_MODE_VALUE;

/**
 * \brief Peripheral reset PG number.
 *
 * Enumeration for PG flags.
 */
typedef enum
{
    CSL_SYS_PG4,
	CSL_SYS_PG3,
	CSL_SYS_PG1
} CSL_SysPGFlags;

/**
 * \brief DSP LDO Voltage values
 */
typedef enum
{
	CSL_DSP_LDO_1pt05_VOLTAGE,
	CSL_DSP_LDO_1pt30_VOLTAGE
} CSL_SysDspLdoVoltage;

/**
 * \brief API to reset the peripherals for a particular clock gate
 *
 * \param flag [in] flag to indicate the clock gate
 *
 * \return Error Status
 */
CSL_Status SYS_peripheralReset(CSL_SysPGFlags flag);

/**
 * \brief API to set EBSR register
 *
 * \param instance [in] Peripheral instance number
 *
 * \return Error Status
 */
CSL_Status SYS_setEBSR (CSL_SysEbsrMode mode, Int16 modeValue);

/**
 * \brief API to set DSP_LDO_V bit in LDOCNTL register to set the DSP LDO
 * voltage
 *
 * \param voltage [in] DSP LDO Voltage value
 *
 * \return None
 */
void SYS_set_DSP_LDO_voltage(CSL_SysDspLdoVoltage voltage);

#ifdef __cplusplus
}
#endif

#endif /* _CSL_SYSCTRL_H_ */
