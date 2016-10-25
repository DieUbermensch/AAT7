/******************************************************************************\
*           Copyright (C) 2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* MODULE NAME... MCBSP
* FILENAME...... csl_mcbspdat.h
* DATE CREATED.. Thu 03/30/2000 
* PROJECT....... CSL - Chip Support Library
* COMPONENT..... CSL service layer
* PREREQUISITS..
*------------------------------------------------------------------------------
* HISTORY:
*   CREATED:       03/30/2000
*   LAST MODIFIED: 04/16/2001 updated FILENAME and other header comments
*   MODIFIED:      10 Apr 2003 added reference for CSL_McbspData for .csldata fix  
*   MODIFIED:      08/03/2004  Added 5501 support
*------------------------------------------------------------------------------
* DESCRIPTION:  (service layer interface file for the MCBSP module)
*       Reserved Area for MCBSP Data 
*
*
\******************************************************************************/
#ifndef _MCBSP_DATA_H_
#define _MCBSP_DATA_H_

#include <csl_std.h>

#if (!(CHIP_5501))
#define _MCBSP_PORT_CNT   3
#else
#define _MCBSP_PORT_CNT   2
#endif

#if (((CHIP_5502) || (CHIP_5501)) == 0)
#define CSL_MCBSPDATAINIT\
{ /*MCBSP Port #0 Handle Initialization Data*/\
  0,                              /*MCBSP Port#*/\
  ((0)*0x0400u)+(0x2800u+ 0x1),   /*MCBSP0_Drr1Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x0),   /*MCBSP0_Drr2Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x3),   /*MCBSP0_Dxr1Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x2),   /*MCBSP0_Dxr2Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x5),   /*MCBSP0_Spcr1Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x4),   /*MCBSP0_Spcr2Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x7),   /*MCBSP0_Rcr1Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x6),   /*MCBSP0_Rcr2Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x9),   /*MCBSP0_Xcr1Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x8),   /*MCBSP0_Xcr2Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0xB),   /*MCBSP0_Srgr1Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0xA),   /*MCBSP0_Srgr2Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0xD),   /*MCBSP0_Mcr1Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0xC),   /*MCBSP0_Mcr2Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0xE),   /*MCBSP0_RceraAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0xF),   /*MCBSP0_RcerbAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x13),  /*MCBSP0_RcercAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x14),  /*MCBSP0_RcerdAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x17),  /*MCBSP0_RcereAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x18),  /*MCBSP0_RcerfAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x1B),  /*MCBSP0_RcergAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x1C),  /*MCBSP0_RcerhAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x10),  /*MCBSP0_XceraAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x11),  /*MCBSP0_XcerbAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x15),  /*MCBSP0_XcercAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x16),  /*MCBSP0_XcerdAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x19),  /*MCBSP0_XcereAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x1A),  /*MCBSP0_XcerfAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x1D),  /*MCBSP0_XcergAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x1E),  /*MCBSP0_XcerhAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x12),  /*MCBSP0_PcrAddr*/\
  17,                             /*MCBSP0_XmtEvent*/\
  5 ,                             /*MCBSP0_RcvEvent*/\
 /* MCBSP Port #1 Handle Initialization Data*/\
  1,                              /*MCBSP Port#*/\
  ((1)*0x0400u)+(0x2800u+ 0x1),   /*MCBSP1_Drr1Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x0),   /*MCBSP1_Drr2Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x3),   /*MCBSP1_Dxr1Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x2),   /*MCBSP1_Dxr2Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x5),   /*MCBSP1_Spcr1Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x4),   /*MCBSP1_Spcr2Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x7),   /*MCBSP1_Rcr1Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x6),   /*MCBSP1_Rcr2Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x9),   /*MCBSP1_Xcr1Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x8),   /*MCBSP1_Xcr2Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0xB),   /*MCBSP1_Srgr1Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0xA),   /*MCBSP1_Srgr2Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0xD),   /*MCBSP1_Mcr1Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0xC),   /*MCBSP1_Mcr2Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0xE),   /*MCBSP1_RceraAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0xF),   /*MCSBP0_RcerbAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x13),  /*MCBSP1_RcercAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x14),  /*MCBSP1_RcerdAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x17),  /*MCBSP1_RcereAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x18),  /*MCBSP1_RcerfAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x1B),  /*MCBSP1_RcergAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x1C),  /*MCBSP1_RcerhAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x10),  /*MCBSP1_XceraAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x11),  /*MCBSP1_XcerbAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x15),  /*MCBSP1_XcercAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x16),  /*MCBSP1_XcerdAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x19),  /*MCBSP1_XcereAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x1A),  /*MCBSP1_XcerfAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x1D),  /*MCBSP1_XcergAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x1E),  /*MCBSP1_XcerhAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x12),  /*MCBSP1_PcrAddr*/\
  7,                              /*MCBSP1_XmtEvent*/\
  6,                              /*MCBSP1_RcvEvent*/\
 /* MCBSP Port #2 Handle Initialization Data*/\
  2,                              /*MCBSP Port#*/\
  ((2)*0x0400u)+(0x2800u+ 0x1),   /*MCBSP2_Drr1Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0x0),   /*MCBSP2_Drr2Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0x3),   /*MCBSP2_Dxr1Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0x2),   /*MCBSP2_Dxr2Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0x5),   /*MCBSP2_Spcr1Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0x4),   /*MCBSP2_Spcr2Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0x7),   /*MCBSP2_Rcr1Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0x6),   /*MCBSP2_Rcr2Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0x9),   /*MCBSP2_Xcr1Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0x8),   /*MCBSP2_Xcr2Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0xB),   /*MCBSP2_Srgr1Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0xA),   /*MCBSP2_Srgr2Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0xD),   /*MCBSP2_Mcr1Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0xC),   /*MCBSP2_Mcr2Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0xE),   /*MCBSP2_RceraAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0xF),   /*MCBSP2_RcerbAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x13),  /*MCBSP2_RcercAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x14),  /*MCBSP2_RcerdAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x17),  /*MCBSP2_RcereAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x18),  /*MCBSP2_RcerfAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x1B),  /*MCBSP2_RcergAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x1C),  /*MCBSP2_RcerhAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x10),  /*MCBSP2_XceraAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x11),  /*MCBSP2_XcerbAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x15),  /*MCBSP2_XcercAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x16),  /*MCBSP2_XcerdAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x19),  /*MCBSP2_XcereAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x1A),  /*MCBSP2_XcerfAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x1D),  /*MCBSP2_XcergAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x1E),  /*MCBSP2_XcerhAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x12),  /*MCBSP2_PcrAddr*/\
  13,                             /*MCBSP2_XmtEvent*/\
  12                              /*MCBSP2_RcvEvent*/\
}
#elif (CHIP_5502)
 #define CSL_MCBSPDATAINIT\
 { /*MCBSP Port #0 Handle Initialization Data*/\
  0,                              /*MCBSP Port#*/\
  ((0)*0x0400u)+(0x2800u+ 0x0),   /*MCBSP0_Drr1Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x1),   /*MCBSP0_Drr2Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x2),   /*MCBSP0_Dxr1Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x3),   /*MCBSP0_Dxr2Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x4),   /*MCBSP0_Spcr1Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x5),   /*MCBSP0_Spcr2Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x6),   /*MCBSP0_Rcr1Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x7),   /*MCBSP0_Rcr2Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x8),   /*MCBSP0_Xcr1Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x9),   /*MCBSP0_Xcr2Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0xA),   /*MCBSP0_Srgr1Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0xB),   /*MCBSP0_Srgr2Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0xC),   /*MCBSP0_Mcr1Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0xD),   /*MCBSP0_Mcr2Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0xE),   /*MCBSP0_RceraAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0xF),   /*MCBSP0_RcerbAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x14),  /*MCBSP0_RcercAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x15),  /*MCBSP0_RcerdAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x18),  /*MCBSP0_RcereAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x19),  /*MCBSP0_RcerfAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x1C),  /*MCBSP0_RcergAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x1D),  /*MCBSP0_RcerhAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x10),  /*MCBSP0_XceraAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x11),  /*MCBSP0_XcerbAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x16),  /*MCBSP0_XcercAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x17),  /*MCBSP0_XcerdAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x1A),  /*MCBSP0_XcereAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x1B),  /*MCBSP0_XcerfAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x1E),  /*MCBSP0_XcergAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x1F),  /*MCBSP0_XcerhAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x12),  /*MCBSP0_PcrAddr*/\
  17,                             /*MCBSP0_XmtEvent*/\
  5 ,                             /*MCBSP0_RcvEvent*/\
 /* MCBSP Port #1 Handle Initialization Data*/\
  1,                              /*MCBSP Port#*/\
  ((1)*0x0400u)+(0x2800u+ 0x0),   /*MCBSP0_Drr1Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x1),   /*MCBSP0_Drr2Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x2),   /*MCBSP0_Dxr1Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x3),   /*MCBSP0_Dxr2Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x4),   /*MCBSP0_Spcr1Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x5),   /*MCBSP0_Spcr2Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x6),   /*MCBSP0_Rcr1Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x7),   /*MCBSP0_Rcr2Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x8),   /*MCBSP0_Xcr1Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x9),   /*MCBSP0_Xcr2Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0xA),   /*MCBSP0_Srgr1Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0xB),   /*MCBSP0_Srgr2Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0xC),   /*MCBSP0_Mcr1Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0xD),   /*MCBSP0_Mcr2Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0xE),   /*MCBSP0_RceraAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0xF),   /*MCBSP0_RcerbAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x14),  /*MCBSP0_RcercAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x15),  /*MCBSP0_RcerdAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x18),  /*MCBSP0_RcereAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x19),  /*MCBSP0_RcerfAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x1C),  /*MCBSP0_RcergAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x1D),  /*MCBSP0_RcerhAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x10),  /*MCBSP0_XceraAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x11),  /*MCBSP0_XcerbAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x16),  /*MCBSP0_XcercAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x17),  /*MCBSP0_XcerdAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x1A),  /*MCBSP0_XcereAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x1B),  /*MCBSP0_XcerfAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x1E),  /*MCBSP0_XcergAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x1F),  /*MCBSP0_XcerhAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x12),  /*MCBSP0_PcrAddr*/\
  7,                              /*MCBSP1_XmtEvent*/\
  6,                              /*MCBSP1_RcvEvent*/\
 /* MCBSP Port #2 Handle Initialization Data*/\
  2,                              /*MCBSP Port#*/\
  ((2)*0x0400u)+(0x2800u+ 0x0),   /*MCBSP0_Drr1Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0x1),   /*MCBSP0_Drr2Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0x2),   /*MCBSP0_Dxr1Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0x3),   /*MCBSP0_Dxr2Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0x4),   /*MCBSP0_Spcr1Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0x5),   /*MCBSP0_Spcr2Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0x6),   /*MCBSP0_Rcr1Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0x7),   /*MCBSP0_Rcr2Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0x8),   /*MCBSP0_Xcr1Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0x9),   /*MCBSP0_Xcr2Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0xA),   /*MCBSP0_Srgr1Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0xB),   /*MCBSP0_Srgr2Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0xC),   /*MCBSP0_Mcr1Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0xD),   /*MCBSP0_Mcr2Addr*/\
  ((2)*0x0400u)+(0x2800u+ 0xE),   /*MCBSP0_RceraAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0xF),   /*MCBSP0_RcerbAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x14),  /*MCBSP0_RcercAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x15),  /*MCBSP0_RcerdAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x18),  /*MCBSP0_RcereAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x19),  /*MCBSP0_RcerfAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x1C),  /*MCBSP0_RcergAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x1D),  /*MCBSP0_RcerhAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x10),  /*MCBSP0_XceraAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x11),  /*MCBSP0_XcerbAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x16),  /*MCBSP0_XcercAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x17),  /*MCBSP0_XcerdAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x1A),  /*MCBSP0_XcereAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x1B),  /*MCBSP0_XcerfAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x1E),  /*MCBSP0_XcergAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x1F),  /*MCBSP0_XcerhAddr*/\
  ((2)*0x0400u)+(0x2800u+ 0x12),  /*MCBSP0_PcrAddr*/\
  13,                             /*MCBSP2_XmtEvent*/\
  12                              /*MCBSP2_RcvEvent*/\
 }
 #else  /*(CHIP_5501)*/
 #define CSL_MCBSPDATAINIT\
 { /*MCBSP Port #0 Handle Initialization Data*/\
  0,                              /*MCBSP Port#*/\
  ((0)*0x0400u)+(0x2800u+ 0x0),   /*MCBSP0_Drr1Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x1),   /*MCBSP0_Drr2Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x2),   /*MCBSP0_Dxr1Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x3),   /*MCBSP0_Dxr2Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x4),   /*MCBSP0_Spcr1Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x5),   /*MCBSP0_Spcr2Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x6),   /*MCBSP0_Rcr1Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x7),   /*MCBSP0_Rcr2Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x8),   /*MCBSP0_Xcr1Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0x9),   /*MCBSP0_Xcr2Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0xA),   /*MCBSP0_Srgr1Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0xB),   /*MCBSP0_Srgr2Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0xC),   /*MCBSP0_Mcr1Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0xD),   /*MCBSP0_Mcr2Addr*/\
  ((0)*0x0400u)+(0x2800u+ 0xE),   /*MCBSP0_RceraAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0xF),   /*MCBSP0_RcerbAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x14),  /*MCBSP0_RcercAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x15),  /*MCBSP0_RcerdAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x18),  /*MCBSP0_RcereAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x19),  /*MCBSP0_RcerfAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x1C),  /*MCBSP0_RcergAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x1D),  /*MCBSP0_RcerhAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x10),  /*MCBSP0_XceraAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x11),  /*MCBSP0_XcerbAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x16),  /*MCBSP0_XcercAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x17),  /*MCBSP0_XcerdAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x1A),  /*MCBSP0_XcereAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x1B),  /*MCBSP0_XcerfAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x1E),  /*MCBSP0_XcergAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x1F),  /*MCBSP0_XcerhAddr*/\
  ((0)*0x0400u)+(0x2800u+ 0x12),  /*MCBSP0_PcrAddr*/\
  17,                             /*MCBSP0_XmtEvent*/\
  5 ,                             /*MCBSP0_RcvEvent*/\
 /* MCBSP Port #1 Handle Initialization Data*/\
  1,                              /*MCBSP Port#*/\
  ((1)*0x0400u)+(0x2800u+ 0x0),   /*MCBSP0_Drr1Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x1),   /*MCBSP0_Drr2Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x2),   /*MCBSP0_Dxr1Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x3),   /*MCBSP0_Dxr2Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x4),   /*MCBSP0_Spcr1Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x5),   /*MCBSP0_Spcr2Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x6),   /*MCBSP0_Rcr1Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x7),   /*MCBSP0_Rcr2Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x8),   /*MCBSP0_Xcr1Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0x9),   /*MCBSP0_Xcr2Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0xA),   /*MCBSP0_Srgr1Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0xB),   /*MCBSP0_Srgr2Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0xC),   /*MCBSP0_Mcr1Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0xD),   /*MCBSP0_Mcr2Addr*/\
  ((1)*0x0400u)+(0x2800u+ 0xE),   /*MCBSP0_RceraAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0xF),   /*MCBSP0_RcerbAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x14),  /*MCBSP0_RcercAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x15),  /*MCBSP0_RcerdAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x18),  /*MCBSP0_RcereAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x19),  /*MCBSP0_RcerfAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x1C),  /*MCBSP0_RcergAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x1D),  /*MCBSP0_RcerhAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x10),  /*MCBSP0_XceraAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x11),  /*MCBSP0_XcerbAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x16),  /*MCBSP0_XcercAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x17),  /*MCBSP0_XcerdAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x1A),  /*MCBSP0_XcereAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x1B),  /*MCBSP0_XcerfAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x1E),  /*MCBSP0_XcergAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x1F),  /*MCBSP0_XcerhAddr*/\
  ((1)*0x0400u)+(0x2800u+ 0x12),  /*MCBSP0_PcrAddr*/\
  7,                              /*MCBSP1_XmtEvent*/\
  6,                              /*MCBSP1_RcvEvent*/\
 }
#endif  /* End of if(CHIP_5502) else if (CHIP_5501) */

typedef struct {
  Uint16 Port;
  Uint16 Drr1Addr;
  Uint16 Drr2Addr;
  Uint16 Dxr1Addr;
  Uint16 Dxr2Addr;
  Uint16 Spcr1Addr;
  Uint16 Spcr2Addr;
  Uint16 Rcr1Addr;
  Uint16 Rcr2Addr;
  Uint16 Xcr1Addr;
  Uint16 Xcr2Addr;
  Uint16 Srgr1Addr;
  Uint16 Srgr2Addr;
  Uint16 Mcr1Addr;
  Uint16 Mcr2Addr;
  Uint16 RceraAddr;
  Uint16 RcerbAddr;
  Uint16 RcercAddr;
  Uint16 RcerdAddr;
  Uint16 RcereAddr;
  Uint16 RcerfAddr;
  Uint16 RcergAddr;
  Uint16 RcerhAddr;
  Uint16 XceraAddr;
  Uint16 XcerbAddr;
  Uint16 XcercAddr;
  Uint16 XcerdAddr;
  Uint16 XcereAddr;
  Uint16 XcerfAddr;
  Uint16 XcergAddr;
  Uint16 XcerhAddr;
  Uint16 PcrAddr;
  Uint16 XmtEvent;
  Uint16 RcvEvent;
} MCBSP_PrivateObj;

typedef struct {
  MCBSP_PrivateObj mcbspPort[_MCBSP_PORT_CNT];
} CSL_McbspDataObj;

extern CSL_McbspDataObj  CSL_McbspData;

#define CSL_MCBSP_DATA   CSL_McbspData

#endif
