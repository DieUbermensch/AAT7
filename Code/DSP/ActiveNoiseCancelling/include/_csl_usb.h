/******************************************************************************/
/* File Name: _usb_api.h, 04 Feb 2001                                         */
/*                                                                            */
/* This is proprietary information, not to be published -- TI INTERNAL DATA   */
/* Copyright (C) 1999, Texas Instruments, Inc.  All Rights Reserved.          */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* Author: MH                                                                 */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Private header file for USB firmware API.                                  */
/* Do not make any changes to the content of this file                        */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Modified last: 04 Feb 2001                                                 */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
 
#ifndef __CSL_USB_H
#define __CSL_USB_H

#include <_csl.h>

#if (_USB_SUPPORT)

#include <csl_usbhal.h>
#include <csl_usb.h>
#include <_csl_usbdrvr.h>
#include <_csl_usb_apimap.h>

/******************************************************************************/
/*                                                                            */
/*                          Symbolic Constants                                */
/*                                                                            */
/******************************************************************************/

#define MAX_ENDPT    16                 /* max number of endpoints supported  */

/******************************************************************************/
/*                                                                            */
/*               Initialization constants for USB module config               */
/*                                                                            */
/******************************************************************************/

#define USBIE_INIT        (USB_INT_RSTR|USB_INT_RESR|USB_INT_SUSR|USB_INT_SETUP|USB_INT_STPOW)
/*#define XY_SIZE_INIT      0x40*/
#define USBCNF0_INIT      (USBEPCNF_UBME|USBEPCNF_USBIE)
/*
#define USB_EPXCNF_INIT   (USBEPCNF_DBUF)
*/
#define USBEPCNF_INIT     (USBEPCNF_UBME|USBEPCNF_DBUF|USBEPCNF_USBIE)
#define USBCTL_INIT       (USBCTL_FEN | USBCTL_FRSTE)

/******************************************************************************/
/*                                                                            */
/*               Internal Flags used by USB data transfer APIs                */
/*                                                                            */
/******************************************************************************/

/* 02/15/01 $MH$ - redefined USB_INOUT_FLAGS */
/* Low byte is allocated for user's flags, high byte for internal flags */
/*#define USB_INOUT_FLAGS_NEW      0x0001   */  /* for internal use               */
/*#define USB_INOUT_FLAGS_BYTE     0x0002   */  /* for internal use               */
/*#define USB_INOUT_FLAGS_STALL    0x0004   */  /* for internal use               */
/*#define USB_INOUT_FLAGS_RESET    0x0008   */  /* for internal use               */
/*#define USB_INOUT_FLAGS_DATAREQ  0x0020   */  /* for internal use               */
/*#define USB_INOUT_FLAGS_ISOCH    0x0100   */  /* for internal use               */


/*#define USB_INOUT_FLAGS_NEW      0x0100   */  /* for internal use               */
/*#define USB_INOUT_FLAGS_DATAREQ  0x0200   */  /* for internal use               */ 
/*#define USB_INOUT_FLAGS_BYTE     0x0400   */  /* for internal use               */ 
/*#define USB_INOUT_FLAGS_0BYTREQ  0x0800   */  /* for internal use               */ 
/*#define USB_INOUT_FLAGS_ISO      0x1000   */  /* for internal use - not in use  */ 
/*#define USB_INOUT_FLAGS_STALL    0x2000   */  /* for internal use - not in use  */ 
/*#define USB_INOUT_FLAGS_RESET    0x4000   */  /* for internal use - not in use  */

#define USB_IOFLAG_NEW           0x0100     /* for internal use               */
#define USB_IOFLAG_DATAREQ       0x0200     /* for internal use               */
#define USB_IOFLAG_BYTE          0x0400     /* for internal use               */
#define USB_IOFLAG_0BYTREQ       0x0800     /* for internal use               */
#define USB_IOFLAG_ISO           0x1000     /* for internal use - not in use  */
#define USB_IOFLAG_STALL         0x2000     /* for internal use - not in use  */
#define USB_IOFLAG_RESET         0x4000     /* for internal use - not in use  */

/****************************12/05/00 $MH$*************************************/
/*   Endpoint transfer status indicator for hEp->status field                 */
/*                                                                            */
/*   This symbolic constants not currrently used by the API                   */
/******************************************************************************/

#define USB_IOSTAT_NONE         0x0000    /* none                             */
#define USB_IOSTAT_IN_PROG      0x0001    /* previous transaction in progress */
#define USB_IOSTAT_DONE         0x0002    /* previous transaction done        */

            
/******************************************************************************/
/*                                                                            */
/*                           Enumerated Data Types                            */
/*                                                                            */
/******************************************************************************/           

/****************************12/22/00 $MH$:************************************/
/*   USB_setParams flags - used to selectively config endpoint regs,             */
/*   intrpt regs, firmware env (internal vars) or all                         */
/*                                                                            */
/*   This enum data type is not currrently used by the API                    */
/******************************************************************************/

typedef enum
{
  USB_CFG_FLAG_NONE    = 0x0000,
  USB_CFG_FLAG_NEW_DEV = 0x0001,
  USB_CFG_FLAG_IF_ONLY = 0x0002
  
}USB_CFG_FLAGS;

/******************************************************************************/
/*                                                                            */
/*                             USB_RST_FLAG                                   */
/*                                                                            */
/******************************************************************************/

typedef enum
{
  USB_RST_SOFT = 0,
  USB_RST_HARD = 1
  
}USB_RST_FLAG;


/******************************************************************************/
/*                                                                            */
/*                           USB Data Structures                              */
/*                                                                            */
/******************************************************************************/            
            


/******************************************************************************/
/*                                                                            */
/*                                USB MACROS                                  */
/*                                                                            */
/******************************************************************************/

#define _USB_EN_EP_INTR(DevNum, EpIndex) \
         ((EpIndex & 0x08) ? (USBIEPIE |= (1 << (EpIndex & 0x07))) : \
                             (USBOEPIE |= (1 << (EpIndex & 0x07))))

#define _USB_DIS_EP_INTR(DevNum, EpIndex) \
         ((EpIndex & 0x08) ? (USBIEPIE &= ~(1 << (EpIndex & 0x07))) : \
                             (USBOEPIE &= ~(1 << (EpIndex & 0x07))))
                             
#define _USB_EN_DMA_INTR(DevNum, EpIndex) \
         ((EpIndex & 0x08) ? (USBIDIE |= (1 << (EpIndex & 0x07))) : \
                             (USBODIE |= (1 << (EpIndex & 0x07))))

#define _USB_DIS_DMA_INTR(DevNum, EpIndex) \
         ((EpIndex & 0x08) ? (USBIDIE &= ~(1 << (EpIndex & 0x07))) : \
                             (USBODIE &= ~(1 << (EpIndex & 0x07))))
                             
/******************************************************************************/
/* Name     :  USB_CONNECT                                                    */
/*                                                                            */
/* Catagory :  Device Control                                                 */
/*                                                                            */
/* Purpose  :  Connect the USB module to upstream port (D+ pullup enabled)    */
/*                                                                            */
/*                                                                            */
/* Author   :  MH                                                             */
/*                                                                            */
/* Based on :                                                                 */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* DevNum:    USB device number, enumerated data type of USB_DevNum.          */
/*            Only USB0 is active currently                                   */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* None                                                                       */
/*                                                                            */
/*============================================================================*/
/* Comments:                                                                  */
/* 03/30/01 $MH$ replaced by functoin USB_connectDev(DevNum)                  */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    05 Feb 2001                                                    */
/*                                                                            */
/******************************************************************************/

/*#define USB_CONNECT(DevNum) \
 *        (USBCTL |= USBCTL_CONN)                              */

/******************************************************************************/
/* Name     :  USB_DISCONNECT                                                 */
/*                                                                            */
/* Catagory :  Device Control                                                 */
/*                                                                            */
/* Purpose  :  Disconnect the USB module from the upstream port               */
/*             (D+ pullup disabled)                                           */
/*                                                                            */
/*                                                                            */
/* Author   :  MH                                                             */
/*                                                                            */
/* Based on :                                                                 */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* DevNum:    USB device number, enumerated data type of USB_DevNum.          */
/*            Only USB0 is active currently                                   */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* None                                                                       */
/*                                                                            */
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* 03/30/01 $MH$ replaced by functoin USB_disconnectDev(DevNum)               */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    05 Feb 2001                                                    */
/*                                                                            */
/******************************************************************************/

/*#define USB_DISCONNECT(DevNum) \
 *        (USBCTL &= ~USBCTL_CONN) */
        
/******************************************************************************/
/* Name     : USB_ISSUE_REMOTE_WAKEUP                                         */
/*                                                                            */
/* Catagory : Device Control                                                  */
/*                                                                            */
/* Purpose  : Issue a remote wakeup signal to the host.                       */
/*                                                                            */
/*                                                                            */
/* Author   : MH                                                              */
/*                                                                            */
/* Based on :                                                                 */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* DevNum:    USB device number, enumerated data type of USB_DevNum.          */
/*            Only USB0 is active currently                                   */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* None                                                                       */
/*                                                                            */
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* Host must set the remote wake up feature first. An application must chech  */
/* if the remote wake-up feature is before generating a remote wake-up signal */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    05 Feb 2001                                                    */
/*                                                                            */
/******************************************************************************/

/*#define USB_ISSUE_REMOTE_WAKEUP(DevNum) \
 *        (USBCTL |= USBCTL_RWUP) */

/******************************************************************************/
/* Name     :  USB_RESET                                                      */
/*                                                                            */
/* Catagory :  Device Control                                                 */
/*                                                                            */
/* Purpose  :  Reset the USB module.                                          */
/*                                                                            */
/*                                                                            */
/* Author   :  MH                                                             */
/*                                                                            */
/* Based on :                                                                 */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* DevNum:    USB device number, enumerated data type of USB_DevNum.          */
/*            Only USB0 is active currently                                   */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* None                                                                       */
/*                                                                            */
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* Once the module has been reset, all the control and status registers are   */
/* returned to powerup reset values and the USB module is diconnected from    */
/* the upstream port.                                                         */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    05 Feb 2001                                                    */
/*                                                                            */
/******************************************************************************/

/*#define USB_RESET(DevNum) \
 *        (USBGCTL |= USBGCTL_RST) */
        
/******************************************************************************/
/* Name     :  USB_ENABLE_BUS_INTRPT                                          */
/*                                                                            */
/* Catagory :  Device Control                                                 */
/*                                                                            */
/* Purpose  :  Enable the USB bus related interrupts defined in USBMSK reg    */
/*                                                                            */
/*                                                                            */
/* Author   :  MH                                                             */
/*                                                                            */
/* Based on :                                                                 */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* DevNum:    USB device number, enumerated data type of USB_DevNum.          */
/*            Only USB0 is active currently                                   */
/*                                                                            */
/* mask  :    8-bit mask to enable selective interrupts.  Interrupts are      */
/*            if the respective mask bits are set                             */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* None                                                                       */
/*                                                                            */
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* USB bus related interrupts are the ones defined in the USB Interrupt Enable*/
/* Register (USBIE)                                                           */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    05 Feb 2001                                                    */
/*                                                                            */
/******************************************************************************/ 
        
/*#define USB_ENABLE_BUS_INTRPT(DevNum, mask) \
 *        (USBIE |= (mask & 0xFF)) */
        
/******************************************************************************/
/* Name     :  USB_DISABLE_BUS_INTRPT                                         */
/*                                                                            */
/* Catagory :  Device Control                                                 */
/*                                                                            */
/* Purpose  :  Disable the USB bus related interrupts defined in USBMSK reg   */
/*                                                                            */
/*                                                                            */
/* Author   :  MH                                                             */
/*                                                                            */
/* Based on :                                                                 */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* DevNum:    USB device number, enumerated data type of USB_DevNum.          */
/*            Only USB0 is active currently                                   */
/*                                                                            */
/* mask  :    8-bit mask to disable selective interrupts.  Interrupts are     */
/*            when the mask bits are set                                      */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* None                                                                       */
/*                                                                            */
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* USB bus related interrupts are the ones defined in the USB Interrupt Enable*/
/* Register (USBIE)                                                           */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    05 Feb 2001                                                    */
/*                                                                            */
/******************************************************************************/

/*#define USB_DISABLE_BUS_INTRPT(DevNum, mask) \
 *        (USBIE &= ~(mask & 0xFF)) */
        
/******************************************************************************/
/* Name     :  USB_CLR_BUS_INTRPT_FLAG                                        */
/*                                                                            */
/* Catagory :  Device Control                                                 */
/*                                                                            */
/* Purpose  :  Clear the USB bus related interrupts flag bits of USBIF reg    */
/*                                                                            */
/*                                                                            */
/* Author   :  MH                                                             */
/*                                                                            */
/* Based on :                                                                 */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* DevNum:    USB device number, enumerated data type of USB_DevNum.          */
/*            Only USB0 is active currently                                   */
/*                                                                            */
/* mask  :    8-bit mask to clear selective interrupts flags. Interrupt flags */
/*            when the respective mask bits are set                           */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* None                                                                       */
/*                                                                            */
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* USB bus related interrupts are the ones defined in the USB Interrupt Enable*/
/* Register (USBIE)                                                           */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    05 Feb 2001                                                    */
/*                                                                            */
/******************************************************************************/
        
/*#define USB_CLR_BUS_INTRPT_FLAG(DevNum, mask) \
 *        (USBIF |= (mask & 0xFF)) */
        
/******************************************************************************/
/* Name     :  USB_CLR_SETUP_EV_FLAG                                          */
/*                                                                            */
/* Catagory :  Device Control                                                 */
/*                                                                            */
/* Purpose  :  Clear the USB setup packet received interrupt flag bit of      */
/*             USBIF reg                                                      */
/*                                                                            */
/* Author   :  MH                                                             */
/*                                                                            */
/* Based on :                                                                 */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* DevNum:    USB device number, enumerated data type of USB_DevNum.          */
/*            Only USB0 is active currently                                   */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* None                                                                       */
/*                                                                            */
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    05 Feb 2001                                                    */
/*                                                                            */
/******************************************************************************/

/*#define USB_CLR_SETUP_EV_FLAG(DevNum) \
 *        (USBIF |= USB_INT_SETUP) */
        
/******************************************************************************/
/* Name     :  USB_CLR_STPOW_EV_FLAG                                          */
/*                                                                            */
/* Catagory :  Device Control                                                 */
/*                                                                            */
/* Purpose  :  Clear the USB setup packet overwrite interrupt flag bit of     */
/*             USBIF reg                                                      */
/*                                                                            */
/* Author   :  MH                                                             */
/*                                                                            */
/* Based on :                                                                 */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* DevNum:    USB device number, enumerated data type of USB_DevNum.          */
/*            Only USB0 is active currently                                   */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* None                                                                       */
/*                                                                            */
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    05 Feb 2001                                                    */
/*                                                                            */
/******************************************************************************/
        
/*#define USB_CLR_STPOW_EV_FLAG(DevNum) \
 *        (USBIF |= USB_INT_STPOW) */
        
/******************************************************************************/
/* Name     :  USB_SET_EP0_CONT_STALL                                         */
/*                                                                            */
/* Catagory :  Device Control                                                 */
/*                                                                            */
/* Purpose  :  Stall USB control endpoints for indefinite period.             */
/*                                                                            */
/* Author   :  MH                                                             */
/*                                                                            */
/* Based on :                                                                 */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* DevNum:    USB device number, enumerated data type of USB_DevNum.          */
/*            Only USB0 is active currently                                   */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* None                                                                       */
/*                                                                            */
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* Once the stall is set, the controll endpoints will reject all the following*/
/* setup and endpoint 0 tokens until the continous stall is cleared by calling*/
/* USB_CLR_EP0_CONT_STALL macro                                               */
/*                                                                            */
/* It is helpful to stall the control endpoints for indefinite time before    */
/* reading the setup packet to make sure the content of setup data buffer is  */
/* not corrupted by a new setup packet.                                       */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    05 Feb 2001                                                    */
/*                                                                            */
/******************************************************************************/ 

/*#define USB_SET_EP0_CONT_STALL(DevNum) \
 *        (USBCTL |= USBCTL_SETUP) */
        
/******************************************************************************/
/* Name     :  USB_CLR_EP0_CONT_STALL                                         */
/*                                                                            */
/* Catagory :  Device Control                                                 */
/*                                                                            */
/* Purpose  :  Clear the indefinite stall of the control endpoints.           */
/*                                                                            */
/* Author   :  MH                                                             */
/*                                                                            */
/* Based on :                                                                 */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* DevNum:    USB device number, enumerated data type of USB_DevNum.          */
/*            Only USB0 is active currently                                   */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* None                                                                       */
/*                                                                            */
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* Brings control endpoints out of indefinite stall mode.  Control endpoints  */
/* enters indefinite stall mode when USB_SET_EP0_CONT_STALL macro is called   */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    05 Feb 2001                                                    */
/*                                                                            */
/******************************************************************************/

/*#define USB_CLR_EP0_CONT_STALL(DevNum) \
 *        (USBIF |= USB_INT_SETUP) */

/******************************************************************************/
/* Name     :  USB_SET_EP0_DATA_DIR                                           */
/*                                                                            */
/* Catagory :  Device Control                                                 */
/*                                                                            */
/* Purpose  :  Sets/Clears the DIR bit of USB Device Control(USBCTL) Register */
/*                                                                            */
/* Author   :  MH                                                             */
/*                                                                            */
/* Based on :                                                                 */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* DevNum   : USB device number, enumerated data type of USB_DevNum.          */
/*            Only USB0 is active currently                                   */
/*                                                                            */
/* DataDir  : Direction of endpoint 0 data transfer (USB_EP0DataDir type)     */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* None                                                                       */
/*                                                                            */
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/*             The DIR bit of USBCTL register determines how endpoint 0 should*/
/*             respond to the data and handshake phase of a control transfer  */                     
/*                                                                            */
/*             If the direction is set to EP0_DATA_OUT the USB will expect a  */
/*             OUT packet from the host and the USB module won't generate an  */
/*             interrupt at the end of a 0 byte handshake packet from the     */
/*             target to host.  If the direction is set to EP0_DATA_OUT and   */
/*             an IN token arrives the USB module will stall enpoint 0.       */
/*                                                                            */
/*             If the direction is set to EP0_DATA_IN the USB will expect an  */
/*             IN token from the host and the USB module won't generate an    */
/*             interrupt when a 0 byte handshake packet arrives from the host */
/*             If the direction is set to EP0_DATA_IN and a OUt token arrives */
/*             the USB module will stall the enpoint 0.                       */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    05 Feb 2001                                                    */
/*                                                                            */
/******************************************************************************/

/*#define USB_SET_EP0_DATA_DIR(DevNun, DataDir) \
 *        ((DataDir) ? (USBCTL |= USBCTL_DIR) : (USBCTL &= ~USBCTL_DIR)) */
        
/******************************************************************************/
/* Name     :  USB_SET_ADDR                                                   */
/*                                                                            */
/* Catagory :  Device Control                                                 */
/*                                                                            */
/* Purpose  :  Set USB device address                                         */
/*                                                                            */
/* Author   :  MH                                                             */
/*                                                                            */
/* Based on :                                                                 */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* DevNum   : USB device number, enumerated data type of USB_DevNum.          */
/*            Only USB0 is active currently                                   */
/*                                                                            */
/* addr     : 7-bit USB device address                                        */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* None                                                                       */
/*                                                                            */
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    05 Feb 2001                                                    */
/*                                                                            */
/******************************************************************************/

/*#define USB_SET_ADDR(DevNum, addr) \
 *        (USBADDR = addr & 0x7F) */
        
 
/******************************************************************************/
/* Name     :  USB_GET_FRM_NO                                                 */
/*                                                                            */
/* Catagory :  Device Control                                                 */
/*                                                                            */
/* Purpose  :  Read current USB frame number                                  */
/*                                                                            */
/* Author   :  MH                                                             */
/*                                                                            */
/* Based on :                                                                 */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* DevNum   : USB device number, enumerated data type of USB_DevNum.          */
/*            Only USB0 is active currently                                   */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* Current USB Frame Number                                                   */
/*                                                                            */
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    07 Feb 2001                                                    */
/*                                                                            */
/******************************************************************************/

/*#define USB_GET_FRM_NO(DevNum) \
 *        (((USBFNUMH & 0x07)<<8) | (USBFNUML & 0xFF)) */




/******************************************************************************/
/*                                                                            */
/*                             USB API Prototypes                             */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* Name     : _USB_resetFirmwareEnv                                           */
/*                                                                            */
/* Catagory : Firmware Initialization (private function)                     */
/*                                                                            */
/* Purpose  : Reset the internal USB firmware variable to a known state       */
/*                                                                            */
/*                                                                            */
/* Author   : MH                                                              */
/*                                                                            */
/* Based on : From scratch                                                    */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* DevNum   : USB device number, enumerated data type of USB_DevNum.          */
/*            Only USB0 is active currently                                   */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* USB_TRUE if the internal firmware variables are reset to a known state,    */
/* else USB_FALSE                                                             */
/*                                                                            */ 
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    21 Dec 2000                                                    */
/*                                                                            */
/******************************************************************************/

USB_Boolean _USB_resetFirmwareEnv(USB_DevNum DevNum);

/******************************************************************************/
/* Name     : _USB_enableDmaIntrpt                                            */
/*                                                                            */
/* Catagory : Device Initialization (private function)                        */
/*                                                                            */
/* Purpose  : Enable the endpoint DMA interrupt.  Affected endpoint is        */
/*            determined by the endpoint objects passed to the function       */
/*                                                                            */
/* Author   : MH                                                              */
/*                                                                            */
/* Based on : From scratch                                                    */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* DevNum   : USB device number, enumerated data type of USB_DevNum.          */
/*            Only USB0 is active currently                                   */
/*                                                                            */
/* hEp      : Handle to an initialized endpoint object                        */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* USB_TRUE if the endpoint DMA interrupt is successfully enabled,            */
/* else USB_FALSE                                                             */    
/*                                                                            */ 
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    21 Dec 2000                                                    */
/*                                                                            */
/******************************************************************************/
USB_Boolean _USB_enableDmaIntrpt(USB_DevNum DevNum, USB_EpHandle hEp);

/******************************************************************************/
/* Name     : _USB_disableDmaIntrpt                                           */
/*                                                                            */
/* Catagory : Device Initialization (private function)                       */
/*                                                                            */
/* Purpose  : Disable the endpoint DMA interrupt.  Affected endpoint is       */
/*            determined by the endpoint objects passed to the function       */
/*                                                                            */
/* Author   : MH                                                              */
/*                                                                            */
/* Based on : From scratch                                                    */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* DevNum   : USB device number, enumerated data type of USB_DevNum.          */
/*            Only USB0 is active currently                                   */
/*                                                                            */
/* hEp      : Handle to an initialized endpoint object                        */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* USB_TRUE if the endpoint DMA interrupt is successfully disabled,           */
/* else USB_FALSE                                                             */    
/*                                                                            */ 
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    21 Dec 2000                                                    */
/*                                                                            */
/******************************************************************************/
USB_Boolean _USB_disableDmaIntrpt(USB_DevNum DevNum, USB_EpHandle hEp);

/******************************************************************************/
/* Name     : _USB_enableEpIntrpt                                             */
/*                                                                            */
/* Catagory : Device Initialization (private function)                       */
/*                                                                            */
/* Purpose  : Enable the endpoint interrupt.  Affected endpoint is determined */
/*            by the endpoint objects passed to the function                  */
/*                                                                            */
/* Author   : MH                                                              */
/*                                                                            */
/* Based on : From scratch                                                    */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* DevNum   : USB device number, enumerated data type of USB_DevNum.          */
/*            Only USB0 is active currently                                   */
/*                                                                            */
/* hEp      : Handle to an initialized endpoint object                        */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* USB_TRUE if the endpoint interrupt is successfully enabled, else USB_FALSE */
/*                                                                            */ 
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    21 Dec 2000                                                    */
/*                                                                            */
/******************************************************************************/
USB_Boolean _USB_enableEpIntrpt(USB_DevNum DevNum, USB_EpHandle hEp);

/******************************************************************************/
/* Name     : _USB_disableEpIntrpt                                            */
/*                                                                            */
/* Catagory : Device Initialization (private function)                       */
/*                                                                            */
/* Purpose  : Disable the endpoint interrupt. Affected endpoint is determined */
/*            by the endpoint objects passed to the function                  */
/*                                                                            */
/* Author   : MH                                                              */
/*                                                                            */
/* Based on : From scratch                                                    */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* DevNum   : USB device number, enumerated data type of USB_DevNum.          */
/*            Only USB0 is active currently                                   */
/*                                                                            */
/* hEp      : Handle to an initialized endpoint object                        */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* USB_TRUE if the endpoint interrupt is successfully disabled,else USB_FALSE */
/*                                                                            */ 
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    21 Dec 2000                                                    */
/*                                                                            */
/******************************************************************************/
USB_Boolean _USB_disableEpIntrpt(USB_DevNum DevNum, USB_EpHandle hEp);

/******************************************************************************/
/* Name     : _USB_configEndpt                                                */
/*                                                                            */
/* Catagory : Initialization (private function)                              */
/*                                                                            */
/* Purpose  : Configure an endpoint descriptor block and DMA registers        */
/*                                                                            */
/*                                                                            */
/* Author   : MH                                                              */
/*                                                                            */
/* Based on : From scratch                                                    */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* hEp          : Handle to an endpoint object to be initialized              */
/*                                                                            */
/* EPxConfRegVal: 8-bit value to be written to Endpoint Config regsiter       */
/*                                                                            */
/* BufBaseAddrX : Xbuffer base address in the USB buffer RAM                  */
/*                                                                            */
/* BufBaseAddrY : Xbuffer base address in the USB buffer RAM                  */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* USB_TRUE if the initialization is successful, else USB_FLASE               */
/*                                                                            */ 
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* The event handler should be in void Fxn(void) form. Using the INTERRUPT    */
/* is not necessary.  Once the program control branches to Fxn the user's     */
/* code is free to call other functions or event post DSP?BIOS SWI            */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:       24 Nov 2000                                                 */
/*                                                                            */
/******************************************************************************/
USB_Boolean _USB_configEndpt(USB_EpHandle  hEpx,
                             Uint16        EPxConfRegVal,
                             Uint16        BufBaseAddrX,
                             Uint16        BufBaseAddrY);
                             
                             
/******************************************************************************/
/* Name     : _USB_addInterface                                               */
/*                                                                            */
/* Catagory : Device Initialization                                           */
/*                                                                            */
/* Purpose  : Include additional endpoint to the existing configuration       */
/*                                                                            */
/*                                                                            */
/* Author   : MH                                                              */
/*                                                                            */
/* Based on : From scratch                                                    */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* DevNum   : USB device number, enumerated data type of USB_DevNum.          */
/*            Only USB0 is active currently                                   */
/*                                                                            */
/* hEpObj[] : Pointer to a NULL terminated array of handles of initialized    */
/*            endpoint objects.  Max number of handles in the array can not   */
/*            be more than 16 (excluding the NULL handle)                     */
/*                                                                            */
/* NumOfEp  : Number of elements in the hEpObj[] array                        */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* USB_TRUE if additional endpoints are successfully added to the existing    */
/* device configuration, else USB_FALSE                                       */
/*                                                                            */ 
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* Once USB_init is called, to add another interface to the current device  */
/* call _USB_addInterface( ). This routine only initialize the endpoint       */
/* register and set endpoint dma intrpt mask bits, and updates the            */
/* USB_GlobalVars with endpoint related information.  This routine does not   */
/* reconfig EP0 regs                                                          */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    22 Dec 2000                                                    */
/*                                                                            */
/******************************************************************************/

USB_Boolean _USB_addInterface(USB_DevNum DevNum, USB_EpHandle hEpObj[], Uint16 NumOfEp);

/* -----------------10/23/2000 3:29PM----------------
 Software allocated memory locations.
 These are locations within the USB SRAM which are
 hard allocated for use in the USB driver.  These
 locations are essentially global variables which
 cannot be relocated and do not consume any regular
 DSP memory.
 Allocate the memory with:
 #pragma DATA_SECTION (USB_GlobalVars, ".usb$globals");
 USB_GlobalVars_struct USB_GlobalVars;
 --------------------------------------------------*/

/* base address for USB_GlobalVars 0x6580@IO (inside USB
 * buffer RAM  */
/* The base address is in a different location for the DA250 */
/* If removing this causes problems, I need to know in which files -- JDK */
/* #define USB_GLOBALVAR_BASE      0x6580 */

typedef Uint16 USB_EP_HANDLE_VECTOR[3];

/*
02/02/01 $MH$ redefined usb global structure with smaller
number of fields.
allocating gloval vars in the DSP data memory for test purpose
use (1) for test and debug, use (2) in the final version
*/

/* (1)
 * define global vars in data space to work around UBS+DMA+McBSP problem 
 -- $mh$ 02/25/03 */

typedef struct
{
  USB_EP_HANDLE_VECTOR  EpHandleTable[16];
  Uint16                NextEpBuffStartAddr[2];
  USB_Boolean           RemoteWkpStat;
  USB_Boolean           FlagSOF;      
  Uchar                 ActiveEndptNos;

} USB_GlobalVars_struct;

/* (2)
 * define global vars as varaiable in io space.
 
typedef ioport struct
{
  USB_EP_HANDLE_VECTOR  EpHandleTable[16];
  Uint16                NextEpBuffStartAddr[2];
  USB_Boolean           RemoteWkpStat;
  USB_Boolean           FlagSOF;      
  Uchar                 ActiveEndptNos;

} USB_GlobalVars_struct;   */


/******************************************************************************/
/*   03/23/01 $MH$                                                            */
/*                                                                            */
/*                  Vectored Prototypes for USB API                           */
/*                                                                            */
/******************************************************************************/

USB_EVENT_MASK vUSB_getEvents(USB_EpHandle hEp);
USB_EVENT_MASK vUSB_peekEvents(USB_EpHandle hEp);
USB_Boolean vUSB_getSetupPacket(USB_DevNum DevNum, USB_SetupStruct *USB_Setup);
USB_Boolean vUSB_postTransaction(USB_EpHandle    hEp,
                                 Uint16          ByteCnt,
                                 void            *Data,
                                 USB_IOFLAGS     Flags);
USB_Boolean vUSB_isTransactionDone(USB_EpHandle hEp);
USB_BYTE_COUNT vUSB_bytesRemaining(USB_EpHandle hEp);
USB_Boolean vUSB_abortTransaction(USB_EpHandle hEp);
USB_Boolean vUSB_abortAllTransaction(USB_DevNum DevNum);
void vUSB_stallEndpt(USB_EpHandle hEp);
void vUSB_clearEndptStall(USB_EpHandle hEp);
USB_Boolean vUSB_getEndptStall(USB_EpHandle hEp);
USB_EpHandle vUSB_epNumToHandle(USB_DevNum DevNum, Uchar Endpt);
USB_Boolean vUSB_initEndptObj(USB_DevNum     DevNum,
                              USB_EpHandle   hEp,
                              USB_EpNum      EpNum, 
                              USB_XferType   XferType,
                              Uint16         MaxPktSiz,
                              Uint16         EvMsk,
                              USB_EVENT_ISR  Fxn);
USB_Boolean vUSB_init(USB_DevNum    DevNum, 
                      USB_EpHandle  hEpObj[], 
                      Uchar         PSofTmrCnt);
                          
/* 03/30/01 $MH$ */
void vUSB_initPLL(Uint16 inclk, Uint16 outclk, Uint16 plldiv);
void vUSB_connectDev(USB_DevNum DevNum);
void vUSB_disconnectDev(USB_DevNum DevNum);
void vUSB_setRemoteWakeup(USB_DevNum DevNum, USB_Boolean RmtWkpStat);
USB_Boolean vUSB_getRemoteWakeupStat(USB_DevNum DevNum);
USB_Boolean vUSB_issueRemoteWakeup(USB_DevNum DevNum);
void vUSB_resetDev(USB_DevNum DevNum);
void vUSB_setDevAddr(USB_DevNum DevNum, Uchar addr);
Uint16 vUSB_getFrameNo(USB_DevNum DevNum);                          



/******************************************************************************/
/*   03/23/01 $MH$                                                            */
/*                                                                            */
/*                  Vectored Prototypes for USB API(internal)                 */
/*                                                                            */
/******************************************************************************/
USB_Boolean _vUSB_resetFirmwareEnv(USB_DevNum DevNum);
USB_Boolean _vUSB_enableDmaIntrpt(USB_DevNum DevNum, USB_EpHandle hEp);
USB_Boolean _vUSB_disableDmaIntrpt(USB_DevNum DevNum, USB_EpHandle hEp);
USB_Boolean _vUSB_enableEpIntrpt(USB_DevNum DevNum, USB_EpHandle hEp);
USB_Boolean _vUSB_disableEpIntrpt(USB_DevNum DevNum, USB_EpHandle hEp);
USB_Boolean _vUSB_configEndpt(USB_EpHandle  hEpx,
                             Uint16        EPxConfRegVal,
                             Uint16        BufBaseAddrX,
                             Uint16        BufBaseAddrY);
USB_Boolean _vUSB_addInterface(USB_DevNum DevNum, USB_EpHandle hEpObj[], Uint16 NumOfEp);

/* 09/28/01 $MH$ */
void vUSB_evDispatch(void);

#endif

#else   /* _USB_SUPPORT */
  #ifndef _USB_MOD
    error USB Module Not Supported on Specified Target Device
  #endif
#endif

