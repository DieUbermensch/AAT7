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
	.dwattr $C$DW$CU, DW_AT_name("../include/usbstk5515_i2c.c")
	.dwattr $C$DW$CU, DW_AT_producer("TMS320C55x C/C++ Codegen PC v4.3.8 Copyright (c) 1996-2010 Texas Instruments Incorporated")
	.dwattr $C$DW$CU, DW_AT_TI_version(0x01)
	.dwattr $C$DW$CU, DW_AT_comp_dir("C:\Users\Kiis\Dropbox\Uni\7. semester\AAT7\Code\DSP\aic3204\Debug")
;******************************************************************************
;* CINIT RECORDS                                                              *
;******************************************************************************
	.sect	".cinit"
	.align	1
	.field  	1,16
	.field  	_i2c_timeout+0,24
	.field  	0,8
	.field  	4095,16			; _i2c_timeout @ 0


$C$DW$1	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_wait")
	.dwattr $C$DW$1, DW_AT_TI_symbol_name("_USBSTK5515_wait")
	.dwattr $C$DW$1, DW_AT_declaration
	.dwattr $C$DW$1, DW_AT_external
	.dwattr $C$DW$1, DW_AT_decl_file("..\include\usbstk5515.h")
	.dwattr $C$DW$1, DW_AT_decl_line(0x6d)
	.dwattr $C$DW$1, DW_AT_decl_column(0x06)
$C$DW$2	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$2, DW_AT_type(*$C$DW$T$13)
	.dwendtag $C$DW$1


$C$DW$3	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_waitusec")
	.dwattr $C$DW$3, DW_AT_TI_symbol_name("_USBSTK5515_waitusec")
	.dwattr $C$DW$3, DW_AT_declaration
	.dwattr $C$DW$3, DW_AT_external
	.dwattr $C$DW$3, DW_AT_decl_file("..\include\usbstk5515.h")
	.dwattr $C$DW$3, DW_AT_decl_line(0x6e)
	.dwattr $C$DW$3, DW_AT_decl_column(0x06)
$C$DW$4	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$4, DW_AT_type(*$C$DW$T$13)
	.dwendtag $C$DW$3


$C$DW$5	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_GPIO_setOutput")
	.dwattr $C$DW$5, DW_AT_TI_symbol_name("_USBSTK5515_GPIO_setOutput")
	.dwattr $C$DW$5, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$5, DW_AT_declaration
	.dwattr $C$DW$5, DW_AT_external
	.dwattr $C$DW$5, DW_AT_decl_file("..\include\usbstk5515_gpio.h")
	.dwattr $C$DW$5, DW_AT_decl_line(0x3d)
	.dwattr $C$DW$5, DW_AT_decl_column(0x07)
$C$DW$6	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$6, DW_AT_type(*$C$DW$T$9)
$C$DW$7	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$7, DW_AT_type(*$C$DW$T$9)
	.dwendtag $C$DW$5

	.global	_i2c_timeout
	.bss	_i2c_timeout,1,0,0
$C$DW$8	.dwtag  DW_TAG_variable, DW_AT_name("i2c_timeout")
	.dwattr $C$DW$8, DW_AT_TI_symbol_name("_i2c_timeout")
	.dwattr $C$DW$8, DW_AT_location[DW_OP_addr _i2c_timeout]
	.dwattr $C$DW$8, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$8, DW_AT_external
	.dwattr $C$DW$8, DW_AT_decl_file("../include/usbstk5515_i2c.c")
	.dwattr $C$DW$8, DW_AT_decl_line(0x0c)
	.dwattr $C$DW$8, DW_AT_decl_column(0x07)
;	C:\Program Files\TexasInstruments\ccsv4\tools\compiler\c5500\bin\acp55.exe -@C:\Users\Kiis\AppData\Local\Temp\1198812 
	.sect	".text"
	.global	_USBSTK5515_I2C_init

$C$DW$9	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_I2C_init")
	.dwattr $C$DW$9, DW_AT_low_pc(_USBSTK5515_I2C_init)
	.dwattr $C$DW$9, DW_AT_high_pc(0x00)
	.dwattr $C$DW$9, DW_AT_TI_symbol_name("_USBSTK5515_I2C_init")
	.dwattr $C$DW$9, DW_AT_external
	.dwattr $C$DW$9, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$9, DW_AT_TI_begin_file("../include/usbstk5515_i2c.c")
	.dwattr $C$DW$9, DW_AT_TI_begin_line(0x16)
	.dwattr $C$DW$9, DW_AT_TI_begin_column(0x07)
	.dwattr $C$DW$9, DW_AT_decl_file("../include/usbstk5515_i2c.c")
	.dwattr $C$DW$9, DW_AT_decl_line(0x16)
	.dwattr $C$DW$9, DW_AT_decl_column(0x07)
	.dwattr $C$DW$9, DW_AT_TI_max_frame_size(0x01)
	.dwpsn	file "../include/usbstk5515_i2c.c",line 23,column 1,is_stmt,address _USBSTK5515_I2C_init

	.dwfde $C$DW$CIE, _USBSTK5515_I2C_init
;----------------------------------------------------------------------
;  22 | Int16 USBSTK5515_I2C_init( )                                           
;----------------------------------------------------------------------
;*******************************************************************************
;* FUNCTION NAME: USBSTK5515_I2C_init                                          *
;*                                                                             *
;*   Function Uses Regs : T0,SP,M40,SATA,SATD,RDM,FRCT,SMUL                    *
;*   Stack Frame        : Compact (No Frame Pointer, w/ debug)                 *
;*   Total Frame Size   : 1 word                                               *
;*                        (1 return address/alignment)                         *
;*   Min System Stack   : 1 word                                               *
;*******************************************************************************
_USBSTK5515_I2C_init:
	.dwcfi	cfa_offset, 1
	.dwcfi	save_reg_to_mem, 91, -1
	.dwpsn	file "../include/usbstk5515_i2c.c",line 24,column 5,is_stmt
;----------------------------------------------------------------------
;  24 | I2C_MDR = 0x0400;             // Reset I2C                             
;----------------------------------------------------------------------
        MOV #1024, *port(#6692) ; |24| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 25,column 5,is_stmt
;----------------------------------------------------------------------
;  25 | I2C_PSC   = 15;               // Config prescaler for 100MHz           
;----------------------------------------------------------------------
        MOV #15, *port(#6704) ; |25| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 26,column 5,is_stmt
;----------------------------------------------------------------------
;  26 | I2C_CLKL  = 25;               // Config clk LOW for 100kHz             
;----------------------------------------------------------------------
        MOV #25, *port(#6668) ; |26| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 27,column 5,is_stmt
;----------------------------------------------------------------------
;  27 | I2C_CLKH  = 25;               // Config clk HIGH for 100kHz            
;----------------------------------------------------------------------
        MOV #25, *port(#6672) ; |27| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 29,column 5,is_stmt
;----------------------------------------------------------------------
;  29 | I2C_MDR   = 0x0420   ;        // Release from reset; Master, Transmitte
;     | r, 7-bit address                                                       
;----------------------------------------------------------------------
        MOV #1056, *port(#6692) ; |29| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 31,column 5,is_stmt
;----------------------------------------------------------------------
;  31 | return 0;                                                              
;----------------------------------------------------------------------
        MOV #0, T0
	.dwpsn	file "../include/usbstk5515_i2c.c",line 32,column 1,is_stmt
$C$DW$10	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$10, DW_AT_low_pc(0x00)
	.dwattr $C$DW$10, DW_AT_TI_return
        RET
                                        ; return occurs
	.dwattr $C$DW$9, DW_AT_TI_end_file("../include/usbstk5515_i2c.c")
	.dwattr $C$DW$9, DW_AT_TI_end_line(0x20)
	.dwattr $C$DW$9, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$9

	.sect	".text"
	.global	_USBSTK5515_I2C_close

$C$DW$11	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_I2C_close")
	.dwattr $C$DW$11, DW_AT_low_pc(_USBSTK5515_I2C_close)
	.dwattr $C$DW$11, DW_AT_high_pc(0x00)
	.dwattr $C$DW$11, DW_AT_TI_symbol_name("_USBSTK5515_I2C_close")
	.dwattr $C$DW$11, DW_AT_external
	.dwattr $C$DW$11, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$11, DW_AT_TI_begin_file("../include/usbstk5515_i2c.c")
	.dwattr $C$DW$11, DW_AT_TI_begin_line(0x27)
	.dwattr $C$DW$11, DW_AT_TI_begin_column(0x07)
	.dwattr $C$DW$11, DW_AT_decl_file("../include/usbstk5515_i2c.c")
	.dwattr $C$DW$11, DW_AT_decl_line(0x27)
	.dwattr $C$DW$11, DW_AT_decl_column(0x07)
	.dwattr $C$DW$11, DW_AT_TI_max_frame_size(0x01)
	.dwpsn	file "../include/usbstk5515_i2c.c",line 40,column 1,is_stmt,address _USBSTK5515_I2C_close

	.dwfde $C$DW$CIE, _USBSTK5515_I2C_close
;----------------------------------------------------------------------
;  39 | Int16 USBSTK5515_I2C_close( )                                          
;----------------------------------------------------------------------
;*******************************************************************************
;* FUNCTION NAME: USBSTK5515_I2C_close                                         *
;*                                                                             *
;*   Function Uses Regs : T0,SP,M40,SATA,SATD,RDM,FRCT,SMUL                    *
;*   Stack Frame        : Compact (No Frame Pointer, w/ debug)                 *
;*   Total Frame Size   : 1 word                                               *
;*                        (1 return address/alignment)                         *
;*   Min System Stack   : 1 word                                               *
;*******************************************************************************
_USBSTK5515_I2C_close:
	.dwcfi	cfa_offset, 1
	.dwcfi	save_reg_to_mem, 91, -1
	.dwpsn	file "../include/usbstk5515_i2c.c",line 41,column 5,is_stmt
;----------------------------------------------------------------------
;  41 | I2C_MDR = 0;                      // Reset I2C                         
;----------------------------------------------------------------------
        MOV #0, *port(#6692) ; |41| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 42,column 5,is_stmt
;----------------------------------------------------------------------
;  42 | return 0;                                                              
;----------------------------------------------------------------------
        MOV #0, T0
	.dwpsn	file "../include/usbstk5515_i2c.c",line 43,column 1,is_stmt
$C$DW$12	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$12, DW_AT_low_pc(0x00)
	.dwattr $C$DW$12, DW_AT_TI_return
        RET
                                        ; return occurs
	.dwattr $C$DW$11, DW_AT_TI_end_file("../include/usbstk5515_i2c.c")
	.dwattr $C$DW$11, DW_AT_TI_end_line(0x2b)
	.dwattr $C$DW$11, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$11

	.sect	".text"
	.global	_USBSTK5515_I2C_reset

$C$DW$13	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_I2C_reset")
	.dwattr $C$DW$13, DW_AT_low_pc(_USBSTK5515_I2C_reset)
	.dwattr $C$DW$13, DW_AT_high_pc(0x00)
	.dwattr $C$DW$13, DW_AT_TI_symbol_name("_USBSTK5515_I2C_reset")
	.dwattr $C$DW$13, DW_AT_external
	.dwattr $C$DW$13, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$13, DW_AT_TI_begin_file("../include/usbstk5515_i2c.c")
	.dwattr $C$DW$13, DW_AT_TI_begin_line(0x32)
	.dwattr $C$DW$13, DW_AT_TI_begin_column(0x07)
	.dwattr $C$DW$13, DW_AT_decl_file("../include/usbstk5515_i2c.c")
	.dwattr $C$DW$13, DW_AT_decl_line(0x32)
	.dwattr $C$DW$13, DW_AT_decl_column(0x07)
	.dwattr $C$DW$13, DW_AT_TI_max_frame_size(0x02)
	.dwpsn	file "../include/usbstk5515_i2c.c",line 51,column 1,is_stmt,address _USBSTK5515_I2C_reset

	.dwfde $C$DW$CIE, _USBSTK5515_I2C_reset
;----------------------------------------------------------------------
;  50 | Int16 USBSTK5515_I2C_reset( )                                          
;----------------------------------------------------------------------
;*******************************************************************************
;* FUNCTION NAME: USBSTK5515_I2C_reset                                         *
;*                                                                             *
;*   Function Uses Regs : T0,SP,M40,SATA,SATD,RDM,FRCT,SMUL                    *
;*   Stack Frame        : Compact (No Frame Pointer, w/ debug)                 *
;*   Total Frame Size   : 2 words                                              *
;*                        (2 return address/alignment)                         *
;*   Min System Stack   : 1 word                                               *
;*******************************************************************************
_USBSTK5515_I2C_reset:
	.dwcfi	cfa_offset, 1
	.dwcfi	save_reg_to_mem, 91, -1
        AADD #-1, SP
	.dwcfi	cfa_offset, 2
	.dwpsn	file "../include/usbstk5515_i2c.c",line 52,column 5,is_stmt
;----------------------------------------------------------------------
;  52 | USBSTK5515_I2C_close( );                                               
;----------------------------------------------------------------------
$C$DW$14	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$14, DW_AT_low_pc(0x00)
	.dwattr $C$DW$14, DW_AT_name("_USBSTK5515_I2C_close")
	.dwattr $C$DW$14, DW_AT_TI_call
        CALL #_USBSTK5515_I2C_close ; |52| 
                                        ; call occurs [#_USBSTK5515_I2C_close] ; |52| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 53,column 5,is_stmt
;----------------------------------------------------------------------
;  53 | USBSTK5515_I2C_init( );                                                
;----------------------------------------------------------------------
$C$DW$15	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$15, DW_AT_low_pc(0x00)
	.dwattr $C$DW$15, DW_AT_name("_USBSTK5515_I2C_init")
	.dwattr $C$DW$15, DW_AT_TI_call
        CALL #_USBSTK5515_I2C_init ; |53| 
                                        ; call occurs [#_USBSTK5515_I2C_init] ; |53| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 54,column 5,is_stmt
;----------------------------------------------------------------------
;  54 | return 0;                                                              
;----------------------------------------------------------------------
        MOV #0, T0
	.dwpsn	file "../include/usbstk5515_i2c.c",line 55,column 1,is_stmt
        AADD #1, SP
	.dwcfi	cfa_offset, 1
$C$DW$16	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$16, DW_AT_low_pc(0x00)
	.dwattr $C$DW$16, DW_AT_TI_return
        RET
                                        ; return occurs
	.dwattr $C$DW$13, DW_AT_TI_end_file("../include/usbstk5515_i2c.c")
	.dwattr $C$DW$13, DW_AT_TI_end_line(0x37)
	.dwattr $C$DW$13, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$13

	.sect	".text"
	.global	_USBSTK5515_I2C_write

$C$DW$17	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_I2C_write")
	.dwattr $C$DW$17, DW_AT_low_pc(_USBSTK5515_I2C_write)
	.dwattr $C$DW$17, DW_AT_high_pc(0x00)
	.dwattr $C$DW$17, DW_AT_TI_symbol_name("_USBSTK5515_I2C_write")
	.dwattr $C$DW$17, DW_AT_external
	.dwattr $C$DW$17, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$17, DW_AT_TI_begin_file("../include/usbstk5515_i2c.c")
	.dwattr $C$DW$17, DW_AT_TI_begin_line(0x44)
	.dwattr $C$DW$17, DW_AT_TI_begin_column(0x07)
	.dwattr $C$DW$17, DW_AT_decl_file("../include/usbstk5515_i2c.c")
	.dwattr $C$DW$17, DW_AT_decl_line(0x44)
	.dwattr $C$DW$17, DW_AT_decl_column(0x07)
	.dwattr $C$DW$17, DW_AT_TI_max_frame_size(0x08)
	.dwpsn	file "../include/usbstk5515_i2c.c",line 69,column 1,is_stmt,address _USBSTK5515_I2C_write

	.dwfde $C$DW$CIE, _USBSTK5515_I2C_write
$C$DW$18	.dwtag  DW_TAG_formal_parameter, DW_AT_name("i2c_addr")
	.dwattr $C$DW$18, DW_AT_TI_symbol_name("_i2c_addr")
	.dwattr $C$DW$18, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$18, DW_AT_location[DW_OP_reg12]
$C$DW$19	.dwtag  DW_TAG_formal_parameter, DW_AT_name("data")
	.dwattr $C$DW$19, DW_AT_TI_symbol_name("_data")
	.dwattr $C$DW$19, DW_AT_type(*$C$DW$T$21)
	.dwattr $C$DW$19, DW_AT_location[DW_OP_reg17]
$C$DW$20	.dwtag  DW_TAG_formal_parameter, DW_AT_name("len")
	.dwattr $C$DW$20, DW_AT_TI_symbol_name("_len")
	.dwattr $C$DW$20, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$20, DW_AT_location[DW_OP_reg13]
;----------------------------------------------------------------------
;  68 | Int16 USBSTK5515_I2C_write( Uint16 i2c_addr, Uint8* data, Uint16 len ) 
;----------------------------------------------------------------------
;*******************************************************************************
;* FUNCTION NAME: USBSTK5515_I2C_write                                         *
;*                                                                             *
;*   Function Uses Regs : AC0,AC0,T0,T1,AR0,XAR0,AR1,AR2,AR3,XAR3,SP,CARRY,TC1,*
;*                        M40,SATA,SATD,RDM,FRCT,SMUL                          *
;*   Stack Frame        : Compact (No Frame Pointer, w/ debug)                 *
;*   Total Frame Size   : 8 words                                              *
;*                        (1 return address/alignment)                         *
;*                        (7 local values)                                     *
;*   Min System Stack   : 1 word                                               *
;*******************************************************************************
_USBSTK5515_I2C_write:
	.dwcfi	cfa_offset, 1
	.dwcfi	save_reg_to_mem, 91, -1
        AADD #-7, SP
	.dwcfi	cfa_offset, 8
$C$DW$21	.dwtag  DW_TAG_variable, DW_AT_name("i2c_addr")
	.dwattr $C$DW$21, DW_AT_TI_symbol_name("_i2c_addr")
	.dwattr $C$DW$21, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$21, DW_AT_location[DW_OP_bregx 0x24 0]
$C$DW$22	.dwtag  DW_TAG_variable, DW_AT_name("data")
	.dwattr $C$DW$22, DW_AT_TI_symbol_name("_data")
	.dwattr $C$DW$22, DW_AT_type(*$C$DW$T$21)
	.dwattr $C$DW$22, DW_AT_location[DW_OP_bregx 0x24 2]
$C$DW$23	.dwtag  DW_TAG_variable, DW_AT_name("len")
	.dwattr $C$DW$23, DW_AT_TI_symbol_name("_len")
	.dwattr $C$DW$23, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$23, DW_AT_location[DW_OP_bregx 0x24 4]
$C$DW$24	.dwtag  DW_TAG_variable, DW_AT_name("timeout")
	.dwattr $C$DW$24, DW_AT_TI_symbol_name("_timeout")
	.dwattr $C$DW$24, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$24, DW_AT_location[DW_OP_bregx 0x24 5]
$C$DW$25	.dwtag  DW_TAG_variable, DW_AT_name("i")
	.dwattr $C$DW$25, DW_AT_TI_symbol_name("_i")
	.dwattr $C$DW$25, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$25, DW_AT_location[DW_OP_bregx 0x24 6]
;----------------------------------------------------------------------
;  70 | Int16 timeout, i;                                                      
;  72 |             //I2C_IER = 0x0000;                                        
;----------------------------------------------------------------------
        MOV T1, *SP(#4) ; |69| 
        MOV XAR0, dbl(*SP(#2))
        MOV T0, *SP(#0) ; |69| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 73,column 9,is_stmt
;----------------------------------------------------------------------
;  73 | I2C_CNT = len;                    // Set length                        
;----------------------------------------------------------------------
        MOV *SP(#4), AR1 ; |73| 
        MOV AR1, *port(#6676) ; |73| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 74,column 9,is_stmt
;----------------------------------------------------------------------
;  74 | I2C_SAR = i2c_addr;               // Set I2C slave address             
;----------------------------------------------------------------------
        MOV T0, AR1
        MOV AR1, *port(#6684) ; |74| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 75,column 9,is_stmt
;----------------------------------------------------------------------
;  75 | I2C_MDR = MDR_STT                 // Set for Master Write              
;  76 |           | MDR_TRX                                                    
;  77 |           | MDR_MST                                                    
;  78 |           | MDR_IRS                                                    
;  79 |           | MDR_FREE;                                                  
;----------------------------------------------------------------------
        MOV #26144, *port(#6692) ; |75| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 81,column 9,is_stmt
;----------------------------------------------------------------------
;  81 | USBSTK5515_wait(100);              // Short delay                      
;----------------------------------------------------------------------
        MOV #100, AC0 ; |81| 
$C$DW$26	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$26, DW_AT_low_pc(0x00)
	.dwattr $C$DW$26, DW_AT_name("_USBSTK5515_wait")
	.dwattr $C$DW$26, DW_AT_TI_call
        CALL #_USBSTK5515_wait ; |81| 
                                        ; call occurs [#_USBSTK5515_wait] ; |81| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 83,column 15,is_stmt
;----------------------------------------------------------------------
;  83 | for ( i = 0 ; i < len ; i++ )                                          
;----------------------------------------------------------------------
        MOV #0, *SP(#6) ; |83| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 83,column 23,is_stmt
        MOV *SP(#6), AR2 ; |83| 
        MOV *SP(#4), AR1 ; |83| 
        CMPU AR2 >= AR1, TC1 ; |83| 
        BCC $C$L4,TC1 ; |83| 
                                        ; branchcc occurs ; |83| 
$C$L1:    
$C$DW$L$_USBSTK5515_I2C_write$2$B:
	.dwpsn	file "../include/usbstk5515_i2c.c",line 85,column 12,is_stmt
;----------------------------------------------------------------------
;  85 | I2C_DXR = data[i];            // Write                                 
;----------------------------------------------------------------------
        MOV *SP(#6), T0 ; |85| 
        MOV dbl(*SP(#2)), XAR3
        MOV *AR3(T0), AR1 ; |85| 
        MOV AR1, *port(#6688) ; |85| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 86,column 13,is_stmt
;----------------------------------------------------------------------
;  86 | timeout = 0x510;             // I2C_timeout = 1ms;                     
;----------------------------------------------------------------------
        MOV #1296, *SP(#5) ; |86| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 87,column 13,is_stmt
;----------------------------------------------------------------------
;  87 | USBSTK5515_GPIO_setOutput( 17, 1);                                     
;  88 | do                                                                     
;----------------------------------------------------------------------
        MOV #17, T0 ; |87| 
$C$DW$27	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$27, DW_AT_low_pc(0x00)
	.dwattr $C$DW$27, DW_AT_name("_USBSTK5515_GPIO_setOutput")
	.dwattr $C$DW$27, DW_AT_TI_call

        CALL #_USBSTK5515_GPIO_setOutput ; |87| 
||      MOV #1, T1

                                        ; call occurs [#_USBSTK5515_GPIO_setOutput] ; |87| 
$C$DW$L$_USBSTK5515_I2C_write$2$E:
$C$L2:    
$C$DW$L$_USBSTK5515_I2C_write$3$B:
	.dwpsn	file "../include/usbstk5515_i2c.c",line 90,column 17,is_stmt
;----------------------------------------------------------------------
;  90 | if ( timeout-- < 0  )                                                  
;----------------------------------------------------------------------
        MOV *SP(#5), AR1 ; |90| 
        SUB #1, AR1, AR2 ; |90| 
        MOV AR2, *SP(#5) ; |90| 
        BCC $C$L3,AR1 >= #0 ; |90| 
                                        ; branchcc occurs ; |90| 
$C$DW$L$_USBSTK5515_I2C_write$3$E:
	.dwpsn	file "../include/usbstk5515_i2c.c",line 92,column 18,is_stmt
;----------------------------------------------------------------------
;  92 | USBSTK5515_GPIO_setOutput( 17, 0);                                     
;----------------------------------------------------------------------
        MOV #17, T0 ; |92| 
$C$DW$28	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$28, DW_AT_low_pc(0x00)
	.dwattr $C$DW$28, DW_AT_name("_USBSTK5515_GPIO_setOutput")
	.dwattr $C$DW$28, DW_AT_TI_call

        CALL #_USBSTK5515_GPIO_setOutput ; |92| 
||      MOV #0, T1

                                        ; call occurs [#_USBSTK5515_GPIO_setOutput] ; |92| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 93,column 21,is_stmt
;----------------------------------------------------------------------
;  93 | USBSTK5515_I2C_reset( );                                               
;----------------------------------------------------------------------
$C$DW$29	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$29, DW_AT_low_pc(0x00)
	.dwattr $C$DW$29, DW_AT_name("_USBSTK5515_I2C_reset")
	.dwattr $C$DW$29, DW_AT_TI_call
        CALL #_USBSTK5515_I2C_reset ; |93| 
                                        ; call occurs [#_USBSTK5515_I2C_reset] ; |93| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 94,column 21,is_stmt
;----------------------------------------------------------------------
;  94 | return -1;                                                             
;----------------------------------------------------------------------
        MOV #-1, T0
        B $C$L5   ; |94| 
                                        ; branch occurs ; |94| 
$C$L3:    
$C$DW$L$_USBSTK5515_I2C_write$5$B:
	.dwpsn	file "../include/usbstk5515_i2c.c",line 96,column 23,is_stmt
;----------------------------------------------------------------------
;  96 | } while ( ( I2C_STR & STR_XRDY ) == 0 );// Wait for Tx Ready           
;----------------------------------------------------------------------
        BTST #4, *port(#6664), TC1 ; |96| 
        BCC $C$L2,!TC1 ; |96| 
                                        ; branchcc occurs ; |96| 
$C$DW$L$_USBSTK5515_I2C_write$5$E:
$C$DW$L$_USBSTK5515_I2C_write$6$B:
	.dwpsn	file "../include/usbstk5515_i2c.c",line 83,column 33,is_stmt
        ADD #1, *SP(#6) ; |83| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 83,column 23,is_stmt
        MOV *SP(#4), AR1 ; |83| 
        MOV *SP(#6), AR2 ; |83| 
        CMPU AR2 < AR1, TC1 ; |83| 
        BCC $C$L1,TC1 ; |83| 
                                        ; branchcc occurs ; |83| 
$C$DW$L$_USBSTK5515_I2C_write$6$E:
$C$L4:    
	.dwpsn	file "../include/usbstk5515_i2c.c",line 99,column 9,is_stmt
;----------------------------------------------------------------------
;  99 | I2C_MDR |= MDR_STP;             // Generate STOP                       
;----------------------------------------------------------------------
        OR #0x0800, *port(#6692) ; |99| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 101,column 3,is_stmt
;----------------------------------------------------------------------
; 101 | USBSTK5515_waitusec(1000);                                             
;----------------------------------------------------------------------
        MOV #1000, AC0 ; |101| 
$C$DW$30	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$30, DW_AT_low_pc(0x00)
	.dwattr $C$DW$30, DW_AT_name("_USBSTK5515_waitusec")
	.dwattr $C$DW$30, DW_AT_TI_call
        CALL #_USBSTK5515_waitusec ; |101| 
                                        ; call occurs [#_USBSTK5515_waitusec] ; |101| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 103,column 9,is_stmt
;----------------------------------------------------------------------
; 103 | return 0;                                                              
;----------------------------------------------------------------------
        MOV #0, T0
$C$L5:    
	.dwpsn	file "../include/usbstk5515_i2c.c",line 105,column 1,is_stmt
        AADD #7, SP
	.dwcfi	cfa_offset, 1
$C$DW$31	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$31, DW_AT_low_pc(0x00)
	.dwattr $C$DW$31, DW_AT_TI_return
        RET
                                        ; return occurs

$C$DW$32	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$32, DW_AT_name("C:\Users\Kiis\Dropbox\Uni\7. semester\AAT7\Code\DSP\aic3204\Debug\usbstk5515_i2c.asm:$C$L1:1:1478686679")
	.dwattr $C$DW$32, DW_AT_TI_begin_file("../include/usbstk5515_i2c.c")
	.dwattr $C$DW$32, DW_AT_TI_begin_line(0x53)
	.dwattr $C$DW$32, DW_AT_TI_end_line(0x61)
$C$DW$33	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$33, DW_AT_low_pc($C$DW$L$_USBSTK5515_I2C_write$2$B)
	.dwattr $C$DW$33, DW_AT_high_pc($C$DW$L$_USBSTK5515_I2C_write$2$E)
$C$DW$34	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$34, DW_AT_low_pc($C$DW$L$_USBSTK5515_I2C_write$6$B)
	.dwattr $C$DW$34, DW_AT_high_pc($C$DW$L$_USBSTK5515_I2C_write$6$E)

$C$DW$35	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$35, DW_AT_name("C:\Users\Kiis\Dropbox\Uni\7. semester\AAT7\Code\DSP\aic3204\Debug\usbstk5515_i2c.asm:$C$L2:2:1478686679")
	.dwattr $C$DW$35, DW_AT_TI_begin_file("../include/usbstk5515_i2c.c")
	.dwattr $C$DW$35, DW_AT_TI_begin_line(0x58)
	.dwattr $C$DW$35, DW_AT_TI_end_line(0x60)
$C$DW$36	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$36, DW_AT_low_pc($C$DW$L$_USBSTK5515_I2C_write$3$B)
	.dwattr $C$DW$36, DW_AT_high_pc($C$DW$L$_USBSTK5515_I2C_write$3$E)
$C$DW$37	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$37, DW_AT_low_pc($C$DW$L$_USBSTK5515_I2C_write$5$B)
	.dwattr $C$DW$37, DW_AT_high_pc($C$DW$L$_USBSTK5515_I2C_write$5$E)
	.dwendtag $C$DW$35

	.dwendtag $C$DW$32

	.dwattr $C$DW$17, DW_AT_TI_end_file("../include/usbstk5515_i2c.c")
	.dwattr $C$DW$17, DW_AT_TI_end_line(0x69)
	.dwattr $C$DW$17, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$17

	.sect	".text"
	.global	_USBSTK5515_I2C_read

$C$DW$38	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_I2C_read")
	.dwattr $C$DW$38, DW_AT_low_pc(_USBSTK5515_I2C_read)
	.dwattr $C$DW$38, DW_AT_high_pc(0x00)
	.dwattr $C$DW$38, DW_AT_TI_symbol_name("_USBSTK5515_I2C_read")
	.dwattr $C$DW$38, DW_AT_external
	.dwattr $C$DW$38, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$38, DW_AT_TI_begin_file("../include/usbstk5515_i2c.c")
	.dwattr $C$DW$38, DW_AT_TI_begin_line(0x79)
	.dwattr $C$DW$38, DW_AT_TI_begin_column(0x07)
	.dwattr $C$DW$38, DW_AT_decl_file("../include/usbstk5515_i2c.c")
	.dwattr $C$DW$38, DW_AT_decl_line(0x79)
	.dwattr $C$DW$38, DW_AT_decl_column(0x07)
	.dwattr $C$DW$38, DW_AT_TI_max_frame_size(0x08)
	.dwpsn	file "../include/usbstk5515_i2c.c",line 122,column 1,is_stmt,address _USBSTK5515_I2C_read

	.dwfde $C$DW$CIE, _USBSTK5515_I2C_read
$C$DW$39	.dwtag  DW_TAG_formal_parameter, DW_AT_name("i2c_addr")
	.dwattr $C$DW$39, DW_AT_TI_symbol_name("_i2c_addr")
	.dwattr $C$DW$39, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$39, DW_AT_location[DW_OP_reg12]
$C$DW$40	.dwtag  DW_TAG_formal_parameter, DW_AT_name("data")
	.dwattr $C$DW$40, DW_AT_TI_symbol_name("_data")
	.dwattr $C$DW$40, DW_AT_type(*$C$DW$T$21)
	.dwattr $C$DW$40, DW_AT_location[DW_OP_reg17]
$C$DW$41	.dwtag  DW_TAG_formal_parameter, DW_AT_name("len")
	.dwattr $C$DW$41, DW_AT_TI_symbol_name("_len")
	.dwattr $C$DW$41, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$41, DW_AT_location[DW_OP_reg13]
;----------------------------------------------------------------------
; 121 | Int16 USBSTK5515_I2C_read( Uint16 i2c_addr, Uint8* data, Uint16 len )  
;----------------------------------------------------------------------
;*******************************************************************************
;* FUNCTION NAME: USBSTK5515_I2C_read                                          *
;*                                                                             *
;*   Function Uses Regs : AC0,AC0,T0,T1,AR0,XAR0,AR1,AR2,AR3,XAR3,SP,CARRY,TC1,*
;*                        M40,SATA,SATD,RDM,FRCT,SMUL                          *
;*   Stack Frame        : Compact (No Frame Pointer, w/ debug)                 *
;*   Total Frame Size   : 8 words                                              *
;*                        (1 return address/alignment)                         *
;*                        (7 local values)                                     *
;*   Min System Stack   : 1 word                                               *
;*******************************************************************************
_USBSTK5515_I2C_read:
	.dwcfi	cfa_offset, 1
	.dwcfi	save_reg_to_mem, 91, -1
        AADD #-7, SP
	.dwcfi	cfa_offset, 8
$C$DW$42	.dwtag  DW_TAG_variable, DW_AT_name("i2c_addr")
	.dwattr $C$DW$42, DW_AT_TI_symbol_name("_i2c_addr")
	.dwattr $C$DW$42, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$42, DW_AT_location[DW_OP_bregx 0x24 0]
$C$DW$43	.dwtag  DW_TAG_variable, DW_AT_name("data")
	.dwattr $C$DW$43, DW_AT_TI_symbol_name("_data")
	.dwattr $C$DW$43, DW_AT_type(*$C$DW$T$21)
	.dwattr $C$DW$43, DW_AT_location[DW_OP_bregx 0x24 2]
$C$DW$44	.dwtag  DW_TAG_variable, DW_AT_name("len")
	.dwattr $C$DW$44, DW_AT_TI_symbol_name("_len")
	.dwattr $C$DW$44, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$44, DW_AT_location[DW_OP_bregx 0x24 4]
$C$DW$45	.dwtag  DW_TAG_variable, DW_AT_name("timeout")
	.dwattr $C$DW$45, DW_AT_TI_symbol_name("_timeout")
	.dwattr $C$DW$45, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$45, DW_AT_location[DW_OP_bregx 0x24 5]
$C$DW$46	.dwtag  DW_TAG_variable, DW_AT_name("i")
	.dwattr $C$DW$46, DW_AT_TI_symbol_name("_i")
	.dwattr $C$DW$46, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$46, DW_AT_location[DW_OP_bregx 0x24 6]
;----------------------------------------------------------------------
; 123 | Int32 timeout, i;                                                      
;----------------------------------------------------------------------
        MOV T1, *SP(#4) ; |122| 
        MOV XAR0, dbl(*SP(#2))
        MOV T0, *SP(#0) ; |122| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 125,column 5,is_stmt
;----------------------------------------------------------------------
; 125 | I2C_CNT = len;                    // Set length                        
;----------------------------------------------------------------------
        MOV *SP(#4), AR1 ; |125| 
        MOV AR1, *port(#6676) ; |125| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 126,column 5,is_stmt
;----------------------------------------------------------------------
; 126 | I2C_SAR = i2c_addr;               // Set I2C slave address             
;----------------------------------------------------------------------
        MOV T0, AR1
        MOV AR1, *port(#6684) ; |126| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 127,column 5,is_stmt
;----------------------------------------------------------------------
; 127 | I2C_MDR = MDR_STT                 // Set for Master Read               
; 128 |           | MDR_MST                                                    
; 129 |           | MDR_IRS                                                    
; 130 |           | MDR_FREE;                                                  
;----------------------------------------------------------------------
        MOV #25632, *port(#6692) ; |127| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 132,column 5,is_stmt
;----------------------------------------------------------------------
; 132 | USBSTK5515_wait( 10 );            // Short delay                       
;----------------------------------------------------------------------
$C$DW$47	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$47, DW_AT_low_pc(0x00)
	.dwattr $C$DW$47, DW_AT_name("_USBSTK5515_wait")
	.dwattr $C$DW$47, DW_AT_TI_call

        CALL #_USBSTK5515_wait ; |132| 
||      MOV #10, AC0 ; |132| 

                                        ; call occurs [#_USBSTK5515_wait] ; |132| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 134,column 11,is_stmt
;----------------------------------------------------------------------
; 134 | for ( i = 0 ; i < len ; i++ )                                          
;----------------------------------------------------------------------
        MOV #0, *SP(#6) ; |134| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 134,column 19,is_stmt
        MOV *SP(#6), AR2 ; |134| 
        MOV *SP(#4), AR1 ; |134| 
        CMPU AR2 >= AR1, TC1 ; |134| 
        BCC $C$L9,TC1 ; |134| 
                                        ; branchcc occurs ; |134| 
$C$L6:    
$C$DW$L$_USBSTK5515_I2C_read$2$B:
	.dwpsn	file "../include/usbstk5515_i2c.c",line 136,column 9,is_stmt
;----------------------------------------------------------------------
; 136 | timeout = i2c_timeout;                                                 
; 138 | //Wait for Rx Ready                                                    
; 139 | do                                                                     
;----------------------------------------------------------------------
        MOV *(#_i2c_timeout), AR1 ; |136| 
        MOV AR1, *SP(#5) ; |136| 
$C$DW$L$_USBSTK5515_I2C_read$2$E:
$C$L7:    
$C$DW$L$_USBSTK5515_I2C_read$3$B:
	.dwpsn	file "../include/usbstk5515_i2c.c",line 141,column 13,is_stmt
;----------------------------------------------------------------------
; 141 | if ( timeout-- < 0 )                                                   
;----------------------------------------------------------------------
        MOV *SP(#5), AR1 ; |141| 
        SUB #1, AR1, AR2 ; |141| 
        MOV AR2, *SP(#5) ; |141| 
        BCC $C$L8,AR1 >= #0 ; |141| 
                                        ; branchcc occurs ; |141| 
$C$DW$L$_USBSTK5515_I2C_read$3$E:
	.dwpsn	file "../include/usbstk5515_i2c.c",line 143,column 17,is_stmt
;----------------------------------------------------------------------
; 143 | USBSTK5515_I2C_reset( );                                               
;----------------------------------------------------------------------
$C$DW$48	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$48, DW_AT_low_pc(0x00)
	.dwattr $C$DW$48, DW_AT_name("_USBSTK5515_I2C_reset")
	.dwattr $C$DW$48, DW_AT_TI_call
        CALL #_USBSTK5515_I2C_reset ; |143| 
                                        ; call occurs [#_USBSTK5515_I2C_reset] ; |143| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 144,column 17,is_stmt
;----------------------------------------------------------------------
; 144 | return -1;                                                             
;----------------------------------------------------------------------
        MOV #-1, T0
        B $C$L10  ; |144| 
                                        ; branch occurs ; |144| 
$C$L8:    
$C$DW$L$_USBSTK5515_I2C_read$5$B:
	.dwpsn	file "../include/usbstk5515_i2c.c",line 146,column 19,is_stmt
;----------------------------------------------------------------------
; 146 | } while ( ( I2C_STR & STR_RRDY ) == 0 );// Wait for Rx Ready           
;----------------------------------------------------------------------
        BTST #3, *port(#6664), TC1 ; |146| 
        BCC $C$L7,!TC1 ; |146| 
                                        ; branchcc occurs ; |146| 
$C$DW$L$_USBSTK5515_I2C_read$5$E:
$C$DW$L$_USBSTK5515_I2C_read$6$B:
	.dwpsn	file "../include/usbstk5515_i2c.c",line 148,column 9,is_stmt
;----------------------------------------------------------------------
; 148 | data[i] = I2C_DRR;            // Read                                  
;----------------------------------------------------------------------
        MOV dbl(*SP(#2)), XAR3
        MOV *SP(#6), T0 ; |148| 
        MOV *port(#6680), AR1 ; |148| 
        MOV AR1, *AR3(T0) ; |148| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 134,column 29,is_stmt
        ADD #1, *SP(#6) ; |134| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 134,column 19,is_stmt
        MOV *SP(#6), AR2 ; |134| 
        MOV *SP(#4), AR1 ; |134| 
        CMPU AR2 < AR1, TC1 ; |134| 
        BCC $C$L6,TC1 ; |134| 
                                        ; branchcc occurs ; |134| 
$C$DW$L$_USBSTK5515_I2C_read$6$E:
$C$L9:    
	.dwpsn	file "../include/usbstk5515_i2c.c",line 151,column 5,is_stmt
;----------------------------------------------------------------------
; 151 | I2C_MDR |= MDR_STP;               // Generate STOP                     
;----------------------------------------------------------------------
        OR #0x0800, *port(#6692) ; |151| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 153,column 2,is_stmt
;----------------------------------------------------------------------
; 153 | USBSTK5515_waitusec(10);                                               
;----------------------------------------------------------------------
$C$DW$49	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$49, DW_AT_low_pc(0x00)
	.dwattr $C$DW$49, DW_AT_name("_USBSTK5515_waitusec")
	.dwattr $C$DW$49, DW_AT_TI_call

        CALL #_USBSTK5515_waitusec ; |153| 
||      MOV #10, AC0 ; |153| 

                                        ; call occurs [#_USBSTK5515_waitusec] ; |153| 
	.dwpsn	file "../include/usbstk5515_i2c.c",line 154,column 5,is_stmt
;----------------------------------------------------------------------
; 154 | return 0;                                                              
;----------------------------------------------------------------------
        MOV #0, T0
$C$L10:    
	.dwpsn	file "../include/usbstk5515_i2c.c",line 155,column 1,is_stmt
        AADD #7, SP
	.dwcfi	cfa_offset, 1
$C$DW$50	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$50, DW_AT_low_pc(0x00)
	.dwattr $C$DW$50, DW_AT_TI_return
        RET
                                        ; return occurs

$C$DW$51	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$51, DW_AT_name("C:\Users\Kiis\Dropbox\Uni\7. semester\AAT7\Code\DSP\aic3204\Debug\usbstk5515_i2c.asm:$C$L6:1:1478686679")
	.dwattr $C$DW$51, DW_AT_TI_begin_file("../include/usbstk5515_i2c.c")
	.dwattr $C$DW$51, DW_AT_TI_begin_line(0x86)
	.dwattr $C$DW$51, DW_AT_TI_end_line(0x95)
$C$DW$52	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$52, DW_AT_low_pc($C$DW$L$_USBSTK5515_I2C_read$2$B)
	.dwattr $C$DW$52, DW_AT_high_pc($C$DW$L$_USBSTK5515_I2C_read$2$E)
$C$DW$53	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$53, DW_AT_low_pc($C$DW$L$_USBSTK5515_I2C_read$6$B)
	.dwattr $C$DW$53, DW_AT_high_pc($C$DW$L$_USBSTK5515_I2C_read$6$E)

$C$DW$54	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$54, DW_AT_name("C:\Users\Kiis\Dropbox\Uni\7. semester\AAT7\Code\DSP\aic3204\Debug\usbstk5515_i2c.asm:$C$L7:2:1478686679")
	.dwattr $C$DW$54, DW_AT_TI_begin_file("../include/usbstk5515_i2c.c")
	.dwattr $C$DW$54, DW_AT_TI_begin_line(0x8b)
	.dwattr $C$DW$54, DW_AT_TI_end_line(0x92)
$C$DW$55	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$55, DW_AT_low_pc($C$DW$L$_USBSTK5515_I2C_read$3$B)
	.dwattr $C$DW$55, DW_AT_high_pc($C$DW$L$_USBSTK5515_I2C_read$3$E)
$C$DW$56	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$56, DW_AT_low_pc($C$DW$L$_USBSTK5515_I2C_read$5$B)
	.dwattr $C$DW$56, DW_AT_high_pc($C$DW$L$_USBSTK5515_I2C_read$5$E)
	.dwendtag $C$DW$54

	.dwendtag $C$DW$51

	.dwattr $C$DW$38, DW_AT_TI_end_file("../include/usbstk5515_i2c.c")
	.dwattr $C$DW$38, DW_AT_TI_end_line(0x9b)
	.dwattr $C$DW$38, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$38

;******************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                              *
;******************************************************************************
	.global	_USBSTK5515_wait
	.global	_USBSTK5515_waitusec
	.global	_USBSTK5515_GPIO_setOutput

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
$C$DW$T$21	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$21, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$T$21, DW_AT_address_class(0x17)
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

$C$DW$57	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC0")
	.dwattr $C$DW$57, DW_AT_location[DW_OP_reg0]
$C$DW$58	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC0")
	.dwattr $C$DW$58, DW_AT_location[DW_OP_reg1]
$C$DW$59	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC0_G")
	.dwattr $C$DW$59, DW_AT_location[DW_OP_reg2]
$C$DW$60	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC1")
	.dwattr $C$DW$60, DW_AT_location[DW_OP_reg3]
$C$DW$61	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC1")
	.dwattr $C$DW$61, DW_AT_location[DW_OP_reg4]
$C$DW$62	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC1_G")
	.dwattr $C$DW$62, DW_AT_location[DW_OP_reg5]
$C$DW$63	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC2")
	.dwattr $C$DW$63, DW_AT_location[DW_OP_reg6]
$C$DW$64	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC2")
	.dwattr $C$DW$64, DW_AT_location[DW_OP_reg7]
$C$DW$65	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC2_G")
	.dwattr $C$DW$65, DW_AT_location[DW_OP_reg8]
$C$DW$66	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC3")
	.dwattr $C$DW$66, DW_AT_location[DW_OP_reg9]
$C$DW$67	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC3")
	.dwattr $C$DW$67, DW_AT_location[DW_OP_reg10]
$C$DW$68	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC3_G")
	.dwattr $C$DW$68, DW_AT_location[DW_OP_reg11]
$C$DW$69	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("T0")
	.dwattr $C$DW$69, DW_AT_location[DW_OP_reg12]
$C$DW$70	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("T1")
	.dwattr $C$DW$70, DW_AT_location[DW_OP_reg13]
$C$DW$71	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("T2")
	.dwattr $C$DW$71, DW_AT_location[DW_OP_reg14]
$C$DW$72	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("T3")
	.dwattr $C$DW$72, DW_AT_location[DW_OP_reg15]
$C$DW$73	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR0")
	.dwattr $C$DW$73, DW_AT_location[DW_OP_reg16]
$C$DW$74	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR0")
	.dwattr $C$DW$74, DW_AT_location[DW_OP_reg17]
$C$DW$75	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR1")
	.dwattr $C$DW$75, DW_AT_location[DW_OP_reg18]
$C$DW$76	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR1")
	.dwattr $C$DW$76, DW_AT_location[DW_OP_reg19]
$C$DW$77	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR2")
	.dwattr $C$DW$77, DW_AT_location[DW_OP_reg20]
$C$DW$78	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR2")
	.dwattr $C$DW$78, DW_AT_location[DW_OP_reg21]
$C$DW$79	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR3")
	.dwattr $C$DW$79, DW_AT_location[DW_OP_reg22]
$C$DW$80	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR3")
	.dwattr $C$DW$80, DW_AT_location[DW_OP_reg23]
$C$DW$81	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR4")
	.dwattr $C$DW$81, DW_AT_location[DW_OP_reg24]
$C$DW$82	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR4")
	.dwattr $C$DW$82, DW_AT_location[DW_OP_reg25]
$C$DW$83	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR5")
	.dwattr $C$DW$83, DW_AT_location[DW_OP_reg26]
$C$DW$84	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR5")
	.dwattr $C$DW$84, DW_AT_location[DW_OP_reg27]
$C$DW$85	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR6")
	.dwattr $C$DW$85, DW_AT_location[DW_OP_reg28]
$C$DW$86	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR6")
	.dwattr $C$DW$86, DW_AT_location[DW_OP_reg29]
$C$DW$87	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR7")
	.dwattr $C$DW$87, DW_AT_location[DW_OP_reg30]
$C$DW$88	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR7")
	.dwattr $C$DW$88, DW_AT_location[DW_OP_reg31]
$C$DW$89	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("FP")
	.dwattr $C$DW$89, DW_AT_location[DW_OP_regx 0x20]
$C$DW$90	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XFP")
	.dwattr $C$DW$90, DW_AT_location[DW_OP_regx 0x21]
$C$DW$91	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("PC")
	.dwattr $C$DW$91, DW_AT_location[DW_OP_regx 0x22]
$C$DW$92	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("SP")
	.dwattr $C$DW$92, DW_AT_location[DW_OP_regx 0x23]
$C$DW$93	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XSP")
	.dwattr $C$DW$93, DW_AT_location[DW_OP_regx 0x24]
$C$DW$94	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BKC")
	.dwattr $C$DW$94, DW_AT_location[DW_OP_regx 0x25]
$C$DW$95	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BK03")
	.dwattr $C$DW$95, DW_AT_location[DW_OP_regx 0x26]
$C$DW$96	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BK47")
	.dwattr $C$DW$96, DW_AT_location[DW_OP_regx 0x27]
$C$DW$97	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ST0")
	.dwattr $C$DW$97, DW_AT_location[DW_OP_regx 0x28]
$C$DW$98	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ST1")
	.dwattr $C$DW$98, DW_AT_location[DW_OP_regx 0x29]
$C$DW$99	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ST2")
	.dwattr $C$DW$99, DW_AT_location[DW_OP_regx 0x2a]
$C$DW$100	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ST3")
	.dwattr $C$DW$100, DW_AT_location[DW_OP_regx 0x2b]
$C$DW$101	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("MDP")
	.dwattr $C$DW$101, DW_AT_location[DW_OP_regx 0x2c]
$C$DW$102	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("MDP05")
	.dwattr $C$DW$102, DW_AT_location[DW_OP_regx 0x2d]
$C$DW$103	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("MDP67")
	.dwattr $C$DW$103, DW_AT_location[DW_OP_regx 0x2e]
$C$DW$104	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BRC0")
	.dwattr $C$DW$104, DW_AT_location[DW_OP_regx 0x2f]
$C$DW$105	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RSA0")
	.dwattr $C$DW$105, DW_AT_location[DW_OP_regx 0x30]
$C$DW$106	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RSA0_H")
	.dwattr $C$DW$106, DW_AT_location[DW_OP_regx 0x31]
$C$DW$107	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("REA0")
	.dwattr $C$DW$107, DW_AT_location[DW_OP_regx 0x32]
$C$DW$108	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("REA0_H")
	.dwattr $C$DW$108, DW_AT_location[DW_OP_regx 0x33]
$C$DW$109	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BRS1")
	.dwattr $C$DW$109, DW_AT_location[DW_OP_regx 0x34]
$C$DW$110	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BRC1")
	.dwattr $C$DW$110, DW_AT_location[DW_OP_regx 0x35]
$C$DW$111	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RSA1")
	.dwattr $C$DW$111, DW_AT_location[DW_OP_regx 0x36]
$C$DW$112	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RSA1_H")
	.dwattr $C$DW$112, DW_AT_location[DW_OP_regx 0x37]
$C$DW$113	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("REA1")
	.dwattr $C$DW$113, DW_AT_location[DW_OP_regx 0x38]
$C$DW$114	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("REA1_H")
	.dwattr $C$DW$114, DW_AT_location[DW_OP_regx 0x39]
$C$DW$115	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CSR")
	.dwattr $C$DW$115, DW_AT_location[DW_OP_regx 0x3a]
$C$DW$116	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RPTC")
	.dwattr $C$DW$116, DW_AT_location[DW_OP_regx 0x3b]
$C$DW$117	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CDP")
	.dwattr $C$DW$117, DW_AT_location[DW_OP_regx 0x3c]
$C$DW$118	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XCDP")
	.dwattr $C$DW$118, DW_AT_location[DW_OP_regx 0x3d]
$C$DW$119	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TRN0")
	.dwattr $C$DW$119, DW_AT_location[DW_OP_regx 0x3e]
$C$DW$120	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TRN1")
	.dwattr $C$DW$120, DW_AT_location[DW_OP_regx 0x3f]
$C$DW$121	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BSA01")
	.dwattr $C$DW$121, DW_AT_location[DW_OP_regx 0x40]
$C$DW$122	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BSA23")
	.dwattr $C$DW$122, DW_AT_location[DW_OP_regx 0x41]
$C$DW$123	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BSA45")
	.dwattr $C$DW$123, DW_AT_location[DW_OP_regx 0x42]
$C$DW$124	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BSA67")
	.dwattr $C$DW$124, DW_AT_location[DW_OP_regx 0x43]
$C$DW$125	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BSAC")
	.dwattr $C$DW$125, DW_AT_location[DW_OP_regx 0x44]
$C$DW$126	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CARRY")
	.dwattr $C$DW$126, DW_AT_location[DW_OP_regx 0x45]
$C$DW$127	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TC1")
	.dwattr $C$DW$127, DW_AT_location[DW_OP_regx 0x46]
$C$DW$128	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TC2")
	.dwattr $C$DW$128, DW_AT_location[DW_OP_regx 0x47]
$C$DW$129	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("M40")
	.dwattr $C$DW$129, DW_AT_location[DW_OP_regx 0x48]
$C$DW$130	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("SXMD")
	.dwattr $C$DW$130, DW_AT_location[DW_OP_regx 0x49]
$C$DW$131	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ARMS")
	.dwattr $C$DW$131, DW_AT_location[DW_OP_regx 0x4a]
$C$DW$132	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("C54CM")
	.dwattr $C$DW$132, DW_AT_location[DW_OP_regx 0x4b]
$C$DW$133	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("SATA")
	.dwattr $C$DW$133, DW_AT_location[DW_OP_regx 0x4c]
$C$DW$134	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("SATD")
	.dwattr $C$DW$134, DW_AT_location[DW_OP_regx 0x4d]
$C$DW$135	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RDM")
	.dwattr $C$DW$135, DW_AT_location[DW_OP_regx 0x4e]
$C$DW$136	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("FRCT")
	.dwattr $C$DW$136, DW_AT_location[DW_OP_regx 0x4f]
$C$DW$137	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("SMUL")
	.dwattr $C$DW$137, DW_AT_location[DW_OP_regx 0x50]
$C$DW$138	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("INTM")
	.dwattr $C$DW$138, DW_AT_location[DW_OP_regx 0x51]
$C$DW$139	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR0LC")
	.dwattr $C$DW$139, DW_AT_location[DW_OP_regx 0x52]
$C$DW$140	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR1LC")
	.dwattr $C$DW$140, DW_AT_location[DW_OP_regx 0x53]
$C$DW$141	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR2LC")
	.dwattr $C$DW$141, DW_AT_location[DW_OP_regx 0x54]
$C$DW$142	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR3LC")
	.dwattr $C$DW$142, DW_AT_location[DW_OP_regx 0x55]
$C$DW$143	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR4LC")
	.dwattr $C$DW$143, DW_AT_location[DW_OP_regx 0x56]
$C$DW$144	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR5LC")
	.dwattr $C$DW$144, DW_AT_location[DW_OP_regx 0x57]
$C$DW$145	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR6LC")
	.dwattr $C$DW$145, DW_AT_location[DW_OP_regx 0x58]
$C$DW$146	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR7LC")
	.dwattr $C$DW$146, DW_AT_location[DW_OP_regx 0x59]
$C$DW$147	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CDPLC")
	.dwattr $C$DW$147, DW_AT_location[DW_OP_regx 0x5a]
$C$DW$148	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CIE_RETA")
	.dwattr $C$DW$148, DW_AT_location[DW_OP_regx 0x5b]
	.dwendtag $C$DW$CU

