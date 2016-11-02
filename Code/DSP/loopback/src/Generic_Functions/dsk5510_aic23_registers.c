/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk5510_aic23_registers.c ========
 *  DSK5510_AIC23_rset() and DSK5510_AIC23_rget() implementation
 */
#include <dsk5510.h>
#include <dsk5510_aic23.h>

/* Internal codec state used to simulate read/write functionality */
static DSK5510_AIC23_Config codecstate = DSK5510_AIC23_DEFAULTCONFIG;

/*
 *  ======== DSK5510_AIC23_rset ========
 *  Set codec register regnum to value regval
 */
void DSK5510_AIC23_rset(DSK5510_AIC23_CodecHandle hCodec, Uint16 regnum, Uint16 regval)
{
    /* Mask off lower 9 bits */
    regval &= 0x1ff;

    /* Wait for XRDY signal before writing data to DXR */
    while (!MCBSP_xrdy(DSK5510_AIC23_CONTROLHANDLE));

    /* Write 16 bit data value to DXR */
    MCBSP_write16(DSK5510_AIC23_CONTROLHANDLE, (regnum << 9) | regval);

    /* Save register value if regnum is in range */
    if (regnum < DSK5510_AIC23_NUMREGS)
        codecstate.regs[regnum] = regval;
}

/*
 *  ======== DSK5510_AIC23_rget ========
 *  Return value of codec register regnum
 */
Uint16 DSK5510_AIC23_rget(DSK5510_AIC23_CodecHandle hCodec, Uint16 regnum)
{
    if (regnum < DSK5510_AIC23_NUMREGS)
        return codecstate.regs[regnum];
    else
        return 0;
}

/*
 *  ======== DSK5510_AIC23_config ========
 *  Set the default codec register config values
 */
void DSK5510_AIC23_config(DSK5510_AIC23_CodecHandle hCodec, DSK5510_AIC23_Config *Config)
{
    int i;

    /* Use default parameters if none are given */
    if (Config == NULL)
        Config = &codecstate;

    /* Assign each register */
    for (i = 0; i < DSK5510_AIC23_NUMREGS; i++)
        DSK5510_AIC23_rset(hCodec, i, Config -> regs[i]);
}
