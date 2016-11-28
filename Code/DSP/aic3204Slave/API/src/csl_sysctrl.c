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


/** @file csl_sysctrl.c
 *
 *  @brief System functional layer API defenition file
 *
 *  Path: \(CSLPATH)/src
 */

/* ============================================================================
 * Revision History
 * ================
 * 08-Nov-2012 Added System control for CSL.
 * 20-Dec-2012 CSL v3.01 release
 * ============================================================================
 */

#include "cslr_sysctrl.h"
#include "csl_sysctrl.h"

Uint16 PG4_flag;
Uint16 PG3_flag;
Uint16 PG1_flag;

/**
 * \brief API to reset the peripherals for a particular clock gate
 *
 * \param flag [in] flag to indicate the clock gate
 *
 * \return Error Status
 */
CSL_Status SYS_peripheralReset(CSL_SysPGFlags flag)
{
	ioport volatile CSL_SysRegs		*sysRegs;

	sysRegs = (CSL_SysRegs *)CSL_SYSCTRL_REGS;
	switch(flag)
	{
		case CSL_SYS_PG4:
			if(PG4_flag == 0)
			{
				CSL_FINS(sysRegs->PRCR, SYS_PRCR_PG4_RST, CSL_SYS_PRCR_PG4_RST_RST);
				PG4_flag = 1;
			}
			else
				return(CSL_SOK);
			break;
		case CSL_SYS_PG3:
			if(PG3_flag == 0)
			{
				CSL_FINS(sysRegs->PRCR, SYS_PRCR_PG3_RST, CSL_SYS_PRCR_PG3_RST_RST);
				PG3_flag = 1;
			}
			else
				return(CSL_SOK);
			break;
		case CSL_SYS_PG1:
			if(PG1_flag == 0)
			{
				CSL_FINS(sysRegs->PRCR, SYS_PRCR_PG1_RST, CSL_SYS_PRCR_PG1_RST_RST);
				PG1_flag = 1;
			}
			else
				return(CSL_SOK);
			break;
	}

	return (CSL_ESYS_INVPARAMS);
}

/**
 * \brief API to configure EBSR register
 *
 * \param mode      [IN] Mode to be configured
 * \param modeValue [IN] Mode Value to be set
 *
 * \return Error Status
 */
CSL_Status SYS_setEBSR (CSL_SysEbsrMode mode, Int16 modeValue)
{
	ioport volatile CSL_SysRegs *sysRegs;
	CSL_Status                  status;

	sysRegs = (CSL_SysRegs *)CSL_SYSCTRL_REGS;
	status  = CSL_ESYS_INVPARAMS;

	switch (mode)
	{
		case CSL_EBSR_FIELD_PPMODE:
			if ((modeValue >= CSL_EBSR_PPMODE_0) &&
			    (modeValue < CSL_EBSR_PPMODE_MAX))
			{
				CSL_FINS(sysRegs->EBSR, SYS_EBSR_PPMODE, modeValue);
				status  = CSL_SOK;
			}
			break;

		case CSL_EBSR_FIELD_SP1MODE:
			if ((modeValue >= CSL_EBSR_SP1MODE_0) &&
			    (modeValue < CSL_EBSR_SP1MODE_MAX))
			{
				CSL_FINS(sysRegs->EBSR, SYS_EBSR_SP1MODE, modeValue);
				status  = CSL_SOK;
			}
			break;

		case CSL_EBSR_FIELD_SP0MODE:
			if ((modeValue >= CSL_EBSR_SP0MODE_0) &&
			    (modeValue < CSL_EBSR_SP0MODE_MAX))
			{
				CSL_FINS(sysRegs->EBSR, SYS_EBSR_SP0MODE, modeValue);
				status  = CSL_SOK;
			}
			break;

		case CSL_EBSR_FIELD_A20MODE:
			if ((modeValue>=CSL_EBSR_A_MODE_0) &&
			    (modeValue < CSL_EBSR_A_MODE_MAX))
			{
				CSL_FINS(sysRegs->EBSR, SYS_EBSR_A20_MODE, modeValue);
				status  = CSL_SOK;
			}
			break;

		case CSL_EBSR_FIELD_A19MODE:
			if ((modeValue >= CSL_EBSR_A_MODE_0) &&
			    (modeValue < CSL_EBSR_A_MODE_MAX))
			{
				CSL_FINS(sysRegs->EBSR, SYS_EBSR_A19_MODE, modeValue);
				status  = CSL_SOK;
			}
			break;

		case CSL_EBSR_FIELD_A18MODE:
			if ((modeValue >= CSL_EBSR_A_MODE_0) &&
			    (modeValue < CSL_EBSR_A_MODE_MAX))
			{
				CSL_FINS(sysRegs->EBSR, SYS_EBSR_A18_MODE, modeValue);
				status  = CSL_SOK;
			}
			break;

		case CSL_EBSR_FIELD_A17MODE:
			if ((modeValue >= CSL_EBSR_A_MODE_0) &&
			    (modeValue < CSL_EBSR_A_MODE_MAX))
			{
				CSL_FINS(sysRegs->EBSR, SYS_EBSR_A17_MODE, modeValue);
				status  = CSL_SOK;
			}
			break;

		case CSL_EBSR_FIELD_A16MODE:
			if ((modeValue >= CSL_EBSR_A_MODE_0) &&
			    (modeValue < CSL_EBSR_A_MODE_MAX))
			{
				CSL_FINS(sysRegs->EBSR, SYS_EBSR_A16_MODE, modeValue);
				status  = CSL_SOK;
			}
			break;

		case CSL_EBSR_FIELD_A15MODE:
			if ((modeValue >= CSL_EBSR_A_MODE_0) &&
			    (modeValue < CSL_EBSR_A_MODE_MAX))
			{
				CSL_FINS(sysRegs->EBSR, SYS_EBSR_A15_MODE, modeValue);
				status  = CSL_SOK;
			}
			break;

		case CSL_EBSR_FIELD_MAX:
		default:
			status  = CSL_ESYS_INVPARAMS;
			break;
	}

	return (status);
}


/**
 * \brief API to set DSP_LDO_V bit in LDOCNTL register to set the DSP LDO
 * voltage
 *
 * \param voltage [in] DSP LDO Voltage value
 *
 * \return None
 */
void SYS_set_DSP_LDO_voltage(CSL_SysDspLdoVoltage voltage)
{
	ioport volatile CSL_LdoRegs *ldoRegs;

	ldoRegs = (CSL_LdoRegs *)CSL_LDO_REGS;

	if (CSL_DSP_LDO_1pt05_VOLTAGE == voltage)
	{
    	ldoRegs->LDOCTRL |= 0x0002; /* Setting DSP_LDOO as 1.05V */
	}
	else
	{
	    ldoRegs->LDOCTRL &= 0xFFFD; /* Setting DSP_LDOO as 1.30V */
	}
}
