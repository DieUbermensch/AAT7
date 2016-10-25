/****************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... I2C
* FILENAME...... csl_i2c.h
* DATE CREATED.. Thu Aug 16 10:16:34 2001
* PROJECT....... Chip Support Library
* COMPONENT..... Service Layer
* PREREQUISITS..
*------------------------------------------------------------------------------
*
* HISTORY:
*	 Created:		Thu Aug 16 10:16:34 2001 (Automatic generation)
*	 Modified: 04/04/2002 Changed name of I2C_init ==> I2C_setup
*        Modified: 03/18/2003 Added I2C_Init structure def for backward
*                              compatability to I2C_init function definition
*        Modified: 07/03/2003  Added CSLAPI  scope and inline control macro for
*                               I2C functions to avoid compiler errors with C++
*------------------------------------------------------------------------------
* DESCRIPTION: CSL Service Layer interface for the I2C module
*
\*************************************************************************/

#ifndef _CSL_I2C_H_
#define _CSL_I2C_H_

#include <csl_chiphal.h>


#if (_I2C_SUPPORT)

#include <_csl.h>
#include <csl_i2chal.h>
#include <csl_i2cdat.h>
/*----------------------------------------------------------------*\
*	 I2C scope and inline control macros
\*----------------------------------------------------------------*/

#ifdef __cplusplus
#define CSLAPI extern "C"
#else
#define CSLAPI extern
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _I2C_MOD_
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
* I2C global macro declarations
\****************************************/

/* error codes */
#define I2C_ERR_MAJOR		   (ERR_BASE_I2C) 
#define I2C_ERR_ALLOC		   (0x00000000) 
#define I2C_ERR_INVALID_HANDLE  (0x00000001)

#define IRQ_EVT_IIC		  IRQ_EVT_I2C


/******************************************\
* I2C Symbolic Register Field Values
\******************************************/
/*  I2COAR field values  */

#define I2C_I2COAR_OAR_OF(x)         ((Uint16)(x))

/*  I2CIER field values  */

	#define I2C_I2CIER_ICXRDY_DISABLE			(000000u)
	#define I2C_I2CIER_ICXRDY_ENABLE			(0x0001u)
	#define I2C_I2CIER_ICXRDY_DEFAULT		I2C_I2CIER_ICXRDY_DISABLE

	#define I2C_I2CIER_ICRRDY_DISABLE			(000000u)
	#define I2C_I2CIER_ICRRDY_ENABLE			(0x0001u)
	#define I2C_I2CIER_ICRRDY_DEFAULT		I2C_I2CIER_ICRRDY_DISABLE

	#define I2C_I2CIER_ARDY_DISABLE			(000000u)
	#define I2C_I2CIER_ARDY_ENABLE			(0x0001u)
	#define I2C_I2CIER_ARDY_DEFAULT		I2C_I2CIER_ARDY_DISABLE

	#define I2C_I2CIER_NACK_DISABLE			(000000u)
	#define I2C_I2CIER_NACK_ENABLE			(0x0001u)
	#define I2C_I2CIER_NACK_DEFAULT		I2C_I2CIER_NACK_DISABLE

	#define I2C_I2CIER_AL_DISABLE			(000000u)
	#define I2C_I2CIER_AL_ENABLE			(0x0001u)
	#define I2C_I2CIER_AL_DEFAULT		I2C_I2CIER_AL_DISABLE

/*  I2CSTR field values  */

	#define I2C_I2CSTR_BB_FREE			(000000u)
	#define I2C_I2CSTR_BB_BUSY			(0x0001u)
	#define I2C_I2CSTR_BB_DEFAULT		I2C_I2CSTR_BB_FREE

	#define I2C_I2CSTR_RSFULL_FALSE			(000000u)
	#define I2C_I2CSTR_RSFULL_TRUE			(0x0001u)
	#define I2C_I2CSTR_RSFULL_DEFAULT		I2C_I2CSTR_RSFULL_FALSE

	#define I2C_I2CSTR_XSMT_FALSE			(0x0001u)
	#define I2C_I2CSTR_XSMT_TRUE			(000000u)
	#define I2C_I2CSTR_XSMT_DEFAULT		I2C_I2CSTR_XSMT_FALSE

	#define I2C_I2CSTR_AAS_OFF			(000000u)
	#define I2C_I2CSTR_AAS_ON			(0x0001u)
	#define I2C_I2CSTR_AAS_DEFAULT		I2C_I2CSTR_AAS_OFF

	#define I2C_I2CSTR_AD0_OFF			(000000u)
	#define I2C_I2CSTR_AD0_ON			(0x0001u)
	#define I2C_I2CSTR_AD0_DEFAULT		I2C_I2CSTR_AD0_OFF

	#define I2C_I2CSTR_XRDY_OFF			(000000u)
	#define I2C_I2CSTR_XRDY_ON			(0x0001u)
	#define I2C_I2CSTR_XRDY_DEFAULT		I2C_I2CSTR_XRDY_OFF

	#define I2C_I2CSTR_RRDY_OFF			(000000u)
	#define I2C_I2CSTR_RRDY_ON			(0x0001u)
	#define I2C_I2CSTR_RRDY_DEFAULT		I2C_I2CSTR_RRDY_OFF

	#define I2C_I2CSTR_ARDY_NORDY			(000000u)
	#define I2C_I2CSTR_ARDY_RDY			(0x0001u)
	#define I2C_I2CSTR_ARDY_DEFAULT		I2C_I2CSTR_ARDY_NORDY

	#define I2C_I2CSTR_NACK_FALSE			(000000u)
	#define I2C_I2CSTR_NACK_TRUE			(0x0001u)
	#define I2C_I2CSTR_NACK_DEFAULT		I2C_I2CSTR_NACK_FALSE

	#define I2C_I2CSTR_AL_OFF			(000000u)
	#define I2C_I2CSTR_AL_ON			(0x0001u)
	#define I2C_I2CSTR_AL_DEFAULT		I2C_I2CSTR_AL_OFF

/*  I2CCLKL field values  */

#define I2C_I2CCLKL_ICCL_OF(x)         ((Uint16)(x))

/*  I2CCLKH field values  */

#define I2C_I2CCLKH_ICCH_OF(x)         ((Uint16)(x))

/*  I2CCNT field values  */

#define I2C_I2CCNT_ICDC_OF(x)         ((Uint16)(x))

/*  I2CSAR field values  */

#define I2C_I2CSAR_SAR_OF(x)         ((Uint16)(x))

/*  I2CMDR field values  */

	#define I2C_I2CMDR_FREE_OFF			(000000u)
	#define I2C_I2CMDR_FREE_ON			(0x0001u)
	#define I2C_I2CMDR_FREE_DEFAULT		I2C_I2CMDR_FREE_OFF

	#define I2C_I2CMDR_STT_OFF			(000000u)
	#define I2C_I2CMDR_STT_ON			(0x0001u)
	#define I2C_I2CMDR_STT_DEFAULT		I2C_I2CMDR_STT_OFF

	#define I2C_I2CMDR_IDLEEN_NOIDLE			(000000u)
	#define I2C_I2CMDR_IDLEEN_IDLE			(0x0001u)
	#define I2C_I2CMDR_IDLEEN_DEFAULT		I2C_I2CMDR_IDLEEN_NOIDLE

	#define I2C_I2CMDR_STP_OFF			(000000u)
	#define I2C_I2CMDR_STP_ON			(0x0001u)
	#define I2C_I2CMDR_STP_DEFAULT		I2C_I2CMDR_STP_OFF

	#define I2C_I2CMDR_MST_OFF			(000000u)
	#define I2C_I2CMDR_MST_ON			(0x0001u)
	#define I2C_I2CMDR_MST_DEFAULT		I2C_I2CMDR_MST_ON

	#define I2C_I2CMDR_TRX_RECEIVE			(000000u)
	#define I2C_I2CMDR_TRX_TRANSMIT			(0x0001u)
	#define I2C_I2CMDR_TRX_DEFAULT		I2C_I2CMDR_TRX_TRANSMIT

	#define I2C_I2CMDR_XA_7BIT			(000000u)
	#define I2C_I2CMDR_XA_10BIT			(0x0001u)
	#define I2C_I2CMDR_XA_DEFAULT		I2C_I2CMDR_XA_7BIT

	#define I2C_I2CMDR_RM_OFF			(000000u)
	#define I2C_I2CMDR_RM_ON			(0x0001u)
	#define I2C_I2CMDR_RM_DEFAULT		I2C_I2CMDR_RM_OFF

	#define I2C_I2CMDR_DLB_DISABLE			(000000u)
	#define I2C_I2CMDR_DLB_ENABLE			(0x0001u)
	#define I2C_I2CMDR_DLB_DEFAULT		I2C_I2CMDR_DLB_DISABLE

	#define I2C_I2CMDR_IRS_RESET			(000000u)
	#define I2C_I2CMDR_IRS_ENABLE			(0x0001u)
	#define I2C_I2CMDR_IRS_DEFAULT		I2C_I2CMDR_IRS_ENABLE

	#define I2C_I2CMDR_STB_OFF			(000000u)
	#define I2C_I2CMDR_STB_ON			(0x0001u)
	#define I2C_I2CMDR_STB_DEFAULT		I2C_I2CMDR_STB_OFF

	#define I2C_I2CMDR_FDF_OFF			(000000u)
	#define I2C_I2CMDR_FDF_ON			(0x0001u)
	#define I2C_I2CMDR_FDF_DEFAULT		I2C_I2CMDR_FDF_OFF

	#define I2C_I2CMDR_BC_OF(x)         ((Uint16)(x))

/*  I2CISRC field values  */

	#define I2C_I2CISRC_INTCODE_NONE			(000000u)
	#define I2C_I2CISRC_INTCODE_AL			(0x0001u)
	#define I2C_I2CISRC_INTCODE_NACK			(0x0002u)
	#define I2C_I2CISRC_INTCODE_ARDY			(0x0003u)
	#define I2C_I2CISRC_INTCODE_RRDY			(0x0004u)
	#define I2C_I2CISRC_INTCODE_XRDY			(0x0005u)
	#define I2C_I2CISRC_INTCODE_DEFAULT		I2C_I2CISRC_INTCODE_NONE

/*  I2CPSC field values  */

#define I2C_I2CPSC_IPSC_OF(x)         ((Uint16)(x))

/* ============================================================== */
 /* Make I2CCLKH register values based on symbolic constants  */

#define I2C_I2CCLKH_RMK(icch)\
 ((Uint16) ( \
  ( I2C_FMK(I2CCLKH,ICCH,icch))\
)\
 )

#define I2C_I2CCLKH_RMKS(icch_sym)\
 ((Uint16) ( \
  ( I2C_FMKS(I2CCLKH,ICCH,icch_sym))\
)\
 )

/*  Default I2CCLKH register value  */

/*  I2CCLKH field values  */


/* ============================================================== */
 /* Make I2CCLKL register values based on symbolic constants  */

#define I2C_I2CCLKL_RMK(iccl)\
 ((Uint16) ( \
  ( I2C_FMK(I2CCLKL,ICCL,iccl))\
)\
 )

#define I2C_I2CCLKL_RMKS(iccl_sym)\
 ((Uint16) ( \
  ( I2C_FMKS(I2CCLKL,ICCL,iccl_sym))\
)\
 )

/*  Default I2CCLKL register value  */

/*  I2CCLKL field values  */


/* ============================================================== */
 /* Make I2CCNT register values based on symbolic constants  */

#define I2C_I2CCNT_RMK(icdc)\
 ((Uint16) ( \
  ( I2C_FMK(I2CCNT,ICDC,icdc))\
)\
 )

#define I2C_I2CCNT_RMKS(icdc_sym)\
 ((Uint16) ( \
  ( I2C_FMKS(I2CCNT,ICDC,icdc_sym))\
)\
 )

/*  Default I2CCNT register value  */

/*  I2CCNT field values  */


/* ============================================================== */
 /* Make I2CDRR register values based on symbolic constants  */

/*  Default I2CDRR register value  */

/*  I2CDRR field values  */


/* ============================================================== */
 /* Make I2CDXR register values based on symbolic constants  */

/*  Default I2CDXR register value  */

/*  I2CDXR field values  */


/* ============================================================== */
 /* Make I2CIER register values based on symbolic constants  */

#define I2C_I2CIER_RMK(xrdy,rrdy,ardy,nack,al)\
 ((Uint16) ( \
  ( I2C_FMK(I2CIER,XRDY,xrdy))|\
  ( I2C_FMK(I2CIER,RRDY,rrdy))|\
  ( I2C_FMK(I2CIER,ARDY,ardy))|\
  ( I2C_FMK(I2CIER,NACK,nack))|\
  ( I2C_FMK(I2CIER,AL,al))\
)\
 )

#define I2C_I2CIER_RMKS(xrdy_sym,rrdy_sym,ardy_sym,nack_sym,al_sym)\
 ((Uint16) ( \
  ( I2C_FMKS(I2CIER,XRDY,xrdy_sym))|\
  ( I2C_FMKS(I2CIER,RRDY,rrdy_sym))|\
  ( I2C_FMKS(I2CIER,ARDY,ardy_sym))|\
  ( I2C_FMKS(I2CIER,NACK,nack_sym))|\
  ( I2C_FMKS(I2CIER,AL,al_sym))\
)\
 )

/*  Default I2CIER register value  */

/*  I2CIER field values  */


/* ============================================================== */
 /* Make I2CISRC register values based on symbolic constants  */

#define I2C_I2CISRC_RMK(testmd)\
 ((Uint16) ( \
  ( I2C_FMK(I2CISRC,TESTMD,testmd))\
)\
 )

#define I2C_I2CISRC_RMKS(testmd_sym)\
 ((Uint16) ( \
  ( I2C_FMKS(I2CISRC,TESTMD,testmd_sym))\
)\
 )

/*  Default I2CISRC register value  */

/*  I2CISRC field values  */


/* ============================================================== */
 /* Make I2CMDR register values based on symbolic constants  */

#define I2C_I2CMDR_RMK(free,stt,idleen,stp,mst,trx,xa,rm,dlb,irs,stb,fdf,bc)\
 ((Uint16) ( \
  ( I2C_FMK(I2CMDR,FREE,free))|\
  ( I2C_FMK(I2CMDR,STT,stt))|\
  ( I2C_FMK(I2CMDR,IDLEEN,idleen))|\
  ( I2C_FMK(I2CMDR,STP,stp))|\
  ( I2C_FMK(I2CMDR,MST,mst))|\
  ( I2C_FMK(I2CMDR,TRX,trx))|\
  ( I2C_FMK(I2CMDR,XA,xa))|\
  ( I2C_FMK(I2CMDR,RM,rm))|\
  ( I2C_FMK(I2CMDR,DLB,dlb))|\
  ( I2C_FMK(I2CMDR,IRS,irs))|\
  ( I2C_FMK(I2CMDR,STB,stb))|\
  ( I2C_FMK(I2CMDR,FDF,fdf))|\
  ( I2C_FMK(I2CMDR,BC,bc))\
)\
 )

#define I2C_I2CMDR_RMKS(free_sym,stt_sym,idleen_sym,stp_sym,mst_sym,trx_sym,xa_sym,rm_sym,dlb_sym,irs_sym,stb_sym,fdf_sym,bc_sym)\
 ((Uint16) ( \
  ( I2C_FMKS(I2CMDR,FREE,free_sym))|\
  ( I2C_FMKS(I2CMDR,STT,stt_sym))|\
  ( I2C_FMKS(I2CMDR,IDLEEN,idleen_sym))|\
  ( I2C_FMKS(I2CMDR,STP,stp_sym))|\
  ( I2C_FMKS(I2CMDR,MST,mst_sym))|\
  ( I2C_FMKS(I2CMDR,TRX,trx_sym))|\
  ( I2C_FMKS(I2CMDR,XA,xa_sym))|\
  ( I2C_FMKS(I2CMDR,RM,rm_sym))|\
  ( I2C_FMKS(I2CMDR,DLB,dlb_sym))|\
  ( I2C_FMKS(I2CMDR,IRS,irs_sym))|\
  ( I2C_FMKS(I2CMDR,STB,stb_sym))|\
  ( I2C_FMKS(I2CMDR,FDF,fdf_sym))|\
  ( I2C_FMKS(I2CMDR,BC,bc_sym))\
)\
 )

/*  Default I2CMDR register value  */

/*  I2CMDR field values  */
/* Reset, rfull, rrdy, xempty, xrdy, read, sendStop, and start macro definitions */

#define I2C_reset() I2C_FSET(I2CMDR,IRS,0)

#define I2C_rfull() I2C_FGET(I2CSTR,RSFULL)

#define I2C_rrdy() I2C_FGET(I2CSTR,RRDY)

#define I2C_xempty() I2C_FGET(I2CSTR,XSMT)

#define I2C_xrdy() I2C_FGET(I2CSTR,XRDY)

#define I2C_writeByte(n) I2C_RSET(I2CDXR,n)

#define I2C_readByte() I2C_RGET(I2CDRR)

#define I2C_sendStop() I2C_FSET(I2CMDR,STP,1)

#define I2C_start() I2C_FSET(I2CMDR,STT,1)

/* ============================================================== */
 /* Make I2COAR register values based on symbolic constants  */

#define I2C_I2COAR_RMK(oar)\
 ((Uint16) ( \
  ( I2C_FMK(I2COAR,OAR,oar))\
)\
 )

#define I2C_I2COAR_RMKS(oar_sym)\
 ((Uint16) ( \
  ( I2C_FMKS(I2COAR,OAR,oar_sym))\
)\
 )

/*  Default I2COAR register value  */

/*  I2COAR field values  */


/* ============================================================== */
 /* Make I2CPSC register values based on symbolic constants  */

#define I2C_I2CPSC_RMK(ipsc)\
 ((Uint16) ( \
  ( I2C_FMK(I2CPSC,IPSC,ipsc))\
)\
 )

#define I2C_I2CPSC_RMKS(ipsc_sym)\
 ((Uint16) ( \
  ( I2C_FMKS(I2CPSC,IPSC,ipsc_sym))\
)\
 )

/*  Default I2CPSC register value  */

/*  I2CPSC field values  */


/* ============================================================== */
 /* Make I2CSAR register values based on symbolic constants  */

#define I2C_I2CSAR_RMK(sar)\
 ((Uint16) ( \
  ( I2C_FMK(I2CSAR,SAR,sar))\
)\
 )

#define I2C_I2CSAR_RMKS(sar_sym)\
 ((Uint16) ( \
  ( I2C_FMKS(I2CSAR,SAR,sar_sym))\
)\
 )

/*  Default I2CSAR register value  */

/*  I2CSAR field values  */


/* ============================================================== */
 /* Make I2CSTR register values based on symbolic constants  */

#define I2C_I2CSTR_RMK(rrdy)\
 ((Uint16) ( \
  ( I2C_FMK(I2CSTR,RRDY,rrdy))\
)\
 )

#define I2C_I2CSTR_RMKS(rrdy_sym)\
 ((Uint16) ( \
  ( I2C_FMKS(I2CSTR,RRDY,rrdy_sym))\
)\
 )

/*  Default I2CSTR register value  */

/*  I2CSTR field values  */

/*************************************************\
 I2C global typedef declarations 
\*************************************************/

typedef struct {
	Uint16 i2coar;
	Uint16 i2cier;
	Uint16 i2cstr;
	Uint16 i2cclkl;
	Uint16 i2cclkh;
	Uint16 i2ccnt;
	Uint16 i2csar;
	Uint16 i2cmdr;
	Uint16 i2cisrc;
	Uint16 i2cpsc;
} I2C_Config;

typedef struct {
	
	Uint16 addrmode;        /* 7 or 10 bit address mode */
	Uint16 ownaddr;         /* don't care if master */
	Uint16 sysinclock;      /* clkout value (Mhz)  */
	Uint16 rate;            /* a number between 10 and 400*/
	Uint16 bitbyte;         /* number of bits/byte to be received or transmitted */
	Uint16 dlb;             /* data loopback mode */
	Uint16 free;	/* free mode */
	
} I2C_Setup;

typedef struct {
	
	Uint16 addrmode;        /* 7 or 10 bit address mode */
	Uint16 ownaddr;         /* don't care if master */
	Uint16 sysinclock;      /* clkout value (Mhz)  */
	Uint16 rate;            /* a number between 10 and 400*/
	Uint16 bitbyte;         /* number of bits/byte to be received or transmitted */
	Uint16 dlb;             /* data loopback mode */
	Uint16 free;	/* free mode */
	
} I2C_Init;

typedef struct
{
   void (*alAddr)(void);          // Arbitration status
   void (*nackAddr)(void);         // No acknowledgement 
   void (*ardyAddr)(void);         // register access ready
   void (*rrdyAddr)(void);         // receive data ready
   void (*xrdyAddr)(void);         // transmit data ready
} I2C_IsrAddr;

#define    I2C_EVT_AL     0x01     // Arbitration win/lose
#define    I2C_EVT_NACK   0x02     // No acknowledgement 
#define    I2C_EVT_ARDY   0x04     // register access ready
#define    I2C_EVT_RRDY   0x08     // receive data ready
#define    I2C_EVT_XRDY   0x10     // transmit data ready


/*************************************************\
* I2C global variable declarations
\*************************************************/

/*************************************************\
* I2C global function declarations
\*************************************************/




IDECL void I2C_config(I2C_Config *myConfig);
IDECL void I2C_configArgs(Uint16 i2coar,Uint16 i2cier,Uint16 i2cstr,Uint16 i2cclkl,Uint16 i2cclkh,Uint16 i2ccnt,Uint16 i2csar,Uint16 i2cmdr,Uint16 i2cisrc,Uint16 i2cpsc);
IDECL void I2C_getConfig(I2C_Config *myConfig);
CSLAPI void I2C_setup(I2C_Setup *Init);
CSLAPI int I2C_write(Uint16 *data,int length,int master,Uint16 slaveaddress,int transfermode,int timeout);
CSLAPI int I2C_read(Uint16 *data,int length,int master,Uint16 slaveaddress,int transfermode,int timeout,int checkbus);
CSLAPI void I2C_eventEnable(Uint16 isrmask);
CSLAPI void I2C_eventDisable(Uint16 ierMask);
CSLAPI void I2C_setCallback(I2C_IsrAddr *isrAddr);
interrupt void I2C_intrDispatch(void);
CSLAPI int I2C_getEventId(void);
/*************************************************\
* I2C inline function declarations
\*************************************************/


#ifdef USEDEFS



/*----------------------------------------------------------------------------*/

IDEF void I2C_config(I2C_Config *Config) {

  int old_intm;

  old_intm = IRQ_globalDisable();  
  I2C_RSET(I2COAR,Config->i2coar);
  I2C_RSET(I2CIER,Config->i2cier);
  I2C_RSET(I2CPSC,Config->i2cpsc);	
  I2C_RSET(I2CCLKL,Config->i2cclkl);
  I2C_RSET(I2CCLKH,Config->i2cclkh);
  I2C_RSET(I2CCNT,Config->i2ccnt);
  I2C_RSET(I2CSAR,Config->i2csar);				 
  I2C_RSET(I2CMDR,Config->i2cmdr);
  I2C_RSET(I2CSTR,Config->i2cstr);
  I2C_RSET(I2CISRC,Config->i2cisrc);
  IRQ_globalRestore(old_intm);   



}

IDEF void I2C_getConfig(I2C_Config *Config) {

  int old_intm;

  old_intm = IRQ_globalDisable();
  Config->i2coar = I2C_RGET(I2COAR);
  Config->i2cier = I2C_RGET(I2CIER);
  Config->i2cpsc = I2C_RGET(I2CPSC);
  Config->i2cclkl = I2C_RGET(I2CCLKL);
  Config->i2cclkh = I2C_RGET(I2CCLKH);
  Config->i2ccnt = I2C_RGET(I2CCNT);
  Config->i2csar = I2C_RGET(I2CSAR);
  Config->i2cmdr = I2C_RGET(I2CMDR);
  Config->i2cstr = I2C_RGET(I2CSTR);
  Config->i2cisrc = I2C_RGET(I2CISRC);
  IRQ_globalRestore(old_intm);   



}


IDEF void I2C_configArgs(Uint16 i2coar,Uint16 i2cier,Uint16 i2cstr,Uint16 i2cclkl,Uint16 i2cclkh,Uint16 i2ccnt,Uint16 i2csar,Uint16 i2cmdr,Uint16 i2cisrc,Uint16 i2cpsc) {

  int old_intm;

  old_intm = IRQ_globalDisable();  
  I2C_RSET(I2COAR,i2coar);
  I2C_RSET(I2CIER,i2cier);
  I2C_RSET(I2CPSC,i2cpsc);	
  I2C_RSET(I2CCLKL,i2cclkl);
  I2C_RSET(I2CCLKH,i2cclkh);
  I2C_RSET(I2CCNT,i2ccnt);
  I2C_RSET(I2CSAR,i2csar);				 
  I2C_RSET(I2CMDR,i2cmdr);
  I2C_RSET(I2CSTR,i2cstr);
  I2C_RSET(I2CISRC,i2cisrc);
  IRQ_globalRestore(old_intm);   

}


/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/

#endif /*USEDEFS */

#else
   #ifndef _I2C_MOD_
	#error I2C Hal Module Not Supported on Specified Target
   #endif
#endif  /* _I2C_SUPPORT  */

#endif  /* _CSL_I2CHAL_H  */

/******************************************************************************\
*     
*      End of csl_i2c.h 
*
\******************************************************************************/
