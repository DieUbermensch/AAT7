/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk5510_aic23_write32.c ========
 *  DSK5510_AIC23_write32() implementation
 */

#include <dsk5510.h>
#include <dsk5510_aic23.h>

/*
 *  ======== DSK5510_AIC23_write32 ========
 *  Write a 32-bit value to the codec
 */
CSLBool DSK5510_AIC23_write32(DSK5510_AIC23_CodecHandle hCodec, Int32 val)
{
    /* If McBSP doesn't have new data available, return false */
    if(!MCBSP_xrdy(DSK5510_AIC23_DATAHANDLE)) {
        return (FALSE);
    }

    /* Write 32 bit data value to DXR, shift to match format mode */
    MCBSP_write32(DSK5510_AIC23_DATAHANDLE, val);

    return (TRUE);
}
