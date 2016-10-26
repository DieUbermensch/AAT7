/*
 *  Copyright 2002 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *
 */
/* "@(#) ReferenceFrameworks 1.10.00 04-30-02 (swat-b21)" */
/*
 *  ======== c55xx_dma_mcbsp.h ========
 */

#ifndef C55XX_DMA_MCBSP_
#define C55XX_DMA_MCBSP_

#include <lio.h>

#include <csl.h>
#include <csl_dma.h>
#include <csl_mcbsp.h>

extern DMA_Handle   C55XX_DMA_MCBSP_hDmaRx;
extern DMA_Handle   C55XX_DMA_MCBSP_hDmaTx;
extern MCBSP_Handle C55XX_DMA_MCBSP_hMcbsp;

/* Driver function table to be used by applications. */
extern LIO_Fxns C55XX_DMA_MCBSP_ILIO;

/* Controller init function -- must be called before controller() open */
extern Void C55XX_DMA_MCBSP_init(Void);

/*
 *  Hardware interrupt handler functions plugable into DSP/BIOS config
 *  tool. This is a straight C function, and must be called by
 *  the DSP/BIOS hardware interrupt dispatcher.  Both the DMA receive
 *  and transmit interrupts must be serviced. On the 5509 EVM these
 *  should be plugged in the DSP/BIOS configuration tool to the INT14 and
 *  INT15 interrupts.
 *
 *  Workaround for bug SDSsq23674 : 55x HWI dispatcher passes invalid argument
 */
extern Void C55XX_DMA_MCBSP_rxIsr(Void);
extern Void C55XX_DMA_MCBSP_txIsr(Void);
extern Void C55XX_DMA_MCBSP_isr( Arg mode );

#endif

