/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... PWR
* FILENAME...... csl_pwrhal.h
* DATE CREATED.. Thu 11/11/1999
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... CSL HAL
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:       11/11/1999 Created
*   MODIFIED:      11/29/1999 modified for TMS320C54xx
*                  07/18/2000 modified for TMS320C55xx
*                  04/16/2001 updated header comments
*   		   08/21/2003 -Corrected SHIFT macros for ICR,ISTR
*                             -Corrected HPREG* and HPFIELD* macros to _PREG*
*                              and _PFILED*
*                             -Corrected 5502 field names as per data manual
*                  09/23/2003 -Renamed MISTR->MISR
*       		      -Corrected PISTR register field names as per data manual
*       	   08/08/2004 Added 5501 support	      
*       		      
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the PWR module)
*
* Registers Covered:
*   (RW) _PWR_ICR  -  Idle configuration register
*
\******************************************************************************/
#ifndef _PWRHAL_H_
#define _PWRHAL_H_

#include <csl_chiphal.h>

#if (_PWR_SUPPORT)

/****************************************\
* _PWR scope and inline control macros
\****************************************/
#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#define IDECL static inline
#define USEDEFS
#define IDEF  static inline


 #define _PWR_IDLE_PERIPHERALS_ACTIVE	(0x0001u)
 #define _PWR_IDLE_PERIPHERALS_INACTIVE   (0x0002u)
 #define _PWR_IDLE_PLL_DISABLED           (0x0003u)


/*============================================================================*\
* _PWR_ICR:  Idle Configuration Register
\*============================================================================*/
#define _PWR_ICR_ADDR			       (0x0001u)
#define _PWR_ICR                           PREG16(_PWR_ICR_ADDR)
#define _ICR                               _PWR_ICR

#define _PWR_ISTR_ADDR			      (0x0002u)
#define _PWR_ISTR	                         PREG16(_PWR_ISTR_ADDR)
#define _ISTR                              _PWR_ISTR

#if (CHIP_5502) || (CHIP_5501)

  #define _PWR_PICR_ADDR                     (0x9400)
  #define _PWR_PICR                          PREG16(_PWR_PICR_ADDR)
  #define _PICR                              _PWR_PICR

  #define _PWR_PISTR_ADDR                     (0x9401)
  #define _PWR_PISTR                          PREG16(_PWR_PISTR_ADDR)
  #define _PISTR                              _PWR_PISTR


  #define _PWR_MICR_ADDR                     (0x9402)
  #define _PWR_MICR                          PREG16(_PWR_MICR_ADDR)
  #define _MICR                              _PWR_MICR

  #define _PWR_MISR_ADDR                     (0x9403)
  #define _PWR_MISR                          PREG16(_PWR_MISR_ADDR)
  #define _MISR                              _PWR_MISR

#endif  // CHIP_5502 || CHIP_5501


/*============================================================================*\
* Generic PWR register/field get/set macros
\*============================================================================*/
#define PWR_ADDR(Reg)              _PWR_##Reg##_ADDR
#define PWR_RGET(Reg)              _PREG_GET(PWR_ADDR(##Reg))
#define PWR_RSET(Reg,Val)          _PREG_SET(PWR_ADDR(##Reg),Val)
#define PWR_RAOI(Reg,AND,OR,INV)   _PREG_AOI(PWR_ADDR(##Reg),AND,OR,INV)
#define PWR_FGET(Reg,Field)        _PFIELD_GET(PWR_ADDR(##Reg),_PWR_##Reg##_##Field)
#define PWR_FSET(Reg,Field,Val)    _PFIELD_SET(PWR_ADDR(##Reg),_PWR_##Reg##_##Field,Val)
#define PWR_FSETS(Reg,Field,Sym)   PWR_FSET(##Reg,##Field,PWR_##Reg##_##Field##_##Sym)
#define PWR_FMK(Reg,Field,Val)     _PWR_##Reg##_##Field##_MK(Val)
#define PWR_FMKS(Reg,Field,Sym)    PWR_FMK(##Reg,##Field,PWR_##Reg##_##Field##_##Sym)

#define PWR_FAOI(Reg,Field,AND,OR,INV)\
  _PFIELD_AOI(PWR_ADDR(##Reg),_PWR_##Reg##_##Field,AND,OR,INV)

/*============================================================================*\
* _PWR_ICR_GET and _PWR_ICR_SET
\*============================================================================*/
#define _PWR_ICR_GET(RegAddr)		      _PREG_GET(RegAddr)
#define _PWR_ICR_SET(RegAddr,Val)		_PREG_SET(RegAddr, Val)

/*============================================================================*\
* _PWR_ISTR_GET
\*============================================================================*/
#define _PWR_ISTR_GET(RegAddr)            _PREG_GET(RegAddr)

#if (CHIP_5502) || (CHIP_5501)
/*============================================================================*\
* _PWR_PICR_GET and _PWR_PICR_SET
\*============================================================================*/
#define _PWR_PICR_GET(RegAddr)		      _PREG_GET(RegAddr)
#define _PWR_PICR_SET(RegAddr,Val)		      _PREG_SET(RegAddr, Val)

/*============================================================================*\
* _PWR_PISTR_GET
\*============================================================================*/
#define _PWR_PISTR_GET(RegAddr)            _PREG_GET(RegAddr)

/*============================================================================*\
* _PWR_MICR_GET and _PWR_MICR_SET
\*============================================================================*/
#define _PWR_MICR_GET(RegAddr)		      _PREG_GET(RegAddr)
#define _PWR_MICR_SET(RegAddr,Val)		_PREG_SET(RegAddr, Val)

/*============================================================================*\
* _PWR_ISTR_GET
\*============================================================================*/
#define _PWR_MISR_GET(RegAddr)            _PREG_GET(RegAddr)

#endif  // CHIP_5502 || CHIP_5501

#if (CHIP_5502) || (CHIP_5501)

/*===========================================================================*\
* _PWR_ICR    - Idle Configuration Register
*
* Fields:
*  (RW) _PWR_ICR_IPORTI
*  (RW) _PWR_ICR_MPORTI
*  (RW) _PWR_ICR_XPORTI
*  (RW) _PWR_ICR_EMIFI
*  (RW) _PWR_ICR_CLKI
*  (RW) _PWR_ICR_PERI
*  (RW) _PWR_ICR_ICACHEI
*  (RW) _PWR_ICR_MPI
*  (RW) _PWR_ICR_CPUI
*
\*==========================================================================*/

/*==========================================================================*\
* (RW) _PWR_ICR_IPORTI
\*--------------------------------------------------------------------------*/
#define _PWR_ICR_IPORTI_SHIFT		  (0x0008)
#define _PWR_ICR_IPORTI_MK(n)          (((Uint16)(n) & 0x0001u) << _PWR_ICR_IPORTI_SHIFT)
#define _PWR_ICR_IPORTI_MASK            (_PWR_ICR_IPORTI_MK(1))
#define _PWR_ICR_IPORTI_CLR             (~(_PWR_ICR_IPORTI_MK(1)))

#define _PWR_ICR_IPORTI_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ICR_IPORTI)

#define _PWR_ICR_IPORTI_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ICR_IPORTI,Val)

/*==========================================================================*\
* (RW) _PWR_ICR_MPORTI
\*--------------------------------------------------------------------------*/
#define _PWR_ICR_MPORTI_SHIFT		  (0x0007)
#define _PWR_ICR_MPORTI_MK(n)          (((Uint16)(n) & 0x0001u) << _PWR_ICR_MPORTI_SHIFT)
#define _PWR_ICR_MPORTI_MASK            (_PWR_ICR_MPORTI_MK(1))
#define _PWR_ICR_MPORTI_CLR             (~(_PWR_ICR_MPORTI_MK(1)))

#define _PWR_ICR_MPORTI_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ICR_MPORTI)

#define _PWR_ICR_MPORTI_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ICR_MPORTI,Val)

/*==========================================================================*\
* (RW) _PWR_ICR_XPORTI
\*--------------------------------------------------------------------------*/
#define _PWR_ICR_XPORTI_SHIFT		  (0x0006)
#define _PWR_ICR_XPORTI_MK(n)          (((Uint16)(n) & 0x0001u) << _PWR_ICR_XPORTI_SHIFT)
#define _PWR_ICR_XPORTI_MASK            (_PWR_ICR_XPORTI_MK(1))
#define _PWR_ICR_XPORTI_CLR             (~(_PWR_ICR_XPORTI_MK(1)))

#define _PWR_ICR_XPORTI_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ICR_XPORTI)

#define _PWR_ICR_XPORTI_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ICR_XPORTI,Val)

/*==========================================================================*\
* (RW) _PWR_ICR_EMIFI
\*--------------------------------------------------------------------------*/
#define _PWR_ICR_EMIFI_SHIFT		  (0x0005)
#define _PWR_ICR_EMIFI_MK(n)          (((Uint16)(n) & 0x0001u) << _PWR_ICR_EMIFI_SHIFT)
#define _PWR_ICR_EMIFI_MASK            (_PWR_ICR_EMIFI_MK(1))
#define _PWR_ICR_EMIFI_CLR             (~(_PWR_ICR_EMIFI_MK(1)))

#define _PWR_ICR_EMIFI_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ICR_EMIFI)

#define _PWR_ICR_EMIFI_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ICR_EMIFI,Val)

/*==========================================================================*\
* (RW) _PWR_ICR_CLKI
\*--------------------------------------------------------------------------*/
#define _PWR_ICR_CLKI_SHIFT		  (0x0004)
#define _PWR_ICR_CLKI_MK(n)          (((Uint16)(n) & 0x0001u) << _PWR_ICR_CLKI_SHIFT)
#define _PWR_ICR_CLKI_MASK            (_PWR_ICR_CLKI_MK(1))
#define _PWR_ICR_CLKI_CLR             (~(_PWR_ICR_CLKI_MK(1)))

#define _PWR_ICR_CLKI_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ICR_CLKI)

#define _PWR_ICR_CLKI_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ICR_CLKI,Val)

/*==========================================================================*\
* (RW) _PWR_ICR_PERI
\*--------------------------------------------------------------------------*/
#define _PWR_ICR_PERI_SHIFT		  (0x0003)
#define _PWR_ICR_PERI_MK(n)          (((Uint16)(n) & 0x0001u) << _PWR_ICR_PERI_SHIFT)
#define _PWR_ICR_PERI_MASK            (_PWR_ICR_PERI_MK(1))
#define _PWR_ICR_PERI_CLR             (~(_PWR_ICR_PERI_MK(1)))

#define _PWR_ICR_PERI_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ICR_PERI)

#define _PWR_ICR_PERI_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ICR_PERI,Val)

/*==========================================================================*\
* (RW) _PWR_ICR_ICACHEI
\*--------------------------------------------------------------------------*/
#define _PWR_ICR_ICACHEI_SHIFT		  (0x0002)
#define _PWR_ICR_ICACHEI_MK(n)          (((Uint16)(n) & 0x0001u) << _PWR_ICR_ICACHEI_SHIFT)
#define _PWR_ICR_ICACHEI_MASK            (_PWR_ICR_ICACHEI_MK(1))
#define _PWR_ICR_ICACHEI_CLR             (~(_PWR_ICR_ICACHEI_MK(1)))

#define _PWR_ICR_ICACHEI_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ICR_ICACHEI)

#define _PWR_ICR_ICACHEI_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ICR_ICACHEI,Val)


/*==========================================================================*\
* (RW) _PWR_ICR_MPI
\*--------------------------------------------------------------------------*/
#define _PWR_ICR_MPI_SHIFT		  (0x0001)
#define _PWR_ICR_MPI_MK(n)          (((Uint16)(n) & 0x0001u) << _PWR_ICR_MPI_SHIFT)
#define _PWR_ICR_MPI_MASK            (_PWR_ICR_MPI_MK(1))
#define _PWR_ICR_MPI_CLR             (~(_PWR_ICR_MPI_MK(1)))

#define _PWR_ICR_MPI_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ICR_MPI)

#define _PWR_ICR_MPI_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ICR_MPI,Val)

/*==========================================================================*\
* (RW) _PWR_ICR_CPUI
\*--------------------------------------------------------------------------*/
#define _PWR_ICR_CPUI_SHIFT		  (0x0000)
#define _PWR_ICR_CPUI_MK(n)          (((Uint16)(n) & 0x0001u) << _PWR_ICR_CPUI_SHIFT)
#define _PWR_ICR_CPUI_MASK            (_PWR_ICR_CPUI_MK(1))
#define _PWR_ICR_CPUI_CLR             (~(_PWR_ICR_CPUI_MK(1)))

#define _PWR_ICR_CPUI_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ICR_CPUI)

#define _PWR_ICR_CPUI_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ICR_CPUI,Val)


/*===========================================================================*\
* _PWR_ISTR    - Idle Status Register
*
* Fields:
*  (RW) _PWR_ISTR_IPORTIS
*  (RW) _PWR_ISTR_MPORTIS
*  (RW) _PWR_ISTR_XPORTIS
*  (RW) _PWR_ISTR_EMIFIS
*  (RW) _PWR_ISTR_CLKIS
*  (RW) _PWR_ISTR_PERIS
*  (RW) _PWR_ISTR_ICACHEIS
*  (RW) _PWR_ISTR_MPIS
*  (RW) _PWR_ISTR_CPUIS
*
\*==========================================================================*/

/*==========================================================================*\
* (RW) _PWR_ISTR_IPORTIS
\*--------------------------------------------------------------------------*/
#define _PWR_ISTR_IPORTIS_SHIFT		  (0x0008)
#define _PWR_ISTR_IPORTIS_MK(n)          (((Uint16)(n) & 0x0001u) << _PWR_ISTR_IPORTIS_SHIFT)
#define _PWR_ISTR_IPORTIS_MASK            (_PWR_ISTR_IPORTIS_MK(1))
#define _PWR_ISTR_IPORTIS_CLR             (~(_PWR_ISTR_IPORTIS_MK(1)))

#define _PWR_ISTR_IPORTIS_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ISTR_IPORTIS)

#define _PWR_ISTR_IPORTIS_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ISTR_IPORTIS,Val)

/*==========================================================================*\
* (RW) _PWR_ISTR_MPORTIS
\*--------------------------------------------------------------------------*/
#define _PWR_ISTR_MPORTIS_SHIFT		  (0x0007)
#define _PWR_ISTR_MPORTIS_MK(n)          (((Uint16)(n) & 0x0001u) << _PWR_ISTR_MPORTIS_SHIFT)
#define _PWR_ISTR_MPORTIS_MASK            (_PWR_ISTR_MPORTIS_MK(1))
#define _PWR_ISTR_MPORTIS_CLR             (~(_PWR_ISTR_MPORTIS_MK(1)))

#define _PWR_ISTR_MPORTIS_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ISTR_MPORTIS)

#define _PWR_ISTR_MPORTIS_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ISTR_MPORTIS,Val)

/*==========================================================================*\
* (RW) _PWR_ISTR_XPORTIS
\*--------------------------------------------------------------------------*/
#define _PWR_ISTR_XPORTIS_SHIFT		  (0x0006)
#define _PWR_ISTR_XPORTIS_MK(n)          (((Uint16)(n) & 0x0001u) << _PWR_ISTR_XPORTIS_SHIFT)
#define _PWR_ISTR_XPORTIS_MASK            (_PWR_ISTR_XPORTIS_MK(1))
#define _PWR_ISTR_XPORTIS_CLR             (~(_PWR_ISTR_XPORTIS_MK(1)))

#define _PWR_ISTR_XPORTIS_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ISTR_XPORTIS)

#define _PWR_ISTR_XPORTIS_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ISTR_XPORTIS,Val)

/*==========================================================================*\
* (RW) _PWR_ISTR_EMIFIS
\*--------------------------------------------------------------------------*/
#define _PWR_ISTR_EMIFIS_SHIFT		  (0x0005)
#define _PWR_ISTR_EMIFIS_MK(n)          (((Uint16)(n) & 0x0001u) << _PWR_ISTR_EMIFIS_SHIFT)
#define _PWR_ISTR_EMIFIS_MASK            (_PWR_ISTR_EMIFIS_MK(1))
#define _PWR_ISTR_EMIFIS_CLR             (~(_PWR_ISTR_EMIFIS_MK(1)))

#define _PWR_ISTR_EMIFIS_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ISTR_EMIFIS)

#define _PWR_ISTR_EMIFIS_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ISTR_EMIFIS,Val)

/*==========================================================================*\
* (RW) _PWR_ISTR_CLKIS
\*--------------------------------------------------------------------------*/
#define _PWR_ISTR_CLKIS_SHIFT		  (0x0004)
#define _PWR_ISTR_CLKIS_MK(n)          (((Uint16)(n) & 0x0001u) << _PWR_ISTR_CLKIS_SHIFT)
#define _PWR_ISTR_CLKIS_MASK            (_PWR_ISTR_CLKIS_MK(1))
#define _PWR_ISTR_CLKIS_CLR             (~(_PWR_ISTR_CLKIS_MK(1)))

#define _PWR_ISTR_CLKIS_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ISTR_CLKIS)

#define _PWR_ISTR_CLKIS_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ISTR_CLKIS,Val)

/*==========================================================================*\
* (RW) _PWR_ISTR_PERIS
\*--------------------------------------------------------------------------*/
#define _PWR_ISTR_PERIS_SHIFT		  (0x0003)
#define _PWR_ISTR_PERIS_MK(n)          (((Uint16)(n) & 0x0001u) << _PWR_ISTR_PERIS_SHIFT)
#define _PWR_ISTR_PERIS_MASK            (_PWR_ISTR_PERIS_MK(1))
#define _PWR_ISTR_PERIS_CLR             (~(_PWR_ISTR_PERIS_MK(1)))

#define _PWR_ISTR_PERIS_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ISTR_PERIS)

#define _PWR_ISTR_PERIS_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ISTR_PERIS,Val)

/*==========================================================================*\
* (RW) _PWR_ISTR_ICACHEIS
\*--------------------------------------------------------------------------*/
#define _PWR_ISTR_ICACHEIS_SHIFT		  (0x0002)
#define _PWR_ISTR_ICACHEIS_MK(n)          (((Uint16)(n) & 0x0001u) << _PWR_ISTR_ICACHEIS_SHIFT)
#define _PWR_ISTR_ICACHEIS_MASK            (_PWR_ISTR_ICACHEIS_MK(1))
#define _PWR_ISTR_ICACHEIS_CLR             (~(_PWR_ISTR_ICACHEIS_MK(1)))

#define _PWR_ISTR_ICACHEIS_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ISTR_ICACHEIS)

#define _PWR_ISTR_ICACHEIS_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ISTR_ICACHEIS,Val)


/*==========================================================================*\
* (RW) _PWR_ISTR_MPI
\*--------------------------------------------------------------------------*/
#define _PWR_ISTR_MPIS_SHIFT		  (0x0001)
#define _PWR_ISTR_MPIS_MK(n)          (((Uint16)(n) & 0x0001u) << _PWR_ISTR_MPIS_SHIFT)
#define _PWR_ISTR_MPIS_MASK            (_PWR_ISTR_MPIS_MK(1))
#define _PWR_ISTR_MPIS_CLR             (~(_PWR_ISTR_MPIS_MK(1)))

#define _PWR_ISTR_MPIS_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ISTR_MPIS)

#define _PWR_ISTR_MPIS_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ISTR_MPIS,Val)

/*==========================================================================*\
* (RW) _PWR_ISTR_CPUI
\*--------------------------------------------------------------------------*/
#define _PWR_ISTR_CPUIS_SHIFT		  (0x0000)
#define _PWR_ISTR_CPUIS_MK(n)          (((Uint16)(n) & 0x0001u) << _PWR_ISTR_CPUIS_SHIFT)
#define _PWR_ISTR_CPUIS_MASK            (_PWR_ISTR_CPUIS_MK(1))
#define _PWR_ISTR_CPUIS_CLR             (~(_PWR_ISTR_CPUIS_MK(1)))

#define _PWR_ISTR_CPUIS_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ISTR_CPUIS)

#define _PWR_ISTR_CPUIS_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ISTR_CPUIS,Val)


#else
/*===========================================================================*\
* _PWR_ICR    - Idle Configuration Register
*
* Fields:
*  (RW) _PWR_ICR_EMIFI
*  (RW) _PWR_ICR_CLKGENI
*  (RW) _PWR_ICR_PERI
*  (RW) _PWR_ICR_CACHEI
*  (RW) _PWR_ICR_DMAI
*  (RW) _PWR_ICR_CPUI
*
\*==========================================================================*/

/*==========================================================================*\
* (RW) _PWR_ICR_EMIFI
\*--------------------------------------------------------------------------*/
#define _PWR_ICR_EMIFI_SHIFT		  (0x0005)
#define _PWR_ICR_EMIFI_MK(n)           (((Uint16)(n) & 0x0001u) << _PWR_ICR_EMIFI_SHIFT)
#define _PWR_ICR_EMIFI_MASK            (_PWR_ICR_EMIFI_MK(1))
#define _PWR_ICR_EMIFI_CLR             (~(_PWR_ICR_EMIFI_MK(1)))

#define _PWR_ICR_EMIFI_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ICR_EMIFI)

#define _PWR_ICR_EMIFI_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ICR_EMIFI,Val)


/*==========================================================================*\
* (RW) _PWR_ICR_CLKGENI
\*--------------------------------------------------------------------------*/
#define _PWR_ICR_CLKGENI_SHIFT		  (0x0004)
#define _PWR_ICR_CLKGENI_MK(n)           (((Uint16)(n) & 0x0001u) << _PWR_ICR_CLKGENI_SHIFT)
#define _PWR_ICR_CLKGENI_MASK            (_PWR_ICR_CLKGENI_MK(1))
#define _PWR_ICR_CLKGENI_CLR             (~(_PWR_ICR_CLKGENI_MK(1)))

#define _PWR_ICR_CLKGENI_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ICR_CLKGENI)

#define _PWR_ICR_CLKGENI_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ICR_CLKGENI,Val)


/*==========================================================================*\
* (RW)
\*--------------------------------------------------------------------------*/
#define _PWR_ICR_PERI_SHIFT		  (0x0003)
#define _PWR_ICR_PERI_MK(n)           (((Uint16)(n) & 0x0001u) << _PWR_ICR_PERI_SHIFT)
#define _PWR_ICR_PERI_MASK            (_PWR_ICR_PERI_MK(1))
#define _PWR_ICR_PERI_CLR             (~(_PWR_ICR_PERI_MK(1)))

#define _PWR_ICR_PERI_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ICR_PERI)

#define _PWR_ICR_PERI_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ICR_PERI,Val)


/*==========================================================================*\
* (RW) _PWR_ICR_CACHEI
\*--------------------------------------------------------------------------*/
#define _PWR_ICR_CACHEI_SHIFT		  (0x0002)
#define _PWR_ICR_CACHEI_MK(n)           (((Uint16)(n) & 0x0001u) << _PWR_ICR_CACHEI_SHIFT)
#define _PWR_ICR_CACHEI_MASK            (_PWR_ICR_CACHEI_MK(1))
#define _PWR_ICR_CACHEI_CLR             (~(_PWR_ICR_CACHEI_MK(1)))

#define _PWR_ICR_CACHEI_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ICR_CACHEI)

#define _PWR_ICR_CACHEI_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ICR_CACHEI,Val)

/*==========================================================================*\
* (RW) _PWR_ICR_DMAI
\*--------------------------------------------------------------------------*/
#define _PWR_ICR_DMAI_SHIFT		  (0x0001)
#define _PWR_ICR_DMAI_MK(n)           (((Uint16)(n) & 0x0001u) << _PWR_ICR_DMAI_SHIFT)
#define _PWR_ICR_DMAI_MASK            (_PWR_ICR_DMAI_MK(1))
#define _PWR_ICR_DMAI_CLR             (~(_PWR_ICR_DMAI_MK(1)))

#define _PWR_ICR_DMAI_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ICR_DMAI)

#define _PWR_ICR_DMAI_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ICR_DMAI,Val)


/*==========================================================================*\
* (RW) _PWR_ICR_CPUI
\*--------------------------------------------------------------------------*/
#define _PWR_ICR_CPUI_SHIFT		  (0x0000)
#define _PWR_ICR_CPUI_MK(n)           (((Uint16)(n) & 0x0001u) << _PWR_ICR_CPUI_SHIFT)
#define _PWR_ICR_CPUI_MASK            (_PWR_ICR_CPUI_MK(1))
#define _PWR_ICR_CPUI_CLR             (~(_PWR_ICR_CPUI_MK(1)))

#define _PWR_ICR_CPUI_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ICR_CPUI)

#define _PWR_ICR_CPUI_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_ICR_CPUI,Val)


/*===========================================================================*\
* _PWR_ISTR    - Idle Status Register
*
* Fields:
*  (R) _PWR_ISTR_EMIFIS
*  (R) _PWR_ISTR_CLKGENIS
*  (R) _PWR_ISTR_PERIS
*  (R) _PWR_ISTR_CACHEIS
*  (R) _PWR_ISTR_DMAIS
*  (R) _PWR_ISTR_CPUIS
*
\*==========================================================================*/


/*==========================================================================*\
* (R) _PWR_ISTR_EMIFIS
\*--------------------------------------------------------------------------*/
#define _PWR_ISTR_EMIFIS_SHIFT		  (0x0005)
#define _PWR_ISTR_EMIFIS_MK(n)           (((Uint16)(n) & 0x0001u) << _PWR_ISTR_EMIFIS_SHIFT)
#define _PWR_ISTR_EMIFIS_MASK            (_PWR_ISTR_EMIFIS_MK(1))
#define _PWR_ISTR_EMIFIS_CLR             (~(_PWR_ISTR_EMIFIS_MK(1)))

#define _PWR_ISTR_EMIFIS_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ISTR_EMIFIS)


/*==========================================================================*\
* (R) _PWR_ISTR_CLKGENIS
\*--------------------------------------------------------------------------*/
#define _PWR_ISTR_CLKGENIS_SHIFT		  (0x0004)
#define _PWR_ISTR_CLKGENIS_MK(n)           (((Uint16)(n) & 0x0001u) << _PWR_ISTR_CLKGENIS_SHIFT)
#define _PWR_ISTR_CLKGENIS_MASK            (_PWR_ISTR_CLKGENIS_MK(1))
#define _PWR_ISTR_CLKGENIS_CLR             (~(_PWR_ISTR_CLKGENIS_MK(1)))

#define _PWR_ISTR_CLKGENIS_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ISTR_CLKGENIS)


/*==========================================================================*\
* (R)  _PWR_ISTR_PERIS
\*--------------------------------------------------------------------------*/
#define _PWR_ISTR_PERIS_SHIFT		  (0x0003)
#define _PWR_ISTR_PERIS_MK(n)           (((Uint16)(n) & 0x0001u) << _PWR_ISTR_PERIS_SHIFT)
#define _PWR_ISTR_PERIS_MASK            (_PWR_ISTR_PERIS_MK(1))
#define _PWR_ISTR_PERIS_CLR             (~(_PWR_ISTR_PERIS_MK(1)))

#define _PWR_ISTR_PERIS_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ISTR_PERIS)


/*==========================================================================*\
* (R) _PWR_ISTR_CACHEIS
\*--------------------------------------------------------------------------*/
#define _PWR_ISTR_CACHEIS_SHIFT		  (0x0002)
#define _PWR_ISTR_CACHEIS_MK(n)           (((Uint16)(n) & 0x0001u) << _PWR_ISTR_CACHEIS_SHIFT)
#define _PWR_ISTR_CACHEIS_MASK            (_PWR_ISTR_CACHEIS_MK(1))
#define _PWR_ISTR_CACHEIS_CLR             (~(_PWR_ISTR_CACHEIS_MK(1)))

#define _PWR_ISTR_CACHEIS_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ISTR_CACHEIS)


/*==========================================================================*\
* (R) _PWR_ISTR_DMAIS
\*--------------------------------------------------------------------------*/
#define _PWR_ISTR_DMAIS_SHIFT		  (0x0001)
#define _PWR_ISTR_DMAIS_MK(n)           (((Uint16)(n) & 0x0001u) << _PWR_ISTR_DMAIS_SHIFT)
#define _PWR_ISTR_DMAIS_MASK            (_PWR_ISTR_DMAIS_MK(1))
#define _PWR_ISTR_DMAIS_CLR             (~(_PWR_ISTR_DMAIS_MK(1)))

#define _PWR_ISTR_DMAIS_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ISTR_DMAIS)


/*==========================================================================*\
* (RW) _PWR_ISTR_CPUIS
\*--------------------------------------------------------------------------*/
#define _PWR_ISTR_CPUIS_SHIFT		  (0x0000)
#define _PWR_ISTR_CPUIS_MK(n)           (((Uint16)(n) & 0x0001u) << _PWR_ISTR_CPUIS_SHIFT)
#define _PWR_ISTR_CPUIS_MASK            (_PWR_ISTR_CPUIS_MK(1))
#define _PWR_ISTR_CPUIS_CLR             (~(_PWR_ISTR_CPUIS_MK(1)))

#define _PWR_ISTR_CPUIS_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_ISTR_CPUIS)

#endif

#if (CHIP_5502) || (CHIP_5501)

/*===========================================================================*\
* _PWR_PICR    - Peripheral Idle Control Register
*
* Fields:
*  (RW) _PWR_PICR_TIM0
*  (RW) _PWR_PICR_TIM1
*  (RW) _PWR_PICR_SP0
*  (RW) _PWR_PICR_SP1
*  (RW) _PWR_PICR_SP2
*  (RW) _PWR_PICR_IO
*  (RW) _PWR_PICR_ID
*  (RW) _PWR_PICR_I2C
*  (RW) _PWR_PICR_URT
*  (RW) _PWR_PICR_PIO
*  (RW) _PWR_PICR_WDT
*  (RW) _PWR_PICR_BIOST
*  (RW) _PWR_PICR_EMIF
*  (RW) _PWR_PICR_MISC
\*==========================================================================*/

/*==========================================================================*\
* (RW) _PWR_PICR_TIM0
\*--------------------------------------------------------------------------*/
#define _PWR_PICR_TIM0_SHIFT		  (0x0000)
#define _PWR_PICR_TIM0_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PICR_TIM0_SHIFT)
#define _PWR_PICR_TIM0_MASK          (_PWR_PICR_TIM0_MK(1))
#define _PWR_PICR_TIM0_CLR           (~(_PWR_PICR_TIM0_MK(1)))

#define _PWR_PICR_TIM0_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PICR_TIM0)

#define _PWR_PICR_TIM0_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PICR_TIM0,Val)

/*==========================================================================*\
* (RW) _PWR_PICR_TIM1
\*--------------------------------------------------------------------------*/
#define _PWR_PICR_TIM1_SHIFT		  (0x0001)
#define _PWR_PICR_TIM1_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PICR_TIM1_SHIFT)
#define _PWR_PICR_TIM1_MASK          (_PWR_PICR_TIM1_MK(1))
#define _PWR_PICR_TIM1_CLR           (~(_PWR_PICR_TIM1_MK(1)))

#define _PWR_PICR_TIM1_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PICR_TIM1)

#define _PWR_PICR_TIM1_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PICR_TIM1,Val)

/*==========================================================================*\
* (RW) _PWR_PICR_SP0
\*--------------------------------------------------------------------------*/
#define _PWR_PICR_SP0_SHIFT		  (0x0002)
#define _PWR_PICR_SP0_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PICR_SP0_SHIFT)
#define _PWR_PICR_SP0_MASK          (_PWR_PICR_SP0_MK(1))
#define _PWR_PICR_SP0_CLR           (~(_PWR_PICR_SP0_MK(1)))

#define _PWR_PICR_SP0_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PICR_SP0)

#define _PWR_PICR_SP0_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PICR_SP0,Val)

/*==========================================================================*\
* (RW) _PWR_PICR_SP1
\*--------------------------------------------------------------------------*/
#define _PWR_PICR_SP1_SHIFT		  (0x0003)
#define _PWR_PICR_SP1_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PICR_SP1_SHIFT)
#define _PWR_PICR_SP1_MASK          (_PWR_PICR_SP1_MK(1))
#define _PWR_PICR_SP1_CLR           (~(_PWR_PICR_SP1_MK(1)))

#define _PWR_PICR_SP1_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PICR_SP1)

#define _PWR_PICR_SP1_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PICR_SP1,Val)


/*==========================================================================*\
* (RW) _PWR_PICR_SP2
\*--------------------------------------------------------------------------*/
#define _PWR_PICR_SP2_SHIFT		  (0x0004)
#define _PWR_PICR_SP2_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PICR_SP2_SHIFT)
#define _PWR_PICR_SP2_MASK          (_PWR_PICR_SP2_MK(1))
#define _PWR_PICR_SP2_CLR           (~(_PWR_PICR_SP2_MK(1)))

#define _PWR_PICR_SP2_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PICR_SP2)

#define _PWR_PICR_SP2_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PICR_SP2,Val)

/*==========================================================================*\
* (RW) _PWR_PICR_IO
\*--------------------------------------------------------------------------*/
#define _PWR_PICR_IO_SHIFT		  (0x0005)
#define _PWR_PICR_IO_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PICR_IO_SHIFT)
#define _PWR_PICR_IO_MASK          (_PWR_PICR_IO_MK(1))
#define _PWR_PICR_IO_CLR           (~(_PWR_PICR_IO_MK(1)))

#define _PWR_PICR_IO_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PICR_IO)

#define _PWR_PICR_IO_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PICR_IO,Val)

/*==========================================================================*\
* (RW) _PWR_PICR_ID
\*--------------------------------------------------------------------------*/
#define _PWR_PICR_ID_SHIFT		  (0x0006)
#define _PWR_PICR_ID_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PICR_ID_SHIFT)
#define _PWR_PICR_ID_MASK          (_PWR_PICR_ID_MK(1))
#define _PWR_PICR_ID_CLR           (~(_PWR_PICR_ID_MK(1)))

#define _PWR_PICR_ID_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PICR_ID)

#define _PWR_PICR_ID_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PICR_ID,Val)

/*==========================================================================*\
* (RW) _PWR_PICR_I2C
\*--------------------------------------------------------------------------*/
#define _PWR_PICR_I2C_SHIFT		  (0x0007)
#define _PWR_PICR_I2C_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PICR_I2C_SHIFT)
#define _PWR_PICR_I2C_MASK          (_PWR_PICR_I2C_MK(1))
#define _PWR_PICR_I2C_CLR           (~(_PWR_PICR_I2C_MK(1)))

#define _PWR_PICR_I2C_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PICR_I2C)

#define _PWR_PICR_I2C_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PICR_I2C,Val)

/*==========================================================================*\
* (RW) _PWR_PICR_URT
\*--------------------------------------------------------------------------*/
#define _PWR_PICR_URT_SHIFT		  (0x0008)
#define _PWR_PICR_URT_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PICR_URT_SHIFT)
#define _PWR_PICR_URT_MASK          (_PWR_PICR_URT_MK(1))
#define _PWR_PICR_URT_CLR           (~(_PWR_PICR_URT_MK(1)))

#define _PWR_PICR_URT_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PICR_URT)

#define _PWR_PICR_URT_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PICR_URT,Val)

/*==========================================================================*\
* (RW) _PWR_PICR_PIO
\*--------------------------------------------------------------------------*/
#define _PWR_PICR_PIO_SHIFT		  (0x0009)
#define _PWR_PICR_PIO_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PICR_PIO_SHIFT)
#define _PWR_PICR_PIO_MASK          (_PWR_PICR_PIO_MK(1))
#define _PWR_PICR_PIO_CLR           (~(_PWR_PICR_PIO_MK(1)))

#define _PWR_PICR_PIO_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PICR_PIO)

#define _PWR_PICR_PIO_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PICR_PIO,Val)

/*==========================================================================*\
* (RW) _PWR_PICR_WDT
\*--------------------------------------------------------------------------*/
#define _PWR_PICR_WDT_SHIFT		  (0x000A)
#define _PWR_PICR_WDT_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PICR_WDT_SHIFT)
#define _PWR_PICR_WDT_MASK          (_PWR_PICR_WDT_MK(1))
#define _PWR_PICR_WDT_CLR           (~(_PWR_PICR_WDT_MK(1)))

#define _PWR_PICR_WDT_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PICR_WDT)

#define _PWR_PICR_WDT_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PICR_WDT,Val)

/*==========================================================================*\
* (RW) _PWR_PICR_BIOST
\*--------------------------------------------------------------------------*/
#define _PWR_PICR_BIOST_SHIFT		  (0x000B)
#define _PWR_PICR_BIOST_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PICR_BIOST_SHIFT)
#define _PWR_PICR_BIOST_MASK          (_PWR_PICR_BIOST_MK(1))
#define _PWR_PICR_BIOST_CLR           (~(_PWR_PICR_BIOST_MK(1)))

#define _PWR_PICR_BIOST_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PICR_BIOST)

#define _PWR_PICR_BIOST_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PICR_BIOST,Val)


/*==========================================================================*\
* (RW) _PWR_PICR_EMIF
\*--------------------------------------------------------------------------*/
#define _PWR_PICR_EMIF_SHIFT		  (0x000C)
#define _PWR_PICR_EMIF_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PICR_EMIF_SHIFT)
#define _PWR_PICR_EMIF_MASK          (_PWR_PICR_EMIF_MK(1))
#define _PWR_PICR_EMIF_CLR           (~(_PWR_PICR_EMIF_MK(1)))

#define _PWR_PICR_EMIF_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PICR_EMIF)

#define _PWR_PICR_EMIF_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PICR_EMIF,Val)

/*==========================================================================*\
* (RW) _PWR_PICR_MISC
\*--------------------------------------------------------------------------*/
#define _PWR_PICR_MISC_SHIFT		  (0x000D)
#define _PWR_PICR_MISC_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PICR_MISC_SHIFT)
#define _PWR_PICR_MISC_MASK          (_PWR_PICR_MISC_MK(1))
#define _PWR_PICR_MISC_CLR           (~(_PWR_PICR_MISC_MK(1)))

#define _PWR_PICR_MISC_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PICR_MISC)

#define _PWR_PICR_MISC_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PICR_MISC,Val)

/*===========================================================================*\
* _PWR_PISTR    - Peripheral Idle Status Register
*
* Fields:
*  (R) _PWR_PISTR_TIM0
*  (R) _PWR_PISTR_TIM1
*  (R) _PWR_PISTR_SP0
*  (R) _PWR_PISTR_SP1
*  (R) _PWR_PISTR_SP2
*  (R) _PWR_PISTR_IO
*  (R) _PWR_PISTR_ID
*  (R) _PWR_PISTR_I2C
*  (R) _PWR_PISTR_URT
*  (R) _PWR_PISTR_PIO
*  (R) _PWR_PISTR_WDT
*  (R) _PWR_PISTR_BIOST
*  (R) _PWR_PISTR_EMIF
*  (R) _PWR_PISTR_MISC
*
\*==========================================================================*/

/*==========================================================================*\
* (R) _PWR_PISTR_TIM0
\*--------------------------------------------------------------------------*/
#define _PWR_PISTR_TIM0_SHIFT		  (0x0000)
#define _PWR_PISTR_TIM0_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PISTR_TIM0_SHIFT)
#define _PWR_PISTR_TIM0_MASK          (_PWR_PISTR_TIM0_MK(1))
#define _PWR_PISTR_TIM0_CLR           (~(_PWR_PISTR_TIM0_MK(1)))

#define _PWR_PISTR_TIM0_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PISTR_TIM0)

#define _PWR_PISTR_TIM0_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PISTR_TIM0,Val)

/*==========================================================================*\
* (R) _PWR_PISTR_TIM1
\*--------------------------------------------------------------------------*/
#define _PWR_PISTR_TIM1_SHIFT		  (0x0001)
#define _PWR_PISTR_TIM1_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PISTR_TIM1_SHIFT)
#define _PWR_PISTR_TIM1_MASK          (_PWR_PISTR_TIM1_MK(1))
#define _PWR_PISTR_TIM1_CLR           (~(_PWR_PISTR_TIM1_MK(1)))

#define _PWR_PISTR_TIM1_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PISTR_TIM1)

#define _PWR_PISTR_TIM1_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PISTR_TIM1,Val)

/*==========================================================================*\
* (R) _PWR_PISTR_SP0
\*--------------------------------------------------------------------------*/
#define _PWR_PISTR_SP0_SHIFT		  (0x0002)
#define _PWR_PISTR_SP0_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PISTR_SP0_SHIFT)
#define _PWR_PISTR_SP0_MASK          (_PWR_PISTR_SP0_MK(1))
#define _PWR_PISTR_SP0_CLR           (~(_PWR_PISTR_SP0_MK(1)))

#define _PWR_PISTR_SP0_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PISTR_SP0)

#define _PWR_PISTR_SP0_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PISTR_SP0,Val)

/*==========================================================================*\
* (R) _PWR_PISTR_SP1
\*--------------------------------------------------------------------------*/
#define _PWR_PISTR_SP1_SHIFT		  (0x0003)
#define _PWR_PISTR_SP1_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PISTR_SP1_SHIFT)
#define _PWR_PISTR_SP1_MASK          (_PWR_PISTR_SP1_MK(1))
#define _PWR_PISTR_SP1_CLR           (~(_PWR_PISTR_SP1_MK(1)))

#define _PWR_PISTR_SP1_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PISTR_SP1)

#define _PWR_PISTR_SP1_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PISTR_SP1,Val)


/*==========================================================================*\
* (R) _PWR_PISTR_SP2
\*--------------------------------------------------------------------------*/
#define _PWR_PISTR_SP2_SHIFT		  (0x0004)
#define _PWR_PISTR_SP2_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PISTR_SP2_SHIFT)
#define _PWR_PISTR_SP2_MASK          (_PWR_PISTR_SP2_MK(1))
#define _PWR_PISTR_SP2_CLR           (~(_PWR_PISTR_SP2_MK(1)))

#define _PWR_PISTR_SP2_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PISTR_SP2)

#define _PWR_PISTR_SP2_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PISTR_SP2,Val)

/*==========================================================================*\
* (R) _PWR_PISTR_IO
\*--------------------------------------------------------------------------*/
#define _PWR_PISTR_IO_SHIFT		  (0x0005)
#define _PWR_PISTR_IO_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PISTR_IO_SHIFT)
#define _PWR_PISTR_IO_MASK          (_PWR_PISTR_IO_MK(1))
#define _PWR_PISTR_IO_CLR           (~(_PWR_PISTR_IO_MK(1)))

#define _PWR_PISTR_IO_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PISTR_IO)

#define _PWR_PISTR_IO_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PISTR_IO,Val)

/*==========================================================================*\
* (R) _PWR_PISTR_ID
\*--------------------------------------------------------------------------*/
#define _PWR_PISTR_ID_SHIFT		  (0x0006)
#define _PWR_PISTR_ID_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PISTR_ID_SHIFT)
#define _PWR_PISTR_ID_MASK          (_PWR_PISTR_ID_MK(1))
#define _PWR_PISTR_ID_CLR           (~(_PWR_PISTR_ID_MK(1)))

#define _PWR_PISTR_ID_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PISTR_ID)

#define _PWR_PISTR_ID_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PISTR_ID,Val)

/*==========================================================================*\
* (R) _PWR_PISTR_I2C
\*--------------------------------------------------------------------------*/
#define _PWR_PISTR_I2C_SHIFT		  (0x0007)
#define _PWR_PISTR_I2C_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PISTR_I2C_SHIFT)
#define _PWR_PISTR_I2C_MASK          (_PWR_PISTR_I2C_MK(1))
#define _PWR_PISTR_I2C_CLR           (~(_PWR_PISTR_I2C_MK(1)))

#define _PWR_PISTR_I2C_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PISTR_I2C)

#define _PWR_PISTR_I2C_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PISTR_I2C,Val)

/*==========================================================================*\
* (R) _PWR_PISTR_URT
\*--------------------------------------------------------------------------*/
#define _PWR_PISTR_URT_SHIFT		  (0x0008)
#define _PWR_PISTR_URT_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PISTR_URT_SHIFT)
#define _PWR_PISTR_URT_MASK          (_PWR_PISTR_URT_MK(1))
#define _PWR_PISTR_URT_CLR           (~(_PWR_PISTR_URT_MK(1)))

#define _PWR_PISTR_URT_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PISTR_URT)

#define _PWR_PISTR_URT_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PISTR_URT,Val)

/*==========================================================================*\
* (R) _PWR_PISTR_PIO
\*--------------------------------------------------------------------------*/
#define _PWR_PISTR_PIO_SHIFT		  (0x0009)
#define _PWR_PISTR_PIO_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PISTR_PIO_SHIFT)
#define _PWR_PISTR_PIO_MASK          (_PWR_PISTR_PIO_MK(1))
#define _PWR_PISTR_PIO_CLR           (~(_PWR_PISTR_PIO_MK(1)))

#define _PWR_PISTR_PIO_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PISTR_PIO)

#define _PWR_PISTR_PIO_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PISTR_PIO,Val)

/*==========================================================================*\
* (R) _PWR_PISTR_WDT
\*--------------------------------------------------------------------------*/
#define _PWR_PISTR_WDT_SHIFT		  (0x000A)
#define _PWR_PISTR_WDT_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PISTR_WDT_SHIFT)
#define _PWR_PISTR_WDT_MASK          (_PWR_PISTR_WDT_MK(1))
#define _PWR_PISTR_WDT_CLR           (~(_PWR_PISTR_WDT_MK(1)))

#define _PWR_PISTR_WDT_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PISTR_WDT)

#define _PWR_PISTR_WDT_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PISTR_WDT,Val)

/*==========================================================================*\
* (R) _PWR_PISTR_BIOST
\*--------------------------------------------------------------------------*/
#define _PWR_PISTR_BIOST_SHIFT		  (0x000B)
#define _PWR_PISTR_BIOST_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PISTR_BIOST_SHIFT)
#define _PWR_PISTR_BIOST_MASK          (_PWR_PISTR_BIOST_MK(1))
#define _PWR_PISTR_BIOST_CLR           (~(_PWR_PISTR_BIOST_MK(1)))

#define _PWR_PISTR_BIOST_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PISTR_BIOST)

#define _PWR_PISTR_BIOST_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PISTR_BIOST,Val)

/*==========================================================================*\
* (RW) _PWR_PISTR_EMIF
\*--------------------------------------------------------------------------*/
#define _PWR_PISTR_EMIF_SHIFT		  (0x000C)
#define _PWR_PISTR_EMIF_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PISTR_EMIF_SHIFT)
#define _PWR_PISTR_EMIF_MASK          (_PWR_PISTR_EMIF_MK(1))
#define _PWR_PISTR_EMIF_CLR           (~(_PWR_PISTR_EMIF_MK(1)))

#define _PWR_PISTR_EMIF_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PISTR_EMIF)

#define _PWR_PISTR_EMIF_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PISTR_EMIF,Val)

/*==========================================================================*\
* (RW) _PWR_PISTR_MISC
\*--------------------------------------------------------------------------*/
#define _PWR_PISTR_MISC_SHIFT		  (0x000D)
#define _PWR_PISTR_MISC_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_PISTR_MISC_SHIFT)
#define _PWR_PISTR_MISC_MASK          (_PWR_PISTR_MISC_MK(1))
#define _PWR_PISTR_MISC_CLR           (~(_PWR_PISTR_MISC_MK(1)))

#define _PWR_PISTR_MISC_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_PISTR_MISC)

#define _PWR_PISTR_MISC_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_PISTR_MISC,Val)

/*===========================================================================*\
* _PWR_MICR    - Master Idle Control Register
*
* Fields:
*  (RW) _PWR_MICR_DMA
*  (RW) _PWR_MICR_HPI
*
\*==========================================================================*/

/*==========================================================================*\
* (RW) _PWR_MICR_DMA
\*--------------------------------------------------------------------------*/
#define _PWR_MICR_DMA_SHIFT		  (0x0000)
#define _PWR_MICR_DMA_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_MICR_DMA_SHIFT)
#define _PWR_MICR_DMA_MASK          (_PWR_MICR_DMA_MK(1))
#define _PWR_MICR_DMA_CLR           (~(_PWR_MICR_DMA_MK(1)))

#define _PWR_MICR_DMA_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_MICR_DMA)

#define _PWR_MICR_DMA_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_MICR_DMA,Val)

/*==========================================================================*\
* (RW) _PWR_MICR_HPI
\*--------------------------------------------------------------------------*/
#define _PWR_MICR_HPI_SHIFT		  (0x0001)
#define _PWR_MICR_HPI_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_MICR_HPI_SHIFT)
#define _PWR_MICR_HPI_MASK          (_PWR_MICR_HPI_MK(1))
#define _PWR_MICR_HPI_CLR           (~(_PWR_MICR_HPI_MK(1)))

#define _PWR_MICR_HPI_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_MICR_HPI)

#define _PWR_MICR_HPI_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_MICR_HPI,Val)


/*===========================================================================*\
* _PWR_MISR    - Master Idle Status Register
*
* Fields:
*  (R) _PWR_MISR_DMA
*  (R) _PWR_MISR_HPI
*
\*==========================================================================*/

/*==========================================================================*\
* (R) _PWR_MISR_DMA
\*--------------------------------------------------------------------------*/
#define _PWR_MISR_DMA_SHIFT		  (0x0000)
#define _PWR_MISR_DMA_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_MISR_DMA_SHIFT)
#define _PWR_MISR_DMA_MASK          (_PWR_MISR_DMA_MK(1))
#define _PWR_MISR_DMA_CLR           (~(_PWR_MISR_DMA_MK(1)))

#define _PWR_MISR_DMA_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_MISR_DMA)

#define _PWR_MISR_DMA_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_MISR_DMA,Val)

/*==========================================================================*\
* (R) _PWR_MISR_UHPI
\*--------------------------------------------------------------------------*/
#define _PWR_MISR_HPI_SHIFT		  (0x0001)
#define _PWR_MISR_HPI_MK(n)         (((Uint16)(n) & 0x0001u) << _PWR_MISR_HPI_SHIFT)
#define _PWR_MISR_HPI_MASK          (_PWR_MISR_HPI_MK(1))
#define _PWR_MISR_HPI_CLR           (~(_PWR_MISR_HPI_MK(1)))

#define _PWR_MISR_HPI_GET(RegAddr) \
	_PFIELD_GET(RegAddr,_PWR_MISR_HPI)

#define _PWR_MISR_HPI_SET(RegAddr,Val) \
	_PFIELD_SET(RegAddr,_PWR_MISR_HPI,Val)

#endif   //CHIP_5502 || CHIP_5501
/*----------------------------------------------------------------------------*/

#endif /* PWR_SUPPORT */
#endif /* _PWRHAL_H_ */
/******************************************************************************\
* End of pwrhal.h
\******************************************************************************/

