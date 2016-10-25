/******************************************************************************/
/* $Id: _csl_usbdrvr.h,v 1.1.1.1 2001/08/16 16:12:53 a0323633 Exp $MH$                                             */
/*                                                                            */
/* This is proprietary information, not to be published -- TI INTERNAL DATA   */
/* Copyright (C) 1999, Texas Instruments, Inc.  All Rights Reserved.          */
/*                                                                            */
/* Header file for generic USB endpoint driver routine                        */
/* request handler can ask the control dispatcher to handle.                  */
/*                                                                            */
/******************************************************************************/

#ifndef __CSL_USBDRVR_H
#define __CSL_USBDRVR_H

#include <_csl.h>

#if (_USB_SUPPORT)

void         _USB_procCtrlInTransaction(USB_EpHandle hInEp0);
void         _USB_procCtrlOutTransaction(USB_EpHandle hOutEp0);
USB_Boolean  _USB_procDmaTransaction(USB_EpHandle hEp);
void         _USB_gotoNextList(USB_EpHandle hEp);
void         USB_evDispatch(void);

/******************************************************************************/
/*   03/23/01 $MH$                                                            */
/*                                                                            */
/*                  Vectored Prototypes for USB API                           */
/*                                                                            */
/******************************************************************************/
void         _vUSB_procCtrlInTransaction(USB_EpHandle hInEp0);
void         _vUSB_procCtrlOutTransaction(USB_EpHandle hOutEp0);
USB_Boolean  _vUSB_procDmaTransaction(USB_EpHandle hEp);
void         _vUSB_gotoNextList(USB_EpHandle hEp);
void         vUSB_evDispatch(void);

#else
  #ifndef _USB_MOD
     error USB Module Not Supported on Specified Target Device
  #endif
#endif   /* _USB_SUPPORT */
#endif
