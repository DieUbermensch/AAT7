;*******************************************************************************
;* TMS320C55x C/C++ Codegen                                          PC v4.3.8 *
;* Date/Time created: Wed Nov 09 11:17:57 2016                                 *
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
	.dwattr $C$DW$CU, DW_AT_name("../main.c")
	.dwattr $C$DW$CU, DW_AT_producer("TMS320C55x C/C++ Codegen PC v4.3.8 Copyright (c) 1996-2010 Texas Instruments Incorporated")
	.dwattr $C$DW$CU, DW_AT_TI_version(0x01)
	.dwattr $C$DW$CU, DW_AT_comp_dir("C:\Users\Kiis\Dropbox\Uni\7. semester\AAT7\Code\DSP\aic3204\Debug")
;******************************************************************************
;* CINIT RECORDS                                                              *
;******************************************************************************
	.sect	".cinit"
	.align	1
	.field  	1,16
	.field  	_i+0,24
	.field  	0,8
	.field  	0,16			; _i @ 0


$C$DW$1	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_init")
	.dwattr $C$DW$1, DW_AT_TI_symbol_name("_USBSTK5515_init")
	.dwattr $C$DW$1, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$1, DW_AT_declaration
	.dwattr $C$DW$1, DW_AT_external
	.dwattr $C$DW$1, DW_AT_decl_file("C:/Program Files/TexasInstruments/ccsv4/tools/compiler/c5500/include/usbstk5515.h")
	.dwattr $C$DW$1, DW_AT_decl_line(0x6a)
	.dwattr $C$DW$1, DW_AT_decl_column(0x07)

$C$DW$2	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_wait")
	.dwattr $C$DW$2, DW_AT_TI_symbol_name("_USBSTK5515_wait")
	.dwattr $C$DW$2, DW_AT_declaration
	.dwattr $C$DW$2, DW_AT_external
	.dwattr $C$DW$2, DW_AT_decl_file("C:/Program Files/TexasInstruments/ccsv4/tools/compiler/c5500/include/usbstk5515.h")
	.dwattr $C$DW$2, DW_AT_decl_line(0x6d)
	.dwattr $C$DW$2, DW_AT_decl_column(0x06)
$C$DW$3	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$3, DW_AT_type(*$C$DW$T$13)
	.dwendtag $C$DW$2


$C$DW$4	.dwtag  DW_TAG_subprogram, DW_AT_name("USBSTK5515_I2C_write")
	.dwattr $C$DW$4, DW_AT_TI_symbol_name("_USBSTK5515_I2C_write")
	.dwattr $C$DW$4, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$4, DW_AT_declaration
	.dwattr $C$DW$4, DW_AT_external
	.dwattr $C$DW$4, DW_AT_decl_file("C:/Program Files/TexasInstruments/ccsv4/tools/compiler/c5500/include/usbstk5515_i2c.h")
	.dwattr $C$DW$4, DW_AT_decl_line(0x1e)
	.dwattr $C$DW$4, DW_AT_decl_column(0x07)
$C$DW$5	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$5, DW_AT_type(*$C$DW$T$9)
$C$DW$6	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$6, DW_AT_type(*$C$DW$T$19)
$C$DW$7	.dwtag  DW_TAG_formal_parameter
	.dwattr $C$DW$7, DW_AT_type(*$C$DW$T$9)
	.dwendtag $C$DW$4


$C$DW$8	.dwtag  DW_TAG_subprogram, DW_AT_name("CPFIR")
	.dwattr $C$DW$8, DW_AT_TI_symbol_name("_CPFIR")
	.dwattr $C$DW$8, DW_AT_declaration
	.dwattr $C$DW$8, DW_AT_external
	.dwattr $C$DW$8, DW_AT_decl_file("../main.c")
	.dwattr $C$DW$8, DW_AT_decl_line(0x29)
	.dwattr $C$DW$8, DW_AT_decl_column(0x0d)
	.global	_J
	.bss	_J,1,0,0
$C$DW$9	.dwtag  DW_TAG_variable, DW_AT_name("J")
	.dwattr $C$DW$9, DW_AT_TI_symbol_name("_J")
	.dwattr $C$DW$9, DW_AT_location[DW_OP_addr _J]
	.dwattr $C$DW$9, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$9, DW_AT_external
	.dwattr $C$DW$9, DW_AT_decl_file("..\aic3204_setup.h")
	.dwattr $C$DW$9, DW_AT_decl_line(0x0f)
	.dwattr $C$DW$9, DW_AT_decl_column(0x07)
	.global	_Dlow
	.bss	_Dlow,1,0,0
$C$DW$10	.dwtag  DW_TAG_variable, DW_AT_name("Dlow")
	.dwattr $C$DW$10, DW_AT_TI_symbol_name("_Dlow")
	.dwattr $C$DW$10, DW_AT_location[DW_OP_addr _Dlow]
	.dwattr $C$DW$10, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$10, DW_AT_external
	.dwattr $C$DW$10, DW_AT_decl_file("..\aic3204_setup.h")
	.dwattr $C$DW$10, DW_AT_decl_line(0x0f)
	.dwattr $C$DW$10, DW_AT_decl_column(0x0a)
	.global	_Dhigh
	.bss	_Dhigh,1,0,0
$C$DW$11	.dwtag  DW_TAG_variable, DW_AT_name("Dhigh")
	.dwattr $C$DW$11, DW_AT_TI_symbol_name("_Dhigh")
	.dwattr $C$DW$11, DW_AT_location[DW_OP_addr _Dhigh]
	.dwattr $C$DW$11, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$11, DW_AT_external
	.dwattr $C$DW$11, DW_AT_decl_file("..\aic3204_setup.h")
	.dwattr $C$DW$11, DW_AT_decl_line(0x0f)
	.dwattr $C$DW$11, DW_AT_decl_column(0x10)
	.global	_BCLK
	.bss	_BCLK,1,0,0
$C$DW$12	.dwtag  DW_TAG_variable, DW_AT_name("BCLK")
	.dwattr $C$DW$12, DW_AT_TI_symbol_name("_BCLK")
	.dwattr $C$DW$12, DW_AT_location[DW_OP_addr _BCLK]
	.dwattr $C$DW$12, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$12, DW_AT_external
	.dwattr $C$DW$12, DW_AT_decl_file("..\aic3204_setup.h")
	.dwattr $C$DW$12, DW_AT_decl_line(0x0f)
	.dwattr $C$DW$12, DW_AT_decl_column(0x17)
	.global	_BCLKN
	.bss	_BCLKN,1,0,0
$C$DW$13	.dwtag  DW_TAG_variable, DW_AT_name("BCLKN")
	.dwattr $C$DW$13, DW_AT_TI_symbol_name("_BCLKN")
	.dwattr $C$DW$13, DW_AT_location[DW_OP_addr _BCLKN]
	.dwattr $C$DW$13, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$13, DW_AT_external
	.dwattr $C$DW$13, DW_AT_decl_file("..\aic3204_setup.h")
	.dwattr $C$DW$13, DW_AT_decl_line(0x0f)
	.dwattr $C$DW$13, DW_AT_decl_column(0x1d)
	.global	_Reg11
	.bss	_Reg11,1,0,0
$C$DW$14	.dwtag  DW_TAG_variable, DW_AT_name("Reg11")
	.dwattr $C$DW$14, DW_AT_TI_symbol_name("_Reg11")
	.dwattr $C$DW$14, DW_AT_location[DW_OP_addr _Reg11]
	.dwattr $C$DW$14, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$14, DW_AT_external
	.dwattr $C$DW$14, DW_AT_decl_file("..\aic3204_setup.h")
	.dwattr $C$DW$14, DW_AT_decl_line(0x0f)
	.dwattr $C$DW$14, DW_AT_decl_column(0x24)
	.global	_Reg12
	.bss	_Reg12,1,0,0
$C$DW$15	.dwtag  DW_TAG_variable, DW_AT_name("Reg12")
	.dwattr $C$DW$15, DW_AT_TI_symbol_name("_Reg12")
	.dwattr $C$DW$15, DW_AT_location[DW_OP_addr _Reg12]
	.dwattr $C$DW$15, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$15, DW_AT_external
	.dwattr $C$DW$15, DW_AT_decl_file("..\aic3204_setup.h")
	.dwattr $C$DW$15, DW_AT_decl_line(0x0f)
	.dwattr $C$DW$15, DW_AT_decl_column(0x2b)
	.global	_Reg13
	.bss	_Reg13,1,0,0
$C$DW$16	.dwtag  DW_TAG_variable, DW_AT_name("Reg13")
	.dwattr $C$DW$16, DW_AT_TI_symbol_name("_Reg13")
	.dwattr $C$DW$16, DW_AT_location[DW_OP_addr _Reg13]
	.dwattr $C$DW$16, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$16, DW_AT_external
	.dwattr $C$DW$16, DW_AT_decl_file("..\aic3204_setup.h")
	.dwattr $C$DW$16, DW_AT_decl_line(0x0f)
	.dwattr $C$DW$16, DW_AT_decl_column(0x32)
	.global	_Reg14
	.bss	_Reg14,1,0,0
$C$DW$17	.dwtag  DW_TAG_variable, DW_AT_name("Reg14")
	.dwattr $C$DW$17, DW_AT_TI_symbol_name("_Reg14")
	.dwattr $C$DW$17, DW_AT_location[DW_OP_addr _Reg14]
	.dwattr $C$DW$17, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$17, DW_AT_external
	.dwattr $C$DW$17, DW_AT_decl_file("..\aic3204_setup.h")
	.dwattr $C$DW$17, DW_AT_decl_line(0x0f)
	.dwattr $C$DW$17, DW_AT_decl_column(0x39)
	.global	_Reg18
	.bss	_Reg18,1,0,0
$C$DW$18	.dwtag  DW_TAG_variable, DW_AT_name("Reg18")
	.dwattr $C$DW$18, DW_AT_TI_symbol_name("_Reg18")
	.dwattr $C$DW$18, DW_AT_location[DW_OP_addr _Reg18]
	.dwattr $C$DW$18, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$18, DW_AT_external
	.dwattr $C$DW$18, DW_AT_decl_file("..\aic3204_setup.h")
	.dwattr $C$DW$18, DW_AT_decl_line(0x0f)
	.dwattr $C$DW$18, DW_AT_decl_column(0x40)
	.global	_Reg19
	.bss	_Reg19,1,0,0
$C$DW$19	.dwtag  DW_TAG_variable, DW_AT_name("Reg19")
	.dwattr $C$DW$19, DW_AT_TI_symbol_name("_Reg19")
	.dwattr $C$DW$19, DW_AT_location[DW_OP_addr _Reg19]
	.dwattr $C$DW$19, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$19, DW_AT_external
	.dwattr $C$DW$19, DW_AT_decl_file("..\aic3204_setup.h")
	.dwattr $C$DW$19, DW_AT_decl_line(0x0f)
	.dwattr $C$DW$19, DW_AT_decl_column(0x47)
	.global	_Reg20
	.bss	_Reg20,1,0,0
$C$DW$20	.dwtag  DW_TAG_variable, DW_AT_name("Reg20")
	.dwattr $C$DW$20, DW_AT_TI_symbol_name("_Reg20")
	.dwattr $C$DW$20, DW_AT_location[DW_OP_addr _Reg20]
	.dwattr $C$DW$20, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$20, DW_AT_external
	.dwattr $C$DW$20, DW_AT_decl_file("..\aic3204_setup.h")
	.dwattr $C$DW$20, DW_AT_decl_line(0x0f)
	.dwattr $C$DW$20, DW_AT_decl_column(0x4e)
	.global	_data1
	.bss	_data1,1,0,0
$C$DW$21	.dwtag  DW_TAG_variable, DW_AT_name("data1")
	.dwattr $C$DW$21, DW_AT_TI_symbol_name("_data1")
	.dwattr $C$DW$21, DW_AT_location[DW_OP_addr _data1]
	.dwattr $C$DW$21, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$21, DW_AT_external
	.dwattr $C$DW$21, DW_AT_decl_file("../main.c")
	.dwattr $C$DW$21, DW_AT_decl_line(0x1d)
	.dwattr $C$DW$21, DW_AT_decl_column(0x07)
	.global	_data2
	.bss	_data2,1,0,0
$C$DW$22	.dwtag  DW_TAG_variable, DW_AT_name("data2")
	.dwattr $C$DW$22, DW_AT_TI_symbol_name("_data2")
	.dwattr $C$DW$22, DW_AT_location[DW_OP_addr _data2]
	.dwattr $C$DW$22, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$22, DW_AT_external
	.dwattr $C$DW$22, DW_AT_decl_file("../main.c")
	.dwattr $C$DW$22, DW_AT_decl_line(0x1d)
	.dwattr $C$DW$22, DW_AT_decl_column(0x0e)
	.global	_data3
	.bss	_data3,1,0,0
$C$DW$23	.dwtag  DW_TAG_variable, DW_AT_name("data3")
	.dwattr $C$DW$23, DW_AT_TI_symbol_name("_data3")
	.dwattr $C$DW$23, DW_AT_location[DW_OP_addr _data3]
	.dwattr $C$DW$23, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$23, DW_AT_external
	.dwattr $C$DW$23, DW_AT_decl_file("../main.c")
	.dwattr $C$DW$23, DW_AT_decl_line(0x1d)
	.dwattr $C$DW$23, DW_AT_decl_column(0x15)
	.global	_data4
	.bss	_data4,1,0,0
$C$DW$24	.dwtag  DW_TAG_variable, DW_AT_name("data4")
	.dwattr $C$DW$24, DW_AT_TI_symbol_name("_data4")
	.dwattr $C$DW$24, DW_AT_location[DW_OP_addr _data4]
	.dwattr $C$DW$24, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$24, DW_AT_external
	.dwattr $C$DW$24, DW_AT_decl_file("../main.c")
	.dwattr $C$DW$24, DW_AT_decl_line(0x1d)
	.dwattr $C$DW$24, DW_AT_decl_column(0x1c)
	.global	_k
	.bss	_k,1,0,0
$C$DW$25	.dwtag  DW_TAG_variable, DW_AT_name("k")
	.dwattr $C$DW$25, DW_AT_TI_symbol_name("_k")
	.dwattr $C$DW$25, DW_AT_location[DW_OP_addr _k]
	.dwattr $C$DW$25, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$25, DW_AT_external
	.dwattr $C$DW$25, DW_AT_decl_file("../main.c")
	.dwattr $C$DW$25, DW_AT_decl_line(0x1e)
	.dwattr $C$DW$25, DW_AT_decl_column(0x07)
	.global	_x
	.bss	_x,255,0,0
$C$DW$26	.dwtag  DW_TAG_variable, DW_AT_name("x")
	.dwattr $C$DW$26, DW_AT_TI_symbol_name("_x")
	.dwattr $C$DW$26, DW_AT_location[DW_OP_addr _x]
	.dwattr $C$DW$26, DW_AT_type(*$C$DW$T$35)
	.dwattr $C$DW$26, DW_AT_external
	.dwattr $C$DW$26, DW_AT_decl_file("../main.c")
	.dwattr $C$DW$26, DW_AT_decl_line(0x23)
	.dwattr $C$DW$26, DW_AT_decl_column(0x07)
	.global	_b
	.bss	_b,255,0,0
$C$DW$27	.dwtag  DW_TAG_variable, DW_AT_name("b")
	.dwattr $C$DW$27, DW_AT_TI_symbol_name("_b")
	.dwattr $C$DW$27, DW_AT_location[DW_OP_addr _b]
	.dwattr $C$DW$27, DW_AT_type(*$C$DW$T$35)
	.dwattr $C$DW$27, DW_AT_external
	.dwattr $C$DW$27, DW_AT_decl_file("../main.c")
	.dwattr $C$DW$27, DW_AT_decl_line(0x24)
	.dwattr $C$DW$27, DW_AT_decl_column(0x07)
	.global	_y
	.bss	_y,255,0,0
$C$DW$28	.dwtag  DW_TAG_variable, DW_AT_name("y")
	.dwattr $C$DW$28, DW_AT_TI_symbol_name("_y")
	.dwattr $C$DW$28, DW_AT_location[DW_OP_addr _y]
	.dwattr $C$DW$28, DW_AT_type(*$C$DW$T$35)
	.dwattr $C$DW$28, DW_AT_external
	.dwattr $C$DW$28, DW_AT_decl_file("../main.c")
	.dwattr $C$DW$28, DW_AT_decl_line(0x25)
	.dwattr $C$DW$28, DW_AT_decl_column(0x07)
	.global	_i
	.bss	_i,1,0,0
$C$DW$29	.dwtag  DW_TAG_variable, DW_AT_name("i")
	.dwattr $C$DW$29, DW_AT_TI_symbol_name("_i")
	.dwattr $C$DW$29, DW_AT_location[DW_OP_addr _i]
	.dwattr $C$DW$29, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$29, DW_AT_external
	.dwattr $C$DW$29, DW_AT_decl_file("../main.c")
	.dwattr $C$DW$29, DW_AT_decl_line(0x26)
	.dwattr $C$DW$29, DW_AT_decl_column(0x07)
;	C:\Program Files\TexasInstruments\ccsv4\tools\compiler\c5500\bin\acp55.exe -@C:\Users\Kiis\AppData\Local\Temp\1508412 
	.sect	".text"
	.global	_AIC3204_rset

$C$DW$30	.dwtag  DW_TAG_subprogram, DW_AT_name("AIC3204_rset")
	.dwattr $C$DW$30, DW_AT_low_pc(_AIC3204_rset)
	.dwattr $C$DW$30, DW_AT_high_pc(0x00)
	.dwattr $C$DW$30, DW_AT_TI_symbol_name("_AIC3204_rset")
	.dwattr $C$DW$30, DW_AT_external
	.dwattr $C$DW$30, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$30, DW_AT_TI_begin_file("..\aic3204_setup.h")
	.dwattr $C$DW$30, DW_AT_TI_begin_line(0x07)
	.dwattr $C$DW$30, DW_AT_TI_begin_column(0x07)
	.dwattr $C$DW$30, DW_AT_decl_file("..\aic3204_setup.h")
	.dwattr $C$DW$30, DW_AT_decl_line(0x07)
	.dwattr $C$DW$30, DW_AT_decl_column(0x07)
	.dwattr $C$DW$30, DW_AT_TI_max_frame_size(0x06)
	.dwpsn	file "..\aic3204_setup.h",line 8,column 1,is_stmt,address _AIC3204_rset

	.dwfde $C$DW$CIE, _AIC3204_rset
$C$DW$31	.dwtag  DW_TAG_formal_parameter, DW_AT_name("regnum")
	.dwattr $C$DW$31, DW_AT_TI_symbol_name("_regnum")
	.dwattr $C$DW$31, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$31, DW_AT_location[DW_OP_reg12]
$C$DW$32	.dwtag  DW_TAG_formal_parameter, DW_AT_name("regval")
	.dwattr $C$DW$32, DW_AT_TI_symbol_name("_regval")
	.dwattr $C$DW$32, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$32, DW_AT_location[DW_OP_reg13]
;----------------------------------------------------------------------
;   7 | Int16 AIC3204_rset( Uint16 regnum, Uint16 regval )                     
;----------------------------------------------------------------------
;*******************************************************************************
;* FUNCTION NAME: AIC3204_rset                                                 *
;*                                                                             *
;*   Function Uses Regs : AC0,AC0,T0,T1,AR0,XAR0,AR1,SP,M40,SATA,SATD,RDM,FRCT,*
;*                        SMUL                                                 *
;*   Stack Frame        : Compact (No Frame Pointer, w/ debug)                 *
;*   Total Frame Size   : 6 words                                              *
;*                        (2 return address/alignment)                         *
;*                        (4 local values)                                     *
;*   Min System Stack   : 1 word                                               *
;*******************************************************************************
_AIC3204_rset:
	.dwcfi	cfa_offset, 1
	.dwcfi	save_reg_to_mem, 91, -1
        AADD #-5, SP
	.dwcfi	cfa_offset, 6
$C$DW$33	.dwtag  DW_TAG_variable, DW_AT_name("regnum")
	.dwattr $C$DW$33, DW_AT_TI_symbol_name("_regnum")
	.dwattr $C$DW$33, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$33, DW_AT_location[DW_OP_bregx 0x24 0]
$C$DW$34	.dwtag  DW_TAG_variable, DW_AT_name("regval")
	.dwattr $C$DW$34, DW_AT_TI_symbol_name("_regval")
	.dwattr $C$DW$34, DW_AT_type(*$C$DW$T$9)
	.dwattr $C$DW$34, DW_AT_location[DW_OP_bregx 0x24 1]
$C$DW$35	.dwtag  DW_TAG_variable, DW_AT_name("cmd")
	.dwattr $C$DW$35, DW_AT_TI_symbol_name("_cmd")
	.dwattr $C$DW$35, DW_AT_type(*$C$DW$T$25)
	.dwattr $C$DW$35, DW_AT_location[DW_OP_bregx 0x24 2]
;----------------------------------------------------------------------
;   9 | Uint8 cmd[2];                                                          
;----------------------------------------------------------------------
        MOV T1, *SP(#1) ; |8| 
        MOV T0, *SP(#0) ; |8| 
	.dwpsn	file "..\aic3204_setup.h",line 10,column 5,is_stmt
;----------------------------------------------------------------------
;  10 | cmd[0] = regnum & 0x007F;       // 7-bit Register Address              
;----------------------------------------------------------------------
        MOV T0, AR1
        AND #0x007f, AR1, AC0 ; |10| 
        MOV AC0, *SP(#2) ; |10| 
	.dwpsn	file "..\aic3204_setup.h",line 11,column 5,is_stmt
;----------------------------------------------------------------------
;  11 | cmd[1] = regval;                // 8-bit Register Data                 
;----------------------------------------------------------------------
        MOV *SP(#1), AR1 ; |11| 
        MOV AR1, *SP(#3) ; |11| 
	.dwpsn	file "..\aic3204_setup.h",line 13,column 5,is_stmt
;----------------------------------------------------------------------
;  13 | return USBSTK5515_I2C_write( AIC3204_I2C_ADDR, cmd, 2 );               
;----------------------------------------------------------------------
        AMAR *SP(#2), XAR0

        MOV #24, T0 ; |13| 
||      MOV #2, T1

$C$DW$36	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$36, DW_AT_low_pc(0x00)
	.dwattr $C$DW$36, DW_AT_name("_USBSTK5515_I2C_write")
	.dwattr $C$DW$36, DW_AT_TI_call
        CALL #_USBSTK5515_I2C_write ; |13| 
                                        ; call occurs [#_USBSTK5515_I2C_write] ; |13| 
	.dwpsn	file "..\aic3204_setup.h",line 14,column 1,is_stmt
        AADD #5, SP
	.dwcfi	cfa_offset, 1
$C$DW$37	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$37, DW_AT_low_pc(0x00)
	.dwattr $C$DW$37, DW_AT_TI_return
        RET
                                        ; return occurs
	.dwattr $C$DW$30, DW_AT_TI_end_file("..\aic3204_setup.h")
	.dwattr $C$DW$30, DW_AT_TI_end_line(0x0e)
	.dwattr $C$DW$30, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$30

	.sect	".text"
	.global	_AIC3204_Init

$C$DW$38	.dwtag  DW_TAG_subprogram, DW_AT_name("AIC3204_Init")
	.dwattr $C$DW$38, DW_AT_low_pc(_AIC3204_Init)
	.dwattr $C$DW$38, DW_AT_high_pc(0x00)
	.dwattr $C$DW$38, DW_AT_TI_symbol_name("_AIC3204_Init")
	.dwattr $C$DW$38, DW_AT_external
	.dwattr $C$DW$38, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$38, DW_AT_TI_begin_file("..\aic3204_setup.h")
	.dwattr $C$DW$38, DW_AT_TI_begin_line(0x12)
	.dwattr $C$DW$38, DW_AT_TI_begin_column(0x07)
	.dwattr $C$DW$38, DW_AT_decl_file("..\aic3204_setup.h")
	.dwattr $C$DW$38, DW_AT_decl_line(0x12)
	.dwattr $C$DW$38, DW_AT_decl_column(0x07)
	.dwattr $C$DW$38, DW_AT_TI_max_frame_size(0x02)
	.dwpsn	file "..\aic3204_setup.h",line 19,column 1,is_stmt,address _AIC3204_Init

	.dwfde $C$DW$CIE, _AIC3204_Init
;----------------------------------------------------------------------
;  18 | Int16 AIC3204_Init(void)                                               
;----------------------------------------------------------------------
;*******************************************************************************
;* FUNCTION NAME: AIC3204_Init                                                 *
;*                                                                             *
;*   Function Uses Regs : AC0,AC0,T0,T1,SP,M40,SATA,SATD,RDM,FRCT,SMUL         *
;*   Stack Frame        : Compact (No Frame Pointer, w/ debug)                 *
;*   Total Frame Size   : 2 words                                              *
;*                        (2 return address/alignment)                         *
;*   Min System Stack   : 1 word                                               *
;*******************************************************************************
_AIC3204_Init:
	.dwcfi	cfa_offset, 1
	.dwcfi	save_reg_to_mem, 91, -1
        AADD #-1, SP
	.dwcfi	cfa_offset, 2
	.dwpsn	file "..\aic3204_setup.h",line 21,column 5,is_stmt
;----------------------------------------------------------------------
;  21 | AIC3204_rset( 0, 0 );          // Select page 0                        
;----------------------------------------------------------------------
        MOV #0, T0
$C$DW$39	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$39, DW_AT_low_pc(0x00)
	.dwattr $C$DW$39, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$39, DW_AT_TI_call

        CALL #_AIC3204_rset ; |21| 
||      MOV #0, T1

                                        ; call occurs [#_AIC3204_rset] ; |21| 
	.dwpsn	file "..\aic3204_setup.h",line 22,column 5,is_stmt
;----------------------------------------------------------------------
;  22 | AIC3204_rset( 1, 1 );          // Reset codec                          
;----------------------------------------------------------------------
        MOV #1, T0
$C$DW$40	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$40, DW_AT_low_pc(0x00)
	.dwattr $C$DW$40, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$40, DW_AT_TI_call

        CALL #_AIC3204_rset ; |22| 
||      MOV #1, T1

                                        ; call occurs [#_AIC3204_rset] ; |22| 
	.dwpsn	file "..\aic3204_setup.h",line 23,column 5,is_stmt
;----------------------------------------------------------------------
;  23 | AIC3204_rset( 0, 1 );          // Select page 1                        
;----------------------------------------------------------------------
        MOV #0, T0
$C$DW$41	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$41, DW_AT_low_pc(0x00)
	.dwattr $C$DW$41, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$41, DW_AT_TI_call

        CALL #_AIC3204_rset ; |23| 
||      MOV #1, T1

                                        ; call occurs [#_AIC3204_rset] ; |23| 
	.dwpsn	file "..\aic3204_setup.h",line 24,column 5,is_stmt
;----------------------------------------------------------------------
;  24 | AIC3204_rset( 1, 8 );          // Disable crude AVDD generation from DV
;     | DD                                                                     
;----------------------------------------------------------------------
        MOV #1, T0
$C$DW$42	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$42, DW_AT_low_pc(0x00)
	.dwattr $C$DW$42, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$42, DW_AT_TI_call

        CALL #_AIC3204_rset ; |24| 
||      MOV #8, T1

                                        ; call occurs [#_AIC3204_rset] ; |24| 
	.dwpsn	file "..\aic3204_setup.h",line 25,column 5,is_stmt
;----------------------------------------------------------------------
;  25 | AIC3204_rset( 2, 1 );          // Enable Analog Blocks, use LDO power  
;----------------------------------------------------------------------
        MOV #2, T0
$C$DW$43	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$43, DW_AT_low_pc(0x00)
	.dwattr $C$DW$43, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$43, DW_AT_TI_call

        CALL #_AIC3204_rset ; |25| 
||      MOV #1, T1

                                        ; call occurs [#_AIC3204_rset] ; |25| 
	.dwpsn	file "..\aic3204_setup.h",line 26,column 5,is_stmt
;----------------------------------------------------------------------
;  26 | AIC3204_rset( 0, 0 );          // Select page 0                        
;----------------------------------------------------------------------
        MOV #0, T0
$C$DW$44	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$44, DW_AT_low_pc(0x00)
	.dwattr $C$DW$44, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$44, DW_AT_TI_call

        CALL #_AIC3204_rset ; |26| 
||      MOV #0, T1

                                        ; call occurs [#_AIC3204_rset] ; |26| 
	.dwpsn	file "..\aic3204_setup.h",line 28,column 5,is_stmt
;----------------------------------------------------------------------
;  28 | AIC3204_rset( 27, BCLK );      // BCLK and WCLK is set as o/p to AIC320
;     | 4(Master)                                                              
;----------------------------------------------------------------------
        MOV #27, T0 ; |28| 
        MOV *(#_BCLK), T1 ; |28| 
$C$DW$45	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$45, DW_AT_low_pc(0x00)
	.dwattr $C$DW$45, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$45, DW_AT_TI_call
        CALL #_AIC3204_rset ; |28| 
                                        ; call occurs [#_AIC3204_rset] ; |28| 
	.dwpsn	file "..\aic3204_setup.h",line 29,column 5,is_stmt
;----------------------------------------------------------------------
;  29 | AIC3204_rset( 28, 0x00 );      // Data ofset = 0                       
;----------------------------------------------------------------------
        MOV #28, T0 ; |29| 
$C$DW$46	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$46, DW_AT_low_pc(0x00)
	.dwattr $C$DW$46, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$46, DW_AT_TI_call

        CALL #_AIC3204_rset ; |29| 
||      MOV #0, T1

                                        ; call occurs [#_AIC3204_rset] ; |29| 
	.dwpsn	file "..\aic3204_setup.h",line 30,column 5,is_stmt
;----------------------------------------------------------------------
;  30 | AIC3204_rset( 4, 3 );          // PLL setting: PLLCLK <- MCLK, CODEC_CL
;     | KIN <-PLL CLK                                                          
;----------------------------------------------------------------------
        MOV #4, T0
$C$DW$47	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$47, DW_AT_low_pc(0x00)
	.dwattr $C$DW$47, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$47, DW_AT_TI_call

        CALL #_AIC3204_rset ; |30| 
||      MOV #3, T1

                                        ; call occurs [#_AIC3204_rset] ; |30| 
	.dwpsn	file "..\aic3204_setup.h",line 31,column 5,is_stmt
;----------------------------------------------------------------------
;  31 | AIC3204_rset( 6, J );          // PLL setting: J=7                     
;----------------------------------------------------------------------
        MOV *(#_J), T1 ; |31| 
$C$DW$48	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$48, DW_AT_low_pc(0x00)
	.dwattr $C$DW$48, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$48, DW_AT_TI_call

        CALL #_AIC3204_rset ; |31| 
||      MOV #6, T0

                                        ; call occurs [#_AIC3204_rset] ; |31| 
	.dwpsn	file "..\aic3204_setup.h",line 32,column 5,is_stmt
;----------------------------------------------------------------------
;  32 | AIC3204_rset( 7, Dhigh );       // PLL setting: HI_BYTE(D=1680)        
;----------------------------------------------------------------------
        MOV *(#_Dhigh), T1 ; |32| 
$C$DW$49	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$49, DW_AT_low_pc(0x00)
	.dwattr $C$DW$49, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$49, DW_AT_TI_call

        CALL #_AIC3204_rset ; |32| 
||      MOV #7, T0

                                        ; call occurs [#_AIC3204_rset] ; |32| 
	.dwpsn	file "..\aic3204_setup.h",line 33,column 5,is_stmt
;----------------------------------------------------------------------
;  33 | AIC3204_rset( 8, Dlow );       // PLL setting: LO_BYTE(D=1680)         
;----------------------------------------------------------------------
        MOV *(#_Dlow), T1 ; |33| 
$C$DW$50	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$50, DW_AT_low_pc(0x00)
	.dwattr $C$DW$50, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$50, DW_AT_TI_call

        CALL #_AIC3204_rset ; |33| 
||      MOV #8, T0

                                        ; call occurs [#_AIC3204_rset] ; |33| 
	.dwpsn	file "..\aic3204_setup.h",line 34,column 5,is_stmt
;----------------------------------------------------------------------
;  34 | AIC3204_rset( 30, BCLKN );      // For 32 bit clocks per frame in Maste
;     | r mode ONLY                                                            
;  35 |                                // BCLK=DAC_CLK/N =(12288000/8) = 1.536M
;     | Hz = 32*fs                                                             
;----------------------------------------------------------------------
        MOV #30, T0 ; |34| 
        MOV *(#_BCLKN), T1 ; |34| 
$C$DW$51	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$51, DW_AT_low_pc(0x00)
	.dwattr $C$DW$51, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$51, DW_AT_TI_call
        CALL #_AIC3204_rset ; |34| 
                                        ; call occurs [#_AIC3204_rset] ; |34| 
	.dwpsn	file "..\aic3204_setup.h",line 36,column 5,is_stmt
;----------------------------------------------------------------------
;  36 | AIC3204_rset( 5, 0x91 );       // PLL setting: Power up PLL, P=1 and R=
;     | 1                                                                      
;----------------------------------------------------------------------
        MOV #145, T1 ; |36| 
$C$DW$52	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$52, DW_AT_low_pc(0x00)
	.dwattr $C$DW$52, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$52, DW_AT_TI_call

        CALL #_AIC3204_rset ; |36| 
||      MOV #5, T0

                                        ; call occurs [#_AIC3204_rset] ; |36| 
	.dwpsn	file "..\aic3204_setup.h",line 37,column 5,is_stmt
;----------------------------------------------------------------------
;  37 | AIC3204_rset( 13, 0 );         // Hi_Byte(DOSR) for DOSR = 128 decimal
;     | or 0x0080 DAC oversamppling                                            
;----------------------------------------------------------------------
        MOV #13, T0
$C$DW$53	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$53, DW_AT_low_pc(0x00)
	.dwattr $C$DW$53, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$53, DW_AT_TI_call

        CALL #_AIC3204_rset ; |37| 
||      MOV #0, T1

                                        ; call occurs [#_AIC3204_rset] ; |37| 
	.dwpsn	file "..\aic3204_setup.h",line 38,column 5,is_stmt
;----------------------------------------------------------------------
;  38 | AIC3204_rset( 14, Reg14 );      // Lo_Byte(DOSR) for DOSR = 128 decimal
;     |  or 0x0080                                                             
;----------------------------------------------------------------------
        MOV *(#_Reg14), T1 ; |38| 
$C$DW$54	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$54, DW_AT_low_pc(0x00)
	.dwattr $C$DW$54, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$54, DW_AT_TI_call

        CALL #_AIC3204_rset ; |38| 
||      MOV #14, T0

                                        ; call occurs [#_AIC3204_rset] ; |38| 
	.dwpsn	file "..\aic3204_setup.h",line 39,column 5,is_stmt
;----------------------------------------------------------------------
;  39 | AIC3204_rset( 20, Reg20 );      // AOSR for AOSR = 128 decimal or 0x008
;     | 0 for decimation filters 1 to 6                                        
;----------------------------------------------------------------------
        MOV #20, T0 ; |39| 
        MOV *(#_Reg20), T1 ; |39| 
$C$DW$55	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$55, DW_AT_low_pc(0x00)
	.dwattr $C$DW$55, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$55, DW_AT_TI_call
        CALL #_AIC3204_rset ; |39| 
                                        ; call occurs [#_AIC3204_rset] ; |39| 
	.dwpsn	file "..\aic3204_setup.h",line 40,column 5,is_stmt
;----------------------------------------------------------------------
;  40 | AIC3204_rset( 11, Reg11 );      // Power up NDAC and set NDAC value to
;     | 2 (0x82)                                                               
;----------------------------------------------------------------------
        MOV *(#_Reg11), T1 ; |40| 
$C$DW$56	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$56, DW_AT_low_pc(0x00)
	.dwattr $C$DW$56, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$56, DW_AT_TI_call

        CALL #_AIC3204_rset ; |40| 
||      MOV #11, T0

                                        ; call occurs [#_AIC3204_rset] ; |40| 
	.dwpsn	file "..\aic3204_setup.h",line 41,column 5,is_stmt
;----------------------------------------------------------------------
;  41 | AIC3204_rset( 12, Reg12 );      // Power up MDAC and set MDAC value to
;     | 7                                                                      
;----------------------------------------------------------------------
        MOV *(#_Reg12), T1 ; |41| 
$C$DW$57	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$57, DW_AT_low_pc(0x00)
	.dwattr $C$DW$57, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$57, DW_AT_TI_call

        CALL #_AIC3204_rset ; |41| 
||      MOV #12, T0

                                        ; call occurs [#_AIC3204_rset] ; |41| 
	.dwpsn	file "..\aic3204_setup.h",line 42,column 5,is_stmt
;----------------------------------------------------------------------
;  42 | AIC3204_rset( 18, Reg18 );      // Power up NADC and set NADC value to
;     | 7                                                                      
;----------------------------------------------------------------------
        MOV #18, T0 ; |42| 
        MOV *(#_Reg18), T1 ; |42| 
$C$DW$58	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$58, DW_AT_low_pc(0x00)
	.dwattr $C$DW$58, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$58, DW_AT_TI_call
        CALL #_AIC3204_rset ; |42| 
                                        ; call occurs [#_AIC3204_rset] ; |42| 
	.dwpsn	file "..\aic3204_setup.h",line 43,column 5,is_stmt
;----------------------------------------------------------------------
;  43 | AIC3204_rset( 19, Reg19 );      // Power up MADC and set MADC value to
;     | 2 (0x82)                                                               
;----------------------------------------------------------------------
        MOV #19, T0 ; |43| 
        MOV *(#_Reg19), T1 ; |43| 
$C$DW$59	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$59, DW_AT_low_pc(0x00)
	.dwattr $C$DW$59, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$59, DW_AT_TI_call
        CALL #_AIC3204_rset ; |43| 
                                        ; call occurs [#_AIC3204_rset] ; |43| 
	.dwpsn	file "..\aic3204_setup.h",line 47,column 5,is_stmt
;----------------------------------------------------------------------
;  47 | AIC3204_rset(  0, 0x01 );      // Select page 1                        
;----------------------------------------------------------------------
        MOV #0, T0
$C$DW$60	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$60, DW_AT_low_pc(0x00)
	.dwattr $C$DW$60, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$60, DW_AT_TI_call

        CALL #_AIC3204_rset ; |47| 
||      MOV #1, T1

                                        ; call occurs [#_AIC3204_rset] ; |47| 
	.dwpsn	file "..\aic3204_setup.h",line 48,column 5,is_stmt
;----------------------------------------------------------------------
;  48 | AIC3204_rset( 12, 0x08 );      // LDAC AFIR routed to HPL              
;----------------------------------------------------------------------
        MOV #12, T0
$C$DW$61	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$61, DW_AT_low_pc(0x00)
	.dwattr $C$DW$61, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$61, DW_AT_TI_call

        CALL #_AIC3204_rset ; |48| 
||      MOV #8, T1

                                        ; call occurs [#_AIC3204_rset] ; |48| 
	.dwpsn	file "..\aic3204_setup.h",line 49,column 5,is_stmt
;----------------------------------------------------------------------
;  49 | AIC3204_rset( 13, 0x08 );      // RDAC AFIR routed to HPR              
;----------------------------------------------------------------------
        MOV #13, T0
$C$DW$62	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$62, DW_AT_low_pc(0x00)
	.dwattr $C$DW$62, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$62, DW_AT_TI_call

        CALL #_AIC3204_rset ; |49| 
||      MOV #8, T1

                                        ; call occurs [#_AIC3204_rset] ; |49| 
	.dwpsn	file "..\aic3204_setup.h",line 50,column 5,is_stmt
;----------------------------------------------------------------------
;  50 | AIC3204_rset(  0, 0x00 );      // Select page 0                        
;----------------------------------------------------------------------
        MOV #0, T0
$C$DW$63	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$63, DW_AT_low_pc(0x00)
	.dwattr $C$DW$63, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$63, DW_AT_TI_call

        CALL #_AIC3204_rset ; |50| 
||      MOV #0, T1

                                        ; call occurs [#_AIC3204_rset] ; |50| 
	.dwpsn	file "..\aic3204_setup.h",line 51,column 5,is_stmt
;----------------------------------------------------------------------
;  51 | AIC3204_rset( 64, 0x02 );      // Left vol=right vol                   
;----------------------------------------------------------------------
        MOV #64, T0 ; |51| 
$C$DW$64	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$64, DW_AT_low_pc(0x00)
	.dwattr $C$DW$64, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$64, DW_AT_TI_call

        CALL #_AIC3204_rset ; |51| 
||      MOV #2, T1

                                        ; call occurs [#_AIC3204_rset] ; |51| 
	.dwpsn	file "..\aic3204_setup.h",line 52,column 5,is_stmt
;----------------------------------------------------------------------
;  52 | AIC3204_rset( 65, 0x00 );      // Left DAC gain to 0dB VOL; Right track
;     | s Left                                                                 
;----------------------------------------------------------------------
        MOV #65, T0 ; |52| 
$C$DW$65	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$65, DW_AT_low_pc(0x00)
	.dwattr $C$DW$65, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$65, DW_AT_TI_call

        CALL #_AIC3204_rset ; |52| 
||      MOV #0, T1

                                        ; call occurs [#_AIC3204_rset] ; |52| 
	.dwpsn	file "..\aic3204_setup.h",line 53,column 5,is_stmt
;----------------------------------------------------------------------
;  53 | AIC3204_rset( 63, 0xd4 );      // Power up left,right data paths and se
;     | t channel                                                              
;----------------------------------------------------------------------
        MOV #212, T1 ; |53| 
        MOV #63, T0 ; |53| 
$C$DW$66	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$66, DW_AT_low_pc(0x00)
	.dwattr $C$DW$66, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$66, DW_AT_TI_call
        CALL #_AIC3204_rset ; |53| 
                                        ; call occurs [#_AIC3204_rset] ; |53| 
	.dwpsn	file "..\aic3204_setup.h",line 54,column 5,is_stmt
;----------------------------------------------------------------------
;  54 | AIC3204_rset(  0, 0x01 );      // Select page 1                        
;----------------------------------------------------------------------
        MOV #0, T0
$C$DW$67	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$67, DW_AT_low_pc(0x00)
	.dwattr $C$DW$67, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$67, DW_AT_TI_call

        CALL #_AIC3204_rset ; |54| 
||      MOV #1, T1

                                        ; call occurs [#_AIC3204_rset] ; |54| 
	.dwpsn	file "..\aic3204_setup.h",line 55,column 5,is_stmt
;----------------------------------------------------------------------
;  55 | AIC3204_rset( 16, 0x00 );      // Unmute HPL , 0dB gain                
;----------------------------------------------------------------------
        MOV #16, T0 ; |55| 
$C$DW$68	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$68, DW_AT_low_pc(0x00)
	.dwattr $C$DW$68, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$68, DW_AT_TI_call

        CALL #_AIC3204_rset ; |55| 
||      MOV #0, T1

                                        ; call occurs [#_AIC3204_rset] ; |55| 
	.dwpsn	file "..\aic3204_setup.h",line 56,column 5,is_stmt
;----------------------------------------------------------------------
;  56 | AIC3204_rset( 17, 0x00 );      // Unmute HPR , 0dB gain                
;----------------------------------------------------------------------
        MOV #17, T0 ; |56| 
$C$DW$69	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$69, DW_AT_low_pc(0x00)
	.dwattr $C$DW$69, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$69, DW_AT_TI_call

        CALL #_AIC3204_rset ; |56| 
||      MOV #0, T1

                                        ; call occurs [#_AIC3204_rset] ; |56| 
	.dwpsn	file "..\aic3204_setup.h",line 57,column 5,is_stmt
;----------------------------------------------------------------------
;  57 | AIC3204_rset(  9, 0x30 );      // Power up HPL,HPR                     
;----------------------------------------------------------------------
        MOV #48, T1 ; |57| 
$C$DW$70	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$70, DW_AT_low_pc(0x00)
	.dwattr $C$DW$70, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$70, DW_AT_TI_call

        CALL #_AIC3204_rset ; |57| 
||      MOV #9, T0

                                        ; call occurs [#_AIC3204_rset] ; |57| 
	.dwpsn	file "..\aic3204_setup.h",line 58,column 5,is_stmt
;----------------------------------------------------------------------
;  58 | AIC3204_rset(  0, 0x00 );      // Select page 0                        
;----------------------------------------------------------------------
        MOV #0, T0
$C$DW$71	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$71, DW_AT_low_pc(0x00)
	.dwattr $C$DW$71, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$71, DW_AT_TI_call

        CALL #_AIC3204_rset ; |58| 
||      MOV #0, T1

                                        ; call occurs [#_AIC3204_rset] ; |58| 
	.dwpsn	file "..\aic3204_setup.h",line 59,column 5,is_stmt
;----------------------------------------------------------------------
;  59 | USBSTK5515_wait( 500 );        // Wait                                 
;----------------------------------------------------------------------
        MOV #500, AC0 ; |59| 
$C$DW$72	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$72, DW_AT_low_pc(0x00)
	.dwattr $C$DW$72, DW_AT_name("_USBSTK5515_wait")
	.dwattr $C$DW$72, DW_AT_TI_call
        CALL #_USBSTK5515_wait ; |59| 
                                        ; call occurs [#_USBSTK5515_wait] ; |59| 
	.dwpsn	file "..\aic3204_setup.h",line 62,column 5,is_stmt
;----------------------------------------------------------------------
;  62 | AIC3204_rset( 0, 1 );          // Select page 1                        
;----------------------------------------------------------------------
        MOV #0, T0
$C$DW$73	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$73, DW_AT_low_pc(0x00)
	.dwattr $C$DW$73, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$73, DW_AT_TI_call

        CALL #_AIC3204_rset ; |62| 
||      MOV #1, T1

                                        ; call occurs [#_AIC3204_rset] ; |62| 
	.dwpsn	file "..\aic3204_setup.h",line 63,column 5,is_stmt
;----------------------------------------------------------------------
;  63 | AIC3204_rset( 0x34, 0x30 );    // STEREO 1 Jack                        
;  64 |                                        // IN2_L to LADC_P through 40 ko
;     | hm                                                                     
;----------------------------------------------------------------------
        MOV #48, T1 ; |63| 
        MOV #52, T0 ; |63| 
$C$DW$74	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$74, DW_AT_low_pc(0x00)
	.dwattr $C$DW$74, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$74, DW_AT_TI_call
        CALL #_AIC3204_rset ; |63| 
                                        ; call occurs [#_AIC3204_rset] ; |63| 
	.dwpsn	file "..\aic3204_setup.h",line 65,column 5,is_stmt
;----------------------------------------------------------------------
;  65 | AIC3204_rset( 0x37, 0x30 );    // IN2_R to RADC_P through 40 kohmm     
;----------------------------------------------------------------------
        MOV #48, T1 ; |65| 
        MOV #55, T0 ; |65| 
$C$DW$75	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$75, DW_AT_low_pc(0x00)
	.dwattr $C$DW$75, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$75, DW_AT_TI_call
        CALL #_AIC3204_rset ; |65| 
                                        ; call occurs [#_AIC3204_rset] ; |65| 
	.dwpsn	file "..\aic3204_setup.h",line 66,column 5,is_stmt
;----------------------------------------------------------------------
;  66 | AIC3204_rset( 0x36, 3 );       // CM_1 (common mode) to LADC_M through
;     | 40 kohm                                                                
;----------------------------------------------------------------------
        MOV #54, T0 ; |66| 
$C$DW$76	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$76, DW_AT_low_pc(0x00)
	.dwattr $C$DW$76, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$76, DW_AT_TI_call

        CALL #_AIC3204_rset ; |66| 
||      MOV #3, T1

                                        ; call occurs [#_AIC3204_rset] ; |66| 
	.dwpsn	file "..\aic3204_setup.h",line 67,column 5,is_stmt
;----------------------------------------------------------------------
;  67 | AIC3204_rset( 0x39, 0xc0 );    // CM_1 (common mode) to RADC_M through
;     | 40 kohm                                                                
;----------------------------------------------------------------------
        MOV #192, T1 ; |67| 
        MOV #57, T0 ; |67| 
$C$DW$77	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$77, DW_AT_low_pc(0x00)
	.dwattr $C$DW$77, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$77, DW_AT_TI_call
        CALL #_AIC3204_rset ; |67| 
                                        ; call occurs [#_AIC3204_rset] ; |67| 
	.dwpsn	file "..\aic3204_setup.h",line 68,column 5,is_stmt
;----------------------------------------------------------------------
;  68 | AIC3204_rset( 0x3b, 0 );       // MIC_PGA_L unmute                     
;----------------------------------------------------------------------
        MOV #59, T0 ; |68| 
$C$DW$78	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$78, DW_AT_low_pc(0x00)
	.dwattr $C$DW$78, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$78, DW_AT_TI_call

        CALL #_AIC3204_rset ; |68| 
||      MOV #0, T1

                                        ; call occurs [#_AIC3204_rset] ; |68| 
	.dwpsn	file "..\aic3204_setup.h",line 69,column 5,is_stmt
;----------------------------------------------------------------------
;  69 | AIC3204_rset( 0x3c, 0 );       // MIC_PGA_R unmute                     
;----------------------------------------------------------------------
        MOV #60, T0 ; |69| 
$C$DW$79	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$79, DW_AT_low_pc(0x00)
	.dwattr $C$DW$79, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$79, DW_AT_TI_call

        CALL #_AIC3204_rset ; |69| 
||      MOV #0, T1

                                        ; call occurs [#_AIC3204_rset] ; |69| 
	.dwpsn	file "..\aic3204_setup.h",line 70,column 5,is_stmt
;----------------------------------------------------------------------
;  70 | AIC3204_rset( 0, 0 );          // Select page 0                        
;----------------------------------------------------------------------
        MOV #0, T0
$C$DW$80	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$80, DW_AT_low_pc(0x00)
	.dwattr $C$DW$80, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$80, DW_AT_TI_call

        CALL #_AIC3204_rset ; |70| 
||      MOV #0, T1

                                        ; call occurs [#_AIC3204_rset] ; |70| 
	.dwpsn	file "..\aic3204_setup.h",line 71,column 5,is_stmt
;----------------------------------------------------------------------
;  71 | AIC3204_rset( 0x51, 0xc0 );    // Powerup Left and Right ADC           
;----------------------------------------------------------------------
        MOV #192, T1 ; |71| 
        MOV #81, T0 ; |71| 
$C$DW$81	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$81, DW_AT_low_pc(0x00)
	.dwattr $C$DW$81, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$81, DW_AT_TI_call
        CALL #_AIC3204_rset ; |71| 
                                        ; call occurs [#_AIC3204_rset] ; |71| 
	.dwpsn	file "..\aic3204_setup.h",line 72,column 5,is_stmt
;----------------------------------------------------------------------
;  72 | AIC3204_rset( 0x52, 0 );       // Unmute Left and Right ADC            
;----------------------------------------------------------------------
        MOV #82, T0 ; |72| 
$C$DW$82	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$82, DW_AT_low_pc(0x00)
	.dwattr $C$DW$82, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$82, DW_AT_TI_call

        CALL #_AIC3204_rset ; |72| 
||      MOV #0, T1

                                        ; call occurs [#_AIC3204_rset] ; |72| 
	.dwpsn	file "..\aic3204_setup.h",line 74,column 5,is_stmt
;----------------------------------------------------------------------
;  74 | AIC3204_rset( 0, 0 );                                                  
;----------------------------------------------------------------------
        MOV #0, T0
$C$DW$83	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$83, DW_AT_low_pc(0x00)
	.dwattr $C$DW$83, DW_AT_name("_AIC3204_rset")
	.dwattr $C$DW$83, DW_AT_TI_call

        CALL #_AIC3204_rset ; |74| 
||      MOV #0, T1

                                        ; call occurs [#_AIC3204_rset] ; |74| 
	.dwpsn	file "..\aic3204_setup.h",line 75,column 5,is_stmt
;----------------------------------------------------------------------
;  75 | USBSTK5515_wait( 200 );        // Wait                                 
;----------------------------------------------------------------------
        MOV #200, AC0 ; |75| 
$C$DW$84	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$84, DW_AT_low_pc(0x00)
	.dwattr $C$DW$84, DW_AT_name("_USBSTK5515_wait")
	.dwattr $C$DW$84, DW_AT_TI_call
        CALL #_USBSTK5515_wait ; |75| 
                                        ; call occurs [#_USBSTK5515_wait] ; |75| 
	.dwpsn	file "..\aic3204_setup.h",line 77,column 5,is_stmt
;----------------------------------------------------------------------
;  77 | I2S0_SRGR = 0x0;                                                       
;----------------------------------------------------------------------
        MOV #0, *port(#10244) ; |77| 
	.dwpsn	file "..\aic3204_setup.h",line 78,column 5,is_stmt
;----------------------------------------------------------------------
;  78 | I2S0_CR = 0x8010;    // 16-bit word, slave, enable I2C                 
;----------------------------------------------------------------------
        MOV #32784, *port(#10240) ; |78| 
	.dwpsn	file "..\aic3204_setup.h",line 79,column 5,is_stmt
;----------------------------------------------------------------------
;  79 | I2S0_ICMR = 0x3f;    // Enable interrupts                              
;----------------------------------------------------------------------
        MOV #63, *port(#10260) ; |79| 
	.dwpsn	file "..\aic3204_setup.h",line 81,column 5,is_stmt
;----------------------------------------------------------------------
;  81 | return 0;                                                              
;----------------------------------------------------------------------
        MOV #0, T0
	.dwpsn	file "..\aic3204_setup.h",line 82,column 1,is_stmt
        AADD #1, SP
	.dwcfi	cfa_offset, 1
$C$DW$85	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$85, DW_AT_low_pc(0x00)
	.dwattr $C$DW$85, DW_AT_TI_return
        RET
                                        ; return occurs
	.dwattr $C$DW$38, DW_AT_TI_end_file("..\aic3204_setup.h")
	.dwattr $C$DW$38, DW_AT_TI_end_line(0x52)
	.dwattr $C$DW$38, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$38

	.sect	".text"
	.global	_codec_init

$C$DW$86	.dwtag  DW_TAG_subprogram, DW_AT_name("codec_init")
	.dwattr $C$DW$86, DW_AT_low_pc(_codec_init)
	.dwattr $C$DW$86, DW_AT_high_pc(0x00)
	.dwattr $C$DW$86, DW_AT_TI_symbol_name("_codec_init")
	.dwattr $C$DW$86, DW_AT_external
	.dwattr $C$DW$86, DW_AT_TI_begin_file("..\aic3204_setup.h")
	.dwattr $C$DW$86, DW_AT_TI_begin_line(0x5a)
	.dwattr $C$DW$86, DW_AT_TI_begin_column(0x06)
	.dwattr $C$DW$86, DW_AT_decl_file("..\aic3204_setup.h")
	.dwattr $C$DW$86, DW_AT_decl_line(0x5a)
	.dwattr $C$DW$86, DW_AT_decl_column(0x06)
	.dwattr $C$DW$86, DW_AT_TI_max_frame_size(0x02)
	.dwpsn	file "..\aic3204_setup.h",line 90,column 22,is_stmt,address _codec_init

	.dwfde $C$DW$CIE, _codec_init
;*******************************************************************************
;* FUNCTION NAME: codec_init                                                   *
;*                                                                             *
;*   Function Uses Regs : SP,M40,SATA,SATD,RDM,FRCT,SMUL                       *
;*   Stack Frame        : Compact (No Frame Pointer, w/ debug)                 *
;*   Total Frame Size   : 2 words                                              *
;*                        (2 return address/alignment)                         *
;*   Min System Stack   : 1 word                                               *
;*******************************************************************************
_codec_init:
;----------------------------------------------------------------------
;  90 | void codec_init(void){                                                 
;----------------------------------------------------------------------
	.dwcfi	cfa_offset, 1
	.dwcfi	save_reg_to_mem, 91, -1
        AADD #-1, SP
	.dwcfi	cfa_offset, 2
	.dwpsn	file "..\aic3204_setup.h",line 94,column 2,is_stmt
;----------------------------------------------------------------------
;  94 | if              (Res == 16){BCLK = 0x0d;}                              
;----------------------------------------------------------------------
	.dwpsn	file "..\aic3204_setup.h",line 94,column 19,is_stmt
;----------------------------------------------------------------------
;  95 | else if (Res == 24){BCLK = 0x2d;}                                      
;  96 | else if (Res == 32){BCLK = 0x3d;}                                      
;  97 | else {BCLK = 0x0d;}                                                    
;----------------------------------------------------------------------
        MOV #13, *(#_BCLK) ; |94| 
	.dwpsn	file "..\aic3204_setup.h",line 94,column 31,is_stmt
        B $C$L1   ; |94| 
                                        ; branch occurs ; |94| 
$C$L1:    
	.dwpsn	file "..\aic3204_setup.h",line 99,column 2,is_stmt
;----------------------------------------------------------------------
;  99 | if              (ADCFs == 48) {J = 0x07; Dlow = 0x90; Dhigh =0x06; BCLK
;     | N = 0x88;                                                              
;----------------------------------------------------------------------
	.dwpsn	file "..\aic3204_setup.h",line 99,column 22,is_stmt
        MOV #7, *(#_J) ; |99| 
	.dwpsn	file "..\aic3204_setup.h",line 99,column 32,is_stmt
        MOV #144, *(#_Dlow) ; |99| 
	.dwpsn	file "..\aic3204_setup.h",line 99,column 45,is_stmt
        MOV #6, *(#_Dhigh) ; |99| 
	.dwpsn	file "..\aic3204_setup.h",line 99,column 58,is_stmt
        MOV #136, *(#_BCLKN) ; |99| 
	.dwpsn	file "..\aic3204_setup.h",line 100,column 8,is_stmt
;----------------------------------------------------------------------
; 100 | Reg11 = 0x82; Reg12 = 0x87; Reg13 = 0; Reg14 = 0x80;                   
;----------------------------------------------------------------------
        MOV #130, *(#_Reg11) ; |100| 
	.dwpsn	file "..\aic3204_setup.h",line 100,column 22,is_stmt
        MOV #135, *(#_Reg12) ; |100| 
	.dwpsn	file "..\aic3204_setup.h",line 100,column 36,is_stmt
        MOV #0, *(#_Reg13) ; |100| 
	.dwpsn	file "..\aic3204_setup.h",line 100,column 47,is_stmt
        MOV #128, *(#_Reg14) ; |100| 
	.dwpsn	file "..\aic3204_setup.h",line 101,column 8,is_stmt
;----------------------------------------------------------------------
; 101 | Reg18 = 0x87; Reg19 = 0x82; Reg20 = 0x80;
;     |                                                                        
;----------------------------------------------------------------------
        MOV #135, *(#_Reg18) ; |101| 
	.dwpsn	file "..\aic3204_setup.h",line 101,column 22,is_stmt
        MOV #130, *(#_Reg19) ; |101| 
	.dwpsn	file "..\aic3204_setup.h",line 101,column 36,is_stmt
        MOV #128, *(#_Reg20) ; |101| 
	.dwpsn	file "..\aic3204_setup.h",line 102,column 8,is_stmt
;----------------------------------------------------------------------
; 103 | else if (ADCFs == 96) {J = 0x0e; Dlow = 0x20; Dhigh =0x0d; BCLKN = 0x84
;     | ;}                                                                     
; 105 | else if (ADCFs == 192){J = 0x08; Dlow = 0x80; Dhigh =0x7; BCLKN = 0x87;
;     |                                                                        
; 106 |                                                 Reg11 = 0x82; Reg12 = 0
;     | x84; Reg13 = 0x0; Reg14 = 64;                                          
; 107 |                                                 Reg18 = 0x82; Reg19 = 0
;     | x84; Reg20 = 64;                                                       
; 109 | else    {J = 0x07; Dlow = 0x90; Dhigh =0x06;}                          
;----------------------------------------------------------------------
        B $C$L2   ; |102| 
                                        ; branch occurs ; |102| 
$C$L2:    
	.dwpsn	file "..\aic3204_setup.h",line 113,column 2,is_stmt
;----------------------------------------------------------------------
; 113 | AIC3204_Init();                                                        
;----------------------------------------------------------------------
$C$DW$87	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$87, DW_AT_low_pc(0x00)
	.dwattr $C$DW$87, DW_AT_name("_AIC3204_Init")
	.dwattr $C$DW$87, DW_AT_TI_call
        CALL #_AIC3204_Init ; |113| 
                                        ; call occurs [#_AIC3204_Init] ; |113| 
	.dwpsn	file "..\aic3204_setup.h",line 115,column 1,is_stmt
        AADD #1, SP
	.dwcfi	cfa_offset, 1
$C$DW$88	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$88, DW_AT_low_pc(0x00)
	.dwattr $C$DW$88, DW_AT_TI_return
        RET
                                        ; return occurs
	.dwattr $C$DW$86, DW_AT_TI_end_file("..\aic3204_setup.h")
	.dwattr $C$DW$86, DW_AT_TI_end_line(0x73)
	.dwattr $C$DW$86, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$86

	.sect	".text"
	.global	_main

$C$DW$89	.dwtag  DW_TAG_subprogram, DW_AT_name("main")
	.dwattr $C$DW$89, DW_AT_low_pc(_main)
	.dwattr $C$DW$89, DW_AT_high_pc(0x00)
	.dwattr $C$DW$89, DW_AT_TI_symbol_name("_main")
	.dwattr $C$DW$89, DW_AT_external
	.dwattr $C$DW$89, DW_AT_TI_begin_file("../main.c")
	.dwattr $C$DW$89, DW_AT_TI_begin_line(0x2c)
	.dwattr $C$DW$89, DW_AT_TI_begin_column(0x06)
	.dwattr $C$DW$89, DW_AT_decl_file("../main.c")
	.dwattr $C$DW$89, DW_AT_decl_line(0x2c)
	.dwattr $C$DW$89, DW_AT_decl_column(0x06)
	.dwattr $C$DW$89, DW_AT_TI_max_frame_size(0x02)
	.dwpsn	file "../main.c",line 45,column 1,is_stmt,address _main

	.dwfde $C$DW$CIE, _main
;----------------------------------------------------------------------
;  44 | void main( void )                                                      
;----------------------------------------------------------------------
;*******************************************************************************
;* FUNCTION NAME: main                                                         *
;*                                                                             *
;*   Function Uses Regs : T0,AR1,AR3,XAR3,SP,CARRY,TC1,M40,SATA,SATD,RDM,FRCT, *
;*                        SMUL                                                 *
;*   Stack Frame        : Compact (No Frame Pointer, w/ debug)                 *
;*   Total Frame Size   : 2 words                                              *
;*                        (2 return address/alignment)                         *
;*   Min System Stack   : 1 word                                               *
;*******************************************************************************
_main:
	.dwcfi	cfa_offset, 1
	.dwcfi	save_reg_to_mem, 91, -1
        AADD #-1, SP
	.dwcfi	cfa_offset, 2
	.dwpsn	file "../main.c",line 47,column 5,is_stmt
;----------------------------------------------------------------------
;  47 | USBSTK5515_init( );                                                    
;----------------------------------------------------------------------
$C$DW$90	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$90, DW_AT_low_pc(0x00)
	.dwattr $C$DW$90, DW_AT_name("_USBSTK5515_init")
	.dwattr $C$DW$90, DW_AT_TI_call
        CALL #_USBSTK5515_init ; |47| 
                                        ; call occurs [#_USBSTK5515_init] ; |47| 
	.dwpsn	file "../main.c",line 48,column 2,is_stmt
;----------------------------------------------------------------------
;  48 | codec_init ();                                                         
;----------------------------------------------------------------------
$C$DW$91	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$91, DW_AT_low_pc(0x00)
	.dwattr $C$DW$91, DW_AT_name("_codec_init")
	.dwattr $C$DW$91, DW_AT_TI_call
        CALL #_codec_init ; |48| 
                                        ; call occurs [#_codec_init] ; |48| 
	.dwpsn	file "../main.c",line 49,column 2,is_stmt
;----------------------------------------------------------------------
;  49 | initAll();                                                             
;----------------------------------------------------------------------
$C$DW$92	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$92, DW_AT_low_pc(0x00)
	.dwattr $C$DW$92, DW_AT_name("_initAll")
	.dwattr $C$DW$92, DW_AT_TI_call
        CALL #_initAll ; |49| 
                                        ; call occurs [#_initAll] ; |49| 
	.dwpsn	file "../main.c",line 51,column 21,is_stmt
;----------------------------------------------------------------------
;  51 | while ( 1 )                                                            
;----------------------------------------------------------------------
$C$L3:    
$C$DW$L$_main$2$B:
	.dwpsn	file "../main.c",line 53,column 14,is_stmt
;----------------------------------------------------------------------
;  53 | if (I2S0_IR == 0)                                                      
;----------------------------------------------------------------------
        MOV *port(#10256), AR1 ; |53| 
        BCC $C$L5,AR1 != #0 ; |53| 
                                        ; branchcc occurs ; |53| 
$C$DW$L$_main$2$E:
$C$DW$L$_main$3$B:
	.dwpsn	file "../main.c",line 55,column 20,is_stmt
;----------------------------------------------------------------------
;  55 | while((Rcv & I2S0_IR) == 0);  // Wait for interrupt pending flag       
;----------------------------------------------------------------------
        BTST #3, *port(#10256), TC1 ; |55| 
        BCC $C$L5,TC1 ; |55| 
                                        ; branchcc occurs ; |55| 
$C$DW$L$_main$3$E:
$C$L4:    
$C$DW$L$_main$4$B:
        BTST #3, *port(#10256), TC1 ; |55| 
        BCC $C$L4,!TC1 ; |55| 
                                        ; branchcc occurs ; |55| 
$C$DW$L$_main$4$E:
$C$L5:    
$C$DW$L$_main$5$B:
	.dwpsn	file "../main.c",line 56,column 17,is_stmt
;----------------------------------------------------------------------
;  56 | k=100;                                                                 
;----------------------------------------------------------------------
        MOV #100, *(#_k) ; |56| 
	.dwpsn	file "../main.c",line 57,column 17,is_stmt
;----------------------------------------------------------------------
;  57 | data3 = I2S0_W0_MSW_R;  // 16 bit left channel received audio data     
;----------------------------------------------------------------------
        MOV *port(#10281), AR1 ; |57| 
        MOV AR1, *(#_data3) ; |57| 
	.dwpsn	file "../main.c",line 58,column 16,is_stmt
;----------------------------------------------------------------------
;  58 | data1 = I2S0_W0_LSW_R;                                                 
;----------------------------------------------------------------------
        MOV *port(#10280), AR1 ; |58| 
        MOV AR1, *(#_data1) ; |58| 
	.dwpsn	file "../main.c",line 59,column 16,is_stmt
;----------------------------------------------------------------------
;  59 | data4 = I2S0_W1_MSW_R;  // 16 bit right channel received audio data    
;----------------------------------------------------------------------
        MOV *port(#10285), AR1 ; |59| 
        MOV AR1, *(#_data4) ; |59| 
	.dwpsn	file "../main.c",line 60,column 16,is_stmt
;----------------------------------------------------------------------
;  60 | data2 = I2S0_W1_LSW_R;                                                 
;  62 | //asm(" bset XF");                                                     
;----------------------------------------------------------------------
        MOV *port(#10284), AR1 ; |60| 
        MOV AR1, *(#_data2) ; |60| 
	.dwpsn	file "../main.c",line 63,column 16,is_stmt
;----------------------------------------------------------------------
;  63 | asm(" bclr XF");                                                       
;----------------------------------------------------------------------
 bclr XF
	.dwpsn	file "../main.c",line 65,column 16,is_stmt
;----------------------------------------------------------------------
;  65 | if(i == N)                                                             
;----------------------------------------------------------------------
        CMP *(#_i) == #255, TC1 ; |65| 
        BCC $C$L6,!TC1 ; |65| 
                                        ; branchcc occurs ; |65| 
$C$DW$L$_main$5$E:
$C$DW$L$_main$6$B:
	.dwpsn	file "../main.c",line 67,column 17,is_stmt
;----------------------------------------------------------------------
;  67 | i = -1;                                                                
;----------------------------------------------------------------------
        MOV #-1, *(#_i) ; |67| 
$C$DW$L$_main$6$E:
$C$L6:    
$C$DW$L$_main$7$B:
	.dwpsn	file "../main.c",line 69,column 16,is_stmt
;----------------------------------------------------------------------
;  69 | x[i] = data3;                                                          
;----------------------------------------------------------------------
        MOV *(#_i), T0 ; |69| 
        MOV *(#_data3), AR1 ; |69| 
        AMOV #_x, XAR3 ; |69| 
        MOV AR1, *AR3(T0) ; |69| 
	.dwpsn	file "../main.c",line 70,column 16,is_stmt
;----------------------------------------------------------------------
;  70 | i++;                                                                   
;  71 | //CPFIR(x,b,N,y,i);                                                    
;----------------------------------------------------------------------
        ADD #1, *(#_i) ; |70| 
	.dwpsn	file "../main.c",line 72,column 17,is_stmt
;----------------------------------------------------------------------
;  72 | CPFIR();                                                               
;----------------------------------------------------------------------
$C$DW$93	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$93, DW_AT_low_pc(0x00)
	.dwattr $C$DW$93, DW_AT_name("_CPFIR")
	.dwattr $C$DW$93, DW_AT_TI_call
        CALL #_CPFIR ; |72| 
                                        ; call occurs [#_CPFIR] ; |72| 
	.dwpsn	file "../main.c",line 74,column 16,is_stmt
;----------------------------------------------------------------------
;  74 | asm(" bset XF");                                                       
;----------------------------------------------------------------------
 bset XF
	.dwpsn	file "../main.c",line 77,column 22,is_stmt
;----------------------------------------------------------------------
;  77 | while((Xmit & I2S0_IR) == 0);  // Wait for interrupt pending flag      
;----------------------------------------------------------------------
        BTST #5, *port(#10256), TC1 ; |77| 
        BCC $C$L8,TC1 ; |77| 
                                        ; branchcc occurs ; |77| 
$C$DW$L$_main$7$E:
$C$L7:    
$C$DW$L$_main$8$B:
        BTST #5, *port(#10256), TC1 ; |77| 
        BCC $C$L7,!TC1 ; |77| 
                                        ; branchcc occurs ; |77| 
$C$DW$L$_main$8$E:
$C$L8:    
$C$DW$L$_main$9$B:
	.dwpsn	file "../main.c",line 78,column 16,is_stmt
;----------------------------------------------------------------------
;  78 | asm(" bclr XF");                                                       
;----------------------------------------------------------------------
 bclr XF
	.dwpsn	file "../main.c",line 79,column 5,is_stmt
;----------------------------------------------------------------------
;  79 | I2S0_W0_MSW_W = data3;  // 16 bit left channel transmit audio data     
;----------------------------------------------------------------------
        MOV *(#_data3), AR1 ; |79| 
        MOV AR1, *port(#10249) ; |79| 
	.dwpsn	file "../main.c",line 80,column 16,is_stmt
;----------------------------------------------------------------------
;  80 | I2S0_W0_LSW_W = 0;                                                     
;----------------------------------------------------------------------
        MOV #0, *port(#10248) ; |80| 
	.dwpsn	file "../main.c",line 81,column 16,is_stmt
;----------------------------------------------------------------------
;  81 | I2S0_W1_MSW_W = data4;  // 16 bit right channel transmit audio data    
;----------------------------------------------------------------------
        MOV *(#_data4), AR1 ; |81| 
        MOV AR1, *port(#10253) ; |81| 
	.dwpsn	file "../main.c",line 82,column 16,is_stmt
;----------------------------------------------------------------------
;  82 | I2S0_W1_LSW_W = 0;                                                     
;----------------------------------------------------------------------
        MOV #0, *port(#10252) ; |82| 
	.dwpsn	file "../main.c",line 51,column 21,is_stmt
        B $C$L3   ; |51| 
                                        ; branch occurs ; |51| 
$C$DW$L$_main$9$E:
	.dwcfi	cfa_offset, 1

$C$DW$94	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$94, DW_AT_name("C:\Users\Kiis\Dropbox\Uni\7. semester\AAT7\Code\DSP\aic3204\Debug\main.asm:$C$L3:1:1478686677")
	.dwattr $C$DW$94, DW_AT_TI_begin_file("../main.c")
	.dwattr $C$DW$94, DW_AT_TI_begin_line(0x33)
	.dwattr $C$DW$94, DW_AT_TI_end_line(0x54)
$C$DW$95	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$95, DW_AT_low_pc($C$DW$L$_main$2$B)
	.dwattr $C$DW$95, DW_AT_high_pc($C$DW$L$_main$2$E)
$C$DW$96	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$96, DW_AT_low_pc($C$DW$L$_main$3$B)
	.dwattr $C$DW$96, DW_AT_high_pc($C$DW$L$_main$3$E)
$C$DW$97	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$97, DW_AT_low_pc($C$DW$L$_main$5$B)
	.dwattr $C$DW$97, DW_AT_high_pc($C$DW$L$_main$5$E)
$C$DW$98	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$98, DW_AT_low_pc($C$DW$L$_main$6$B)
	.dwattr $C$DW$98, DW_AT_high_pc($C$DW$L$_main$6$E)
$C$DW$99	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$99, DW_AT_low_pc($C$DW$L$_main$7$B)
	.dwattr $C$DW$99, DW_AT_high_pc($C$DW$L$_main$7$E)
$C$DW$100	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$100, DW_AT_low_pc($C$DW$L$_main$9$B)
	.dwattr $C$DW$100, DW_AT_high_pc($C$DW$L$_main$9$E)

$C$DW$101	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$101, DW_AT_name("C:\Users\Kiis\Dropbox\Uni\7. semester\AAT7\Code\DSP\aic3204\Debug\main.asm:$C$L4:2:1478686677")
	.dwattr $C$DW$101, DW_AT_TI_begin_file("../main.c")
	.dwattr $C$DW$101, DW_AT_TI_begin_line(0x37)
	.dwattr $C$DW$101, DW_AT_TI_end_line(0x37)
$C$DW$102	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$102, DW_AT_low_pc($C$DW$L$_main$4$B)
	.dwattr $C$DW$102, DW_AT_high_pc($C$DW$L$_main$4$E)
	.dwendtag $C$DW$101


$C$DW$103	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$103, DW_AT_name("C:\Users\Kiis\Dropbox\Uni\7. semester\AAT7\Code\DSP\aic3204\Debug\main.asm:$C$L7:2:1478686677")
	.dwattr $C$DW$103, DW_AT_TI_begin_file("../main.c")
	.dwattr $C$DW$103, DW_AT_TI_begin_line(0x4d)
	.dwattr $C$DW$103, DW_AT_TI_end_line(0x4d)
$C$DW$104	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$104, DW_AT_low_pc($C$DW$L$_main$8$B)
	.dwattr $C$DW$104, DW_AT_high_pc($C$DW$L$_main$8$E)
	.dwendtag $C$DW$103

	.dwendtag $C$DW$94

	.dwattr $C$DW$89, DW_AT_TI_end_file("../main.c")
	.dwattr $C$DW$89, DW_AT_TI_end_line(0x55)
	.dwattr $C$DW$89, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$89

	.sect	".text"
	.global	_initAll

$C$DW$105	.dwtag  DW_TAG_subprogram, DW_AT_name("initAll")
	.dwattr $C$DW$105, DW_AT_low_pc(_initAll)
	.dwattr $C$DW$105, DW_AT_high_pc(0x00)
	.dwattr $C$DW$105, DW_AT_TI_symbol_name("_initAll")
	.dwattr $C$DW$105, DW_AT_external
	.dwattr $C$DW$105, DW_AT_TI_begin_file("../main.c")
	.dwattr $C$DW$105, DW_AT_TI_begin_line(0x57)
	.dwattr $C$DW$105, DW_AT_TI_begin_column(0x06)
	.dwattr $C$DW$105, DW_AT_decl_file("../main.c")
	.dwattr $C$DW$105, DW_AT_decl_line(0x57)
	.dwattr $C$DW$105, DW_AT_decl_column(0x06)
	.dwattr $C$DW$105, DW_AT_TI_max_frame_size(0x02)
	.dwpsn	file "../main.c",line 88,column 1,is_stmt,address _initAll

	.dwfde $C$DW$CIE, _initAll
;----------------------------------------------------------------------
;  87 | void initAll(void)                                                     
;----------------------------------------------------------------------
;*******************************************************************************
;* FUNCTION NAME: initAll                                                      *
;*                                                                             *
;*   Function Uses Regs : T0,AR1,AR2,AR3,XAR3,SP,CARRY,TC1,M40,SATA,SATD,RDM,  *
;*                        FRCT,SMUL                                            *
;*   Stack Frame        : Compact (No Frame Pointer, w/ debug)                 *
;*   Total Frame Size   : 2 words                                              *
;*                        (1 return address/alignment)                         *
;*                        (1 local values)                                     *
;*   Min System Stack   : 1 word                                               *
;*******************************************************************************
_initAll:
;----------------------------------------------------------------------
;  89 | Int16 cnt;                                                             
;  90 | // Clear array                                                         
;----------------------------------------------------------------------
	.dwcfi	cfa_offset, 1
	.dwcfi	save_reg_to_mem, 91, -1
        AADD #-1, SP
	.dwcfi	cfa_offset, 2
$C$DW$106	.dwtag  DW_TAG_variable, DW_AT_name("cnt")
	.dwattr $C$DW$106, DW_AT_TI_symbol_name("_cnt")
	.dwattr $C$DW$106, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$106, DW_AT_location[DW_OP_bregx 0x24 0]
	.dwpsn	file "../main.c",line 91,column 6,is_stmt
;----------------------------------------------------------------------
;  91 | for(cnt=0;cnt<=N;cnt++)                                                
;----------------------------------------------------------------------
        MOV #0, *SP(#0) ; |91| 
	.dwpsn	file "../main.c",line 91,column 12,is_stmt
        MOV #255, AR2 ; |91| 
        MOV *SP(#0), AR1 ; |91| 
        CMP AR1 > AR2, TC1 ; |91| 
        BCC $C$L10,TC1 ; |91| 
                                        ; branchcc occurs ; |91| 
$C$L9:    
$C$DW$L$_initAll$2$B:
	.dwpsn	file "../main.c",line 93,column 3,is_stmt
;----------------------------------------------------------------------
;  93 | x[cnt] = 0;                                                            
;----------------------------------------------------------------------
        MOV AR1, T0 ; |93| 
        AMOV #_x, XAR3 ; |93| 
        MOV #0, *AR3(T0) ; |93| 
	.dwpsn	file "../main.c",line 94,column 3,is_stmt
;----------------------------------------------------------------------
;  94 | b[cnt] = 0;                                                            
;----------------------------------------------------------------------
        MOV *SP(#0), T0 ; |94| 
        AMOV #_b, XAR3 ; |94| 
        MOV #0, *AR3(T0) ; |94| 
	.dwpsn	file "../main.c",line 95,column 3,is_stmt
;----------------------------------------------------------------------
;  95 | y[cnt] = 0;                                                            
;----------------------------------------------------------------------
        MOV *SP(#0), T0 ; |95| 
        AMOV #_y, XAR3 ; |95| 
        MOV #0, *AR3(T0) ; |95| 
	.dwpsn	file "../main.c",line 91,column 19,is_stmt
        ADD #1, *SP(#0) ; |91| 
	.dwpsn	file "../main.c",line 91,column 12,is_stmt
        MOV *SP(#0), AR1 ; |91| 
        CMP AR1 <= AR2, TC1 ; |91| 
        BCC $C$L9,TC1 ; |91| 
                                        ; branchcc occurs ; |91| 
$C$DW$L$_initAll$2$E:
$C$L10:    
	.dwpsn	file "../main.c",line 97,column 1,is_stmt
        AADD #1, SP
	.dwcfi	cfa_offset, 1
$C$DW$107	.dwtag  DW_TAG_TI_branch
	.dwattr $C$DW$107, DW_AT_low_pc(0x00)
	.dwattr $C$DW$107, DW_AT_TI_return
        RET
                                        ; return occurs

$C$DW$108	.dwtag  DW_TAG_TI_loop
	.dwattr $C$DW$108, DW_AT_name("C:\Users\Kiis\Dropbox\Uni\7. semester\AAT7\Code\DSP\aic3204\Debug\main.asm:$C$L9:1:1478686677")
	.dwattr $C$DW$108, DW_AT_TI_begin_file("../main.c")
	.dwattr $C$DW$108, DW_AT_TI_begin_line(0x5b)
	.dwattr $C$DW$108, DW_AT_TI_end_line(0x60)
$C$DW$109	.dwtag  DW_TAG_TI_loop_range
	.dwattr $C$DW$109, DW_AT_low_pc($C$DW$L$_initAll$2$B)
	.dwattr $C$DW$109, DW_AT_high_pc($C$DW$L$_initAll$2$E)
	.dwendtag $C$DW$108

	.dwattr $C$DW$105, DW_AT_TI_end_file("../main.c")
	.dwattr $C$DW$105, DW_AT_TI_end_line(0x61)
	.dwattr $C$DW$105, DW_AT_TI_end_column(0x01)
	.dwendentry
	.dwendtag $C$DW$105

;******************************************************************************
;* UNDEFINED EXTERNAL REFERENCES                                              *
;******************************************************************************
	.global	_USBSTK5515_init
	.global	_USBSTK5515_wait
	.global	_USBSTK5515_I2C_write
	.global	_CPFIR

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
$C$DW$T$19	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$19, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$T$19, DW_AT_address_class(0x17)

$C$DW$T$25	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$25, DW_AT_type(*$C$DW$T$6)
	.dwattr $C$DW$T$25, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$25, DW_AT_byte_size(0x02)
$C$DW$110	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$110, DW_AT_upper_bound(0x01)
	.dwendtag $C$DW$T$25

$C$DW$T$7	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$7, DW_AT_encoding(DW_ATE_signed_char)
	.dwattr $C$DW$T$7, DW_AT_name("wchar_t")
	.dwattr $C$DW$T$7, DW_AT_byte_size(0x01)
$C$DW$T$8	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$8, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$8, DW_AT_name("short")
	.dwattr $C$DW$T$8, DW_AT_byte_size(0x01)

$C$DW$T$35	.dwtag  DW_TAG_array_type
	.dwattr $C$DW$T$35, DW_AT_type(*$C$DW$T$8)
	.dwattr $C$DW$T$35, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$35, DW_AT_byte_size(0xff)
$C$DW$111	.dwtag  DW_TAG_subrange_type
	.dwattr $C$DW$111, DW_AT_upper_bound(0xfe)
	.dwendtag $C$DW$T$35

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
$C$DW$T$39	.dwtag  DW_TAG_typedef, DW_AT_name("size_t")
	.dwattr $C$DW$T$39, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$T$39, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$39, DW_AT_decl_file("C:/Program Files/TexasInstruments/ccsv4/tools/compiler/c5500/include/stdio.h")
	.dwattr $C$DW$T$39, DW_AT_decl_line(0x19)
	.dwattr $C$DW$T$39, DW_AT_decl_column(0x19)
$C$DW$T$12	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$12, DW_AT_encoding(DW_ATE_signed)
	.dwattr $C$DW$T$12, DW_AT_name("long")
	.dwattr $C$DW$T$12, DW_AT_byte_size(0x02)
$C$DW$T$40	.dwtag  DW_TAG_typedef, DW_AT_name("fpos_t")
	.dwattr $C$DW$T$40, DW_AT_type(*$C$DW$T$12)
	.dwattr $C$DW$T$40, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$40, DW_AT_decl_file("C:/Program Files/TexasInstruments/ccsv4/tools/compiler/c5500/include/stdio.h")
	.dwattr $C$DW$T$40, DW_AT_decl_line(0x27)
	.dwattr $C$DW$T$40, DW_AT_decl_column(0x0e)
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

$C$DW$T$20	.dwtag  DW_TAG_structure_type
	.dwattr $C$DW$T$20, DW_AT_byte_size(0x0c)
$C$DW$112	.dwtag  DW_TAG_member
	.dwattr $C$DW$112, DW_AT_type(*$C$DW$T$10)
	.dwattr $C$DW$112, DW_AT_name("fd")
	.dwattr $C$DW$112, DW_AT_TI_symbol_name("_fd")
	.dwattr $C$DW$112, DW_AT_data_member_location[DW_OP_plus_uconst 0x0]
	.dwattr $C$DW$112, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$112, DW_AT_decl_file("C:/Program Files/TexasInstruments/ccsv4/tools/compiler/c5500/include/stdio.h")
	.dwattr $C$DW$112, DW_AT_decl_line(0x1d)
	.dwattr $C$DW$112, DW_AT_decl_column(0x0b)
$C$DW$113	.dwtag  DW_TAG_member
	.dwattr $C$DW$113, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$113, DW_AT_name("buf")
	.dwattr $C$DW$113, DW_AT_TI_symbol_name("_buf")
	.dwattr $C$DW$113, DW_AT_data_member_location[DW_OP_plus_uconst 0x2]
	.dwattr $C$DW$113, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$113, DW_AT_decl_file("C:/Program Files/TexasInstruments/ccsv4/tools/compiler/c5500/include/stdio.h")
	.dwattr $C$DW$113, DW_AT_decl_line(0x1e)
	.dwattr $C$DW$113, DW_AT_decl_column(0x16)
$C$DW$114	.dwtag  DW_TAG_member
	.dwattr $C$DW$114, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$114, DW_AT_name("pos")
	.dwattr $C$DW$114, DW_AT_TI_symbol_name("_pos")
	.dwattr $C$DW$114, DW_AT_data_member_location[DW_OP_plus_uconst 0x4]
	.dwattr $C$DW$114, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$114, DW_AT_decl_file("C:/Program Files/TexasInstruments/ccsv4/tools/compiler/c5500/include/stdio.h")
	.dwattr $C$DW$114, DW_AT_decl_line(0x1f)
	.dwattr $C$DW$114, DW_AT_decl_column(0x16)
$C$DW$115	.dwtag  DW_TAG_member
	.dwattr $C$DW$115, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$115, DW_AT_name("bufend")
	.dwattr $C$DW$115, DW_AT_TI_symbol_name("_bufend")
	.dwattr $C$DW$115, DW_AT_data_member_location[DW_OP_plus_uconst 0x6]
	.dwattr $C$DW$115, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$115, DW_AT_decl_file("C:/Program Files/TexasInstruments/ccsv4/tools/compiler/c5500/include/stdio.h")
	.dwattr $C$DW$115, DW_AT_decl_line(0x20)
	.dwattr $C$DW$115, DW_AT_decl_column(0x16)
$C$DW$116	.dwtag  DW_TAG_member
	.dwattr $C$DW$116, DW_AT_type(*$C$DW$T$19)
	.dwattr $C$DW$116, DW_AT_name("buff_stop")
	.dwattr $C$DW$116, DW_AT_TI_symbol_name("_buff_stop")
	.dwattr $C$DW$116, DW_AT_data_member_location[DW_OP_plus_uconst 0x8]
	.dwattr $C$DW$116, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$116, DW_AT_decl_file("C:/Program Files/TexasInstruments/ccsv4/tools/compiler/c5500/include/stdio.h")
	.dwattr $C$DW$116, DW_AT_decl_line(0x21)
	.dwattr $C$DW$116, DW_AT_decl_column(0x16)
$C$DW$117	.dwtag  DW_TAG_member
	.dwattr $C$DW$117, DW_AT_type(*$C$DW$T$11)
	.dwattr $C$DW$117, DW_AT_name("flags")
	.dwattr $C$DW$117, DW_AT_TI_symbol_name("_flags")
	.dwattr $C$DW$117, DW_AT_data_member_location[DW_OP_plus_uconst 0xa]
	.dwattr $C$DW$117, DW_AT_accessibility(DW_ACCESS_public)
	.dwattr $C$DW$117, DW_AT_decl_file("C:/Program Files/TexasInstruments/ccsv4/tools/compiler/c5500/include/stdio.h")
	.dwattr $C$DW$117, DW_AT_decl_line(0x22)
	.dwattr $C$DW$117, DW_AT_decl_column(0x16)
	.dwendtag $C$DW$T$20

	.dwattr $C$DW$T$20, DW_AT_decl_file("C:/Program Files/TexasInstruments/ccsv4/tools/compiler/c5500/include/stdio.h")
	.dwattr $C$DW$T$20, DW_AT_decl_line(0x1c)
	.dwattr $C$DW$T$20, DW_AT_decl_column(0x10)
$C$DW$T$44	.dwtag  DW_TAG_typedef, DW_AT_name("FILE")
	.dwattr $C$DW$T$44, DW_AT_type(*$C$DW$T$20)
	.dwattr $C$DW$T$44, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$44, DW_AT_decl_file("C:/Program Files/TexasInstruments/ccsv4/tools/compiler/c5500/include/stdio.h")
	.dwattr $C$DW$T$44, DW_AT_decl_line(0x23)
	.dwattr $C$DW$T$44, DW_AT_decl_column(0x03)
$C$DW$T$41	.dwtag  DW_TAG_base_type
	.dwattr $C$DW$T$41, DW_AT_encoding(DW_ATE_signed_char)
	.dwattr $C$DW$T$41, DW_AT_name("signed char")
	.dwattr $C$DW$T$41, DW_AT_byte_size(0x01)
$C$DW$T$42	.dwtag  DW_TAG_pointer_type
	.dwattr $C$DW$T$42, DW_AT_type(*$C$DW$T$41)
	.dwattr $C$DW$T$42, DW_AT_address_class(0x17)
$C$DW$T$43	.dwtag  DW_TAG_typedef, DW_AT_name("va_list")
	.dwattr $C$DW$T$43, DW_AT_type(*$C$DW$T$42)
	.dwattr $C$DW$T$43, DW_AT_language(DW_LANG_C)
	.dwattr $C$DW$T$43, DW_AT_decl_file("C:/Program Files/TexasInstruments/ccsv4/tools/compiler/c5500/include/stdarg.h")
	.dwattr $C$DW$T$43, DW_AT_decl_line(0x0d)
	.dwattr $C$DW$T$43, DW_AT_decl_column(0x0f)
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

$C$DW$118	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC0")
	.dwattr $C$DW$118, DW_AT_location[DW_OP_reg0]
$C$DW$119	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC0")
	.dwattr $C$DW$119, DW_AT_location[DW_OP_reg1]
$C$DW$120	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC0_G")
	.dwattr $C$DW$120, DW_AT_location[DW_OP_reg2]
$C$DW$121	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC1")
	.dwattr $C$DW$121, DW_AT_location[DW_OP_reg3]
$C$DW$122	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC1")
	.dwattr $C$DW$122, DW_AT_location[DW_OP_reg4]
$C$DW$123	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC1_G")
	.dwattr $C$DW$123, DW_AT_location[DW_OP_reg5]
$C$DW$124	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC2")
	.dwattr $C$DW$124, DW_AT_location[DW_OP_reg6]
$C$DW$125	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC2")
	.dwattr $C$DW$125, DW_AT_location[DW_OP_reg7]
$C$DW$126	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC2_G")
	.dwattr $C$DW$126, DW_AT_location[DW_OP_reg8]
$C$DW$127	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC3")
	.dwattr $C$DW$127, DW_AT_location[DW_OP_reg9]
$C$DW$128	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC3")
	.dwattr $C$DW$128, DW_AT_location[DW_OP_reg10]
$C$DW$129	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AC3_G")
	.dwattr $C$DW$129, DW_AT_location[DW_OP_reg11]
$C$DW$130	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("T0")
	.dwattr $C$DW$130, DW_AT_location[DW_OP_reg12]
$C$DW$131	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("T1")
	.dwattr $C$DW$131, DW_AT_location[DW_OP_reg13]
$C$DW$132	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("T2")
	.dwattr $C$DW$132, DW_AT_location[DW_OP_reg14]
$C$DW$133	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("T3")
	.dwattr $C$DW$133, DW_AT_location[DW_OP_reg15]
$C$DW$134	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR0")
	.dwattr $C$DW$134, DW_AT_location[DW_OP_reg16]
$C$DW$135	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR0")
	.dwattr $C$DW$135, DW_AT_location[DW_OP_reg17]
$C$DW$136	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR1")
	.dwattr $C$DW$136, DW_AT_location[DW_OP_reg18]
$C$DW$137	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR1")
	.dwattr $C$DW$137, DW_AT_location[DW_OP_reg19]
$C$DW$138	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR2")
	.dwattr $C$DW$138, DW_AT_location[DW_OP_reg20]
$C$DW$139	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR2")
	.dwattr $C$DW$139, DW_AT_location[DW_OP_reg21]
$C$DW$140	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR3")
	.dwattr $C$DW$140, DW_AT_location[DW_OP_reg22]
$C$DW$141	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR3")
	.dwattr $C$DW$141, DW_AT_location[DW_OP_reg23]
$C$DW$142	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR4")
	.dwattr $C$DW$142, DW_AT_location[DW_OP_reg24]
$C$DW$143	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR4")
	.dwattr $C$DW$143, DW_AT_location[DW_OP_reg25]
$C$DW$144	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR5")
	.dwattr $C$DW$144, DW_AT_location[DW_OP_reg26]
$C$DW$145	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR5")
	.dwattr $C$DW$145, DW_AT_location[DW_OP_reg27]
$C$DW$146	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR6")
	.dwattr $C$DW$146, DW_AT_location[DW_OP_reg28]
$C$DW$147	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR6")
	.dwattr $C$DW$147, DW_AT_location[DW_OP_reg29]
$C$DW$148	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR7")
	.dwattr $C$DW$148, DW_AT_location[DW_OP_reg30]
$C$DW$149	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XAR7")
	.dwattr $C$DW$149, DW_AT_location[DW_OP_reg31]
$C$DW$150	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("FP")
	.dwattr $C$DW$150, DW_AT_location[DW_OP_regx 0x20]
$C$DW$151	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XFP")
	.dwattr $C$DW$151, DW_AT_location[DW_OP_regx 0x21]
$C$DW$152	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("PC")
	.dwattr $C$DW$152, DW_AT_location[DW_OP_regx 0x22]
$C$DW$153	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("SP")
	.dwattr $C$DW$153, DW_AT_location[DW_OP_regx 0x23]
$C$DW$154	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XSP")
	.dwattr $C$DW$154, DW_AT_location[DW_OP_regx 0x24]
$C$DW$155	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BKC")
	.dwattr $C$DW$155, DW_AT_location[DW_OP_regx 0x25]
$C$DW$156	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BK03")
	.dwattr $C$DW$156, DW_AT_location[DW_OP_regx 0x26]
$C$DW$157	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BK47")
	.dwattr $C$DW$157, DW_AT_location[DW_OP_regx 0x27]
$C$DW$158	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ST0")
	.dwattr $C$DW$158, DW_AT_location[DW_OP_regx 0x28]
$C$DW$159	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ST1")
	.dwattr $C$DW$159, DW_AT_location[DW_OP_regx 0x29]
$C$DW$160	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ST2")
	.dwattr $C$DW$160, DW_AT_location[DW_OP_regx 0x2a]
$C$DW$161	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ST3")
	.dwattr $C$DW$161, DW_AT_location[DW_OP_regx 0x2b]
$C$DW$162	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("MDP")
	.dwattr $C$DW$162, DW_AT_location[DW_OP_regx 0x2c]
$C$DW$163	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("MDP05")
	.dwattr $C$DW$163, DW_AT_location[DW_OP_regx 0x2d]
$C$DW$164	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("MDP67")
	.dwattr $C$DW$164, DW_AT_location[DW_OP_regx 0x2e]
$C$DW$165	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BRC0")
	.dwattr $C$DW$165, DW_AT_location[DW_OP_regx 0x2f]
$C$DW$166	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RSA0")
	.dwattr $C$DW$166, DW_AT_location[DW_OP_regx 0x30]
$C$DW$167	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RSA0_H")
	.dwattr $C$DW$167, DW_AT_location[DW_OP_regx 0x31]
$C$DW$168	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("REA0")
	.dwattr $C$DW$168, DW_AT_location[DW_OP_regx 0x32]
$C$DW$169	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("REA0_H")
	.dwattr $C$DW$169, DW_AT_location[DW_OP_regx 0x33]
$C$DW$170	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BRS1")
	.dwattr $C$DW$170, DW_AT_location[DW_OP_regx 0x34]
$C$DW$171	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BRC1")
	.dwattr $C$DW$171, DW_AT_location[DW_OP_regx 0x35]
$C$DW$172	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RSA1")
	.dwattr $C$DW$172, DW_AT_location[DW_OP_regx 0x36]
$C$DW$173	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RSA1_H")
	.dwattr $C$DW$173, DW_AT_location[DW_OP_regx 0x37]
$C$DW$174	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("REA1")
	.dwattr $C$DW$174, DW_AT_location[DW_OP_regx 0x38]
$C$DW$175	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("REA1_H")
	.dwattr $C$DW$175, DW_AT_location[DW_OP_regx 0x39]
$C$DW$176	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CSR")
	.dwattr $C$DW$176, DW_AT_location[DW_OP_regx 0x3a]
$C$DW$177	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RPTC")
	.dwattr $C$DW$177, DW_AT_location[DW_OP_regx 0x3b]
$C$DW$178	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CDP")
	.dwattr $C$DW$178, DW_AT_location[DW_OP_regx 0x3c]
$C$DW$179	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("XCDP")
	.dwattr $C$DW$179, DW_AT_location[DW_OP_regx 0x3d]
$C$DW$180	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TRN0")
	.dwattr $C$DW$180, DW_AT_location[DW_OP_regx 0x3e]
$C$DW$181	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TRN1")
	.dwattr $C$DW$181, DW_AT_location[DW_OP_regx 0x3f]
$C$DW$182	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BSA01")
	.dwattr $C$DW$182, DW_AT_location[DW_OP_regx 0x40]
$C$DW$183	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BSA23")
	.dwattr $C$DW$183, DW_AT_location[DW_OP_regx 0x41]
$C$DW$184	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BSA45")
	.dwattr $C$DW$184, DW_AT_location[DW_OP_regx 0x42]
$C$DW$185	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BSA67")
	.dwattr $C$DW$185, DW_AT_location[DW_OP_regx 0x43]
$C$DW$186	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("BSAC")
	.dwattr $C$DW$186, DW_AT_location[DW_OP_regx 0x44]
$C$DW$187	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CARRY")
	.dwattr $C$DW$187, DW_AT_location[DW_OP_regx 0x45]
$C$DW$188	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TC1")
	.dwattr $C$DW$188, DW_AT_location[DW_OP_regx 0x46]
$C$DW$189	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("TC2")
	.dwattr $C$DW$189, DW_AT_location[DW_OP_regx 0x47]
$C$DW$190	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("M40")
	.dwattr $C$DW$190, DW_AT_location[DW_OP_regx 0x48]
$C$DW$191	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("SXMD")
	.dwattr $C$DW$191, DW_AT_location[DW_OP_regx 0x49]
$C$DW$192	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("ARMS")
	.dwattr $C$DW$192, DW_AT_location[DW_OP_regx 0x4a]
$C$DW$193	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("C54CM")
	.dwattr $C$DW$193, DW_AT_location[DW_OP_regx 0x4b]
$C$DW$194	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("SATA")
	.dwattr $C$DW$194, DW_AT_location[DW_OP_regx 0x4c]
$C$DW$195	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("SATD")
	.dwattr $C$DW$195, DW_AT_location[DW_OP_regx 0x4d]
$C$DW$196	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("RDM")
	.dwattr $C$DW$196, DW_AT_location[DW_OP_regx 0x4e]
$C$DW$197	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("FRCT")
	.dwattr $C$DW$197, DW_AT_location[DW_OP_regx 0x4f]
$C$DW$198	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("SMUL")
	.dwattr $C$DW$198, DW_AT_location[DW_OP_regx 0x50]
$C$DW$199	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("INTM")
	.dwattr $C$DW$199, DW_AT_location[DW_OP_regx 0x51]
$C$DW$200	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR0LC")
	.dwattr $C$DW$200, DW_AT_location[DW_OP_regx 0x52]
$C$DW$201	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR1LC")
	.dwattr $C$DW$201, DW_AT_location[DW_OP_regx 0x53]
$C$DW$202	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR2LC")
	.dwattr $C$DW$202, DW_AT_location[DW_OP_regx 0x54]
$C$DW$203	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR3LC")
	.dwattr $C$DW$203, DW_AT_location[DW_OP_regx 0x55]
$C$DW$204	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR4LC")
	.dwattr $C$DW$204, DW_AT_location[DW_OP_regx 0x56]
$C$DW$205	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR5LC")
	.dwattr $C$DW$205, DW_AT_location[DW_OP_regx 0x57]
$C$DW$206	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR6LC")
	.dwattr $C$DW$206, DW_AT_location[DW_OP_regx 0x58]
$C$DW$207	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("AR7LC")
	.dwattr $C$DW$207, DW_AT_location[DW_OP_regx 0x59]
$C$DW$208	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CDPLC")
	.dwattr $C$DW$208, DW_AT_location[DW_OP_regx 0x5a]
$C$DW$209	.dwtag  DW_TAG_TI_assign_register, DW_AT_name("CIE_RETA")
	.dwattr $C$DW$209, DW_AT_location[DW_OP_regx 0x5b]
	.dwendtag $C$DW$CU

