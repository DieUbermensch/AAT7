/******************************************************************************\
*           Copyright (C) 1999 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... IRQ
* FILENAME...... csl_irqhal.h
* DATE CREATED.. Sun 06/20/1999 
* PROJECT....... Chip Support Library
* COMPONENT..... HAL
* PREREQUISITS.. csl_stdinc.h, csl_stdinchal.h
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:       06/20/1999 
*   MODIFIED:      12/02/1999 Modified for TMS320C54xx
*   MODIFIED:      06/19/2000 header names consistent with #ifdefs, eliminate
*                             LIBBUILD 
*   MODIFIED:      07/11/2000 Modified for TMS320C5510
*   
*------------------------------------------------------------------------------
* DESCRIPTION:  (HAL interface file for the IRQ module)
*
* Registers Covered:
*
\******************************************************************************/
#ifndef _CSL_IRQHAL_H_
#define _CSL_IRQHAL_H_
  
#include <csl_chiphal.h>  
  
  
#if (_IRQ_SUPPORT)
/*============================================================================*\
* misc declarations
\*============================================================================*/
#define _IRQ_BASE_ADDR     (_CHIP_PERBASE_ADDR)


#elif (!(_IRQ_MOD_)) /* IRQ_SUPPORT */
  #error IRQ HAL Module Not Supported on Specified Target
#endif /* IRQ_SUPPORT */

#endif /* _CSL_IRQHAL_H_ */
/******************************************************************************\
* End of csl_irqhal.h
\******************************************************************************/

