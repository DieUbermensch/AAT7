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


/** @file csl_uhpi.h
 *
 *  @brief UHPI functional layer API header file
 *
 *  Path: \(CSLPATH)\ inc
 */

/* ============================================================================
 * Revision History
 * ================
 * 01-Dec-2010 Created
 * 06-Jul-2011 CSL v2.50 release
 * 13-Sep-2012 CSL v3.00 release
 * 20-Dec-2012 CSL v3.01 release
 * ============================================================================
 */

/** @defgroup CSL_UHPI_API UHPI
 *
 * @section Introduction
 *
 * @subsection xxx Overview
 * The Universal Host Port Interface provides a parallel port interface through which an external
 * host processor cna directly access the processor's recources (configuration and program/data
 * memories. The UHPI enables a host device and the processor to exchange information via internal
 * memory of the DSP
 *
 */

#ifndef _CSL_UHPI_H_
#define _CSL_UHPI_H_
/**
@defgroup CSL_UHPI_SYMBOL  UHPI Symbols Defined
@ingroup CSL_UHPI_API
*/
/**
@defgroup CSL_UHPI_DATASTRUCT  UHPI Data Structures
@ingroup CSL_UHPI_API
*/
/**
@defgroup CSL_UHPI_FUNCTION  UHPI Functions
@ingroup CSL_UHPI_API
*/

/**
@defgroup CSL_UHPI_ENUM UHPI Enumerated Data Types
@ingroup CSL_UHPI_API
*/
#include "cslr.h"
#include "csl_error.h"
#include "csl_types.h"
#include "cslr_uhpi.h"
#include "soc.h"
#include "csl_intc.h"
#include "csl_general.h"
#include "cslr_uhpi.h"

/* Portion to be moved while integrating this to CSL 2.10 */
//typedef volatile ioport CSL_UhpiRegs 	         * CSL_UhpiRegsOvly;
//#define CSL_UHPI_REGS 		            ((CSL_UhpiRegsOvly) 0x2E00)

//typedef volatile CSL_UhpiRegs 	         * CSL_UhpiRegsOvly;
//#define CSL_UHPI_REGS 		            ((CSL_UhpiRegsOvly) 0x8900)
/***********************************************************/


/**
@addtogroup CSL_UHPI_ENUM
@{*/
/**
 * \brief enum for UHPI instance numbers
 *
 */
typedef enum CSL_UhpiInsId
{
	/** UHPI hardware instance 0                                             */
    CSL_UHPI_INST_0 = (0u),
	/** Invalid UHPI hardware instance                                       */
    CSL_UHPI_INST_INVALID = (1u)
} CSL_UhpiInsId;

/**
 *  \brief Enum for UHPI Operating mode bit(Only CSL_UHPI_16BIT_MUXED_SINGLE_FULLWORD_CYCLES is possible)
 */
typedef enum CSL_UhpiOpmode {
	/** UHPI 8 Bit Multiplexed mode / dual half-word cycles (8 bit host data bus/16 bit memory width)	*/
	CSL_UHPI_8BIT_MUXED_DUAL_HALFWORD_CYCLES = 0,
	/** 16 Bit Multiplexed mode / single full-word cycles (16 bit host data bus/16 bit memory width)	*/
	CSL_UHPI_16BIT_MUXED_SINGLE_FULLWORD_CYCLES,
	/** 16 Bit Multiplexed mode / dual half-word cycles (16 bit host data bus/32 bit memory width)		*/
	CSL_UHPI_16BIT_MUXED_DUAL_HALFWORD_CYCLES,
	/** 16 Bit Non-multiplexed mode (16 bit data bus/16 bit memory width)								*/
	CSL_UHPI_16BIT_NONMUXED,
	/** 32 Bit Non-multiplexed mode (32 bit data bus/32 bit memory width)								*/
	CSL_UHPI_32BIT_NONMUXED,
	/** 32 Bit Multiplexed mode (32 bit data bus/32 bit memory width)									*/
	CSL_UHPI_32BIT_MUXED,
	/** Invalid mode									*/
	CSL_UHPI_INVALID_OPMODE
} CSL_UhpiOpmode;
/**
@} */


/**
\addtogroup CSL_UHPI_DATASTRUCT
@{ */

/** \brief  UHPI Setup
*/
typedef struct CSL_UhpiSetup
{
	/**  UHPI Operating mode			        		                     */
	CSL_UhpiOpmode        op_mode;
	/**  UHPI GPIO interrupt mode			        		                 */
	Bool	      		  gpio_intr;
} CSL_UhpiSetup;
/** \brief  UHPI Object
*/
typedef struct CSL_UhpiObj
{
    /** Instance id of UHPI     */
    Uint16 insId;
    /** UHPI register overlay structure pointer     */
	CSL_UhpiRegsOvly Regs;
    /** System control register overlay structure pointer                    */
    CSL_SysRegsOvly sysRegs;
} CSL_UhpiObj;

/** Handle to the UHPI object structure                                       */
typedef CSL_UhpiObj  *CSL_UhpiHandle;

/**
@} */


/** @addtogroup CSL_UHPI_SYMBOL
 @{ */

/* Macros for the UHPI */
#define CSL_UHPI_FREEMODE_ENABLE  	(0x01u)
#define CSL_UHPI_FREEMODE_DISABLE  	(0x00u)


/* GPIO enable/disable -- delete */
#define CSL_UHPI_GPIO_ENABLE  		(0x01u)
#define CSL_UHPI_GPIO_DISABLE  		(0x00u)

/* GPIO interrupt enable/disable */
#define CSL_UHPI_GPIO_INTERRUPT_ENABLE	(0x01u)
#define CSL_UHPI_GPIO_INTERRUPT_DISABLE	(0x00u)

/**
@} */


/** @addtogroup CSL_UHPI_FUNCTION
 @{ */
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
		  			CSL_Status 		*status);


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
CSL_Status UHPI_Config(CSL_UhpiHandle hUhpi, CSL_UhpiSetup *UhpiSetup);


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
CSL_Status UHPI_Close( CSL_UhpiHandle hUhpi );
/**
@} */

#endif /* _CSL_UHPI_H_ */


