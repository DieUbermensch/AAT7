/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk5510.c ========
 *  5510DSK board initialization implementation.
 */

#include <csl.h>

#include <dsk5510.h>

/* Read a 16-bit value from 32-bit address */
Uint16 DSK5510_mget(Uint32 memaddr)
{
    return *((Uint16 *)memaddr);
}

/* Write a 16-bit value to a 32-bit address */
void DSK5510_mset(Uint32 memaddr, Uint16 memval)
{
    *((Uint16 *)memaddr) = memval;
}
