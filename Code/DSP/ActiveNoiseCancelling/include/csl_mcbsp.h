/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... MCBSP
* FILENAME...... csl_mcbsp.h
* DATE CREATED.. Fri 06/11/1999
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... SL - Service Layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:    06/11/1999 Created
*   MODIFIED:   11/18/1999 Modified for TMS320C54xx
*   MODIFIED:   02/15/2000 C54x Romability
*   MODIFIED:   06/01/2000 Modified for TMS320C55x
*   MODIFIED:   04/16/2001 updated FILENAME and other header comments
*   MODIFIED:   05/11/2001 updated to include MCBSP_getConfig()
*   MODIFIED:   05/16/2001 updated to include MCBSP_read16/write16
*   MODIFIED:   06/28/2001 updated for new CSL initialization model
*   MODIFIED:   01/24/2002 added MCBS_read and MCBSP_write for C54x
*                          CSL compatability
*   MODIFIED:   05/07/2002 Added MCBSP_Private typedef for C++ type checking
*   MODIFIED:   09/25/2003 Removed xrdy/rrdy polling from MCBSP_write32()and MCBSP_read32()
*   MODIFIED:   10/07/2003 Removed READONLY fields from SPCR,PCR RMK macros
*   MODIFIED:   12/02/2003 Fixed ~ in MCBSP_xempty() with !
*   MODIFIED:   08/03/2004 Added 5501 support
*------------------------------------------------------------------------------
* DESCRIPTION:  (interface file for the MCBSP module)
*
*
*
\******************************************************************************/
#ifndef _MCBSP_H_
#define _MCBSP_H_

#include <_csl.h>
#include <csl_mcbsphal.h>
#include <csl_mcbspdat.h>

#if (_MCBSP_SUPPORT)
/****************************************\
* MCBSP scope and inline control macros
\****************************************/
#ifdef __cplusplus
#define CSLAPI extern "C"
#else
#define CSLAPI extern
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _MCBSP_MOD_
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
* MCBSP global macro declarations
\****************************************/

#define MCBSP_PORT_CNT             _MCBSP_PORT_CNT

/* MCBSP_Open() flags */
#define MCBSP_OPEN_RESET          (0x0001)


/* error codes */
#define MCBSP_ERR_MAJOR            (0x00000004)
#define MCBSP_ERR_ALLOC            (0x00000000)
#define MCBSP_ERR_INVALID_HANDLE   (0x00000001)

/* device identifiers for MCBSP_Open() */
#define MCBSP_PORT0    (0)
#define MCBSP_PORT1    (1)

#if (!(CHIP_5501))
#define MCBSP_PORT2    (2)
#endif

#define MCBSP_PORT_ANY (-1)
/*#if (MCBSP_PORT_CNT == XX)*/

/* Constants for MCBSP_start */
#define MCBSP_RCV_START       (1u)
#define MCBSP_XMIT_START      (2u)
#define MCBSP_SRGR_START      (4u)
#define MCBSP_SRGR_FRAMESYNC  (8u)
#define MCBSP_SRGR_DEFAULT_DELAY  (0xFFFFu)

/*******************************************\
* MCBSP global macro definition : ROMABILITY
\*******************************************/
/* Reserved ROM Area by Mcbspdata.h */

/* Data definition */

/* Predefined Device Handlers */
#define MCBSP_HDEV0   ((MCBSP_Handle)&(CSL_MCBSP_DATA.mcbspPort[0]))
#define MCBSP_HDEV1   ((MCBSP_Handle)&(CSL_MCBSP_DATA.mcbspPort[1]))

#if (!(CHIP_5501))
#define MCBSP_HDEV2   ((MCBSP_Handle)&(CSL_MCBSP_DATA.mcbspPort[2]))
#endif

#define MCBSP_HDEV(n) ((MCBSP_Handle)&(CSL_MCBSP_DATA.mcbspPort[n]))

/* Get IRQ_EventNumber listed into the IRQ.h file */

#define MCBSP_getXmtEventId(_MCBSP) (\
  MCBSP_ASSERT_HANDLE(_MCBSP,return 0xFFFF)\
  (((MCBSP_PrivateObj*)_MCBSP)->XmtEvent)\
)
#define MCBSP_getRcvEventId(_MCBSP) (\
  MCBSP_ASSERT_HANDLE(_MCBSP,return 0xFFFF)\
  (((MCBSP_PrivateObj*)_MCBSP)->RcvEvent)\
)


#define MCBSP_xempty(_MCBSP)\
     (!(MCBSP_FGETH(_MCBSP,SPCR2,XEMPTY)))

#define MCBSP_xrdy(_MCBSP)\
      MCBSP_FGETH(_MCBSP,SPCR2,XRDY)

#define MCBSP_rrdy(_MCBSP)\
      MCBSP_FGETH(_MCBSP,SPCR1,RRDY)

#define MCBSP_rfull(_MCBSP)\
      MCBSP_FGETH(_MCBSP,SPCR1,RFULL)

#define MCBSP_getPort(_MCBSP)\
     ((MCBSP_PrivateObj *)(_MCBSP))->Port


/*Enable-Disable Receive-Transmit Channels;*/
#define MCBSP_channelEnable(_MCBSP,Reg,Channels)\
 MCBSP_RSETH(_MCBSP,Reg,Channels)


#define MCBSP_channelDisable(_MCBSP,Reg,Channels)\
 MCBSP_RAOIH(_MCBSP,Reg,~Channels,0,0)

#define MCBSP_channelStatus(_MCBSP,Reg,Channels) \
 (((MCBSP_RGETH(_MCBSP,Reg)) & (Channels))!=0)


/*******************************************/
/* Define a debuging assertion macro */
/* for validating device handles */

#ifdef _MCRTE_DEBUG
  #define MCBSP_ASSERT_HANDLE(_MCBSP,RetExp) \
    if (_MCBSP == INV) { \
      ERR_submit(MCBSP_ERR_MAJOR, MCBSP_ERR_INVALID_HANDLE); \
      RetExp; \
    }
#else
  #define MCBSP_ASSERT_HANDLE(_MCBSP,RetExp)
#endif

#define MCBSP_CHAN0     0x0001
#define MCBSP_CHAN1     0x0002
#define MCBSP_CHAN2     0x0004
#define MCBSP_CHAN3     0x0008
#define MCBSP_CHAN4     0x0010
#define MCBSP_CHAN5     0x0020
#define MCBSP_CHAN6     0x0040
#define MCBSP_CHAN7     0x0080
#define MCBSP_CHAN8     0x0100
#define MCBSP_CHAN9     0x0200
#define MCBSP_CHAN10    0x0400
#define MCBSP_CHAN11    0x0800
#define MCBSP_CHAN12    0x1000
#define MCBSP_CHAN13    0x2000
#define MCBSP_CHAN14    0x4000
#define MCBSP_CHAN15    0x8000


/*-----------------------------------------------------------------------*/
/* The following macros are used to construct peripheral register        */
/* values based on symbolic constants. They will be useful to initialize */
/* the MCBSP_Config structure in a readable way.                         */
/*-----------------------------------------------------------------------*/

/*===========================================================================*\
* MCBSP SPCR1   - Serial Port Control Register 1 Macros
*
* Fields:
*  (RW) DLB
*  (RW) RJUST
*  (RW) CLKSTP
*  (RW) DXENA
*  (RW) ABIS
*  (RW) RINTM
*  (RW) RSYNCERR
*  (R)  RFULL
*  (R)  RRDY
*  (RW) RRST
\*==========================================================================*/

#define MCBSP_SPCR1_DEFAULT                (0x0000u)



/*---------------------------------------*\
* MCBSP_SPCR1_MK Macro
\*---------------------------------------*/

#define MCBSP_SPCR1_RMK(dlb,rjust,clkstp, dxena, abis, rintm, rsyncerr,rrst)\
    ((Uint16)( \
    (MCBSP_FMK(SPCR1,RRST,rrst))         |\
    (MCBSP_FMK(SPCR1,RSYNCERR,rsyncerr)) |\
    (MCBSP_FMK(SPCR1,RINTM,rintm))       |\
    (MCBSP_FMK(SPCR1,ABIS,abis))         |\
    (MCBSP_FMK(SPCR1,DXENA,dxena))       |\
    (MCBSP_FMK(SPCR1,CLKSTP,clkstp))     |\
    (MCBSP_FMK(SPCR1,RJUST,rjust))       |\
    (MCBSP_FMK(SPCR1,DLB,dlb))            \
  ) \
)

#define MCBSP_SPCR1_RMKS(dlb_s,rjust_s,clkstp_s, dxena_s, abis_s, rintm_s, rrst_s)\
    ((Uint16)( \
    (MCBSP_FMKS(SPCR1,RRST,rrst_s))| \
    (MCBSP_FMKS(SPCR1,RINTM,rintm_s))| \
    (MCBSP_FMKS(SPCR1,ABIS,abis_s))| \
    (MCBSP_FMKS(SPCR1,DXENA,dxena_s))| \
    (MCBSP_FMKS(SPCR1,CLKSTP,clkstp_s))| \
    (MCBSP_FMKS(SPCR1,RJUST,rjust_s))| \
    (MCBSP_FMKS(SPCR1,DLB,dlb_s)) \
  ) \
)


/* SPCR1 field values */
#define MCBSP_SPCR1_RRST_DISABLE           (0x0000u)
#define MCBSP_SPCR1_RRST_ENABLE            (0x0001u)
#define MCBSP_SPCR1_RRDY_NO                (0x0000u)
#define MCBSP_SPCR1_RRDY_YES               (0x0001u)
#define MCBSP_SPCR1_RFULL_NO               (0x0000u)
#define MCBSP_SPCR1_RFULL_YES              (0x0001u)
#define MCBSP_SPCR1_RSYNCERR_NO            (0x0000u)
#define MCBSP_SPCR1_RSYNCERR_YES           (0x0001u)
#define MCBSP_SPCR1_RINTM_RRDY             (0x0000u)
#define MCBSP_SPCR1_RINTM_EOS              (0x0001u)
#define MCBSP_SPCR1_RINTM_FRM              (0x0002u)
#define MCBSP_SPCR1_RINTM_RSYNCERR         (0x0003u)
#define MCBSP_SPCR1_ABIS_DISABLE           (0x0000u)
#define MCBSP_SPCR1_ABIS_ENABLE            (0x0001u)
#define MCBSP_SPCR1_DXENA_NA               (0x0000u)
#define MCBSP_SPCR1_DXENA_OFF              (0x0000u)
#define MCBSP_SPCR1_DXENA_ON               (0x0001u)
#define MCBSP_SPCR1_CLKSTP_DISABLE         (0x0000u)
#define MCBSP_SPCR1_CLKSTP_NODELAY         (0x0002u)
#define MCBSP_SPCR1_CLKSTP_DELAY           (0x0003u)
#define MCBSP_SPCR1_RJUST_RZF              (0x0000u)
#define MCBSP_SPCR1_RJUST_RSE              (0x0001u)
#define MCBSP_SPCR1_RJUST_LZF              (0x0002u)
#define MCBSP_SPCR1_DLB_OFF                (0x0000u)
#define MCBSP_SPCR1_DLB_ON                 (0x0001u)



/*===========================================================================*\
* _MCBSP_SPCR2   - Serial Port Control Register 2 Macros
*
* Fields:
*  (RW) FREE
*  (RW) SOFT
*  (RW) FRST
*  (RW) GRST
*  (RW) XINTM
*  (RW) XSYNCERR
*  (R)  XEMPTY
*  (R)  XRDY
*  (RW) XRST
\*==========================================================================*/

/*---------------------------------------*\
* MCBSP_SPCR2_MK Macro
\*---------------------------------------*/

#define MCBSP_SPCR2_RMK(free,soft,frst,grst,xintm,xsyncerr,xrst)\
    ((Uint16)( \
    (MCBSP_FMK(SPCR2,XRST,xrst))         |\
    (MCBSP_FMK(SPCR2,XSYNCERR,xsyncerr)) |\
    (MCBSP_FMK(SPCR2,XINTM,xintm))       |\
    (MCBSP_FMK(SPCR2,GRST,grst))         |\
    (MCBSP_FMK(SPCR2,FRST,frst))         |\
    (MCBSP_FMK(SPCR2,SOFT,soft))         |\
    (MCBSP_FMK(SPCR2,FREE,free))          \
  ) \
)

#define MCBSP_SPCR2_RMKS(free_s,soft_s,frst_s,grst_s,xintm_s,xsyncerr_s,xrst_s)\
    ((Uint16)( \
    (MCBSP_FMKS(SPCR2,XRST,xrst_s))|\
    (MCBSP_FMKS(SPCR2,XINTM,xintm_s))|\
    (MCBSP_FMKS(SPCR2,XSYNCERR,xsyncerr_s))|\
    (MCBSP_FMKS(SPCR2,GRST,grst_s))|\
    (MCBSP_FMKS(SPCR2,FRST,frst_s))|\
    (MCBSP_FMKS(SPCR2,SOFT,soft_s))|\
    (MCBSP_FMKS(SPCR2,FREE,free_s))\
  ) \
)

/* SPCR2 field values */
#define MCBSP_SPCR2_DEFAULT                (0x0000u)

#define MCBSP_SPCR2_XRST_DISABLE           (0x0000u)
#define MCBSP_SPCR2_XRST_ENABLE            (0x0001u)
#define MCBSP_SPCR2_XRDY_NO                (0x0000u)
#define MCBSP_SPCR2_XRDY_YES               (0x0001u)
#define MCBSP_SPCR2_XEMPTY_YES             (0x0000u)
#define MCBSP_SPCR2_XEMPTY_NO              (0x0001u)
#define MCBSP_SPCR2_XSYNCERR_NO            (0x0000u)
#define MCBSP_SPCR2_XSYNCERR_YES           (0x0001u)
#define MCBSP_SPCR2_XINTM_XRDY             (0x0000u)
#define MCBSP_SPCR2_XINTM_EOS              (0x0001u)
#define MCBSP_SPCR2_XINTM_FRM              (0x0002u)
#define MCBSP_SPCR2_XINTM_XSYNCERR         (0x0003u)
#define MCBSP_SPCR2_GRST_RESET             (0x0000u)
#define MCBSP_SPCR2_GRST_CLKG              (0x0001u)
#define MCBSP_SPCR2_FRST_RESET             (0x0000u)
#define MCBSP_SPCR2_FRST_FSG               (0x0001u)
#define MCBSP_SPCR2_SOFT_NO                (0x0000u)
#define MCBSP_SPCR2_SOFT_YES               (0x0001u)
#define MCBSP_SPCR2_FREE_NO                (0x0000u)
#define MCBSP_SPCR2_FREE_YES               (0x0001u)


/*===========================================================================*\
* MCBSP RCR1   - Receive Control Register 2 Macros
*
* Fields:
*  (RW) RFRLEN1
*  (RW) RWDLEN1
\*==========================================================================*/

/* default RCR1 register value */
#define MCBSP_RCR1_DEFAULT                 (0x0000u)


/*---------------------------------------*\
* MCBSP_RCR1_MK Macro
\*---------------------------------------*/

#define MCBSP_RCR1_RMK(rfrlen1,rwdlen1)\
  ((Uint16)(\
    (MCBSP_FMK(RCR1,RWDLEN1,rwdlen1))|\
    (MCBSP_FMK(RCR1,RFRLEN1,rfrlen1))\
  ) \
)

#define MCBSP_RCR1_RMKS(rfrlen1_s,rwdlen1_s)\
  ((Uint16)(\
    (MCBSP_FMKS(RCR1,RWDLEN1,rwdlen1_s))|\
    (MCBSP_FMKS(RCR1,RFRLEN1,rfrlen1_s))\
  ) \
)

/* RCR1 field values */
#define MCBSP_RCR1_RWDLEN1_8BIT            (0x0000u)
#define MCBSP_RCR1_RWDLEN1_12BIT           (0x0001u)
#define MCBSP_RCR1_RWDLEN1_16BIT           (0x0002u)
#define MCBSP_RCR1_RWDLEN1_20BIT           (0x0003u)
#define MCBSP_RCR1_RWDLEN1_24BIT           (0x0004u)
#define MCBSP_RCR1_RWDLEN1_32BIT           (0x0005u)
#define MCBSP_RCR1_RFRLEN1_OF(x)           ((Uint16)(x))

/*===========================================================================*\
* MCBSP RCR2   - Receive Control Register 2 Macros
*
* Fields:
*  (RW) RPHASE
*  (RW) RFRLEN2
*  (RW) RWDLEN2
*  (RW) RCOMPAND
*  (RW) RFIG
*  (RW) RDATDLY
\*==========================================================================*/

/* default RCR2 register value */
#define MCBSP_RCR2_DEFAULT                 (0x0000u)


/*---------------------------------------*\
* MCBSP_RCR2_MK Macro
\*---------------------------------------*/

#define MCBSP_RCR2_RMK(rphase,rfrlen2,rwdlen2,rcompand,rfig,rdatdly)\
   ((Uint16)(\
    (MCBSP_FMK(RCR2,RDATDLY,rdatdly))   |\
    (MCBSP_FMK(RCR2,RFIG,rfig))         |\
    (MCBSP_FMK(RCR2,RCOMPAND,rcompand)) |\
    (MCBSP_FMK(RCR2,RWDLEN2,rwdlen2))   |\
    (MCBSP_FMK(RCR2,RFRLEN2,rfrlen2))   |\
    (MCBSP_FMK(RCR2,RPHASE,rphase))      \
  ) \
)

#define MCBSP_RCR2_RMKS(rphase_s,rfrlen2_s,rwdlen2_s,rcompand_s,rfig_s,rdatdly_s)\
   ((Uint16)(\
    (MCBSP_FMKS(RCR2,RDATDLY,rdatdly_s))   |\
    (MCBSP_FMKS(RCR2,RFIG,rfig_s))         |\
    (MCBSP_FMKS(RCR2,RCOMPAND,rcompand_s)) |\
    (MCBSP_FMKS(RCR2,RWDLEN2,rwdlen2_s))   |\
    (MCBSP_FMKS(RCR2,RFRLEN2,rfrlen2_s))   |\
    (MCBSP_FMKS(RCR2,RPHASE,rphase_s))      \
  ) \
)


/* RCR2 field values */
#define MCBSP_RCR2_RDATDLY_0BIT            (0x0000u)
#define MCBSP_RCR2_RDATDLY_1BIT            (0x0001u)
#define MCBSP_RCR2_RDATDLY_2BIT            (0x0002u)
#define MCBSP_RCR2_RFIG_YES                (0x0000u)
#define MCBSP_RCR2_RFIG_NO                 (0x0001u)
#define MCBSP_RCR2_RCOMPAND_MSB            (0x0000u)
#define MCBSP_RCR2_RCOMPAND_8BITLSB        (0x0001u)
#define MCBSP_RCR2_RCOMPAND_ULAW           (0x0002u)
#define MCBSP_RCR2_RCOMPAND_ALAW           (0x0003u)
#define MCBSP_RCR2_RWDLEN2_8BIT            (0x0000u)
#define MCBSP_RCR2_RWDLEN2_12BIT           (0x0001u)
#define MCBSP_RCR2_RWDLEN2_16BIT           (0x0002u)
#define MCBSP_RCR2_RWDLEN2_20BIT           (0x0003u)
#define MCBSP_RCR2_RWDLEN2_24BIT           (0x0004u)
#define MCBSP_RCR2_RWDLEN2_32BIT           (0x0005u)
#define MCBSP_RCR2_RFRLEN2_OF(x)           ((Uint16)(x))
#define MCBSP_RCR2_RPHASE_SINGLE           (0x0000u)
#define MCBSP_RCR2_RPHASE_DUAL             (0x0001u)


/*===========================================================================*\
* _MCBSP_XCR1   - Transmit Control Register 1
*
* Fields:
*  (RW) _MCBSP_XCR1_XFRLEN1
*  (RW) _MCBSP_XCR1_XWDLEN1
\*==========================================================================*/

/* default XCR1 register value */
#define MCBSP_XCR1_DEFAULT                (0x0000u)



/*---------------------------------------*\
* MCBSP_XCR1_MK Macro
\*---------------------------------------*/

#define MCBSP_XCR1_RMK(xfrlen1,xwdlen1)\
  ((Uint16)(\
    (MCBSP_FMK(XCR1,XWDLEN1,xwdlen1))|\
    (MCBSP_FMK(XCR1,XFRLEN1,xfrlen1))\
  ) \
)

#define MCBSP_XCR1_RMKS(xfrlen1_s,xwdlen1_s)\
  ((Uint16)(\
    (MCBSP_FMKS(XCR1,XWDLEN1,xwdlen1_s))|\
    (MCBSP_FMKS(XCR1,XFRLEN1,xfrlen1_s))\
  ) \
)

/* XCR1 field values */
#define MCBSP_XCR1_XWDLEN1_8BIT            (0x0000u)
#define MCBSP_XCR1_XWDLEN1_12BIT           (0x0001u)
#define MCBSP_XCR1_XWDLEN1_16BIT           (0x0002u)
#define MCBSP_XCR1_XWDLEN1_20BIT           (0x0003u)
#define MCBSP_XCR1_XWDLEN1_24BIT           (0x0004u)
#define MCBSP_XCR1_XWDLEN1_32BIT           (0x0005u)
#define MCBSP_XCR1_XFRLEN1_OF(x)           ((Uint16)(x))


/*===========================================================================*\
*  MCBSP XCR2   - Transmit Control Register 2 Macros
*
* Fields:
*  (RW) XPHASE
*  (RW) XFRLEN2
*  (RW) XWDLEN2
*  (RW) XCOMPAND
*  (RW) XFIG
*  (RW) XDATDLY
\*==========================================================================*/

/* default XCR register value */
#define MCBSP_XCR2_DEFAULT                (0x0000u)


/*---------------------------------------*\
* MCBSP_XCR2_MK Macro
\*---------------------------------------*/

#define MCBSP_XCR2_RMK(xphase,xfrlen2,xwdlen2,xcompand,xfig,xdatdly)\
   ((Uint16)(\
    (MCBSP_FMK(XCR2,XDATDLY,xdatdly))|\
    (MCBSP_FMK(XCR2,XFIG,xfig))|\
    (MCBSP_FMK(XCR2,XCOMPAND,xcompand))|\
    (MCBSP_FMK(XCR2,XWDLEN2,xwdlen2))|\
    (MCBSP_FMK(XCR2,XFRLEN2,xfrlen2))|\
    (MCBSP_FMK(XCR2,XPHASE,xphase))\
  ) \
)

#define MCBSP_XCR2_RMKS(xphase_s,xfrlen2_s,xwdlen2_s,xcompand_s,xfig_s,xdatdly_s)\
   ((Uint16)(\
    (MCBSP_FMKS(XCR2,XDATDLY,xdatdly_s))|\
    (MCBSP_FMKS(XCR2,XFIG,xfig_s))|\
    (MCBSP_FMKS(XCR2,XCOMPAND,xcompand_s))|\
    (MCBSP_FMKS(XCR2,XWDLEN2,xwdlen2_s))|\
    (MCBSP_FMKS(XCR2,XFRLEN2,xfrlen2_s))|\
    (MCBSP_FMKS(XCR2,XPHASE,xphase_s))\
  ) \
)


/* XCR2 field values */
#define MCBSP_XCR2_XDATDLY_0BIT            (0x0000u)
#define MCBSP_XCR2_XDATDLY_1BIT            (0x0001u)
#define MCBSP_XCR2_XDATDLY_2BIT            (0x0002u)
#define MCBSP_XCR2_XFIG_YES                (0x0000u)
#define MCBSP_XCR2_XFIG_NO                 (0x0001u)
#define MCBSP_XCR2_XCOMPAND_MSB            (0x0000u)
#define MCBSP_XCR2_XCOMPAND_8BITLSB        (0x0001u)
#define MCBSP_XCR2_XCOMPAND_ULAW           (0x0002u)
#define MCBSP_XCR2_XCOMPAND_ALAW           (0x0003u)
#define MCBSP_XCR2_XWDLEN2_8BIT            (0x0000u)
#define MCBSP_XCR2_XWDLEN2_12BIT           (0x0001u)
#define MCBSP_XCR2_XWDLEN2_16BIT           (0x0002u)
#define MCBSP_XCR2_XWDLEN2_20BIT           (0x0003u)
#define MCBSP_XCR2_XWDLEN2_24BIT           (0x0004u)
#define MCBSP_XCR2_XWDLEN2_32BIT           (0x0005u)
#define MCBSP_XCR2_XFRLEN2_OF(x)           ((Uint16)(x))
#define MCBSP_XCR2_XPHASE_SINGLE           (0x0000u)
#define MCBSP_XCR2_XPHASE_DUAL             (0x0001u)


/*===========================================================================*\
*  MCBSP SRGR1 -  Sample Rate Generator Register 1 Macros
*
* Fields:
*  (RW) _MCBSP_SRGR1_FWID
*  (RW) _MCBSP_SRGR1_CLKGDV
\*==========================================================================*/

/* default SRGR register value */
#define MCBSP_SRGR1_DEFAULT                (0x0001u)



/*---------------------------------------*\
* MCBSP_SRGR1_MK Macro
\*---------------------------------------*/

#define MCBSP_SRGR1_RMK(fwid,clkgdv) (\
  (Uint16)(\
    (MCBSP_FMK(SRGR1,CLKGDV,clkgdv))|\
    (MCBSP_FMK(SRGR1,FWID,fwid))\
  )\
)

#define MCBSP_SRGR1_RMKS(fwid_s,clkgdv_s) (\
  (Uint16)(\
    (MCBSP_FMKS(SRGR1,CLKGDV,clkgdv_s))|\
    (MCBSP_FMKS(SRGR1,FWID,fwid_s))\
  )\
)

/* SRGR1 field values */
#define MCBSP_SRGR1_CLKGDV_OF(x)           ((Uint16)(x))
#define MCBSP_SRGR1_FWID_OF(x)             ((Uint16)(x))


/*===========================================================================*\
* _MCBSP_SRGR2 -  Sample Rate Generator Register 2
*
* Fields:
*  (RW) _MCBSP_SRGR2_GSYNC
*  (RW) _MCBSP_SRGR2_CLKSP
*  (RW) _MCBSP_SRGR2_CLKSM
*  (RW) _MCBSP_SRGR2_FSGM
*  (RW) _MCBSP_SRGR2_FPER
\*==========================================================================*/

/* default SRGR2 register value */
#define MCBSP_SRGR2_DEFAULT                (0x2000u)


/*---------------------------------------*\
* MCBSP_SRGR2_MK Macro
\*---------------------------------------*/

#define MCBSP_SRGR2_RMK(gsync,clksp,clksm,fsgm,fper)(\
  (Uint16)(\
    (MCBSP_FMK(SRGR2,FPER,fper))|\
    (MCBSP_FMK(SRGR2,FSGM,fsgm))|\
    (MCBSP_FMK(SRGR2,CLKSM,clksm))|\
    (MCBSP_FMK(SRGR2,CLKSP,clksp))|\
    (MCBSP_FMK(SRGR2,GSYNC,gsync))\
  )\
)

#define MCBSP_SRGR2_RMKS(gsync_s,clksp_s,clksm_s,fsgm_s,fper_s)(\
  (Uint16)(\
    (MCBSP_FMKS(SRGR2,FPER,fper_s))|\
    (MCBSP_FMKS(SRGR2,FSGM,fsgm_s))|\
    (MCBSP_FMKS(SRGR2,CLKSM,clksm_s))|\
    (MCBSP_FMKS(SRGR2,CLKSP,clksp_s))|\
    (MCBSP_FMKS(SRGR2,GSYNC,gsync_s))\
  )\
)


/* SRGR2 field values */
#define MCBSP_SRGR2_FPER_OF(x)             ((Uint16)(x))
#define MCBSP_SRGR2_FSGM_DXR2XSR           (0x0000u)
#define MCBSP_SRGR2_FSGM_FSG               (0x0001u)
#define MCBSP_SRGR2_CLKSM_CLKS             (0x0000u)
#define MCBSP_SRGR2_CLKSM_INTERNAL         (0x0001u)
#define MCBSP_SRGR2_CLKSP_RISING           (0x0000u)
#define MCBSP_SRGR2_CLKSP_FALLING          (0x0001u)
#define MCBSP_SRGR2_GSYNC_FREE             (0x0000u)
#define MCBSP_SRGR2_GSYNC_SYNC             (0x0001u)


/*===========================================================================*\
*  MCBSP MCR1 -  Multi-channel Control Register 1 Macros
*
* Fields:
*  (RW) RMCME
*  (RW) RPBBLK
*  (RW) RPABLK
*  (R)  RCBLK
*  (RW) RMCM
\*==========================================================================*/

/* default MCR register value */
#define MCBSP_MCR1_DEFAULT                 (0x0000u)

/*---------------------------------------*\
* MCBSP_MCR1_MK Macro
\*---------------------------------------*/

    #define MCBSP_MCR1_RMK(rmcme, rpbblk, rpablk, rcblk, rmcm)\
  ((Uint16)(\
     (MCBSP_FMK(MCR1,RMCM,rmcm))    |\
     (MCBSP_FMK(MCR1,RPABLK,rpablk))|\
     (MCBSP_FMK(MCR1,RPBBLK,rpbblk))|\
     (MCBSP_FMK(MCR1,RCBLK,rcblk))  |\
     (MCBSP_FMK(MCR1,RMCME,rmcme))   \
    )\
  )

    #define MCBSP_MCR1_RMKS(rmcme_s,rpbblk_s, rpablk_s, rcblk_s, rmcm_s)\
  ((Uint16)(\
     (MCBSP_FMKS(MCR1,RMCM,rmcm_s))    |\
     (MCBSP_FMKS(MCR1,RPABLK,rpablk_s))|\
     (MCBSP_FMKS(MCR1,RPBBLK,rpbblk_s))|\
     (MCBSP_FMKS(MCR1,RCBLK,rcblk_s))  |\
     (MCBSP_FMKS(MCR1,RMCME,rmcme_s))   \
    )\
  )

/* MCR1 field values */
#define MCBSP_MCR1_RMCM_CHENABLE           (0x0000u)
#define MCBSP_MCR1_RMCM_ELDISABLE          (0x0001u)
#define MCBSP_MCR1_RCBLK_SF0               (0x0000u)
#define MCBSP_MCR1_RCBLK_SF1               (0x0001u)
#define MCBSP_MCR1_RCBLK_SF2               (0x0002u)
#define MCBSP_MCR1_RCBLK_SF3               (0x0003u)
#define MCBSP_MCR1_RCBLK_SF4               (0x0004u)
#define MCBSP_MCR1_RCBLK_SF5               (0x0005u)
#define MCBSP_MCR1_RCBLK_SF6               (0x0006u)
#define MCBSP_MCR1_RCBLK_SF7               (0x0007u)
#define MCBSP_MCR1_RPABLK_SF0              (0x0000u)
#define MCBSP_MCR1_RPABLK_SF2              (0x0001u)
#define MCBSP_MCR1_RPABLK_SF4              (0x0002u)
#define MCBSP_MCR1_RPABLK_SF6              (0x0003u)
#define MCBSP_MCR1_RPBBLK_SF1              (0x0000u)
#define MCBSP_MCR1_RPBBLK_SF3              (0x0001u)
#define MCBSP_MCR1_RPBBLK_SF5              (0x0002u)
#define MCBSP_MCR1_RPBBLK_SF7              (0x0003u)
#define MCBSP_MCR1_RMCME_NO                (0x0000u)
#define MCBSP_MCR1_RMCME_AtoH              (0x0001u)


/*===========================================================================*\
* MCBSP MCR2 -  Multi-channel Control Register 2 Macros
*
* Fields:
*  (RW) _MCBSP_MCR2_XMCME
*  (RW) _MCBSP_MCR2_XPBBLK
*  (RW) _MCBSP_MCR2_XPABLK
*  (R)  _MCBSP_MCR2_XCBLK
*  (RW) _MCBSP_MCR2_XMCM
\*==========================================================================*/

/* default MCR register value */
#define MCBSP_MCR2_DEFAULT                 (0x0000u)


/*---------------------------------------*\
* MCBSP_MCR2_MK Macro
\*---------------------------------------*/

   #define MCBSP_MCR2_RMK(xmcme,xpbblk,xpablk,xcblk,xmcm)\
  ( (Uint16)(\
      (MCBSP_FMK(MCR2,XMCM,xmcm))    |\
      (MCBSP_FMK(MCR2,XPABLK,xpablk))|\
      (MCBSP_FMK(MCR2,XPBBLK,xpbblk))|\
      (MCBSP_FMK(MCR2,XCBLK,xcblk))  |\
      (MCBSP_FMK(MCR2,XMCME,xmcme))   \
     )\
   )

   #define MCBSP_MCR2_RMKS(xmcme_s,xpbblk_s,xpablk_s,xcblk_s,xmcm_s)\
  ( (Uint16)(\
      (MCBSP_FMKS(MCR2,XMCM,xmcm_s))    |\
      (MCBSP_FMKS(MCR2,XPABLK,xpablk_s))|\
      (MCBSP_FMKS(MCR2,XPBBLK,xpbblk_s))|\
      (MCBSP_FMKS(MCR2,XCBLK,xcblk_s))  |\
      (MCBSP_FMKS(MCR2,XMCME,xmcme_s))   \
     )\
   )



/* MCR2 field values */

#define MCBSP_MCR2_XMCM_ENNOMASK           (0x0000u)
#define MCBSP_MCR2_XMCM_DISXP              (0x0001u)
#define MCBSP_MCR2_XMCM_ENMASK             (0x0002u)
#define MCBSP_MCR2_XMCM_DISRP              (0x0003u)
#define MCBSP_MCR2_XCBLK_SF0               (0x0000u)
#define MCBSP_MCR2_XCBLK_SF1               (0x0001u)
#define MCBSP_MCR2_XCBLK_SF2               (0x0002u)
#define MCBSP_MCR2_XCBLK_SF3               (0x0003u)
#define MCBSP_MCR2_XCBLK_SF4               (0x0004u)
#define MCBSP_MCR2_XCBLK_SF5               (0x0005u)
#define MCBSP_MCR2_XCBLK_SF6               (0x0006u)
#define MCBSP_MCR2_XCBLK_SF7               (0x0007u)
#define MCBSP_MCR2_XPABLK_SF0              (0x0000u)
#define MCBSP_MCR2_XPABLK_SF2              (0x0001u)
#define MCBSP_MCR2_XPABLK_SF4              (0x0002u)
#define MCBSP_MCR2_XPABLK_SF6              (0x0003u)
#define MCBSP_MCR2_XPBBLK_SF1              (0x0000u)
#define MCBSP_MCR2_XPBBLK_SF3              (0x0001u)
#define MCBSP_MCR2_XPBBLK_SF5              (0x0002u)
#define MCBSP_MCR2_XPBBLK_SF7              (0x0003u)
#define MCBSP_MCR2_XMCME_NO                (0x0000u)
#define MCBSP_MCR2_XMCME_AtoH              (0x0001u)


/*===========================================================================
* MCBSP RCERA -  Receive Channel Enable Register A Macros
*
* Fields:
*  (RW) RCE15
*  (RW) RCE14
*  (RW) RCE13
*  (RW) RCE12
*  (RW) RCE11
*  (RW) RCE10
*  (RW) RCE9
*  (RW) RCE8
*  (RW) RCE7
*  (RW) RCE6
*  (RW) RCE5
*  (RW) RCE4
*  (RW) RCE3
*  (RW) RCE2
*  (RW) RCE1
*  (RW) RCE0
\*==========================================================================*/

/* default RCER register value */
#define MCBSP_RCERA_DEFAULT                (0x0000u)


/*---------------------------------------*\
* MCBSP_RCERA_MK Macro
\*---------------------------------------*/

#define MCBSP_RCERA_RMK(rcea)((Uint16)(\
    (((Uint16)(rcea))&0xFFFFu)\
  )\
)\

/*===========================================================================
* MCBSP RCERB -  Receive Channel Enable Register B Macros
\*==========================================================================*/

/* default RCER register value */
#define MCBSP_RCERB_DEFAULT                (0x0000u)


/*---------------------------------------*\
* MCBSP_RCERB_MK Macro
\*---------------------------------------*/

#define MCBSP_RCERB_RMK(rceb)((Uint16)(\
    (((Uint16)(rceb))&0xFFFFu)\
  )\
)\

/*===========================================================================
* MCBSP RCERC -  Receive Channel Enable Register C Macros
\*==========================================================================*/

/* default RCER register value */
#define MCBSP_RCERC_DEFAULT                (0x0000u)


/*---------------------------------------*\
* MCBSP_RCERC_MK Macro
\*---------------------------------------*/

#define MCBSP_RCERC_RMK(rcec)((Uint16)(\
    (((Uint16)(rcec))&0xFFFFu)\
  )\
)\

/*===========================================================================
* MCBSP RCERD -  Receive Channel Enable Register D Macros
\*==========================================================================*/

/* default RCER register value */
#define MCBSP_RCERD_DEFAULT                (0x0000u)


/*---------------------------------------*\
* MCBSP_RCERD_MK Macro
\*---------------------------------------*/

#define MCBSP_RCERD_RMK(rced)((Uint16)(\
    (((Uint16)(rced))&0xFFFFu)\
  )\
)\


/*===========================================================================
* MCBSP RCERE -  Receive Channel Enable Register E Macros
\*==========================================================================*/

/* default RCER register value */
#define MCBSP_RCERE_DEFAULT                (0x0000u)


/*---------------------------------------*\
* MCBSP_RCERE_MK Macro
\*---------------------------------------*/

#define MCBSP_RCERE_RMK(rcee)((Uint16)(\
    (((Uint16)(rcee))&0xFFFFu)\
  )\
)\

/*===========================================================================
* MCBSP RCERF -  Receive Channel Enable Register F Macros
\*==========================================================================*/

/* default RCER register value */
#define MCBSP_RCERF_DEFAULT                (0x0000u)


/*---------------------------------------*\
* MCBSP_RCERF_MK Macro
\*---------------------------------------*/

#define MCBSP_RCERF_RMK(rcef)((Uint16)(\
    (((Uint16)(rcef))&0xFFFFu)\
  )\
)\

/*===========================================================================
* MCBSP RCERG -  Receive Channel Enable Register G Macros
\*==========================================================================*/

/* default RCER register value */
#define MCBSP_RCERG_DEFAULT                (0x0000u)


/*---------------------------------------*\
* MCBSP_RCERG_GET Macro
\*---------------------------------------*/

/*---------------------------------------*\
* MCBSP_RCERG_MK Macro
\*---------------------------------------*/

#define MCBSP_RCERG_RMK(rceg)((Uint16)(\
    (((Uint16)(rceg))&0xFFFFu)\
  )\
)\


/*===========================================================================
* MCBSP RCERH -  Receive Channel Enable Register G Macros
\*==========================================================================*/

/* default RCER register value */
#define MCBSP_RCERH_DEFAULT                (0x0000u)


/*---------------------------------------*\
* MCBSP_RCERH_RMK Macro
\*---------------------------------------*/

#define MCBSP_RCERH_RMK(rceh)((Uint16)(\
    (((Uint16)(rceh))&0xFFFFu)\
  )\
)\


/*===========================================================================*\
* MCBSP XCERA -  Transmit Channel Enable Register A
*
* Fields:
*  (RW) XCE15
*  (RW) XCE14
*  (RW) XCE13
*  (RW) XCE12
*  (RW) XCE11
*  (RW) XCE10
*  (RW) XCE9
*  (RW) XCE8
*  (RW) XCE7
*  (RW) XCE6
*  (RW) XCE5
*  (RW) XCE4
*  (RW) XCE3
*  (RW) XCE2
*  (RW) XCE1
*  (RW) XCE0
\*==========================================================================*/

/* default XCERA register value */
#define MCBSP_XCERA_DEFAULT                (0x0000u)



/*---------------------------------------*\
* MCBSP_XCERA_MK Macro
\*---------------------------------------*/

#define MCBSP_XCERA_RMK(xcea) ((Uint16)(\
    (((Uint16)(xcea))&0xFFFFu)\
  )\
)

/*===========================================================================*\
* MCBSP XCERB -  Transmit Channel Enable Register B
\*==========================================================================*/


/* default XCERB register value */
#define MCBSP_XCERB_DEFAULT                (0x0000u)


/*---------------------------------------*\
* MCBSP_XCERB_MK Macro
\*---------------------------------------*/

#define MCBSP_XCERB_RMK(xceb) ((Uint16)(\
    (((Uint16)(xceb))&0xFFFFu)\
  )\
)



/*===========================================================================*\
* MCBSP XCERC -  Transmit Channel Enable Register C
\*==========================================================================*/

/* default XCER register value */
#define MCBSP_XCERC_DEFAULT                (0x0000u)


/*---------------------------------------*\
* MCBSP_XCERC_MK Macro
\*---------------------------------------*/

#define MCBSP_XCERC_RMK(xcec) ((Uint16)(\
    (((Uint16)(xcec))&0xFFFFu)\
  )\
)

/*===========================================================================*\
* MCBSP XCERD -  Transmit Channel Enable Register D
\*==========================================================================*/

/* default XCERD register value */
#define MCBSP_XCERD_DEFAULT                (0x0000u)


/*---------------------------------------*\
* MCBSP_XCERD_MK Macro
\*---------------------------------------*/

#define MCBSP_XCERD_RMK(xced) ((Uint16)(\
    (((Uint16)(xced))&0xFFFFu)\
  )\
)

/*===========================================================================*\
* MCBSP XCERE -  Transmit Channel Enable Register E
\*==========================================================================*/

/* default XCERE register value */
#define MCBSP_XCERE_DEFAULT                (0x0000u)


/*---------------------------------------*\
* MCBSP_XCERE_MK Macro
\*---------------------------------------*/

#define MCBSP_XCERE_RMK(xcee) ((Uint16)(\
    (((Uint16)(xcee))&0xFFFFu)\
  )\
)


/*===========================================================================*\
* MCBSP XCERF -  Transmit Channel Enable Register F
\*==========================================================================*/

/* default XCERF register value */
#define MCBSP_XCERF_DEFAULT                (0x0000u)


/*---------------------------------------*\
* MCBSP_XCERF_MK Macro
\*---------------------------------------*/

#define MCBSP_XCERF_RMK(xcef) ((Uint16)(\
    (((Uint16)(xcef))&0xFFFFu)\
  )\
)

/*===========================================================================*\
* MCBSP XCERG -  Transmit Channel Enable Register G
\*==========================================================================*/

/* default XCERG register value */
#define MCBSP_XCERG_DEFAULT                (0x0000u)


/*---------------------------------------*\
* MCBSP_XCERG_MK Macro
\*---------------------------------------*/

#define MCBSP_XCERG_RMK(xceg) ((Uint16)(\
    (((Uint16)(xceg))&0xFFFFu)\
  )\
)

/*===========================================================================*\
* MCBSP XCERH -  Transmit Channel Enable Register H
\*==========================================================================*/

/* default XCERH register value */
#define MCBSP_XCERH_DEFAULT                (0x0000u)


/*---------------------------------------*\
* MCBSP_XCERH_MK Macro
\*---------------------------------------*/

#define MCBSP_XCERH_RMK(xceh) (Uint16)(\
    (((Uint16)(xceh))&0xFFFFu)\
  )\

#define MCBSP_XCER_RMK(xce15,xce14,xce13,xce12,xce11,xce10,xce9,xce8,\
                     xce7,xce6,xce5,xce4,xce3,xce2,xce1,xce0)\
  (Uint16) (MCBSP_FMK(XCERA,XCE15,xce15)   |\
            MCBSP_FMK(XCERA,XCE14,xce14)   |\
            MCBSP_FMK(XCERA,XCE13,xce13)   |\
            MCBSP_FMK(XCERA,XCE12,xce12)   |\
            MCBSP_FMK(XCERA,XCE11,xce11)   |\
            MCBSP_FMK(XCERA,XCE10,xce10)   |\
            MCBSP_FMK(XCERA,XCE9,xce9)     |\
            MCBSP_FMK(XCERA,XCE8,xce8)     |\
            MCBSP_FMK(XCERA,XCE7,xce7)     |\
            MCBSP_FMK(XCERA,XCE6,xce6)     |\
            MCBSP_FMK(XCERA,XCE5,xce5)     |\
            MCBSP_FMK(XCERA,XCE4,xce4)     |\
            MCBSP_FMK(XCERA,XCE3,xce3)     |\
            MCBSP_FMK(XCERA,XCE2,xce2)     |\
            MCBSP_FMK(XCERA,XCE1,xce1)     |\
            MCBSP_FMK(XCERA,XCE0,xce0)      \
)

#define MCBSP_RCER_RMK(rce15,rce14,rce13,rce12,rce11,rce10,rce9,rce8,\
                     rce7,rce6,rce5,rce4,rce3,rce2,rce1,rce0)\
  (Uint16) (MCBSP_FMK(RCERA,RCE15,rce15)   |\
            MCBSP_FMK(RCERA,RCE14,rce14)   |\
            MCBSP_FMK(RCERA,RCE13,rce13)   |\
            MCBSP_FMK(RCERA,RCE12,rce12)   |\
            MCBSP_FMK(RCERA,RCE11,rce11)   |\
            MCBSP_FMK(RCERA,RCE10,rce10)   |\
            MCBSP_FMK(RCERA,RCE9,rce9)     |\
            MCBSP_FMK(RCERA,RCE8,rce8)     |\
            MCBSP_FMK(RCERA,RCE7,rce7)     |\
            MCBSP_FMK(RCERA,RCE6,rce6)     |\
            MCBSP_FMK(RCERA,RCE5,rce5)     |\
            MCBSP_FMK(RCERA,RCE4,rce4)     |\
            MCBSP_FMK(RCERA,RCE3,rce3)     |\
            MCBSP_FMK(RCERA,RCE2,rce2)     |\
            MCBSP_FMK(RCERA,RCE1,rce1)     |\
            MCBSP_FMK(RCERA,RCE0,rce0)      \
)

/*===========================================================================/
* MCBSP PCR   - Pin Control Register Macros
*
* Fields:
*  (RW) SCLKME
*  (R)  CLKSSTAT
*  (RW) DXSTAT
*  (R)  DRSTAT
*  (RW) FSXP
*  (RW) FSRP
*  (RW) CLKXP
*  (RW) CLKRP
*  (RW) IDLEEN
*  (RW) XIOEN
*  (RW) RIOEN
*  (RW) FSXM
*  (RW) FSRM
*  (RW) CLKXM
*  (RW) CLKRM
\*==========================================================================*/

/* default PCR register value */
#define MCBSP_PCR_DEFAULT                 (0x0000u)

/*---------------------------------------*\
* MCBSP_PCR_MK Macro
\*---------------------------------------*/

#if(((CHIP_5502) || (CHIP_5501))==0)

#define MCBSP_PCR_RMK(idleen,xioen,rioen,fsxm,fsrm,clkxm,clkrm,\
						sclkme,dxstat,fsxp,fsrp,clkxp,clkrp) \
   ((Uint16)(\
       (MCBSP_FMK(PCR,CLKRP,clkrp))       |\
       (MCBSP_FMK(PCR,CLKXP,clkxp))       |\
       (MCBSP_FMK(PCR,FSRP,fsrp))         |\
       (MCBSP_FMK(PCR,FSXP,fsxp))         |\
       (MCBSP_FMK(PCR,CLKRM,clkrm))       |\
       (MCBSP_FMK(PCR,CLKXM,clkxm))       |\
       (MCBSP_FMK(PCR,DXSTAT,dxstat))     |\
       (MCBSP_FMK(PCR,SCLKME,sclkme))     |\
       (MCBSP_FMK(PCR,FSRM,fsrm))         |\
       (MCBSP_FMK(PCR,FSXM,fsxm))         |\
       (MCBSP_FMK(PCR,RIOEN,rioen))       |\
       (MCBSP_FMK(PCR,XIOEN,xioen))       |\
       (MCBSP_FMK(PCR,IDLEEN,idleen))      \
       )\
     )

#define MCBSP_PCR_RMKS(idleen_s,xioen_s,rioen_s,fsxm_s,fsrm_s,clkxm_s,clkrm_s,\
						sclkme_s,dxstat_s,fsxp_s,fsrp_s,clkxp_s,clkrp_s) \
   ((Uint16)(\
       (MCBSP_FMKS(PCR,CLKRP,clkrp_s))|\
       (MCBSP_FMKS(PCR,CLKXP,clkxp_s))|\
       (MCBSP_FMKS(PCR,FSRP,fsrp_s))|\
       (MCBSP_FMKS(PCR,FSXP,fsxp_s))|\
       (MCBSP_FMKS(PCR,CLKRM,clkrm_s))|\
       (MCBSP_FMKS(PCR,DXSTAT,dxstat_s))|\
       (MCBSP_FMKS(PCR,CLKXM,clkxm_s))|\
       (MCBSP_FMKS(PCR,SCLKME,sclkme_s))|\
       (MCBSP_FMKS(PCR,FSRM,fsrm_s))|\
       (MCBSP_FMKS(PCR,FSXM,fsxm_s))|\
       (MCBSP_FMKS(PCR,RIOEN,rioen_s))|\
       (MCBSP_FMKS(PCR,XIOEN,xioen_s))|\
       (MCBSP_FMKS(PCR,IDLEEN,idleen_s))\
       )\
     )

#else
#define MCBSP_PCR_RMK(xioen,rioen,fsxm,fsrm,clkxm,clkrm,\
						sclkme,dxstat,fsxp,fsrp,clkxp,clkrp) \
   ((Uint16)(\
       (MCBSP_FMK(PCR,CLKRP,clkrp))       |\
       (MCBSP_FMK(PCR,CLKXP,clkxp))       |\
       (MCBSP_FMK(PCR,FSRP,fsrp))         |\
       (MCBSP_FMK(PCR,FSXP,fsxp))         |\
       (MCBSP_FMK(PCR,CLKRM,clkrm))       |\
       (MCBSP_FMK(PCR,CLKXM,clkxm))       |\
       (MCBSP_FMK(PCR,DXSTAT,dxstat))     |\
       (MCBSP_FMK(PCR,SCLKME,sclkme))     |\
       (MCBSP_FMK(PCR,FSRM,fsrm))         |\
       (MCBSP_FMK(PCR,FSXM,fsxm))         |\
       (MCBSP_FMK(PCR,RIOEN,rioen))       |\
       (MCBSP_FMK(PCR,XIOEN,xioen))       \
       )\
     )

#define MCBSP_PCR_RMKS(xioen_s,rioen_s,fsxm_s,fsrm_s,clkxm_s,clkrm_s,\
						sclkme_s,dxstat_s,fsxp_s,fsrp_s,clkxp_s,clkrp_s) \
   ((Uint16)(\
       (MCBSP_FMKS(PCR,CLKRP,clkrp_s))|\
       (MCBSP_FMKS(PCR,CLKXP,clkxp_s))|\
       (MCBSP_FMKS(PCR,FSRP,fsrp_s))|\
       (MCBSP_FMKS(PCR,FSXP,fsxp_s))|\
       (MCBSP_FMKS(PCR,CLKRM,clkrm_s))|\
       (MCBSP_FMKS(PCR,CLKXM,clkxm_s))|\
       (MCBSP_FMKS(PCR,SCLKME,sclkme_s))|\
       (MCBSP_FMKS(PCR,FSRM,fsrm_s))|\
       (MCBSP_FMKS(PCR,FSXM,fsxm_s))|\
       (MCBSP_FMKS(PCR,RIOEN,rioen_s))|\
       (MCBSP_FMKS(PCR,XIOEN,xioen_s))\
       )\
     )

#endif

/* PCR field values */
#define MCBSP_PCR_CLKRP_FALLING           (0x0000u)
#define MCBSP_PCR_CLKRP_RISING            (0x0001u)
#define MCBSP_PCR_CLKXP_RISING            (0x0000u)
#define MCBSP_PCR_CLKXP_FALLING           (0x0001u)
#define MCBSP_PCR_FSRP_ACTIVEHIGH         (0x0000u)
#define MCBSP_PCR_FSRP_ACTIVELOW          (0x0001u)
#define MCBSP_PCR_FSXP_ACTIVEHIGH         (0x0000u)
#define MCBSP_PCR_FSXP_ACTIVELOW          (0x0001u)
#define MCBSP_PCR_DRSTAT_0                (0x0000u)
#define MCBSP_PCR_DRSTAT_1                (0x0001u)
#define MCBSP_PCR_DXSTAT_0                (0x0000u)
#define MCBSP_PCR_DXSTAT_1                (0x0001u)
#define MCBSP_PCR_CLKSSTAT_0              (0x0000u)
#define MCBSP_PCR_CLKSSTAT_1              (0x0001u)

#if (((CHIP_5502) || (CHIP_5501))==0)

#define MCBSP_PCR_IDLEEN_RESET            (0x0000u)
#define MCBSP_PCR_IDLEEN_ON               (0x0001u)

#endif

#define MCBSP_PCR_SCLKME_BCLK             (0x0001u)
#define MCBSP_PCR_SCLKME_NO               (0x0000u)
#define MCBSP_PCR_CLKRM_INPUT             (0x0000u)
#define MCBSP_PCR_CLKRM_OUTPUT            (0x0001u)
#define MCBSP_PCR_CLKXM_INPUT             (0x0000u)
#define MCBSP_PCR_CLKXM_OUTPUT            (0x0001u)
#define MCBSP_PCR_FSRM_EXTERNAL           (0x0000u)
#define MCBSP_PCR_FSRM_INTERNAL           (0x0001u)
#define MCBSP_PCR_FSXM_EXTERNAL           (0x0000u)
#define MCBSP_PCR_FSXM_INTERNAL           (0x0001u)
#define MCBSP_PCR_RIOEN_SP                (0x0000u)
#define MCBSP_PCR_RIOEN_GPIO              (0x0001u)
#define MCBSP_PCR_XIOEN_SP                (0x0000u)
#define MCBSP_PCR_XIOEN_GPIO              (0x0001u)

/****************************************\
* MCBSP global typedef declarations
\****************************************/

/* device handle type */
typedef struct {
  Uint32 Private;
} MCBSP_Private,*MCBSP_Handle;

/* private object, not to be used by application code */
/* device configuration structure */
typedef struct {
  Uint16 spcr1;
  Uint16 spcr2;
  Uint16 rcr1;
  Uint16 rcr2;
  Uint16 xcr1;
  Uint16 xcr2;
  Uint16 srgr1;
  Uint16 srgr2;
  Uint16 mcr1;
  Uint16 mcr2;
  Uint16 pcr;
  Uint16 rcera;
  Uint16 rcerb;
  Uint16 rcerc;
  Uint16 rcerd;
  Uint16 rcere;
  Uint16 rcerf;
  Uint16 rcerg;
  Uint16 rcerh;
  Uint16 xcera;
  Uint16 xcerb;
  Uint16 xcerc;
  Uint16 xcerd;
  Uint16 xcere;
  Uint16 xcerf;
  Uint16 xcerg;
  Uint16 xcerh;

} MCBSP_Config;



/****************************************\
* MCBSP global variable declarations
\****************************************/

/****************************************\
* MCBSP global function declarations
\****************************************/
CSLAPI void MCBSP_init();
CSLAPI void MCBSP_reset(MCBSP_Handle _MCBSP);

CSLAPI MCBSP_Handle MCBSP_open(int DevNum, Uint32 Flags);
CSLAPI void MCBSP_close(MCBSP_Handle _MCBSP);

CSLAPI void MCBSP_config(MCBSP_Handle _MCBSP, MCBSP_Config *Config);
CSLAPI void MCBSP_configArgs(MCBSP_Handle _MCBSP, Uint16 spcr1, Uint16 spcr2,
  Uint16 rcr1, Uint16 rcr2, Uint16 xcr1, Uint16 xcr2,
  Uint16 srgr1, Uint16 srgr2,Uint16 mcr1, Uint16 mcr2,Uint16 pcr,
  Uint16 rcera, Uint16 rcerb, Uint16 rcerc, Uint16 rcerd,
  Uint16 rcere, Uint16 rcerf,Uint16 rcerg, Uint16 rcerh,
  Uint16 xcera,Uint16 xcerb, Uint16 xcerc,Uint16 xcerd,
  Uint16 xcere,Uint16 xcerf,Uint16 xcerg,Uint16 xcerh);

CSLAPI void MCBSP_getConfig(MCBSP_Handle _MCBSP, MCBSP_Config *Config);
CSLAPI CSLBool MCBSP_start(MCBSP_Handle hMcbsp, Uint16 StartMask, Uint32 SampleRateDelay);

/*------------------------------------------*\
 * Static Inline Functions
\*------------------------------------------*/

IDECL Uint32 MCBSP_read32(MCBSP_Handle _MCBSP);
IDECL void MCBSP_write32(MCBSP_Handle _MCBSP,Uint32 Val);
IDECL Uint16 MCBSP_read16(MCBSP_Handle _MCBSP);
IDECL Uint16 MCBSP_read(MCBSP_Handle _MCBSP);
IDECL void MCBSP_write16(MCBSP_Handle _MCBSP,Uint16 Val);
IDECL void MCBSP_write(MCBSP_Handle _MCBSP,Uint16 Val);

#ifdef USEDEFS
/*-----------------------------------------------------------------*/
IDEF Uint32 MCBSP_read32(MCBSP_Handle _MCBSP) {
  Uint16 drr2, drr1;
  Uint32 val;
  MCBSP_ASSERT_HANDLE(_MCBSP,return 0xFFFFFFFF);
  drr2 = _PREG_GET(((MCBSP_PrivateObj*)_MCBSP)->Drr2Addr);
  drr1 = _PREG_GET(((MCBSP_PrivateObj*)_MCBSP)->Drr1Addr);
  val = (((Uint32)drr2<<16)&0xFFFF0000 )|(drr1 &0x0000FFFF);
  return val;
}
/*-----------------------------------------------------------------*/
IDEF void MCBSP_write32(MCBSP_Handle _MCBSP,Uint32 Val) {
  MCBSP_ASSERT_HANDLE(_MCBSP,return);
  _PREG_SET((((MCBSP_PrivateObj*)_MCBSP)->Dxr2Addr),(Val>>16));
  _PREG_SET((((MCBSP_PrivateObj*)_MCBSP)->Dxr1Addr),(Val&0x0000FFFF));
}
/*-----------------------------------------------------------------*/
IDEF Uint16 MCBSP_read16(MCBSP_Handle _MCBSP) {
  Uint16 val;
  MCBSP_ASSERT_HANDLE(_MCBSP,return 0xFFFFFFFF);
  val = _PREG_GET(((MCBSP_PrivateObj*)_MCBSP)->Drr1Addr);
  return val;
}
/*-----------------------------------------------------------------*/
IDEF Uint16 MCBSP_read(MCBSP_Handle _MCBSP) {
  Uint16 val;
  MCBSP_ASSERT_HANDLE(_MCBSP,return 0xFFFFFFFF);
  val = _PREG_GET(((MCBSP_PrivateObj*)_MCBSP)->Drr1Addr);
  return val;
}
/*-----------------------------------------------------------------*/
IDEF void MCBSP_write16(MCBSP_Handle _MCBSP,Uint16 Val) {
MCBSP_ASSERT_HANDLE(_MCBSP,return);
_PREG_SET((((MCBSP_PrivateObj*)_MCBSP)->Dxr1Addr),(Val));
}
/*-----------------------------------------------------------------*/
IDEF void MCBSP_write(MCBSP_Handle _MCBSP,Uint16 Val) {
MCBSP_ASSERT_HANDLE(_MCBSP,return);
_PREG_SET((((MCBSP_PrivateObj*)_MCBSP)->Dxr1Addr),(Val));
}
#endif /* USEDEFS */

#endif /* MCBSP_SUPPORT */
#endif /* _MCBSP_H_ */
/******************************************************************************\
* End of csl_mcbsp.h
\******************************************************************************/

