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

//#include "i2s.h"
//#include "data_types.h"
//#include "register_system.h"
//#include "register_cpu.h"
//#include "rtc.h"
//#include "control.h"
//#include "dma.h"





// Initialize
void initAll(void);
Int16 data1 = 0, data2 = 0, data3 = 0, data4 = 0;

//FIR
extern Int16 FIR(Int16 *x, Int16 *b, Int16 order, Int16 index);
#define N 16
Int16 x[N];
//Int16 b[] = {0xCCD,0xCCD,0xCCD,0xCCD,0xCCD,0xCCD,0xCCD,0xCCD,0xCCD,0xCCD};
//Int16 b[] = {0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000}; //Passthrough filter
Int16 b[] = {0x709,0x737,0x760,0x783,0x7A1,0x7B8,0x7C8,0x7D2,0x7D5,0x7D2,0x7C8,0x7B8,0x7A1,0x783,0x760,0x737,0x709}; //Ref Filter

Int16 y[N];
Int16 i = 0;

//FXLMS
extern void  FXLMS(Int16 *x, Int16 *b, Int16 error, Int16 index, Int16 *uN );
#define NLMS 5
Int16 xLMS[NLMS] = {0x4000,0,0,0,0};
Int16 bLMS[NLMS] = {0x4000,2,3,4,5};
Int16 u = 1; //Is multiplied in initialize function
Int16 iLMS = 0;
Int16 e = 1;
Int16 constants[2];


void main( void )
{
    /* Initialize Board and Codec - look in "aic3204_setup.h" */
    USBSTK5515_init();
	codec_init ();
	initAll();
            while ( 1 )
            {
            	/* Read Digital audio */
            	while((Rcv & I2S0_IR) == 0);  // Wait for interrupt pending flag
                data3 = I2S0_W0_MSW_R;  // 16 bit left channel received audio data
      	        data1 = I2S0_W0_LSW_R;
      	        data4 = I2S0_W1_MSW_R;  // 16 bit right channel received audio data
      	        data2 = I2S0_W1_LSW_R;

      	        //asm(" bset XF");
      	        /* Signal processing */
      	        asm(" bclr XF");
      	        
      	        if(i == N)
      	        {
      	        	i = 0;
      	        	iLMS = 0;
      	        }
      	        x[i] = data3;
       	        y[i] = FIR(x,b,N,i);
       	        FXLMS(x, b, 1, NLMS, constants);
       	        data3 = y[i];
       	        data4 = y[i];      	               
       	        i++;
       	        iLMS++;
      	        asm(" bset XF");





				/* Write Digital audio */
      	        //while((Xmit & I2S0_IR) == 0);  // Wait for interrupt pending flag
      	        asm(" bclr XF");
				I2S0_W0_MSW_W = y[i-1];  // 16 bit left channel transmit audio data
      	        I2S0_W0_LSW_W = 0;
      	        I2S0_W1_MSW_W = y[i-1];  // 16 bit right channel transmit audio data
      	        I2S0_W1_LSW_W = 0;
      	        
			}
}

void initAll(void)
{
	Int16 cnt;
	// Clear arrays
	for(cnt=0;cnt<N;cnt++) 
	{
		x[cnt] = 0;
		y[cnt] = 0;	
	}	
	for(cnt=0;cnt<NLMS;cnt++) 
	{
		//xLMS[cnt] = 0;
		//bLMS[cnt] = 0;	
	}	
	u = -2*u;
	constants[0] = u;
	constants[1] = NLMS;
}
