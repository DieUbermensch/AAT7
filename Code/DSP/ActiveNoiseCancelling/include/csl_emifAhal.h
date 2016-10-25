/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... EMI
* FILENAME...... csl_emifhal.h
* DATE CREATED.. Wed 05/24/2000 
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS.. stdinc.h, chip.h
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:  05/24/2000 created
*   MODIFIED: 04/16/2001 modifed FILENAME and other header comments
*   MODIFIED: 01/24/2002 fixed bug in EMIF_FSETS macro definition 
*   MODIFIED: 11/23/2002 added status bits to EMIF BUS Error Register (5509A) 
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the TIMER module)
*
* Registers Covered:
*   (RW) _EMIF_EGCR  -  Global Control Register
*   (W)  _EMIF_EMIRST  -  Global Reset Register
*   (R)  _EMIF_EMIBE  -  Bus Error Status Register
*   (RW) _EMIF_CE01 -  CE0 Space Control Register 1
*   (RW) _EMIF_CE02 -  CE0 Space Control Register 2
*   (RW) _EMIF_CE03 -  CE0 Space Control Register 3
*   (RW) _EMIF_CE11 -  CE1 Space Control Register 1
*   (RW) _EMIF_CE12 -  CE1 Space Control Register 2
*   (RW) _EMIF_CE13 -  CE1 Space Control Register 3
*   (RW) _EMIF_CE21 -  CE2 Space Control Register 1
*   (RW) _EMIF_CE22 -  CE2 Space Control Register 2
*   (RW) _EMIF_CE23 -  CE2 Space Control Register 3
*   (RW) _EMIF_CE31 -  CE3 Space Control Register 1
*   (RW) _EMIF_CE32 -  CE3 Space Control Register 2
*   (RW) _EMIF_CE33 -  CE3 Space Control Register 2
*   (RW) _EMIF_SDC1 - SDRAM Control Register 1
*   (R)  _EMIF_SDPER	- SDRAM Period Register
*   (R)  _EMIF_SDCNT - SDRAM Counter Register
*   (R)  _EMIF_INIT  - SDRAM Initialization Register
*   (RW) _EMIF_SDC2 - SDRAM Control Register 2
\******************************************************************************/
#ifndef _EMIFAHAL_H_
#define _EMIFAHAL_H_

#include <csl_std.h>
#include <csl_chiphal.h>

#if (_EMIFA_SUPPORT)

/*============================================================================*\
* misc declarations
\*============================================================================*/

#define _EMIF_DEVICE_CNT			(2)


/*============================================================================*\
* EMIF generic register and field  access macros
\*============================================================================*/

#define EMIF_ADDR(Reg)                _EMIF_##Reg##_ADDR
#define EMIF_RGET(Reg)                _PREG_GET(EMIF_ADDR(##Reg))
#define EMIF_RSET(Reg,Val)            _PREG_SET(EMIF_ADDR(##Reg),Val)
#define EMIF_RAOI(Reg,AND,OR,INV)     _PREG_AOI(EMIF_ADDR(##Reg),AND,OR,INV)
#define EMIF_FGET(Reg,Field)          _PFIELD_GET(EMIF_ADDR(##Reg), _EMIF_##Reg##_##Field)
#define EMIF_FSET(Reg,Field,Val)      _PFIELD_SET(EMIF_ADDR(##Reg), _EMIF_##Reg##_##Field,Val)
#define EMIF_FSETS(Reg,Field,Sym)     EMIF_FSET(##Reg,##Field,EMIF_##Reg##_##Field##_##Sym)
#define EMIF_FMK(Reg,Field,Val)       _EMIF_##Reg##_##Field##_MK(Val)
#define EMIF_FMKS(Reg,Field,Sym)      EMIF_FMK(##Reg,##Field,EMIF_##Reg##_##Field##_##Sym)
#define EMIF_FAOI(Reg,Field,AND,OR,INV)\
  _PFIELD_AOI(EMIF_ADDR(##Reg),_EMIF_##Reg##_##Field,AND,OR,INV)

/*============================================================================*\
* _EMIF_EGCR:  Global Control Register
\*============================================================================*/
#define _EMIF_EGCR_ADDR				(0x0800u)
#define _EMIF_EGCR                       	PREG16(_EMIF_EGCR_ADDR)
#define _EGCR                           	_EMIF_EGCR

/*============================================================================*\
* _EMIF_EGCR_GET and _EMIF_EGCR_SET
\*============================================================================*/
#define _EMIF_EGCR_GET(RegAddr)		_PREG_GET(RegAddr)
#define _EMIF_EGCR_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/*============================================================================*\
* _EMIF_EMIRST:  Global Reset Register
\*============================================================================*/
#define _EMIF_EMIRST_ADDR			(0x0801u)
#define _EMIF_EMIRST                     	PREG16(_EMIF_EMIRST_ADDR)
#define _EMIRST                          	_EMIF_EMIRST

/*============================================================================*\
* _EMIF_EMIRST_GET 
\*============================================================================*/

#define _EMIF_EMIRST_SET(RegAddr,Val)		_PREG_SET(RegAddr,Val)

/*============================================================================*\
* _EMIF_EMIBE:  Bus Error Status Register
\*============================================================================*/
#define _EMIF_EMIBE_ADDR				(0x0802u)
#define _EMIF_EMIBE                       	PREG16(_EMIF_EMIBE_ADDR)
#define _EMIBE                              	_EMIF_EMIBE

/*============================================================================*\
* _EMIF_EMIBE_GET 
\*============================================================================*/
#define _EMIF_EMIBE_GET(RegAddr)		_PREG_GET(RegAddr)

/*============================================================================*\
* _EMIF_CE01:  CE0 Space Control Register 1
\*============================================================================*/
#define _EMIF_CE01_ADDR				(0x0803u)
#define _EMIF_CE01                       	PREG16(_EMIF_CE01_ADDR)
#define _CE01                              _EMIF_CE01

/*============================================================================*\
* _EMIF_CE02:  CE0 Space Control Register 2
\*============================================================================*/
#define _EMIF_CE02_ADDR				(0x0804u)
#define _EMIF_CE02                       	PREG16(_EMIF_CE02_ADDR)
#define _CE02                              _EMIF_CE02

/*============================================================================*\
* _EMIF_CE03:  CE0 Space Control Register 3
\*============================================================================*/
#define _EMIF_CE03_ADDR				(0x0805u)
#define _EMIF_CE03                       	PREG16(_EMIF_CE03_ADDR)
#define _CE03                              _EMIF_CE03

/*============================================================================*\
* _EMIF_CE11:  CE1 Space Control Register 1
\*============================================================================*/
#define _EMIF_CE11_ADDR				(0x0806u)
#define _EMIF_CE11                       	PREG16(_EMIF_CE11_ADDR)
#define _CE11                              _EMIF_CE11

/*============================================================================*\
* _EMIF_CE12:  CE1 Space Control Register 2
\*============================================================================*/
#define _EMIF_CE12_ADDR				(0x0807u)
#define _EMIF_CE12                       	PREG16(_EMIF_CE12_ADDR)
#define _CE12                              _EMIF_CE12

/*============================================================================*\
* _EMIF_CE13:  CE1 Space Control Register 3
\*============================================================================*/
#define _EMIF_CE13_ADDR				(0x0808u)
#define _EMIF_CE13                       	PREG16(_EMIF_CE13_ADDR)
#define _CE13                              _EMIF_CE13

/*============================================================================*\
* _EMIF_CE21:  CE2 Space Control Register 1
\*============================================================================*/
#define _EMIF_CE21_ADDR				(0x0809u)
#define _EMIF_CE21                       	PREG16(_EMIF_CE21_ADDR)
#define _CE21                              _EMIF_CE21

/*============================================================================*\
* _EMIF_CE22:  CE2 Space Control Register 2
\*============================================================================*/
#define _EMIF_CE22_ADDR				(0x080Au)
#define _EMIF_CE22                       	PREG16(_EMIF_CE22_ADDR)
#define _CE22                              _EMIF_CE22

/*============================================================================*\
* _EMIF_CE23:  CE2 Space Control Register 3
\*============================================================================*/
#define _EMIF_CE23_ADDR				(0x080Bu)
#define _EMIF_CE23                       	PREG16(_EMIF_CE23_ADDR)
#define _CE23                              _EMIF_CE23

/*============================================================================*\
* _EMIF_CE31:  CE3 Space Control Register 1
\*============================================================================*/
#define _EMIF_CE31_ADDR				(0x080Cu)
#define _EMIF_CE31                       	PREG16(_EMIF_CE31_ADDR)
#define _CE31                              _EMIF_CE31

/*============================================================================*\
* _EMIF_CE32:  CE3 Space Control Register 2
\*============================================================================*/
#define _EMIF_CE32_ADDR				(0x080Du)
#define _EMIF_CE32                       	PREG16(_EMIF_CE32_ADDR)
#define _CE32                              _EMIF_CE32

/*============================================================================*\
* _EMIF_CE33:  CE3 Space Control Register 3
\*============================================================================*/
#define _EMIF_CE33_ADDR				(0x080Eu)
#define _EMIF_CE33                       	PREG16(_EMIF_CE33_ADDR)
#define _CE33                              _EMIF_CE33

/*============================================================================*\
* _EMIF_SDC1:  SDRAM Control Register 1
\*============================================================================*/
#define _EMIF_SDC1_ADDR			(0x080Fu)
#define _EMIF_SDC1                    PREG16(_EMIF_SDC1_ADDR)
#define _SDC1	                        _EMIF_SDC1

/*============================================================================*\
* _EMIF_SDC1_GET and _EMIF_SDC1_SET
\*============================================================================*/
#define _EMIF_SDC1_GET(RegAddr)		_PREG_GET(RegAddr)
#define _EMIF_SDC1_SET(RegAddr,Val)	_PREG_SET(RegAddr,Val)


/*============================================================================*\
* _EMIF_SDPER:  SDRAM Period Register
\*============================================================================*/
#define _EMIF_SDPER_ADDR			(0x0810u)
#define _EMIF_SDPER                    	PREG16(_EMIF_SDPER_ADDR)
#define _SDPER	                        _EMIF_SDPER

/*============================================================================*\
* _EMIF_SDCNT:  SDRAM Counter Register
\*============================================================================*/
#define _EMIF_SDCNT_ADDR			(0x0811u)
#define _EMIF_SDCNT                    PREG16(_EMIF_SDCNT_ADDR)
#define _SDCNT	                        _EMIF_SDCNT


/*============================================================================*\
* _EMIF_INIT:  SDRAM Initialization Register
\*============================================================================*/
#define _EMIF_INIT_ADDR			     (0x0812u)
#define _EMIF_INIT                    	PREG16(_EMIF_INIT_ADDR)
#define _INIT	                        _EMIF_INIT

#define _EMIF_SDINIT_ADDR			(0x0812u)
#define _EMIF_SDINIT                    	PREG16(_EMIF_SDINIT_ADDR)
#define _SDINIT	                        _EMIF_SDINIT

/*============================================================================*\
* _EMIF_SDC2:  SDRAM Control Register 2
\*============================================================================*/
#define _EMIF_SDC2_ADDR			  (0x0813u)
#define _EMIF_SDC2                    PREG16(_EMIF_SDC2_ADDR)
#define _SDC2	                    _EMIF_SDC2

/*============================================================================*\
* _EMIF_IPMR:  Internal Power Management Register
\*============================================================================*/
#define _EMIF_IPMR_ADDR			  (0x0814u)
#define _EMIF_IPMR                    PREG16(_EMIF_IPMR_ADDR)
#define _IPMR	                    _EMIF_IPMR

/* \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ */
/* \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ */
/* \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ */
/* \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ */
/* \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ */
/* ============================================================================ *\
* _EMIF_EGCR	   - Global Control Register
*
* Fields:
*  (RW) _EMIF_EGCR_MEMFREQ	- Memory Clock Frequency field
*  (RW) _EMIF_EGCR_WPE		- Write Posting Enable field
*  (RW) _EMIF_EGCR_MEMCEN	- Mem Clock Enable field
*  (R)  _EMIF_EGCR_ARDY		- Value of ARDY input
*  (R)  _EMIF_EGCR_HOLD		- Value of /HOLD input
*  (R)  _EMIF_EGCR_HOLDA		- Value of /HOLDA output
*  (RW)  _EMIF_EGCR_NOHOLD	- External HOLD disable field
\*============================================================================*/

/*==========================================================================*\
* (RW) _EMIF_EGCR_MEMFREQ
\*--------------------------------------------------------------------------*/
#define _EMIF_EGCR_MEMFREQ_SHIFT		(0x0009u)
#define _EMIF_EGCR_MEMFREQ_MK(n)           (((Uint16)(n) & 0x0003u) << _EMIF_EGCR_MEMFREQ_SHIFT)
#define _EMIF_EGCR_MEMFREQ_MASK            (_EMIF_EGCR_MEMFREQ_MK(0x0003u))
#define _EMIF_EGCR_MEMFREQ_CLR             (~(_EMIF_EGCR_MEMFREQ_MK(0x0003u)))

/*==========================================================================*\
* (RW) _EMIF_EGCR_WPE
\*--------------------------------------------------------------------------*/
#define _EMIF_EGCR_WPE_SHIFT			(0x0007u)
#define _EMIF_EGCR_WPE_MK(n)           	(((Uint16)(n) & 0x0001u) << _EMIF_EGCR_WPE_SHIFT)
#define _EMIF_EGCR_WPE_MASK            	(_EMIF_EGCR_WPE_MK(0x0001u))
#define _EMIF_EGCR_WPE_CLR             	(~(_EMIF_EGCR_WPE_MK(0x0001u)))

/*==========================================================================*\
* (RW) _EMIF_EGCR_MEMCEN
\*--------------------------------------------------------------------------*/
#define _EMIF_EGCR_MEMCEN_SHIFT		(0x0005u)
#define _EMIF_EGCR_MEMCEN_MK(n)           (((Uint16)(n) & 0x0001u) << _EMIF_EGCR_MEMCEN_SHIFT)
#define _EMIF_EGCR_MEMCEN_MASK            (_EMIF_EGCR_MEMCEN_MK(0x0001u))
#define _EMIF_EGCR_MEMCEN_CLR             (~(_EMIF_EGCR_MEMCEN_MK(0x0001u)))

/*==========================================================================*\
* (R) _EMIF_EGCR_ARDY
\*--------------------------------------------------------------------------*/
#define _EMIF_EGCR_ARDY_SHIFT			(0x0003u)
#define _EMIF_EGCR_ARDY_MK(n)           	(((Uint16)(n) & 0x0001u) << _EMIF_EGCR_ARDY_SHIFT)
#define _EMIF_EGCR_ARDY_MASK            	(_EMIF_EGCR_ARDY_MK(0x0001u))
#define _EMIF_EGCR_ARDY_CLR               (~(_EMIF_EGCR_ARDY_MASK))

/*==========================================================================*\
* (R) _EMIF_EGCR_HOLD
\*--------------------------------------------------------------------------*/
#define _EMIF_EGCR_HOLD_SHIFT			(0x0002u)
#define _EMIF_EGCR_HOLD_MK(n)           	(((Uint16)(n) & 0x0001u) << _EMIF_EGCR_HOLD_SHIFT)
#define _EMIF_EGCR_HOLD_MASK            	(_EMIF_EGCR_HOLD_MK(0x0001u))
#define _EMIF_EGCR_HOLD_CLR               (~(_EMIF_EGCR_HOLD_MASK))

/*==========================================================================*\
* (R) _EMIF_EGCR_HOLDA
\*--------------------------------------------------------------------------*/
#define _EMIF_EGCR_HOLDA_SHIFT		(0x0001u)
#define _EMIF_EGCR_HOLDA_MK(n)           	(((Uint16)(n) & 0x0001u) << _EMIF_EGCR_HOLDA_SHIFT)
#define _EMIF_EGCR_HOLDA_MASK            	(_EMIF_EGCR_HOLDA_MK(0x0001u))
#define _EMIF_EGCR_HOLDA_CLR              (~(_EMIF_EGCR_HOLDA_MASK))

/*==========================================================================*\
* (RW) _EMIF_EGCR_NOHOLD
\*--------------------------------------------------------------------------*/
#define _EMIF_EGCR_NOHOLD_SHIFT		(0x0000u)
#define _EMIF_EGCR_NOHOLD_MK(n)           (((Uint16)(n) & 0x0001u) << _EMIF_EGCR_NOHOLD_SHIFT)
#define _EMIF_EGCR_NOHOLD_MASK            (_EMIF_EGCR_NOHOLD_MK(0x0001u))
#define _EMIF_EGCR_NOHOLD_CLR             (~(_EMIF_EGCR_NOHOLD_MK(0x0001u)))

/*==========================================================================*\
* _EMIF_EGCR	- Global Control Register Config
\*--------------------------------------------------------------------------*/
#define _EMIF_EGCR_CFG(memfreq,wpe,memcen,nohold) \
	_PREG_SET(_EMIF_EGCR_ADDR,\
    		(Uint16) (_EMIF_EGCR_MEMFREQ_MK(memfreq)|\
				_EMIF_EGCR_WPE_MK(wpe)|\
				_EMIF_EGCR_MEMCEN_MK(memcen)|\
				_EMIF_EGCR_NOHOLD_MK(nohold)\
             ))

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*============================================================================*\
* _EMIF_EMIRST		- Global Reset Register
*
* Fields:
*  (W) _EMIF_EMIRST_EMIRST
\*============================================================================*/
#define _EMIF_EMIRST_EMIRST_SHIFT			(0x0000u)
#define _EMIF_EMIRST_EMIRST_MK(n)           	(((Uint16)(n) & 0xFFFFu) << _EMIF_EMIRST_EMIRST_SHIFT)
#define _EMIF_EMIRST_EMIRST_MASK            	(_EMIF_EMIRST_EMIRST_MK(0xFFFFu))
#define _EMIF_EMIRST_EMIRST_CLR             	(~(_EMIF_EMIRST_EMIRST_MK(0xFFFFu)))

/*==========================================================================*\
* _EMIF_EMIRST		- Global Reset Register Config
\*--------------------------------------------------------------------------*/
#define _EMIF_EMIRST_CFG(EMIRST) \
	_PREG_SET(_EMIF_EMIRST_ADDR,\
    		(Uint16) (	_EMIF_EMIRST_EMIRST_MK(EMIRST)\
	))


/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*=============================================================================*\
* _EMIF_EMIBE	   - Bus Error Status Register
*
* Fields:
*  (R) _EMIF_EMIBE_TIME
*  (R) _EMIF_EMIBE_CE3
*  (R) _EMIF_EMIBE_CE2
*  (R) _EMIF_EMIBE_CE1
*  (R) _EMIF_EMIBE_CE0
*  (R) _EMIF_EMIBE_DMA
*  (R) _EMIF_EMIBE_FBUS
*  (R) _EMIF_EMIBE_EBUS
*  (R) _EMIF_EMIBE_DBUS
*  (R) _EMIF_EMIBE_CBUS
*  (R) _EMIF_EMIBE_PBUS
\*============================================================================*/

/*==========================================================================*\
* (R) _EMIF_EMIBE_TIME
\*--------------------------------------------------------------------------*/
#define _EMIF_EMIBE_TIME_SHIFT		(0x000Cu)
#define _EMIF_EMIBE_TIME_MK(n)           	(((Uint16)(n) & 0x0001u) << _EMIF_EMIBE_TIME_SHIFT)
#define _EMIF_EMIBE_TIME_MASK            	(_EMIF_EMIBE_TIME_MK(0x0001u))
#define _EMIF_EMIBE_TIME_CLR              (~(_EMIF_EMIBE_TIME_MASK))

/*==========================================================================*\
* (R) _EMIF_EMIBE_CE3
\*--------------------------------------------------------------------------*/
#define _EMIF_EMIBE_CE3_SHIFT			(0x000Au)
#define _EMIF_EMIBE_CE3_MK(n)           	(((Uint16)(n) & 0x0001u) << _EMIF_EMIBE_CE3_SHIFT)
#define _EMIF_EMIBE_CE3_MASK            	(_EMIF_EMIBE_CE3_MK(0x0001u))
#define _EMIF_EMIBE_CE3_CLR               (~(_EMIF_EMIBE_CE3_MASK))

/*==========================================================================*\
* (R) _EMIF_EMIBE_CE2
\*--------------------------------------------------------------------------*/
#define _EMIF_EMIBE_CE2_SHIFT			(0x0009u)
#define _EMIF_EMIBE_CE2_MK(n)           	(((Uint16)(n) & 0x0001u) << _EMIF_EMIBE_CE2_SHIFT)
#define _EMIF_EMIBE_CE2_MASK            	(_EMIF_EMIBE_CE2_MK(0x0001u))
#define _EMIF_EMIBE_CE2_CLR               (~(_EMIF_EMIBE_CE2_MASK))

/*==========================================================================*\
* (R) _EMIF_EMIBE_CE1
\*--------------------------------------------------------------------------*/
#define _EMIF_EMIBE_CE1_SHIFT			(0x0008u)
#define _EMIF_EMIBE_CE1_MK(n)           	(((Uint16)(n) & 0x0001u) << _EMIF_EMIBE_CE1_SHIFT)
#define _EMIF_EMIBE_CE1_MASK            	(_EMIF_EMIBE_CE1_MK(0x0001u))
#define _EMIF_EMIBE_CE1_CLR               (~(_EMIF_EMIBE_CE1_MASK))

/*==========================================================================*\
* (R) _EMIF_EMIBE_CE0
\*--------------------------------------------------------------------------*/
#define _EMIF_EMIBE_CE0_SHIFT			(0x0007u)
#define _EMIF_EMIBE_CE0_MK(n)           	(((Uint16)(n) & 0x0001u) << _EMIF_EMIBE_CE0_SHIFT)
#define _EMIF_EMIBE_CE0_MASK            	(_EMIF_EMIBE_CE0_MK(0x0001u))
#define _EMIF_EMIBE_CE0_CLR               (~(_EMIF_EMIBE_CE0_MASK))

/*==========================================================================*\
* (R) _EMIF_EMIBE_DMA
\*--------------------------------------------------------------------------*/
#define _EMIF_EMIBE_DMA_SHIFT			(0x0006u)
#define _EMIF_EMIBE_DMA_MK(n)           	(((Uint16)(n) & 0x0001u) << _EMIF_EMIBE_DMA_SHIFT)
#define _EMIF_EMIBE_DMA_MASK            	(_EMIF_EMIBE_DMA_MK(0x0001u))
#define _EMIF_EMIBE_DMA_CLR               (~(_EMIF_EMIBE_DMA_MASK))

/*==========================================================================*\
* (R) _EMIF_EMIBE_FBUS
\*--------------------------------------------------------------------------*/
#define _EMIF_EMIBE_FBUS_SHIFT		(0x0005u)
#define _EMIF_EMIBE_FBUS_MK(n)           	(((Uint16)(n) & 0x0001u) << _EMIF_EMIBE_FBUS_SHIFT)
#define _EMIF_EMIBE_FBUS_MASK            	(_EMIF_EMIBE_FBUS_MK(0x0001u))
#define _EMIF_EMIBE_FBUS_CLR              (~(_EMIF_EMIBE_FBUS_MASK))

/*==========================================================================*\
* (R) _EMIF_EMIBE_EBUS
\*--------------------------------------------------------------------------*/
#define _EMIF_EMIBE_EBUS_SHIFT		(0x0004u)
#define _EMIF_EMIBE_EBUS_MK(n)           	(((Uint16)(n) & 0x0001u) << _EMIF_EMIBE_EBUS_SHIFT)
#define _EMIF_EMIBE_EBUS_MASK            	(_EMIF_EMIBE_EBUS_MK(0x0001u))
#define _EMIF_EMIBE_EBUS_CLR              (~(_EMIF_EMIBE_EBUS_MASK))

/*==========================================================================*\
* (R) _EMIF_EMIBE_DBUS
\*--------------------------------------------------------------------------*/
#define _EMIF_EMIBE_DBUS_SHIFT		(0x0003u)
#define _EMIF_EMIBE_DBUS_MK(n)           	(((Uint16)(n) & 0x0001u) << _EMIF_EMIBE_DBUS_SHIFT)
#define _EMIF_EMIBE_DBUS_MASK            	(_EMIF_EMIBE_DBUS_MK(0x0001u))
#define _EMIF_EMIBE_DBUS_CLR              (~(_EMIF_EMIBE_DBUS_MASK))

/*==========================================================================*\
* (R) _EMIF_EMIBE_CBUS
\*--------------------------------------------------------------------------*/
#define _EMIF_EMIBE_CBUS_SHIFT		(0x0002u)
#define _EMIF_EMIBE_CBUS_MK(n)           	(((Uint16)(n) & 0x0001u) << _EMIF_EMIBE_CBUS_SHIFT)
#define _EMIF_EMIBE_CBUS_MASK            	(_EMIF_EMIBE_CBUS_MK(0x0001u))
#define _EMIF_EMIBE_CBUS_CLR              (~(_EMIF_EMIBE_CBUS_MASK))

/*==========================================================================*\
* (R) _EMIF_EMIBE_PBUS
\*--------------------------------------------------------------------------*/
#define _EMIF_EMIBE_PBUS_SHIFT		(0x0000u)
#define _EMIF_EMIBE_PBUS_MK(n)           	(((Uint16)(n) & 0x0001u) << _EMIF_EMIBE_PBUS_SHIFT)
#define _EMIF_EMIBE_PBUS_MASK            	(_EMIF_EMIBE_PBUS_MK(0x0001u))
#define _EMIF_EMIBE_PBUS_CLR              (~(_EMIF_EMIBE_PBUS_MASK))


/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*===========================================================================*\
* _EMIF_CE01   - Space Control Register 1
* _EMIF_CE11   - Space Control Register 1
* _EMIF_CE21   - Space Control Register 1
* _EMIF_CE31   - Space Control Register 1
*
* Fields:
*  (RW) _EMIF_CEx1_MTYPE	- MTYPE field
*  (RW) _EMIF_CEx1_RDSETUP	- Read Setup field
*  (RW) _EMIF_CEx1_RDSTROBE	- Read Strobe field
*  (RW) _EMIF_CEx1_RDHOLD	- Read Hold field
\*===========================================================================*/

/*==========================================================================*\
* (RW) _EMIF_CE01_MTYPE
\*--------------------------------------------------------------------------*/
#define _EMIF_CE01_MTYPE_SHIFT		(0x000Cu)
#define _EMIF_CE01_MTYPE_MK(n)           	(((Uint16)(n) & 0x0007u) << _EMIF_CE01_MTYPE_SHIFT)
#define _EMIF_CE01_MTYPE_MASK            	(_EMIF_CE01_MTYPE_MK(0x0007u))
#define _EMIF_CE01_MTYPE_CLR             	(~(_EMIF_CE01_MTYPE_MK(0x0007u)))

/*==========================================================================*\
* (RW) _EMIF_CE01_RDSETUP
\*--------------------------------------------------------------------------*/
#define _EMIF_CE01_RDSETUP_SHIFT		(0x0008u)
#define _EMIF_CE01_RDSETUP_MK(n)		(((Uint16)(n) & 0x000Fu) << _EMIF_CE01_RDSETUP_SHIFT)
#define _EMIF_CE01_RDSETUP_MASK           (_EMIF_CE01_RDSETUP_MK(0x000Fu))
#define _EMIF_CE01_RDSETUP_CLR            (~(_EMIF_CE01_RDSETUP_MK(0x000Fu)))

/*==========================================================================*\
* (RW) _EMIF_CE01_RDSTROBE
\*--------------------------------------------------------------------------*/
#define _EMIF_CE01_RDSTROBE_SHIFT		(0x0002u)
#define _EMIF_CE01_RDSTROBE_MK(n)		(((Uint16)(n) & 0x003fu) << _EMIF_CE01_RDSTROBE_SHIFT)
#define _EMIF_CE01_RDSTROBE_MASK          (_EMIF_CE01_RDSTROBE_MK(0x003Fu))
#define _EMIF_CE01_RDSTROBE_CLR           (~(_EMIF_CE01_RDSTROBE_MK(0x003Fu)))

/*==========================================================================*\
* (RW) _EMIF_CE01_RDHOLD
\*--------------------------------------------------------------------------*/
#define _EMIF_CE01_RDHOLD_SHIFT		(0x0000u)
#define _EMIF_CE01_RDHOLD_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE01_RDHOLD_SHIFT)
#define _EMIF_CE01_RDHOLD_MASK          	(_EMIF_CE01_RDHOLD_MK(0x0003u))
#define _EMIF_CE01_RDHOLD_CLR           	(~(_EMIF_CE01_RDHOLD_MK(0x0003u)))

/*==========================================================================*\
* _EMIF_CE01	- CE(0/1/2/3) Space Control Register 1 Config
\*--------------------------------------------------------------------------*/
#define _EMIF_CE01_CFG(Sp,mtype,rdsetup,rdstrobe,rdhold) \
	_PREG_SET(_EMIF_CE01_ADDR(Sp),\
    		(Uint16) (	_EMIF_CE01_MTYPE_MK(mtype) 		|	\
				_EMIF_CE01_RDSETUP_MK(rdsetup)	|	\
				_EMIF_CE01_RDSTROBE_MK(rdstrobe) 	|	\
				_EMIF_CE01_RDHOLD_MK(rdhold) 			\
             ))

/*==========================================================================*\
* (RW) _EMIF_CE11_MTYPE
\*--------------------------------------------------------------------------*/
#define _EMIF_CE11_MTYPE_SHIFT		(0x000Cu)
#define _EMIF_CE11_MTYPE_MK(n)           	(((Uint16)(n) & 0x0007u) << _EMIF_CE11_MTYPE_SHIFT)
#define _EMIF_CE11_MTYPE_MASK            	(_EMIF_CE11_MTYPE_MK(0x0007u))
#define _EMIF_CE11_MTYPE_CLR             	(~(_EMIF_CE11_MTYPE_MK(0x0007u)))

/*==========================================================================*\
* (RW) _EMIF_CE11_RDSETUP
\*--------------------------------------------------------------------------*/
#define _EMIF_CE11_RDSETUP_SHIFT		(0x0008u)
#define _EMIF_CE11_RDSETUP_MK(n)		(((Uint16)(n) & 0x000Fu) << _EMIF_CE11_RDSETUP_SHIFT)
#define _EMIF_CE11_RDSETUP_MASK           (_EMIF_CE11_RDSETUP_MK(0x000Fu))
#define _EMIF_CE11_RDSETUP_CLR            (~(_EMIF_CE11_RDSETUP_MK(0x000Fu)))

/*==========================================================================*\
* (RW) _EMIF_CE11_RDSTROBE
\*--------------------------------------------------------------------------*/
#define _EMIF_CE11_RDSTROBE_SHIFT		(0x0002u)
#define _EMIF_CE11_RDSTROBE_MK(n)		(((Uint16)(n) & 0x003fu) << _EMIF_CE11_RDSTROBE_SHIFT)
#define _EMIF_CE11_RDSTROBE_MASK          (_EMIF_CE11_RDSTROBE_MK(0x003Fu))
#define _EMIF_CE11_RDSTROBE_CLR           (~(_EMIF_CE11_RDSTROBE_MK(0x003Fu)))

/*==========================================================================*\
* (RW) _EMIF_CE11_RDHOLD
\*--------------------------------------------------------------------------*/
#define _EMIF_CE11_RDHOLD_SHIFT		(0x0000u)
#define _EMIF_CE11_RDHOLD_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE11_RDHOLD_SHIFT)
#define _EMIF_CE11_RDHOLD_MASK          	(_EMIF_CE11_RDHOLD_MK(0x0003u))
#define _EMIF_CE11_RDHOLD_CLR           	(~(_EMIF_CE11_RDHOLD_MK(0x0003u)))

/*==========================================================================*\
* _EMIF_CE11	- CE(0/1/2/3) Space Control Register 1 Config
\*--------------------------------------------------------------------------*/
#define _EMIF_CE11_CFG(Sp,mtype,rdsetup,rdstrobe,rdhold) \
	_PREG_SET(_EMIF_CE11_ADDR(Sp),\
    		(Uint16) (	_EMIF_CE11_MTYPE_MK(mtype) 		|	\
				_EMIF_CE11_RDSETUP_MK(rdsetup)	|	\
				_EMIF_CE11_RDSTROBE_MK(rdstrobe) 	|	\
				_EMIF_CE11_RDHOLD_MK(rdhold) 			\
             ))

/*==========================================================================*\
* (RW) _EMIF_CE21_MTYPE
\*--------------------------------------------------------------------------*/
#define _EMIF_CE21_MTYPE_SHIFT		(0x000Cu)
#define _EMIF_CE21_MTYPE_MK(n)           	(((Uint16)(n) & 0x0007u) << _EMIF_CE21_MTYPE_SHIFT)
#define _EMIF_CE21_MTYPE_MASK            	(_EMIF_CE21_MTYPE_MK(0x0007u))
#define _EMIF_CE21_MTYPE_CLR             	(~(_EMIF_CE21_MTYPE_MK(0x0007u)))

/*==========================================================================*\
* (RW) _EMIF_CE21_RDSETUP
\*--------------------------------------------------------------------------*/
#define _EMIF_CE21_RDSETUP_SHIFT		(0x0008u)
#define _EMIF_CE21_RDSETUP_MK(n)		(((Uint16)(n) & 0x000Fu) << _EMIF_CE21_RDSETUP_SHIFT)
#define _EMIF_CE21_RDSETUP_MASK           (_EMIF_CE21_RDSETUP_MK(0x000Fu))
#define _EMIF_CE21_RDSETUP_CLR            (~(_EMIF_CE21_RDSETUP_MK(0x000Fu)))

/*==========================================================================*\
* (RW) _EMIF_CE21_RDSTROBE
\*--------------------------------------------------------------------------*/
#define _EMIF_CE21_RDSTROBE_SHIFT		(0x0002u)
#define _EMIF_CE21_RDSTROBE_MK(n)		(((Uint16)(n) & 0x003fu) << _EMIF_CE21_RDSTROBE_SHIFT)
#define _EMIF_CE21_RDSTROBE_MASK          (_EMIF_CE21_RDSTROBE_MK(0x003Fu))
#define _EMIF_CE21_RDSTROBE_CLR           (~(_EMIF_CE21_RDSTROBE_MK(0x003Fu)))

/*==========================================================================*\
* (RW) _EMIF_CE21_RDHOLD
\*--------------------------------------------------------------------------*/
#define _EMIF_CE21_RDHOLD_SHIFT		(0x0000u)
#define _EMIF_CE21_RDHOLD_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE21_RDHOLD_SHIFT)
#define _EMIF_CE21_RDHOLD_MASK          	(_EMIF_CE21_RDHOLD_MK(0x0003u))
#define _EMIF_CE21_RDHOLD_CLR           	(~(_EMIF_CE21_RDHOLD_MK(0x0003u)))

/*==========================================================================*\
* _EMIF_CE21	- CE(0/1/2/3) Space Control Register 1 Config
\*--------------------------------------------------------------------------*/
#define _EMIF_CE21_CFG(Sp,mtype,rdsetup,rdstrobe,rdhold) \
	_PREG_SET(_EMIF_CE21_ADDR(Sp),\
    		(Uint16) (	_EMIF_CE21_MTYPE_MK(mtype) 		|	\
				_EMIF_CE21_RDSETUP_MK(rdsetup)	|	\
				_EMIF_CE21_RDSTROBE_MK(rdstrobe) 	|	\
				_EMIF_CE21_RDHOLD_MK(rdhold) 			\
             ))

/*==========================================================================*\
* (RW) _EMIF_CE31_MTYPE
\*--------------------------------------------------------------------------*/
#define _EMIF_CE31_MTYPE_SHIFT		(0x000Cu)
#define _EMIF_CE31_MTYPE_MK(n)           	(((Uint16)(n) & 0x0007u) << _EMIF_CE31_MTYPE_SHIFT)
#define _EMIF_CE31_MTYPE_MASK            	(_EMIF_CE31_MTYPE_MK(0x0007u))
#define _EMIF_CE31_MTYPE_CLR             	(~(_EMIF_CE31_MTYPE_MK(0x0007u)))

/*==========================================================================*\
* (RW) _EMIF_CE31_RDSETUP
\*--------------------------------------------------------------------------*/
#define _EMIF_CE31_RDSETUP_SHIFT		(0x0008u)
#define _EMIF_CE31_RDSETUP_MK(n)		(((Uint16)(n) & 0x000Fu) << _EMIF_CE31_RDSETUP_SHIFT)
#define _EMIF_CE31_RDSETUP_MASK           (_EMIF_CE31_RDSETUP_MK(0x000Fu))
#define _EMIF_CE31_RDSETUP_CLR            (~(_EMIF_CE31_RDSETUP_MK(0x000Fu)))

/*==========================================================================*\
* (RW) _EMIF_CE31_RDSTROBE
\*--------------------------------------------------------------------------*/
#define _EMIF_CE31_RDSTROBE_SHIFT		(0x0002u)
#define _EMIF_CE31_RDSTROBE_MK(n)		(((Uint16)(n) & 0x003fu) << _EMIF_CE31_RDSTROBE_SHIFT)
#define _EMIF_CE31_RDSTROBE_MASK          (_EMIF_CE31_RDSTROBE_MK(0x003Fu))
#define _EMIF_CE31_RDSTROBE_CLR           (~(_EMIF_CE31_RDSTROBE_MK(0x003Fu)))

/*==========================================================================*\
* (RW) _EMIF_CE31_RDHOLD
\*--------------------------------------------------------------------------*/
#define _EMIF_CE31_RDHOLD_SHIFT		(0x0000u)
#define _EMIF_CE31_RDHOLD_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE31_RDHOLD_SHIFT)
#define _EMIF_CE31_RDHOLD_MASK          	(_EMIF_CE31_RDHOLD_MK(0x0003u))
#define _EMIF_CE31_RDHOLD_CLR           	(~(_EMIF_CE31_RDHOLD_MK(0x0003u)))

/*==========================================================================*\
* _EMIF_CE31	- CE(0/1/2/3) Space Control Register 1 Config
\*--------------------------------------------------------------------------*/
#define _EMIF_CE31_CFG(Sp,mtype,rdsetup,rdstrobe,rdhold) \
	_PREG_SET(_EMIF_CE31_ADDR(Sp),\
    		(Uint16) (	_EMIF_CE31_MTYPE_MK(mtype) 		|	\
				_EMIF_CE31_RDSETUP_MK(rdsetup)	|	\
				_EMIF_CE31_RDSTROBE_MK(rdstrobe) 	|	\
				_EMIF_CE31_RDHOLD_MK(rdhold) 			\
             ))


/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*===========================================================================*\
* _EMIF_CE02   - Space Control Register 2
* _EMIF_CE12   - Space Control Register 2
* _EMIF_CE22   - Space COntrol Register 2
* _EMIF_CE32   - Space Control Register 2
*
* Fields:
*  (RW) _EMIF_CEx2_RDEXHLD 	- Extended Hold Read field
*  (RW) _EMIF_CEx2_WREXHLD	- Extended Hold Write field
*  (RW) _EMIF_CEx2_WRSETUP	- Write Setup field
*  (RW) _EMIF_CEx2_WRSTROBE	- Write Strobe field
*  (RW) _EMIF_CEx2_WRHOLD	- Write Hold field
\*===========================================================================*/

/*==========================================================================*\
* (RW) _EMIF_CE02_RDEXHLD
\*--------------------------------------------------------------------------*/
#define _EMIF_CE02_RDEXHLD_SHIFT		(0x000Eu)
#define _EMIF_CE02_RDEXHLD_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE02_RDEXHLD_SHIFT)
#define _EMIF_CE02_RDEXHLD_MASK          	(_EMIF_CE02_RDEXHLD_MK(0x0003u))
#define _EMIF_CE02_RDEXHLD_CLR           	(~(_EMIF_CE02_RDEXHLD_MK(0x0003u)))

/*==========================================================================*\
* (RW) _EMIF_CE02_WREXHLD
\*--------------------------------------------------------------------------*/
#define _EMIF_CE02_WREXHLD_SHIFT		(0x000Cu)
#define _EMIF_CE02_WREXHLD_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE02_WREXHLD_SHIFT)
#define _EMIF_CE02_WREXHLD_MASK          	(_EMIF_CE02_WREXHLD_MK(0x0003u))
#define _EMIF_CE02_WREXHLD_CLR           	(~(_EMIF_CE02_WREXHLD_MK(0x0003u)))

/*==========================================================================*\
* (RW) _EMIF_CE02_WRSETUP
\*--------------------------------------------------------------------------*/
#define _EMIF_CE02_WRSETUP_SHIFT		(0x0008u)
#define _EMIF_CE02_WRSETUP_MK(n)		(((Uint16)(n) & 0x000Fu) << _EMIF_CE02_WRSETUP_SHIFT)
#define _EMIF_CE02_WRSETUP_MASK          	(_EMIF_CE02_WRSETUP_MK(0x000Fu))
#define _EMIF_CE02_WRSETUP_CLR           	(~(_EMIF_CE02_WRSETUP_MK(0x000Fu)))

/*==========================================================================*\
* (RW) _EMIF_CE02_WRSTROBE
\*--------------------------------------------------------------------------*/
#define _EMIF_CE02_WRSTROBE_SHIFT		(0x0002u)
#define _EMIF_CE02_WRSTROBE_MK(n)		(((Uint16)(n) & 0x003Fu) << _EMIF_CE02_WRSTROBE_SHIFT)
#define _EMIF_CE02_WRSTROBE_MASK          (_EMIF_CE02_WRSTROBE_MK(0x003Fu))
#define _EMIF_CE02_WRSTROBE_CLR           (~(_EMIF_CE02_WRSTROBE_MK(0x003Fu)))

/*==========================================================================*\
* (RW) _EMIF_CE02_WRHOLD
\*--------------------------------------------------------------------------*/
#define _EMIF_CE02_WRHOLD_SHIFT		(0x0000u)
#define _EMIF_CE02_WRHOLD_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE02_WRHOLD_SHIFT)
#define _EMIF_CE02_WRHOLD_MASK          	(_EMIF_CE02_WRHOLD_MK(0x0003u))
#define _EMIF_CE02_WRHOLD_CLR           	(~(_EMIF_CE02_WRHOLD_MK(0x0003u)))

/*==========================================================================*\
* _EMIF_CE02		- CE(0/1/2/3) Space Control Register 2 Config
\*--------------------------------------------------------------------------*/
#define _EMIF_CE02_CFG(Sp,rdexhld,wrexhld,wrsetup,wrstrobe,wrhold) \
	_PREG_SET(_EMIF_CE02_ADDR(Sp),\
    		(Uint16) (	_EMIF_CE02_RDEXHLD_MK(rdexhld) 	|	\
				_EMIF_CE02_WREXHLD_MK(wrexhld)		|	\
				_EMIF_CE02_WRSETUP_MK(wrsetup) 	|	\
				_EMIF_CE02_WRSTROBE_MK(wrstrobe) 	|	\
				_EMIF_CE02_WRHOLD_MK(wrhold) 			\
             ))

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*===========================================================================*\
* _EMIF_CE02   - Space Control Register 2
* _EMIF_CE12   - Space Control Register 2
* _EMIF_CE22   - Space COntrol Register 2
* _EMIF_CE32   - Space Control Register 2
*
* Fields:
*  (RW) _EMIF_CEx2_RDEXHLD 	- Extended Hold Read field
*  (RW) _EMIF_CEx2_WREXHLD	- Extended Hold Write field
*  (RW) _EMIF_CEx2_WRSETUP	- Write Setup field
*  (RW) _EMIF_CEx2_WRSTROBE	- Write Strobe field
*  (RW) _EMIF_CEx2_WRHOLD	- Write Hold field
\*===========================================================================*/

/*==========================================================================*\
* (RW) _EMIF_CE12_RDEXHLD
\*--------------------------------------------------------------------------*/
#define _EMIF_CE12_RDEXHLD_SHIFT		(0x000Eu)
#define _EMIF_CE12_RDEXHLD_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE12_RDEXHLD_SHIFT)
#define _EMIF_CE12_RDEXHLD_MASK          	(_EMIF_CE12_RDEXHLD_MK(0x0003u))
#define _EMIF_CE12_RDEXHLD_CLR           	(~(_EMIF_CE12_RDEXHLD_MK(0x0003u)))

/*==========================================================================*\
* (RW) _EMIF_CE12_WREXHLD
\*--------------------------------------------------------------------------*/
#define _EMIF_CE12_WREXHLD_SHIFT		(0x000Cu)
#define _EMIF_CE12_WREXHLD_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE12_WREXHLD_SHIFT)
#define _EMIF_CE12_WREXHLD_MASK          	(_EMIF_CE12_WREXHLD_MK(0x0003u))
#define _EMIF_CE12_WREXHLD_CLR           	(~(_EMIF_CE12_WREXHLD_MK(0x0003u)))

/*==========================================================================*\
* (RW) _EMIF_CE12_WRSETUP
\*--------------------------------------------------------------------------*/
#define _EMIF_CE12_WRSETUP_SHIFT		(0x0008u)
#define _EMIF_CE12_WRSETUP_MK(n)		(((Uint16)(n) & 0x000Fu) << _EMIF_CE12_WRSETUP_SHIFT)
#define _EMIF_CE12_WRSETUP_MASK          	(_EMIF_CE12_WRSETUP_MK(0x000Fu))
#define _EMIF_CE12_WRSETUP_CLR           	(~(_EMIF_CE12_WRSETUP_MK(0x000Fu)))

/*==========================================================================*\
* (RW) _EMIF_CE12_WRSTROBE
\*--------------------------------------------------------------------------*/
#define _EMIF_CE12_WRSTROBE_SHIFT		(0x0002u)
#define _EMIF_CE12_WRSTROBE_MK(n)		(((Uint16)(n) & 0x003Fu) << _EMIF_CE12_WRSTROBE_SHIFT)
#define _EMIF_CE12_WRSTROBE_MASK          (_EMIF_CE12_WRSTROBE_MK(0x003Fu))
#define _EMIF_CE12_WRSTROBE_CLR           (~(_EMIF_CE12_WRSTROBE_MK(0x003Fu)))

/*==========================================================================*\
* (RW) _EMIF_CE12_WRHOLD
\*--------------------------------------------------------------------------*/
#define _EMIF_CE12_WRHOLD_SHIFT		(0x0000u)
#define _EMIF_CE12_WRHOLD_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE12_WRHOLD_SHIFT)
#define _EMIF_CE12_WRHOLD_MASK          	(_EMIF_CE12_WRHOLD_MK(0x0003u))
#define _EMIF_CE12_WRHOLD_CLR           	(~(_EMIF_CE12_WRHOLD_MK(0x0003u)))

/*==========================================================================*\
* _EMIF_CE12		- CE(0/1/2/3) Space Control Register 2 Config
\*--------------------------------------------------------------------------*/
#define _EMIF_CE12_CFG(Sp,rdexhld,wrexhld,wrsetup,wrstrobe,wrhold) \
	_PREG_SET(_EMIF_CE12_ADDR(Sp),\
    		(Uint16) (	_EMIF_CE12_RDEXHLD_MK(rdexhld) 	|	\
				_EMIF_CE12_WREXHLD_MK(wrexhld)		|	\
				_EMIF_CE12_WRSETUP_MK(wrsetup) 	|	\
				_EMIF_CE12_WRSTROBE_MK(wrstrobe) 	|	\
				_EMIF_CE12_WRHOLD_MK(wrhold) 			\
             ))


/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*===========================================================================*\
* _EMIF_CE02   - Space Control Register 2
* _EMIF_CE12   - Space Control Register 2
* _EMIF_CE22   - Space COntrol Register 2
* _EMIF_CE32   - Space Control Register 2
*
* Fields:
*  (RW) _EMIF_CEx2_RDEXHLD 	- Extended Hold Read field
*  (RW) _EMIF_CEx2_WREXHLD	- Extended Hold Write field
*  (RW) _EMIF_CEx2_WRSETUP	- Write Setup field
*  (RW) _EMIF_CEx2_WRSTROBE	- Write Strobe field
*  (RW) _EMIF_CEx2_WRHOLD	- Write Hold field
\*===========================================================================*/

/*==========================================================================*\
* (RW) _EMIF_CE22_RDEXHLD
\*--------------------------------------------------------------------------*/
#define _EMIF_CE22_RDEXHLD_SHIFT		(0x000Eu)
#define _EMIF_CE22_RDEXHLD_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE22_RDEXHLD_SHIFT)
#define _EMIF_CE22_RDEXHLD_MASK          	(_EMIF_CE22_RDEXHLD_MK(0x0003u))
#define _EMIF_CE22_RDEXHLD_CLR           	(~(_EMIF_CE22_RDEXHLD_MK(0x0003u)))

/*==========================================================================*\
* (RW) _EMIF_CE22_WREXHLD
\*--------------------------------------------------------------------------*/
#define _EMIF_CE22_WREXHLD_SHIFT		(0x000Cu)
#define _EMIF_CE22_WREXHLD_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE22_WREXHLD_SHIFT)
#define _EMIF_CE22_WREXHLD_MASK          	(_EMIF_CE22_WREXHLD_MK(0x0003u))
#define _EMIF_CE22_WREXHLD_CLR           	(~(_EMIF_CE22_WREXHLD_MK(0x0003u)))

/*==========================================================================*\
* (RW) _EMIF_CE22_WRSETUP
\*--------------------------------------------------------------------------*/
#define _EMIF_CE22_WRSETUP_SHIFT		(0x0008u)
#define _EMIF_CE22_WRSETUP_MK(n)		(((Uint16)(n) & 0x000Fu) << _EMIF_CE22_WRSETUP_SHIFT)
#define _EMIF_CE22_WRSETUP_MASK          	(_EMIF_CE22_WRSETUP_MK(0x000Fu))
#define _EMIF_CE22_WRSETUP_CLR           	(~(_EMIF_CE22_WRSETUP_MK(0x000Fu)))

/*==========================================================================*\
* (RW) _EMIF_CE22_WRSTROBE
\*--------------------------------------------------------------------------*/
#define _EMIF_CE22_WRSTROBE_SHIFT		(0x0002u)
#define _EMIF_CE22_WRSTROBE_MK(n)		(((Uint16)(n) & 0x003Fu) << _EMIF_CE22_WRSTROBE_SHIFT)
#define _EMIF_CE22_WRSTROBE_MASK          (_EMIF_CE22_WRSTROBE_MK(0x003Fu))
#define _EMIF_CE22_WRSTROBE_CLR           (~(_EMIF_CE22_WRSTROBE_MK(0x003Fu)))

/*==========================================================================*\
* (RW) _EMIF_CE22_WRHOLD
\*--------------------------------------------------------------------------*/
#define _EMIF_CE22_WRHOLD_SHIFT		(0x0000u)
#define _EMIF_CE22_WRHOLD_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE22_WRHOLD_SHIFT)
#define _EMIF_CE22_WRHOLD_MASK          	(_EMIF_CE22_WRHOLD_MK(0x0003u))
#define _EMIF_CE22_WRHOLD_CLR           	(~(_EMIF_CE22_WRHOLD_MK(0x0003u)))

/*==========================================================================*\
* _EMIF_CE22		- CE(0/1/2/3) Space Control Register 2 Config
\*--------------------------------------------------------------------------*/
#define _EMIF_CE22_CFG(Sp,rdexhld,wrexhld,wrsetup,wrstrobe,wrhold) \
	_PREG_SET(_EMIF_CE22_ADDR(Sp),\
    		(Uint16) (	_EMIF_CE22_RDEXHLD_MK(rdexhld) 	|	\
				_EMIF_CE22_WREXHLD_MK(wrexhld)		|	\
				_EMIF_CE22_WRSETUP_MK(wrsetup) 	|	\
				_EMIF_CE22_WRSTROBE_MK(wrstrobe) 	|	\
				_EMIF_CE22_WRHOLD_MK(wrhold) 			\
             ))


/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*===========================================================================*\
* _EMIF_CE02   - Space Control Register 2
* _EMIF_CE12   - Space Control Register 2
* _EMIF_CE22   - Space COntrol Register 2
* _EMIF_CE32   - Space Control Register 2
*
* Fields:
*  (RW) _EMIF_CEx2_RDEXHLD 	- Extended Hold Read field
*  (RW) _EMIF_CEx2_WREXHLD	- Extended Hold Write field
*  (RW) _EMIF_CEx2_WRSETUP	- Write Setup field
*  (RW) _EMIF_CEx2_WRSTROBE	- Write Strobe field
*  (RW) _EMIF_CEx2_WRHOLD	- Write Hold field
\*===========================================================================*/

/*==========================================================================*\
* (RW) _EMIF_CE32_RDEXHLD
\*--------------------------------------------------------------------------*/
#define _EMIF_CE32_RDEXHLD_SHIFT		(0x000Eu)
#define _EMIF_CE32_RDEXHLD_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE32_RDEXHLD_SHIFT)
#define _EMIF_CE32_RDEXHLD_MASK          	(_EMIF_CE32_RDEXHLD_MK(0x0003u))
#define _EMIF_CE32_RDEXHLD_CLR           	(~(_EMIF_CE32_RDEXHLD_MK(0x0003u)))

/*==========================================================================*\
* (RW) _EMIF_CE32_WREXHLD
\*--------------------------------------------------------------------------*/
#define _EMIF_CE32_WREXHLD_SHIFT		(0x000Cu)
#define _EMIF_CE32_WREXHLD_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE32_WREXHLD_SHIFT)
#define _EMIF_CE32_WREXHLD_MASK          	(_EMIF_CE32_WREXHLD_MK(0x0003u))
#define _EMIF_CE32_WREXHLD_CLR           	(~(_EMIF_CE32_WREXHLD_MK(0x0003u)))

/*==========================================================================*\
* (RW) _EMIF_CE32_WRSETUP
\*--------------------------------------------------------------------------*/
#define _EMIF_CE32_WRSETUP_SHIFT		(0x0008u)
#define _EMIF_CE32_WRSETUP_MK(n)		(((Uint16)(n) & 0x000Fu) << _EMIF_CE32_WRSETUP_SHIFT)
#define _EMIF_CE32_WRSETUP_MASK          	(_EMIF_CE32_WRSETUP_MK(0x000Fu))
#define _EMIF_CE32_WRSETUP_CLR           	(~(_EMIF_CE32_WRSETUP_MK(0x000Fu)))

/*==========================================================================*\
* (RW) _EMIF_CE32_WRSTROBE
\*--------------------------------------------------------------------------*/
#define _EMIF_CE32_WRSTROBE_SHIFT		(0x0002u)
#define _EMIF_CE32_WRSTROBE_MK(n)		(((Uint16)(n) & 0x003Fu) << _EMIF_CE32_WRSTROBE_SHIFT)
#define _EMIF_CE32_WRSTROBE_MASK          (_EMIF_CE32_WRSTROBE_MK(0x003Fu))
#define _EMIF_CE32_WRSTROBE_CLR           (~(_EMIF_CE32_WRSTROBE_MK(0x003Fu)))

/*==========================================================================*\
* (RW) _EMIF_CE32_WRHOLD
\*--------------------------------------------------------------------------*/
#define _EMIF_CE32_WRHOLD_SHIFT		(0x0000u)
#define _EMIF_CE32_WRHOLD_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_CE32_WRHOLD_SHIFT)
#define _EMIF_CE32_WRHOLD_MASK          	(_EMIF_CE32_WRHOLD_MK(0x0003u))
#define _EMIF_CE32_WRHOLD_CLR           	(~(_EMIF_CE32_WRHOLD_MK(0x0003u)))

/*==========================================================================*\
* _EMIF_CE32		- CE(0/1/2/3) Space Control Register 2 Config
\*--------------------------------------------------------------------------*/
#define _EMIF_CE32_CFG(Sp,rdexhld,wrexhld,wrsetup,wrstrobe,wrhold) \
	_PREG_SET(_EMIF_CE32_ADDR(Sp),\
    		(Uint16) (	_EMIF_CE32_RDEXHLD_MK(rdexhld) 	|	\
				_EMIF_CE32_WREXHLD_MK(wrexhld)		|	\
				_EMIF_CE32_WRSETUP_MK(wrsetup) 	|	\
				_EMIF_CE32_WRSTROBE_MK(wrstrobe) 	|	\
				_EMIF_CE32_WRHOLD_MK(wrhold) 			\
             ))



/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*===========================================================================*\
* _EMIF_CE03   - Space Control Register 3
* _EMIF_CE13   - Space Control Register 3
* _EMIF_CE23   - Space COntrol Register 3
* _EMIF_CE33   - Space Control Register 3
*
* Fields:
*  (RW) _EMIF_CEx3_TIMOUT 	- Timeout field
\*===========================================================================*/

/*==========================================================================*\
* (RW) _EMIF_CE03_TIMOUT
\*--------------------------------------------------------------------------*/
#define _EMIF_CE03_TIMOUT_SHIFT		(0x0000u)
#define _EMIF_CE03_TIMOUT_MK(n)		(((Uint16)(n) & 0x00FFu) << _EMIF_CE03_TIMOUT_SHIFT)
#define _EMIF_CE03_TIMOUT_MASK          	(_EMIF_CE03_TIMOUT_MK(0x00FFu))
#define _EMIF_CE03_TIMOUT_CLR           	(~(_EMIF_CE03_TIMOUT_MK(0x00FFu)))

/*==========================================================================*\
* _EMIF_CE03		- CE(0/1/2/3) Space Control Register 3 Config
\*--------------------------------------------------------------------------*/
#define _EMIF_CE03_CFG(Sp,timeout) \
	_PREG_SET(_EMIF_CE03_ADDR(Sp),\
    		(Uint16) (	_EMIF_CE03_TIMOUT_MK(timeout)\
             ))

/*==========================================================================*\
* (RW) _EMIF_CE13_TIMOUT
\*--------------------------------------------------------------------------*/
#define _EMIF_CE13_TIMOUT_SHIFT		(0x0000u)
#define _EMIF_CE13_TIMOUT_MK(n)		(((Uint16)(n) & 0x00FFu) << _EMIF_CE13_TIMOUT_SHIFT)
#define _EMIF_CE13_TIMOUT_MASK          	(_EMIF_CE13_TIMOUT_MK(0x00FFu))
#define _EMIF_CE13_TIMOUT_CLR           	(~(_EMIF_CE13_TIMOUT_MK(0x00FFu)))

/*==========================================================================*\
* _EMIF_CE13		- CE(0/1/2/3) Space Control Register 3 Config
\*--------------------------------------------------------------------------*/
#define _EMIF_CE13_CFG(Sp,timeout) \
	_PREG_SET(_EMIF_CE13_ADDR(Sp),\
    		(Uint16) (	_EMIF_CE13_TIMOUT_MK(timeout)\
             ))

/*==========================================================================*\
* (RW) _EMIF_CE23_TIMOUT
\*--------------------------------------------------------------------------*/
#define _EMIF_CE23_TIMOUT_SHIFT		(0x0000u)
#define _EMIF_CE23_TIMOUT_MK(n)		(((Uint16)(n) & 0x00FFu) << _EMIF_CE23_TIMOUT_SHIFT)
#define _EMIF_CE23_TIMOUT_MASK          	(_EMIF_CE23_TIMOUT_MK(0x00FFu))
#define _EMIF_CE23_TIMOUT_CLR           	(~(_EMIF_CE23_TIMOUT_MK(0x00FFu)))

/*==========================================================================*\
* _EMIF_CE33		- CE(0/1/2/3) Space Control Register 3 Config
\*--------------------------------------------------------------------------*/
#define _EMIF_CE23_CFG(Sp,timeout) \
	_PREG_SET(_EMIF_CE23_ADDR(Sp),\
    		(Uint16) (	_EMIF_CE33_TIMOUT_MK(timeout)\
             ))

/*==========================================================================*\
* (RW) _EMIF_CE33_TIMOUT
\*--------------------------------------------------------------------------*/
#define _EMIF_CE33_TIMOUT_SHIFT		(0x0000u)
#define _EMIF_CE33_TIMOUT_MK(n)		(((Uint16)(n) & 0x00FFu) << _EMIF_CE33_TIMOUT_SHIFT)
#define _EMIF_CE33_TIMOUT_MASK          	(_EMIF_CE33_TIMOUT_MK(0x00FFu))
#define _EMIF_CE33_TIMOUT_CLR           	(~(_EMIF_CE33_TIMOUT_MK(0x00FFu)))

/*==========================================================================*\
* _EMIF_CE33		- CE(0/1/2/3) Space Control Register 3 Config
\*--------------------------------------------------------------------------*/
#define _EMIF_CE33_CFG(Sp,timeout) \
	_PREG_SET(_EMIF_CE33_ADDR(Sp),\
    		(Uint16) (	_EMIF_CE33_TIMOUT_MK(timeout)\
             ))

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*===========================================================================*\
* _EMIF_SDC1   - SDRAM Control Register 1
*
* Fields:
*  (RW) _EMIF_SDC1_TRC
*  (RW) _EMIF_SDC1_SDSIZE
*  (RW) _EMIF_SDC1_SDWID
*  (RW) _EMIF_SDC1_RFEN
*  (RW) _EMIF_SDC1_TRCD
*  (RW) _EMIF_SDC1_TRP
\*===========================================================================*/

/*===========================================================================*\
* (RW) _EMIF_SDC1_TRC
\*--------------------------------------------------------------------------*/
#define _EMIF_SDC1_TRC_SHIFT		      (0x000Bu)
#define _EMIF_SDC1_TRC_MK(n)		      (((Uint16)(n) & 0x001Fu) << _EMIF_SDC1_TRC_SHIFT)
#define _EMIF_SDC1_TRC_MASK          	(_EMIF_SDC1_TRC_MK(0x001Fu))
#define _EMIF_SDC1_TRC_CLR           	(~(_EMIF_SDC1_TRC_MK(0x001Fu)))

/*==========================================================================*\
* (RW) _EMIF_SDC1_SDSIZE
\*--------------------------------------------------------------------------*/
#define _EMIF_SDC1_SDSIZE_SHIFT		(0x000Au)
#define _EMIF_SDC1_SDSIZE_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_SDC1_SDSIZE_SHIFT)
#define _EMIF_SDC1_SDSIZE_MASK            (_EMIF_SDC1_SDSIZE_MK(0x0001u))
#define _EMIF_SDC1_SDSIZE_CLR             (~(_EMIF_SDC1_SDSIZE_MK(0x0001u)))

/*==========================================================================*\
* (RW) _EMIF_SDC1_SDWID
\*--------------------------------------------------------------------------*/
#define _EMIF_SDC1_SDWID_SHIFT		(0x0009u)
#define _EMIF_SDC1_SDWID_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_SDC1_SDWID_SHIFT)
#define _EMIF_SDC1_SDWID_MASK        	(_EMIF_SDC1_SDWID_MK(0x0001u))
#define _EMIF_SDC1_SDWID_CLR         	(~(_EMIF_SDC1_SDWID_MK(0x0001u)))

/*==========================================================================*\
* (RW) _EMIF_SDC1_RFEN
\*--------------------------------------------------------------------------*/
#define _EMIF_SDC1_RFEN_SHIFT		      (0x0008u)
#define _EMIF_SDC1_RFEN_MK(n)		      (((Uint16)(n) & 0x0001u) << _EMIF_SDC1_RFEN_SHIFT)
#define _EMIF_SDC1_RFEN_MASK        	(_EMIF_SDC1_RFEN_MK(0x0001u))
#define _EMIF_SDC1_RFEN_CLR         	(~(_EMIF_SDC1_RFEN_MK(0x0001u)))

/*==========================================================================*\
* (RW) _EMIF_SDC1_TRCD
\*--------------------------------------------------------------------------*/
#define _EMIF_SDC1_TRCD_SHIFT		      (0x0004u)
#define _EMIF_SDC1_TRCD_MK(n)		      (((Uint16)(n) & 0x000Fu) << _EMIF_SDC1_TRCD_SHIFT)
#define _EMIF_SDC1_TRCD_MASK        	(_EMIF_SDC1_TRCD_MK(0x000Fu))
#define _EMIF_SDC1_TRCD_CLR         	(~(_EMIF_SDC1_TRCD_MK(0x000Fu)))

/*==========================================================================*\
* (RW) _EMIF_SDC1_TRP
\*--------------------------------------------------------------------------*/
#define _EMIF_SDC1_TRP_SHIFT		      (0x0000u)
#define _EMIF_SDC1_TRP_MK(n)		      (((Uint16)(n) & 0x000Fu) << _EMIF_SDC1_TRP_SHIFT)
#define _EMIF_SDC1_TRP_MASK        	      (_EMIF_SDC1_TRP_MK(0x000Fu))
#define _EMIF_SDC1_TRP_CLR         	      (~(_EMIF_SDC1_TRP_MK(0x000Fu)))

/*==========================================================================*\
* _EMIF_SDC1		- SDRAM Control Register 1 Config
\*--------------------------------------------------------------------------*/
#define _EMIF_SDC1_CFG(trc,sdsize,sdwid,rfen,trcd,trp) \
	_PREG_SET(_EMIF_SDC1_ADDR,\
    		(Uint16) (	_EMIF_SDC1_TRC_MK(trc) 		|	\
				_EMIF_SDC1_SDSIZE_MK(sdsize) 	|	\
				_EMIF_SDC1_SDWID_MK(sdwid) 	|	\
				_EMIF_SDC1_RFEN_MK(rfen) 		|	\
				_EMIF_SDC1_TRCD_MK(trcd) 		|	\
				_EMIF_SDC1_TRP_MK(trp)			\
             ))

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*===========================================================================*\
* _EMIF_SDPER   - SDRAM Period Register
*
* Fields:
*  (RW) _EMIF_SDPER_PERIOD
\*===========================================================================*/

/*==========================================================================*\
* (RW) _EMIF_SDPER_PERIOD
\*--------------------------------------------------------------------------*/
#define _EMIF_SDPER_PERIOD_SHIFT		(0x0000u)
#define _EMIF_SDPER_PERIOD_MK(n)		(((Uint16)(n) & 0x0FFFu) << _EMIF_SDPER_PERIOD_SHIFT)
#define _EMIF_SDPER_PERIOD_MASK        	(_EMIF_SDPER_PERIOD_MK(0x0FFFu))
#define _EMIF_SDPER_PERIOD_CLR         	(~(_EMIF_SDPER_PERIOD_MK(0x0FFFu)))

/*==========================================================================*\
* _EMIF_SDPER		- SDRAM Period Register Config
\*--------------------------------------------------------------------------*/
#define _EMIF_SDPER_CFG(period) \
	_PREG_SET(_EMIF_SDPER_ADDR,\
    		(Uint16) (	_EMIF_SDPER_PERIOD_MK(period)		\
             ))

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*============================================================================*\
* _EMIF_SDCNT   - SDRAM Counter Register
*
* Fields:
*  (R)  _EMIF_SDCNT_COUNTER
\*===========================================================================*/

/*===========================================================================*\
* (R) _EMIF_SDCNT_COUNTER
\*---------------------------------------------------------------------------*/
#define _EMIF_SDCNT_COUNTER_SHIFT		(0x0000u)
#define _EMIF_SDCNT_COUNTER_MK(n)		(((Uint16)(n) & 0x0FFFu) << _EMIF_SDCNT_COUNTER_SHIFT)
#define _EMIF_SDCNT_COUNTER_MASK        	(_EMIF_SDCNT_COUNTER_MK(0x0FFFu))
#define _EMIF_SDCNT_COUNTER_CLR           (~(_EMIF_SDCNT_COUNTER_MASK))

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*===========================================================================*\
* _EMIF_INIT   - SDRAM INITialization Register
*
* Fields:
*  (RW)  _EMIF_INIT_INIT
\*===========================================================================*/

/*==========================================================================*\
*  (RW)  _EMIF_INIT_INIT
\*--------------------------------------------------------------------------*/
#define _EMIF_INIT_INIT_SHIFT		(0x0000u)
#define _EMIF_INIT_INIT_MK(n)		(((Uint16)(n) & 0xFFFFu) << _EMIF_INIT_INIT_SHIFT)
#define _EMIF_INIT_INIT_MASK        (_EMIF_INIT_INIT_MK(0xFFFFu))
#define _EMIF_INIT_INIT_CLR         (~(_EMIF_INIT_INIT_MK(0xFFFFu)))

/*==========================================================================*\
* _EMIF_INIT		- SDRAM INITialization Register
\*--------------------------------------------------------------------------*/
#define _EMIF_INIT_CFG(val) \
	_PREG_SET(_EMIF_INIT_ADDR,\
    		(Uint16) (	_EMIF_INIT_INIT_MK(val)		\
             ))

/*==========================================================================*\
*  (RW)  _EMIF_SDINIT_INIT
\*--------------------------------------------------------------------------*/
#define _EMIF_SDINIT_INIT_SHIFT		(0x0000u)
#define _EMIF_SDINIT_INIT_MK(n)		(((Uint16)(n) & 0xFFFFu) << _EMIF_SDINIT_INIT_SHIFT)
#define _EMIF_SDINIT_INIT_MASK        (_EMIF_SDINIT_INIT_MK(0xFFFFu))
#define _EMIF_SDINIT_INIT_CLR         (~(_EMIF_SDINIT_INIT_MK(0xFFFFu)))

/*==========================================================================*\
* _EMIF_SDINIT		- SDRAM INITialization Register
\*--------------------------------------------------------------------------*/
#define _EMIF_SDINIT_CFG(val) \
	_PREG_SET(_EMIF_SDINIT_ADDR,\
    		(Uint16) (	_EMIF_SDINIT_INIT_MK(val)		\
             ))


/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/*===========================================================================*\
* _EMIF_SDC2   - SDRAM Control Register 2
*
* Fields:
*  (RW) _EMIF_SDC2_SDACC
*  (RW) _EMIF_SDC2_TMRD
*  (RW) _EMIF_SDC2_TRAS
*  (RW) _EMIF_SDC2_TACTV2ACTV
\*==========================================================================*/
/*==========================================================================*\
* (RW) _EMIF_SDC2_SDACC
\*--------------------------------------------------------------------------*/
#define _EMIF_SDC2_SDACC_SHIFT		(0x000Au)
#define _EMIF_SDC2_SDACC_MK(n)		(((Uint16)(n) & 0x0001u) << _EMIF_SDC2_SDACC_SHIFT)
#define _EMIF_SDC2_SDACC_MASK        	(_EMIF_SDC2_SDACC_MK(0x0003u))
#define _EMIF_SDC2_SDACC_CLR         	(~(_EMIF_SDC2_SDACC_MK(0x0003u)))

/*==========================================================================*\
* (RW) _EMIF_SDC2_TMRD
\*--------------------------------------------------------------------------*/
#define _EMIF_SDC2_TMRD_SHIFT		(0x0008u)
#define _EMIF_SDC2_TMRD_MK(n)		(((Uint16)(n) & 0x0003u) << _EMIF_SDC2_TMRD_SHIFT)
#define _EMIF_SDC2_TMRD_MASK        	(_EMIF_SDC2_TMRD_MK(0x0003u))
#define _EMIF_SDC2_TMRD_CLR         	(~(_EMIF_SDC2_TMRD_MK(0x0003u)))

/*==========================================================================*\
* (RW) _EMIF_SDC2_TRAS
\*--------------------------------------------------------------------------*/
#define _EMIF_SDC2_TRAS_SHIFT		(0x0004u)
#define _EMIF_SDC2_TRAS_MK(n)		(((Uint16)(n) & 0x000Fu) << _EMIF_SDC2_TRAS_SHIFT)
#define _EMIF_SDC2_TRAS_MASK        	(_EMIF_SDC2_TRAS_MK(0x000Fu))
#define _EMIF_SDC2_TRAS_CLR         	(~(_EMIF_SDC2_TRAS_MK(0x000Fu)))

/*==========================================================================*\
* (RW) _EMIF_SDC2_TACTV2ACTV
\*--------------------------------------------------------------------------*/
#define _EMIF_SDC2_TACTV2ACTV_SHIFT	(0x0000u)
#define _EMIF_SDC2_TACTV2ACTV_MK(n)	(((Uint16)(n) & 0x000Fu) << _EMIF_SDC2_TACTV2ACTV_SHIFT)
#define _EMIF_SDC2_TACTV2ACTV_MASK   	(_EMIF_SDC2_TACTV2ACTV_MK(0x000Fu))
#define _EMIF_SDC2_TACTV2ACTV_CLR    	(~(_EMIF_SDC2_TACTV2ACTV_MK(0x000Fu)))

/*==========================================================================*\
* _EMIF_SDC2		- SDRAM Control Register 2 Config
\*--------------------------------------------------------------------------*/
#define _EMIF_SDC2_CFG(sdacc, tmrd,tras,tactv2actv) \
	_PREG_SET(_EMIF_SDC2_ADDR,\
    		(Uint16) (  _EMIF_SDC2_SDACC_MK(sdacc)          |	\
                  	_EMIF_SDC2_TMRD_MK(tmrd) 		|	\
				_EMIF_SDC2_TRAS_MK(tras) 		|	\
				_EMIF_SDC2_TACTV2ACTV_MK(tactv2actv) 	\
             ))


#elif (!(_EMIF_MOD))
	#error EMIF Hal Module Not Supported on Specified Target
#endif
#endif
