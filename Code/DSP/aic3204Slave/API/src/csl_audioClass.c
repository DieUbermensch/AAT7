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


/** @file csl_audioClass.c
 *
 *  @brief USB Audio Class functional layer API source file
 *
 *  Path: \(CSLPATH)\ src
 */

/* ============================================================================
 * Revision History
 * ================
 * 10-Dec-2008 Created
 * 08-May-2009 Modifed to fix the string desc ASCII to UNICODE conversion issue
 * 28-May-2009 Modifed as per the review comments
 * 13-Aug-2010 CSL v2.10 release
 * 06-Jul-2011 CSL v2.50 release
 * 12-Jul-2012 Added new license header
 * 13-Sep-2012 CSL v3.00 release
 * 20-Dec-2012 CSL v3.01 release
 * ============================================================================
 */
#include <string.h>
#include <stdio.h>

#include <csl_audioClass.h>
#include <csl_audioClassAux.h>

/** ============================================================================
 *   @n@b AC_Open
 *
 *   @b Description
 *   @n This function Opens the Audio class module.
 *      It initializes Ac and Ctrl handles with the data given
 *      by the application
 *
 *   @b Arguments
 *   @verbatim
		    pAppClassHandle      Application handle to the Audio Class Obj
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK              - Returned for success
 *   @li                    CSL_ESYS_BADHANDLE   - Invalid Audio class handle
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Initializes Ac and Ctrl handles
 *
 *   @b Modifies
 *   @n Ac and Ctrl handle data
 *
 *   @b Example
 *   @verbatim
			CSL_AcInitStructApp    acAppHandle;
			pAcAppClassHandle      pAppClassHandle;
			Uint16                 acAppBuffer[420];
			CSL_Status             status;

			pAppClassHandle = &acAppHandle;

			// Assign values to all the members in acAppHandle struct
			acAppHandle.pAcObj = &acAppBuffer[0];
			.....
			.....
			status = AC_Open(pAppClassHandle);
     @endverbatim
 *  ============================================================================
 */
CSL_Status AC_Open(pAcAppClassHandle    pAppClassHandle)
{
	pAcClassHandle    pHandle;
	CSL_Status        status;
	Uint16            eventMask;
	CSL_UsbConfig     usbConfig;
	CSL_UsbEpConfig   usbEpConfig;

	status  = CSL_SOK;
	pHandle = (pAcClassHandle)(pAppClassHandle->pAcObj);

	if(pAppClassHandle != NULL)
	{
		/* Initing CSL_AcCtrlObject */
		if (pAppClassHandle->numLun > 0)
		{
			pHandle->acHandle.noOfLun = pAppClassHandle->numLun - 1;
		}

		USB_init();

		/* Requesting handle to Ctrl End Point */
		pHandle->usbDevHandle = USB_open (CSL_USB0);
		if (NULL == pHandle->usbDevHandle)
		{
			status = CSL_ESYS_BADHANDLE;
			return (status);
		}

		status = USB_config (pHandle->usbDevHandle, &usbConfig);
		if (CSL_SOK != status)
		{
			return (status);
		}

		/* Reset the USB device */
		status = USB_resetDev(pHandle->usbDevHandle);
		if(status != CSL_SOK)
		{
			printf("USB Reset failed\n");
			return(status);
		}

		pHandle->ctrlHandle.devNum = CSL_USB0;

		/* Initilialising all default values */
		pHandle->ctrlHandle.suspendFlag   = 0;
		pHandle->ctrlHandle.curConfigStat = 0x0;

		pHandle->ctrlHandle.getMinBuffer[0] = 0x0000;
		pHandle->ctrlHandle.getMinBuffer[1] = 0xa180;

		pHandle->ctrlHandle.getMaxBuffer[0] = 0x0000;
		pHandle->ctrlHandle.getMaxBuffer[1] = 0x0000;

		pHandle->ctrlHandle.getResBuffer[0] = 0x0000;
		pHandle->ctrlHandle.getResBuffer[1] = 0x0180;

		/* Copying the Application Specific values to the Audio Class Handle */
		pAppClassHandle->strDescrApp[0] =
		                 (char*)&pHandle->ctrlHandle.stringDescrLangid[0];

		pHandle->ctrlHandle.strDescr    = &pAppClassHandle->strDescrApp[0];
		pHandle->ctrlHandle.acReqTable = &pAppClassHandle->acReqTableApp[0];
		pHandle->acHandle.lbaBuffer    = pAppClassHandle->lbaBufferApp;

		pHandle->acHandle.mediaInitDone  = TRUE;
		pHandle->acHandle.playBackActive = FALSE;

		/* Initing CSL_AcObject */
		pHandle->acHandle.lbaBuffer = pAppClassHandle->lbaBufferApp;

		/* Initialising the default values for all the Audio Class Object */
		AC_initAcVal(&pHandle->acHandle);

		pHandle->acHandle.recordAudio  = pAppClassHandle->recordAudioApp;
		pHandle->acHandle.playAudio    = pAppClassHandle->playAudioApp;
		pHandle->acHandle.mediaGetPresentState =
		                           pAppClassHandle->mediaGetPresentStateApp;
		pHandle->acHandle.mediaInit     = pAppClassHandle->mediaInitApp;
		pHandle->acHandle.mediaEject    = pAppClassHandle->mediaEjectApp;
		pHandle->acHandle.mediaLockUnit = pAppClassHandle->mediaLockUnitApp;
		pHandle->acHandle.getMediaSize  = pAppClassHandle->getMediaSizeApp;
		pHandle->acHandle.stopAudio     = pAppClassHandle->stopAudioApp;

		/* Copying  user's VID and PID into the device descriptor */
		pHandle->ctrlHandle.deviceDescr[5] = pAppClassHandle->vId;
		pHandle->ctrlHandle.deviceDescr[6] = pAppClassHandle->pId;

		/* Initialized the Control Endpoint OUT 0 */
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
		/* Initialized the Control Endpoint IN 0 */
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
		/* Initialized the Iso Endpoint OUT 2 */
		USB_initEndptObj(pHandle->ctrlHandle.devNum,
		                 &pHandle->acHandle.isoOutEpHandle,
		                 CSL_USB_OUT_EP2,
						 CSL_USB_ISO,
		                 pAppClassHandle->rxPktSize,
		                 CSL_USB_EVENT_EOT,
		                 pAppClassHandle->isoHandler);
#else
		pHandle->acHandle.isoOutEpHandle = USB_requestEndpt (pHandle->usbDevHandle, CSL_USB_OUT_EP2, &status);
		if (CSL_SOK != status)
		{
			return (status);
		}

		usbEpConfig.opMode          = CSL_USB_OPMODE_POLLED;
		usbEpConfig.epNum           = CSL_USB_OUT_EP2;
		usbEpConfig.xferType        = CSL_USB_ISO;
		usbEpConfig.maxPktSize      = CSL_USB_EP0_PACKET_SIZE;
		usbEpConfig.eventMask       = CSL_USB_EVENT_EOT;
		usbEpConfig.dblPktBuf       = 0;
		usbEpConfig.asyncTxfer      = 0;
		usbEpConfig.fxn             = pAppClassHandle->isoHandler;

		status = USB_configEndpt (pHandle->acHandle.isoOutEpHandle,
		                          &usbEpConfig);
		if (CSL_SOK != status)
		{
			return (status);
		}
#endif /* #if 0 */

		/* hEpHandleArray needs to be setup */
		pHandle->ctrlHandle.hEpHandleArray[0] = pHandle->ctrlHandle.ctrlOutEpHandle;
		pHandle->ctrlHandle.hEpHandleArray[1] = pHandle->ctrlHandle.ctrlInEpHandle;
		pHandle->ctrlHandle.hEpHandleArray[2] = pHandle->acHandle.isoOutEpHandle;
		pHandle->ctrlHandle.hEpHandleArray[3] = pHandle->acHandle.isoInEpHandle;
		pHandle->ctrlHandle.hEpHandleArray[4] = NULL;

		/* USB API setParams called for setup */
		USB_setParams(pHandle->usbDevHandle, pHandle->ctrlHandle.hEpHandleArray, 0x0);

		USB_connectDev(pHandle->usbDevHandle);
	}
	else
	{
		status = CSL_ESYS_BADHANDLE;
	}

	return(status);
}

/** ============================================================================
 *   @n@b AC_Close
 *
 *   @b Description
 *   @n This function Closes the audio class module.
 *
 *   @b Arguments
 *   @verbatim
            pAppClassHandle       Application handle to the Audio Class Obj
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK              - Returned for success
 *   @li                    CSL_ESYS_BADHANDLE   - Invalid Audio class handle
 *
 *   <b> Pre Condition </b>
 *   @n  AC_Open function should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Closes the Audio Class module
 *
 *   @b Modifies
 *   @n Ac and Ctl handles
 *
 *   @b Example
 *   @verbatim
			CSL_AcInitStructApp    acAppHandle;
			pAcAppClassHandle      pAppClassHandle;
			Uint16                 acAppBuffer[420];
			CSL_Status             status;

			pAppClassHandle = &acAppHandle;

			// Assign values to all the members in acAppHandle struct
			acAppHandle.pAcObj = &acAppBuffer[0];
			.....
			.....
			status = AC_Open(pAppClassHandle);
			....
			....
			status = AC_Close(pAppClassHandle);
     @endverbatim
 *  ============================================================================
 */
CSL_Status AC_Close(pAcAppClassHandle    pAppClassHandle)
{
	pAcClassHandle       pAcClassHdl;
	//CSL_AcCtrlObject     *pCtrlHandle;
	CSL_Status           status;

	pAcClassHdl = (pAcClassHandle)(pAppClassHandle->pAcObj);
	//pCtrlHandle  = &pAcClassHdl->ctrlHandle;
	status       = CSL_SOK;

	if(pAppClassHandle != NULL)
	{
		status = USB_disconnectDev(pAcClassHdl->usbDevHandle);
		if (status == CSL_SOK)
		{
			///status = USB_close(pAcClassHdl->usbDevHandle);
		}

		pAppClassHandle->pAcObj = NULL;
	}
	else
	{
		status = CSL_ESYS_BADHANDLE;
	}

	return(status);
}

/** ============================================================================
 *   @n@b AC_Ctrl
 *
 *   @b Description
 *   @n This function handles all USB traffic on the Control Endpoint.
 *      Detects the events on the Control Endpoint and takes
 *      the appropriate action
 *
 *   @b Arguments
 *   @verbatim
            pAcObj        Handle to the Audio Class Obj
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li       CSL_SOK                          - Returned for success
 *   @li       CSL_ESYS_BADHANDLE               - Invalid Audio class handle
 *   @li       CSL_AC_INVALID_REQUEST_HANDLER   - Invalid request class handler
 *
 *   <b> Pre Condition </b>
 *   @n  AC_Open function should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Control end point events are serviced
 *
 *   @b Modifies
 *   @n USB Registers.
 *
 *   @b Example
 *   @verbatim
			CSL_AcInitStructApp    acAppHandle;
			pAcAppClassHandle      pAppClassHandle;
			Uint16                 acAppBuffer[420];
			CSL_Status             status;

			pAppClassHandle = &acAppHandle;

			// Assign values to all the members in acAppHandle struct
			acAppHandle.pAcObj = &acAppBuffer[0];
			.....
			.....
			status = AC_Open(pAppClassHandle);
			....
			....
            status = AC_Ctrl(pAppClassHandle->pAcObj);
     @endverbatim
 *  ============================================================================
 */
CSL_Status AC_Ctrl(void    *pAcObj)
{
	pAcClassHandle      pAcClassHdl;
    CSL_AcCtrlObject    *pCtrlHandle;
	CSL_AcRequestRet    reqHandlerRet;
    CSL_UsbEventMask    usbCtrlEvents;
    CSL_UsbEpHandle     hCtrlEpIn;
	CSL_UsbEpHandle     hCtrlEpOut;
	CSL_Status          status;
    Uint16              request;

    if(pAcObj == NULL)
    {
		return(CSL_ESYS_BADHANDLE);
	}

    pAcClassHdl   = (pAcClassHandle)(pAcObj);
    pCtrlHandle   = &pAcClassHdl->ctrlHandle;
    hCtrlEpIn     = pCtrlHandle->ctrlInEpHandle;
    hCtrlEpOut    = pCtrlHandle->ctrlOutEpHandle;
    reqHandlerRet = CSL_AC_REQUEST_DONE;

    pCtrlHandle->fpRequestHandler = AC_reqUnknown;
    /* Finding out which Endpoint caused this function to be called by responding */
    usbCtrlEvents = (USB_getEvents(hCtrlEpOut, &status) |
                     USB_getEvents(hCtrlEpIn, &status));

    /* Check for the RESET event, abort Endpoint Activities and Reconfigure
    the USB Module */
	if(usbCtrlEvents & CSL_USB_EVENT_RESET)
	{
		pCtrlHandle->suspendFlag = FALSE;
		/* Stop all Data transfer Activities */
		status |= USB_abortAllTransaction(pAcClassHdl->usbDevHandle);
		/* Reinitialize the Device */
		status |= USB_setParams(pAcClassHdl->usbDevHandle,
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

		status |= USB_getSetupPacket(pAcClassHdl->usbDevHandle,
		                            &pCtrlHandle->usbSetup, FALSE);
		request = ((((pCtrlHandle->usbSetup.bmRequestType ) <<
		           CSL_AC_8BIT_SHIFT) & 0xF000) |
				   pCtrlHandle->usbSetup.bRequest);

		pCtrlHandle->fpRequestHandler = AC_lookupReqHandler(request,
	                                                pCtrlHandle->acReqTable);

	    if(reqHandlerRet == CSL_AC_REQUEST_DONE)
	    {
			reqHandlerRet = (pCtrlHandle->fpRequestHandler)(pAcClassHdl->usbDevHandle,
					         &pCtrlHandle->usbSetup,hCtrlEpIn,hCtrlEpOut,pAcObj);
		}

		switch(reqHandlerRet)
		{
			/* The Request Handler Routine successfully completed the task,
			so 0 byte ACK is sent */
			case CSL_AC_REQUEST_SEND_ACK:
				status |= USB_postTransaction(hCtrlEpIn, 0, NULL,
				                              CSL_USB_IOFLAG_NONE);
				pCtrlHandle->fpRequestHandler = AC_reqUnknown;
				break;

			/* For Future Use */
			case CSL_AC_REQUEST_DATA_OUT:
				break;

			/* The Request Handler Routine successfully completed the task,
			so 0 byte ACK is received */
			case CSL_AC_REQUEST_GET_ACK:
				status |= USB_postTransaction(hCtrlEpOut, 0, NULL,
				                              CSL_USB_IOFLAG_NONE);
				pCtrlHandle->fpRequestHandler = AC_reqUnknown;
				break;

			/* For Future Use */
			case CSL_AC_REQUEST_DATA_IN:
				break;

			/* Request Handler is Confused about the Setup Packet, so Stall
			the Control Endpoints */
			case CSL_AC_REQUEST_STALL:
				status |= USB_stallEndpt(hCtrlEpOut);
				status |= USB_stallEndpt(hCtrlEpIn);
				break;

			case CSL_AC_REQUEST_DONE:
				pCtrlHandle->fpRequestHandler = AC_reqUnknown;
				break;

			default:
				status = CSL_AC_INVALID_REQUEST_HANDLER;
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
 *   @n@b AC_Iso
 *
 *   @b Description
 *   @n This function handles all UBS traffic on the Isochronous Endpoint
 *      This maintains the state of the Audio class application.
 *      Provides Media Access Data to the low level USB module for transfer.
 *
 *   @b Arguments
 *   @verbatim
            pAcObj        Handle to the Audio Class Obj
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li         CSL_SOK              - Returned for success
 *   @li         CSL_ESYS_BADHANDLE   - Invalid Audio class handle
 *   @li         CSL_ESYS_INVPARAMS   - Returned for invalid parameters
 *
 *   <b> Pre Condition </b>
 *   @n  AC_Open function should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Transfers data on iso end points
 *
 *   @b Modifies
 *   @n USB data buffeters
 *
 *   @b Example
 *   @verbatim
			CSL_AcInitStructApp    acAppHandle;
			pAcAppClassHandle      pAppClassHandle;
			Uint16                 acAppBuffer[420];
			CSL_Status             status;

			pAppClassHandle = &acAppHandle;

			// Assign values to all the members in acAppHandle struct
			acAppHandle.pAcObj = &acAppBuffer[0];
			.....
			.....
			status = AC_Open(pAppClassHandle);
			....
			....
			status = AC_Iso(pAppClassHandle->pAcObj);
     @endverbatim
 *  ============================================================================
 */
CSL_Status AC_Iso(void    *pAcObj)
{
	pAcClassHandle      pAcClassHdl;
	CSL_AcObject        *pAcHandle;
	CSL_UsbEpHandle     hUsbOutEp;
	CSL_Status          status;
	CSL_UsbEventMask    usbEvent;

	status = CSL_SOK;

	if(pAcObj != NULL)
	{
		pAcClassHdl = (pAcClassHandle)(pAcObj);
		pAcHandle   = &pAcClassHdl->acHandle;
		hUsbOutEp   = pAcHandle->isoOutEpHandle;

		usbEvent = USB_getEvents(hUsbOutEp, &status);

		if((usbEvent & CSL_USB_EVENT_ISO_RX) == CSL_USB_EVENT_ISO_RX)
		{
			status = USB_postTransaction(pAcHandle->isoOutEpHandle, hUsbOutEp->maxPktSize,
                             &pAcHandle->lbaBuffer[0],
                             CSL_USB_IOFLAG_NOSHORT);
		}

		if((usbEvent & CSL_USB_EVENT_WRITE_MEDIA) == CSL_USB_EVENT_WRITE_MEDIA)
		{
			status = pAcHandle->playAudio(hUsbOutEp->maxPktSize/2, &pAcHandle->lbaBuffer[0],
			                              &pAcHandle->lbaBuffer[0], (void*)(&pAcHandle->playBackActive));
		}
	}
	else
	{
		status = CSL_ESYS_BADHANDLE;
	}

	return(status);
}

/** ============================================================================
 *   @n@b AC_GetactivityFlagStatus
 *
 *   @b Description
 *   @n This function gives the status of the activity Flag
 *
 *   @b Arguments
 *   @verbatim
            pAcObj        Handle to the Audio Class Obj
     @endverbatim
 *
 *   <b> Return Value </b>  - Status of the activity flag
 *   @li                     '1' - If the activity is present
 *   @li                     '0' - If the activity is not present
 *
 *   <b> Pre Condition </b>
 *   @n  AC_Open function should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Returns Activity flag status
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
			Uint16                 activityFlagStat;
			CSL_AcInitStructApp    acAppHandle;
			pAcAppClassHandle      pAppClassHandle;
			Uint16                 acAppBuffer[420];
			CSL_Status             status;

			pAppClassHandle = &acAppHandle;

			// Assign values to all the members in acAppHandle struct
			acAppHandle.pAcObj = &acAppBuffer[0];
			.....
			.....
			status = AC_Open(pAppClassHandle);
			....
			....
			activityFlagStat = AC_GetactivityFlagStatus(pAppClassHandle->pAcObj);
     @endverbatim
 *  ============================================================================
 */
Uint16 AC_GetactivityFlagStatus(void    *pAcObj)
{
   pAcClassHandle    pAcClassHdl;
   CSL_AcObject      *pAcHandle;

   pAcClassHdl = (pAcClassHandle)(pAcObj);
   pAcHandle   = &pAcClassHdl->acHandle;

   return(pAcHandle->activityPresentFlag);
}

/** ============================================================================
 *   @n@b AC_GetsuspendFlagStatus
 *
 *   @b Description
 *   @n This function gives the status of the suspend Flag
 *
 *   @b Arguments
 *   @verbatim
            pAcObj        Handle to the Audio Class Obj
     @endverbatim
 *
 *   <b> Return Value </b>  - Status of the suspend flag
 *   @li                     '1' - If the device is suspended
 *   @li                     '0' - If the device is not suspended
 *
 *   <b> Pre Condition </b>
 *   @n  AC_Open function should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Returns suspend flag status
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
			Uint16                 suspendFlagStat;
			CSL_AcInitStructApp    acAppHandle;
			pAcAppClassHandle      pAppClassHandle;
			Uint16                 acAppBuffer[420];
			CSL_Status             status;

			pAppClassHandle = &acAppHandle;

			// Assign values to all the members in acAppHandle struct
			acAppHandle.pAcObj = &acAppBuffer[0];
			.....
			.....
			status = AC_Open(pAppClassHandle);
			....
			....
			suspendFlagStat = AC_GetsuspendFlagStatus(pAppClassHandle->pAcObj);
     @endverbatim
 *  ============================================================================
 */
Uint16 AC_GetsuspendFlagStatus(void    *pAcObj)
{
   pAcClassHandle       pAcClassHdl;
   CSL_AcCtrlObject     *pCtrlHandle;

   pAcClassHdl = (pAcClassHandle)(pAcObj);
   pCtrlHandle = &pAcClassHdl->ctrlHandle;

   return(pCtrlHandle->suspendFlag);
}

/** ============================================================================
 *   @n@b AC_initDescriptors
 *
 *   @b Description
 *   @n This function initializes the descriptors used by the USB audio class
 *
 *   @b Arguments
 *   @verbatim
		    pAcObj      Audio Class object
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
			CSL_AcInitStructApp    acAppHandle;
			pAcAppClassHandle      pAppClassHandle;
			Uint16                 acAppBuffer[420];
			CSL_Status             status;

			pAppClassHandle = &acAppHandle;

			// Assign values to all the members in acAppHandle struct
			acAppHandle.pAcObj = &acAppBuffer[0];

			status = AC_initDescriptors(pAppClassHandle->pAcObj,
			                            CSL_AC_DEVICE_DESCR, 18);
     @endverbatim
 *  ============================================================================
 */
CSL_Status AC_initDescriptors(void             *pAcObj,
                              Uint16           *descBuf,
                              CSL_AcDescrId    descrId,
                              Uint16           descrLen)
{
	pAcClassHandle       pAcClassHdl;
    CSL_AcCtrlObject     *pCtrlHandle;
	CSL_Status           status;
	Uint16               length;

	status = CSL_ESYS_INVPARAMS;

    if(pAcObj != NULL)
    {
		pAcClassHdl = (pAcClassHandle)(pAcObj);
    	pCtrlHandle  = &pAcClassHdl->ctrlHandle;

    	switch(descrId)
    	{
			/* Initilaize the device descriptor */
			case CSL_AC_DEVICE_DESCR:
				if(descrLen <= CSL_AC_DEVICE_DESCR_MAX_LEN)
				{
					pCtrlHandle->deviceDescr[0] = 0x0000;
					for(length = 0; length < (descrLen+1)/2; length++)
					{
						pCtrlHandle->deviceDescr[length+1] = descBuf[length];
					}
					status = CSL_SOK;
				}
			    break;

			/* Initilaize the device qualifier descriptor */
			case CSL_AC_DEVICE_QUAL_DESCR:
				if(descrLen <= CSL_AC_DEV_QUAL_DESCR_MAX_LEN)
				{
					pCtrlHandle->deviceQualifierDescr[0] = 0x0000;
					for(length = 0; length < (descrLen+1)/2; length++)
					{
						pCtrlHandle->deviceQualifierDescr[length+1] = descBuf[length];
					}
					status = CSL_SOK;
				}
			    break;

			/* Initilaize the configuration descriptor */
			case CSL_AC_CONFIG_DESCR:
				if(descrLen <= CSL_AC_CONFIG_DESCR_MAX_LEN)
				{
					pCtrlHandle->confDescr[0] = 0x0000;
					for(length = 0; length < (descrLen+1)/2; length++)
					{
						pCtrlHandle->confDescr[length+1] = descBuf[length];
					}
					status = CSL_SOK;
				}
			    break;
			/* Initilaize the interface descriptor */
			case CSL_AC_INTERFACE_DESCR:
				if(descrLen <= CSL_AC_INTER_DESCR_MAX_LEN)
				{
					pCtrlHandle->audioClassIntDescr[0] = 0x0000;
					for(length = 0; length < (descrLen+1)/2; length++)
					{
						pCtrlHandle->audioClassIntDescr[length+1] = descBuf[length];
					}
					status = CSL_SOK;
				}
			    break;
			/* Initilaize the string descriptor language Id */
			case CSL_AC_STRING_LANGID_DESC:
				if(descrLen < CSL_AC_STRING_DESCR_LANGID_MAX_LEN)
				{
					pCtrlHandle->stringDescrLangid[0] = 0x0000;
					for(length = 0; length < (descrLen+1)/2; length++)
					{
						pCtrlHandle->stringDescrLangid[length+1] = descBuf[length];
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
 *   @n@b AC_initAcVal
 *
 *   @b Description
 *   @n This function initializes the Audio Class object
 *
 *   @b Arguments
 *   @verbatim
            pAcHandle        Handle to the Audio class Object
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK              - Returned for success
 *   @li                    CSL_ESYS_BADHANDLE   - Invalid Audio class handle
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Initializes Audio Class object
 *
 *   @b Modifies
 *   @n Audio Class object structure
 *
 *   @b Example
 *   @verbatim
            CSL_AcObject    acObj;
            CSL_Status      status;

            status = AC_initAcVal(&acObj);

     @endverbatim
 *  ============================================================================
 */
static CSL_Status AC_initAcVal(CSL_AcObject    *pAcHandle)
{
    Uint16       copyCnt;
    CSL_Status   status;

	status = CSL_SOK;

	if(pAcHandle != NULL)
	{
		pAcHandle->mediaState = 0;
		pAcHandle->activityPresentFlag =0;

		/* Sense Data */
		/* size */
		pAcHandle->senseData[0] = CSL_AC_SENSE_DATA0_DEFVAL;
		/* Dummy for USB_postTransaction */
		pAcHandle->senseData[1] = CSL_AC_SENSE_DATA1_DEFVAL;
		/* Error code = 0x70 (0-1) */
		pAcHandle->senseData[2] = CSL_AC_SENSE_DATA2_DEFVAL;
		/* Sense key (2-3) */
		pAcHandle->senseData[3] = CSL_AC_SENSE_DATA3_DEFVAL;
		/* bytes 4-5 */
		pAcHandle->senseData[4] = CSL_AC_SENSE_DATA4_DEFVAL;
		/* Additional length = 18 (6-7) */
		pAcHandle->senseData[5] = CSL_AC_SENSE_DATA5_DEFVAL;

		pAcHandle->readCapacity[0] = CSL_AC_READ_CAPACITY0_DEFVAL;

		for(copyCnt = 6; copyCnt < 15; copyCnt++)
		{
			pAcHandle->senseData[copyCnt]  = 0x0000;
		}

		/* CSW */
		/* Dummy for USB_postTransaction */
		pAcHandle->csw[0] = CSL_AC_CSW0_DEFVAL;
		pAcHandle->csw[1] = CSL_AC_CSW1_DEFVAL;
		pAcHandle->csw[2] = CSL_AC_CSW2_DEFVAL;
		for (copyCnt = 3; copyCnt < 8; copyCnt++)
		{
			pAcHandle->csw[copyCnt] = 0;
		}
	}
	else
	{
		status = CSL_ESYS_BADHANDLE;
	}

	return(status);
}

/** ============================================================================
 *   @n@b  AC_reqGetDescriptor
 *
 *   @b Description
 *   @n This function handles the request from host to get the descriptor
 *
 *   @b Arguments
 *   @verbatim
            CSL_AC_REQUEST_ARGS    - AC request arguments
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @li        CSL_AC_REQUEST_GET_ACK  - Get acknowledgement for request\
 *   @li        CSL_AC_REQUEST_STALL    - Request stall signal (Error)
 *
 *   <b> Pre Condition </b>
 *   @n  AC_lookupReqHandler should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Sends the descriptor
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
             CSL_AcInitStructApp    acAppHandle;
             CSL_AcObject           *pAcHandle;
             CSL_AcCtrlObject       *pCtrlHandle;
             CSL_UsbEpHandle        hUbOutEp;
             Uint16                 lunNum;
             Uint16                 acAppBuffer[420];
             CSL_Status             status;
             Uint16                 request;

             // Assign values to all the members in acAppHandle struct
             acAppHandle.pAcObj = &acAppBuffer[0];
             .....
             .....
             status = AC_Open(&acAppHandle);
             ....
             ....
             pCtrlHandle->fpRequestHandler = AC_lookupReqHandler(request,
                                                       pCtrlHandle->acReqTable);

             pCtrlHandle->fpRequestHandler(pCtrlHandle->devNum,
                                           &pCtrlHandle->usbSetup,hCtrlEpIn,hCtrlEpOut,pAC);
     @endverbatim
 *  ============================================================================
 */
CSL_AcRequestRet AC_reqGetDescriptor(CSL_UsbDevHandle      devHandle,
                                     CSL_UsbSetupStruct    *usbSetup,
                                     CSL_UsbEpHandle       hInEp,
                                     CSL_UsbEpHandle       hOutEp,
                                     void                  *pAcObj)
{
	Uint16    tempLen;
	Uint16    strLen;
	Uint16    inOutFlag;
	Uint16    count;
    Uint16    temp1;
    Uint16    temp2;
    Uint16    unicodeString[CSL_AC_UNICODE_SIZE];
    Uint16    descrLen;
	pAcClassHandle       pACClassHdl;
	CSL_AcCtrlObject*    pCtrlHandle;

	pACClassHdl = (pAcClassHandle)(pAcObj);
	pCtrlHandle  = &pACClassHdl->ctrlHandle;
	count = 0;

    switch(usbSetup->wValue >> CSL_AC_8BIT_SHIFT)
    {
    	case CSL_USB_DEVICE_DESCRIPTOR_TYPE:

    	    tempLen = pCtrlHandle->deviceDescr[1]&0xFF;
    	    /* select the smaller of two  */
            tempLen =
                (tempLen < usbSetup->wLength) ? tempLen : usbSetup->wLength;
            USB_postTransaction(hInEp, tempLen,
                                (void*)&pCtrlHandle->deviceDescr[0],
                                CSL_USB_IOFLAG_NONE);
            break;

    	case CSL_USB_CONFIGURATION_DESCRIPTOR_TYPE:
         	inOutFlag = (CSL_USB_IOFLAG_LNK | CSL_USB_IOFLAG_CAT);
         	tempLen = pCtrlHandle->confDescr[2];
         	if(tempLen == usbSetup->wLength)
         	{
				inOutFlag |= CSL_USB_IOFLAG_NOSHORT;
			}

         	 /* select the smaller of two */
         	tempLen =
         	    (tempLen < usbSetup->wLength) ? tempLen : usbSetup->wLength;

			USB_postTransaction(hInEp, tempLen, &pCtrlHandle->confDescr[0],
         	                    inOutFlag);
         	break;

    	case CSL_USB_STRING_DESCRIPTOR_TYPE:
         	memcpy(unicodeString,0,sizeof(unicodeString));
			/* LANGID Language Codes */
         	if((usbSetup->wValue & 0xFF) == 0)
         	{
         		tempLen = pCtrlHandle->stringDescrLangid[1] & CSL_AC_8BIT_MASK;
           		/* select the smaller of two */
           		tempLen =
           		   (tempLen < usbSetup->wLength) ? tempLen : usbSetup->wLength;

           		USB_postTransaction(hInEp, tempLen,
           		                    &pCtrlHandle->stringDescrLangid[0],
           		                    CSL_USB_IOFLAG_NONE);
         	}
         	else
         	{
         		/* strlen of the string requested */
         		strLen = strlen(pCtrlHandle->strDescr[usbSetup->wValue &
         		                                      CSL_AC_8BIT_MASK]);
				/* Descreptor length eaqual to two time of string
				   length plus two bytes for sending descriptor length
				   and descriptor type */
				descrLen = 2*(strLen) + 2;

           		/* select the smallest of two */
           		tempLen =
           		    (descrLen < usbSetup->wLength) ? descrLen : usbSetup->wLength;

				/* Convert the ASCII string to UNICODE string */
           		for(count = 0; count < strLen; count++)
           		{
					temp1 = (pCtrlHandle->strDescr[usbSetup->wValue &
					                      CSL_AC_8BIT_MASK][count]);
					temp2 =  0x00;
					unicodeString[count + 2] = (temp2 << CSL_AC_8BIT_SHIFT) | temp1;
           		}

           		unicodeString[1] = ((CSL_USB_STRING_DESCRIPTOR_TYPE <<
           		                    CSL_AC_8BIT_SHIFT) | tempLen);

           		USB_postTransaction(hInEp, tempLen , &unicodeString[0],
                   				    CSL_USB_IOFLAG_NONE);
         	}
        	break;

		case CSL_USB_DEVICE_QUAL_DESCRIPTOR_TYPE:
			tempLen = pCtrlHandle->deviceQualifierDescr[1] & 0xFF;
    	    /* select the smaller of two  */
            tempLen =
                (tempLen < usbSetup->wLength) ? tempLen : usbSetup->wLength;
            USB_postTransaction(hInEp, tempLen, (void*)&pCtrlHandle->deviceQualifierDescr,
                                CSL_USB_IOFLAG_NONE);
			break;

    	default:
    		return(CSL_AC_REQUEST_STALL);
	}

	return(CSL_AC_REQUEST_GET_ACK);
}

/** ============================================================================
 *   @n@b  AC_reqSetCurrent
 *
 *   @b Description
 *   @n This function handles the request from host to set current
 *
 *   @b Arguments
 *   @verbatim
            devNum       - USB device number
            usbSetup     - USb setup structure
            hInEp        - USB ISO In end point handle
            hOutEp       - USB ISO Out end point object
            pAcObj       - USB Audio Class object
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @li        CSL_AC_REQUEST_SEND_ACK - Send acknowledgement for request
 *   @li        CSL_AC_REQUEST_STALL    - Request stall signal (Error)
 *
 *   <b> Pre Condition </b>
 *   @n  AC_lookupReqHandler should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Sends acknowledgement
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
             CSL_AcInitStructApp    acAppHandle;
             CSL_AcObject           *pAcHandle;
             CSL_AcCtrlObject       *pCtrlHandle;
             CSL_UsbEpHandle        hUbOutEp;
             Uint16                 lunNum;
             Uint16                 acAppBuffer[420];
             CSL_Status             status;
             Uint16                 request;

             // Assign values to all the members in acAppHandle struct
             acAppHandle.pAcObj = &acAppBuffer[0];
             .....
             .....
             status = AC_Open(&acAppHandle);
             ....
             ....
             pCtrlHandle->fpRequestHandler = AC_lookupReqHandler(request,
                                                       pCtrlHandle->acReqTable);

             pCtrlHandle->fpRequestHandler(pCtrlHandle->devNum,
                                           &pCtrlHandle->usbSetup,hCtrlEpIn,hCtrlEpOut,pAcObj);
     @endverbatim
 *  ============================================================================
 */
CSL_AcRequestRet AC_reqSetCurrent(CSL_UsbDevHandle      devHandle,
                                  CSL_UsbSetupStruct    *usbSetup,
                                  CSL_UsbEpHandle       hInEp,
                                  CSL_UsbEpHandle       hOutEp,
                                  void                  *pAcObj)
{
	pAcClassHandle       pAcClassHdl;
    CSL_AcCtrlObject     *pCtrlHandle;
	Uint16               tempLen;
	CSL_AcRequestRet     requestRet;

	requestRet  = CSL_AC_REQUEST_SEND_ACK;
    pAcClassHdl = (pAcClassHandle)(pAcObj);
    pCtrlHandle = &pAcClassHdl->ctrlHandle;

	tempLen = usbSetup->wLength;

	switch(usbSetup->wValue >> CSL_AC_8BIT_SHIFT)
	{
		/* Set Mute Control */
		case USB_AC_FEATURE_UNIT_MUTE_CTRL:
			if((usbSetup->wValue & CSL_AC_8BIT_MASK) == 0)
			{
				pCtrlHandle->muteCtrlBuf[0] = 0x0000;
				pCtrlHandle->muteCtrlBuf[1] = 0x0000;
				pCtrlHandle->muteCtrlBuf[2] = 0x0000;
				USB_postTransaction(hOutEp, tempLen,
                                    (void*)&pCtrlHandle->muteCtrlBuf[0],
                                    CSL_USB_IOFLAG_NONE);
			}
			break;
		/* Set Volume Control */
		case USB_AC_FEATURE_UNIT_VOLUME_CTRL:
			if((usbSetup->wValue & CSL_AC_8BIT_MASK) ==
			   USB_AC_FEATURE_UNIT_LEFT_RIGHT_VOLUME)
			{
				USB_postTransaction(hOutEp, tempLen,
                                    (void*)&pCtrlHandle->leftRightVolBuf[0],
                                    CSL_USB_IOFLAG_NONE);
			}
			else if((usbSetup->wValue & CSL_AC_8BIT_MASK) ==
			        USB_AC_FEATURE_UNIT_LEFT_VOLUME)
			{
				USB_postTransaction(hOutEp, tempLen,
                                    (void*)&pCtrlHandle->leftVolBuf[0],
                                    CSL_USB_IOFLAG_NONE);
			}
			else if((usbSetup->wValue & CSL_AC_8BIT_MASK) ==
			        USB_AC_FEATURE_UNIT_RIGHT_VOLUME)
			{
				USB_postTransaction(hOutEp, tempLen,
                                    (void*)&pCtrlHandle->rightVolBuf[0],
                                    CSL_USB_IOFLAG_NONE);
			}
			else
			{
				requestRet = CSL_AC_REQUEST_STALL;
			}
			break;

		default :
			requestRet = CSL_AC_REQUEST_STALL;
			break;
	}

	return(requestRet);
}

/** ============================================================================
 *   @n@b  AC_reqGetCurrent
 *
 *   @b Description
 *   @n This function handles the request from host to get current
 *
 *   @b Arguments
 *   @verbatim
            devNum       - USB device number
            usbSetup     - USb setup structure
            hInEp        - USB ISO In end point handle
            hOutEp       - USB ISO Out end point object
            pAcObj       - USB Audio Class object
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @li        CSL_AC_REQUEST_GET_ACK  - Get acknowledgement for request
 *   @li        CSL_AC_REQUEST_STALL    - Request stall signal (Error)
 *
 *   <b> Pre Condition </b>
 *   @n  AC_lookupReqHandler should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Sends requested current value
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
             CSL_AcInitStructApp    acAppHandle;
             CSL_AcObject           *pAcHandle;
             CSL_AcCtrlObject       *pCtrlHandle;
             CSL_UsbEpHandle        hUbOutEp;
             Uint16                 lunNum;
             Uint16                 acAppBuffer[420];
             CSL_Status             status;
             Uint16                 request;

             // Assign values to all the members in acAppHandle struct
             acAppHandle.pAcObj = &acAppBuffer[0];
             .....
             .....
             status = AC_Open(&acAppHandle);
             ....
             ....
             pCtrlHandle->fpRequestHandler = AC_lookupReqHandler(request,
                                                       pCtrlHandle->acReqTable);

             pCtrlHandle->fpRequestHandler(pCtrlHandle->devNum,
                                           &pCtrlHandle->usbSetup,hCtrlEpIn,hCtrlEpOut,pAcObj);
     @endverbatim
 *  ============================================================================
 */
CSL_AcRequestRet AC_reqGetCurrent(CSL_UsbDevHandle      devHandle,
                                  CSL_UsbSetupStruct    *usbSetup,
                                  CSL_UsbEpHandle       hInEp,
                                  CSL_UsbEpHandle       hOutEp,
                                  void                  *pAcObj)
{

	pAcClassHandle      pAcClassHdl;
    CSL_AcCtrlObject    *pCtrlHandle;
	Uint16              tempLen;
	CSL_AcRequestRet    requestRet;

	requestRet  = CSL_AC_REQUEST_GET_ACK;
    pAcClassHdl = (pAcClassHandle)(pAcObj);
    pCtrlHandle = &pAcClassHdl->ctrlHandle;

	tempLen = usbSetup->wLength;

	switch(usbSetup->wValue >> CSL_AC_8BIT_SHIFT)
	{
		/* Send the audio mute value */
		case USB_AC_FEATURE_UNIT_MUTE_CTRL:
			if((usbSetup->wValue & CSL_AC_8BIT_MASK) == 0)
			{
				USB_postTransaction(hInEp, tempLen,
                                    (void*)&pCtrlHandle->muteCtrlBuf[0],
                                     CSL_USB_IOFLAG_NONE);
			}
			break;
		/* Get volume request */
		case USB_AC_FEATURE_UNIT_VOLUME_CTRL:
			if((usbSetup->wValue & CSL_AC_8BIT_MASK) ==
			   USB_AC_FEATURE_UNIT_LEFT_RIGHT_VOLUME)
			{
				USB_postTransaction(hInEp, tempLen,
                                   (void*)&pCtrlHandle->leftRightVolBuf[0],
                                          CSL_USB_IOFLAG_NONE);
			}
			else if((usbSetup->wValue & CSL_AC_8BIT_MASK) ==
			        USB_AC_FEATURE_UNIT_LEFT_VOLUME)
			{
				USB_postTransaction(hInEp, tempLen,
                                    (void*)&pCtrlHandle->leftVolBuf[0],
                                    CSL_USB_IOFLAG_NONE);
			}
			else if((usbSetup->wValue & CSL_AC_8BIT_MASK) ==
			        USB_AC_FEATURE_UNIT_RIGHT_VOLUME)
			{
				USB_postTransaction(hInEp, tempLen,
                                    (void*)&pCtrlHandle->rightVolBuf[0],
                                     CSL_USB_IOFLAG_NONE);
			}
			else
			{
				requestRet = CSL_AC_REQUEST_STALL;
			}
			break;

		default :
			requestRet = CSL_AC_REQUEST_STALL;
			break;
	}

	return(requestRet);
}

/** ============================================================================
 *   @n@b  AC_reqGetMinimum
 *
 *   @b Description
 *   @n This function handles the get minimum request from host
 *
 *   @b Arguments
 *   @verbatim
            devNum       - USB device number
            usbSetup     - USb setup structure
            hInEp        - USB ISO In end point handle
            hOutEp       - USB ISO Out end point object
            pAcObj       - USB Audio Class object
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @li        CSL_AC_REQUEST_GET_ACK  - Get acknowledgement for request
 *   @li        CSL_AC_REQUEST_STALL    - Request stall signal (Error)
 *
 *   <b> Pre Condition </b>
 *   @n  AC_lookupReqHandler should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Sends requested minimum value
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
             CSL_AcInitStructApp    acAppHandle;
             CSL_AcObject           *pAcHandle;
             CSL_AcCtrlObject       *pCtrlHandle;
             CSL_UsbEpHandle        hUbOutEp;
             Uint16                 lunNum;
             Uint16                 acAppBuffer[420];
             CSL_Status             status;
             Uint16                 request;

             // Assign values to all the members in acAppHandle struct
             acAppHandle.pAcObj = &acAppBuffer[0];
             .....
             .....
             status = AC_Open(&acAppHandle);
             ....
             ....
             pCtrlHandle->fpRequestHandler = AC_lookupReqHandler(request,
                                                       pCtrlHandle->acReqTable);

             pCtrlHandle->fpRequestHandler(pCtrlHandle->devNum,
                                           &pCtrlHandle->usbSetup,hCtrlEpIn,hCtrlEpOut,pAcObj);
     @endverbatim
 *  ============================================================================
 */
CSL_AcRequestRet AC_reqGetMinimum(CSL_UsbDevHandle      devHandle,
                                  CSL_UsbSetupStruct    *usbSetup,
                                  CSL_UsbEpHandle       hInEp,
                                  CSL_UsbEpHandle       hOutEp,
                                  void                  *pAcObj)
{
	pAcClassHandle      pAcClassHdl;
    CSL_AcCtrlObject    *pCtrlHandle;
	Uint16              tempLen;
	CSL_Status          status;

    pAcClassHdl = (pAcClassHandle)(pAcObj);
    pCtrlHandle = &pAcClassHdl->ctrlHandle;
	status      = CSL_SOK;

    tempLen = usbSetup->wLength;

	status = USB_postTransaction(hInEp, tempLen,
								 (void*)(&pCtrlHandle->getMinBuffer[0]),
								  CSL_USB_IOFLAG_NONE);
	if(status != CSL_SOK)
	{
		return(CSL_AC_REQUEST_STALL);
	}

	return(CSL_AC_REQUEST_GET_ACK);
}

/** ============================================================================
 *   @n@b  AC_reqGetMaximum
 *
 *   @b Description
 *   @n This function handles the get maximum request from host
 *
 *   @b Arguments
 *   @verbatim
            devNum       - USB device number
            usbSetup     - USb setup structure
            hInEp        - USB ISO In end point handle
            hOutEp       - USB ISO Out end point object
            pAcObj       - USB Audio Class object
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @li        CSL_AC_REQUEST_GET_ACK  - Get acknowledgement for request
 *   @li        CSL_AC_REQUEST_STALL    - Request stall signal (Error)
 *
 *   <b> Pre Condition </b>
 *   @n  AC_lookupReqHandler should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Sends requested maximum value
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
             CSL_AcInitStructApp    acAppHandle;
             CSL_AcObject           *pAcHandle;
             CSL_AcCtrlObject       *pCtrlHandle;
             CSL_UsbEpHandle        hUbOutEp;
             Uint16                 lunNum;
             Uint16                 acAppBuffer[420];
             CSL_Status             status;
             Uint16                 request;

             // Assign values to all the members in acAppHandle struct
             acAppHandle.pAcObj = &acAppBuffer[0];
             .....
             .....
             status = AC_Open(&acAppHandle);
             ....
             ....
             pCtrlHandle->fpRequestHandler = AC_lookupReqHandler(request,
                                                       pCtrlHandle->acReqTable);

             pCtrlHandle->fpRequestHandler(pCtrlHandle->devNum,
                                           &pCtrlHandle->usbSetup,hCtrlEpIn,hCtrlEpOut,pAcObj);
     @endverbatim
 *  ============================================================================
 */
CSL_AcRequestRet AC_reqGetMaximum(CSL_UsbDevHandle      devHandle,
                                  CSL_UsbSetupStruct    *usbSetup,
                                  CSL_UsbEpHandle       hInEp,
                                  CSL_UsbEpHandle       hOutEp,
                                  void                  *pAcObj)
{
	pAcClassHandle      pAcClassHdl;
    CSL_AcCtrlObject    *pCtrlHandle;
	Uint16              tempLen;
	CSL_Status          status;

    pAcClassHdl = (pAcClassHandle)(pAcObj);
    pCtrlHandle = &pAcClassHdl->ctrlHandle;
	status      = CSL_SOK;

    tempLen = usbSetup->wLength;

	status = USB_postTransaction(hInEp, tempLen,
								 (void*)(&pCtrlHandle->getMaxBuffer[0]),
								  CSL_USB_IOFLAG_NONE);
	if(status != CSL_SOK)
	{
		return(CSL_AC_REQUEST_STALL);
	}

	return(CSL_AC_REQUEST_GET_ACK);
}

/** ============================================================================
 *   @n@b  AC_reqGetResolution
 *
 *   @b Description
 *   @n This function handles the get resolution request from host
 *
 *   @b Arguments
 *   @verbatim
            devNum       - USB device number
            usbSetup     - USb setup structure
            hInEp        - USB ISO In end point handle
            hOutEp       - USB ISO Out end point object
            pAcObj       - USB Audio Class object
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @li        CSL_AC_REQUEST_GET_ACK  - Get acknowledgement for request
 *   @li        CSL_AC_REQUEST_STALL    - Request stall signal (Error)
 *
 *   <b> Pre Condition </b>
 *   @n  AC_lookupReqHandler should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Sends requested resolution value
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
             CSL_AcInitStructApp    acAppHandle;
             CSL_AcObject           *pAcHandle;
             CSL_AcCtrlObject       *pCtrlHandle;
             CSL_UsbEpHandle        hUbOutEp;
             Uint16                 lunNum;
             Uint16                 acAppBuffer[420];
             CSL_Status             status;
             Uint16                 request;

             // Assign values to all the members in acAppHandle struct
             acAppHandle.pAcObj = &acAppBuffer[0];
             .....
             .....
             status = AC_Open(&acAppHandle);
             ....
             ....
             pCtrlHandle->fpRequestHandler = AC_lookupReqHandler(request,
                                                       pCtrlHandle->acReqTable);

             pCtrlHandle->fpRequestHandler(pCtrlHandle->devNum,
                                           &pCtrlHandle->usbSetup,hCtrlEpIn,hCtrlEpOut,pAcObj);
     @endverbatim
 *  ============================================================================
 */
CSL_AcRequestRet AC_reqGetResolution(CSL_UsbDevHandle      devHandle,
                                     CSL_UsbSetupStruct    *usbSetup,
                                     CSL_UsbEpHandle       hInEp,
                                     CSL_UsbEpHandle       hOutEp,
                                     void                  *pAcObj)
{
	pAcClassHandle      pAcClassHdl;
    CSL_AcCtrlObject    *pCtrlHandle;
	Uint16              tempLen;
	CSL_Status          status;

    pAcClassHdl = (pAcClassHandle)(pAcObj);
    pCtrlHandle = &pAcClassHdl->ctrlHandle;
	status      = CSL_SOK;

    tempLen = usbSetup->wLength;

	status = USB_postTransaction(hInEp, tempLen,
								 (void*)(&pCtrlHandle->getResBuffer[0]),
								  CSL_USB_IOFLAG_NONE);
	if(status != CSL_SOK)
	{
		return(CSL_AC_REQUEST_STALL);
	}

	return(CSL_AC_REQUEST_GET_ACK);
}

/** ============================================================================
 *   @n@b  AC_reqSetInterface
 *
 *   @b Description
 *   @n This function handles the request from host to set interafce
 *   unit number
 *
 *   @b Arguments
 *   @verbatim
             devNum       - USB device number
             usbSetup     - USb setup structure
             hInEp        - USB ISO In end point handle
             hOutEp       - USB ISO Out end point object
             pAcObj       - USB Audio Class object
     @endverbatim
 *
 *   <b> Return Value </b>
 *   @li        CSL_AC_REQUEST_SEND_ACK - Send acknowledgement for request
 *   @li        CSL_AC_REQUEST_STALL    - Request stall signal (Error)
 *
 *   <b> Pre Condition </b>
 *   @n  AC_lookupReqHandler should be called successfully
 *
 *   <b> Post Condition </b>
 *   @n  Sends acknowledgement
 *
 *   @b Modifies
 *   @n None
 *
 *   @b Example
 *   @verbatim
             CSL_AcInitStructApp    acAppHandle;
             CSL_AcObject           *pAcHandle;
             CSL_AcCtrlObject       *pCtrlHandle;
             CSL_UsbEpHandle        hUbOutEp;
             Uint16                 lunNum;
             Uint16                 acAppBuffer[420];
             CSL_Status             status;
             Uint16                 request;

             // Assign values to all the members in acAppHandle struct
             acAppHandle.pAcObj = &acAppBuffer[0];
             .....
             .....
             status = AC_Open(&acAppHandle);
             ....
             ....
             pCtrlHandle->fpRequestHandler = AC_lookupReqHandler(request,
                                                       pCtrlHandle->acReqTable);

             pCtrlHandle->fpRequestHandler(pCtrlHandle->devNum,
                                           &pCtrlHandle->usbSetup,hCtrlEpIn,hCtrlEpOut,pAcObj);
     @endverbatim
 *  ============================================================================
 */
CSL_AcRequestRet AC_reqSetInterface(CSL_UsbDevHandle      devHandle,
                                    CSL_UsbSetupStruct    *usbSetup,
                                    CSL_UsbEpHandle       hInEp,
                                    CSL_UsbEpHandle       hOutEp,
                                    void                  *pAcObj)
{
	CSL_AcRequestRet    retStat;
	CSL_AcMediaStatus   mediaStatus;
	pAcClassHandle      pAcClassHdl;
	CSL_AcObject        *pAcHandle;
	Uint16              dummy;

    pAcClassHdl = (pAcClassHandle)(pAcObj);
	pAcHandle   = &pAcClassHdl->acHandle;
	retStat     = CSL_AC_REQUEST_SEND_ACK;
	dummy       = 0;

	if(usbSetup->wIndex == 0)
	{
		if (usbSetup->wValue == 0)
		{
			retStat = CSL_AC_REQUEST_SEND_ACK;
		}
	}
	else if(usbSetup->wIndex == 1)
	{
		if (usbSetup->wValue == 0)
		{
			if(pAcHandle->playBackActive == TRUE)
			{
				mediaStatus = pAcHandle->stopAudio(dummy, (void*)&dummy);
				mediaStatus = pAcHandle->mediaInit(dummy);
				if(mediaStatus == CSL_AC_MEDIACCESS_SUCCESS)
				{
					pAcHandle->playBackActive = FALSE;
					//pAcHandle->mediaInitDone  = FALSE;
				}
			}
			retStat = CSL_AC_REQUEST_SEND_ACK;
		}
		else if (usbSetup->wValue == 1)
		{
			//USB_configEpForIsoRx();
			if(pAcHandle->mediaInitDone == FALSE)
			{
				mediaStatus = pAcHandle->mediaInit(dummy);
				if(mediaStatus == CSL_AC_MEDIACCESS_SUCCESS)
				{
					pAcHandle->mediaInitDone = TRUE;
				}
			}
			retStat = CSL_AC_REQUEST_SEND_ACK;
		}
		else
		{
			retStat = CSL_AC_REQUEST_STALL;
		}
	}
	else
	{
		/* Interface not supported, STALL the endpoint */
		retStat = CSL_AC_REQUEST_STALL;
	}

	return(retStat);
}

