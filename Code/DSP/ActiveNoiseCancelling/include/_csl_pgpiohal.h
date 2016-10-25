/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... GPIO
* FILENAME...... csl_pgpiohal.h
* DATE CREATED.. Mon 06/05/2000 
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS.. csl_stdinc.h, csl_chip.h
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:       06/05/2000 (AP) created
*   LAST MODIFIED: 04/16/2001 updated FILENAME and other header comments  
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the GPIO module)
*
* Registers Covered:
*   (RW) _GPIO_GPIOEN
*   (RW) _GPIO_AGPIOEN
*   (RW) _GPIO_GPIODIR
*   (RW) _GPIO_AGPIODIR
*   (RW) _GPIO_GPIODATA
*   (RW) _GPIO_AGPIODATA
\******************************************************************************/

#ifndef _PGPIOHAL_H_
#define _PGPIOHAL_H_

#include <csl_chiphal.h>

#if (_GPIO_PGPIO_SUPPORT)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _GPIO_AGPIOEN
\*============================================================================*/
#define _GPIO_AGPIOEN_ADDR				(0x4400u)
#define _GPIO_AGPIOEN                       	PREG16(_GPIO_AGPIOEN_ADDR)
#define _AGPIOEN                              	_GPIO_AGPIOEN

/*============================================================================*\
* (RW) _GPIO_AGPIODIR
\*============================================================================*/
#define _GPIO_AGPIODIR_ADDR				(0x4401u)
#define _GPIO_AGPIODIR                       	PREG16(_GPIO_AGPIODIR_ADDR)
#define _AGPIODIR                              	_GPIO_AGPIODIR

/*============================================================================*\
* (RW) _GPIO_AGPIODATA
\*============================================================================*/
#define _GPIO_AGPIODATA_ADDR				(0x4402u)
#define _GPIO_AGPIODATA                       	PREG16(_GPIO_AGPIODATA_ADDR)
#define _AGPIODATA                            	_GPIO_AGPIODATA

/*============================================================================*\
* (RW) _GPIO_GPIOEN
\*============================================================================*/
#define _GPIO_GPIOEN_ADDR				(0x4403u)
#define _GPIO_GPIOEN                       	PREG16(_GPIO_GPIOEN_ADDR)
#define _GPIOEN                              	_GPIO_GPIOEN

/*============================================================================*\
* (RW) _GPIO_GPIODIR
\*============================================================================*/
#define _GPIO_GPIODIR_ADDR				(0x4404u)
#define _GPIO_GPIODIR                       	PREG16(_GPIO_GPIODIR_ADDR)
#define _GPIODIR                              	_GPIO_GPIODIR

/*============================================================================*\
* (RW) _GPIO_GPIODATA
\*============================================================================*/
#define _GPIO_GPIODATA_ADDR				(0x4405u)
#define _GPIO_GPIODATA                       	PREG16(_GPIO_GPIODATA_ADDR)
#define _GPIODATA                            	_GPIO_GPIODATA


/*============================================================================*\
* Generic GPIO register/field get and set macros
\*============================================================================*/

#define GPIO_ADDR(Reg)                    _GPIO_##Reg##_ADDR
#define GPIO_RGET(Reg)                    _PREG_GET(GPIO_ADDR(##Reg))
#define GPIO_RSET(Reg,Val)                _PREG_SET(GPIO_ADDR(##Reg),Val)
#define GPIO_RAOI(Reg,AND,OR,INV)         _PREG_AOI(GPIO_ADDR(##Reg),AND,OR,INV)
#define GPIO_FGET(Reg,Field)              _PFIELD_GET(GPIO_ADDR(##Reg),_GPIO_##Reg##_##Field)
#define GPIO_FSET(Reg,Field,Val)\
   _PFIELD_SET(GPIO_ADDR(Reg), _GPIO_##Reg##_##Field, Val)
#define GPIO_FSETS(Reg,Field,Sym)\
   GPIO_FSET(Reg,##Field,GPIO_##Reg##_##Field##_##Sym)
#define GPIO_FAOI(Reg,Field,AND,OR,INV)  _PFIELD_AOI(GPIO_ADDR(Reg),_GPIO_##Reg##_##Field,AND,OR,INV)
#define GPIO_FMK(Reg,Field,Val)          _GPIO_##Reg##_##Field##_MK(Val)
#define GPIO_FMKS(Reg,Field,Sym)         GPIO_FMK(##Reg,##Field,GPIO_##Reg##_##Field##_##Sym)


/*===========================================================================*\
* _GPIO_GPIODIR
*
* Fields:
*  (RW) _GPIO_GPIODIR_IO13DIR
*  (RW) _GPIO_GPIODIR_IO12DIR
*  (RW) _GPIO_GPIODIR_IO11DIR
*  (RW) _GPIO_GPIODIR_IO10DIR
*  (RW) _GPIO_GPIODIR_IO9DIR
*  (RW) _GPIO_GPIODIR_IO8DIR
\*==========================================================================*/


/*==========================================================================*\
* (RW) _GPIO_GPIODIR_IO13DIR
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIODIR_IO13DIR_SHIFT		(0x0005u)
#define _GPIO_GPIODIR_IO13DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIODIR_IO13DIR_SHIFT)
#define _GPIO_GPIODIR_IO13DIR_MASK       	(_GPIO_GPIODIR_IO13DIR_MK(0x0001u))
#define _GPIO_GPIODIR_IO13DIR_CLR        	(~(_GPIO_GPIODIR_IO13DIR_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIODIR_IO12DIR
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIODIR_IO12DIR_SHIFT		(0x0004u)
#define _GPIO_GPIODIR_IO12DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIODIR_IO12DIR_SHIFT)
#define _GPIO_GPIODIR_IO12DIR_MASK       	(_GPIO_GPIODIR_IO12DIR_MK(0x0001u))
#define _GPIO_GPIODIR_IO12DIR_CLR        	(~(_GPIO_GPIODIR_IO12DIR_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIODIR_IO11DIR
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIODIR_IO11DIR_SHIFT		(0x0003u)
#define _GPIO_GPIODIR_IO11DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIODIR_IO11DIR_SHIFT)
#define _GPIO_GPIODIR_IO11DIR_MASK       	(_GPIO_GPIODIR_IO11DIR_MK(0x0001u))
#define _GPIO_GPIODIR_IO11DIR_CLR        	(~(_GPIO_GPIODIR_IO11DIR_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIODIR_IO10DIR
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIODIR_IO10DIR_SHIFT		(0x0002u)
#define _GPIO_GPIODIR_IO10DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIODIR_IO10DIR_SHIFT)
#define _GPIO_GPIODIR_IO10DIR_MASK       	(_GPIO_GPIODIR_IO10DIR_MK(0x0001u))
#define _GPIO_GPIODIR_IO10DIR_CLR        	(~(_GPIO_GPIODIR_IO10DIR_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIODIR_IO9DIR
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIODIR_IO9DIR_SHIFT		(0x0001u)
#define _GPIO_GPIODIR_IO9DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIODIR_IO9DIR_SHIFT)
#define _GPIO_GPIODIR_IO9DIR_MASK       	(_GPIO_GPIODIR_IO9DIR_MK(0x0001u))
#define _GPIO_GPIODIR_IO9DIR_CLR        	(~(_GPIO_GPIODIR_IO9DIR_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIODIR_IO8DIR
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIODIR_IO8DIR_SHIFT		(0x0000u)
#define _GPIO_GPIODIR_IO8DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIODIR_IO8DIR_SHIFT)
#define _GPIO_GPIODIR_IO8DIR_MASK       	(_GPIO_GPIODIR_IO8DIR_MK(0x0001u))
#define _GPIO_GPIODIR_IO8DIR_CLR        	(~(_GPIO_GPIODIR_IO8DIR_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIODIR 	- Config
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIODIR_CFG(io8,io9,io10,io11,io12,io13)  \
	HPREG_SET(_GPIO_GPIODIR_ADDR,						\
    		(Uint16) (	_GPIO_GPIODIR_IO0DIR_MK(io8) 		|	\
				_GPIO_GPIODIR_IO1DIR_MK(io9) 		|	\
				_GPIO_GPIODIR_IO2DIR_MK(io10) 		|	\
				_GPIO_GPIODIR_IO3DIR_MK(io11) 		|	\
				_GPIO_GPIODIR_IO4DIR_MK(io12) 		|	\
				_GPIO_GPIODIR_IO5DIR_MK(io13) 		|	\
				_GPIO_GPIODIR_IO6DIR_MK(io14) 		|	\
				_GPIO_GPIODIR_IO7DIR_MK(io15) 			\
	             ))

/*===========================================================================*\
* _GPIO_GPIODATA
*
* Fields:
*  (RW) _GPIO_GPIODATA_IO13D
*  (RW) _GPIO_GPIODATA_IO12D
*  (RW) _GPIO_GPIODATA_IO11D
*  (RW) _GPIO_GPIODATA_IO10D
*  (RW) _GPIO_GPIODATA_IO9D
*  (RW) _GPIO_GPIODATA_IO8D
\*==========================================================================*/

/*==========================================================================*\
* (RW) _GPIO_GPIODATA_IO13D
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIODATA_IO13D_SHIFT		(0x0005u)
#define _GPIO_GPIODATA_IO13D_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIODATA_IO13D_SHIFT)
#define _GPIO_GPIODATA_IO13D_MASK       	(_GPIO_GPIODATA_IO13D_MK(0x0001u))
#define _GPIO_GPIODATA_IO13D_CLR        	(~(_GPIO_GPIODATA_IO13D_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIODATA_IO12D
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIODATA_IO12D_SHIFT		(0x0004u)
#define _GPIO_GPIODATA_IO12D_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIODATA_IO12D_SHIFT)
#define _GPIO_GPIODATA_IO12D_MASK       	(_GPIO_GPIODATA_IO12D_MK(0x0001u))
#define _GPIO_GPIODATA_IO12D_CLR        	(~(_GPIO_GPIODATA_IO12D_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIODATA_IO11D
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIODATA_IO11D_SHIFT		(0x0003u)
#define _GPIO_GPIODATA_IO11D_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIODATA_IO11D_SHIFT)
#define _GPIO_GPIODATA_IO11D_MASK       	(_GPIO_GPIODATA_IO11D_MK(0x0001u))
#define _GPIO_GPIODATA_IO11D_CLR        	(~(_GPIO_GPIODATA_IO11D_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIODATA_IO10D
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIODATA_IO10D_SHIFT		(0x0002u)
#define _GPIO_GPIODATA_IO10D_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIODATA_IO10D_SHIFT)
#define _GPIO_GPIODATA_IO10D_MASK       	(_GPIO_GPIODATA_IO10D_MK(0x0001u))
#define _GPIO_GPIODATA_IO10D_CLR        	(~(_GPIO_GPIODATA_IO10D_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIODATA_IO9D
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIODATA_IO9D_SHIFT		(0x0001u)
#define _GPIO_GPIODATA_IO9D_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIODATA_IO9D_SHIFT)
#define _GPIO_GPIODATA_IO9D_MASK       	(_GPIO_GPIODATA_IO9D_MK(0x0001u))
#define _GPIO_GPIODATA_IO9D_CLR        	(~(_GPIO_GPIODATA_IO9D_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIODATA_IO8D
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIODATA_IO8D_SHIFT		(0x0000u)
#define _GPIO_GPIODATA_IO8D_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIODATA_IO8D_SHIFT)
#define _GPIO_GPIODATA_IO8D_MASK       	(_GPIO_GPIODATA_IO8D_MK(0x0001u))
#define _GPIO_GPIODATA_IO8D_CLR        	(~(_GPIO_GPIODATA_IO8D_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIODATA 	- Config
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIODATA_CFG(io8,io9,io10,io11,io12,io13)  \
	HPREG_SET(_GPIO_GPIODATA_ADDR,						\
    		(Uint16) (	_GPIO_GPIODATA_IO8D_MK(io8) 		|	\
				_GPIO_GPIODATA_IO9D_MK(io9) 		|	\
				_GPIO_GPIODATA_IO10D_MK(io10) 		|	\
				_GPIO_GPIODATA_IO11D_MK(io11) 		|	\
				_GPIO_GPIODATA_IO12D_MK(io12) 		|	\
				_GPIO_GPIODATA_IO13D_MK(io13) 			\
	             ))

/*===========================================================================*\
* _GPIO_GPIOEN
*
* Fields:
*  (RW) _GPIO_GPIOEN_IO13
*  (RW) _GPIO_GPIOEN_IO12
*  (RW) _GPIO_GPIOEN_IO11
*  (RW) _GPIO_GPIOEN_IO10
*  (RW) _GPIO_GPIOEN_IO9
*  (RW) _GPIO_GPIOEN_IO8
\*==========================================================================*/

/*==========================================================================*\
* (RW) _GPIO_GPIOEN_IO13
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIOEN_IO13_SHIFT		(0x0005u)
#define _GPIO_GPIOEN_IO13_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIOEN_IO13_SHIFT)
#define _GPIO_GPIOEN_IO13_MASK       	(_GPIO_GPIOEN_IO13_MK(0x0001u))
#define _GPIO_GPIOEN_IO13_CLR        	(~(_GPIO_GPIOEN_IO13_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIOEN_IO12
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIOEN_IO12_SHIFT		(0x0004u)
#define _GPIO_GPIOEN_IO12_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIOEN_IO12_SHIFT)
#define _GPIO_GPIOEN_IO12_MASK       	(_GPIO_GPIOEN_IO12_MK(0x0001u))
#define _GPIO_GPIOEN_IO12_CLR        	(~(_GPIO_GPIOEN_IO12_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIOEN_IO11
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIOEN_IO11_SHIFT		(0x0003u)
#define _GPIO_GPIOEN_IO11_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIOEN_IO11_SHIFT)
#define _GPIO_GPIOEN_IO11_MASK       	(_GPIO_GPIOEN_IO11_MK(0x0001u))
#define _GPIO_GPIOEN_IO11_CLR        	(~(_GPIO_GPIOEN_IO11_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIOEN_IO10
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIOEN_IO10_SHIFT		(0x0002u)
#define _GPIO_GPIOEN_IO10_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIOEN_IO10_SHIFT)
#define _GPIO_GPIOEN_IO10_MASK       	(_GPIO_GPIOEN_IO10_MK(0x0001u))
#define _GPIO_GPIOEN_IO10_CLR        	(~(_GPIO_GPIOEN_IO10_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIOEN_IO9
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIOEN_IO9_SHIFT		(0x0001u)
#define _GPIO_GPIOEN_IO9_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIOEN_IO9_SHIFT)
#define _GPIO_GPIOEN_IO9_MASK       	(_GPIO_GPIOEN_IO9_MK(0x0001u))
#define _GPIO_GPIOEN_IO9_CLR        	(~(_GPIO_GPIOEN_IO9_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIOEN_IO8D
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIOEN_IO8_SHIFT		(0x0000u)
#define _GPIO_GPIOEN_IO8_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIOEN_IO8_SHIFT)
#define _GPIO_GPIOEN_IO8_MASK       	(_GPIO_GPIOEN_IO8_MK(0x0001u))
#define _GPIO_GPIOEN_IO8_CLR        	(~(_GPIO_GPIOEN_IO8_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIOEN 	- Config
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIOEN_CFG(io8,io9,io10,io11,io12,io13)  \
	HPREG_SET(_GPIO_GPIOEN_ADDR,						\
    		(Uint16) (	_GPIO_GPIOEN_IO8_MK(io8) 		|	\
				_GPIO_GPIOEN_IO9_MK(io9) 		|	\
				_GPIO_GPIOEN_IO10_MK(io10) 		|	\
				_GPIO_GPIOEN_IO11_MK(io11) 		|	\
				_GPIO_GPIOEN_IO12_MK(io12) 		|	\
				_GPIO_GPIOEN_IO13_MK(io13) 			\
	             ))

/*===========================================================================*\
* _GPIO_AGPIODIR
*
* Fields:
*  (RW) _GPIO_AGPIODIR_IO13DIR
*  (RW) _GPIO_AGPIODIR_IO12DIR
*  (RW) _GPIO_AGPIODIR_IO11DIR
*  (RW) _GPIO_AGPIODIR_IO10DIR
*  (RW) _GPIO_AGPIODIR_IO9DIR
*  (RW) _GPIO_AGPIODIR_IO8DIR
\*==========================================================================*/


/*==========================================================================*\
* (RW) _GPIO_AGPIODIR_IO13DIR
\*--------------------------------------------------------------------------*/
#define _GPIO_AGPIODIR_IO13DIR_SHIFT		(0x0005u)
#define _GPIO_AGPIODIR_IO13DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_AGPIODIR_IO13DIR_SHIFT)
#define _GPIO_AGPIODIR_IO13DIR_MASK       	(_GPIO_AGPIODIR_IO13DIR_MK(0x0001u))
#define _GPIO_AGPIODIR_IO13DIR_CLR        	(~(_GPIO_AGPIODIR_IO13DIR_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_AGPIODIR_IO12DIR
\*--------------------------------------------------------------------------*/
#define _GPIO_AGPIODIR_IO12DIR_SHIFT		(0x0004u)
#define _GPIO_AGPIODIR_IO12DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_AGPIODIR_IO12DIR_SHIFT)
#define _GPIO_AGPIODIR_IO12DIR_MASK       	(_GPIO_AGPIODIR_IO12DIR_MK(0x0001u))
#define _GPIO_AGPIODIR_IO12DIR_CLR        	(~(_GPIO_AGPIODIR_IO12DIR_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_AGPIODIR_IO11DIR
\*--------------------------------------------------------------------------*/
#define _GPIO_AGPIODIR_IO11DIR_SHIFT		(0x0003u)
#define _GPIO_AGPIODIR_IO11DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_AGPIODIR_IO11DIR_SHIFT)
#define _GPIO_AGPIODIR_IO11DIR_MASK       	(_GPIO_AGPIODIR_IO11DIR_MK(0x0001u))
#define _GPIO_AGPIODIR_IO11DIR_CLR        	(~(_GPIO_AGPIODIR_IO11DIR_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_AGPIODIR_IO10DIR
\*--------------------------------------------------------------------------*/
#define _GPIO_AGPIODIR_IO10DIR_SHIFT		(0x0002u)
#define _GPIO_AGPIODIR_IO10DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_AGPIODIR_IO10DIR_SHIFT)
#define _GPIO_AGPIODIR_IO10DIR_MASK       	(_GPIO_AGPIODIR_IO10DIR_MK(0x0001u))
#define _GPIO_AGPIODIR_IO10DIR_CLR        	(~(_GPIO_AGPIODIR_IO10DIR_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_AGPIODIR_IO9DIR
\*--------------------------------------------------------------------------*/
#define _GPIO_AGPIODIR_IO9DIR_SHIFT		(0x0001u)
#define _GPIO_AGPIODIR_IO9DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_AGPIODIR_IO9DIR_SHIFT)
#define _GPIO_AGPIODIR_IO9DIR_MASK       	(_GPIO_AGPIODIR_IO9DIR_MK(0x0001u))
#define _GPIO_AGPIODIR_IO9DIR_CLR        	(~(_GPIO_AGPIODIR_IO9DIR_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_AGPIODIR_IO8DIR
\*--------------------------------------------------------------------------*/
#define _GPIO_AGPIODIR_IO8DIR_SHIFT		(0x0000u)
#define _GPIO_AGPIODIR_IO8DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_AGPIODIR_IO8DIR_SHIFT)
#define _GPIO_AGPIODIR_IO8DIR_MASK       	(_GPIO_AGPIODIR_IO8DIR_MK(0x0001u))
#define _GPIO_AGPIODIR_IO8DIR_CLR        	(~(_GPIO_AGPIODIR_IO8DIR_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_AGPIODIR 	- Config
\*--------------------------------------------------------------------------*/
#define _GPIO_AGPIODIR_CFG(io8,io9,io10,io11,io12,io13)  \
	HPREG_SET(_GPIO_AGPIODIR_ADDR,						\
    		(Uint16) (	_GPIO_AGPIODIR_IO0DIR_MK(io8) 		|	\
				_GPIO_AGPIODIR_IO1DIR_MK(io9) 		|	\
				_GPIO_AGPIODIR_IO2DIR_MK(io10) 		|	\
				_GPIO_AGPIODIR_IO3DIR_MK(io11) 		|	\
				_GPIO_AGPIODIR_IO4DIR_MK(io12) 		|	\
				_GPIO_AGPIODIR_IO5DIR_MK(io13) 		|	\
				_GPIO_AGPIODIR_IO6DIR_MK(io14) 		|	\
				_GPIO_AGPIODIR_IO7DIR_MK(io15) 			\
	             ))

/*===========================================================================*\
* _GPIO_AGPIODATA
*
* Fields:
*  (RW) _GPIO_AGPIODATA_IO13D
*  (RW) _GPIO_AGPIODATA_IO12D
*  (RW) _GPIO_AGPIODATA_IO11D
*  (RW) _GPIO_AGPIODATA_IO10D
*  (RW) _GPIO_AGPIODATA_IO9D
*  (RW) _GPIO_AGPIODATA_IO8D
\*==========================================================================*/

/*==========================================================================*\
* (RW) _GPIO_AGPIODATA_IO13D
\*--------------------------------------------------------------------------*/
#define _GPIO_AGPIODATA_IO13D_SHIFT		(0x0005u)
#define _GPIO_AGPIODATA_IO13D_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_AGPIODATA_IO13D_SHIFT)
#define _GPIO_AGPIODATA_IO13D_MASK       	(_GPIO_AGPIODATA_IO13D_MK(0x0001u))
#define _GPIO_AGPIODATA_IO13D_CLR        	(~(_GPIO_AGPIODATA_IO13D_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_AGPIODATA_IO12D
\*--------------------------------------------------------------------------*/
#define _GPIO_AGPIODATA_IO12D_SHIFT		(0x0004u)
#define _GPIO_AGPIODATA_IO12D_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_AGPIODATA_IO12D_SHIFT)
#define _GPIO_AGPIODATA_IO12D_MASK       	(_GPIO_AGPIODATA_IO12D_MK(0x0001u))
#define _GPIO_AGPIODATA_IO12D_CLR        	(~(_GPIO_AGPIODATA_IO12D_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_AGPIODATA_IO11D
\*--------------------------------------------------------------------------*/
#define _GPIO_AGPIODATA_IO11D_SHIFT		(0x0003u)
#define _GPIO_AGPIODATA_IO11D_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_AGPIODATA_IO11D_SHIFT)
#define _GPIO_AGPIODATA_IO11D_MASK       	(_GPIO_AGPIODATA_IO11D_MK(0x0001u))
#define _GPIO_AGPIODATA_IO11D_CLR        	(~(_GPIO_AGPIODATA_IO11D_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_AGPIODATA_IO10D
\*--------------------------------------------------------------------------*/
#define _GPIO_AGPIODATA_IO10D_SHIFT		(0x0002u)
#define _GPIO_AGPIODATA_IO10D_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_AGPIODATA_IO10D_SHIFT)
#define _GPIO_AGPIODATA_IO10D_MASK       	(_GPIO_AGPIODATA_IO10D_MK(0x0001u))
#define _GPIO_AGPIODATA_IO10D_CLR        	(~(_GPIO_AGPIODATA_IO10D_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_AGPIODATA_IO9D
\*--------------------------------------------------------------------------*/
#define _GPIO_AGPIODATA_IO9D_SHIFT		(0x0001u)
#define _GPIO_AGPIODATA_IO9D_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_AGPIODATA_IO9D_SHIFT)
#define _GPIO_AGPIODATA_IO9D_MASK       	(_GPIO_AGPIODATA_IO9D_MK(0x0001u))
#define _GPIO_AGPIODATA_IO9D_CLR        	(~(_GPIO_AGPIODATA_IO9D_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_AGPIODATA_IO8D
\*--------------------------------------------------------------------------*/
#define _GPIO_AGPIODATA_IO8D_SHIFT		(0x0000u)
#define _GPIO_AGPIODATA_IO8D_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_AGPIODATA_IO8D_SHIFT)
#define _GPIO_AGPIODATA_IO8D_MASK       	(_GPIO_AGPIODATA_IO8D_MK(0x0001u))
#define _GPIO_AGPIODATA_IO8D_CLR        	(~(_GPIO_AGPIODATA_IO8D_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_AGPIODATA 	- Config
\*--------------------------------------------------------------------------*/
#define _GPIO_AGPIODATA_CFG(io8,io9,io10,io11,io12,io13)  \
	HPREG_SET(_GPIO_AGPIODATA_ADDR,						\
    		(Uint16) (	_GPIO_AGPIODATA_IO8D_MK(io8) 		|	\
				_GPIO_AGPIODATA_IO9D_MK(io9) 		|	\
				_GPIO_AGPIODATA_IO10D_MK(io10) 		|	\
				_GPIO_AGPIODATA_IO11D_MK(io11) 		|	\
				_GPIO_AGPIODATA_IO12D_MK(io12) 		|	\
				_GPIO_AGPIODATA_IO13D_MK(io13) 			\
	             ))

/*===========================================================================*\
* _GPIO_AGPIOEN
*
* Fields:
*  (RW) _GPIO_AGPIOEN_IO13
*  (RW) _GPIO_AGPIOEN_IO12
*  (RW) _GPIO_AGPIOEN_IO11
*  (RW) _GPIO_AGPIOEN_IO10
*  (RW) _GPIO_AGPIOEN_IO9
*  (RW) _GPIO_AGPIOEN_IO8
\*==========================================================================*/

/*==========================================================================*\
* (RW) _GPIO_AGPIOEN_IO13
\*--------------------------------------------------------------------------*/
#define _GPIO_AGPIOEN_IO13_SHIFT		(0x0005u)
#define _GPIO_AGPIOEN_IO13_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_AGPIOEN_IO13_SHIFT)
#define _GPIO_AGPIOEN_IO13_MASK       	(_GPIO_AGPIOEN_IO13_MK(0x0001u))
#define _GPIO_AGPIOEN_IO13_CLR        	(~(_GPIO_AGPIOEN_IO13_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_AGPIOEN_IO12
\*--------------------------------------------------------------------------*/
#define _GPIO_AGPIOEN_IO12_SHIFT		(0x0004u)
#define _GPIO_AGPIOEN_IO12_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_AGPIOEN_IO12_SHIFT)
#define _GPIO_AGPIOEN_IO12_MASK       	(_GPIO_AGPIOEN_IO12_MK(0x0001u))
#define _GPIO_AGPIOEN_IO12_CLR        	(~(_GPIO_AGPIOEN_IO12_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_AGPIOEN_IO11
\*--------------------------------------------------------------------------*/
#define _GPIO_AGPIOEN_IO11_SHIFT		(0x0003u)
#define _GPIO_AGPIOEN_IO11_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_AGPIOEN_IO11_SHIFT)
#define _GPIO_AGPIOEN_IO11_MASK       	(_GPIO_AGPIOEN_IO11_MK(0x0001u))
#define _GPIO_AGPIOEN_IO11_CLR        	(~(_GPIO_AGPIOEN_IO11_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_AGPIOEN_IO10
\*--------------------------------------------------------------------------*/
#define _GPIO_AGPIOEN_IO10_SHIFT		(0x0002u)
#define _GPIO_AGPIOEN_IO10_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_AGPIOEN_IO10_SHIFT)
#define _GPIO_AGPIOEN_IO10_MASK       	(_GPIO_AGPIOEN_IO10_MK(0x0001u))
#define _GPIO_AGPIOEN_IO10_CLR        	(~(_GPIO_AGPIOEN_IO10_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_AGPIOEN_IO9
\*--------------------------------------------------------------------------*/
#define _GPIO_AGPIOEN_IO9_SHIFT		(0x0001u)
#define _GPIO_AGPIOEN_IO9_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_AGPIOEN_IO9_SHIFT)
#define _GPIO_AGPIOEN_IO9_MASK       	(_GPIO_AGPIOEN_IO9_MK(0x0001u))
#define _GPIO_AGPIOEN_IO9_CLR        	(~(_GPIO_AGPIOEN_IO9_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_AGPIOEN_IO8D
\*--------------------------------------------------------------------------*/
#define _GPIO_AGPIOEN_IO8_SHIFT		(0x0000u)
#define _GPIO_AGPIOEN_IO8_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_AGPIOEN_IO8_SHIFT)
#define _GPIO_AGPIOEN_IO8_MASK       	(_GPIO_AGPIOEN_IO8_MK(0x0001u))
#define _GPIO_AGPIOEN_IO8_CLR        	(~(_GPIO_AGPIOEN_IO8_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_AGPIOEN 	- Config
\*--------------------------------------------------------------------------*/
#define _GPIO_AGPIOEN_CFG(io8,io9,io10,io11,io12,io13)  \
	HPREG_SET(_GPIO_AGPIOEN_ADDR,						\
    		(Uint16) (	_GPIO_AGPIOEN_IO8_MK(io8) 		|	\
				_GPIO_AGPIOEN_IO9_MK(io9) 		|	\
				_GPIO_AGPIOEN_IO10_MK(io10) 		|	\
				_GPIO_AGPIOEN_IO11_MK(io11) 		|	\
				_GPIO_AGPIOEN_IO12_MK(io12) 		|	\
				_GPIO_AGPIOEN_IO13_MK(io13) 			\
	             ))

#else
   #ifndef _GPIO_MOD_
	#error GPIO Hal Module Not Supported on Specified Target
   #endif
#endif
#endif
