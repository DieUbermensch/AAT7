/****************************************************************************\
*           Copyright (C) 1999-2001 Texas Instruments Incorporated.
*                           All Rights Reserved 
*------------------------------------------------------------------------------
* MODULE NAME... RTC
* FILENAME...... csl_time.h
* DATE CREATED.. Fri Mar 30 2001
* PROJECT....... Chip Support Library
* COMPONENT..... Service Layer
* PREREQUISITS.. 
*------------------------------------------------------------------------------
*
* HISTORY:
*	 Created:		Fri Mar 30 2001 ()
*	 Last Modified:	
*
*------------------------------------------------------------------------------
* DESCRIPTION: CSL Time Functions for the RTC module 
*
\*************************************************************************/

#ifndef _CSL_TIME
#define _CSL_TIME

#include <linkage.h> 
 


#ifndef NULL
#define NULL      0
#endif

#ifdef __cplusplus
extern "C" namespace std {
#endif

typedef unsigned long time_t;

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif /* ! _SIZE_T */

struct tm 
{
    int tm_sec;      /* seconds after the minute   - [0,59]  */
    int tm_min;      /* minutes after the hour     - [0,59]  */
    int tm_hour;     /* hours after the midnight   - [0,23]  */
    int tm_mday;     /* day of the month           - [1,31]  */
    int tm_mon;      /* months since January       - [0,11]  */
    int tm_year;     /* years since 1900                     */
    int tm_wday;     /* days since Sunday          - [0,6]   */
    int tm_yday;     /* days since Jan 1st         - [0,365] */
    int tm_isdst;    /* Daylight Savings Time flag           */
};

/*************************************************************************/
/* TIME ZONE STRUCTURE DEFINITION                                        */
/*************************************************************************/
typedef struct 
{
    short daylight;
    long  timezone;
    char  tzname[4];
    char  dstname[4];
} TZ;

extern _DATA_ACCESS TZ _tz;

/****************************************************************************/
/* FUNCTION DECLARATIONS.  (NOTE : clock AND time ARE SYSTEM SPECIFIC)      */
/****************************************************************************/
_CODE_ACCESS time_t     RTC_time(time_t *_timer);     
 
_CODE_ACCESS time_t     RTC_mktime(struct tm *_tptr);
_CODE_ACCESS double     RTC_difftime(time_t _time1, time_t _time0);
      _IDECL char      *RTC_ctime(const time_t *_timer);
_CODE_ACCESS char      *RTC_asctime(const struct tm *_timeptr);
_CODE_ACCESS struct tm *RTC_gmtime(const time_t *_timer);
_CODE_ACCESS struct tm *RTC_localtime(const time_t *_timer);
_CODE_ACCESS size_t     RTC_strftime(char *_out, size_t _maxsize, 
				 const char *_format,
				 const struct tm *_timeptr);

#if defined(_INLINE) || defined(_CTIME_)

_IDEFN char *RTC_ctime(const time_t *timer)
{
   return(RTC_asctime(RTC_localtime(timer)));
}

#endif /* _INLINE || _CTIME_ */

#ifdef __cplusplus
} /* extern "C" */

#ifndef _CPP_STYLE_HEADER
using std::time_t;
using std::size_t;
using std::tm;
using std::TZ;
using std::_tz;
using std::RTC_time;
using std::RTC_mktime;
using std::RTC_difftime;
using std::RTC_ctime;
using std::RTC_asctime;
using std::RTC_gmtime;
using std::RTC_localtime;
using std::RTC_strftime;
#endif /* ! _CPP_STYLE_HEADER */

#endif /* __cplusplus */
 
 
#endif /* _TIME */

