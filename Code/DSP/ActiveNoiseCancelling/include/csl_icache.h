/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... ICACHE
* FILENAME...... csl_icache.h
* DATE CREATED.. Mon 05/22/2000 
* PROJECT....... MCRTE - multichannel runtime environment
* COMPONENT..... CSL service layer
* PREREQUISITS.. csl_icachhal.h, stdinc.h, chiphal.h, csl.h
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:          05/22/2000
*   MODIFIED:         04/12/2001  Changed FILENAME to match actual name
*                     01/02/2002  Adapted for Rev 2.1
*                     08/03/2004  Added 5501 support
*   LAST MODIFIED:    08/17/2004  Added poll to validate ICACHE_enable() and 
*                                  ICACHE_disable()                 
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface for ICACHE Module)
\******************************************************************************/
#ifndef _ICACHE_H_
#define _ICACHE_H_    

#include <csl_std.h>
#include <csl_chiphal.h>
#include <csl.h>

#if (_ICACHE_SUPPORT)

#include <csl_icachhal.h> 

/****************************************\
* ICACHE scope and inline control macros
\****************************************/

#ifdef __cplusplus
#define CSLAPI extern "C"  
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _ICACHE_MOD_
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
* ICACHE global macro declarations
\****************************************/


/* error codes */
#define ICACHE_ERR_MAJOR            (ERR_BASE_ICACHE) 
#define ICACHE_ERR_ALLOC            (0x00000000)
#define ICACHE_ERR_INVALID_HANDLE   (0x00000001)

#if (CHIP_5510) | (CHIP_5510PG2_0)

/******************************************************************************
* ICACHE ICGC Global Control Register Macros
*
*
* Fields:
*   (RW) RMODE
*
\******************************************************************************/



/*---------------------------------------*\
* ICACHE_ICGC_RMK Macros
\*---------------------------------------*/

#define ICACHE_ICGC_RMK(rMode)\
    (Uint16) (ICACHE_FMK(ICGC,RMODE,rMode))

#define ICACHE_ICGC_RMKS(rMode_s)\
    (Uint16) (ICACHE_FMKS(ICGC,RMODE,rMode_s))

/*---------------------------------------*\
* ICGC Field Values
\*---------------------------------------*/


 #define ICACHE_ICGC_RMODE_0RAMSET    (0xCBFFu)
 #define ICACHE_ICGC_RMODE_1RAMSET    (0xCE1Fu)
 #define ICACHE_ICGC_RMODE_2RAMSET    (0xCFFFu)


/******************************************************************************\
* ICACHE ICWC - ICACHE N-Way Control Register Macros
*
* Fields:
*   (RW) WINIT
*
\******************************************************************************/

/*---------------------------------------*\
* ICACHE_ICWC_RMK Macros
\*---------------------------------------*/

#define ICACHE_ICWC_RMK(wInit)\
  (Uint16) ( ICACHE_FMK(ICWC,WINIT,wInit))


#define ICACHE_ICWC_RMKS(wInit_s)\
  (Uint16) ( ICACHE_FMKS(ICWC,WINIT,wInit_s))

/*---------------------------------------*\
* ICWC Field Values
\*---------------------------------------*/


 #define ICACHE_ICWC_WINIT_WINIT    (0xFu)

/******************************************************************************\
* ICACHE ICRC1 - 1/2 RamSet Control Register 1 Macros
*
* Fields:
*   (R ) R1TVALID
*   (RW) R1INIT
*
\******************************************************************************/

/*---------------------------------------*\
* ICACHE_ICRC1_MK Macro
\*---------------------------------------*/

#define ICACHE_ICRC1_RMK(r1Init)\
   (Uint16) ( ICACHE_FMK(ICRC1,R1INIT,r1Init))

#define ICACHE_ICRC1_RMKS(r1Init_s)\
   (Uint16) ( ICACHE_FMKS(ICRC1,R1INIT,r1Init_s))


/*---------------------------------------*\
* ICRC1 Field Values
\*---------------------------------------*/

 #define ICACHE_ICRC1_R1TVALID_NO    (0x0u)
 #define ICACHE_ICRC1_R1TVALID_YES    (0x1u)
 #define ICACHE_ICRC1_R1INIT_INIT    (0x3u)


/******************************************************************************\
* ICACHE ICRC2 - 1/2 RamSet Control Register 2 Macros
*
* Fields:
*   (R ) R2TVALID
*   (RW) R2INIT
*
\******************************************************************************/

/*---------------------------------------*\
* ICACHE_ICRC2_MK Macro
\*---------------------------------------*/

#define ICACHE_ICRC2_RMK(r2Init)\
   (Uint16) ( ICACHE_FMK(ICRC2,R2INIT,r2Init))

#define ICACHE_ICRC2_RMKS(r2Init_s)\
   (Uint16) ( ICACHE_FMKS(ICRC2,R2INIT,r2Init_s))

/*---------------------------------------*\
* ICRC2 Field Values
\*---------------------------------------*/

 #define ICACHE_ICRC1_R2TVALID_NO    (0x0u)
 #define ICACHE_ICRC1_R2TVALID_YES    (0x1u)
 #define ICACHE_ICRC2_R2INIT_INIT    (0x3u)

/******************************************************************************\
* ICACHE ICRTAG1 - ICACHE 1/2 Ram-set Tag Register 1 Macros
*
* Fields:
*   (RW) R1TAG
*
\******************************************************************************/


/*---------------------------------------*\
* ICACHE_ICRTAG1_MK Macro
\*---------------------------------------*/

#define ICACHE_ICRTAG1_RMK(r1tag)\
           (Uint16) (ICACHE_FMK(ICRTAG1,R1TAG,r1tag))

/*---------------------------------------*\
* ICRTAG1 Field Values
\*---------------------------------------*/

#define ICACHE_ICRTAG1_R1TAG_OF(x)         ((Uint16)(x))

/******************************************************************************\
* ICACHE ICRTAG2 - ICACHE 1/2 Ram-set Tag Register 2 Macros
*
* Fields:
*   (RW) R2TAG
*
\******************************************************************************/

/*---------------------------------------*\
* ICACHE_ICRTAG2_MK Macro
\*---------------------------------------*/

#define ICACHE_ICRTAG2_RMK(r2tag)\
           (Uint16) (ICACHE_FMK(ICRTAG2,R2TAG,r2tag))

/*---------------------------------------*\
* ICRTAG2 Field Values
\*---------------------------------------*/

#define ICACHE_ICRTAG2_R2TAG_OF(x)         ((Uint16)(x))


/******************************************************************************\
* ICACHE ICST - ICACHE Status Register
*
* Fields:
*   (R) IEN
*
\******************************************************************************/

/*---------------------------------------*\
* ICST Field Values
\*---------------------------------------*/

#define ICACHE_ICST_IEN_ENABLED         (0x1u)
#define ICACHE_ICST_IEN_DISABLED         (0x0u)


/*******************************************\
* ICACHE global macro definition : ROMABILITY
\*******************************************/  
/* Reserved ROM Area by icachedata.h */

#define ICache_Initialized           ICACHE_SYM(0)


/****************************************\
* ICACHE type definitions
\****************************************/

typedef struct
{
   Uint16              rmode;
   Uint32              r1addr;
   Uint32              r2addr;
} ICACHE_Setup;

typedef struct
{
   Uint16              rmode;
   Uint32              r1addr;
   Uint32              r2addr;
} ICACHE_Init;

typedef struct
{
   Uint32              r1addr;
   Uint32              r2addr;
} ICACHE_Tagset;


typedef struct {
Uint16 icgc;
Uint16 icwc;
Uint16 icrc1;
Uint16 icrtag1;
Uint16 icrc2;
Uint16 icrtag2;
} ICACHE_Config;



#endif

#if (CHIP_5502) || (CHIP_5501)

/******************************************************************************
* ICACHE ICGC Global Control Register Macros
*
* Fields:
*   (RW) _ICACHE_ICGC_FLUSHLINE
*
\******************************************************************************/


/*---------------------------------------*\
* ICACHE_ICGC_RMK Macros
\*---------------------------------------*/

#define ICACHE_ICGC_RMK(flushLine)\
    (Uint16) (ICACHE_FMK(ICGC,FLUSHLINE,flushLine)|\
)

#define ICACHE_ICGC_RMKS(flushLine_s)\
    (Uint16) (ICACHE_FMKS(ICGC,FLUSHLINE,flushLine_s)|\
)


/******************************************************************************\
* _ICACHE_ICFLARL - ICache Flush Line Address Low Register 
*
* Fields:
*   (RW) _ICACHE_ICFLARL_LAL
*
\******************************************************************************/


/*---------------------------------------*\
* CACHE_ICFLARL_RMK Macros
\*---------------------------------------*/

#define ICACHE_ICFLARL_RMK(lal)\
       (Uint16)(ICACHE_FMK(ICFLARL,LAL,lal))

#define ICACHE_ICFLARL_RMKS(lal_s)\
       (Uint16)(ICACHE_FMKS(ICFLARL,LAL,lal_s))



/******************************************************************************\
* _ICACHE_ICFLARH - ICache Flush Line Address High Register 
*
* Fields:
*   (RW) _ICACHE_ICFLARL_LAH
*
\******************************************************************************/


/*---------------------------------------*\
* ICACHE_ICFLARH_RMK Macros
\*---------------------------------------*/

#define ICACHE_ICFLARH_RMK(lah)\
       (Uint16)(ICACHE_FMK(ICFLARH,LAH,lah))

#define ICACHE_ICFLARH_RMKS(lah_s)\
       (Uint16)(ICACHE_FMKS(ICFLARH,LAH,lah_s))



/******************************************************************************\
* _ICACHE_ICWMC - ICACHE N-Way Miss Counter Register
*
* Fields:
*
*   (RW ) _ICACHE_ICWMC_MISSCNT
*
\******************************************************************************/


/*---------------------------------------*\
* ICACHE_ICWMC_RMK Macros
\*---------------------------------------*/

#define ICACHE_ICWMC_RMK(missCnt)\
       (Uint16)(ICACHE_FMK(ICWMC,MISSCNT,missCnt))

#define ICACHE_ICWMC_RMKS(missCnt_s)\
       (Uint16)(ICACHE_FMKS(ICWMC,MISSCNT,missCnt_s))



/*******************************************\
* ICACHE global macro definition : ROMABILITY
\*******************************************/  
/* Reserved ROM Area by cachedata.h */

#define ICache_Initialized           CACHE_SYM(0)



/****************************************\
* ICACHE type definitions
\****************************************/


typedef struct {
Uint16 icgc;

} ICACHE_Config;


#endif

/****************************************\
* ICACHE global function declarations
\****************************************/

IDECL  void ICACHE_enable();
IDECL  void ICACHE_disable();
IDECL  void ICACHE_flush();
IDECL  void ICACHE_freeze();
IDECL  void ICACHE_unfreeze();
IDECL  void ICACHE_config(ICACHE_Config *Config);

#if (CHIP_5510) | (CHIP_5510PG2_0)
IDECL  void ICACHE_setup(ICACHE_Setup *params);
IDECL  void ICACHE_init(ICACHE_Init *params);
IDECL  void ICACHE_tagset(ICACHE_Tagset *params);
IDECL  void ICACHE_configArgs(Uint16 icgc, Uint16 icwc, Uint16 icrc1, Uint16 icrtag1,\
                         Uint16 icrc2, Uint16 icrtag2);
#endif 


#if (CHIP_5502) || (CHIP_5501)
IDECL  void ICACHE_setup();
IDECL  void ICACHE_configArgs(Uint16 icgc);
#endif


/****************************************\
* ICACHE Inline Functions
\****************************************/
#ifdef  USEDEFS


/*----------------------------------------------------------------------------*/
IDEF  void ICACHE_unfreeze()
	{
	CHIP_FSET(ST3_55,CAFRZ,0);  
	}


/*----------------------------------------------------------------------------*/
IDEF  void ICACHE_freeze()
	{
	CHIP_FSET(ST3_55,CAFRZ,1);  
	}

/*----------------------------------------------------------------------------*/
IDEF  void ICACHE_flush()
	{
	CHIP_FSET(ST3_55,CACLR,1);   
	}

/*----------------------------------------------------------------------------*/
IDEF  void ICACHE_disable()
	{
	CHIP_FSET(ST3_55,CAEN,0);    

        #if (CHIP_5510) || (CHIP_5510PG2_0)
        
        /* Poll to validate disable */	
    	while(ICACHE_FGET(ICST, IEN));

        #endif

	}

/*----------------------------------------------------------------------------*/
IDEF  void ICACHE_enable()
	{
	CHIP_FSET(ST3_55,CAEN,1);    

        #if (CHIP_5510) || (CHIP_5510PG2_0)
                /* Poll to validate enable */	
    	        while(!ICACHE_FGET(ICST, IEN));
        #endif

	}
/*----------------------------------------------------------------------------*/

#if (CHIP_5510) | (CHIP_5510PG2_0)

IDEF  void ICACHE_setup(ICACHE_Setup *params)
	{
	
	Uint16 r1tag, r2tag;
   /* Set Ramset Mode in GCR register */

	ICACHE_RSET(ICGC, params -> rmode);
	
   /* Initialize Ramset N-Way Control Registers*/
   
   	ICACHE_FSET(ICWC,WINIT, ICACHE_ICWC_WINIT_WINIT);
   	ICACHE_FSET(ICRC1,R1INIT, ICACHE_ICRC1_R1INIT_INIT);
  	ICACHE_FSET(ICRC2,R2INIT,ICACHE_ICRC2_R2INIT_INIT);    	
   /* Enable ICACHE */
	CHIP_FSET(ST3_55,CAEN,1);  

   /* Poll to validate enable */	
    	while(!ICACHE_FGET(ICST, IEN));

   /* Initialize tags according to rmode values */

   if ((params -> rmode) == ICACHE_ICGC_RMODE_1RAMSET)		/* 1 RAMSET */
	{ 	
	
	   r1tag = (Uint16)(((params -> r1addr)>>12)&0x0FFFu);
	   ICACHE_FSET(ICRTAG1, R1TAG, r1tag);
	   while(!ICACHE_FGET(ICRC1, R1TVALID));

  	} 

   if ((params -> rmode) == ICACHE_ICGC_RMODE_2RAMSET)		/* 2 RAMSET */
	{ 
	
	 r1tag = (Uint16)(((params -> r1addr)>>12)&0x0FFFu);
	 r2tag = (Uint16)(((params -> r2addr)>>12)&0x0FFFu);	
	   ICACHE_FSET(ICRTAG1, R1TAG, r1tag);
	   while(!ICACHE_FGET(ICRC1, R1TVALID));
	   ICACHE_FSET(ICRTAG2, R2TAG, r2tag);
	   while(!ICACHE_FGET(ICRC2, R2TVALID));

  	}

   if ((params -> rmode) == ICACHE_ICGC_RMODE_0RAMSET)		/* 0 RAMSET */
      {}

}

/*----------------------------------------------------------------------------*/

IDEF  void ICACHE_tagset(ICACHE_Tagset *params)
	{
	Uint16	rmode;
	Uint16 r1tag, r2tag;
    rmode = ICACHE_RGET(ICGC);

   /* Initialize tags according to rmode values */

   if (rmode == ICACHE_ICGC_RMODE_1RAMSET )		/* 1 RAMSET */
	{ 	
	
	   r1tag = (Uint16)(((params -> r1addr)>>12)&0x0FFFu);
	   ICACHE_FSET(ICRTAG1, R1TAG, r1tag);
	   while(ICACHE_FGET(ICRC1, R1TVALID));

  	} 

   if (rmode == ICACHE_ICGC_RMODE_2RAMSET)		/* 2 RAMSET */
	{ 	
	
	   r1tag = (Uint16)(((params -> r1addr)>>12)&0x0FFFu);
	   r2tag = (Uint16)(((params -> r2addr)>>12)&0x0FFFu);
	   ICACHE_FSET(ICRTAG1, R1TAG, r1tag);
	   while(ICACHE_FGET(ICRC1, R1TVALID));
	   ICACHE_FSET(ICRTAG2, R2TAG, r2tag);
	   while(ICACHE_FGET(ICRC2, R2TVALID));

  	}

}

/*----------------------------------------------------------------------------*/

IDEF void ICACHE_config(ICACHE_Config *Config) 
	{

	ICACHE_RSET(ICGC, Config -> icgc);      
        ICACHE_RSET(ICWC, Config -> icwc);
        ICACHE_RSET(ICRC1, Config -> icrc1);
	ICACHE_RSET(ICRTAG1, Config -> icrtag1);
        ICACHE_RSET(ICRC2, Config -> icrc2);
        ICACHE_RSET(ICRTAG2, Config -> icrtag2);
	}

/*----------------------------------------------------------------------------*/


IDEF void ICACHE_configArgs(Uint16 icgc, Uint16 icwc, Uint16 icrc1, Uint16 icrtag1, Uint16 icrc2, Uint16 icrtag2) 
{

	ICACHE_RSET(ICGC, icgc);     
        ICACHE_RSET(ICWC, icwc);
        ICACHE_RSET(ICRC1, icrc1);
	 ICACHE_RSET(ICRTAG1, icrtag1);
        ICACHE_RSET(ICRC2, icrc2);
        ICACHE_RSET(ICRTAG2, icrtag2);


}

#endif 

#if (CHIP_5502) || (CHIP_5501)

IDEF  void ICACHE_setup()
	{


}

IDEF void ICACHE_config(ICACHE_Config *Config) 
	{

	ICACHE_RSET(ICGC, Config -> icgc);      
	}

/*----------------------------------------------------------------------------*/


IDEF void ICACHE_configArgs(Uint16 icgc) 
{
	ICACHE_RSET(ICGC, icgc);     
}

#endif /*5502 || 5501*/

#endif /*USEDEFS */


#else

     #ifndef _ICACHE_MOD_
     #error ICACHE Module Not Supported on Specified Target
     #endif

#endif /* _ICACHE_SUPPORT */

#endif /* _ICACHE_H_ */
/******************************************************************************\
* End of csl_icache.h
\******************************************************************************/

