/********************************************************************
** _cls_usb_apimap.h                                               **
**                                                                 **
** Copyright (c) 2003, Texas Instruments, Inc.                     **
** All rights reserved.                                            **
**                                                                 **
** TMS320VC5509 USB API map file                                   **
**                                                                 **
** Author: MH                                                      **
**                                                                 **
*********************************************************************/
#ifndef __CSL_USB_APIMAP_H
#define __CSL_USB_APIMAP_H

#define   USB_getEvents                 vUSB_getEvents              
#define   USB_peekEvents                vUSB_peekEvents                                              
#define   USB_getSetupPacket            vUSB_getSetupPacket                                                                     
#define   USB_postTransaction           vUSB_postTransaction                                                                    
#define   USB_isTransactionDone         vUSB_isTransactionDone                                                                   
#define   USB_bytesRemaining            vUSB_bytesRemaining                                                                     
#define   USB_stallEndpt                vUSB_stallEndpt                                                                         
#define   USB_clearEndptStall           vUSB_clearEndptStall                                                                    
#define   USB_getEndptStall             vUSB_getEndptStall                                                                      
#define   USB_initEndptObj              vUSB_initEndptObj
#define   USB_init                      vUSB_init
#define   USB_epNumToHandle             vUSB_epNumToHandle
#define   USB_abortTransaction          vUSB_abortTransaction                                                                      
#define   USB_abortAllTransaction       vUSB_abortAllTransaction
#define   USB_connectDev                vUSB_connectDev                                                                         
#define   USB_disconnectDev             vUSB_disconnectDev                                                                                                                                     
#define   USB_setRemoteWakeup           vUSB_setRemoteWakeup
#define   USB_getRemoteWakeupStat       vUSB_getRemoteWakeupStat
#define   USB_issueRemoteWakeup         vUSB_issueRemoteWakeup                                                                                                                         
#define   USB_resetDev                  vUSB_resetDev                                                   
#define   USB_setDevAddr                vUSB_setDevAddr                                                                                                                              
#define   USB_getFrameNo                vUSB_getFrameNo                                      
#define   USB_initPLL                   vUSB_initPLL 
#define   USB_evDispatch                vUSB_evDispatch   
                                                                        
#define   _USB_configEndpt              _vUSB_configEndpt                                                                                 
#define   _USB_addInterface             _vUSB_addInterface                                                                           
#define   _USB_resetFirmwareEnv         _vUSB_resetFirmwareEnv                                                                       
#define   _USB_enableEpIntrpt           _vUSB_enableEpIntrpt                                                                        
#define   _USB_disableEpIntrpt          _vUSB_disableEpIntrpt                                                                        
#define   _USB_enableDmaIntrpt          _vUSB_enableDmaIntrpt                                                                  
#define   _USB_disableDmaIntrpt         _vUSB_disableDmaIntrpt
#define   _USB_procCtrlOutTransaction   _vUSB_procCtrlOutTransaction                                                                               
#define   _USB_procCtrlInTransaction    _vUSB_procCtrlInTransaction                                                                        
#define   _USB_procDmaTransaction       _vUSB_procDmaTransaction
#define   _USB_gotoNextList             _vUSB_gotoNextList                                                                               
                                                                                          
#endif                                                                    
