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


/** @file csl_emif.c
 *
 *  @brief EMIF functional layer API source file
 *
 *  Path: \(CSLPATH)\src\emif\src
 */

/* ============================================================================
 * Revision History
 * ================
 * 25-Feb-2013 Created
 * ============================================================================
 */

#include <csl_emif.h>
#include "csl_sysctrl.h"
#include "csl_pll.h"

/** ============================================================================
 *   @n@b EMIF_init
 *
 *   @b Description
 *   @n This is the initialization function for the emif CSL.
 *      It populates emif object structure information. This API should
 *      be called before calling any other emif CSL APIs.
 *
 *   @b Arguments
 *   @verbatim
            emifObj       Pointer to emif object structure
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Nand init is successful
 *   @li                    CSL_ESYS_INVPARAMS - Invalid parameter
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  EMIF object structure is populated
 *
 *   @b Modifies
 *   @n EMIF object structure
 *
 *   @b Example
 *   @verbatim
			CSL_EmifObj    emifObj;
			CSL_Status     status;

			status = EMIF_init(&emifObj);
     @endverbatim
 *  ============================================================================
 */
CSL_Status EMIF_init(CSL_EmifObj    *emifObj)
{
    CSL_Status         result;
    volatile Uint16    looper;

	result = CSL_ESYS_INVPARAMS;

    if(emifObj != NULL)
    {
        emifObj->sysCtrlRegs = CSL_SYSCTRL_REGS;

		/* Reset EMIF module */
		CSL_FINS(emifObj->sysCtrlRegs->PSRCR, SYS_PSRCR_COUNT,
				 CSL_EMIF_RESET_COUNT_VAL);

		/* reset Emif Module */
		SYS_peripheralReset(CSL_SYS_PG1);

		/* Give some delay for the device to reset */
		for(looper = 0; looper < CSL_EMIF_DELAY; looper++){;}

		/* Enable EMIF module in Idle PCGCR */
		CSL_FINST(emifObj->sysCtrlRegs->PCGCR1, SYS_PCGCR1_EMIFCG, ACTIVE);

		/* Set EMIF access to 16 bit */
		CSL_FINST(emifObj->sysCtrlRegs->ESCR, SYS_ESCR_BYTEMODE, FULL);

		emifObj->regs = CSL_EMIF_REGS;
		result = CSL_SOK;
    }

    return (result);
}

/** ============================================================================
 *   @n@b SDRAM_config
 *
 *   @b Description
 *   @n This API configures the sdram hardware registers.
 *
 *   @b Arguments
 *   @verbatim
            hEmif         Handle to the emif object
            sdramConfig   SDRAM configuration structure
			sdramTimr     SDRAM timer configuration structure
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Nand setup is successful
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *   @li                    CSL_ESYS_INVPARAMS - Invalid config structure
 *
 *   <b> Pre Condition </b>
 *   @n  Emif init should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Configures sdram registers
 *
 *   @b Modifies
 *   @n sdram registers
 *
 *   @b Example
 *   @verbatim
            CSL_EmifObj            emifObj;
            CSL_Status             status;
            CSL_EmifConfig         emifCfg;
            CSL_EmifHandle         hEmif;

            status = EMIF_init(&emifObj);
            hEmif  = &emifObj;
            ...
            ...
            ...
            status = SDRAM_config(hEmif, &sdramConfig, &sdramTimr);
     @endverbatim
 *  ============================================================================
 */
CSL_Status SDRAM_config(CSL_EmifHandle      hEmif,
                        CSL_SdramCfg        *sdramConfig,
                        CSL_SdramTimr       *sdramTimr)
{
    CSL_Status   result;
	Uint32       sysClock;

    result = CSL_SOK;

    if(hEmif != NULL)
	{
        if((sdramConfig != NULL) && (sdramTimr != NULL))
		{
			/* Get the clock value at which CPU is running */
			sysClock = getSysClk();

			/* Maximum clock frequency on the EM_SDCLK pin is limited to 100 MHz,
			   setting the EMIF to operate at half of the CPU clock if CPU clock is >100MHz */
			//if (sysClock >= CSL_CLOCK_100MHz)
			if (sysClock > CSL_CLOCK_100MHz)
			{
				/* Set EMIF clock multiplier value to half rate */
			    CSL_FINS(hEmif->sysCtrlRegs->ECDR, SYS_ECDR_EDIV, CSL_EMIF_ECDR_EDIV_HALFRATE);
			}

	        /* Configuring SDTIMR registers */
			CSL_FINS(hEmif->regs->SDTIMR1, EMIF_SDTIMR1_TRAS,
			         sdramTimr->tRAS);
			CSL_FINS(hEmif->regs->SDTIMR1, EMIF_SDTIMR1_TRC,
			         sdramTimr->tRC);
			CSL_FINS(hEmif->regs->SDTIMR1, EMIF_SDTIMR1_TRRD,
			         sdramTimr->tRRD);
			CSL_FINS(hEmif->regs->SDTIMR2, EMIF_SDTIMR2_TRFC,
			         sdramTimr->tRFC);
			CSL_FINS(hEmif->regs->SDTIMR2, EMIF_SDTIMR2_TRP,
			         sdramTimr->tRP);
			CSL_FINS(hEmif->regs->SDTIMR2, EMIF_SDTIMR2_TRCD,
			         sdramTimr->tRCD);
			CSL_FINS(hEmif->regs->SDTIMR2, EMIF_SDTIMR2_TWR,
			         sdramTimr->tWR);

	        /* Configuring SDSRETR registers */
			CSL_FINS(hEmif->regs->SDSRETR, EMIF_SDSRETR_TXS,
			         sdramTimr->tXS);

	        /* Configuring SDRCR registers */
			CSL_FINS(hEmif->regs->SDRCR, EMIF_SDRCR_REFRATE,
			         sdramTimr->refRate);

	        /* Configuring SDRAM configuration registers */
			CSL_FINS(hEmif->regs->SDCR1, EMIF_SDCR1_NM,
			         sdramConfig->NM);
			CSL_FINS(hEmif->regs->SDCR1, EMIF_SDCR1_BIT_11_9_LOCK,
			         sdramConfig->bit11to9Lock);
			CSL_FINS(hEmif->regs->SDCR1, EMIF_SDCR1_CL,
			         sdramConfig->CasLatency);
			CSL_FINS(hEmif->regs->SDCR1, EMIF_SDCR1_IBANK,
			         sdramConfig->num_ibank);
			CSL_FINS(hEmif->regs->SDCR1, EMIF_SDCR1_EBANK,
			         sdramConfig->ebank);
			CSL_FINS(hEmif->regs->SDCR1, EMIF_SDCR1_PAGESIZE,
			         sdramConfig->pageSize);

			CSL_FINS(hEmif->regs->SDCR2, EMIF_SDCR2_BIT_9_1_LOCK,
			         sdramConfig->bit9to1Lock);
			CSL_FINS(hEmif->regs->SDCR2, EMIF_SDCR2_SR,
			         sdramConfig->selfRefresh);
			CSL_FINS(hEmif->regs->SDCR2, EMIF_SDCR2_PD,
			         sdramConfig->pdMode);
			CSL_FINS(hEmif->regs->SDCR2, EMIF_SDCR2_PDWR,
			         sdramConfig->pdwr);
			CSL_FINS(hEmif->regs->SDCR2, EMIF_SDCR2_PASR,
			         sdramConfig->pasr);
			CSL_FINS(hEmif->regs->SDCR2, EMIF_SDCR2_ROWSIZE,
			         sdramConfig->rowSize);
			CSL_FINS(hEmif->regs->SDCR2, EMIF_SDCR2_IBANK_POS,
			         sdramConfig->ibankPos);
			CSL_FINS(hEmif->regs->SDCR2, EMIF_SDCR2_SDRAM_DRIVE,
			         sdramConfig->sdramDrive);

			/* Enable SDRAM clock */
			CSL_FINS(hEmif->sysCtrlRegs->CCR1, SYS_CCR1_SDCLK_EN,
			         CSL_SYS_CCR1_SDCLK_EN_SDCLKON);
		}
		else
		{
		    result = CSL_ESYS_INVPARAMS;
		}
    }
    else
    {
		result = CSL_ESYS_BADHANDLE;
	}

    return (result);
}

/** ============================================================================
 *   @n@b SDRAM_enablePowerDownMode
 *
 *   @b Description
 *   @n This API enables power dowm mode for SDRAM.
 *
 *   @b Arguments
 *   @verbatim
 *          hEmif         Handle to the emif object
 *   @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - SDRAM power down mode set successfully
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *
 *   <b> Pre Condition </b>
 *   @n  Emif init and SDRAM configurations should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  SDRAM is in powerdown mode
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
            CSL_EmifObj            emifObj;
            CSL_Status             status;
            CSL_EmifConfig         emifCfg;
            CSL_EmifHandle         hEmif;

            status = EMIF_init(&emifObj);
            hEmif  = &emifObj;
            status = SDRAM_config(hEmif, &sdramConfig, &sdramTimr);
            ...
            ...
            ...
			status = SDRAM_enablePowerDownMode(hEmif);
     @endverbatim
 *  ============================================================================
 */
CSL_Status SDRAM_enablePowerDownMode(CSL_EmifHandle      hEmif)
{
    CSL_Status                result;

    result = CSL_SOK;

    if(hEmif != NULL)
	{
		/* Set EMIF access to byte mode to avoid triggering the SDRAM initialization sequence  */
		CSL_FINST(hEmif->sysCtrlRegs->ESCR, SYS_ESCR_BYTEMODE, UPPER);
		/* Set PD bit in SDCR2 to enable powerdown mode */
		CSL_FINS(hEmif->regs->SDCR2, EMIF_SDCR2_PD, CSL_SDRAM_PD_PWRDN_EN);
		/* Set PDWR bit in SDCR2 to perform refreshes in powerdown mode */
		CSL_FINS(hEmif->regs->SDCR2, EMIF_SDCR2_PDWR, CSL_SDRAM_PDWR_EN);
		/* Set EMIF access to word mode */
		CSL_FINST(hEmif->sysCtrlRegs->ESCR, SYS_ESCR_BYTEMODE, FULL);

    }
    else
    {
		result = CSL_ESYS_BADHANDLE;
	}

    return (result);

}

/** ============================================================================
 *   @n@b SDRAM_disablePowerDownMode
 *
 *   @b Description
 *   @n This API disables power dowm mode for SDRAM.
 *
 *   @b Arguments
 *   @verbatim
 *          hEmif         Handle to the emif object
 *   @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - SDRAM power down mode disabled successfully
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *
 *   <b> Pre Condition </b>
 *   @n  Emif init and SDRAM configurations and SDRAM must be in powerdown mode
 *       should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  SDRAM is out of powerdown mode
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
            CSL_EmifObj            emifObj;
            CSL_Status             status;
            CSL_EmifConfig         emifCfg;
            CSL_EmifHandle         hEmif;

            status = EMIF_init(&emifObj);
            hEmif  = &emifObj;
            status = SDRAM_config(hEmif, &sdramConfig, &sdramTimr);
            ...
            ...
            ...
			status = SDRAM_enablePowerDownMode(hEmif);
			...
			...
            status = SDRAM_disablePowerDownMode(hEmif);
     @endverbatim
 *  ============================================================================
 */
CSL_Status SDRAM_disablePowerDownMode(CSL_EmifHandle      hEmif)
{
    CSL_Status                result;

    result = CSL_SOK;

    if(hEmif != NULL)
	{
		/* Set EMIF access to byte mode to avoid triggering the SDRAM initialization sequence  */
		CSL_FINST(hEmif->sysCtrlRegs->ESCR, SYS_ESCR_BYTEMODE, UPPER);
		/* Reset PD bit in SDCR2 to disable powerdown mode */
		CSL_FINS(hEmif->regs->SDCR2, EMIF_SDCR2_PD, CSL_SDRAM_SDCR2_PD_DEFAULT);
		/* Reset PDWR bit in SDCR2 after powerdown mode is disabled */
		CSL_FINS(hEmif->regs->SDCR2, EMIF_SDCR2_PDWR, CSL_SDRAM_SDCR2_PDWR_DEFAULT);
		/* Set EMIF access to word mode */
		CSL_FINST(hEmif->sysCtrlRegs->ESCR, SYS_ESCR_BYTEMODE, FULL);
    }
    else
    {
		result = CSL_ESYS_BADHANDLE;
	}

    return (result);

}
/** ============================================================================
 *   @n@b SDRAM_enableSelfRefreshMode
 *
 *   @b Description
 *   @n This API enables self refresh mode for SDRAM.
 *
 *   @b Arguments
 *   @verbatim
 *          hEmif         Handle to the emif object
 *   @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - SDRAM self refresh mode enabled successfully
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *
 *   <b> Pre Condition </b>
 *   @n  Emif init and SDRAM configurations and should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  SDRAM is in self refresh mode
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
            CSL_EmifObj            emifObj;
            CSL_Status             status;
            CSL_EmifConfig         emifCfg;
            CSL_EmifHandle         hEmif;

            status = EMIF_init(&emifObj);
            hEmif  = &emifObj;
            status = SDRAM_config(hEmif, &sdramConfig, &sdramTimr);
            ...
            ...
            ...
			status = SDRAM_enableSelfRefreshMode(hEmif);
     @endverbatim
 *  ============================================================================
 */
CSL_Status SDRAM_enableSelfRefreshMode(CSL_EmifHandle      hEmif)
{
    CSL_Status                result;

    result = CSL_SOK;

    if(hEmif != NULL)
	{
		/* Set EMIF access to byte mode to avoid triggering the SDRAM initialization sequence  */
		CSL_FINST(hEmif->sysCtrlRegs->ESCR, SYS_ESCR_BYTEMODE, UPPER);
		/* Set SR bit in SDCR2 to enable self refresh mode */
		CSL_FINS(hEmif->regs->SDCR2, EMIF_SDCR2_SR, CSL_SDRAM_SR_EN);
		/* Set EMIF access to word mode */
		CSL_FINST(hEmif->sysCtrlRegs->ESCR, SYS_ESCR_BYTEMODE, FULL);
    }
    else
    {
		result = CSL_ESYS_BADHANDLE;
	}

    return (result);

}
/** ============================================================================
 *   @n@b SDRAM_disableSelfRefreshMode
 *
 *   @b Description
 *   @n This API disables self refresh mode for SDRAM.
 *
 *   @b Arguments
 *   @verbatim
 *          hEmif         Handle to the emif object
 *   @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - SDRAM self refresh mode disabled successfully
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *
 *   <b> Pre Condition </b>
 *   @n  Emif init and SDRAM configurations and should be called successfully
 *       SDRAM must be in self refresh mode
 *
 *   <b> Post Condition </b>
 *   @n  SDRAM is out of self refresh mode
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
            CSL_EmifObj            emifObj;
            CSL_Status             status;
            CSL_EmifConfig         emifCfg;
            CSL_EmifHandle         hEmif;

            status = EMIF_init(&emifObj);
            hEmif  = &emifObj;
            status = SDRAM_config(hEmif, &sdramConfig, &sdramTimr);
            ...
            ...
            ...
			status = SDRAM_enableSelfRefreshMode(hEmif);
			...
			...
            status = SDRAM_disableSelfRefreshMode(hEmif);
     @endverbatim
 *  ============================================================================
 */
CSL_Status SDRAM_disableSelfRefreshMode(CSL_EmifHandle      hEmif)
{
    CSL_Status   result;

    result = CSL_SOK;

    if(hEmif != NULL)
	{
		/* Set EMIF access to byte mode to avoid triggering the SDRAM initialization sequence  */
		CSL_FINST(hEmif->sysCtrlRegs->ESCR, SYS_ESCR_BYTEMODE, UPPER);
		/* Reset SR bit in SDCR2 to disable self refresh mode */
		CSL_FINS(hEmif->regs->SDCR2, EMIF_SDCR2_SR, CSL_SDRAM_SDCR2_SR_DEFAULT);
		/* Set EMIF access to word mode */
		CSL_FINST(hEmif->sysCtrlRegs->ESCR, SYS_ESCR_BYTEMODE, FULL);
    }
    else
    {
		result = CSL_ESYS_BADHANDLE;
	}

    return (result);

}

/** ============================================================================
 *   @n@b SDRAM_read
 *
 *   @b Description
 *   @n This API reads numWords from sdram.
 *
 *   @b Arguments
 *   @verbatim
            hEmif         Handle to the emif object
            numWords      Number of words to be read
			sdramAddr     SDRAM address to start the read operation
            dataBuff      Data buffer to copy data read from SDRAM
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - SDRAM read is successful
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *   @li                    CSL_ESYS_INVPARAMS - Invalid input parameters
 *
 *   <b> Pre Condition </b>
 *   @n  Emif init and SDRAM configurations should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Reads from sdram memory
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
            CSL_EmifObj            emifObj;
            CSL_Status             status;
            CSL_EmifConfig         emifCfg;
            CSL_EmifHandle         hEmif;

            status = EMIF_init(&emifObj);
            hEmif  = &emifObj;
            status = SDRAM_config(hEmif, &sdramConfig, &sdramTimr);
            ...
            ...
            ...
			status = SDRAM_read(hEmif, numWords, sdramAddr, &dataBuff);
     @endverbatim
 *  ============================================================================
 */
CSL_Status SDRAM_read(CSL_EmifHandle      hEmif,
                      Uint32              numWords,
                      Uint32              sdramAddr,
                      Uint16              *dataBuff)
{
    CSL_Status                result;
	Uint16                    *startAddr;
	Uint32					  count;

    result    = CSL_SOK;
	startAddr = (Uint16 *)sdramAddr;

    if(hEmif != NULL)
	{
        if((sdramAddr >= CSL_SDRAM_START_ADDR) &&
           ((sdramAddr + numWords) < CSL_SDRAM_END_ADDR)&&
           (dataBuff != NULL)&&
           (numWords != 0))
        {
		    for(count = 0; count < numWords; count++)
			{
			    dataBuff[count] = *startAddr++;
			}
        }
		else
		{
		    result = CSL_ESYS_INVPARAMS;
		}
    }
    else
    {
		result = CSL_ESYS_BADHANDLE;
	}

	return(result);
}

/** ============================================================================
 *   @n@b SDRAM_write
 *
 *   @b Description
 *   @n This API writes numWords to sdram.
 *
 *   @b Arguments
 *   @verbatim
            hEmif         Handle to the emif object
            numWords      Number of words to be written
			sdramAddr     SDRAM address to start the write operation
            dataBuff      Data to be written to SDRAM
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - SDRAM write is successful
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *   @li                    CSL_ESYS_INVPARAMS - Invalid config structure
 *
 *   <b> Pre Condition </b>
 *   @n  Emif init and SDRAM configurations should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Writes into sdram memory
 *
 *   @b Modifies
 *   @n sdram memory content
 *
 *   @b Example
 *   @verbatim
            CSL_EmifObj            emifObj;
            CSL_Status             status;
            CSL_EmifConfig         emifCfg;
            CSL_EmifHandle         hEmif;

            status = EMIF_init(&emifObj);
            hEmif  = &emifObj;
            status = SDRAM_config(hEmif, &sdramConfig, &sdramTimr);
            ...
            ...
            ...
			status = SDRAM_write(hEmif, numWords, sdramAddr, &dataBuff);
     @endverbatim
 *  ============================================================================
 */
CSL_Status SDRAM_write(CSL_EmifHandle      hEmif,
                       Uint32              numWords,
                       Uint32              sdramAddr,
                       Uint16              *dataBuff)
{
    CSL_Status      result;
	Uint16          *startAddr;
	Uint32          count;

    result    = CSL_SOK;
	startAddr = (Uint16 *)sdramAddr;

    if(hEmif != NULL)
	{
        if((sdramAddr >= CSL_SDRAM_START_ADDR) &&
           ((sdramAddr + numWords) < CSL_SDRAM_END_ADDR))
        {
		    for(count = 0; count < numWords; count++)
			{
			    *startAddr++ = dataBuff[count];
			}
        }
		else
		{
		    result = CSL_ESYS_INVPARAMS;
		}
    }
    else
    {
		result = CSL_ESYS_BADHANDLE;
	}
	return(result);
}

/** ============================================================================
 *   @n@b EMIF_asyncConfig
 *
 *   @b Description
 *   @n This API configures the asynchronous memory hardware registers.
 *
 *   @b Arguments
 *   @verbatim
            hEmif         Handle to the emif object
            emifConfig    Emif configuration structure
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Asynchronous configuration is successful
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *   @li                    CSL_ESYS_INVPARAMS - Invalid config structure
 *
 *   <b> Pre Condition </b>
 *   @n  Emif init should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Configures asynchronous registers
 *
 *   @b Modifies
 *   @n emif registers
 *
 *   @b Example
 *   @verbatim
            CSL_EmifObj            emifObj;
            CSL_Status             status;
            CSL_EmifConfig         emifCfg;
            CSL_EmifHandle         hEmif;
            CSL_EmifAsyncWaitCfg   asyncWaitConfig;
            CSL_EmifAsyncCfg       asyncConfig;

            status = EMIF_init(&emifObj);
            hEmif  = &emifObj;
            ...
            emifCfg.emifWidth = CSL_EMIF_8_BIT;
            ...
            ...
            emifCfg.asyncWaitCfg = &asyncWaitConfig;
        	emifCfg.asyncCfg     = &asyncConfig;
            status = EMIF_asyncConfig(hEmif, &emifCfg);
     @endverbatim
 *  ============================================================================
 */
CSL_Status EMIF_asyncConfig(CSL_EmifHandle      hEmif,
                            CSL_AsyncConfig     *asyncConfig)
{
    CSL_Status                result;
    volatile ioport Uint16    *asyncCfg0Addr;
    volatile ioport Uint16    *asyncCfg1Addr;

	result = CSL_SOK;

    if(hEmif != NULL)
    {
		if(asyncConfig != NULL)
		{
			hEmif->chipSelect   = asyncConfig->chipSelect;


			/* Configure async wait config register */
			/* Set the chip select */
			switch(asyncConfig->chipSelect)
			{
				case CSL_EMIF_CS2:
					/* CS2 */
					CSL_FINS(hEmif->regs->AWCCR2, EMIF_AWCCR2_CS2_WAIT,
					         asyncConfig->asyncWaitCfg->waitPin);

					asyncCfg0Addr = &hEmif->regs->ACS2CR1;
					asyncCfg1Addr = &hEmif->regs->ACS2CR2;

					break;

				case CSL_EMIF_CS3:
					/* CS3 */
					CSL_FINS(hEmif->regs->AWCCR2, EMIF_AWCCR2_CS3_WAIT,
					         asyncConfig->asyncWaitCfg->waitPin);

					asyncCfg0Addr = &hEmif->regs->ACS3CR1;
					asyncCfg1Addr = &hEmif->regs->ACS3CR2;

					break;

				case CSL_EMIF_CS4:
					/* CS4 */
					CSL_FINS(hEmif->regs->AWCCR2, EMIF_AWCCR2_CS4_WAIT,
					         asyncConfig->asyncWaitCfg->waitPin);

					asyncCfg0Addr = &hEmif->regs->ACS4CR1;
					asyncCfg1Addr = &hEmif->regs->ACS4CR2;

					break;

				case CSL_EMIF_CS5:
					/* CS5 */
					CSL_FINS(hEmif->regs->AWCCR2, EMIF_AWCCR2_CS5_WAIT,
					         asyncConfig->asyncWaitCfg->waitPin);

					asyncCfg0Addr = &hEmif->regs->ACS5CR1;
					asyncCfg1Addr = &hEmif->regs->ACS5CR2;

					break;

				default:
				    result = CSL_ESYS_INVPARAMS;
					break;
			}

			/* Store the wait pin configuration */
			hEmif->waitPin = (1 << asyncConfig->asyncWaitCfg->waitPin);

			/* Set the wait polarity */
			CSL_FINS(hEmif->regs->AWCCR2, EMIF_AWCCR2_WP0,
			         asyncConfig->asyncWaitCfg->waitPol);
			CSL_FINS(hEmif->regs->AWCCR2, EMIF_AWCCR2_WP1,
			         asyncConfig->asyncWaitCfg->waitPol);
			CSL_FINS(hEmif->regs->AWCCR2, EMIF_AWCCR2_WP2,
			         asyncConfig->asyncWaitCfg->waitPol);
			CSL_FINS(hEmif->regs->AWCCR2, EMIF_AWCCR2_WP3,
			         asyncConfig->asyncWaitCfg->waitPol);

			/* Set the extended wait cycles */
			CSL_FINS(hEmif->regs->AWCCR1, EMIF_AWCCR1_MEWC,
			         asyncConfig->asyncWaitCfg->waitCycles);

			/* Configure async configuration register */
			/* Set strobe mode select bit */
			CSL_FINS(*asyncCfg1Addr, EMIF_ACS2CR2_SS,
			         asyncConfig->asyncCfg->selectStrobe);
			/* Set extended wait mode bit */
			CSL_FINS(*asyncCfg1Addr, EMIF_ACS2CR2_EW,
			         asyncConfig->asyncCfg->ewMode);
			/* Set write srobe setup cycles */
			CSL_FINS(*asyncCfg1Addr, EMIF_ACS2CR2_WSETUP,
			         asyncConfig->asyncCfg->w_setup);
			/* Set write duration cycles */
			CSL_FINS(*asyncCfg1Addr, EMIF_ACS2CR2_WSTROBE,
			         asyncConfig->asyncCfg->w_strobe);
			/* Set write hold cycles */
			CSL_FINS(*asyncCfg1Addr, EMIF_ACS2CR2_WHOLD,
			         asyncConfig->asyncCfg->w_hold);
			/* Set read strobe setup cycles */
			CSL_FINS(*asyncCfg1Addr, EMIF_ACS2CR2_RSETUPMSB,
			         (asyncConfig->asyncCfg->r_setup >> 0x3));
			CSL_FINS(*asyncCfg0Addr, EMIF_ACS2CR1_RSETUPLSB,
			         (asyncConfig->asyncCfg->r_setup & 0x7));
			/* Set read strobe duration cycles */
			CSL_FINS(*asyncCfg0Addr, EMIF_ACS2CR1_RSTROBE,
			         asyncConfig->asyncCfg->r_strobe);
			/* Set read strobe hold cycles */
			CSL_FINS(*asyncCfg0Addr, EMIF_ACS2CR1_RHOLD,
			         asyncConfig->asyncCfg->r_hold);
			/* Set turn around cycles */
			CSL_FINS(*asyncCfg0Addr, EMIF_ACS2CR1_TA,
			         asyncConfig->asyncCfg->turnAround);
			/* Set asynchronous memory size */
			CSL_FINS(*asyncCfg0Addr, EMIF_ACS2CR1_ASIZE,
			         asyncConfig->asyncCfg->aSize);

			/* emif Byte access */
			CSL_FINS(hEmif->sysCtrlRegs->ESCR, SYS_ESCR_BYTEMODE,
			         asyncConfig->emifAccess);
		}
		else
		{
			result = CSL_ESYS_INVPARAMS;
		}
    }
    else
    {
		result = CSL_ESYS_BADHANDLE;
	}

    return (result);

}

/** ============================================================================
 *   @n@b NOR_readNwords
 *
 *   @b Description
 *   @n This API reads numWords from NOR flash.
 *
 *   @b Arguments
 *   @verbatim
            hEmif         Handle to the emif object
            numWords      Number of words to be read
			sdramAddr     NOR address to start the read operation
            dataBuff      Data buffer to copy data read from NOR
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - NOR read is successful
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *   @li                    CSL_ESYS_INVPARAMS - Invalid input parameters
 *
 *   <b> Pre Condition </b>
 *   @n  Emif init and Asynchronous configurations should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Reads from NOR flash
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
            CSL_EmifObj            emifObj;
            CSL_Status             status;
            CSL_EmifConfig         emifCfg;
            CSL_EmifHandle         hEmif;

            status = EMIF_init(&emifObj);
            hEmif  = &emifObj;
            status = EMIF_asyncConfig(hEmif, &sdramConfig, &sdramTimr);
            ...
            ...
            ...
			status = NOR_readNwords(hEmif, numWords, norAddr, &dataBuff);
     @endverbatim
 *  ============================================================================
 */
CSL_Status NOR_readNwords(CSL_EmifHandle      hEmif,
                          Uint32              numWords,
                          Uint32              norAddr,
                          Uint16              *dataBuff)
{
    CSL_Status      result;
	Uint16          *startAddr;
    Uint16          *baseAddr;
	Uint32          count;

    result    = CSL_SOK;
	startAddr = (Uint16 *)(CSL_EMIF_NOR_BASE_ADDR + norAddr);
	baseAddr  = (Uint16 *)(CSL_EMIF_NOR_BASE_ADDR);

	/* Send Read array command to base address */
    *baseAddr = CSL_NOR_READ_ARRAY_CMD;

    if(hEmif != NULL)
	{
        if(((norAddr+ (Uint16 *)CSL_EMIF_NOR_BASE_ADDR+numWords) < (Uint16 *)CSL_NOR_END_ADDR)&&
           (dataBuff != NULL) &&
           (numWords != 0))
        {
		    for(count = 0; count < numWords; count++)
			{
			    dataBuff[count] = *startAddr++;
			}
        }
		else
		{
		    result = CSL_ESYS_INVPARAMS;
		}
    }
    else
    {
		result = CSL_ESYS_BADHANDLE;
	}

	return(result);
}

/** ============================================================================
 *   @n@b NOR_WriteNwords
 *
 *   @b Description
 *   @n This API writes numWords to NOR flash.
 *
 *   @b Arguments
 *   @verbatim
            hEmif         Handle to the emif object
            numWords      Number of words to be written
			norAddr       NOR address to start the write operation
            dataBuff      Data to be written to NOR
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - NOR write is successful
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *   @li                    CSL_ESYS_INVPARAMS - Invalid config structure
 *
 *   <b> Pre Condition </b>
 *   @n  Emif init and Asynchronous configurations should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Writes into NOR memory
 *
 *   @b Modifies
 *   @n NOR memory content
 *
 *   @b Example
 *   @verbatim
            CSL_EmifObj            emifObj;
            CSL_Status             status;
            CSL_EmifConfig         emifCfg;
            CSL_EmifHandle         hEmif;

            status = EMIF_init(&emifObj);
            hEmif  = &emifObj;
            status = EMIF_asyncConfig(hEmif, &sdramConfig, &sdramTimr);
            ...
            ...
            ...
			status = NOR_WriteNwords(hEmif, numWords, norAddr, &dataBuff);
     @endverbatim
 *  ============================================================================
 */
CSL_Status NOR_WriteNwords(CSL_EmifHandle      hEmif,
                           Uint32              numWords,
                           Uint32              norAddr,
                           Uint16              *dataBuff)
{
    CSL_Status    result;
	Uint16        *startAddr;
	Uint32        count;

    result    = CSL_SOK;
	startAddr = (Uint16 *)(CSL_EMIF_NOR_BASE_ADDR + norAddr);

    if(hEmif != NULL)
	{
        if(((norAddr+ (Uint16 *)CSL_EMIF_NOR_BASE_ADDR+numWords) < (Uint16 *)CSL_NOR_END_ADDR)&&
           (dataBuff != NULL) &&
           (numWords != 0))
        {
		    for(count = 0; count < numWords; count++)
			{
		        *startAddr = CSL_NOR_WORD_PROGRAM_CMD;

                /* write data to be programmed */
			    *startAddr++ = dataBuff[count];

				/* Poll for program completion */
			    result = NOR_checkStatus(CSL_NOR_WRITE_TIMEOUT);
				if(result != CSL_SOK)
				{
				    result = CSL_ESYS_FAIL;
					break;
				}
			}
        }
		else
		{
		    result = CSL_ESYS_INVPARAMS;
		}
    }
    else
    {
		result = CSL_ESYS_BADHANDLE;
	}
	return(result);
}

/** ============================================================================
 *   @n@b NOR_checkStatus
 *
 *   @b Description
 *   @n This API checks the status of Erase/Program command to the NOR device.
 *      This API must be called after sending the command to the NOR device.
 *
 *   @b Arguments
 *   @verbatim
            timeOut    Timeout count for the particular command
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - NOR status check is successful
 *   @li                    CSL_ESYS_FAIL     - Time-out or any errors has occured
 *
 *   <b> Pre Condition </b>
 *   @n  Erase or Write commands are be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Returns time-out condition(If occurs)
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
            CSL_EmifHandle    hEmif;
            CSL_Status        status;
            . . .
            . . .
			status = NOR_checkStatus(timeOut);
     @endverbatim
 *  ============================================================================
 */
CSL_Status NOR_checkStatus(Uint32 timeOut)
{
	volatile Uint16 *flashAddr;
	CSL_Status status = CSL_ESYS_FAIL;

	flashAddr = (volatile Uint16*)CSL_EMIF_NOR_BASE_ADDR;
    /* Read Status Register */
    *flashAddr = CSL_NOR_READ_STATUS_CMD;

    while (timeOut > 0)
    {
        /*
         *  Check the busy bit
         */
        if ((*flashAddr & CSL_NOR_OP_COMPLETION_STATUS1) || (*flashAddr & CSL_NOR_OP_COMPLETION_STATUS2))
         {
            /*
             * Check for any errors
             */
            if (((*flashAddr & CSL_NOR_OP_ERROR_CHECK_MASK1) != 0) ||
                ((*flashAddr & CSL_NOR_OP_ERROR_CHECK_MASK2) != 0))
            {
                *flashAddr = CSL_NOR_READ_ARRAY_CMD;
                status = CSL_ESYS_FAIL;
				break;
            }
            else
            {
                *flashAddr = CSL_NOR_READ_ARRAY_CMD;
                status = CSL_SOK;
				break;
            }
        }
        timeOut--;
    }

    /* Timeout occured */
    *flashAddr = CSL_NOR_READ_ARRAY_CMD;

    return(status);
}

/** ============================================================================
 *   @n@b NOR_sendCommand
 *
 *   @b Description
 *   @n This API sends command to NOR flash.
 *
 *   @b Arguments
 *   @verbatim
            hEmif         Handle to the emif object
			norAddr       NOR address to start the write operation
            command       Command to be sent to the NOR flash
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - NOR command sent successfully
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *   @li                    CSL_ESYS_INVPARAMS - Invalid parameters
 *
 *   <b> Pre Condition </b>
 *   @n  Emif init and Asynchronous configurations should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Sends command to NOR flash
 *
 *   @b Modifies
 *   @n Writes command to the NOR flash
 *
 *   @b Example
 *   @verbatim
            CSL_EmifObj            emifObj;
            CSL_Status             status;
            CSL_EmifConfig         emifCfg;
            CSL_EmifHandle         hEmif;

            status = EMIF_init(&emifObj);
            hEmif  = &emifObj;
            status = EMIF_asyncConfig(hEmif, &sdramConfig, &sdramTimr);
            ...
            ...
            ...
			status = NOR_sendCommand(hEmif, norAddr, command);
     @endverbatim
 *  ============================================================================
 */
CSL_Status NOR_sendCommand(CSL_EmifHandle      hEmif,
                           Uint32              norAddr,
                           Uint16              command)
{
    CSL_Status    result;
	Uint16        *startAddr;

    result    = CSL_SOK;
	startAddr = (Uint16 *)(CSL_EMIF_NOR_BASE_ADDR + norAddr);

    if(hEmif != NULL)
	{
	    if(norAddr < (Uint32)(CSL_NOR_START_ADDR - CSL_NOR_END_ADDR))
		{
	        *startAddr = command;
		}
		else
		{
		    result = CSL_ESYS_INVPARAMS;
		}
    }
    else
    {
		result = CSL_ESYS_BADHANDLE;
	}
	return(result);
}

/** ============================================================================
 *   @n@b NAND_setup
 *
 *   @b Description
 *   @n This API configures the EMIF hardware registers.
 *
 *   @b Arguments
 *   @verbatim
            hEmif         Handle to the emif object
            nandConfig    Emif configuration structure
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Nand setup is successful
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *   @li                    CSL_ESYS_INVPARAMS - Invalid config structure
 *
 *   <b> Pre Condition </b>
 *   @n  Emif init should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Configures emif registers
 *
 *   @b Modifies
 *   @n emif registers
 *
 *   @b Example
 *   @verbatim
			CSL_EmifObj            emifObj;
			CSL_Status             status;
			CSL_EmifConfig         emifCfg;
			CSL_EmifHandle         hEmif;
			CSL_EmifAsyncWaitCfg   asyncWaitConfig;
			CSL_EmifAsyncCfg       asyncConfig;

			status = EMIF_init(&emifObj);
			hEmif  = &emifObj;
			...
			emifCfg.emifWidth = CSL_NAND_8_BIT;
			...
			...
			emifCfg.asyncWaitCfg = &asyncWaitConfig;
			emifCfg.asyncCfg     = &asyncConfig;
            status = EMIF_setup(hEmif, &nandCfg);
     @endverbatim
 *  ============================================================================
 */
CSL_Status NAND_setup(CSL_EmifHandle      hEmif,
                      CSL_NandConfig      *nandConfig)
{
    CSL_Status     result;

	result = CSL_SOK;

    if(hEmif != NULL)
    {
		if(nandConfig != NULL)
		{
			hEmif->nandWidth    = nandConfig->nandWidth;
			hEmif->nandPageSize = nandConfig->nandPageSize;
			hEmif->emifOpMode   = nandConfig->emifOpMode;
			hEmif->nandType     = nandConfig->nandType;

			/* Configure async wait config register */
			/* Set the chip select */
			switch(hEmif->chipSelect)
			{
				case CSL_EMIF_CS2:
					/* CS2 */
					/* Set the chip select in nand flash control register */
					CSL_FINST(hEmif->regs->NANDFCR, EMIF_NANDFCR_CS2_USE_NAND,
					          NAND);
					CSL_FINST(hEmif->regs->NANDFCR, EMIF_NANDFCR_CS3_USE_NAND,
					          NONAND);
					CSL_FINST(hEmif->regs->NANDFCR, EMIF_NANDFCR_CS4_USE_NAND,
					         NONAND);
					CSL_FINST(hEmif->regs->NANDFCR, EMIF_NANDFCR_CS5_USE_NAND,
					          NONAND);

					break;

				case CSL_EMIF_CS3:
					/* CS3 */
					/* Set the chip select in nand flash control register */
					CSL_FINST(hEmif->regs->NANDFCR, EMIF_NANDFCR_CS2_USE_NAND,
					          NONAND);
					CSL_FINST(hEmif->regs->NANDFCR, EMIF_NANDFCR_CS3_USE_NAND,
					          NAND);
					CSL_FINST(hEmif->regs->NANDFCR, EMIF_NANDFCR_CS4_USE_NAND,
					          NONAND);
					CSL_FINST(hEmif->regs->NANDFCR, EMIF_NANDFCR_CS5_USE_NAND,
					          NONAND);

					break;

				case CSL_EMIF_CS4:
					/* CS4 */
					/* Set the chip select in nand flash control register */
					CSL_FINST(hEmif->regs->NANDFCR, EMIF_NANDFCR_CS2_USE_NAND,
					          NONAND);
					CSL_FINST(hEmif->regs->NANDFCR, EMIF_NANDFCR_CS3_USE_NAND,
					          NONAND);
					CSL_FINST(hEmif->regs->NANDFCR, EMIF_NANDFCR_CS4_USE_NAND,
					          NAND);
					CSL_FINST(hEmif->regs->NANDFCR, EMIF_NANDFCR_CS5_USE_NAND,
					          NONAND);
					break;

				case CSL_EMIF_CS5:
					/* CS5 */
					/* Set the chip select in nand flash control register */
					CSL_FINST(hEmif->regs->NANDFCR, EMIF_NANDFCR_CS2_USE_NAND,
					          NONAND);
					CSL_FINST(hEmif->regs->NANDFCR, EMIF_NANDFCR_CS3_USE_NAND,
					          NONAND);
					CSL_FINST(hEmif->regs->NANDFCR, EMIF_NANDFCR_CS4_USE_NAND,
					          NONAND);
					CSL_FINST(hEmif->regs->NANDFCR, EMIF_NANDFCR_CS5_USE_NAND,
					          NAND);

					break;

				default:
				    result = CSL_ESYS_INVPARAMS;
					break;
			}

		}
		else
		{
			result = CSL_ESYS_INVPARAMS;
		}
    }
    else
    {
		result = CSL_ESYS_BADHANDLE;
	}

    return (result);
}

/** ============================================================================
 *   @n@b NAND_getBankInfo
 *
 *   @b Description
 *   @n This API gives the bank details of the nand device. This API populates
 *      the base and offset address locations for the NAND flash based on the
 *      bank number passed as the parameter. Bank number should be decide based
 *      on the EMIF chip select connected to NAND flash as shown below.
 *      CSL_NAND_BANK_0 - EMIF_CS2
 *      CSL_NAND_BANK_1 - EMIF_CS3
 *      CSL_NAND_BANK_2 - EMIF_CS4
 *      CSL_NAND_BANK_3 - EMIF_CS5
 *
 *      NOTE: This API sets ALE and CLE address offset to default values assuming
 *      A11 address bit is connected to ALE signal of NAND flash and A12 address
 *      bit is connected to CLE signal of NAND flash.
 *      Use NAND_setLatchEnableOffset() to change the default offset values.
 *
 *   @b Arguments
 *   @verbatim
            hEmif      Handle to the emif object
            bank       Pointer to nand bank info structure
            bankNum    Nand bank number
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Nand get bank info is successful
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *   @li                    CSL_ESYS_INVPARAMS - Invalid parameter
 *
 *   <b> Pre Condition </b>
 *   @n  Nand init should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Populates nand bank info structure
 *
 *   @b Modifies
 *   @n Nand bank info structure
 *
 *   @b Example
 *   @verbatim
            CSL_emifObj    emifObj;
			Uint16         bankNum;
			CSL_Status     status;
			CSL_EmifHandle hEmif;

			bankNum = 0;
			status = EMIF_init(&emifObj);
			hEmif  = &emifObj;
			....
			....
            status = NAND_getBankInfo(hEmif, (CSL_NandAsyncBank*)&hEmif->bank, bankNum);
     @endverbatim
 *  ============================================================================
 */
CSL_Status NAND_getBankInfo(CSL_EmifHandle      hEmif,
                            CSL_NandAsyncBank   *bank,
                            Uint16              bankNum)
{
    CSL_Status result;

	result = CSL_SOK;

    if(hEmif != NULL)
    {
		if(bank != NULL)
		{
			switch(bankNum)
			{
				case CSL_NAND_BANK_0:
					bank->CExDATA = (Uint32)CSL_EMIF_CS2_DATA_BASE_ADDR;
					break;

				case CSL_NAND_BANK_1:
					bank->CExDATA = (Uint32)CSL_EMIF_CS3_DATA_BASE_ADDR;
					break;

				case CSL_NAND_BANK_2:
					bank->CExDATA = (Uint32)CSL_EMIF_CS4_DATA_BASE_ADDR;
					break;

				case CSL_NAND_BANK_3:
					bank->CExDATA = (Uint32)CSL_EMIF_CS5_DATA_BASE_ADDR;
					break;

				default:
				    result = CSL_ESYS_INVPARAMS;
					break;
			}

			if(result == CSL_SOK)
			{
				bank->CExNUM = bankNum;

				/* A11 address bit is connected to  ALE signal of NAND flash */
				bank->CExALE  = (Uint32)(bank->CExDATA +
										(CSL_EMIF_CSx_ADDR_OFFSET));
				/* A12 address bit is  mapped to CLE signal of NAND flash */
				bank->CExCLE  = (Uint32)(bank->CExDATA +
										 (CSL_EMIF_CSx_CMD_OFFSET));
			}
		}
		else
		{
			result = CSL_ESYS_INVPARAMS;
		}
    }
    else
    {
		result = CSL_ESYS_BADHANDLE;
	}

    return (result);
}

/** ============================================================================
 *   @n@b NAND_setLatchEnableOffset
 *
 *   @b Description
 *   @n This API sets the CLE and ALE address offset.
 *      Any of the EMIF address lines can be used to drive ALE and CLE of the
 *      NAND flash. ALE and CLE address offset are decided based of the address
 *      lines used to drive ALE and CLE pins. This API should be called after
 *      calling NAND_getBankInfo() API to modify the ALE and CLE address from
 *      the default value.
 *
 *      NOTE: Addresses passed should be offset values from the base address.
 *      For example assume that EMIF A11 line is used to drive ALE pin and
 *      EMIF A12 line is used to driver CLE pin. Then the address offset for
 *      ALE will be 0x1000 and address offset for CLE will be 0x2000.
 *
 *      Calling this API is mandatory in case of NAND ALE and CLE connected to
 *      pins other than A11 and A12 respectively. Otherwise NAND CSL APIs
 *      will not function properly.
 *
 *   @b Arguments
 *   @verbatim
            hEmif         Handle to the emif object
            addrOffset    ALE offset location
            cmdOffset     CLE offset location
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Set address offset is successful
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *
 *   <b> Pre Condition </b>
 *   @n  Nand init should be called successfully
 *   @n  NAND_getBankInfo() should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Sets the ALE and CLE address offset
 *
 *   @b Modifies
 *   @n NAND handle
 *
 *   @b Example
 *   @verbatim
            CSL_emifObj    emifObj;
			Uint16         bankNum;
			CSL_Status     status;
			CSL_EmifHandle hEmif;

			bankNum = 0;
			status = EMIF_init(&emifObj);
			hEmif  = &emifObj;
			....
			....
            status = NAND_getBankInfo(hEmif, (CSL_NandAsyncBank*)&hEmif->bank, bankNum);
            status = NAND_setLatchEnableOffset(hEmif, 0x2000, 0x4000);
     @endverbatim
 *  ============================================================================
 */
CSL_Status NAND_setLatchEnableOffset(CSL_EmifHandle    hEmif,
                                     Uint32            addrOffset,
                                     Uint32            cmdOffset)
{
    CSL_Status result;

	result = CSL_SOK;

    if(hEmif != NULL)
    {
		/* Set the ALE offset */
		hEmif->bank.CExALE  = (Uint32)(hEmif->bank.CExDATA + addrOffset);
		/* Set the CLE offset */
		hEmif->bank.CExCLE  = (Uint32)(hEmif->bank.CExDATA + cmdOffset);
    }
    else
    {
		result = CSL_ESYS_BADHANDLE;
	}

    return (result);
}

/** ============================================================================
 *   @n@b NAND_isStatusWriteProtected
 *
 *   @b Description
 *   @n This is the API used to check if the nand device is write protected.
 *      It is not possible write any data to nand if it is write-protected.
 *      So this API must be called before calling the write API to check the
 *      nand status.
 *
 *   @b Arguments
 *   @verbatim
            hEmif         Handle to the emif object
            WPstatus      Write protect status pointer
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Retutned for success
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *   @li                    CSL_ESYS_INVPARAMS - Invalid parameter
 *
 *   <b> Pre Condition </b>
 *   @n  EMIF_init and NAND_getBankInfo should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Write protect status is returned in status variable
 *   @li    TRUE     - NAND device is write protected
 *   @li    FALSE    - NAND device is not write protected
 *
 *   @b Modifies
 *   @n Write protect status variable
 *
 *   @b Example
 *   @verbatim
            CSL_emifObj    emifObj;
			Uint16         bankNum;
			CSL_Status     status;
			CSL_EmifHandle hEmif;
            		Uint16         wpstatus;

			bankNum = 0;
			status = EMIF_init(&emifObj);
			hEmif  = &emifObj;
			....
			....
            status = NAND_getBankInfo(hEmif, (CSL_NandAsyncBank*)&hEmif->bank, bankNum);
 			....
 			....
            status = NAND_isStatusWriteProtected(hEmif,&wpstatus);
     @endverbatim
 *  ============================================================================
 */
CSL_Status NAND_isStatusWriteProtected(CSL_EmifHandle      hEmif,
                                       Uint16              *WPstatus)
{
    volatile Uint32     timeOut;
    volatile Uint16     statusByte;
    Uint16              statusSuccess;
	CSL_Status		    result;
	volatile Uint16     looper;

	result        = CSL_SOK;
    timeOut       = CSL_NAND_READ_STATUS_TIMEOUT;

	if(hEmif != NULL)
	{
		if(WPstatus != NULL)
		{
			if(hEmif->nandType == CSL_NAND_SMALL_BLOCK)
			{
				statusSuccess = CSL_NAND_SB_CMD_STATUS_SUCCESS;
			}
			else
			{
				statusSuccess = CSL_NAND_BB_CMD_STATUS_SUCCESS;
			}

			do
			{
				*(CSL_VUint16*)hEmif->bank.CExCLE = CSL_NAND_CMD_STATUS;

				/* Wait for the device to provide response */
				for(looper = 0; looper < CSL_EMIF_DELAY; looper++);

				 CSL_NAND_READWORD(hEmif, statusByte);
				timeOut--;
			} while (((statusByte & statusSuccess) != statusSuccess) &&
					 (timeOut > 0));

			if(timeOut > 0)
			{
				*WPstatus = FALSE;
				return(result);
			}
			else
			{
				if(statusByte != CSL_NAND_BB_CMD_WP_STATUS_OPEN)
				{
					*WPstatus = TRUE;
				}
				else
				{
					*WPstatus = FALSE;
				}
			}
		}
		else
		{
			result = CSL_ESYS_INVPARAMS;
		}
	}
	else
	{
		result = CSL_ESYS_BADHANDLE;
	}

	return(result);
}

/** ============================================================================
 *   @n@b NAND_sendCommand
 *
 *   @b Description
 *   @n Any command to the nand device should be sent through this API.
 *      nand device is having specific commands for each operation.
 *
 *   @b Arguments
 *   @verbatim
            hEmif          Handle to the emif object
            cmd            Command to the nand device
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Nand send command is successful
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *
 *   <b> Pre Condition </b>
 *   @n  EMIF_init and NAND_getBankInfo should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Sends command to the nand device
 *
 *   @b Modifies
 *   @n Writes command to the command latch address
 *
 *   @b Example
 *   @verbatim
            CSL_emifObj    emifObj;
			Uint16         bankNum;
			CSL_Status     status;
			CSL_EmifHandle hEmif;

			bankNum = 0;
			status = EMIF_init(&emifObj);
			hEmif  = &emifObj;
			....
			....
            status = NAND_getBankInfo(hEmif, (CSL_NandAsyncBank*)&hEmif->bank, bankNum);
 			....
 			....
            status = NAND_sendCommand(hEmif,CSL_NAND_CMD_READ_START);
     @endverbatim
 *  ============================================================================
 */
CSL_Status NAND_sendCommand(CSL_EmifHandle    hEmif,
                            CSL_VUint16       cmd)
{
	CSL_Status result;

	result = CSL_SOK;

    if(NULL != hEmif)
    {
        *(CSL_VUint16*)hEmif->bank.CExCLE = cmd;
    }
    else
	{
		result = CSL_ESYS_BADHANDLE;
	}

    return (result);
}

/** ============================================================================
 *   @n@b NAND_checkCommandStatus
 *
 *   @b Description
 *   @n This API checks the status of any command to the nand device.
 *      This API must be called after sending any command to the nand device.
 *
 *   @b Arguments
 *   @verbatim
            hEmif    Handle to the emif object
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Nand status check is successful
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *   @li                    CSL_NAND_E_TIMEOUT - Time-out has occured
 *
 *   <b> Pre Condition </b>
 *   @n  NAND_sendCommand API should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Returns time-out condition(If occurs)
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
            CSL_EmifHandle    hEmif;
            CSL_Status        status;

            status = NAND_sendCommand(hEmif, CSL_NAND_CMD_READ_START);

            if(status == CSL_SOK)
            {
				status = NAND_checkCommandStatus(hEmif);
			}
     @endverbatim
 *  ============================================================================
 */
CSL_Status NAND_checkCommandStatus(CSL_EmifHandle    hEmif)
{
	CSL_Status         result;
    volatile Uint16    timeout;
    volatile Uint16    status;

	timeout = 0;
	result  = CSL_SOK;

    if(NULL != hEmif)
    {
        /* Check for R/B status */
        do
        {
			status = CSL_FEXT(hEmif->regs->NANDFSR1, EMIF_NANDFSR1_WAITSTAT);
			timeout++;

		}while(((status & hEmif->waitPin) == FALSE) &&
		        (timeout < CSL_NAND_MAX_TIMEOUT));

		if(timeout >= CSL_NAND_MAX_TIMEOUT)
		{
			result = CSL_NAND_E_TIMEOUT;
		}
    }
    else
    {
		result = CSL_ESYS_BADHANDLE;
	}

	return (result);
}

/** ============================================================================
 *   @n@b NAND_setAddress
 *
 *   @b Description
 *   @n This API used to set address of nand page to read/write data from/to
 *      nand device. Page address must be set to a valid nand page before
 *      calling read/write APIs.
 *
 *   @b Arguments
 *   @verbatim
            hEmif          Handle to the emif object
            addr           Addres value to set
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Nand set address is successful
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *   @li                    CSL_ESYS_INVPARAMS - Invalid parameter
 *
 *   <b> Pre Condition </b>
 *   @n  EMIF_init and NAND_getBankInfo should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Sets nand address
 *
 *   @b Modifies
 *   @n Writes address to the address latch
 *
 *   @b Example
 *   @verbatim
            CSL_emifObj    emifObj;
			Uint16         bankNum;
			CSL_Status     status;
			CSL_EmifHandle hEmif;

			bankNum = 0;
			status = EMIF_init(&emifObj);
			hEmif  = &emifObj;
			....
			....
            status = NAND_getBankInfo(hEmif, (CSL_NandAsyncBank*)&hEmif->bank, bankNum);
 			....
 			....
            status = NAND_setAddress(hEmif,0x01);
     @endverbatim
 *  ============================================================================
 */
CSL_Status NAND_setAddress(CSL_EmifHandle    hEmif,
                           Uint16            addr)
{
	CSL_Status    result;

	result = CSL_SOK;

	if (hEmif != NULL)
	{
		if(hEmif->nandWidth == CSL_EMIF_8_BIT)
		{
		    *(CSL_VUint8*)hEmif->bank.CExALE = (Uint8)addr;
		}
		else if(hEmif->nandWidth == CSL_EMIF_16_BIT)
		{
		    *(CSL_VUint16*)hEmif->bank.CExALE = (Uint16)addr;
		}
		else
		{
			result = CSL_ESYS_INVPARAMS;
		}
    }
    else
	{
		result = CSL_ESYS_BADHANDLE;
	}

    return (result);
}

/** ============================================================================
 *   @n@b NAND_enableHwECC
 *
 *   @b Description
 *   @n This API enables hardware ECC(Error Check and  Correction) of the
 *      nand device. ECC is used to check and correct errors occurred during
 *      nand data transfer.
 *
 *   @b Arguments
 *   @verbatim
            hEmif      Handle to the emif object
            csInput    Nand chip selection input
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Nand enable HW ECC is successful
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *   @li                    CSL_ESYS_INVPARAMS - Invalid parameter
 *
 *   <b> Pre Condition </b>
 *   @n  Nand init should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Enables nand hardware error check and correction
 *
 *   @b Modifies
 *   @n Nand ECC registers
 *
 *   @b Example
 *   @verbatim
            CSL_emifObj         emifObj;
			CSL_Status          status;
			CSL_EmifHandle      hEmif;
			CSL_EMifChipSelect  csInput;

			status = EMIF_init(&emifObj);
			hEmif  = &emifObj;
			....
			....
			csInput = CSL_NAND_CE0;
            status = NAND_enableHwECC(hEmif,csInput);
     @endverbatim
 *  ============================================================================
 */
CSL_Status NAND_enableHwECC(CSL_EmifHandle        hEmif,
                            CSL_EmifChipSelect    csInput)
{
	CSL_Status    result;
	Uint16        tempVal;

	result = CSL_SOK;

	/* Save the EMIF access setting */
	tempVal = CSL_FEXT(hEmif->sysCtrlRegs->ESCR, SYS_ESCR_BYTEMODE);

	/* Set EMIF access to 16 bit */
	CSL_FINST(hEmif->sysCtrlRegs->ESCR, SYS_ESCR_BYTEMODE, FULL);

	if (hEmif != NULL)
	{
		if(hEmif->nandWidth == CSL_EMIF_8_BIT)
		{
			/* 4 bit ECC possible only for 8 bit NAND devices */
			/* write the appropriate CS value */
			CSL_FINS(hEmif->regs->NANDFCR, EMIF_NANDFCR_4BIT_ECC_SEL, csInput);
			/* Enable 4-Bit ECC for the selected CS */
			CSL_FINS(hEmif->regs->NANDFCR, EMIF_NANDFCR_4BIT_ECC_START, TRUE);
		}
	    else
	    {
			/* 16 bit NAND device */
			/* only 1 bit ECC is possible for 16 bit NAND */
			switch(csInput)
			{
				case CSL_EMIF_CS2:
					/* CS2 */
					CSL_FINS(hEmif->regs->NANDFCR, EMIF_NANDFCR_CS2_ECC_START,
					         TRUE);
					break;
				case CSL_EMIF_CS3:
					/* CS3 */
					CSL_FINS(hEmif->regs->NANDFCR, EMIF_NANDFCR_CS3_ECC_START,
					         TRUE);
					break;
				case CSL_EMIF_CS4:
					/* CS4 */
					CSL_FINS(hEmif->regs->NANDFCR, EMIF_NANDFCR_CS4_ECC_START,
					         TRUE);
					break;
				case CSL_EMIF_CS5:
					/* CS5 */
					CSL_FINS(hEmif->regs->NANDFCR, EMIF_NANDFCR_CS5_ECC_START,
					         TRUE);
					break;
				default:
				    result = CSL_ESYS_INVPARAMS;
					break;
			}
		}
    }
    else
    {
		result = CSL_ESYS_BADHANDLE;
	}

	/* Restore EMIF access setting */
	CSL_FINS(hEmif->sysCtrlRegs->ESCR, SYS_ESCR_BYTEMODE, tempVal);

    return (result);
}

/** ============================================================================
 *   @n@b NAND_disableHwECC
 *
 *   @b Description
 *   @n This API disables hardware ECC of the nand device.
 *
 *   @b Arguments
 *   @verbatim
            hEmif      Handle to the emif object
            csInput    Nand chip selection input
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Nand disable HW ECC is successful
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *   @li                    CSL_ESYS_INVPARAMS - Invalid parameter
 *
 *   <b> Pre Condition </b>
 *   @n  NAND_enableHwECC API should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Disables nand hardware error check and correction
 *
 *   @b Modifies
 *   @n Nand ECC registers
 *
 *   @b Example
 *   @verbatim
			CSL_Status          status;
			CSL_EmifHandle      hEmif;
			CSL_EMifChipSelect  csInput;

			csInput = CSL_NAND_CE0;

            status = NAND_enableHwECC(hEmif, csInput);
            ...
            ...
            status = NAND_disableHwECC(hEmif, csInput);
     @endverbatim
 *  ============================================================================
 */
CSL_Status NAND_disableHwECC(CSL_EmifHandle        hEmif,
                             CSL_EmifChipSelect    csInput)
{
	CSL_Status    result;
	Uint16        status;
	Uint16        tempVal;

	result = CSL_SOK;

	/* Save the EMIF access setting */
	tempVal = CSL_FEXT(hEmif->sysCtrlRegs->ESCR, SYS_ESCR_BYTEMODE);

	/* Set EMIF access to 16 bit */
	CSL_FINST(hEmif->sysCtrlRegs->ESCR, SYS_ESCR_BYTEMODE, FULL);

	if (hEmif != NULL)
	{
		if(hEmif->nandWidth == CSL_EMIF_8_BIT)
		{
			/* 4 bit ECC possible only for 8 bit NAND devices */
			/* Stop 4-Bit ECC by reading the 4BIT ECC register */
			status = CSL_FEXT(hEmif->regs->NAND4BITECC1,
	                          EMIF_NAND4BITECC1_4BIT_ECC_VAL1);
		}
	    else
	    {
			/* 16 bit NAND device */
			switch(csInput)
	        {
				case CSL_EMIF_CS2:
					/* CS2 ECC register read to stop the ECC */
					status = CSL_FEXTR(hEmif->regs->NCS2ECC1,
					                   CSL_EMIF_NCS2ECC1_MSB,
					                   CSL_EMIF_NCS2ECC1_LSB);
					break;
				case CSL_EMIF_CS3:
					/* CS3 ECC register read to stop the ECC */
					status = CSL_FEXTR(hEmif->regs->NCS3ECC1,
					                   CSL_EMIF_NCS3ECC1_MSB,
					                   CSL_EMIF_NCS3ECC1_LSB);
					break;
				case CSL_EMIF_CS4:
					/* CS4 ECC register read to stop the ECC */
					status = CSL_FEXTR(hEmif->regs->NCS4ECC1,
					                   CSL_EMIF_NCS4ECC1_MSB,
					                   CSL_EMIF_NCS4ECC1_LSB);
					break;
				case CSL_EMIF_CS5:
					/* CS5 ECC register read to stop the ECC */
					status = CSL_FEXTR(hEmif->regs->NCS5ECC1,
					                   CSL_EMIF_NCS5ECC1_MSB,
					                   CSL_EMIF_NCS5ECC1_LSB);
					break;
				default:
				    result = CSL_ESYS_INVPARAMS;
					break;
			}
		}
	}
	else
	{
		/* Dummy instruction to avoid compilation warning */
		result = status;
		result = CSL_ESYS_BADHANDLE;
	}

	/* Restore EMIF access setting */
	CSL_FINS(hEmif->sysCtrlRegs->ESCR, SYS_ESCR_BYTEMODE, tempVal);

    return (result);
}

/** ============================================================================
 *   @n@b NAND_readECC
 *
 *   @b Description
 *   @n This API is used to read the information generated by ECC hardware.
 *      Hardware ECC must be enabled before calling this API.
 *
 *   @b Arguments
 *   @verbatim
            hEmif        Handle to the emif object
            eccBuffer    ECC Buffer pointer
            csInput      Chip select used for calculating Ecc
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Nand read is successful
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *   @li                    CSL_ESYS_INVPARAMS - Invalid parameter
 *
 *   <b> Pre Condition </b>
 *   @n  NAND_enableHwECC API should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Populates ECC data into eccBuffer
 *
 *   @b Modifies
 *   @n eccBuffer
 *
 *   @b Example
 *   @verbatim
            CSL_Status           status;
			CSL_EmifHandle       hEmif;
			Uint16               eccBuffer[8];
			CSL_EMifChipSelect   csInput;

			csInput = CSL_NAND_CE0;

            status = NAND_enableHwECC(hEmif, csInput);
            ...
            ...
            status = NAND_readECC(hEmif, eccBuffer, csInput);
     @endverbatim
 *  ============================================================================
 */
CSL_Status NAND_readECC(CSL_EmifHandle        hEmif,
                        Uint16                *eccBuffer,
                        CSL_EmifChipSelect    csInput)
{
	CSL_Status    result;

	result = CSL_SOK;

	if(NULL != hEmif)
	{
		if(NULL != eccBuffer)
		{
			if(hEmif->nandWidth == CSL_EMIF_8_BIT)
			{
				/* 4 bit ECC possible only for 8 bit NAND devices */
				eccBuffer[0] = CSL_FEXT(hEmif->regs->NAND4BITECC1,
				                        EMIF_NAND4BITECC1_4BIT_ECC_VAL1);

				eccBuffer[1] = CSL_FEXT(hEmif->regs->NAND4BITECC2,
				                        EMIF_NAND4BITECC2_4BIT_ECC_VAL2);

				eccBuffer[2] = CSL_FEXT(hEmif->regs->NAND4BITECC3,
				                        EMIF_NAND4BITECC3_4BIT_ECC_VAL3);

				eccBuffer[3] = CSL_FEXT(hEmif->regs->NAND4BITECC4,
				                        EMIF_NAND4BITECC4_4BIT_ECC_VAL4);

				eccBuffer[4] = CSL_FEXT(hEmif->regs->NAND4BITECC5,
				                        EMIF_NAND4BITECC5_4BIT_ECC_VAL5);

				eccBuffer[5] = CSL_FEXT(hEmif->regs->NAND4BITECC6,
				                        EMIF_NAND4BITECC6_4BIT_ECC_VAL6);

				eccBuffer[6] = CSL_FEXT(hEmif->regs->NAND4BITECC7,
				                        EMIF_NAND4BITECC7_4BIT_ECC_VAL7);

				eccBuffer[7] = CSL_FEXT(hEmif->regs->NAND4BITECC8,
				                        EMIF_NAND4BITECC8_4BIT_ECC_VAL8);
			}
			else
			{
				/* 16 bit NAND device */
				switch(csInput)
				{
					case CSL_EMIF_CS2:
						 eccBuffer[0] = CSL_FEXTR(hEmif->regs->NCS2ECC1,
						                          CSL_EMIF_NCS2ECC1_MSB,
						                          CSL_EMIF_NCS2ECC1_LSB);

						 eccBuffer[1] = CSL_FEXTR(hEmif->regs->NCS2ECC2,
						                          CSL_EMIF_NCS2ECC2_MSB,
						                          CSL_EMIF_NCS2ECC2_LSB);
						 break;
					case CSL_EMIF_CS3:
						 eccBuffer[0] = CSL_FEXTR(hEmif->regs->NCS3ECC1,
						                          CSL_EMIF_NCS3ECC1_MSB,
						                          CSL_EMIF_NCS3ECC1_LSB);

						 eccBuffer[1] = CSL_FEXTR(hEmif->regs->NCS3ECC2,
						                          CSL_EMIF_NCS3ECC2_MSB,
						                          CSL_EMIF_NCS3ECC2_LSB);
					case CSL_EMIF_CS4:
						 eccBuffer[0] = CSL_FEXTR(hEmif->regs->NCS4ECC1,
						                          CSL_EMIF_NCS4ECC1_MSB,
						                          CSL_EMIF_NCS4ECC1_LSB);

						 eccBuffer[1] = CSL_FEXTR(hEmif->regs->NCS5ECC1,
						                          CSL_EMIF_NCS4ECC2_MSB,
						                          CSL_EMIF_NCS4ECC2_LSB);
						 break;
					case CSL_EMIF_CS5:
						 eccBuffer[0] = CSL_FEXTR(hEmif->regs->NCS5ECC1,
						                          CSL_EMIF_NCS5ECC1_MSB,
						                          CSL_EMIF_NCS5ECC1_LSB);

						 eccBuffer[1] = CSL_FEXTR(hEmif->regs->NCS5ECC2,
						                          CSL_EMIF_NCS5ECC2_MSB,
						                          CSL_EMIF_NCS5ECC2_LSB);
						 break;
					default:
						 result = CSL_ESYS_INVPARAMS;
						 break;
				}
			}
		}
		else
		{
			result = CSL_ESYS_INVPARAMS;
		}
	}
	else
	{
		result = CSL_ESYS_BADHANDLE;
	}

    return (result);
}

/** ============================================================================
 *   @n@b NAND_readNBytes
 *
 *   @b Description
 *   @n This API reads N number of bytes from a nand physical page.
 *      Number of bytes to be read is sent as an argument to this API.
 *      A read command should be sent and nand page address should be set
 *      before calling this API.
 *
 *   @b Arguments
 *   @verbatim
            hEmif          Handle to the emif object
            readRequest    Number of bytes to read
            pReadBuffer    Read buffer pointer
            pack           Data pack flag
            spare          Spare area flag
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Nand read is successful
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *   @li                    CSL_ESYS_INVPARAMS - Invalid parameter
 *
 *   <b> Pre Condition </b>
 *   @n  NAND_sendCommand and NAND_setAddress APIs should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Reads the data from nand
 *
 *   @b Modifies
 *   @n Copies data from nand to read buffer
 *
 *   @b Example
 *   @verbatim
            #define  NAND_BUF_SIZE      (1024)

			CSL_Status     status;
			CSL_EmifHandle hEmif;
			Uint32         address;
			Uint16         nandReadBuf[NAND_BUF_SIZE];

			address = 0x40;
            status = NAND_sendCommand(hEmif,CSL_NAND_CMD_READ_START);

            // Set column address
			status = NAND_setAddress(hEmif,0x00);
	        status = NAND_setAddress(hEmif,0x00);
            // Set row address
			status = NAND_setAddress(hEmif,0x40);
			status = NAND_setAddress(hEmif,0x00);
			status = NAND_setAddress(hEmif,0x00);
            ....
            ....
            status = NAND_readNBytes(hEmif,NAND_BUF_SIZE,nandreadBuf,0,0);
     @endverbatim
 *  ============================================================================
 */
CSL_Status NAND_readNBytes(CSL_EmifHandle    hEmif,
                           Uint16            readRequest,
                           Uint16            *pReadBuffer,
                           Uint16            pack,
                           Bool				 spare)
{
	CSL_Status    result;
    Uint16        index;
	Uint16        loopLimit;

	loopLimit = 0;
	result    = CSL_SOK;

	if (NULL != hEmif)
	{
		if (pReadBuffer != NULL)
		{
			if (FALSE == pack)
			{
				if(spare == 0)
				{
					loopLimit = readRequest/2;
				}
				else
				{
					loopLimit = readRequest;
				}

				for (index = 0; index < loopLimit; index++)
				{
					CSL_NAND_READWORD(hEmif, pReadBuffer[index]);
	            }
	        }
	        else
	        {
				for (index = 0; index < (readRequest/2); index++)
				{
					CSL_NAND_READWORD(hEmif, pReadBuffer[index]);
		        }
	        }
		}
		else
		{
			result = CSL_ESYS_INVPARAMS;
		}
	}
	else
	{
		result = CSL_ESYS_BADHANDLE;
	}

    return (result);
}

/** ============================================================================
 *   @n@b NAND_writeNBytes
 *
 *   @b Description
 *   @n This API writes N number of bytes to a nand physical page.
 *      Number of bytes to be written is sent as an argument to this API.
 *      A page program command should be sent and nand page address
 *      should be set before calling this API. nand device should not be
 *      write-protected for proper functioning of this API.
 *
 *   @b Arguments
 *   @verbatim
            hEmif          Handle to the emif object
            writeRequest   Number of bytes to write
            pWriteBuffer   Write buffer pointer
            val            If a value needs to be wriiten directly without
                           using write buffer
            spare          Spare area flag
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Nand write is successful
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *
 *
 *   <b> Pre Condition </b>
 *   @n  NAND_sendCommand and NAND_setAddress APIs should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Writes the data to nand
 *
 *   @b Modifies
 *   @n Nand write registers
 *
 *   @b Example
 *   @verbatim
            #define  NAND_BUF_SIZE      (1024)

			CSL_Status     status;
			CSL_EmifHandle hEmif;
			Uint32         address;
			Uint16         nandWriteBuf[NAND_BUF_SIZE];

			address = 0x40;
            status = NAND_sendCommand(hEmif,CSL_NAND_CMD_READ_START);
            // Set column address
			status = NAND_setAddress(hEmif,0x00);
	        status = NAND_setAddress(hEmif,0x00);

            // Set row address
			status = NAND_setAddress(hEmif,0x40);
			status = NAND_setAddress(hEmif,0x00);
			status = NAND_setAddress(hEmif,0x00);
            ....
            ....
            status = NAND_writeNBytes(hEmif,NAND_BUF_SIZE,nandWriteBuf,0,0);
     @endverbatim
 *  ============================================================================
 */
CSL_Status NAND_writeNBytes(CSL_EmifHandle     hEmif,
                            Uint16             writeRequest,
                            Uint16             *pWriteBuffer,
                            Uint16             val,
                            Bool			   spare)
{
	CSL_Status result;
    volatile Uint16 countVar;
	volatile Uint16 loopLimit;

	result = CSL_SOK;

    if(NULL != hEmif)
    {
		if(NULL == pWriteBuffer)
		{
			/* if a value 'val' needs to be directly written...*/
        	for (countVar = 0; countVar < writeRequest; countVar++)
        	{
				CSL_NAND_WRITEWORD(hEmif, val);
            }
		}
		else
		{
			/* If the request is for 1 byte...*/
        	if((1u) == writeRequest)
        	{
				CSL_NAND_WRITEWORD(hEmif, *pWriteBuffer);
			}
			else
			{
				/* Check whether number of bytes is multiple of 2 and then write
				 * as bytes into the data register.
				 */
				if((writeRequest % (2u)) != 0)
				{
					for(countVar = 0; countVar < (writeRequest/2); countVar++)
					{
						CSL_NAND_WRITEWORD(hEmif, pWriteBuffer[countVar]);
			        }

			        CSL_NAND_WRITEBYTE(hEmif, (pWriteBuffer[countVar] & 0xFF));
				 }
				 else
				 {
					if(spare == 0)
					{
						loopLimit = writeRequest/2;
					}
					else
					{
						loopLimit = writeRequest;
					}

					for (countVar = 0; countVar < loopLimit; countVar++)
				    {
						CSL_NAND_WRITEWORD(hEmif, pWriteBuffer[countVar]);
					}
				}
			}
		}
    }
    else
    {
		result = CSL_ESYS_BADHANDLE;
	}

    return (result);
}

/** ============================================================================
 *   @n@b NAND_hasRandomRead
 *
 *   @b Description
 *   @n This API is used to check whether a nand device is having random
 *      page read or not. If nand is having random read we can set pointer
 *      to any address in the page and retrieve the data from there.
 *
 *   @b Arguments
 *   @verbatim
            nandOptions    Extra commands for big block nand
            RRstatus       Random read status pointer
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *   @n
 *
 *   <b> Pre Condition </b>
 *   @n  nandOptions information needs to be computed from nand device Id
 *
 *   <b> Post Condition </b>
 *   @n  Random read status is returned in status variable
 *   @li                TRUE     - NAND device is having random read
 *   @li                FALSE    - NAND device is not having random read
 *
 *   @b Modifies
 *   @n Random read status variable
 *
 *   @b Example
 *   @verbatim
 			Uint32    nandOptions;
 			Uint16    RRstatus;

 			//get the nandOptions information from nand device Id
 			NAND_hasRandomRead(nandOptions, &RRstatus);
     @endverbatim
 *  ============================================================================
 */
void NAND_hasRandomRead(Uint32    nandOptions,
                        Uint16    *RRstatus)
{
	Uint16    status;

	if(RRstatus != NULL)
	{
		status = (nandOptions & CSL_NAND_BB_RANDOM_PAGE_READ);

		if(status == CSL_NAND_BB_RANDOM_PAGE_READ)
		{
			*RRstatus = TRUE;
		}
		else
		{
			*RRstatus = FALSE;
		}
	}
}

/** ============================================================================
 *   @n@b NAND_hasRandomWrite
 *
 *   @b Description
 *   @n This API is used to check whether a nand device is having random
 *      page write or not. If nand is having random write we can set pointer
 *      to any address in the page and write the data from there.
 *
 *   @b Arguments
 *   @verbatim
            nandOptions    Extra commands for big block nand
            RWstatus       Random write status pointer
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *   @n
 *
 *   <b> Pre Condition </b>
 *   @n  nandOptions information needs to be computed from nand device Id
 *
 *   <b> Post Condition </b>
 *   @n  Random write status is returned in status variable
 *   @li                TRUE     - NAND device is having random write
 *   @li                FALSE    - NAND device is not having random write
 *
 *   @b Modifies
 *   @n Random write status variable
 *
 *   @b Example
 *   @verbatim
 			Uint32    nandOptions;
 			Uint16    RWstatus;

 			//get the nandOptions information from nand device Id
 			NAND_hasRandomWrite(nandOptions, &RWstatus);
     @endverbatim
 *  ============================================================================
 */
void NAND_hasRandomWrite(Uint32    nandOptions,
                         Uint16    *RWstatus)
{
	Uint16    status;

	if(RWstatus != NULL)
	{
		status = (nandOptions & CSL_NAND_BB_RANDOM_PAGE_WRITE);

		if(status == CSL_NAND_BB_RANDOM_PAGE_WRITE)
		{
			*RWstatus = TRUE;
		}
		else
		{
			*RWstatus = FALSE;
		}
	}
}

/** ============================================================================
 *   @n@b NAND_hasCacheProg
 *
 *   @b Description
 *   @n This API checks whether a nand device supports cache programming
 *      feature or not.
 *
 *   @b Arguments
 *   @verbatim
            nandOptions    Extra commands for big block nand
            CPstatus       Cache program status pointer
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *   @n
 *
 *   <b> Pre Condition </b>
 *   @n  nandOptions information needs to be computed from nand device Id
 *
 *   <b> Post Condition </b>
 *   @n  Cache program status is returned in status variable
 *   @li                TRUE     - NAND device is having cache programming
 *   @li                FALSE    - NAND device is not having cache programming
 *
 *   @b Modifies
 *   @n Cache program status variable
 *
 *   @b Example
 *   @verbatim
 			Uint32    nandOptions;
 			Uint16    CPstatus;

 			//get the nandOptions information from nand device Id
 			NAND_hasCacheProg(nandOptions, &CPstatus);
     @endverbatim
 *  ============================================================================
 */
void NAND_hasCacheProg(Uint32    nandOptions,
                       Uint16    *CPstatus)
{
	Uint16    status;

	if(CPstatus != NULL)
	{
		status = (nandOptions & CSL_NAND_BB_CACHE_PROG);

		if(status == CSL_NAND_BB_CACHE_PROG)
		{
			*CPstatus = TRUE;
		}
		else
		{
			*CPstatus = FALSE;
		}
	}
}

/** ============================================================================
 *   @n@b NAND_hasCopyBack
 *
 *   @b Description
 *   @n This API checks whether a nand device supports copy back
 *      feature or not.
 *
 *   @b Arguments
 *   @verbatim
            nandOptions    Extra commands for big block nand
            CBstatus       Copy back status pointer
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *   @n
 *
 *   <b> Pre Condition </b>
 *   @n  nandOptions information needs to be computed from nand device Id
 *
 *   <b> Post Condition </b>
 *   @n  Copy back status is returned in status variable
 *   @li                TRUE     - NAND device support copy back feature
 *   @li                FALSE    - NAND device does not support copy back feature
 *
 *   @b Modifies
 *   @n Copy back status variable
 *
 *   @b Example
 *   @verbatim
 			Uint32    nandOptions;
 			Uint16    CBstatus;

 			//get the nandOptions information from nand device Id
 			NAND_hasCopyBack(nandOptions, &CBstatus);
     @endverbatim
 *  ============================================================================
 */
void NAND_hasCopyBack(Uint32    nandOptions,
                      Uint16    *CBstatus)
{
	Uint16    status;

	if(CBstatus != NULL)
	{
		status = (nandOptions & CSL_NAND_BB_COPY_BACK);

		if(status == CSL_NAND_BB_COPY_BACK)
		{
			*CBstatus = TRUE;
		}
		else
		{
			*CBstatus = FALSE;
		}
	}
}

/** ============================================================================
 *   @n@b EMIF_intrEnable
 *
 *   @b Description
 *   @n This API enables emif interrupts. This API is used in interrupt
 *      mode of operation of the device.
 *
 *   @b Arguments
 *   @verbatim
            hEmif        Handle to the emif object
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Emif interrupt enable is successful
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *
 *   <b> Pre Condition </b>
 *   @n  EMIF_init should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Enables emif interrupts
 *
 *   @b Modifies
 *   @n Emif interrupt registers
 *
 *   @b Example
 *   @verbatim
            CSL_emifObj    emifObj;
			CSL_Status     status;
			CSL_EmifHandle hEmif;

			status = EMIF_init(&emifObj);
			hEmif  = &emifObj;
			....
			....
            status = EMIF_intrEnable(hEmif);
     @endverbatim
 *  ============================================================================
 */
CSL_Status EMIF_intrEnable(CSL_EmifHandle    hEmif)
{
	CSL_Status    result;

	result = CSL_SOK;

	if(hEmif != NULL)
	{
		/** Enable Wait rise interrupt */
		CSL_FINS(hEmif->regs->EIMSR, EMIF_EIMSR_WRMASKSET, TRUE);
		/** Enable line trap interrupt */
		CSL_FINS(hEmif->regs->EIMSR, EMIF_EIMSR_LTMASKSET, TRUE);
		/** Enable asyncronous time-out interrupt */
		CSL_FINS(hEmif->regs->EIMSR, EMIF_EIMSR_ATMASKSET, TRUE);
	}
	else
	{
		result = CSL_ESYS_BADHANDLE;
	}

    return (result);
}

/** ============================================================================
 *   @n@b EMIF_intrDisable
 *
 *   @b Description
 *   @n This API is used to disable emif interrupts.
 *
 *   @b Arguments
 *   @verbatim
            hEmif        Handle to the emif object
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - emif interrupt disable is successful
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *
 *
 *   <b> Pre Condition </b>
 *   @n  EMIF_intrEnable should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Disables emif interrupts
 *
 *   @b Modifies
 *   @n Emif interrupt registers
 *
 *   @b Example
 *   @verbatim
            CSL_emifObj    emifObj;
			CSL_Status     status;
			CSL_EmifHandle hEmif;

			status = EMIF_init(&emifObj);
			hEmif  = &emifObj;
			....
			....
            status = EMIF_intrEnable(hEmif);
            ...
            ...
            status = EMIF_intrDisable(hEmif);
     @endverbatim
 *  ============================================================================
 */
CSL_Status EMIF_intrDisable(CSL_EmifHandle    hEmif)
{
	CSL_Status    result;

	result = CSL_SOK;

	if(hEmif != NULL)
	{
		/** Disable Wait rise interrupt */
		CSL_FINS(hEmif->regs->EIMCR, EMIF_EIMCR_WRMASKCLR, TRUE);
		/** Disable line trap interrupt */
		CSL_FINS(hEmif->regs->EIMCR, EMIF_EIMCR_LTMASKCLR, TRUE);
		/** Disable asyncronous time-out interrupt */
		CSL_FINS(hEmif->regs->EIMCR, EMIF_EIMCR_ATMASKCLR, TRUE);
	}
	else
	{
		result = CSL_ESYS_BADHANDLE;
	}

    return (result);
}

/** ============================================================================
 *   @n@b EMIF_intrReadAT
 *
 *   @b Description
 *   @n Reads Asynchronous time-out bit of emif interrupt raw register
 *
 *   @b Arguments
 *   @verbatim
            hEmif        Handle to the emif object
            ATstatus     Asynchronous time-out status variable
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Returned for success
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *   @li                    CSL_ESYS_INVPARAMS - Invalid parameter
 *
 *   <b> Pre Condition </b>
 *   @n  EMIF_intrEnable should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Emif asynchronous time-out bit status is returned in status variable
 *
 *   @b Modifies
 *   @n Asynchronous time-out status variable
 *
 *   @b Example
 *   @verbatim
            CSL_emifObj    emifObj;
 			CSL_Status     status;
 			CSL_EmifHandle hEmif;
 			Uint16         ATstatus;

 			status = EMIF_init(&emifObj);
 			hEmif  = &emifObj;
 			....
 			....
            status = EMIF_intrEnable(hEmif);
            ...
            ...
            status = EMIF_intrReadAT(hEmif,&ATstatus);
     @endverbatim
 *  ============================================================================
 */
CSL_Status EMIF_intrReadAT(CSL_EmifHandle    hEmif,
                           Uint16            *ATstatus)
{
	CSL_Status    result;

	result = CSL_SOK;

	if(hEmif != NULL)
	{
		if(ATstatus != NULL)
		{
			*ATstatus = CSL_FEXT(hEmif->regs->EIRR, EMIF_EIRR_AT);
		}
		else
		{
			result = CSL_ESYS_INVPARAMS;
		}
	}
	else
	{
		result = CSL_ESYS_BADHANDLE;
	}

    return (result);
}

/** ============================================================================
 *   @n@b EMIF_intrReadLT
 *
 *   @b Description
 *   @n Reads Line-trap bit of emif interrupt raw register
 *
 *   @b Arguments
 *   @verbatim
            hEmif        Handle to the emif object
            LTstatus     Line trap status variable
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Returned for success
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *   @li                    CSL_ESYS_INVPARAMS - Invalid parameter
 *
 *   <b> Pre Condition </b>
 *   @n  EMIF_intrEnable should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Emif line trap bit status is returned in status variable
 *
 *   @b Modifies
 *   @n Line trap status variable
 *
 *   @b Example
 *   @verbatim
            CSL_emifObj    emifObj;
 			CSL_Status     status;
 			CSL_EmifHandle hEmif;
 			Uint16         LTstatus;

 			status = EMIF_init(&emifObj);
 			hEmif  = &emifObj;
 			....
 			....
            status = EMIF_intrEnable(hEmif);
            ...
            ...
            status = EMIF_intrReadLT(hEmif,&LTstatus);
     @endverbatim
 *  ============================================================================
 */
CSL_Status EMIF_intrReadLT(CSL_EmifHandle    hEmif,
                           Uint16            *LTstatus)
{
	CSL_Status    result;

	result = CSL_SOK;

	if(hEmif != NULL)
	{
		if(LTstatus != NULL)
		{
			*LTstatus = CSL_FEXT(hEmif->regs->EIRR, EMIF_EIRR_LT);
		}
		else
		{
			result = CSL_ESYS_INVPARAMS;
		}
	}
	else
	{
		result = CSL_ESYS_BADHANDLE;
	}

    return (result);
}

/** ============================================================================
 *   @n@b EMIF_intrReadWR
 *
 *   @b Description
 *   @n Reads wait-rise bit of emif interrupt raw register
 *
 *   @b Arguments
 *   @verbatim
            hEmif        Handle to the emif object
            WRstatus     Wait-raise status variable
     @endverbatim
 *
 *   <b> Return Value </b> CSL_Status
 *   @li                    CSL_SOK            - Returned for success
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *   @li                    CSL_ESYS_INVPARAMS - Invalid parameter
 *
 *   <b> Pre Condition </b>
 *   @n  EMIF_intrEnable should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Emif wait-rise bit status is returned in status variable
 *
 *   @b Modifies
 *   @n Wait-rise status variable
 *
 *   @b Example
 *   @verbatim
            CSL_emifObj    emifObj;
 			CSL_Status     status;
 			CSL_EmifHandle hEmif;
 			Uint16         WRstatus;

 			status = EMIF_init(&emifObj);
 			hEmif  = &emifObj;
 			....
 			....
            status = EMIF_intrEnable(hEmif);
            ...
            ...
            status = EMIF_intrReadWR(hEmif,&WRstatus);
     @endverbatim
 *  ============================================================================
 */
CSL_Status EMIF_intrReadWR(CSL_EmifHandle    hEmif,
                           Uint16            *WRstatus)
{
	CSL_Status    result;

	result = CSL_SOK;

	if(hEmif != NULL)
	{
		if(WRstatus != NULL)
		{
			*WRstatus = CSL_FEXT(hEmif->regs->EIRR, EMIF_EIRR_WR);
		}
		else
		{
			result = CSL_ESYS_INVPARAMS;
		}
	}
	else
	{
		result = CSL_ESYS_BADHANDLE;
	}

    return (result);
}

/** ============================================================================
 *   @n@b EMIF_intrClear
 *
 *   @b Description
 *   @n Clears a emif interrupt
 *
 *   @b Arguments
 *   @verbatim
            hEmif        Handle to the emif object
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Returned for success
 *   @li                    CSL_ESYS_BADHANDLE - Invalid handle
 *
 *   <b> Pre Condition </b>
 *   @n  EMIF_intrEnable should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Clears emif interrupt
 *
 *   @b Modifies
 *   @n Emif interrupt mask register
 *
 *   @b Example
 *   @verbatim
            CSL_emifObj    emifObj;
 			CSL_Status     status;
 			CSL_EmifHandle hEmif;
 			Uint16         WRstatus;

 			status = EMIF_init(&emifObj);
 			hEmif  = &emifObj;
 			....
 			....
            status = EMIF_intrEnable(hEmif);
            ...
            ...
            status = EMIF_intrClear(hEmif);
     @endverbatim
 *  ============================================================================
 */
CSL_Status EMIF_intrClear(CSL_EmifHandle    hEmif)
{
	CSL_Status    result;

	result = CSL_SOK;

	if(hEmif != NULL)
	{
		/** Clear Wait rise interrupt */
		CSL_FINS(hEmif->regs->EIMR, EMIF_EIMR_WRMASKED, TRUE);
		/** Clear line trap interrupt */
		CSL_FINS(hEmif->regs->EIMR, EMIF_EIMR_LTMASKED, TRUE);
		/** Clear asyncronous time-out interrupt */
		CSL_FINS(hEmif->regs->EIMR, EMIF_EIMR_ATMASKED, TRUE);
	}
	else
	{
		result = CSL_ESYS_BADHANDLE;
	}

    return (result);
}


