/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_emif.h
* DATE CREATED.. 06/11/1999 
*------------------------------------------------------------------------------
* HISTORY:
*      MODIFIED:  07/14/2000
*      MODIFIED:  05/11/2001 updated for EMIF_getConfig()
*      MODIFIED:  05/16/2001 renamed EMIF_CONFIG -> EMIF_Config 
*      MODIFIED:  01/27/2002 fixed problem with EMIF_EMIF_EGCR_MEMFREQ_1/2X
*                             _OF(x) type symbolic constants
*      MODIFIED:  10/11/2002 added EMIF_reset macro/function as separate API 
*      MODIFIED:  11/22/2002 added MEMFREQ for 1BY4,1BY8,1BY16 fixed 1/2X
*                            added DEBUG and ST bits to Bus Error regitser (EMIBE)
*                            added symbolic constants EMIF_CKE_GPIO, EMIF_CKE_XF
\******************************************************************************/
#ifndef _EMIFA_H_
#define _EMIFA_H_

#include <csl.h>
#include <csl_emifdat.h>
#include <csl_emifAhal.h>

#if (_EMIF_SUPPORT)
/****************************************\
* EMIF scope and inline control macros
\****************************************/
#ifdef __cplusplus
#define CSLAPI extern "C"  
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _EMIF_MOD_
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
                          
#define Emif_Initialized            EMIF_SYM(0) 
/****************************************\
* EMIF global macro declarations
\****************************************/
/*-----------------------------------------------------------------------*/
/* The following macros are used to construct peripheral register        */
/* values based on symbolic constants. They will be useful to initialize */
/* the EMIF_Config structure in a readable way.                          */
/*-----------------------------------------------------------------------*/

/*============================================================================*\
* _EMIF_EGCR	- Global Control Register
*
* Fields:
*  (RW) MEMFREQ	- Memory Clock Frequency field
*  (RW) WPE		- Write Posting Enable field
*  (RW) MEMCEN	- Mem Clock Enable field
*  (R)  ARDY	- Value of ARDY input
*  (R)  HOLD	- Value of /HOLD input
*  (R)  HOLDA	- Value of /HOLDA output
*  (RW) NOHOLD	- External HOLD disable field
\*============================================================================*/

/*==========================================================================*\
*  EMIF_EGCR_DEFAULT Values
\*==========================================================================*/

/* default register value */
#define EMIF_EGCR_DEFAULT              (0x0020)
#define EMIF_EGCR_OF(x)               ((Uint16)(x))

/* field values */
#define EMIF_EGCR_MEMFREQ_1X           (0x0000)
#define EMIF_EGCR_MEMFREQ_1BY2X        (0x0001)
#define EMIF_EGCR_MEMFREQ_1BY4X        (0x0002)
#define EMIF_EGCR_MEMFREQ_1BY8X        (0x0003)
#define EMIF_EGCR_MEMFREQ_1BY16X       (0x0004)
#define EMIF_EGCR_WPE_OFF	         (0x0000)
#define EMIF_EGCR_WPE_ON           	   (0x0001)
#define EMIF_EGCR_MEMCEN_OFF           (0x0000)
#define EMIF_EGCR_MEMCEN_DISABLED      (0x0000)
#define EMIF_EGCR_MEMCEN_ON            (0x0001)
#define EMIF_EGCR_MEMCEN_ENABLED       (0x0001)
#define EMIF_EGCR_ARDY_LO              (0x0000)
#define EMIF_EGCR_ARDY_HI              (0x0001)
#define EMIF_EGCR_HOLD_LO              (0x0000)
#define EMIF_EGCR_HOLD_HI              (0x0001)
#define EMIF_EGCR_HOLDA_LO             (0x0000)
#define EMIF_EGCR_HOLDA_HI             (0x0001)
#define EMIF_EGCR_NOHOLD_HOLD          (0x0000)
#define EMIF_EGCR_NOHOLD_NOHOLD        (0x0001)

/*==========================================================================*\
*  EMIF_EGCR_MK
\*==========================================================================*/

/* make register value based on symbolic constants */

#define EMIF_EGCR_RMK(memfreq,wpe,memcen,nohold) \
 ((Uint16) ( \
 ( EMIF_FMK(EGCR,MEMFREQ,memfreq))|\
 ( EMIF_FMK(EGCR,WPE,wpe))|\
 ( EMIF_FMK(EGCR,MEMCEN,memcen))|\
 ( EMIF_FMK(EGCR,NOHOLD,nohold))\
 )\
)  

#define EMIF_EGCR_RMKS(memfreq_sym,wpe_sym,memcen_sym,nohold_sym) \
 ((Uint16) ( \
 ( EMIF_FMKS(EGCR,MEMFREQ,memfreq_sym))|\
 ( EMIF_FMKS(EGCR,WPE,wpe_sym))|\
 ( EMIF_FMKS(EGCR,MEMCEN,memcen_sym))|\
 ( EMIF_FMKS(EGCR,NOHOLD,nohold_sym))\
 )\
)  

/*============================================================================*\
* EMIF_EMIRST	-  Global Reset Register
*
* Fields:
*  (W) EMIRST	-  Global Reset Register Field
\*============================================================================*/
/* field values */
#define EMIF_EMIRST_EMIRST_0F(x)	       ((Uint16)(x))

/*==========================================================================*\
*  EMIF_EMIRST_RMK
\*==========================================================================*/

/* make register value based on symbolic constants */

#define EMIF_EMIRST_RMK(emirst) \
 ((Uint16) ( EMIF_FMK(EMIRST,EMIRST,emirst))\
)  

#define EMIF_EMIRST_RMKS(emirst_sym) \
 ((Uint16) ( EMIF_FMKS(EMIRST,EMIRST,emirst_sym))\
)  

/*=============================================================================*\
* _EMIF_EMIBE	   - Bus Error Status Register
*
* Fields:
*  (R) TIME
*  (R) CE3
*  (R) CE2
*  (R) CE1
*  (R) CE0
*  (R) DMA
*  (R) FBUS
*  (R) EBUS
*  (R) DBUS
*  (R) CBUS
*  (R) PBUS
\*============================================================================*/

#define EMIF_EMIBE_TIME_TRUE      (0x1u)
#define EMIF_EMIBE_TIME_FALSE     (0x0u)
#define EMIF_EMIBE_TIME_DEFAULT    EMIF_EMIBE_TIME_FALSE

#define EMIF_EMIBE_CE3_TRUE      (0x1u)
#define EMIF_EMIBE_CE3_FALSE     (0x0u)
#define EMIF_EMIBE_CE3_DEFAULT    EMIF_EMIBE_CE3_FALSE

#define EMIF_EMIBE_CE2_TRUE      (0x1u)
#define EMIF_EMIBE_CE2_FALSE     (0x0u)
#define EMIF_EMIBE_CE2_DEFAULT    EMIF_EMIBE_CE2_FALSE

#define EMIF_EMIBE_CE1_TRUE      (0x1u)
#define EMIF_EMIBE_CE1_FALSE     (0x0u)
#define EMIF_EMIBE_CE1_DEFAULT    EMIF_EMIBE_CE1_FALSE

#define EMIF_EMIBE_CE0_TRUE      (0x1u)
#define EMIF_EMIBE_CE0_FALSE     (0x0u)
#define EMIF_EMIBE_CE0_DEFAULT    EMIF_EMIBE_CE0_FALSE

#define EMIF_EMIBE_DMA_TRUE      (0x1u)
#define EMIF_EMIBE_DMA_FALSE     (0x0u)
#define EMIF_EMIBE_DMA_DEFAULT    EMIF_EMIBE_DMA_FALSE

#define EMIF_EMIBE_FBUS_TRUE      (0x1u)
#define EMIF_EMIBE_FBUS_FALSE     (0x0u)
#define EMIF_EMIBE_FBUS_DEFAULT    EMIF_EMIBE_FBUS_FALSE

#define EMIF_EMIBE_EBUS_TRUE      (0x1u)
#define EMIF_EMIBE_EBUS_FALSE     (0x0u)
#define EMIF_EMIBE_EBUS_DEFAULT    EMIF_EMIBE_EBUS_FALSE

#define EMIF_EMIBE_DBUS_TRUE      (0x1u)
#define EMIF_EMIBE_DBUS_FALSE     (0x0u)
#define EMIF_EMIBE_DBUS_DEFAULT    EMIF_EMIBE_DBUS_FALSE

#define EMIF_EMIBE_CBUS_TRUE      (0x1u)
#define EMIF_EMIBE_CBUS_FALSE     (0x0u)
#define EMIF_EMIBE_CBUS_DEFAULT    EMIF_EMIBE_CBUS_FALSE

#define EMIF_EMIBE_PBUS_TRUE      (0x1u)
#define EMIF_EMIBE_PBUS_FALSE     (0x0u)
#define EMIF_EMIBE_PBUS_DEFAULT    EMIF_EMIBE_PBUS_FALSE


#define EMIF_EMIBE_RMK(time,ce3,ce2,ce1,ce0,dma,fbus,ebus,dbus,cbus,pbus)\
 ((Uint16) (\
  EMIF_FMK(EMIBE,TIME,time) |\
  EMIF_FMK(EMIBE,CE3,ce3)   |\
  EMIF_FMK(EMIBE,CE2,ce2)   |\
  EMIF_FMK(EMIBE,CE1,ce1)   |\
  EMIF_FMK(EMIBE,CE0,ce0)   |\
  EMIF_FMK(EMIBE,DMA,dma)   |\
  EMIF_FMK(EMIBE,FBUS,fbus) |\
  EMIF_FMK(EMIBE,EBUS,ebus) |\
  EMIF_FMK(EMIBE,DBUS,dbus) |\
  EMIF_FMK(EMIBE,CBUS,cbus) |\
  EMIF_FMK(EMIBE,PBUS,pbus)\
  )\
)

#define EMIF_EMIBE_RMKS(time,ce3,ce2,ce1,ce0,dma,fbus,ebus,dbus,cbus,pbus)\
 ((Uint16) (\
  EMIF_FMKS(EMIBE,TIME,time) |\
  EMIF_FMKS(EMIBE,CE3,ce3)   |\
  EMIF_FMKS(EMIBE,CE2,ce2)   |\
  EMIF_FMKS(EMIBE,CE1,ce1)   |\
  EMIF_FMKS(EMIBE,CE0,ce0)   |\
  EMIF_FMKS(EMIBE,DMA,dma)   |\
  EMIF_FMKS(EMIBE,FBUS,fbus) |\
  EMIF_FMKS(EMIBE,EBUS,ebus) |\
  EMIF_FMKS(EMIBE,DBUS,dbus) |\
  EMIF_FMKS(EMIBE,CBUS,cbus) |\
  EMIF_FMKS(EMIBE,PBUS,pbus)\
  )\
)

/*===========================================================================*\
* _EMIF_CE01   - Space Control Register 1
* _EMIF_CE11   - Space Control Register 1
* _EMIF_CE21   - Space Control Register 1
* _EMIF_CE31   - Space Control Register 1
*
* Fields:
*  (RW) MTYPE	- MTYPE field
*  (RW) RDSETUP	- Read Setup field
*  (RW) RDSTROBE	- Read Strobe field
*  (RW) RDHOLD	- Read Hold field
\*===========================================================================*/

/*==========================================================================*\
*  EMIF_CEx1_DEFAULT Values
\*==========================================================================*/

/* default register value */
#define EMIF_CEx1_DEFAULT               (0x2FFF)
#define EMIF_CEx1_OF(x)                 ((Uint16)(x))

/* field values */
#define EMIF_CEx1_RDHOLD_OF(x)           ((Uint16)(x))
#define EMIF_CEx1_RDSTROBE_OF(x)         ((Uint16)(x))
#define EMIF_CEx1_RDSETUP_OF(x)          ((Uint16)(x))
#define EMIF_CEx1_MTYPE_ASYNC8           (0x0000)
#define EMIF_CEx1_MTYPE_ASYNC16          (0x0001)
#define EMIF_CEx1_MTYPE_ASYNC32          (0x0002)
#define EMIF_CEx1_MTYPE_SDRAM32          (0x0003)
#define EMIF_CEx1_MTYPE_SBSRAM32         (0x0004)

/*==========================================================================*\
*  EMIF_CEx1_MK
\*==========================================================================*/

#define EMIF_CEx1_RMK(mtype,rdsetup,rdstrobe,rdhold) \
 ((Uint16) ( \
  ( EMIF_FMK(CE01,MTYPE,mtype))|\
  ( EMIF_FMK(CE01,RDSETUP,rdsetup))|\
  ( EMIF_FMK(CE01,RDSTROBE,rdstrobe))|\
  ( EMIF_FMK(CE01,RDHOLD,rdhold))\
  )\
) 

#define EMIF_CEx1_RMKS(mtype_sym,rdsetup_sym,rdstrobe_sym,rdhold_sym) \
 ((Uint16) ( \
  ( EMIF_FMKS(CE01,MTYPE,mtype_sym))|\
  ( EMIF_FMKS(CE01,RDSETUP,rdsetup_sym))|\
  ( EMIF_FMKS(CE01,RDSTROBE,rdstrobe_sym))|\
  ( EMIF_FMKS(CE01,RDHOLD,rdhold_sym))\
  )\
) 


/*===========================================================================*\
* _EMIF_CE02   - Space Control Register 2
* _EMIF_CE12   - Space Control Register 2
* _EMIF_CE22   - Space COntrol Register 2
* _EMIF_CE32   - Space Control Register 2
*
* Fields:
*  (RW) RDEXHLD 	- Extended Hold Read field
*  (RW) WREXHLD	- Extended Hold Write field
*  (RW) WRSETUP	- Write Setup field
*  (RW) WRSTROBE	- Write Strobe field
*  (RW) WRHOLD	- Write Hold field
\*===========================================================================*/

/*==========================================================================*\
*  EMIF_CEx2_DEFAULT Values
\*==========================================================================*/


/* default register value */
#define EMIF_CEx2_DEFAULT               (0x5FFF)
#define EMIF_CEx2_OF(x)                  ((Uint16)(x))

/* field values */
#define EMIF_CEx2_WRHOLD_OF(x)           ((Uint16)(x))
#define EMIF_CEx2_WRSTROBE_OF(x)         ((Uint16)(x))
#define EMIF_CEx2_WRSETUP_OF(x)          ((Uint16)(x))
#define EMIF_CEx2_WREXHLD_OF(x)           ((Uint16)(x))
#define EMIF_CEx2_RDEXHLD_OF(x)          ((Uint16)(x))


/*==========================================================================*\
*  EMIF_CEx2_RMK
\*==========================================================================*/

/* make register value based on symbolic constants */
#define EMIF_CEx2_RMK(rdexhld,wrexhld,wrsetup,wrstrobe,wrhold) \
 ((Uint16) ( \
  ( EMIF_FMK(CE02,RDEXHLD,rdexhld))|\
  ( EMIF_FMK(CE02,WREXHLD,wrexhld))|\
  ( EMIF_FMK(CE02,WRSETUP,wrsetup))|\
  ( EMIF_FMK(CE02,WRSTROBE,wrstrobe))|\
  ( EMIF_FMK(CE02,WRHOLD,wrhold))\
  )\
) 

/*==========================================================================*\
*  EMIF_CEx2_GET
\*==========================================================================*/

/*===========================================================================*\
* _EMIF_CE03   - Space Control Register 3
* _EMIF_CE13   - Space Control Register 3
* _EMIF_CE23   - Space COntrol Register 3
* _EMIF_CE33   - Space Control Register 3
*
* Fields:
*  (RW) TIMOUT 	- Timeout field
\*===========================================================================*/

/*==========================================================================*\
*  EMIF_CEx3_DEFAULT Values
\*==========================================================================*/
/* default register value */
#define EMIF_CEx3_DEFAULT                (0x0000)
#define EMIF_CEx3_OF(x)                  ((Uint16)(x))

/* field values */
#define EMIF_CEx3_TIMOUT_OF(x)           ((Uint16)(x))

/*==========================================================================*\
*  EMIF_CEx3_MK
\*==========================================================================*/
/* make register value based on symbolic constants */

#define EMIF_CEx3_RMK(timout)            ((Uint16) (EMIF_FMK(CE03,TIMOUT,timout))) 

/*==========================================================================*\
*  EMIF_CEx3_SET
\*==========================================================================*/

#define EMIF_CE03_SET(val) (_PREG_SET(_EMIF_CE03_ADDR,val))
#define EMIF_CE13_SET(val) (_PREG_SET(_EMIF_CE13_ADDR,val))
#define EMIF_CE23_SET(val) (_PREG_SET(_EMIF_CE23_ADDR,val))
#define EMIF_CE33_SET(val) (_PREG_SET(_EMIF_CE33_ADDR,val))


/*==========================================================================*\
*  EMIF_CEx3_GET
\*==========================================================================*/

#define EMIF_CE03_GET 	((Uint16) _PREG_GET(_EMIF_CE03_ADDR))
#define EMIF_CE13_GET 	((Uint16) _PREG_GET(_EMIF_CE13_ADDR))
#define EMIF_CE23_GET 	((Uint16) _PREG_GET(_EMIF_CE23_ADDR))
#define EMIF_CE33_GET 	((Uint16) _PREG_GET(_EMIF_CE33_ADDR))

/*==========================================================================*\
*  EMIF_CEx3_FSET
\*==========================================================================*/

#define EMIF_CE03_FSET(FIELD,val) (_PFIELD_SET(_EMIF_CE03_ADDR,_EMIF_CEx3_##FIELD,val))
#define EMIF_CE13_FSET(FIELD,val) (_PFIELD_SET(_EMIF_CE13_ADDR,_EMIF_CEx3_##FIELD,val))
#define EMIF_CE23_FSET(FIELD,val) (_PFIELD_SET(_EMIF_CE23_ADDR,_EMIF_CEx3_##FIELD,val))
#define EMIF_CE33_FSET(FIELD,val) (_PFIELD_SET(_EMIF_CE33_ADDR,_EMIF_CEx3_##FIELD,val))

/*==========================================================================*\
*  EMIF_CEx3_FGET
\*==========================================================================*/

#define EMIF_CE03_FGET(FIELD) 	   ((Uint16) _PFIELD_GET(_EMIF_CE03_ADDR,_EMIF_CEx3_##FIELD))
#define EMIF_CE13_FGET(FIELD) 	   ((Uint16) _PFIELD_GET(_EMIF_CE13_ADDR,_EMIF_CEx3_##FIELD))
#define EMIF_CE23_FGET(FIELD) 	   ((Uint16) _PFIELD_GET(_EMIF_CE23_ADDR,_EMIF_CEx3_##FIELD))
#define EMIF_CE33_FGET(FIELD) 	   ((Uint16) _PFIELD_GET(_EMIF_CE33_ADDR,_EMIF_CEx3_##FIELD))

/*===========================================================================*\
* _EMIF_SDC1   - SDRAM Control Register 1
*
* Fields:
*  (RW) TRC
*  (RW) SDSIZE
*  (RW) SDWID
*  (RW) RFEN
*  (RW) TRCD
*  (RW) TRP
\*===========================================================================*/

/*==========================================================================*\
*  EMIF_SDC1_DEFAULT Values
\*==========================================================================*/
/* default register value */
#define EMIF_SDC1_DEFAULT             (0x0F94)


#define EMIF_SDC1_OF(x)                 ((Uint16)(x))

/* field values */
#define EMIF_SDC1_TRP_OF(x)             ((Uint16)(x))
#define EMIF_SDC1_TRCD_OF(x)            ((Uint16)(x))
#define EMIF_SDC1_RFEN_DISABLE          (0x0000)
#define EMIF_SDC1_RFEN_ENABLE           (0x0001)
#define EMIF_SDC1_SDWID_OFF             (0x0000)
#define EMIF_SDC1_SDWID_ON              (0x0001)
#define EMIF_SDC1_SDSIZE_16M            (0x0000)
#define EMIF_SDC1_SDSIZE_64M            (0x0001)
#define EMIF_SDC1_TRC_OF(x)             ((Uint16)(x))

/*==========================================================================*\
*  EMIF_SDC1_MK
\*==========================================================================*/
/* make register value based on symbolic constants */
#define EMIF_SDC1_MK(trc,sdsize,sdwid,rfen,trcd,trp) \
 ((Uint16) ( \
  ( _EMIF_SDC1_TRC_MK(trc))|\
  ( _EMIF_SDC1_SDSIZE_MK(sdsize))|\
  ( _EMIF_SDC1_SDWID_MK(sdwid))|\
  ( _EMIF_SDC1_RFEN_MK(rfen))|\
  ( _EMIF_SDC1_TRCD_MK(trcd))|\
  ( _EMIF_SDC1_TRP_MK(trp))\
  )\
)
/*==========================================================================*\
*  EMIF_SDC1_SET
\*==========================================================================*/

#define EMIF_SDC1_SET(val) (_PREG_SET(_EMIF_SDC1_ADDR,val))

/*==========================================================================*\
*  EMIF_SDC1_GET
\*==========================================================================*/

#define EMIF_SDC1_GET 	((Uint16) _PREG_GET(_EMIF_SDC1_ADDR))

/*==========================================================================*\
*  EMIF_SDC1_FSET
\*==========================================================================*/

#define EMIF_SDC1_FSET(FIELD,val) (_PFIELD_SET(_EMIF_SDC1_ADDR,_EMIF_SDC1_##FIELD,val))

/*==========================================================================*\
*  EMIF_SDC1_FGET
\*==========================================================================*/

#define EMIF_SDC1_FGET(FIELD) 	   ((Uint16) _PFIELD_GET(_EMIF_SDC1_ADDR,_EMIF_SDC1_##FIELD))

#define EMIF_SDC1_RMK(trc,sdsize,sdwid,rfen,trcd,trp)( \
(Uint16) (	EMIF_FMK(SDC1,TRC,trc) 		|\
		EMIF_FMK(SDC1,SDSIZE,sdsize) 	|\
		EMIF_FMK(SDC1,SDWID,sdwid) 	|\
		EMIF_FMK(SDC1,RFEN,rfen) 	|\
		EMIF_FMK(SDC1,TRCD,trcd) 	|\
		EMIF_FMK(SDC1,TRP,trp)		)\
)


/*===========================================================================*\
* _EMIF_SDPER   - SDRAM Period Register
*
* Fields:
*  (RW) PERIOD
\*===========================================================================*/

/*==========================================================================*\
*  EMIF_SDPER_DEFAULT Values
\*==========================================================================*/
/* default register value */
#define EMIF_SDPER_DEFAULT             (0x0080)
#define EMIF_SDPER_OF(x)  ((Uint16)(x))

/* field values */
#define EMIF_SDPER_PERIOD_OF(x)          ((Uint16)(x))

/*==========================================================================*\
*  EMIF_SDCNT_RMK
\*==========================================================================*/
/* make register value based on symbolic constants */

#define EMIF_SDCNT_COUNTER_OF(x)          ((Uint16)(x))

#define EMIF_SDCNT_RMK(sdcnt)             ((Uint16)(EMIF_FMK(SDCNT,COUNTER,sdcnt)))

/*==========================================================================*\
*  EMIF_SDPER_RMK
\*==========================================================================*/
/* make register value based on symbolic constants */

#define EMIF_SDPER_RMK(period) \
 ((Uint16) ( \
  ( EMIF_FMK(SDPER,PERIOD,period))\
  )\
)

#define EMIF_SDPER_RMKS(period_s) \
 ((Uint16) ( \
  ( EMIF_FMKS(SDPER,PERIOD,period_s))\
  )\
)


/*===========================================================================*\
* EMIF_INIT   - SDRAM Initialization Register
*
* Fields:
*  (RW) INIT
\*===========================================================================*/

/*==========================================================================*\
*  EMIF_INIT_DEFAULT Values
\*==========================================================================*/
/* default register value */
#define EMIF_INIT_DEFAULT             (0x0000u)
#define EMIF_SDINIT_DEFAULT           (0x0000u)
#define EMIF_INIT_OF(x)               ((Uint16)(x))
#define EMIF_SDINIT_OF(x)             ((Uint16)(x))

/* field values */
#define EMIF_SDINIT_INIT_OF(x)          ((Uint16)(x))
#define EMIF_SDINIT_INIT_OF(x)          ((Uint16)(x))


/*==========================================================================*\
*  EMIF_INIT_RMK
\*==========================================================================*/
/* make register value based on symbolic constants */

/* make register value based on symbolic constants */
#define EMIF_INIT_RMK(val) \
 ((Uint16) ( \
  ( EMIF_FMK(INIT,INIT,val))\
  )\
)

#define EMIF_INIT_RMKS(val_s) \
 ((Uint16) ( \
  ( EMIF_FMKS(INIT,INIT,val_s))\
  )\
)

/* make register value based on symbolic constants */
#define EMIF_SDINIT_RMK(val) \
 ((Uint16) ( \
  ( EMIF_FMK(SDINIT,INIT,val))\
  )\
)

#define EMIF_SDINIT_RMKS(val_s) \
 ((Uint16) ( \
  ( EMIF_FMKS(SDINIT,INIT,val_s))\
  )\
)

/*===========================================================================*\
* _EMIF_SDC2   - SDRAM Control Register 2
*
* Fields:
*  (RW) SDACC
*  (RW) TMRD
*  (RW) TRAS
*  (RW) TACTV2ACTV
\*==========================================================================*/

/*==========================================================================*\
*  EMIF_SDC2_DEFAULT Values
\*==========================================================================*/
/* default register value */
#define EMIF_SDC2_DEFAULT             (0x03FF)


#define EMIF_SDC2_OF(x)                 ((Uint16)(x))

/* field values */
#define EMIF_SDC2_SDACC_16BITBUS        (0u)
#define EMIF_SDC2_SDACC_32BITBUS        (1u)
#define EMIF_SDC2_TACTV2ACTV_OF(x)      ((Uint16)(x))
#define EMIF_SDC2_TRAS_OF(x)             ((Uint16)(x))
#define EMIF_SDC2_TMRD_OF(x)            ((Uint16)(x))

/*==========================================================================*\
*  EMIF_SDC2_RMK
\*==========================================================================*/
/* make register value based on symbolic constants */
#define EMIF_SDC2_RMK(sdacc,tmrd,tras,tactv2actv) \
 ((Uint16) ( \
  (EMIF_FMK(SDC2,SDACC,sdacc))|\
  (EMIF_FMK(SDC2,TMRD,tmrd))|\
  (EMIF_FMK(SDC2,TRAS,tras))|\
  (EMIF_FMK(SDC2,TACTV2ACTV,tactv2actv))\
  )\
) 

#define EMIF_SDC2_RMKS(sdacc_s,tmrd_s,tras_s,tactv2actv_s) \
 ((Uint16) ( \
  (EMIF_FMKS(SDC2,SDACC,sdacc_s))|\
  (EMIF_FMKS(SDC2,TMRD,tmrd_s))|\
  (EMIF_FMKS(SDC2,TRAS,tras_s))|\
  (EMIF_FMKS(SDC2,TACTV2ACTV,tactv2actv_s))\
  )\
) 


/****************************************\
* Define constants for EMIF clock
\****************************************/
#define EMIF_CKE_GPIO4            (0x0001u)
#define EMIF_CKE_XF               (0x0000u)
#define EMIF_CKEEN_ENABLED        (0x0001u)
#define EMIF_SRCOM_ENABLE         (0x0001u)
#define EMIF_SREF_DELAY_DEFAULT   (0x0028u)  
#define EMIF_SRCOM_DISABLED       (0x0000u)

/****************************************\
* EMIF global typedef declarations
\****************************************/

/* device configuration structure */
typedef struct {
  Uint16 egcr;
  Uint16 emirst;
  Uint16 ce01;
  Uint16 ce02;
  Uint16 ce03;
  Uint16 ce11;
  Uint16 ce12;
  Uint16 ce13;
  Uint16 ce21;
  Uint16 ce22;
  Uint16 ce23;
  Uint16 ce31;
  Uint16 ce32;
  Uint16 ce33;
  Uint16 sdc1;
  Uint16 sdper;
  Uint16 init;
  Uint16 sdc2;
} EMIF_Config;

/****************************************\
* EMIF global variable declarations
\****************************************/

/****************************************\
* EMIF global function declarations
\****************************************/

CSLAPI void EMIF_config(EMIF_Config *Config);
CSLAPI void EMIF_getConfig(EMIF_Config *Config);
CSLAPI void EMIF_configArgs(Uint16 egcr, Uint16 emirst, Uint16 ce01,
  Uint16 ce02, Uint16 ce03, Uint16 ce11, Uint16 ce12, Uint16 ce13,
  Uint16 ce21, Uint16 ce22, Uint16 ce23, Uint16 ce31, Uint16 ce32,
  Uint16 ce33, Uint16 sdc1, Uint16 sdper, Uint16 init, 
  Uint16 sdc2);

CSLAPI void EMIF_enterselfRefresh(Uint16 ckePin, Uint16 tRasDelay);
CSLAPI void EMIF_exitselfRefresh(Uint16 tXsrDelay);

/****************************************\
* EMIF inline function declarations
\****************************************/
static inline void EMIF_reset(void);

/****************************************\
* EMIF inline function definitions
\****************************************/
static inline void EMIF_reset(void) {
  EMIF_RSET(EMIRST,0xFFFF);
}

#endif /* EMIF_SUPPORT */
#endif /* _EMIFA_H_ */
/******************************************************************************\
* End of emif.h
\******************************************************************************/
