/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk5510.c ========
 *  5510DSK board initializion implementation.
 */

#include <csl.h>

#include <dsk5510.h>
#include <dsk5510_aic23.h>

/* Initialize the board APIs */
void DSK5510_init()
{
}

/* Read a 16-bit value from a CPLD register */
Uint16 DSK5510_rget(Int16 regnum)
{
    return DSK5510_mget(DSK5510_CPLD_BASE + regnum);
}

/* Write a 16-bit value to a CPLD register */
void DSK5510_rset(Int16 regnum, Uint16 regval)
{
    DSK5510_mset(DSK5510_CPLD_BASE + regnum, regval);
}
