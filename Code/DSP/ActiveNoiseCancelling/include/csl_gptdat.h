/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... TIMER
* FILENAME...... csl_gptdat.h
* DATE CREATED.. Thu 03/30/2000 
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... CSL service layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:       03/30/2000
*   LAST MODIFIED: 04/16/2001 updated FILENAME and other header comments 
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the TIMER module)
*       Reserved Area for TIMER Data 
*
*
\******************************************************************************/
#ifndef _GPT_DATA_H_
#define _GPT_DATA_H_

#include <csl_std.h>

#define __GPT_DEVICE_CNT           2

/* private object, not to be used by application code */
typedef struct {
	volatile Uint16 gptpid1;
	volatile Uint16 gptpid2;
	volatile Uint16 gptemu;
	volatile Uint16 gptclk;
	volatile Uint16 gptgpint;
	volatile Uint16 gptgpen;
	volatile Uint16 gptgpdir;
	volatile Uint16 gptgpdat;
	volatile Uint16 gptcnt1;
	volatile Uint16 gptcnt2;
	volatile Uint16 gptcnt3;
	volatile Uint16 gptcnt4;
	volatile Uint16 gptprd1;
	volatile Uint16 gptprd2;
	volatile Uint16 gptprd3;
	volatile Uint16 gptprd4;
	volatile Uint16 gptctl1;
	volatile Uint16 gptctl2;
	volatile Uint16 gptgctl1;
} GPT_RegObj, *GPT_RegPtr;


typedef struct {
  Uint16  devNum;
  Uint16  EventId;
  GPT_RegPtr  regs;
} GPT_PrivateObj, *GPT_Handle;
 

// The following addresses are incorrect for GPT
// timer registers... these were altered to allow
// use of simulator for testing purposes.
// These definitions need t obe returned to their
// correct values of 0x1000 and 0x2400 respectively
// when simulator is no longer used as the test bed.

#define CSL_GPTDATAINIT\
{/*Timer #0 Handle Initialization Data*/\
  0x0000u,  /*TIMER0_Timer*/\
  0x0004u,  /*TIMER0_EventId*/\
 (GPT_RegPtr)0x1000u,   /* TIMER0_PID1Addr */\
/*Timer #1 Handle Initialization Data*/\
  0x0001u,  /*TIMER1_Timer*/\
  0x0016u,  /*TIMER1_EventId*/\
 (GPT_RegPtr)0x2400u,   /* TIMER1_PID1Addr */\
}

typedef struct {
  GPT_PrivateObj Gpt[__GPT_DEVICE_CNT];
} CSL_GptDataObj;

extern CSL_GptDataObj CSL_GptData;

#define CSL_GPT_DATA  CSL_GptData

#endif
