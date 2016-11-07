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






// Initialize



Int16 data1, data2, data3, data4;
Int16 k;

//FIR
#define N 255

Int16 x[N];
Int16 b[N];
Int16 y[N];
Int16 i = 0;

void CPFIR(Int16 *x, Int16 *b, Int16 order, Int16 *y, Int16 index);
void initAll(void);

void main( void )
{
    /* Initialize Board and Codec - look in "aic3204_setup.h" */
    USBSTK5515_init( );
	codec_init ();
	initAll();

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
<<<<<<< HEAD
      	        //asm(" bset XF");
      	        asm(" bclr XF");
      	        
      	        if(i == N)
      	        {
      	        	i = -1;
      	        }
      	        x[i] = data3;
      	        i++;
      	        
       	        //CPFIR(x,b,N,y,i);
      	        
      	                
=======
      	        asm(" bset XF");
>>>>>>> 7e2ebba7f949dca56dbb8ebe5e268c0cbf0fc33e
				/* Write Digital audio */
      	        while((Xmit & I2S0_IR) == 0);  // Wait for interrupt pending flag
      	        asm(" bclr XF");
				I2S0_W0_MSW_W = data3;  // 16 bit left channel transmit audio data
      	        I2S0_W0_LSW_W = 0;
      	        I2S0_W1_MSW_W = data4;  // 16 bit right channel transmit audio data
      	        I2S0_W1_LSW_W = 0;
      	        
			}
}

void initAll(void)
{
	Int16 cnt;
	// Clear array
	for(cnt=0;cnt<=N;cnt++) 
	{
		x[cnt] = 0;
		b[cnt] = 0;
		y[cnt] = 0;	
	}	
}
