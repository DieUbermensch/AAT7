/*
 *  Copyright 2002 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *
 */
/* "@(#) ReferenceFrameworks 1.10.00 04-30-02 (swat-b21)" */
/*
 *  ======== dsk5510_dma_aic23.c ========
 *
 *  DMA interrupt-driven low-level streaming device driver for TI
 *  5510 DSK. Uses the C55x Chip Support Library.
 *
 *  DSP/BIOS configuration:
 *     DMA channel 4 RX ISR plugged to C55XX_DMA_MCBSP_isr with arg = 0
 *     DMA channel 5 TX ISR plugged to C55XX_DMA_MCBSP_isr with arg = 1
 */

#include <std.h>

#include <csl.h>
#include <csl_dma.h>
#include <csl_mcbsp.h>

#include <lio.h>

#include <c55xx_dma_mcbsp.h>
#include <dsk5510_dma_aic23.h>
#include <dsk5510_aic23.h>

/*
 * Public LIO interface table.
 * This table is initialized by DSK5510_DMA_AIC23_init function.
 */
LIO_Fxns DSK5510_DMA_AIC23_ILIO;

/*
 *  Public driver setup data object. Used if the user passes NULL as
 *  setup() argument, or by the user to modify the default parameters.
 */
DSK5510_DMA_AIC23_Setup DSK5510_DMA_AIC23_SETUP = {
    DSK5510_AIC23_DEFAULTCONFIG,          /* default codec parameters */
};

/*
 *  ======== DSK5510_DMA_AIC23_init ========
 *
 *  Controller initialization function
 */
#pragma CODE_SECTION(DSK5510_DMA_AIC23_init, ".text:init")
Void DSK5510_DMA_AIC23_init(Void)
{
    volatile Uint16 dummy;

    /*
     * Use C55XX_DMA_MCBSP_ILIO functions for the heart of the
     * controller.  This is common DMA/MCBSP code that works for
     * many DMA/MCBSP/codec combinations.
     */
    DSK5510_DMA_AIC23_ILIO = C55XX_DMA_MCBSP_ILIO;
    C55XX_DMA_MCBSP_init();

    /*
     * Clear DMA status registers.  DMA interrupts will not trigger if
     * the controller thinks a previous interrupt has not been properly
     * handler.
     */
    dummy = DMA_RGETH( C55XX_DMA_MCBSP_hDmaRx, DMACSR );
    dummy = DMA_RGETH( C55XX_DMA_MCBSP_hDmaTx, DMACSR );
}

/*
 *  ======== EVM5509_DMA_AIC23_setup ========
 *
 *  Driver setup() function, called by the user after the init() function
 *  above. Either the address of a driver setup object is passed, or NULL,
 *  in which case the function will use the default setup object, defined
 *  above.
 *  Initializes the DMA, McBSPs connected to the codec, and the codec.
 */

#pragma CODE_SECTION(DSK5510_DMA_AIC23_setup, ".text:init")
Void DSK5510_DMA_AIC23_setup(DSK5510_DMA_AIC23_Setup *setup )
{
    static Bool curinit = FALSE;
    volatile Uns temp;

    if (curinit) {
        return;
    }
    curinit = TRUE;

    /* use default parameters if none are given */
    if (setup == NULL) {
        setup = &DSK5510_DMA_AIC23_SETUP;
    }

    /* Set DMA to continue transfer even during emulation stop */
    DMA_FSET( DMAGCR, FREE, 1 );

    /* set codec parameters (this will also initialize the codec) */
    DSK5510_AIC23_openCodec( 0, &(setup->aic23) );

}
