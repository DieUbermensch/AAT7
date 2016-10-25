/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... ICACHE
* FILENAME...... csl_icachdat.h
* DATE CREATED.. Thu 03/30/2000 
* PROJECT....... MCRTE - multichannel runtime environment
* COMPONENT..... CSL service layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   
*    	CREATED:  03/30/2000
*     MODIFIED: 04/12/2001 Changed FILENAME comment to match filename
*     MODIFIED: 10 April 2003 added reference to CSL_IcacheData for .csldata 
*                             size fix
*
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the ICACHE module)
*       Reserved Area for ICACHE Data 
*
*
\******************************************************************************/
#ifndef _ICACHE_DATA_H_
#define _ICACHE_DATA_H_
 #define CSL_ICACHEDATAINIT\
  { 0x0000u }

  

  typedef struct {
    Uint16 reserved;
  } CSL_IcacheDataObj;

extern CSL_IcacheDataObj CSL_IcacheData;

#define CSL_ICACHE_DATA  CSL_IcacheData

#endif
