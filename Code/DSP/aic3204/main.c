/*
 *  Basic coded setup
 *  Author: Group 761
 */

// Define address for the board
#define AIC3204_I2C_ADDR 0x18
#define Rcv 0x08
#define Xmit 0x20


// Setup files - dont touch! 
#include "stdio.h"
#include "usbstk5515.h"
#include "usbstk5515_gpio.h"
#include "usbstk5515_i2c.h"
#include "aic3204_setup.h"










Int16 data1, data2, data3, data4;
Int16 k;
void main( void )
{
    /* Initialize Board and Codec - look in "aic3204_setup.h" */
    USBSTK5515_init( );
	codec_init ();

            while ( 1 )
            {
            	if (I2S0_IR == 0)
            	/* Read Digital audio */
            	while((Rcv & I2S0_IR) == 0);  // Wait for interrupt pending flag
                k=100;
                data3 = I2S0_W0_MSW_R;  // 16 bit left channel received audio data
      	        data1 = I2S0_W0_LSW_R;
      	        data4 = I2S0_W1_MSW_R;  // 16 bit right channel received audio data
      	        data2 = I2S0_W1_LSW_R;
      	        //asm(" bset XF");
      	        asm(" bclr XF");
				/* Write Digital audio */
      	        while((Xmit & I2S0_IR) == 0);  // Wait for interrupt pending flag
				I2S0_W0_MSW_W = data3;  // 16 bit left channel transmit audio data
      	        I2S0_W0_LSW_W = 0;
      	        I2S0_W1_MSW_W = data4;  // 16 bit right channel transmit audio data
      	        I2S0_W1_LSW_W = 0;
      	        
    
			}
}
