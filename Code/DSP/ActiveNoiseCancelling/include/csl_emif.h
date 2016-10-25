/******************************************************************************\
*           Copyright (C) 1999-2000 Texas Instruments Incorporated.
*                           All Rights Reserved
*------------------------------------------------------------------------------
* FILENAME...... csl_emif.h
* DATE CREATED.. 06/11/1999 
*------------------------------------------------------------------------------
* HISTORY:
*      MODIFIED:  07/14/2000
*      MODIFIED:  05/11/2001 updated for EMIF_getConfig()
*      MODIFIED:  05/16/2001 renamed EMIF_CONFIG -> EMIF_Config 
*      MODIFIED:  01/27/2002 fixed problem with EMIF_EMIF_EGCR_MEMFREQ_1/2X
*                             _OF(x) type symbolic constants
*      MODIFIED:  02/12/2002 added support for 5502 EMIF
*      MODIFIED: 10 April 2003 added #include of csl_emifdat.h
\******************************************************************************/
#ifndef _EMIF_H_
#define _EMIF_H_

  #include <_csl.h>
  #include <csl_emifdat.h>

  #if (_EMIFB_SUPPORT)
     #include <csl_emifB.h>
  #elif (_EMIFA_SUPPORT)
     #include <csl_emifA.h>
  #endif
#endif /* _EMIF_H_ */
/******************************************************************************\
* End of emif.h
\******************************************************************************/
