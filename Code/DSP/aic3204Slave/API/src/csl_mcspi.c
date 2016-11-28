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


/** @file csl_McSPI.c
 *
 *  @brief  McSPI functional layer API defenition file
 *
 *  Path: \(CSLPATH)/src
 */

/* ============================================================================
 * Revision History
 * ================
 * 07-Dec-2010 Created for C5517
 * 06-Jul-2011 CSL v2.50 release
 * 13-Sep-2012 CSL v3.00 release
 * 20-Dec-2012 CSL v3.01 release
 * ============================================================================
 */

#include "csl_general.h"
#include "csl_mcspi.h"
#include "cslr_mcspi.h"
#include "cslr_sysctrl.h"
#include "csl_sysctrl.h"

#ifdef CHIP_C5517

/*******************************************************************
* void McSPI_reset(void)
* input:
*        None
* Output:
*        None
* Return:
*        None;
*Description:
*     This function is to reset the MCSPI module in the Phoenix
********************************************************************/
void McSPI_reset(void)
{
	Uint16 looper;
	///ioport volatile CSL_SysPGFlags	*sysFlags;

	// Disable MCSPI module in Idle PCGCR
	//CSL_FINST(CSL_SYSCTRL_REGS->PCGCR1, SYS_PCGCR1_MCSPICG, ACTIVE);
	CSL_SYSCTRL_REGS->PCGCR1 = 0;
	// Disable MCSPI Refernce Clock in Idle PCGCR
	//CSL_FINST(CSL_SYSCTRL_REGS->PCGCR2, SYS_PCGCR2_MCSPIREFCG, ACTIVE);
	CSL_SYSCTRL_REGS->PCGCR2 = 0;

#if (defined(CHIP_C5517))
	CSL_SYSCTRL_REGS->CLKSTOP2 = 0;
#else
	CSL_SYSCTRL_REGS->CLKSTOP1 = 0;
#endif

	// set reset counter value
//	CSL_FINST(CSL_SYSCTRL_REGS->EBSR, SYS_EBSR_SP1MODE, MODE1);

	// set reset counter value
	CSL_FINS(CSL_SYSCTRL_REGS->PSRCR, SYS_PSRCR_COUNT, 0x20);

	// enable mcspi self-clearing
	SYS_peripheralReset(CSL_SYS_PG1);

	// give some delay for the device to reset
	for(looper = 0; looper < 300; looper++){;}


	return;
}

/** ============================================================================
 *   @n@b McSPI_open
 *
 *   @b Description
 *   @n This function opens the McSPI handle .
 *
 *   @b Arguments
 *   @verbatim
            CSL_McSpiHandle            Handle to the McSPI
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_McSpiHandle
 *
 *   <b> Pre Condition </b>
 *
 *   <b> Post Condition </b>
 *   @n  The handler will be opened
 *
 *   @b Example
 *   @verbatim
            GPIO_Handle     hGPIO;
            CSL_status      status;
            ...

            status = CSL_McSpiHandle McSPI_open(McSPI_OperMode opMode,CSL_McSpiObj *McSpiObj,CSL_Status 	*status);
     @endverbatim
 *  ============================================================================
 */

CSL_McSpiHandle McSPI_open(McSPI_OperMode opMode,
						   CSL_McSpiObj *McSpiObj,
						   CSL_Status 	*status)
{

   CSL_McSpiHandle hMcSPI;


	///Uint16 rd_value;
   *status = CSL_SOK;
   hMcSPI = NULL;
/*
   if(NULL == hMcSPI)
   {
	*status = CSL_ESYS_BADHANDLE;
	return (hMcSPI);
   }
*/

   hMcSPI = McSpiObj;
   if(hMcSPI->open == TRUE)
   {
      hMcSPI->open = FALSE;
      hMcSPI = NULL;
      return (hMcSPI);
   }
   hMcSPI->opMode = opMode;
   hMcSPI->Regs			= CSL_MCSPI_REGS;
   hMcSPI->sysRegs 		= CSL_SYSCTRL_REGS;



	// reset the MCSPI
	McSPI_reset();

	/*Takes the System Clock and divides it down for the McSPI functional clock(SPIREFCLK).
	0000 = Divide-by-1
	0001 = Divide-by-2
	0010 = Divide-by-4
	0011 = Divide-by-6
	0100 = Divide-by-8
	0101 = Divide-by-10
	0110 = Divide-by-12
	0111 = Divide-by-14
	1000 = Divide-by-16
	1001 = Divide-by-18
	1010 = Divide-by-20
	1011 = Divide-by-22
	1100 = Divide-by-24
	1101 = Divide-by-26
	1110 = Divide-by-28
	1111 = Divide-by-30*/
//	CSL_FINS(CSL_SYSCTRL_REGS->MSPIFCDR, SYS_MSPIFCDR_FCDIV, 0);
	/*Takes the System Clock and divides it down for the McSPI functional clock(SPIREFCLK).
	0000 = Divide-by-1
	0001 = Divide-by-2
	0010 = Divide-by-4*/
/*	CSL_FINS(CSL_SYSCTRL_REGS->MSPIFCDR, SYS_MSPIFCDR_OCDIV, 0);
	// set the MCSPI operation mode to master
	CSL_FINS(CSL_MCSPI_REGS->MODULCTRLL, MCSPI_MODULCTRLL_MS,       CSL_MCSPI_MODULCTRLL_MS_MASTER);
	// set the inital delay to no delay
	CSL_FINS(CSL_MCSPI_REGS->MODULCTRLL, MCSPI_MODULCTRLL_INITDLY,  CSL_MCSPI_MODULCTRLL_INITDLY_NODELAY);
	// set the MCSPI to single channel mode
	CSL_FINS(CSL_MCSPI_REGS->MODULCTRLL, MCSPI_MODULCTRLL_SINGLE,  CSL_MCSPI_MODULCTRLL_SINGLE_SINGLECH);
*/
	// set the MCSPI clock phase to be even
/*	CSL_FINS(CSL_MCSPI_REGS->CH0CONFL, MCSPI_CH0CONFL_PHA,  CSL_MCSPI_CH0CONFL_PHA_EVEN);
	// set the MCSPI clock polarity to active low
	CSL_FINS(CSL_MCSPI_REGS->CH0CONFL, MCSPI_CH0CONFL_POL,  CSL_MCSPI_CH0CONFL_POL_ACTIVELOW);
		// set the module clock divider - see table above for value
		CSL_FINS(CSL_MCSPI_REGS->CH0CONFL, MCSPI_CH0CONFL_CLKD, 2);
	// set the chip select polarity to active low
	CSL_FINS(CSL_MCSPI_REGS->CH0CONFL, MCSPI_CH0CONFL_EPOL, CSL_MCSPI_CH0CONFL_EPOL_ACTIVELOW);
	// set the word length to 8 bit
	CSL_FINS(CSL_MCSPI_REGS->CH0CONFL, MCSPI_CH0CONFL_WL,   CSL_MCSPI_CH0CONFL_WL_8BIT);
	// set to duplex mode to mode 2 - transmit mode
	CSL_FINS(CSL_MCSPI_REGS->CH0CONFL, MCSPI_CH0CONFL_TRM,  CSL_MCSPI_CH0CONFL_TRM_MODE2);

	// enable data line 1 for reception (no transmission)
		CSL_FINS(CSL_MCSPI_REGS->CH0CONFU, MCSPI_CH0CONFU_DPE1, CSL_MCSPI_CH0CONFU_DPE1_NOTRANSMISSON);
	// enable data line 0 transmission
	CSL_FINS(CSL_MCSPI_REGS->CH0CONFU, MCSPI_CH0CONFU_DPE0, CSL_MCSPI_CH0CONFU_DPE0_DATLINE0);
	// select data line 1 for RX
		CSL_FINS(CSL_MCSPI_REGS->CH0CONFU, MCSPI_CH0CONFU_IS,   CSL_MCSPI_CH0CONFU_IS_LINE1);

	// disable FIFO
	CSL_FINS(CSL_MCSPI_REGS->CH0CONFU, MCSPI_CH0CONFU_FFER, CSL_MCSPI_CH0CONFU_FFER_FIFONOTUSED);
	CSL_FINS(CSL_MCSPI_REGS->CH0CONFU, MCSPI_CH0CONFU_FFEW, CSL_MCSPI_CH0CONFU_FFER_FIFONOTUSED);

	// disable all MCSPI IRQs
	CSL_MCSPI_REGS->IRQENABLEL = 0x0000;
	CSL_MCSPI_REGS->IRQENABLEU = 0x0000;

	// clear CH0STATL
	rd_value = CSL_MCSPI_REGS->CH0STATL;
	CSL_MCSPI_REGS->CH0STATL = rd_value;

		// enable channel 0
	CSL_FINS(CSL_MCSPI_REGS->CH0CTRLL,  MCSPI_CH0CTRLL_EN,  1);
*/
   return(hMcSPI);
}
/*******************************************************************
* void McSPI_init(unsigned char clock_divider)
* input:
*        clock_divider     set the clock divider for MCSPI
* Output:
*        None
* Return:
*        None;
*Description:
*     This function is to init the MCSPI module in the Phoenix
********************************************************************/
Uint16 McSPI_init(unsigned int clock_divider)
{
	Uint16 status;
	Uint16 rd_value;

	status = 0;
	// reset the MCSPI
	McSPI_reset();

	/*Takes the System Clock and divides it down for the McSPI functional clock(SPIREFCLK).
	0000 = Divide-by-1
	0001 = Divide-by-2
	0010 = Divide-by-4
	0011 = Divide-by-6
	0100 = Divide-by-8
	0101 = Divide-by-10
	0110 = Divide-by-12
	0111 = Divide-by-14
	1000 = Divide-by-16
	1001 = Divide-by-18
	1010 = Divide-by-20
	1011 = Divide-by-22
	1100 = Divide-by-24
	1101 = Divide-by-26
	1110 = Divide-by-28
	1111 = Divide-by-30*/
	CSL_FINS(CSL_SYSCTRL_REGS->MSPIFCDR, SYS_MSPIFCDR_FCDIV, 0);
	/*Takes the System Clock and divides it down for the McSPI functional clock(SPIREFCLK).
	0000 = Divide-by-1
	0001 = Divide-by-2
	0010 = Divide-by-4*/
	CSL_FINS(CSL_SYSCTRL_REGS->MSPIFCDR, SYS_MSPIFCDR_OCDIV, 0);
	// set the MCSPI operation mode to master
	CSL_FINS(CSL_MCSPI_REGS->MODULCTRLL, MCSPI_MODULCTRLL_MS,       CSL_MCSPI_MODULCTRLL_MS_MASTER);
	// set the inital delay to no delay
	CSL_FINS(CSL_MCSPI_REGS->MODULCTRLL, MCSPI_MODULCTRLL_INITDLY,  CSL_MCSPI_MODULCTRLL_INITDLY_NODELAY);
	// set the MCSPI to single channel mode
	CSL_FINS(CSL_MCSPI_REGS->MODULCTRLL, MCSPI_MODULCTRLL_SINGLE,  CSL_MCSPI_MODULCTRLL_SINGLE_SINGLECH);

	// set the MCSPI clock phase to be even
	CSL_FINS(CSL_MCSPI_REGS->CH0CONFL, MCSPI_CH0CONFL_PHA,  CSL_MCSPI_CH0CONFL_PHA_EVEN);
	// set the MCSPI clock polarity to active low
	CSL_FINS(CSL_MCSPI_REGS->CH0CONFL, MCSPI_CH0CONFL_POL,  CSL_MCSPI_CH0CONFL_POL_ACTIVELOW);
		// set the module clock divider
		CSL_FINS(CSL_MCSPI_REGS->CH0CONFL, MCSPI_CH0CONFL_CLKD, clock_divider);
	// set the chip select polarity to active low
	CSL_FINS(CSL_MCSPI_REGS->CH0CONFL, MCSPI_CH0CONFL_EPOL, CSL_MCSPI_CH0CONFL_EPOL_ACTIVELOW);
	// set the word length to 8 bit
	CSL_FINS(CSL_MCSPI_REGS->CH0CONFL, MCSPI_CH0CONFL_WL,   CSL_MCSPI_CH0CONFL_WL_8BIT);
	// set to duplex mode to mode 2 - transmit mode
	CSL_FINS(CSL_MCSPI_REGS->CH0CONFL, MCSPI_CH0CONFL_TRM,  CSL_MCSPI_CH0CONFL_TRM_MODE2);

	// enable data line 1 for reception (no transmission)
		CSL_FINS(CSL_MCSPI_REGS->CH0CONFU, MCSPI_CH0CONFU_DPE1, CSL_MCSPI_CH0CONFU_DPE1_NOTRANSMISSON);
	// enable data line 0 transmission
	CSL_FINS(CSL_MCSPI_REGS->CH0CONFU, MCSPI_CH0CONFU_DPE0, CSL_MCSPI_CH0CONFU_DPE0_DATLINE0);
	// select data line 1 for RX
		CSL_FINS(CSL_MCSPI_REGS->CH0CONFU, MCSPI_CH0CONFU_IS,   CSL_MCSPI_CH0CONFU_IS_LINE1);

	// disable FIFO
	CSL_FINS(CSL_MCSPI_REGS->CH0CONFU, MCSPI_CH0CONFU_FFER, CSL_MCSPI_CH0CONFU_FFER_FIFONOTUSED);
	CSL_FINS(CSL_MCSPI_REGS->CH0CONFU, MCSPI_CH0CONFU_FFEW, CSL_MCSPI_CH0CONFU_FFER_FIFONOTUSED);

	// disable all MCSPI IRQs
	CSL_MCSPI_REGS->IRQENABLEL = 0x0000;
	CSL_MCSPI_REGS->IRQENABLEU = 0x0000;

	// clear CH0STATL
	rd_value = CSL_MCSPI_REGS->CH0STATL;
	CSL_MCSPI_REGS->CH0STATL = rd_value;

		// enable channel 0
	CSL_FINS(CSL_MCSPI_REGS->CH0CTRLL,  MCSPI_CH0CTRLL_EN,  1);

	return (status);
}
/** ============================================================================
 *   @n@b McSPI_close
 *
 *   @b Description
 *   @n This function closes the McSPI handle.
 *
 *   @b Arguments
 *   @verbatim
            CSL_McSpiHandle            Handle to the McSPI
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_McSpiHandle
 *
 *   <b> Pre Condition </b>
 *
 *   <b> Post Condition </b>
 *   @n  The handler will be closed
 *
 *   @b Example
 *   @verbatim
            GPIO_Handle     hGPIO;
            CSL_status      status;
            ...

            status = CSL_McSpiHandle McSPI_close(CSL_McSpiHandle hMcSPI);
     @endverbatim
 *  ============================================================================
 */

CSL_Status  McSPI_close(CSL_McSpiHandle hMcSPI)
{
    if(NULL == hMcSPI)
    {
    	return (CSL_ESYS_BADHANDLE);
    }


    switch(hMcSPI->ch)
    {
    	case CSL_McSPI_CSNUM_CS0:
    		CSL_FINS(hMcSPI->Regs->CH0CTRLL, MCSPI_CH0CTRLL_EN,  0);
    	break;

    	case CSL_McSPI_CSNUM_CS1:
    		CSL_FINS(hMcSPI->Regs->CH1CTRLL, MCSPI_CH1CTRLL_EN,  0);
    	break;

    	case CSL_McSPI_CSNUM_CS2:
    		CSL_FINS(hMcSPI->Regs->CH2CTRLL, MCSPI_CH2CTRLL_EN,  0);
    	break;
#if	(CH3_ENABLE == 1)
    	case CSL_McSPI_CSNUM_CS3:
    		CSL_FINS(hMcSPI->Regs->CH3CTRLL, MCSPI_CH3CTRLL_EN,  0);
    	break;
#endif

    	default:
    	break;
    }



	//Added code to clock stop and PCGCR disable

	//issue reset to MCSPI
	SYS_peripheralReset(CSL_SYS_PG3);


	// Enable MCSPI module in Idle PCGCR
	CSL_FINST(hMcSPI->sysRegs->PCGCR1, SYS_PCGCR1_MCSPICG, DISABLED);

	if(TRUE == hMcSPI->open) //if opened already the module needs close,After that McSPI handler should not be used
    {
    	hMcSPI->open = FALSE;
    	hMcSPI = NULL;      //Derefrencing hMcSPI handler leads to crash of program
    }

    return (CSL_SOK);

}

/** ============================================================================
 *   @n@b McSPI_config
 *
 *   @b Description
 *   @n This function configures the McSPI registers
 *
 *   @b Arguments
 *   @verbatim
            CSL_McSpiHandle            Handle to the McSPI
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_McSpiHandle
 *
 *   <b> Pre Condition </b>
 *
 *   <b> Post Condition </b>
 *   @n  The McSPI registers will be reconfigured
 *
 *   @b Example
 *   @verbatim
            GPIO_Handle     hGPIO;
            CSL_status      status;
            ...
			return (status);

     @endverbatim
 *  ============================================================================
 */

CSL_Status  McSPI_config (CSL_McSpiHandle hMcSPI)
{
   Int16 status;

   status = CSL_SOK;
   if(NULL == hMcSPI)
   {
      return (CSL_ESYS_BADHANDLE);
   }

   /*Takes the System Clock and divides it down for the McSPI functional clock(SPIREFCLK).
0000 = Divide-by-1
0001 = Divide-by-2
0010 = Divide-by-4
0011 = Divide-by-6
0100 = Divide-by-8
0101 = Divide-by-10
0110 = Divide-by-12
0111 = Divide-by-14
1000 = Divide-by-16
1001 = Divide-by-18
1010 = Divide-by-20
1011 = Divide-by-22
1100 = Divide-by-24
1101 = Divide-by-26
1110 = Divide-by-28
1111 = Divide-by-30*/
   CSL_FINS(hMcSPI->sysRegs->MSPIFCDR, SYS_MSPIFCDR_FCDIV, 0x01);
   CSL_FINS(hMcSPI->Regs->MODULCTRLL, MCSPI_MODULCTRLL_MS,       hMcSPI->McSPIHwConfig.mode);
   CSL_FINS(hMcSPI->Regs->MODULCTRLL, MCSPI_MODULCTRLL_INITDLY,  hMcSPI->McSPIHwConfig.dataDelay);


   if(McSPI_MASTER == hMcSPI->McSPIHwConfig.mode)
   {
           switch(hMcSPI->ch)
           {
	       case CSL_McSPI_CSNUM_CS0:
		   if(hMcSPI->opMode == McSPI_DMA_MODE){
		   CSL_FINST(hMcSPI->Regs->CH0CONFL, MCSPI_CH0CONFL_DMAR,ENABLE);
		   CSL_FINST(hMcSPI->Regs->CH0CONFL, MCSPI_CH0CONFL_DMAW,ENABLE);
		  }
		   CSL_FINS(hMcSPI->Regs->CH0CONFL, MCSPI_CH0CONFL_PHA,  hMcSPI->McSPIHwConfig.clkPh);
		   CSL_FINS(hMcSPI->Regs->CH0CONFL, MCSPI_CH0CONFL_POL,  hMcSPI->McSPIHwConfig.clkPol);
		   CSL_FINS(hMcSPI->Regs->CH0CONFL, MCSPI_CH0CONFL_CLKD, hMcSPI->McSPIHwConfig.ClkDiv);
		   CSL_FINS(hMcSPI->Regs->CH0CONFL, MCSPI_CH0CONFL_EPOL, hMcSPI->McSPIHwConfig.csPol);
		   CSL_FINS(hMcSPI->Regs->CH0CONFL, MCSPI_CH0CONFL_WL,   hMcSPI->McSPIHwConfig.wLen);
		   CSL_FINS(hMcSPI->Regs->CH0CONFL, MCSPI_CH0CONFL_TRM,  hMcSPI->McSPIHwConfig.duplex);

		   if(hMcSPI->McSPIHwConfig.enDat0_1==0)
		   {
		      CSL_FINS(hMcSPI->Regs->CH0CONFU, MCSPI_CH0CONFU_DPE0, CSL_MCSPI_CH0CONFU_DPE0_DATLINE0);
		      CSL_FINS(hMcSPI->Regs->CH0CONFU, MCSPI_CH0CONFU_DPE1, CSL_MCSPI_CH0CONFU_DPE1_NOTRANSMISSON);
              CSL_FINS(hMcSPI->Regs->CH0CONFU, MCSPI_CH0CONFU_IS,   CSL_MCSPI_CH0CONFU_IS_LINE1);
		   }
		   else if(hMcSPI->McSPIHwConfig.enDat0_1==1)
		   {
		      CSL_FINS(hMcSPI->Regs->CH0CONFU, MCSPI_CH0CONFU_DPE1, CSL_MCSPI_CH0CONFU_DPE1_DATLINE1);
		      CSL_FINS(hMcSPI->Regs->CH0CONFU, MCSPI_CH0CONFU_DPE0, CSL_MCSPI_CH0CONFU_DPE0_NOTRANSMISSON);
	          CSL_FINS(hMcSPI->Regs->CH0CONFU, MCSPI_CH0CONFU_IS,   CSL_MCSPI_CH0CONFU_IS_LINE0);
		   }

		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_TX0_EMPTY_ENABLE,      CSL_MCSPI_IRQENABLEL_TX0_EMPTY_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_TX0_UNDERFLOW_ENABLE,  CSL_MCSPI_IRQENABLEL_TX0_UNDERFLOW_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_RX0_FULL_ENABLE,       CSL_MCSPI_IRQENABLEL_RX0_FULL_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_RX0_OVERFLOW_ENABLE,   CSL_MCSPI_IRQENABLEL_RX0_OVERFLOW_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEU, MCSPI_IRQENABLEU_WKE, CSL_MCSPI_IRQENABLEU_WKE_ENABLE);

		   if(hMcSPI->McSPIHwConfig.fifo==McSPI_FIFO_EN)
		   {
			CSL_FINS(hMcSPI->Regs->CH0CONFU, MCSPI_CH0CONFU_FFER, 1);
			CSL_FINS(hMcSPI->Regs->CH0CONFU, MCSPI_CH0CONFU_FFEW, 1);
		   }

		   CSL_FINS(hMcSPI->Regs->CH0CTRLL,  MCSPI_CH0CTRLL_EN,  1);
	      break;

	      case CSL_McSPI_CSNUM_CS1:
		  if(hMcSPI->opMode == McSPI_DMA_MODE){
		   CSL_FINST(hMcSPI->Regs->CH1CONFL, MCSPI_CH1CONFL_DMAR,ENABLE);
		   CSL_FINST(hMcSPI->Regs->CH1CONFL, MCSPI_CH1CONFL_DMAW,ENABLE);
		  }
		   CSL_FINS(hMcSPI->Regs->CH1CONFL, MCSPI_CH1CONFL_PHA,  hMcSPI->McSPIHwConfig.clkPh);
		   CSL_FINS(hMcSPI->Regs->CH1CONFL, MCSPI_CH1CONFL_POL,  hMcSPI->McSPIHwConfig.clkPol);
		   CSL_FINS(hMcSPI->Regs->CH1CONFL, MCSPI_CH1CONFL_CLKD, hMcSPI->McSPIHwConfig.ClkDiv);
		   CSL_FINS(hMcSPI->Regs->CH1CONFL, MCSPI_CH1CONFL_EPOL, hMcSPI->McSPIHwConfig.csPol);
		   CSL_FINS(hMcSPI->Regs->CH1CONFL, MCSPI_CH1CONFL_WL,   hMcSPI->McSPIHwConfig.wLen);
		   CSL_FINS(hMcSPI->Regs->CH1CONFL, MCSPI_CH1CONFL_TRM,  hMcSPI->McSPIHwConfig.duplex);

		   if(hMcSPI->McSPIHwConfig.enDat0_1==0)
		   {
		      CSL_FINS(hMcSPI->Regs->CH1CONFU, MCSPI_CH1CONFU_DPE0, CSL_MCSPI_CH1CONFU_DPE0_DATLINE0);
		      CSL_FINS(hMcSPI->Regs->CH1CONFU, MCSPI_CH1CONFU_DPE1, CSL_MCSPI_CH1CONFU_DPE1_NOTRANSMISSON);
              CSL_FINS(hMcSPI->Regs->CH1CONFU, MCSPI_CH1CONFU_IS,   CSL_MCSPI_CH1CONFU_IS_LINE1);
		   }
		   else if(hMcSPI->McSPIHwConfig.enDat0_1==1)
		   {
		      CSL_FINS(hMcSPI->Regs->CH1CONFU, MCSPI_CH1CONFU_DPE1, CSL_MCSPI_CH1CONFU_DPE1_DATLINE1);
		      CSL_FINS(hMcSPI->Regs->CH1CONFU, MCSPI_CH1CONFU_DPE0, CSL_MCSPI_CH1CONFU_DPE0_NOTRANSMISSON);
	          CSL_FINS(hMcSPI->Regs->CH1CONFU, MCSPI_CH1CONFU_IS,   CSL_MCSPI_CH1CONFU_IS_LINE0);
		   }

		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_TX1_EMPTY_ENABLE,      CSL_MCSPI_IRQENABLEL_TX1_EMPTY_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_TX1_UNDERFLOW_ENABLE,  CSL_MCSPI_IRQENABLEL_TX1_UNDERFLOW_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_RX1_FULL_ENABLE,       CSL_MCSPI_IRQENABLEL_RX1_FULL_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEU, MCSPI_IRQENABLEU_WKE, CSL_MCSPI_IRQENABLEU_WKE_ENABLE);

		   if(hMcSPI->McSPIHwConfig.fifo==McSPI_FIFO_EN)
		   {
		    	CSL_FINS(hMcSPI->Regs->CH1CONFU, MCSPI_CH1CONFU_FFER, 1);
		   		CSL_FINS(hMcSPI->Regs->CH1CONFU, MCSPI_CH1CONFU_FFEW, 1);
		   }

		   CSL_FINS(hMcSPI->Regs->CH1CTRLL,  MCSPI_CH1CTRLL_EN,  1);
	      break;

	      case CSL_McSPI_CSNUM_CS2:
		  if(hMcSPI->opMode == McSPI_DMA_MODE){
		   CSL_FINST(hMcSPI->Regs->CH2CONFL, MCSPI_CH2CONFL_DMAR,ENABLE);
		   CSL_FINST(hMcSPI->Regs->CH2CONFL, MCSPI_CH2CONFL_DMAW,ENABLE);
		  }
		   CSL_FINS(hMcSPI->Regs->CH2CONFL, MCSPI_CH2CONFL_PHA,  hMcSPI->McSPIHwConfig.clkPh);
		   CSL_FINS(hMcSPI->Regs->CH2CONFL, MCSPI_CH2CONFL_POL,  hMcSPI->McSPIHwConfig.clkPol);
		   CSL_FINS(hMcSPI->Regs->CH2CONFL, MCSPI_CH2CONFL_CLKD, hMcSPI->McSPIHwConfig.ClkDiv);
		   CSL_FINS(hMcSPI->Regs->CH2CONFL, MCSPI_CH2CONFL_EPOL, hMcSPI->McSPIHwConfig.csPol);
		   CSL_FINS(hMcSPI->Regs->CH2CONFL, MCSPI_CH2CONFL_WL,   hMcSPI->McSPIHwConfig.wLen);
		   CSL_FINS(hMcSPI->Regs->CH2CONFL, MCSPI_CH2CONFL_TRM,  hMcSPI->McSPIHwConfig.duplex);

		   if(hMcSPI->McSPIHwConfig.enDat0_1==0)
		   {
		      CSL_FINS(hMcSPI->Regs->CH2CONFU, MCSPI_CH2CONFU_DPE0, CSL_MCSPI_CH2CONFU_DPE0_DATLINE0);
		      CSL_FINS(hMcSPI->Regs->CH2CONFU, MCSPI_CH2CONFU_DPE1, CSL_MCSPI_CH2CONFU_DPE1_NOTRANSMISSON);
              CSL_FINS(hMcSPI->Regs->CH2CONFU, MCSPI_CH2CONFU_IS,   CSL_MCSPI_CH2CONFU_IS_LINE1);
		   }
		   else if(hMcSPI->McSPIHwConfig.enDat0_1==1)
		   {
		      CSL_FINS(hMcSPI->Regs->CH2CONFU, MCSPI_CH2CONFU_DPE1, CSL_MCSPI_CH2CONFU_DPE1_DATLINE1);
		      CSL_FINS(hMcSPI->Regs->CH2CONFU, MCSPI_CH2CONFU_DPE0, CSL_MCSPI_CH2CONFU_DPE0_NOTRANSMISSON);
              CSL_FINS(hMcSPI->Regs->CH2CONFU, MCSPI_CH2CONFU_IS,   CSL_MCSPI_CH2CONFU_IS_LINE0);
		   }

		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_TX2_EMPTY_ENABLE,      CSL_MCSPI_IRQENABLEL_TX2_EMPTY_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_TX2_UNDERFLOW_ENABLE,  CSL_MCSPI_IRQENABLEL_TX2_UNDERFLOW_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_RX2_FULL_ENABLE,       CSL_MCSPI_IRQENABLEL_RX2_FULL_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEU, MCSPI_IRQENABLEU_WKE, CSL_MCSPI_IRQENABLEU_WKE_ENABLE);

		   if(hMcSPI->McSPIHwConfig.fifo==McSPI_FIFO_EN)
		   {
				CSL_FINS(hMcSPI->Regs->CH2CONFU, MCSPI_CH2CONFU_FFER, 1);
				CSL_FINS(hMcSPI->Regs->CH2CONFU, MCSPI_CH2CONFU_FFEW, 1);
		   }
		   CSL_FINS(hMcSPI->Regs->CH2CTRLL,  MCSPI_CH2CTRLL_EN,  1);
	      break;
#if	(CH3_ENABLE == 1)
	      case CSL_McSPI_CSNUM_CS3:
		  if(hMcSPI->opMode == McSPI_DMA_MODE){
		   CSL_FINST(hMcSPI->Regs->CH3CONFL, MCSPI_CH3CONFL_DMAR,ENABLE);
		   CSL_FINST(hMcSPI->Regs->CH3CONFL, MCSPI_CH3CONFL_DMAW,ENABLE);
		  }
		   CSL_FINS(hMcSPI->Regs->CH3CONFL, MCSPI_CH3CONFL_PHA,  hMcSPI->McSPIHwConfig.clkPh);
		   CSL_FINS(hMcSPI->Regs->CH3CONFL, MCSPI_CH3CONFL_POL,  hMcSPI->McSPIHwConfig.clkPol);
		   CSL_FINS(hMcSPI->Regs->CH3CONFL, MCSPI_CH3CONFL_CLKD, hMcSPI->McSPIHwConfig.ClkDiv);
		   CSL_FINS(hMcSPI->Regs->CH3CONFL, MCSPI_CH3CONFL_EPOL, hMcSPI->McSPIHwConfig.csPol);
		   CSL_FINS(hMcSPI->Regs->CH3CONFL, MCSPI_CH3CONFL_WL,   hMcSPI->McSPIHwConfig.wLen);
		   CSL_FINS(hMcSPI->Regs->CH3CONFL, MCSPI_CH3CONFL_TRM,  hMcSPI->McSPIHwConfig.duplex);

		   if(hMcSPI->McSPIHwConfig.enDat0_1==0)
		   {
		      CSL_FINS(hMcSPI->Regs->CH3CONFU, MCSPI_CH3CONFU_DPE0, CSL_MCSPI_CH3CONFU_DPE0_DATLINE0);
		      CSL_FINS(hMcSPI->Regs->CH3CONFU, MCSPI_CH3CONFU_DPE1, CSL_MCSPI_CH3CONFU_DPE1_NOTRANSMISSON);
	          CSL_FINS(hMcSPI->Regs->CH3CONFU, MCSPI_CH3CONFU_IS,   CSL_MCSPI_CH3CONFU_IS_LINE1);
		   }
		   else if(hMcSPI->McSPIHwConfig.enDat0_1==1)
		   {
		      CSL_FINS(hMcSPI->Regs->CH3CONFU, MCSPI_CH3CONFU_DPE1, CSL_MCSPI_CH3CONFU_DPE1_DATLINE1);
		      CSL_FINS(hMcSPI->Regs->CH3CONFU, MCSPI_CH3CONFU_DPE0, CSL_MCSPI_CH3CONFU_DPE0_NOTRANSMISSON);
	          CSL_FINS(hMcSPI->Regs->CH3CONFU, MCSPI_CH3CONFU_IS,   CSL_MCSPI_CH3CONFU_IS_LINE0);
		   }

		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_TX3_EMPTY_ENABLE,      CSL_MCSPI_IRQENABLEL_TX3_EMPTY_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_TX3_UNDERFLOW_ENABLE,  CSL_MCSPI_IRQENABLEL_TX3_UNDERFLOW_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_RX3_FULL_ENABLE,       CSL_MCSPI_IRQENABLEL_RX3_FULL_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEU, MCSPI_IRQENABLEU_WKE, CSL_MCSPI_IRQENABLEU_WKE_ENABLE);

		   if(hMcSPI->McSPIHwConfig.fifo==McSPI_FIFO_EN)
		   {
				CSL_FINS(hMcSPI->Regs->CH3CONFU, MCSPI_CH3CONFU_FFER, 1);
				CSL_FINS(hMcSPI->Regs->CH3CONFU, MCSPI_CH3CONFU_FFEW, 1);
		   }
		   CSL_FINS(hMcSPI->Regs->CH3CTRLL,  MCSPI_CH3CTRLL_EN,  1);
	      break;
#endif
	      default:

	      break;
           }
      }else {            //case SLAVE
	  switch(hMcSPI->ch)
      {
      case CSL_McSPI_CSNUM_CS0:
      	  if(hMcSPI->opMode == McSPI_DMA_MODE){
		   CSL_FINST(hMcSPI->Regs->CH0CONFL, MCSPI_CH0CONFL_DMAR,ENABLE);
		   CSL_FINST(hMcSPI->Regs->CH0CONFL, MCSPI_CH0CONFL_DMAW,ENABLE);
		  }
		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_TX0_EMPTY_ENABLE,      CSL_MCSPI_IRQENABLEL_TX0_EMPTY_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_TX0_UNDERFLOW_ENABLE,  CSL_MCSPI_IRQENABLEL_TX0_UNDERFLOW_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_RX0_FULL_ENABLE,       CSL_MCSPI_IRQENABLEL_RX0_FULL_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_RX0_OVERFLOW_ENABLE,   CSL_MCSPI_IRQENABLEL_RX0_OVERFLOW_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEU, MCSPI_IRQENABLEU_WKE, CSL_MCSPI_IRQENABLEU_WKE_ENABLE);

		   CSL_FINS(hMcSPI->Regs->CH0CONFL, MCSPI_CH0CONFL_PHA,  hMcSPI->McSPIHwConfig.clkPh);
		   CSL_FINS(hMcSPI->Regs->CH0CONFL, MCSPI_CH0CONFL_POL,  hMcSPI->McSPIHwConfig.clkPol);
		   CSL_FINS(hMcSPI->Regs->CH0CONFL, MCSPI_CH0CONFL_CLKD, hMcSPI->McSPIHwConfig.ClkDiv);
		   CSL_FINS(hMcSPI->Regs->CH0CONFL, MCSPI_CH0CONFL_TRM,  hMcSPI->McSPIHwConfig.duplex);

		   CSL_FINS(hMcSPI->Regs->CH0CONFL, MCSPI_CH0CONFL_WL,   hMcSPI->McSPIHwConfig.wLen);
		   CSL_FINS(hMcSPI->Regs->CH0CONFL, MCSPI_CH0CONFL_EPOL, hMcSPI->McSPIHwConfig.csPol);

		   if(hMcSPI->McSPIHwConfig.inSel==0)
		   {
		      CSL_FINS(hMcSPI->Regs->CH0CONFU, MCSPI_CH0CONFU_IS,   hMcSPI->McSPIHwConfig.inSel);
		      CSL_FINS(hMcSPI->Regs->CH0CONFU, MCSPI_CH0CONFU_DPE1, CSL_MCSPI_CH0CONFU_DPE1_DATLINE1);
		      CSL_FINS(hMcSPI->Regs->CH0CONFU, MCSPI_CH0CONFU_DPE0, CSL_MCSPI_CH0CONFU_DPE0_NOTRANSMISSON);
		   }
		   else if(hMcSPI->McSPIHwConfig.inSel==1)
		   {
		      CSL_FINS(hMcSPI->Regs->CH0CONFU, MCSPI_CH0CONFU_IS,   hMcSPI->McSPIHwConfig.inSel);
		      CSL_FINS(hMcSPI->Regs->CH0CONFU, MCSPI_CH0CONFU_DPE0, CSL_MCSPI_CH0CONFU_DPE0_DATLINE0);
		      CSL_FINS(hMcSPI->Regs->CH0CONFU, MCSPI_CH0CONFU_DPE1, CSL_MCSPI_CH0CONFU_DPE1_NOTRANSMISSON);
		   }

		   if(hMcSPI->McSPIHwConfig.fifo==McSPI_FIFO_EN)
		   {
				CSL_FINS(hMcSPI->Regs->CH0CONFU, MCSPI_CH0CONFU_FFER, 1);
				CSL_FINS(hMcSPI->Regs->CH0CONFU, MCSPI_CH0CONFU_FFEW, 1);
		   }

		   CSL_FINS(hMcSPI->Regs->CH0CTRLL,  MCSPI_CH0CTRLL_EN,  1);
	   break;
	   case CSL_McSPI_CSNUM_CS1:
	     if(hMcSPI->opMode == McSPI_DMA_MODE){
		   CSL_FINST(hMcSPI->Regs->CH1CONFL, MCSPI_CH1CONFL_DMAR,ENABLE);
		   CSL_FINST(hMcSPI->Regs->CH1CONFL, MCSPI_CH1CONFL_DMAW,ENABLE);
		  }
		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_TX1_EMPTY_ENABLE,      CSL_MCSPI_IRQENABLEL_TX0_EMPTY_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_TX1_UNDERFLOW_ENABLE,  CSL_MCSPI_IRQENABLEL_TX0_UNDERFLOW_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_RX1_FULL_ENABLE,       CSL_MCSPI_IRQENABLEL_RX0_FULL_ENABLE_ENABLE);
//		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_RX1_OVERFLOW_ENABLE,   CSL_MCSPI_IRQENABLEL_RX0_OVERFLOW_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEU, MCSPI_IRQENABLEU_WKE, CSL_MCSPI_IRQENABLEU_WKE_ENABLE);

		   CSL_FINS(hMcSPI->Regs->CH1CONFL, MCSPI_CH1CONFL_PHA,  hMcSPI->McSPIHwConfig.clkPh);
		   CSL_FINS(hMcSPI->Regs->CH1CONFL, MCSPI_CH1CONFL_POL,  hMcSPI->McSPIHwConfig.clkPol);
		   CSL_FINS(hMcSPI->Regs->CH1CONFL, MCSPI_CH1CONFL_CLKD, hMcSPI->McSPIHwConfig.ClkDiv);
		   CSL_FINS(hMcSPI->Regs->CH1CONFL, MCSPI_CH1CONFL_TRM,  hMcSPI->McSPIHwConfig.duplex);


		   CSL_FINS(hMcSPI->Regs->CH1CONFL, MCSPI_CH1CONFL_WL,   hMcSPI->McSPIHwConfig.wLen);
		   CSL_FINS(hMcSPI->Regs->CH1CONFL, MCSPI_CH1CONFL_EPOL, hMcSPI->McSPIHwConfig.csPol);

		   if(hMcSPI->McSPIHwConfig.inSel==0)
		   {
		      CSL_FINS(hMcSPI->Regs->CH1CONFU, MCSPI_CH1CONFU_IS,   hMcSPI->McSPIHwConfig.inSel);
		      CSL_FINS(hMcSPI->Regs->CH1CONFU, MCSPI_CH1CONFU_DPE1, CSL_MCSPI_CH0CONFU_DPE1_DATLINE1);
		      CSL_FINS(hMcSPI->Regs->CH1CONFU, MCSPI_CH1CONFU_DPE0, CSL_MCSPI_CH0CONFU_DPE0_NOTRANSMISSON);
		   }
		   else if(hMcSPI->McSPIHwConfig.inSel==1)
		   {
		      CSL_FINS(hMcSPI->Regs->CH1CONFU, MCSPI_CH1CONFU_IS,   hMcSPI->McSPIHwConfig.inSel);
		      CSL_FINS(hMcSPI->Regs->CH1CONFU, MCSPI_CH1CONFU_DPE0, CSL_MCSPI_CH0CONFU_DPE0_DATLINE0);
		      CSL_FINS(hMcSPI->Regs->CH1CONFU, MCSPI_CH1CONFU_DPE1, CSL_MCSPI_CH0CONFU_DPE1_NOTRANSMISSON);
		   }

		   if(hMcSPI->McSPIHwConfig.fifo==McSPI_FIFO_EN)
		   {
				CSL_FINS(hMcSPI->Regs->CH1CONFU, MCSPI_CH1CONFU_FFER, 1);
				CSL_FINS(hMcSPI->Regs->CH1CONFU, MCSPI_CH1CONFU_FFEW, 1);
		   }

		   CSL_FINS(hMcSPI->Regs->CH1CTRLL,  MCSPI_CH1CTRLL_EN,  1);
	   break;
	    case CSL_McSPI_CSNUM_CS2:
		if(hMcSPI->opMode == McSPI_DMA_MODE){
		   CSL_FINST(hMcSPI->Regs->CH2CONFL, MCSPI_CH2CONFL_DMAR,ENABLE);
		   CSL_FINST(hMcSPI->Regs->CH2CONFL, MCSPI_CH2CONFL_DMAW,ENABLE);
		  }
		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_TX2_EMPTY_ENABLE,      CSL_MCSPI_IRQENABLEL_TX0_EMPTY_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_TX2_UNDERFLOW_ENABLE,  CSL_MCSPI_IRQENABLEL_TX0_UNDERFLOW_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_RX2_FULL_ENABLE,       CSL_MCSPI_IRQENABLEL_RX0_FULL_ENABLE_ENABLE);
//		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_RX2_OVERFLOW_ENABLE,   CSL_MCSPI_IRQENABLEL_RX0_OVERFLOW_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEU, MCSPI_IRQENABLEU_WKE, CSL_MCSPI_IRQENABLEU_WKE_ENABLE);

	   	   CSL_FINS(hMcSPI->Regs->CH2CONFL, MCSPI_CH2CONFL_PHA,  hMcSPI->McSPIHwConfig.clkPh);
		   CSL_FINS(hMcSPI->Regs->CH2CONFL, MCSPI_CH2CONFL_POL,  hMcSPI->McSPIHwConfig.clkPol);
		   CSL_FINS(hMcSPI->Regs->CH2CONFL, MCSPI_CH2CONFL_CLKD, hMcSPI->McSPIHwConfig.ClkDiv);
		   CSL_FINS(hMcSPI->Regs->CH2CONFL, MCSPI_CH2CONFL_TRM,  hMcSPI->McSPIHwConfig.duplex);



		   CSL_FINS(hMcSPI->Regs->CH2CONFL, MCSPI_CH2CONFL_WL,   hMcSPI->McSPIHwConfig.wLen);
		   CSL_FINS(hMcSPI->Regs->CH2CONFL, MCSPI_CH2CONFL_EPOL, hMcSPI->McSPIHwConfig.csPol);

		   if(hMcSPI->McSPIHwConfig.inSel==0)
		   {
		      CSL_FINS(hMcSPI->Regs->CH2CONFU, MCSPI_CH2CONFU_IS,   hMcSPI->McSPIHwConfig.inSel);
		      CSL_FINS(hMcSPI->Regs->CH2CONFU, MCSPI_CH2CONFU_DPE1, CSL_MCSPI_CH0CONFU_DPE1_DATLINE1);
		      CSL_FINS(hMcSPI->Regs->CH2CONFU, MCSPI_CH2CONFU_DPE0, CSL_MCSPI_CH0CONFU_DPE0_NOTRANSMISSON);
		   }
		   else if(hMcSPI->McSPIHwConfig.inSel==1)
		   {
		      CSL_FINS(hMcSPI->Regs->CH2CONFU, MCSPI_CH2CONFU_IS,   hMcSPI->McSPIHwConfig.inSel);
		      CSL_FINS(hMcSPI->Regs->CH2CONFU, MCSPI_CH2CONFU_DPE0, CSL_MCSPI_CH0CONFU_DPE0_DATLINE0);
		      CSL_FINS(hMcSPI->Regs->CH2CONFU, MCSPI_CH2CONFU_DPE1, CSL_MCSPI_CH0CONFU_DPE1_NOTRANSMISSON);
		   }

		   if(hMcSPI->McSPIHwConfig.fifo==McSPI_FIFO_EN)
		   {
				CSL_FINS(hMcSPI->Regs->CH2CONFU, MCSPI_CH2CONFU_FFER, 1);
				CSL_FINS(hMcSPI->Regs->CH2CONFU, MCSPI_CH2CONFU_FFEW, 1);
   		   }

		   CSL_FINS(hMcSPI->Regs->CH2CTRLL,  MCSPI_CH2CTRLL_EN,  1);
	    break;
#if	(CH3_ENABLE == 1)
	     case CSL_McSPI_CSNUM_CS3:
		 if(hMcSPI->opMode == McSPI_DMA_MODE){
		   CSL_FINST(hMcSPI->Regs->CH3CONFL, MCSPI_CH3CONFL_DMAR,ENABLE);
		   CSL_FINST(hMcSPI->Regs->CH3CONFL, MCSPI_CH3CONFL_DMAW,ENABLE);
		  }
		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_TX3_EMPTY_ENABLE,      CSL_MCSPI_IRQENABLEL_TX0_EMPTY_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_TX3_UNDERFLOW_ENABLE,  CSL_MCSPI_IRQENABLEL_TX0_UNDERFLOW_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_RX3_FULL_ENABLE,       CSL_MCSPI_IRQENABLEL_RX0_FULL_ENABLE_ENABLE);
//		   CSL_FINS(hMcSPI->Regs->IRQENABLEL, MCSPI_IRQENABLEL_RX3_OVERFLOW_ENABLE,   CSL_MCSPI_IRQENABLEL_RX0_OVERFLOW_ENABLE_ENABLE);
		   CSL_FINS(hMcSPI->Regs->IRQENABLEU, MCSPI_IRQENABLEU_WKE, CSL_MCSPI_IRQENABLEU_WKE_ENABLE);

		   CSL_FINS(hMcSPI->Regs->CH3CONFL, MCSPI_CH3CONFL_PHA,  hMcSPI->McSPIHwConfig.clkPh);
		   CSL_FINS(hMcSPI->Regs->CH3CONFL, MCSPI_CH3CONFL_POL,  hMcSPI->McSPIHwConfig.clkPol);
		   CSL_FINS(hMcSPI->Regs->CH3CONFL, MCSPI_CH3CONFL_CLKD, hMcSPI->McSPIHwConfig.ClkDiv);
		   CSL_FINS(hMcSPI->Regs->CH3CONFL, MCSPI_CH3CONFL_TRM,  hMcSPI->McSPIHwConfig.duplex);

		   CSL_FINS(hMcSPI->Regs->CH3CONFL, MCSPI_CH3CONFL_WL,   hMcSPI->McSPIHwConfig.wLen);
		   CSL_FINS(hMcSPI->Regs->CH3CONFL, MCSPI_CH3CONFL_EPOL, hMcSPI->McSPIHwConfig.csPol);

		   if(hMcSPI->McSPIHwConfig.inSel==0)
		   {
		      CSL_FINS(hMcSPI->Regs->CH3CONFU, MCSPI_CH3CONFU_IS,   hMcSPI->McSPIHwConfig.inSel);
		      CSL_FINS(hMcSPI->Regs->CH3CONFU, MCSPI_CH3CONFU_DPE1, CSL_MCSPI_CH0CONFU_DPE1_DATLINE1);
		      CSL_FINS(hMcSPI->Regs->CH3CONFU, MCSPI_CH3CONFU_DPE0, CSL_MCSPI_CH0CONFU_DPE0_NOTRANSMISSON);
		   }
		   else if(hMcSPI->McSPIHwConfig.inSel==1)
		   {
		      CSL_FINS(hMcSPI->Regs->CH3CONFU, MCSPI_CH3CONFU_IS,   hMcSPI->McSPIHwConfig.inSel);
		      CSL_FINS(hMcSPI->Regs->CH3CONFU, MCSPI_CH3CONFU_DPE0, CSL_MCSPI_CH0CONFU_DPE0_DATLINE0);
		      CSL_FINS(hMcSPI->Regs->CH3CONFU, MCSPI_CH3CONFU_DPE1, CSL_MCSPI_CH0CONFU_DPE1_NOTRANSMISSON);
		   }

		   if(hMcSPI->McSPIHwConfig.fifo==McSPI_FIFO_EN)
		   {
				CSL_FINS(hMcSPI->Regs->CH3CONFU, MCSPI_CH3CONFU_FFER, 1);
				CSL_FINS(hMcSPI->Regs->CH3CONFU, MCSPI_CH3CONFU_FFEW, 1);
		   }

		   CSL_FINS(hMcSPI->Regs->CH3CTRLL,  MCSPI_CH3CTRLL_EN,  1);
	   break;
#endif
	  default:
      break;


	  }   // switch statement close

   }

   if(CSL_ESYS_INVPARAMS != status)
   {
   	hMcSPI->configured = TRUE;
   }
   else
   {
   	hMcSPI->configured = FALSE;
   }

   return (status);
}


/** ============================================================================
 *   @n@b McSPI_write
 *
 *   @b Description
 *   @n This function writes data to the specified device
 *
 *   @b Arguments
 *   @verbatim
            CSL_McSpiHandle            Handle to the McSPI
	    Uint16		       Buffer
	    Uint16		       Buffer length
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_SOK
 *
 *   <b> Pre Condition </b>
 *
 *   <b> Post Condition </b>
 *   @n
 *
 *   @b Example
 *   @verbatim
            GPIO_Handle     hGPIO;
            CSL_status      status;
            ...
			return (CSL_SOK);

     @endverbatim
 *  ============================================================================
 */
CSL_Status  McSPI_write (CSL_McSpiHandle hMcSPI, Uint16	*writeBuffer, Uint16 bufLen)
{
    Uint16 	      getWLen;
    volatile Uint16   bufIndex;

    bufIndex = 0;
    if ( (NULL == writeBuffer) || (0 == bufLen) || (NULL == hMcSPI) )
    {
    	return (CSL_ESYS_INVPARAMS);
    }

    while(bufIndex < bufLen)
    {
       switch(hMcSPI->McSPIHwConfig.mode)
       {
          case McSPI_MASTER:
            switch(hMcSPI->ch)
              {
	         case CSL_McSPI_CSNUM_CS0:

		      	getWLen = CSL_FEXT(hMcSPI->Regs->CH0CONFL,MCSPI_CH0CONFL_WL);

	              if(getWLen >=  McSPI_MAX_WORD_LEN)
	              {
	               return (CSL_ESYS_INVPARAMS);
	              }
				 if(McSPI_TxEmptyInt_Chk(hMcSPI)){
			      	  hMcSPI->Regs->CH0TXL = (Uint16)(writeBuffer[bufIndex]);
					  bufIndex++;
					  if(getWLen >=  McSPI_WORD_LENGTH_16){
			              hMcSPI->Regs->CH0TXU = (Uint16)(writeBuffer[bufIndex]);
						  bufIndex++;
					  }else{
						  hMcSPI->Regs->CH0TXU = (Uint16)0x0000;
					  }
					  while(!(CSL_MCSPI_REGS->CH0STATL & CSL_MCSPI_CH0STATL_EOT_MASK ));
				  }

		 break;

	         case CSL_McSPI_CSNUM_CS1:

		     	  getWLen = CSL_FEXT(hMcSPI->Regs->CH1CONFL,MCSPI_CH1CONFL_WL);

	              if(getWLen >=  McSPI_MAX_WORD_LEN)
	              {
	               return (CSL_ESYS_INVPARAMS);
	              }
				 if(McSPI_TxEmptyInt_Chk(hMcSPI)){
			      	  hMcSPI->Regs->CH1TXL = (Uint16)(writeBuffer[bufIndex]);
					  bufIndex++;
					  if(getWLen >=  McSPI_WORD_LENGTH_16){
			              hMcSPI->Regs->CH1TXU = (Uint16)(writeBuffer[bufIndex]);
						  bufIndex++;
					  }else{
						  hMcSPI->Regs->CH1TXU = (Uint16)0x0000;
					  }
					  while(!(CSL_MCSPI_REGS->CH1STATL & CSL_MCSPI_CH1STATL_EOT_MASK ));
				 }
		 break;

	         case CSL_McSPI_CSNUM_CS2:

		     	  getWLen = CSL_FEXT(hMcSPI->Regs->CH2CONFL,MCSPI_CH2CONFL_WL);

	              if(getWLen >=  McSPI_MAX_WORD_LEN)
	              {
	               return (CSL_ESYS_INVPARAMS);
	              }
				 if(McSPI_TxEmptyInt_Chk(hMcSPI)){
			      	  hMcSPI->Regs->CH2TXL = (Uint16)(writeBuffer[bufIndex]);
					  bufIndex++;
					  if(getWLen >=  McSPI_WORD_LENGTH_16){
			              hMcSPI->Regs->CH2TXU = (Uint16)(writeBuffer[bufIndex]);
						  bufIndex++;
					  }else{
						  hMcSPI->Regs->CH2TXU = (Uint16)0x0000;
					  }
					  while(!(CSL_MCSPI_REGS->CH2STATL & CSL_MCSPI_CH2STATL_EOT_MASK ));
			     }
		 break;
#if	(CH3_ENABLE == 1)
	         case CSL_McSPI_CSNUM_CS3:

		      getWLen = CSL_FEXT(hMcSPI->Regs->CH3CONFL,MCSPI_CH3CONFL_WL);

	              if(getWLen >=  McSPI_MAX_WORD_LEN)
	              {
	               return (CSL_ESYS_INVPARAMS);
	              }
				 if(McSPI_TxEmptyInt_Chk(hMcSPI)){
			     	  hMcSPI->Regs->TX3L = (Uint16)(writeBuffer[bufIndex]);
					  bufIndex++;
					  if(getWLen >=  McSPI_WORD_LENGTH_16){
			              hMcSPI->Regs->TX3U = (Uint16)(writeBuffer[bufIndex]);
						  bufIndex++;
					  }else{
						  hMcSPI->Regs->TX3U = (Uint16)0x0000;
					  }
					  while(!(CSL_MCSPI_REGS->CH3STATL & CSL_MCSPI_CH3STATL_EOT_MASK ));
				  }
		 break;
#endif
		 default:
		 break;
	      }
	  break;

	  case McSPI_SLAVE:
		switch(hMcSPI->ch)
        {
	     case CSL_McSPI_CSNUM_CS0:
	       getWLen = CSL_FEXT(hMcSPI->Regs->CH0CONFL,MCSPI_CH0CONFL_WL);

	       if(getWLen >=  McSPI_MAX_WORD_LEN)
	       {
	        return (CSL_ESYS_INVPARAMS);
	       }
		 if(McSPI_TxEmptyInt_Chk(hMcSPI)){
		       hMcSPI->Regs->CH0TXL = (Uint16)(writeBuffer[bufIndex]);
			   bufIndex++;
			   if(getWLen >=  McSPI_WORD_LENGTH_16){
	              hMcSPI->Regs->CH0TXU = (Uint16)(writeBuffer[bufIndex]);
				  bufIndex++;
			   }else{
				  hMcSPI->Regs->CH0TXU = (Uint16)0x0000;
			   }
			  while(!(CSL_MCSPI_REGS->CH0STATL & CSL_MCSPI_CH0STATL_EOT_MASK ));
		  }
	 	 break;
		   case CSL_McSPI_CSNUM_CS1:
	       getWLen = CSL_FEXT(hMcSPI->Regs->CH1CONFL,MCSPI_CH1CONFL_WL);

	       if(getWLen >=  McSPI_MAX_WORD_LEN)
	       {
	        return (CSL_ESYS_INVPARAMS);
	       }
		 if(McSPI_TxEmptyInt_Chk(hMcSPI)){
      		 hMcSPI->Regs->CH1TXL = (Uint16)(writeBuffer[bufIndex]);
			  bufIndex++;
			  if(getWLen >=  McSPI_WORD_LENGTH_16){
	              hMcSPI->Regs->CH1TXU = (Uint16)(writeBuffer[bufIndex]);
				  bufIndex++;
			  }else{
				  hMcSPI->Regs->CH1TXU = (Uint16)0x0000;
			  }
			  while(!(CSL_MCSPI_REGS->CH1STATL & CSL_MCSPI_CH1STATL_EOT_MASK ));
		 }
	 	 break;
		   case CSL_McSPI_CSNUM_CS2:
	       getWLen = CSL_FEXT(hMcSPI->Regs->CH2CONFL,MCSPI_CH2CONFL_WL);

	       if(getWLen >=  McSPI_MAX_WORD_LEN)
	       {
	        return (CSL_ESYS_INVPARAMS);
	       }
		 if(McSPI_TxEmptyInt_Chk(hMcSPI)){
	       hMcSPI->Regs->CH0TXL = (Uint16)(writeBuffer[bufIndex]);
		  bufIndex++;
		  if(getWLen >=  McSPI_WORD_LENGTH_16){
              hMcSPI->Regs->CH2TXU = (Uint16)(writeBuffer[bufIndex]);
			  bufIndex++;
		  }else{
			  hMcSPI->Regs->CH2TXU = (Uint16)0x0000;
		  }
		  while(!(CSL_MCSPI_REGS->CH2STATL & CSL_MCSPI_CH2STATL_EOT_MASK ));
		  }
	 	 break;
#if	(CH3_ENABLE == 1)
		 case CSL_McSPI_CSNUM_CS3:
	       getWLen = CSL_FEXT(hMcSPI->Regs->CH3CONFL,MCSPI_CH3CONFL_WL);

	       if(getWLen >=  McSPI_MAX_WORD_LEN)
	       {
	        return (CSL_ESYS_INVPARAMS);
	       }
		 if(McSPI_TxEmptyInt_Chk(hMcSPI)){
	       hMcSPI->Regs->TX3L = (Uint16)(writeBuffer[bufIndex]);
		   bufIndex++;
		   if(getWLen >=  McSPI_WORD_LENGTH_16){
              hMcSPI->Regs->TX3U = (Uint16)(writeBuffer[bufIndex]);
			  bufIndex++;
		   }else{
			  hMcSPI->Regs->TX3U = (Uint16)0x0000;
		   }
		   while(!(CSL_MCSPI_REGS->CH3STATL & CSL_MCSPI_CH3STATL_EOT_MASK ));
		  }
	 	 break;
#endif

 		 default:
		 break;
		}

	  default:
	  break;
       }
    }

    return (CSL_SOK);
}

/** ============================================================================
 *   @n@b McSPI_read
 *
 *   @b Description
 *   @n This function reads data from the specified device
 *
 *   @b Arguments
 *   @verbatim
            CSL_McSpiHandle    Handle to the McSPI
	    	Uint16		       Buffer
	    	Uint16		       Buffer length
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_SOK
 *
 *   <b> Pre Condition </b>
 *
 *   <b> Post Condition </b>
 *   @n  Data from source is read
 *
 *   @b Example
 *   @verbatim
            GPIO_Handle     hGPIO;
            CSL_status      status;
            ...
			return (CSL_SOK);

     @endverbatim
 *  ============================================================================
 */

CSL_Status  McSPI_read (CSL_McSpiHandle hMcSPI, Uint16	*readBuffer, Uint16 bufLen)
{
            Int16   getWLen;
   volatile Uint16  bufIndex;
   Uint16 rd_value;


   bufIndex = 0;
   if( (NULL == readBuffer) || (0 == bufLen) || (NULL == hMcSPI) )
   {
   	return (CSL_ESYS_INVPARAMS);
   }

   while(bufIndex < bufLen)
   {
       switch(hMcSPI->McSPIHwConfig.mode)
       {
          case McSPI_MASTER:
              switch(hMcSPI->ch)
              {
	         case CSL_McSPI_CSNUM_CS0:

		      getWLen = CSL_FEXT(hMcSPI->Regs->CH0CONFL,MCSPI_CH0CONFL_WL);


			if(McSPI_RxFullInt_Chk(hMcSPI)){
		      readBuffer[bufIndex] = hMcSPI->Regs->CH0RXL;
		      bufIndex++;
			  if(getWLen >=  McSPI_WORD_LENGTH_16){
		      readBuffer[bufIndex] = hMcSPI->Regs->CH0RXU;
		      bufIndex++;
			  }
			  rd_value =CSL_MCSPI_REGS->IRQSTATUSL;
			  CSL_MCSPI_REGS->IRQSTATUSL = rd_value & CSL_MCSPI_IRQSTATUSL_RX0_FULL_MASK;

			 }
		 	break;

	         case CSL_McSPI_CSNUM_CS1:

		      getWLen = CSL_FEXT(hMcSPI->Regs->CH1CONFL,MCSPI_CH1CONFL_WL);


			if(McSPI_RxFullInt_Chk(hMcSPI)){
		      readBuffer[bufIndex] = hMcSPI->Regs->CH1RXL;
		      bufIndex++;
			  if(getWLen >=  McSPI_WORD_LENGTH_16){
		      readBuffer[bufIndex] = hMcSPI->Regs->CH1RXU;
		      bufIndex++;
			  }
			  rd_value =CSL_MCSPI_REGS->IRQSTATUSL;
			  CSL_MCSPI_REGS->IRQSTATUSL = rd_value & CSL_MCSPI_IRQSTATUSL_RX1_FULL_MASK;

			 }
		 break;

	         case CSL_McSPI_CSNUM_CS2:

		      getWLen = CSL_FEXT(hMcSPI->Regs->CH2CONFL,MCSPI_CH2CONFL_WL);


			if(McSPI_RxFullInt_Chk(hMcSPI)){
		      readBuffer[bufIndex] = hMcSPI->Regs->CH2RXL;
		      bufIndex++;
			  if(getWLen >=  McSPI_WORD_LENGTH_16){
		      readBuffer[bufIndex] = hMcSPI->Regs->CH2RXU;
		      bufIndex++;
			  }
			  rd_value =CSL_MCSPI_REGS->IRQSTATUSL;
			  CSL_MCSPI_REGS->IRQSTATUSL = rd_value & CSL_MCSPI_IRQSTATUSL_RX2_FULL_MASK;

			 }
		 break;
#if	(CH3_ENABLE == 1)
	         case CSL_McSPI_CSNUM_CS3:

		      getWLen = CSL_FEXT(hMcSPI->Regs->CH3CONFL,MCSPI_CH3CONFL_WL);


			if(McSPI_RxFullInt_Chk(hMcSPI)){
		      readBuffer[bufIndex] = hMcSPI->Regs->RX3L;
		      bufIndex++;
			  if(getWLen >=  McSPI_WORD_LENGTH_16){
		      readBuffer[bufIndex] = hMcSPI->Regs->RX3U;
		      bufIndex++;
			  }
			  rd_value =CSL_MCSPI_REGS->IRQSTATUSL;
			  CSL_MCSPI_REGS->IRQSTATUSL = rd_value & CSL_MCSPI_IRQSTATUSL_RX3_FULL_MASK;

			 }
			 break;
#endif
		 default:
		 break;
	      }
	  break;

	  case McSPI_SLAVE:
	     switch(hMcSPI->ch)
         {
	         case CSL_McSPI_CSNUM_CS0:

	     	 getWLen = CSL_FEXT(hMcSPI->Regs->CH0CONFL,MCSPI_CH0CONFL_WL);

		if(McSPI_RxFullInt_Chk(hMcSPI)){
			readBuffer[bufIndex] = hMcSPI->Regs->CH0RXL;
			bufIndex++;
			if(getWLen >=  McSPI_WORD_LENGTH_16){
			readBuffer[bufIndex] = hMcSPI->Regs->CH0RXU;
			bufIndex++;
			}
			  rd_value =CSL_MCSPI_REGS->IRQSTATUSL;
			  CSL_MCSPI_REGS->IRQSTATUSL = rd_value & CSL_MCSPI_IRQSTATUSL_RX0_FULL_MASK;

		}
			break;

		 case CSL_McSPI_CSNUM_CS1:

	      getWLen = CSL_FEXT(hMcSPI->Regs->CH1CONFL,MCSPI_CH1CONFL_WL);


		if(McSPI_RxFullInt_Chk(hMcSPI)){
	      readBuffer[bufIndex] = hMcSPI->Regs->CH1RXL;
	      bufIndex++;
		  if(getWLen >=  McSPI_WORD_LENGTH_16){
	      readBuffer[bufIndex] = hMcSPI->Regs->CH1RXU;
	      bufIndex++;
		  }
			  rd_value =CSL_MCSPI_REGS->IRQSTATUSL;
			  CSL_MCSPI_REGS->IRQSTATUSL = rd_value & CSL_MCSPI_IRQSTATUSL_RX1_FULL_MASK;

		 }
		 break;


		  case CSL_McSPI_CSNUM_CS2:

	      getWLen = CSL_FEXT(hMcSPI->Regs->CH2CONFL,MCSPI_CH2CONFL_WL);


		if(McSPI_RxFullInt_Chk(hMcSPI)){
	      readBuffer[bufIndex] = hMcSPI->Regs->CH2RXL;
	      bufIndex++;
	      if(getWLen >=  McSPI_WORD_LENGTH_16){
	      readBuffer[bufIndex] = hMcSPI->Regs->CH2RXU;
	      bufIndex++;
		  }
			  rd_value =CSL_MCSPI_REGS->IRQSTATUSL;
			  CSL_MCSPI_REGS->IRQSTATUSL = rd_value & CSL_MCSPI_IRQSTATUSL_RX2_FULL_MASK;

	    }
		 break;
#if	(CH3_ENABLE == 1)
		 case CSL_McSPI_CSNUM_CS3:

	      getWLen = CSL_FEXT(hMcSPI->Regs->CH3CONFL,MCSPI_CH3CONFL_WL);

		if(McSPI_RxFullInt_Chk(hMcSPI)){
	      readBuffer[bufIndex] = hMcSPI->Regs->RX3L;
	      bufIndex++;
	      if(getWLen >=  McSPI_WORD_LENGTH_16){
	      readBuffer[bufIndex] = hMcSPI->Regs->RX3U;
	      bufIndex++;
		  }
			  rd_value =CSL_MCSPI_REGS->IRQSTATUSL;
			  CSL_MCSPI_REGS->IRQSTATUSL = rd_value & CSL_MCSPI_IRQSTATUSL_RX3_FULL_MASK;

		 }
		 break;
#endif
		 default:
		 break;
		 }

	  break;

	  default:
	  break;
       }
   }

   return (CSL_SOK);
}
/** ============================================================================
 *   @n@b McSPI_RxFullInt_Chk
 *
 *   @b Description
 *   @n This function checks if the RX channel is full
 *
 *   @b Arguments
 *   @verbatim
            CSL_McSpiHandle            Handle to the McSPI
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_SOK
 *
 *   <b> Pre Condition </b>
 *
 *   <b> Post Condition </b>
 *   @n
 *
 *   @b Example
 *   @verbatim
            GPIO_Handle     hGPIO;
            CSL_status      status;
            ...
			return (CSL_SOK);

     @endverbatim
 *  ============================================================================
 */
Uint16  McSPI_RxFullInt_Chk (CSL_McSpiHandle hMcSPI)
{
Uint16 flag = 0;
   switch(hMcSPI->McSPIHwConfig.mode)
   {
      case McSPI_MASTER:
          switch(hMcSPI->ch)
          {
            case CSL_McSPI_CSNUM_CS0:

			flag = ( (hMcSPI->Regs->IRQSTATUSL & CSL_MCSPI_IRQSTATUSL_RX0_FULL_MASK) );
	        break;

	     case CSL_McSPI_CSNUM_CS1:

			flag = ( (hMcSPI->Regs->IRQSTATUSL & CSL_MCSPI_IRQSTATUSL_RX1_FULL_MASK) );
	     break;

	     case CSL_McSPI_CSNUM_CS2:

			 flag = ( (hMcSPI->Regs->IRQSTATUSL & CSL_MCSPI_IRQSTATUSL_RX2_FULL_MASK) );
	     break;
#if	(CH3_ENABLE == 1)
	     case CSL_McSPI_CSNUM_CS3:
			flag = ( (hMcSPI->Regs->IRQSTATUSL & CSL_MCSPI_IRQSTATUSL_RX3_FULL_MASK) );
	     break;
#endif
	     default:
	     break;
	  }
      break;

      case McSPI_SLAVE:
		  switch(hMcSPI->ch)
          {
             case CSL_McSPI_CSNUM_CS0:

			flag = ( (hMcSPI->Regs->IRQSTATUSL & CSL_MCSPI_IRQSTATUSL_RX0_FULL_MASK) );
	     	break;

	     case CSL_McSPI_CSNUM_CS1:

			flag = ( (hMcSPI->Regs->IRQSTATUSL & CSL_MCSPI_IRQSTATUSL_RX1_FULL_MASK) );
	     	break;

	     case CSL_McSPI_CSNUM_CS2:

			 flag = ( (hMcSPI->Regs->IRQSTATUSL & CSL_MCSPI_IRQSTATUSL_RX2_FULL_MASK) );
	     	break;
#if	(CH3_ENABLE == 1)
	     case CSL_McSPI_CSNUM_CS3:

			flag = ( (hMcSPI->Regs->IRQSTATUSL & CSL_MCSPI_IRQSTATUSL_RX3_FULL_MASK) );
	     	break;
#endif
	     default:
	     break;
	  }
	  break;

      default:
      break;
   }

   return (flag);
 }
/** ============================================================================
 *   @n@b McSPI_TxEmptyInt_Chk
 *
 *   @b Description
 *   @n This function checks if the TX channel is empty
 *
 *   @b Arguments
 *   @verbatim
            CSL_McSpiHandle            Handle to the McSPI
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_SOK
 *
 *   <b> Pre Condition </b>
 *
 *   <b> Post Condition </b>
 *   @n
 *
 *   @b Example
 *   @verbatim
            GPIO_Handle     hGPIO;
            CSL_status      status;
            ...
			return (CSL_SOK);

     @endverbatim
 *  ============================================================================
 */
Uint16  McSPI_TxEmptyInt_Chk (CSL_McSpiHandle hMcSPI)
{

   switch(hMcSPI->McSPIHwConfig.mode)
   {
      case McSPI_MASTER:
          switch(hMcSPI->ch)
          {
             case CSL_McSPI_CSNUM_CS0:

	        return( (hMcSPI->Regs->IRQSTATUSL & CSL_MCSPI_IRQSTATUSL_TX0_EMPTY_MASK) ) ;

	     case CSL_McSPI_CSNUM_CS1:

	        return( (hMcSPI->Regs->IRQSTATUSL & CSL_MCSPI_IRQSTATUSL_TX1_EMPTY_MASK) ) ;

	     case CSL_McSPI_CSNUM_CS2:

	        return( (hMcSPI->Regs->IRQSTATUSL & CSL_MCSPI_IRQSTATUSL_TX2_EMPTY_MASK) ) ;
#if	(CH3_ENABLE == 1)
	     case CSL_McSPI_CSNUM_CS3:

	        return( (hMcSPI->Regs->IRQSTATUSL & CSL_MCSPI_IRQSTATUSL_TX3_EMPTY_MASK) ) ;
#endif
	     default:
	     break;
	  }
      break;

      case McSPI_SLAVE:

	   switch(hMcSPI->ch)
          {
             case CSL_McSPI_CSNUM_CS0:

	        return( (hMcSPI->Regs->IRQSTATUSL & CSL_MCSPI_IRQSTATUSL_TX0_EMPTY_MASK) ) ;

	     case CSL_McSPI_CSNUM_CS1:

	        return( (hMcSPI->Regs->IRQSTATUSL & CSL_MCSPI_IRQSTATUSL_TX1_EMPTY_MASK) ) ;

	     case CSL_McSPI_CSNUM_CS2:

	        return( (hMcSPI->Regs->IRQSTATUSL & CSL_MCSPI_IRQSTATUSL_TX2_EMPTY_MASK) ) ;
#if	(CH3_ENABLE == 1)
	     case CSL_McSPI_CSNUM_CS3:

	        return( (hMcSPI->Regs->IRQSTATUSL & CSL_MCSPI_IRQSTATUSL_TX3_EMPTY_MASK) ) ;
#endif
	     default:
	     break;
	  }

      break;

      default:
      break;
   }

   return (CSL_SOK);
}
#else
#endif
