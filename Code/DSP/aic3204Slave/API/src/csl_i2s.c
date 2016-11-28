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


/** @file csl_i2s.c
 *
 *  @brief I2S functional layer API defenition file
 *
 *  Path: \(CSLPATH)/src
 */

/* ============================================================================
 * Revision History
 * ================
 * 25-Aug-2008 Added I2S for CSL.
 * 25-Aug-2008 Updated for Doxygen.
 * 28-Aug-2008 Added Return Types for Error checking for API's parameter.
 * 04-Jan-2009 Modified I2S_read to add latency for the first data receive
 * 11-Jan-2010 Replaced magic numbers with macros as per review comments
 * 13-Aug-2010 CSL v2.10 release
 * 06-Jul-2011 CSL v2.50 release
 * 13-Sep-2012 CSL v3.00 release
 * 20-Dec-2012 CSL v3.01 release
 * ============================================================================
 */

#include "csl_i2s.h"
#include "csl_sysctrl.h"

Uint16	fsError = 0;	/**< FSYNC gobal parameter 				*/
Uint16	ouError = 0;	/**< under/over run global parameter	*/


/** ===========================================================================
 *   @n@b I2S_open
 *
 *   @b Description
 *   @n This function returns the handle to the I2S
 *      instance. This handle is passed to all other CSL APIs.
 *
 *   @b Arguments
 *   @verbatim
            i2sInstNum	Instance number to open.
            opMode		Mode of operation (intrrupt/Polling/DMA)
			chType		Channel Type (Stereo/Mono)
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_I2sHandle
 *   @n                     Valid I2S handle will be returned if
 *                          handler value is not equal to NULL.
 *
 *   <b> Pre Condition </b>
 *   @n
 *
 *   <b> Post Condition </b>
 *   @n   1.    The status is returned in the status variable. If status
 *              returned is
 *   @li            NULL               - InValid I2S handle is returned
 *   @n   2.    CSL_DMA_ChannelObj object structure is populated
 *
 *   @b Modifies
 *   @n    1. CSL_I2sObj	 I2S object structure
 *   @n    2.
 *
 *   @b Example
 *   @verbatim

            I2S_Instance		 i2sInstNum;
            I2S_OpMode		     opMode;
            I2S_ChanType 	     chType;
            ...

            hI2S = I2S_open(I2S_Instance	i2sInstNum,
					   		I2S_OpMode		opMode,
					   		I2S_ChanType 	chType);
            ...
    @endverbatim
 *  ===========================================================================
 */

CSL_I2sHandle I2S_open(I2S_Instance		i2sInstNum,
					   I2S_OpMode		opMode,
					   I2S_ChanType 	chType)
{
	CSL_I2sHandle hI2s;
	ioport volatile CSL_SysRegs		*sysRegs;
	///ioport volatile CSL_SysPGFlags	*sysFlags;
	hI2s = NULL;
	/* Check device is already in used*/
#if (defined(CHIP_C5517)) //No I2S1 in CHIP 5517
	if(i2sInstNum == I2S_INVALID || i2sInstNum == I2S_INSTANCE1)
	{
		return (NULL);
	}
#else
	if(i2sInstNum == I2S_INVALID)
	{
		return (NULL);
	}
#endif

	hI2s = &I2S_InstanceNum[i2sInstNum];

	if((i2sInstNum >= 0) & (i2sInstNum <= 3))
	{
		hI2s->i2sNum    = i2sInstNum;
		hI2s->chType    = chType;
		hI2s->opMode    = opMode;
		hI2s->firstRead = TRUE;

		sysRegs = (CSL_SysRegs *)CSL_SYSCTRL_REGS;
		/* Configure the Peripheral Reset Control Register in each instance */
    	//CSL_FINS(sysRegs->PRCR, SYS_PRCR_PG3_RST, CSL_SYS_PRCR_PG3_RST_RST);
		//CSL_FINS(sysRegs->PRCR, SYS_PRCR_PG4_RST, CSL_SYS_PRCR_PG4_RST_RST);

		/* Set Instance hardware registers*/
		switch(i2sInstNum)
		{
			case I2S_INSTANCE0:
				SYS_peripheralReset(CSL_SYS_PG3);
				hI2s->hwRegs = (CSL_I2sRegs *)(CSL_I2S0_REGS);
				CSL_FINS(sysRegs->PCGCR1, SYS_PCGCR1_I2S0CG,
										CSL_SYS_PCGCR1_I2S0CG_ACTIVE);
//				CSL_FINS(sysRegs->EBSR, SYS_EBSR_SP0MODE,
//										CSL_SYS_EBSR_SP0MODE_MODE1);
				break;
#if (!(defined(CHIP_C5517)))
			case I2S_INSTANCE1:
				SYS_peripheralReset(CSL_SYS_PG3);
				hI2s->hwRegs = (CSL_I2sRegs *)(CSL_I2S1_REGS);
				CSL_FINS(sysRegs->PCGCR1, SYS_PCGCR1_I2S1CG,
										CSL_SYS_PCGCR1_I2S1CG_ACTIVE);
//				CSL_FINS(sysRegs->EBSR, SYS_EBSR_SP1MODE,
//										CSL_SYS_EBSR_SP1MODE_MODE1);
				break;
#endif
			case I2S_INSTANCE2:
				SYS_peripheralReset(CSL_SYS_PG4);
				hI2s->hwRegs = (CSL_I2sRegs *)(CSL_I2S2_REGS);
				CSL_FINS(sysRegs->PCGCR1, SYS_PCGCR1_I2S2CG,
										CSL_SYS_PCGCR1_I2S2CG_ACTIVE);
//				CSL_FINS(sysRegs->EBSR, SYS_EBSR_PPMODE,
//										CSL_SYS_EBSR_PPMODE_MODE6);
				break;
			case I2S_INSTANCE3:
				SYS_peripheralReset(CSL_SYS_PG4);
				hI2s->hwRegs = (CSL_I2sRegs *)(CSL_I2S3_REGS);
				CSL_FINS(sysRegs->PCGCR1, SYS_PCGCR1_I2S3CG,
										CSL_SYS_PCGCR1_I2S3CG_ACTIVE);
//				CSL_FINS(sysRegs->EBSR, SYS_EBSR_PPMODE,
//										CSL_SYS_EBSR_PPMODE_MODE6);
				break;
			default:
				break;
		}
	}
	hI2s->configured = FALSE;
	return(hI2s);
}

/** ===========================================================================
 *   @n@b I2S_setup
 *
 *   @b Description
 *   @n It configures the I2S Controller registers of particular handle as per
 *      the values passed in the I2S config structure.
 *
 *   @b Arguments
 *   @verbatim
            i2sHandle       Handle to the I2S.
            i2sHwConfig     Pointer to I2S Config structure.

     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK             - Hardware setup successful
 *   @li                    CSL_ESYS_BADHANDLE  - Invalid handle
 *   @li                    CSL_ESYS_INVPARAMS  - Congig Parameter is invalid.
 *
 *   <b> Pre Condition </b>
 *   @n  I2S_open has to call, before calling I2S_setup
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Modifies
 *   @n 1. I2S registers will be updated as per config parameter
 *   @n 2. CSL_I2sObj Object will be updated to store some info
 *              as passed config parameter.
 *
 *   @b Example
 *   @verbatim
            CSL_I2sHandle   hI2S;
            I2S_Config      hwConfig;
            Int16           status;

            status = I2S_setup(hI2S, &hwConfig);
            ...

     @endverbatim
 *  ===========================================================================
 */
CSL_Status I2S_setup(CSL_I2sHandle	hI2s,
				     I2S_Config 	*i2sHwConfig)
{
	ioport CSL_I2sRegs	  *regs;

	if(NULL == hI2s)
	{
		return (CSL_ESYS_BADHANDLE);
	}

	if(NULL == i2sHwConfig)
	{
		return (CSL_ESYS_INVPARAMS);
	}

	if(TRUE != hI2s->configured)
	{
		regs = hI2s->hwRegs;

		hI2s->fsDiv        = i2sHwConfig->fsDiv;
		hI2s->loopBackMode = i2sHwConfig->loopBackMode;
		hI2s->datapack     = i2sHwConfig->datapack;
		hI2s->wordLen      = i2sHwConfig->wordLen;

		/* Reset All the registers*/
		regs->I2SSCTRL   &= (Uint16)CSL_I2S_I2SSCTRL_RESETVAL;
		regs->I2SSRATE   &= (Uint16)CSL_I2S_I2SSRATE_RESETVAL;

#if (defined(CHIP_C5517))
		regs->I2STXLTL   &= (Uint16)CSL_I2S_I2STXLTL_RESETVAL;
		regs->I2STXLTU   &= (Uint16)CSL_I2S_I2STXLTU_RESETVAL;
		regs->I2STXRTL   &= (Uint16)CSL_I2S_I2STXRTL_RESETVAL;
		regs->I2STXRTU   &= (Uint16)CSL_I2S_I2STXRTU_RESETVAL;
#else
		regs->I2STXLT0   &= (Uint16)CSL_I2S_I2STXLT0_RESETVAL;
		regs->I2STXLT1   &= (Uint16)CSL_I2S_I2STXLT1_RESETVAL;
		regs->I2STXRT0   &= (Uint16)CSL_I2S_I2STXRT0_RESETVAL;
		regs->I2STXRT1   &= (Uint16)CSL_I2S_I2STXRT1_RESETVAL;
#endif

		regs->I2SINTFL   &= (Uint16)CSL_I2S_I2SINTFL_RESETVAL;
		regs->I2SINTMASK &= (Uint16)CSL_I2S_I2SINTMASK_RESETVAL;

#if (defined(CHIP_C5517))
		regs->I2SRXLTL   &= (Uint16)CSL_I2S_I2SRXLTL_RESETVAL;
		regs->I2SRXLTU   &= (Uint16)CSL_I2S_I2SRXLTU_RESETVAL;
		regs->I2SRXRTL   &= (Uint16)CSL_I2S_I2SRXRTL_RESETVAL;
		regs->I2SRXRTU   &= (Uint16)CSL_I2S_I2SRXRTU_RESETVAL;
#else
		regs->I2SRXLT0   &= (Uint16)CSL_I2S_I2SRXLT0_RESETVAL;
		regs->I2SRXLT1   &= (Uint16)CSL_I2S_I2SRXLT1_RESETVAL;
		regs->I2SRXRT0   &= (Uint16)CSL_I2S_I2SRXRT0_RESETVAL;
		regs->I2SRXRT1   &= (Uint16)CSL_I2S_I2SRXRT1_RESETVAL;
#endif

		/* Data transmit/receive is Mono/Stereo type*/
		CSL_FINS(regs->I2SSCTRL, I2S_I2SSCTRL_MONO, i2sHwConfig->dataType);

		/* Enable/disable the loopback bit */
		CSL_FINS(regs->I2SSCTRL, I2S_I2SSCTRL_LOOPBACK, i2sHwConfig->loopBackMode);

		/* Set FSYNC polarity is High/Low */
		CSL_FINS(regs->I2SSCTRL, I2S_I2SSCTRL_FSPOL, i2sHwConfig->fsPol);

		/* Set the clock polarity FALLING/RESING */
		CSL_FINS(regs->I2SSCTRL, I2S_I2SSCTRL_CLKPOL, i2sHwConfig->clkPol);

		/* Data delay set to ONE/TWo bit*/
		CSL_FINS(regs->I2SSCTRL, I2S_I2SSCTRL_DATADLY, i2sHwConfig->datadelay);

		/* Data packing Enable/Disable */
		CSL_FINS(regs->I2SSCTRL, I2S_I2SSCTRL_PACK, i2sHwConfig->datapack);

		/* Set data sign extension*/
		CSL_FINS(regs->I2SSCTRL, I2S_I2SSCTRL_SIGN_EXT, i2sHwConfig->signext);

		/* Set Word length for a word */
		CSL_FINS(regs->I2SSCTRL, I2S_I2SSCTRL_WDLNGTH, i2sHwConfig->wordLen);

		/* Set the Mode of transmission */
		if(i2sHwConfig->i2sMode == I2S_SLAVE)
		{
			CSL_FINST(regs->I2SSCTRL, I2S_I2SSCTRL_MODE, CLEAR);
		}
		else
		{
			CSL_FINST(regs->I2SSCTRL, I2S_I2SSCTRL_MODE, SET);
		}

		/* Channel type is Mono/Stereo, Set the dependant bit*/
		if(hI2s->chType == I2S_CHAN_MONO)
		{
			CSL_FINST(regs->I2SSCTRL, I2S_I2SSCTRL_FRMT, SET);
			/* Left transmit & recv channel disable */
			CSL_FINST(regs->I2SINTMASK, I2S_I2SINTMASK_XMITST, DISABLE);
			CSL_FINST(regs->I2SINTMASK, I2S_I2SINTMASK_XMITMON, ENABLE);
			CSL_FINST(regs->I2SINTMASK, I2S_I2SINTMASK_RCVST, DISABLE);
			CSL_FINST(regs->I2SINTMASK, I2S_I2SINTMASK_RCVMON, ENABLE);
		}
		else
		{
			CSL_FINST(regs->I2SSCTRL, I2S_I2SSCTRL_FRMT, CLEAR);
			/* Right transmit & recv channel disable */
			CSL_FINST(regs->I2SINTMASK, I2S_I2SINTMASK_XMITST, ENABLE);
			CSL_FINST(regs->I2SINTMASK, I2S_I2SINTMASK_XMITMON, DISABLE);
			CSL_FINST(regs->I2SINTMASK, I2S_I2SINTMASK_RCVST, ENABLE);
			CSL_FINST(regs->I2SINTMASK, I2S_I2SINTMASK_RCVMON, DISABLE);
		}

		/* Set the bit for the frame sync devider */
		CSL_FINS(regs->I2SSRATE, I2S_I2SSRATE_FSDIV, i2sHwConfig->fsDiv);

		/* Set bit for the serializer clock divider */
		CSL_FINS(regs->I2SSRATE, I2S_I2SSRATE_CLKDIV, i2sHwConfig->clkDiv);

		/* Frame-sync error enable/disable	*/
		CSL_FINS(regs->I2SINTMASK, I2S_I2SINTMASK_FERR, i2sHwConfig->FError);

		/* Overrun or under-run error enable/disable	*/
		CSL_FINS(regs->I2SINTMASK, I2S_I2SINTMASK_OUERR, i2sHwConfig->OuError);

		/* Reset the IR*/
		regs->I2SINTFL &= (Uint16)CSL_I2S_I2SINTFL_RESETVAL;

		hI2s->configured = TRUE;
	}
	return(CSL_SOK);
}

/** ===========================================================================
 *   @n@b I2S_close
 *
 *   @b Description
 *   @n This function closes the specified handle to I2S.
 *
 *   @b Arguments
 *   @verbatim
            i2sHandle          Handle to the I2S
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK             - Close successful
 *   @li                    CSL_ESYS_BADHANDLE  - Invalid handle
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  None
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
            CSL_I2sHandle   hI2S;
            CSL_status   status;

            status = I2S_close(hI2S);
     @endverbatim
 *  ===========================================================================
 */
CSL_Status I2S_close(CSL_I2sHandle	hI2s)
{
	Int16 status;
	ioport volatile CSL_SysRegs		*sysRegs;

	if(NULL == hI2s)
	{
		return (CSL_ESYS_BADHANDLE);
	}

	sysRegs = (CSL_SysRegs *)CSL_SYSCTRL_REGS;

	switch(hI2s->i2sNum)
	{
		case I2S_INSTANCE0:
			CSL_FINS(sysRegs->PCGCR1, SYS_PCGCR1_I2S0CG,
										CSL_SYS_PCGCR1_I2S0CG_DISABLED);
			break;
	#if (!(defined(CHIP_C5517)))
		case I2S_INSTANCE1:
			CSL_FINS(sysRegs->PCGCR1, SYS_PCGCR1_I2S1CG,
										CSL_SYS_PCGCR1_I2S1CG_DISABLED);
			break;
	#endif
		case I2S_INSTANCE2:
			CSL_FINS(sysRegs->PCGCR1, SYS_PCGCR1_I2S2CG,
										CSL_SYS_PCGCR1_I2S2CG_DISABLED);
			break;
		case I2S_INSTANCE3:
			CSL_FINS(sysRegs->PCGCR1, SYS_PCGCR1_I2S3CG,
										CSL_SYS_PCGCR1_I2S3CG_DISABLED);
			break;
	}

	I2S_InstanceNum[hI2s->i2sNum].hwRegs = NULL;

	/* Reset the Instance to Invalid */
	hI2s->i2sNum = I2S_INVALID;

	/* Set the configutation to FALSE */
	hI2s->configured = FALSE;
	hI2s = NULL;
	status = CSL_SOK;

	return (status);
}

/** ===========================================================================
 *   @n@b I2S_read
 *
 *   @b Description
 *   @n This function Read data form specified device.
 *      This function introduces a delay during the first data receive operation.
 *      Data latency is calculated as per the I2S hardware specification. This
 *      delay is applicable only to polled mode operation. For interrupt mode
 *      this function should be called only after getting the receive interrupt
 *      from the I2S.
 *
 *   @b Arguments
 *   @verbatim
            i2sHandle          Handle to the I2S
			readBuff          Pointer to the read buffer.
			buffLen           Maximum read buffer size.
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK             - Read successful
 *   @li                    CSL_ESYS_BADHANDLE  - Invalid handle
 *
 *   <b> Pre Condition </b>
 *   @n  This function has to call after I2S_open function call.
 *
 *   <b> Post Condition </b>
 *   @n  SPI_close can be call after this function call.
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
            CSL_I2sHandle   hI2S;
			Uint16          readBuff[size];
            Uint16          buffLen;
            CSL_status   status;

            status = I2S_read(hI2S, &readBuff, buffLen);
     @endverbatim
 *  ===========================================================================
 */
CSL_Status I2S_read (CSL_I2sHandle	hI2s,
				Uint16 *readBuff, Uint16 buffLen)
{
	ioport	CSL_I2sRegs	  *regs;
	Uint16	i2sIrStatus;
	Int16  latency;
	Uint16  dummyData;

	if(NULL == hI2s)
	{
		return(CSL_ESYS_BADHANDLE);
	}

	if ((NULL == readBuff) || (0 == buffLen))
	{
		return(CSL_ESYS_INVPARAMS);
	}

	regs = hI2s->hwRegs;

	if ((hI2s->firstRead == TRUE) && (hI2s->opMode == I2S_POLLED))
	{
		hI2s->firstRead = FALSE;

		if (hI2s->loopBackMode == I2S_LOOPBACK_ENABLE)
		{
			if (hI2s->datapack == I2S_DATAPACK_ENABLE)
			{
				switch(hI2s->wordLen)
				{
	     			case I2S_WORDLEN_8:
						if(hI2s->fsDiv == I2S_FSDIV8)
						{
							latency = CSL_I2S_LATENCY_6;
						}
						else
						{
							latency = CSL_I2S_LATENCY_5;
						}

						break;

	     			case I2S_WORDLEN_10:
	     			case I2S_WORDLEN_12:
	     			case I2S_WORDLEN_14:
	     			case I2S_WORDLEN_16:
						latency = 6;
						break;

					default:
						break;
				}
			}
			else
			{
				latency = CSL_I2S_LATENCY_2;
			}
		}
		else
		{
			switch(hI2s->wordLen)
			{
     			case I2S_WORDLEN_8:
     			case I2S_WORDLEN_18:
     			case I2S_WORDLEN_20:
     			case I2S_WORDLEN_24:
     			case I2S_WORDLEN_32:
					latency = CSL_I2S_LATENCY_2;
					break;

     			case I2S_WORDLEN_10:
     			case I2S_WORDLEN_12:
     			case I2S_WORDLEN_14:
     			case I2S_WORDLEN_16:
					latency = CSL_I2S_LATENCY_3;
					break;

				default:
					break;
			}
		}

		/* Ignore the first few frames */
		while(latency > 0)
		{
			i2sIrStatus = regs->I2SINTFL;

			if((i2sIrStatus & CSL_I2S_I2SINTFL_RCVMONFL_MASK) ||
			   (i2sIrStatus & CSL_I2S_I2SINTFL_RCVSTFL_MASK))
			{
			    /* Copy data from receive register to local buffer      */
#if (defined(CHIP_C5517))
				dummyData = regs->I2SRXLTU;
				dummyData = regs->I2SRXLTL;
#else
				dummyData = regs->I2SRXLT1;
				dummyData = regs->I2SRXLT0;
#endif

				if(hI2s->chType == I2S_CHAN_STEREO)
				{
#if (defined(CHIP_C5517))
					dummyData = regs->I2SRXRTU;
					dummyData = regs->I2SRXRTL;
#else
					dummyData = regs->I2SRXRT1;
					dummyData = regs->I2SRXRT0;
#endif

					/* Reset IIR register for the stereo channel  */
					CSL_FINST(regs->I2SINTFL, I2S_I2SINTFL_RCVSTFL, CLEAR);
				}

				/* Reset IIR register for the stereo channel  */
				CSL_FINST(regs->I2SINTFL, I2S_I2SINTFL_RCVMONFL, CLEAR);
				latency--;
				latency--;
			}
		}

		dummyData = dummyData;
	}

	/* This function is not supporting for DMA_POLLED & DMA_INTERRUPT mode */
	if((hI2s->opMode == DMA_POLLED)||
		(hI2s->opMode == DMA_INTERRUPT))
	{
		return(CSL_ESYS_INVPARAMS);
	}

	if(hI2s->opMode == I2S_INTERRUPT)
	{
	    /* Copy data from receive register to local buffer      */
		while(buffLen > 0)
		{
#if (defined(CHIP_C5517))
			*readBuff++ = regs->I2SRXLTU;
			*readBuff++ = regs->I2SRXLTL;
#else
			*readBuff++ = regs->I2SRXLT1;
			*readBuff++ = regs->I2SRXLT0;
#endif

			if(hI2s->chType == I2S_CHAN_STEREO)
			{
#if (defined(CHIP_C5517))
				*readBuff++ = regs->I2SRXRTU;
				*readBuff++ = regs->I2SRXRTL;
#else
				*readBuff++ = regs->I2SRXRT1;
				*readBuff++ = regs->I2SRXRT0;
#endif
				buffLen -= 2;
			}
			buffLen -= 2;
		}

		/* Reset IIR register for the mono and sterio channel  */
		CSL_FINST(regs->I2SINTFL, I2S_I2SINTFL_RCVSTFL, CLEAR);
		CSL_FINST(regs->I2SINTFL, I2S_I2SINTFL_RCVMONFL, CLEAR);
	}
	else
	{
		while((buffLen > 0) && (fsError == 0) &&
				(ouError == 0))
		{
			i2sIrStatus = regs->I2SINTFL;
			if(i2sIrStatus & CSL_I2S_I2SINTFL_FERRFL_MASK)
			{
				fsError++;
			}

			if(i2sIrStatus & CSL_I2S_I2SINTFL_OUERRFL_MASK)
			{
				ouError++;
			}

			if((i2sIrStatus & CSL_I2S_I2SINTFL_RCVMONFL_MASK) ||
			   (i2sIrStatus & CSL_I2S_I2SINTFL_RCVSTFL_MASK))
			{
			    /* Copy data from receive register to local buffer      */
#if (defined(CHIP_C5517))
				*readBuff++ = regs->I2SRXLTU;
				*readBuff++ = regs->I2SRXLTL;
#else
				*readBuff++ = regs->I2SRXLT1;
				*readBuff++ = regs->I2SRXLT0;
#endif
				if(i2sIrStatus & CSL_I2S_I2SINTFL_RCVSTFL_MASK)
				{
#if (defined(CHIP_C5517))
					*readBuff++ = regs->I2SRXRTU;
					*readBuff++ = regs->I2SRXRTL;
#else
					*readBuff++ = regs->I2SRXRT1;
					*readBuff++ = regs->I2SRXRT0;
#endif
					/* Reset IIR register for the sterio channel  */
					CSL_FINST(regs->I2SINTFL, I2S_I2SINTFL_RCVSTFL, CLEAR);
					buffLen -= 2;
				}
				/* Reset IIR register for the sterio channel  */
				CSL_FINST(regs->I2SINTFL, I2S_I2SINTFL_RCVMONFL, CLEAR);
				buffLen -= 2;
			}
		}
	}

	fsError = 0;
	ouError = 0;

	return (CSL_SOK);
}

/** ===========================================================================
 *   @n@b I2S_write
 *
 *   @b Description
 *   @n This function Write data to specified device.
 *
 *   @b Arguments
 *   @verbatim
            i2sHandle         Handle to the I2S
			writeBuff         Pointer to the write buffer.
			buffLen           Maximum read buffer size.
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK             - Write successful
 *   @li                    CSL_ESYS_BADHANDLE  - Invalid handle
 *
 *   <b> Pre Condition </b>
 *   @n  This function has to call after I2S_open function call.
 *
 *   <b> Post Condition </b>
 *   @n  SPI_close can be call after this function call.
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
            CSL_I2sHandle   hI2S;
			Uint16          writeBuff[size];
            Uint16          buffLen;
            CSL_status   status;

            status = I2S_write(hI2S, &writeBuff, buffLen);
     @endverbatim
 *  ===========================================================================
 */
CSL_Status I2S_write(CSL_I2sHandle	hI2s,
				Uint16 *writeBuff, Uint16 buffLen)
{
	ioport	CSL_I2sRegs	  *regs;
	Uint16	i2sIrStatus;
	volatile Int16   i;

	if(hI2s == NULL)
	{
		return(CSL_ESYS_BADHANDLE);
	}

	if((NULL == writeBuff) || (0 == buffLen))
	{
		return(CSL_ESYS_INVPARAMS);
	}

	/* This function is not supporting for DMA_POLLED & DMA_INTERRUPT mode */
	if((hI2s->opMode == DMA_POLLED)||
		(hI2s->opMode == DMA_INTERRUPT))
	{
		return(CSL_ESYS_INVPARAMS);
	}

	regs = hI2s->hwRegs;

	if(hI2s->opMode == I2S_INTERRUPT)
	{
		while(buffLen > 0)
		{
		    /* Copy data from local buffer to transmit register  */

#if (defined(CHIP_C5517))
	 		regs->I2STXLTL = *writeBuff++;
			regs->I2STXLTU = *writeBuff++;
#else
	 		regs->I2STXLT0 = *writeBuff++;
			regs->I2STXLT1 = *writeBuff++;
#endif

			if(hI2s->chType == I2S_CHAN_STEREO)
			{
#if (defined(CHIP_C5517))
				regs->I2STXRTL = *writeBuff++;
				regs->I2STXRTU = *writeBuff++;
#else
				regs->I2STXRT0 = *writeBuff++;
				regs->I2STXRT1 = *writeBuff++;
#endif
				buffLen -= 2;
			}
			buffLen -= 2;
		}
	}
	else
	{
		while((buffLen > 0) && (fsError == 0) &&
				(ouError == 0))
		{
			i2sIrStatus = regs->I2SINTFL;

			if(i2sIrStatus & CSL_I2S_I2SINTFL_FERRFL_MASK)
			{
				fsError++;
			}

			if(i2sIrStatus & CSL_I2S_I2SINTFL_OUERRFL_MASK)
			{
				ouError++;
			}

			if((i2sIrStatus & CSL_I2S_I2SINTFL_XMITMONFL_MASK) ||
				(i2sIrStatus &  CSL_I2S_I2SINTFL_XMITSTFL_MASK))
			{
			    /* Copy data from local buffer to transmit register  */

#if (defined(CHIP_C5517))
				regs->I2STXLTL = *writeBuff++;
				//for(i = 0; i < 100; i++);
				regs->I2STXLTU = *writeBuff++;
#else
				regs->I2STXLT0 = *writeBuff++;
				//for(i = 0; i < 100; i++);
				regs->I2STXLT1 = *writeBuff++;
#endif

				//for(i = 0; i < 100; i++);
				if(i2sIrStatus & CSL_I2S_I2SINTFL_XMITSTFL_MASK)
				{
#if (defined(CHIP_C5517))
					regs->I2STXRTL = *writeBuff++;
					//for(i = 0; i < 100; i++);
					regs->I2STXRTU = *writeBuff++;
					//for(i = 0; i < 100; i++);
#else
					regs->I2STXRT0 = *writeBuff++;
					//for(i = 0; i < 100; i++);
					regs->I2STXRT1 = *writeBuff++;
					//for(i = 0; i < 100; i++);
#endif
					buffLen -= 2;
				}
				buffLen -= 2;
			}
		}
	}

	fsError = 0;
	ouError = 0;

	return (CSL_SOK);
}

/** ===========================================================================
 *   @n@b I2S_reset
 *
 *   @b Description
 *   @n This function Reset control and hardware specific register.
 *
 *   @b Arguments
 *   @verbatim
            i2sHandle         Handle to the I2S
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK             - Reset successful
 *   @li                    CSL_ESYS_BADHANDLE  - Invalid handle
 *
 *   <b> Pre Condition </b>
 *   @n  This function should call after the I2S_config call.
 *
 *   <b> Post Condition </b>
 *   @n  I2S_close function can be call after this function call.
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
            CSL_I2sHandle   hI2S;
            CSL_status   status;

            status = I2S_reset(hI2S);
     @endverbatim
 *  ===========================================================================
 */
CSL_Status I2S_reset(CSL_I2sHandle	hI2s)
{
	ioport	CSL_I2sRegs	  *regs;

	if(hI2s == NULL)
	{
		return(CSL_ESYS_BADHANDLE);
	}

	regs = 	hI2s->hwRegs;

	/* Reset the register */
	regs->I2SSCTRL &= (Uint16)CSL_I2S_I2SSCTRL_RESETVAL;
	regs->I2SSRATE &= (Uint16)CSL_I2S_I2SSRATE_RESETVAL;

#if (defined(CHIP_C5517))
	regs->I2STXLTL &= (Uint16)CSL_I2S_I2STXLTL_RESETVAL;
	regs->I2STXLTU &= (Uint16)CSL_I2S_I2STXLTU_RESETVAL;
	regs->I2STXRTL &= (Uint16)CSL_I2S_I2STXRTL_RESETVAL;
	regs->I2STXRTU &= (Uint16)CSL_I2S_I2STXRTU_RESETVAL;
#else
	regs->I2STXLT0 &= (Uint16)CSL_I2S_I2STXLT0_RESETVAL;
	regs->I2STXLT1 &= (Uint16)CSL_I2S_I2STXLT1_RESETVAL;
	regs->I2STXRT0 &= (Uint16)CSL_I2S_I2STXRT0_RESETVAL;
	regs->I2STXRT1 &= (Uint16)CSL_I2S_I2STXRT1_RESETVAL;
#endif

	regs->I2SINTFL &= (Uint16)CSL_I2S_I2SINTFL_RESETVAL;
	regs->I2SINTMASK   &= (Uint16)CSL_I2S_I2SINTMASK_RESETVAL;

#if (defined(CHIP_C5517))
	regs->I2SRXLTL &= (Uint16)CSL_I2S_I2SRXLTL_RESETVAL;
	regs->I2SRXLTU &= (Uint16)CSL_I2S_I2SRXLTU_RESETVAL;
	regs->I2SRXRTL &= (Uint16)CSL_I2S_I2SRXRTL_RESETVAL;
	regs->I2SRXRTU &= (Uint16)CSL_I2S_I2SRXRTU_RESETVAL;
#else
	regs->I2SRXLT0 &= (Uint16)CSL_I2S_I2SRXLT0_RESETVAL;
	regs->I2SRXLT1 &= (Uint16)CSL_I2S_I2SRXLT1_RESETVAL;
	regs->I2SRXRT0 &= (Uint16)CSL_I2S_I2SRXRT0_RESETVAL;
	regs->I2SRXRT1 &= (Uint16)CSL_I2S_I2SRXRT1_RESETVAL;
#endif

	return(CSL_SOK);
}

/** ===========================================================================
 *   @n@b I2S_transEnable
 *
 *   @b Description
 *   @n  This function Enable or Disable transmission/receive bit
 *
 *   @b Arguments
 *   @verbatim
            i2sHandle         Handle to the I2S
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK             - Reset successful
 *   @li                    CSL_ESYS_BADHANDLE  - Invalid handle
 *
 *   <b> Pre Condition </b>
 *   @n  This fuction calls before read/write function to enable transnission
 *
 *   <b> Post Condition </b>
 *   @n  This fuction calls before read/write function to disable transnission
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
            CSL_I2sHandle   hI2S;
			Uint16			enableBit
            CSL_status   	status;

            status = I2S_transEnable(CSL_I2sHandle	i2sHandle,
            						Uint16 enableBit);
     @endverbatim
 *  ===========================================================================
 */
CSL_Status I2S_transEnable(CSL_I2sHandle	hI2s, Uint16 enableBit)
{
	ioport	CSL_I2sRegs	  *regs;

	if(NULL == hI2s)
	{
		return(CSL_ESYS_BADHANDLE);
	}

	regs = 	hI2s->hwRegs;

	if(enableBit == TRUE)
	{
	    /*  Enable the transmit and receive bit */
		CSL_FINST(regs->I2SSCTRL, I2S_I2SSCTRL_ENABLE, SET);
	}
	else
	{
	    /*  Disable the transmit and receive bit */
		CSL_FINST(regs->I2SSCTRL, I2S_I2SSCTRL_ENABLE, CLEAR);
		hI2s->firstRead = TRUE;
	}
	return(CSL_SOK);
}

