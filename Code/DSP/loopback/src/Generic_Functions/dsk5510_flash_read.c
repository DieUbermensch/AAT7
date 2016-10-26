/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk5510_flash_read.c ========
 *  DSK5510_FLASH_read() implementation
 */

#include <std.h>
#include <csl.h>

#include <dsk5510.h>
#include <dsk5510_flash.h>

/* Read data from a data range in Flash */
void DSK5510_FLASH_read(Uint32 src, Uint32 dst, Uint32 length)
{
    Uint32 i, tmpval;

    /* Establish source and destination */
    for (i =0; i < length; i++)
    {
        tmpval = DSK5510_mget(src++);
        DSK5510_mset(dst++, tmpval);
    }
}
