/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk5510_flash_write.c ========
 *  DSK5510_FLASH_write() implementation
 */

#include <std.h>
#include <csl.h>

#include <dsk5510.h>
#include <dsk5510_flash.h>

/* Write data to a data range in Flash */
void DSK5510_FLASH_write(Uint32 src, Uint32 dst, Uint32 length)
{
    Uint32 i, tmpval;

    /* Establish source and destination */
    for (i = 0; i < length; i++)
    {
        // Program one 16-bit word
        DSK5510_mset(DSK5510_FLASH_CTL555, 0xaa);
        DSK5510_mset(DSK5510_FLASH_CTL2AA, 0x55);
        DSK5510_mset(DSK5510_FLASH_CTL555, 0xa0);
        tmpval = DSK5510_mget(src);
        DSK5510_mset(dst, tmpval);

        // Wait for operation to complete
        while(1)
        {
            tmpval = DSK5510_mget(src);
            if (DSK5510_mget(dst) == tmpval)
                break;
        }

        src++;
        dst++;
    }

    /* Put back in read mode */
    DSK5510_mset(DSK5510_FLASH_BASE, 0xf0);
}
