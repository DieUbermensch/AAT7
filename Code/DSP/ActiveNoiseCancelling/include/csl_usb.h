/******************************************************************************/
/* $Id: usb_api.h, 03 Dec 2000                                                */
/*                                                                            */
/* This is proprietary information, not to be published -- TI INTERNAL DATA   */
/* Copyright (C) 2001, Texas Instruments, Inc.  All Rights Reserved.          */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* Author: MH                                                                 */
/*                                                                            */
/* Based on: usb.h by Jason Kridner(IA) and Venkat Raghavan (TI India)        */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/*                DO NOT MAKE ANY CHANGE TO THIS FILE                         */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Modified last: 15 Jan 2001                                                 */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
 
#ifndef _CSL_USB_H
#define _CSL_USB_H

#if (_USB_SUPPORT) 

/****************************************\
* USB scope and inline control macros
\****************************************/

#ifdef __cplusplus
#define CSLAPI extern "C"  
#else
#define CSLAPI extern 
#endif

#undef  USEDEFS
#undef  IDECL
#undef  IDEF

#ifdef  _USB_MOD
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

#include <csl.h>
#include <csl_std.h>
#include <csl_usb_apimap.h>

/******************************************************************************/
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#define USB_IOFLAGS             Uint16
#define USB_EVENT_MASK          Uint16
#define USB_BYTE_COUNT          Uint16


            /************************************************/
            /*                                              */
            /*           Symbolic Constants                 */
            /*                                              */
            /************************************************/
            
            

/******************************************************************************/
/*                                                                            */
/*                          define NULL                                       */
/*                                                                            */
/******************************************************************************/
 
#ifndef NULL
#define NULL 0
#endif

/******************************************************************************/
/*                                                                            */
/*                    USB Data Transfer Flags                                 */
/*                                                                            */
/******************************************************************************/
 
#define USB_IOFLAG_NONE          0x0000  /* use default value                 */
#define USB_IOFLAG_NOSHORT       0x0001  /* do not expect or insert a 0 byte  */
                                         /* packet after a full size packet   */
#define USB_IOFLAG_SWAP          0x0002  /* swap hi/lo bytes before data xmit */
                                         /* after data recv.                  */                                         
#define USB_IOFLAG_LNK           0x0004  /* xmit or recv data buffer passed   */
                                         /* is a linked list                  */
#define USB_IOFLAG_CAT           0x0008  /* concatenate multiple linked list  */
                                         /* to fill up the data buffer with   */
                                         /* to max packet size before sending */
                                         /* or receiving a data packet        */                                                                                  
#define USB_IOFLAG_EOLL          0x0010  /* ignore argument ByteCnt, transfer */
                                         /* ends when the end of the linked   */
                                         /* list reached                      */                                                                                                                         

/******************************************************************************/
/*   Symbolic constants for  USB interrupt Events                             */
/*                                                                            */
/*   USB_EVENT_EOT is not an actual hardware interrupt, this     */
/*   flag is set by the USB event dispatcher to indicate the completion       */
/*   of the last requested data transfer.                                     */
/*                                                                            */
/******************************************************************************/

/*-------------5/16/00 4:00PM---------------*/
#define USB_EVENT_NONE                  0x0000  /* No interrupt received      */ 
#define USB_EVENT_RESET                 0x0001  /* Bus Reset                  */
#define USB_EVENT_SOF                   0x0002  /* Start of Frame             */
#define USB_EVENT_SUSPEND               0x0004  /* Bus Suspend                */
#define USB_EVENT_RESUME                0x0008  /* Bus Resume                 */
#define USB_EVENT_SETUP                 0x0010  /* Setup Packet Received      */
#define USB_EVENT_EOT                   0x0020  /* End of posted transaction  */
/* -----------01/05/01 $MH$---------------- */
#define USB_EVENT_STPOW                 0x0040  /* Setup Packet Overwrite     */
#define USB_EVENT_PSOF                  0x0080  /* Pre Start of Frame         */
#define USB_EVENT_HINT                  0x0100  /* Host interrupt             */
#define USB_EVENT_HERR                  0x0200  /* Host Error                 */



            /************************************************/
            /*                                              */
            /*           Enumerated Data Types              */
            /*                                              */
            /************************************************/
            
            

/****************************11/24/00 $MH$*************************************/
/*                                                                            */
/*                           USB Endpoints                                    */
/*                                                                            */
/*  These values are use by the CSL GUI or the USB API to initialize the      */
/*  USB Endpoint Objects                                                      */
/*                                                                            */
/******************************************************************************/

typedef enum 
{                                  /*            OUT ENDPOINTS                */
  USB_OUT_EP0  = 0x00,             /* Out Endpoint 0  - Control Out Endpoint  */
  USB_OUT_EP1  = 0x01,             /* Out Endpoint 1                          */
  USB_OUT_EP2  = 0x02,             /* Out Endpoint 2                          */
  USB_OUT_EP3  = 0x03,             /* Out Endpoint 3                          */
  USB_OUT_EP4  = 0x04,             /* Out Endpoint 4                          */
  USB_OUT_EP5  = 0x05,             /* Out Endpoint 5                          */
  USB_OUT_EP6  = 0x06,             /* Out Endpoint 6                          */
  USB_OUT_EP7  = 0x07,             /* Out Endpoint 7                          */
  
                                   /*            IN ENDPOINTS                */
  USB_IN_EP0   = 0x08,             /* In Endpoint 0  - Control In Endpoint   */
  USB_IN_EP1   = 0x09,             /* In Endpoint 1                          */
  USB_IN_EP2   = 0x0A,             /* In Endpoint 2                          */
  USB_IN_EP3   = 0x0B,             /* In Endpoint 3                          */
  USB_IN_EP4   = 0x0C,             /* In Endpoint 4                          */
  USB_IN_EP5   = 0x0D,             /* In Endpoint 5                          */
  USB_IN_EP6   = 0x0E,             /* In Endpoint 6                          */
  USB_IN_EP7   = 0x0F              /* In Endpoint 7                          */
  
}USB_EpNum;


/****************************11/24/00 $MH$*************************************/
/*                                                                            */
/*                         USB Transfer Tytes                                 */
/*                                                                            */
/*  These values are use by the CSL GUI or the USB API to initialize the      */
/*  USB Endpoint Objects                                                      */
/*                                                                            */
/******************************************************************************/

typedef enum 
{
  USB_CTRL  = 0x00,          /* Endpoint functions as control endpint         */
  USB_BULK  = 0x01,          /* Endpoint functions as bulk endpint            */
  USB_INTR  = 0x02,          /* Endpoint functions as interrupt endpint       */
  USB_ISO   = 0x03,          /* Endpoint functions as isochronous endpint     */
  USB_HPORT = 0x04           /* Endpoint functions as Host Port - special     */      
                             /* feature - not a part USB spec                 */
}USB_XferType;


/****************************11/24/00 $MH$*************************************/
/*                                                                            */
/*      USB device number - only useful if multiple exists on the             */
/*      same DSP.  Currently only USB0 supported.  Used by Device Control,    */
/*      Status Query and Data Transfer APIs                                   */
/*                                                                            */
/******************************************************************************/

typedef enum 
{
  USB0 = 0x00,    /* 1st USB module  -                                        */
  USB1 = 0x01,    /* 2nd USB module  - if the DSP support 2 USB module        */
  USB2 = 0x02     /* 3rd USB module  - if the DSP support 3 USB module        */
  
}USB_DevNum;


/****************************01/15/01 $MH$*************************************/
/*                                                                            */
/*      USB EP0 data dir type enumeration, used for setting and clearing      */
/*      DIR bit of USB Control Register (USBCTL).Used by Device Control macro */
/*      USB_SET_EP0_DATA_DIR(DevNun, DataDir)                                 */
/*                                                                            */
/******************************************************************************/

typedef enum 
{
  EP0_DATA_OUT = 0x00,            /* Endpoint0 data dir: Host -> Target       */
  EP0_DATA_IN  = 0x01             /* Endpoint0 data dir: Target -> host       */
  
} USB_EP0DataDir;


/******************************************************************************/
/*                                                                            */
/*                             USB_BOOLEAN                                    */
/*                                                                            */
/******************************************************************************/

typedef enum
{
  USB_FALSE = 0,
  USB_TRUE
}USB_Boolean;


            /************************************************/
            /*                                              */
            /*           USB Data Structures                */
            /*                                              */
            /************************************************/
            
            
/****************************01/15/01 $MH$*************************************/
/*                                                                            */
/*      USB_SetupStruct                                                       */
/*      Data structure to hold USB setup packet.  Used by USB API             */
/*      USB_getSetupPacket(USB_DevNum DevNum, USB_SetupStruct *USB_Setup)     */
/*                                                                            */
/******************************************************************************/

typedef struct
{
  int New;              /* New = 1, structure holds new setup packet          */    
  Uint16 bmRequestType; /* Byte 0 of setup packet                             */
  Uint16 bRequest;      /* Byte 1 of setup packet                             */
  Uint16 wValue;        /* Byte 2 and 3 of setup packet                       */
  Uint16 wIndex;        /* Byte 4 and 5 setup packet                          */
  Uint16 wLength;       /* Byte 6 and 7 of setup packet                       */
  
}USB_SetupStruct;


/****************************01/15/01 $MH$*************************************/
/*                                                                            */
/*      USB_DataStruct                                                        */
/*      Structure used by the USB Data Transfer API to send and received      */
/*      USB data in linked list form. USB Descriptors should be created as a  */
/*      linked list of USB_DataStruct type                                    */
/*                                                                            */
/******************************************************************************/

typedef struct USB_DataStructDef
{
  Uint16                    Bytes;        /* Total number of bytes in the buf */
  Uint16                    *pBuffer;     /* pointer to the start of buffer   */
  struct USB_DataStructDef  *pNextBuffer; /* pointer to the next structure    */
  
}USB_DataStruct;

/******************************************************************************/
/*                                                                            */
/*      USB_EVENT_ISR                                                         */
/*      Type definition for USB Event ISR pointer                             */
/*                                                                            */
/******************************************************************************/

typedef void (*USB_EVENT_ISR)();

/******************************************************************************/
/*                                                                            */
/*      USB_EvISR_NONE                                                        */
/*      NULL pointer for USB Event ISR                                        */
/*                                                                            */
/******************************************************************************/

#define USB_EvISR_NONE  (USB_EVENT_ISR)0

/******************************02/08/01 $MH$***********************************/
/*                                                                            */
/*                 Data Structure for USB Enpoint Object                      */
/*  Every active USB endpoint is associated with an endpoint object which     */
/*  keeps track of the endpoint related initialization and runtime information*/
/*                                                                            */
/*  03/05/01 $MH$ added XferBytCnt to keep track of actual number of data     */
/*  bytes moved in (out) to (from) the data buffer.  The size of the          */
/*  data buffer has to be (N+1) words.  Where N = (#bytes of data)/2, the     */
/*  the extra word at the beginning of the data buffer is used to store the   */
/*  actual number of bytes moved in (out).                                    */
/*                                                                            */
/******************************************************************************/

typedef struct 
{
   USB_EpNum        EpNum;        /* USB endpoint number                      */
   USB_XferType     XferType;     /* USB xfer type supported by the EP        */
   Uint16           MaxPktSiz;    /* Max pkt size supported by the EP         */
   Uint16           EventMask;    /* ORed value of USB_EVENTS, the USB        */
                                  /* event dispatcher will call the event     */
                                  /* ISR if event matches with EventMask      */
   USB_EVENT_ISR    Fxn;          /* Pointer to USB event ISR                 */
   Uint16           DataFlags;    /* ORed combination of USB_DATA_INOUT_FLAGS */
   Uint16           Status;       /* Reserved for future use                  */
   Uint16           EDReg_SAddr;  /* Endpoint desc reg block start addr       */
                                  /* 2 regs for EP0, 6 regs for the rest      */
   Uint16           DMA_SAddr;    /* DMA reg block start addr                 */
                                  /* used only for EP1 - EP7                  */
   Uint16           TotBytCnt;    /* Total number of bytes to xfer            */
   Uint16           BytInThisSeg; /* # of bytes in the active node of         */
                                  /* the linked list                          */
   Uint16           *XferBytCnt;  /* Pointer to store the number of bytes     */
                                  /* moved in (out) - stored in the first of  */
                                  /* the buffer                               */
   Uint16           *pBuffer;     /* Active data buffer pointer               */
   USB_DataStruct   *pNextBuffer; /* Pointer to the next node of the          */
                                  /* linked list                              */ 
   Uint16           EventFlag;    /* Flag to indicate the event cuased        */
                                  /* USB interrupt                            */
}  USB_EpObj,*USB_EpHandle;

/******************************************************************************/
/*                                                                            */
/*                         USB_NULL_EpHandle                                  */
/*                                                                            */
/*  NULL pointer for USB Enpoint Handle. During the endpoint initialization   */
/*  NULL endpoint handles are assigned to unused endpoints                    */
/*                                                                            */
/******************************************************************************/

#define USB_NULL_EpHandle   (USB_EpHandle)0



/******************************************************************************/
/*                                                                            */
/*                           USB API Prototypes                               */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* Name     : USB_setAPIVectorAddress                                         */
/*                                                                            */
/* Catagory : Software Initialization                                         */
/*                                                                            */
/* Purpose  : Initialize API vector pointer                                   */
/*                                                                            */
/* Author   : MH                                                              */
/*                                                                            */
/* Based on :                                                                 */
/*                                                                            */
/*============================================================================*/
/* Arguments:      None                                                       */
/*                                                                            */
/*============================================================================*/
/* Return Value:   None                                                       */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* The user application access to the USB API via a relocate-able call        */
/* table.                                                                     */
/*                                                                            */
/* This relocateable table allows user applications to call the API           */
/* routines out of ROM or out of RAM by relocating the API Vector             */
/* Table to RAM and replacing any desired functions with new ones             */
/* while still being able to use ROM functions.  The initial API              */
/* Vector Table contained in this file is the ROM version which will          */
/* be used as the default table until or if a user application moves          */
/* the table to another location in ROM or more likely RAM.                   */
/*                                                                            */
/* This scheme is specially implemented to replace the USB API in the         */
/* ROM with the updated ones.                                                 */
/*                                                                            */
/* USB buffer RAM locations 0x667E and 0x667F are reserved to point to        */
/* the API Vector Table.  These are 8 bit locations and hold the              */
/* two bytes of a 24 bit address, the lower byte is assumed to be 0           */
/* thus forcing the table to be allocated on 256 byte boundaries.             */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    16 Jan 2001                                                    */
/*                                                                            */
/******************************************************************************/
CSLAPI void USB_setAPIVectorAddress();

/******************************************************************************/
/* Name     : USB_initPLL                                                     */
/*                                                                            */
/* Catagory : Device Control                                                  */
/*                                                                            */
/* Purpose  : Initailize USB PLL to generate clock for the USB module         */
/*                                                                            */
/* Author   : MH                                                              */
/*                                                                            */
/* Based on : C55x PLL init routine                                           */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* inclk      : Input clock (supplied at CLKIN pin) frequency ( in MHz)       */
/*                                                                            */
/* outclk     : Desired clock frequency (in MHz) for the USB moduel, the      */
/*              outclk must be 48 MHz for the proper operation of the USB     */
/*              module.                                                       */
/*                                                                            */
/* plldiv     : Input clock (supplied at CLKIN pin) devide down value, used   */
/*              for USB PLL enable as well as USB PLL bypass mode             */
/*                                                                            */
/*============================================================================*/
/* Return Value:   None                                                       */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* pllmult = (outclk * (plldiv+1)) / inclk                                    */
/*                                                                            */
/* if pllmult > 1                                                             */
/*		outclk = (pllmult / (plldiv + 1)) * inclk                         */
/*                                                                            */
/* if pllmult < 1                                                             */
/*		outclk = (1 / (plldiv + 1)) * inclk                               */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    16 Jan 2001                                                    */
/*                                                                            */
/******************************************************************************/

CSLAPI void USB_initPLL(Uint16 inclk, Uint16 outclk, Uint16 plldiv);

/******************************************************************************/
/* Name     :  USB_connectDev                                                 */
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
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    30 Mar 2001                                                    */
/*                                                                            */
/******************************************************************************/

CSLAPI void USB_connectDev(USB_DevNum DevNum);

/******************************************************************************/
/* Name     :  USB_disconnectDev                                              */
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
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    30 Mar 2001                                                    */
/*                                                                            */
/******************************************************************************/

CSLAPI void USB_disconnectDev(USB_DevNum DevNum);
        
        
/******************************************************************************/
/* Name     : USB_issueRemoteWakeup                                            */
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
/* USB_TRUE if successfull, else USB_FASLE (specailly if remote wakeup feature*/
/* is not set prior to calling this function)                                 */
/*                                                                            */
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* The USB driver will generate a remote wakeup signal on the bus if and only */
/* if the remote wakeup is enabled.  User's application must enable the remote*/
/* wakeup feature by calling the USB_setRemoteWakeup( ) routine if a Set      */
/* Remote Wakeup request is received from the  host.                          */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    30 Mar 2001                                                    */
/*                                                                            */
/******************************************************************************/

CSLAPI USB_Boolean USB_issueRemoteWakeup(USB_DevNum DevNum);

/******************************************************************************/
/* Name     : USB_setRemoteWakeup                                             */
/*                                                                            */
/* Catagory : Software Control                                                */
/*                                                                            */
/* Purpose  : Set or clear Remote Wakeup Feature                              */
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
/* RmtWkpStat:  If USB_TRUE the driver will set remote wakeup feature         */
/*              and a subsequent call to USB_issueRemoteWakeup( ) will cause  */
/*              the driver to generate a remote signal on the bus             */
/*                                                                            */
/*              If USB_FALSE the driver will clear remote wakeup feature      */
/*              and a subsequent call to USB_issueRemoteWakeup( ) will not    */
/*              generate a remote signal on the bus                           */           
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
/* Host must set the remote wake up feature first. An application must verify */
/* if the remote wake-up feature is set before generating a remote wake-up    */
/* signal.                                                                    */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    31 Mar 2001                                                    */
/*                                                                            */
/******************************************************************************/

CSLAPI void USB_setRemoteWakeup(USB_DevNum DevNum, USB_Boolean RmtWkpStat);

/******************************************************************************/
/* Name     : USB_getRemoteWakeupStat                                         */
/*                                                                            */
/* Catagory : Status / Query                                                  */
/*                                                                            */
/* Purpose  : get the status of the Remote Wakeup Feature (whether the        */
/*            the feature is set or clear in the software)                    */
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
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* USB_TRUE if the Remote Wakeup Feature is enabled in the software.          */
/* USB_FALSE if the Remote Wakeup Feature is disabled in the software.        */
/*                                                                            */
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* An application must verify if the remote wakeup feature is set by the host */
/* before calling USB_issueRemoteWakeup( )                                    */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    31 Mar 2001                                                    */
/*                                                                            */
/******************************************************************************/

CSLAPI USB_Boolean USB_getRemoteWakeupStat(USB_DevNum DevNum);

/******************************************************************************/
/* Name     :  USB_resetDev                                                   */
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
/* Created:    30 Mar 2001                                                    */
/*                                                                            */
/******************************************************************************/

CSLAPI void USB_resetDev(USB_DevNum DevNum);
        
       
/******************************************************************************/
/* Name     :  USB_setDevAddr                                                 */
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
/* Created:    30 Mar 2001                                                    */
/*                                                                            */
/******************************************************************************/

CSLAPI void USB_setDevAddr(USB_DevNum DevNum, Uchar addr);

 
/******************************************************************************/
/* Name     :  USB_getFrameNo                                                 */
/*                                                                            */
/* Catagory :  Status/Query                                                   */
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
/* Created:    30 Mar 2001                                                    */
/*                                                                            */
/******************************************************************************/

CSLAPI Uint16 USB_getFrameNo(USB_DevNum DevNum);

/******************************************************************************/
/* Name     : USB_getEvents                                                   */
/*                                                                            */
/* Catagory : Status / Query                                                  */
/*                                                                            */
/* Purpose  : Read and clear all the pending USB_EVENTS associated with a     */
/*            particular USB endpoint                                         */
/*                                                                            */
/* Author   : MH (partially)                                                  */
/*                                                                            */
/* Based on : USB code by Jason Kridner(IA) and Venkat Raghavan (TI India)    */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* hEp      : Handle to an initialized endpoint object                        */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* ORed combination of all the pending USB_EVENTS associated with a particular*/
/* endpoint                                                                   */
/*                                                                            */
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* Calling this routine also clears all the pending USB_ENENTS associated     */
/* a particular endpoint                                                      */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    28 Nov 2000                                                    */
/*                                                                            */
/******************************************************************************/

CSLAPI USB_EVENT_MASK USB_getEvents(USB_EpHandle hEp);

/******************************************************************************/
/* Name     : USB_peekEvents                                                  */
/*                                                                            */
/* Catagory : Status / Query                                                  */
/*                                                                            */
/* Purpose  : Read all the pending USB_EVENTS associated with a particular    */
/*            USB endpoint                                                    */
/*                                                                            */
/* Author   : MH (partially)                                                  */
/*                                                                            */
/* Based on : USB code by Jason Kridner(IA) and Venkat Raghavan (TI India)    */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* hEp      : Handle to an initialized endpoint object                        */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* ORed combination of all the pending USB_EVENTS associated with a           */
/* particular endpoint                                                        */
/*                                                                            */
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* Calling this routine does not clear the pending USB_ENENTS associated      */
/* a particular endpoint                                                      */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    28 Nov 2000                                                    */
/*                                                                            */
/******************************************************************************/

CSLAPI USB_EVENT_MASK USB_peekEvents(USB_EpHandle hEp);

/******************************************************************************/
/* Name     : USB_getSetupPacket                                              */
/*                                                                            */
/* Catagory : Data Transfer                                                   */
/*                                                                            */
/* Purpose  : Read the setup packet from the setup data buffer                */
/*                                                                            */
/*                                                                            */
/* Author   : MH (partially)                                                  */
/*                                                                            */
/* Based on : USB code by Jason Kridner(IA) and Venkat Raghavan (TI India)    */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* DevNum     : USB device number, enumerated data type of USB_DevNum.        */
/*              Only USB0 is active currently                                 */
/*                                                                            */
/* *USB_Setup : Pointer to a structure of type USB_SetupStruct.               */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* USB_TRUE if successful else USB_FALSE. If successful successful USB_Setup  */
/* structure holds the new setup packet                                       */
/*                                                                            */
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    28 Nov 2000                                                    */
/*                                                                            */
/******************************************************************************/

CSLAPI USB_Boolean USB_getSetupPacket(USB_DevNum DevNum, USB_SetupStruct *USB_Setup);


/******************************************************************************/
/* Name     : USB_postTransaction                                             */
/*                                                                            */
/* Catagory : Data Transfer                                                   */
/*                                                                            */
/* Purpose  : Transmit and receive USB data through an endpoint               */
/*                                                                            */
/*                                                                            */
/* Author   : MH (partially)                                                  */
/*                                                                            */
/* Based on : USB code by Jason Kridner(IA) and Venkat Raghavan (TI India)    */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* hEp      : Handle to an initialized endpoint object                        */
/*                                                                            */
/* ByteCnt  : Total number of bytes in the buffer pointed by *Data            */
/*            ByteCnt = 0 .. 65535                                            */
/*                                                                            */
/* Data    : A pointer to a data buffer or to a linked list of type           */
/*            USB_DataStruct                                                  */
/*                                                                            */
/* Flags    : ORed combination of USB Data Transfer Flags                     */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* USB_FALSE, if the previously posted transfer is not completed. USB_TRUE    */
/* if the data transfer request was posted successfully.                      */
/*                                                                            */ 
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* The endpoint handle determines the endpoint data moving in or out of the   */
/* USB module. At the end of the data transfer the USB event dispatcher will  */
/* call the associated event handler routine if the USB_TRANSACTIN_DONE event */
/* mask is set and an event handler routine is supplied during the endpoint   */
/* object initialization                                                      */
/*                                                                            */
/*--------------------- 03/08/01 $MH$ KNOWN LIMITATIONS  ---------------------*/
/*                                                                            */
/*  This limitation apply only for Out Endpoints if and only if the           */
/*  the data buffer is a linked list and USB_IOFLAG_CAT is set.  In           */
/*  such condition if the host prematurely terminates the data transfer       */
/*  (with or without a short packet) the driver fills up the data buffer      */ 
/*  of the current node of the linked list and then waits for more data       */ 
/*  from host to fill up the data buffers of the rest of the linked list.     */      
/*  This means the posted transation is still in progress and a call to       */  
/*  the routine USB_isTransactionDone(..) will return USB_FALSE.              */
/*  If the current node happen to be the very last node of the linked         */
/*  list the driver will treat this as a termination of transfer and          */
/*  a call to the routine USB_isTransactionDone(..) will return USB_TRUE      */
/*                                                                            */
/*  Since the driver programs the DMA GO and RLD registers at the same time   */
/*  (whenever possible) in order to move data more efficiently, if is beyond  */
/*  the scope of the driver to anticipate an early termination of data        */
/*  transfer and not program the DMA RLD registers                            */
/*                                                                            */
/*  WORK AROUND:  If you have doubt that the host may prematurely termainate  */
/*  the transfer then do not use the USB_IOFLAG_CAT flag with a linked list   */
/*  for OUT transfers.                                                        */
/*                                                                            */ 
/*  AFFECTED ENDPOINTS:  OUT[1..7]                                            */
/*                                                                            */
/*  THIS DOES NOT EFFECT ENDPOINT 0 IN/OUT TRANSFERS,  since endpoint0        */
/*  trnasfer are not done by the USB dedicated DMA                            */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    28 Nov 2000                                                    */
/*                                                                            */
/******************************************************************************/
CSLAPI USB_Boolean USB_postTransaction(USB_EpHandle    hEp,
                                Uint16          ByteCnt,
                                void            *Data,
                                USB_IOFLAGS     Flags);

/******************************************************************************/
/* Name     : USB_isTransactionDone                                           */
/*                                                                            */
/* Catagory : Status / Query                                                  */
/*                                                                            */
/* Purpose  : Returns  the status of the previously posted data transfer      */
/*            request                                                         */
/*                                                                            */
/* Author   : MH (partially)                                                  */
/*                                                                            */
/* Based on : USB code by Jason Kridner(IA) and Venkat Raghavan (TI India)    */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* hEp      : Handle to an initialized endpoint object                        */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* USB_TRUE, if the previously posted transfer is completed, else USB_FLASE.  */
/*                                                                            */ 
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* The endpoint handle determines the endpoint data will pass through.        */
/* It is a good idea to call this function before posting a data transfer     */
/* request                                                                    */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    28 Nov 2000                                                    */
/*                                                                            */
/******************************************************************************/
CSLAPI USB_Boolean USB_isTransactionDone(USB_EpHandle hEp);

/******************************************************************************/
/* Name     : USB_bytesRemaining                                              */
/*                                                                            */
/* Catagory : Status / Query                                                  */
/*                                                                            */
/* Purpose  : Find out number of bytes waiting to be transferred from the     */
/*            previously posted data transfer request                         */
/*                                                                            */
/* Author   : MH (partially)                                                  */
/*                                                                            */
/* Based on : USB code by Jason Kridner(IA) and Venkat Raghavan (TI India)    */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* hEp      : Handle to an initialized endpoint object                        */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* Number of bytes remaining to be transferred. Return value is 0xFFFF if     */
/* USB_IOFLAG_EOLL flag used while posting the transfer request       */
/*                                                                            */ 
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* The endpoint handle determines the endpoint data moves through.            */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    28 Nov 2000                                                    */
/*                                                                            */
/******************************************************************************/
CSLAPI USB_BYTE_COUNT USB_bytesRemaining(USB_EpHandle hEp);

/******************************************************************************/
/* Name     : USB_abortTransaction                                            */
/*                                                                            */
/* Catagory : Data Transfer                                                   */
/*                                                                            */
/* Purpose  : Terminate the data transfer in progress and free up the endpoint*/
/*            to post a new data transfer request                             */
/*                                                                            */
/* Author   : MH                                                              */
/*                                                                            */
/* Based on : None                                                            */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* hEp      : Handle to an initialized endpoint object                        */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* USB_TRUE if successful, else USB_FALSE                                     */
/*                                                                            */ 
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* The endpoint handle determines the endpoint associated with the data       */
/* transfer in progress                                                       */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    21 Dec 2000                                                    */
/*                                                                            */
/* Modified:   02/20/01 $MH$                                                  */
/*                                                                            */
/* Renamed from  USB_killTransaction( ) to USB_abortTransaction( )            */           
/*                                                                            */
/******************************************************************************/
CSLAPI USB_Boolean USB_abortTransaction(USB_EpHandle hEp);


/******************************************************************************/
/* Name     : USB_abortAllTransaction                                          */
/*                                                                            */
/* Catagory : Software Control                                                */
/*                                                                            */
/* Purpose  : Terminate all the data transfer in progress and free up the     */
/*            the endpoints to post new data transfer requests                */
/*                                                                            */
/* Author   : MH                                                              */
/*                                                                            */
/* Based on : From scratch                                                    */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* DevNum     : USB device number, enumerated data type of USB_DevNum.        */
/*              Only USB0 is active currently                                 */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* USB_TRUE if successful, else USB_FALSE                                     */
/*                                                                            */ 
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    10 Jan 2001                                                    */
/*                                                                            */
/* Modified:   02/20/01 $MH$                                                  */
/*                                                                            */
/* Renamed from  USB_killAllTransaction( ) to USB_abortAllTransaction( )      */
/*                                                                            */
/******************************************************************************/
CSLAPI USB_Boolean USB_abortAllTransaction(USB_DevNum DevNum);

/******************************************************************************/
/* Name     : USB_stallEndpt                                                  */
/*                                                                            */
/* Catagory : Device Control                                                  */
/*                                                                            */
/* Purpose  : Stall an endpoint                                               */
/*                                                                            */
/* Author   : MH (partially)                                                  */
/*                                                                            */
/* Based on : USB code by Jason Kridner(IA) and Venkat Raghavan (TI India)    */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* hEp      : Handle to an initialized endpoint object                        */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* None                                                                       */
/*                                                                            */ 
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* The endpoint handle determines the endpoint to stall                       */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    28 Nov 2000                                                    */
/*                                                                            */
/******************************************************************************/
CSLAPI void USB_stallEndpt(USB_EpHandle hEp);

/******************************************************************************/
/* Name     : USB_clearEndptStall                                             */
/*                                                                            */
/* Catagory : Device Control                                                  */
/*                                                                            */
/* Purpose  : Clear an endpoint stall                                         */
/*                                                                            */
/* Author   : MH (partially)                                                  */
/*                                                                            */
/* Based on : USB code by Jason Kridner(IA) and Venkat Raghavan (TI India)    */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* hEp      : Handle to an initialized endpoint object                        */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* None                                                                       */
/*                                                                            */ 
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* The endpoint handle determines the endpoint to bring out of stall          */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    28 Nov 2000                                                    */
/*                                                                            */
/******************************************************************************/
CSLAPI void USB_clearEndptStall(USB_EpHandle hEp);

/******************************************************************************/
/* Name     : USB_getEndptStall                                               */
/*                                                                            */
/* Catagory : Status / Query                                                  */
/*                                                                            */
/* Purpose  : Find out if an endpoint is stalled                              */
/*                                                                            */
/* Author   : MH (partially)                                                  */
/*                                                                            */
/* Based on : USB code by Jason Kridner(IA) and Venkat Raghavan (TI India)    */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* hEp      : Handle to an initialized endpoint object                        */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* USB_TRUE if the endpoint is stalled, otherwise USB_FALSE                   */
/*                                                                            */ 
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* The endpoint handle selects the endpoint                                   */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    28 Nov 2000                                                    */
/*                                                                            */
/******************************************************************************/
CSLAPI USB_Boolean USB_getEndptStall(USB_EpHandle hEp);

/******************************************************************************/
/* Name     : USB_epNumToHandle                                               */
/*                                                                            */
/* Catagory : Misc                                                            */
/*                                                                            */
/* Purpose  : Retrieve an handle to an endpoint                               */
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
/* Endpt    : 8-bit endpoint number as specified in the USB specification     */
/*            0x00 -> Endpt 0 Out, 0x01 -> Endpt 1 Out ....                   */
/*            0x80 -> Endpt 0 In,  0x81 -> Endpt 1 In  ....                   */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* An handle to the endpoint object if a valid endpoint object exists, else   */
/* a NULL handle                                                              */
/*                                                                            */  
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* This routine is helpful when the application does not have any prior       */
/* knowledge of the endpoint it is dealing with.  For example, if the host    */
/* requests to stall an endpoint the application can read the endpoint number */
/* from the setup packet, retrieve the handle to this endpoint by calling     */
/* USB_epNumToHandle(..), and call USB_stallEndpt(..) with the handle to      */
/* stall the ednpoint;                                                        */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    12 Dec 2000                                                    */
/*                                                                            */
/******************************************************************************/
CSLAPI USB_EpHandle USB_epNumToHandle(USB_DevNum DevNum, Uchar Endpt);


/******************************************************************************/
/* Name     : USB_initEndptObj                                                */
/*                                                                            */
/* Catagory : Initialization                                                  */
/*                                                                            */
/* Purpose  : Initialize an endpoint object                                   */
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
/* hEp      : Handle to an endpoint object to be initialized                  */
/*                                                                            */
/* EpNum    : USB endpoint number of enumarated data type USB_EpNum           */
/*                                                                            */
/* XferType : Type of data transfer to be supported by the endpoint           */
/*                                                                            */
/* MaxPktSiz: Max data packet size supported by the endpoint                  */
/*                                                                            */
/* EvMsk    : ORed combination of USB Interrupt Events to be broadcasted      */
/*            to the associated event handler                                 */
/*                                                                            */
/* Fxn      : Associated event handler routine                                */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* USB_TRUE if the initialization is successful, else USB_FLASE               */
/*                                                                            */ 
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* The event handler should be in void Fxn(void) form. Do no use the          */
/* INTERRUPT pragma . Once the program control branches to Fxn the user's     */
/* code is free to call other functions or even post DSP?BIOS SWI             */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    24 Nov 2000                                                    */
/*                                                                            */
/******************************************************************************/
CSLAPI USB_Boolean USB_initEndptObj(USB_DevNum     DevNum,
                             USB_EpHandle   hEp,
                             USB_EpNum      EpNum, 
                             USB_XferType   XferType,
                             Uint16         MaxPktSiz,
                             Uint16         EvMsk,
                             USB_EVENT_ISR  Fxn);
                              
/******************************************************************************/
/* Name     : USB_init                                                        */
/*                                                                            */
/* Catagory : Device Initialization                                           */
/*                                                                            */
/* Purpose  : Configure the USB module                                        */
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
/* DevNum     : USB device number, enumerated data type of USB_DevNum.        */
/*              Only USB0 is active currently                                 */
/*                                                                            */
/* hEpObj[]   : Pointer to a NULL terminated array of handles of initialized  */
/*              endpoint objects.  Max number of handles in the array can not */
/*              be more than 16 (excluding the NULL handle)                   */
/*                                                                            */
/* PSofTmrCnt : 8-bit counter value for the pre SOF timer                     */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* USB_TRUE if the device configuration is successful, else USB_FALSE         */
/*                                                                            */ 
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* Upon sucessful return from the function call the USB module is completely  */
/* for operation (all the regs are configured and unmasked interrupts         */
/* are enabled).  Once the USB module is configured the user's code needs to  */
/* unmask the USB interrupt mask bit in the IER0 reg of DSP and enable the    */
/* DSP global interrupt.  Finally the user's code should call the routine     */
/* USB_connectDev(USB0) to connect the usb module to the USB bus              */
/*                                                                            */
/*============================================================================*/
/* History:                                                                   */
/*                                                                            */
/* Created:    24 Nov 2000                                                    */
/*                                                                            */
/* 28 Feb 01 $MH$                                                             */
/* Changed name from USB_config( ) to USB_setParams( ) to comply with CSL     */
/* standard                                                                   */
/*                                                                            */
/* 18 Jul 01 $MH$                                                             */
/* Changed name from USB_setParams( ) to USB_init( ) to comply with CSL       */
/* standard                                                                   */
/*                                                                            */                      
/******************************************************************************/
CSLAPI USB_Boolean USB_init(USB_DevNum    DevNum, 
                     USB_EpHandle  hEpObj[], 
                     Uchar         PSofTmrCnt);
                          
/******************************************************************************/
/*  Name:  USB_evDispatch                                                     */
/*                                                                            */
/*  Catagory : USB Event Dispatcher                                           */
/*                                                                            */
/*  Purpose:                                                                  */
/*                                                                            */
/*  This is the USB task dispatcher. This function sets the event flags based */
/*  on the USB events occured and calls the event handler routines binded to  */
/*  to each active endpoint objects.  The event handler routines are binded   */
/*  to the endpoint objects during the endpoint object initialization         */
/*                                                                            */
/*  Author: MH                                                                */
/*  Date: 24 Nov 2000                                                         */
/*  Based on : Venkat Raghavan (TI India)                                     */
/*                                                                            */
/*============================================================================*/
/* Arguments:                                                                 */
/*                                                                            */
/* None                                                                       */
/*                                                                            */
/*============================================================================*/
/* Return Value:                                                              */
/*                                                                            */
/* None                                                                       */
/*                                                                            */ 
/*============================================================================*/
/* Comments:                                                                  */
/*                                                                            */
/* Any USB application build on CSL USB component must use this USB event     */
/* distacher function to hand the USB interrupts.  There are two ways users   */
/* can accomplish this.  The first method is interrupt polling , where  the   */
/* user's code polls the USB interrupt flag bit periodically and calls the    */
/* USB Event Dispatcher function every time the USB interrupt flag is set.    */
/* The second method is to encapsulate the USB Event Dispatcher function in   */
/* an ISR and set up the DSP interrupt vector table to service this ISR every */
/* time a USB event occurs.                                                   */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* 28 Sep 2001 $MH$                                                           */
/*                                                                            */
/* Converted INTERRUPT USB_isr() to void USB_evDispatch(void), so the         */
/* module can be used with DSP/BIOS                                           */
/*                                                                            */
/******************************************************************************/

CSLAPI void USB_evDispatch(void);                          

#endif /* USB_SUPPORT */

#endif

