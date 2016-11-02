/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk5510_aic23_write16.c ========
 *  DSK5510_AIC23_write16() implementation
 */

#include <dsk5510.h>
#include <dsk5510_aic23.h>


/*
 *  ======== DSK5510_AIC23_write16 ========
 *  Write a 16-bit value to the codec
 */
CSLBool DSK5510_AIC23_write16(DSK5510_AIC23_CodecHandle hCodec, Int16 val)
{
    /* If McBSP not ready for new data, return false */
    if (!MCBSP_xrdy(DSK5510_AIC23_DATAHANDLE)) {
        return (FALSE);
    }

    /* Write 16 bit data value to DXR */
    MCBSP_write16(DSK5510_AIC23_DATAHANDLE, val);

    return(TRUE);
}
