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


/* Standard Types File: [last revised: 2004-01-14] */

#ifndef _TISTDTYPES_H_
#define _TISTDTYPES_H_

/*
    The purpose of this header file is to consolidate all the primitive "C"
    data types into one file. This file is expected to be included in the
    basic types file exported by other software components, for example CSL.
 */

#ifndef _TI_STD_TYPES
#define _TI_STD_TYPES

#ifndef TRUE

typedef int		Bool;
#define TRUE		((Bool) 1)
#define FALSE		((Bool) 0)

#endif

typedef int             Int;
typedef unsigned int    Uns;    /* deprecated type */
typedef char            Char;
typedef char *          String;
typedef void *          Ptr;

typedef unsigned long	Uint32;
typedef unsigned short	Uint16;
typedef unsigned char	Uint8;

 /* Signed integer definitions (32bit, 16bit, 8bit) follow... */
typedef long		Int32;
typedef short		Int16;
typedef char		Int8;

#endif /* _TI_STD_TYPES */


#endif /* _TISTDTYPES_H_ */

