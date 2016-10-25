/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... TIMER
* FILENAME...... csl_timdat.h
* DATE CREATED.. Thu 03/30/2000 
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... CSL service layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:       03/30/2000
*   LAST MODIFIED: 04/16/2001 updated FILENAME and other header comments 
*   MODIFIED:      10 Apr 2003 Added CSL_TimerData reference for .csldata size fix
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the TIMER module)
*       Reserved Area for TIMER Data 
*
*
\******************************************************************************/
#ifndef _TIMER_DATA_H_
#define _TIMER_DATA_H_

#include <csl_std.h>

#define TIMER_DEVICE_CNT           2

#define CSL_TIMERDATAINIT\
{/*Timer #0 Handle Initialization Data*/\
  0x0000u,  /*TIMER0_Timer*/\
  0x0004u,  /*TIMER0_EventId*/\
  0x1002u,  /*TIMER0_TcrAddr*/\
  0x1001u,  /*TIMER0_PrdAddr*/\
  0x1000u,  /*TIMER0_TimAddr*/\
  0x1003u,  /*TIMER0_PrscAddr*/\
/* Timer #1 Handle Initialization Data*/\
  0x0001u,  /*TIMER1_Timer*/\
  0x0016u,  /*TIMER1_EventId*/\
  0x2402u,  /*TIMER1_TcrAddr*/\
  0x2401u,  /*TIMER1_PrdAddr*/\
  0x2400u,  /*TIMER1_TimAddr*/\
  0x2403u  /*TIMER1_PrscAddr*/\
}

/* private object, not to be used by application code */
typedef struct {
  Uint16  Timer;
  Uint16  EventId;
  Uint16  TcrAddr;
  Uint16  PrdAddr;
  Uint16  TimAddr;
  Uint16  PrscAddr;
} TIMER_PrivateObj;

typedef struct {
  TIMER_PrivateObj Timer[TIMER_DEVICE_CNT];
} CSL_TimerDataObj;

extern CSL_TimerDataObj  CSL_TimerData;

#define CSL_TIMER_DATA   CSL_TimerData

#endif
