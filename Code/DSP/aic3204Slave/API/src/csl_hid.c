/* ============================================================================
 * Copyright (c) 2008-2012 Texas Instruments Incorporated.
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/


/** @file csl_hid.c
 *
 *  @brief USB HID Class functional layer API source file
 *
 *  Path: \(CSLPATH)\ src
 */

/* ============================================================================
 * Revision History
 * ================
 * 24-Dec-2012 Created
 * ============================================================================
 */

#include <csl_hid.h>
#include <csl_hidAux.h>

#include <log.h>
#include <std.h>
#include <mbx.h>
#include <sem.h>
#include <swi.h>
#include <tsk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern CSL_UsbRegsOvly    usbRegisters;

unsigned char input[8];
Uint16        protocolVal;
Uint16        idleVal;

/** ============================================================================
 *   @n@b HID_Open
 *
 *   @b Description
 *   @n This function Opens the Hid class module.
 *      It initializes Hid and Ctrl handles with the data given
 *      by the application
 *
 *   @b Arguments
 *   @verbatim
            pAppClassHandle      Application handle to the Hid Class Obj
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK              - Returned for success
 *   @li                    CSL_ESYS_BADHANDLE   - Invalid Hid class handle
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Initializes Hid and Ctrl handles
 *
 *   @b Modifies
 *   @n Hid and Ctrl handle data
 *
 *   @b Example
 *   @verbatim
            CSL_HidInitStructApp    hidAppHandle;
            pHidAppClassHandle      pAppClassHandle;
            Uint16                 hidAppBuffer[420];
            CSL_Status             status;

            pAppClassHandle = &hidAppHandle;

            // Assign values to all the members in hidAppHandle struct
            hidAppHandle.pHidObj = &hidAppBuffer[0];
            .....
            .....
            status = HID_Open(pAppClassHandle);
     @endverbatim
 *  ============================================================================
 */
CSL_Status HID_Open(pHidAppClassHandle    pAppClassHandle,
                    CSL_UsbConfig         *usbConfig)
{
    pHidClassHandle   pHandle;
    CSL_Status        status;
    Uint16            eventMask;
	CSL_UsbEpConfig   usbEpConfig;

    status  = CSL_SOK;
    pHandle = (pHidClassHandle)(pAppClassHandle->pHidObj);

    if(pAppClassHandle != NULL)
    {
		USB_init();

		pHandle->usbDevHandle = USB_open (CSL_USB0);
		if (NULL == pHandle->usbDevHandle)
		{
			return (CSL_ESYS_BADHANDLE);
		}

		status = USB_config (pHandle->usbDevHandle, usbConfig);
		if (CSL_SOK != status)
		{
			return (status);
		}

		status = USB_resetDev(pHandle->usbDevHandle);
		if(status != CSL_SOK)
		{
			printf("USB Reset failed\n");
			return(status);
		}

        /* Initing CSL_HidCtrlObject */
        if (pAppClassHandle->numLun > 0)
        {
            pHandle->hidHandle.noOfLun = pAppClassHandle->numLun - 1;
        }

        pHandle->ctrlHandle.devNum = CSL_USB0;

        /* Initialising all default values */
        pHandle->ctrlHandle.suspendFlag   = 0;
        pHandle->ctrlHandle.curConfigStat = 0x0;


        pHandle->ctrlHandle.strDescr    = pAppClassHandle->strDescrApp;
        pHandle->ctrlHandle.hidReqTable = &pAppClassHandle->hidReqTableApp[0];

        /* Initiating CSL_HidObject */
        pHandle->hidHandle.lbaBufferHidReport = pAppClassHandle->lbaBufferHidReportApp;

        /* Initialising the default values for all the Hid Class Object */
        HID_initVal(&pHandle->hidHandle);

        pHandle->hidHandle.getHidReport = pAppClassHandle->getHidReportApp;

        /* Copying  user's VID and PID into the device descriptor */
        pHandle->ctrlHandle.deviceDescr[5] = pAppClassHandle->vId;
        pHandle->ctrlHandle.deviceDescr[6] = pAppClassHandle->pId;

        /* Initialize the Control Endpoint OUT 0 */
        eventMask = (CSL_USB_EVENT_RESET | CSL_USB_EVENT_SETUP |
                     CSL_USB_EVENT_SUSPEND | CSL_USB_EVENT_RESUME |
                     CSL_USB_EVENT_RESET | CSL_USB_EVENT_EOT);

#if 0
        USB_initEndptObj(pHandle->ctrlHandle.devNum,
                         &pHandle->ctrlHandle.ctrlOutEpHandle,
                         CSL_USB_OUT_EP0,
                         CSL_USB_CTRL,
                         CSL_USB_EP0_PACKET_SIZE,
                         eventMask,
                         pAppClassHandle->ctrlHandler);
#else
		pHandle->ctrlHandle.ctrlOutEpHandle = USB_requestEndpt (pHandle->usbDevHandle, CSL_USB_OUT_EP0, &status);
		if (CSL_SOK != status)
		{
			return (status);
		}

		usbEpConfig.opMode          = CSL_USB_OPMODE_POLLED;
		usbEpConfig.epNum           = CSL_USB_OUT_EP0;
		usbEpConfig.xferType        = CSL_USB_CTRL;
		usbEpConfig.maxPktSize      = CSL_USB_EP0_PACKET_SIZE;
		usbEpConfig.eventMask       = eventMask;
		usbEpConfig.dblPktBuf       = 0;
		usbEpConfig.asyncTxfer      = 0;
		usbEpConfig.fxn             = pAppClassHandle->ctrlHandler;

		status = USB_configEndpt (pHandle->ctrlHandle.ctrlOutEpHandle,
		                          &usbEpConfig);
		if (CSL_SOK != status)
		{
			return (status);
		}
#endif /* #if 0 */

#if 0
        /* Initialize the Control Endpoint IN 0 */
        USB_initEndptObj(pHandle->ctrlHandle.devNum,
                         &pHandle->ctrlHandle.ctrlInEpHandle,
                         CSL_USB_IN_EP0,
                         CSL_USB_CTRL,
                         CSL_USB_EP0_PACKET_SIZE,
                         CSL_USB_EVENT_EOT,
                         pAppClassHandle->ctrlHandler);
#else
		pHandle->ctrlHandle.ctrlInEpHandle = USB_requestEndpt (pHandle->usbDevHandle, CSL_USB_IN_EP0, &status);
		if (CSL_SOK != status)
		{
			return (status);
		}

		usbEpConfig.opMode          = CSL_USB_OPMODE_POLLED;
		usbEpConfig.epNum           = CSL_USB_IN_EP0;
		usbEpConfig.xferType        = CSL_USB_CTRL;
		usbEpConfig.maxPktSize      = CSL_USB_EP0_PACKET_SIZE;
		usbEpConfig.eventMask       = CSL_USB_EVENT_EOT;
		usbEpConfig.dblPktBuf       = 0;
		usbEpConfig.asyncTxfer      = 0;
		usbEpConfig.fxn             = pAppClassHandle->ctrlHandler;

		status = USB_configEndpt (pHandle->ctrlHandle.ctrlInEpHandle,
		                          &usbEpConfig);
		if (CSL_SOK != status)
		{
			return (status);
		}
#endif /* #if 0 */

#if 0
        /* Initialize the HID Interrupt Endpoint OUT 1 */
        USB_initEndptObj(pHandle->ctrlHandle.devNum,
                         &pHandle->hidHandle.hidIntOutEpHandle,
                         CSL_USB_OUT_EP1,
                         CSL_USB_INTR,
                         pAppClassHandle->hidTxPktSize,
                         CSL_USB_EVENT_EOT,
                         pAppClassHandle->hidHandler);
#else
		pHandle->hidHandle.hidIntOutEpHandle = USB_requestEndpt (pHandle->usbDevHandle, CSL_USB_OUT_EP1, &status);
		if (CSL_SOK != status)
		{
			return (status);
		}

		usbEpConfig.opMode          = CSL_USB_OPMODE_POLLED;
		usbEpConfig.epNum           = CSL_USB_OUT_EP1;
		usbEpConfig.xferType        = CSL_USB_INTR;
		usbEpConfig.maxPktSize      = pAppClassHandle->hidTxPktSize;
		usbEpConfig.eventMask       = CSL_USB_EVENT_EOT;
		usbEpConfig.dblPktBuf       = 0;
		usbEpConfig.asyncTxfer      = 0;
		usbEpConfig.fxn             = pAppClassHandle->hidHandler;

		status = USB_configEndpt (pHandle->hidHandle.hidIntOutEpHandle,
		                          &usbEpConfig);
		if (CSL_SOK != status)
		{
			return (status);
		}
#endif /* #if 0 */

#if 0
        /* Initialize the HID Interrupt Endpoint IN 2 */
        USB_initEndptObj(pHandle->ctrlHandle.devNum,
                         &pHandle->hidHandle.hidIntInEpHandle,
                         CSL_USB_IN_EP2,
                         CSL_USB_INTR,
                         pAppClassHandle->hidTxPktSize,
                         CSL_USB_EVENT_EOT,
                         pAppClassHandle->hidHandler);
#else
		pHandle->hidHandle.hidIntInEpHandle = USB_requestEndpt (pHandle->usbDevHandle, CSL_USB_IN_EP2, &status);
		if (CSL_SOK != status)
		{
			return (status);
		}

		usbEpConfig.opMode          = CSL_USB_OPMODE_POLLED; /* TBD */
		usbEpConfig.epNum           = CSL_USB_IN_EP2;
		usbEpConfig.xferType        = CSL_USB_INTR;
		usbEpConfig.maxPktSize      = pAppClassHandle->hidTxPktSize;
		usbEpConfig.eventMask       = CSL_USB_EVENT_EOT;
		usbEpConfig.dblPktBuf       = 0;
		usbEpConfig.asyncTxfer      = 0;
		usbEpConfig.fxn             = pAppClassHandle->hidHandler;

		status = USB_configEndpt (pHandle->hidHandle.hidIntInEpHandle,
		                          &usbEpConfig);
		if (CSL_SOK != status)
		{
			return (status);
		}
#endif /* #if 0 */

        pHandle->ctrlHandle.hidIfNum = pAppClassHandle->hidIfNum; // HID interface number
        pHandle->ctrlHandle.hidReportId = pAppClassHandle->hidReportId; // HID report ID
        pHandle->ctrlHandle.hidReportLen = pAppClassHandle->hidReportLen; // HID report length (bytes)
        pHandle->ctrlHandle.hidIdleRate = 0; // HID idle rate -- only indefinite duration supported

		/* hEpHandleArray needs to be setup */
		pHandle->ctrlHandle.hEpHandleArray[0] = pHandle->ctrlHandle.ctrlOutEpHandle;
		pHandle->ctrlHandle.hEpHandleArray[1] = pHandle->ctrlHandle.ctrlInEpHandle;
		pHandle->ctrlHandle.hEpHandleArray[2] = pHandle->hidHandle.hidIntOutEpHandle;
		pHandle->ctrlHandle.hEpHandleArray[3] = pHandle->hidHandle.hidIntInEpHandle;
		pHandle->ctrlHandle.hEpHandleArray[4] = NULL;
        pHandle->ctrlHandle.hEpHandleArray[5] = NULL;

        /* USB API setParams called for setup */
        USB_setParams(pHandle->usbDevHandle, pHandle->ctrlHandle.hEpHandleArray, FALSE);

        USB_connectDev(pHandle->usbDevHandle);
    }
    else
    {
        status = CSL_ESYS_BADHANDLE;
    }

    return(status);
}

/** ============================================================================
 *   @n@b HID_Close
 *
 *   @b Description
 *   @n This function Closes the Hid class module.
 *
 *   @b Arguments
 *   @verbatim
            pAppClassHandle       Application handle to the Hid Class Obj
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK              - Returned for success
 *   @li                    CSL_ESYS_BADHANDLE   - Invalid Hid class handle
 *
 *   <b> Pre Condition </b>
 *   @n  HID_Open function should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Closes the Hid Class module
 *
 *   @b Modifies
 *   @n Hid and Ctl handles
 *
 *   @b Example
 *   @verbatim
            CSL_HidInitStructApp    hidAppHandle;
            pHidAppClassHandle      pAppClassHandle;
            Uint16                 hidAppBuffer[420];
            CSL_Status             status;

            pAppClassHandle = &hidAppHandle;

            // Assign values to all the members in hidAppHandle struct
            hidAppHandle.pHidObj = &hidAppBuffer[0];
            .....
            .....
            status = HID_Open(pAppClassHandle);
            ....
            ....
            status = HID_Close(pAppClassHandle);
     @endverbatim
 *  ============================================================================
 */
CSL_Status HID_Close(pHidAppClassHandle    pAppClassHandle)
{
    pHidClassHandle       pHidClassHdl;
    CSL_Status           status;

    pHidClassHdl = (pHidClassHandle)(pAppClassHandle->pHidObj);
    status       = CSL_SOK;

    if(pAppClassHandle != NULL)
    {
        status = USB_disconnectDev(pHidClassHdl->usbDevHandle);
        pAppClassHandle->pHidObj = NULL;
    }
    else
    {
        status = CSL_ESYS_BADHANDLE;
    }

    return(status);
}

/** ============================================================================
 *   @n@b HID_Ctrl
 *
 *   @b Description
 *   @n This function handles all USB traffic on the Control Endpoint.
 *      Detects the events on the Control Endpoint and takes
 *      the appropriate action
 *
 *   @b Arguments
 *   @verbatim
            pHidObj        Handle to the Hid Class Obj
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li       CSL_SOK                          - Returned for success
 *   @li       CSL_ESYS_BADHANDLE               - Invalid Hid class handle
 *   @li       CSL_HID_INVALID_REQUEST_HANDLER   - Invalid request class handler
 *
 *   <b> Pre Condition </b>
 *   @n  HID_Open function should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Control end point events are serviced
 *
 *   @b Modifies
 *   @n USB Registers.
 *
 *   @b Example
 *   @verbatim
            CSL_HidInitStructApp    hidAppHandle;
            pHidAppClassHandle      pAppClassHandle;
            Uint16                 hidAppBuffer[420];
            CSL_Status             status;

            pAppClassHandle = &hidAppHandle;

            // Assign values to all the members in hidAppHandle struct
            hidAppHandle.pHidObj = &hidAppBuffer[0];
            .....
            .....
            status = HID_Open(pAppClassHandle);
            ....
            ....
            status = HID_Ctrl(pAppClassHandle->pHidObj);
     @endverbatim
 *  ============================================================================
 */
CSL_Status HID_Ctrl(void    *pHidObj)
{
    pHidClassHandle     pHidClassHdl;
    CSL_HidCtrlObject   *pCtrlHandle;
    CSL_HidRequestRet   reqHandlerRet;
    CSL_UsbEventMask    usbCtrlEvents;
    CSL_UsbEpHandle     hCtrlEpIn;
    CSL_UsbEpHandle     hCtrlEpOut;
    CSL_Status          status;
    Uint16              request;

    if(pHidObj == NULL)
    {
        return(CSL_ESYS_BADHANDLE);
    }

    pHidClassHdl  = (pHidClassHandle)(pHidObj);
    pCtrlHandle   = &pHidClassHdl->ctrlHandle;
    hCtrlEpIn     = pCtrlHandle->ctrlInEpHandle;
    hCtrlEpOut    = pCtrlHandle->ctrlOutEpHandle;
    reqHandlerRet = CSL_HID_REQUEST_DONE;

    pCtrlHandle->fpRequestHandler = HID_reqUnknown;
    /* Finding out which Endpoint caused this function to be called by responding */
    usbCtrlEvents = (USB_getEvents(hCtrlEpOut, &status) |
                     USB_getEvents(hCtrlEpIn, &status));

    /* Check for the RESET event, abort Endpoint Activities and Reconfigure
    the USB Module */
    if(usbCtrlEvents & CSL_USB_EVENT_RESET)
    {
        pCtrlHandle->suspendFlag = FALSE;
        /* Stop all Data transfer Activities */
        status |= USB_abortAllTransaction(pHidClassHdl->usbDevHandle);
        /* Reinitialize the Device */
        status |= USB_setParams(pHidClassHdl->usbDevHandle,
                                pCtrlHandle->hEpHandleArray, FALSE);
        /* Reset device Config No */
        pCtrlHandle->curConfigStat = FALSE;
    }

    if(usbCtrlEvents & CSL_USB_EVENT_SUSPEND)
    {
        pCtrlHandle->suspendFlag = TRUE;
    }

    if(usbCtrlEvents & CSL_USB_EVENT_RESUME)
    {
        pCtrlHandle->suspendFlag = FALSE;
    }

     /* If Event Received is Setup Packet,read the Packet and Lookup the
     Request Table for the Appropriate Request Handler */
     if((usbCtrlEvents & CSL_USB_EVENT_SETUP) == CSL_USB_EVENT_SETUP)
     {

        status |= USB_getSetupPacket(pHidClassHdl->usbDevHandle,
                                    &pCtrlHandle->usbSetup, FALSE);
        request = ((((pCtrlHandle->usbSetup.bmRequestType ) <<
                   CSL_HID_8BIT_SHIFT) & 0xF000) |
                   pCtrlHandle->usbSetup.bRequest);

        pCtrlHandle->fpRequestHandler = HID_lookupReqHandler(request,
                                                    pCtrlHandle->hidReqTable);

        if(reqHandlerRet == CSL_HID_REQUEST_DONE)
        {
            reqHandlerRet = (pCtrlHandle->fpRequestHandler)(pHidClassHdl->usbDevHandle,
                             &pCtrlHandle->usbSetup,hCtrlEpIn,hCtrlEpOut,pHidObj);
        }

        switch(reqHandlerRet)
        {
            /* The Request Handler Routine successfully completed the task,
            so 0 byte ACK is sent */
            case CSL_HID_REQUEST_SEND_ACK:
                status |= USB_postTransaction(hCtrlEpIn, 0, NULL,
                                              CSL_USB_IOFLAG_NONE);
                pCtrlHandle->fpRequestHandler = HID_reqUnknown;
                break;

            /* For Future Use */
            case CSL_HID_REQUEST_DATA_OUT:
                //printf("datout\n");
                break;

            /* The Request Handler Routine successfully completed the task,
            so 0 byte ACK is received */
            case CSL_HID_REQUEST_GET_ACK:
                status |= USB_postTransaction(hCtrlEpOut, 0, NULL,
                                              CSL_USB_IOFLAG_NONE);
                pCtrlHandle->fpRequestHandler = HID_reqUnknown;
                break;

            /* For Future Use */
            case CSL_HID_REQUEST_DATA_IN:
                //printf("datin\n");
                break;

            /* Request Handler is Confused about the Setup Packet, so Stall
            the Control Endpoints */
            case CSL_HID_REQUEST_STALL:
                status |= USB_stallEndpt(hCtrlEpOut);
                status |= USB_stallEndpt(hCtrlEpIn);

                // RDN: Try This
                //pCtrlHandle->fpRequestHandler = HID_reqUnknown;
                break;

            case CSL_HID_REQUEST_DONE:
                pCtrlHandle->fpRequestHandler = HID_reqUnknown;
                break;

            default:
                status = CSL_HID_INVALID_REQUEST_HANDLER;
                //printf("invalreq\n");
                break;
        }

        /* Clear the flags if New Setup Packet is Received */
        if(pCtrlHandle->usbSetup.newPacket)
        {
            pCtrlHandle->usbSetup.newPacket = FALSE;
        }
    }

    return(status);
}

/** ============================================================================
 *   @n@b HID_reportHandler
 *
 *   @b Description
 *   @n This function handles all USB traffic on the HID Interrupt Endpoint.
 *      Detects the events on the HID Endpoint and takes the appropriate action
 *
 *   @b Arguments
 *   @verbatim
            pHidObj        Handle to the Hid Class Obj
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li       CSL_SOK                          - Returned for success
 *   @li       CSL_ESYS_BADHANDLE               - Invalid Hid class handle
 *   @li       CSL_HID_INVALID_REQUEST_HANDLER   - Invalid request class handler
 *
 *   <b> Pre Condition </b>
 *   @n  HID_Open function should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  HID interrupt end point events are serviced
 *
 *   @b Modifies
 *   @n USB Registers.
 *
 *   @b Example
 *   @verbatim
            CSL_HidInitStructApp    hidAppHandle;
            pHidAppClassHandle      pAppClassHandle;
            Uint16                 hidAppBuffer[420];
            CSL_Status             status;

            pAppClassHandle = &hidAppHandle;

            // Assign values to all the members in hidAppHandle struct
            hidAppHandle.pHidObj = &hidAppBuffer[0];
            .....
            .....
            status = HID_Open(pAppClassHandle);
            ....
            ....
            status = HID_reportHandler(pAppClassHandle->pHidObj);
     @endverbatim
 *  ============================================================================
 */
CSL_Status HID_reportHandler(void    *pHidObj)
{
    pHidClassHandle     pHidClassHdl;
    CSL_HidCtrlObject   *pCtrlHandle;
    CSL_HidObject       *phidHandle;
    CSL_UsbEpHandle     hUsbInEp;
    CSL_Status          status;
    CSL_UsbEventMask    usbEvent;

    status = CSL_SOK;

    if (pHidObj != NULL)
    {
        pHidClassHdl = (pHidClassHandle)(pHidObj);
        pCtrlHandle  = &pHidClassHdl->ctrlHandle;
        phidHandle   = &pHidClassHdl->hidHandle;
        hUsbInEp     = phidHandle->hidIntInEpHandle;

        usbEvent = USB_getEvents(hUsbInEp, &status);

        if ((usbEvent & CSL_USB_EVENT_HID_REPORT_TX) == CSL_USB_EVENT_HID_REPORT_TX)
        {
            status = phidHandle->getHidReport(pCtrlHandle->hidReportLen,
                &phidHandle->lbaBufferHidReport[0]);

            /* Post transaction to USB */
            USB_postTransaction(phidHandle->hidIntInEpHandle, pCtrlHandle->hidReportLen,
                (void *)(&phidHandle->lbaBufferHidReport[0]), CSL_USB_IOFLAG_NONE);
        }
    }
    else
    {
        status = CSL_ESYS_BADHANDLE;
    }

    return CSL_SOK;
}

/** ============================================================================
 *   @n@b HID_initDescriptors
 *
 *   @b Description
 *   @n This function initializes the descriptors used by the USB Hid class
 *
 *   @b Arguments
 *   @verbatim
            pHidObj      Hid Class object
            descBuf     Descriptor buffer pointer
            descrId     Id of the Descriptor to initialize
            descrLen    Length of the descriptor to initialize (in bytes)
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK            - Returned for success
 *   @li                    CSL_ESYS_BADHANDLE - Invalid Ctrl handle
 *   @li                    CSL_ESYS_INVPARAMS - Invalid parameter
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Initializes descriptors
 *
 *   @b Modifies
 *   @n Descriptor buffers
 *
 *   @b Example
 *   @verbatim
            CSL_HidInitStructApp    hidAppHandle;
            pHidAppClassHandle      pAppClassHandle;
            Uint16                 hidAppBuffer[420];
            CSL_Status             status;

            pAppClassHandle = &hidAppHandle;

            // Assign values to all the members in hidAppHandle struct
            hidAppHandle.pHidObj = &hidAppBuffer[0];

            status = HID_initDescriptors(pAppClassHandle->pHidObj,
                                        CSL_HID_DEVICE_DESCR, 18);
     @endverbatim
 *  ============================================================================
 */
CSL_Status HID_initDescriptors(void             *pHidObj,
                              Uint16           *descBuf,
                              CSL_HidDescrId    descrId,
                              Uint16           descrLen)
{
    pHidClassHandle       pHidClassHdl;
    CSL_HidCtrlObject     *pCtrlHandle;
    CSL_Status           status;
    Uint16               length;

    status = CSL_ESYS_INVPARAMS;

    if(pHidObj != NULL)
    {
        pHidClassHdl = (pHidClassHandle)(pHidObj);
        pCtrlHandle  = &pHidClassHdl->ctrlHandle;

        switch(descrId)
        {
            /* Initialize the device descriptor */
            case CSL_HID_DEVICE_DESCR:
                if(descrLen <= CSL_HID_DEVICE_DESCR_MAX_LEN)
                {
                    pCtrlHandle->deviceDescr[0] = 0x0000;
                    for(length = 0; length < (descrLen+1)/2; length++)
                    {
                        //pCtrlHandle->deviceDescr[length+1] = descBuf[length];
                        pCtrlHandle->deviceDescr[length+1] = descBuf[(length*2)] | (descBuf[(length*2) + 1] << 8);
                    }
                    status = CSL_SOK;
                }
                break;

            /* Initialize the device qualifier descriptor */
            case CSL_HID_DEVICE_QUAL_DESCR:
                if(descrLen <= CSL_HID_DEV_QUAL_DESCR_MAX_LEN)
                {
                    pCtrlHandle->deviceQualifierDescr[0] = 0x0000;
                    for(length = 0; length < (descrLen+1)/2; length++)
                    {
                        pCtrlHandle->deviceQualifierDescr[length+1] = descBuf[length];
                        //pCtrlHandle->deviceQualifierDescr[length+1] = descBuf[length];
                    }
                    status = CSL_SOK;
                }
                break;


            /* Initialize the configuration descriptor */
            case CSL_HID_CONFIG_DESCR:
                if(descrLen <= CSL_HID_CONFIG_DESCR_MAX_LEN)
                {
                    pCtrlHandle->confDescr[0] = 0x0000;
                    for(length = 0; length < (descrLen+1)/2; length++)
                    {
                        //pCtrlHandle->confDescr[length+1] = descBuf[length];
                        pCtrlHandle->confDescr[length+1] = descBuf[(length*2)] | (descBuf[(length*2) + 1] << 8);
                    }
                    status = CSL_SOK;
                }
                break;

            /* Initialize the configuration descriptor */
            case CSL_HID_OTHER_SPEED_CONFIG_DESCR:
                if(descrLen <= CSL_HID_CONFIG_DESCR_MAX_LEN)
                {
                    pCtrlHandle->osConfDescr[0] = 0x0000;
                    for(length = 0; length < (descrLen+1)/2; length++)
                    {
                        //pCtrlHandle->confDescr[length+1] = descBuf[length];
                        pCtrlHandle->osConfDescr[length+1] = descBuf[(length*2)] | (descBuf[(length*2) + 1] << 8);
                    }
                    status = CSL_SOK;
                }
                break;

            /* Initialize the interface descriptor */
            case CSL_HID_INTERFACE_DESCR:
                if(descrLen <= CSL_HID_INTER_DESCR_MAX_LEN)
                {
                    pCtrlHandle->hidClassIntDescr[0] = 0x0000;
                    for(length = 0; length < (descrLen+1)/2; length++)
                    {
                        pCtrlHandle->hidClassIntDescr[length+1] = descBuf[length];
                    }
                    status = CSL_SOK;
                }
                break;
            /* Initialize the string descriptor language Id */
            case CSL_HID_STRING_LANGID_DESC:
                if(descrLen < CSL_HID_STRING_DESCR_LANGID_MAX_LEN)
                {
                    pCtrlHandle->stringDescrLangid[0] = 0x0000;
                    for(length = 0; length < (descrLen+1)/2; length++)
                    {
                        pCtrlHandle->stringDescrLangid[length+1] = descBuf[length];
                    }
                    status = CSL_SOK;
                }
                break;

            /* Initialize the HID report descriptor */
            case CSL_HID_REPORT_DESC:
                if (descrLen < CSL_HID_REPORT_DESCR_MAX_LEN)
                {
                    pCtrlHandle->hidClassHidReportDescrLen = descrLen; /* store descriptor length since contained at variable offset in configuration descriptor */
                    pCtrlHandle->hidClassHidReportDescr[0] = 0x0000;
                    for(length = 0; length < (descrLen+1)/2; length++)
                    {
                        pCtrlHandle->hidClassHidReportDescr[length+1] = descBuf[(length*2)] | (descBuf[(length*2) + 1] << 8);
                    }
                    status = CSL_SOK;
                }
                break;

            default :
                break;
        }
    }
    else
    {
        return(CSL_ESYS_BADHANDLE);
    }

    return(status);

}

/** ============================================================================
 *   @n@b HID_initHidVal
 *
 *   @b Description
 *   @n This function initializes the Hid Class object
 *
 *   @b Arguments
 *   @verbatim
            phidHandle        Handle to the Hid class Object
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK              - Returned for success
 *   @li                    CSL_ESYS_BADHANDLE   - Invalid Hid class handle
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Initializes Hid Class object
 *
 *   @b Modifies
 *   @n Hid Class object structure
 *
 *   @b Example
 *   @verbatim
            CSL_HidObject    hidObj;
            CSL_Status      status;

            status = HID_initHidVal(&hidObj);

     @endverbatim
 *  ============================================================================
 */
static CSL_Status HID_initVal(CSL_HidObject    *phidHandle)
{
    CSL_Status   status;

    status = CSL_SOK;

    if(phidHandle != NULL)
    {
        phidHandle->mediaState = 0;
    }
    else
    {
        status = CSL_ESYS_BADHANDLE;
    }

    return(status);
}

/** ============================================================================
 *   @n@b  HID_reqHidGetReport
 *
 *   @b Description
 *   @n This function handles the request from host to get HID report
 *
 *   @b Arguments
 *   @verbatim
             devNum       - USB device number
             usbSetup     - USb setup structure
             hInEp        - USB ISO In end point handle
             hOutEp       - USB ISO Out end point object
             pHidObj       - USB Hid Class object
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @li        CSL_HID_REQUEST_SEND_ACK - Send acknowledgement for request
 *   @li        CSL_HID_REQUEST_STALL    - Request stall signal (Error)
 *
 *   <b> Pre Condition </b>
 *   @n  HID_lookupReqHandler should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Sends acknowledgement
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
             CSL_HidInitStructApp   hidAppHandle;
             CSL_HidObject          *phidHandle;
             CSL_HidCtrlObject      *pCtrlHandle;
             CSL_UsbEpHandle        hUbOutEp;
             Uint16                 lunNum;
             Uint16                 hidAppBuffer[420];
             CSL_Status             status;
             Uint16                 request;

             // Assign values to all the members in hidAppHandle struct
             hidAppHandle.pHidObj = &hidAppBuffer[0];
             .....
             .....
             status = HID_Open(&hidAppHandle);
             ....
             ....
             pCtrlHandle->fpRequestHandler = HID_lookupReqHandler(request,
                                                       pCtrlHandle->hidReqTable);

             pCtrlHandle->fpRequestHandler(pCtrlHandle->devNum,
                                           &pCtrlHandle->usbSetup,hCtrlEpIn,hCtrlEpOut,pHidObj);
     @endverbatim
 *  ============================================================================
 */
CSL_HidRequestRet HID_reqHidGetReport(CSL_UsbDevHandle      devHandle,
                                      CSL_UsbSetupStruct    *usbSetup,
                                      CSL_UsbEpHandle       hInEp,
                                      CSL_UsbEpHandle       hOutEp,
                                      void                  *pHidObj)
{
    pHidClassHandle      pHidClassHdl;
    CSL_HidCtrlObject    *pCtrlHandle;
    CSL_HidObject        *phidHandle;
    Uint16              tempLen;
    CSL_Status          status;
	CSL_HidRequestRet    retStat;


    pHidClassHdl = (pHidClassHandle)(pHidObj);
    pCtrlHandle = &pHidClassHdl->ctrlHandle;

    if ((usbSetup->wIndex == pCtrlHandle->hidIfNum) && /* check HID interface */
        (usbSetup->wValue == (CSL_HID_INPUT_REPORT_TYPE << 8) | pCtrlHandle->hidReportId)) /* check valid Report Type (MSB) and ID (LSB) */
    {
        phidHandle   = &pHidClassHdl->hidHandle;

        /* Get report data */
        status = phidHandle->getHidReport(pCtrlHandle->hidReportLen,
            &phidHandle->lbaBufferHidReport[0]);

        /* Send data */
        if (status == CSL_SOK)
        {
            tempLen = pCtrlHandle->hidReportLen; /* length of report descriptor */
            /* select the smaller of two  */
            tempLen =
                (tempLen < usbSetup->wLength) ? tempLen : usbSetup->wLength;

            /* Post transaction to USB */
            USB_postTransaction(hInEp, tempLen,
                (void *)(&phidHandle->lbaBufferHidReport[0]),
                CSL_USB_IOFLAG_NONE);

            retStat = CSL_HID_REQUEST_GET_ACK;
        }
        else
        {
            retStat = CSL_HID_REQUEST_STALL;
        }
    }
    else
    {
	    retStat = CSL_HID_REQUEST_STALL;
    }

	return retStat;
}

/**
 * \brief API to handle USB HID Bus Stall request
 *
 * \param NONE
 *
 * \return NONE
 */
static void HID_stallBus(void)
{
    /* Set SERV_RXPKTRDY bit of PERI_CSR0 to clear RXPKTRDY bit */
    usbRegisters->PERI_CSR0 |= 0x40;

    /* Set SENDSTALL bit of PERI_CSR0 to transmit STALL and terminate the
       current transaction */
    usbRegisters->PERI_CSR0 |= 0x20;
}

/**
 * \brief API to handle USB HID Class Type Request
 *
 * \param hidAppHandle [IN] HID Class Object Handle
 * \param input        [IN] String that holds the Requests' details
 * \param usbSetUp     [IN] Pointer to USB set up structure
 *
 * \return NONE
 */
static void HID_classTypeReq(pHidAppClassHandle hidAppHandle,
                             unsigned char      *input,
                             CSL_UsbSetupStruct *usbSetUp)
{
	Uint8  			bRequest;
	Uint16 			bRequest_bmRequestType;
	Uint16 			wValue;

	pHidClassHandle appHidClassHandle;

	bRequest_bmRequestType = (Uint16)input[0];
	wValue                 = (Uint16)input[1];

	bRequest      = (Uint8)(bRequest_bmRequestType >> 8) & 0x00FF;

	appHidClassHandle = (pHidClassHandle)hidAppHandle->pHidObj;

	/*The below commands are only for compliance. These are not being used
	  by the HID driver */
    switch(bRequest)
    {
        case  CSL_USB_GET_PROTOCOL:
              USB_postTransaction(appHidClassHandle->ctrlHandle.ctrlInEpHandle, 1,
                                  &protocolVal, CSL_USB_IOFLAG_NONE);
              break;

        case  CSL_USB_SET_PROTOCOL:
              protocolVal = wValue;
              break;

        case  CSL_USB_GET_IDLE:
              USB_postTransaction(appHidClassHandle->ctrlHandle.ctrlInEpHandle, 1,
                                  &idleVal, CSL_USB_IOFLAG_NONE);
              break;

        case  CSL_USB_SET_IDLE:
              idleVal = wValue >> 8;
              break;

       default:  HID_stallBus();
              break;
    }
}

/**
 * \brief API to handle USB Vendor Request
 *
 * \param NONE
 *
 * \return NONE
 */
static void HID_vendorReq(void)
{
    HID_stallBus();
}

/**
 * \brief API to handle USB HID Set Address Request
 *
 * \param usbSetUp [IN] Pointer to USB set up structure
 *
 * \return NONE
 */
static void HID_setAddrReq(CSL_UsbSetupStruct *usbSetUp)
{
/*	usbSetUp->newPacket     = 1;
	usbSetUp->bmRequestType = bmRequestType;
	usbSetUp->bRequest      = bRequest;
	usbSetUp->wValue        = wValue;
	usbSetUp->wIndex        = wIndex;
	usbSetUp->wLength       = wLength;
*/
}

/**
 * \brief API to handle All the HID standard Requests
 *
 * \param hidAppHandle [IN] HID Class Object Handle
 * \param input        [IN] String that holds the Requests' details
 * \param usbSetUp     [IN] Pointer to USB set up structure
 *
 * \return NONE
 */
static void HID_stdRequest(pHidAppClassHandle hidAppHandle,
                           unsigned char      *input,
                           CSL_UsbSetupStruct *usbSetUp)
{
	CSL_HidRequestRet (*fpRequestHandler)(CSL_HID_REQUEST_ARGS);

	Uint8  			bRequest;
	Uint8  			bmRequestType;
	Uint16 			bRequest_bmRequestType;
	Uint16 			wValue;
	Uint16 			wIndex;
	Uint16 			wLength;
	pHidClassHandle appHidClassHandle;

	bRequest_bmRequestType = (Uint16)input[0];
	wValue                 = (Uint16)input[1];
	wIndex                 = (Uint16)input[2];
	wLength                = (Uint16)input[3];

	bRequest      = (Uint8)(bRequest_bmRequestType >> 8) & 0x00FF;
    bmRequestType = (Uint8)(bRequest_bmRequestType) & 0x00FF;

	appHidClassHandle = (pHidClassHandle)hidAppHandle->pHidObj;
    fpRequestHandler  = NULL;

    switch(bRequest)
    {
        case  CSL_USB_GET_STATUS:
            fpRequestHandler = HID_reqGetStatus;
            break;

        case  CSL_USB_CLEAR_FEATURE:
            fpRequestHandler = HID_reqClearFeature;
            break;

        case  CSL_USB_SET_FEATURE:
            fpRequestHandler = HID_reqSetFeature;
            break;

        case  CSL_USB_SET_ADDRESS:
            HID_setAddrReq(usbSetUp);
            break;

        case  CSL_USB_GET_DESCRIPTOR:
            fpRequestHandler = HID_reqGetDescriptor;
            break;

        case  CSL_USB_SET_DESCRIPTOR:
            fpRequestHandler = HID_reqUnknown;
            break;

        case  CSL_USB_GET_CONFIGURATION:
            fpRequestHandler = HID_reqGetConfiguration;
            break;

        case  CSL_USB_SET_CONFIGURATION:
            fpRequestHandler = HID_reqSetConfiguration;
            break;

        case  CSL_USB_GET_INTERFACE:
            fpRequestHandler = HID_reqGetConfiguration;//HID_reqGetInterface;
            break;

        case  CSL_USB_SET_INTERFACE:
            fpRequestHandler = HID_reqSetConfiguration;//HID_reqSetInterface;
            break;

        //case  CSL_USB_SYNCH_FRAME:
            //synch_frame();
            //break;

       default:  HID_stallBus();
            break;
    }

	usbSetUp->newPacket     = 1;
	usbSetUp->bmRequestType = bmRequestType;
	usbSetUp->bRequest      = bRequest;
	usbSetUp->wValue        = wValue;
	usbSetUp->wIndex        = wIndex;
	usbSetUp->wLength       = wLength;

    if (fpRequestHandler != NULL)
    {
		fpRequestHandler(appHidClassHandle->usbDevHandle,
		                 usbSetUp,
		                 appHidClassHandle->ctrlHandle.ctrlInEpHandle,
		                 appHidClassHandle->ctrlHandle.ctrlOutEpHandle,
		                 (void *)hidAppHandle->pHidObj);
	}
}

/**
 * \brief API to handle Set Up Request
 *
 * \param hidAppHandle [IN] HID Class Object Handle
 * \param input        [IN] String that holds the Requests' details
 * \param usbSetUp     [IN] Pointer to USB set up structure
 *
 * \return NONE
 */
static void HID_ReqSetup(pHidAppClassHandle hidAppHandle,
                         unsigned char      *input,
                         CSL_UsbSetupStruct *usbSetUp)
{
	Uint16 bRequest_bmRequestType;
	Uint8  bmRequestType;

	bRequest_bmRequestType = (Uint16)input[0];

    bmRequestType = (Uint8)(bRequest_bmRequestType) & 0x00FF;

    /* SETUP packet received, parse the received packet */
    switch(bmRequestType&0x60)
    {
        case 0x00:  HID_stdRequest(hidAppHandle, input, usbSetUp);
            break;

        case 0x20:  HID_classTypeReq(hidAppHandle, input, usbSetUp); /* A place holder, not implemented */
            break;

        case 0x40:  HID_vendorReq();    /* A place holder, not implemented */
            break;

        default:    HID_stallBus(); /* Unrecognized request type */
            break;
    }
}

/** ============================================================================
 *   @n@b HID_eventHandler
 *
 *   @b Description
 *   @n This function handles all HID data transactions
 *
 *   @b Arguments
 *   @verbatim
			pContext		 Pointer to the USBContext structure
            hHidClass        Handle to the HID Class Obj
            usbSetUp         Structure to hold the USB Set up Values that were
                             used to configure the USB End Point
     @endverbatim
 *
 *   <b> Return Value </b>  - Status of the processing (CSL_Status)
 *   @li    CSL_SOK                    (0)         Success
 *   @li    CSL_ESYS_FAIL              (-1)        Generic failure
 *   @li    CSL_ESYS_BADHANDLE         (-5)        Handle passed to CSL was invalid
 *   @li    CSL_ESYS_INVPARAMS         (-6)        Invalid parameters
 *
 *   <b> Pre Condition </b>
 *   @n  HID module should be opened using HID_Open function
 *
 *   <b> Post Condition </b>
 *   @n  Returns request processing status
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
			CSL_HidInitStructApp    pHidAppHandle;
			CSL_HidClassStruct      hidClassStruct;
			CSL_UsbSetupStruct      usbSetUp;
			CSL_Status              status;

			// Assign values to all the members in hidAppHandle struct
			hidAppHandle.pHidObj = &hidClassStruct;
			.....
			.....
			status = HID_Open(pHidAppHandle);
			....
			....

			in USB ISR:
			....
			....
			if (pContext->dwIntSourceL & (1<<CSL_USB_IN_EP0))
			{
				// Handle the HID Event
				HID_eventHandler(pContext, &pHidAppHandle, &usbSetUp);
			}
			....
			....
     @endverbatim
 *  ============================================================================
 */
void HID_eventHandler(pUsbContext        pContext,
                      pHidAppClassHandle pHidAppHandle,
                      CSL_UsbSetupStruct *usbSetUp)
{
	Uint16          RXPKTRDY;
	Uint16          TXPKTRDY;
	Uint16          SENTSTALL;
    int             j;
	Uint16          *inPtr;
	Uint16          bRequest_bmRequestType;
	static Uint8    bRequest = 0;
	pHidClassHandle appHidClassHandle;

	appHidClassHandle = (pHidClassHandle)pHidAppHandle->pHidObj;
	inPtr             = (Uint16 *)input;

	RXPKTRDY  = (usbRegisters->PERI_CSR0 & 0x0001);
	TXPKTRDY  = (usbRegisters->PERI_CSR0 & 0x0002);
	SENTSTALL = (usbRegisters->PERI_CSR0 & 0x0004);

	TXPKTRDY = TXPKTRDY; /* To remove warning */

	/* If a bus error occurred: abort current transfer, clear SENTSTALL bit */
	if (SENTSTALL == 0x0004)
	{
		usbRegisters->PERI_CSR0 &= ~0x0004; //clear SENTSTALL bit
	}
	/* If a packet has been received without bus-error */
	else if (RXPKTRDY == 0x0001)
	{
		for (j = 0; j < 4; j++)
		{
			*inPtr = usbRegisters->FIFO0R1;
			inPtr++;
		}
		inPtr = (Uint16 *)input; // Reset the pointer back to the beginning of input-buffer
		usbRegisters->PERI_CSR0 |= 0x40;  // Set (B6) of PERI_CSR0: received package served

		bRequest_bmRequestType = (Uint16)input[0];

        bRequest = (Uint8)(bRequest_bmRequestType >> 8) & 0x00FF;

		HID_ReqSetup(pHidAppHandle, input, usbSetUp);
	}
	/* Other interrupts without receiving a package */
	else
	{
		if (bRequest == 0x05)
		{
			HID_reqSetAddress(appHidClassHandle->usbDevHandle,
							  usbSetUp,
							  appHidClassHandle->ctrlHandle.ctrlInEpHandle,
							  appHidClassHandle->ctrlHandle.ctrlOutEpHandle,
							  (void *)pHidAppHandle->pHidObj);
		}

	}

	/* Set INDEX pointing to EP0 and no test mode */
	usbRegisters->INDEX_TESTMODE = 0x0000;
}

