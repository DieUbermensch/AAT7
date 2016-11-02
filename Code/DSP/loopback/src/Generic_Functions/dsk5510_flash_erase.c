/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk5510_flash_erase.c ========
 *  DSK5510_FLASH_erase() implementation
 */

#include <std.h>
#include <csl.h>

#include <dsk5510.h>
#include <dsk5510_flash.h>

#define DSK5510_FLASH_SECTORS       11

/* Constant table containing end address of each sector */
static Uint32 sector_end[DSK5510_FLASH_SECTORS] = {
    DSK5510_FLASH_BASE + 0x007fff, /* Sector 0  */
    DSK5510_FLASH_BASE + 0x00ffff, /* Sector 1  */
    DSK5510_FLASH_BASE + 0x017fff, /* Sector 2  */
    DSK5510_FLASH_BASE + 0x01ffff, /* Sector 3  */
    DSK5510_FLASH_BASE + 0x027fff, /* Sector 4  */
    DSK5510_FLASH_BASE + 0x02ffff, /* Sector 5  */
    DSK5510_FLASH_BASE + 0x037fff, /* Sector 6  */
    DSK5510_FLASH_BASE + 0x03bfff, /* Sector 7  */
    DSK5510_FLASH_BASE + 0x03cfff, /* Sector 8  */
    DSK5510_FLASH_BASE + 0x03dfff, /* Sector 9  */
    DSK5510_FLASH_BASE + 0x03ffff  /* Sector 10 */
};


/* Erase a segment of Flash memory */
void DSK5510_FLASH_erase(Uint32 start, Uint32 length)
{
    Int16 i;
    Uint32 sector_base, end;

    /* Calculate extents of range to erase */
    end = start + length - 1;

    /* Walk through each sector, erase any sectors within range */
    sector_base = DSK5510_FLASH_BASE;
    for (i = 0; i < DSK5510_FLASH_SECTORS; i++)
    {
        if ((start <= sector_base) && (sector_end[i] <= end))
        {
            /* Start sector erase sequence */
            DSK5510_mset(DSK5510_FLASH_CTL555, 0xaa);
            DSK5510_mset(DSK5510_FLASH_CTL2AA, 0x55);
            DSK5510_mset(DSK5510_FLASH_CTL555, 0x80);
            DSK5510_mset(DSK5510_FLASH_CTL555, 0xaa);
            DSK5510_mset(DSK5510_FLASH_CTL2AA, 0x55);

            /* Start erase at sector address */
            DSK5510_mset(sector_end[i], 0x30);

            /* Wait for erase to complete */
            while (1)
                if (DSK5510_mget(sector_end[i]) & 0x80)
                    break;

            /* Put back in read mode */
            DSK5510_mset(DSK5510_FLASH_BASE, 0xf0);
        }

        /* Advance to next sector */
        sector_base = sector_end[i] + 1;
    }
}
