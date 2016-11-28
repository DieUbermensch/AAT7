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


/** @file csl_types.h
 *
 *  @brief CSL standard types definition file
 *
 *  Path: \(CSLPATH)\inc
 */

/* ============================================================================
 * Revision History
 * ================
 * 11-Aug-2008 Created
 * 13-Aug-2010 CSL v2.10 release
 * 06-Jul-2011 CSL v2.50 release
 * 13-Sep-2012 CSL v3.00 release
 * 20-Dec-2012 CSL v3.01 release
 * ============================================================================
 */

#ifndef _CSL_TYPES_H_
#define _CSL_TYPES_H_

#include <tistdtypes.h>

#ifndef TRUE

#define TRUE		((Bool) 1)
#define FALSE		((Bool) 0)

#endif

typedef Int16     CSL_Uid;
typedef Int16     CSL_ModuleId;
typedef Uint32    CSL_Xio;

typedef Uint8     CSL_BitMask8;
typedef Uint16    CSL_BitMask16;
typedef Uint32    CSL_BitMask32;

typedef volatile Uint8     CSL_Reg8;
typedef volatile Uint16    CSL_Reg16;
typedef volatile Uint32    CSL_Reg32;

typedef Int16    CSL_Status;
typedef Int16    CSL_InstNum;
typedef Int16    CSL_ChaNum;

typedef unsigned long long int     CSL_Uint64;
typedef volatile unsigned int      CSL_VUint32;
typedef volatile unsigned short    CSL_VUint16;
typedef volatile unsigned char     CSL_VUint8;

typedef Uint8      BYTE;
typedef Uint8*     PBYTE;
typedef Uint16     WORD;
typedef Uint16*    PWORD;
typedef Uint32     DWORD;
typedef Uint32*    PDWORD;
typedef void*      PVOID;
typedef void       VOID;
typedef Bool*      PBool;

typedef enum {
  CSL_EXCLUSIVE = 0,
  CSL_SHARED    = 1
} CSL_OpenMode;

typedef enum {
  CSL_FAIL      = 0,
  CSL_PASS      = 1
} CSL_Test;

#ifndef NULL
#define NULL            ((void*)0)
#endif

#endif /* _CSL_TYPES_H_ */

