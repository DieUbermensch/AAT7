//    
//  Project: Experiment 1.6.6 Loopback - Chapter 1    
//  File name: loopback.c      
//   
//  Description: This function is an example of looping audio on the C5510 DSK.   
//               This function is modified from the DSK tone example.   
//   
//  For the book "Real Time Digital Signal Processing:    
//                Implementation and Application, 2nd Ed"   
//                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian   
//                Publisher: John Wiley and Sons, Ltd   
//   
//  Tools used: CCS v.2.12.07   
//              TMS320VC5510 DSK Rev-C   
//   
   
   
/*  
 *  Copyright 2002 by Spectrum Digital Incorporated.  
 *  All rights reserved. Property of Spectrum Digital Incorporated.  
 */   
   
/*  
 *  DSP/BIOS is configured using the DSP/BIOS configuration tool.  Settings  
 *  for this example are stored in a configuration file called tone.cdb.  At  
 *  compile time, Code Composer will auto-generate DSP/BIOS related files  
 *  based on these settings.  A header file called tonecfg.h contains the  
 *  results of the autogeneration and must be included for proper operation.  
 *  The name of the file is taken from tone.cdb and adding cfg.h.  
 */   
//#include "loopbackcfg.h"   
   
/*  
 *  The 5510 DSK Board Support Library is divided into several modules, each  
 *  of which has its own include file.  The file dsk5510.h must be included  
 *  in every program that uses the BSL.  This example also includes  
 *  dsk5510_aic23.h because it uses the AIC23 codec module.  
 */   
#include "dsk5510.h"   
#include "dsk5510_aic23.h"   
//#include "dsk5510_dma_aic23.h"
   
/* Codec configuration settings */   
DSK5510_AIC23_Config config = {    
  0x0017,  /* 0 DSK5510_AIC23_LEFTINVOL  Left line input channel volume */    
  0x0017,  /* 1 DSK5510_AIC23_RIGHTINVOL Right line input channel volume */   
  0x01f9,  /* 2 DSK5510_AIC23_LEFTHPVOL  Left channel headphone volume */     
  0x01f9,  /* 3 DSK5510_AIC23_RIGHTHPVOL Right channel headphone volume */    
  0x0011,  /* 4 DSK5510_AIC23_ANAPATH    Analog audio path control */         
  0x0000,  /* 5 DSK5510_AIC23_DIGPATH    Digital audio path control */        
  0x0000,  /* 6 DSK5510_AIC23_POWERDOWN  Power down control */                
  0x0043,  /* 7 DSK5510_AIC23_DIGIF      Digital audio interface format */    
  0x0081,  /* 8 DSK5510_AIC23_SAMPLERATE Sample rate control */               
  0x0001   /* 9 DSK5510_AIC23_DIGACT     Digital interface activation */      
};   
   
/*  
 *  main() - Main code routine, initializes BSL and generates tone  
 */   
   
void main()   
{   
  DSK5510_AIC23_CodecHandle hCodec;   
  Uint16 i,j;   
  Int16  left,right;       
       
  // Initialize the board support library, must be called first   
  DSK5510_init();   
   
  // Start the codec   
  hCodec = DSK5510_AIC23_openCodec(0, &config);   
           
  // Loop back line-in audio for 30 seconds at 48kHz sampling rate   
  for (i = 0; i < 30; i++)   
  {   
    for (j = 0; j < 48000; j++)   
    {       
      // Read a sample from the left input channel    
      while (DSK5510_AIC23_read16(hCodec, &left));   
      // Read a sample from the right input channel   
      while (!DSK5510_AIC23_read16(hCodec, &right));      
               
      // Write a sample to the left output channel   
      while (DSK5510_AIC23_write16(hCodec, left));   
      // Write a sample to the right output channel   
      while (!DSK5510_AIC23_write16(hCodec, right));   
    }       
  }   
   
  // Close the codec   
  DSK5510_AIC23_closeCodec(hCodec);   
} 
