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



/*********************************************************************
*    mcspi.h
**********************************************************************/
#ifndef MCSPI_H
#define MCSPI_H

/*********************************************************************
* Bit-field definitions for MCSPI registers...
**********************************************************************/

/* clock regsiter */
#define MCSPI_CLK_ENABLE       0x8000
/* device config register */
/* command register */
#define MCSPI_CMD_WIRQ         0x4000
#define MCSPI_CMD_FIRQ         0x8000
#define MCSPI_CMD_FLEN         0xFFF
#define MCSPI_CMD_WRITE        0x2     /* Write command */
#define MCSPI_CMD_READ         0x1     /* Read command */
#define MCSPI_CMD_WLEN_SHIFT   0x3     /* word length shift */
#define MCSPI_CMD_8BIT_WLEN    0x7
#define MCSPI_CMD_16BIT_WLEN   0x15
#define MCSPI_CMD_CS0          0x0     /* CS0 transfer */
#define MCSPI_CMD_CS1          0x1     /* CS1 transfer */
#define MCSPI_CMD_CS2          0x2     /* CS2 transfer */
#define MCSPI_CMD_CS3          0x3     /* CS3 transfer */
#define MCSPI_CMD_CS_SHIFT     12
/* status register */
#define MCSPI_STATUS_BUSY      0x1
#define MCSPI_STATUS_WC        0x2
#define MCSPI_STATUS_FC        0x4
#define MCSPI_STATUS_AE        0x8

#define MCSPI_TIMEOUT	         30000
#define MCSPI_ERROR_TIMEOUT	     0x0004

/******************************************************
      Function prototypes
******************************************************/
Uint16 MCSPI_RESET(void);
Uint16 MCSPI_INIT(unsigned char clock_divider);
Uint16 MCSPI_READ_WRITE_N_BYTES(unsigned short *buffer, unsigned short count,
               unsigned short *cmdbuffer, unsigned short cmdcount, unsigned short readWrite );

#endif // MCSPI_H
