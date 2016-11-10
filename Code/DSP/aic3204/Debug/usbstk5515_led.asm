;*******************************************************************************
;* TMS320C55x C/C++ Codegen                                          PC v4.3.8 *
;* Date/Time created: Wed Nov 09 11:17:59 2016                                 *
;*******************************************************************************
	.compiler_opts --hll_source=on --mem_model:code=flat --mem_model:data=large --silicon_core_3_3 --symdebug:dwarf 
	.mmregs
	.cpl_on
	.arms_on
	.c54cm_off
	.asg AR6, FP
	.asg XAR6, XFP
	.asg DPH, MDP
	.model call=c55_std
	.model mem=large
	.noremark 5002  ; code respects overwrite rules
;*******************************************************************************
;* GLOBAL FILE PARAMETERS                                                      *
;*                                                                             *
;*   Architecture       : TMS320C55x                                           *
;*   Optimizing for     : Speed                                                *
;*   Memory             : Large Model (23-Bit Data Pointers)                   *
;*   Calls              : Normal Library ASM calls                             *
;*   Debug Info         : Standard TI Debug Information                        *
;*******************************************************************************

$C$DW$CU	.dwtag  DW_TAG_compile_unit
	.dwattr $C$DW$CU, DW_AT_name("../include/usbstk5515_led.c")
	.dwattr $C$DW$CU, DW_AT_producer("TMS320C55x C/C++ Codegen PC v4.3.8 Copyright (c) 1996-2010 Texas Instruments Incorporated")
	.dwattr $C$DW$CU, DW_AT_TI_version(0x01)
	.dwattr $C$DW$CU, DW_AT_comp_dir("C:\Users\Kiis\Dropbox\Uni\7. semester\AAT7\Code\DSP\aic3204\Debug")

$C$DW$1	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_GPIO_setDirection")
	.dwattr $C$DW$1, DW_AT_TI_symbol_name("_USBSTK5515_GPIO_setDirection")
	.dwattr $C$DW$1, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$1, DW_AT_declaration
	.dwattr $C$DW$1, DW_AT_external
	.dwattr $C$DW$1, DW_AT_decl_file("..\include\usbstk5515_gpio.h")
	.dwattr $C$DW$1, DW_AT_decl_line(0x3c)
	.dwattr $C$DW$1, DW_AT_decl_column(0x07)
$C$DW$2	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$2, DW_AT_type(*$C$DW$T$9)
$C$DW$3	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$3, DW_AT_type(*$C$DW$T$9)
	.dwendtag $C$DW$1


$C$DW$4	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_GPIO_setOutput")
	.dwattr $C$DW$4, DW_AT_TI_symbol_name("_USBSTK5515_GPIO_setOutput")
	.dwattr $C$DW$4, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$4, DW_AT_declaration
	.dwattr $C$DW$4, DW_AT_external
	.dwattr $C$DW$4, DW_AT_decl_file("..\include\usbstk5515_gpio.h")
	.dwattr $C$DW$4, DW_AT_decl_line(0x3d)
	.dwattr $C$DW$4, DW_AT_decl_column(0x07)
$C$DW$5	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$5, DW_AT_type(*$C$DW$T$9)
$C$DW$6	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$6, DW_AT_type(*$C$DW$T$9)
	.dwendtag $C$DW$4


$C$DW$7	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_GPIO_getInput")
	.dwattr $C$DW$7, DW_AT_TI_symbol_name("_USBSTK5515_GPIO_getInput")
	.dwattr $C$DW$7, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$7, DW_AT_declaration
	.dwattr $C$DW$7, DW_AT_external
	.dwattr $C$DW$7, DW_AT_decl_file("..\include\usbstk5515_gpio.h")
	.dwattr $C$DW$7, DW_AT_decl_line(0x3e)
	.dwattr $C$DW$7, DW_AT_decl_column(0x07)
$C$DW$8	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$8, DW_AT_type(*$C$DW$T$9)
	.dwendtag $C$DW$7

;	C:\Program Files\TexasInstruments\ccsv4\tools\compiler\c5500\bin\acp55.exe -@C:\Users\Kiis\AppData\Local\Temp\0284012 
	.sect	".text"
	.global	_USBSTK5515_LED_init

$C$DW$9	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_LED_init")
	.dwattr $C$DW$9, DW_AT_low_pc(_USBSTK5515_LED_init)
	.dwattr $C$DW$9, DW_AT_high_pc(0x00)
	.dwattr $C$DW$9, DW_AT_TI_symbol_name("_USBSTK5515_LED_init")
	.dwattr $C$DW$9, DW_AT_external
	.dwattr $C$DW$9, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$9, DW_AT_TI_begin_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$9, DW_AT_TI_begin_line(0x16)
	.dwattr $C$DW$9, DW_AT_TI_begin_column(0x07)
	.dwattr $C$DW$9, DW_AT_decl_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$9, DW_AT_decl_line(0x16)
	.dwattr $C$DW$9, DW_AT_decl_column(0x07)
	.dwattr $C$DW$9, DW_AT_TI_max_frame_size(0x02)
	.dwpsn	file "../include/usbstk5515_led.c",line 23,column 1,is_stmt,address _USBSTK5515_LED_init

	.dwfde $C$DW$CIE, _USBSTK5515_LED_init
;----------------------------------------------------------------------
;  22 | Int16 USBSTK5515_LED_init( )                                           
;----------------------------------------------------------------------
;*******************************************************************************
;* FUNCTION NAME: USBSTK5515_LED_init                                          *
;*                                                                             *
;*   Function Uses Regs : T0,SP,M40,SATA,SATD,RDM,FRCT,SMUL                    *
;*   Stack Frame        : Compact (No Frame Pointer, w/ debug)                 *
;*   Total Frame Size   : 2 words                                              *
;*                        (2 return address/alignment)                         *
;*   Min System Stack   : 1 word                                               *
;*******************************************************************************
_USBSTK5515_LED_init:
	.dwcfi	cfa_offset, 1
	.dwcfi	save_reg_to_mem, 91, -1
        AADD #-1, SP
	.dwcfi	cfa_offset, 2
	.dwpsn	file "../include/usbstk5515_led.c",line 25,column 5,is_stmt
;----------------------------------------------------------------------
;  25 | return USBSTK5515_LED_off( 0 );                                        
;----------------------------------------------------------------------
$C$DW$10	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$10, DW_AT_low_pc(0x00)
	.dwattr $C$DW$10, DW_AT_name("_USBSTK5515_LED_off")
	.dwattr $C$DW$10, DW_AT_TI_call

        CALL #_USBSTK5515_LED_off ; |25| 
||      MOV #0, T0

                                        ; call occurs [#_USBSTK5515_LED_off] ; |25| 
	.dwpsn	file "../include/usbstk5515_led.c",line 26,column 1,is_stmt
        AADD #1, SP
	.dwcfi	cfa_offset, 1
$C$DW$11	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$11, DW_AT_low_pc(0x00)
	.dwattr $C$DW$11, DW_AT_TI_return
        RET
                                        ; return occurs
	.dwattr $C$DW$9, DW_AT_TI_end_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$9, DW_AT_TI_end_line(0x1a)
	.dwattr $C$DW$9, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$9

	.sect	".text"
	.global	_USBSTK5515_LED_on

$C$DW$12	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_LED_on")
	.dwattr $C$DW$12, DW_AT_low_pc(_USBSTK5515_LED_on)
	.dwattr $C$DW$12, DW_AT_high_pc(0x00)
	.dwattr $C$DW$12, DW_AT_TI_symbol_name("_USBSTK5515_LED_on")
	.dwattr $C$DW$12, DW_AT_external
	.dwattr $C$DW$12, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$12, DW_AT_TI_begin_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$12, DW_AT_TI_begin_line(0x24)
	.dwattr $C$DW$12, DW_AT_TI_begin_column(0x07)
	.dwattr $C$DW$12, DW_AT_decl_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$12, DW_AT_decl_line(0x24)
	.dwattr $C$DW$12, DW_AT_decl_column(0x07)
	.dwattr $C$DW$12, DW_AT_TI_max_frame_size(0x02)
	.dwpsn	file "../include/usbstk5515_led.c",line 37,column 1,is_stmt,address _USBSTK5515_LED_on

	.dwfde $C$DW$CIE, _USBSTK5515_LED_on
$C$DW$13	.dwtag  DW_TAG_formal_parameter, DW_AT_name("number")
	.dwattr $C$DW$13, DW_AT_TI_symbol_name("_number")
	.dwattr $C$DW$13, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$13, DW_AT_location[DW_OP_reg12]
;----------------------------------------------------------------------
;  36 | Int16 USBSTK5515_LED_on(Uint16 number)                                 
;----------------------------------------------------------------------
;*******************************************************************************
;* FUNCTION NAME: USBSTK5515_LED_on                                            *
;*                                                                             *
;*   Function Uses Regs : T0,SP,M40,SATA,SATD,RDM,FRCT,SMUL                    *
;*   Stack Frame        : Compact (No Frame Pointer, w/ debug)                 *
;*   Total Frame Size   : 2 words                                              *
;*                        (1 return address/alignment)                         *
;*                        (1 local values)                                     *
;*   Min System Stack   : 1 word                                               *
;*******************************************************************************
_USBSTK5515_LED_on:
	.dwcfi	cfa_offset, 1
	.dwcfi	save_reg_to_mem, 91, -1
        AADD #-1, SP
	.dwcfi	cfa_offset, 2
$C$DW$14	.dwtag  DW_TAG_variable, DW_AT_name("number")
	.dwattr $C$DW$14, DW_AT_TI_symbol_name("_number")
	.dwattr $C$DW$14, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$14, DW_AT_location[DW_OP_bregx 0x24 0]
        MOV T0, *SP(#0) ; |37| 
	.dwpsn	file "../include/usbstk5515_led.c",line 38,column 2,is_stmt
;----------------------------------------------------------------------
;  38 | asm(" bset XF");                                                       
;----------------------------------------------------------------------
 bset XF
	.dwpsn	file "../include/usbstk5515_led.c",line 39,column 2,is_stmt
;----------------------------------------------------------------------
;  39 | asm(" nop");                                                           
;----------------------------------------------------------------------
 nop
	.dwpsn	file "../include/usbstk5515_led.c",line 40,column 2,is_stmt
;----------------------------------------------------------------------
;  40 | asm(" nop");                                                           
;----------------------------------------------------------------------
 nop
	.dwpsn	file "../include/usbstk5515_led.c",line 41,column 2,is_stmt
;----------------------------------------------------------------------
;  41 | asm(" nop");                                                           
;----------------------------------------------------------------------
 nop
	.dwpsn	file "../include/usbstk5515_led.c",line 42,column 2,is_stmt
;----------------------------------------------------------------------
;  42 | asm(" nop");                                                           
;----------------------------------------------------------------------
 nop
	.dwpsn	file "../include/usbstk5515_led.c",line 43,column 2,is_stmt
;----------------------------------------------------------------------
;  43 | asm(" nop");                                                           
;----------------------------------------------------------------------
 nop
	.dwpsn	file "../include/usbstk5515_led.c",line 45,column 5,is_stmt
;----------------------------------------------------------------------
;  45 | return 0;                                                              
;----------------------------------------------------------------------
        MOV #0, T0
	.dwpsn	file "../include/usbstk5515_led.c",line 46,column 1,is_stmt
        AADD #1, SP
	.dwcfi	cfa_offset, 1
$C$DW$15	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$15, DW_AT_low_pc(0x00)
	.dwattr $C$DW$15, DW_AT_TI_return
        RET
                                        ; return occurs
	.dwattr $C$DW$12, DW_AT_TI_end_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$12, DW_AT_TI_end_line(0x2e)
	.dwattr $C$DW$12, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$12

	.sect	".text"
	.global	_USBSTK5515_LED_off

$C$DW$16	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_LED_off")
	.dwattr $C$DW$16, DW_AT_low_pc(_USBSTK5515_LED_off)
	.dwattr $C$DW$16, DW_AT_high_pc(0x00)
	.dwattr $C$DW$16, DW_AT_TI_symbol_name("_USBSTK5515_LED_off")
	.dwattr $C$DW$16, DW_AT_external
	.dwattr $C$DW$16, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$16, DW_AT_TI_begin_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$16, DW_AT_TI_begin_line(0x38)
	.dwattr $C$DW$16, DW_AT_TI_begin_column(0x07)
	.dwattr $C$DW$16, DW_AT_decl_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$16, DW_AT_decl_line(0x38)
	.dwattr $C$DW$16, DW_AT_decl_column(0x07)
	.dwattr $C$DW$16, DW_AT_TI_max_frame_size(0x02)
	.dwpsn	file "../include/usbstk5515_led.c",line 57,column 1,is_stmt,address _USBSTK5515_LED_off

	.dwfde $C$DW$CIE, _USBSTK5515_LED_off
$C$DW$17	.dwtag  DW_TAG_formal_parameter, DW_AT_name("number")
	.dwattr $C$DW$17, DW_AT_TI_symbol_name("_number")
	.dwattr $C$DW$17, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$17, DW_AT_location[DW_OP_reg12]
;----------------------------------------------------------------------
;  56 | Int16 USBSTK5515_LED_off(Uint16 number)                                
;----------------------------------------------------------------------
;*******************************************************************************
;* FUNCTION NAME: USBSTK5515_LED_off                                           *
;*                                                                             *
;*   Function Uses Regs : T0,SP,M40,SATA,SATD,RDM,FRCT,SMUL                    *
;*   Stack Frame        : Compact (No Frame Pointer, w/ debug)                 *
;*   Total Frame Size   : 2 words                                              *
;*                        (1 return address/alignment)                         *
;*                        (1 local values)                                     *
;*   Min System Stack   : 1 word                                               *
;*******************************************************************************
_USBSTK5515_LED_off:
	.dwcfi	cfa_offset, 1
	.dwcfi	save_reg_to_mem, 91, -1
        AADD #-1, SP
	.dwcfi	cfa_offset, 2
$C$DW$18	.dwtag  DW_TAG_variable, DW_AT_name("number")
	.dwattr $C$DW$18, DW_AT_TI_symbol_name("_number")
	.dwattr $C$DW$18, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$18, DW_AT_location[DW_OP_bregx 0x24 0]
        MOV T0, *SP(#0) ; |57| 
	.dwpsn	file "../include/usbstk5515_led.c",line 58,column 2,is_stmt
;----------------------------------------------------------------------
;  58 | asm(" bclr XF");                                                       
;----------------------------------------------------------------------
 bclr XF
	.dwpsn	file "../include/usbstk5515_led.c",line 59,column 2,is_stmt
;----------------------------------------------------------------------
;  59 | asm(" nop");                                                           
;----------------------------------------------------------------------
 nop
	.dwpsn	file "../include/usbstk5515_led.c",line 60,column 2,is_stmt
;----------------------------------------------------------------------
;  60 | asm(" nop");                                                           
;----------------------------------------------------------------------
 nop
	.dwpsn	file "../include/usbstk5515_led.c",line 61,column 2,is_stmt
;----------------------------------------------------------------------
;  61 | asm(" nop");                                                           
;----------------------------------------------------------------------
 nop
	.dwpsn	file "../include/usbstk5515_led.c",line 62,column 2,is_stmt
;----------------------------------------------------------------------
;  62 | asm(" nop");                                                           
;----------------------------------------------------------------------
 nop
	.dwpsn	file "../include/usbstk5515_led.c",line 63,column 2,is_stmt
;----------------------------------------------------------------------
;  63 | asm(" nop");                                                           
;----------------------------------------------------------------------
 nop
	.dwpsn	file "../include/usbstk5515_led.c",line 65,column 5,is_stmt
;----------------------------------------------------------------------
;  65 | return 0;                                                              
;----------------------------------------------------------------------
        MOV #0, T0
	.dwpsn	file "../include/usbstk5515_led.c",line 66,column 1,is_stmt
        AADD #1, SP
	.dwcfi	cfa_offset, 1
$C$DW$19	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$19, DW_AT_low_pc(0x00)
	.dwattr $C$DW$19, DW_AT_TI_return
        RET
                                        ; return occurs
	.dwattr $C$DW$16, DW_AT_TI_end_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$16, DW_AT_TI_end_line(0x42)
	.dwattr $C$DW$16, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$16

	.sect	".text"
	.global	_USBSTK5515_ULED_init

$C$DW$20	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_ULED_init")
	.dwattr $C$DW$20, DW_AT_low_pc(_USBSTK5515_ULED_init)
	.dwattr $C$DW$20, DW_AT_high_pc(0x00)
	.dwattr $C$DW$20, DW_AT_TI_symbol_name("_USBSTK5515_ULED_init")
	.dwattr $C$DW$20, DW_AT_external
	.dwattr $C$DW$20, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$20, DW_AT_TI_begin_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$20, DW_AT_TI_begin_line(0x4b)
	.dwattr $C$DW$20, DW_AT_TI_begin_column(0x07)
	.dwattr $C$DW$20, DW_AT_decl_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$20, DW_AT_decl_line(0x4b)
	.dwattr $C$DW$20, DW_AT_decl_column(0x07)
	.dwattr $C$DW$20, DW_AT_TI_max_frame_size(0x02)
	.dwpsn	file "../include/usbstk5515_led.c",line 76,column 1,is_stmt,address _USBSTK5515_ULED_init

	.dwfde $C$DW$CIE, _USBSTK5515_ULED_init
;----------------------------------------------------------------------
;  75 | Int16 USBSTK5515_ULED_init( )                                          
;----------------------------------------------------------------------
;*******************************************************************************
;* FUNCTION NAME: USBSTK5515_ULED_init                                         *
;*                                                                             *
;*   Function Uses Regs : T0,T1,SP,M40,SATA,SATD,RDM,FRCT,SMUL                 *
;*   Stack Frame        : Compact (No Frame Pointer, w/ debug)                 *
;*   Total Frame Size   : 2 words                                              *
;*                        (2 return address/alignment)                         *
;*   Min System Stack   : 1 word                                               *
;*******************************************************************************
_USBSTK5515_ULED_init:
	.dwcfi	cfa_offset, 1
	.dwcfi	save_reg_to_mem, 91, -1
        AADD #-1, SP
	.dwcfi	cfa_offset, 2
	.dwpsn	file "../include/usbstk5515_led.c",line 79,column 5,is_stmt
;----------------------------------------------------------------------
;  79 | USBSTK5515_GPIO_setDirection( 14, GPIO_OUT );  // DS1                  
;----------------------------------------------------------------------
        MOV #14, T0
$C$DW$21	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$21, DW_AT_low_pc(0x00)
	.dwattr $C$DW$21, DW_AT_name("_USBSTK5515_GPIO_setDirection")
	.dwattr $C$DW$21, DW_AT_TI_call

        CALL #_USBSTK5515_GPIO_setDirection ; |79| 
||      MOV #1, T1

                                        ; call occurs [#_USBSTK5515_GPIO_setDirection] ; |79| 
	.dwpsn	file "../include/usbstk5515_led.c",line 80,column 5,is_stmt
;----------------------------------------------------------------------
;  80 | USBSTK5515_GPIO_setDirection( 15, GPIO_OUT );  // DS2                  
;----------------------------------------------------------------------
        MOV #15, T0
$C$DW$22	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$22, DW_AT_low_pc(0x00)
	.dwattr $C$DW$22, DW_AT_name("_USBSTK5515_GPIO_setDirection")
	.dwattr $C$DW$22, DW_AT_TI_call

        CALL #_USBSTK5515_GPIO_setDirection ; |80| 
||      MOV #1, T1

                                        ; call occurs [#_USBSTK5515_GPIO_setDirection] ; |80| 
	.dwpsn	file "../include/usbstk5515_led.c",line 81,column 5,is_stmt
;----------------------------------------------------------------------
;  81 | USBSTK5515_GPIO_setDirection( 16, GPIO_OUT );  // DS3                  
;----------------------------------------------------------------------
        MOV #16, T0 ; |81| 
$C$DW$23	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$23, DW_AT_low_pc(0x00)
	.dwattr $C$DW$23, DW_AT_name("_USBSTK5515_GPIO_setDirection")
	.dwattr $C$DW$23, DW_AT_TI_call

        CALL #_USBSTK5515_GPIO_setDirection ; |81| 
||      MOV #1, T1

                                        ; call occurs [#_USBSTK5515_GPIO_setDirection] ; |81| 
	.dwpsn	file "../include/usbstk5515_led.c",line 82,column 5,is_stmt
;----------------------------------------------------------------------
;  82 | USBSTK5515_GPIO_setDirection( 17, GPIO_OUT );  // DS4                  
;----------------------------------------------------------------------
        MOV #17, T0 ; |82| 
$C$DW$24	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$24, DW_AT_low_pc(0x00)
	.dwattr $C$DW$24, DW_AT_name("_USBSTK5515_GPIO_setDirection")
	.dwattr $C$DW$24, DW_AT_TI_call

        CALL #_USBSTK5515_GPIO_setDirection ; |82| 
||      MOV #1, T1

                                        ; call occurs [#_USBSTK5515_GPIO_setDirection] ; |82| 
	.dwpsn	file "../include/usbstk5515_led.c",line 85,column 5,is_stmt
;----------------------------------------------------------------------
;  85 | return USBSTK5515_ULED_setall( 0x0F );                                 
;----------------------------------------------------------------------
$C$DW$25	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$25, DW_AT_low_pc(0x00)
	.dwattr $C$DW$25, DW_AT_name("_USBSTK5515_ULED_setall")
	.dwattr $C$DW$25, DW_AT_TI_call

        CALL #_USBSTK5515_ULED_setall ; |85| 
||      MOV #15, T0

                                        ; call occurs [#_USBSTK5515_ULED_setall] ; |85| 
	.dwpsn	file "../include/usbstk5515_led.c",line 86,column 1,is_stmt
        AADD #1, SP
	.dwcfi	cfa_offset, 1
$C$DW$26	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$26, DW_AT_low_pc(0x00)
	.dwattr $C$DW$26, DW_AT_TI_return
        RET
                                        ; return occurs
	.dwattr $C$DW$20, DW_AT_TI_end_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$20, DW_AT_TI_end_line(0x56)
	.dwattr $C$DW$20, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$20

	.sect	".text"
	.global	_USBSTK5515_ULED_getall

$C$DW$27	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_ULED_getall")
	.dwattr $C$DW$27, DW_AT_low_pc(_USBSTK5515_ULED_getall)
	.dwattr $C$DW$27, DW_AT_high_pc(0x00)
	.dwattr $C$DW$27, DW_AT_TI_symbol_name("_USBSTK5515_ULED_getall")
	.dwattr $C$DW$27, DW_AT_external
	.dwattr $C$DW$27, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$27, DW_AT_TI_begin_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$27, DW_AT_TI_begin_line(0x5f)
	.dwattr $C$DW$27, DW_AT_TI_begin_column(0x07)
	.dwattr $C$DW$27, DW_AT_decl_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$27, DW_AT_decl_line(0x5f)
	.dwattr $C$DW$27, DW_AT_decl_column(0x07)
	.dwattr $C$DW$27, DW_AT_TI_max_frame_size(0x06)
	.dwpsn	file "../include/usbstk5515_led.c",line 96,column 1,is_stmt,address _USBSTK5515_ULED_getall

	.dwfde $C$DW$CIE, _USBSTK5515_ULED_getall
$C$DW$28	.dwtag  DW_TAG_formal_parameter, DW_AT_name("pattern")
	.dwattr $C$DW$28, DW_AT_TI_symbol_name("_pattern")
	.dwattr $C$DW$28, DW_AT_type(*$C$DW$T$24)
	.dwattr $C$DW$28, DW_AT_location[DW_OP_reg17]
;----------------------------------------------------------------------
;  95 | Int16 USBSTK5515_ULED_getall( Uint16 *pattern )                        
;----------------------------------------------------------------------
;*******************************************************************************
;* FUNCTION NAME: USBSTK5515_ULED_getall                                       *
;*                                                                             *
;*   Function Uses Regs : AC0,T0,T2,T3,AR0,XAR0,AR1,AR3,XAR3,SP,M40,SATA,SATD, *
;*                        RDM,FRCT,SMUL                                        *
;*   Save On Entry Regs : T2,T3                                                *
;*   Stack Frame        : Compact (No Frame Pointer, w/ debug)                 *
;*   Total Frame Size   : 6 words                                              *
;*                        (1 return address/alignment)                         *
;*                        (3 local values)                                     *
;*                        (2 register save area)                               *
;*   Min System Stack   : 1 word                                               *
;*******************************************************************************
_USBSTK5515_ULED_getall:
	.dwcfi	cfa_offset, 1
	.dwcfi	save_reg_to_mem, 91, -1
        PSH T2
	.dwcfi	cfa_offset, 2
	.dwcfi	save_reg_to_mem, 14, -2
        PSH T3
	.dwcfi	cfa_offset, 3
	.dwcfi	save_reg_to_mem, 15, -3
        AADD #-3, SP
	.dwcfi	cfa_offset, 6
$C$DW$29	.dwtag  DW_TAG_variable, DW_AT_name("pattern")
	.dwattr $C$DW$29, DW_AT_TI_symbol_name("_pattern")
	.dwattr $C$DW$29, DW_AT_type(*$C$DW$T$24)
	.dwattr $C$DW$29, DW_AT_location[DW_OP_bregx 0x24 0]
$C$DW$30	.dwtag  DW_TAG_variable, DW_AT_name("retval")
	.dwattr $C$DW$30, DW_AT_TI_symbol_name("_retval")
	.dwattr $C$DW$30, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$30, DW_AT_location[DW_OP_bregx 0x24 2]
;----------------------------------------------------------------------
;  97 | Uint16 retval;                                                         
;----------------------------------------------------------------------
        MOV XAR0, dbl(*SP(#0))
	.dwpsn	file "../include/usbstk5515_led.c",line 99,column 2,is_stmt
;----------------------------------------------------------------------
;  99 | retval = USBSTK5515_GPIO_getInput(14)  |                               
; 100 |     (USBSTK5515_GPIO_getInput(15) << 1) |                              
; 101 |         (USBSTK5515_GPIO_getInput(16) << 2) |                          
; 102 |         (USBSTK5515_GPIO_getInput(17) << 3);                           
;----------------------------------------------------------------------
$C$DW$31	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$31, DW_AT_low_pc(0x00)
	.dwattr $C$DW$31, DW_AT_name("_USBSTK5515_GPIO_getInput")
	.dwattr $C$DW$31, DW_AT_TI_call

        CALL #_USBSTK5515_GPIO_getInput ; |99| 
||      MOV #14, T0

                                        ; call occurs [#_USBSTK5515_GPIO_getInput] ; |99| 
        MOV T0, T3 ; |99| 
$C$DW$32	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$32, DW_AT_low_pc(0x00)
	.dwattr $C$DW$32, DW_AT_name("_USBSTK5515_GPIO_getInput")
	.dwattr $C$DW$32, DW_AT_TI_call

        CALL #_USBSTK5515_GPIO_getInput ; |99| 
||      MOV #15, T0

                                        ; call occurs [#_USBSTK5515_GPIO_getInput] ; |99| 
        MOV T0, AC0 ; |99| 

        SFTS AC0, #1, AC0 ; |99| 
||      MOV #16, T0 ; |99| 

$C$DW$33	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$33, DW_AT_low_pc(0x00)
	.dwattr $C$DW$33, DW_AT_name("_USBSTK5515_GPIO_getInput")
	.dwattr $C$DW$33, DW_AT_TI_call

        CALL #_USBSTK5515_GPIO_getInput ; |99| 
||      MOV AC0, T2 ; |99| 

                                        ; call occurs [#_USBSTK5515_GPIO_getInput] ; |99| 

        MOV T0, AC0 ; |99| 
||      OR T3, T2 ; |99| 

        SFTS AC0, #2, AC0 ; |99| 
||      MOV #17, T0 ; |99| 

$C$DW$34	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$34, DW_AT_low_pc(0x00)
	.dwattr $C$DW$34, DW_AT_name("_USBSTK5515_GPIO_getInput")
	.dwattr $C$DW$34, DW_AT_TI_call

        CALL #_USBSTK5515_GPIO_getInput ; |99| 
||      MOV AC0, T3 ; |99| 

                                        ; call occurs [#_USBSTK5515_GPIO_getInput] ; |99| 
        MOV T0, AC0 ; |99| 

        SFTS AC0, #3, AC0 ; |99| 
||      OR T2, T3 ; |99| 

        OR T3, AC0 ; |99| 
        MOV AC0, *SP(#2) ; |99| 
	.dwpsn	file "../include/usbstk5515_led.c",line 104,column 5,is_stmt
;----------------------------------------------------------------------
; 104 | *pattern = retval;                                                     
;----------------------------------------------------------------------
        MOV dbl(*SP(#0)), XAR3
        MOV AC0, AR1
        MOV AR1, *AR3 ; |104| 
	.dwpsn	file "../include/usbstk5515_led.c",line 106,column 5,is_stmt
;----------------------------------------------------------------------
; 106 | return 0;                                                              
;----------------------------------------------------------------------
        MOV #0, T0
	.dwpsn	file "../include/usbstk5515_led.c",line 107,column 1,is_stmt
        AADD #3, SP
	.dwcfi	cfa_offset, 3
        POP T3
	.dwcfi	restore_reg, 15
	.dwcfi	cfa_offset, 2
        POP T2
	.dwcfi	restore_reg, 14
	.dwcfi	cfa_offset, 1
$C$DW$35	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$35, DW_AT_low_pc(0x00)
	.dwattr $C$DW$35, DW_AT_TI_return
        RET
                                        ; return occurs
	.dwattr $C$DW$27, DW_AT_TI_end_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$27, DW_AT_TI_end_line(0x6b)
	.dwattr $C$DW$27, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$27

	.sect	".text"
	.global	_USBSTK5515_ULED_setall

$C$DW$36	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_ULED_setall")
	.dwattr $C$DW$36, DW_AT_low_pc(_USBSTK5515_ULED_setall)
	.dwattr $C$DW$36, DW_AT_high_pc(0x00)
	.dwattr $C$DW$36, DW_AT_TI_symbol_name("_USBSTK5515_ULED_setall")
	.dwattr $C$DW$36, DW_AT_external
	.dwattr $C$DW$36, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$36, DW_AT_TI_begin_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$36, DW_AT_TI_begin_line(0x74)
	.dwattr $C$DW$36, DW_AT_TI_begin_column(0x07)
	.dwattr $C$DW$36, DW_AT_decl_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$36, DW_AT_decl_line(0x74)
	.dwattr $C$DW$36, DW_AT_decl_column(0x07)
	.dwattr $C$DW$36, DW_AT_TI_max_frame_size(0x02)
	.dwpsn	file "../include/usbstk5515_led.c",line 117,column 1,is_stmt,address _USBSTK5515_ULED_setall

	.dwfde $C$DW$CIE, _USBSTK5515_ULED_setall
$C$DW$37	.dwtag  DW_TAG_formal_parameter, DW_AT_name("pattern")
	.dwattr $C$DW$37, DW_AT_TI_symbol_name("_pattern")
	.dwattr $C$DW$37, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$37, DW_AT_location[DW_OP_reg12]
;----------------------------------------------------------------------
; 116 | Int16 USBSTK5515_ULED_setall( Uint16 pattern )                         
;----------------------------------------------------------------------
;*******************************************************************************
;* FUNCTION NAME: USBSTK5515_ULED_setall                                       *
;*                                                                             *
;*   Function Uses Regs : T0,T1,SP,TC1,M40,SATA,SATD,RDM,FRCT,SMUL             *
;*   Stack Frame        : Compact (No Frame Pointer, w/ debug)                 *
;*   Total Frame Size   : 2 words                                              *
;*                        (1 return address/alignment)                         *
;*                        (1 local values)                                     *
;*   Min System Stack   : 1 word                                               *
;*******************************************************************************
_USBSTK5515_ULED_setall:
	.dwcfi	cfa_offset, 1
	.dwcfi	save_reg_to_mem, 91, -1
        AADD #-1, SP
	.dwcfi	cfa_offset, 2
$C$DW$38	.dwtag  DW_TAG_variable, DW_AT_name("pattern")
	.dwattr $C$DW$38, DW_AT_TI_symbol_name("_pattern")
	.dwattr $C$DW$38, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$38, DW_AT_location[DW_OP_bregx 0x24 0]
        MOV T0, *SP(#0) ; |117| 
	.dwpsn	file "../include/usbstk5515_led.c",line 118,column 5,is_stmt
;----------------------------------------------------------------------
; 118 | if (pattern & 0x01)                                                    
;----------------------------------------------------------------------
        BTST #0, *SP(#0), TC1 ; |118| 
        BCC $C$L1,!TC1 ; |118| 
                                        ; branchcc occurs ; |118| 
	.dwpsn	file "../include/usbstk5515_led.c",line 119,column 9,is_stmt
;----------------------------------------------------------------------
; 119 | USBSTK5515_GPIO_setOutput( 14, 1);                                     
; 120 | else                                                                   
;----------------------------------------------------------------------
        MOV #14, T0
$C$DW$39	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$39, DW_AT_low_pc(0x00)
	.dwattr $C$DW$39, DW_AT_name("_USBSTK5515_GPIO_setOutput")
	.dwattr $C$DW$39, DW_AT_TI_call

        CALL #_USBSTK5515_GPIO_setOutput ; |119| 
||      MOV #1, T1

                                        ; call occurs [#_USBSTK5515_GPIO_setOutput] ; |119| 
        B $C$L2   ; |119| 
                                        ; branch occurs ; |119| 
$C$L1:    
	.dwpsn	file "../include/usbstk5515_led.c",line 121,column 9,is_stmt
;----------------------------------------------------------------------
; 121 | USBSTK5515_GPIO_setOutput( 14, 0);                                     
;----------------------------------------------------------------------
        MOV #14, T0
$C$DW$40	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$40, DW_AT_low_pc(0x00)
	.dwattr $C$DW$40, DW_AT_name("_USBSTK5515_GPIO_setOutput")
	.dwattr $C$DW$40, DW_AT_TI_call

        CALL #_USBSTK5515_GPIO_setOutput ; |121| 
||      MOV #0, T1

                                        ; call occurs [#_USBSTK5515_GPIO_setOutput] ; |121| 
$C$L2:    
	.dwpsn	file "../include/usbstk5515_led.c",line 123,column 5,is_stmt
;----------------------------------------------------------------------
; 123 | if (pattern & 0x02)                                                    
;----------------------------------------------------------------------
        BTST #1, *SP(#0), TC1 ; |123| 
        BCC $C$L3,!TC1 ; |123| 
                                        ; branchcc occurs ; |123| 
	.dwpsn	file "../include/usbstk5515_led.c",line 124,column 9,is_stmt
;----------------------------------------------------------------------
; 124 | USBSTK5515_GPIO_setOutput( 15, 1);                                     
; 125 | else                                                                   
;----------------------------------------------------------------------
        MOV #15, T0
$C$DW$41	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$41, DW_AT_low_pc(0x00)
	.dwattr $C$DW$41, DW_AT_name("_USBSTK5515_GPIO_setOutput")
	.dwattr $C$DW$41, DW_AT_TI_call

        CALL #_USBSTK5515_GPIO_setOutput ; |124| 
||      MOV #1, T1

                                        ; call occurs [#_USBSTK5515_GPIO_setOutput] ; |124| 
        B $C$L4   ; |124| 
                                        ; branch occurs ; |124| 
$C$L3:    
	.dwpsn	file "../include/usbstk5515_led.c",line 126,column 9,is_stmt
;----------------------------------------------------------------------
; 126 | USBSTK5515_GPIO_setOutput( 15, 0);                                     
;----------------------------------------------------------------------
        MOV #15, T0
$C$DW$42	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$42, DW_AT_low_pc(0x00)
	.dwattr $C$DW$42, DW_AT_name("_USBSTK5515_GPIO_setOutput")
	.dwattr $C$DW$42, DW_AT_TI_call

        CALL #_USBSTK5515_GPIO_setOutput ; |126| 
||      MOV #0, T1

                                        ; call occurs [#_USBSTK5515_GPIO_setOutput] ; |126| 
$C$L4:    
	.dwpsn	file "../include/usbstk5515_led.c",line 128,column 5,is_stmt
;----------------------------------------------------------------------
; 128 | if (pattern & 0x04)                                                    
;----------------------------------------------------------------------
        BTST #2, *SP(#0), TC1 ; |128| 
        BCC $C$L5,!TC1 ; |128| 
                                        ; branchcc occurs ; |128| 
	.dwpsn	file "../include/usbstk5515_led.c",line 129,column 9,is_stmt
;----------------------------------------------------------------------
; 129 | USBSTK5515_GPIO_setOutput( 16, 1);                                     
; 130 | else                                                                   
;----------------------------------------------------------------------
        MOV #16, T0 ; |129| 
$C$DW$43	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$43, DW_AT_low_pc(0x00)
	.dwattr $C$DW$43, DW_AT_name("_USBSTK5515_GPIO_setOutput")
	.dwattr $C$DW$43, DW_AT_TI_call

        CALL #_USBSTK5515_GPIO_setOutput ; |129| 
||      MOV #1, T1

                                        ; call occurs [#_USBSTK5515_GPIO_setOutput] ; |129| 
        B $C$L6   ; |129| 
                                        ; branch occurs ; |129| 
$C$L5:    
	.dwpsn	file "../include/usbstk5515_led.c",line 131,column 9,is_stmt
;----------------------------------------------------------------------
; 131 | USBSTK5515_GPIO_setOutput( 16, 0);                                     
;----------------------------------------------------------------------
        MOV #16, T0 ; |131| 
$C$DW$44	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$44, DW_AT_low_pc(0x00)
	.dwattr $C$DW$44, DW_AT_name("_USBSTK5515_GPIO_setOutput")
	.dwattr $C$DW$44, DW_AT_TI_call

        CALL #_USBSTK5515_GPIO_setOutput ; |131| 
||      MOV #0, T1

                                        ; call occurs [#_USBSTK5515_GPIO_setOutput] ; |131| 
$C$L6:    
	.dwpsn	file "../include/usbstk5515_led.c",line 133,column 5,is_stmt
;----------------------------------------------------------------------
; 133 | if (pattern & 0x08)                                                    
;----------------------------------------------------------------------
        BTST #3, *SP(#0), TC1 ; |133| 
        BCC $C$L7,!TC1 ; |133| 
                                        ; branchcc occurs ; |133| 
	.dwpsn	file "../include/usbstk5515_led.c",line 134,column 9,is_stmt
;----------------------------------------------------------------------
; 134 | USBSTK5515_GPIO_setOutput( 17, 1);                                     
; 135 | else                                                                   
;----------------------------------------------------------------------
        MOV #17, T0 ; |134| 
$C$DW$45	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$45, DW_AT_low_pc(0x00)
	.dwattr $C$DW$45, DW_AT_name("_USBSTK5515_GPIO_setOutput")
	.dwattr $C$DW$45, DW_AT_TI_call

        CALL #_USBSTK5515_GPIO_setOutput ; |134| 
||      MOV #1, T1

                                        ; call occurs [#_USBSTK5515_GPIO_setOutput] ; |134| 
        B $C$L8   ; |134| 
                                        ; branch occurs ; |134| 
$C$L7:    
	.dwpsn	file "../include/usbstk5515_led.c",line 136,column 9,is_stmt
;----------------------------------------------------------------------
; 136 | USBSTK5515_GPIO_setOutput( 17, 0);                                     
;----------------------------------------------------------------------
        MOV #17, T0 ; |136| 
$C$DW$46	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$46, DW_AT_low_pc(0x00)
	.dwattr $C$DW$46, DW_AT_name("_USBSTK5515_GPIO_setOutput")
	.dwattr $C$DW$46, DW_AT_TI_call

        CALL #_USBSTK5515_GPIO_setOutput ; |136| 
||      MOV #0, T1

                                        ; call occurs [#_USBSTK5515_GPIO_setOutput] ; |136| 
$C$L8:    
	.dwpsn	file "../include/usbstk5515_led.c",line 138,column 5,is_stmt
;----------------------------------------------------------------------
; 138 | return 0;                                                              
;----------------------------------------------------------------------
        MOV #0, T0
	.dwpsn	file "../include/usbstk5515_led.c",line 139,column 1,is_stmt
        AADD #1, SP
	.dwcfi	cfa_offset, 1
$C$DW$47	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$47, DW_AT_low_pc(0x00)
	.dwattr $C$DW$47, DW_AT_TI_return
        RET
                                        ; return occurs
	.dwattr $C$DW$36, DW_AT_TI_end_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$36, DW_AT_TI_end_line(0x8b)
	.dwattr $C$DW$36, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$36

	.sect	".text"
	.global	_USBSTK5515_ULED_on

$C$DW$48	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_ULED_on")
	.dwattr $C$DW$48, DW_AT_low_pc(_USBSTK5515_ULED_on)
	.dwattr $C$DW$48, DW_AT_high_pc(0x00)
	.dwattr $C$DW$48, DW_AT_TI_symbol_name("_USBSTK5515_ULED_on")
	.dwattr $C$DW$48, DW_AT_external
	.dwattr $C$DW$48, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$48, DW_AT_TI_begin_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$48, DW_AT_TI_begin_line(0x94)
	.dwattr $C$DW$48, DW_AT_TI_begin_column(0x07)
	.dwattr $C$DW$48, DW_AT_decl_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$48, DW_AT_decl_line(0x94)
	.dwattr $C$DW$48, DW_AT_decl_column(0x07)
	.dwattr $C$DW$48, DW_AT_TI_max_frame_size(0x04)
	.dwpsn	file "../include/usbstk5515_led.c",line 149,column 1,is_stmt,address _USBSTK5515_ULED_on

	.dwfde $C$DW$CIE, _USBSTK5515_ULED_on
$C$DW$49	.dwtag  DW_TAG_formal_parameter, DW_AT_name("number")
	.dwattr $C$DW$49, DW_AT_TI_symbol_name("_number")
	.dwattr $C$DW$49, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$49, DW_AT_location[DW_OP_reg12]
;----------------------------------------------------------------------
; 148 | Int16 USBSTK5515_ULED_on( Uint16 number )                              
;----------------------------------------------------------------------
;*******************************************************************************
;* FUNCTION NAME: USBSTK5515_ULED_on                                           *
;*                                                                             *
;*   Function Uses Regs : AC0,AC0,T0,T1,AR0,XAR0,AR1,SP,CARRY,M40,SATA,SATD,   *
;*                        RDM,FRCT,SMUL                                        *
;*   Stack Frame        : Compact (No Frame Pointer, w/ debug)                 *
;*   Total Frame Size   : 4 words                                              *
;*                        (1 return address/alignment)                         *
;*                        (3 local values)                                     *
;*   Min System Stack   : 1 word                                               *
;*******************************************************************************
_USBSTK5515_ULED_on:
	.dwcfi	cfa_offset, 1
	.dwcfi	save_reg_to_mem, 91, -1
        AADD #-3, SP
	.dwcfi	cfa_offset, 4
$C$DW$50	.dwtag  DW_TAG_variable, DW_AT_name("number")
	.dwattr $C$DW$50, DW_AT_TI_symbol_name("_number")
	.dwattr $C$DW$50, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$50, DW_AT_location[DW_OP_bregx 0x24 0]
$C$DW$51	.dwtag  DW_TAG_variable, DW_AT_name("led_state")
	.dwattr $C$DW$51, DW_AT_TI_symbol_name("_led_state")
	.dwattr $C$DW$51, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$51, DW_AT_location[DW_OP_bregx 0x24 1]
$C$DW$52	.dwtag  DW_TAG_variable, DW_AT_name("led_bit_on")
	.dwattr $C$DW$52, DW_AT_TI_symbol_name("_led_bit_on")
	.dwattr $C$DW$52, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$52, DW_AT_location[DW_OP_bregx 0x24 2]
;----------------------------------------------------------------------
; 150 | Uint16 led_state;                                                      
; 151 | Uint16 led_bit_on;                                                     
;----------------------------------------------------------------------
        MOV T0, *SP(#0) ; |149| 
	.dwpsn	file "../include/usbstk5515_led.c",line 153,column 5,is_stmt
;----------------------------------------------------------------------
; 153 | led_bit_on = 1 << ( 3 - number );                                      
;----------------------------------------------------------------------
        MOV #3, AR1

        SUB *SP(#0), AR1, T1 ; |153| 
||      MOV #1, AC0

        SFTS AC0, T1, AC0 ; |153| 
        MOV AC0, *SP(#2) ; |153| 
	.dwpsn	file "../include/usbstk5515_led.c",line 158,column 5,is_stmt
;----------------------------------------------------------------------
; 158 | if ( USBSTK5515_ULED_getall( &led_state ) )                            
;----------------------------------------------------------------------
        AMAR *SP(#1), XAR0
$C$DW$53	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$53, DW_AT_low_pc(0x00)
	.dwattr $C$DW$53, DW_AT_name("_USBSTK5515_ULED_getall")
	.dwattr $C$DW$53, DW_AT_TI_call
        CALL #_USBSTK5515_ULED_getall ; |158| 
                                        ; call occurs [#_USBSTK5515_ULED_getall] ; |158| 
        BCC $C$L9,T0 == #0 ; |158| 
                                        ; branchcc occurs ; |158| 
	.dwpsn	file "../include/usbstk5515_led.c",line 159,column 9,is_stmt
;----------------------------------------------------------------------
; 159 | return -1;                                                             
;----------------------------------------------------------------------
        MOV #-1, T0
        B $C$L11  ; |159| 
                                        ; branch occurs ; |159| 
$C$L9:    
	.dwpsn	file "../include/usbstk5515_led.c",line 161,column 5,is_stmt
;----------------------------------------------------------------------
; 161 | led_state = led_state & ( ~led_bit_on );                               
;----------------------------------------------------------------------
        MOV *SP(#2), AR1 ; |161| 
        NOT AR1, AR1 ; |161| 
        AND *SP(#1), AR1, AC0 ; |161| 
        MOV AC0, *SP(#1) ; |161| 
	.dwpsn	file "../include/usbstk5515_led.c",line 163,column 5,is_stmt
;----------------------------------------------------------------------
; 163 | if ( USBSTK5515_ULED_setall( led_state ) )                             
;----------------------------------------------------------------------
$C$DW$54	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$54, DW_AT_low_pc(0x00)
	.dwattr $C$DW$54, DW_AT_name("_USBSTK5515_ULED_setall")
	.dwattr $C$DW$54, DW_AT_TI_call

        CALL #_USBSTK5515_ULED_setall ; |163| 
||      MOV AC0, T0

                                        ; call occurs [#_USBSTK5515_ULED_setall] ; |163| 
        BCC $C$L10,T0 == #0 ; |163| 
                                        ; branchcc occurs ; |163| 
	.dwpsn	file "../include/usbstk5515_led.c",line 164,column 9,is_stmt
;----------------------------------------------------------------------
; 164 | return -1;                                                             
;----------------------------------------------------------------------
        MOV #-1, T0
        B $C$L11  ; |164| 
                                        ; branch occurs ; |164| 
$C$L10:    
	.dwpsn	file "../include/usbstk5515_led.c",line 166,column 5,is_stmt
;----------------------------------------------------------------------
; 166 | return 0;                                                              
;----------------------------------------------------------------------
        MOV #0, T0
$C$L11:    
	.dwpsn	file "../include/usbstk5515_led.c",line 167,column 1,is_stmt
        AADD #3, SP
	.dwcfi	cfa_offset, 1
$C$DW$55	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$55, DW_AT_low_pc(0x00)
	.dwattr $C$DW$55, DW_AT_TI_return
        RET
                                        ; return occurs
	.dwattr $C$DW$48, DW_AT_TI_end_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$48, DW_AT_TI_end_line(0xa7)
	.dwattr $C$DW$48, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$48

	.sect	".text"
	.global	_USBSTK5515_ULED_off

$C$DW$56	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_ULED_off")
	.dwattr $C$DW$56, DW_AT_low_pc(_USBSTK5515_ULED_off)
	.dwattr $C$DW$56, DW_AT_high_pc(0x00)
	.dwattr $C$DW$56, DW_AT_TI_symbol_name("_USBSTK5515_ULED_off")
	.dwattr $C$DW$56, DW_AT_external
	.dwattr $C$DW$56, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$56, DW_AT_TI_begin_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$56, DW_AT_TI_begin_line(0xb0)
	.dwattr $C$DW$56, DW_AT_TI_begin_column(0x07)
	.dwattr $C$DW$56, DW_AT_decl_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$56, DW_AT_decl_line(0xb0)
	.dwattr $C$DW$56, DW_AT_decl_column(0x07)
	.dwattr $C$DW$56, DW_AT_TI_max_frame_size(0x04)
	.dwpsn	file "../include/usbstk5515_led.c",line 177,column 1,is_stmt,address _USBSTK5515_ULED_off

	.dwfde $C$DW$CIE, _USBSTK5515_ULED_off
$C$DW$57	.dwtag  DW_TAG_formal_parameter, DW_AT_name("number")
	.dwattr $C$DW$57, DW_AT_TI_symbol_name("_number")
	.dwattr $C$DW$57, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$57, DW_AT_location[DW_OP_reg12]
;----------------------------------------------------------------------
; 176 | Int16 USBSTK5515_ULED_off( Uint16 number )                             
;----------------------------------------------------------------------
;*******************************************************************************
;* FUNCTION NAME: USBSTK5515_ULED_off                                          *
;*                                                                             *
;*   Function Uses Regs : AC0,T0,T1,AR0,XAR0,AR1,SP,CARRY,M40,SATA,SATD,RDM,   *
;*                        FRCT,SMUL                                            *
;*   Stack Frame        : Compact (No Frame Pointer, w/ debug)                 *
;*   Total Frame Size   : 4 words                                              *
;*                        (1 return address/alignment)                         *
;*                        (3 local values)                                     *
;*   Min System Stack   : 1 word                                               *
;*******************************************************************************
_USBSTK5515_ULED_off:
	.dwcfi	cfa_offset, 1
	.dwcfi	save_reg_to_mem, 91, -1
        AADD #-3, SP
	.dwcfi	cfa_offset, 4
$C$DW$58	.dwtag  DW_TAG_variable, DW_AT_name("number")
	.dwattr $C$DW$58, DW_AT_TI_symbol_name("_number")
	.dwattr $C$DW$58, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$58, DW_AT_location[DW_OP_bregx 0x24 0]
$C$DW$59	.dwtag  DW_TAG_variable, DW_AT_name("led_state")
	.dwattr $C$DW$59, DW_AT_TI_symbol_name("_led_state")
	.dwattr $C$DW$59, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$59, DW_AT_location[DW_OP_bregx 0x24 1]
$C$DW$60	.dwtag  DW_TAG_variable, DW_AT_name("led_bit_off")
	.dwattr $C$DW$60, DW_AT_TI_symbol_name("_led_bit_off")
	.dwattr $C$DW$60, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$60, DW_AT_location[DW_OP_bregx 0x24 2]
;----------------------------------------------------------------------
; 178 | Uint16 led_state;                                                      
; 179 | Uint16 led_bit_off;                                                    
;----------------------------------------------------------------------
        MOV T0, *SP(#0) ; |177| 
	.dwpsn	file "../include/usbstk5515_led.c",line 181,column 5,is_stmt
;----------------------------------------------------------------------
; 181 | led_bit_off = 1 << ( 3 - number );                                     
;----------------------------------------------------------------------
        MOV #3, AR1

        SUB *SP(#0), AR1, T1 ; |181| 
||      MOV #1, AC0

        SFTS AC0, T1, AC0 ; |181| 
        MOV AC0, *SP(#2) ; |181| 
	.dwpsn	file "../include/usbstk5515_led.c",line 186,column 5,is_stmt
;----------------------------------------------------------------------
; 186 | if ( USBSTK5515_ULED_getall( &led_state ) )                            
;----------------------------------------------------------------------
        AMAR *SP(#1), XAR0
$C$DW$61	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$61, DW_AT_low_pc(0x00)
	.dwattr $C$DW$61, DW_AT_name("_USBSTK5515_ULED_getall")
	.dwattr $C$DW$61, DW_AT_TI_call
        CALL #_USBSTK5515_ULED_getall ; |186| 
                                        ; call occurs [#_USBSTK5515_ULED_getall] ; |186| 
        BCC $C$L12,T0 == #0 ; |186| 
                                        ; branchcc occurs ; |186| 
	.dwpsn	file "../include/usbstk5515_led.c",line 187,column 9,is_stmt
;----------------------------------------------------------------------
; 187 | return -1;                                                             
;----------------------------------------------------------------------
        MOV #-1, T0
        B $C$L14  ; |187| 
                                        ; branch occurs ; |187| 
$C$L12:    
	.dwpsn	file "../include/usbstk5515_led.c",line 189,column 5,is_stmt
;----------------------------------------------------------------------
; 189 | led_state = led_state | led_bit_off;                                   
;----------------------------------------------------------------------
        MOV *SP(#2), AR1 ; |189| 
        OR *SP(#1), AR1, AR1 ; |189| 
        MOV AR1, *SP(#1) ; |189| 
	.dwpsn	file "../include/usbstk5515_led.c",line 191,column 5,is_stmt
;----------------------------------------------------------------------
; 191 | if ( USBSTK5515_ULED_setall( led_state ) )                             
;----------------------------------------------------------------------
$C$DW$62	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$62, DW_AT_low_pc(0x00)
	.dwattr $C$DW$62, DW_AT_name("_USBSTK5515_ULED_setall")
	.dwattr $C$DW$62, DW_AT_TI_call

        CALL #_USBSTK5515_ULED_setall ; |191| 
||      MOV AR1, T0

                                        ; call occurs [#_USBSTK5515_ULED_setall] ; |191| 
        BCC $C$L13,T0 == #0 ; |191| 
                                        ; branchcc occurs ; |191| 
	.dwpsn	file "../include/usbstk5515_led.c",line 192,column 9,is_stmt
;----------------------------------------------------------------------
; 192 | return -1;                                                             
;----------------------------------------------------------------------
        MOV #-1, T0
        B $C$L14  ; |192| 
                                        ; branch occurs ; |192| 
$C$L13:    
	.dwpsn	file "../include/usbstk5515_led.c",line 194,column 5,is_stmt
;----------------------------------------------------------------------
; 194 | return 0;                                                              
;----------------------------------------------------------------------
        MOV #0, T0
$C$L14:    
	.dwpsn	file "../include/usbstk5515_led.c",line 195,column 1,is_stmt
        AADD #3, SP
	.dwcfi	cfa_offset, 1
$C$DW$63	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$63, DW_AT_low_pc(0x00)
	.dwattr $C$DW$63, DW_AT_TI_return
        RET
                                        ; return occurs
	.dwattr $C$DW$56, DW_AT_TI_end_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$56, DW_AT_TI_end_line(0xc3)
	.dwattr $C$DW$56, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$56

	.sect	".text"
	.global	_USBSTK5515_ULED_toggle

$C$DW$64	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_ULED_toggle")
	.dwattr $C$DW$64, DW_AT_low_pc(_USBSTK5515_ULED_toggle)
	.dwattr $C$DW$64, DW_AT_high_pc(0x00)
	.dwattr $C$DW$64, DW_AT_TI_symbol_name("_USBSTK5515_ULED_toggle")
	.dwattr $C$DW$64, DW_AT_external
	.dwattr $C$DW$64, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$64, DW_AT_TI_begin_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$64, DW_AT_TI_begin_line(0xcc)
	.dwattr $C$DW$64, DW_AT_TI_begin_column(0x07)
	.dwattr $C$DW$64, DW_AT_decl_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$64, DW_AT_decl_line(0xcc)
	.dwattr $C$DW$64, DW_AT_decl_column(0x07)
	.dwattr $C$DW$64, DW_AT_TI_max_frame_size(0x06)
	.dwpsn	file "../include/usbstk5515_led.c",line 205,column 1,is_stmt,address _USBSTK5515_ULED_toggle

	.dwfde $C$DW$CIE, _USBSTK5515_ULED_toggle
$C$DW$65	.dwtag  DW_TAG_formal_parameter, DW_AT_name("number")
	.dwattr $C$DW$65, DW_AT_TI_symbol_name("_number")
	.dwattr $C$DW$65, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$65, DW_AT_location[DW_OP_reg12]
;----------------------------------------------------------------------
; 204 | Int16 USBSTK5515_ULED_toggle( Uint16 number )                          
;----------------------------------------------------------------------
;*******************************************************************************
;* FUNCTION NAME: USBSTK5515_ULED_toggle                                       *
;*                                                                             *
;*   Function Uses Regs : AC0,AC0,T0,T1,AR0,XAR0,AR1,SP,CARRY,M40,SATA,SATD,   *
;*                        RDM,FRCT,SMUL                                        *
;*   Stack Frame        : Compact (No Frame Pointer, w/ debug)                 *
;*   Total Frame Size   : 6 words                                              *
;*                        (2 return address/alignment)                         *
;*                        (4 local values)                                     *
;*   Min System Stack   : 1 word                                               *
;*******************************************************************************
_USBSTK5515_ULED_toggle:
	.dwcfi	cfa_offset, 1
	.dwcfi	save_reg_to_mem, 91, -1
        AADD #-5, SP
	.dwcfi	cfa_offset, 6
$C$DW$66	.dwtag  DW_TAG_variable, DW_AT_name("number")
	.dwattr $C$DW$66, DW_AT_TI_symbol_name("_number")
	.dwattr $C$DW$66, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$66, DW_AT_location[DW_OP_bregx 0x24 0]
$C$DW$67	.dwtag  DW_TAG_variable, DW_AT_name("led_state")
	.dwattr $C$DW$67, DW_AT_TI_symbol_name("_led_state")
	.dwattr $C$DW$67, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$67, DW_AT_location[DW_OP_bregx 0x24 1]
$C$DW$68	.dwtag  DW_TAG_variable, DW_AT_name("new_led_state")
	.dwattr $C$DW$68, DW_AT_TI_symbol_name("_new_led_state")
	.dwattr $C$DW$68, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$68, DW_AT_location[DW_OP_bregx 0x24 2]
$C$DW$69	.dwtag  DW_TAG_variable, DW_AT_name("led_bit_toggle")
	.dwattr $C$DW$69, DW_AT_TI_symbol_name("_led_bit_toggle")
	.dwattr $C$DW$69, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$69, DW_AT_location[DW_OP_bregx 0x24 3]
;----------------------------------------------------------------------
; 206 | Uint16 led_state;                                                      
; 207 | Uint16 new_led_state;                                                  
; 208 | Uint16 led_bit_toggle;                                                 
;----------------------------------------------------------------------
        MOV T0, *SP(#0) ; |205| 
	.dwpsn	file "../include/usbstk5515_led.c",line 211,column 5,is_stmt
;----------------------------------------------------------------------
; 211 | led_bit_toggle = 1 << ( 3 - number );                                  
;----------------------------------------------------------------------
        MOV #3, AR1

        SUB *SP(#0), AR1, T1 ; |211| 
||      MOV #1, AC0

        SFTS AC0, T1, AC0 ; |211| 
        MOV AC0, *SP(#3) ; |211| 
	.dwpsn	file "../include/usbstk5515_led.c",line 216,column 5,is_stmt
;----------------------------------------------------------------------
; 216 | if ( USBSTK5515_ULED_getall( &led_state ) )                            
;----------------------------------------------------------------------
        AMAR *SP(#1), XAR0
$C$DW$70	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$70, DW_AT_low_pc(0x00)
	.dwattr $C$DW$70, DW_AT_name("_USBSTK5515_ULED_getall")
	.dwattr $C$DW$70, DW_AT_TI_call
        CALL #_USBSTK5515_ULED_getall ; |216| 
                                        ; call occurs [#_USBSTK5515_ULED_getall] ; |216| 
        BCC $C$L15,T0 == #0 ; |216| 
                                        ; branchcc occurs ; |216| 
	.dwpsn	file "../include/usbstk5515_led.c",line 217,column 9,is_stmt
;----------------------------------------------------------------------
; 217 | return -1;                                                             
;----------------------------------------------------------------------
        MOV #-1, T0
        B $C$L19  ; |217| 
                                        ; branch occurs ; |217| 
$C$L15:    
	.dwpsn	file "../include/usbstk5515_led.c",line 219,column 5,is_stmt
;----------------------------------------------------------------------
; 219 | if ( ( led_state & led_bit_toggle ) == 0 )                             
;----------------------------------------------------------------------
        MOV *SP(#3), AR1 ; |219| 
        AND *SP(#1), AR1, AR1 ; |219| 
        BCC $C$L16,AR1 != #0 ; |219| 
                                        ; branchcc occurs ; |219| 
	.dwpsn	file "../include/usbstk5515_led.c",line 220,column 9,is_stmt
;----------------------------------------------------------------------
; 220 | new_led_state = led_state | led_bit_toggle;     /* Turn OFF */         
; 221 | else                                                                   
;----------------------------------------------------------------------
        MOV *SP(#3), AR1 ; |220| 
        OR *SP(#1), AR1, AR1 ; |220| 
        MOV AR1, *SP(#2) ; |220| 
        B $C$L17  ; |220| 
                                        ; branch occurs ; |220| 
$C$L16:    
	.dwpsn	file "../include/usbstk5515_led.c",line 222,column 9,is_stmt
;----------------------------------------------------------------------
; 222 | new_led_state = led_state & ~led_bit_toggle;    /* Turn ON */          
;----------------------------------------------------------------------
        MOV *SP(#3), AR1 ; |222| 
        NOT AR1, AR1 ; |222| 
        AND *SP(#1), AR1, AC0 ; |222| 
        MOV AC0, *SP(#2) ; |222| 
$C$L17:    
	.dwpsn	file "../include/usbstk5515_led.c",line 224,column 5,is_stmt
;----------------------------------------------------------------------
; 224 | if ( USBSTK5515_ULED_setall( new_led_state ) )                         
;----------------------------------------------------------------------
        MOV *SP(#2), T0 ; |224| 
$C$DW$71	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$71, DW_AT_low_pc(0x00)
	.dwattr $C$DW$71, DW_AT_name("_USBSTK5515_ULED_setall")
	.dwattr $C$DW$71, DW_AT_TI_call
        CALL #_USBSTK5515_ULED_setall ; |224| 
                                        ; call occurs [#_USBSTK5515_ULED_setall] ; |224| 
        BCC $C$L18,T0 == #0 ; |224| 
                                        ; branchcc occurs ; |224| 
	.dwpsn	file "../include/usbstk5515_led.c",line 225,column 9,is_stmt
;----------------------------------------------------------------------
; 225 | return -1;                                                             
;----------------------------------------------------------------------
        MOV #-1, T0
        B $C$L19  ; |225| 
                                        ; branch occurs ; |225| 
$C$L18:    
	.dwpsn	file "../include/usbstk5515_led.c",line 227,column 5,is_stmt
;----------------------------------------------------------------------
; 227 | return 0;                                                              
;----------------------------------------------------------------------
        MOV #0, T0
$C$L19:    
	.dwpsn	file "../include/usbstk5515_led.c",line 228,column 1,is_stmt
        AADD #5, SP
	.dwcfi	cfa_offset, 1
$C$DW$72	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$72, DW_AT_low_pc(0x00)
	.dwattr $C$DW$72, DW_AT_TI_return
        RET
                                        ; return occurs
	.dwattr $C$DW$64, DW_AT_TI_end_file("../include/usbstk5515_led.c")
	.dwattr $C$DW$64, DW_AT_TI_end_line(0xe4)
	.dwattr $C$DW$64, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$64

;******************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                              *
;******************************************************************************
	.global	_USBSTK5515_GPIO_setDirection
	.global	_USBSTK5515_GPIO_setOutput
	.global	_USBSTK5515_GPIO_getInput

;*******************************************************************************
;* TYPE INFORMATION                                                            *
;*******************************************************************************
$C$DW$T$4	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$4, DW_AT_encoding(DW_ATE_boolean)
	.dwattr $C$DW$T$4, DW_AT_name("bool")
	.dwattr $C$DW$T$4, DW_AT_byte_size(0x01)
$C$DW$T$5	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$5, DW_AT_encoding(DW_ATE_signed_char)
	.dwattr $C$DW$T$5, DW_AT_name("signed char")
	.dwattr $C$DW$T$5, DW_AT_byte_size(0x01)
$C$DW$T$6	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$6, DW_AT_encoding(DW_ATE_unsigned_char)
	.dwattr $C$DW$T$6, DW_AT_name("unsigned char")
	.dwattr $C$DW$T$6, DW_AT_byte_size(0x01)
$C$DW$T$7	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$7, DW_AT_encoding(DW_ATE_signed_char)
	.dwattr $C$DW$T$7, DW_AT_name("wchar_t")
	.dwattr $C$DW$T$7, DW_AT_byte_size(0x01)
$C$DW$T$8	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$8, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$8, DW_AT_name("short")
	.dwattr $C$DW$T$8, DW_AT_byte_size(0x01)
$C$DW$T$9	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$9, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$9, DW_AT_name("unsigned short")
	.dwattr $C$DW$T$9, DW_AT_byte_size(0x01)
$C$DW$T$24	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$24, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$T$24, DW_AT_address_class(0x17)
$C$DW$T$10	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$10, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$10, DW_AT_name("int")
	.dwattr $C$DW$T$10, DW_AT_byte_size(0x01)
$C$DW$T$11	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$11, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$11, DW_AT_name("unsigned int")
	.dwattr $C$DW$T$11, DW_AT_byte_size(0x01)
$C$DW$T$12	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$12, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$12, DW_AT_name("long")
	.dwattr $C$DW$T$12, DW_AT_byte_size(0x02)
$C$DW$T$13	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$13, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$13, DW_AT_name("unsigned long")
	.dwattr $C$DW$T$13, DW_AT_byte_size(0x02)
$C$DW$T$14	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$14, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$14, DW_AT_name("long long")
	.dwattr $C$DW$T$14, DW_AT_byte_size(0x04)
	.dwattr $C$DW$T$14, DW_AT_bit_size(0x28)
	.dwattr $C$DW$T$14, DW_AT_bit_offset(0x18)
$C$DW$T$15	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$15, DW_AT_encoding(DW_ATE_unsigned)
	.dwattr $C$DW$T$15, DW_AT_name("unsigned long long")
	.dwattr $C$DW$T$15, DW_AT_byte_size(0x04)
	.dwattr $C$DW$T$15, DW_AT_bit_size(0x28)
	.dwattr $C$DW$T$15, DW_AT_bit_offset(0x18)
$C$DW$T$16	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$16, DW_AT_encoding(DW_ATE_float)
	.dwattr $C$DW$T$16, DW_AT_name("float")
	.dwattr $C$DW$T$16, DW_AT_byte_size(0x02)
$C$DW$T$17	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$17, DW_AT_encoding(DW_ATE_float)
	.dwattr $C$DW$T$17, DW_AT_name("double")
	.dwattr $C$DW$T$17, DW_AT_byte_size(0x02)
$C$DW$T$18	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$18, DW_AT_encoding(DW_ATE_float)
	.dwattr $C$DW$T$18, DW_AT_name("long double")
	.dwattr $C$DW$T$18, DW_AT_byte_size(0x02)
	.dwattr $C$DW$CU, DW_AT_language(DW_LANG_C)

;***************************************************************
;* DWARF CIE ENTRIES                                           *
;***************************************************************

$C$DW$CIE	.dwcie 91
	.dwcfi	cfa_register, 36
	.dwcfi	cfa_offset, 0
	.dwcfi	undefined, 0
	.dwcfi	undefined, 1
	.dwcfi	undefined, 2
	.dwcfi	undefined, 3
	.dwcfi	undefined, 4
	.dwcfi	undefined, 5
	.dwcfi	undefined, 6
	.dwcfi	undefined, 7
	.dwcfi	undefined, 8
	.dwcfi	undefined, 9
	.dwcfi	undefined, 10
	.dwcfi	undefined, 11
	.dwcfi	undefined, 12
	.dwcfi	undefined, 13
	.dwcfi	same_value, 14
	.dwcfi	same_value, 15
	.dwcfi	undefined, 16
	.dwcfi	undefined, 17
	.dwcfi	undefined, 18
	.dwcfi	undefined, 19
	.dwcfi	undefined, 20
	.dwcfi	undefined, 21
	.dwcfi	undefined, 22
	.dwcfi	undefined, 23
	.dwcfi	undefined, 24
	.dwcfi	undefined, 25
	.dwcfi	same_value, 26
	.dwcfi	same_value, 27
	.dwcfi	same_value, 28
	.dwcfi	same_value, 29
	.dwcfi	same_value, 30
	.dwcfi	same_value, 31
	.dwcfi	undefined, 32
	.dwcfi	undefined, 33
	.dwcfi	undefined, 34
	.dwcfi	undefined, 35
	.dwcfi	undefined, 36
	.dwcfi	undefined, 37
	.dwcfi	undefined, 38
	.dwcfi	undefined, 39
	.dwcfi	undefined, 40
	.dwcfi	undefined, 41
	.dwcfi	undefined, 42
	.dwcfi	undefined, 43
	.dwcfi	undefined, 44
	.dwcfi	undefined, 45
	.dwcfi	undefined, 46
	.dwcfi	undefined, 47
	.dwcfi	undefined, 48
	.dwcfi	undefined, 49
	.dwcfi	undefined, 50
	.dwcfi	undefined, 51
	.dwcfi	undefined, 52
	.dwcfi	undefined, 53
	.dwcfi	undefined, 54
	.dwcfi	undefined, 55
	.dwcfi	undefined, 56
	.dwcfi	undefined, 57
	.dwcfi	undefined, 58
	.dwcfi	undefined, 59
	.dwcfi	undefined, 60
	.dwcfi	undefined, 61
	.dwcfi	undefined, 62
	.dwcfi	undefined, 63
	.dwcfi	undefined, 64
	.dwcfi	undefined, 65
	.dwcfi	undefined, 66
	.dwcfi	undefined, 67
	.dwcfi	undefined, 68
	.dwcfi	undefined, 69
	.dwcfi	undefined, 70
	.dwcfi	undefined, 71
	.dwcfi	undefined, 72
	.dwcfi	undefined, 73
	.dwcfi	undefined, 74
	.dwcfi	undefined, 75
	.dwcfi	undefined, 76
	.dwcfi	undefined, 77
	.dwcfi	undefined, 78
	.dwcfi	undefined, 79
	.dwcfi	undefined, 80
	.dwcfi	undefined, 81
	.dwcfi	undefined, 82
	.dwcfi	undefined, 83
	.dwcfi	undefined, 84
	.dwcfi	undefined, 85
	.dwcfi	undefined, 86
	.dwcfi	undefined, 87
	.dwcfi	undefined, 88
	.dwcfi	undefined, 89
	.dwcfi	undefined, 90
	.dwcfi	undefined, 91
	.dwendentry

;***************************************************************
;* DWARF REGISTER MAP                                          *
;***************************************************************

$C$DW$73	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC0")
	.dwattr $C$DW$73, DW_AT_location[DW_OP_reg0]
$C$DW$74	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC0")
	.dwattr $C$DW$74, DW_AT_location[DW_OP_reg1]
$C$DW$75	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC0_G")
	.dwattr $C$DW$75, DW_AT_location[DW_OP_reg2]
$C$DW$76	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC1")
	.dwattr $C$DW$76, DW_AT_location[DW_OP_reg3]
$C$DW$77	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC1")
	.dwattr $C$DW$77, DW_AT_location[DW_OP_reg4]
$C$DW$78	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC1_G")
	.dwattr $C$DW$78, DW_AT_location[DW_OP_reg5]
$C$DW$79	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC2")
	.dwattr $C$DW$79, DW_AT_location[DW_OP_reg6]
$C$DW$80	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC2")
	.dwattr $C$DW$80, DW_AT_location[DW_OP_reg7]
$C$DW$81	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC2_G")
	.dwattr $C$DW$81, DW_AT_location[DW_OP_reg8]
$C$DW$82	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC3")
	.dwattr $C$DW$82, DW_AT_location[DW_OP_reg9]
$C$DW$83	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC3")
	.dwattr $C$DW$83, DW_AT_location[DW_OP_reg10]
$C$DW$84	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC3_G")
	.dwattr $C$DW$84, DW_AT_location[DW_OP_reg11]
$C$DW$85	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("T0")
	.dwattr $C$DW$85, DW_AT_location[DW_OP_reg12]
$C$DW$86	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("T1")
	.dwattr $C$DW$86, DW_AT_location[DW_OP_reg13]
$C$DW$87	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("T2")
	.dwattr $C$DW$87, DW_AT_location[DW_OP_reg14]
$C$DW$88	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("T3")
	.dwattr $C$DW$88, DW_AT_location[DW_OP_reg15]
$C$DW$89	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR0")
	.dwattr $C$DW$89, DW_AT_location[DW_OP_reg16]
$C$DW$90	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR0")
	.dwattr $C$DW$90, DW_AT_location[DW_OP_reg17]
$C$DW$91	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR1")
	.dwattr $C$DW$91, DW_AT_location[DW_OP_reg18]
$C$DW$92	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR1")
	.dwattr $C$DW$92, DW_AT_location[DW_OP_reg19]
$C$DW$93	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR2")
	.dwattr $C$DW$93, DW_AT_location[DW_OP_reg20]
$C$DW$94	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR2")
	.dwattr $C$DW$94, DW_AT_location[DW_OP_reg21]
$C$DW$95	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR3")
	.dwattr $C$DW$95, DW_AT_location[DW_OP_reg22]
$C$DW$96	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR3")
	.dwattr $C$DW$96, DW_AT_location[DW_OP_reg23]
$C$DW$97	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR4")
	.dwattr $C$DW$97, DW_AT_location[DW_OP_reg24]
$C$DW$98	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR4")
	.dwattr $C$DW$98, DW_AT_location[DW_OP_reg25]
$C$DW$99	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR5")
	.dwattr $C$DW$99, DW_AT_location[DW_OP_reg26]
$C$DW$100	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR5")
	.dwattr $C$DW$100, DW_AT_location[DW_OP_reg27]
$C$DW$101	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR6")
	.dwattr $C$DW$101, DW_AT_location[DW_OP_reg28]
$C$DW$102	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR6")
	.dwattr $C$DW$102, DW_AT_location[DW_OP_reg29]
$C$DW$103	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR7")
	.dwattr $C$DW$103, DW_AT_location[DW_OP_reg30]
$C$DW$104	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR7")
	.dwattr $C$DW$104, DW_AT_location[DW_OP_reg31]
$C$DW$105	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("FP")
	.dwattr $C$DW$105, DW_AT_location[DW_OP_regx 0x20]
$C$DW$106	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XFP")
	.dwattr $C$DW$106, DW_AT_location[DW_OP_regx 0x21]
$C$DW$107	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("PC")
	.dwattr $C$DW$107, DW_AT_location[DW_OP_regx 0x22]
$C$DW$108	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("SP")
	.dwattr $C$DW$108, DW_AT_location[DW_OP_regx 0x23]
$C$DW$109	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XSP")
	.dwattr $C$DW$109, DW_AT_location[DW_OP_regx 0x24]
$C$DW$110	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BKC")
	.dwattr $C$DW$110, DW_AT_location[DW_OP_regx 0x25]
$C$DW$111	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BK03")
	.dwattr $C$DW$111, DW_AT_location[DW_OP_regx 0x26]
$C$DW$112	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BK47")
	.dwattr $C$DW$112, DW_AT_location[DW_OP_regx 0x27]
$C$DW$113	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ST0")
	.dwattr $C$DW$113, DW_AT_location[DW_OP_regx 0x28]
$C$DW$114	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ST1")
	.dwattr $C$DW$114, DW_AT_location[DW_OP_regx 0x29]
$C$DW$115	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ST2")
	.dwattr $C$DW$115, DW_AT_location[DW_OP_regx 0x2a]
$C$DW$116	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ST3")
	.dwattr $C$DW$116, DW_AT_location[DW_OP_regx 0x2b]
$C$DW$117	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("MDP")
	.dwattr $C$DW$117, DW_AT_location[DW_OP_regx 0x2c]
$C$DW$118	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("MDP05")
	.dwattr $C$DW$118, DW_AT_location[DW_OP_regx 0x2d]
$C$DW$119	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("MDP67")
	.dwattr $C$DW$119, DW_AT_location[DW_OP_regx 0x2e]
$C$DW$120	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BRC0")
	.dwattr $C$DW$120, DW_AT_location[DW_OP_regx 0x2f]
$C$DW$121	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RSA0")
	.dwattr $C$DW$121, DW_AT_location[DW_OP_regx 0x30]
$C$DW$122	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RSA0_H")
	.dwattr $C$DW$122, DW_AT_location[DW_OP_regx 0x31]
$C$DW$123	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("REA0")
	.dwattr $C$DW$123, DW_AT_location[DW_OP_regx 0x32]
$C$DW$124	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("REA0_H")
	.dwattr $C$DW$124, DW_AT_location[DW_OP_regx 0x33]
$C$DW$125	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BRS1")
	.dwattr $C$DW$125, DW_AT_location[DW_OP_regx 0x34]
$C$DW$126	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BRC1")
	.dwattr $C$DW$126, DW_AT_location[DW_OP_regx 0x35]
$C$DW$127	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RSA1")
	.dwattr $C$DW$127, DW_AT_location[DW_OP_regx 0x36]
$C$DW$128	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RSA1_H")
	.dwattr $C$DW$128, DW_AT_location[DW_OP_regx 0x37]
$C$DW$129	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("REA1")
	.dwattr $C$DW$129, DW_AT_location[DW_OP_regx 0x38]
$C$DW$130	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("REA1_H")
	.dwattr $C$DW$130, DW_AT_location[DW_OP_regx 0x39]
$C$DW$131	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CSR")
	.dwattr $C$DW$131, DW_AT_location[DW_OP_regx 0x3a]
$C$DW$132	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RPTC")
	.dwattr $C$DW$132, DW_AT_location[DW_OP_regx 0x3b]
$C$DW$133	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CDP")
	.dwattr $C$DW$133, DW_AT_location[DW_OP_regx 0x3c]
$C$DW$134	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XCDP")
	.dwattr $C$DW$134, DW_AT_location[DW_OP_regx 0x3d]
$C$DW$135	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TRN0")
	.dwattr $C$DW$135, DW_AT_location[DW_OP_regx 0x3e]
$C$DW$136	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TRN1")
	.dwattr $C$DW$136, DW_AT_location[DW_OP_regx 0x3f]
$C$DW$137	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BSA01")
	.dwattr $C$DW$137, DW_AT_location[DW_OP_regx 0x40]
$C$DW$138	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BSA23")
	.dwattr $C$DW$138, DW_AT_location[DW_OP_regx 0x41]
$C$DW$139	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BSA45")
	.dwattr $C$DW$139, DW_AT_location[DW_OP_regx 0x42]
$C$DW$140	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BSA67")
	.dwattr $C$DW$140, DW_AT_location[DW_OP_regx 0x43]
$C$DW$141	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BSAC")
	.dwattr $C$DW$141, DW_AT_location[DW_OP_regx 0x44]
$C$DW$142	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CARRY")
	.dwattr $C$DW$142, DW_AT_location[DW_OP_regx 0x45]
$C$DW$143	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TC1")
	.dwattr $C$DW$143, DW_AT_location[DW_OP_regx 0x46]
$C$DW$144	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TC2")
	.dwattr $C$DW$144, DW_AT_location[DW_OP_regx 0x47]
$C$DW$145	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("M40")
	.dwattr $C$DW$145, DW_AT_location[DW_OP_regx 0x48]
$C$DW$146	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("SXMD")
	.dwattr $C$DW$146, DW_AT_location[DW_OP_regx 0x49]
$C$DW$147	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ARMS")
	.dwattr $C$DW$147, DW_AT_location[DW_OP_regx 0x4a]
$C$DW$148	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("C54CM")
	.dwattr $C$DW$148, DW_AT_location[DW_OP_regx 0x4b]
$C$DW$149	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("SATA")
	.dwattr $C$DW$149, DW_AT_location[DW_OP_regx 0x4c]
$C$DW$150	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("SATD")
	.dwattr $C$DW$150, DW_AT_location[DW_OP_regx 0x4d]
$C$DW$151	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RDM")
	.dwattr $C$DW$151, DW_AT_location[DW_OP_regx 0x4e]
$C$DW$152	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("FRCT")
	.dwattr $C$DW$152, DW_AT_location[DW_OP_regx 0x4f]
$C$DW$153	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("SMUL")
	.dwattr $C$DW$153, DW_AT_location[DW_OP_regx 0x50]
$C$DW$154	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("INTM")
	.dwattr $C$DW$154, DW_AT_location[DW_OP_regx 0x51]
$C$DW$155	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR0LC")
	.dwattr $C$DW$155, DW_AT_location[DW_OP_regx 0x52]
$C$DW$156	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR1LC")
	.dwattr $C$DW$156, DW_AT_location[DW_OP_regx 0x53]
$C$DW$157	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR2LC")
	.dwattr $C$DW$157, DW_AT_location[DW_OP_regx 0x54]
$C$DW$158	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR3LC")
	.dwattr $C$DW$158, DW_AT_location[DW_OP_regx 0x55]
$C$DW$159	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR4LC")
	.dwattr $C$DW$159, DW_AT_location[DW_OP_regx 0x56]
$C$DW$160	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR5LC")
	.dwattr $C$DW$160, DW_AT_location[DW_OP_regx 0x57]
$C$DW$161	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR6LC")
	.dwattr $C$DW$161, DW_AT_location[DW_OP_regx 0x58]
$C$DW$162	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR7LC")
	.dwattr $C$DW$162, DW_AT_location[DW_OP_regx 0x59]
$C$DW$163	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CDPLC")
	.dwattr $C$DW$163, DW_AT_location[DW_OP_regx 0x5a]
$C$DW$164	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CIE_RETA")
	.dwattr $C$DW$164, DW_AT_location[DW_OP_regx 0x5b]
	.dwendtag $C$DW$CU

