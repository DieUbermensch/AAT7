/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk5510_led.c ========
 *  LED module for the DSK5510
 */

#include <csl.h>

#include "dsk5510.h"
#include "dsk5510_led.h"

static Int16 ledstate;

void DSK5510_LED_init()
{
    /* Turn all LEDs off */
    ledstate = 0;
    DSK5510_rset(DSK5510_USER_REG, ledstate);
}

void DSK5510_LED_off(Uint32 ledNum)
{
    /* Check bounds for ledNum */
    if (ledNum >= 4)
        return;

    /* Clear the LED bit */
    ledstate &= ~(1 << ledNum);
    DSK5510_rset(DSK5510_USER_REG, ledstate);
}

void DSK5510_LED_on(Uint32 ledNum)
{
    /* Check bounds for ledNum */
    if (ledNum >= 4)
        return;

    /* Set the LED bit */
    ledstate |= 1 << ledNum;
    DSK5510_rset(DSK5510_USER_REG, ledstate);
}

void DSK5510_LED_toggle(Uint32 ledNum)
{
    /* Check bounds for ledNum */
    if (ledNum >= 4)
        return;

    /* Toggle the LED bit */
    if ((DSK5510_rget(DSK5510_USER_REG) & (1 << ledNum)) == 0)
        DSK5510_LED_on(ledNum);
    else
        DSK5510_LED_off(ledNum);
}


