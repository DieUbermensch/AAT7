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


/** @file csl_uhpiAux.h
 *
 * @brief UHPI functional layer inline header file
 *
 * @brief
 *  - The defines inline function definitions
 *
 *  Path: \(CSLPATH)\ inc
 */

/* ============================================================================
 * Revision History
 * ================
 * 30-Nov-2010 Created
 * 06-Jul-2011 CSL v2.50 release
 * 13-Sep-2012 CSL v3.00 release
 * 20-Dec-2012 CSL v3.01 release
 * ============================================================================
 */
#ifndef _CSL_UHPI_AUX_H_
#define _CSL_UHPI_AUX_H_

#include "csl_uhpi.h"

#ifdef __cplusplus
extern "C" {
#endif

/* UHPI Inline functions */

/** ============================================================================
 *   @n@b UHPI_HWOB_Getstatus
 *
 *   @b Description
 *   @n This API is used to get the HWOB bit staus
 *
 *   @b Arguments
 *   @verbatim
            hUhpi        Handle to the UHPI
     @endverbatim
 *
 *   <b> Return Value </b>  Bool
 *   @li                    0/1             -  HWOB bit status.
 *
 *   <b> Pre Condition </b>
 *   @n  UHPI_open should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n none
 *
 *   @b Modifies
 *   @n none
 *
 *   @endverbatim
 *  ============================================================================
 */
static inline
 Uint16 UHPI_HWOB_Getstatus(CSL_UhpiHandle hUhpi)
{

    /* Extract the HWOB bit */
	return((Uint16)(CSL_FEXT(hUhpi->Regs->UHPICL,UHPI_UHPICL_HWOB)));

}


/** ============================================================================
 *   @n@b UHPI_hostTOdspInterrupt_Generate
 *
 *   @b Description
 *   @n This API is used to generate the dsp interrupt
 *
 *   @b Arguments
 *   @verbatim
            hUhpi        Handle to the UHPI
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  UHPI_open should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n none
 *
 *   @b Modifies
 *   @n none
 *
 *   @endverbatim
 *  ============================================================================
 */
static inline
 void UHPI_hostTOdspInterrupt_Generate(CSL_UhpiHandle hUhpi)
{
    /* Generate the DSP interrupt */
	CSL_FINST(hUhpi->Regs->UHPICL, UHPI_UHPICL_DSP_INT, GENERATE);
}

/** ============================================================================
 *   @n@b UHPI_hostTOdspInterrupt_Clear
 *
 *   @b Description
 *   @n This API is used to clear the dsp interrupt
 *
 *   @b Arguments
 *   @verbatim
            hUhpi        Handle to the UHPI
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  UHPI_open should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n none
 *
 *   @b Modifies
 *   @n none
 *
 *   @endverbatim
 *  ============================================================================
 */
static inline
 void UHPI_hostTOdspInterrupt_Clear(CSL_UhpiHandle hUhpi)
{
    /* Clear the DSP interrupt */
	CSL_FINST(hUhpi->Regs->UHPICL, UHPI_UHPICL_DSP_INT, CLEAR);
}


/** ============================================================================
 *   @n@b UHPI_hostTOdspInterrupt_Status
 *
 *   @b Description
 *   @n This API is used to get the dsp interrupt status
 *
 *   @b Arguments
 *   @verbatim
            hUhpi        Handle to the UHPI
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  UHPI_open should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n none
 *
 *   @b Modifies
 *   @n none
 *
 *   @endverbatim
 *  ============================================================================
 */
static inline
 Uint16 UHPI_hostTOdspInterrupt_Status(CSL_UhpiHandle hUhpi)
{
    /* Status of the DSP interrupt */
	return((Uint16)(CSL_FEXT(hUhpi->Regs->UHPICL,UHPI_UHPICL_DSP_INT)));
}

/** ============================================================================
 *   @n@b UHPI_dspTOhostInterrupt_Generate
 *
 *   @b Description
 *   @n This API is used to generate the host interrupt
 *
 *   @b Arguments
 *   @verbatim
            hUhpi        Handle to the UHPI
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  UHPI_open should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n none
 *
 *   @b Modifies
 *   @n none
 *
 *   @endverbatim
 *  ============================================================================
 */
static inline
 void UHPI_dspTOhostInterrupt_Generate(CSL_UhpiHandle hUhpi)
{
    /* Generate the Host interrupt */
	CSL_FINST(hUhpi->Regs->UHPICL, UHPI_UHPICL_HINT, GENERATE);
}

/** ============================================================================
 *   @n@b UHPI_dspTOhostInterrupt_Clear
 *
 *   @b Description
 *   @n This API is used to clear the host interrupt
 *
 *   @b Arguments
 *   @verbatim
            hUhpi        Handle to the UHPI
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  UHPI_open should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n none
 *
 *   @b Modifies
 *   @n none
 *
 *   @endverbatim
 *  ============================================================================
 */
static inline
 void UHPI_dspTOhostInterrupt_Clear(CSL_UhpiHandle hUhpi)
{
    /* Clear the Host interrupt */
	CSL_FINST(hUhpi->Regs->UHPICL, UHPI_UHPICL_HINT, CLEAR);
}


/** ============================================================================
 *   @n@b UHPI_dspTOhostInterrupt_Status
 *
 *   @b Description
 *   @n This API is used to get the host interrupt status
 *
 *   @b Arguments
 *   @verbatim
            hUhpi        Handle to the UHPI
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  UHPI_open should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n none
 *
 *   @b Modifies
 *   @n none
 *
 *   @endverbatim
 *  ============================================================================
 */
static inline
 Uint16 UHPI_dspTOhostInterrupt_Status(CSL_UhpiHandle hUhpi)
{
    /*Get the host interrupt status*/
	return((Uint16)(CSL_FEXT(hUhpi->Regs->UHPICL,UHPI_UHPICL_HINT)));
}


/** ============================================================================
 *   @n@b UHPI_HRDY_Status
 *
 *   @b Description
 *   @n This API is used to get the HPI ready status
 *
 *   @b Arguments
 *   @verbatim
            hUhpi        Handle to the UHPI
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  UHPI_open should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n none
 *
 *   @b Modifies
 *   @n none
 *
 *   @endverbatim
 *  ============================================================================
 */
static inline
 Uint16 UHPI_HRDY_Status(CSL_UhpiHandle hUhpi)
{
    /* Get the HRDY status */
	return((Uint16)(CSL_FEXT(hUhpi->Regs->UHPICL,UHPI_UHPICL_HRDY)));
}

/** ============================================================================
 *   @n@b UHPI_FETCH_Status
 *
 *   @b Description
 *   @n This API is used to get the HPI fetch status. Always will read 0
 *
 *   @b Arguments
 *   @verbatim
            hUhpi        Handle to the UHPI
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  UHPI_open should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n none
 *
 *   @b Modifies
 *   @n none
 *
 *   @endverbatim
 *  ============================================================================
 */
static inline
 Uint16 UHPI_FETCH_Status(CSL_UhpiHandle hUhpi)
{
    /* Get the Fetch bit status */
	return((Uint16)(CSL_FEXT(hUhpi->Regs->UHPICL,UHPI_UHPICL_FETCH)));
}

/** ============================================================================
 *   @n@b UHPI_XHPIA_Status
 *
 *   @b Description
 *   @n This API is used to get the extended HPI address status.
 *
 *   @b Arguments
 *   @verbatim
            hUhpi        Handle to the UHPI
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  UHPI_open should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n none
 *
 *   @b Modifies
 *   @n none
 *
 *   @endverbatim
 *  ============================================================================
 */
static inline
 Uint16 UHPI_XHPIA_Status(CSL_UhpiHandle hUhpi)
{
    /* Get the XHPIA bit status */
	return((Uint16)(CSL_FEXT(hUhpi->Regs->UHPICL,UHPI_UHPICL_XHPIA)));
}

/** ============================================================================
 *   @n@b UHPI_RESET_Status
 *
 *   @b Description
 *   @n This API is used to get the RESET bit status.
 *
 *   @b Arguments
 *   @verbatim
            hUhpi        Handle to the UHPI
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  UHPI_open should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n none
 *
 *   @b Modifies
 *   @n none
 *
 *   @endverbatim
 *  ============================================================================
 */
static inline
 Uint16 UHPI_RESET_Status(CSL_UhpiHandle hUhpi)
{
    /* Get the RESET bit status */
	return((Uint16)(CSL_FEXT(hUhpi->Regs->UHPICL,UHPI_UHPICL_RESET)));
}

/** ============================================================================
 *   @n@b UHPI_HPIRST_Generate
 *
 *   @b Description
 *   @n This API is used to generate the HPI reset.
 *
 *   @b Arguments
 *   @verbatim
            hUhpi        Handle to the UHPI
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  UHPI_open should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n none
 *
 *   @b Modifies
 *   @n none
 *
 *   @endverbatim
 *  ============================================================================
 */
static inline
 void UHPI_HPIRST_Generate(CSL_UhpiHandle hUhpi)
{
	/* Generate the HPI reset */
	CSL_FINST(hUhpi->Regs->UHPICL, UHPI_UHPICL_HPI_RST, GENERATE);
}

/** ============================================================================
 *   @n@b UHPI_HPIRST_Clear
 *
 *   @b Description
 *   @n This API is used to clear the HPI reset.
 *
 *   @b Arguments
 *   @verbatim
            hUhpi        Handle to the UHPI
     @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  UHPI_open should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n none
 *
 *   @b Modifies
 *   @n none
 *
 *   @endverbatim
 *  ============================================================================
 */
static inline
 void UHPI_HPIRST_Clear(CSL_UhpiHandle hUhpi)
{
	/* Generate the HPI reset */
	CSL_FINST(hUhpi->Regs->UHPICL, UHPI_UHPICL_HPI_RST, CLEAR);
}

#ifdef __cplusplus
 }
#endif

#endif /* _CSL_UHPI_AUX_H_ */
