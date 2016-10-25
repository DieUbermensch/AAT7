/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... GPIO
* FILENAME...... csl_gpiohal.h
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
*   (RW) _GPIO_IODIR
*   (RW) _GPIO_IODATA
\******************************************************************************/

#ifndef _GPIOHAL_H_
#define _GPIOHAL_H_

#include <csl_chiphal.h>

#if (_GPIO_SUPPORT)

/******************************************************************************\
\******************************************************************************/
/*============================================================================*\
* (RW) _GPIO_IODIR
\*============================================================================*/
#define _GPIO_IODIR_ADDR				(0x3400u)
#define _GPIO_IODIR                       	PREG16(_GPIO_IODIR_ADDR)
#define _IODIR                              	_GPIO_IODIR

/*============================================================================*\
* (RW) _GPIO_IODATA
\*============================================================================*/
#define _GPIO_IODATA_ADDR				(0x3401u)
#define _GPIO_IODATA                       	PREG16(_GPIO_IODATA_ADDR)
#define _IODATA                              	_GPIO_IODATA

/*============================================================================*\
* Generic GPIO register/field get and set macros
\*============================================================================*/

#define GPIO_ADDR(Reg)                    _GPIO_##Reg##_ADDR
#define GPIO_RGET(Reg)                    _PREG_GET(GPIO_ADDR(##Reg))
#define GPIO_RSET(Reg,Val)                _PREG_SET(GPIO_ADDR(##Reg),Val)
#define GPIO_RAOI(Reg,AND,OR,INV)         _PREG_AOI(GPIO_ADDR(##Reg),AND,OR,INV)
#define GPIO_FGET(Reg,Field)              _PFIELD_GET(GPIO_ADDR(##Reg),_GPIO_##Reg##_##Field)
#define GPIO_FSET(Reg,Field,Val)\
   _PFIELD_SET(GPIO_ADDR(##Reg), _GPIO_##Reg##_##Field, Val)
#define GPIO_FSETS(Reg,Field,Sym)\
   GPIO_FSET(##Reg,##Field,GPIO_##Reg##_##Field##_##Sym)
#define GPIO_FAOI(Reg,Field,AND,OR,INV)  _PFIELD_AOI(GPIO_ADDR(##Reg),_GPIO_##Reg##_##Field,AND,OR,INV)
#define GPIO_FMK(Reg,Field,Val)          _GPIO_##Reg##_##Field##_MK(Val)
#define GPIO_FMKS(Reg,Field,Sym)         GPIO_FMK(##Reg,##Field,GPIO_##Reg##_##Field##_##Sym)

/*===========================================================================*\
* _GPIO_IODIR
*
* Fields:
*  (RW) _GPIO_IODIR_IO7DIR
*  (RW) _GPIO_IODIR_IO6DIR
*  (RW) _GPIO_IODIR_IO5DIR
*  (RW) _GPIO_IODIR_IO4DIR
*  (RW) _GPIO_IODIR_IO3DIR
*  (RW) _GPIO_IODIR_IO2DIR
*  (RW) _GPIO_IODIR_IO1DIR
*  (RW) _GPIO_IODIR_IO0DIR
\*==========================================================================*/

/*==========================================================================*\
* (RW) _GPIO_IODIR_IO7DIR
\*--------------------------------------------------------------------------*/
#define _GPIO_IODIR_IO7DIR_SHIFT		(0x0007u)
#define _GPIO_IODIR_IO7DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODIR_IO7DIR_SHIFT)
#define _GPIO_IODIR_IO7DIR_MASK       	(_GPIO_IODIR_IO7DIR_MK(0x0001u))
#define _GPIO_IODIR_IO7DIR_CLR        	(~(_GPIO_IODIR_IO7DIR_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODIR_IO6DIR
\*--------------------------------------------------------------------------*/
#define _GPIO_IODIR_IO6DIR_SHIFT		(0x0006u)
#define _GPIO_IODIR_IO6DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODIR_IO6DIR_SHIFT)
#define _GPIO_IODIR_IO6DIR_MASK       	(_GPIO_IODIR_IO6DIR_MK(0x0001u))
#define _GPIO_IODIR_IO6DIR_CLR        	(~(_GPIO_IODIR_IO6DIR_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODIR_IO5DIR
\*--------------------------------------------------------------------------*/
#define _GPIO_IODIR_IO5DIR_SHIFT		(0x0005u)
#define _GPIO_IODIR_IO5DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODIR_IO5DIR_SHIFT)
#define _GPIO_IODIR_IO5DIR_MASK       	(_GPIO_IODIR_IO5DIR_MK(0x0001u))
#define _GPIO_IODIR_IO5DIR_CLR        	(~(_GPIO_IODIR_IO5DIR_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODIR_IO4DIR
\*--------------------------------------------------------------------------*/
#define _GPIO_IODIR_IO4DIR_SHIFT		(0x0004u)
#define _GPIO_IODIR_IO4DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODIR_IO4DIR_SHIFT)
#define _GPIO_IODIR_IO4DIR_MASK       	(_GPIO_IODIR_IO4DIR_MK(0x0001u))
#define _GPIO_IODIR_IO4DIR_CLR        	(~(_GPIO_IODIR_IO4DIR_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODIR_IO3DIR
\*--------------------------------------------------------------------------*/
#define _GPIO_IODIR_IO3DIR_SHIFT		(0x0003u)
#define _GPIO_IODIR_IO3DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODIR_IO3DIR_SHIFT)
#define _GPIO_IODIR_IO3DIR_MASK       	(_GPIO_IODIR_IO3DIR_MK(0x0001u))
#define _GPIO_IODIR_IO3DIR_CLR        	(~(_GPIO_IODIR_IO3DIR_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODIR_IO2DIR
\*--------------------------------------------------------------------------*/
#define _GPIO_IODIR_IO2DIR_SHIFT		(0x0002u)
#define _GPIO_IODIR_IO2DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODIR_IO2DIR_SHIFT)
#define _GPIO_IODIR_IO2DIR_MASK       	(_GPIO_IODIR_IO2DIR_MK(0x0001u))
#define _GPIO_IODIR_IO2DIR_CLR        	(~(_GPIO_IODIR_IO2DIR_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODIR_IO1DIR
\*--------------------------------------------------------------------------*/
#define _GPIO_IODIR_IO1DIR_SHIFT		(0x0001u)
#define _GPIO_IODIR_IO1DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODIR_IO1DIR_SHIFT)
#define _GPIO_IODIR_IO1DIR_MASK       	(_GPIO_IODIR_IO1DIR_MK(0x0001u))
#define _GPIO_IODIR_IO1DIR_CLR        	(~(_GPIO_IODIR_IO1DIR_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODIR_IO0DIR
\*--------------------------------------------------------------------------*/
#define _GPIO_IODIR_IO0DIR_SHIFT		(0x0000u)
#define _GPIO_IODIR_IO0DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODIR_IO0DIR_SHIFT)
#define _GPIO_IODIR_IO0DIR_MASK       	(_GPIO_IODIR_IO0DIR_MK(0x0001u))
#define _GPIO_IODIR_IO0DIR_CLR        	(~(_GPIO_IODIR_IO0DIR_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODIR 	- Config
\*--------------------------------------------------------------------------*/
#define _GPIO_IODIR_CFG(io0,io1,io2,io3,io4,io5,io6,io7)  \
	HPREG_SET(_GPIO_IODIR_ADDR,						\
    		(Uint16) (	_GPIO_IODIR_IO0DIR_MK(io0) 		|	\
				_GPIO_IODIR_IO1DIR_MK(io1) 		|	\
				_GPIO_IODIR_IO2DIR_MK(io2) 		|	\
				_GPIO_IODIR_IO3DIR_MK(io3) 		|	\
				_GPIO_IODIR_IO4DIR_MK(io4) 		|	\
				_GPIO_IODIR_IO5DIR_MK(io5) 		|	\
				_GPIO_IODIR_IO6DIR_MK(io6) 		|	\
				_GPIO_IODIR_IO7DIR_MK(io7) 			\
	             ))

/*===========================================================================*\
* _GPIO_IODATA
*
* Fields:
*  (RW) _GPIO_IODATA_IO7D
*  (RW) _GPIO_IODATA_IO6D
*  (RW) _GPIO_IODATA_IO5D
*  (RW) _GPIO_IODATA_IO4D
*  (RW) _GPIO_IODATA_IO3D
*  (RW) _GPIO_IODATA_IO2D
*  (RW) _GPIO_IODATA_IO1D
*  (RW) _GPIO_IODATA_IO0D
\*==========================================================================*/

/*==========================================================================*\
* (RW) _GPIO_IODATA_IO7D
\*--------------------------------------------------------------------------*/
#define _GPIO_IODATA_IO7D_SHIFT		(0x0007u)
#define _GPIO_IODATA_IO7D_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODATA_IO7D_SHIFT)
#define _GPIO_IODATA_IO7D_MASK       	(_GPIO_IODATA_IO7D_MK(0x0001u))
#define _GPIO_IODATA_IO7D_CLR        	(~(_GPIO_IODATA_IO7D_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODATA_IO6D
\*--------------------------------------------------------------------------*/
#define _GPIO_IODATA_IO6D_SHIFT		(0x0006u)
#define _GPIO_IODATA_IO6D_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODATA_IO6D_SHIFT)
#define _GPIO_IODATA_IO6D_MASK       	(_GPIO_IODATA_IO6D_MK(0x0001u))
#define _GPIO_IODATA_IO6D_CLR        	(~(_GPIO_IODATA_IO6D_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODATA_IO5D
\*--------------------------------------------------------------------------*/
#define _GPIO_IODATA_IO5D_SHIFT		(0x0005u)
#define _GPIO_IODATA_IO5D_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODATA_IO5D_SHIFT)
#define _GPIO_IODATA_IO5D_MASK       	(_GPIO_IODATA_IO5D_MK(0x0001u))
#define _GPIO_IODATA_IO5D_CLR        	(~(_GPIO_IODATA_IO5D_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODATA_IO4D
\*--------------------------------------------------------------------------*/
#define _GPIO_IODATA_IO4D_SHIFT		(0x0004u)
#define _GPIO_IODATA_IO4D_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODATA_IO4D_SHIFT)
#define _GPIO_IODATA_IO4D_MASK       	(_GPIO_IODATA_IO4D_MK(0x0001u))
#define _GPIO_IODATA_IO4D_CLR        	(~(_GPIO_IODATA_IO4D_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODATA_IO3D
\*--------------------------------------------------------------------------*/
#define _GPIO_IODATA_IO3D_SHIFT		(0x0003u)
#define _GPIO_IODATA_IO3D_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODATA_IO3D_SHIFT)
#define _GPIO_IODATA_IO3D_MASK       	(_GPIO_IODATA_IO3D_MK(0x0001u))
#define _GPIO_IODATA_IO3D_CLR        	(~(_GPIO_IODATA_IO3D_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODATA_IO2D
\*--------------------------------------------------------------------------*/
#define _GPIO_IODATA_IO2D_SHIFT		(0x0002u)
#define _GPIO_IODATA_IO2D_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODATA_IO2D_SHIFT)
#define _GPIO_IODATA_IO2D_MASK       	(_GPIO_IODATA_IO2D_MK(0x0001u))
#define _GPIO_IODATA_IO2D_CLR        	(~(_GPIO_IODATA_IO2D_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODATA_IO1D
\*--------------------------------------------------------------------------*/
#define _GPIO_IODATA_IO1D_SHIFT		(0x0001u)
#define _GPIO_IODATA_IO1D_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODATA_IO1D_SHIFT)
#define _GPIO_IODATA_IO1D_MASK       	(_GPIO_IODATA_IO1D_MK(0x0001u))
#define _GPIO_IODATA_IO1D_CLR        	(~(_GPIO_IODATA_IO1D_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODATA_IO0D
\*--------------------------------------------------------------------------*/
#define _GPIO_IODATA_IO0D_SHIFT		(0x0000u)
#define _GPIO_IODATA_IO0D_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODATA_IO0D_SHIFT)
#define _GPIO_IODATA_IO0D_MASK       	(_GPIO_IODATA_IO0D_MK(0x0001u))
#define _GPIO_IODATA_IO0D_CLR        	(~(_GPIO_IODATA_IO0D_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODATA 	- Config
\*--------------------------------------------------------------------------*/

/*==========================================================================*\
* (RW) _GPIO_IODATA_IO7DAT
\*--------------------------------------------------------------------------*/
#define _GPIO_IODATA_IO7DAT_SHIFT		(0x0007u)
#define _GPIO_IODATA_IO7DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODATA_IO7DAT_SHIFT)
#define _GPIO_IODATA_IO7DAT_MASK       	(_GPIO_IODATA_IO7DAT_MK(0x0001u))
#define _GPIO_IODATA_IO7DAT_CLR        	(~(_GPIO_IODATA_IO7DAT_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODATA_IO6DAT
\*--------------------------------------------------------------------------*/
#define _GPIO_IODATA_IO6DAT_SHIFT		(0x0006u)
#define _GPIO_IODATA_IO6DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODATA_IO6DAT_SHIFT)
#define _GPIO_IODATA_IO6DAT_MASK       	(_GPIO_IODATA_IO6DAT_MK(0x0001u))
#define _GPIO_IODATA_IO6DAT_CLR        	(~(_GPIO_IODATA_IO6DAT_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODATA_IO5DAT
\*--------------------------------------------------------------------------*/
#define _GPIO_IODATA_IO5DAT_SHIFT		(0x0005u)
#define _GPIO_IODATA_IO5DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODATA_IO5DAT_SHIFT)
#define _GPIO_IODATA_IO5DAT_MASK       	(_GPIO_IODATA_IO5DAT_MK(0x0001u))
#define _GPIO_IODATA_IO5DAT_CLR        	(~(_GPIO_IODATA_IO5DAT_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODATA_IO4DAT
\*--------------------------------------------------------------------------*/
#define _GPIO_IODATA_IO4DAT_SHIFT		(0x0004u)
#define _GPIO_IODATA_IO4DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODATA_IO4DAT_SHIFT)
#define _GPIO_IODATA_IO4DAT_MASK       	(_GPIO_IODATA_IO4DAT_MK(0x0001u))
#define _GPIO_IODATA_IO4DAT_CLR        	(~(_GPIO_IODATA_IO4DAT_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODATA_IO3D
\*--------------------------------------------------------------------------*/
#define _GPIO_IODATA_IO3DAT_SHIFT		(0x0003u)
#define _GPIO_IODATA_IO3DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODATA_IO3DAT_SHIFT)
#define _GPIO_IODATA_IO3DAT_MASK       	(_GPIO_IODATA_IO3DAT_MK(0x0001u))
#define _GPIO_IODATA_IO3DAT_CLR        	(~(_GPIO_IODATA_IO3DAT_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODATA_IO2D
\*--------------------------------------------------------------------------*/
#define _GPIO_IODATA_IO2DAT_SHIFT		(0x0002u)
#define _GPIO_IODATA_IO2DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODATA_IO2DAT_SHIFT)
#define _GPIO_IODATA_IO2DAT_MASK       	(_GPIO_IODATA_IO2DAT_MK(0x0001u))
#define _GPIO_IODATA_IO2DAT_CLR        	(~(_GPIO_IODATA_IO2DAT_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODATA_IO1D
\*--------------------------------------------------------------------------*/
#define _GPIO_IODATA_IO1DAT_SHIFT		(0x0001u)
#define _GPIO_IODATA_IO1DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODATA_IO1DAT_SHIFT)
#define _GPIO_IODATA_IO1DAT_MASK       	(_GPIO_IODATA_IO1DAT_MK(0x0001u))
#define _GPIO_IODATA_IO1DAT_CLR        	(~(_GPIO_IODATA_IO1DAT_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODATA_IO0D
\*--------------------------------------------------------------------------*/
#define _GPIO_IODATA_IO0DAT_SHIFT		(0x0000u)
#define _GPIO_IODATA_IO0DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_IODATA_IO0DAT_SHIFT)
#define _GPIO_IODATA_IO0DAT_MASK       	(_GPIO_IODATA_IO0DAT_MK(0x0001u))
#define _GPIO_IODATA_IO0DAT_CLR        	(~(_GPIO_IODATA_IO0DAT_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_IODATA 	- Config
\*--------------------------------------------------------------------------*/
#define _GPIO_IODATA_CFG(io0,io1,io2,io3,io4,io5,io6,io7)  \
	HPREG_SET(_GPIO_IODATA_ADDR,						\
    		(Uint16) (	_GPIO_IODATA_IO0DAT_MK(io0) 		|	\
				_GPIO_IODATA_IO1DAT_MK(io1) 		|	\
				_GPIO_IODATA_IO2DAT_MK(io2) 		|	\
				_GPIO_IODATA_IO3DAT_MK(io3) 		|	\
				_GPIO_IODATA_IO4DAT_MK(io4) 		|	\
				_GPIO_IODATA_IO5DAT_MK(io5) 		|	\
				_GPIO_IODATA_IO6DAT_MK(io6) 		|	\
				_GPIO_IODATA_IO7DAT_MK(io7) 			\
	             ))


#if (_GPIO_PARALLEL_SUPPORT)


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

/*===============================================================*\
* Use new IODATA bit field nomenclature
\*===============================================================*/

/*==========================================================================*\
* (RW) _GPIO_GPIODATA_IO13DAT
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIODATA_IO13DAT_SHIFT		(0x0005u)
#define _GPIO_GPIODATA_IO13DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIODATA_IO13DAT_SHIFT)
#define _GPIO_GPIODATA_IO13DAT_MASK       	(_GPIO_GPIODATA_IO13DAT_MK(0x0001u))
#define _GPIO_GPIODATA_IO13DAT_CLR        	(~(_GPIO_GPIODATA_IO13DAT_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIODATA_IO12D
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIODATA_IO12DAT_SHIFT		(0x0004u)
#define _GPIO_GPIODATA_IO12DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIODATA_IO12DAT_SHIFT)
#define _GPIO_GPIODATA_IO12DAT_MASK       	(_GPIO_GPIODATA_IO12DAT_MK(0x0001u))
#define _GPIO_GPIODATA_IO12DAT_CLR        	(~(_GPIO_GPIODATA_IO12DAT_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIODATA_IO11D
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIODATA_IO11DAT_SHIFT		(0x0003u)
#define _GPIO_GPIODATA_IO11DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIODATA_IO11DAT_SHIFT)
#define _GPIO_GPIODATA_IO11DAT_MASK       	(_GPIO_GPIODATA_IO11DAT_MK(0x0001u))
#define _GPIO_GPIODATA_IO11DAT_CLR        	(~(_GPIO_GPIODATA_IO11DAT_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIODATA_IO10D
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIODATA_IO10DAT_SHIFT		(0x0002u)
#define _GPIO_GPIODATA_IO10DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIODATA_IO10DAT_SHIFT)
#define _GPIO_GPIODATA_IO10DAT_MASK       	(_GPIO_GPIODATA_IO10DAT_MK(0x0001u))
#define _GPIO_GPIODATA_IO10DAT_CLR        	(~(_GPIO_GPIODATA_IO10DAT_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIODATA_IO9D
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIODATA_IO9DAT_SHIFT		(0x0001u)
#define _GPIO_GPIODATA_IO9DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIODATA_IO9DAT_SHIFT)
#define _GPIO_GPIODATA_IO9DAT_MASK       	(_GPIO_GPIODATA_IO9DAT_MK(0x0001u))
#define _GPIO_GPIODATA_IO9DAT_CLR        	(~(_GPIO_GPIODATA_IO9DAT_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIODATA_IO8D
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIODATA_IO8DAT_SHIFT		(0x0000u)
#define _GPIO_GPIODATA_IO8DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIODATA_IO8DAT_SHIFT)
#define _GPIO_GPIODATA_IO8DAT_MASK       	(_GPIO_GPIODATA_IO8DAT_MK(0x0001u))
#define _GPIO_GPIODATA_IO8DAT_CLR        	(~(_GPIO_GPIODATA_IO8DAT_MK(0x0001u)))

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
* (RW) _GPIO_GPIOEN_IO13EN
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIOEN_IO13EN_SHIFT		(0x0005u)
#define _GPIO_GPIOEN_IO13EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIOEN_IO13EN_SHIFT)
#define _GPIO_GPIOEN_IO13EN_MASK       	(_GPIO_GPIOEN_IO13EN_MK(0x0001u))
#define _GPIO_GPIOEN_IO13EN_CLR        	(~(_GPIO_GPIOEN_IO13EN_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIOEN_IO12
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIOEN_IO12EN_SHIFT		(0x0004u)
#define _GPIO_GPIOEN_IO12EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIOEN_IO12EN_SHIFT)
#define _GPIO_GPIOEN_IO12EN_MASK       	(_GPIO_GPIOEN_IO12EN_MK(0x0001u))
#define _GPIO_GPIOEN_IO12EN_CLR        	(~(_GPIO_GPIOEN_IO12EN_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIOEN_IO11
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIOEN_IO11EN_SHIFT		(0x0003u)
#define _GPIO_GPIOEN_IO11EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIOEN_IO11EN_SHIFT)
#define _GPIO_GPIOEN_IO11EN_MASK       	(_GPIO_GPIOEN_IO11EN_MK(0x0001u))
#define _GPIO_GPIOEN_IO11EN_CLR        	(~(_GPIO_GPIOEN_IO11EN_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIOEN_IO10
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIOEN_IO10EN_SHIFT		(0x0002u)
#define _GPIO_GPIOEN_IO10EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIOEN_IO10EN_SHIFT)
#define _GPIO_GPIOEN_IO10EN_MASK       	(_GPIO_GPIOEN_IO10EN_MK(0x0001u))
#define _GPIO_GPIOEN_IO10EN_CLR        	(~(_GPIO_GPIOEN_IO10EN_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIOEN_IO9
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIOEN_IO9EN_SHIFT		(0x0001u)
#define _GPIO_GPIOEN_IO9EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIOEN_IO9EN_SHIFT)
#define _GPIO_GPIOEN_IO9EN_MASK       	(_GPIO_GPIOEN_IO9EN_MK(0x0001u))
#define _GPIO_GPIOEN_IO9EN_CLR        	(~(_GPIO_GPIOEN_IO9EN_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIOEN_IO8D
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIOEN_IO8EN_SHIFT		(0x0000u)
#define _GPIO_GPIOEN_IO8EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_GPIOEN_IO8EN_SHIFT)
#define _GPIO_GPIOEN_IO8EN_MASK       	(_GPIO_GPIOEN_IO8EN_MK(0x0001u))
#define _GPIO_GPIOEN_IO8EN_CLR        	(~(_GPIO_GPIOEN_IO8EN_MK(0x0001u)))

/*==========================================================================*\
* (RW) _GPIO_GPIOEN 	- Config
\*--------------------------------------------------------------------------*/
#define _GPIO_GPIOEN_CFG(io8,io9,io10,io11,io12,io13)  \
	HPREG_SET(_GPIO_GPIOEN_ADDR,						\
    		(Uint16) (	_GPIO_GPIOEN_IO8EN_MK(io8) 		|	\
				_GPIO_GPIOEN_IO9EN_MK(io9) 		|	\
				_GPIO_GPIOEN_IO10EN_MK(io10) 		|	\
				_GPIO_GPIOEN_IO11EN_MK(io11) 		|	\
				_GPIO_GPIOEN_IO12EN_MK(io12) 		|	\
				_GPIO_GPIOEN_IO13EN_MK(io13) 			\
	             ))



/*----------------------------------------------------------------*\
*		 Address Macros			
\*----------------------------------------------------------------*/

/*--------------------- Register: PGPIOEN0 -----------------------*/
#define _GPIO_PGPIOEN0_ADDR		(0x4400u)
#define _GPIO_PGPIOEN0			PREG16(_GPIO_PGPIOEN0_ADDR)
#define PGPIOEN0			_GPIO_PGPIOEN0


/*--------------------- Register: PGPIODIR0 -----------------------*/
#define _GPIO_PGPIODIR0_ADDR		(0x4401u)
#define _GPIO_PGPIODIR0			PREG16(_GPIO_PGPIODIR0_ADDR)
#define PGPIODIR0			_GPIO_PGPIODIR0


/*--------------------- Register: PGPIODAT0 -----------------------*/
#define _GPIO_PGPIODAT0_ADDR		(0x4402u)
#define _GPIO_PGPIODAT0			PREG16(_GPIO_PGPIODAT0_ADDR)
#define PGPIODAT0			_GPIO_PGPIODAT0


/*--------------------- Register: PGPIOEN1 -----------------------*/
#define _GPIO_PGPIOEN1_ADDR		(0x4403u)
#define _GPIO_PGPIOEN1			PREG16(_GPIO_PGPIOEN1_ADDR)
#define PGPIOEN1			_GPIO_PGPIOEN1


/*--------------------- Register: PGPIODIR1 -----------------------*/
#define _GPIO_PGPIODIR1_ADDR		(0x4404u)
#define _GPIO_PGPIODIR1			PREG16(_GPIO_PGPIODIR1_ADDR)
#define PGPIODIR1			_GPIO_PGPIODIR1


/*--------------------- Register: PGPIODAT1 -----------------------*/
#define _GPIO_PGPIODAT1_ADDR		(0x4405u)
#define _GPIO_PGPIODAT1			PREG16(_GPIO_PGPIODAT1_ADDR)
#define PGPIODAT1			_GPIO_PGPIODAT1


/*--------------------- Register: PGPIOEN2 -----------------------*/
#define _GPIO_PGPIOEN2_ADDR		(0x4406u)
#define _GPIO_PGPIOEN2			PREG16(_GPIO_PGPIOEN2_ADDR)
#define PGPIOEN2			_GPIO_PGPIOEN2


/*--------------------- Register: PGPIODIR2 -----------------------*/
#define _GPIO_PGPIODIR2_ADDR		(0x4407u)
#define _GPIO_PGPIODIR2			PREG16(_GPIO_PGPIODIR2_ADDR)
#define PGPIODIR2			_GPIO_PGPIODIR2


/*--------------------- Register: PGPIODAT2 -----------------------*/
#define _GPIO_PGPIODAT2_ADDR		(0x4408u)
#define _GPIO_PGPIODAT2			PREG16(_GPIO_PGPIODAT2_ADDR)
#define PGPIODAT2			_GPIO_PGPIODAT2



/*----------------------------------------------------------------*\
*		 Register Macros		
\*----------------------------------------------------------------*/

/*--------------------- Register: PGPIOEN0 -----------------------*/
#define _GPIO_PGPIOEN0_GET		  _PREG_GET(_GPIO_PGPIOEN0_ADDR) 
#define _GPIO_PGPIOEN0_SET(Val)		  _PREG_SET(_GPIO_PGPIOEN0_ADDR,Val)
#define _GPIO_PGPIOEN0_FGET(Field)	  _PFIELD_GET(_GPIO_PGPIOEN0_ADDR, _GPIO_PGPIOEN0_##Field)
#define _GPIO_PGPIOEN0_FSET(Field,Val)	  _PFIELD_SET(_GPIO_PGPIOEN0_ADDR, _GPIO_PGPIOEN0_##Field, Val)
#define _GPIO_PGPIOEN0_AOI(AND,OR,INV)	  _PREG_AOI(_GPIO_PGPIOEN0_ADDR,AND,OR,INV)
#define _GPIO_PGPIOEN0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPIO_PGPIOEN0_ADDR, _GPIO_PGPIOEN0_##Field,AND,OR,INV)


/*--------------------- Register: PGPIODIR0 -----------------------*/
#define _GPIO_PGPIODIR0_GET		  _PREG_GET(_GPIO_PGPIODIR0_ADDR) 
#define _GPIO_PGPIODIR0_SET(Val)		  _PREG_SET(_GPIO_PGPIODIR0_ADDR,Val)
#define _GPIO_PGPIODIR0_FGET(Field)	  _PFIELD_GET(_GPIO_PGPIODIR0_ADDR, _GPIO_PGPIODIR0_##Field)
#define _GPIO_PGPIODIR0_FSET(Field,Val)	  _PFIELD_SET(_GPIO_PGPIODIR0_ADDR, _GPIO_PGPIODIR0_##Field, Val)
#define _GPIO_PGPIODIR0_AOI(AND,OR,INV)	  _PREG_AOI(_GPIO_PGPIODIR0_ADDR,AND,OR,INV)
#define _GPIO_PGPIODIR0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPIO_PGPIODIR0_ADDR, _GPIO_PGPIODIR0_##Field,AND,OR,INV)


/*--------------------- Register: PGPIODAT0 -----------------------*/
#define _GPIO_PGPIODAT0_GET		  _PREG_GET(_GPIO_PGPIODAT0_ADDR) 
#define _GPIO_PGPIODAT0_SET(Val)		  _PREG_SET(_GPIO_PGPIODAT0_ADDR,Val)
#define _GPIO_PGPIODAT0_FGET(Field)	  _PFIELD_GET(_GPIO_PGPIODAT0_ADDR, _GPIO_PGPIODAT0_##Field)
#define _GPIO_PGPIODAT0_FSET(Field,Val)	  _PFIELD_SET(_GPIO_PGPIODAT0_ADDR, _GPIO_PGPIODAT0_##Field, Val)
#define _GPIO_PGPIODAT0_AOI(AND,OR,INV)	  _PREG_AOI(_GPIO_PGPIODAT0_ADDR,AND,OR,INV)
#define _GPIO_PGPIODAT0_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPIO_PGPIODAT0_ADDR, _GPIO_PGPIODAT0_##Field,AND,OR,INV)


/*--------------------- Register: PGPIOEN1 -----------------------*/
#define _GPIO_PGPIOEN1_GET		  _PREG_GET(_GPIO_PGPIOEN1_ADDR) 
#define _GPIO_PGPIOEN1_SET(Val)		  _PREG_SET(_GPIO_PGPIOEN1_ADDR,Val)
#define _GPIO_PGPIOEN1_FGET(Field)	  _PFIELD_GET(_GPIO_PGPIOEN1_ADDR, _GPIO_PGPIOEN1_##Field)
#define _GPIO_PGPIOEN1_FSET(Field,Val)	  _PFIELD_SET(_GPIO_PGPIOEN1_ADDR, _GPIO_PGPIOEN1_##Field, Val)
#define _GPIO_PGPIOEN1_AOI(AND,OR,INV)	  _PREG_AOI(_GPIO_PGPIOEN1_ADDR,AND,OR,INV)
#define _GPIO_PGPIOEN1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPIO_PGPIOEN1_ADDR, _GPIO_PGPIOEN1_##Field,AND,OR,INV)


/*--------------------- Register: PGPIODIR1 -----------------------*/
#define _GPIO_PGPIODIR1_GET		  _PREG_GET(_GPIO_PGPIODIR1_ADDR) 
#define _GPIO_PGPIODIR1_SET(Val)		  _PREG_SET(_GPIO_PGPIODIR1_ADDR,Val)
#define _GPIO_PGPIODIR1_FGET(Field)	  _PFIELD_GET(_GPIO_PGPIODIR1_ADDR, _GPIO_PGPIODIR1_##Field)
#define _GPIO_PGPIODIR1_FSET(Field,Val)	  _PFIELD_SET(_GPIO_PGPIODIR1_ADDR, _GPIO_PGPIODIR1_##Field, Val)
#define _GPIO_PGPIODIR1_AOI(AND,OR,INV)	  _PREG_AOI(_GPIO_PGPIODIR1_ADDR,AND,OR,INV)
#define _GPIO_PGPIODIR1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPIO_PGPIODIR1_ADDR, _GPIO_PGPIODIR1_##Field,AND,OR,INV)


/*--------------------- Register: PGPIODAT1 -----------------------*/
#define _GPIO_PGPIODAT1_GET		  _PREG_GET(_GPIO_PGPIODAT1_ADDR) 
#define _GPIO_PGPIODAT1_SET(Val)		  _PREG_SET(_GPIO_PGPIODAT1_ADDR,Val)
#define _GPIO_PGPIODAT1_FGET(Field)	  _PFIELD_GET(_GPIO_PGPIODAT1_ADDR, _GPIO_PGPIODAT1_##Field)
#define _GPIO_PGPIODAT1_FSET(Field,Val)	  _PFIELD_SET(_GPIO_PGPIODAT1_ADDR, _GPIO_PGPIODAT1_##Field, Val)
#define _GPIO_PGPIODAT1_AOI(AND,OR,INV)	  _PREG_AOI(_GPIO_PGPIODAT1_ADDR,AND,OR,INV)
#define _GPIO_PGPIODAT1_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPIO_PGPIODAT1_ADDR, _GPIO_PGPIODAT1_##Field,AND,OR,INV)


/*--------------------- Register: PGPIOEN2 -----------------------*/
#define _GPIO_PGPIOEN2_GET		  _PREG_GET(_GPIO_PGPIOEN2_ADDR) 
#define _GPIO_PGPIOEN2_SET(Val)		  _PREG_SET(_GPIO_PGPIOEN2_ADDR,Val)
#define _GPIO_PGPIOEN2_FGET(Field)	  _PFIELD_GET(_GPIO_PGPIOEN2_ADDR, _GPIO_PGPIOEN2_##Field)
#define _GPIO_PGPIOEN2_FSET(Field,Val)	  _PFIELD_SET(_GPIO_PGPIOEN1_ADDR, _GPIO_PGPIOEN2_##Field, Val)
#define _GPIO_PGPIOEN2_AOI(AND,OR,INV)	  _PREG_AOI(_GPIO_PGPIOEN2_ADDR,AND,OR,INV)
#define _GPIO_PGPIOEN2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPIO_PGPIOEN2_ADDR, _GPIO_PGPIOEN2_##Field,AND,OR,INV)


/*--------------------- Register: PGPIODIR2 -----------------------*/
#define _GPIO_PGPIODIR2_GET		  _PREG_GET(_GPIO_PGPIODIR2_ADDR) 
#define _GPIO_PGPIODIR2_SET(Val)		  _PREG_SET(_GPIO_PGPIODIR2_ADDR,Val)
#define _GPIO_PGPIODIR2_FGET(Field)	  _PFIELD_GET(_GPIO_PGPIODIR2_ADDR, _GPIO_PGPIODIR2_##Field)
#define _GPIO_PGPIODIR2_FSET(Field,Val)	  _PFIELD_SET(_GPIO_PGPIODIR2_ADDR, _GPIO_PGPIODIR2_##Field, Val)
#define _GPIO_PGPIODIR2_AOI(AND,OR,INV)	  _PREG_AOI(_GPIO_PGPIODIR2_ADDR,AND,OR,INV)
#define _GPIO_PGPIODIR2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPIO_PGPIODIR2_ADDR, _GPIO_PGPIODIR2_##Field,AND,OR,INV)


/*--------------------- Register: PGPIODAT2 -----------------------*/
#define _GPIO_PGPIODAT2_GET		  _PREG_GET(_GPIO_PGPIODAT2_ADDR) 
#define _GPIO_PGPIODAT2_SET(Val)		  _PREG_SET(_GPIO_PGPIODAT2_ADDR,Val)
#define _GPIO_PGPIODAT2_FGET(Field)	  _PFIELD_GET(_GPIO_PGPIODAT2_ADDR, _GPIO_PGPIODAT2_##Field)
#define _GPIO_PGPIODAT2_FSET(Field,Val)	  _PFIELD_SET(_GPIO_PGPIODAT2_ADDR, _GPIO_PGPIODAT2_##Field, Val)
#define _GPIO_PGPIODAT2_AOI(AND,OR,INV)	  _PREG_AOI(_GPIO_PGPIODAT2_ADDR,AND,OR,INV)
#define _GPIO_PGPIODAT2_FAOI(Field,AND,OR,INV)\
	_PFIELD_AOI(_GPIO_PGPIODAT2_ADDR, _GPIO_PGPIODAT2_##Field,AND,OR,INV)



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the PGPIOEN1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPIO_PGPIOEN2	 - Note: Add description here
*
* Fields:
*	(RW)   _GPIO_PGPIOEN2_IO32EN	
*	(RW)   _GPIO_PGPIOEN2_IO33EN	
*	(RW)   _GPIO_PGPIOEN2_IO34EN	
*	(RW)   _GPIO_PGPIOEN2_IO35EN	
*	(RW)   _GPIO_PGPIOEN2_IO36EN	
*	(RW)   _GPIO_PGPIOEN2_IO37EN	
*	(RW)   _GPIO_PGPIOEN2_IO38EN	
*	(RW)   _GPIO_PGPIOEN2_IO39EN	
*	(RW)   _GPIO_PGPIOEN2_IO40EN	
*	(RW)   _GPIO_PGPIOEN2_IO41EN	
*	(RW)   _GPIO_PGPIOEN2_IO42EN	
*	(RW)   _GPIO_PGPIOEN2_IO43EN	
*	(RW)   _GPIO_PGPIOEN2_IO44EN	
*	(RW)   _GPIO_PGPIOEN2_IO45EN	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN2_IO32EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN2_IO32EN_SHIFT		(000000u)
#define _GPIO_PGPIOEN2_IO32EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN2_IO32EN_SHIFT)
#define _GPIO_PGPIOEN2_IO32EN_MASK		(_GPIO_PGPIOEN2_IO32EN_MK(0x0001u))
#define _GPIO_PGPIOEN2_IO32EN_CLR		(~(_GPIO_PGPIOEN2_IO32EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN2_IO33EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN2_IO33EN_SHIFT		(0x0001u)
#define _GPIO_PGPIOEN2_IO33EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN2_IO33EN_SHIFT)
#define _GPIO_PGPIOEN2_IO33EN_MASK		(_GPIO_PGPIOEN2_IO33EN_MK(0x0001u))
#define _GPIO_PGPIOEN2_IO33EN_CLR		(~(_GPIO_PGPIOEN2_IO33EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN2_IO34EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN2_IO34EN_SHIFT		(0x0002u)
#define _GPIO_PGPIOEN2_IO34EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN2_IO34EN_SHIFT)
#define _GPIO_PGPIOEN2_IO34EN_MASK		(_GPIO_PGPIOEN2_IO34EN_MK(0x0001u))
#define _GPIO_PGPIOEN2_IO34EN_CLR		(~(_GPIO_PGPIOEN2_IO34EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN2_IO35EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN2_IO35EN_SHIFT		(0x0003u)
#define _GPIO_PGPIOEN2_IO35EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN2_IO35EN_SHIFT)
#define _GPIO_PGPIOEN2_IO35EN_MASK		(_GPIO_PGPIOEN2_IO35EN_MK(0x0001u))
#define _GPIO_PGPIOEN2_IO35EN_CLR		(~(_GPIO_PGPIOEN2_IO35EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN2_IO36EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN2_IO36EN_SHIFT		(0x0004u)
#define _GPIO_PGPIOEN2_IO36EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN2_IO36EN_SHIFT)
#define _GPIO_PGPIOEN2_IO36EN_MASK		(_GPIO_PGPIOEN2_IO36EN_MK(0x0001u))
#define _GPIO_PGPIOEN2_IO36EN_CLR		(~(_GPIO_PGPIOEN2_IO36EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN2_IO37EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN2_IO37EN_SHIFT		(0x0005u)
#define _GPIO_PGPIOEN2_IO37EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN2_IO37EN_SHIFT)
#define _GPIO_PGPIOEN2_IO37EN_MASK		(_GPIO_PGPIOEN2_IO37EN_MK(0x0001u))
#define _GPIO_PGPIOEN2_IO37EN_CLR		(~(_GPIO_PGPIOEN2_IO37EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN2_IO38EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN2_IO38EN_SHIFT		(0x0006u)
#define _GPIO_PGPIOEN2_IO38EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN2_IO38EN_SHIFT)
#define _GPIO_PGPIOEN2_IO38EN_MASK		(_GPIO_PGPIOEN2_IO38EN_MK(0x0001u))
#define _GPIO_PGPIOEN2_IO38EN_CLR		(~(_GPIO_PGPIOEN2_IO38EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN2_IO39EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN2_IO39EN_SHIFT		(0x0007u)
#define _GPIO_PGPIOEN2_IO39EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN2_IO39EN_SHIFT)
#define _GPIO_PGPIOEN2_IO39EN_MASK		(_GPIO_PGPIOEN2_IO39EN_MK(0x0001u))
#define _GPIO_PGPIOEN2_IO39EN_CLR		(~(_GPIO_PGPIOEN2_IO39EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN2_IO40EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN2_IO40EN_SHIFT		(0x0008u)
#define _GPIO_PGPIOEN2_IO40EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN2_IO40EN_SHIFT)
#define _GPIO_PGPIOEN2_IO40EN_MASK		(_GPIO_PGPIOEN2_IO40EN_MK(0x0001u))
#define _GPIO_PGPIOEN2_IO40EN_CLR		(~(_GPIO_PGPIOEN2_IO40EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN2_IO41EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN2_IO41EN_SHIFT		(0x0009u)
#define _GPIO_PGPIOEN2_IO41EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN2_IO41EN_SHIFT)
#define _GPIO_PGPIOEN2_IO41EN_MASK		(_GPIO_PGPIOEN2_IO41EN_MK(0x0001u))
#define _GPIO_PGPIOEN2_IO41EN_CLR		(~(_GPIO_PGPIOEN2_IO41EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN2_IO42EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN2_IO42EN_SHIFT		(0x000au)
#define _GPIO_PGPIOEN2_IO42EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN2_IO42EN_SHIFT)
#define _GPIO_PGPIOEN2_IO42EN_MASK		(_GPIO_PGPIOEN2_IO42EN_MK(0x0001u))
#define _GPIO_PGPIOEN2_IO42EN_CLR		(~(_GPIO_PGPIOEN2_IO42EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN2_IO43EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN2_IO43EN_SHIFT		(0x000bu)
#define _GPIO_PGPIOEN2_IO43EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN2_IO43EN_SHIFT)
#define _GPIO_PGPIOEN2_IO43EN_MASK		(_GPIO_PGPIOEN2_IO43EN_MK(0x0001u))
#define _GPIO_PGPIOEN2_IO43EN_CLR		(~(_GPIO_PGPIOEN2_IO43EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN2_IO44EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN2_IO44EN_SHIFT		(0x000cu)
#define _GPIO_PGPIOEN2_IO44EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN2_IO44EN_SHIFT)
#define _GPIO_PGPIOEN2_IO44EN_MASK		(_GPIO_PGPIOEN2_IO44EN_MK(0x0001u))
#define _GPIO_PGPIOEN2_IO44EN_CLR		(~(_GPIO_PGPIOEN2_IO44EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN2_IO45EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN2_IO45EN_SHIFT		(0x000du)
#define _GPIO_PGPIOEN2_IO45EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN2_IO45EN_SHIFT)
#define _GPIO_PGPIOEN2_IO45EN_MASK		(_GPIO_PGPIOEN2_IO45EN_MK(0x0001u))
#define _GPIO_PGPIOEN2_IO45EN_CLR		(~(_GPIO_PGPIOEN2_IO45EN_MASK))


/******************************************************************************\
* 
* _GPIO_PGPIOEN1	 - Note: Add description here
*
* Fields:
*	(RW)   _GPIO_PGPIOEN1_IO16EN	
*	(RW)   _GPIO_PGPIOEN1_IO17EN	
*	(RW)   _GPIO_PGPIOEN1_IO18EN	
*	(RW)   _GPIO_PGPIOEN1_IO19EN	
*	(RW)   _GPIO_PGPIOEN1_IO20EN	
*	(RW)   _GPIO_PGPIOEN1_IO21EN	
*	(RW)   _GPIO_PGPIOEN1_IO22EN	
*	(RW)   _GPIO_PGPIOEN1_IO23EN	
*	(RW)   _GPIO_PGPIOEN1_IO24EN	
*	(RW)   _GPIO_PGPIOEN1_IO25EN	
*	(RW)   _GPIO_PGPIOEN1_IO26EN	
*	(RW)   _GPIO_PGPIOEN1_IO27EN	
*	(RW)   _GPIO_PGPIOEN1_IO28EN	
*	(RW)   _GPIO_PGPIOEN1_IO29EN	
*     (RW)   _GPIO_PGPIOEN1_IO30EN
*     (RW)   _GPIO_PGPIOEN1_IO31EN
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN1_IO16EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN1_IO16EN_SHIFT		(000000u)
#define _GPIO_PGPIOEN1_IO16EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN1_IO16EN_SHIFT)
#define _GPIO_PGPIOEN1_IO16EN_MASK		(_GPIO_PGPIOEN1_IO16EN_MK(0x0001u))
#define _GPIO_PGPIOEN1_IO16EN_CLR		(~(_GPIO_PGPIOEN1_IO16EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN1_IO17EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN1_IO17EN_SHIFT		(0x0001u)
#define _GPIO_PGPIOEN1_IO17EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN1_IO17EN_SHIFT)
#define _GPIO_PGPIOEN1_IO17EN_MASK		(_GPIO_PGPIOEN1_IO17EN_MK(0x0001u))
#define _GPIO_PGPIOEN1_IO17EN_CLR		(~(_GPIO_PGPIOEN1_IO17EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN1_IO18EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN1_IO18EN_SHIFT		(0x0002u)
#define _GPIO_PGPIOEN1_IO18EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN1_IO18EN_SHIFT)
#define _GPIO_PGPIOEN1_IO18EN_MASK		(_GPIO_PGPIOEN1_IO18EN_MK(0x0001u))
#define _GPIO_PGPIOEN1_IO18EN_CLR		(~(_GPIO_PGPIOEN1_IO18EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN1_IO19EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN1_IO19EN_SHIFT		(0x0003u)
#define _GPIO_PGPIOEN1_IO19EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN1_IO19EN_SHIFT)
#define _GPIO_PGPIOEN1_IO19EN_MASK		(_GPIO_PGPIOEN1_IO19EN_MK(0x0001u))
#define _GPIO_PGPIOEN1_IO19EN_CLR		(~(_GPIO_PGPIOEN1_IO19EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN1_IO20EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN1_IO20EN_SHIFT		(0x0004u)
#define _GPIO_PGPIOEN1_IO20EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN1_IO20EN_SHIFT)
#define _GPIO_PGPIOEN1_IO20EN_MASK		(_GPIO_PGPIOEN1_IO20EN_MK(0x0001u))
#define _GPIO_PGPIOEN1_IO20EN_CLR		(~(_GPIO_PGPIOEN1_IO20EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN1_IO21EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN1_IO21EN_SHIFT		(0x0005u)
#define _GPIO_PGPIOEN1_IO21EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN1_IO21EN_SHIFT)
#define _GPIO_PGPIOEN1_IO21EN_MASK		(_GPIO_PGPIOEN1_IO21EN_MK(0x0001u))
#define _GPIO_PGPIOEN1_IO21EN_CLR		(~(_GPIO_PGPIOEN1_IO21EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN1_IO22EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN1_IO22EN_SHIFT		(0x0006u)
#define _GPIO_PGPIOEN1_IO22EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN1_IO22EN_SHIFT)
#define _GPIO_PGPIOEN1_IO22EN_MASK		(_GPIO_PGPIOEN1_IO22EN_MK(0x0001u))
#define _GPIO_PGPIOEN1_IO22EN_CLR		(~(_GPIO_PGPIOEN1_IO22EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN1_IO23EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN1_IO23EN_SHIFT		(0x0007u)
#define _GPIO_PGPIOEN1_IO23EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN1_IO23EN_SHIFT)
#define _GPIO_PGPIOEN1_IO23EN_MASK		(_GPIO_PGPIOEN1_IO23EN_MK(0x0001u))
#define _GPIO_PGPIOEN1_IO23EN_CLR		(~(_GPIO_PGPIOEN1_IO23EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN1_IO24EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN1_IO24EN_SHIFT		(0x0008u)
#define _GPIO_PGPIOEN1_IO24EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN1_IO24EN_SHIFT)
#define _GPIO_PGPIOEN1_IO24EN_MASK		(_GPIO_PGPIOEN1_IO24EN_MK(0x0001u))
#define _GPIO_PGPIOEN1_IO24EN_CLR		(~(_GPIO_PGPIOEN1_IO24EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN1_IO25EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN1_IO25EN_SHIFT		(0x0009u)
#define _GPIO_PGPIOEN1_IO25EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN1_IO25EN_SHIFT)
#define _GPIO_PGPIOEN1_IO25EN_MASK		(_GPIO_PGPIOEN1_IO25EN_MK(0x0001u))
#define _GPIO_PGPIOEN1_IO25EN_CLR		(~(_GPIO_PGPIOEN1_IO25EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN1_IO26EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN1_IO26EN_SHIFT		(0x000au)
#define _GPIO_PGPIOEN1_IO26EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN1_IO26EN_SHIFT)
#define _GPIO_PGPIOEN1_IO26EN_MASK		(_GPIO_PGPIOEN1_IO26EN_MK(0x0001u))
#define _GPIO_PGPIOEN1_IO26EN_CLR		(~(_GPIO_PGPIOEN1_IO26EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN1_IO27EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN1_IO27EN_SHIFT		(0x000bu)
#define _GPIO_PGPIOEN1_IO27EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN1_IO27EN_SHIFT)
#define _GPIO_PGPIOEN1_IO27EN_MASK		(_GPIO_PGPIOEN1_IO27EN_MK(0x0001u))
#define _GPIO_PGPIOEN1_IO27EN_CLR		(~(_GPIO_PGPIOEN1_IO27EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN1_IO28EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN1_IO28EN_SHIFT		(0x000cu)
#define _GPIO_PGPIOEN1_IO28EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN1_IO28EN_SHIFT)
#define _GPIO_PGPIOEN1_IO28EN_MASK		(_GPIO_PGPIOEN1_IO28EN_MK(0x0001u))
#define _GPIO_PGPIOEN1_IO28EN_CLR		(~(_GPIO_PGPIOEN1_IO28EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN1_IO29EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN1_IO29EN_SHIFT		(0x000du)
#define _GPIO_PGPIOEN1_IO29EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN1_IO29EN_SHIFT)
#define _GPIO_PGPIOEN1_IO29EN_MASK		(_GPIO_PGPIOEN1_IO29EN_MK(0x0001u))
#define _GPIO_PGPIOEN1_IO29EN_CLR		(~(_GPIO_PGPIOEN1_IO29EN_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN1_IO30EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN1_IO30EN_SHIFT		(0x000eu)
#define _GPIO_PGPIOEN1_IO30EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN1_IO30EN_SHIFT)
#define _GPIO_PGPIOEN1_IO30EN_MASK		(_GPIO_PGPIOEN1_IO30EN_MK(0x0001u))
#define _GPIO_PGPIOEN1_IO30EN_CLR		(~(_GPIO_PGPIOEN1_IO30EN_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN1_IO31EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN1_IO31EN_SHIFT		(0x000fu)
#define _GPIO_PGPIOEN1_IO31EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN1_IO31EN_SHIFT)
#define _GPIO_PGPIOEN1_IO31EN_MASK		(_GPIO_PGPIOEN1_IO31EN_MK(0x0001u))
#define _GPIO_PGPIOEN1_IO31EN_CLR		(~(_GPIO_PGPIOEN1_IO31EN_MASK))

/******************************************************************************\
* 
* _GPIO_PGPIOEN0	 - Note: Add description here
*
* Fields:
*	(RW)   _GPIO_PGPIOEN0_IO16EN	
*	(RW)   _GPIO_PGPIOEN0_IO1EN	
*	(RW)   _GPIO_PGPIOEN0_IO2EN	
*	(RW)   _GPIO_PGPIOEN0_IO3EN	
*	(RW)   _GPIO_PGPIOEN0_IO4EN	
*	(RW)   _GPIO_PGPIOEN0_IO5EN	
*	(RW)   _GPIO_PGPIOEN0_IO6EN	
*	(RW)   _GPIO_PGPIOEN0_IO7EN	
*	(RW)   _GPIO_PGPIOEN0_IO8EN	
*	(RW)   _GPIO_PGPIOEN0_IO9EN	
*	(RW)   _GPIO_PGPIOEN0_IO10EN	
*	(RW)   _GPIO_PGPIOEN0_IO11EN	
*	(RW)   _GPIO_PGPIOEN0_IO12EN	
*	(RW)   _GPIO_PGPIOEN0_IO13EN	
*     (RW)   _GPIO_PGPIOEN0_IO14EN
*     (RW)   _GPIO_PGPIOEN0_IO15EN
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN0_IO0EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN0_IO0EN_SHIFT		(000000u)
#define _GPIO_PGPIOEN0_IO0EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN0_IO0EN_SHIFT)
#define _GPIO_PGPIOEN0_IO0EN_MASK		(_GPIO_PGPIOEN0_IO0EN_MK(0x0001u))
#define _GPIO_PGPIOEN0_IO0EN_CLR		(~(_GPIO_PGPIOEN0_IO0EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN0_IO1EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN0_IO1EN_SHIFT		(0x0001u)
#define _GPIO_PGPIOEN0_IO1EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN0_IO1EN_SHIFT)
#define _GPIO_PGPIOEN0_IO1EN_MASK		(_GPIO_PGPIOEN0_IO1EN_MK(0x0001u))
#define _GPIO_PGPIOEN0_IO1EN_CLR		(~(_GPIO_PGPIOEN0_IO1EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN0_IO2EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN0_IO2EN_SHIFT		(0x0002u)
#define _GPIO_PGPIOEN0_IO2EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN0_IO2EN_SHIFT)
#define _GPIO_PGPIOEN0_IO2EN_MASK		(_GPIO_PGPIOEN0_IO2EN_MK(0x0001u))
#define _GPIO_PGPIOEN0_IO2EN_CLR		(~(_GPIO_PGPIOEN0_IO2EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN0_IO3EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN0_IO3EN_SHIFT		(0x0003u)
#define _GPIO_PGPIOEN0_IO3EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN0_IO3EN_SHIFT)
#define _GPIO_PGPIOEN0_IO3EN_MASK		(_GPIO_PGPIOEN0_IO3EN_MK(0x0001u))
#define _GPIO_PGPIOEN0_IO3EN_CLR		(~(_GPIO_PGPIOEN0_IO3EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN0_IO4EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN0_IO4EN_SHIFT		(0x0004u)
#define _GPIO_PGPIOEN0_IO4EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN0_IO4EN_SHIFT)
#define _GPIO_PGPIOEN0_IO4EN_MASK		(_GPIO_PGPIOEN0_IO4EN_MK(0x0001u))
#define _GPIO_PGPIOEN0_IO4EN_CLR		(~(_GPIO_PGPIOEN0_IO4EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN0_IO5EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN0_IO5EN_SHIFT		(0x0005u)
#define _GPIO_PGPIOEN0_IO5EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN0_IO5EN_SHIFT)
#define _GPIO_PGPIOEN0_IO5EN_MASK		(_GPIO_PGPIOEN0_IO5EN_MK(0x0001u))
#define _GPIO_PGPIOEN0_IO5EN_CLR		(~(_GPIO_PGPIOEN0_IO5EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN0_IO6EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN0_IO6EN_SHIFT		(0x0006u)
#define _GPIO_PGPIOEN0_IO6EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN0_IO6EN_SHIFT)
#define _GPIO_PGPIOEN0_IO6EN_MASK		(_GPIO_PGPIOEN0_IO6EN_MK(0x0001u))
#define _GPIO_PGPIOEN0_IO6EN_CLR		(~(_GPIO_PGPIOEN0_IO6EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN0_IO7EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN0_IO7EN_SHIFT		(0x0007u)
#define _GPIO_PGPIOEN0_IO7EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN0_IO7EN_SHIFT)
#define _GPIO_PGPIOEN0_IO7EN_MASK		(_GPIO_PGPIOEN0_IO7EN_MK(0x0001u))
#define _GPIO_PGPIOEN0_IO7EN_CLR		(~(_GPIO_PGPIOEN0_IO7EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN0_IO8EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN0_IO8EN_SHIFT		(0x0008u)
#define _GPIO_PGPIOEN0_IO8EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN0_IO8EN_SHIFT)
#define _GPIO_PGPIOEN0_IO8EN_MASK		(_GPIO_PGPIOEN0_IO8EN_MK(0x0001u))
#define _GPIO_PGPIOEN0_IO8EN_CLR		(~(_GPIO_PGPIOEN0_IO8EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN0_IO9EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN0_IO9EN_SHIFT		(0x0009u)
#define _GPIO_PGPIOEN0_IO9EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN0_IO9EN_SHIFT)
#define _GPIO_PGPIOEN0_IO9EN_MASK		(_GPIO_PGPIOEN0_IO9EN_MK(0x0001u))
#define _GPIO_PGPIOEN0_IO9EN_CLR		(~(_GPIO_PGPIOEN0_IO9EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN0_IO10EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN0_IO10EN_SHIFT		(0x000au)
#define _GPIO_PGPIOEN0_IO10EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN0_IO10EN_SHIFT)
#define _GPIO_PGPIOEN0_IO10EN_MASK		(_GPIO_PGPIOEN0_IO10EN_MK(0x0001u))
#define _GPIO_PGPIOEN0_IO10EN_CLR		(~(_GPIO_PGPIOEN0_IO10EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN0_IO11EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN0_IO11EN_SHIFT		(0x000bu)
#define _GPIO_PGPIOEN0_IO11EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN0_IO11EN_SHIFT)
#define _GPIO_PGPIOEN0_IO11EN_MASK		(_GPIO_PGPIOEN0_IO11EN_MK(0x0001u))
#define _GPIO_PGPIOEN0_IO11EN_CLR		(~(_GPIO_PGPIOEN0_IO11EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN0_IO12EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN0_IO12EN_SHIFT		(0x000cu)
#define _GPIO_PGPIOEN0_IO12EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN0_IO12EN_SHIFT)
#define _GPIO_PGPIOEN0_IO12EN_MASK		(_GPIO_PGPIOEN0_IO12EN_MK(0x0001u))
#define _GPIO_PGPIOEN0_IO12EN_CLR		(~(_GPIO_PGPIOEN0_IO12EN_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN0_IO13EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN0_IO13EN_SHIFT		(0x000du)
#define _GPIO_PGPIOEN0_IO13EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN0_IO13EN_SHIFT)
#define _GPIO_PGPIOEN0_IO13EN_MASK		(_GPIO_PGPIOEN0_IO13EN_MK(0x0001u))
#define _GPIO_PGPIOEN0_IO13EN_CLR		(~(_GPIO_PGPIOEN0_IO13EN_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN0_IO14EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN0_IO14EN_SHIFT		(0x000eu)
#define _GPIO_PGPIOEN0_IO14EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN0_IO14EN_SHIFT)
#define _GPIO_PGPIOEN0_IO14EN_MASK		(_GPIO_PGPIOEN0_IO14EN_MK(0x0001u))
#define _GPIO_PGPIOEN0_IO14EN_CLR		(~(_GPIO_PGPIOEN0_IO14EN_MASK))

/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIOEN0_IO15EN:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIOEN0_IO15EN_SHIFT		(0x000fu)
#define _GPIO_PGPIOEN0_IO15EN_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIOEN0_IO15EN_SHIFT)
#define _GPIO_PGPIOEN0_IO15EN_MASK		(_GPIO_PGPIOEN0_IO15EN_MK(0x0001u))
#define _GPIO_PGPIOEN0_IO15EN_CLR		(~(_GPIO_PGPIOEN0_IO15EN_MASK))





/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the PGPIODAT0 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPIO_PGPIODAT0	 - Note: Add description here
*
* Fields:
*	(RW)   _GPIO_PGPIODAT0_IO0DAT	
*	(RW)   _GPIO_PGPIODAT0_IO1DAT	
*	(RW)   _GPIO_PGPIODAT0_IO2DAT	
*	(RW)   _GPIO_PGPIODAT0_IO3DAT	
*	(RW)   _GPIO_PGPIODAT0_IO4DAT	
*	(RW)   _GPIO_PGPIODAT0_IO5DAT	
*	(RW)   _GPIO_PGPIODAT0_IO6DAT	
*	(RW)   _GPIO_PGPIODAT0_IO7DAT	
*	(RW)   _GPIO_PGPIODAT0_IO8DAT	
*	(RW)   _GPIO_PGPIODAT0_IO9DAT	
*	(RW)   _GPIO_PGPIODAT0_IO10DAT	
*	(RW)   _GPIO_PGPIODAT0_IO11DAT	
*	(RW)   _GPIO_PGPIODAT0_IO12DAT	
*	(RW)   _GPIO_PGPIODAT0_IO13DAT	
*	(RW)   _GPIO_PGPIODAT0_IO14DAT	
*	(RW)   _GPIO_PGPIODAT0_IO15DAT	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT0_IO0DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT0_IO0DAT_SHIFT		(000000u)
#define _GPIO_PGPIODAT0_IO0DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT0_IO0DAT_SHIFT)
#define _GPIO_PGPIODAT0_IO0DAT_MASK		(_GPIO_PGPIODAT0_IO0DAT_MK(0x0001u))
#define _GPIO_PGPIODAT0_IO0DAT_CLR		(~(_GPIO_PGPIODAT0_IO0DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT0_IO1DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT0_IO1DAT_SHIFT		(0x0001u)
#define _GPIO_PGPIODAT0_IO1DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT0_IO1DAT_SHIFT)
#define _GPIO_PGPIODAT0_IO1DAT_MASK		(_GPIO_PGPIODAT0_IO1DAT_MK(0x0001u))
#define _GPIO_PGPIODAT0_IO1DAT_CLR		(~(_GPIO_PGPIODAT0_IO1DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT0_IO2DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT0_IO2DAT_SHIFT		(0x0002u)
#define _GPIO_PGPIODAT0_IO2DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT0_IO2DAT_SHIFT)
#define _GPIO_PGPIODAT0_IO2DAT_MASK		(_GPIO_PGPIODAT0_IO2DAT_MK(0x0001u))
#define _GPIO_PGPIODAT0_IO2DAT_CLR		(~(_GPIO_PGPIODAT0_IO2DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT0_IO3DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT0_IO3DAT_SHIFT		(0x0003u)
#define _GPIO_PGPIODAT0_IO3DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT0_IO3DAT_SHIFT)
#define _GPIO_PGPIODAT0_IO3DAT_MASK		(_GPIO_PGPIODAT0_IO3DAT_MK(0x0001u))
#define _GPIO_PGPIODAT0_IO3DAT_CLR		(~(_GPIO_PGPIODAT0_IO3DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT0_IO4DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT0_IO4DAT_SHIFT		(0x0004u)
#define _GPIO_PGPIODAT0_IO4DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT0_IO4DAT_SHIFT)
#define _GPIO_PGPIODAT0_IO4DAT_MASK		(_GPIO_PGPIODAT0_IO4DAT_MK(0x0001u))
#define _GPIO_PGPIODAT0_IO4DAT_CLR		(~(_GPIO_PGPIODAT0_IO4DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT0_IO5DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT0_IO5DAT_SHIFT		(0x0005u)
#define _GPIO_PGPIODAT0_IO5DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT0_IO5DAT_SHIFT)
#define _GPIO_PGPIODAT0_IO5DAT_MASK		(_GPIO_PGPIODAT0_IO5DAT_MK(0x0001u))
#define _GPIO_PGPIODAT0_IO5DAT_CLR		(~(_GPIO_PGPIODAT0_IO5DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT0_IO6DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT0_IO6DAT_SHIFT		(0x0006u)
#define _GPIO_PGPIODAT0_IO6DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT0_IO6DAT_SHIFT)
#define _GPIO_PGPIODAT0_IO6DAT_MASK		(_GPIO_PGPIODAT0_IO6DAT_MK(0x0001u))
#define _GPIO_PGPIODAT0_IO6DAT_CLR		(~(_GPIO_PGPIODAT0_IO6DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT0_IO7DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT0_IO7DAT_SHIFT		(0x0007u)
#define _GPIO_PGPIODAT0_IO7DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT0_IO7DAT_SHIFT)
#define _GPIO_PGPIODAT0_IO7DAT_MASK		(_GPIO_PGPIODAT0_IO7DAT_MK(0x0001u))
#define _GPIO_PGPIODAT0_IO7DAT_CLR		(~(_GPIO_PGPIODAT0_IO7DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT0_IO8DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT0_IO8DAT_SHIFT		(0x0008u)
#define _GPIO_PGPIODAT0_IO8DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT0_IO8DAT_SHIFT)
#define _GPIO_PGPIODAT0_IO8DAT_MASK		(_GPIO_PGPIODAT0_IO8DAT_MK(0x0001u))
#define _GPIO_PGPIODAT0_IO8DAT_CLR		(~(_GPIO_PGPIODAT0_IO8DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT0_IO9DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT0_IO9DAT_SHIFT		(0x0009u)
#define _GPIO_PGPIODAT0_IO9DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT0_IO9DAT_SHIFT)
#define _GPIO_PGPIODAT0_IO9DAT_MASK		(_GPIO_PGPIODAT0_IO9DAT_MK(0x0001u))
#define _GPIO_PGPIODAT0_IO9DAT_CLR		(~(_GPIO_PGPIODAT0_IO9DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT0_IO10DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT0_IO10DAT_SHIFT		(0x000au)
#define _GPIO_PGPIODAT0_IO10DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT0_IO10DAT_SHIFT)
#define _GPIO_PGPIODAT0_IO10DAT_MASK		(_GPIO_PGPIODAT0_IO10DAT_MK(0x0001u))
#define _GPIO_PGPIODAT0_IO10DAT_CLR		(~(_GPIO_PGPIODAT0_IO10DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT0_IO11DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT0_IO11DAT_SHIFT		(0x000bu)
#define _GPIO_PGPIODAT0_IO11DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT0_IO11DAT_SHIFT)
#define _GPIO_PGPIODAT0_IO11DAT_MASK		(_GPIO_PGPIODAT0_IO11DAT_MK(0x0001u))
#define _GPIO_PGPIODAT0_IO11DAT_CLR		(~(_GPIO_PGPIODAT0_IO11DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT0_IO12DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT0_IO12DAT_SHIFT		(0x000cu)
#define _GPIO_PGPIODAT0_IO12DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT0_IO12DAT_SHIFT)
#define _GPIO_PGPIODAT0_IO12DAT_MASK		(_GPIO_PGPIODAT0_IO12DAT_MK(0x0001u))
#define _GPIO_PGPIODAT0_IO12DAT_CLR		(~(_GPIO_PGPIODAT0_IO12DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT0_IO13DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT0_IO13DAT_SHIFT		(0x000du)
#define _GPIO_PGPIODAT0_IO13DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT0_IO13DAT_SHIFT)
#define _GPIO_PGPIODAT0_IO13DAT_MASK		(_GPIO_PGPIODAT0_IO13DAT_MK(0x0001u))
#define _GPIO_PGPIODAT0_IO13DAT_CLR		(~(_GPIO_PGPIODAT0_IO13DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT0_IO14DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT0_IO14DAT_SHIFT		(0x000eu)
#define _GPIO_PGPIODAT0_IO14DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT0_IO14DAT_SHIFT)
#define _GPIO_PGPIODAT0_IO14DAT_MASK		(_GPIO_PGPIODAT0_IO14DAT_MK(0x0001u))
#define _GPIO_PGPIODAT0_IO14DAT_CLR		(~(_GPIO_PGPIODAT0_IO14DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT0_IO15DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT0_IO15DAT_SHIFT		(0x000fu)
#define _GPIO_PGPIODAT0_IO15DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT0_IO15DAT_SHIFT)
#define _GPIO_PGPIODAT0_IO15DAT_MASK		(_GPIO_PGPIODAT0_IO15DAT_MK(0x0001u))
#define _GPIO_PGPIODAT0_IO15DAT_CLR		(~(_GPIO_PGPIODAT0_IO15DAT_MASK))


/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the PGPIODAT1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPIO_PGPIODAT1	 - Note: Add description here
*
* Fields:
*	(RW)   _GPIO_PGPIODAT1_IO16DAT	
*	(RW)   _GPIO_PGPIODAT1_IO1DAT	
*	(RW)   _GPIO_PGPIODAT1_IO18DAT	
*	(RW)   _GPIO_PGPIODAT1_IO19DAT	
*	(RW)   _GPIO_PGPIODAT1_IO20DAT	
*	(RW)   _GPIO_PGPIODAT1_IO5DAT	
*	(RW)   _GPIO_PGPIODAT1_IO22DAT	
*	(RW)   _GPIO_PGPIODAT1_IO23DAT	
*	(RW)   _GPIO_PGPIODAT1_IO24DAT	
*	(RW)   _GPIO_PGPIODAT1_IO25DAT	
*	(RW)   _GPIO_PGPIODAT1_IO26DAT	
*	(RW)   _GPIO_PGPIODAT1_IO27DAT	
*	(RW)   _GPIO_PGPIODAT1_IO28DAT	
*	(RW)   _GPIO_PGPIODAT1_IO29DAT	
*	(RW)   _GPIO_PGPIODAT1_IO30DAT	
*	(RW)   _GPIO_PGPIODAT1_IO31DAT	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT1_IO16DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT1_IO16DAT_SHIFT		(000000u)
#define _GPIO_PGPIODAT1_IO16DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT1_IO16DAT_SHIFT)
#define _GPIO_PGPIODAT1_IO16DAT_MASK		(_GPIO_PGPIODAT1_IO16DAT_MK(0x0001u))
#define _GPIO_PGPIODAT1_IO16DAT_CLR		(~(_GPIO_PGPIODAT1_IO16DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT1_IO17DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT1_IO17DAT_SHIFT		(0x0001u)
#define _GPIO_PGPIODAT1_IO17DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT1_IO17DAT_SHIFT)
#define _GPIO_PGPIODAT1_IO17DAT_MASK		(_GPIO_PGPIODAT1_IO17DAT_MK(0x0001u))
#define _GPIO_PGPIODAT1_IO17DAT_CLR		(~(_GPIO_PGPIODAT1_IO17DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT1_IO18DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT1_IO18DAT_SHIFT		(0x0002u)
#define _GPIO_PGPIODAT1_IO18DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT1_IO18DAT_SHIFT)
#define _GPIO_PGPIODAT1_IO18DAT_MASK		(_GPIO_PGPIODAT1_IO18DAT_MK(0x0001u))
#define _GPIO_PGPIODAT1_IO18DAT_CLR		(~(_GPIO_PGPIODAT1_IO18DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT1_IO19DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT1_IO19DAT_SHIFT		(0x0003u)
#define _GPIO_PGPIODAT1_IO19DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT1_IO19DAT_SHIFT)
#define _GPIO_PGPIODAT1_IO19DAT_MASK		(_GPIO_PGPIODAT1_IO19DAT_MK(0x0001u))
#define _GPIO_PGPIODAT1_IO19DAT_CLR		(~(_GPIO_PGPIODAT1_IO19DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT1_IO20DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT1_IO20DAT_SHIFT		(0x0004u)
#define _GPIO_PGPIODAT1_IO20DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT1_IO20DAT_SHIFT)
#define _GPIO_PGPIODAT1_IO20DAT_MASK		(_GPIO_PGPIODAT1_IO20DAT_MK(0x0001u))
#define _GPIO_PGPIODAT1_IO20DAT_CLR		(~(_GPIO_PGPIODAT1_IO20DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT1_IO21DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT1_IO21DAT_SHIFT		(0x0005u)
#define _GPIO_PGPIODAT1_IO21DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT1_IO21DAT_SHIFT)
#define _GPIO_PGPIODAT1_IO21DAT_MASK		(_GPIO_PGPIODAT1_IO21DAT_MK(0x0001u))
#define _GPIO_PGPIODAT1_IO21DAT_CLR		(~(_GPIO_PGPIODAT1_IO21DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT1_IO22DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT1_IO22DAT_SHIFT		(0x0006u)
#define _GPIO_PGPIODAT1_IO22DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT1_IO22DAT_SHIFT)
#define _GPIO_PGPIODAT1_IO22DAT_MASK		(_GPIO_PGPIODAT1_IO22DAT_MK(0x0001u))
#define _GPIO_PGPIODAT1_IO22DAT_CLR		(~(_GPIO_PGPIODAT1_IO22DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT1_IO23DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT1_IO23DAT_SHIFT		(0x0007u)
#define _GPIO_PGPIODAT1_IO23DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT1_IO23DAT_SHIFT)
#define _GPIO_PGPIODAT1_IO23DAT_MASK		(_GPIO_PGPIODAT1_IO23DAT_MK(0x0001u))
#define _GPIO_PGPIODAT1_IO23DAT_CLR		(~(_GPIO_PGPIODAT1_IO23DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT1_IO24DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT1_IO24DAT_SHIFT		(0x0008u)
#define _GPIO_PGPIODAT1_IO24DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT1_IO24DAT_SHIFT)
#define _GPIO_PGPIODAT1_IO24DAT_MASK		(_GPIO_PGPIODAT1_IO24DAT_MK(0x0001u))
#define _GPIO_PGPIODAT1_IO24DAT_CLR		(~(_GPIO_PGPIODAT1_IO24DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT1_IO25DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT1_IO25DAT_SHIFT		(0x0009u)
#define _GPIO_PGPIODAT1_IO25DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT1_IO25DAT_SHIFT)
#define _GPIO_PGPIODAT1_IO25DAT_MASK		(_GPIO_PGPIODAT1_IO25DAT_MK(0x0001u))
#define _GPIO_PGPIODAT1_IO25DAT_CLR		(~(_GPIO_PGPIODAT1_IO25DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT1_IO26DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT1_IO26DAT_SHIFT		(0x000au)
#define _GPIO_PGPIODAT1_IO26DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT1_IO26DAT_SHIFT)
#define _GPIO_PGPIODAT1_IO26DAT_MASK		(_GPIO_PGPIODAT1_IO26DAT_MK(0x0001u))
#define _GPIO_PGPIODAT1_IO26DAT_CLR		(~(_GPIO_PGPIODAT1_IO26DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT1_IO27DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT1_IO27DAT_SHIFT		(0x000bu)
#define _GPIO_PGPIODAT1_IO27DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT1_IO27DAT_SHIFT)
#define _GPIO_PGPIODAT1_IO27DAT_MASK		(_GPIO_PGPIODAT1_IO27DAT_MK(0x0001u))
#define _GPIO_PGPIODAT1_IO27DAT_CLR		(~(_GPIO_PGPIODAT1_IO27DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT1_IO28DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT1_IO28DAT_SHIFT		(0x000cu)
#define _GPIO_PGPIODAT1_IO28DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT1_IO28DAT_SHIFT)
#define _GPIO_PGPIODAT1_IO28DAT_MASK		(_GPIO_PGPIODAT1_IO28DAT_MK(0x0001u))
#define _GPIO_PGPIODAT1_IO28DAT_CLR		(~(_GPIO_PGPIODAT1_IO28DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT1_IO29DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT1_IO29DAT_SHIFT		(0x000du)
#define _GPIO_PGPIODAT1_IO29DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT1_IO29DAT_SHIFT)
#define _GPIO_PGPIODAT1_IO29DAT_MASK		(_GPIO_PGPIODAT1_IO29DAT_MK(0x0001u))
#define _GPIO_PGPIODAT1_IO29DAT_CLR		(~(_GPIO_PGPIODAT1_IO29DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT1_IO30DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT1_IO30DAT_SHIFT		(0x000eu)
#define _GPIO_PGPIODAT1_IO30DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT1_IO30DAT_SHIFT)
#define _GPIO_PGPIODAT1_IO30DAT_MASK		(_GPIO_PGPIODAT1_IO30DAT_MK(0x0001u))
#define _GPIO_PGPIODAT1_IO30DAT_CLR		(~(_GPIO_PGPIODAT1_IO30DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT1_IO31DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT1_IO31DAT_SHIFT		(0x000fu)
#define _GPIO_PGPIODAT1_IO31DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT1_IO31DAT_SHIFT)
#define _GPIO_PGPIODAT1_IO31DAT_MASK		(_GPIO_PGPIODAT1_IO31DAT_MK(0x0001u))
#define _GPIO_PGPIODAT1_IO31DAT_CLR		(~(_GPIO_PGPIODAT1_IO31DAT_MASK))




/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the PGPIODAT1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPIO_PGPIODAT1	 - Note: Add description here
*
* Fields:
*	(RW)   _GPIO_PGPIODAT2_IO32DAT	
*	(RW)   _GPIO_PGPIODAT2_IO33DAT	
*	(RW)   _GPIO_PGPIODAT2_IO34DAT	
*	(RW)   _GPIO_PGPIODAT2_IO35DAT	
*	(RW)   _GPIO_PGPIODAT2_IO36DAT	
*	(RW)   _GPIO_PGPIODAT2_IO37DAT	
*	(RW)   _GPIO_PGPIODAT2_IO38DAT	
*	(RW)   _GPIO_PGPIODAT2_IO39DAT	
*	(RW)   _GPIO_PGPIODAT2_IO40DAT	
*	(RW)   _GPIO_PGPIODAT2_IO41DAT	
*	(RW)   _GPIO_PGPIODAT2_IO42DAT	
*	(RW)   _GPIO_PGPIODAT2_IO43DAT	
*	(RW)   _GPIO_PGPIODAT2_IO44DAT	
*	(RW)   _GPIO_PGPIODAT2_IO45DAT	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT2_IO32DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT2_IO32DAT_SHIFT		(000000u)
#define _GPIO_PGPIODAT2_IO32DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT2_IO32DAT_SHIFT)
#define _GPIO_PGPIODAT2_IO32DAT_MASK		(_GPIO_PGPIODAT2_IO32DAT_MK(0x0001u))
#define _GPIO_PGPIODAT2_IO32DAT_CLR		(~(_GPIO_PGPIODAT2_IO32DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT2_IO33DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT2_IO33DAT_SHIFT		(0x0001u)
#define _GPIO_PGPIODAT2_IO33DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT2_IO33DAT_SHIFT)
#define _GPIO_PGPIODAT2_IO33DAT_MASK		(_GPIO_PGPIODAT2_IO33DAT_MK(0x0001u))
#define _GPIO_PGPIODAT2_IO33DAT_CLR		(~(_GPIO_PGPIODAT2_IO33DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT2_IO34DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT2_IO34DAT_SHIFT		(0x0002u)
#define _GPIO_PGPIODAT2_IO34DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT2_IO34DAT_SHIFT)
#define _GPIO_PGPIODAT2_IO34DAT_MASK		(_GPIO_PGPIODAT2_IO34DAT_MK(0x0001u))
#define _GPIO_PGPIODAT2_IO34DAT_CLR		(~(_GPIO_PGPIODAT2_IO34DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT2_IO35DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT2_IO35DAT_SHIFT		(0x0003u)
#define _GPIO_PGPIODAT2_IO35DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT2_IO35DAT_SHIFT)
#define _GPIO_PGPIODAT2_IO35DAT_MASK		(_GPIO_PGPIODAT2_IO35DAT_MK(0x0001u))
#define _GPIO_PGPIODAT2_IO35DAT_CLR		(~(_GPIO_PGPIODAT2_IO35DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT2_IO36DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT2_IO36DAT_SHIFT		(0x0004u)
#define _GPIO_PGPIODAT2_IO36DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT2_IO36DAT_SHIFT)
#define _GPIO_PGPIODAT2_IO36DAT_MASK		(_GPIO_PGPIODAT2_IO36DAT_MK(0x0001u))
#define _GPIO_PGPIODAT2_IO36DAT_CLR		(~(_GPIO_PGPIODAT2_IO36DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT2_IO37DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT2_IO37DAT_SHIFT		(0x0005u)
#define _GPIO_PGPIODAT2_IO37DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT2_IO37DAT_SHIFT)
#define _GPIO_PGPIODAT2_IO37DAT_MASK		(_GPIO_PGPIODAT2_IO37DAT_MK(0x0001u))
#define _GPIO_PGPIODAT2_IO37DAT_CLR		(~(_GPIO_PGPIODAT2_IO37DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT2_IO38DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT2_IO38DAT_SHIFT		(0x0006u)
#define _GPIO_PGPIODAT2_IO38DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT2_IO38DAT_SHIFT)
#define _GPIO_PGPIODAT2_IO38DAT_MASK		(_GPIO_PGPIODAT2_IO38DAT_MK(0x0001u))
#define _GPIO_PGPIODAT2_IO38DAT_CLR		(~(_GPIO_PGPIODAT2_IO38DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT2_IO39DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT2_IO39DAT_SHIFT		(0x0007u)
#define _GPIO_PGPIODAT2_IO39DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT2_IO39DAT_SHIFT)
#define _GPIO_PGPIODAT2_IO39DAT_MASK		(_GPIO_PGPIODAT2_IO39DAT_MK(0x0001u))
#define _GPIO_PGPIODAT2_IO39DAT_CLR		(~(_GPIO_PGPIODAT2_IO39DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT2_IO40DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT2_IO40DAT_SHIFT		(0x0008u)
#define _GPIO_PGPIODAT2_IO40DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT2_IO40DAT_SHIFT)
#define _GPIO_PGPIODAT2_IO40DAT_MASK		(_GPIO_PGPIODAT2_IO40DAT_MK(0x0001u))
#define _GPIO_PGPIODAT2_IO40DAT_CLR		(~(_GPIO_PGPIODAT2_IO40DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT2_IO41DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT2_IO41DAT_SHIFT		(0x0009u)
#define _GPIO_PGPIODAT2_IO41DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT2_IO41DAT_SHIFT)
#define _GPIO_PGPIODAT2_IO41DAT_MASK		(_GPIO_PGPIODAT2_IO41DAT_MK(0x0001u))
#define _GPIO_PGPIODAT2_IO41DAT_CLR		(~(_GPIO_PGPIODAT2_IO41DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT2_IO42DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT2_IO42DAT_SHIFT		(0x000au)
#define _GPIO_PGPIODAT2_IO42DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT2_IO42DAT_SHIFT)
#define _GPIO_PGPIODAT2_IO42DAT_MASK		(_GPIO_PGPIODAT2_IO42DAT_MK(0x0001u))
#define _GPIO_PGPIODAT2_IO42DAT_CLR		(~(_GPIO_PGPIODAT2_IO42DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT2_IO43DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT2_IO43DAT_SHIFT		(0x000bu)
#define _GPIO_PGPIODAT2_IO43DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT2_IO43DAT_SHIFT)
#define _GPIO_PGPIODAT2_IO43DAT_MASK		(_GPIO_PGPIODAT2_IO43DAT_MK(0x0001u))
#define _GPIO_PGPIODAT2_IO43DAT_CLR		(~(_GPIO_PGPIODAT2_IO43DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT2_IO44DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT2_IO44DAT_SHIFT		(0x000cu)
#define _GPIO_PGPIODAT2_IO44DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT2_IO44DAT_SHIFT)
#define _GPIO_PGPIODAT2_IO44DAT_MASK		(_GPIO_PGPIODAT2_IO44DAT_MK(0x0001u))
#define _GPIO_PGPIODAT2_IO44DAT_CLR		(~(_GPIO_PGPIODAT2_IO44DAT_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODAT2_IO45DAT:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODAT2_IO45DAT_SHIFT		(0x000du)
#define _GPIO_PGPIODAT2_IO45DAT_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODAT2_IO45DAT_SHIFT)
#define _GPIO_PGPIODAT2_IO45DAT_MASK		(_GPIO_PGPIODAT2_IO45DAT_MK(0x0001u))
#define _GPIO_PGPIODAT2_IO45DAT_CLR		(~(_GPIO_PGPIODAT2_IO45DAT_MASK))



/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the PGPIODIR0 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPIO_PGPIODIR0	 - Note: Add description here
*
* Fields:
*	(RW)   _GPIO_PGPIODIR1_IO16DIR	
*	(RW)   _GPIO_PGPIODIR1_IO17DIR	
*	(RW)   _GPIO_PGPIODIR1_IO18DIR	
*	(RW)   _GPIO_PGPIODIR1_IO19DIR	
*	(RW)   _GPIO_PGPIODIR1_IO20DIR	
*	(RW)   _GPIO_PGPIODIR1_IO21DIR	
*	(RW)   _GPIO_PGPIODIR1_IO22DIR	
*	(RW)   _GPIO_PGPIODIR1_IO23DIR	
*	(RW)   _GPIO_PGPIODIR1_IO24DIR	
*	(RW)   _GPIO_PGPIODIR1_IO25DIR	
*	(RW)   _GPIO_PGPIODIR1_IO26DIR	
*	(RW)   _GPIO_PGPIODIR1_IO27DIR	
*	(RW)   _GPIO_PGPIODIR1_IO28DIR	
*	(RW)   _GPIO_PGPIODIR1_IO29DIR	
*	(RW)   _GPIO_PGPIODIR1_IO30DIR	
*	(RW)   _GPIO_PGPIODIR1_IO31DIR	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR1_IO16DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR1_IO16DIR_SHIFT		(000000u)
#define _GPIO_PGPIODIR1_IO16DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR1_IO16DIR_SHIFT)
#define _GPIO_PGPIODIR1_IO16DIR_MASK		(_GPIO_PGPIODIR1_IO16DIR_MK(0x0001u))
#define _GPIO_PGPIODIR1_IO16DIR_CLR		(~(_GPIO_PGPIODIR1_IO16DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR1_IO17DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR1_IO17DIR_SHIFT		(0x0001u)
#define _GPIO_PGPIODIR1_IO17DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR1_IO17DIR_SHIFT)
#define _GPIO_PGPIODIR1_IO17DIR_MASK		(_GPIO_PGPIODIR1_IO17DIR_MK(0x0001u))
#define _GPIO_PGPIODIR1_IO17DIR_CLR		(~(_GPIO_PGPIODIR1_IO17DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR1_IO18DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR1_IO18DIR_SHIFT		(0x0002u)
#define _GPIO_PGPIODIR1_IO18DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR1_IO18DIR_SHIFT)
#define _GPIO_PGPIODIR1_IO18DIR_MASK		(_GPIO_PGPIODIR1_IO18DIR_MK(0x0001u))
#define _GPIO_PGPIODIR1_IO18DIR_CLR		(~(_GPIO_PGPIODIR1_IO18DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR1_IO19DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR1_IO19DIR_SHIFT		(0x0003u)
#define _GPIO_PGPIODIR1_IO19DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR1_IO19DIR_SHIFT)
#define _GPIO_PGPIODIR1_IO19DIR_MASK		(_GPIO_PGPIODIR1_IO19DIR_MK(0x0001u))
#define _GPIO_PGPIODIR1_IO19DIR_CLR		(~(_GPIO_PGPIODIR1_IO19DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR1_IO20DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR1_IO20DIR_SHIFT		(0x0004u)
#define _GPIO_PGPIODIR1_IO20DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR1_IO20DIR_SHIFT)
#define _GPIO_PGPIODIR1_IO20DIR_MASK		(_GPIO_PGPIODIR1_IO20DIR_MK(0x0001u))
#define _GPIO_PGPIODIR1_IO20DIR_CLR		(~(_GPIO_PGPIODIR1_IO20DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR1_IO21DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR1_IO21DIR_SHIFT		(0x0005u)
#define _GPIO_PGPIODIR1_IO21DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR1_IO21DIR_SHIFT)
#define _GPIO_PGPIODIR1_IO21DIR_MASK		(_GPIO_PGPIODIR1_IO21DIR_MK(0x0001u))
#define _GPIO_PGPIODIR1_IO21DIR_CLR		(~(_GPIO_PGPIODIR1_IO21DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR1_IO22DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR1_IO22DIR_SHIFT		(0x0006u)
#define _GPIO_PGPIODIR1_IO22DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR1_IO22DIR_SHIFT)
#define _GPIO_PGPIODIR1_IO22DIR_MASK		(_GPIO_PGPIODIR1_IO22DIR_MK(0x0001u))
#define _GPIO_PGPIODIR1_IO22DIR_CLR		(~(_GPIO_PGPIODIR1_IO22DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR1_IO23DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR1_IO23DIR_SHIFT		(0x0007u)
#define _GPIO_PGPIODIR1_IO23DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR1_IO23DIR_SHIFT)
#define _GPIO_PGPIODIR1_IO23DIR_MASK		(_GPIO_PGPIODIR1_IO23DIR_MK(0x0001u))
#define _GPIO_PGPIODIR1_IO23DIR_CLR		(~(_GPIO_PGPIODIR1_IO23DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR1_IO24DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR1_IO24DIR_SHIFT		(0x0008u)
#define _GPIO_PGPIODIR1_IO24DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR1_IO24DIR_SHIFT)
#define _GPIO_PGPIODIR1_IO24DIR_MASK		(_GPIO_PGPIODIR1_IO24DIR_MK(0x0001u))
#define _GPIO_PGPIODIR1_IO24DIR_CLR		(~(_GPIO_PGPIODIR1_IO24DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR1_IO25DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR1_IO25DIR_SHIFT		(0x0009u)
#define _GPIO_PGPIODIR1_IO25DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR1_IO25DIR_SHIFT)
#define _GPIO_PGPIODIR1_IO25DIR_MASK		(_GPIO_PGPIODIR1_IO25DIR_MK(0x0001u))
#define _GPIO_PGPIODIR1_IO25DIR_CLR		(~(_GPIO_PGPIODIR1_IO25DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR1_IO26DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR1_IO26DIR_SHIFT		(0x000au)
#define _GPIO_PGPIODIR1_IO26DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR1_IO26DIR_SHIFT)
#define _GPIO_PGPIODIR1_IO26DIR_MASK		(_GPIO_PGPIODIR1_IO26DIR_MK(0x0001u))
#define _GPIO_PGPIODIR1_IO26DIR_CLR		(~(_GPIO_PGPIODIR1_IO26DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR1_IO27DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR1_IO27DIR_SHIFT		(0x000bu)
#define _GPIO_PGPIODIR1_IO27DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR1_IO27DIR_SHIFT)
#define _GPIO_PGPIODIR1_IO27DIR_MASK		(_GPIO_PGPIODIR1_IO27DIR_MK(0x0001u))
#define _GPIO_PGPIODIR1_IO27DIR_CLR		(~(_GPIO_PGPIODIR1_IO27DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR1_IO28DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR1_IO28DIR_SHIFT		(0x000cu)
#define _GPIO_PGPIODIR1_IO28DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR1_IO28DIR_SHIFT)
#define _GPIO_PGPIODIR1_IO28DIR_MASK		(_GPIO_PGPIODIR1_IO28DIR_MK(0x0001u))
#define _GPIO_PGPIODIR1_IO28DIR_CLR		(~(_GPIO_PGPIODIR1_IO28DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR1_IO29DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR1_IO29DIR_SHIFT		(0x000du)
#define _GPIO_PGPIODIR1_IO29DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR1_IO29DIR_SHIFT)
#define _GPIO_PGPIODIR1_IO29DIR_MASK		(_GPIO_PGPIODIR1_IO29DIR_MK(0x0001u))
#define _GPIO_PGPIODIR1_IO29DIR_CLR		(~(_GPIO_PGPIODIR1_IO29DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR1_IO30DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR1_IO30DIR_SHIFT		(0x000eu)
#define _GPIO_PGPIODIR1_IO30DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR1_IO30DIR_SHIFT)
#define _GPIO_PGPIODIR1_IO30DIR_MASK		(_GPIO_PGPIODIR1_IO30DIR_MK(0x0001u))
#define _GPIO_PGPIODIR1_IO30DIR_CLR		(~(_GPIO_PGPIODIR1_IO30DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR1_IO31DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR1_IO31DIR_SHIFT		(0x000fu)
#define _GPIO_PGPIODIR1_IO31DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR1_IO31DIR_SHIFT)
#define _GPIO_PGPIODIR1_IO31DIR_MASK		(_GPIO_PGPIODIR1_IO31DIR_MK(0x0001u))
#define _GPIO_PGPIODIR1_IO31DIR_CLR		(~(_GPIO_PGPIODIR1_IO31DIR_MASK))


/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the PGPIODIR1 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPIO_PGPIODIR0	 - Note: Add description here
*
* Fields:
*	(RW)   _GPIO_PGPIODIR0_IO0DIR	
*	(RW)   _GPIO_PGPIODIR0_IO1DIR	
*	(RW)   _GPIO_PGPIODIR0_IO2DIR	
*	(RW)   _GPIO_PGPIODIR0_IO3DIR	
*	(RW)   _GPIO_PGPIODIR0_IO4DIR	
*	(RW)   _GPIO_PGPIODIR0_IO5DIR	
*	(RW)   _GPIO_PGPIODIR0_IO6DIR	
*	(RW)   _GPIO_PGPIODIR0_IO7DIR	
*	(RW)   _GPIO_PGPIODIR0_IO8DIR	
*	(RW)   _GPIO_PGPIODIR0_IO9DIR	
*	(RW)   _GPIO_PGPIODIR0_IO10DIR	
*	(RW)   _GPIO_PGPIODIR0_IO11DIR	
*	(RW)   _GPIO_PGPIODIR0_IO12DIR	
*	(RW)   _GPIO_PGPIODIR0_IO13DIR	
*	(RW)   _GPIO_PGPIODIR0_IO14DIR	
*	(RW)   _GPIO_PGPIODIR0_IO15DIR	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR0_IO0DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR0_IO0DIR_SHIFT		(000000u)
#define _GPIO_PGPIODIR0_IO0DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR0_IO0DIR_SHIFT)
#define _GPIO_PGPIODIR0_IO0DIR_MASK		(_GPIO_PGPIODIR0_IO0DIR_MK(0x0001u))
#define _GPIO_PGPIODIR0_IO0DIR_CLR		(~(_GPIO_PGPIODIR0_IO0DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR0_IO1DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR0_IO1DIR_SHIFT		(0x0001u)
#define _GPIO_PGPIODIR0_IO1DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR0_IO1DIR_SHIFT)
#define _GPIO_PGPIODIR0_IO1DIR_MASK		(_GPIO_PGPIODIR0_IO1DIR_MK(0x0001u))
#define _GPIO_PGPIODIR0_IO1DIR_CLR		(~(_GPIO_PGPIODIR0_IO1DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR0_IO2DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR0_IO2DIR_SHIFT		(0x0002u)
#define _GPIO_PGPIODIR0_IO2DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR0_IO2DIR_SHIFT)
#define _GPIO_PGPIODIR0_IO2DIR_MASK		(_GPIO_PGPIODIR0_IO2DIR_MK(0x0001u))
#define _GPIO_PGPIODIR0_IO2DIR_CLR		(~(_GPIO_PGPIODIR0_IO2DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR0_IO3DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR0_IO3DIR_SHIFT		(0x0003u)
#define _GPIO_PGPIODIR0_IO3DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR0_IO3DIR_SHIFT)
#define _GPIO_PGPIODIR0_IO3DIR_MASK		(_GPIO_PGPIODIR0_IO3DIR_MK(0x0001u))
#define _GPIO_PGPIODIR0_IO3DIR_CLR		(~(_GPIO_PGPIODIR0_IO3DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR0_IO4DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR0_IO4DIR_SHIFT		(0x0004u)
#define _GPIO_PGPIODIR0_IO4DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR0_IO4DIR_SHIFT)
#define _GPIO_PGPIODIR0_IO4DIR_MASK		(_GPIO_PGPIODIR0_IO4DIR_MK(0x0001u))
#define _GPIO_PGPIODIR0_IO4DIR_CLR		(~(_GPIO_PGPIODIR0_IO4DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR0_IO5DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR0_IO5DIR_SHIFT		(0x0005u)
#define _GPIO_PGPIODIR0_IO5DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR0_IO5DIR_SHIFT)
#define _GPIO_PGPIODIR0_IO5DIR_MASK		(_GPIO_PGPIODIR0_IO5DIR_MK(0x0001u))
#define _GPIO_PGPIODIR0_IO5DIR_CLR		(~(_GPIO_PGPIODIR0_IO5DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR0_IO6DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR0_IO6DIR_SHIFT		(0x0006u)
#define _GPIO_PGPIODIR0_IO6DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR0_IO6DIR_SHIFT)
#define _GPIO_PGPIODIR0_IO6DIR_MASK		(_GPIO_PGPIODIR0_IO6DIR_MK(0x0001u))
#define _GPIO_PGPIODIR0_IO6DIR_CLR		(~(_GPIO_PGPIODIR0_IO6DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR0_IO7DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR0_IO7DIR_SHIFT		(0x0007u)
#define _GPIO_PGPIODIR0_IO7DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR0_IO7DIR_SHIFT)
#define _GPIO_PGPIODIR0_IO7DIR_MASK		(_GPIO_PGPIODIR0_IO7DIR_MK(0x0001u))
#define _GPIO_PGPIODIR0_IO7DIR_CLR		(~(_GPIO_PGPIODIR0_IO7DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR0_IO8DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR0_IO8DIR_SHIFT		(0x0008u)
#define _GPIO_PGPIODIR0_IO8DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR0_IO8DIR_SHIFT)
#define _GPIO_PGPIODIR0_IO8DIR_MASK		(_GPIO_PGPIODIR0_IO8DIR_MK(0x0001u))
#define _GPIO_PGPIODIR0_IO8DIR_CLR		(~(_GPIO_PGPIODIR0_IO8DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR0_IO9DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR0_IO9DIR_SHIFT		(0x0009u)
#define _GPIO_PGPIODIR0_IO9DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR0_IO9DIR_SHIFT)
#define _GPIO_PGPIODIR0_IO9DIR_MASK		(_GPIO_PGPIODIR0_IO9DIR_MK(0x0001u))
#define _GPIO_PGPIODIR0_IO9DIR_CLR		(~(_GPIO_PGPIODIR0_IO9DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR0_IO10DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR0_IO10DIR_SHIFT		(0x000au)
#define _GPIO_PGPIODIR0_IO10DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR0_IO10DIR_SHIFT)
#define _GPIO_PGPIODIR0_IO10DIR_MASK		(_GPIO_PGPIODIR0_IO10DIR_MK(0x0001u))
#define _GPIO_PGPIODIR0_IO10DIR_CLR		(~(_GPIO_PGPIODIR0_IO10DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR0_IO11DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR0_IO11DIR_SHIFT		(0x000bu)
#define _GPIO_PGPIODIR0_IO11DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR0_IO11DIR_SHIFT)
#define _GPIO_PGPIODIR0_IO11DIR_MASK		(_GPIO_PGPIODIR0_IO11DIR_MK(0x0001u))
#define _GPIO_PGPIODIR0_IO11DIR_CLR		(~(_GPIO_PGPIODIR0_IO11DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR0_IO12DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR0_IO12DIR_SHIFT		(0x000cu)
#define _GPIO_PGPIODIR0_IO12DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR0_IO12DIR_SHIFT)
#define _GPIO_PGPIODIR0_IO12DIR_MASK		(_GPIO_PGPIODIR0_IO12DIR_MK(0x0001u))
#define _GPIO_PGPIODIR0_IO12DIR_CLR		(~(_GPIO_PGPIODIR0_IO12DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR0_IO13DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR0_IO13DIR_SHIFT		(0x000du)
#define _GPIO_PGPIODIR0_IO13DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR0_IO13DIR_SHIFT)
#define _GPIO_PGPIODIR0_IO13DIR_MASK		(_GPIO_PGPIODIR0_IO13DIR_MK(0x0001u))
#define _GPIO_PGPIODIR0_IO13DIR_CLR		(~(_GPIO_PGPIODIR0_IO13DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR0_IO14DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR0_IO14DIR_SHIFT		(0x000eu)
#define _GPIO_PGPIODIR0_IO14DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR0_IO14DIR_SHIFT)
#define _GPIO_PGPIODIR0_IO14DIR_MASK		(_GPIO_PGPIODIR0_IO14DIR_MK(0x0001u))
#define _GPIO_PGPIODIR0_IO14DIR_CLR		(~(_GPIO_PGPIODIR0_IO14DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR0_IO15DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR0_IO15DIR_SHIFT		(0x000fu)
#define _GPIO_PGPIODIR0_IO15DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR0_IO15DIR_SHIFT)
#define _GPIO_PGPIODIR0_IO15DIR_MASK		(_GPIO_PGPIODIR0_IO15DIR_MK(0x0001u))
#define _GPIO_PGPIODIR0_IO15DIR_CLR		(~(_GPIO_PGPIODIR0_IO15DIR_MASK))


/*----------------------------------------------------------------*\
* Macros to SET/GET and Configure globally the PGPIODIR2 register			
\*----------------------------------------------------------------*/

/******************************************************************************\
* 
* _GPIO_PGPIODIR2	 - Note: Add description here
*
* Fields:
*	(RW)   _GPIO_PGPIODIR2_IO32DIR	
*	(RW)   _GPIO_PGPIODIR2_IO33DIR	
*	(RW)   _GPIO_PGPIODIR2_IO34DIR	
*	(RW)   _GPIO_PGPIODIR2_IO35DIR	
*	(RW)   _GPIO_PGPIODIR2_IO36DIR	
*	(RW)   _GPIO_PGPIODIR2_IO37DIR	
*	(RW)   _GPIO_PGPIODIR2_IO38DIR	
*	(RW)   _GPIO_PGPIODIR2_IO39DIR	
*	(RW)   _GPIO_PGPIODIR2_IO40DIR	
*	(RW)   _GPIO_PGPIODIR2_IO41DIR	
*	(RW)   _GPIO_PGPIODIR2_IO42DIR	
*	(RW)   _GPIO_PGPIODIR2_IO43DIR	
*	(RW)   _GPIO_PGPIODIR2_IO44DIR	
*	(RW)   _GPIO_PGPIODIR2_IO45DIR	
*
\******************************************************************************/




/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR2_IO32DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR2_IO32DIR_SHIFT		(000000u)
#define _GPIO_PGPIODIR2_IO32DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR2_IO32DIR_SHIFT)
#define _GPIO_PGPIODIR2_IO32DIR_MASK		(_GPIO_PGPIODIR2_IO32DIR_MK(0x0001u))
#define _GPIO_PGPIODIR2_IO32DIR_CLR		(~(_GPIO_PGPIODIR2_IO32DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR2_IO33DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR2_IO33DIR_SHIFT		(0x0001u)
#define _GPIO_PGPIODIR2_IO33DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR2_IO33DIR_SHIFT)
#define _GPIO_PGPIODIR2_IO33DIR_MASK		(_GPIO_PGPIODIR2_IO33DIR_MK(0x0001u))
#define _GPIO_PGPIODIR2_IO33DIR_CLR		(~(_GPIO_PGPIODIR2_IO33DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR2_IO34DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR2_IO34DIR_SHIFT		(0x0002u)
#define _GPIO_PGPIODIR2_IO34DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR2_IO34DIR_SHIFT)
#define _GPIO_PGPIODIR2_IO34DIR_MASK		(_GPIO_PGPIODIR2_IO34DIR_MK(0x0001u))
#define _GPIO_PGPIODIR2_IO34DIR_CLR		(~(_GPIO_PGPIODIR2_IO34DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR2_IO35DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR2_IO35DIR_SHIFT		(0x0003u)
#define _GPIO_PGPIODIR2_IO35DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR2_IO35DIR_SHIFT)
#define _GPIO_PGPIODIR2_IO35DIR_MASK		(_GPIO_PGPIODIR2_IO35DIR_MK(0x0001u))
#define _GPIO_PGPIODIR2_IO35DIR_CLR		(~(_GPIO_PGPIODIR2_IO35DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR2_IO36DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR2_IO36DIR_SHIFT		(0x0004u)
#define _GPIO_PGPIODIR2_IO36DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR2_IO36DIR_SHIFT)
#define _GPIO_PGPIODIR2_IO36DIR_MASK		(_GPIO_PGPIODIR2_IO36DIR_MK(0x0001u))
#define _GPIO_PGPIODIR2_IO36DIR_CLR		(~(_GPIO_PGPIODIR2_IO36DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR2_IO37DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR2_IO37DIR_SHIFT		(0x0005u)
#define _GPIO_PGPIODIR2_IO37DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR2_IO37DIR_SHIFT)
#define _GPIO_PGPIODIR2_IO37DIR_MASK		(_GPIO_PGPIODIR2_IO37DIR_MK(0x0001u))
#define _GPIO_PGPIODIR2_IO37DIR_CLR		(~(_GPIO_PGPIODIR2_IO37DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR2_IO38DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR2_IO38DIR_SHIFT		(0x0006u)
#define _GPIO_PGPIODIR2_IO38DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR2_IO38DIR_SHIFT)
#define _GPIO_PGPIODIR2_IO38DIR_MASK		(_GPIO_PGPIODIR2_IO38DIR_MK(0x0001u))
#define _GPIO_PGPIODIR2_IO38DIR_CLR		(~(_GPIO_PGPIODIR2_IO38DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR2_IO39DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR2_IO39DIR_SHIFT		(0x0007u)
#define _GPIO_PGPIODIR2_IO39DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR2_IO39DIR_SHIFT)
#define _GPIO_PGPIODIR2_IO39DIR_MASK		(_GPIO_PGPIODIR2_IO39DIR_MK(0x0001u))
#define _GPIO_PGPIODIR2_IO39DIR_CLR		(~(_GPIO_PGPIODIR2_IO39DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR2_IO40DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR2_IO40DIR_SHIFT		(0x0008u)
#define _GPIO_PGPIODIR2_IO40DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR2_IO40DIR_SHIFT)
#define _GPIO_PGPIODIR2_IO40DIR_MASK		(_GPIO_PGPIODIR2_IO40DIR_MK(0x0001u))
#define _GPIO_PGPIODIR2_IO40DIR_CLR		(~(_GPIO_PGPIODIR2_IO40DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR2_IO41DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR2_IO41DIR_SHIFT		(0x0009u)
#define _GPIO_PGPIODIR2_IO41DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR2_IO41DIR_SHIFT)
#define _GPIO_PGPIODIR2_IO41DIR_MASK		(_GPIO_PGPIODIR2_IO41DIR_MK(0x0001u))
#define _GPIO_PGPIODIR2_IO41DIR_CLR		(~(_GPIO_PGPIODIR2_IO41DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR2_IO42DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR2_IO42DIR_SHIFT		(0x000au)
#define _GPIO_PGPIODIR2_IO42DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR2_IO42DIR_SHIFT)
#define _GPIO_PGPIODIR2_IO42DIR_MASK		(_GPIO_PGPIODIR2_IO42DIR_MK(0x0001u))
#define _GPIO_PGPIODIR2_IO42DIR_CLR		(~(_GPIO_PGPIODIR2_IO42DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR2_IO43DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR2_IO43DIR_SHIFT		(0x000bu)
#define _GPIO_PGPIODIR2_IO43DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR2_IO43DIR_SHIFT)
#define _GPIO_PGPIODIR2_IO43DIR_MASK		(_GPIO_PGPIODIR2_IO43DIR_MK(0x0001u))
#define _GPIO_PGPIODIR2_IO43DIR_CLR		(~(_GPIO_PGPIODIR2_IO43DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR2_IO44DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR2_IO44DIR_SHIFT		(0x000cu)
#define _GPIO_PGPIODIR2_IO44DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR2_IO44DIR_SHIFT)
#define _GPIO_PGPIODIR2_IO44DIR_MASK		(_GPIO_PGPIODIR2_IO44DIR_MK(0x0001u))
#define _GPIO_PGPIODIR2_IO44DIR_CLR		(~(_GPIO_PGPIODIR2_IO44DIR_MASK))



/*----------------------------------------------------------------*\
*   (RW)  _GPIO_PGPIODIR2_IO45DIR:	
\*----------------------------------------------------------------*/

#define _GPIO_PGPIODIR2_IO45DIR_SHIFT		(0x000du)
#define _GPIO_PGPIODIR2_IO45DIR_MK(n)		(((Uint16)(n) & 0x0001u) << _GPIO_PGPIODIR2_IO45DIR_SHIFT)
#define _GPIO_PGPIODIR2_IO45DIR_MASK		(_GPIO_PGPIODIR2_IO45DIR_MK(0x0001u))
#define _GPIO_PGPIODIR2_IO45DIR_CLR		(~(_GPIO_PGPIODIR2_IO45DIR_MASK))




#endif
#else
   #ifndef _GPIO_MOD
	#error GPIO Hal Module Not Supported on Specified Target
   #endif
#endif
#endif
