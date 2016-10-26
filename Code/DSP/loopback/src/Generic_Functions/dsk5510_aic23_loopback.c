/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk5510_aic23_loopback.c ========
 *  DSK5510_AIC23_loopback() implementation
 */

#include <dsk5510.h>
#include <dsk5510_aic23.h>

/*
 *  ======== DSK5510_AIC23_loopback ========
 *  Enable/disable codec loopback mode
 */
void DSK5510_AIC23_loopback(DSK5510_AIC23_CodecHandle hCodec, CSLBool mode)
{
    int regval;

    /* Set bypass bit if mode is true */
    regval = (mode) ? 0x8 : 0x0;

    /* Write to codec register */
    DSK5510_AIC23_rset(hCodec, DSK5510_AIC23_ANAPATH,
        (DSK5510_AIC23_rget(hCodec, DSK5510_AIC23_ANAPATH) & 0xfff7 | regval));
}
