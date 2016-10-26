/*
 *  Copyright 2002 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *
 */
/* "@(#) ReferenceFrameworks 1.10.00 04-30-02 (swat-b21)" */
/*
 *  ======== c55xx_dma_mcbsp.c ========
 *
 *  DMA interrupt-driven low-level streaming device driver for TI
 *  C55x chips. Uses the C55x Chip Support Library.
 */

#include <std.h>

#include <atm.h>
#include <hwi.h>
#include <log.h>

#include <csl.h>
#include <csl_dma.h>
#include <csl_mcbsp.h>
#include <csl_irq.h>

#include <lio.h>

#include <c55xx_dma_mcbsp.h>

/*
 * Driver state variables
 */
typedef struct ChanObj {
    Bool        inuse;          /* TRUE => channel has been opened */

    LIO_Mode    mode;           /* LIO_INPUT or LIO_OUTPUT */

    Uns         cursize;        /* size of current buffer 0 = DMA not active */

    Ptr         nextbufp;       /* hold next job for multiple submits */
    Uns         nextsize;

    LIO_Tcallback callback;     /* used to notify client when I/O complete */
    Arg         callbackArg;
} ChanObj, *ChanHandle;

/*
 *  Channel state variable storage.
 */
#define NUMCHANS        2       /* LIO_INPUT and LIO_OUTPUT */
static ChanObj chans[NUMCHANS] = {
    {FALSE, LIO_INPUT, 0, NULL, 0, NULL, NULL},
    {FALSE, LIO_OUTPUT, 0, NULL, 0, NULL, NULL}
};

extern DMA_Handle C55XX_DMA_MCBSP_hDmaRx;
extern DMA_Handle C55XX_DMA_MCBSP_hDmaTx;
extern MCBSP_Handle C55XX_DMA_MCBSP_hMcbsp;

/*
 * Forward declaration of LIO interface functions. They are only exposed
 * via the LIO function table to avoid namespace pollution.
 */
static Bool cancel(Ptr chanp);
static Bool close(Ptr chanp);
static Bool ctrl(Ptr chanp, Uns cmd, Ptr args);
static Ptr open(String name, LIO_Mode mode, Ptr args, LIO_Tcallback cbFxn, Arg cbArg);
static Int submit(Ptr chanp, Ptr bufp, Uns size);

/*
 * Public LIO interface table.
 */
LIO_Fxns C55XX_DMA_MCBSP_ILIO = {
    &cancel,
    &close,
    &ctrl,
    &open,
    &submit,
};

static Void startDma(LIO_Mode mode, Ptr bufp, Uns nmaus);

/*
 *  ======== cancel ========
 */
static Bool cancel(Ptr chanp)
{
    ChanHandle chan = (ChanHandle)chanp;

    if (chan->mode == LIO_INPUT) {
        DMA_stop(C55XX_DMA_MCBSP_hDmaRx);
    }
    else {
        DMA_stop(C55XX_DMA_MCBSP_hDmaTx);
    }

    chan->cursize = chan->nextsize = 0;

    return (TRUE);              /* success */
}

/*
 *  ======== close ========
 */
static Bool close(Ptr chanp)
{
    ChanHandle chan = (ChanHandle)chanp;
    Uns event;

    chan->inuse = FALSE;

    if (chan->mode == LIO_INPUT) {
        event = DMA_getEventId(C55XX_DMA_MCBSP_hDmaRx);
    }
    else {
        event = DMA_getEventId(C55XX_DMA_MCBSP_hDmaTx);
    }

    IRQ_disable(event);

    return (TRUE);              /* success */
}

/*
 *  ======== ctrl ========
 *  The LIO ctrl function. Catch all for adding device or vendor
 *  specific functionality to an LIO driver.
 */
static Bool ctrl(Ptr chanp, Uns cmd, Ptr args)
{
    return (TRUE);      /* success */
}

/*
 *  ======== open ========
 */
static Ptr open(String name, LIO_Mode mode, Ptr args,
                LIO_Tcallback cbFxn, Arg cbArg)
{
    ChanHandle chan;
    Uns event;

    /* Check to make sure LIO_Tcallback is NULL */
    if (cbFxn == NULL) {
       return (NULL);
    }

    chan = &chans[mode];        /* bind input or output channel */

    /*
     * Check check if channel is already in use.
     * Use ATM_setu() for atomic test-and-set.
     */
    if (ATM_setu((Uns *)&chan->inuse, TRUE)) {
        return (NULL);          /* ERROR! channel is already open! */
    }

    chan->cursize = 0;

    chan->callback = cbFxn;
    chan->callbackArg = cbArg;

    if (chan->mode == LIO_INPUT) {
        event = DMA_getEventId(C55XX_DMA_MCBSP_hDmaRx);
    }
    else {
        event = DMA_getEventId(C55XX_DMA_MCBSP_hDmaTx);
    }

    /* Enable DMA interrupt */
    IRQ_enable(event);

    return ((Ptr)chan);         /* success */
}

/*
 *  ======== submit ========
 *  Sets the buf variables in the channel object and starts the DMA.
 */
static Int submit(Ptr chanp, Ptr bufp, Uns nmaus)
{
    ChanHandle chan = (ChanHandle)chanp;
    Uns imask;

    imask = HWI_disable();

    if (chan->cursize != 0) {
        if (chan->nextsize != 0) {
            HWI_restore(imask);
            return (-1);        /* ERROR! no slots available */
        }
        chan->nextbufp = bufp;
        chan->nextsize = nmaus;
    }
    else {
        chan->cursize = nmaus;
        startDma(chan->mode, bufp, nmaus);
    }

    HWI_restore(imask);

    return (0);                 /* SUCCESS */
}

/*
 *  ======== startDma ========
 */
static Void startDma(LIO_Mode mode, Ptr bufp, Uns nmaus)
{
    /*
     *  Program upper and lower addresses in appropriate DMA channel
     *  and start transfer.
     *  By default, the TMS320C55xx compiler assigns all data symbols word
     *  addresses. The DMA however, expects all addresses to be byte
     *  addresses. Therefore, we must shift the address by 2 in order to
     *  change the word address to a byte address for the DMA transfer.
     */
    Uint16 dmaAddrU = (Uint16)( ((Uint32)bufp>>15) & 0xFFFF );
    Uint16 dmaAddrL = (Uint16)( ((Uint32)bufp<<1) & 0xFFFF );

    if (mode == LIO_INPUT) {
        DMA_RSETH(C55XX_DMA_MCBSP_hDmaRx, DMACDSAL, dmaAddrL);
        DMA_RSETH(C55XX_DMA_MCBSP_hDmaRx, DMACDSAU, dmaAddrU);
        DMA_RSETH(C55XX_DMA_MCBSP_hDmaRx, DMACEN, nmaus);
        DMA_start(C55XX_DMA_MCBSP_hDmaRx);
    }
    else {
        DMA_RSETH(C55XX_DMA_MCBSP_hDmaTx, DMACSSAL, dmaAddrL);
        DMA_RSETH(C55XX_DMA_MCBSP_hDmaTx, DMACSSAU, dmaAddrU);
        DMA_RSETH(C55XX_DMA_MCBSP_hDmaTx, DMACEN, nmaus);
        DMA_start(C55XX_DMA_MCBSP_hDmaTx);
    }
}

/*
 *  ======== C55XX_DMA_MCBSP_rxIsr ========
 *  Workaround for bug SDSsq23674 : 55x HWI dispatcher passes invalid argument
 */
Void C55XX_DMA_MCBSP_rxIsr(Void)
{
    C55XX_DMA_MCBSP_isr( (Arg)LIO_INPUT );
}

/*
 *  ======== C55XX_DMA_MCBSP_txIsr ========
 *  Workaround for bug SDSsq23674 : 55x HWI dispatcher passes invalid argument
 */
Void C55XX_DMA_MCBSP_txIsr(Void)
{
    C55XX_DMA_MCBSP_isr( (Arg)LIO_OUTPUT );
}

/*
 *  ======== C55XX_DMA_MCBSP_isr ========
 *  Argument is of type 'Arg' instead of 'LIO_Mode' in preparation for
 *  when SDSsq23674 is fixed, and this function can be plugged directly into
 *  the BIOS HWI Function configuration.
 *  If you are using a CCS release where this bug is fixed, simply :-
 *      - kill the C55XX_DMA_MCBSP_rxIsr, C55XX_DMA_MCBSP_txIsr ISRs,
 *      - plug both input and output BIOS HWI vectors with _C55XX_DMA_MCBSP_isr
 *      - set the Receive (LIO_INPUT) BIOS HWI vector Dispatcher Arg == 0x0
 *      - set the Transmit (LIO_OUTPUT) BIOS HWI vector Dispatcher Arg == 0x1
 */
Void C55XX_DMA_MCBSP_isr( Arg mode )
{
    ChanHandle   chan;
    Uns          nmaus;
    volatile Uns temp;

    /* ArgToInt ensures compatibility for 55x large model if used */
    LIO_Mode     lioMode = (LIO_Mode)( ArgToInt(mode) );
    chan = &chans[lioMode];

    /*
     *  Need to clear the C55 DMA channel's CSR bits to ensure we continue
     *  to get DMA completion interrupts. We do this by reading DMACSR reg
     *  Note : this is different from C54xx where we dont need to do this
     */
    if (chan->mode == LIO_INPUT) {
        temp = DMA_RGETH( C55XX_DMA_MCBSP_hDmaRx, DMACSR );
    }
    else {
        temp = DMA_RGETH( C55XX_DMA_MCBSP_hDmaTx, DMACSR );
    }

    nmaus = chan->cursize;      // nmaus is needed for callback below

    chan->cursize = 0;

    /*
     * Check to see if another job is pending.  If yes, reprogram the DMA.
     */
    if (chan->nextsize != 0) {
        chan->cursize = chan->nextsize;
        startDma(chan->mode, chan->nextbufp, chan->nextsize);
        chan->nextsize = 0;
    }
    else {
        LOG_message("C55XX_DMA_MCBSP_isr: WARNING: nextsize = 0!", 0);
    }

    (*chan->callback)(chan->callbackArg, nmaus);
}

/*
 *  ======== C55XX_DMA_MCBSP_init ========
 */
Void C55XX_DMA_MCBSP_init(void)
{
    /*
     * This function is currently empty.  Initialization of the
     * McBSP, DMA and codec are handled by the board/codec specific
     * controller.
     */
}

