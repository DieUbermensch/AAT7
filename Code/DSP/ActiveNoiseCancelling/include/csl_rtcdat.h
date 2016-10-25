/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... RTC
* FILENAME...... csl_rtcdat.h
* DATE CREATED.. Thu 02/20/2001
* PROJECT....... Chip Support Library
* COMPONENT..... CSL service layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   MODIFIED: 10 April 2003 added reference for CSL_RtcData for .csldata size fix
*   
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the RTC module)
*       Reserved ROM Area for RTC Data 
*
*
\******************************************************************************/
#ifndef _CSL_RTC_DATA_H_
#define _CSL_RTC_DATA_H_

  #include <csl_std.h>
  #include <csl_time.h>

  #define CSL_RTCDATAINIT\
  { "Sun","Mon","Tue","Wed","Thu","Fri","Sat",   /* day */\
    "Jan","Feb","Mar","Apr","May","Jun",         /* mon */\
    "Jul","Aug","Sep","Oct","Nov","Dec",\
     31,28,31,30,31,30,31,31,30,31,30,31,        /* mon_len */\
     0,31,59,90,120,151,181,212,243,273,304,334, /* mon_day */\
     "Sunday","Monday","Tuesday","Wednesday",    /* fday    */\
     "Thursday","Friday","Saturday",\
     "January","February","March","April","May", /* fmon    */\
     "June", "July","August","September",\
     "October","November", "December",\
     0,                                          /* daylight */\
     21600,                                      /* timezone */\
     "CST",                                      /* tzname   */\
     "DST",                                      /* dstname  */\
     0x00000000u,\
     0x00000000u,\
     0x00000000u,\
     0x00000000u,\
     0x00000000u\
  }

  

  typedef struct {
   char *day[7];
   char *mon[12];
   Uint16 mon_len[12];
   Uint16 mon_day[12];
   char *fday[7];
   char *fmon[12];
   TZ   _tz;
   Uint32 RTC_isrDispatchTable[5];
  } CSL_RtcDataObj;

extern CSL_RtcDataObj  CSL_RtcData;

#define CSL_RTC_DATA   CSL_RtcData

#endif
