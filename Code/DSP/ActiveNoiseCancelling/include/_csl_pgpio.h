 /******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... PGPIO
* FILENAME...... csl_pgpio.h
* DATE CREATED.. Fri 06/09/2000 
* PROJECT....... Chip Support Library
* COMPONENT..... CSL service layer
* PREREQUISITS.. 
* VERSION....... 1.00
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:         06/09/2000 created for C5510
*   LAST MODIFIED:   04/16/2001 updated module name and other header comments
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the PGPIO module,
*                which manipulaes pins that have powerdown/idle enable modes)
*
*
*
\******************************************************************************/
#ifndef _PGPIO_H_
#define _PGPIO_H_

#include <_csl.h>
#include <_csl_gpiohal.h>
#include <_csl_pgpiohal.h>
#include <_csl_pgpiodat.h>


#if (_GPIO_PGPIO_SUPPORT)
/****************************************\
* GIO scope and inline control macros
\****************************************/
#ifdef __cplusplus
#define CSLAPI extern "C"  
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _GPIO_MOD_
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
* GIO static macro declarations          
\****************************************/
 
#define GPIO_DEV0    (0)


#define GPIO_INPUT                (0)
#define GPIO_OUTPUT               (1)

/* Define Pin ID's for All Possible GPIO Pins */

#define GPIO_GPIO                 (0x0000u)
#define GPIO_AGPIO                (0x1000u)


#define GPIO_PIN0            (((Uint32)(GPIO_GPIO) << 16) | 0x0001u)
#define GPIO_PIN1            (((Uint32)(GPIO_GPIO) << 16) | 0x0002u)
#define GPIO_PIN2            (((Uint32)(GPIO_GPIO) << 16) | 0x0004u)
#define GPIO_PIN3            (((Uint32)(GPIO_GPIO) << 16) | 0x0008u)
#define GPIO_PIN4            (((Uint32)(GPIO_GPIO) << 16) | 0x0010u)
#define GPIO_PIN5            (((Uint32)(GPIO_GPIO) << 16) | 0x0020u)
#define GPIO_PIN6            (((Uint32)(GPIO_GPIO) << 16) | 0x0040u)
#define GPIO_PIN7            (((Uint32)(GPIO_GPIO) << 16) | 0x0080u)
#define GPIO_PIN8            (((Uint32)(GPIO_GPIO) << 16) | 0x0100u)
#define GPIO_PIN9            (((Uint32)(GPIO_GPIO) << 16) | 0x0200u)
#define GPIO_PIN10           (((Uint32)(GPIO_GPIO) << 16) | 0x0400u)
#define GPIO_PIN11           (((Uint32)(GPIO_GPIO) << 16) | 0x0800u)
#define GPIO_PIN12           (((Uint32)(GPIO_GPIO) << 16) | 0x1000u)
#define GPIO_PIN13           (((Uint32)(GPIO_GPIO) << 16) | 0x2000u)

#define AGPIO_PIN0           (((Uint32)(GPIO_AGPIO) << 16) | 0x0001u)
#define AGPIO_PIN1           (((Uint32)(GPIO_AGPIO) << 16) | 0x0002u)
#define AGPIO_PIN2           (((Uint32)(GPIO_AGPIO) << 16) | 0x0004u)
#define AGPIO_PIN3           (((Uint32)(GPIO_AGPIO) << 16) | 0x0008u)
#define AGPIO_PIN4           (((Uint32)(GPIO_AGPIO) << 16) | 0x0010u)
#define AGPIO_PIN5           (((Uint32)(GPIO_AGPIO) << 16) | 0x0020u)
#define AGPIO_PIN6           (((Uint32)(GPIO_AGPIO) << 16) | 0x0040u)
#define AGPIO_PIN7           (((Uint32)(GPIO_AGPIO) << 16) | 0x0080u)
#define AGPIO_PIN8           (((Uint32)(GPIO_AGPIO) << 16) | 0x0100u)
#define AGPIO_PIN9           (((Uint32)(GPIO_AGPIO) << 16) | 0x0200u)
#define AGPIO_PIN10          (((Uint32)(GPIO_AGPIO) << 16) | 0x0400u)
#define AGPIO_PIN11          (((Uint32)(GPIO_AGPIO) << 16) | 0x0800u)
#define AGPIO_PIN12          (((Uint32)(GPIO_AGPIO) << 16) | 0x1000u)
#define AGPIO_PIN13          (((Uint32)(GPIO_AGPIO) << 16) | 0x2000u)
#define AGPIO_PIN14          (((Uint32)(GPIO_AGPIO) << 16) | 0x4000u)
#define AGPIO_PIN15          (((Uint32)(GPIO_AGPIO) << 16) | 0x8000u)



/* Configure GIO (General Purpose I/O) Pins */
#define GPIO_IODIR_IO0_EN         (0x00000001u)
#define GPIO_IODIR_IO1_EN         (0x00000002u)
#define GPIO_IODIR_IO2_EN         (0x00000004u)
#define GPIO_IODIR_IO3_EN         (0x00000008u)
#define GPIO_IODIR_IO4_EN         (0x00000010u)
#define GPIO_IODIR_IO5_EN         (0x00000020u)
#define GPIO_IODIR_IO6_EN         (0x00000040u)
#define GPIO_IODIR_IO7_EN         (0x00000080u)
#define GPIO_IODIR_IO8_EN         (0x00010000u)
#define GPIO_IODIR_IO9_EN         (0x00020000u)
#define GPIO_IODIR_IO10_EN        (0x00040000u)
#define GPIO_IODIR_IO11_EN        (0x00080000u)
#define GPIO_IODIR_IO12_EN        (0x00100000u)
#define GPIO_IODIR_IO13_EN        (0x00200000u)

#define GPIO_IODIR_IODIR0         (0x0001u)
#define GPIO_IODIR_IODIR1         (0x0002u)
#define GPIO_IODIR_IODIR2         (0x0004u)
#define GPIO_IODIR_IODIR3         (0x0008u)
#define GPIO_IODIR_IODIR4         (0x0010u)
#define GPIO_IODIR_IODIR5         (0x0020u)
#define GPIO_IODIR_IODIR6         (0x0040u)
#define GPIO_IODIR_IODIR7         (0x0080u)
#define GPIO_IODIR_IODIR8         (0x00010000u)
#define GPIO_IODIR_IODIR9         (0x00020000u)
#define GPIO_IODIR_IODIR10        (0x00040000u)
#define GPIO_IODIR_IODIR11        (0x00080000u)
#define GPIO_IODIR_IODIR12        (0x00100000u)
#define GPIO_IODIR_IODIR13        (0x00200000u)

#define GPIO_IODIR_IO0DIR         (0x0001u)
#define GPIO_IODIR_IO1DIR         (0x0002u)
#define GPIO_IODIR_IO2DIR         (0x0004u)
#define GPIO_IODIR_IO3DIR         (0x0008u)
#define GPIO_IODIR_IO4DIR         (0x0010u)
#define GPIO_IODIR_IO5DIR         (0x0020u)
#define GPIO_IODIR_IO6DIR         (0x0040u)
#define GPIO_IODIR_IO7DIR         (0x0080u)
#define GPIO_IODIR_IO8DIR         (0x00010000u)
#define GPIO_IODIR_IO9DIR         (0x00020000u)
#define GPIO_IODIR_IO10DIR        (0x00040000u)
#define GPIO_IODIR_IO11DIR        (0x00080000u)
#define GPIO_IODIR_IO12DIR        (0x00100000u)
#define GPIO_IODIR_IO13DIR        (0x00200000u)

#define GPIO_IODATA_IOD0_O	    (0x00000001u)
#define GPIO_IODATA_IOD1_O        (0x00000002u)
#define GPIO_IODATA_IOD2_O        (0x00000004u)
#define GPIO_IODATA_IOD3_O        (0x00000008u)
#define GPIO_IODATA_IOD4_O        (0x00000010u)
#define GPIO_IODATA_IOD5_O        (0x00000020u)
#define GPIO_IODATA_IOD6_O        (0x00000040u)
#define GPIO_IODATA_IOD7_O        (0x00000080u)
#define GPIO_IODATA_IOD8_O        (0x00010000u)
#define GPIO_IODATA_IOD9_O        (0x00020000u)
#define GPIO_IODATA_IOD10_O       (0x00040000u)
#define GPIO_IODATA_IOD11_O       (0x00080000u)
#define GPIO_IODATA_IOD12_O       (0x00100000u)
#define GPIO_IODATA_IOD13_O       (0x00200000u)

#define GPIO_IODATA_IO0D_OUTPUT   (0x00000001u)
#define GPIO_IODATA_IO1D_OUTPUT   (0x00000002u)
#define GPIO_IODATA_IO2D_OUTPUT   (0x00000004u)
#define GPIO_IODATA_IO3D_OUTPUT   (0x00000008u)
#define GPIO_IODATA_IO4D_OUTPUT   (0x00000010u)
#define GPIO_IODATA_IO5D_OUTPUT   (0x00000020u)
#define GPIO_IODATA_IO6D_OUTPUT   (0x00000040u)
#define GPIO_IODATA_IO7D_OUTPUT   (0x00000080u)
#define GPIO_IODATA_IO8D_OUTPUT   (0x00010000u)
#define GPIO_IODATA_IO9D_OUTPUT   (0x00020000u)
#define GPIO_IODATA_IO10D_OUTPUT  (0x00040000u)
#define GPIO_IODATA_IO11D_OUTPUT  (0x00080000u)
#define GPIO_IODATA_IO12D_OUTPUT  (0x00100000u)
#define GPIO_IODATA_IO13D_OUTPUT  (0x00200000u)

#define GPIO_IODATA_IOD0_I        (0x00000000u)
#define GPIO_IODATA_IOD1_I        (0x00000000u)
#define GPIO_IODATA_IOD2_I        (0x00000000u)
#define GPIO_IODATA_IOD3_I        (0x00000000u)
#define GPIO_IODATA_IOD4_I        (0x00000000u)
#define GPIO_IODATA_IOD5_I        (0x00000000u)
#define GPIO_IODATA_IOD6_I        (0x00000000u)
#define GPIO_IODATA_IOD7_I        (0x00000000u)
#define GPIO_IODATA_IOD8_I        (0x00000000u)
#define GPIO_IODATA_IOD9_I        (0x00000000u)
#define GPIO_IODATA_IOD10_I       (0x00000000u)
#define GPIO_IODATA_IOD11_I       (0x00000000u)
#define GPIO_IODATA_IOD12_I       (0x00000000u)
#define GPIO_IODATA_IOD13_I       (0x00000000u)

#define GPIO_IODATA_IO0D_INPUT   (0x00000000u)
#define GPIO_IODATA_IO1D_INPUT   (0x00000000u)
#define GPIO_IODATA_IO2D_INPUT   (0x00000000u)
#define GPIO_IODATA_IO3D_INPUT   (0x00000000u)
#define GPIO_IODATA_IO4D_INPUT   (0x00000000u)
#define GPIO_IODATA_IO5D_INPUT   (0x00000000u)
#define GPIO_IODATA_IO6D_INPUT   (0x00000000u)
#define GPIO_IODATA_IO7D_INPUT   (0x00000000u)
#define GPIO_IODATA_IO8D_INPUT   (0x00000000u)
#define GPIO_IODATA_IO9D_INPUT   (0x00000000u)
#define GPIO_IODATA_IO10D_INPUT  (0x00000000u)
#define GPIO_IODATA_IO11D_INPUT  (0x00000000u)
#define GPIO_IODATA_IO12D_INPUT  (0x00000000u)
#define GPIO_IODATA_IO13D_INPUT  (0x00000000u)


/****************************************\
* GIO static typedef declarations
\****************************************/
/*******************************************\
* GIO: global macro definition : ROMABILITY
\*******************************************/  
/* Reserved ROM Area by giodata.h */ 
    
/*===========================================================================*\
*  GPIO IODIR Macros
*
* Fields:
*  (RW) IO7DIR
*  (RW) IO6DIR
*  (RW) IO5DIR
*  (RW) IO4DIR
*  (RW) IO3DIR
*  (RW) IO2DIR
*  (RW) IO1DIR
*  (RW) IO0DIR
\*==========================================================================*/



/*---------------------------------------*\
* GPIO_IODIR_MK Macro
\*---------------------------------------*/

#define GPIO_IODIR_RMK(io7, io6, io5, io4, io3,\
                        io2, io1, io0 )\
  (Uint16) ( GPIO_FMK(IODIR,IO7DIR,io7)    |\
             GPIO_FMK(IODIR,IO6DIR,io6)    |\
             GPIO_FMK(IODIR,IO5DIR,io5)    |\
             GPIO_FMK(IODIR,IO4DIR,io4)    |\
             GPIO_FMK(IODIR,IO3DIR,io3)    |\
             GPIO_FMK(IODIR,IO2DIR,io2)    |\
             GPIO_FMK(IODIR,IO1DIR,io1)    |\
             GPIO_FMK(IODIR,IO0DIR,io0)    \
)

#define GPIO_IODIR_RMKS(io7, io6, io5, io4, io3,\
                        io2, io1, io0 )\
  (Uint16) ( GPIO_FMKS(IODIR,IO7DIR,io7)    |\
             GPIO_FMKS(IODIR,IO6DIR,io6)    |\
             GPIO_FMKS(IODIR,IO5DIR,io5)    |\
             GPIO_FMKS(IODIR,IO4DIR,io4)    |\
             GPIO_FMKS(IODIR,IO3DIR,io3)    |\
             GPIO_FMKS(IODIR,IO2DIR,io2)    |\
             GPIO_FMKS(IODIR,IO1DIR,io1)    |\
             GPIO_FMKS(IODIR,IO0DIR,io0)    \
)

/*===========================================================================*\
* GPIO IODATA
*
* Fields:
*  (RW) IO7D
*  (RW) IO6D
*  (RW) IO5D
*  (RW) IO4D
*  (RW) IO3D
*  (RW) IO2D
*  (RW) IO1D
*  (RW) IO0D
\*==========================================================================*/

/*---------------------------------------*\
* GPIO_IODATA_MK Macro
\*---------------------------------------*/

#define GPIO_IODATA_RMK(io0,io1,io2,io3,io4,io5,io6,io7)(\
(Uint16) (	GPIO_FMK(IODATA,IO0D,io0) 		|	\
		GPIO_FMK(IODATA,IO1D,io1) 		|	\
		GPIO_FMK(IODATA,IO2D,io2) 		|	\
		GPIO_FMK(IODATA,IO3D,io3) 		|	\
		GPIO_FMK(IODATA,IO4D,io4) 		|	\
		GPIO_FMK(IODATA,IO5D,io5) 		|	\
		GPIO_FMK(IODATA,IO6D,io6) 		|	\
		GPIO_FMK(IODATA,IO7D,io7) 			\
	   ))

#define GPIO_IODATA_RMKS(io0,io1,io2,io3,io4,io5,io6,io7)(\
(Uint16) (	GPIO_FMKS(IODATA,IO0D,io0) 		|	\
		GPIO_FMKS(IODATA,IO1D,io1) 		|	\
		GPIO_FMKS(IODATA,IO2D,io2) 		|	\
		GPIO_FMKS(IODATA,IO3D,io3) 		|	\
		GPIO_FMKS(IODATA,IO4D,io4) 		|	\
		GPIO_FMKS(IODATA,IO5D,io5) 		|	\
		GPIO_FMKS(IODATA,IO6D,io6) 		|	\
		GPIO_FMKS(IODATA,IO7D,io7) 			\
	   ))

/*===========================================================================*\
*  GPIO GPIODIR Macros
*
* Fields:
*  (RW) IO7DIR
*  (RW) IO6DIR
*  (RW) IO5DIR
*  (RW) IO4DIR
*  (RW) IO3DIR
*  (RW) IO2DIR
*  (RW) IO1DIR
*  (RW) IO0DIR
*  (RW) IO8DIR
*  (RW) IO9DIR
*  (RW) IO10DIR
*  (RW) IO11DIR
*  (RW) IO12DIR
*  (RW) IO13DIR
\*==========================================================================*/



/*---------------------------------------*\
* GPIO_GPIODIR0_RMK Macro
\*---------------------------------------*/

#define GPIO_GPIODIR_RMK(io8, io9, io10, io11, io12,io13)\
  (Uint16) ( GPIO_FMK(GPIODIR,IO8DIR,io8)    |\
             GPIO_FMK(GPIODIR,IO9DIR,io9)    |\
             GPIO_FMK(GPIODIR,IO10DIR,io10)  |\
             GPIO_FMK(GPIODIR,IO11DIR,io11)  |\
             GPIO_FMK(GPIODIR,IO12DIR,io12)  |\
             GPIO_FMK(GPIODIR,IO13DIR,io13)  \
)

#define GPIO_GPIOEN_RMK(io8, io9, io10, io11, io12, io13)\
  (Uint16) ( GPIO_FMK(GPIOEN,IO8,io8)    |\
             GPIO_FMK(GPIOEN,IO9,io9)    |\
             GPIO_FMK(GPIOEN,IO10,io10)  |\
             GPIO_FMK(GPIOEN,IO11,io11)  |\
             GPIO_FMK(GPIOEN,IO12,io12)  |\
             GPIO_FMK(GPIOEN,IO13,io13)  \
)

#define GPIO_GPIODIR_RMKS(io8, io9, io10, io11, io12,io13)\
  (Uint16) ( GPIO_FMKS(GPIODIR,IO8DIR,io8)    |\
             GPIO_FMKS(GPIODIR,IO9DIR,io9)    |\
             GPIO_FMKS(GPIODIR,IO10DIR,io10)  |\
             GPIO_FMKS(GPIODIR,IO11DIR,io11)  |\
             GPIO_FMKS(GPIODIR,IO12DIR,io12)  |\
             GPIO_FMKS(GPIODIR,IO13DIR,io13)  \
)

#define GPIO_GPIOEN_RMKS(io8, io9, io10, io11, io12, io13)\
  (Uint16) ( GPIO_FMKS(GPIOEN,IO8,io8)    |\
             GPIO_FMKS(GPIOEN,IO9,io9)    |\
             GPIO_FMKS(GPIOEN,IO10,io10)  |\
             GPIO_FMKS(GPIOEN,IO11,io11)  |\
             GPIO_FMKS(GPIOEN,IO12,io12)  |\
             GPIO_FMKS(GPIOEN,IO13,io13)  \
)

/*===========================================================================*\
* GPIO GPIODATA
*
* Fields:
*  (RW) IO7D
*  (RW) IO6D
*  (RW) IO5D
*  (RW) IO4D
*  (RW) IO3D
*  (RW) IO2D
*  (RW) IO1D
*  (RW) IO0D
*  (RW) IO8D
*  (RW) IO9D
*  (RW) I010D
*  (RW) IO11D
*  (RW) IO12D
*  (RW) IO13D
\*==========================================================================*/

/*---------------------------------------*\
* GPIO_GPIODATA_RMK Macro
\*---------------------------------------*/
#define GPIO_GPIODATA_RMK(io8,io9,io10,io11,io12,io13)(\
(Uint16) (	GPIO_FMK(GPIODATA,IO8D,io8) 	 |\
		GPIO_FMK(GPIODATA,IO9D,io9) 	 |\
		GPIO_FMK(GPIODATA,IO10D,io10) |\
		GPIO_FMK(GPIODATA,IO11D,io11) |\
		GPIO_FMK(GPIODATA,IO12D,io12) |\
		GPIO_FMK(GPIODATA,IO13D,io13) \
	   ))

#define GPIO_GPIODATA_RMKS(io8,io9,io10,io11,io12,io13)(\
(Uint16) (	GPIO_FMKS(GPIODATA,IO8D,io8)   |\
		GPIO_FMKS(GPIODATA,IO9D,io9)   |\
		GPIO_FMKS(GPIODATA,IO10D,io10) |\
		GPIO_FMKS(GPIODATA,IO11D,io11) |\
		GPIO_FMKS(GPIODATA,IO12D,io12) |\
		GPIO_FMKS(GPIODATA,IO13D,io13) \
	   ))

#define GPIO_AGPIODATA_RMK(io8,io9,io10,io11,io12,io13)(\
(Uint16) (	GPIO_FMK(AGPIODATA,IO8D,io8) 	 |\
		GPIO_FMK(AGPIODATA,IO9D,io9) 	 |\
		GPIO_FMK(AGPIODATA,IO10D,io10) |\
		GPIO_FMK(AGPIODATA,IO11D,io11) |\
		GPIO_FMK(AGPIODATA,IO12D,io12) |\
		GPIO_FMK(AGPIODATA,IO13D,io13) \
	   ))

#define GPIO_AGPIODATA_RMKS(io8,io9,io10,io11,io12,io13)(\
(Uint16) (	GPIO_FMKS(AGPIODATA,IO8D,io8)   |\
		GPIO_FMKS(AGPIODATA,IO9D,io9)   |\
		GPIO_FMKS(AGPIODATA,IO10D,io10) |\
		GPIO_FMKS(AGPIODATA,IO11D,io11) |\
		GPIO_FMKS(AGPIODATA,IO12D,io12) |\
		GPIO_FMKS(AGPIODATA,IO13D,io13) \
	   ))

#define GPIO_AGPIOEN_RMK(io8, io9, io10, io11, io12, io13)\
  (Uint16) ( GPIO_FMK(AGPIOEN,IO8,io8)    |\
             GPIO_FMK(AGPIOEN,IO9,io9)    |\
             GPIO_FMK(AGPIOEN,IO10,io10)  |\
             GPIO_FMK(AGPIOEN,IO11,io11)  |\
             GPIO_FMK(AGPIOEN,IO12,io12)  |\
             GPIO_FMK(AGPIOEN,IO13,io13)  \
)
#define GPIO_AGPIOEN_RMKS(io8, io9, io10, io11, io12, io13)\
  (Uint16) ( GPIO_FMKS(AGPIOEN,IO8,io8)    |\
             GPIO_FMKS(AGPIOEN,IO9,io9)    |\
             GPIO_FMKS(AGPIOEN,IO10,io10)  |\
             GPIO_FMKS(AGPIOEN,IO11,io11)  |\
             GPIO_FMKS(AGPIOEN,IO12,io12)  |\
             GPIO_FMKS(AGPIOEN,IO13,io13)  \
)

#define GPIO_AGPIODIR_RMK(io8, io9, io10, io11, io12, io13)\
  (Uint16) ( GPIO_FMK(AGPIODIR,IO8DIR,io8)    |\
             GPIO_FMK(AGPIODIR,IO9DIR,io9)    |\
             GPIO_FMK(AGPIODIR,IO10DIR,io10)  |\
             GPIO_FMK(AGPIODIR,IO11DIR,io11)  |\
             GPIO_FMK(AGPIODIR,IO12DIR,io12)  |\
             GPIO_FMK(AGPIODIR,IO13DIR,io13)  \
)

#define GPIO_AGPIODIR_RMKS(io8, io9, io10, io11, io12, io13)\
  (Uint16) ( GPIO_FMKS(AGPIODIR,IO8DIR,io8)    |\
             GPIO_FMKS(AGPIODIR,IO9DIR,io9)    |\
             GPIO_FMKS(AGPIODIR,IO10DIR,io10)  |\
             GPIO_FMKS(AGPIODIR,IO11DIR,io11)  |\
             GPIO_FMKS(AGPIODIR,IO12DIR,io12)  |\
             GPIO_FMKS(AGPIODIR,IO13DIR,io13)  \
)

/****************************************\
* Overload GPIO pin functions           
\****************************************/

#define GPIO_pinEnable              _PGPIO_pinEnable
#define GPIO_pinDisable             _PGPIO_pinDisable
#define GPIO_pinDirection           _PGPIO_pinDirection
#define GPIO_pinRead                _PGPIO_pinRead
#define GPIO_pinWrite               _PGPIO_pinWrite

/****************************************\
* GPIO function declarations        
\****************************************/
IDECL int _PGPIO_pinEnable(Uint32 pinId);
IDECL int _PGPIO_pinDisable(Uint32 pinId);
IDECL int _PGPIO_pinDirection(Uint32 pinId, Uint16 direction);
IDECL int _PGPIO_pinRead(Uint32 pinId);
IDECL int _PGPIO_pinWrite(Uint32 pinId, Uint16 value);


/*****************************************\
* GPIO Inline Functions
\*****************************************/

#ifdef  USEDEFS

/*------------------------------------------------------------------------------*/
IDEF int _PGPIO_pinEnable(Uint32 pinId) {
  Uint16 dev = ((pinId >> 16) & 0xffffu);
  Uint16 pin = (pinId & 0xffffu);
  Uint16 pin2;

   switch (dev) {
    case GPIO_GPIO: 
                        pin2 = (pinId >> 8) & 0x3fu;
                        _GPIO_GPIOEN |= pin2;
                        return _GPIO_GPIOEN;

    case GPIO_AGPIO:   
                        _GPIO_AGPIOEN |= pin;
                        return  _GPIO_AGPIOEN;

    default:            return 0;
 }
}

/*----------------------------------------------------------------------------*/
IDEF int _PGPIO_pinDisable(Uint32 pinId) {
  Uint16 dev = ((pinId >> 16) & 0xffffu);
  Uint16 pin = (pinId & 0xffffu);
  Uint16 pin2;

   switch (dev) {
    case GPIO_GPIO: 
                        pin2 = ((pin >> 8) & 0x3fu);
                        _GPIO_GPIOEN &= ~(pin2);
                        return ((_GPIO_GPIOEN & pin2) ? 1:0);

    case GPIO_AGPIO:   
                        _GPIO_AGPIOEN &= ~(pin);
                        return  ((_GPIO_AGPIOEN & pin) ? 1:0);

 
    default:            return 0;
 }
}
/*----------------------------------------------------------------------------*/
IDEF int _PGPIO_pinDirection(Uint32 pinId, Uint16 direction) {
  Uint16 dev = ((pinId >> 16) & 0xffffu);
  Uint16 pin = (Uint16)(pinId & 0xffffu);
  Uint16 pin1, pin2;
   switch (dev) {
    case GPIO_GPIO: 
                         pin1 = pinId & 0xffu;
                         pin2 = (pinId >> 8) & 0x3fu;
                        if (pin1) {
                           _GPIO_IODIR = (_GPIO_IODIR & (~(pin1)))
                                         | ((direction) ? pin1:0);
                           return ((_GPIO_IODIR & pin1) ? 1:0);
                        }
                        _GPIO_GPIODIR = (_GPIO_GPIODIR & (~(pin2)))
                                        | ((direction)?  pin2:0);
                        return ((_GPIO_GPIODIR & pin2)? 1:0);

    case GPIO_AGPIO:   
                        _GPIO_AGPIODIR = (_GPIO_AGPIODIR & (~(pin))) 
                                          | ((direction)? pin:0);
                        return ((_GPIO_AGPIODIR & pin) ? 1:0);

    default:            return 0;
  }
}
/*----------------------------------------------------------------------------*/
IDEF int _PGPIO_pinWrite(Uint32 pinId, Uint16 val) {
  Uint16 dev = ((pinId >> 16) & 0xffffu);
  Uint16 pin = (pinId & 0xffffu);
  Uint16 pin1,pin2;

   switch (dev) {
    case GPIO_GPIO: 
                        pin1 = (Uint16)(pin & 0xffu);
                        pin2 = (Uint16)((pin >> 8) & 0x3fu);
                        if (pin1) {
                            _GPIO_IODATA = (_GPIO_IODATA & (~pin1)) 
                                           | ((val) ? pin1:0);
                           return ((_GPIO_IODATA & pin1)? 1:0);
                        }
                        _GPIO_GPIODATA = (_GPIO_GPIODATA & (~(pin2)))
                                         | ((val)? pin2:0);
                        return ((_GPIO_GPIODATA & pin2)? 1:0);
    case GPIO_AGPIO:   
                        _GPIO_AGPIODATA = (_GPIO_AGPIODATA & ~pin) | 
                                         ((val) ? pin:0);
                        return  ((_GPIO_AGPIODATA & pin) ? 1:0);

    default:            return 0;
 }
}
/*----------------------------------------------------------------------------*/
IDEF int _PGPIO_pinRead(Uint32 pinId) {
  Uint16 dev = ((pinId >> 16) & 0xffffu);
  Uint16 pin = (pinId & 0xffffu);
  Uint16 pin1,pin2,val;

   switch (dev) {
    case GPIO_GPIO: 
                       pin1 = (pin & 0xffu);
                       pin2 = ((pin >> 8) & 0x3fu);
                       if (pin1) {
                          val = (_GPIO_IODATA & (pin1)) & (0xffu);
                       }
                       else {
                          val = ((_GPIO_GPIODATA & (pin2)) & 0x3fu);
                       }
                       return ((val) ? 1:0);
    case GPIO_AGPIO:   
                       return  ((_GPIO_AGPIODATA & pin) ? 1:0);

 
    default:           return 0;
  }
}
#endif   /* USEDEFS */
#else
  #ifndef _GPIO_MOD_ 			/* PGPIO_SUPPORT */
     #error PGPIO Module Not Supported on Specified Target TEST!!!
  #endif  
#endif 					/* PGPIO_SUPPORT */

#endif
/******************************************************************************\
* End of csl_PGPIO.h
\******************************************************************************/
