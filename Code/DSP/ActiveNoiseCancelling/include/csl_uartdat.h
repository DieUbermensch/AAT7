/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... UART
* FILENAME...... csl_UARTdat.h
* DATE CREATED.. Thu 03/30/2000 
* PROJECT....... CSL  - Chip Support Library
* COMPONENT..... CSL service layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:       02/13/2002
*   MODIFIED:      10 Apri 2003 Added reference for CSL_UartData for .csldata size
*                               fix
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the UART module)
*       Reserved Area for UART Data 
*
*
\******************************************************************************/
#ifndef _UART_DATA_H_
#define _UART_DATA_H_

  #include <csl_std.h>

     #define CSL_UARTDATAINIT\
     { 0x0000u,\
       0x0000u,\
       0x0000u,\
       0x0000u,\
       0x0000u,\
       0x0000u,\
       0x0000u,\
    }
    typedef struct {
      Uint32 UART_isrDispatchTable[7];
    } CSL_UartDataObj;

extern CSL_UartDataObj CSL_UartData;

#define CSL_UART_DATA  CSL_UartData

#endif
