/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk5510_aic23_powerDown.c ========
 *  DSK5510_AIC23_powerDown() implementation
 */

#include <dsk5510.h>
#include <dsk5510_aic23.h>

/*
 *  ======== DSK5510_AIC23_powerDown ========
 *  Enable/disable powerdown modes for the DAC and ADC codec subsections
 */
void DSK5510_AIC23_powerDown(DSK5510_AIC23_CodecHandle hCodec, Uint16 sect)
{
    /* Write to codec register */
    DSK5510_AIC23_rset(hCodec, DSK5510_AIC23_POWERDOWN,
        (DSK5510_AIC23_rget(hCodec, DSK5510_AIC23_POWERDOWN) & 0xff00) | (sect & 0xff));
}
