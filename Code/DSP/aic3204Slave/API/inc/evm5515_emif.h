/* ============================================================================
 * Copyright (c) 2008-2012 Texas Instruments Incorporated.
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/


/*
 *  EMIF Header file
 *
 */


/* ------------------------------------------------------------------------ *
 *  Registers                                                               *
 * ------------------------------------------------------------------------ */

#define EMIF_REV                *(volatile ioport Uint16*)(0x1000)
#define EMIF_STATUS             *(volatile ioport Uint16*)(0x1001)
#define EMIF_AWCCR1             *(volatile ioport Uint16*)(0x1004)
#define EMIF_AWCCR2             *(volatile ioport Uint16*)(0x1005)
#define EMIF_ACS2CR1            *(volatile ioport Uint16*)(0x1010)
#define EMIF_ACS2CR2            *(volatile ioport Uint16*)(0x1011)
#define EMIF_ACS3CR1            *(volatile ioport Uint16*)(0x1014)
#define EMIF_ACS3CR2            *(volatile ioport Uint16*)(0x1015)
#define EMIF_ACS4CR1            *(volatile ioport Uint16*)(0x1018)
#define EMIF_ACS4CR2            *(volatile ioport Uint16*)(0x1019)
#define EMIF_ACS5CR1            *(volatile ioport Uint16*)(0x101C)
#define EMIF_ACS5CR2            *(volatile ioport Uint16*)(0x101D)
#define EMIF_EIRR               *(volatile ioport Uint16*)(0x1040)
#define EMIF_EIMR               *(volatile ioport Uint16*)(0x1044)
#define EMIF_EIMSR              *(volatile ioport Uint16*)(0x1048)
#define EMIF_EIMCR              *(volatile ioport Uint16*)(0x104C)
#define EMIF_NANDFCR            *(volatile ioport Uint16*)(0x1060)
#define EMIF_NANDFSR1           *(volatile ioport Uint16*)(0x1064)
#define EMIF_NANDFSR2           *(volatile ioport Uint16*)(0x1065)

