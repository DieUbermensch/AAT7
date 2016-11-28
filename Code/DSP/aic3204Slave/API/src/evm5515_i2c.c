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
 *  I2C implementation
 *
 */
#include "evm5515_i2c.h"

Int32 i2c_timeout = 0x0fff;

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  EVM5515_I2C_init( )                                                            *
 *                                                                          *
 *      Enable and initalize the I2C module                                 *
 *      The I2C clk is set to run at 100 KHz                                 *
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int16 EVM5515_I2C_init( )
{
	// Reset I2C
    I2C_MDR = 0x0400;             
	// Config I2C to 100MHz
    I2C_PSC   = 15; 
    I2C_CLKL  = 25;
    I2C_CLKH  = 25;
	// Release from reset; Set I2C to Master, Transmitter, 7-bit address
    I2C_MDR   = 0x0420;        

    return 0;
}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  EVM5515_I2C_close( )                                                           *
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int16 EVM5515_I2C_close( )
{
	// Reset I2C
    I2C_MDR = 0;
    return 0;
}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  EVM5515_I2C_reset( )                                                           *
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int16 EVM5515_I2C_reset( )
{
    EVM5515_I2C_close( );
    EVM5515_I2C_init( );
    return 0;
}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  EVM5515_I2C_write( Uint16 i2c_addr, Uint8* data, Uint16 len )                                       *
 *                                                                          *
 *      I2C write in Master mode                                            *
 *                                                                          *
 *      i2c_addr    <- I2C slave address                                    *
 *      data        <- I2C data ptr                                         *
 *      len         <- # of bytes to write                                  *
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int16 EVM5515_I2C_write( Uint16 i2c_addr, Uint8* data, Uint16 len )
{
    Int16 timeout, i;

	// construct the I2C write command with addr and length
    I2C_CNT = len;
    I2C_SAR = i2c_addr;
    I2C_MDR = MDR_STT
                  | MDR_TRX
                  | MDR_MST
                  | MDR_IRS
                  | MDR_FREE;

        EVM5515_wait(100);              // Short delay

        for ( i = 0 ; i < len ; i++ )
        {
           I2C_DXR = data[i];            // Write
            timeout = 0x7fff;//i2c_timeout;
            do
            {
                if ( timeout-- < 0  )
                {
                    EVM5515_I2C_reset( );
                    return -1;
                }
            } while ( ( I2C_STR & STR_XRDY ) == 0 );// Wait for Tx Ready
        }

        I2C_MDR |= MDR_STP;             // Generate STOP

		EVM5515_waitusec(1000);

        return 0;

}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  EVM5515_I2C_read( Uint16 i2c_addr, Uint8* data, Uint16 len )                                        *
 *                                                                          *
 *      I2C read in Master mode                                             *
 *                                                                          *
 *      i2c_addr    <- I2C slave address                                    *
 *      data        <- I2C data ptr                                         *
 *      len         <- # of bytes to write                                  *
 *                                                                          *
 *      Returns:    0: PASS                                                 *
 *                 -1: FAIL Timeout                                         *
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int16 EVM5515_I2C_read( Uint16 i2c_addr, Uint8* data, Uint16 len )
{
    Int32 timeout, i;

	// construct the I2C read command with addr and length
    I2C_CNT = len;
    I2C_SAR = i2c_addr;
    I2C_MDR = MDR_STT 
              | MDR_MST
              | MDR_IRS
              | MDR_FREE;

    EVM5515_wait( 10 );            // Short delay

    for ( i = 0 ; i < len ; i++ )
    {
        timeout = i2c_timeout;

        //Wait for Rx Ready
        do
        {
            if ( timeout-- < 0 )
            {
                EVM5515_I2C_reset( );
                return -1;
            }
        } while ( ( I2C_STR & STR_RRDY ) == 0 );// Wait for Rx Ready

        data[i] = I2C_DRR;            // Read
    }

    I2C_MDR |= MDR_STP;               // Generate STOP

	EVM5515_waitusec(10);
    return 0;
}
