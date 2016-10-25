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

#ifndef _GPIO5509HAL_H_
#define _GPIO5509HAL_H_

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
#define _GPIO_IODATA_CFG(io0,io1,io2,io3,io4,io5,io6,io7)  \
	HPREG_SET(_GPIO_IODATA_ADDR,						\
    		(Uint16) (	_GPIO_IODATA_IO0D_MK(io0) 		|	\
				_GPIO_IODATA_IO1D_MK(io1) 		|	\
				_GPIO_IODATA_IO2D_MK(io2) 		|	\
				_GPIO_IODATA_IO3D_MK(io3) 		|	\
				_GPIO_IODATA_IO4D_MK(io4) 		|	\
				_GPIO_IODATA_IO5D_MK(io5) 		|	\
				_GPIO_IODATA_IO6D_MK(io6) 		|	\
				_GPIO_IODATA_IO7D_MK(io7) 			\
	             ))

#else
   #ifndef _GPIO_MOD
	#error GPIO Hal Module Not Supported on Specified Target
   #endif
#endif
#endif
