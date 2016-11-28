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


#include<stdio.h>
#include<csl_i2c.h>

#define CSL_I2C_OWN_ADDR		(0x2F)
#define CSL_I2C_SYS_CLK			(100)
#define CSL_I2C_BUS_FREQ		(10)
#define CSL_I2C_TCA6416_ADDR	(0x21)

CSL_Status ioExpander_Setup(void);
CSL_Status ioExpander_Read(Uint16 port, Uint16 pin, Uint16 *rValue);
CSL_Status ioExpander_Write(Uint16 port, Uint16 pin, Uint16 value);

CSL_Status ioExpander_Setup(void)
{
	CSL_Status 		status;
	CSL_I2cSetup	i2cSetup;

	/* Initialize I2C module */
	status = I2C_init(CSL_I2C0);
	if(status != CSL_SOK)
	{
		printf("I2C Init Failed!!\n");
		return(status);
	}

	/* Setup I2C module */
	i2cSetup.addrMode    = CSL_I2C_ADDR_7BIT;
	i2cSetup.bitCount    = CSL_I2C_BC_8BITS;
	i2cSetup.loopBack    = CSL_I2C_LOOPBACK_DISABLE;
	i2cSetup.freeMode    = CSL_I2C_FREEMODE_DISABLE;
	i2cSetup.repeatMode  = CSL_I2C_REPEATMODE_DISABLE;
	i2cSetup.ownAddr     = CSL_I2C_OWN_ADDR;
	i2cSetup.sysInputClk = CSL_I2C_SYS_CLK;
	i2cSetup.i2cBusFreq  = CSL_I2C_BUS_FREQ;

	status = I2C_setup(&i2cSetup);
	if(status != CSL_SOK)
	{
		printf("I2C Setup Failed!!\n");
		return(status);
	}

	return status;
}

CSL_Status ioExpander_Read(Uint16 port, Uint16 pin, Uint16 *rValue)
{
	CSL_Status 	status;
	Uint16		i2cWriteBuf[2];
	Uint16 		i2cReadBuf[1];
	Uint16		configOld;

/*Read Old Config*/
	if(0 == port)
	{
		i2cWriteBuf[0] = 0x06; /*Port0 Config Cmd*/
	}
	else if(1 == port)
	{
		i2cWriteBuf[0] = 0x07; /*Port1 Config Cmd*/
	}
	{ Uint16 delay; for(delay=0; delay<0xFFFF; delay++);}
	status = I2C_write(i2cWriteBuf, 1, CSL_I2C_TCA6416_ADDR,
						TRUE, ((CSL_I2C_START) | (CSL_I2C_STOP)),
						CSL_I2C_MAX_TIMEOUT);
	if(status != CSL_SOK)
	{
		printf("I2C Write Failed!!\n");
		return(status);
	}

	{ Uint16 delay; for(delay=0; delay<0xFFFF; delay++);}
	status = I2C_read(i2cReadBuf, 1, CSL_I2C_TCA6416_ADDR,
	                   TRUE, ((CSL_I2C_START) | (CSL_I2C_STOP)),
	                   CSL_I2C_MAX_TIMEOUT, FALSE);
	if(status != CSL_SOK)
	{
		printf("I2C Read Failed!!\n");
		return(status);
	}

	configOld = i2cReadBuf[0];

/*Set new config*/
	if(0 == port)
	{
		i2cWriteBuf[0] = 0x06; /*Port0 Config Cmd*/
	}
	else if(1 == port)
	{
		i2cWriteBuf[0] = 0x07; /*Port1 Config Cmd*/
	}
	i2cWriteBuf[1] = configOld;
	i2cWriteBuf[1] |= ((Uint16)0x1 << pin); /*1-IN, 0-OUT*/
	{ Uint16 delay; for(delay=0; delay<0xFFFF; delay++);}
	status = I2C_write(i2cWriteBuf, 2, CSL_I2C_TCA6416_ADDR,
						TRUE, ((CSL_I2C_START) | (CSL_I2C_STOP)),
						CSL_I2C_MAX_TIMEOUT);
	if(status != CSL_SOK)
	{
		printf("I2C Write Failed!!\n");
		return(status);
	}

/*Read pin*/
	if(0 == port)
	{
		i2cWriteBuf[0] = 0x00; /*Port0 Input Cmd*/
	}
	else if(1 == port)
	{
		i2cWriteBuf[0] = 0x01; /*Port1 Input Cmd*/
	}
	{ Uint16 delay; for(delay=0; delay<0xFFFF; delay++);}
	status = I2C_write(i2cWriteBuf, 1, CSL_I2C_TCA6416_ADDR,
						TRUE, ((CSL_I2C_START) | (CSL_I2C_STOP)),
						CSL_I2C_MAX_TIMEOUT);
	if(status != CSL_SOK)
	{
		printf("I2C Write Failed!!\n");
		return(status);
	}

	{ Uint16 delay; for(delay=0; delay<0xFFFF; delay++);}
	status = I2C_read(i2cReadBuf, 1, CSL_I2C_TCA6416_ADDR,
	                   TRUE, ((CSL_I2C_START) | (CSL_I2C_STOP)),
	                   CSL_I2C_MAX_TIMEOUT, FALSE);
	if(status != CSL_SOK)
	{
		printf("I2C Read Failed!!\n");
		return(status);
	}

	*rValue = (i2cReadBuf[0] >> pin) & 0x1;

	return status;
}

CSL_Status ioExpander_Write(Uint16 port, Uint16 pin, Uint16 wValue)
{
	CSL_Status 	status;
	Uint16 		i2cWriteBuf[2];
	Uint16 		i2cReadBuf[1];
	Uint16		configOld;
	Uint16		driveOld;

/*Read Old Config*/
	if(0 == port)
	{
		i2cWriteBuf[0] = 0x06; /*Port0 Config Cmd*/
	}
	else if(1 == port)
	{
		i2cWriteBuf[0] = 0x07; /*Port1 Config Cmd*/
	}
	{ Uint16 delay; for(delay=0; delay<0xFFFF; delay++);}
	status = I2C_write(i2cWriteBuf, 1, CSL_I2C_TCA6416_ADDR,
						TRUE, ((CSL_I2C_START) | (CSL_I2C_STOP)),
						CSL_I2C_MAX_TIMEOUT);
	if(status != CSL_SOK)
	{
		printf("I2C Write Failed!!\n");
		return(status);
	}

	{ Uint16 delay; for(delay=0; delay<0xFFFF; delay++);}
	status = I2C_read(i2cReadBuf, 1, CSL_I2C_TCA6416_ADDR,
	                   TRUE, ((CSL_I2C_START) | (CSL_I2C_STOP)),
	                   CSL_I2C_MAX_TIMEOUT, FALSE);
	if(status != CSL_SOK)
	{
		printf("I2C Read Failed!!\n");
		return(status);
	}

	configOld = i2cReadBuf[0];

/*Read Old Drive*/
	if(0 == port)
	{
		i2cWriteBuf[0] = 0x02; /*Port0 Output Cmd*/
	}
	else if(1 == port)
	{
		i2cWriteBuf[0] = 0x03; /*Port1 Output Cmd*/
	}
	{ Uint16 delay; for(delay=0; delay<0xFFFF; delay++);}
	status = I2C_write(i2cWriteBuf, 1, CSL_I2C_TCA6416_ADDR,
						TRUE, ((CSL_I2C_START) | (CSL_I2C_STOP)),
						CSL_I2C_MAX_TIMEOUT);
	if(status != CSL_SOK)
	{
		printf("I2C Write Failed!!\n");
		return(status);
	}

	{ Uint16 delay; for(delay=0; delay<0xFFFF; delay++);}
	status = I2C_read(i2cReadBuf, 1, CSL_I2C_TCA6416_ADDR,
	                   TRUE, ((CSL_I2C_START) | (CSL_I2C_STOP)),
	                   CSL_I2C_MAX_TIMEOUT, FALSE);
	if(status != CSL_SOK)
	{
		printf("I2C Read Failed!!\n");
		return(status);
	}

	driveOld = i2cReadBuf[0];

/*Configure pin as OUT*/
	if(0 == port)
	{
		i2cWriteBuf[0] = 0x06; /*Port0 Config Cmd*/
	}
	else if(1 == port)
	{
		i2cWriteBuf[0] = 0x07; /*Port1 Config Cmd*/
	}
	i2cWriteBuf[1] = configOld;
	i2cWriteBuf[1] &= (~((Uint16)0x1 << pin)); /*1-IN, 0-OUT*/;
	{ Uint16 delay; for(delay=0; delay<0xFFFF; delay++);}
	status = I2C_write(i2cWriteBuf, 2, CSL_I2C_TCA6416_ADDR,
						TRUE, ((CSL_I2C_START) | (CSL_I2C_STOP)),
						CSL_I2C_MAX_TIMEOUT);
	if(status != CSL_SOK)
	{
		printf("I2C Write Failed!!\n");
		return(status);
	}

/*Drive pin*/
	if(0 == port)
	{
		i2cWriteBuf[0] = 0x02; /*Port0 Output Cmd*/
	}
	else if(1 == port)
	{
		i2cWriteBuf[0] = 0x03; /*Port1 Output Cmd*/
	}
	i2cWriteBuf[1] = driveOld;
	if(wValue)
		i2cWriteBuf[1] |= ((Uint16)0x1 << pin);
	else
		i2cWriteBuf[1] &= (~((Uint16)0x1 << pin));

	{ Uint16 delay; for(delay=0; delay<0xFFFF; delay++);}
	status = I2C_write(i2cWriteBuf, 2, CSL_I2C_TCA6416_ADDR,
						TRUE, ((CSL_I2C_START) | (CSL_I2C_STOP)),
						CSL_I2C_MAX_TIMEOUT);
	if(status != CSL_SOK)
	{
		printf("I2C Write Failed!!\n");
		return(status);
	}

	return status;
}


