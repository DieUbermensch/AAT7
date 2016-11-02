/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk5510_aic23_mute.c ========
 *  DSK5510_AIC23_mute() implementation
 */

#include <dsk5510.h>
#include <dsk5510_aic23.h>

/*
 *  ======== DSK5510_AIC23_mute ========
 *  Enable/disable codec mute mode
 */
void DSK5510_AIC23_mute(DSK5510_AIC23_CodecHandle hCodec, CSLBool mode)
{
    int regval;

    /* Enable mute if mode is true */
    regval = (mode) ? 0x08 : 0x00;

    /* Write to codec registers (left and right) */
    DSK5510_AIC23_rset(hCodec, DSK5510_AIC23_DIGPATH,
        (DSK5510_AIC23_rget(hCodec, DSK5510_AIC23_DIGPATH) & 0xfff7) | regval);
}
