/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... GPIO
* FILENAME...... csl_gpio.h
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
*   MODIFIED:   04/23/2002 added PGPIO support for 5502
*   MODIFIED:   10/06/2003 Fixed GPIO_open(),GPIO_close()and GPIO_pinDisable() bugs.
*   MODIFIED:   06/03/2004 Fixed C++ compiler warnings.
*   MODIFIED:   08/03/2004 Added 5501 chip type
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the GPIO module)
*
*
*
\******************************************************************************/
#ifndef _GPIO5502_H_
#define _GPIO5502_H_

#include <_csl.h>

#if (_GPIO_SUPPORT)

#include <csl_gpio5502hal.h>
#include <csl_gpio5502dat.h>

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
#define _GPIO_NON_PARALLEL           0
#define _GPIO_PARALLEL_0             1
#define _GPIO_PARALLEL_1             2
#define _GPIO_PARALLEL_2             3

/*=====================================================*\
* Define Symbolic Constants for PIN Names
\*=====================================================*/


#define GPIO_PIN0            (((Uint32)(_GPIO_NON_PARALLEL) << 16) | 0x0001u)
#define GPIO_PIN1            (((Uint32)(_GPIO_NON_PARALLEL) << 16) | 0x0002u)
#define GPIO_PIN2            (((Uint32)(_GPIO_NON_PARALLEL) << 16) | 0x0004u)
#define GPIO_PIN3            (((Uint32)(_GPIO_NON_PARALLEL) << 16) | 0x0008u)
#define GPIO_PIN4            (((Uint32)(_GPIO_NON_PARALLEL) << 16) | 0x0010u)
#define GPIO_PIN5            (((Uint32)(_GPIO_NON_PARALLEL) << 16) | 0x0020u)
#define GPIO_PIN6            (((Uint32)(_GPIO_NON_PARALLEL) << 16) | 0x0040u)
#define GPIO_PIN7            (((Uint32)(_GPIO_NON_PARALLEL) << 16) | 0x0080u)

#define GPIO_GPIO_PIN0        (((Uint32)(_GPIO_NON_PARALLEL) << 16) | 0x0001u)
#define GPIO_GPIO_PIN1        (((Uint32)(_GPIO_NON_PARALLEL) << 16) | 0x0002u)
#define GPIO_GPIO_PIN2        (((Uint32)(_GPIO_NON_PARALLEL) << 16) | 0x0004u)
#define GPIO_GPIO_PIN3        (((Uint32)(_GPIO_NON_PARALLEL) << 16) | 0x0008u)
#define GPIO_GPIO_PIN4        (((Uint32)(_GPIO_NON_PARALLEL) << 16) | 0x0010u)
#define GPIO_GPIO_PIN5        (((Uint32)(_GPIO_NON_PARALLEL) << 16) | 0x0020u)
#define GPIO_GPIO_PIN6        (((Uint32)(_GPIO_NON_PARALLEL) << 16) | 0x0040u)
#define GPIO_GPIO_PIN7        (((Uint32)(_GPIO_NON_PARALLEL) << 16) | 0x0080u)

#define GPIO_PGPIO_PIN0       (((Uint32)(_GPIO_PARALLEL_0) << 16) | 0x0001u) 
#define GPIO_PGPIO_PIN1       (((Uint32)(_GPIO_PARALLEL_0) << 16) | 0x0002u) 
#define GPIO_PGPIO_PIN2       (((Uint32)(_GPIO_PARALLEL_0) << 16) | 0x0004u) 
#define GPIO_PGPIO_PIN3       (((Uint32)(_GPIO_PARALLEL_0) << 16) | 0x0008u) 
#define GPIO_PGPIO_PIN4       (((Uint32)(_GPIO_PARALLEL_0) << 16) | 0x0010u) 
#define GPIO_PGPIO_PIN5       (((Uint32)(_GPIO_PARALLEL_0) << 16) | 0x0020u) 
#define GPIO_PGPIO_PIN6       (((Uint32)(_GPIO_PARALLEL_0) << 16) | 0x0040u) 
#define GPIO_PGPIO_PIN7       (((Uint32)(_GPIO_PARALLEL_0) << 16) | 0x0080u) 
#define GPIO_PGPIO_PIN8       (((Uint32)(_GPIO_PARALLEL_0) << 16) | 0x0100u) 
#define GPIO_PGPIO_PIN9       (((Uint32)(_GPIO_PARALLEL_0) << 16) | 0x0200u) 
#define GPIO_PGPIO_PIN10      (((Uint32)(_GPIO_PARALLEL_0) << 16) | 0x0400u) 
#define GPIO_PGPIO_PIN11      (((Uint32)(_GPIO_PARALLEL_0) << 16) | 0x0800u) 
#define GPIO_PGPIO_PIN12      (((Uint32)(_GPIO_PARALLEL_0) << 16) | 0x1000u) 
#define GPIO_PGPIO_PIN13      (((Uint32)(_GPIO_PARALLEL_0) << 16) | 0x2000u) 
#define GPIO_PGPIO_PIN14      (((Uint32)(_GPIO_PARALLEL_0) << 16) | 0x4000u) 
#define GPIO_PGPIO_PIN15      (((Uint32)(_GPIO_PARALLEL_0) << 16) | 0x8000u) 

#define GPIO_PGPIO_PIN16      (((Uint32)(_GPIO_PARALLEL_1) << 16) | 0x0001u) 
#define GPIO_PGPIO_PIN17      (((Uint32)(_GPIO_PARALLEL_1) << 16) | 0x0002u) 
#define GPIO_PGPIO_PIN18      (((Uint32)(_GPIO_PARALLEL_1) << 16) | 0x0004u) 
#define GPIO_PGPIO_PIN19      (((Uint32)(_GPIO_PARALLEL_1) << 16) | 0x0008u) 
#define GPIO_PGPIO_PIN20      (((Uint32)(_GPIO_PARALLEL_1) << 16) | 0x0010u) 
#define GPIO_PGPIO_PIN21      (((Uint32)(_GPIO_PARALLEL_1) << 16) | 0x0020u) 
#define GPIO_PGPIO_PIN22      (((Uint32)(_GPIO_PARALLEL_1) << 16) | 0x0040u) 
#define GPIO_PGPIO_PIN23      (((Uint32)(_GPIO_PARALLEL_1) << 16) | 0x0080u) 
#define GPIO_PGPIO_PIN24      (((Uint32)(_GPIO_PARALLEL_1) << 16) | 0x0100u) 
#define GPIO_PGPIO_PIN25      (((Uint32)(_GPIO_PARALLEL_1) << 16) | 0x0200u) 
#define GPIO_PGPIO_PIN26      (((Uint32)(_GPIO_PARALLEL_1) << 16) | 0x0400u) 
#define GPIO_PGPIO_PIN27      (((Uint32)(_GPIO_PARALLEL_1) << 16) | 0x0800u) 
#define GPIO_PGPIO_PIN28      (((Uint32)(_GPIO_PARALLEL_1) << 16) | 0x1000u) 
#define GPIO_PGPIO_PIN29      (((Uint32)(_GPIO_PARALLEL_1) << 16) | 0x2000u) 
#define GPIO_PGPIO_PIN30      (((Uint32)(_GPIO_PARALLEL_1) << 16) | 0x4000u) 
#define GPIO_PGPIO_PIN31      (((Uint32)(_GPIO_PARALLEL_1) << 16) | 0x8000u) 

#define GPIO_PGPIO_PIN32      (((Uint32)(_GPIO_PARALLEL_2) << 16) | 0x0001u) 
#define GPIO_PGPIO_PIN33      (((Uint32)(_GPIO_PARALLEL_2) << 16) | 0x0002u) 
#define GPIO_PGPIO_PIN34      (((Uint32)(_GPIO_PARALLEL_2) << 16) | 0x0004u) 
#define GPIO_PGPIO_PIN35      (((Uint32)(_GPIO_PARALLEL_2) << 16) | 0x0008u) 
#define GPIO_PGPIO_PIN36      (((Uint32)(_GPIO_PARALLEL_2) << 16) | 0x0010u) 
#define GPIO_PGPIO_PIN37      (((Uint32)(_GPIO_PARALLEL_2) << 16) | 0x0020u) 
#define GPIO_PGPIO_PIN38      (((Uint32)(_GPIO_PARALLEL_2) << 16) | 0x0040u) 
#define GPIO_PGPIO_PIN39      (((Uint32)(_GPIO_PARALLEL_2) << 16) | 0x0080u) 
#define GPIO_PGPIO_PIN40      (((Uint32)(_GPIO_PARALLEL_2) << 16) | 0x0100u) 
#define GPIO_PGPIO_PIN41      (((Uint32)(_GPIO_PARALLEL_2) << 16) | 0x0200u) 
#define GPIO_PGPIO_PIN42      (((Uint32)(_GPIO_PARALLEL_2) << 16) | 0x0400u) 
#define GPIO_PGPIO_PIN43      (((Uint32)(_GPIO_PARALLEL_2) << 16) | 0x0800u) 
#define GPIO_PGPIO_PIN44      (((Uint32)(_GPIO_PARALLEL_2) << 16) | 0x1000u) 
#define GPIO_PGPIO_PIN45      (((Uint32)(_GPIO_PARALLEL_2) << 16) | 0x2000u) 

/*=====================================================*\
* GPIO PIN Enable Masks           
\*=====================================================*/

#define GPIO_PIN0_ENABLE             (0x0001u)
#define GPIO_PIN1_ENABLE             (0x0002u)
#define GPIO_PIN2_ENABLE             (0x0004u)
#define GPIO_PIN3_ENABLE             (0x0008u)
#define GPIO_PIN4_ENABLE             (0x0010u)
#define GPIO_PIN5_ENABLE             (0x0020u)
#define GPIO_PIN6_ENABLE             (0x0040u)
#define GPIO_PIN7_ENABLE             (0x0080u)

#define GPIO_GPIO_PIN0_ENABLE        (0x0001u)
#define GPIO_GPIO_PIN1_ENABLE        (0x0002u)
#define GPIO_GPIO_PIN2_ENABLE        (0x0004u)
#define GPIO_GPIO_PIN3_ENABLE        (0x0008u)
#define GPIO_GPIO_PIN4_ENABLE        (0x0010u)
#define GPIO_GPIO_PIN5_ENABLE        (0x0020u)
#define GPIO_GPIO_PIN6_ENABLE        (0x0040u)
#define GPIO_GPIO_PIN7_ENABLE        (0x0080u)

#define GPIO_PGPIO_PIN0_ENABLE       (0x0001u) 
#define GPIO_PGPIO_PIN1_ENABLE       (0x0002u) 
#define GPIO_PGPIO_PIN2_ENABLE       (0x0004u) 
#define GPIO_PGPIO_PIN3_ENABLE       (0x0008u) 
#define GPIO_PGPIO_PIN4_ENABLE       (0x0010u) 
#define GPIO_PGPIO_PIN5_ENABLE       (0x0020u) 
#define GPIO_PGPIO_PIN6_ENABLE       (0x0040u) 
#define GPIO_PGPIO_PIN7_ENABLE       (0x0080u) 
#define GPIO_PGPIO_PIN8_ENABLE       (0x0100u) 
#define GPIO_PGPIO_PIN9_ENABLE       (0x0200u) 
#define GPIO_PGPIO_PIN10_ENABLE      (0x0400u) 
#define GPIO_PGPIO_PIN11_ENABLE      (0x0800u) 
#define GPIO_PGPIO_PIN12_ENABLE      (0x1000u) 
#define GPIO_PGPIO_PIN13_ENABLE      (0x2000u) 
#define GPIO_PGPIO_PIN14_ENABLE      (0x4000u) 
#define GPIO_PGPIO_PIN15_ENABLE      (0x8000u) 

#define GPIO_PGPIO_PIN16_ENABLE      (0x0001u) 
#define GPIO_PGPIO_PIN17_ENABLE      (0x0002u) 
#define GPIO_PGPIO_PIN18_ENABLE      (0x0004u) 
#define GPIO_PGPIO_PIN19_ENABLE      (0x0008u) 
#define GPIO_PGPIO_PIN20_ENABLE      (0x0010u) 
#define GPIO_PGPIO_PIN21_ENABLE      (0x0020u) 
#define GPIO_PGPIO_PIN22_ENABLE      (0x0040u) 
#define GPIO_PGPIO_PIN23_ENABLE      (0x0080u) 
#define GPIO_PGPIO_PIN24_ENABLE      (0x0100u) 
#define GPIO_PGPIO_PIN25_ENABLE      (0x0200u) 
#define GPIO_PGPIO_PIN26_ENABLE      (0x0400u) 
#define GPIO_PGPIO_PIN27_ENABLE      (0x0800u) 
#define GPIO_PGPIO_PIN28_ENABLE      (0x1000u) 
#define GPIO_PGPIO_PIN29_ENABLE      (0x2000u) 
#define GPIO_PGPIO_PIN30_ENABLE      (0x4000u) 
#define GPIO_PGPIO_PIN31_ENABLE      (0x8000u) 

#define GPIO_PGPIO_PIN32_ENABLE      (0x0001u) 
#define GPIO_PGPIO_PIN33_ENABLE      (0x0002u) 
#define GPIO_PGPIO_PIN34_ENABLE      (0x0004u) 
#define GPIO_PGPIO_PIN35_ENABLE      (0x0008u) 
#define GPIO_PGPIO_PIN36_ENABLE      (0x0010u) 
#define GPIO_PGPIO_PIN37_ENABLE      (0x0020u) 
#define GPIO_PGPIO_PIN38_ENABLE      (0x0040u) 
#define GPIO_PGPIO_PIN39_ENABLE      (0x0080u) 
#define GPIO_PGPIO_PIN40_ENABLE      (0x0100u) 
#define GPIO_PGPIO_PIN41_ENABLE      (0x0200u) 
#define GPIO_PGPIO_PIN42_ENABLE      (0x0400u) 
#define GPIO_PGPIO_PIN43_ENABLE      (0x0800u) 
#define GPIO_PGPIO_PIN44_ENABLE      (0x1000u) 
#define GPIO_PGPIO_PIN45_ENABLE      (0x2000u) 

/*=====================================================*\
* GPIO PIN Direction Masks           
\*=====================================================*/

#define GPIO_PIN0_OUTPUT             (0x0001u)
#define GPIO_PIN1_OUTPUT             (0x0002u)
#define GPIO_PIN2_OUTPUT             (0x0004u)
#define GPIO_PIN3_OUTPUT             (0x0008u)
#define GPIO_PIN4_OUTPUT             (0x0010u)
#define GPIO_PIN5_OUTPUT             (0x0020u)
#define GPIO_PIN6_OUTPUT             (0x0040u)
#define GPIO_PIN7_OUTPUT             (0x0080u)

#define GPIO_GPIO_PIN0_OUTPUT        (0x0001u)
#define GPIO_GPIO_PIN1_OUTPUT        (0x0002u)
#define GPIO_GPIO_PIN2_OUTPUT        (0x0004u)
#define GPIO_GPIO_PIN3_OUTPUT        (0x0008u)
#define GPIO_GPIO_PIN4_OUTPUT        (0x0010u)
#define GPIO_GPIO_PIN5_OUTPUT        (0x0020u)
#define GPIO_GPIO_PIN6_OUTPUT        (0x0040u)
#define GPIO_GPIO_PIN7_OUTPUT        (0x0080u)

#define GPIO_PGPIO_PIN0_OUTPUT       (0x0001u) 
#define GPIO_PGPIO_PIN1_OUTPUT       (0x0002u) 
#define GPIO_PGPIO_PIN2_OUTPUT       (0x0004u) 
#define GPIO_PGPIO_PIN3_OUTPUT       (0x0008u) 
#define GPIO_PGPIO_PIN4_OUTPUT       (0x0010u) 
#define GPIO_PGPIO_PIN5_OUTPUT       (0x0020u) 
#define GPIO_PGPIO_PIN6_OUTPUT       (0x0040u) 
#define GPIO_PGPIO_PIN7_OUTPUT       (0x0080u) 
#define GPIO_PGPIO_PIN8_OUTPUT       (0x0100u) 
#define GPIO_PGPIO_PIN9_OUTPUT       (0x0200u) 
#define GPIO_PGPIO_PIN10_OUTPUT      (0x0400u) 
#define GPIO_PGPIO_PIN11_OUTPUT      (0x0800u) 
#define GPIO_PGPIO_PIN12_OUTPUT      (0x1000u) 
#define GPIO_PGPIO_PIN13_OUTPUT      (0x2000u) 
#define GPIO_PGPIO_PIN14_OUTPUT      (0x4000u) 
#define GPIO_PGPIO_PIN15_OUTPUT      (0x8000u) 

#define GPIO_PGPIO_PIN16_OUTPUT      (0x0001u) 
#define GPIO_PGPIO_PIN17_OUTPUT      (0x0002u) 
#define GPIO_PGPIO_PIN18_OUTPUT      (0x0004u) 
#define GPIO_PGPIO_PIN19_OUTPUT      (0x0008u) 
#define GPIO_PGPIO_PIN20_OUTPUT      (0x0010u) 
#define GPIO_PGPIO_PIN21_OUTPUT      (0x0020u) 
#define GPIO_PGPIO_PIN22_OUTPUT      (0x0040u) 
#define GPIO_PGPIO_PIN23_OUTPUT      (0x0080u) 
#define GPIO_PGPIO_PIN24_OUTPUT      (0x0100u) 
#define GPIO_PGPIO_PIN25_OUTPUT      (0x0200u) 
#define GPIO_PGPIO_PIN26_OUTPUT      (0x0400u) 
#define GPIO_PGPIO_PIN27_OUTPUT      (0x0800u) 
#define GPIO_PGPIO_PIN28_OUTPUT      (0x1000u) 
#define GPIO_PGPIO_PIN29_OUTPUT      (0x2000u) 
#define GPIO_PGPIO_PIN30_OUTPUT      (0x4000u) 
#define GPIO_PGPIO_PIN31_OUTPUT      (0x8000u) 

#define GPIO_PGPIO_PIN32_OUTPUT      (0x0001u) 
#define GPIO_PGPIO_PIN33_OUTPUT      (0x0002u) 
#define GPIO_PGPIO_PIN34_OUTPUT      (0x0004u) 
#define GPIO_PGPIO_PIN35_OUTPUT      (0x0008u) 
#define GPIO_PGPIO_PIN36_OUTPUT      (0x0010u) 
#define GPIO_PGPIO_PIN37_OUTPUT      (0x0020u) 
#define GPIO_PGPIO_PIN38_OUTPUT      (0x0040u) 
#define GPIO_PGPIO_PIN39_OUTPUT      (0x0080u) 
#define GPIO_PGPIO_PIN40_OUTPUT      (0x0100u) 
#define GPIO_PGPIO_PIN41_OUTPUT      (0x0200u) 
#define GPIO_PGPIO_PIN42_OUTPUT      (0x0400u) 
#define GPIO_PGPIO_PIN43_OUTPUT      (0x0800u) 
#define GPIO_PGPIO_PIN44_OUTPUT      (0x1000u) 
#define GPIO_PGPIO_PIN45_OUTPUT      (0x2000u) 

#define GPIO_PIN0_INPUT             (0x0001u)
#define GPIO_PIN1_INPUT             (0x0002u)
#define GPIO_PIN2_INPUT             (0x0004u)
#define GPIO_PIN3_INPUT             (0x0008u)
#define GPIO_PIN4_INPUT             (0x0010u)
#define GPIO_PIN5_INPUT             (0x0020u)
#define GPIO_PIN6_INPUT             (0x0040u)
#define GPIO_PIN7_INPUT             (0x0080u)

#define GPIO_GPIO_PIN0_INPUT        (0x0000u)
#define GPIO_GPIO_PIN1_INPUT        (0x0000u)
#define GPIO_GPIO_PIN2_INPUT        (0x0000u)
#define GPIO_GPIO_PIN3_INPUT        (0x0000u)
#define GPIO_GPIO_PIN4_INPUT        (0x0000u)
#define GPIO_GPIO_PIN5_INPUT        (0x0000u)
#define GPIO_GPIO_PIN6_INPUT        (0x0000u)
#define GPIO_GPIO_PIN7_INPUT        (0x0000u)

#define GPIO_PGPIO_PIN0_INPUT       (0x0000u) 
#define GPIO_PGPIO_PIN1_INPUT       (0x0000u) 
#define GPIO_PGPIO_PIN2_INPUT       (0x0000u) 
#define GPIO_PGPIO_PIN3_INPUT       (0x0000u) 
#define GPIO_PGPIO_PIN4_INPUT       (0x0000u) 
#define GPIO_PGPIO_PIN5_INPUT       (0x0000u) 
#define GPIO_PGPIO_PIN6_INPUT       (0x0000u) 
#define GPIO_PGPIO_PIN7_INPUT       (0x0000u) 
#define GPIO_PGPIO_PIN8_INPUT       (0x0000u) 
#define GPIO_PGPIO_PIN9_INPUT       (0x0000u) 
#define GPIO_PGPIO_PIN10_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN11_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN12_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN13_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN14_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN15_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN16_INPUT      (0x0000u) 

#define GPIO_PGPIO_PIN17_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN18_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN19_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN20_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN21_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN22_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN23_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN24_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN25_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN26_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN27_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN28_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN29_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN30_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN31_INPUT      (0x0000u) 

#define GPIO_PGPIO_PIN32_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN33_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN34_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN35_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN36_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN37_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN38_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN39_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN40_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN41_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN42_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN43_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN44_INPUT      (0x0000u) 
#define GPIO_PGPIO_PIN45_INPUT      (0x0000u) 


#define GPIO_INPUT           (0x0000u)
#define GPIO_OUTPUT          (0x0001u)

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
(Uint16) (	GPIO_FMK(IODATA,IO0DAT,io0) |	\
		GPIO_FMK(IODATA,IO1DAT,io1) |	\
		GPIO_FMK(IODATA,IO2DAT,io2) |	\
		GPIO_FMK(IODATA,IO3DAT,io3) |	\
		GPIO_FMK(IODATA,IO4DAT,io4) |	\
		GPIO_FMK(IODATA,IO5DAT,io5) |	\
		GPIO_FMK(IODATA,IO6DAT,io6) |	\
		GPIO_FMK(IODATA,IO7DAT,io7) 	\
	   ))

/***************************************\
* GPIO COnfiguration Structure
\***************************************/
typedef struct {
      Uint16 iodir;
#if (CHIP_5509)
      Uint16 pgpioen0;
      Uint16 pgpiodir0;
      Uint16 pgpioen1;
      Uint16 pgpiodir1;
#endif
#if (CHIP_5502) || (CHIP_5501)
      Uint16 pgpioen0;
      Uint16 pgpiodir0;
      Uint16 pgpioen1;
      Uint16 pgpiodir1;
      Uint16 pgpioen2;
      Uint16 pgpiodir2;
#endif
} GPIO_ConfigAll;

typedef struct {
#if (_GPIO_PARALLEL_SUPPORT)
     Uint16 ioen;
#endif
     Uint16 iodir;
} GPIO_Config;
     

typedef struct {
    Uint16 Private;
}GPIO_Obj, *GPIO_Handle;

/****************************************\
* GIO function declarations        
\****************************************/
IDECL  GPIO_Handle GPIO_open(Uint32 allocmask, Uint32 flags);
IDECL  void GPIO_close(GPIO_Handle hGpio);
IDECL  void GPIO_config(GPIO_Handle hGpio, GPIO_Config *pinCfg);

#if (_GPIO_PARALLEL_SUPPORT)
IDECL void GPIO_configArgs(GPIO_Handle hGpio, Uint32 enabMask, Uint16 direction);
#else
IDECL void GPIO_configArgs(GPIO_Handle hGpio, Uint16 direction);
#endif

IDECL  void GPIO_configAll(GPIO_ConfigAll *gCfg);
#if (CHIP_5502) || (CHIP_5501)
IDECL  void GPIO_configAllArgs(GPIO_Handle hGpio, Uint16 iodir, Uint16 pgpioen0, Uint16 pgpiodir0,
       Uint16 pgpioen1, Uint16 pgpiodir1, Uint16 pgpioen2, Uint16 pgpiodir2);
#elif (CHIP_5509)
IDECL   void GPIO_configAllArgs(GPIO_Handle hGpio, Uint16 iodir, Uint16 pgpioen0, Uint16 pgpiodir0,
         Uint16 pgpioen1, Uint16 pgpiodir1);
#else
IDECL   void GPIO_configAllArgs(GPIO_Handle hGpio, Uint16 iodir);
#endif

IDECL  void GPIO_pinEnable(GPIO_Handle hGpio, Uint32 pinMask);
IDECL  void GPIO_pinDisable(GPIO_Handle hGpio, Uint32 pinMask);
IDECL  void GPIO_pinDirection(GPIO_Handle hGpio, Uint32 pinMask, Uint16 direction);
IDECL  int  GPIO_pinRead(GPIO_Handle hGpio, Uint32 pinId);
IDECL  void GPIO_pinWrite(GPIO_Handle hGpio, Uint32 pinId, Uint16 val);
IDECL  int  GPIO_pinReadAll(GPIO_Handle hGpio, Uint32 pinMask);
IDECL  void GPIO_pinWriteAll(GPIO_Handle hGpio, Uint32 pinMask, Uint16 pinVals);
IDECL  void  GPIO_pinReset(GPIO_Handle hGpio, Uint32 pinMask);


/****************************************\
* GPIO Inline Functions
\****************************************/

#ifdef USEDEFS
/*------------------------------------------------------*/
IDEF void GPIO_close(GPIO_Handle hGpio) {
   GPIO_PrivateObj *ptr = (GPIO_PrivateObj *)hGpio;
   Uint16 regIndx = ptr->regIndx;

   (CSL_SYS_DATA).GpioAllocMask[regIndx] = 0;
   ptr->pinsAllocated = 0x0000;
}
  
/*------------------------------------------------------*/
IDEF void GPIO_config(GPIO_Handle hGpio, GPIO_Config *cfg) {
   GPIO_PrivateObj *ptr = (GPIO_PrivateObj *)hGpio;
  
   if (ptr->regIndx == _GPIO_NON_PARALLEL) {
      *((ioport Uint16 *)(ptr->dirReg)) = cfg->iodir;
      return;
   }
   *((ioport Uint16 *)(ptr->enableReg)) = cfg->ioen & (ptr->pinsAllocated);
   *((ioport Uint16 *)(ptr->dirReg)) = cfg->iodir;
}
/*------------------------------------------------------*/
#if (_GPIO_PARALLEL_SUPPORT)
IDEF void GPIO_configArgs(GPIO_Handle hGpio, Uint32 enabMask, Uint16 direction) {
#else
IDEF void GPIO_configArgs(GPIO_Handle hGpio, Uint16 direction) {
#endif
    GPIO_PrivateObj *ptr = (GPIO_PrivateObj *)hGpio;

    if (ptr->regIndx == _GPIO_NON_PARALLEL) {
      *(ioport Uint16 *)(ptr->dirReg) = direction;
      return;
    }

    *(ioport Uint16 *)(ptr->enableReg) = enabMask & (ptr->pinsAllocated);
}
/*------------------------------------------------------*/
IDEF void GPIO_configAll(GPIO_ConfigAll *gCfg) {

     GPIO_RSET(IODIR,gCfg->iodir);
#if (_GPIO_PARALLEL_SUPPORT)
      GPIO_RSET(PGPIOEN0,gCfg->pgpioen0);
      GPIO_RSET(PGPIODIR0,gCfg->pgpiodir0);
      GPIO_RSET(PGPIOEN1,gCfg->pgpioen1);
      GPIO_RSET(PGPIODIR1,gCfg->pgpiodir1);
#if (CHIP_5502) || (CHIP_5501)
      GPIO_RSET(PGPIOEN2,gCfg->pgpioen2);
      GPIO_RSET(PGPIODIR2,gCfg->pgpiodir2);
#endif
#endif
}
/*------------------------------------------------------*/
#if (CHIP_5502) || (CHIP_5501)
IDEF  void GPIO_configAllArgs(GPIO_Handle hGpio, Uint16 iodir, Uint16 pgpioen0, Uint16 pgpiodir0,
       Uint16 pgpioen1, Uint16 pgpiodir1, Uint16 pgpioen2, Uint16 pgpiodir2) {
#elif (CHIP_5509)
IDEF  void GPIO_configAllArgs(GPIO_Handle hGpio, Uint16 iodir, Uint16 pgpioen0, Uint16 pgpiodir0,
        Uint16 pgpioen1, Uint16 pgpiodir1) {
#else
IDEF  void GPIO_configAllArgs(GPIO_Handle hGpio, Uint16 iodir) {
#endif

     GPIO_RSET(IODIR,iodir);
#if (_GPIO_PARALLEL_SUPPORT)
      GPIO_RSET(PGPIOEN0,pgpioen0);
      GPIO_RSET(PGPIODIR0,pgpiodir0);
      GPIO_RSET(PGPIOEN1,pgpioen1);
      GPIO_RSET(PGPIODIR1,pgpiodir1);
#if (CHIP_5502) || (CHIP_5501)
      GPIO_RSET(PGPIOEN2,pgpioen2);
      GPIO_RSET(PGPIODIR2,pgpiodir2);
#endif
#endif
}
/*----------------------------------------------------------------------------*/
IDEF GPIO_Handle GPIO_open(Uint32 allocMask, Uint32 flags){
  Uint16 regIndx = (Uint16)((allocMask >> 16) & 0xFFFFu);
  Uint16 pinMask = (Uint16)(allocMask & 0xFFFFu); 
  Uint16 old_intm;

  GPIO_PrivateObj *ptr = (GPIO_PrivateObj *)INV;
  old_intm = IRQ_globalDisable();

  if (!((CSL_SYS_DATA).GpioAllocMask[regIndx] )) {
      (CSL_SYS_DATA).GpioAllocMask[regIndx] = pinMask; /*allocated;*/
      ptr = (GPIO_PrivateObj *)(&((CSL_GPIO_DATA).pinObj[regIndx]));
      ptr->regIndx = regIndx;
      ptr->pinsAllocated = pinMask;
  }
  IRQ_globalRestore(old_intm);
  
  return (GPIO_Handle)(ptr);
}

/*------------------------------------------------------*/
IDEF void GPIO_pinEnable(GPIO_Handle hGpio, Uint32 pinId){
  GPIO_PrivateObj *ptr = (GPIO_PrivateObj *)hGpio;
  Uint16 allocMask;
  Uint16 pin = (Uint16)(pinId & 0xFFFFu);

   allocMask = ptr->pinsAllocated;
   if (ptr->regIndx == _GPIO_NON_PARALLEL) {
     return;
   }
   *((ioport Uint16 *)(ptr->enableReg)) = *((ioport Uint16 *)(ptr->enableReg)) 
                                          | (allocMask & pin);

}
/*------------------------------------------------------*/
IDEF void GPIO_pinDisable(GPIO_Handle hGpio, Uint32 pinId){
  GPIO_PrivateObj *ptr = (GPIO_PrivateObj *)hGpio;
  Uint16 allocMask;
  Uint16 pin = (Uint16)(pinId & 0xFFFFu);

   if (ptr->regIndx == _GPIO_NON_PARALLEL) {
     return;
   }
   allocMask = ptr->pinsAllocated;
   *((ioport Uint16 *)(ptr->enableReg)) = (*((ioport Uint16 *)(ptr->enableReg))) 
                                          & (~(allocMask & pin));

}
/*------------------------------------------------------*/
IDEF void GPIO_pinDirection(GPIO_Handle hGpio, Uint32 pinMask, Uint16 direction){
   GPIO_PrivateObj *ptr = (GPIO_PrivateObj *)hGpio;
   Uint16 pins = (Uint16)(pinMask & 0xFFFFu);
   Uint16 allocMask = ptr->pinsAllocated;
   *((ioport Uint16 *)(ptr->dirReg)) = ((*((ioport Uint16 *)(ptr->dirReg))) 
                                       & (~(allocMask & pins))) | ((direction) ? pins:0x0000u);
}
/*------------------------------------------------------*/
IDEF int GPIO_pinRead(GPIO_Handle hGpio, Uint32 pinId){
  GPIO_PrivateObj *ptr = (GPIO_PrivateObj *)hGpio;  
  Uint16 pins = (Uint16)(pinId & 0xFFFFu);
  Uint16 val;
  
  val =  ((*((ioport Uint16 *)(ptr->datReg))) & (ptr->pinsAllocated & pins));
  return (val ? 1:0);
}
/*------------------------------------------------------*/
IDEF int GPIO_pinReadAll(GPIO_Handle hGpio, Uint32 pinMask){
  GPIO_PrivateObj *ptr = (GPIO_PrivateObj *)hGpio;  
  Uint16 pins = (Uint16)(pinMask & 0xFFFFu);
  Uint16 val;
  
  val =  ((*((ioport Uint16 *)(ptr->datReg))) & (ptr->pinsAllocated & pins));
  return (val);
}
/*------------------------------------------------------*/
IDEF void GPIO_pinWrite(GPIO_Handle hGpio, Uint32 pinMask, Uint16 val){
  GPIO_PrivateObj *ptr = (GPIO_PrivateObj *)hGpio;  
  Uint16 pins = (Uint16)(pinMask & 0xFFFFu);
  Uint16 allocMask = ptr->pinsAllocated;
   *((ioport Uint16 *)(ptr->datReg)) = ((*((ioport Uint16 *)(ptr->datReg))) 
                                       & (~(allocMask & pins))) | ((val) ? pins:0x0000u);
}
/*------------------------------------------------------*/
IDEF void GPIO_pinWriteAll(GPIO_Handle hGpio, Uint32 pinMask, Uint16 val){
  GPIO_PrivateObj *ptr = (GPIO_PrivateObj *)hGpio;  
  Uint16 pins = (Uint16)(pinMask & 0xFFFFu);
  Uint16 allocMask = ptr->pinsAllocated;
   *((ioport Uint16 *)(ptr->datReg)) = ((*((ioport Uint16 *)(ptr->datReg))) 
                                       & (~(allocMask & pins))) | val;
}
/*------------------------------------------------------*/
IDEF void GPIO_pinReset(GPIO_Handle hGpio, Uint32 pinMask) {
  GPIO_PrivateObj *ptr = (GPIO_PrivateObj *)hGpio;
  Uint16 allocMask = ptr->pinsAllocated;

#if (_GPIO_PARALLEL_SUPPORT)
  *((ioport Uint16 *)(ptr->enableReg)) = *(ioport Uint16 *)(ptr->enableReg)
                                       & (~(allocMask & pinMask));
#endif
  *((ioport Uint16 *)(ptr->dirReg)) = (*((ioport Uint16 *)(ptr->dirReg)) &
                                    (~(allocMask & pinMask)));
}

#endif  // USEDEFS

#else
  #ifndef _GPIO_MOD_ 			/* GPIO_SUPPORT */
    #error GPIO Module Not Supported on Specified Target TEST!!!  
  #endif
#endif 					/* GPIO_SUPPORT */

#endif 					/* _GPIO_H_ */
/******************************************************************************\
* End of csl_gpio.h
\******************************************************************************/

