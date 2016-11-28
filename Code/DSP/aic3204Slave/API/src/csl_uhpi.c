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


/** @file csl_uhpi.c
 *
 *  @brief UHPI functional layer API header file
 *
 *  Path: \(CSLPATH)\src
 */

/* ============================================================================
 * Revision History
 * ================
 * 06-Dec-2008 Created
 * 13-Aug-2010 CSL v2.10 release
 * 06-Jul-2011 CSL v2.50 release
 * 13-Sep-2012 CSL v3.00 release
 * 20-Dec-2012 CSL v3.01 release
 * ============================================================================
 */

#include "csl_uhpi.h"
#include "csl_uhpiAux.h"
#include "csl_sysctrl.h"
/** ============================================================================
 *   @n@b UHPI_open
 *
 *   @b Description
 *   @n Open the handle to the UHPI CSL module
 *
 *   @b Arguments
 *   @verbatim
            instance      UHPI Hardware instance number
            UhpiObj		  UHPI CSL object
            CSL_Status	  CSL status
     @endverbatim
  *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Returned for success
 *   @li                    CSL_ESYS_INVPARAMS - Invalid parameter
 							CSL_ESYS_BADHANDLE - Bad handle passed
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Initializes UHPI module
 *
 *   @b Modifies
 *   @n UHPI Object structure
 *
 *   @b Example
 *   @verbatim
            CSL_UhpiHandle hUhpi;
            hUhpi = UHPI_open(CSL_UhpiInsId	instance,
									 CSL_UhpiObj		*UhpiObj,
		  						     CSL_Status 		*status)
     @endverbatim
 *  ============================================================================
 */
CSL_UhpiHandle UHPI_open(CSL_UhpiInsId	instance,
					CSL_UhpiObj		*UhpiObj,
		  			CSL_Status 		*status)
{
	CSL_UhpiHandle hUhpi;
	///ioport volatile CSL_SysPGFlags	*sysFlags;
	*status = CSL_SOK;
	hUhpi = NULL;

	if(NULL == UhpiObj)
	{
		*status = CSL_ESYS_BADHANDLE;
		return (hUhpi);
	}

 	if((instance < CSL_UHPI_INST_0) || (instance >= CSL_UHPI_INST_INVALID))
	{
		*status = CSL_ESYS_INVPARAMS;
		return (hUhpi);
	}

  	hUhpi = UhpiObj;

	switch (instance)
	{
		case CSL_UHPI_INST_0:
			hUhpi->insId	 	= CSL_UHPI_INST_0;
			hUhpi->Regs			= CSL_UHPI_REGS;
 			hUhpi->sysRegs 		= CSL_SYSCTRL_REGS;
    			break;
		default:
			*status = CSL_ESYS_INVPARAMS;
	}

	/* EBSR setting */
//	CSL_FINST(hUhpi->sysRegs->EBSR, SYS_EBSR_PPMODE, MODE0);

	/* Reset HPI*/
	//CSL_SYSCTRL_REGS->PSRCR = 0x000A;
	SYS_peripheralReset(CSL_SYS_PG4);

	/* Clock gating setting - enable clock */
	//CSL_FINST(hUhpi->sysRegs->PCGCR2, SYS_PCGCR2_HPICG, ACTIVE);


	return (hUhpi);
}

/** ============================================================================
 *   @n@b UHPI_Config
 *
 *   @b Description
 *   @n Configures the UHPI CSL module
 *
 *   @b Arguments
 *   @verbatim
            instanceNum      UHPI Hardware instance number
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Returned for success
 *   @li                    CSL_ESYS_INVPARAMS - Invalid parameter
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Initializes UHPI module
 *
 *   @b Modifies
 *   @n UHPI Object structure
 *
 *   @b Example
 *   @verbatim
            CSL_Status    status;
            status = UHPI_config(hUhpi,&Uhpisetup);
     @endverbatim
 *  ============================================================================
 */
CSL_Status UHPI_Config(CSL_UhpiHandle hUhpi, CSL_UhpiSetup *UhpiSetup)
{
	CSL_Status         status;
	volatile Uint16    looper;

	status = CSL_SOK;

	if( NULL == hUhpi )
	{
		return CSL_ESYS_BADHANDLE;
	}
	if( NULL == UhpiSetup)
	{
	 	return CSL_ESYS_INVPARAMS;
    }

	/* Configuration to UHPI module will start here */

	/* Enable the free operation even in emulation suspend mode(can be enhanced to have control over this) */
	//CSL_FINST(hUhpi->Regs->PWREMU_MGMT, UHPI_PWREMU_MGMT_FREE, ENABLE);
	//CSL_FINST(hUhpi->Regs->PWREMU_MGMT, UHPI_PWREMU_MGMT_SOFT, DISABLE);


	switch(UhpiSetup->op_mode) //Only one mode is selected in Phoenix
	{
	 case CSL_UHPI_8BIT_MUXED_DUAL_HALFWORD_CYCLES:
	 	  return CSL_ESYS_INVPARAMS;

	 case CSL_UHPI_16BIT_MUXED_SINGLE_FULLWORD_CYCLES:
		  //CSL_FINST(hUhpi->sysRegs->HPICR, SYSCTRL_HPICR_NMUX, DISABLE);
		  break;

 	 case CSL_UHPI_16BIT_MUXED_DUAL_HALFWORD_CYCLES:
          return CSL_ESYS_INVPARAMS;

	 case CSL_UHPI_16BIT_NONMUXED:
          return CSL_ESYS_INVPARAMS;

	 case CSL_UHPI_32BIT_NONMUXED:
		  return CSL_ESYS_INVPARAMS;

	 case CSL_UHPI_32BIT_MUXED:
		  return CSL_ESYS_INVPARAMS;

	 default:
	 	  return CSL_ESYS_INVPARAMS;
	}

	switch(UhpiSetup->gpio_intr)
	{
	 case CSL_UHPI_GPIO_INTERRUPT_ENABLE:
	 	CSL_FINST(hUhpi->Regs->GPIO_ENL, UHPI_GPIO_ENL_GPIO_EN2, ENABLE); //Inversion bit ignored in CSL
		CSL_FINST(hUhpi->Regs->GPINT_CTRLL, UHPI_GPINT_CTRLL_GPINT_EN2, ENABLE);
	    break;
	 case CSL_UHPI_GPIO_INTERRUPT_DISABLE:
	 	CSL_FINST(hUhpi->Regs->GPIO_ENL, UHPI_GPIO_ENL_GPIO_EN2, DISABLE); //Inversion bit ignored in CSL
		CSL_FINST(hUhpi->Regs->GPINT_CTRLL, UHPI_GPINT_CTRLL_GPINT_EN2, DISABLE);
	 	break;
	 default: return CSL_ESYS_INVPARAMS;
	}


	return(status);
}

/** ============================================================================
 *   @n@b UHPI_Close
 *
 *   @b Description
 *   @n Close the handle to UHPI and stops the clock to UHPI
 *
 *   @b Arguments
 *   @verbatim
            None
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Returned for success
 *							CSL_ESYS_BADHANDLE - Bad handle passed
 *
 *   <b> Pre Condition </b>
 *   @n  UHPI_open should be called successfully.
 *   @n  None
 *
 *   <b> Post Condition </b>
 *
 *
 *   @b Example
 *   @verbatim
            Status = UHPI_Close(hUhpi);
			if( Status != CSL_SOK )
			{
			 printf("UHPI_Close is failed\r\n");
			}
     @endverbatim
 *  ============================================================================
 */
CSL_Status UHPI_Close( CSL_UhpiHandle hUhpi )
{

	if( NULL == hUhpi )
	{
		return CSL_ESYS_BADHANDLE;
	}

	/* Reset HPI*/
//	hUhpi->sysRegs->PSRCR = 0x000A;
//	CSL_FINST(hUhpi->sysRegs->PRCR, SYS_PRCR_PG4_RST, RST);

	/* Clock gating setting - Disable clock */
//	CSL_FINST(hUhpi->sysRegs->PCGCR2, SYS_PCGCR2_HPICG, DISABLED);


	/* Close the handle */
	hUhpi = NULL;

	return(CSL_SOK);
}
