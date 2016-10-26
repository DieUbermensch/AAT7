/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk5510_aic23_setfreq.c ========
 *  DSK5510_AIC23_setFreq() implementation
 */

#include <dsk5510.h>
#include <dsk5510_aic23.h>

/*
 *  ======== DSK5510_AIC23_outGain ========
 *  Set the output gain on the codec
 */
void DSK5510_AIC23_outGain(DSK5510_AIC23_CodecHandle hCodec, Uint16 outGain)
{
    /* Write to codec registers (left and right) */
    DSK5510_AIC23_rset(hCodec, DSK5510_AIC23_LEFTHPVOL,
        (DSK5510_AIC23_rget(hCodec, DSK5510_AIC23_LEFTHPVOL) & 0xff80) | (outGain & 0x7f));
    DSK5510_AIC23_rset(hCodec, DSK5510_AIC23_RIGHTHPVOL,
        (DSK5510_AIC23_rget(hCodec, DSK5510_AIC23_RIGHTHPVOL) & 0xff80) | (outGain & 0x7f));
}

