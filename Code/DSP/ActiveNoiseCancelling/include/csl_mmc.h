/************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved 
*------------------------------------------------------------------------
* MODULE NAME... MMC
* FILENAME...... csl_mmc.h
* DATE CREATED.. Thu May 24 14:48:09 2001
* PROJECT....... Chip Support Library
* COMPONENT..... Service Layer
* PREREQUISITS.. 
*------------------------------------------------------------------------
*
* HISTORY:
*	 Created:		Thu May 24 14:48:09 2001 (Automatic generation)
*	 Modified:	Wd April 9 2003 changed reg names MMCCIE ==> MMCIM
*                 MMCFCLK ==> MMCFCLKCTL as per SPSR163D
*
*------------------------------------------------------------------------
* DESCRIPTION: CSL Service Layer interface for the MMC module 
*
\*************************************************************************/

#ifndef _CSL_MMC_H_
#define _CSL_MMC_H_

#include <_csl.h>
#include <csl_mmchal.h>

#if (_MMC_SUPPORT) 

/*----------------------------------------------------------------*\
*	 MMC scope and inline control macros 			
\*----------------------------------------------------------------*/

#ifdef __cplusplus
#define CSLAPI extern "C"
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _MMC_MOD_
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
* MMC global macro declarations
\****************************************/

/* error codes */
#define MMC_ERR_MAJOR		   (ERR_BASE_MMC) 
#define MMC_ERR_ALLOC		   (0x00000000) 
#define MMC_ERR_INVALID_HANDLE     (0x00000001) 

#define MMC_DEVICE_CNT		   _MMC_DEVICE_CNT

/* MMC_Open() flags */
#define MMC_OPEN_RESET	           (0x0001)

/* device identifiers for MMC_Open() */
#define MMC_DEVANY  (-1)
#define MMC_DEV0    (0)
#define MMC_DEV1    (1)

/* define a debuging assertion macro for validating device handles */
#ifdef _MCRTE_DEBUG
  #define MMC_ASSERT_HANDLE(hMMC,RetExp) \
    if (hMMC == INV) { \
       ERR_submit(MMC_ERR_MAJOR, MMC_ERR_INVALID_HANDLE); \
       RetExp; \
    } 
#else
  #define MMC_ASSERT_HANDLE(hMMC,RetExp) 
#endif

/* Card Type defined here */
#define SD_CARD  1
#define MMC_CARD 0

/*******************************************\
* MMC global macro definition : ROMABILITY 
\*******************************************/ 
/* Reserved ROM Area for MMCData.h */
/* Data definition */  

/* Predefined Device Handlers */
#define MMC_hDev0   ((MMC_Handle)&(CSL_MMC_DATA.mmc[0]))
#define MMC_hDev1   ((MMC_Handle)&(CSL_MMC_DATA.mmc[1]))


/* ============================================================== */
 /* Make MMCARGH register values based on symbolic constants  */

#define MMC_MMCARGH_RMK(argh)((Uint16)( \
  ( MMC_FMK(MMCARGH,ARGH,argh))\
 )\
)

#define MMC_MMCARGH_RMKS(argh_sym)((Uint16)( \
  ( MMC_FMKS(MMCARGH,ARGH,argh_sym))\
 )\
)

/*  Default MMCARGH register value  */
#define MMC_MMCARGH_DEFAULT		MMC_STUFF_BITS

/*  MMCARGH field values  */
#define MMC_MMCARGH_ARGH_OF(n)      ((Uint16)(n))


/* ============================================================== */
 /* Make MMCARGL register values based on symbolic constants  */

#define MMC_MMCARGL_RMK(argl)((Uint16)( \
  ( MMC_FMK(MMCARGL,ARGL,argl))\
 )\
)

#define MMC_MMCARGL_RMKS(argl_sym)((Uint16)( \
  ( MMC_FMKS(MMCARGL,ARGL,argl_sym))\
 )\
)

/*  Default MMCARGL register value  */
#define MMC_MMCARGL_DEFAULT        MMC_STUFF_BITS

/*  MMCARGL field values  */
#define MMC_MMCARGL_ARGL_OF(n)    ((Uint16)(n))

/* ============================================================== */
 /* Make MMCBLEN register values based on symbolic constants  */

#define MMC_MMCBLEN_RMK(blen)((Uint16)( \
  ( MMC_FMK(MMCBLEN,BLEN,blen))\
 )\
)

#define MMC_MMCBLEN_RMKS(blen_sym)((Uint16)( \
  ( MMC_FMKS(MMCBLEN,BLEN,blen_sym))\
 )\
)

/*  Default MMCBLEN register value  */
#define MMC_MMCBLEN_DEFAULT      (0x0000u)

/*  MMCBLEN field values  */
#define MMC_MMCBLEN_BLEN_OF(n)   ((Uint16)(n))


/* ============================================================== */
 /* Make MMCCIDX register values based on symbolic constants  */

#define MMC_MMCCIDX_RMK(cidx)((Uint16)( \
  ( MMC_FMK(MMCCIDX,CIDX,cidx))\
 )\
)

#define MMC_MMCCIDX_RMKS(cidx_sym)((Uint16)( \
  ( MMC_FMKS(MMCCIDX,CIDX,cidx_sym))\
 )\
)

/*  Default MMCCIDX register value  */

/*  MMCCIDX field values  */


/* ============================================================== */
 /* Make MMCCIE register values based on symbolic constants  */

#define MMC_MMCCIE_RMK(datdne,bsydne,rspdne,toutrd,toutrs,crcwr,crcrd,crcrs,dxrdy,drrdy,dateg)((Uint16)( \
  ( MMC_FMK(MMCCIE,DATDNE,datdne))|\
  ( MMC_FMK(MMCCIE,BSYDNE,bsydne))|\
  ( MMC_FMK(MMCCIE,RSPDNE,rspdne))|\
  ( MMC_FMK(MMCCIE,TOUTRD,toutrd))|\
  ( MMC_FMK(MMCCIE,TOUTRS,toutrs))|\
  ( MMC_FMK(MMCCIE,CRCWR,crcwr))|\
  ( MMC_FMK(MMCCIE,CRCRD,crcrd))|\
  ( MMC_FMK(MMCCIE,CRCRS,crcrs))|\
  ( MMC_FMK(MMCCIE,DXRDY,dxrdy))|\
  ( MMC_FMK(MMCCIE,DRRDY,drrdy))|\
  ( MMC_FMK(MMCCIE,DATEG,dateg))\
 )\
)

#define MMC_MMCCIE_RMKS(datdne_sym,bsydne_sym,rspdne_sym,toutrd_sym,toutrs_sym,crcwr_sym,crcrd_sym,\
                        crcrs_sym,dxrdy_sym,drrdy_sym,dateg_sym)((Uint16)( \
  ( MMC_FMKS(MMCCIE,DATDNE,datdne_sym))|\
  ( MMC_FMKS(MMCCIE,BSYDNE,bsydne_sym))|\
  ( MMC_FMKS(MMCCIE,RSPDNE,rspdne_sym))|\
  ( MMC_FMKS(MMCCIE,TOUTRD,toutrd_sym))|\
  ( MMC_FMKS(MMCCIE,TOUTRS,toutrs_sym))|\
  ( MMC_FMKS(MMCCIE,CRCWR,crcwr_sym))|\
  ( MMC_FMKS(MMCCIE,CRCRD,crcrd_sym))|\
  ( MMC_FMKS(MMCCIE,CRCRS,crcrs_sym))|\
  ( MMC_FMKS(MMCCIE,DXRDY,dxrdy_sym))|\
  ( MMC_FMKS(MMCCIE,DRRDY,drrdy_sym))|\
  ( MMC_FMKS(MMCCIE,DATEG,dateg_sym))\
 )\
)

/*  Default MMCCIE register value  */

/*  MMCCIE field values  */

/* ============================================================== */
 /* Make MMCCLK register values based on symbolic constants  */

#define MMC_MMCCLK_RMK(cdiv,clken)((Uint16)( \
  ( MMC_FMK(MMCCLK,CDIV,cdiv))|\
  ( MMC_FMK(MMCCLK,CLKEN,clken))\
 )\
)

#define MMC_MMCCLK_RMKS(cdiv_sym,clken_sym)((Uint16)( \
  ( MMC_FMKS(MMCCLK,CDIV,cdiv_sym))|\
  ( MMC_FMKS(MMCCLK,CLKEN,clken_sym))\
 )\
)

/*  Default MMCCLK register value  */

/*  MMCCLK field values  */


/* ============================================================== */
 /* Make MMCCMD register values based on symbolic constants  */

#define MMC_MMCCMD_RMK(cmd,bsyexp,rspfmt,write,stream,data,init,dclr)((Uint16)( \
  ( MMC_FMK(MMCCMD,CMD,cmd))|\
  ( MMC_FMK(MMCCMD,BSYEXP,bsyexp))|\
  ( MMC_FMK(MMCCMD,RSPFMT,rspfmt))|\
  ( MMC_FMK(MMCCMD,WRITE,write))|\
  ( MMC_FMK(MMCCMD,STREAM,stream))|\
  ( MMC_FMK(MMCCMD,DATA,data))|\
  ( MMC_FMK(MMCCMD,INIT,init))|\
  ( MMC_FMK(MMCCMD,DCLR,dclr))\
 )\
)

#define MMC_MMCCMD_RMKS(cmd_sym,bsyexp_sym,rspfmt_sym,write_sym,stream_sym,data_sym,init_sym,dclr_sym)((Uint16)( \
  ( MMC_FMKS(MMCCMD,CMD,cmd_sym))|\
  ( MMC_FMKS(MMCCMD,BSYEXP,bsyexp_sym))|\
  ( MMC_FMKS(MMCCMD,RSPFMT,rspfmt_sym))|\
  ( MMC_FMKS(MMCCMD,WRITE,write_sym))|\
  ( MMC_FMKS(MMCCMD,STREAM,stream_sym))|\
  ( MMC_FMKS(MMCCMD,DATA,data_sym))|\
  ( MMC_FMKS(MMCCMD,INIT,init_sym))|\
  ( MMC_FMKS(MMCCMD,DCLR,dclr_sym))\
 )\
)

/*  Default MMCCMD register value  */

/*  MMCCMD field values  */


/* ============================================================== */
 /* Make MMCCTL register values based on symbolic constants  */

#define MMC_MMCCTL_RMK(datrst,cmdrst,width,dateg,dmaen,nacskp,clkpst,clkpre)((Uint16)( \
  ( MMC_FMK(MMCCTL,DATRST,datrst))|\
  ( MMC_FMK(MMCCTL,CMDRST,cmdrst))|\
  ( MMC_FMK(MMCCTL,WIDTH,width))|\
  ( MMC_FMK(MMCCTL,DATEG,dateg))|\
  ( MMC_FMK(MMCCTL,DMAEN,dmaen))|\
  ( MMC_FMK(MMCCTL,NACSKP,nacskp))|\
  ( MMC_FMK(MMCCTL,CLKPST,clkpst))|\
  ( MMC_FMK(MMCCTL,CLKPRE,clkpre))\
 )\
)

#define MMC_MMCCTL_RMKS(datrst_sym,cmdrst_sym,width_sym,dateg_sym,\
                        dmaen_sym,nacskp_sym,clkpst_sym,clkpre_sym)((Uint16)( \
  ( MMC_FMKS(MMCCTL,DATRST,datrst_sym))|\
  ( MMC_FMKS(MMCCTL,CMDRST,cmdrst_sym))|\
  ( MMC_FMKS(MMCCTL,WIDTH,width_sym))|\
  ( MMC_FMKS(MMCCTL,DATEG,dateg_sym))|\
  ( MMC_FMKS(MMCCTL,DMAEN,dmaen_sym))|\
  ( MMC_FMKS(MMCCTL,NACSKP,nacskp_sym))|\
  ( MMC_FMKS(MMCCTL,CLKPST,clkpst_sym))|\
  ( MMC_FMKS(MMCCTL,CLKPRE,clkpre_sym))\
 )\
)

/*  Default MMCCTL register value  */

/*  MMCCTL field values  */


/* ============================================================== */
 /* Make MMCDRR register values based on symbolic constants  */

#define MMC_MMCDRR_RMK(drr)((Uint16)( \
  ( MMC_FMK(MMCDRR,DRR,drr))\
 )\
)

#define MMC_MMCDRR_RMKS(drr_sym)((Uint16)( \
  ( MMC_FMKS(MMCDRR,DRR,drr_sym))\
 )\
)

/*  Default MMCDRR register value  */

/*  MMCDRR field values  */


/* ============================================================== */
 /* Make MMCDRSP register values based on symbolic constants  */

#define MMC_MMCDRSP_RMK(drsp)((Uint16)( \
  ( MMC_FMK(MMCDRSP,DRSP,drsp))\
 )\
)

#define MMC_MMCDRSP_RMKS(drsp_sym)((Uint16)( \
  ( MMC_FMKS(MMCDRSP,DRSP,drsp_sym))\
 )\
)

/*  Default MMCDRSP register value  */

/*  MMCDRSP field values  */


/* ============================================================== */
 /* Make MMCDXR register values based on symbolic constants  */

#define MMC_MMCDXR_RMK(dxr)((Uint16)( \
  ( MMC_FMK(MMCDXR,DXR,dxr))\
 )\
)

#define MMC_MMCDXR_RMKS(dxr_sym)((Uint16)( \
  ( MMC_FMKS(MMCDXR,DXR,dxr_sym))\
 )\
)

/*  Default MMCDXR register value  */

/*  MMCDXR field values  */


/* ============================================================== */
 /* Make MMCFCLK register values based on symbolic constants  */

#define MMC_MMCFCLK_RMK(fdiv,idleen)((Uint16)( \
  ( MMC_FMK(MMCFCLK,FDIV,fdiv))|\
  ( MMC_FMK(MMCFCLK,IDLEEN,idleen))\
 )\
)

#define MMC_MMCFCLK_RMKS(fdiv_sym,idleen_sym)((Uint16)( \
  ( MMC_FMKS(MMCFCLK,FDIV,fdiv_sym))|\
  ( MMC_FMKS(MMCFCLK,IDLEEN,idleen_sym))\
 )\
)

/*  Default MMCFCLK register value  */

/*  MMCFCLK field values  */

/* ============================================================== */
 /* Make MMCNBLC register values based on symbolic constants  */
/*
#define MMC_MMCNBLC_RMK((Uint16)( \
 )\
)

#define MMC_MMCNBLC_RMKS((Uint16)( \
 )\
)
*/
/*  Default MMCNBLC register value  */

/*  MMCNBLC field values  */


/* ============================================================== */
 /* Make MMCNBLK register values based on symbolic constants  */

#define MMC_MMCNBLK_RMK(nblk)((Uint16)( \
  ( MMC_FMK(MMCNBLK,NBLK,nblk))\
 )\
)

#define MMC_MMCNBLK_RMKS(nblk_sym)((Uint16)( \
  ( MMC_FMKS(MMCNBLK,NBLK,nblk_sym))\
 )\
)

/*  Default MMCNBLK register value  */

/*  MMCNBLK field values  */


/* ============================================================== */
 /* Make MMCRSP0 register values based on symbolic constants  */

#define MMC_MMCRSP0_RMK(rsp)((Uint16)( \
  ( MMC_FMK(MMCRSP0,RSP,rsp))\
 )\
)

#define MMC_MMCRSP0_RMKS(rsp_sym)((Uint16)( \
  ( MMC_FMKS(MMCRSP0,RSP,rsp_sym))\
 )\
)

/*  Default MMCRSP0 register value  */

/*  MMCRSP0 field values  */


/* ============================================================== */
 /* Make MMCRSP1 register values based on symbolic constants  */

#define MMC_MMCRSP1_RMK(rsp)((Uint16)( \
  ( MMC_FMK(MMCRSP1,RSP,rsp))\
 )\
)

#define MMC_MMCRSP1_RMKS(rsp_sym)((Uint16)( \
  ( MMC_FMKS(MMCRSP1,RSP,rsp_sym))\
 )\
)

/*  Default MMCRSP1 register value  */

/*  MMCRSP1 field values  */


/* ============================================================== */
 /* Make MMCRSP2 register values based on symbolic constants  */

#define MMC_MMCRSP2_RMK(rsp)((Uint16)( \
  ( MMC_FMK(MMCRSP2,RSP,rsp))\
 )\
)

#define MMC_MMCRSP2_RMKS(rsp_sym)((Uint16)( \
  ( MMC_FMKS(MMCRSP2,RSP,rsp_sym))\
 )\
)

/*  Default MMCRSP2 register value  */

/*  MMCRSP2 field values  */


/* ============================================================== */
 /* Make MMCRSP3 register values based on symbolic constants  */

#define MMC_MMCRSP3_RMK(rsp)((Uint16)( \
  ( MMC_FMK(MMCRSP3,RSP,rsp))\
 )\
)

#define MMC_MMCRSP3_RMKS(rsp_sym)((Uint16)( \
  ( MMC_FMKS(MMCRSP3,RSP,rsp_sym))\
 )\
)

/*  Default MMCRSP3 register value  */

/*  MMCRSP3 field values  */


/* ============================================================== */
 /* Make MMCRSP4 register values based on symbolic constants  */

#define MMC_MMCRSP4_RMK(rsp)((Uint16)( \
  ( MMC_FMK(MMCRSP4,RSP,rsp))\
 )\
)

#define MMC_MMCRSP4_RMKS(rsp_sym)((Uint16)( \
  ( MMC_FMKS(MMCRSP4,RSP,rsp_sym))\
 )\
)

/*  Default MMCRSP4 register value  */

/*  MMCRSP4 field values  */


/* ============================================================== */
 /* Make MMCRSP5 register values based on symbolic constants  */

#define MMC_MMCRSP5_RMK(rsp)((Uint16)( \
  ( MMC_FMK(MMCRSP5,RSP,rsp))\
 )\
)

#define MMC_MMCRSP5_RMKS(rsp_sym)((Uint16)( \
  ( MMC_FMKS(MMCRSP5,RSP,rsp_sym))\
 )\
)

/*  Default MMCRSP5 register value  */

/*  MMCRSP5 field values  */


/* ============================================================== */
 /* Make MMCRSP6 register values based on symbolic constants  */

#define MMC_MMCRSP6_RMK(rsp)((Uint16)( \
  ( MMC_FMK(MMCRSP6,RSP,rsp))\
 )\
)

#define MMC_MMCRSP6_RMKS(rsp_sym)((Uint16)( \
  ( MMC_FMKS(MMCRSP6,RSP,rsp_sym))\
 )\
)

/*  Default MMCRSP6 register value  */

/*  MMCRSP6 field values  */


/* ============================================================== */
 /* Make MMCRSP7 register values based on symbolic constants  */

#define MMC_MMCRSP7_RMK(rsp)((Uint16)( \
  ( MMC_FMK(MMCRSP7,RSP,rsp))\
 )\
)

#define MMC_MMCRSP7_RMKS(rsp_sym)((Uint16)( \
  ( MMC_FMKS(MMCRSP7,RSP,rsp_sym))\
 )\
)

/*  Default MMCRSP7 register value  */

/*  MMCRSP7 field values  */


/* ============================================================== */
 /* Make MMCST0 register values based on symbolic constants  */
/*
#define MMC_MMCST0_RMK((Uint16)( \
 )\
)

#define MMC_MMCST0_RMKS((Uint16)( \
 )\
)
*/
/*  Default MMCST0 register value  */

/*  MMCST0 field values  */


/* ============================================================== */
 /* Make MMCST1 register values based on symbolic constants  */
/*
#define MMC_MMCST1_RMK((Uint16)( \
 )\
)

#define MMC_MMCST1_RMKS((Uint16)( \
 )\
)
*/
/*  Default MMCST1 register value  */

/*  MMCST1 field values  */


/* ============================================================== */
 /* Make MMCTOD register values based on symbolic constants  */

#define MMC_MMCTOD_RMK(tod)((Uint16)( \
  ( MMC_FMK(MMCTOD,TOD,tod))\
 )\
)

#define MMC_MMCTOD_RMKS(tod_sym)((Uint16)( \
  ( MMC_FMKS(MMCTOD,TOD,tod_sym))\
 )\
)

/*  Default MMCTOD register value  */

/*  MMCTOD field values  */


/* ============================================================== */
 /* Make MMCTOR register values based on symbolic constants  */

#define MMC_MMCTOR_RMK(tor)((Uint16)( \
  ( MMC_FMK(MMCTOR,TOR,tor))\
 )\
)

#define MMC_MMCTOR_RMKS(tor_sym)((Uint16)( \
  ( MMC_FMKS(MMCTOR,TOR,tor_sym))\
 )\
)

/*  Default MMCTOR register value  */
#define MMC_MMCTOR_DEFAULT         (0x0000u)

/*  MMCTOR field values  */
#define MMC_MMCTOR_TOR_OF(n)       ((Uint16)(n))

//----------------------------------------------------------------
// MMC PreDefined Symbolic Command Constants
//----------------------------------------------------------------
#define MMC_SET_MMC_MODE        (0x0001)
#define MMC_STUFF_BITS          (0x0000)
#define MMC_RSPNONE		(0x0000)
#define MMC_RSP1                (0x0200)  
#define MMC_RSP2                (0x0400)
#define MMC_RSP3                (0x0600)
#define MMC_RSP4                (0x0200)
#define MMC_RSP5                (0x0200)
#define MMC_RSP6                (0x0200)
#define BUSY_EXPECTED           (0x0100)

#define MMC_CMD0                (0x0000u)
#define MMC_CMD1                (0x0001u)
#define MMC_CMD2                (0x0002u)
#define MMC_CMD3                (0x0003u)
#define MMC_CMD4                (0x0004u)
#define MMC_CMD5                (0x0005u)
#define MMC_CMD6                (0x0006u)
#define MMC_CMD7                (0x0007u)
#define MMC_CMD8                (0x0008u)
#define MMC_CMD9                (0x0009u)
#define MMC_CMD10               (0x000Au)
#define MMC_CMD11               (0x000Bu)
#define MMC_CMD12               (0x000Cu)
#define MMC_CMD13               (0x000Du)
#define MMC_CMD14               (0x000Eu)
#define MMC_CMD15               (0x000Fu)
#define MMC_CMD16               (0x0010u)
#define MMC_CMD17               (0x0011u)
#define MMC_CMD18               (0x0012u)
#define MMC_CMD19               (0x0013u)
#define MMC_CMD20               (0x0014u)
#define MMC_CMD21               (0x0015u)
#define MMC_CMD22               (0x0016u)
#define MMC_CMD23               (0x0017u)
#define MMC_CMD24               (0x0018u)
#define MMC_CMD25               (0x0019u)
#define MMC_CMD26               (0x001Au)
#define MMC_CMD27               (0x001Bu)
#define MMC_CMD28               (0x001Cu)
#define MMC_CMD29               (0x001Du)
#define MMC_CMD30               (0x001Eu)
#define MMC_CMD31               (0x001Fu)
#define MMC_CMD32               (0x0020u)
#define MMC_CMD33               (0x0021u)
#define MMC_CMD34               (0x0022u)
#define MMC_CMD35               (0x0023u)
#define MMC_CMD36               (0x0024u)
#define MMC_CMD37               (0x0025u)
#define MMC_CMD38               (0x0026u)
#define MMC_CMD39               (0x0027u)
#define MMC_CMD40               (0x0028u)
#define MMC_CMD41               (0x0029u)
#define MMC_CMD42               (0x002Au)
#define MMC_CMD43               (0x002Bu)
#define MMC_CMD44               (0x002Cu)
#define MMC_CMD45               (0x002Du)
#define MMC_CMD46               (0x002Eu)
#define MMC_CMD47               (0x002Fu)
#define MMC_CMD48               (0x0030u)
#define MMC_CMD49               (0x0031u)
#define MMC_CMD50               (0x0032u)
#define MMC_CMD51               (0x0033u)
#define MMC_CMD52               (0x0034u)
#define MMC_CMD53               (0x0035u)
#define MMC_CMD54               (0x0036u)
#define MMC_CMD55               (0x0037u)
#define MMC_CMD56               (0x0038u)
#define MMC_CMD57               (0x0039u)
#define MMC_CMD58               (0x003Au)
#define MMC_CMD59               (0x003Bu)
#define MMC_CMD60               (0x003Cu)
#define MMC_CMD61               (0x003Du)
#define MMC_CMD62               (0x003Eu)
#define MMC_CMD63               (0x003Fu)
#define MMC_CMD64               (0x0040u)

/* other fields in the commands */
#define CMD_DCLR                (0x8000)
#define CMD_ADD_INIT_CYCLES     (0x4000)
#define CMD_DATA_TRANSFER       (0x2000)
#define CMD_STREAM_MODE         (0x1000)
#define CMD_WRITE               (0x0800)
#define CMD_READ                (0x0000)

/* commands to be used */
#define MMC_GO_IDLE_STATE          (MMC_CMD0 | MMC_RSPNONE | CMD_ADD_INIT_CYCLES | CMD_DCLR)
#define MMC_SEND_OP_COND           (MMC_CMD1 | MMC_RSP3)
#define MMC_ALL_SEND_CID  	   (MMC_CMD2 | MMC_RSP2)
#define MMC_SET_RELATIVE_ADDR      (MMC_CMD3 | MMC_RSP1)
#define MMC_SET_DSR                (MMC_CMD4 | MMC_RSPNONE)
#define MMC_SELECT_CARD            (MMC_CMD7 | MMC_RSP1)
#define MMC_SEND_CSD               (MMC_CMD9 | MMC_RSP2)
#define MMC_SEND_CID               (MMC_CMD10 | MMC_RSP2)
#define MMC_READ_DAT_UNTIL_STOP    (MMC_CMD11 | MMC_RSP1 | CMD_DCLR | \
                                    CMD_DATA_TRANSFER | CMD_STREAM_MODE)
#define MMC_STOP_TRANSMISSION      (MMC_CMD12 | MMC_RSP1 | BUSY_EXPECTED)
#define MMC_SEND_STATUS            (MMC_CMD13 | MMC_RSP1)
#define MMC_GO_INACTIVE_STATE      (MMC_CMD15 | MMC_RSPNONE)
#define MMC_SET_BLOCKLEN           (MMC_CMD16 | MMC_RSP1)
#define MMC_READ_SINGLE_BLOCK      (MMC_CMD17 | MMC_RSP1 | CMD_DCLR | CMD_DATA_TRANSFER)
#define MMC_READ_MULTIPLE_BLOCK    (MMC_CMD18 | MMC_RSP1 | CMD_DCLR | CMD_DATA_TRANSFER)
#define MMC_WRITE_DAT_UNTIL_STOP   (MMC_CMD20 | MMC_RSP1 | CMD_STREAM_MODE | \
                                    CMD_DCLR | CMD_DATA_TRANSFER | CMD_WRITE)
#define MMC_SET_BLOCK_COUNT        (MMC_CMD23 | MMC_RSP1)
#define MMC_WRITE_BLOCK            (MMC_CMD24 | MMC_RSP1 | CMD_DCLR | CMD_DATA_TRANSFER | CMD_WRITE)
#define MMC_WRITE_MULTIPLE_BLOCK   (MMC_CMD25 | MMC_RSP1 | CMD_DCLR | CMD_DATA_TRANSFER | CMD_WRITE)
#define MMC_PROGRAM_CID            (MMC_CMD26 | MMC_RSP1)
#define MMC_PROGRAM_CSD            (MMC_CMD27 | MMC_RSP1)
#define MMC_SET_WRITE_PROT         (MMC_CMD28 | MMC_RSP1 | BUSY_EXPECTED)
#define MMC_CLR_WRITE_PROT         (MMC_CMD29 | MMC_RSP1 | BUSY_EXPECTED)
#define MMC_SEND_WRITE_PROT        (MMC_CMD30 | MMC_RSP1)
#define MMC_TAG_SECTOR_START       (MMC_CMD32 | MMC_RSP1)
#define MMC_TAG_SECTOR_END         (MMC_CMD33 | MMC_RSP1)
#define MMC_UNTAG_SECTOR           (MMC_CMD34 | MMC_RSP1)
#define MMC_TAG_ERASE_GROUP_START  (MMC_CMD35 | MMC_RSP1)
#define MMC_TAG_ERASE_GROUP_END    (MMC_CMD36 | MMC_RSP1)
#define MMC_UNTAG_ERASE_GROUP      (MMC_CMD37 | MMC_RSP1)
#define MMC_ERASE                  (MMC_CMD38 | MMC_RSP1 | BUSY_EXPECTED)
#define MMC_FAST_IO                (MMC_CMD39 | MMC_RSP4)
#define MMC_GO_IRQ_STATE           (MMC_CMD40 | MMC_RSP5)
#define MMC_LOCK_UNLOCK            (MMC_CMD42 | MMC_RSP1 | BUSY_EXPECTED)
#define MMC_APP_CMD                (MMC_CMD55 | MMC_RSP1)
#define MMC_GEN_CMD                (MMC_CMD56 | MMC_RSP1 | BUSY_EXPECTED)

/* SD SPECIFIC COMMANDS */
#define SD_ACMD6                   6u
#define SD_ACMD13                  13u
#define SD_ACMD22                  22u
#define SD_ACMD23                  23u
#define SD_ACMD41                  41u
#define SD_ACMD42                  42u
#define SD_ACMD51                  51u

#define SD_GO_IDLE_STATE           (MMC_CMD0 | MMC_RSPNONE | CMD_ADD_INIT_CYCLES | CMD_DCLR)
#define SD_ALL_SEND_CID            (MMC_CMD2  | MMC_RSP2)
#define SD_SEND_RELATIVE_ADDR      (MMC_CMD3  | MMC_RSP6)
#define SD_SET_DSR                 (MMC_CMD4  | MMC_RSPNONE)
#define SD_SELECT_CARD             (MMC_CMD7  | MMC_RSP1)
#define SD_SEND_CSD                (MMC_CMD9  | MMC_RSP2)
#define SD_SEND_CID                (MMC_CMD10 | MMC_RSP2)
#define SD_STOP_TRANSMISSION       (MMC_CMD12 | MMC_RSP1 | BUSY_EXPECTED)
#define SD_SEND_STATUS             (MMC_CMD13 | MMC_RSP1)
#define SD_GO_INACTIVE_STATE       (MMC_CMD15 | MMC_RSPNONE)
#define SD_SET_BLOCKLEN            (MMC_CMD16 | MMC_RSP1)
#define SD_READ_SINGLE_BLOCK       (MMC_CMD17 | MMC_RSP1 | CMD_DCLR | CMD_DATA_TRANSFER)
#define SD_READ_MULTIPLE_BLOCK     (MMC_CMD18 | MMC_RSP1 | CMD_DCLR | CMD_DATA_TRANSFER)
#define SD_WRITE_BLOCK             (MMC_CMD24 | MMC_RSP1 | CMD_DCLR | CMD_DATA_TRANSFER | CMD_WRITE)
#define SD_WRITE_MULTIPLE_BLOCK    (MMC_CMD25 | MMC_RSP1 | CMD_DCLR | CMD_DATA_TRANSFER | CMD_WRITE)
#define SD_PROGRAM_CSD             (MMC_CMD27 | MMC_RSP1)
#define SD_SET_WRITE_PROT          (MMC_CMD28 | MMC_RSP1 | BUSY_EXPECTED)
#define SD_CLR_WRITE_PROT          (MMC_CMD29 | MMC_RSP1 | BUSY_EXPECTED)
#define SD_SEND_WRITE_PROT         (MMC_CMD30 | MMC_RSP1)
#define SD_ERASE_WR_BLK_START      (MMC_CMD32 | MMC_RSP1)
#define SD_ERASE_WR_BLK_END        (MMC_CMD33 | MMC_RSP1)
#define SD_ERASE                   (MMC_CMD38 | MMC_RSP1 | BUSY_EXPECTED)
#define SD_LOCK_UNLOCK             (MMC_CMD42 | MMC_RSP1 | BUSY_EXPECTED)
#define SD_APP_CMD                 (MMC_CMD55 | MMC_RSP1)
#define SD_GEN_CMD                 (MMC_CMD56 | MMC_RSP1 | BUSY_EXPECTED)

#define SD_SET_BUS_WIDTH           (SD_ACMD6  | MMC_RSP1)
#define SD_STATUS                  (SD_ACMD13 | MMC_RSP1)
#define SD_SEND_NUM_WR_BLKS        (SD_ACMD22 | MMC_RSP1)
#define SD_SET_WR_BLK_ERASE_CNT    (SD_ACMD23 | MMC_RSP1)
#define SD_SEND_OP_COND            (SD_ACMD41 | MMC_RSP3)
#define SD_SET_CLR_CARD_DETECT     (SD_ACMD42 | MMC_RSP1)
#define SD_SCR                     (SD_ACMD51 | MMC_RSP1)


#define MMC_WAIT_FOR_DATDNE        (0x0001)
#define MMC_UNTAG_ERASE_SECTORS    (0x0008)

#define MMC_VOLTAGE_RANGE_ONLY     (0x0001)
#define MMC_FORCE_CARDS_INACTIVE   (0x0002)

#define MMC_OPEN_ONLY              (0x0001)
#define MMC_OPEN_INIT              (0x0002)
#define MMC_OPEN_NATIVE            (0x0008)

#define MMC_EVT_DATDNE             (0x0001u)
#define MMC_EVT_BSYDNE             (0x0002u)
#define MMC_EVT_RSPDNE             (0x0004u)
#define MMC_EVT_TOUTRD             (0x0008u)
#define MMC_EVT_TOUTRS             (0x0010u)
#define MMC_EVT_CRCWR              (0x0020u)
#define MMC_EVT_CRCRD              (0x0040u)
#define MMC_EVT_CRCRS              (0x0080u)
#define MMC_EVT_DXRDY              (0x0200u)
#define MMC_EVT_DRRDY              (0x0400u)
#define MMC_EVT_DATEG              (0x0800u)

#define MMC_ST0_DATDNE             (_MMC_MMCST0_DATDNE_MK(1))
#define MMC_ST0_BSYDNE             (_MMC_MMCST0_BSYDNE_MK(1))
#define MMC_ST0_RSPDNE             (_MMC_MMCST0_RSPDNE_MK(1))
#define MMC_ST0_TOUTRD             (_MMC_MMCST0_TOUTRD_MK(1))
#define MMC_ST0_TOUTRS             (_MMC_MMCST0_TOUTRS_MK(1))
#define MMC_ST0_CRCWR              (_MMC_MMCST0_CRCWR_MK(1))
#define MMC_ST0_CRCRD              (_MMC_MMCST0_CRCRD_MK(1))
#define MMC_ST0_CRCRS              (_MMC_MMCST0_CRCRS_MK(1))
#define MMC_ST0_DXRDY              (_MMC_MMCST0_DXRDY_MK(1))
#define MMC_ST0_DRRDY              (_MMC_MMCST0_DRRDY_MK(1))
#define MMC_ST0_DATEG              (_MMC_MMCST0_DATEG_MK(1))

#define MMC_USE_LAST_STATUS        (0x80000000u)

#define MMC_DAT1_PIN               (0x6000000u)
#define MMC_DAT2_PIN               (0x7000000u)
#define MMC_DAT3_PIN               (0x8000000u)
#define MMC_CSEN_PIN               MMC_DAT3_PIN

#define MMC_RESPONSE_TIMEOUT       (0xFFFFu)

/*************************************************\
* MMC global variable declarations
\*************************************************/


/*************************************************\
* MMC global function declarations
\*************************************************/


CSLAPI MMC_Handle MMC_open(int devNum);
CSLAPI void MMC_close(MMC_Handle hMMC);
CSLAPI void MMC_config(MMC_Handle hMMC, MMC_Config *myConfig);
CSLAPI void MMC_configArgs(MMC_Handle mmc, Uint16 mmcctl, Uint16 mmcfclk, Uint16 mmcclk,
            Uint16 mmcie, Uint16 mmctor, Uint16 mmctod, Uint16 mmcblen,
            Uint16 mmcnblk);
CSLAPI int  MMC_selectCard(MMC_Handle mmc, MMC_CardObj *card);
CSLAPI void MMC_getConfig(MMC_Handle mmc, MMC_Config *mmcCfg);
CSLAPI int  MMC_getStatus(MMC_Handle mmc, Uint32 lmask);

CSLAPI void MMC_clearResponse(MMC_Handle mmc);
CSLAPI int  MMC_read(MMC_Handle mmc, Uint32 cardAddr, Uint16 *buffer, Uint32 length);
CSLAPI int  MMC_sendAllCID(MMC_Handle mmc, MMC_CardIdObj *cid);
CSLAPI int  SD_sendAllCID(MMC_Handle mmc, MMC_CardIdObj *cid);
CSLAPI void MMC_sendGoIdle(MMC_Handle mmc);


CSLAPI int  MMC_sendCsd(MMC_Handle mmc, MMC_CardCsdObj *csd);
CSLAPI int  SD_sendCsd(MMC_Handle mmc, SD_CardCsdObj *csd);
CSLAPI int  MMC_sendCmd(MMC_Handle mmc, Uint16 cmd, Uint16 argh, Uint16 argl, Uint16 waitForRsp);
CSLAPI void MMC_getCardId(MMC_Handle mmc, MMC_CardIdObj *cid);
CSLAPI void MMC_getCardCsd(MMC_Handle mmc, MMC_CardCsdObj *csd);
CSLAPI void SD_getCardCsd(MMC_Handle mmc, SD_CardCsdObj *csd);

CSLAPI void MMC_setChipSelect(MMC_Handle mmc, Uint16 gpioPin, MMC_CardObj *card);
CSLAPI  int MMC_getNumberOfCards(MMC_Handle mmc, Uint16 *active, Uint16 *inactive);
CSLAPI void MMC_deselectCard(MMC_Handle mmc, MMC_CardObj *card);
CSLAPI  int MMC_drrdy(MMC_Handle mmc);
CSLAPI  int MMC_dxrdy(MMC_Handle mmc);
CSLAPI  int MMC_setRca(MMC_Handle mmc, MMC_CardObj *card, Uint16 rca);
CSLAPI void interrupt MMC_dispatch0();
CSLAPI void interrupt MMC_dispatch1();
CSLAPI void MMC_eventEnable(MMC_Handle mmc,Uint16 eventMask);
CSLAPI void MMC_eventDisable(MMC_Handle mmc, Uint16 eventMask);
CSLAPI void MMC_setCallBack(MMC_Handle mmc, MMC_CallBackObj *func);
CSLAPI void MMC_intEnable(MMC_Handle mmc, Uint16 enableMask);
CSLAPI void MMC_setCardPtr(MMC_Handle mmc, MMC_CardObj *cards);
CSLAPI int  MMC_saveStatus(MMC_Handle mmc);
CSLAPI int  MMC_stop(MMC_Handle mmc);
CSLAPI int  MMC_write(MMC_Handle mmc, Uint32 cardAddr, void *buffer, Uint32 bufLen);
CSLAPI int  SD_sendRca(MMC_Handle mmc,MMC_CardObj *card);
CSLAPI int  MMC_sendOpCond(MMC_Handle mmc, Uint32 hVddMask);
CSLAPI void MMC_setupNative(MMC_Handle mmc, MMC_SetupNative *mmcInit);
CSLAPI void MMC_setCardType(MMC_CardObj *card, Uint16 type);

/*************************************************\
* MMC inline function declarations
\*************************************************/


#ifdef USEDEFS

/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/

#endif /*USEDEFS */

#endif  /* _MMC_SUPPORT  */

#endif  /* _CSL_MMCHAL_H  */

/******************************************************************************\
*     
*      End of csl_mmc.h 
*
\******************************************************************************/
