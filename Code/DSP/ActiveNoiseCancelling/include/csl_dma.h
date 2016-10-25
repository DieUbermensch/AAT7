/*****************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... DMA
* FILENAME...... csl_dma.h
* DATE CREATED.. Fri 06/11/1999
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... SL - Service Layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:  06/11/1999 Created
*   MODIFIED: 03/27/2001 Modified to support 5510PG2.0
*   MODIFIED: 04/16/2001 updated header comments
*   MODIFIED: 05/11/2001 updated for DMA_getConfig()
*   MODIFIED: 06/27/2001 updated for new CSL initialization model
*   MODIFIED: 01/09/2001 fixed problem with 5509 and 5510 PG2.0 support
*   MODIFIED: 01/25/2002 fixed typo FRAMIE ==> FRAMEIE
*   MODIFIED: 04/04/2002 Made misc changes to symbolic values
*   MODIFIED: 05/07/2002 Added DMA_Private typedef for C++ type checking
*   MODIFIED: 06/10/2003 Fixed the problem with DMA_stop and DMA_start
*                          to read DMACSR to clear all pending interrupts
*   MODIFIED: 06/19/2003 Added GTCR register
*   MODIFIED: 07/31/2003 Modified the type of DMA_Config variables,
*                         dmacfi and dmacei to 16 bit signed integers.
*   MODIFIED: 10/06/2003 Added dummy check in DMA_start() and DMA_stop()
*                         to avoid C++ compiler warnings.
*   MODIFIED: 01/08/2004 Added WP field to DMACCR register(5502 and 5501)                       
*   MODIFIED: 08/02/2004 Added 5501 support
*   MODIFIED: 09/15/2004 Added AERR field in DMACSR and AERRIE in DMACICR registers
*------------------------------------------------------------------------------
* DESCRIPTION:  (interface file for the DMA module)
*
*
*
\******************************************************************************/
#ifndef _DMA_H_
#define _DMA_H_

#include <_csl.h>
#include <csl_dmahal.h>

#if (_DMA_SUPPORT)

/****************************************\
* DMA scope and inline control macros
\****************************************/

#ifdef __cplusplus
#define CSLAPI extern "C"
#else
#define CSLAPI extern
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _DMA_MOD_
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
* DMA global macro declarations
\****************************************/
#define DMA_CHA_CNT        (_DMA_CHA_CNT)


/* DMA_Open() flags */
#define DMA_OPEN_RESET     (0x00000001)

/* error codes */
#define DMA_ERR_MAJOR            (ERR_BASE_DMA)
#define DMA_ERR_ALLOC            (0x00000000)
#define DMA_ERR_INVALID_HANDLE   (0x00000001)
#define DMA_ERR_GLOBAL_ALLOC     (0x00000002)

/* channel identifiers for DMA_Open() */
#define DMA_CHA_ANY  (-1)
#define DMA_CHA0    (0)
#define DMA_CHA1    (1)
#define DMA_CHA2    (2)
#define DMA_CHA3    (3)
#define DMA_CHA4    (4)
#define DMA_CHA5    (5)

/* define a debuging assertion macro for validating channel handles */
#ifdef _MCRTE_DEBUG
  #define DMA_ASSERT_HANDLE(hDma,RetExp) \
    if (hDma == INV) { \
      ERR_submit(DMA_ERR_MAJOR, DMA_ERR_INVALID_HANDLE); \
      RetExp; \
    } 
#else
  #define DMA_ASSERT_HANDLE(hDma,RetExp) 
#endif                                

/* For TMS320C55xx devices, the following macros set the DMAGCR register */


#define SET_ALLOCATED(h,val)  CSL_SYS_DATA.DmaAllocMask = (CSL_SYS_DATA.DmaAllocMask & (~(1u<<((DMA_PrivateObj*)(h)->ChaNum)))\
                              | ((val & 1u)<<((DMA_PrivateObj*)(h)->ChaNum))

#define GET_ALLOCATED(h)  CSL_SYS_DATA.DmaAllocMask| (1u<<(((DMA_PrivateObj*)(h)->ChaNum)));
#define GET_EVENTID(h)   (((DMA_PrivateObj*)(h))->EventId)
#define GET_CHANUM(h)    (((DMA_PrivateObj*)(h))->ChaNum) 
 
/* For TMS320C5510 PG2 devices, the following macros set the DMAGSCR register */
#define DMA_setCompmode(value)  ((DMA_FSET(DMAGSCR,COMPMODE,value))

/*-----------------------------------------------------------------------*/
/* The following macros are used to construct peripheral register        */
/* values based on symbolic constants. They will be useful to initialize */
/* the DMA_Config structure in a readable way.                           */
/*-----------------------------------------------------------------------*/

/*============================================================================*\
* DMA DMAGCR	   - Global Control Register Macros
*
* Fields:
*  (RW) FREE
*  (RW) EHPIEXCL
*  (RW) EHPIPRIO
\*============================================================================*/

/* default register value */
#define DMA_DMAGCR_DEFAULT                     (0x0000u)


/*---------------------------------------*\
* DMA_DMAGCR_MK Macros
\*---------------------------------------*/

#define DMA_DMAGCR_RMK(free, excl, prio)((Uint16)(\
    DMA_FMK(DMAGCR,FREE,free) |\
    DMA_FMK(DMAGCR,EHPIEXCL,excl) |\
    DMA_FMK(DMAGCR,EHPIPRIO,prio)\
  )\
)  

#define DMA_DMAGCR_RMKS(free_sym, excl_sym, prio_sym)((Uint16)(\
    DMA_FMKS(DMAGCR,FREE,free_sym) |\
    DMA_FMKS(DMAGCR,EHPIEXCL,ecxl_sym) |\
    DMA_FMKS(DMAGCR,EHPIPRIO,prio_sym)\
  )\
)  

/* field values */

#define DMA_DMAGCR_EHPIPRIO_HI                (0x0001u)
#define DMA_DMAGCR_EHPIPRIO_LOW               (0x0000u)
#define DMA_DMAGCR_EHPIPRIO_DEFAULT           DMA_DMAGCR_EHPIPRIO_LOW

#define DMA_DMAGCR_EHPIEXCL_ON                (0x0001u)
#define DMA_DMAGCR_EHPIEXCL_OFF               (0x0000u)
#define DMA_DMAGCR_EHPIEXCL_DEFAULT           DMA_DMAGCR_EHPIEXCL_OFF

#define DMA_DMAGCR_FREE_ON                    (0x0001u)
#define DMA_DMAGCR_FREE_OFF                   (0x0000u)
#define DMA_DMAGCR_FREE_DEFAULT               DMA_DMAGCR_FREE_OFF             

#if (_DMA_DST_AND_SRC_INDEX_SUPPORT)
  /*---------------------------------------*\
  * DMA_DMAGSCR_MK Macros 
  \*---------------------------------------*/

  #define DMA_DMAGSCR_RMK(mode)((Uint16)\
      DMA_FMK(DMAGSCR,COMPMODE,mode))  

  #define DMA_DMAGSCR_RMKS(mode_sym, excl_sym, prio_sym)((Uint16)\
      DMA_FMKS(DMAGSCR,COMPMODE,mode_sym)) 


  /* field values */

  #define DMA_DMAGSCR_DEFAULT                (0x0000u)
  #define DMA_DMAGSCR_COMPMODE_ON            (0x0000u)
  #define DMA_DMAGSCR_COMPMODE_OFF           (0x0001u)
  #define DMA_DMAGSCR_COMPMODE_DEFAULT       DMA_DMAGSCR_COMPMODE_ON
#endif

/*============================================================================*\
* DMA DMAGTCR	   - Global Timeout Control Register Macros
*
* Fields:
* #if (CHIP_5502) || (CHIP_5501)
*  (RW) PTE
*  (RW) ETE
*  (RW) ITE1
*  (RW) ITE0
* #else
*  (RW) DTCE
*  (RW) STCE
\*============================================================================*/

/* default register value */
	
#if (_DMA_DST_AND_SRC_INDEX_SUPPORT)

  #define DMA_DMAGTCR_DEFAULT                  (0x0000u)

/*---------------------------------------*\
* DMA_DMAGTCR_MK Macros
\*---------------------------------------*/
  #if (CHIP_5502) || (CHIP_5501)
    #define DMA_DMAGTCR_RMK(pte, ete, ite1, ite0)((Uint16)(\
        DMA_FMK(DMAGTCR,PTE,pte) |\
        DMA_FMK(DMAGTCR,ETE,ete) |\
        DMA_FMK(DMAGTCR,ITE1,ite1) |\
        DMA_FMK(DMAGTCR,ITE0,ite0)\
      )\
    )

    #define DMA_DMAGTCR_RMKS(pte_sym, ete_sym, ite1_sym, ite0_sym)((Uint16)(\
        DMA_FMKS(DMAGTCR,PTE,pte_sym) |\
        DMA_FMKS(DMAGTCR,ETE,ete_sym) |\
        DMA_FMKS(DMAGTCR,ITE1,ite1_sym) |\
        DMA_FMKS(DMAGTCR,ITE0,ite0_sym)\
      )\
    )  
    
    /* field values */
    
    #define DMA_DMAGTCR_ITE0_HI                   (0x0001u)
    #define DMA_DMAGTCR_ITE0_LOW                  (0x0000u)
    #define DMA_DMAGTCR_ITE0_DEFAULT              DMA_DMAGTCR_ITE0_LOW
    
    #define DMA_DMAGTCR_ITE1_HI                   (0x0001u)
    #define DMA_DMAGTCR_ITE1_LOW                  (0x0000u)
    #define DMA_DMAGTCR_ITE1_DEFAULT              DMA_DMAGTCR_ITE1_LOW
    
    #define DMA_DMAGTCR_ETE_HI                   (0x0001u)
    #define DMA_DMAGTCR_ETE_LOW                  (0x0000u)
    #define DMA_DMAGTCR_ETE_DEFAULT              DMA_DMAGTCR_ETE_LOW
    
    #define DMA_DMAGTCR_PTE_HI                   (0x0001u)
    #define DMA_DMAGTCR_PTE_LOW                  (0x0000u)
    #define DMA_DMAGTCR_PTE_DEFAULT              DMA_DMAGTCR_PTE_LOW
  #else
     #define DMA_DMAGTCR_RMK(dtce, stce)((Uint16)(\
        DMA_FMK(DMAGTCR,DTCE,dtce) |\
        DMA_FMK(DMAGTCR,STCE,stce)\
      )\
    )  
    
    #define DMA_DMAGTCR_RMKS(dtce_sym, stce_sym)((Uint16)(\
        DMA_FMKS(DMAGTCR,DTCE,dtce_sym) |\
        DMA_FMKS(DMAGTCR,STCE,stce_sym)\
      )\
    )  
    
    /* field values */
    
    #define DMA_DMAGTCR_STCE_HI                   (0x0001u)
    #define DMA_DMAGTCR_STCE_LOW                  (0x0000u)
    #define DMA_DMAGTCR_STCE_DEFAULT              DMA_DMAGTCR_STCE_LOW
    
    #define DMA_DMAGTCR_DTCE_HI                   (0x0001u)
    #define DMA_DMAGTCR_DTCE_LOW                  (0x0000u)
    #define DMA_DMAGTCR_DTCE_DEFAULT              DMA_DMAGTCR_DTCE_LOW 
  #endif  

#endif

/*============================================================================*\
* DMA DMACSDPn	   - Channel #n Source Destination Parameters Register Macros
*
* Fields:
*  (RW) DSTBEN
*  (RW) DSTPACK
*  (RW) DST
*  (RW) SRCBEN
*  (RW) SRCPACK
*  (RW) SRC
*  (RW) DATATYPE
\*============================================================================*/

/* Default register value */
#define DMA_DMACSDP_DEFAULT                      (0x0000u)


/*---------------------------------------*\
* DMA_DMACSDP_MK Macros
\*---------------------------------------*/


#define DMA_DMACSDP_RMK(dstben, dstpack, dst, srcben, srcpack, src, datatype)((Uint16)(\
    DMA_FMK(DMACSDP,DSTBEN,dstben)|\
    DMA_FMK(DMACSDP,DSTPACK,dstpack)|\
    DMA_FMK(DMACSDP,DST,dst)|\
    DMA_FMK(DMACSDP,SRCBEN,srcben)|\
    DMA_FMK(DMACSDP,SRCPACK,srcpack)|\
    DMA_FMK(DMACSDP,SRC,src)|\
    DMA_FMK(DMACSDP,DATATYPE,datatype)\
  )\
)

#define DMA_DMACSDP_RMKS(dstben_sym, dstpack_sym, dst_sym, srcben_sym,\
   srcpack_sym, src_sym, datatype_sym)((Uint16)(\
    DMA_FMKS(DMACSDP,DSTBEN,dstben_sym)|\
    DMA_FMKS(DMACSDP,DSTPACK,dstpack_sym)|\
    DMA_FMKS(DMACSDP,DST,dst_sym)|\
    DMA_FMKS(DMACSDP,SRCBEN,srcben_sym)|\
    DMA_FMKS(DMACSDP,SRCPACK,srcpack_sym)|\
    DMA_FMKS(DMACSDP,SRC,src_sym)|\
    DMA_FMKS(DMACSDP,DATATYPE,datatype_sym)\
  )\
)


/* field values */


 #define DMA_DMACSDP_DATATYPE_8BIT                (0x0000u)
 #define DMA_DMACSDP_DATATYPE_16BIT               (0x0001u)
 #define DMA_DMACSDP_DATATYPE_32BIT               (0x0002u)
 #define DMA_DMACSDP_DATATYPE_DEFAULT             DMA_DMACSDP_DATATYPE_8BIT                

#if (CHIP_5502) || (CHIP_5501)
 #define DMA_DMACSDP_SRC_DARAMPORT0               (0x0000u)
 #define DMA_DMACSDP_SRC_DARAMPORT1               (0x0001u)
#else  
 #define DMA_DMACSDP_SRC_SARAM                    (0x0000u)
 #define DMA_DMACSDP_SRC_DARAM                    (0x0001u)
#endif
   
 #define DMA_DMACSDP_SRC_EMIF                     (0x0002u)
 #define DMA_DMACSDP_SRC_PERIPH                   (0x0003u)

#if (CHIP_5502) || (CHIP_5501)   
 #define DMA_DMACSDP_SRC_DEFAULT                  DMA_DMACSDP_SRC_DARAMPORT0
#else
 #define DMA_DMACSDP_SRC_DEFAULT                  DMA_DMACSDP_SRC_SARAM
#endif   

 #define DMA_DMACSDP_SRCPACK_ON                   (0x0001u)
 #define DMA_DMACSDP_SRCPACK_OFF                  (0x0000u)
 #define DMA_DMACSDP_SRCPACK_DEFAULT              DMA_DMACSDP_SRCPACK_OFF

 #define DMA_DMACSDP_SRCBEN_NOBURST               (0x0000u)
 #define DMA_DMACSDP_SRCBEN_BURST4                (0x0002u)
 #define DMA_DMACSDP_SRCBEN_DEFAULT               DMA_DMACSDP_SRCBEN_NOBURST

#if (CHIP_5502) || (CHIP_5501) 
 #define DMA_DMACSDP_DST_DARAMPORT0               (0x0000u)
 #define DMA_DMACSDP_DST_DARAMPORT1               (0x0001u)
#else  
 #define DMA_DMACSDP_DST_SARAM                    (0x0000u)
 #define DMA_DMACSDP_DST_DARAM                    (0x0001u)
#endif
   
 #define DMA_DMACSDP_DST_EMIF                     (0x0002u)
 #define DMA_DMACSDP_DST_PERIPH                   (0x0003u)

#if (CHIP_5502) || (CHIP_5501) 
 #define DMA_DMACSDP_DST_DEFAULT                  DMA_DMACSDP_DST_DARAMPORT0
#else   
 #define DMA_DMACSDP_DST_DEFAULT                  DMA_DMACSDP_DST_SARAM
#endif

 #define DMA_DMACSDP_DSTPACK_ON                   (0x0001u)
 #define DMA_DMACSDP_DSTPACK_OFF                  (0x0000u)
 #define DMA_DMACSDP_DSTPACK_DEFAULT              DMA_DMACSDP_DSTPACK_OFF                  

 #define DMA_DMACSDP_DSTBEN_NOBURST               (0x0000u)
 #define DMA_DMACSDP_DSTBEN_BURST4                (0x0002u)
 #define DMA_DMACSDP_DSTBEN_DEFAULT               DMA_DMACSDP_DSTBEN_NOBURST

/*============================================================================*\
* DMA DMACCRn	   - Channel #n Channel Control Register Macros
*
* Fields:
*  (RW) DSTAMODE
*  (RW) SRCAMODE
*  (RW) ENDPROG
*  (RW) WP
*  (RW) REPEAT
*  (RW) AUTOINIT
*  (RW) EN
*  (RW) PRIO
*  (RW) FS
*  (RW) SYNC
\*============================================================================*/

/* default register value */
#define DMA_DMACCR_DEFAULT                     (0x0000u)


/*---------------------------------------*\
* DMA_DMACCR_MK Macro
\*---------------------------------------*/
#if (CHIP_5502)  || (CHIP_5501)
   
 #define DMA_DMACCR_RMK(dstamode, srcamode, endprog, wp, repeat, autoinit,\
                     en, prio, fs, sync)((Uint16)(\
    DMA_FMK(DMACCR,DSTAMODE,dstamode)|\
    DMA_FMK(DMACCR,SRCAMODE,srcamode)|\
    DMA_FMK(DMACCR,ENDPROG,endprog)|\
    DMA_FMK(DMACCR,WP,wp)|\
    DMA_FMK(DMACCR,REPEAT,repeat)|\
    DMA_FMK(DMACCR,AUTOINIT,autoinit)|\
    DMA_FMK(DMACCR,EN,en)|\
    DMA_FMK(DMACCR,PRIO,prio)|\
    DMA_FMK(DMACCR,FS,fs)|\
    DMA_FMK(DMACCR,SYNC,sync)\
    )\
  )  

 #define DMA_DMACCR_RMKS(dstamode_sym, srcamode_sym, endprog_sym, wp_sym, \
    repeat_sym, autoinit_sym, en_sym, prio_sym, fs_sym, sync_sym)((Uint16)(\
    DMA_FMKS(DMACCR,DSTAMODE,dstamode_sym)|\
    DMA_FMKS(DMACCR,SRCAMODE,srcamode_sym)|\
    DMA_FMKS(DMACCR,ENDPROG,endprog_sym)|\
    DMA_FMKS(DMACCR,WP,wp_sym)|\
    DMA_FMKS(DMACCR,REPEAT,repeat_sym)|\
    DMA_FMKS(DMACCR,AUTOINIT,autoinit_sym)|\
    DMA_FMKS(DMACCR,EN,en_sym)|\
    DMA_FMKS(DMACCR,PRIO,prio_sym)|\
    DMA_FMKS(DMACCR,FS,fs_sym)|\
    DMA_FMKS(DMACCR,SYNC,sync_sym)\
    )\
  )  

#else
 #define DMA_DMACCR_RMK(dstamode, srcamode, endprog, repeat, autoinit,\
                     en, prio, fs, sync)((Uint16)(\
    DMA_FMK(DMACCR,DSTAMODE,dstamode)|\
    DMA_FMK(DMACCR,SRCAMODE,srcamode)|\
    DMA_FMK(DMACCR,ENDPROG,endprog)|\
    DMA_FMK(DMACCR,REPEAT,repeat)|\
    DMA_FMK(DMACCR,AUTOINIT,autoinit)|\
    DMA_FMK(DMACCR,EN,en)|\
    DMA_FMK(DMACCR,PRIO,prio)|\
    DMA_FMK(DMACCR,FS,fs)|\
    DMA_FMK(DMACCR,SYNC,sync)\
    )\
  )  

 #define DMA_DMACCR_RMKS(dstamode_sym, srcamode_sym, endprog_sym, \
    repeat_sym, autoinit_sym, en_sym, prio_sym, fs_sym, sync_sym)((Uint16)(\
    DMA_FMKS(DMACCR,DSTAMODE,dstamode_sym)|\
    DMA_FMKS(DMACCR,SRCAMODE,srcamode_sym)|\
    DMA_FMKS(DMACCR,ENDPROG,endprog_sym)|\
    DMA_FMKS(DMACCR,REPEAT,repeat_sym)|\
    DMA_FMKS(DMACCR,AUTOINIT,autoinit_sym)|\
    DMA_FMKS(DMACCR,EN,en_sym)|\
    DMA_FMKS(DMACCR,PRIO,prio_sym)|\
    DMA_FMKS(DMACCR,FS,fs_sym)|\
    DMA_FMKS(DMACCR,SYNC,sync_sym)\
    )\
  )  
  
#endif  /* (CHIP_5502) || (CHIP_5501)*/  

/* field values */

#define DMA_DMACCR_SYNC_NONE                     (0x0000u)
#define DMA_DMACCR_SYNC_REVT0                    (0x0001u)
#define DMA_DMACCR_SYNC_XEVT0                    (0x0002u)                    
#define DMA_DMACCR_SYNC_REVTA0                   (0x0003u) 
#define DMA_DMACCR_SYNC_XEVTA0                   (0x0004u) 
#define DMA_DMACCR_SYNC_REVT1                    (0x0005u)
#define DMA_DMACCR_SYNC_XEVT1                    (0x0006u)
#define DMA_DMACCR_SYNC_REVTA1                   (0x0007u)
#define DMA_DMACCR_SYNC_XEVTA1                   (0x0008u)
#define DMA_DMACCR_SYNC_REVT2                    (0x0009u)
#define DMA_DMACCR_SYNC_XEVT2                    (0x000Au)
#define DMA_DMACCR_SYNC_REVTA2                   (0x000Bu)
#define DMA_DMACCR_SYNC_XEVTA2                   (0x000Cu)
#define DMA_DMACCR_SYNC_TIM1INT                  (0x000Du)
#define DMA_DMACCR_SYNC_TIM2INT                  (0x000Eu)
#define DMA_DMACCR_SYNC_EXTINT0                  (0x000Fu)
#define DMA_DMACCR_SYNC_EXTINT1                  (0x0010u)
#define DMA_DMACCR_SYNC_EXTINT2                  (0x0011u)
#define DMA_DMACCR_SYNC_EXTINT3                  (0x0012u)
#define DMA_DMACCR_SYNC_EXTINT4                  (0x0013u)
#define DMA_DMACCR_SYNC_EXTINT5                  (0x0014u) 
#define DMA_DMACCR_SYNC_DEFAULT                  DMA_DMACCR_SYNC_NONE
                       
#define DMA_DMACCR_FS_ENABLE                     (0x0001u)
#define DMA_DMACCR_FS_DISABLE                    (0x0000u)
#define DMA_DMACCR_FS_ELEMENT                    (0x0000u)
#define DMA_DMACCR_FS_FRAME                      (0x0001u)
#define DMA_DMACCR_FS_DEFAULT                    DMA_DMACCR_FS_DISABLE

#define DMA_DMACCR_PRIO_HI                       (0x0001u)
#define DMA_DMACCR_PRIO_LOW                      (0x0000u)
#define DMA_DMACCR_PRIO_DEFAULT			 DMA_DMACCR_PRIO_LOW
                      
#define DMA_DMACCR_EN_START                      (0x0001u)
#define DMA_DMACCR_EN_STOP                       (0x0000u)
#define DMA_DMACCR_EN_DEFAULT                    DMA_DMACCR_EN_STOP                  

#define DMA_DMACCR_AUTOINIT_ON                   (0x0001u)
#define DMA_DMACCR_AUTOINIT_OFF                  (0x0000u)
#define DMA_DMACCR_AUTOINIT_DEFAULT              DMA_DMACCR_AUTOINIT_OFF

#define DMA_DMACCR_REPEAT_ON                     (0x0001u)
#define DMA_DMACCR_REPEAT_ALWAYS                 (0x0001u)
#define DMA_DMACCR_REPEAT_ENDPROG1               (0x0000u)
#define DMA_DMACCR_REPEAT_OFF                    (0x0000u)
#define DMA_DMACCR_REPEAT_DEFAULT                DMA_DMACCR_REPEAT_OFF                    

#define DMA_DMACCR_ENDPROG_ON                    (0x0001u)
#define DMA_DMACCR_ENDPROG_OFF                   (0x0000u)
#define DMA_DMACCR_ENDPROG_DEFAULT               DMA_DMACCR_ENDPROG_OFF

#if (CHIP_5502) || (CHIP_5501)
  #define DMA_DMACCR_WP_ENABLE                   (0x0001u)
  #define DMA_DMACCR_WP_DISABLE                  (0x0000u)
  #define DMA_DMACCR_WP_DEFAULT                  DMA_DMACCR_WP_DISABLE
#endif
    
    
#define DMA_DMACCR_SRCAMODE_CONST                (0x0000u)
#define DMA_DMACCR_SRCAMODE_POSTINC              (0x0001u)
#define DMA_DMACCR_SRCAMODE_SGLINDX              (0x0002u)
#define DMA_DMACCR_SRCAMODE_DBLINDX              (0x0003u)
#define DMA_DMACCR_SRCAMODE_DEFAULT              DMA_DMACCR_SRCAMODE_CONST

#define DMA_DMACCR_DSTAMODE_CONST                (0x0000u)
#define DMA_DMACCR_DSTAMODE_POSTINC              (0x0001u)
#define DMA_DMACCR_DSTAMODE_SGLINDX              (0x0002u)
#define DMA_DMACCR_DSTAMODE_DBLINDX              (0x0003u)
#define DMA_DMACCR_DSTAMODE_DEFAULT              DMA_DMACCR_DSTAMODE_CONST

#define DMA_DMACCR_SYNC_OF(x)                    ((Uint16)(x))

/*========================================================================*\
* DMA DMACICRn	   - Channel #n Channel Interrupt Control Register Macros
*
* Fields:
*  (RW) AERRIE (For 5501 and 5502 only)
*  (RW) BLOCKIE
*  (RW) LASTIE
*  (RW) FRAMEIE
*  (RW) HALFIE
*  (RW) DROPIE
*  (RW) TIMEOUTIE
\*========================================================================*/

/* register value */
#define DMA_DMACICR_DEFAULT                      (0x0183u)

/*---------------------------------------*\
* DMA_DMACICR_MK Macros
\*---------------------------------------*/
#if (CHIP_5502) || (CHIP_5501)  

#define DMA_DMACICR_RMK(aerrie, blockie, lastie, frameie, halfie, dropie, timeoutie)((Uint16)(\
    DMA_FMK(DMACICR,AERRIE, aerrie)|\
    DMA_FMK(DMACICR,BLOCKIE, blockie)|\
    DMA_FMK(DMACICR,LASTIE, lastie)|\
    DMA_FMK(DMACICR,FRAMEIE, frameie)|\
    DMA_FMK(DMACICR,HALFIE, halfie)|\
    DMA_FMK(DMACICR,DROPIE, dropie)|\
    DMA_FMK(DMACICR,TIMEOUTIE, timeoutie)\
 )\
)

#define DMA_DMACICR_RMKS(aerrie_sym, blockie_sym, lastie_sym, frameie_sym, halfie_sym,\
  dropie_sym, timeoutie_sym)((Uint16)(\
    DMA_FMKS(DMACICR,AERRIE, aerrie_sym)|\
    DMA_FMKS(DMACICR,BLOCKIE, blockie_sym)|\
    DMA_FMKS(DMACICR,LASTIE, lastie_sym)|\
    DMA_FMKS(DMACICR,FRAMEIE, frameie_sym)|\
    DMA_FMKS(DMACICR,HALFIE, halfie_sym)|\
    DMA_FMKS(DMACICR,DROPIE, dropie_sym)|\
    DMA_FMKS(DMACICR,TIMEOUTIE, timeoutie_sym)\
 )\
)

#else

#define DMA_DMACICR_RMK(blockie, lastie, frameie, halfie, dropie, timeoutie)((Uint16)(\
    DMA_FMK(DMACICR,BLOCKIE, blockie)|\
    DMA_FMK(DMACICR,LASTIE, lastie)|\
    DMA_FMK(DMACICR,FRAMEIE, frameie)|\
    DMA_FMK(DMACICR,HALFIE, halfie)|\
    DMA_FMK(DMACICR,DROPIE, dropie)|\
    DMA_FMK(DMACICR,TIMEOUTIE, timeoutie)\
 )\
)

#define DMA_DMACICR_RMKS(blockie_sym, lastie_sym, frameie_sym, halfie_sym,\
  dropie_sym, timeoutie_sym)((Uint16)(\
    DMA_FMKS(DMACICR,BLOCKIE, blockie_sym)|\
    DMA_FMKS(DMACICR,LASTIE, lastie_sym)|\
    DMA_FMKS(DMACICR,FRAMEIE, frameie_sym)|\
    DMA_FMKS(DMACICR,HALFIE, halfie_sym)|\
    DMA_FMKS(DMACICR,DROPIE, dropie_sym)|\
    DMA_FMKS(DMACICR,TIMEOUTIE, timeoutie_sym)\
 )\
)

#endif /* 5502 || 5501 */

/* field values */


 #define DMA_DMACICR_TIMEOUTIE_ON                 (0x0001u)
 #define DMA_DMACICR_TIMEOUTIE_OFF                (0x0000u)
 #define DMA_DMACICR_TIMEOUTIE_DEFAULT            DMA_DMACICR_TIMEOUTIE_ON

 #define DMA_DMACICR_DROPIE_ON                    (0x0001u)
 #define DMA_DMACICR_DROPIE_OFF                   (0x0000u)
 #define DMA_DMACICR_DROPIE_DEFAULT               DMA_DMACICR_DROPIE_ON

 #define DMA_DMACICR_HALFIE_ON               (0x0001u)
 #define DMA_DMACICR_HALFIE_OFF              (0x0000u)
 #define DMA_DMACICR_HALFIE_DEFAULT          DMA_DMACICR_HALFIE_OFF

 #define DMA_DMACICR_FIRSTHALFIE_ON               (0x0001u)
 #define DMA_DMACICR_FIRSTHALFIE_OFF              (0x0000u)
 #define DMA_DMACICR_FIRSTHALFIE_DEFAULT          DMA_DMACICR_HALFIE_OFF

 #define DMA_DMACICR_FRAMEIE_ON                   (0x0001u)
 #define DMA_DMACICR_FRAMEIE_OFF                  (0x0000u)
 #define DMA_DMACICR_FRAMEIE_DEFAULT               DMA_DMACICR_FRAMEIE_OFF

 #define DMA_DMACICR_LASTIE_ON                    (0x0001u)
 #define DMA_DMACICR_LASTIE_OFF                   (0x0000u)
 #define DMA_DMACICR_LASTIE_DEFAULT               DMA_DMACICR_LASTIE_OFF                   

 #define DMA_DMACICR_BLOCKIE_ON                   (0x0001u)
 #define DMA_DMACICR_BLOCKIE_OFF                  (0x0000u)
 #define DMA_DMACICR_BLOCKIE_DEFAULT              DMA_DMACICR_BLOCKIE_OFF

 #define DMA_DMACICR_AERRIE_ON                   (0x0001u)
 #define DMA_DMACICR_AERRIE_OFF                  (0x0000u)
 #define DMA_DMACICR_AERRIE_DEFAULT              DMA_DMACICR_AERRIE_ON


/*========================================================================*\
* DMA DMACSRn	   - Channel #n Channel Status Register Macros
*
* Fields:
*  (R) AERR (For 5501 and 5502 only)
*  (R) SYNC
*  (R) BLOCK
*  (R) LAST
*  (R) FRAME
*  (R) HALF
*  (R) DROP
*  (R) TIMEOUT
\*========================================================================*/

/*---------------------------------------*\
* DMA_DMACSR_MK Macros
\*---------------------------------------*/ 
#define DMA_DMACSR_AERR_TRUE      (0x1u)
#define DMA_DMACSR_AERR_FALSE     (0x0u)
#define DMA_DMACSR_AERR_DEFAULT   DMA_DMACSR_AERR_FALSE

#define DMA_DMACSR_SYNC_TRUE      (0x1u)
#define DMA_DMACSR_SYNC_FALSE     (0x0u)
#define DMA_DMACSR_SYNC_DEFAULT   DMA_DMACSR_SYNC_FALSE

#define DMA_DMACSR_BLOCK_TRUE     (0x1u)
#define DMA_DMACSR_BLOCK_FALSE    (0x0u)
#define DMA_DMACSR_BLOCK_DEFAULT  DMA_DMACSR_BLOCK_FALSE

#define DMA_DMACSR_LAST_TRUE      (0x1u)
#define DMA_DMACSR_LAST_FALSE     (0x0u)
#define DMA_DMACSR_LAST_DEFAULT   DMA_DMACSR_LAST_FALSE

#define DMA_DMACSR_FRAME_TRUE     (0x1u)
#define DMA_DMACSR_FRAME_FALSE    (0x0u)
#define DMA_DMACSR_FRAME_DEFAULT  DMA_DMACSR_FRAME_FALSE

#define DMA_DMACSR_HALF_TRUE     (0x1u)
#define DMA_DMACSR_HALF_FALSE    (0x0u)
#define DMA_DMACSR_HALF_DEFAULT  DMA_DMACSR_HALF_FALSE

#define DMA_DMACSR_DROP_TRUE     (0x1u)
#define DMA_DMACSR_DROP_FALSE    (0x0u)
#define DMA_DMACSR_DROP_DEFAULT  DMA_DMACSR_DROP_FALSE

#define DMA_DMACSR_TIMEOUT_TRUE     (0x1u)
#define DMA_DMACSR_TIMEOUT_FALSE    (0x0u)
#define DMA_DMACSR_TIMEOUT_DEFAULT  DMA_DMACSR_TIMEOUT_FALSE


/* Register only Readable */
#if (CHIP_5502) || (CHIP_5501)

#define DMA_DMACSR_RMK(aerr,sync,block,last,frame,half,drop,timeout)(\
(Uint16) (DMA_FMK(DMACSR,AERR,aerr)   |\
          DMA_FMK(DMACSR,SYNC,sync)   |\
          DMA_FMK(DMACSR,BLOCK,block) |\
          DMA_FMK(DMACSR,LAST,last)   |\
          DMA_FMK(DMACSR,FRAME,frame) |\
          DMA_FMK(DMACSR,HALF,half)   |\
          DMA_FMK(DMACSR,DROP,drop)   |\
          DMA_FMK(DMACSR,TIMEOUT,timeout) )\
)

#define DMA_DMACSR_RMKS(aerr,sync,block,last,frame,half,drop,timeout)(\
(Uint16) (DMA_FMKS(DMACSR,AERR,aerr)   |\
          DMA_FMKS(DMACSR,SYNC,sync)   |\
          DMA_FMKS(DMACSR,BLOCK,block) |\
          DMA_FMKS(DMACSR,LAST,last)   |\
          DMA_FMKS(DMACSR,FRAME,frame) |\
          DMA_FMKS(DMACSR,HALF,half)   |\
          DMA_FMKS(DMACSR,DROP,drop)   |\
          DMA_FMKS(DMACSR,TIMEOUT,timeout) )\
)

#else

#define DMA_DMACSR_RMK(sync,block,last,frame,half,drop,timeout)(\
(Uint16) (DMA_FMK(DMACSR,SYNC,sync)   |\
          DMA_FMK(DMACSR,BLOCK,block) |\
          DMA_FMK(DMACSR,LAST,last)   |\
          DMA_FMK(DMACSR,FRAME,frame) |\
          DMA_FMK(DMACSR,HALF,half)   |\
          DMA_FMK(DMACSR,DROP,drop)   |\
          DMA_FMK(DMACSR,TIMEOUT,timeout) )\
)

#define DMA_DMACSR_RMKS(sync,block,last,frame,half,drop,timeout)(\
(Uint16) (DMA_FMKS(DMACSR,SYNC,sync)   |\
          DMA_FMKS(DMACSR,BLOCK,block) |\
          DMA_FMKS(DMACSR,LAST,last)   |\
          DMA_FMKS(DMACSR,FRAME,frame) |\
          DMA_FMKS(DMACSR,HALF,half)   |\
          DMA_FMKS(DMACSR,DROP,drop)   |\
          DMA_FMKS(DMACSR,TIMEOUT,timeout) )\
)

#endif /* 5502 || 5501 */

/*========================================================================*\
* HDMA_DMACSSALn	   - Channel #n Channel Source Start Address (lower 16 bits)
*
* Fields:
*  (RW) SSAL       
\*========================================================================*/

/* default register value */
#define DMA_DMACSSAL_DEFAULT                      (0x0000u)
#define DMA_DMACSSAL_SSAL_OF(x)                   ((Uint16)(x))


/*---------------------------------------*\
* DMA_DMACSSAL_MK Macro
\*---------------------------------------*/ 

#define DMA_DMACSSAL_RMK(ssal) ((Uint16)(\
    DMA_FMK(DMACSSAL,SSAL,ssal)\
  )\
) 

/*============================================================================*\
*  DMA DMACSSAUn	   - Channel #n Channel Source Start Address (lower 16 bits)
*
* Fields:
*  (RW) SSAU       
\*============================================================================*/


/* default register value */
#define DMA_DMACSSAU_DEFAULT                      (0x0000u)
#define DMA_DMACSSAU_SSAU_OF(x)                   ((Uint16)(x))


/*---------------------------------------*\
* DMA_DMACSSAU_MK Macro
\*---------------------------------------*/ 

#define DMA_DMACSSAU_RMK(ssau) ((Uint16)(\
    DMA_FMK(DMACSSAU,SSAU,ssau)\
  )\
) 

/*============================================================================*\
*  DMA DMACDSALn	   - Channel #n Channel Source Start Address (lower 16 bits)
*
* Fields:
*  (RW) DSAL       
\*============================================================================*/

/* default register value */
#define DMA_DMACDSAL_DEFAULT                      (0x0000u)
#define DMA_DMACDSAL_DSAL_OF(x)                   ((Uint16)(x))


/*---------------------------------------*\
* DMA_DMACDSAL_MK Macro
\*---------------------------------------*/ 

#define DMA_DMACDSAL_RMK(dsal) ((Uint16)(\
    DMA_FMK(DMACDSAL,DSAL,dsal)\
  )\
)


/*============================================================================*\
*  DMA DMACDSAUn	   - Channel #n Channel Source Start Address (lower 16 bits)
*
* Fields:
*  (RW) DSAU       
\*============================================================================*/

/* default register value */
#define DMA_DMACDSAU_DEFAULT                      (0x0000u)
#define DMA_DMACDSAU_DSAU_OF(x)                   ((Uint16)(x))

/*---------------------------------------*\
* DMA_DMACDSAU_MK Macro
\*---------------------------------------*/ 

#define DMA_DMACDSAU_RMK(dsau) ((Uint16)(\
    DMA_FMK(DMACDSAU,DSAU,dsau)\
  )\
) 

/*========================================================================*\
*  DMA DMACENn	   - Channel #n Channel Element Number Register
*
* Fields:
*  (RW) ELEMENTNUM       
\*========================================================================*/

/* default register value */
#define DMA_DMACEN_DEFAULT                      (0x0000u)
#define DMA_DMACEN_ELEMENTNUM_OF(x)             ((Uint16)(x))


/*---------------------------------------*\
* DMA_DMACEN_MK Macro
\*---------------------------------------*/ 

#define DMA_DMACEN_RMK(elementnum) ((Uint16)(\
    DMA_FMK(DMACEN,ELEMENTNUM,elementnum)\
  )\
) 

/*========================================================================*\
* HDMA_DMACFNn	   - Channel #n Channel Frame Number Register
*
* Fields:
*  (RW) FRAMENUM      
\*========================================================================*/

/* default register value */
#define DMA_DMACFN_DEFAULT                      (0x0000u)
#define DMA_DMACFN_FRAMENUM_OF(x)               ((Uint16)(x))


/*---------------------------------------*\
* DMA_DMACFN_MK Macro
\*---------------------------------------*/ 

#define DMA_DMACFN_RMK(framenum) ((Uint16)(\
    DMA_FMK(DMACFN,FRAMENUM,framenum)\
  )\
)


/*========================================================================*\
* DMA DMACFIn	   - Channel #n Channel Frame Index Register Macros
*
* Fields:
*  (RW) FRAMENDX      
\*========================================================================*/

/* default register value */
#define DMA_DMACFI_DEFAULT                      (0x0000u)
#define DMA_DMACFI_FRAMENDX_OF(x)               ((Uint16)(x))


/*---------------------------------------*\
* DMA_DMACFI_MK Macro
\*---------------------------------------*/ 

#define DMA_DMACFI_RMK(framendx) ((Uint16)(\
    DMA_FMK(DMACFI,FRAMENDX,framendx)\
  )\
) 


/*========================================================================*\
*  DMA DMACEIn	   - Channel #n Channel Element Index Register Macros
*
* Fields:
*  (RW) ELEMENTNDX      
\*========================================================================*/

/* default register value */
#define DMA_DMACEI_DEFAULT                      (0x0000u)
#define DMA_DMACEI_ELEMENTNDX_OF(x)             ((Uint16)(x))


/*---------------------------------------*\
* DMA_DMACEI_MK Macro
\*---------------------------------------*/


#define DMA_DMACEI_RMK(elementndx) ((Uint16)(\
    DMA_FMK(DMACEI,ELEMENTNDX,elementndx)\
  )\
) 

#if _DMA_DST_AND_SRC_INDEX_SUPPORT
  /*========================================================================*\
   * DMA DMACDFIn	   - Channel #n Destination Frame Index Register Macros
   *
   * Fields:
   *  (RW) FRAMENDX      
  \*========================================================================*/

  /* default register value */
  #define DMA_DMACDFI_DEFAULT                      (0x0000u)
  #define DMA_DMACDFI_FRAMENDX_OF(x)               ((Uint16)(x))


  /*---------------------------------------*\
   * DMA_DMACDFI_MK Macro 
  \*---------------------------------------*/ 

  #define DMA_DMACDFI_RMK(framendx) ((Uint16)(\
      DMA_FMK(DMACDFI,FRAMENDX,framendx)\
    )\
  ) 


  /*========================================================================*\
   *  DMA DMACDEIn	   - Channel #n Destination Element Index Register Macros
   *
   * Fields:
   *  (RW) ELEMENTNDX      
  \*========================================================================*/

  /* default register value */
  #define DMA_DMACDEI_DEFAULT                      (0x0000u)
  #define DMA_DMACDEI_ELEMENTNDX_OF(x)             ((Uint16)(x))


  /*---------------------------------------*\
  * DMA_DMACDEI_MK Macro
  \*---------------------------------------*/ 


  #define DMA_DMACDEI_RMK(elementndx) ((Uint16)(\
      DMA_FMK(DMACDEI,ELEMENTNDX,elementndx)\
    )\
  )

  /*========================================================================*\
  * DMA DMACSFIn	   - Channel #n Source Frame Index Register Macros
  *
  * Fields:
  *  (RW) FRAMENDX      
  \*========================================================================*/

  /* default register value */
  #define DMA_DMACSFI_DEFAULT                      (0x0000u)
  #define DMA_DMACSFI_FRAMENDX_OF(x)               ((Uint16)(x))


  /*---------------------------------------*\
  * DMA_DMACDFI_MK Macro
  \*---------------------------------------*/ 

  #define DMA_DMACSFI_RMK(framendx) ((Uint16)(\
      DMA_FMK(DMACSFI,FRAMENDX,framendx)\
    )\
  )


  /*========================================================================*\
  *  DMA DMACSEIn	   - Channel #n Source Element Index Register Macros
  *
  * Fields:
  *  (RW) ELEMENTNDX      
  \*========================================================================*/

  /* default register value */
  #define DMA_DMACSEI_DEFAULT                      (0x0000u)
  #define DMA_DMACSEI_ELEMENTNDX_OF(x)             ((Uint16)(x))


  /*---------------------------------------*\
  * DMA_DMACSEI_MK Macro
  \*---------------------------------------*/ 

 
  #define DMA_DMACSEI_RMK(elementndx) ((Uint16)(\
      DMA_FMK(DMACSEI,ELEMENTNDX,elementndx)\
    )\
  ) 
#endif

/****************************************\
* DMA global typedef declarations
\****************************************/

typedef void (*DMA_AdrPtr)();

/* channel handle type */
typedef struct {
  Uint32 Private;
} DMA_Private, *DMA_Handle;

/* channel configuration structure */
typedef struct {
  Uint16 dmacsdp;
  Uint16 dmaccr;
  Uint16 dmacicr;
  DMA_AdrPtr dmacssal;
  Uint16 dmacssau;
  DMA_AdrPtr dmacdsal;
  Uint16 dmacdsau;
  Uint16 dmacen;
  Uint16 dmacfn;
#if _DMA_DST_AND_SRC_INDEX_SUPPORT
  Int16 dmacsfi;
  Int16 dmacsei;
  Int16 dmacdfi;
  Int16 dmacdei;
#else
  Int16 dmacfi;
  Int16 dmacei;
#endif
} DMA_Config;


/*******************************************\
* DMA global macro definition : ROMABILITY
\*******************************************/  
/* Reserved ROM Area by dmadata.h */
 
/* Data definition */
 
#define DMA_hCha0  ((DMA_Handle)(&(CSL_DMA_DATA.DmaChan[0])))
#define DMA_hCha1  ((DMA_Handle)(&(CSL_DMA_DATA.DmaChan[1])))
#define DMA_hCha2  ((DMA_Handle)(&(CSL_DMA_DATA.DmaChan[2])))
#define DMA_hCha3  ((DMA_Handle)(&(CSL_DMA_DATA.DmaChan[3])))
#define DMA_hCha4  ((DMA_Handle)(&(CSL_DMA_DATA.DmaChan[4])))
#define DMA_hCha5  ((DMA_Handle)(&(CSL_DMA_DATA.DmaChan[5])))
#define DMA_hCha(n)((DMA_Handle)(&(CSL_DMA_DATA.DmaChan[n])))





#define DMA_getEventId(hDma) (\
     (Uint16)(((DMA_PrivateObj*)hDma)->EventId))


#define DMA_pause(hDma)           DMA_FSETH(hDma,DMACCR,EN,0)


/****************************************\
* DMA global function declarations
\****************************************/
CSLAPI void DMA_init();
CSLAPI void DMA_reset(DMA_Handle hDma);

CSLAPI DMA_Handle DMA_open(int ChaNum, Uint32 Flags);
CSLAPI void DMA_close(DMA_Handle hDma);

CSLAPI void DMA_config(DMA_Handle hDma, DMA_Config *Config);
CSLAPI void DMA_getConfig(DMA_Handle hDma, DMA_Config *Config);


#if _DMA_DST_AND_SRC_INDEX_SUPPORT
  CSLAPI void DMA_configArgs(DMA_Handle hDma, Uint16 dmacsdp, Uint16 dmaccr, Uint16 dmacicr, 
    DMA_AdrPtr dmacssal, Uint16 dmacssau, DMA_AdrPtr dmacdsal, Uint16 dmacdsau, Uint16 dmacen,
    Uint16 dmacfn, Int16 dmacsfi, Int16 dmacsei, Int16 dmacdfi, Int16 dmacdei);
#else
  CSLAPI void DMA_configArgs(DMA_Handle hDma, Uint16 dmacsdp, Uint16 dmaccr,
    Uint16 dmacicr, DMA_AdrPtr dmacssal, Uint16 dmacssau, DMA_AdrPtr dmacdsal, Uint16 dmacdsau,
    Uint16 dmacen, Uint16 dmacfn, Int16 dmacfi, Int16 dmacei);
#endif


/* Prototypes for Static Inline Functions */
static inline void DMA_stop(DMA_Handle hDma);
static inline void DMA_start(DMA_Handle hDma);

/* Definitions for static inline functions */

static inline void DMA_start(DMA_Handle hDma) {
          if(DMA_RGETH(hDma,DMACSR))  {
           	;   /* Dummy check to avoid C++ compiler warning */
	  }
	  DMA_FSETH(hDma,DMACCR,EN,1);
}

static inline void DMA_stop(DMA_Handle hDma) {
          DMA_FSETH(hDma,DMACCR,EN,0);
          if(DMA_RGETH(hDma,DMACSR)){
	       ;    /* Dummy check to avoid C++ compiler warning */
          }
}

#endif /* DMA_SUPPORT */
#endif /* _DMA_H_ */
/******************************************************************************\
* End of dma.h
\******************************************************************************/

