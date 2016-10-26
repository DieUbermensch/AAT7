/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk5510_aic23_read16.c ========
 *  DSK5510_AIC23_read16() implementation
 */

#include <dsk5510.h>
#include <dsk5510_aic23.h>

/*
 *  ======== DSK5510_AIC23_read16 ========
 *  Read a 16-bit value from the codec
 */
CSLBool DSK5510_AIC23_read16(DSK5510_AIC23_CodecHandle hCodec, Int16 *val)
{
    /* If McBSP doesn't have new data available, return false */
    if (!MCBSP_rrdy(DSK5510_AIC23_DATAHANDLE)) {
        return (FALSE);
    }

    /* Read the data */
    *val = MCBSP_read16(DSK5510_AIC23_DATAHANDLE);
    return (TRUE);
}
