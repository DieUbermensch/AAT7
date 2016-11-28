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


/** @file csl_mcbsp.h
 *
 *  @brief McBSP functional layer API header file
 *
 *  Path: \(CSLPATH)\ inc
 */

/* ============================================================================
 * Revision History
 * ================
 * 16-Sep-2010 Created
 * 06-Jul-2011 CSL v2.50 release
 * 13-Sep-2012 CSL v3.00 release
 * 20-Dec-2012 CSL v3.01 release

 * ============================================================================
 */
#ifndef _CSL_MCBSP_H_
#define _CSL_MCBSP_H_

#include "cslr.h"
#include "csl_error.h"
#include "csl_types.h"
#include "cslr_mcbsp.h"
#include "soc.h"
#include "csl_intc.h"
#include "csl_general.h"



/* Constants for MCBSP_start */
#define MCBSP_RCV_START       (1u)
#define MCBSP_XMIT_START      (2u)
#define MCBSP_SRGR_START      (4u)
#define MCBSP_SRGR_FRAMESYNC  (8u)
#define MCBSP_SRGR_DEFAULT_DELAY  (0xFFFFu)


#define MCBSP_CHAN0     0x0001
#define MCBSP_CHAN1     0x0002
#define MCBSP_CHAN2     0x0004
#define MCBSP_CHAN3     0x0008
#define MCBSP_CHAN4     0x0010
#define MCBSP_CHAN5     0x0020
#define MCBSP_CHAN6     0x0040
#define MCBSP_CHAN7     0x0080
#define MCBSP_CHAN8     0x0100
#define MCBSP_CHAN9     0x0200
#define MCBSP_CHAN10    0x0400
#define MCBSP_CHAN11    0x0800
#define MCBSP_CHAN12    0x1000
#define MCBSP_CHAN13    0x2000
#define MCBSP_CHAN14    0x4000
#define MCBSP_CHAN15    0x8000


/**
@addtogroup CSL_UART_ENUM
@{*/
/**
 * \brief UART instance numbers
 *
 */
typedef enum
{
	/** MCBSP hardware instance 0                                             */
    CSL_MCBSP_INST_0 = (0u),
	/** Invalid MCBSP hardware instance                                       */
    CSL_MCBSP_INST_INVALID = (1u)
} CSL_McbspInsId;

typedef enum
{
	/** MCBSP oprtaing mode                                             */
    CSL_MCBSP_OPMODE_NORMAL = (0u),
    CSL_MCBSP_OPMODE_32CHANNEL,
	CSL_MCBSP_OPMODE_128CHANNEL,
	CSL_MCBSP_OPMODE_512CHANNEL
} CSL_McbspOpMode;


typedef struct
{
   /** Input clock in Hz*/
    Uint32              clkInput;
	/*  McBSP operating mode */
	CSL_McbspOpMode mcbsp_opmode;
    /**Word length selection
      Valid values - 8,12,16,20,24,32bits*/
    Uint16              wordLength;
    /**Frame length selection
      Valid values - (1-128)*/
    Uint16              frameLength;
   /** single phase frame/double phase frame*/
    Uint16              phase;
   /** data delay*/
    Uint16              datadelay;
   /** frame ignore flag */
    Uint16              frameignore;
    /**Loopback mode enable/disable*/
    Uint16              loopBackmode;
	/**Companding*/
	Uint16              companding;
	/**free mode*/
	//Uint16              freemode;
	/**Rjust mode*/
	Uint16              rjust_mode;
	/**Abis mode*/
	Uint16              abismode;
	/**DXENA enable/disable*/
	Uint16              dxena;
	/**CLKSTP */
	Uint16              clkstp;
	/**CLKXP,CLKRP */
	Uint16              sample_polarity;
	/**FRAMESYNC */
	Uint16              fs_polarity;
	/**clock source */
	Uint16 				clocksource;
	/**interrupt event */
	Uint16 				intr_event;
	/**McBSP opration mode */
	Uint16 				sample_rate;
	/**McBSP FSXPIn behavior */
	Uint16 				fsxpin_status;
} CSL_McbspSetup;



typedef struct CSL_McbspObj
{
    /** Instance id of McBSP     */
    Uint16 insId;
    /** McBSP register overlay structure pointer     */
	CSL_McbspRegsOvly Regs;
    /** System control register overlay structure pointer                    */
    CSL_SysRegsOvly sysRegs;
    /**Trigger level of fifo*/
    Uint16 trigLevel;
    /** ISR  dispatch table for storing call back function pointers*/
    Uint32 MCBSP_isrDispatchTable[7];
}CSL_McbspObj;

/** Handle to the McBSP object structure                                       */
typedef CSL_McbspObj  *CSL_McbspHandle;


/* Macros for the */
#define CSL_MCBSP_SINGLEPHASE  	(0x01u)
#define CSL_MCBSP_DUALPHASE  	(0x02u)

#define CSL_MCBSP_WORD8   	(0x08u)
#define CSL_MCBSP_WORD12  	(0x0Cu)
#define CSL_MCBSP_WORD16  	(0x10u)
#define CSL_MCBSP_WORD20  	(0x14u)
#define CSL_MCBSP_WORD24  	(0x18u)
#define CSL_MCBSP_WORD32  	(0x20u)

#define CSL_MCBSP_FRMAEIGNORETRUE  		(0x01u)
#define CSL_MCBSP_FRMAEIGNOREFALSE  	(0x00u)

#define CSL_MCBSP_INTERNALLOOPBACK_ENABLE  		(0x01u)
#define CSL_MCBSP_INTERNALLOOPBACK_DISABLE  	(0x00u)

#define CSL_MCBSP_DATADELAY0BIT  		(0x00u)
#define CSL_MCBSP_DATADELAY1BIT  		(0x01u)
#define CSL_MCBSP_DATADELAY2BIT  		(0x02u)
#define CSL_MCBSP_DATADELAYINVALID  	(0x03u)

#define CSL_MCBSP_FRMAELENGHT(x) 		(x-1)

#define CSL_MCBSP_COFF_MSBFIRST  		(0x00u)
#define CSL_MCBSP_COFF_LSBFIRST  		(0x01u)
#define CSL_MCBSP_CON_ULAW  		    (0x02u)
#define CSL_MCBSP_CON_ALAW  	        (0x03u)

#define CSL_MCBSP_RJUST_RJZFMSB  		(0x00u)
#define CSL_MCBSP_RJUST_RJSEMSB  		(0x01u)
// Below line Modified by Chandra from RJZFLSB to LJZFLSB, Needs review
#define CSL_MCBSP_RJUST_LJZFLSB  		(0x02u)
#define CSL_MCBSP_RJUST_RESERVED    	(0x03u)


#define CSL_MCBSP_ABIS_ENABLE  		  	(0x01u)
#define CSL_MCBSP_ABIS_DISABLE       	(0x00u)

#define CSL_MCBSP_DXENA_ENABLE  	   	(0x01u)
#define CSL_MCBSP_DXENA_DISABLE        	(0x00u)

#define CSL_MCBSP_CLKSTP_WITHDELAY  	(0x01u)
#define CSL_MCBSP_CLKSTP_WITHOUTDELAY   (0x00u)

#define CSL_MCBSP_DATASAMPLE_FALLING	(0x00u)
#define CSL_MCBSP_DATASAMPLE_RISING		(0x01u)

#define CSL_MCBSP_FS_ACTIVEHIGH		   	(0x00u)
#define CSL_MCBSP_FS_ACTIVELOW		   	(0x01u)

#define CSL_MCBSP_CLOCKSOURCE_CLKR	    (0x00u)
#define CSL_MCBSP_CLOCKSOURCE_CLKX	    (0x01u)
#define CSL_MCBSP_CLOCKSOURCE_CLKS	    (0x02u)
#define CSL_MCBSP_CLOCKSOURCE_SYSCLK    (0x03u)

#define CSL_MCBSP_INTR_RDY		   		(0x00u)
#define CSL_MCBSP_INTR_EOF		   		(0x01u)
#define CSL_MCBSP_INTR_NEWFS	   		(0x02u)
#define CSL_MCBSP_INTR_SYNCERR 	   		(0x03u)

#define CSL_MCBSP_FSX_FSXPINIP  		(0x00u)
#define CSL_MCBSP_FSX_SRGOP		   		(0x01u)
#define CSL_MCBSP_FSX_DXRTOXSRCPYOP		(0x02u)


#define CSL_MCBSP_OPMODE_NORMAL  		(0x00u)
#define CSL_MCBSP_OPMODE_32CHANNEL  	(0x01u)
#define CSL_MCBSP_OPMODE_128CHANNEL  	(0x02u)
#define CSL_MCBSP_OPMODE_512CHANNEL  	(0x03u)

//#define CSL_MCBSP_CLKRP_RISING			(0x01u)
//#define CSL_MCBSP_CLKRP_FALLING		    (0x00u)
//#define CSL_MCBSP_FSXP_ACTIVEHIGH		    (0x00u)
//#define CSL_MCBSP_FSXP_ACTIVELOW		    (0x01u)
//#define CSL_MCBSP_FREE_ENABLE  		    (0x01u)
//#define CSL_MCBSP_FREE_DISABLE          (0x00u)
//#define CSL_MCBSP_SOFT_ENABLE  		    (0x01u)
//#define CSL_MCBSP_SOFT_DISABLE          (0x00u)

/****************************************\
* MCBSP global function declarations
\****************************************/
void MCBSP_reset(CSL_McbspHandle hMcbsp);
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
						   CSL_Status 	*status);
/** ============================================================================
 *   @n@b MCBSP_close
 *
 *   @b Description
 *   @n Close the handle to MCBSP and stops the clock to MCBSP
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
CSL_Status MCBSP_close(CSL_McbspHandle hMcbsp);

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
CSL_Status Mcbsp_Configure(CSL_McbspHandle hMcbsp,CSL_McbspSetup *mcbspSetup);

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
CSL_Status MCBSP_start( CSL_McbspHandle hMcbsp, Uint16 StartMask, Uint32 SampleRateDelay );

Uint32 MCBSP_read32(CSL_McbspHandle hMcbsp);
void MCBSP_write32(CSL_McbspHandle hMcbsp,Uint32 Val);
Uint16 MCBSP_read16(CSL_McbspHandle hMcbsp);
Uint16 MCBSP_read(CSL_McbspHandle hMcbsp);
void MCBSP_write16(CSL_McbspHandle hMcbsp,Uint16 Val);
void MCBSP_write(CSL_McbspHandle hMcbsp,Uint16 Val);




/* Inline Function definitions */
static inline
Uint16 MCBSP_xempty(CSL_McbspHandle hMcbsp)
{

    /* Extract the XEMPTY bit */
	return((Uint16)(CSL_FEXT(hMcbsp->Regs->SPCRU,MCBSP_SPCRU_XEMPTY)));

}

static inline
Uint16 MCBSP_xrdy(CSL_McbspHandle hMcbsp)
{
    /* Extract the XRDY bit */
	return((Uint16)(CSL_FEXT(hMcbsp->Regs->SPCRU,MCBSP_SPCRU_XRDY)));
}


static inline
Uint16 MCBSP_rrdy(CSL_McbspHandle hMcbsp)
{

    /* Extract the RRDY bit */
	return((Uint16)(CSL_FEXT(hMcbsp->Regs->SPCRL,MCBSP_SPCRL_RRDY)));

}


static inline
Uint16 MCBSP_rfull(CSL_McbspHandle hMcbsp)
{
    /* Extract the RFULL bit */
	return((Uint16)(CSL_FEXT(hMcbsp->Regs->SPCRL,MCBSP_SPCRL_RFULL)));
}

#endif /* _CSL_MCBSP_H_ */

