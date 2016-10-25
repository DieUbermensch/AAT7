/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... GPIO
* FILENAME...... _csl_gpio.h
* DATE CREATED.. Fri 06/09/2000 
* PROJECT....... Chip Support Library
* COMPONENT..... CSL service layer
* PREREQUISITS.. 
* VERSION....... 1.00
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:    06/09/2000 created for C5510
*   MODIFIED:   04/16/2001 updated module name and other header comments
*   MODIFIED:   01/22/2002 fixed pinDir and pinWrit so they dont affect
*                          just PIN0
*   MODIFIED:   04/04/2002 added GPIO_PIN definitions
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the GPIO module)
*
*
*
\******************************************************************************/
#ifndef _GPIO_H_
#define _GPIO_H_

#include <_csl.h>
#include <csl_gpiohal.h>

#if (_GPIO_SUPPORT) | (_GPIO_PGPIO_SUPPORT)
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

#if (!(_GPIO_PGPIO_SUPPORT))
#define GPIO_PIN0            (((Uint32)(GPIO_GPIO) << 16) | 0x0001u)
#define GPIO_PIN1            (((Uint32)(GPIO_GPIO) << 16) | 0x0002u)
#define GPIO_PIN2            (((Uint32)(GPIO_GPIO) << 16) | 0x0004u)
#define GPIO_PIN3            (((Uint32)(GPIO_GPIO) << 16) | 0x0008u)
#define GPIO_PIN4            (((Uint32)(GPIO_GPIO) << 16) | 0x0010u)
#define GPIO_PIN5            (((Uint32)(GPIO_GPIO) << 16) | 0x0020u)
#define GPIO_PIN6            (((Uint32)(GPIO_GPIO) << 16) | 0x0040u)
#define GPIO_PIN7            (((Uint32)(GPIO_GPIO) << 16) | 0x0080u)

#define GPIO_INPUT           (0x0000u)
#define GPIO_OUTPUT          (0x0001u)
#endif

/* Configure GIO (General Purpose I/O) Pins */
#define GPIO_IODIR_IODIR0_EN         (0x0001u)
#define GPIO_IODIR_IODIR1_EN         (0x0002u)
#define GPIO_IODIR_IODIR2_EN         (0x0004u)
#define GPIO_IODIR_IODIR3_EN         (0x0008u)
#define GPIO_IODIR_IODIR4_EN         (0x0010u)
#define GPIO_IODIR_IODIR5_EN         (0x0020u)
#define GPIO_IODIR_IODIR6_EN         (0x0040u)
#define GPIO_IODIR_IODIR7_EN         (0x0080u)

#define GPIO_IODIR_IODIR0            (0x0001u)
#define GPIO_IODIR_IODIR1            (0x0002u)
#define GPIO_IODIR_IODIR2            (0x0004u)
#define GPIO_IODIR_IODIR3            (0x0008u)
#define GPIO_IODIR_IODIR4            (0x0010u)
#define GPIO_IODIR_IODIR5            (0x0020u)
#define GPIO_IODIR_IODIR6            (0x0040u)
#define GPIO_IODIR_IODIR7            (0x0080u)

#define GPIO_IODIR_IO0DIR            (0x0001u)
#define GPIO_IODIR_IO1DIR            (0x0002u)
#define GPIO_IODIR_IO2DIR            (0x0004u)
#define GPIO_IODIR_IO3DIR            (0x0008u)
#define GPIO_IODIR_IO4DIR            (0x0010u)
#define GPIO_IODIR_IO5DIR            (0x0020u)
#define GPIO_IODIR_IO6DIR            (0x0040u)
#define GPIO_IODIR_IO7DIR            (0x0080u)

#define GPIO_IODATA_IOD0_O	       (0x0001u)
#define GPIO_IODATA_IOD1_O           (0x0002u)
#define GPIO_IODATA_IOD2_O           (0x0004u)
#define GPIO_IODATA_IOD3_O           (0x0008u)
#define GPIO_IODATA_IOD4_O           (0x0010u)
#define GPIO_IODATA_IOD5_O           (0x0020u)
#define GPIO_IODATA_IOD6_O           (0x0040u)
#define GPIO_IODATA_IOD7_O           (0x0080u)

#define GPIO_IODATA_IO0DIR_OUTPUT	 (0x0001u)
#define GPIO_IODATA_IO1DIR_OUTPUT    (0x0002u)
#define GPIO_IODATA_IO2DIR_OUTPUT    (0x0004u)
#define GPIO_IODATA_IO3DIR_OUTPUT    (0x0008u)
#define GPIO_IODATA_IO4DIR_OUTPUT    (0x0010u)
#define GPIO_IODATA_IO5DIR_OUTPUT    (0x0020u)
#define GPIO_IODATA_IO6DIR_OUTPUT    (0x0040u)
#define GPIO_IODATA_IO7DIR_OUTPUT    (0x0080u)


#define GPIO_IODATA_IOD0_I           (0x0000u)
#define GPIO_IODATA_IOD1_I           (0x0000u)
#define GPIO_IODATA_IOD2_I           (0x0000u)
#define GPIO_IODATA_IOD3_I           (0x0000u)
#define GPIO_IODATA_IOD4_I           (0x0000u)
#define GPIO_IODATA_IOD5_I           (0x0000u)
#define GPIO_IODATA_IOD6_I           (0x0000u)
#define GPIO_IODATA_IOD7_I           (0x0000u)

#define GPIO_IODATA_IO0DIR_INPUT      (0x0000u)
#define GPIO_IODATA_IO1DIR_INPUT      (0x0000u)
#define GPIO_IODATA_IO2DIR_INPUT      (0x0000u)
#define GPIO_IODATA_IO3DIR_INPUT      (0x0000u)
#define GPIO_IODATA_IO4DIR_INPUT      (0x0000u)
#define GPIO_IODATA_IO5DIR_INPUT      (0x0000u)
#define GPIO_IODATA_IO6DIR_INPUT      (0x0000u)
#define GPIO_IODATA_IO7DIR_INPUT      (0x0000u)

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
(Uint16) (	GPIO_FMK(IODATA,IO0D,io0) |	\
		GPIO_FMK(IODATA,IO1D,io1) |	\
		GPIO_FMK(IODATA,IO2D,io2) |	\
		GPIO_FMK(IODATA,IO3D,io3) |	\
		GPIO_FMK(IODATA,IO4D,io4) |	\
		GPIO_FMK(IODATA,IO5D,io5) |	\
		GPIO_FMK(IODATA,IO6D,io6) |	\
		GPIO_FMK(IODATA,IO7D,io7) 	\
	   ))

/***************************************\
* Overload GPIO functions
\***************************************/
#define GPIO_pinEnable        _GPIO_pinEnable
#define GPIO_pinDisable       _GPIO_pinDisable
#define GPIO_pinDirection     _GPIO_pinDirection
#define GPIO_pinRead          _GPIO_pinRead
#define GPIO_pinWrite         _GPIO_pinWrite

/****************************************\
* GIO function declarations        
\****************************************/
IDECL  int _GPIO_pinEnable(Uint32 pinId);
IDECL  int _GPIO_pinDisable(Uint32 pinId);
IDECL  int _GPIO_pinDirection(Uint32 pinId, Uint16 direction);
IDECL  int _GPIO_pinRead(Uint32 pinId);
IDECL  int _GPIO_pinWrite(Uint32 pinId, Uint16 val);

/****************************************\
* GPIO Inline Functions
\****************************************/

#ifdef USEDEFS

/*------------------------------------------------------*/
IDEF int _GPIO_pinEnable(Uint32 pinId){
  return 1;
}
/*------------------------------------------------------*/
IDEF int _GPIO_pinDisable(Uint32 pinId){
  return 1;
}
/*------------------------------------------------------*/
IDEF int _GPIO_pinDirection(Uint32 pinId, Uint16 direction){
   Uint16 pin = (Uint16)(pinId & 0xFFFFu);
  _GPIO_IODIR = (_GPIO_IODIR & ~(pin)) | ((direction) ? pin:0);
  return ((_GPIO_IODIR & pin) ? 1:0);
}
/*------------------------------------------------------*/
IDEF int _GPIO_pinRead(Uint32 pinId){
  Uint16 pin = (Uint16)(pinId & 0xFFFFu);
  return ((_GPIO_IODIR & pin) ? 1:0);
}
/*------------------------------------------------------*/
IDEF int _GPIO_pinWrite(Uint32 pinId, Uint16 val){
  Uint16 pin = (Uint16)(pinId & 0xFFFFu);
  _GPIO_IODIR = (_GPIO_IODIR & (~pin)) | ((val) ? pin:0);
  return ((_GPIO_IODIR & pin) ? 1:0);
}
#endif  // USEDEFS

#else
  #ifndef _GPIO_MOD_ 			/* GPIO_SUPPORT */
    #error GPIO Module Not Supported on Specified Target TEST!!!  
  #endif
#endif 					/* GPIO_SUPPORT */

#endif 					/* _GPIO_H_ */
/******************************************************************************\
* End of _csl_gpio.h
\******************************************************************************/
