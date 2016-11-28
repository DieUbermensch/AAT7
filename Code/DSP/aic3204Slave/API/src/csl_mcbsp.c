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


/** @file csl_mcbsp.c
 *
 *  @brief McBSP functional layer API source file
 *
 *  Path: \\(CSLPATH)\\src
 */

/* ============================================================================
 * Revision History
 * ================
 * 25-Jun-2012 Added McBSP to CSL
 * 13-Sep-2012 CSL v3.00 release
 * 20-Dec-2012 CSL v3.01 release
 * 10-Mar-2016 CSL v3.05 release
 * ============================================================================
 */
#include "cslr_mcbsp.h"
#include "cslr_sysctrl.h"
#include "csl_mcbsp.h"


#ifdef CHIP_C5517

/** ============================================================================
 *   @n@b MCBSP_reset
 *
 *   @b Description
 *   @n Reset the McBSP CSL module and all its registers
 *
 *   @b Arguments
 *   @verbatim
            hMcbsp		  Handle to the McBSP
     @endverbatim
 *
 *   <b> Return Value </b>  N/A
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n   MCBSP registers reset to default values
 *
 *   @b Modifies
 *   @n MCBSP registers
 *
 *   @b Example
 *   @verbatim
            CSL_McbspHandle hMcbsp;
     @endverbatim
 *  ============================================================================
 */
void MCBSP_reset(CSL_McbspHandle hMcbsp)
{
   Uint16 k=0;


 CSL_FINS(hMcbsp->sysRegs->PRCR, SYS_PRCR_MCBSP_RST, CSL_SYS_PRCR_MCBSP_RST_RST);


 hMcbsp->sysRegs->CLKSTOP1 = (Uint16) (((hMcbsp->sysRegs->CLKSTOP1 & 0xFFBF) | 0x0000));
  for(k=0;k<5;k++) { __asm("    NOP"); }

//McBSP registers
 hMcbsp->Regs->SPCRL   	= CSL_MCBSP_SPCRL_RESETVAL;
 hMcbsp->Regs->SPCRU   	= CSL_MCBSP_SPCRU_RESETVAL;
 hMcbsp->Regs->RCRL    	= CSL_MCBSP_RCRL_RESETVAL;
 hMcbsp->Regs->RCRU    	= CSL_MCBSP_RCRU_RESETVAL;
 hMcbsp->Regs->XCRL	 	= CSL_MCBSP_XCRL_RESETVAL;
 hMcbsp->Regs->XCRU    	= CSL_MCBSP_XCRU_RESETVAL;
 hMcbsp->Regs->SRGRL   	= CSL_MCBSP_SRGRL_RESETVAL;
 hMcbsp->Regs->SRGRU   	= CSL_MCBSP_SRGRU_RESETVAL;
 hMcbsp->Regs->MCRL    	= CSL_MCBSP_MCRL_RESETVAL;
 hMcbsp->Regs->MCRU    	= CSL_MCBSP_MCRU_RESETVAL;
 hMcbsp->Regs->RCERA 	= CSL_MCBSP_RCERA_RESETVAL;
 hMcbsp->Regs->RCERB 	= CSL_MCBSP_RCERB_RESETVAL;
 hMcbsp->Regs->XCERA 	= CSL_MCBSP_XCERA_RESETVAL;
 hMcbsp->Regs->XCERB 	= CSL_MCBSP_XCERB_RESETVAL;
 hMcbsp->Regs->RCERA 	= CSL_MCBSP_RCERA_RESETVAL;
 hMcbsp->Regs->RCERB 	= CSL_MCBSP_RCERB_RESETVAL;
 hMcbsp->Regs->PCRL    	= CSL_MCBSP_PCRL_RESETVAL;
 hMcbsp->Regs->RCERC 	= CSL_MCBSP_RCERC_RESETVAL;
 hMcbsp->Regs->RCERD 	= CSL_MCBSP_RCERD_RESETVAL;
 hMcbsp->Regs->XCERC 	= CSL_MCBSP_XCERC_RESETVAL;
 hMcbsp->Regs->XCERD 	= CSL_MCBSP_XCERD_RESETVAL;
 hMcbsp->Regs->RCERE 	= CSL_MCBSP_RCERE_RESETVAL;
 hMcbsp->Regs->RCERF 	= CSL_MCBSP_RCERF_RESETVAL;
 hMcbsp->Regs->XCERE 	= CSL_MCBSP_XCERE_RESETVAL;
 hMcbsp->Regs->XCERF 	= CSL_MCBSP_XCERF_RESETVAL;
 hMcbsp->Regs->RCERG 	= CSL_MCBSP_RCERG_RESETVAL;
 hMcbsp->Regs->RCERH 	= CSL_MCBSP_RCERH_RESETVAL;
 hMcbsp->Regs->XCERG 	= CSL_MCBSP_XCERG_RESETVAL;
 hMcbsp->Regs->XCERH 	= CSL_MCBSP_XCERH_RESETVAL;
}


/** ============================================================================
 *   @n@b MCBSP_open
 *
 *   @b Description
 *   @n Open the handle to the McBSP CSL module
 *
 *   @b Arguments
 *   @verbatim
            instance      MCBSP Hardware instance number
            McbspObj	  MCBSP CSL object
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
 *   @n  Initializes MCBSP module
 *
 *   @b Modifies
 *   @n MCBSP Object structure
 *
 *   @b Example
 *   @verbatim
            CSL_McbspHandle hMcbsp;
            hMcbsp =  MCBSP_open(CSL_McbspInsId instance,
						   CSL_McbspObj *McbspObj,
						   CSL_Status 	*status)
     @endverbatim
 *  ============================================================================
 */

CSL_McbspHandle MCBSP_open(CSL_McbspInsId instance,
						   CSL_McbspObj *McbspObj,
						   CSL_Status 	*status)
{

 CSL_McbspHandle hMcbsp;

 *status = CSL_SOK;
 hMcbsp = NULL;

 if(NULL == McbspObj)
 {
	*status = CSL_ESYS_BADHANDLE;
	return (hMcbsp);
 }

 if((instance<CSL_MCBSP_INST_0) || (instance>=CSL_MCBSP_INST_INVALID))
 {
     *status = CSL_ESYS_BADHANDLE;
	 return (hMcbsp);
 }

 hMcbsp = McbspObj;

 switch (instance)
 {
	case CSL_MCBSP_INST_0:
				hMcbsp->insId	 		= CSL_MCBSP_INST_0;
				hMcbsp->Regs			= CSL_MCBSP_REGS;
 				hMcbsp->sysRegs 		= CSL_SYSCTRL_REGS;
    			break;
	default:
			*status = CSL_ESYS_INVPARAMS;
 }

 CSL_FINS(hMcbsp->sysRegs->PCGCR1, SYS_PCGCR1_MCBSPCG, CSL_SYS_PCGCR1_MCBSPCG_ACTIVE);
// CSL_FINS(hMcbsp->sysRegs->EBSR,SYS_EBSR_SP0MODE,CSL_SYS_EBSR_SP0MODE_MODE3);

 // Below lines added by Chandra
  //Desassert clk stop request to mcbsp
 hMcbsp->sysRegs->CLKSTOP1 = (Uint16) (((hMcbsp->sysRegs->CLKSTOP1 & 0xFFBF) | 0x0000));
  // Wait until the clk stop ack is deasserted
 while ((hMcbsp->sysRegs->CLKSTOP1 & 0x0080) != (Uint16) 0x0000 )  {
     __asm("    NOP");
     }

 MCBSP_reset(hMcbsp); // resets all the registers to their default values

 return (hMcbsp);
}

/** ============================================================================
 *   @n@b MCBSP_close
 *
 *   @b Description
 *   @n Close the handle to MCBSP and stops the clock to MCBSP
 *
 *   @b Arguments
 *   @verbatim
             CSL_McbspHandle      MCBSP Handle
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Returned for success
 *							CSL_ESYS_BADHANDLE - Bad handle passed
 *
 *   <b> Pre Condition </b>
 *   @n  MCBSP_open should be called successfully.
 *   @n  None
 *
 *   <b> Post Condition </b>
 *
 *
 *   @b Example
 *   @verbatim
            Status = MCBSP_close(hMcbsp);
			if( Status != CSL_SOK )
			{
			 printf("MCBSP_close is failed\r\n");
			}
     @endverbatim
 *  ============================================================================
 */
CSL_Status MCBSP_close(CSL_McbspHandle hMcbsp)
{

  if( NULL == hMcbsp )
  {
	return CSL_ESYS_BADHANDLE;
  }


  /* RESET transmitter,receiver and frame sync*/
  CSL_FINST(hMcbsp->Regs->SPCRL,MCBSP_SPCRL_RRST,ENABLE);
  CSL_FINST(hMcbsp->Regs->SPCRU,MCBSP_SPCRU_XRST,ENABLE);
  CSL_FINST(hMcbsp->Regs->SPCRU,MCBSP_SPCRU_FRST,RESET);
  CSL_FINST(hMcbsp->Regs->SPCRU,MCBSP_SPCRU_GRST,RESET);

  /*Reset McBSP*/
  CSL_FINS(hMcbsp->sysRegs->PRCR, SYS_PRCR_MCBSP_RST, CSL_SYS_PRCR_MCBSP_RST_RST);

  /*Stop the clock and release the serial port */
  CSL_FINS(hMcbsp->sysRegs->PCGCR1,SYS_PCGCR1_MCBSPCG,CSL_SYS_PCGCR1_MCBSPCG_DISABLED);
  CSL_FINS(hMcbsp->sysRegs->EBSR,SYS_EBSR_SP0MODE,CSL_SYS_EBSR_SP0MODE_MODE0);

  /* Close the handle */
  hMcbsp = NULL;

  return(CSL_SOK);
}

/** ============================================================================
 *   @n@b Mcbsp_Configure
 *
 *   @b Description
 *   @n Configures the MCBSP CSL module
 *
 *   @b Arguments
 *   @verbatim
            CSL_McbspHandle      MCBSP Handle
			CSL_McbspSetup	 	 McBSP configuration structure
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Returned for success
 *   @li                    CSL_ESYS_INVPARAMS - Invalid parameter
 *
 *   <b> Pre Condition </b>
 *   @n  MCBSP_open should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Initializes McBSP with the configuration structure
 *
 *   @b Modifies
 *   @n MCBSP Object structure
 *
 *   @b Example
 *   @verbatim
            CSL_Status    status;
            status = Mcbsp_Configure(hMcbsp,&ConfigLoopBack32);
     @endverbatim
 *  ============================================================================
 */
CSL_Status Mcbsp_Configure(CSL_McbspHandle hMcbsp,CSL_McbspSetup *mcbspSetup)
{

	CSL_Status         status;

	status = CSL_SOK;
	/* Checking for the correct argument for the phase */
	switch(mcbspSetup->phase)
	{
			case CSL_MCBSP_SINGLEPHASE:
				CSL_FINST(hMcbsp->Regs->RCRU,MCBSP_RCRU_RPHASE,SINGLEPHASE);
				CSL_FINST(hMcbsp->Regs->XCRU,MCBSP_XCRU_XPHASE,SINGLEPHASE);
				 break;
			case CSL_MCBSP_DUALPHASE:
				CSL_FINST(hMcbsp->Regs->RCRU,MCBSP_RCRU_RPHASE,DUALPHASE);
				CSL_FINST(hMcbsp->Regs->XCRU,MCBSP_XCRU_XPHASE,DUALPHASE);
				 break;
			default: status=CSL_ESYS_INVPARAMS;
				return(status);
	}

	//fRAME LENGTH SETTING
	CSL_FINS(hMcbsp->Regs->RCRL,MCBSP_RCRL_RFRLEN1,mcbspSetup->frameLength);
	CSL_FINS(hMcbsp->Regs->XCRL,MCBSP_XCRL_XFRLEN1,mcbspSetup->frameLength);
	if(mcbspSetup->phase == CSL_MCBSP_DUALPHASE)
    {
	 CSL_FINS(hMcbsp->Regs->RCRU,MCBSP_RCRU_RFRLEN2,mcbspSetup->frameLength);
	 CSL_FINS(hMcbsp->Regs->XCRU,MCBSP_XCRU_XFRLEN2,mcbspSetup->frameLength);
	}

	switch(mcbspSetup->wordLength)
		{
			case CSL_MCBSP_WORD8:
				 CSL_FINST(hMcbsp->Regs->RCRL,MCBSP_RCRL_RWDLEN1,8BITS);
				 CSL_FINST(hMcbsp->Regs->XCRL,MCBSP_XCRL_XWDLEN1,8BITS);
				 if(mcbspSetup->phase == CSL_MCBSP_DUALPHASE)
				 {
				  CSL_FINST(hMcbsp->Regs->RCRU,MCBSP_RCRU_RWDLEN2,8BITS);
				  CSL_FINST(hMcbsp->Regs->XCRU,MCBSP_RCRU_RWDLEN2,8BITS);
				 }
				 break;
			case CSL_MCBSP_WORD12:
				 CSL_FINST(hMcbsp->Regs->RCRL,MCBSP_RCRL_RWDLEN1,12BITS);
				 CSL_FINST(hMcbsp->Regs->XCRL,MCBSP_XCRL_XWDLEN1,12BITS);
				 if(mcbspSetup->phase == CSL_MCBSP_DUALPHASE)
				 {
				  CSL_FINST(hMcbsp->Regs->RCRU,MCBSP_RCRU_RWDLEN2,12BITS);
				  CSL_FINST(hMcbsp->Regs->XCRU,MCBSP_RCRU_RWDLEN2,12BITS);
				 }
				 break;
			case CSL_MCBSP_WORD16:
				 CSL_FINST(hMcbsp->Regs->RCRL,MCBSP_RCRL_RWDLEN1,16BITS);
				 CSL_FINST(hMcbsp->Regs->XCRL,MCBSP_XCRL_XWDLEN1,16BITS);
				 if(mcbspSetup->phase == CSL_MCBSP_DUALPHASE)
				 {
				  CSL_FINST(hMcbsp->Regs->RCRU,MCBSP_RCRU_RWDLEN2,16BITS);
				  CSL_FINST(hMcbsp->Regs->XCRU,MCBSP_RCRU_RWDLEN2,16BITS);
				 }
				 break;
			case CSL_MCBSP_WORD20:
				 CSL_FINST(hMcbsp->Regs->RCRL,MCBSP_RCRL_RWDLEN1,20BITS);
				 CSL_FINST(hMcbsp->Regs->XCRL,MCBSP_XCRL_XWDLEN1,20BITS);
				 if(mcbspSetup->phase == CSL_MCBSP_DUALPHASE)
				 {
				  CSL_FINST(hMcbsp->Regs->RCRU,MCBSP_RCRU_RWDLEN2,20BITS);
				  CSL_FINST(hMcbsp->Regs->XCRU,MCBSP_RCRU_RWDLEN2,20BITS);
				 }
				 break;
			case CSL_MCBSP_WORD24:
				 CSL_FINST(hMcbsp->Regs->RCRL,MCBSP_RCRL_RWDLEN1,24BITS);
				 CSL_FINST(hMcbsp->Regs->XCRL,MCBSP_XCRL_XWDLEN1,24BITS);
				 if(mcbspSetup->phase == CSL_MCBSP_DUALPHASE)
				 {
				  CSL_FINST(hMcbsp->Regs->RCRU,MCBSP_RCRU_RWDLEN2,24BITS);
				  CSL_FINST(hMcbsp->Regs->XCRU,MCBSP_RCRU_RWDLEN2,24BITS);
				 }
				 break;
			case CSL_MCBSP_WORD32:
				 CSL_FINST(hMcbsp->Regs->RCRL,MCBSP_RCRL_RWDLEN1,32BITS);
				 CSL_FINST(hMcbsp->Regs->XCRL,MCBSP_XCRL_XWDLEN1,32BITS);
				 if(mcbspSetup->phase == CSL_MCBSP_DUALPHASE)
				 {
				  CSL_FINST(hMcbsp->Regs->RCRU,MCBSP_RCRU_RWDLEN2,32BITS);
				  CSL_FINST(hMcbsp->Regs->XCRU,MCBSP_RCRU_RWDLEN2,32BITS);
				 }
				 break;
			default: status=CSL_ESYS_INVPARAMS;
				return(status);
		}

	switch(mcbspSetup->datadelay)
		{
			case CSL_MCBSP_DATADELAY0BIT:
				CSL_FINST(hMcbsp->Regs->RCRU,MCBSP_RCRU_RDATDLY,0BIT);
				CSL_FINST(hMcbsp->Regs->XCRU,MCBSP_XCRU_XDATDLY,0BIT);
				break;
			case CSL_MCBSP_DATADELAY1BIT:
				CSL_FINST(hMcbsp->Regs->RCRU,MCBSP_RCRU_RDATDLY,1BIT);
				CSL_FINST(hMcbsp->Regs->XCRU,MCBSP_XCRU_XDATDLY,1BIT);
				break;
			case CSL_MCBSP_DATADELAY2BIT:
				CSL_FINST(hMcbsp->Regs->RCRU,MCBSP_RCRU_RDATDLY,2BIT);
				CSL_FINST(hMcbsp->Regs->XCRU,MCBSP_XCRU_XDATDLY,2BIT);
				break;
			default: status=CSL_ESYS_INVPARAMS;
				return(status);
		}

	switch(mcbspSetup->clocksource)
		{
			case CSL_MCBSP_CLOCKSOURCE_SYSCLK:
				CSL_FINST(hMcbsp->Regs->SRGRU,MCBSP_SRGRU_CLKSM,ONE);
				CSL_FINST(hMcbsp->Regs->PCRL,MCBSP_PCRL_SCLKME,ZERO);
				break;
			case CSL_MCBSP_CLOCKSOURCE_CLKS:
				CSL_FINST(hMcbsp->Regs->SRGRU,MCBSP_SRGRU_CLKSM,ZERO);
				CSL_FINST(hMcbsp->Regs->PCRL,MCBSP_PCRL_SCLKME,ZERO);
				break;
			case CSL_MCBSP_CLOCKSOURCE_CLKR:
				CSL_FINST(hMcbsp->Regs->SRGRU,MCBSP_SRGRU_CLKSM,ZERO);
				CSL_FINST(hMcbsp->Regs->PCRL,MCBSP_PCRL_SCLKME,ONE);
				break;
			case CSL_MCBSP_CLOCKSOURCE_CLKX:
				CSL_FINST(hMcbsp->Regs->SRGRU,MCBSP_SRGRU_CLKSM,ONE);
				CSL_FINST(hMcbsp->Regs->PCRL,MCBSP_PCRL_SCLKME,ONE);
				break;
			default: status=CSL_ESYS_INVPARAMS;
				return(status);

		}

	switch(mcbspSetup->intr_event)
		{
			case CSL_MCBSP_INTR_RDY:
				CSL_FINST(hMcbsp->Regs->SPCRL,MCBSP_SPCRL_RINTM,RRDY);
				CSL_FINST(hMcbsp->Regs->SPCRU,MCBSP_SPCRU_XINTM,XRDY);
				break;
			case CSL_MCBSP_INTR_EOF:
				CSL_FINST(hMcbsp->Regs->SPCRL,MCBSP_SPCRL_RINTM,EOF);
				CSL_FINST(hMcbsp->Regs->SPCRU,MCBSP_SPCRU_XINTM,EOF);
				break;
			case CSL_MCBSP_INTR_NEWFS:
				CSL_FINST(hMcbsp->Regs->SPCRL,MCBSP_SPCRL_RINTM,NEWFS);
				CSL_FINST(hMcbsp->Regs->SPCRU,MCBSP_SPCRU_XINTM,NEWFS);

				break;
			case CSL_MCBSP_INTR_SYNCERR:
				CSL_FINST(hMcbsp->Regs->SPCRL,MCBSP_SPCRL_RINTM,SYNCERR);
				CSL_FINST(hMcbsp->Regs->SPCRU,MCBSP_SPCRU_XINTM,SYNCERR);
				break;
			default: status=CSL_ESYS_INVPARAMS;
				return(status);

		}

	switch(mcbspSetup->frameignore)
		{
			case CSL_MCBSP_FRMAEIGNORETRUE:
				CSL_FINST(hMcbsp->Regs->RCRU,MCBSP_RCRU_RFIG,ENABLE);
				CSL_FINST(hMcbsp->Regs->XCRU,MCBSP_XCRU_XFIG,ENABLE);
				break;
			case CSL_MCBSP_FRMAEIGNOREFALSE:
				CSL_FINST(hMcbsp->Regs->RCRU,MCBSP_RCRU_RFIG,DISABLE);
				CSL_FINST(hMcbsp->Regs->XCRU,MCBSP_XCRU_XFIG,DISABLE);
				break;
			default: status=CSL_ESYS_INVPARAMS;
				return(status);
		}

   	switch(mcbspSetup->companding)
	{
			case CSL_MCBSP_COFF_MSBFIRST:
				CSL_FINST(hMcbsp->Regs->RCRU,MCBSP_RCRU_RCOMPAND,NCMSBFIRST);
				CSL_FINST(hMcbsp->Regs->XCRU,MCBSP_XCRU_XCOMPAND,NCMSBFIRST);
				 break;
			case CSL_MCBSP_COFF_LSBFIRST:
				CSL_FINST(hMcbsp->Regs->RCRU,MCBSP_RCRU_RCOMPAND,NCLSBFIRST);
				CSL_FINST(hMcbsp->Regs->XCRU,MCBSP_XCRU_XCOMPAND,NCLSBFIRST);
				 break;
			case CSL_MCBSP_CON_ULAW:
				CSL_FINST(hMcbsp->Regs->RCRU,MCBSP_RCRU_RCOMPAND,CULAW);
				CSL_FINST(hMcbsp->Regs->XCRU,MCBSP_XCRU_XCOMPAND,CULAW);
				 break;
			case CSL_MCBSP_CON_ALAW:
				CSL_FINST(hMcbsp->Regs->RCRU,MCBSP_RCRU_RCOMPAND,CALAW);
				CSL_FINST(hMcbsp->Regs->XCRU,MCBSP_XCRU_XCOMPAND,CALAW);
				 break;
			default: status=CSL_ESYS_INVPARAMS;
				return(status);
	}

	switch(mcbspSetup->rjust_mode)
	{
			case CSL_MCBSP_RJUST_RJZFMSB:
				CSL_FINST(hMcbsp->Regs->SPCRL,MCBSP_SPCRL_RJUST,RJZFMSB);
			    break;
			case CSL_MCBSP_RJUST_RJSEMSB:
				CSL_FINST(hMcbsp->Regs->SPCRL,MCBSP_SPCRL_RJUST,RJSEMSB);
				break;
			case CSL_MCBSP_RJUST_LJZFLSB:
                               // Below line modified by Chandra. Needs review
				CSL_FINST(hMcbsp->Regs->SPCRL,MCBSP_SPCRL_RJUST,LJZFLSB);
				break;
			default: status=CSL_ESYS_INVPARAMS;
				return(status);
	}

	switch(mcbspSetup->mcbsp_opmode)
	{
			case CSL_MCBSP_OPMODE_NORMAL:
				CSL_FINST(hMcbsp->Regs->MCRL,MCBSP_MCRL_RMCME,ZERO);
				CSL_FINST(hMcbsp->Regs->MCRU,MCBSP_MCRU_XMCME,ZERO);
				CSL_FINST(hMcbsp->Regs->MCRL,MCBSP_MCRL_RMCM,ZERO);
				CSL_FINST(hMcbsp->Regs->MCRU,MCBSP_MCRU_XMCM,ZERO);
				CSL_FINST(hMcbsp->Regs->MCRL,MCBSP_MCRL_REMODE,ZERO);
				CSL_FINST(hMcbsp->Regs->MCRU,MCBSP_MCRU_XEMODE,ZERO);

				CSL_FINS(hMcbsp->Regs->SRGRU,MCBSP_SRGRU_FPER,mcbspSetup->wordLength);
			    break;
			case CSL_MCBSP_OPMODE_32CHANNEL:
				CSL_FINST(hMcbsp->Regs->MCRL,MCBSP_MCRL_RMCME,ZERO);
				CSL_FINST(hMcbsp->Regs->MCRU,MCBSP_MCRU_XMCME,ZERO);
				CSL_FINST(hMcbsp->Regs->MCRL,MCBSP_MCRL_RMCM,ONE);
				CSL_FINST(hMcbsp->Regs->MCRU,MCBSP_MCRU_XMCM,ONE);
				CSL_FINST(hMcbsp->Regs->MCRL,MCBSP_MCRL_REMODE,ZERO);
				CSL_FINST(hMcbsp->Regs->MCRU,MCBSP_MCRU_XEMODE,ZERO);

			  CSL_MCBSP_REGS->RCERA = (Uint16) (0xFFFF);
			  CSL_MCBSP_REGS->RCERB = (Uint16) (0xFFFF);

			  CSL_MCBSP_REGS->XCERA = (Uint16) (0xFFFF);
			  CSL_MCBSP_REGS->XCERB = (Uint16) (0xFFFF);
				CSL_FINS(hMcbsp->Regs->SRGRU,MCBSP_SRGRU_FPER,(((mcbspSetup->wordLength)*(mcbspSetup->frameLength + 1))-1));
				break;
			case CSL_MCBSP_OPMODE_128CHANNEL:
				CSL_FINST(hMcbsp->Regs->MCRL,MCBSP_MCRL_RMCME,ONE);
				CSL_FINST(hMcbsp->Regs->MCRU,MCBSP_MCRU_XMCME,ONE);
				CSL_FINST(hMcbsp->Regs->MCRL,MCBSP_MCRL_RMCM,ZERO);
				CSL_FINST(hMcbsp->Regs->MCRU,MCBSP_MCRU_XMCM,ZERO);
				CSL_FINST(hMcbsp->Regs->MCRL,MCBSP_MCRL_REMODE,ZERO);
				CSL_FINST(hMcbsp->Regs->MCRU,MCBSP_MCRU_XEMODE,ZERO);
			  CSL_MCBSP_REGS->RCERA = (Uint16) (0xFFFF);
			  CSL_MCBSP_REGS->RCERB = (Uint16) (0xFFFF);

			  CSL_MCBSP_REGS->XCERA = (Uint16) (0xFFFF);
			  CSL_MCBSP_REGS->XCERB = (Uint16) (0xFFFF);

			  CSL_MCBSP_REGS->RCERC = (Uint16) (0xFFFF);
			  CSL_MCBSP_REGS->RCERD = (Uint16) (0xFFFF);

			  CSL_MCBSP_REGS->XCERC = (Uint16) (0xFFFF);
			  CSL_MCBSP_REGS->XCERD = (Uint16) (0xFFFF);

			  CSL_MCBSP_REGS->RCERE = (Uint16) (0xFFFF);
			  CSL_MCBSP_REGS->RCERF = (Uint16) (0xFFFF);

			  CSL_MCBSP_REGS->XCERE = (Uint16) (0xFFFF);
			  CSL_MCBSP_REGS->XCERF = (Uint16) (0xFFFF);

			  CSL_MCBSP_REGS->RCERG = (Uint16) (0xFFFF);
			  CSL_MCBSP_REGS->RCERH = (Uint16) (0xFFFF);

			  CSL_MCBSP_REGS->XCERG = (Uint16) (0xFFFF);
			  CSL_MCBSP_REGS->XCERH = (Uint16) (0xFFFF);
				CSL_FINS(hMcbsp->Regs->SRGRU,MCBSP_SRGRU_FPER,(((mcbspSetup->wordLength)*(mcbspSetup->frameLength + 1))-1));

				break;
			case CSL_MCBSP_OPMODE_512CHANNEL:status=CSL_ESYS_INVPARAMS;
				return(status);
			default: status=CSL_ESYS_INVPARAMS;
				return(status);
	}

	switch(mcbspSetup->fsxpin_status)
	{
			case CSL_MCBSP_FSX_FSXPINIP:
				CSL_FINST(hMcbsp->Regs->PCRL,MCBSP_PCRL_FSXM,ZERO);
				CSL_FINST(hMcbsp->Regs->SRGRU,MCBSP_SRGRU_FSGM,ZERO);
			    break;
			case CSL_MCBSP_FSX_SRGOP:
				CSL_FINST(hMcbsp->Regs->PCRL,MCBSP_PCRL_FSXM,ONE);
				CSL_FINST(hMcbsp->Regs->SRGRU,MCBSP_SRGRU_FSGM,ONE);
				break;
			case CSL_MCBSP_FSX_DXRTOXSRCPYOP:
				CSL_FINST(hMcbsp->Regs->PCRL,MCBSP_PCRL_FSXM,ONE);
				CSL_FINST(hMcbsp->Regs->SRGRU,MCBSP_SRGRU_FSGM,ZERO);
				break;

			default: status=CSL_ESYS_INVPARAMS;
				return(status);
	}


	if( mcbspSetup->abismode == CSL_MCBSP_ABIS_ENABLE )
	{
		CSL_FINST(hMcbsp->Regs->SPCRL,MCBSP_SPCRL_ABIS,ENABLE);
	}
	else if( mcbspSetup->abismode == CSL_MCBSP_ABIS_DISABLE )
	{
		CSL_FINST(hMcbsp->Regs->SPCRL,MCBSP_SPCRL_ABIS,DISABLE);
	}

	if( mcbspSetup->loopBackmode == CSL_MCBSP_INTERNALLOOPBACK_ENABLE )
	{
		CSL_FINST(hMcbsp->Regs->SPCRL,MCBSP_SPCRL_DLB,ENABLE);
	}
	else if( mcbspSetup->loopBackmode == CSL_MCBSP_INTERNALLOOPBACK_DISABLE )
	{
		CSL_FINST(hMcbsp->Regs->SPCRL,MCBSP_SPCRL_DLB,DISABLE);
	}

	/*DXENA*/
	if( mcbspSetup->dxena == CSL_MCBSP_DXENA_ENABLE )
	{
		CSL_FINST(hMcbsp->Regs->SPCRL,MCBSP_SPCRL_DXENA,ON);
	}
	else if( mcbspSetup->dxena == CSL_MCBSP_DXENA_DISABLE )
	{
		CSL_FINST(hMcbsp->Regs->SPCRL,MCBSP_SPCRL_DXENA,OFF);
	}

	/*CLKSTP*/
	if( mcbspSetup->clkstp == CSL_MCBSP_CLKSTP_WITHDELAY )
	{
		CSL_FINST(hMcbsp->Regs->SPCRL,MCBSP_SPCRL_CLKSTP,WITHDELAY);
	}
	else if( mcbspSetup->clkstp == CSL_MCBSP_CLKSTP_WITHOUTDELAY )
	{
		CSL_FINST(hMcbsp->Regs->SPCRL,MCBSP_SPCRL_CLKSTP,WITHOUTDELAY);
	}

	/*DATA CLOCK POLARITY*/
	if( mcbspSetup->sample_polarity == CSL_MCBSP_DATASAMPLE_RISING )
	{
		CSL_FINST(hMcbsp->Regs->PCRL,MCBSP_PCRL_CLKRP,RISINGEDGE);
		CSL_FINST(hMcbsp->Regs->PCRL,MCBSP_PCRL_CLKXP,FALLINGEDGE);
	}
	else if( mcbspSetup->sample_polarity == CSL_MCBSP_DATASAMPLE_FALLING )
	{
		CSL_FINST(hMcbsp->Regs->PCRL,MCBSP_PCRL_CLKRP,FALLINGEDGE);
		CSL_FINST(hMcbsp->Regs->PCRL,MCBSP_PCRL_CLKXP,RISINGEDGE);
	}


	/*FRAME SYNC POLARITY*/
	if( mcbspSetup->fs_polarity == CSL_MCBSP_FS_ACTIVEHIGH )
	{
		CSL_FINST(hMcbsp->Regs->PCRL,MCBSP_PCRL_FSRP,ACTIVEHIGH);
		CSL_FINST(hMcbsp->Regs->PCRL,MCBSP_PCRL_FSXP,ACTIVEHIGH);
	}
	else if( mcbspSetup->fs_polarity == CSL_MCBSP_FS_ACTIVELOW )
	{
		CSL_FINST(hMcbsp->Regs->PCRL,MCBSP_PCRL_FSRP,ACTIVELOW);
		CSL_FINST(hMcbsp->Regs->PCRL,MCBSP_PCRL_FSXP,ACTIVELOW);
	}

	/* Setting the sample rate */
	//((clkInput/(sample_rate*wordLength)) - 1)
	CSL_FINS(hMcbsp->Regs->SRGRL,MCBSP_SRGRL_CLKGDV,((mcbspSetup->clkInput/(mcbspSetup->sample_rate * mcbspSetup->wordLength)) - 1));

	/*Not handled as a CSL argument. */
	CSL_FINS(hMcbsp->Regs->SRGRL,MCBSP_SRGRL_FWID,0);

	/*Not handled in CSl CLKSP and GSYNC of SRGRU */
	CSL_FINS(hMcbsp->Regs->SRGRU,MCBSP_SRGRU_CLKSP,0);
	CSL_FINS(hMcbsp->Regs->SRGRU,MCBSP_SRGRU_GSYNC,0);

	/*Not handled bits in PCR by CSL */
	CSL_FINST(hMcbsp->Regs->PCRL,MCBSP_PCRL_CLKXM,ONE);
	CSL_FINST(hMcbsp->Regs->PCRL,MCBSP_PCRL_CLKRM,ZERO);
    return (status);
}


/** ============================================================================
 *   @n@b MCBSP_start
 *
 *   @b Description
 *   @n Close the handle to UHPI and stops the clock to UHPI
 *
 *   @b Arguments
 *   @verbatim
            CSL_McbspHandle      MCBSP Handle
			Uint16 				 StartMask
			Uint32 			     SampleRateDelay
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Returned for success
 *							CSL_ESYS_BADHANDLE - Bad handle passed
							CSL_ESYS_INVPARAMS - Invalid parameter
 *
 *   <b> Pre Condition </b>
 *   @n  MCBSP_open should be called successfully.
 *   @n  None
 *
 *   <b> Post Condition </b>
 *
 *
 *   @b Example
 *   @verbatim

            Status = MCBSP_start(hMcbsp,StartMask,SampleRateDelay);
			if( Status != CSL_SOK )
			{
			 printf("MCBSP_start is failed\r\n");
			}
     @endverbatim
 *  ============================================================================
 */
CSL_Status MCBSP_start( CSL_McbspHandle hMcbsp, Uint16 StartMask, Uint32 SampleRateDelay )
{
  CSL_Status status;
  unsigned char flag=1;

  // compiler should not optimize delay loop under -o3 switch
  volatile Uint32 count = SampleRateDelay;

  status = CSL_SOK;
  if (StartMask & MCBSP_SRGR_START) {
    CSL_FINST(hMcbsp->Regs->SPCRU,MCBSP_SPCRU_GRST,NOTRESET);
    while (count > 0)  {
           --count;
     }
	 flag=0;
  }

  if (StartMask & MCBSP_RCV_START) {
	CSL_FINST(hMcbsp->Regs->SPCRL,MCBSP_SPCRL_RRST,ENABLE);
	flag=0;
  }

  if (StartMask & MCBSP_XMIT_START) {
    CSL_FINST(hMcbsp->Regs->SPCRU,MCBSP_SPCRU_XRST,ENABLE);
	flag=0;
  }

 if (StartMask & MCBSP_SRGR_FRAMESYNC) {
    CSL_FINST(hMcbsp->Regs->SPCRU,MCBSP_SPCRU_FRST,NOTRESET);
	flag=0;
  }
  if( flag == 1 )
  {
	status = CSL_ESYS_INVPARAMS;
  }

 return(status);
}
/** ============================================================================
 *   @n@b MCBSP_read32
 *
 *   @b Description
 *   @n This function reads the data from the Data Receive Register
 *
 *   @b Arguments
 *   @verbatim
            CSL_McbspHandle      MCBSP Handle
     @endverbatim
 *
 *   <b> Return Value </b>  val
 *   @li                    32 bits from DRR
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *	 @n	 Data read from DRR
 *
 *   @b Example
 *   @verbatim

            value = MCBSP_read32(CSL_McbspHandle hMcbsp)
     @endverbatim
 *  ============================================================================
 */
Uint32 MCBSP_read32(CSL_McbspHandle hMcbsp)
{
  Uint32 drr2, drr1;
  Uint32 val;
  drr2 = hMcbsp->Regs->DRRU;
  drr1 = hMcbsp->Regs->DRRL;
  val = ((drr2<<16)&0xFFFF0000 )|(drr1 &0x0000FFFF);
  return val;
}
/** ============================================================================
 *   @n@b MCBSP_write32
 *
 *   @b Description
 *   @n This function writes the data onto the Data Transmit Register
 *
 *   @b Arguments
 *   @verbatim
            CSL_McbspHandle      MCBSP Handle
            Uint32				 Val
     @endverbatim
 *
 *   <b> Return Value </b>  none
 *   @li
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *	 @n	 Data written to DXR
 *
 *   @b Example
 *   @verbatim

     @endverbatim
 *  ============================================================================
 */
void MCBSP_write32(CSL_McbspHandle hMcbsp,Uint32 Val)
{
  hMcbsp->Regs->DXRU = (Val>>16);
  hMcbsp->Regs->DXRL = (Val&0x0000FFFF);
}

/** ============================================================================
 *   @n@b MCBSP_read16
 *
 *   @b Description
 *   @n This function reads the data from the lower 16 bits of the Data Receive Register
 *
 *   @b Arguments
 *   @verbatim
            CSL_McbspHandle      MCBSP Handle
     @endverbatim
 *
 *   <b> Return Value </b>  val
 *   @li                    16 bits from DRR
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *	 @n	 Data read from DRRL
 *
 *   @b Example
 *   @verbatim

            value = MCBSP_read16(CSL_McbspHandle hMcbsp)
     @endverbatim
 *  ============================================================================
 */
Uint16 MCBSP_read16(CSL_McbspHandle hMcbsp)
{
  Uint16 val;
  val = hMcbsp->Regs->DRRL;
  return val;
}

/** ============================================================================
 *   @n@b MCBSP_write16
 *
 *   @b Description
 *   @n This function writes the data onto the 16 lower bits of the Data Transmit Register
 *
 *   @b Arguments
 *   @verbatim
            CSL_McbspHandle      MCBSP Handle
            Uint32				 Val
     @endverbatim
 *
 *   <b> Return Value </b>  none
 *   @li
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *	 @n	 Data written to DXRL
 *
 *   @b Example
 *   @verbatim

     @endverbatim
 *  ============================================================================
 */
void MCBSP_write16(CSL_McbspHandle hMcbsp,Uint16 Val)
{
  hMcbsp->Regs->DXRL = Val;
}
/** ============================================================================
 *   @n@b MCBSP_read
 *
 *   @b Description
 *   @n This function reads the data from the lower 16 bits of the Data Receive Register
 *
 *   @b Arguments
 *   @verbatim
            CSL_McbspHandle      MCBSP Handle
     @endverbatim
 *
 *   <b> Return Value </b>  val
 *   @li                    16 bits from DRR
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *	 @n	 Data read from DRRL
 *
 *   @b Example
 *   @verbatim

            value = MCBSP_read(CSL_McbspHandle hMcbsp)
     @endverbatim
 *  ============================================================================
 */
Uint16 MCBSP_read(CSL_McbspHandle hMcbsp) {
  Uint16 val;
  val = hMcbsp->Regs->DRRL;
  return val;
}
/** ============================================================================
 *   @n@b MCBSP_write
 *
 *   @b Description
 *   @n This function writes the data onto the 16 lower bits of the Data Transmit Register
 *
 *   @b Arguments
 *   @verbatim
            CSL_McbspHandle      MCBSP Handle
            Uint32				 Val
     @endverbatim
 *
 *   <b> Return Value </b>  none
 *   @li
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *	 @n	 Data written to DXRL
 *
 *   @b Example
 *   @verbatim

     @endverbatim
 *  ============================================================================
 */
void MCBSP_write(CSL_McbspHandle hMcbsp,Uint16 Val)
{
 hMcbsp->Regs->DXRL = Val;
}

#else
#endif

