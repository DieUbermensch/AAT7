/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk5510_dip.c ========
 *  DIP switch module for the DSK5510
 */

#include <csl.h>

#include <dsk5510.h>
#include <dsk5510_dip.h>

void DSK5510_DIP_init()
{
}

Uint32 DSK5510_DIP_get(Uint32 dipNum)
{
    /* Check bounds for dipNum */
    if (dipNum >= 4)
        return (Uint32)-1;

    /* Read DIP switch */
    if ((DSK5510_rget(DSK5510_USER_REG) & (0x10 << dipNum)) == 0)
        return 0;
    else
        return 1;
}

