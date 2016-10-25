/****************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved 
*------------------------------------------------------------------------------
* MODULE NAME... EMIF
* FILENAME...... csl_emif.h
* DATE CREATED.. Mon Feb 11 15:35:20 2002
* PROJECT....... Chip Support Library
* COMPONENT..... Service Layer
* PREREQUISITS.. 
*------------------------------------------------------------------------------
*
* HISTORY:
*	 Created:		Mon Feb 11 15:35:20 2002 (Automatic generation)
*	 Last Modified:	27 Mar 2003
*
*------------------------------------------------------------------------------
* DESCRIPTION: CSL Service Layer interface for the EMIF module 
*
\*************************************************************************/

#ifndef _CSL_EMIFB_H_
#define _CSL_EMIFB_H_

#include <csl_emifBhal.h>
#include <csl_std.h>
#include <_csl.h>
#include <csl_chiphal.h>

#if (_EMIFB_SUPPORT) 

/*----------------------------------------------------------------*\
*	 EMIF scope and inline control macros 			
\*----------------------------------------------------------------*/

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

/****************************************\
* EMIF global macro declarations
\****************************************/

/* error codes */
#define EMIF_ERR_MAJOR		   (ERR_BASE_EMIF) 
#define EMIF_ERR_ALLOC		   (0x00000000) 
#define EMIF_ERR_INVALID_HANDLE  (0x00000001) 

/* ============================================================== */
 /* Make CE0CTL1 register values based on symbolic constants  */

/*  CE0CTL1 field values  */

	#define EMIF_CE0CTL1_TA_OF(x)			((Uint16)(x))
	#define EMIF_CE0CTL1_TA_DEFAULT		EMIF_CE0CTL1_TA_OF(3)

	#define EMIF_CE0CTL1_READ_STROBE_OF(x)		((Uint16)(x))
	#define EMIF_CE0CTL1_READ_STROBE_DEFAULT		EMIF_CE0CTL1_READ_STROBE_OF(0x3fu)

	#define EMIF_CE0CTL1_MTYPE_8BIT_ASYNC			(000000u)
	#define EMIF_CE0CTL1_MTYPE_16BIT_ASYNC			(0x0001u)
	#define EMIF_CE0CTL1_MTYPE_32BIT_ASYNC			(0x0002u)
	#define EMIF_CE0CTL1_MTYPE_32BIT_SDRAM			(0x0003u)
	#define EMIF_CE0CTL1_MTYPE_32BIT_SBSRAM			(0x0004u)
	#define EMIF_CE0CTL1_MTYPE_8BIT_SDRAM			(0x0008u)
	#define EMIF_CE0CTL1_MTYPE_16BIT_SDRAM			(0x0009u)
	#define EMIF_CE0CTL1_MTYPE_8BIT_SBSRAM			(000010u)
	#define EMIF_CE0CTL1_MTYPE_16BIT_SBSRAM			(000011u)
	#define EMIF_CE0CTL1_MTYPE_DEFAULT		EMIF_CE0CTL1_MTYPE_8BIT_ASYNC

	#define EMIF_CE0CTL1_WRITE_HOLD_MSB_HIGH			(0x0001u)
	#define EMIF_CE0CTL1_WRITE_HOLD_MSB_LOW			(000000u)
	#define EMIF_CE0CTL1_WRITE_HOLD_MSB_DEFAULT		EMIF_CE0CTL1_WRITE_HOLD_MSB_LOW

	#define EMIF_CE0CTL1_WRITE_HOLD_HIGH			(0x0001u)
	#define EMIF_CE0CTL1_WRITE_HOLD_LOW				(000000u)
	#define EMIF_CE0CTL1_WRITE_HOLD_DEFAULT			EMIF_CE0CTL1_WRITE_HOLD_LOW

	#define EMIF_CE0CTL1_READ_HOLD_OF(x)		((Uint16)(x))
	#define EMIF_CE0CTL1_READ_HOLD_DEFAULT		EMIF_CE0CTL1_READ_HOLD_OF(3)


#define EMIF_CE0CTL1_RMK(ta,read_strobe,mtype,write_hold,read_hold)\
 ((Uint16) ( \
  ( EMIF_FMK(CE0CTL1,TA,ta))|\
  ( EMIF_FMK(CE0CTL1,READ_STROBE,read_strobe))|\
  ( EMIF_FMK(CE0CTL1,MTYPE,mtype))|\
  ( EMIF_FMK(CE0CTL1,WRITE_HOLD,write_hold))|\
  ( EMIF_FMK(CE0CTL1,READ_HOLD,read_hold))\
)\
 )

#define EMIF_CE0CTL1_RMKS(ta_sym,read_strobe_sym,mtype_sym,write_hold_sym,read_hold_sym)\
 ((Uint16) ( \
  ( EMIF_FMKS(CE0CTL1,TA,ta_sym))|\
  ( EMIF_FMKS(CE0CTL1,READ_STROBE,read_strobe_sym))|\
  ( EMIF_FMKS(CE0CTL1,MTYPE,mtype_sym))|\
  ( EMIF_FMKS(CE0CTL1,WRITE_HOLD,write_hold_sym))|\
  ( EMIF_FMKS(CE0CTL1,READ_HOLD,read_hold_sym))\
)\
 )

/*  Default CE0CTL1 register value  */

#define EMIF_CE0CTL1_DEFAULT               (0xFF03u)

/* ============================================================== */
 /* Make CE0CTL2 register values based on symbolic constants  */

/*  CE0CTL2 field values  */

	#define EMIF_CE0CTL2_WRITE_SETUP_OF(x)			((Uint16)(x))
      #define EMIF_CE0CTL2_WRITE_SETUP_DEFAULT			EMIF_CE0CTL2_WRITE_SETUP_OF(15)

	#define EMIF_CE0CTL2_WRITE_STROBE_OF(x)			((Uint16)(x))
	#define EMIF_CE0CTL2_WRITE_STROBE_DEFAULT			EMIF_CE0CTL2_WRITE_STROBE_OF(0x3fu)
	#define EMIF_CE0CTL2_WRITE_HOLD_OF(x)			((Uint16)(x))
	#define EMIF_CE0CTL2_WRITE_HOLD_DEFAULT			EMIF_CE0CTL2_WRITE_HOLD_OF(3)
	#define EMIF_CE0CTL2_READ_SETUP_OF(x)			((Uint16)(x))
      #define EMIF_CE0CTL2_READ_SETUP_DEFAULT			EMIF_CE0CTL2_READ_SETUP_OF(15)

#define EMIF_CE0CTL2_RMK(write_setup,write_strobe,write_hold,read_setup)\
 ((Uint16) ( \
  ( EMIF_FMK(CE0CTL2,WRITE_SETUP,write_setup))|\
  ( EMIF_FMK(CE0CTL2,WRITE_STROBE,write_strobe))|\
  ( EMIF_FMK(CE0CTL2,WRITE_HOLD,write_hold))|\
  ( EMIF_FMK(CE0CTL2,READ_SETUP,read_setup))\
)\
 )

#define EMIF_CE0CTL2_RMKS(write_setup_sym,write_strobe_sym,write_hold_sym,read_setup_sym)\
 ((Uint16) ( \
  ( EMIF_FMKS(CE0CTL2,WRITE_SETUP,write_setup_sym))|\
  ( EMIF_FMKS(CE0CTL2,WRITE_STROBE,write_strobe_sym))|\
  ( EMIF_FMKS(CE0CTL2,WRITE_HOLD,write_hold_sym))|\
  ( EMIF_FMKS(CE0CTL2,READ_SETUP,read_setup_sym))\
)\
 )

/*  Default CE0CTL2 register value  */

#define EMIF_CE0CTL2_DEFAULT          (0xFFFFu)

/* ============================================================== */
 /* Make CE0SEC1 register values based on symbolic constants  */

/*  CE0SEC1 field values  */

	#define EMIF_CE0SEC1_SNCCLK_SYNC_ECLKOUT1			(000000u)
	#define EMIF_CE0SEC1_SNCCLK_SYNC_ECLKOUT2			(0x0001u)
	#define EMIF_CE0SEC1_SNCCLK_DEFAULT		EMIF_CE0SEC1_SNCCLK_SYNC_ECLKOUT1

	#define EMIF_CE0SEC1_REN_ADS			(000000u)
	#define EMIF_CE0SEC1_REN_REN			(0x0001u)
	#define EMIF_CE0SEC1_REN_DEFAULT		EMIF_CE0SEC1_REN_ADS

	#define EMIF_CE0SEC1_RENEN_ADS			(000000u)
	#define EMIF_CE0SEC1_RENEN_REN			(0x0001u)
	#define EMIF_CE0SEC1_RENEN_DEFAULT		EMIF_CE0SEC1_RENEN_ADS

      #define EMIF_CE0SEC1_CEEXT_CE_TIED_TO_SOE			(0x0001u)
	#define EMIF_CE0SEC1_CEEXT_CE_TIED_TO_SNCCRL			(000000u)
	#define EMIF_CE0SEC1_CEEXT_DEFAULT		EMIF_CE0SEC1_CEEXT_CE_TIED_TO_SNCCRL

	#define EMIF_CE0SEC1_SYNCWL_0CYCLES			(000000u)
	#define EMIF_CE0SEC1_SYNCWL_1CYCLES			(0x0001u)
	#define EMIF_CE0SEC1_SYNCWL_2CYCLES			(0x0002u)
	#define EMIF_CE0SEC1_SYNCWL_3CYCLES			(0x0003u)
	#define EMIF_CE0SEC1_SYNCWL_DEFAULT		EMIF_CE0SEC1_SYNCWL_2CYCLES

	#define EMIF_CE0SEC1_SYNCRL_0CYCLES			(000000u)
	#define EMIF_CE0SEC1_SYNCRL_1CYCLE			(0x0001u)
	#define EMIF_CE0SEC1_SYNCRL_2CYCLES			(0x0002u)
	#define EMIF_CE0SEC1_SYNCRL_3CYCLES			(0x0003u)
	#define EMIF_CE0SEC1_SYNCRL_DEFAULT		EMIF_CE0SEC1_SYNCRL_2CYCLES

#define EMIF_CE0SEC1_RMK(sncclk,renen,ceext,syncwl,syncrl)\
 ((Uint16) ( \
  ( EMIF_FMK(CE0SEC1,SNCCLK,sncclk))|\
  ( EMIF_FMK(CE0SEC1,RENEN,renen))|\
  ( EMIF_FMK(CE0SEC1,CEEXT,ceext))|\
  ( EMIF_FMK(CE0SEC1,SYNCWL,syncwl))|\
  ( EMIF_FMK(CE0SEC1,SYNCRL,syncrl))\
)\
 )

#define EMIF_CE0SEC1_RMKS(sncclk_sym,renen_sym,ceext_sym,syncwl_sym,syncrl_sym)\
 ((Uint16) ( \
  ( EMIF_FMKS(CE0SEC1,SNCCLK,sncclk_sym))|\
  ( EMIF_FMKS(CE0SEC1,RENEN,renen_sym))|\
  ( EMIF_FMKS(CE0SEC1,CEEXT,ceext_sym))|\
  ( EMIF_FMKS(CE0SEC1,SYNCWL,syncwl_sym))|\
  ( EMIF_FMKS(CE0SEC1,SYNCRL,syncrl_sym))\
)\
 )

/*  Default CE0SEC1 register value  */

#define EMIF_CE0SEC1_DEFAULT          (0x0002u)

/* ============================================================== */
/* Make CE1CTL1 register values based on symbolic constants       */

/*  CE1CTL1 field values  */

	#define EMIF_CE1CTL1_TA_OF(x)			((Uint16)(x))
	#define EMIF_CE1CTL1_TA_DEFAULT		EMIF_CE1CTL1_TA_OF(3)

	#define EMIF_CE1CTL1_READ_STROBE_OF(x)		((Uint16)(x))
	#define EMIF_CE1CTL1_READ_STROBE_DEFAULT		EMIF_CE1CTL1_READ_STROBE_OF(0x3fu)

	#define EMIF_CE1CTL1_MTYPE_8BIT_ASYNC			(000000u)
	#define EMIF_CE1CTL1_MTYPE_16BIT_ASYNC			(0x0001u)
	#define EMIF_CE1CTL1_MTYPE_32BIT_ASYNC			(0x0002u)
	#define EMIF_CE1CTL1_MTYPE_32BIT_SDRAM			(0x0003u)
	#define EMIF_CE1CTL1_MTYPE_32BIT_SBSRAM			(0x0004u)
	#define EMIF_CE1CTL1_MTYPE_8BIT_SDRAM			(0x0008u)
	#define EMIF_CE1CTL1_MTYPE_16BIT_SDRAM			(0x0009u)
	#define EMIF_CE1CTL1_MTYPE_8BIT_SBSRAM			(000010u)
	#define EMIF_CE1CTL1_MTYPE_16BIT_SBSRAM			(000011u)
	#define EMIF_CE1CTL1_MTYPE_DEFAULT		EMIF_CE1CTL1_MTYPE_8BIT_ASYNC

	#define EMIF_CE1CTL1_WRITE_HOLD_MSB_HIGH			(0x0001u)
	#define EMIF_CE1CTL1_WRITE_HOLD_MSB_LOW			(000000u)
	#define EMIF_CE1CTL1_WRITE_HOLD_MSB_DEFAULT		EMIF_CE1CTL1_WRITE_HOLD_MSB_LOW

	#define EMIF_CE1CTL1_WRITE_HOLD_HIGH			(0x0001u)
	#define EMIF_CE1CTL1_WRITE_HOLD_LOW				(000000u)
	#define EMIF_CE1CTL1_WRITE_HOLD_DEFAULT			EMIF_CE1CTL1_WRITE_HOLD_LOW

	#define EMIF_CE1CTL1_READ_HOLD_OF(x)		((Uint16)(x))
	#define EMIF_CE1CTL1_READ_HOLD_DEFAULT		EMIF_CE1CTL1_READ_HOLD_OF(3)


#define EMIF_CE1CTL1_RMK(ta,read_strobe,mtype,write_hold,read_hold)\
 ((Uint16) ( \
  ( EMIF_FMK(CE1CTL1,TA,ta))|\
  ( EMIF_FMK(CE1CTL1,READ_STROBE,read_strobe))|\
  ( EMIF_FMK(CE1CTL1,MTYPE,mtype))|\
  ( EMIF_FMK(CE1CTL1,WRITE_HOLD,write_hold))|\
  ( EMIF_FMK(CE1CTL1,READ_HOLD,read_hold))\
)\
 )

#define EMIF_CE1CTL1_RMKS(ta_sym,read_strobe_sym,mtype_sym,write_hold_sym,read_hold_sym)\
 ((Uint16) ( \
  ( EMIF_FMKS(CE1CTL1,TA,ta_sym))|\
  ( EMIF_FMKS(CE1CTL1,READ_STROBE,read_strobe_sym))|\
  ( EMIF_FMKS(CE1CTL1,MTYPE,mtype_sym))|\
  ( EMIF_FMKS(CE1CTL1,WRITE_HOLD,write_hold_sym))|\
  ( EMIF_FMKS(CE1CTL1,READ_HOLD,read_hold_sym))\
)\
 )

/*  Default CE1CTL1 register value  */

#define EMIF_CE1CTL1_DEFAULT         (0xFF03u)

/* ============================================================== */
 /* Make CE1CTL2 register values based on symbolic constants  */

/*  CE1CTL2 field values  */

	#define EMIF_CE1CTL2_WRITE_SETUP_OF(x)			((Uint16)(x))
	#define EMIF_CE1CTL2_WRITE_SETUP_DEFAULT			EMIF_CE1CTL2_WRITE_SETUP_OF(15)

	#define EMIF_CE1CTL2_WRITE_STROBE_OF(x)			((Uint16)(x))
	#define EMIF_CE1CTL2_WRITE_STROBE_DEFAULT			EMIF_CE1CTL2_WRITE_STROBE_OF(0x3fu)

	#define EMIF_CE1CTL2_WRITE_HOLD_OF(x)			((Uint16)(x))
	#define EMIF_CE1CTL2_WRITE_HOLD_DEFAULT			EMIF_CE1CTL2_WRITE_HOLD_OF(3)

	#define EMIF_CE1CTL2_READ_SETUP_OF(x)			((Uint16)(x))
	#define EMIF_CE1CTL2_READ_SETUP_DEFAULT			EMIF_CE1CTL2_READ_SETUP_OF(15)

#define EMIF_CE1CTL2_RMK(write_setup,write_strobe,write_hold,read_setup)\
 ((Uint16) ( \
  ( EMIF_FMK(CE1CTL2,WRITE_SETUP,write_setup))|\
  ( EMIF_FMK(CE1CTL2,WRITE_STROBE,write_strobe))|\
  ( EMIF_FMK(CE1CTL2,WRITE_HOLD,write_hold))|\
  ( EMIF_FMK(CE1CTL2,READ_SETUP,read_setup))\
)\
 )

#define EMIF_CE1CTL2_RMKS(write_setup_sym,write_strobe_sym,write_hold_sym,read_setup_sym)\
 ((Uint16) ( \
  ( EMIF_FMKS(CE1CTL2,WRITE_SETUP,write_setup_sym))|\
  ( EMIF_FMKS(CE1CTL2,WRITE_STROBE,write_strobe_sym))|\
  ( EMIF_FMKS(CE1CTL2,WRITE_HOLD,write_hold_sym))|\
  ( EMIF_FMKS(CE1CTL2,READ_SETUP,read_setup_sym))\
)\
 )

/*  Default CE1CTL2 register value  */

#define EMIF_CE1CTL2_DEFAULT           (0xFFFFu)

/* ============================================================== */
 /* Make CE1SEC1 register values based on symbolic constants  */

/*  CE1SEC1 field values  */

	#define EMIF_CE1SEC1_SNCCLK_SYNC_ECLKOUT1			(000000u)
	#define EMIF_CE1SEC1_SNCCLK_SYNC_ECLKOUT2			(0x0001u)
	#define EMIF_CE1SEC1_SNCCLK_DEFAULT		EMIF_CE1SEC1_SNCCLK_SYNC_ECLKOUT1

	#define EMIF_CE1SEC1_REN_ADS			(000000u)
	#define EMIF_CE1SEC1_REN_REN			(0x0001u)
	#define EMIF_CE1SEC1_REN_DEFAULT		EMIF_CE1SEC1_REN_ADS

	#define EMIF_CE1SEC1_RENEN_ADS			(000000u)
	#define EMIF_CE1SEC1_RENEN_REN			(0x0001u)
	#define EMIF_CE1SEC1_RENEN_DEFAULT		EMIF_CE1SEC1_RENEN_ADS

	#define EMIF_CE1SEC1_CEEXT_CE_TIED_TO_SOE			(0x0001u)
	#define EMIF_CE1SEC1_CEEXT_CE_TIED_TO_SNCCRL			(000000u)
	#define EMIF_CE1SEC1_CEEXT_DEFAULT		EMIF_CE1SEC1_CEEXT_CE_TIED_TO_SNCCRL

	#define EMIF_CE1SEC1_SYNCWL_0CYCLES			(000000u)
	#define EMIF_CE1SEC1_SYNCWL_1CYCLES			(0x0001u)
	#define EMIF_CE1SEC1_SYNCWL_2CYCLES			(0x0002u)
	#define EMIF_CE1SEC1_SYNCWL_3CYCLES			(0x0003u)
	#define EMIF_CE1SEC1_SYNCWL_DEFAULT		EMIF_CE1SEC1_SYNCWL_2CYCLES

	#define EMIF_CE1SEC1_SYNCRL_0CYCLES			(000000u)
	#define EMIF_CE1SEC1_SYNCRL_1CYCLE			(0x0001u)
	#define EMIF_CE1SEC1_SYNCRL_2CYCLES			(0x0002u)
	#define EMIF_CE1SEC1_SYNCRL_3CYCLES			(0x0003u)
	#define EMIF_CE1SEC1_SYNCRL_DEFAULT		EMIF_CE1SEC1_SYNCRL_2CYCLES

#define EMIF_CE1SEC1_RMK(sncclk,renen,ceext,syncwl,syncrl)\
 ((Uint16) ( \
  ( EMIF_FMK(CE1SEC1,SNCCLK,sncclk))|\
  ( EMIF_FMK(CE1SEC1,RENEN,renen))|\
  ( EMIF_FMK(CE1SEC1,CEEXT,ceext))|\
  ( EMIF_FMK(CE1SEC1,SYNCWL,syncwl))|\
  ( EMIF_FMK(CE1SEC1,SYNCRL,syncrl))\
)\
 )

#define EMIF_CE1SEC1_RMKS(sncclk_sym,renen_sym,ceext_sym,syncwl_sym,syncrl_sym)\
 ((Uint16) ( \
  ( EMIF_FMKS(CE1SEC1,SNCCLK,sncclk_sym))|\
  ( EMIF_FMKS(CE1SEC1,RENEN,renen_sym))|\
  ( EMIF_FMKS(CE1SEC1,CEEXT,ceext_sym))|\
  ( EMIF_FMKS(CE1SEC1,SYNCWL,syncwl_sym))|\
  ( EMIF_FMKS(CE1SEC1,SYNCRL,syncrl_sym))\
)\
 )



/*  Default CE1SEC1 register value  */

#define EMIF_CE1SEC1_DEFAULT             (0x0002u)

/* ============================================================== */
 /* Make CE2CTL1 register values based on symbolic constants  */

/*  CE2CTL1 field values  */

	#define EMIF_CE2CTL1_TA_OF(x)			((Uint16)(x))
	#define EMIF_CE2CTL1_TA_DEFAULT		EMIF_CE2CTL1_TA_OF(3)

	#define EMIF_CE2CTL1_READ_STROBE_OF(x)		((Uint16)(x))
	#define EMIF_CE2CTL1_READ_STROBE_DEFAULT		EMIF_CE2CTL1_READ_STROBE_OF(0x3fu)

	#define EMIF_CE2CTL1_MTYPE_8BIT_ASYNC			(000000u)
	#define EMIF_CE2CTL1_MTYPE_16BIT_ASYNC			(0x0001u)
	#define EMIF_CE2CTL1_MTYPE_32BIT_ASYNC			(0x0002u)
	#define EMIF_CE2CTL1_MTYPE_32BIT_SDRAM			(0x0003u)
	#define EMIF_CE2CTL1_MTYPE_32BIT_SBSRAM			(0x0004u)
	#define EMIF_CE2CTL1_MTYPE_8BIT_SDRAM			(0x0008u)
	#define EMIF_CE2CTL1_MTYPE_16BIT_SDRAM			(0x0009u)
	#define EMIF_CE2CTL1_MTYPE_8BIT_SBSRAM			(000010u)
	#define EMIF_CE2CTL1_MTYPE_16BIT_SBSRAM			(000011u)
	#define EMIF_CE2CTL1_MTYPE_DEFAULT		EMIF_CE2CTL1_MTYPE_8BIT_ASYNC

	#define EMIF_CE2CTL1_WRITE_HOLD_MSB_HIGH			(0x0001u)
	#define EMIF_CE2CTL1_WRITE_HOLD_MSB_LOW			(000000u)
	#define EMIF_CE2CTL1_WRITE_HOLD_MSB_DEFAULT		EMIF_CE2CTL1_WRITE_HOLD_MSB_LOW

	#define EMIF_CE2CTL1_WRITE_HOLD_HIGH			(0x0001u)
	#define EMIF_CE2CTL1_WRITE_HOLD_LOW				(000000u)
	#define EMIF_CE2CTL1_WRITE_HOLD_DEFAULT			EMIF_CE2CTL1_WRITE_HOLD_LOW

	#define EMIF_CE2CTL1_READ_HOLD_OF(x)		((Uint16)(x))
	#define EMIF_CE2CTL1_READ_HOLD_DEFAULT		EMIF_CE2CTL1_READ_HOLD_OF(3)


#define EMIF_CE2CTL1_RMK(ta,read_strobe,mtype,write_hold,read_hold)\
 ((Uint16) ( \
  ( EMIF_FMK(CE2CTL1,TA,ta))|\
  ( EMIF_FMK(CE2CTL1,READ_STROBE,read_strobe))|\
  ( EMIF_FMK(CE2CTL1,MTYPE,mtype))|\
  ( EMIF_FMK(CE2CTL1,WRITE_HOLD,write_hold))|\
  ( EMIF_FMK(CE2CTL1,READ_HOLD,read_hold))\
)\
 )

#define EMIF_CE2CTL1_RMKS(ta_sym,read_strobe_sym,mtype_sym,write_hold_sym,read_hold_sym)\
 ((Uint16) ( \
  ( EMIF_FMKS(CE2CTL1,TA,ta_sym))|\
  ( EMIF_FMKS(CE2CTL1,READ_STROBE,read_strobe_sym))|\
  ( EMIF_FMKS(CE2CTL1,MTYPE,mtype_sym))|\
  ( EMIF_FMKS(CE2CTL1,WRITE_HOLD,write_hold_sym))|\
  ( EMIF_FMKS(CE2CTL1,READ_HOLD,read_hold_sym))\
)\
 )

/*  Default CE2CTL1 register value  */

#define EMIF_CE2CTL1_DEFAULT          (0xFF03u)

/* ============================================================== */
 /* Make CE2CTL2 register values based on symbolic constants  */

/*  CE2CTL2 field values  */

	#define EMIF_CE2CTL2_WRITE_SETUP_OF(x)			((Uint16)(x))
	#define EMIF_CE2CTL2_WRITE_SETUP_DEFAULT			EMIF_CE2CTL2_WRITE_SETUP_OF(15)

	#define EMIF_CE2CTL2_WRITE_STROBE_OF(x)			((Uint16)(x))
	#define EMIF_CE2CTL2_WRITE_STROBE_DEFAULT			EMIF_CE2CTL2_WRITE_STROBE_OF(0x3fu)

	#define EMIF_CE2CTL2_WRITE_HOLD_OF(x)			((Uint16)(x))
	#define EMIF_CE2CTL2_WRITE_HOLD_DEFAULT			EMIF_CE2CTL2_WRITE_HOLD_OF(3)

	#define EMIF_CE2CTL2_READ_SETUP_OF(x)			((Uint16)(x))
	#define EMIF_CE2CTL2_READ_SETUP_DEFAULT			EMIF_CE2CTL2_READ_SETUP_OF(15)

#define EMIF_CE2CTL2_RMK(write_setup,write_strobe,write_hold,read_setup)\
 ((Uint16) ( \
  ( EMIF_FMK(CE2CTL2,WRITE_SETUP,write_setup))|\
  ( EMIF_FMK(CE2CTL2,WRITE_STROBE,write_strobe))|\
  ( EMIF_FMK(CE2CTL2,WRITE_HOLD,write_hold))|\
  ( EMIF_FMK(CE2CTL2,READ_SETUP,read_setup))\
)\
 )

#define EMIF_CE2CTL2_RMKS(write_setup_sym,write_strobe_sym,write_hold_sym,read_setup_sym)\
 ((Uint16) ( \
  ( EMIF_FMKS(CE2CTL2,WRITE_SETUP,write_setup_sym))|\
  ( EMIF_FMKS(CE2CTL2,WRITE_STROBE,write_strobe_sym))|\
  ( EMIF_FMKS(CE2CTL2,WRITE_HOLD,write_hold_sym))|\
  ( EMIF_FMKS(CE2CTL2,READ_SETUP,read_setup_sym))\
)\
 )

/*  Default CE2CTL2 register value  */

#define EMIF_CE2CTL2_DEFAULT           (0xFFFFu)

/* ============================================================== */
 /* Make CE2SEC1 register values based on symbolic constants  */

/*  CE2SEC1 field values  */

	#define EMIF_CE2SEC1_SNCCLK_SYNC_ECLKOUT1			(000000u)
	#define EMIF_CE2SEC1_SNCCLK_SYNC_ECLKOUT2			(0x0001u)
	#define EMIF_CE2SEC1_SNCCLK_DEFAULT		EMIF_CE2SEC1_SNCCLK_SYNC_ECLKOUT1

	#define EMIF_CE2SEC1_REN_ADS			(000000u)
	#define EMIF_CE2SEC1_REN_REN			(0x0001u)
	#define EMIF_CE2SEC1_REN_DEFAULT		EMIF_CE2SEC1_REN_ADS

	#define EMIF_CE2SEC1_RENEN_ADS			(000000u)
	#define EMIF_CE2SEC1_RENEN_REN			(0x0001u)
	#define EMIF_CE2SEC1_RENEN_DEFAULT		EMIF_CE2SEC1_RENEN_ADS

	#define EMIF_CE2SEC1_CEEXT_CE_TIED_TO_SOE			(0x0001u)
	#define EMIF_CE2SEC1_CEEXT_CE_TIED_TO_SNCCRL			(000000u)
	#define EMIF_CE2SEC1_CEEXT_DEFAULT		EMIF_CE2SEC1_CEEXT_CE_TIED_TO_SNCCRL

	#define EMIF_CE2SEC1_SYNCWL_0CYCLES			(000000u)
	#define EMIF_CE2SEC1_SYNCWL_1CYCLES			(0x0001u)
	#define EMIF_CE2SEC1_SYNCWL_2CYCLES			(0x0002u)
	#define EMIF_CE2SEC1_SYNCWL_3CYCLES			(0x0003u)
	#define EMIF_CE2SEC1_SYNCWL_DEFAULT		EMIF_CE2SEC1_SYNCWL_2CYCLES

	#define EMIF_CE2SEC1_SYNCRL_0CYCLES			(000000u)
	#define EMIF_CE2SEC1_SYNCRL_1CYCLE			(0x0001u)
	#define EMIF_CE2SEC1_SYNCRL_2CYCLES			(0x0002u)
	#define EMIF_CE2SEC1_SYNCRL_3CYCLES			(0x0003u)
	#define EMIF_CE2SEC1_SYNCRL_DEFAULT		EMIF_CE2SEC1_SYNCRL_2CYCLES


#define EMIF_CE2SEC1_RMK(sncclk,renen,ceext,syncwl,syncrl)\
 ((Uint16) ( \
  ( EMIF_FMK(CE2SEC1,SNCCLK,sncclk))|\
  ( EMIF_FMK(CE2SEC1,RENEN,renen))|\
  ( EMIF_FMK(CE2SEC1,CEEXT,ceext))|\
  ( EMIF_FMK(CE2SEC1,SYNCWL,syncwl))|\
  ( EMIF_FMK(CE2SEC1,SYNCRL,syncrl))\
)\
 )

#define EMIF_CE2SEC1_RMKS(sncclk_sym,renen_sym,ceext_sym,syncwl_sym,syncrl_sym)\
 ((Uint16) ( \
  ( EMIF_FMKS(CE2SEC1,SNCCLK,sncclk_sym))|\
  ( EMIF_FMKS(CE2SEC1,RENEN,renen_sym))|\
  ( EMIF_FMKS(CE2SEC1,CEEXT,ceext_sym))|\
  ( EMIF_FMKS(CE2SEC1,SYNCWL,syncwl_sym))|\
  ( EMIF_FMKS(CE2SEC1,SYNCRL,syncrl_sym))\
)\
 )



/*  Default CE2SEC1 register value  */

#define EMIF_CE2SEC1_DEFAULT         (0x0002u)

/* ============================================================== */
 /* Make CE3CTL1 register values based on symbolic constants  */

/*  CE3CTL1 field values  */

	#define EMIF_CE3CTL1_TA_OF(x)			((Uint16)(x))
	#define EMIF_CE3CTL1_TA_DEFAULT		EMIF_CE3CTL1_TA_OF(3)

	#define EMIF_CE3CTL1_READ_STROBE_OF(x)		((Uint16)(x))
	#define EMIF_CE3CTL1_READ_STROBE_DEFAULT		EMIF_CE3CTL1_READ_STROBE_OF(0x3fu)

	#define EMIF_CE3CTL1_MTYPE_8BIT_ASYNC			(000000u)
	#define EMIF_CE3CTL1_MTYPE_16BIT_ASYNC			(0x0001u)
	#define EMIF_CE3CTL1_MTYPE_32BIT_ASYNC			(0x0002u)
	#define EMIF_CE3CTL1_MTYPE_32BIT_SDRAM			(0x0003u)
	#define EMIF_CE3CTL1_MTYPE_32BIT_SBSRAM			(0x0004u)
	#define EMIF_CE3CTL1_MTYPE_8BIT_SDRAM			(0x0008u)
	#define EMIF_CE3CTL1_MTYPE_16BIT_SDRAM			(0x0009u)
	#define EMIF_CE3CTL1_MTYPE_8BIT_SBSRAM			(000010u)
	#define EMIF_CE3CTL1_MTYPE_16BIT_SBSRAM			(000011u)
	#define EMIF_CE3CTL1_MTYPE_DEFAULT		EMIF_CE3CTL1_MTYPE_8BIT_ASYNC

	#define EMIF_CE3CTL1_WRITE_HOLD_MSB_HIGH			(0x0001u)
	#define EMIF_CE3CTL1_WRITE_HOLD_MSB_LOW			(000000u)
	#define EMIF_CE3CTL1_WRITE_HOLD_MSB_DEFAULT		EMIF_CE3CTL1_WRITE_HOLD_MSB_LOW

	#define EMIF_CE3CTL1_WRITE_HOLD_HIGH			(0x0001u)
	#define EMIF_CE3CTL1_WRITE_HOLD_LOW				(000000u)
	#define EMIF_CE3CTL1_WRITE_HOLD_DEFAULT			EMIF_CE3CTL1_WRITE_HOLD_LOW

	#define EMIF_CE3CTL1_READ_HOLD_OF(x)		((Uint16)(x))
	#define EMIF_CE3CTL1_READ_HOLD_DEFAULT		EMIF_CE3CTL1_READ_HOLD_OF(3)


#define EMIF_CE3CTL1_RMK(ta,read_strobe,mtype,write_hold,read_hold)\
 ((Uint16) ( \
  ( EMIF_FMK(CE3CTL1,TA,ta))|\
  ( EMIF_FMK(CE3CTL1,READ_STROBE,read_strobe))|\
  ( EMIF_FMK(CE3CTL1,MTYPE,mtype))|\
  ( EMIF_FMK(CE3CTL1,WRITE_HOLD,write_hold))|\
  ( EMIF_FMK(CE3CTL1,READ_HOLD,read_hold))\
)\
 )

#define EMIF_CE3CTL1_RMKS(ta_sym,read_strobe_sym,mtype_sym,write_hold_sym,read_hold_sym)\
 ((Uint16) ( \
  ( EMIF_FMKS(CE3CTL1,TA,ta_sym))|\
  ( EMIF_FMKS(CE3CTL1,READ_STROBE,read_strobe_sym))|\
  ( EMIF_FMKS(CE3CTL1,MTYPE,mtype_sym))|\
  ( EMIF_FMKS(CE3CTL1,WRITE_HOLD,write_hold_sym))|\
  ( EMIF_FMKS(CE3CTL1,READ_HOLD,read_hold_sym))\
)\
 )

/*  Default CE3CTL1 register value  */

#define EMIF_CE3CTL1_DEFAULT          (0xFF03u)

/* ============================================================== */
 /* Make CE3CTL2 register values based on symbolic constants  */

/*  CE3CTL2 field values  */

	#define EMIF_CE3CTL2_WRITE_SETUP_OF(x)			((Uint16)(x))
	#define EMIF_CE3CTL2_WRITE_SETUP_DEFAULT			EMIF_CE3CTL2_WRITE_SETUP_OF(15)

	#define EMIF_CE3CTL2_WRITE_STROBE_OF(x)			((Uint16)(x))
	#define EMIF_CE3CTL2_WRITE_STROBE_DEFAULT			EMIF_CE3CTL2_WRITE_STROBE_OF(0x3fu)

	#define EMIF_CE3CTL2_WRITE_HOLD_OF(x)			((Uint16)(x))
	#define EMIF_CE3CTL2_WRITE_HOLD_DEFAULT			EMIF_CE3CTL2_WRITE_HOLD_OF(3)

	#define EMIF_CE3CTL2_READ_SETUP_OF(x)			((Uint16)(x))
	#define EMIF_CE3CTL2_READ_SETUP_DEFAULT			EMIF_CE3CTL2_READ_SETUP_OF(15)



#define EMIF_CE3CTL2_RMK(write_setup,write_strobe,write_hold,read_setup)\
 ((Uint16) ( \
  ( EMIF_FMK(CE3CTL2,WRITE_SETUP,write_setup))|\
  ( EMIF_FMK(CE3CTL2,WRITE_STROBE,write_strobe))|\
  ( EMIF_FMK(CE3CTL2,WRITE_HOLD,write_hold))|\
  ( EMIF_FMK(CE3CTL2,READ_SETUP,read_setup))\
)\
 )

#define EMIF_CE3CTL2_RMKS(write_setup_sym,write_strobe_sym,write_hold_sym,read_setup_sym)\
 ((Uint16) ( \
  ( EMIF_FMKS(CE3CTL2,WRITE_SETUP,write_setup_sym))|\
  ( EMIF_FMKS(CE3CTL2,WRITE_STROBE,write_strobe_sym))|\
  ( EMIF_FMKS(CE3CTL2,WRITE_HOLD,write_hold_sym))|\
  ( EMIF_FMKS(CE3CTL2,READ_SETUP,read_setup_sym))\
)\
 )

/*  Default CE3CTL2 register value  */

#define EMIF_CE3CTL2_DEFAULT              (0xFFFFu)

/* ============================================================== */
 /* Make CE3SEC1 register values based on symbolic constants  */

/*  CE3SEC1 field values  */

	#define EMIF_CE3SEC1_SNCCLK_SYNC_ECLKOUT1			(000000u)
	#define EMIF_CE3SEC1_SNCCLK_SYNC_ECLKOUT2			(0x0001u)
	#define EMIF_CE3SEC1_SNCCLK_DEFAULT		EMIF_CE3SEC1_SNCCLK_SYNC_ECLKOUT1

	#define EMIF_CE3SEC1_REN_ADS			(000000u)
	#define EMIF_CE3SEC1_REN_REN			(0x0001u)
	#define EMIF_CE3SEC1_REN_DEFAULT		EMIF_CE3SEC1_REN_ADS

	#define EMIF_CE3SEC1_RENEN_ADS			(000000u)
	#define EMIF_CE3SEC1_RENEN_REN			(0x0001u)
	#define EMIF_CE3SEC1_RENEN_DEFAULT			EMIF_CE3SEC1_RENEN_ADS

	#define EMIF_CE3SEC1_CEEXT_CE_TIED_TO_SOE			(0x0001u)
	#define EMIF_CE3SEC1_CEEXT_CE_TIED_TO_SNCCRL			(000000u)
	#define EMIF_CE3SEC1_CEEXT_DEFAULT		EMIF_CE3SEC1_CEEXT_CE_TIED_TO_SNCCRL

	#define EMIF_CE3SEC1_SYNCWL_0CYCLES			(000000u)
	#define EMIF_CE3SEC1_SYNCWL_1CYCLES			(0x0001u)
	#define EMIF_CE3SEC1_SYNCWL_2CYCLES			(0x0002u)
	#define EMIF_CE3SEC1_SYNCWL_3CYCLES			(0x0003u)
	#define EMIF_CE3SEC1_SYNCWL_DEFAULT		EMIF_CE3SEC1_SYNCWL_2CYCLES

	#define EMIF_CE3SEC1_SYNCRL_0CYCLES			(000000u)
	#define EMIF_CE3SEC1_SYNCRL_1CYCLE			(0x0001u)
	#define EMIF_CE3SEC1_SYNCRL_2CYCLES			(0x0002u)
	#define EMIF_CE3SEC1_SYNCRL_3CYCLES			(0x0003u)
	#define EMIF_CE3SEC1_SYNCRL_DEFAULT		EMIF_CE3SEC1_SYNCRL_2CYCLES

#define EMIF_CE3SEC1_RMK(sncclk,renen,ceext,syncwl,syncrl)\
 ((Uint16) ( \
  ( EMIF_FMK(CE3SEC1,SNCCLK,sncclk))|\
  ( EMIF_FMK(CE3SEC1,RENEN,renen))|\
  ( EMIF_FMK(CE3SEC1,CEEXT,ceext))|\
  ( EMIF_FMK(CE3SEC1,SYNCWL,syncwl))|\
  ( EMIF_FMK(CE3SEC1,SYNCRL,syncrl))\
)\
 )

#define EMIF_CE3SEC1_RMKS(sncclk_sym,renen_sym,ceext_sym,syncwl_sym,syncrl_sym)\
 ((Uint16) ( \
  ( EMIF_FMKS(CE3SEC1,SNCCLK,sncclk_sym))|\
  ( EMIF_FMKS(CE3SEC1,RENEN,renen_sym))|\
  ( EMIF_FMKS(CE3SEC1,CEEXT,ceext_sym))|\
  ( EMIF_FMKS(CE3SEC1,SYNCWL,syncwl_sym))|\
  ( EMIF_FMKS(CE3SEC1,SYNCRL,syncrl_sym))\
)\
 )


/*  Default CE3SEC1 register value  */

#define EMIF_CE3SEC1_DEFAULT              (0x0002u)

/* ============================================================== */
 /* Make GBLCTL1 register values based on symbolic constants  */

/*  GBLCTL1 field values  */

	#define EMIF_GBLCTL1_ARDY_DEV_NOT_READY			(000000u)
	#define EMIF_GBLCTL1_ARDY_DEV_READY			(0x0001u)
	#define EMIF_GBLCTL1_HOLD_EXT_REQUEST			(000000u)
	#define EMIF_GBLCTL1_HOLD_NO_REQUEST			(0x0001u)
	#define EMIF_GBLCTL1_HOLDA_EXT_DEV_OWNS_EMIF			(000000u)
	#define EMIF_GBLCTL1_HOLDA_EMIF_FREE			(0x0001u)
	#define EMIF_GBLCTL1_NOHOLD_HOLD_ENABLED			(000000u)
	#define EMIF_GBLCTL1_NOHOLD_HOLD_DISABLED			(0x0001u)
	#define EMIF_GBLCTL1_NOHOLD_DEFAULT		EMIF_GBLCTL1_NOHOLD_HOLD_DISABLED

	#define EMIF_GBLCTL1_EK1HZ_HIGHZ			(0x0001u)
	#define EMIF_GBLCTL1_EK1HZ_EK1EN			(000000u)
	#define EMIF_GBLCTL1_EK1HZ_DEFAULT		EMIF_GBLCTL1_EK1HZ_EK1EN

	#define EMIF_GBLCTL1_EK1EN_ENABLED			(000001u)
	#define EMIF_GBLCTL1_EK1EN_DISABLED			(000000u)

#define EMIF_GBLCTL1_RMK(nohold,ek1hz,ek1en)\
 ((Uint16) ( \
  ( EMIF_FMK(GBLCTL1,NOHOLD,nohold))|\
  ( EMIF_FMK(GBLCTL1,EK1HZ,ek1hz))|\
  ( EMIF_FMK(GBLCTL1,EK1EN,ek1en))\
)\
 )

#define EMIF_GBLCTL1_RMKS(nohold_sym,ek1hz_sym,ek1en_sym)\
 ((Uint16) ( \
  ( EMIF_FMKS(GBLCTL1,NOHOLD,nohold_sym))|\
  ( EMIF_FMKS(GBLCTL1,EK1HZ,ek1hz_sym))|\
  ( EMIF_FMKS(GBLCTL1,EK1EN,ek1en_sym))\
)\
 )

/*  Default GBLCTL1 register value  */

#define EMIF_GBLCTL1_DEFAULT                 (0x0060u)

/* ============================================================== */
 /* Make GBLCTL2 register values based on symbolic constants  */

/*  GBLCTL2 field values  */

	#define EMIF_GBLCTL2_EK2RATE_1XCLK			(000000u)
	#define EMIF_GBLCTL2_EK2RATE_2XCLK			(0x0001u)
	#define EMIF_GBLCTL2_EK2RATE_4XCLK			(0x0002u)
	#define EMIF_GBLCTL2_EK2RATE_DEFAULT		EMIF_GBLCTL2_EK2RATE_1XCLK

	#define EMIF_GBLCTL2_EK2HZ_HIGHZ			(0x0001u)
	#define EMIF_GBLCTL2_EK2HZ_EK2EN			(000000u)
	#define EMIF_GBLCTL2_EK2HZ_DEFAULT		EMIF_GBLCTL2_EK2HZ_EK2EN

	#define EMIF_GBLCTL2_EK2EN_ENABLED			(0x0001u)
	#define EMIF_GBLCTL2_EK2EN_DISABLED			(000000u)
	#define EMIF_GBLCTL2_EK2EN_DEFAULT		EMIF_GBLCTL2_EK2EN_ENABLED


#define EMIF_GBLCTL2_RMK(ek2rate,ek2hz,ek2en)\
 ((Uint16) ( \
  ( EMIF_FMK(GBLCTL2,EK2RATE,ek2rate))|\
  ( EMIF_FMK(GBLCTL2,EK2HZ,ek2hz))|\
  ( EMIF_FMK(GBLCTL2,EK2EN,ek2en))\
)\
 )

#define EMIF_GBLCTL2_RMKS(ek2rate_sym,ek2hz_sym,ek2en_sym)\
 ((Uint16) ( \
  ( EMIF_FMKS(GBLCTL2,EK2RATE,ek2rate_sym))|\
  ( EMIF_FMKS(GBLCTL2,EK2HZ,ek2hz_sym))|\
  ( EMIF_FMKS(GBLCTL2,EK2EN,ek2en_sym))\
)\
 )

/*  Default GBLCTL2 register value  */

#define EMIF_GBLCTL2_DEFAULT         (0x0009u)

/* ============================================================== */
 /* Make SDCTL1 register values based on symbolic constants  */

/*  SDCTL1 field values  */

	#define EMIF_SDCTL1_TRC_OF(x)			((Uint16)(x))
	#define EMIF_SDCTL1_SLFRFR_ENABLED			(0x0001u)
	#define EMIF_SDCTL1_SLFRFR_DISABLED			(000000u)
	#define EMIF_SDCTL1_SLFRFR_GP_OUTPUT			(000000u)
	#define EMIF_SDCTL1_SLFRFR_DEFAULT		EMIF_SDCTL1_SLFRFR_DISABLED


#define EMIF_SDCTL1_RMK(trc,slfrfr)\
 ((Uint16) ( \
  ( EMIF_FMK(SDCTL1,TRC,trc))|\
  ( EMIF_FMK(SDCTL1,SLFRFR,slfrfr))\
)\
 )

#define EMIF_SDCTL1_RMKS(trc_sym,slfrfr_sym)\
 ((Uint16) ( \
  ( EMIF_FMKS(SDCTL1,TRC,trc_sym))|\
  ( EMIF_FMKS(SDCTL1,SLFRFR,slfrfr_sym))\
)\
 )

/*  Default SDCTL1 register value  */

#define EMIF_SDCTL1_DEFAULT          (0xF000u)

/* ============================================================== */
 /* Make SDCTL2 register values based on symbolic constants  */

/*  SDCTL2 field values  */

	#define EMIF_SDCTL2_SDWTH_2BANKS			(000000u)
	#define EMIF_SDCTL2_SDWTH_4BANKS			(0x0010u)
	#define EMIF_SDCTL2_SDWTH_11ROW_ADDR_PINS			(000000u)
	#define EMIF_SDCTL2_SDWTH_12ROW_ADDR_PINS			(0x0004u)
	#define EMIF_SDCTL2_SDWTH_13ROW_ADDR_PINS			(0x0008u)
	#define EMIF_SDCTL2_SDWTH_9COL_ADDR_PINS			(000000u)
	#define EMIF_SDCTL2_SDWTH_8COL_ADDR_PINS			(0x0001u)
	#define EMIF_SDCTL2_SDWTH_10COL_ADDR_PINS			(0x0002u)
	#define EMIF_SDCTL2_SDWTH_DEFAULT		EMIF_SDCTL2_SDWTH_2BANKS

	#define EMIF_SDCTL2_RFEN_ENABLED			(0x0001u)
	#define EMIF_SDCTL2_RFEN_DISABLED			(000000u)
	#define EMIF_SDCTL2_RFEN_DEFAULT		EMIF_SDCTL2_RFEN_ENABLED

	#define EMIF_SDCTL2_INIT_INIT_SDRAM			(0x0001u)
	#define EMIF_SDCTL2_INIT_INIT_DONE			(000000u)
	#define EMIF_SDCTL2_TRCD_OF(x)			((Uint16)(x))
	#define EMIF_SDCTL2_TRP_OF(x)			((Uint16)(x))

#define EMIF_SDCTL2_RMK(sdwth,rfen,init,trcd,trp)\
 ((Uint16) ( \
  ( EMIF_FMK(SDCTL2,SDWTH,sdwth))|\
  ( EMIF_FMK(SDCTL2,RFEN,rfen))|\
  ( EMIF_FMK(SDCTL2,INIT,init))|\
  ( EMIF_FMK(SDCTL2,TRCD,trcd))|\
  ( EMIF_FMK(SDCTL2,TRP,trp))\
)\
 )

#define EMIF_SDCTL2_RMKS(sdwth_sym,rfen_sym,init_sym,trcd_sym,trp_sym)\
 ((Uint16) ( \
  ( EMIF_FMKS(SDCTL2,SDWTH,sdwth_sym))|\
  ( EMIF_FMKS(SDCTL2,RFEN,rfen_sym))|\
  ( EMIF_FMKS(SDCTL2,INIT,init_sym))|\
  ( EMIF_FMKS(SDCTL2,TRCD,trcd_sym))|\
  ( EMIF_FMKS(SDCTL2,TRP,trp_sym))\
)\
 )

/*  Default SDCTL2 register value  */

#define EMIF_SDCTL2_DEFAULT           (0x0348u)

/* ============================================================== */
 /* Make SDEXT1 register values based on symbolic constants  */

/*  SDEXT1 field values  */

	#define EMIF_SDEXT1_R2WDQM_1CYCLE			(0x0001u)
	#define EMIF_SDEXT1_R2WDQM_2CYCLES			(0x0002u)
	#define EMIF_SDEXT1_R2WDQM_3CYCLES			(0x0003u)
	#define EMIF_SDEXT1_R2WDQM_DEFAULT		EMIF_SDEXT1_R2WDQM_2CYCLES

	#define EMIF_SDEXT1_RD2WR_3CYCLES			(0x0003u)
	#define EMIF_SDEXT1_RD2WR_4CYCLES			(0x0004u)
	#define EMIF_SDEXT1_RD2WR_5CYCLES			(0x0005u)
	#define EMIF_SDEXT1_RD2WR_DEFAULT		EMIF_SDEXT1_RD2WR_5CYCLES

	#define EMIF_SDEXT1_RD2DEAC_1CYCLE			(0x0001u)
	#define EMIF_SDEXT1_RD2DEAC_2CYCLES			(0x0002u)
	#define EMIF_SDEXT1_RD2DEAC_3CYCLES			(0x0003u)
	#define EMIF_SDEXT1_RD2DEAC_DEFAULT		EMIF_SDEXT1_RD2DEAC_3CYCLES

	#define EMIF_SDEXT1_RD2RD_1CYCLE			(000000u)
	#define EMIF_SDEXT1_RD2RD_2CYCLES			(0x0001u)
	#define EMIF_SDEXT1_RD2RD_DEFAULT		EMIF_SDEXT1_RD2RD_2CYCLES

	#define EMIF_SDEXT1_THZP_OF(x)			((Uint16)(x))
	#define EMIF_SDEXT1_TWR_OF(x)			((Uint16)(x))
	#define EMIF_SDEXT1_TRRD_2CYCLES			(000000u)
	#define EMIF_SDEXT1_TRRD_3CYCLES			(0x0001u)
	#define EMIF_SDEXT1_TRRD_DEFAULT		EMIF_SDEXT1_TRRD_3CYCLES

	#define EMIF_SDEXT1_TRAS_OF(x)			((Uint16)(x))
	#define EMIF_SDEXT1_TCL_2CYCLES			(000000u)
	#define EMIF_SDEXT1_TCL_3CYCLES			(0x0001u)
	#define EMIF_SDEXT1_TCL_DEFAULT		EMIF_SDEXT1_TCL_3CYCLES


#define EMIF_SDEXT1_RMK(r2wdqm,rd2wr,rd2deac,rd2rd,thzp,twr,trrd,tras,tcl)\
 ((Uint16) ( \
  ( EMIF_FMK(SDEXT1,R2WDQM,r2wdqm))|\
  ( EMIF_FMK(SDEXT1,RD2WR,rd2wr))|\
  ( EMIF_FMK(SDEXT1,RD2DEAC,rd2deac))|\
  ( EMIF_FMK(SDEXT1,RD2RD,rd2rd))|\
  ( EMIF_FMK(SDEXT1,THZP,thzp))|\
  ( EMIF_FMK(SDEXT1,TWR,twr))|\
  ( EMIF_FMK(SDEXT1,TRRD,trrd))|\
  ( EMIF_FMK(SDEXT1,TRAS,tras))|\
  ( EMIF_FMK(SDEXT1,TCL,tcl))\
)\
 )

#define EMIF_SDEXT1_RMKS(r2wdqm_sym,rd2wr_sym,rd2deac_sym,rd2rd_sym,thzp_sym,twr_sym,trrd_sym,tras_sym,tcl_sym)\
 ((Uint16) ( \
  ( EMIF_FMKS(SDEXT1,R2WDQM,r2wdqm_sym))|\
  ( EMIF_FMKS(SDEXT1,RD2WR,rd2wr_sym))|\
  ( EMIF_FMKS(SDEXT1,RD2DEAC,rd2deac_sym))|\
  ( EMIF_FMKS(SDEXT1,RD2RD,rd2rd_sym))|\
  ( EMIF_FMKS(SDEXT1,THZP,thzp_sym))|\
  ( EMIF_FMKS(SDEXT1,TWR,twr_sym))|\
  ( EMIF_FMKS(SDEXT1,TRRD,trrd_sym))|\
  ( EMIF_FMKS(SDEXT1,TRAS,tras_sym))|\
  ( EMIF_FMKS(SDEXT1,TCL,tcl_sym))\
)\
 )

/*  Default SDEXT1 register value  */

#define EMIF_SDEXT1_DEFAULT           (0x5F3Fu)

/* ============================================================== */
 /* Make SDEXT2 register values based on symbolic constants  */

/*  SDEXT2 field values  */

	#define EMIF_SDEXT2_WR2RD_0CYCLES			(000000u)
	#define EMIF_SDEXT2_WR2RD_1CYCLE			(0x0001u)
	#define EMIF_SDEXT2_WR2RD_DEFAULT		EMIF_SDEXT2_WR2RD_1CYCLE

	#define EMIF_SDEXT2_WR2DEAC_1CYCLE			(0x0001u)
	#define EMIF_SDEXT2_WR2DEAC_DEFAULT		EMIF_SDEXT2_WR2DEAC_1CYCLE

	#define EMIF_SDEXT2_WR2WR_1CYCLE			(0x0001u)
	#define EMIF_SDEXT2_WR2WR_DEFAULT		EMIF_SDEXT2_WR2WR_1CYCLE

	#define EMIF_SDEXT2_R2WDQM_1CYCLE			(0x0001u)
	#define EMIF_SDEXT2_R2WDQM_2CYCLES			(0x0002u)
	#define EMIF_SDEXT2_R2WDQM_3CYCLES			(0x0003u)
	#define EMIF_SDEXT2_R2WDQM_DEFAULT		EMIF_SDEXT2_R2WDQM_2CYCLES


#define EMIF_SDEXT2_RMK(wr2rd,wr2deac,wr2wr,r2wdqm)\
 ((Uint16) ( \
  ( EMIF_FMK(SDEXT2,WR2RD,wr2rd))|\
  ( EMIF_FMK(SDEXT2,WR2DEAC,wr2deac))|\
  ( EMIF_FMK(SDEXT2,WR2WR,wr2wr))|\
  ( EMIF_FMK(SDEXT2,R2WDQM,r2wdqm))\
)\
 )

#define EMIF_SDEXT2_RMKS(wr2rd_sym,wr2deac_sym,wr2wr_sym,r2wdqm_sym)\
 ((Uint16) ( \
  ( EMIF_FMKS(SDEXT2,WR2RD,wr2rd_sym))|\
  ( EMIF_FMKS(SDEXT2,WR2DEAC,wr2deac_sym))|\
  ( EMIF_FMKS(SDEXT2,WR2WR,wr2wr_sym))|\
  ( EMIF_FMKS(SDEXT2,R2WDQM,r2wdqm_sym))\
)\
 )

/*  Default SDEXT2 register value  */

#define EMIF_SDEXT2_DEFAULT          (0x0017u)

/* ============================================================== */
 /* Make SDTIM1 register values based on symbolic constants  */

/*  SDTIM1 field values  */

	#define EMIF_SDTIM1_PERIOD_OF(x)			((Uint16)(x))

#define EMIF_SDTIM1_RMK(period)\
 ((Uint16) ( \
  ( EMIF_FMK(SDTIM1,PERIOD,period))\
)\
 )

#define EMIF_SDTIM1_RMKS(period_sym)\
 ((Uint16) ( \
  ( EMIF_FMKS(SDTIM1,PERIOD,period_sym))\
)\
 )

/*  Default SDTIM1 register value  */

#define EMIF_SDTIM1_DEFAULT         (0x05DCu)

/*  SDRFR1 field values  */

	#define EMIF_SDRFR1_PERIOD_OF(x)			((Uint16)(x))

#define EMIF_SDRFR1_RMK(period)\
 ((Uint16) ( \
  ( EMIF_FMK(SDRFR1,PERIOD,period))\
)\
 )

#define EMIF_SDRFR1_RMKS(period_sym)\
 ((Uint16) ( \
  ( EMIF_FMKS(SDRFR1,PERIOD,period_sym))\
)\
 )

/*  Default SDRFR1 register value  */

#define EMIF_SDRFR1_DEFAULT          (0x05DCu)


/* ============================================================== */
 /* Make SDTIM2 register values based on symbolic constants  */

/*  SDTIM2 field values  */

	#define EMIF_SDTIM2_EXTRA_REFRESHES_1REFRESH			(000000u)
	#define EMIF_SDTIM2_EXTRA_REFRESHES_2REFRESHES			(0x0001u)
	#define EMIF_SDTIM2_EXTRA_REFRESHES_3REFRESHES			(0x0002u)
	#define EMIF_SDTIM2_EXTRA_REFRESHES_4REFRESHES			(0x0003u)
	#define EMIF_SDTIM2_EXTRA_REFRESHES_DEFAULT		EMIF_SDTIM2_EXTRA_REFRESHES_1REFRESH

	#define EMIF_SDTIM2_COUNTER_OF(x)			             ((Uint16)(x))

#define EMIF_SDTIM2_RMK(extra_refreshes,counter)\
 ((Uint16) ( \
  ( EMIF_FMK(SDTIM2,EXTRA_REFRESHES,extra_refreshes))|\
  ( EMIF_FMK(SDTIM2,COUNTER,counter))\
)\
 )

#define EMIF_SDTIM2_RMKS(extra_refreshes_sym,counter_sym)\
 ((Uint16) ( \
  ( EMIF_FMKS(SDTIM2,EXTRA_REFRESHES,extra_refreshes_sym))|\
  ( EMIF_FMKS(SDTIM2,COUNTER,counter_sym))\
)\
 )

/*  Default SDTIM2 register value  */

#define EMIF_SDTIM2_DEFAULT           (0x05DCu)

/* ============================================================== */
 /* Make SDRFR2 register values based on symbolic constants  */

/*  SDRFR2 field values  */

	#define EMIF_SDRFR2_EXTRA_REFRESHES_1REFRESH			(000000u)
	#define EMIF_SDRFR2_EXTRA_REFRESHES_2REFRESHES			(0x0001u)
	#define EMIF_SDRFR2_EXTRA_REFRESHES_3REFRESHES			(0x0002u)
	#define EMIF_SDRFR2_EXTRA_REFRESHES_4REFRESHES			(0x0003u)
	#define EMIF_SDRFR2_EXTRA_REFRESHES_DEFAULT		EMIF_SDRFR2_EXTRA_REFRESHES_1REFRESH

	#define EMIF_SDRFR2_COUNTER_OF(x)			             ((Uint16)(x))

#define EMIF_SDRFR2_RMK(extra_refreshes,counter)\
 ((Uint16) ( \
  ( EMIF_FMK(SDRFR2,EXTRA_REFRESHES,extra_refreshes))|\
  ( EMIF_FMK(SDRFR2,COUNTER,counter))\
)\
 )

#define EMIF_SDRFR2_RMKS(extra_refreshes_sym,counter_sym)\
 ((Uint16) ( \
  ( EMIF_FMKS(SDRFR2,EXTRA_REFRESHES,extra_refreshes_sym))|\
  ( EMIF_FMKS(SDRFR2,COUNTER,counter_sym))\
)\
 )

/*  Default SDRFR2 register value  */
#define EMIF_SDRFR2_DEFAULT           (0x05DCu)

/* ============================================================== */
 /* Make CESCR register values based on symbolic constants       */

#define EMIF_CESCR_RMK(ces)\
  ((Uint16)EMIF_FMK(CESCR,CES,ces))

#define EMIF_CESCR_RMKS(ces)\
  ((Uint16)EMIF_FMKS(CESCR,CES,ces))

#define EMIF_CESCR_DEFAULT						(0x0000u)

/*************************************************\
 EMIF global typedef declarations 
\*************************************************/

typedef struct {
	Uint16 gblctl1;
	Uint16 gblctl2;
	Uint16 ce1ctl1;
	Uint16 ce1ctl2;
	Uint16 ce0ctl1;
	Uint16 ce0ctl2;
	Uint16 ce2ctl1;
	Uint16 ce2ctl2;
	Uint16 ce3ctl1;
	Uint16 ce3ctl2;
	Uint16 sdctl1;
	Uint16 sdctl2;
	Uint16 sdrfr1;
	Uint16 sdrfr2;
	Uint16 sdext1;
	Uint16 sdext2;
	Uint16 ce1sec1;
	Uint16 ce0sec1;
	Uint16 ce2sec1;
	Uint16 ce3sec1;
      Uint16 cescr;
} EMIF_Config;


/*************************************************\
* EMIF global variable declarations
\*************************************************/


/*************************************************\
* EMIF global function declarations
\*************************************************/



CSLAPI void EMIF_config(EMIF_Config *myConfig);
CSLAPI void EMIF_configArgs(Uint16 gblctl1,Uint16 gblctl2,Uint16 ce1ctl1,Uint16 ce1ctl2,Uint16 ce0ctl1,
                            Uint16 ce0ctl2,Uint16 ce2ctl1,Uint16 ce2ctl2,Uint16 ce3ctl1,Uint16 ce3ctl2,
                            Uint16 sdctl1,Uint16 sdctl2,Uint16 sdrfr1,Uint16 sdrfr2,Uint16 sdext1,Uint16 sdext2,
                            Uint16 ce1sec1,Uint16 ce0sec1,Uint16 ce2sec1,Uint16 ce3sec1, Uint16 cescr);
CSLAPI void EMIF_getConfig(EMIF_Config *myConfig);

/*************************************************\
* EMIF inline function declarations
\*************************************************/


#ifdef USEDEFS


/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/

#endif /*USEDEFS */

#elif (!(_EMIF_MOD))
	#error EMIF Hal Module Not Supported on Specified Target
#endif  /* _EMIF_SUPPORT  */

#endif  /* _CSL_EMIFHAL_H  */

/******************************************************************************\
*     
*      End of csl_emif.h 
*
\******************************************************************************/
