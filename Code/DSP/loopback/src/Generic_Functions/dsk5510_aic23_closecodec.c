/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk5510_aic23_closeCodec.c ========
 *  DSK5510_AIC23_closeCodec() implementation
 */

#include <dsk5510.h>
#include <dsk5510_aic23.h>

/*
 *  ======== DSK5510_AIC23_closeCodec ========
 *  Close the codec
 */
void DSK5510_AIC23_closeCodec(DSK5510_AIC23_CodecHandle hCodec)
{
    /* Turn the codec off */
    DSK5510_AIC23_rset(hCodec, DSK5510_AIC23_POWERDOWN, 0xff);
}
