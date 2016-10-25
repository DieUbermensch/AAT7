/****************************************************************************\
*           Copyright (C) 1999-2001 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... RTC
* FILENAME...... csl_rtc.h
* DATE CREATED.. Thu Feb  1 10:52:13 2001
* PROJECT....... Chip Support Library
* COMPONENT..... Service Layer
* PREREQUISITS..
*------------------------------------------------------------------------------
*
* HISTORY:
*	 Created:	Thu Feb  1 10:52:13 2001 (Automatic generation)
*	 3/30/2001	Modified to fix midnight bug (IM)
*	 Modified:  4/11/2001 (IM) Changed to reflect the changes in the RTC documentation version 2.8
*	 Modified:	7/20/2001 (IM) changed some names
*	 Modified:	7/20/2001 (IM) Removed 2nd and 3rd argument from setCallback function
*    Modified:	7/20/2001 (IM) Added RTC_stop() function
*    Modified:  7/03/2003  Renamed the variable names from 'new' to 'val' to
*                            avoid C++ compile time erros.
*    Modified:  9/17/2003  Modified RTC_decToBcd() and RTC_bcdToDec()
*                            to avoid rts55 library calls.
*            : 12/02/2003  Added inline definitions for eventEnable and 
*                            eventDisable APIs for inlining, added underscore
*                            '_' prefix for private API
*------------------------------------------------------------------------------
* DESCRIPTION: CSL Service Layer interface for the RTC module
*
\*************************************************************************/

#ifndef _CSL_RTC_H_
#define _CSL_RTC_H_

#include <_csl.h>
#include <csl_rtcdat.h>
#include <csl_rtchal.h>

#if (_RTC_SUPPORT) 

/*----------------------------------------------------------------*\
*	 RTC scope and inline control macros 			
\*----------------------------------------------------------------*/

#ifdef __cplusplus
#define CSLAPI extern "C"
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _RTC_MOD_
  #define IDECL CSLAPI
  #define IDEF
#else
  #ifdef  _INLINE
    #define IDECL static inline
    #define USEDEFS
    #define IDEF  static inline
  #else
    #define IDECL CSLAPI
 #endif
#endif

/****************************************\
* RTC global macro declarations
\****************************************/

/* error codes */
#define RTC_ERR_MAJOR		   (ERR_BASE_RTC) 
#define RTC_ERR_ALLOC		   (0x00000000) 
#define RTC_ERR_INVALID_HANDLE  (0x00000001) 


/********************************************\
	Periodic interrupt Rates (Register A)
\********************************************/
#define RTC_RTCPINTR_UIP_NO       (0x00u)
#define RTC_RTCPINTR_UIP_YES      (0x01u)

#define RTC_RATE_NONE      0x0000
#define RTC_RATE_122us     0x0003
#define RTC_RATE_244us     0x0004
#define RTC_RATE_488us     0x0005
#define RTC_RATE_976us     0x0006
#define RTC_RATE_1_95ms    0x0007
#define RTC_RATE_3_9ms     0x0008
#define RTC_RATE_7_8125ms  0x0009
#define RTC_RATE_15_625ms  0x000A
#define RTC_RATE_31_25ms   0x000B
#define RTC_RATE_62_5ms    0x000C
#define RTC_RATE_125ms     0x000D
#define RTC_RATE_250ms     0x000E
#define RTC_RATE_500ms     0x000F
#define RTC_RATE_1min      0x001F

#define DONTCARE		   0xFF
/********************************************\
	RTC time of day (AM/PM bits in RTCHOUR and RTCHOURA registers)
\********************************************/
/*
#define AM		0
#define PM		1

*/

/* ============================================================== */
 /* Make RTCDAYW register values based on symbolic constants  */

#define RTC_RTCDAYW_RMK(dar,daen,day)\
 ((Uint16) ( \
  ( RTC_FMK(RTCDAYW,DAR,dar))|\
  ( RTC_FMK(RTCDAYW,DAEN,daen))|\
  ( RTC_FMK(RTCDAYW,DAY,day))\
)\
 )

#define RTC_RTCDAYW_RMKS(dar_sym,daen_sym,day_sym)\
 ((Uint16) ( \
  ( RTC_FMKS(RTCDAYW,DAR,dar_sym))|\
  ( RTC_FMKS(RTCDAYW,DAEN,daen_sym))|\
  ( RTC_FMKS(RTCDAYW,DAY,day_sym))\
)\
 )

/*  Default RTCDAYW register value  */

/*  RTCDAYW field values  */

#define RTC_RTCDAYW_DAY_OF(x)         ((Uint16)(x))
#define RTC_RTCDAYW_DAR_OF(x)         ((Uint16)(x))
#define RTC_RTCDAYW_DAEN_ENABLE       (0x01u)
#define RTC_RTCDAYW_DAEN_DISABLE      (0x00u)


/* ============================================================== */
 /* Make RTCHOUR register values based on symbolic constants  */

#define RTC_RTCHOUR_RMK(ampm,hr)\
 ((Uint16) ( \
  ( RTC_FMK(RTCHOUR,AMPM,ampm))|\
  ( RTC_FMK(RTCHOUR,HR,hr))\
)\
 )

#define RTC_RTCHOUR_RMKS(ampm_sym,hr_sym)\
 ((Uint16) ( \
  ( RTC_FMKS(RTCHOUR,AMPM,ampm_sym))|\
  ( RTC_FMKS(RTCHOUR,HR,hr_sym))\
)\
 )

/*  Default RTCHOUR register value  */

/*  RTCHOUR field values  */

#define RTC_RTCHOUR_AMPM_AM           (0x00u)
#define RTC_RTCHOUR_AMPM_PM           (0x01u)
#define RTC_RTCHOUR_HR_OF(x)          ((Uint16)(x))

/* ============================================================== */
 /* Make RTCHOURA register values based on symbolic constants  */

#define RTC_RTCHOURA_RMK(ampm,har)\
 ((Uint16) ( \
  ( RTC_FMK(RTCHOURA,AMPM,ampm))|\
  ( RTC_FMK(RTCHOURA,HAR,har))\
)\
 )

#define RTC_RTCHOURA_RMKS(ampm_sym,har_sym)\
 ((Uint16) ( \
  ( RTC_FMKS(RTCHOURA,AMPM,ampm_sym))|\
  ( RTC_FMKS(RTCHOURA,HAR,har_sym))\
)\
 )

/*  Default RTCHOURA register value  */

/*  RTCHOURA field values  */

#define RTC_RTCHOURA_AMPM_AM           (0x00u)
#define RTC_RTCHOURA_AMPM_PM           (0x01u)
#define RTC_RTCHOURA_HAR_OF(x)         ((Uint16)(x))

/* ============================================================== */
 /* Make RTCINTEN register values based on symbolic constants  */

#define RTC_RTCINTEN_RMK(set,pie,aie,uie,tm)\
 ((Uint16) ( \
  ( RTC_FMK(RTCINTEN,SET,set))|\
  ( RTC_FMK(RTCINTEN,PIE,pie))|\
  ( RTC_FMK(RTCINTEN,AIE,aie))|\
  ( RTC_FMK(RTCINTEN,UIE,uie))|\
  ( RTC_FMK(RTCINTEN,TM,tm))\
)\
 )

#define RTC_RTCINTEN_RMKS(set_sym,pie_sym,aie_sym,uie_sym,tm_sym)\
 ((Uint16) ( \
  ( RTC_FMKS(RTCINTEN,SET,set_sym))|\
  ( RTC_FMKS(RTCINTEN,PIE,pie_sym))|\
  ( RTC_FMKS(RTCINTEN,AIE,aie_sym))|\
  ( RTC_FMKS(RTCINTEN,UIE,uie_sym))|\
  ( RTC_FMKS(RTCINTEN,TM,tm_sym))\
)\
 )

/*  Default RTCINTEN register value  */

/*  RTCINTEN field values  */

#define RTC_RTCINTEN_SET_OFF			(0x00u)
#define RTC_RTCINTEN_SET_ON			(0x01u)
#define RTC_RTCINTEN_PIE_DISABLE		(0x00u)
#define RTC_RTCINTEN_PIE_ENABLE		(0x01u)
#define RTC_RTCINTEN_AIE_DISABLE		(0x00u)
#define RTC_RTCINTEN_AIE_ENABLE		(0x01u)
#define RTC_RTCINTEN_UIE_DISABLE		(0x00u)
#define RTC_RTCINTEN_UIE_ENABLE		(0x01u)
#define RTC_RTCINTEN_TM_12HMODE		(0x00u)
#define RTC_RTCINTEN_TM_24HMODE		(0x01u)
#define RTC_RTCINTEN_TM_DEFAULT		RTC_RTCINTEN_TM_24HMODE

/* ============================================================== */
 /* Make RTCINTFL register values based on symbolic constants  */

#define RTC_RTCINTFL_RMK(pf,af,uf)\
 ((Uint16) ( \
  ( RTC_FMK(RTCINTFL,PF,pf))|\
  ( RTC_FMK(RTCINTFL,AF,af))|\
  ( RTC_FMK(RTCINTFL,UF,uf))\
)\
 )

#define RTC_RTCINTFL_RMKS(pf_sym,af_sym,uf_sym)\
 ((Uint16) ( \
  ( RTC_FMKS(RTCINTFL,PF,pf_sym))|\
  ( RTC_FMKS(RTCINTFL,AF,af_sym))|\
  ( RTC_FMKS(RTCINTFL,UF,uf_sym))\
)\
 )

/*  Default RTCINTFL register value  */

/*  RTCINTFL field values  */

#define RTC_RTCINTFL_IRQF_NO		(0x00u)
#define RTC_RTCINTFL_IRQF_YES		(0x01u)
#define RTC_RTCINTFL_PF_NO		(0x00u)
#define RTC_RTCINTFL_PF_YES		(0x01u)
#define RTC_RTCINTFL_AF_NO		(0x00u)
#define RTC_RTCINTFL_AF_YES		(0x01u)
#define RTC_RTCINTFL_UF_NO		(0x00u)
#define RTC_RTCINTFL_UF_YES		(0x01u)


/* ============================================================== */
	/* Macros for periodic alarms */

#define _SET_B		RTC_FSET(RTCINTEN,SET,1)		/* Set bit SET in Register B to 1 */  
#define _RESET_B		RTC_FSET(RTCINTEN,SET,0)		/* Set bit SET in Register B to 0 */  


/* ============================================================== */


/*************************************************\
 RTC global typedef declarations 
\*************************************************/

typedef struct {
	Uint16 rtcsec;
	Uint16 rtcseca;
	Uint16 rtcmin;
	Uint16 rtcmina;
	Uint16 rtchour;
	Uint16 rtchoura;
	Uint16 rtcdayw;
	Uint16 rtcdaym;
	Uint16 rtcmonth;
	Uint16 rtcyear;
	Uint16 rtcpintr;
	Uint16 rtcinten;
      Uint16 rtcintfl;
} RTC_Config;

typedef struct {
	Uint16 year;
	Uint16 month;
	Uint16 daym;
	Uint16 dayw;
} RTC_Date;

typedef struct {
	Uint16 hour;
	Uint16 minute;
	Uint16 second;
} RTC_Time;


typedef struct {
	Uint16 alhour;
	Uint16 alminute;
	Uint16 alsecond;
	Uint16 aldayw;
} RTC_Alarm;

/*************** Declarations for interrupt routines ******************/
typedef struct 
{ 
   void (*periodicAddr)(void);          // Periodic interrupt
   void (*alarmAddr)(void);         // Alarm interrupt
   void (*updateAddr)(void);         // update ended
} RTC_IsrAddr; 

#define    RTC_EVT_PERIODIC   (Uint16)0x40     // Periodic Interrupt Enable
#define    RTC_EVT_ALARM   	(Uint16)0x20     // Alarm Interrupt Enable
#define    RTC_EVT_UPDATE  	(Uint16)0x10     // Update Ended Interrupt

/*************** End Declarations for interrupt routines ******************/

/*************************************************\
* RTC global variable declarations
\*************************************************/


/*************************************************\
* RTC global function declarations
\*************************************************/

IDECL void RTC_config(RTC_Config *Config);

IDECL void RTC_configArgs(Uint16 rtcsec,Uint16 rtcseca,Uint16 rtcmin,Uint16 rtcmina,Uint16 rtchour,Uint16 rtchoura,Uint16 rtcdayw,
				   Uint16 rtcdaym,Uint16 rtcmonth,Uint16 rtcyear,Uint16 rtcpintr,Uint16 rtcinten);

IDECL void RTC_getConfig(RTC_Config *Config);

IDECL void RTC_setTime(RTC_Time *myTime);
IDECL void RTC_getTime(RTC_Time *myTime);
IDECL void RTC_setDate(RTC_Date *myDate);
IDECL void RTC_getDate(RTC_Date *myDate);

IDECL void RTC_setPeriodicInterval(Uint16 interval); /* Set periodic interrupt rate (see RS table) */
IDECL void RTC_setAlarm(RTC_Alarm *myAlarm);	/* Set alarm at a specific time: sec, min, hour, day of week */

IDECL int RTC_getEventId();
IDECL void RTC_eventEnable(Uint16 isrMask);
IDECL void RTC_eventDisable(Uint16 ierMask);
IDECL void RTC_start();
IDECL void RTC_stop();

IDECL int RTC_decToBcd(int dec_value);
IDECL int RTC_bcdToDec(int hex_value);

CSLAPI void RTC_setCallback(RTC_IsrAddr *isrAddr);
CSLAPI void RTC_reset();

/***** private function *****/
interrupt void _RTC_intrDispatch(void);

/*************************************************\
* RTC inline function declarations
\*************************************************/

#ifdef USEDEFS

IDEF void RTC_config(RTC_Config *Config) {
  int old_intm;

  old_intm = IRQ_globalDisable();  

  RTC_RSET(RTCINTFL,0x70);			/* Clear flags in Register C */
  _SET_B;			/* Set bit SET in Register B to 1 */  

/* Set Data registers */
  RTC_RSET(RTCSEC,Config->rtcsec);
  RTC_RSET(RTCSECA,Config->rtcseca);
  RTC_RSET(RTCMIN,Config->rtcmin);
  RTC_RSET(RTCMINA,Config->rtcmina);
  RTC_RSET(RTCHOUR,Config->rtchour);
  RTC_RSET(RTCHOURA,Config->rtchoura);
  RTC_RSET(RTCDAYW,Config->rtcdayw);
  RTC_RSET(RTCDAYM,Config->rtcdaym);
  RTC_RSET(RTCMONTH,Config->rtcmonth);
  RTC_RSET(RTCYEAR,Config->rtcyear);    
  
  RTC_RSET(RTCPINTR,Config->rtcpintr);	/* Set Register A */
  RTC_RSET(RTCINTEN,Config->rtcinten);	/* Set Register B */

  IRQ_globalRestore(old_intm);   

}

/*----------------------------------------------------------------------------*/
 IDEF void RTC_getConfig(RTC_Config *Config) {
  int old_intm, old_set;
  old_intm = IRQ_globalDisable();  
  old_set = RTC_FGET(RTCINTEN, SET);

  while (RTC_FGET(RTCPINTR,UIP) != 0);

  _SET_B;		 /* Set bit SET in Register B to 1 */

  Config->rtcsec = RTC_RGET(RTCSEC);
  Config->rtcseca = RTC_RGET(RTCSECA);
  Config->rtcmin = RTC_RGET(RTCMIN);
  Config->rtcmina = RTC_RGET(RTCMINA);  
  Config->rtchour = RTC_RGET(RTCHOUR);
  Config->rtchoura = RTC_RGET(RTCHOURA);
  Config->rtcdayw = RTC_RGET(RTCDAYW);
  Config->rtcdaym = RTC_RGET(RTCDAYM);
  Config->rtcmonth = RTC_RGET(RTCMONTH);
  Config->rtcyear = RTC_RGET(RTCYEAR);
  Config->rtcpintr = RTC_RGET(RTCPINTR);
  Config->rtcinten = RTC_RGET(RTCINTEN);

  RTC_FSET(RTCINTEN, SET, old_set);

  IRQ_globalRestore(old_intm);   
}            

/*----------------------------------------------------------------------------------------------*/
IDEF void RTC_configArgs(Uint16 rtcsec,Uint16 rtcseca,Uint16 rtcmin,Uint16 rtcmina,Uint16 rtchour,Uint16 rtchoura,Uint16 rtcdayw,
				   Uint16 rtcdaym,Uint16 rtcmonth,Uint16 rtcyear,Uint16 rtcpintr,Uint16 rtcinten)
{
  int old_intm;

   old_intm = IRQ_globalDisable(); 
    
  RTC_RSET(RTCPINTR,rtcpintr);
  _SET_B; 		 /* Set bit SET in Register B to 1 */  

  RTC_RSET(RTCSEC,rtcsec);
  RTC_RSET(RTCSECA,rtcseca);
  RTC_RSET(RTCMIN,rtcmin);
  RTC_RSET(RTCMINA,rtcmina);
  RTC_RSET(RTCHOUR,rtchour);
  RTC_RSET(RTCHOURA,rtchoura);
  RTC_RSET(RTCDAYW,rtcdayw);
  RTC_RSET(RTCDAYM,rtcdaym);
  RTC_RSET(RTCMONTH,rtcmonth);
  RTC_RSET(RTCYEAR,rtcyear);    
  RTC_RSET(RTCINTEN,rtcinten);
  
  IRQ_globalRestore(old_intm);   
}

/*--------------------------------------------------------------------------------------------*/

IDEF void RTC_setTime(RTC_Time *myTime) {
  /* time is set for the default mode of 24-hour */

  int old_intm;
  old_intm = IRQ_globalDisable();  

  _SET_B; 		 /* Set bit SET in Register B to 1 */  

  RTC_FSET(RTCINTEN, TM, 1);		//Make sure we have time in 24-hour format
  RTC_RSET(RTCSEC,myTime->second); 
  RTC_RSET(RTCMIN,myTime->minute);
  RTC_FSET(RTCHOUR,HR,myTime->hour);
	
  IRQ_globalRestore(old_intm);   

}

/*----------------------------------------------------------------------------*/

IDEF void RTC_getTime(RTC_Time *myTime) {
  int old_intm, old_set;

/* Only a 24-hour mode is supported */

  old_intm = IRQ_globalDisable();  
  old_set = RTC_FGET(RTCINTEN, SET);

  while (RTC_FGET(RTCPINTR,UIP) != 0);

  _SET_B;		 /* Set bit SET in Register B to 1 */

  myTime->second = RTC_RGET(RTCSEC);
  myTime->minute = RTC_RGET(RTCMIN);
  myTime->hour = RTC_FGET(RTCHOUR,HR); 
  
  RTC_FSET(RTCINTEN, SET, old_set);

  IRQ_globalRestore(old_intm);   

}

/*----------------------------------------------------------------------------*/

IDEF void RTC_setDate(RTC_Date *myDate) {
  int old_intm;

  old_intm = IRQ_globalDisable();  

  _SET_B; 		 /* Set bit SET in Register B to 1 */  

  RTC_RSET(RTCYEAR,myDate->year);
  RTC_FSET(RTCMONTH,MONTH,myDate->month);
  RTC_FSET(RTCDAYM,DATE,myDate->daym);
  RTC_FSET(RTCDAYW,DAY,myDate->dayw);

  IRQ_globalRestore(old_intm);   

}

/*----------------------------------------------------------------------------*/

IDEF void RTC_getDate(RTC_Date *myDate) {
  int old_intm, old_set;
  old_intm = IRQ_globalDisable();  
  old_set = RTC_FGET(RTCINTEN, SET);

  while (RTC_FGET(RTCPINTR,UIP) != 0);
  
  myDate->year = RTC_RGET(RTCYEAR);
  myDate->month = RTC_FGET(RTCMONTH,MONTH);
  myDate->daym = RTC_FGET(RTCDAYM,DATE);
  myDate->dayw = RTC_FGET(RTCDAYW,DAY);

  RTC_FSET(RTCINTEN, SET, old_set);

  IRQ_globalRestore(old_intm);   

}

/*----------------------------------------------------------------------------*/

IDEF void RTC_setPeriodicInterval(Uint16 interval) { /* Set periodic interrupt rate (see RS table) */
  int old_intm;
  old_intm = IRQ_globalDisable();  

  RTC_FSET(RTCPINTR,RS,interval);

  IRQ_globalRestore(old_intm);   

}

/*----------------------------------------------------------------------------*/

IDEF void RTC_setAlarm(RTC_Alarm *myAlarm) {
  int old_intm;
  old_intm = IRQ_globalDisable();  

/* Only a 24-hour mode is supported */

  _SET_B; 		 /* Set bit SET in Register B to 1 */  

 // RTC_RSET(RTCSECA,SAR,myAlarm->alsecond); 
 // RTC_RSET(RTCMINA,MAR,myAlarm->alminute);
  RTC_FSET(RTCSECA,SAR,myAlarm->alsecond); 
  RTC_FSET(RTCMINA,MAR,myAlarm->alminute);
  RTC_FSET(RTCHOURA,HAR,myAlarm->alhour);
  RTC_FSET(RTCDAYW,DAEN, 1);
  RTC_FSET(RTCDAYW,DAR,myAlarm->aldayw);

  IRQ_globalRestore(old_intm);   

}

/*----------------------------------------------------------------------------*/
IDEF int RTC_getEventId() {

	return IRQ_EVT_RTC;
}

IDEF void RTC_eventEnable(Uint16 isrMask)
{     Uint16 temp;
	temp = RTC_RGET(RTCINTEN)|(isrMask);
        RTC_RSET(RTCINTEN, temp); 
        IRQ_enable(IRQ_EVT_RTC);
}

IDEF void RTC_eventDisable(Uint16 ierMask)
{     
	Uint16 temp = RTC_RGET(RTCINTEN) & (~ierMask);
	RTC_RSET(RTCINTEN, temp);

        if ( !(RTC_RGET(RTCINTEN) & 0x70) )
            IRQ_disable(IRQ_EVT_RTC);
}


/*----------------------------------------------------------------------------*/
IDEF void RTC_start() {
  int oldgie;

  oldgie = IRQ_globalDisable(); 
    
  _RESET_B;		 /* Set bit SET in Register B to 0 */

  IRQ_globalRestore(oldgie);

}

/*----------------------------------------------------------------------------*/

IDEF void RTC_stop() {
  int oldgie;

  oldgie = IRQ_globalDisable(); 
    
  _SET_B;		 /* Set bit SET in Register B to 1 */

  IRQ_globalRestore(oldgie);

}

/*----------------------------------------------------------------------------*/

/* Changes decimal value to BCD value which is what RTC needs
 --------------------------------------------------*/
/*
RTC_decToBcd() => 16 * (dec_value / 10) + (dec_value % 10);
               => 6 * (dec_value / 10) + 10 * (dec_value / 10) + (dec_value % 10);
               => 6 * (dec_value / 10) + dec_value;
               Now (dec_value / 10) ~= (dec_value * A + B) >> C;
               For division by 10;
                  "(dec_value * 103) >> 10"  seems most optimal.
*/

IDEF int RTC_decToBcd(int dec_value)
{
    /* note: designed to work for 100 > dec_value >= 0; */
    return (dec_value + 6 * (dec_value * 103 >> 10));
}

/* RTC_bcdToDec() =>  (10 * hex_value/16) + (hex_value % 16)
                  =>  hex_value - (6* hex_value/16)
*/


IDEF int RTC_bcdToDec(int hex_value)
{
    /* note: designed to work for 0x100 > hex_value >= 0x00; */
   return (hex_value - 6 * (hex_value >> 4));

}

/*************************************************/


#endif /*USEDEFS */

#else
  #ifndef _RTC_MOD_
	#error RTC Hal Module Not Supported on Specified Target
  #endif
#endif  /* _RTC_SUPPORT  */

#endif  /* _CSL_RTCHAL_H  */

/******************************************************************************\
*
*      End of csl_rtc.h
*
\******************************************************************************/
