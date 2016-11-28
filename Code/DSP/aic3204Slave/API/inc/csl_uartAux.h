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


/** @file csl_uartAux.h
 *
 * @brief UART functional layer inline header file
 *
 * @brief
 *  - The defines inline function definitions
 *
 *  Path: \(CSLPATH)\ inc
 */

/* ============================================================================
 * Revision History
 * ================
 * 17-Sep-2008 Created
 * 13-Aug-2010 CSL v2.10 release
 * 06-Jul-2011 CSL v2.50 release
 * 13-Sep-2012 CSL v3.00 release
 * 20-Dec-2012 CSL v3.01 release
 * ============================================================================
 */

 #ifndef _CSL_UARTAUX_H_
#define _CSL_UARTAUX_H_

#include <csl_uart.h>
#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup CSL_UART_FUNCTION
@{*/

/** ============================================================================
 *   @n@b UART_getDataReadyStatus
 *
 *   @b Description
 *   @n This API is used to get the status of DR bit in LSR reg
 *
 *   @b Arguments
 *   @verbatim
            hUart        Handle to the uart
     @endverbatim
 *
 *   <b> Return Value </b>  Bool
 *   @li                    TRUE             -  DR bit is set
 *
 *   @li                    FALSE            -  DR bit is not set.
 *
 *   <b> Pre Condition </b>
 *   @n  UART_init should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n none
 *
 *   @b Modifies
 *   @n none
 *
 *   @b Example
 *   @verbatim

         CSL_Status              	status;
         Bool                    	bStatus;
         CSL_UartObj         		    uartObj;
         CSL_UartHandle            	hUart;
         Uint32                  	uartInstId;
         uartInstId = 0;
         status = UART_init(&uartObj,uartInstId);
         hUart = &uartObj;
         bStatus = UART_getDataReadyStatus(hUart);

     @endverbatim
 *  ============================================================================
 */
static inline
 Bool UART_getDataReadyStatus(CSL_UartHandle hUart)
{
    Uint16 DatRdy = 0;

    DatRdy = CSL_FEXT(hUart->uartRegs->LSR,UART_LSR_DR);
    if( DatRdy )
        return TRUE;
    return FALSE;
}


/** ============================================================================
 *   @n@b UART_getXmitHoldRegEmptyStatus
 *
 *   @b Description
 *   @n This API is used to get the status of THRE bit in LSR reg
 *
 *   @b Arguments
 *   @verbatim
            hUart        Handle to the uart
     @endverbatim
 *
 *   <b> Return Value </b>  Bool
 *   @li                    TRUE             -  THRE  bit is set
 *
 *   @li                    FALSE            -  THRE  bit is not set.
 *
 *   <b> Pre Condition </b>
 *   @n  UART_init should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n none
 *
 *   @b Modifies
 *   @n none
 *
 *   @b Example
 *   @verbatim

         CSL_Status              	status;
         Bool                    	bStatus;
         CSL_UartObj         		uartObj;
         CSL_UartHandle            	hUart;
         Uint32                  	uartInstId;
         uartInstId = 0;
         status = UART_init(&uartObj,uartInstId);
         hUart = &uartObj;
         bStatus = UART_getXmitHoldRegEmptyStatus(hUart);

     @endverbatim
 *  ============================================================================
 */
static inline
Bool UART_getXmitHoldRegEmptyStatus(CSL_UartHandle hUart)
{
    Uint16 XmitRdy = 0;

    XmitRdy = CSL_FEXT(hUart->uartRegs->LSR,UART_LSR_THRE);

    if( XmitRdy )
        return TRUE;
    return FALSE;
}

/** ============================================================================
 *   @n@b UART_getRecvorResetStatus
 *
 *   @b Description
 *   @n This API is used to get the Receiver reset status
 *
 *   @b Arguments
 *   @verbatim
            hUart        Handle to the uart
     @endverbatim
 *
 *   <b> Return Value </b>  Bool
 *   @li                    TRUE             -  Receiver in reset state.
 *
 *   @li                    FALSE            -  Receiver is enabled.
 *
 *   <b> Pre Condition </b>
 *   @n  UART_init should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n none
 *
 *   @b Modifies
 *   @n none
 *
 *   @b Example
 *   @verbatim

         CSL_Status              	status;
         Bool                    	bStatus;
         CSL_UartObj         		    uartObj;
         CSL_UartHandle            	hUart;
         Uint32                  	uartInstId;
         uartInstId = 0;
         status = UART_init(&uartObj,uartInstId);
         hUart = &uartObj;
         bStatus = UART_getRecvorResetStatus(hUart);

     @endverbatim
 *  ============================================================================
 */
static inline
CSL_Status UART_getRecvorResetStatus(CSL_UartHandle hUart)
{
    Uint16 UrRst = 0;

	UrRst = CSL_FEXT(hUart->uartRegs->PWREMU_MGMT,UART_PWREMU_MGMT_URRST);
    if( UrRst )
        return FALSE;
    return TRUE;

}
/** ============================================================================
 *   @n@b UART_getXmitorResetState
 *
 *   @b Description
 *   @n This API is used to get the Receiver reset status
 *
 *   @b Arguments
 *   @verbatim
            hUart        Handle to the uart
     @endverbatim
 *
 *   <b> Return Value </b>  Bool
 *   @li                    TRUE             -  Transmittor in reset state.
 *
 *   @li                    FALSE            -  Transmittor is enabled.
 *
 *   <b> Pre Condition </b>
 *   @n  UART_init should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n none
 *
 *   @b Modifies
 *   @n none
 *
 *   @b Example
 *   @verbatim

         CSL_Status              	status;
         Bool                    	bStatus;
         CSL_UartObj         		    uartObj;
         CSL_UartHandle            	hUart;
         Uint32                  	uartInstId;
         uartInstId = 0;
         status = UART_init(&uartObj,uartInstId);
         hUart = &uartObj;
         bStatus = UART_getXmitorResetState(hUart);

     @endverbatim
 *  ============================================================================
 */
static inline
CSL_Status UART_getXmitorResetState(CSL_UartHandle hUart)
{
    Uint16 UtRst = 0;

	UtRst = CSL_FEXT(hUart->uartRegs->PWREMU_MGMT,UART_PWREMU_MGMT_UTRST);
    if( UtRst )
        return FALSE;
    return TRUE;

}
/** ============================================================================
 *   @n@b UART_getModeOfTransfer
 *
 *   @b Description
 *   @n This API is used to get Xfer mode of UART in ,Fifo mode or non fifo mode.
 *
 *   @b Arguments
 *   @verbatim
            hUart        Handle to the uart
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_UartXferMode
 *   @li                    CSL_UART_FIFO_MODE             -  UART in fifo mode.
 *
 *   @li                    CSL_UART_NON_FIFO_MODE         -  UART in non fifo mode.
 *
 *   @li                    CSL_UART_MODE_UNDEFINED          -  UART Xfer mode is undefined.
 *
 *   <b> Pre Condition </b>
 *   @n  UART_init and UART_setup should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n none
 *
 *   @b Modifies
 *   @n none
 *
 *   @b Example
 *   @verbatim

         CSL_Status              	status;
         CSL_UartXferMode       uartXferMode;
         CSL_UartObj         		    uartObj;
         CSL_UartHandle            	hUart;
         Uint32                  	uartInstId;
         CSL_UartSetup                 uartSetup;
         uartSetup.....

         uartInstId = 0;
         status = UART_init(&uartObj,uartInstId);
         hUart = &uartObj;
         status = UART_setup(hUart,&uartSetup);
         uartXferMode = UART_getModeOfTransfer(hUart);

     @endverbatim
 *  ============================================================================
 */

static inline
CSL_UartXferMode UART_getModeOfTransfer(CSL_UartHandle hUart)
{
    Uint16 UtRst = 0;

	UtRst = CSL_FEXT(hUart->uartRegs->FCR,UART_IIR_FIFOEN);

    if( 0 == UtRst )
    {
        return CSL_UART_NON_FIFO_MODE;
    }
    if (3 == UtRst)
    {
        return CSL_UART_FIFO_MODE;
    }
    return CSL_UART_MODE_UNDEFINED;

}
/** ============================================================================
 *   @n@b UART_setToIntMode
 *
 *   @b Description
 *   @n This API is used to set the interrupt mode.
 *
 *   @b Arguments
 *   @verbatim
            hUart        Handle to the uart
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_ESYS_BADHANDLE           -  Invalid handle.
 *
 *   @li                    CSL_SOK                      -  Changed to interruptmode.
 *
 *   <b> Pre Condition </b>
 *   @n  UART_init should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n none
 *
 *   @b Modifies
 *   @n none
 *
 *   @b Example
 *   @verbatim

         CSL_Status              	status;
         CSL_UartObj         		    uartObj;
         CSL_UartHandle            	hUart;
         Uint32                  	uartInstId;
         uartInstId = 0;
         status = UART_init(&uartObj,uartInstId);
         hUart = &uartObj;
         status = UART_setToIntMode(hUart);


     @endverbatim
 *  ============================================================================
 */
static inline
CSL_Status UART_setToIntMode(CSL_UartHandle hUart)
{
    CSL_Status status = CSL_SOK;
    if( NULL == hUart )
	{
	 	return CSL_ESYS_BADHANDLE;
	}
    hUart->opmode = UART_INTERRUPT;
    return status;
}
/** ============================================================================
 *   @n@b UART_setToPollMode
 *
 *   @b Description
 *   @n This API is used to switch to the poll mode.
 *
 *   @b Arguments
 *   @verbatim
            hUart        Handle to the uart
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_ESYS_BADHANDLE                    -  Invalid handle.
 *
 *   @li                    CSL_SOK              -  Successfully changed to poll mode.
 *
 *   <b> Pre Condition </b>
 *   @n  UART_init should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n none
 *
 *   @b Modifies
 *   @n none
 *
 *   @b Example
 *   @verbatim

         CSL_Status              	status;
         CSL_UartObj         		    uartObj;
         CSL_UartHandle            	hUart;
         Uint32                  	uartInstId;
         uartInstId = 0;
         status = UART_init(&uartObj,uartInstId);
         hUart = &uartObj;
         status = UART_setToPollMode(hUart);
     @endverbatim
 *  ============================================================================
 */static inline
CSL_Status UART_setToPollMode(CSL_UartHandle hUart)
{
    CSL_Status status = CSL_SOK;
    hUart->opmode = UART_POLLED;
    return status;
}

/** ============================================================================
 *   @n@b UART_enableFreeRun
 *
 *   @b Description
 *   @n This API is used to start free running mode.
 *
 *   @b Arguments
 *   @verbatim
            hUart        Handle to the uart
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_ESYS_BADHANDLE   -  Invalid handle.
 *
 *   @li                    CSL_SOK              - Free running mode is enabled.
 *
 *   <b> Pre Condition </b>
 *   @n  UART_init should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n none
 *
 *   @b Modifies
 *   @n none
 *
 *   @b Example
 *   @verbatim

         CSL_Status              	status;
         CSL_UartObj         		    uartObj;
         CSL_UartHandle            	hUart;
         Uint32                  	uartInstId;
         CSL_UartConfig                config;
         uartInstId = 0;
         config.FCR = CSL_UART_FIFO_DMA1_DISABLE_TRIG01;
         config.DLL = 0x001b;
         config.DLH = 0x0006;
         config.LCR = 0x0003
         config.MCR = 0x0000;
         status = UART_init(&uartObj,uartInstId);
         hUart = &uartObj;
         status = UART_config(hUart,&config);
         status = UART_resetOff(hUart);
         status = UUART_enableFreeRun(hUart);
     @endverbatim
 *  ============================================================================
 */
static inline
CSL_Status UART_enableFreeRun(CSL_UartHandle hUart)
{
    CSL_Status status = CSL_SOK;
    CSL_FINST(hUart->uartRegs->PWREMU_MGMT, UART_PWREMU_MGMT_FREE,RUN);
    return status;
}

/** ============================================================================
 *   @n@b UART_disableFreeRun
 *
 *   @b Description
 *   @n This API is used to stop free running mode.
 *
 *   @b Arguments
 *   @verbatim
            hUart        Handle to the uart
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_ESYS_BADHANDLE   -  Invalid handle.
 *
 *   @li                    CSL_SOK              - Stop Free running mode.
 *
 *   <b> Pre Condition </b>
 *   @n  UART_init should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n none
 *
 *   @b Modifies
 *   @n none
 *
 *   @b Example
 *   @verbatim

         CSL_Status              	status;
         CSL_UartObj         		    uartObj;
         CSL_UartHandle            	hUart;
         Uint32                  	uartInstId;
         CSL_UartSetup                 uartSetup;
         uartInstId = 0;

         uartSetup.afeEnable = CSL_UART_NO_AFE;
         uartSetup.baud = 2400;
         uartSetup.clkInput = 60000000;
         uartSetup.fifoControl = CSL_UART_FIFO_DISABLE;
         uartSetup.loopBackEnable = CSL_UART_NO_LOOPBACK;
         uartSetup.parity =  CSL_UART_DISABLE_PARITY;
         uartSetup.rtsEnable = CSL_UART_NO_RTS;
         uartSetup.stopBits = 0;
         uartSetup.wordLength = CSL_UART_WORD8;

         status = UART_init(&uartObj,uartInstId);
         hUart = &uartObj;
         status = UART_setup(hUart,&setup);
         status = UUART_disableFreeRun(hUart);
     @endverbatim
 *  ============================================================================
 */
static inline
CSL_Status UART_disableFreeRun(CSL_UartHandle hUart)
{
    CSL_Status status = CSL_SOK;
    CSL_FINST(hUart->uartRegs->PWREMU_MGMT,UART_PWREMU_MGMT_FREE,STOP);
    return status;
}

/**
@} */
#ifdef __cplusplus
 }
#endif
#endif// _CSL_UARTAUX_H_
