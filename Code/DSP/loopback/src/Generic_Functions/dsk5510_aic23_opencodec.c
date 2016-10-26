/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk5510_aic23_openCodec.c ========
 *  DSK5510_AIC23_openCodec() implementation
 */

#include <dsk5510.h>
#include <dsk5510_aic23.h>

/*
 *  ======== DSK5510_AIC23_openCodec ========
 *  Open the codec and return a codec handle
 */
DSK5510_AIC23_CodecHandle DSK5510_AIC23_openCodec(int id, DSK5510_AIC23_Config *Config)
{
    /*
     *  Initialize the AIC23 codec
     */

    /* Start McBSP1 as the codec control channel */
    MCBSP_start(DSK5510_AIC23_CONTROLHANDLE, MCBSP_XMIT_START |
        MCBSP_SRGR_START | MCBSP_SRGR_FRAMESYNC, 100);

    /* Reset the AIC23 */
    DSK5510_AIC23_rset(0, DSK5510_AIC23_RESET, 0);

    /* Configure the rest of the AIC23 registers */
    DSK5510_AIC23_config(0, Config);

    /* Clear any garbage from the codec data port */
    if (MCBSP_rrdy(DSK5510_AIC23_DATAHANDLE))
        MCBSP_read16(DSK5510_AIC23_DATAHANDLE);

    /* Start McBSP2 as the codec data channel */
    MCBSP_start(DSK5510_AIC23_DATAHANDLE, MCBSP_XMIT_START | MCBSP_RCV_START |
        MCBSP_SRGR_START | MCBSP_SRGR_FRAMESYNC, 220);

    return (0);
}
