/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk5510_flash_checksum.c ========
 *  DSK5510_FLASH_checksum() implementation
 */

#include <std.h>
#include <csl.h>

#include <dsk5510.h>
#include <dsk5510_flash.h>

/* Calculate the checksum of a data range in Flash */
Uint32 DSK5510_FLASH_checksum(Uint32 start, Uint32 length)
{
    Uint32 i, checksum;

    /* Calculate checksum by adding each word to the total */
    checksum = 0;
    for (i = 0; i < length; i++)
    {
        checksum += DSK5510_mget(start++);
    }

    return checksum;
}
