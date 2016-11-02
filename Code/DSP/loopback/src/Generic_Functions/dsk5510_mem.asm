;
;  Copyright 2002 by Spectrum Digital Incorporated.
;  All rights reserved. Property of Spectrum Digital Incorporated.
;

;
;  Read a 16-bit value from a CPLD register.  Implemented in assembly so it
;  works with both small and large memory models.
;
;  Implements the following C code:
;
;      Uint16 DSK5510_mget(Uint32 memaddr)
;      {
;          return *((Uint16 *)memaddr);
;      }
;

    .global _DSK5510_mget
_DSK5510_mget:
    pshboth xar0                ;  Save XAR0 in the stack
    btst #11,mmap(@st1_55),tc1  ;  Save the old intm state
    bset intm                   ;  Set Intm bit to disable interrupts
    nop                         ;  6 nops for latency
    nop                         ;  6 nops for latency
    nop                         ;  6 nops for latency
    nop                         ;  6 nops for latency
    nop                         ;  6 nops for latency
    nop                         ;  6 nops for latency
    mov ac0, xar0               ;  Load move address into xar0
    mov *ar0, t0                ;  Read from memory, return in t0
    nop                         ;  2 nops for latency
    nop                         ;  2 nops for latency
    xcc !tc1                    ;  If !TC1 INTM = 0
    bclr st1_intm               ;  Re-enable interrupts
    popboth xar0                ;  Restore xar0 in the stack
    ret                         ;  Return to caller


;  Write a 16-bit value to a CPLD register.  Implemented in assembly so works
;  with both small and large memory models.
;
;  Implements the following C code:
;
;      void DSK5510_mset(Uint32 memaddr, Uint16 memval)
;      {
;          *((Uint16 *)memaddr) = memval;
;      }
;


    .global _DSK5510_mset
_DSK5510_mset:
    btst #11,mmap(@st1_55),tc1  ;  Save the old intm state
    bset intm                   ;  Set Intm bit to disable interrupts
    nop                         ;  6 nops for latency
    nop                         ;  6 nops for latency
    nop                         ;  6 nops for latency
    nop                         ;  6 nops for latency
    nop                         ;  6 nops for latency
    nop                         ;  6 nops for latency
    pshboth xar0                ;  Save xar0 in the stack
    mov ac0, xar0               ;  Load move address into xar0
    mov t0, *ar0                ;  Write t0 to memory
    nop                         ;  4 nops for latency
    nop                         ;  4 nops for latency
    nop                         ;  4 nops for latency
    nop                         ;  4 nops for latency
    xcc !tc1                    ;  If !TC1 INTM = 0
    bclr st1_intm               ;  Re-enable interrupts
    popboth xar0                ;  Restore xar0 in the stack
    ret                         ;  Return to caller

