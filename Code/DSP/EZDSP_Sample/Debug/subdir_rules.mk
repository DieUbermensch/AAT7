################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
aic_test_i2c.obj: C:/Users/Mikkel\ Krogh/Downloads/usbstk5515_v1/tests/USB_Stick_Sample/asm/aic_test_i2c.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -vcpu:3.3 -g --define="_DEBUG" --define="C55X" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --include_path="../../../../include" --include_path="C:/Users/Mikkel Krogh/Downloads/usbstk5515_v1/tests/USB_Stick_Sample/inc" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/EZDSP_Sample/Debug" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --diag_warning=225 --ptrdiff_size=32 --algebraic --memory_model=large --asm_source=algebraic --preproc_with_compile --preproc_dependency="aic_test_i2c.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

dma.obj: C:/Users/Mikkel\ Krogh/Downloads/usbstk5515_v1/tests/USB_Stick_Sample/src/dma.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -vcpu:3.3 -g --define="_DEBUG" --define="C55X" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --include_path="../../../../include" --include_path="C:/Users/Mikkel Krogh/Downloads/usbstk5515_v1/tests/USB_Stick_Sample/inc" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/EZDSP_Sample/Debug" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --diag_warning=225 --ptrdiff_size=32 --algebraic --memory_model=large --asm_source=algebraic --preproc_with_compile --preproc_dependency="dma.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

i2s.obj: C:/Users/Mikkel\ Krogh/Downloads/usbstk5515_v1/tests/USB_Stick_Sample/src/i2s.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -vcpu:3.3 -g --define="_DEBUG" --define="C55X" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --include_path="../../../../include" --include_path="C:/Users/Mikkel Krogh/Downloads/usbstk5515_v1/tests/USB_Stick_Sample/inc" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/EZDSP_Sample/Debug" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --diag_warning=225 --ptrdiff_size=32 --algebraic --memory_model=large --asm_source=algebraic --preproc_with_compile --preproc_dependency="i2s.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

i2s_register.obj: C:/Users/Mikkel\ Krogh/Downloads/usbstk5515_v1/tests/USB_Stick_Sample/asm/i2s_register.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -vcpu:3.3 -g --define="_DEBUG" --define="C55X" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --include_path="../../../../include" --include_path="C:/Users/Mikkel Krogh/Downloads/usbstk5515_v1/tests/USB_Stick_Sample/inc" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/EZDSP_Sample/Debug" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --diag_warning=225 --ptrdiff_size=32 --algebraic --memory_model=large --asm_source=algebraic --preproc_with_compile --preproc_dependency="i2s_register.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

main.obj: C:/Users/Mikkel\ Krogh/Downloads/usbstk5515_v1/tests/USB_Stick_Sample/src/main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -vcpu:3.3 -g --define="_DEBUG" --define="C55X" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --include_path="../../../../include" --include_path="C:/Users/Mikkel Krogh/Downloads/usbstk5515_v1/tests/USB_Stick_Sample/inc" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/EZDSP_Sample/Debug" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --diag_warning=225 --ptrdiff_size=32 --algebraic --memory_model=large --asm_source=algebraic --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

oled_test.obj: C:/Users/Mikkel\ Krogh/Downloads/usbstk5515_v1/tests/USB_Stick_Sample/src/oled_test.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -vcpu:3.3 -g --define="_DEBUG" --define="C55X" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --include_path="../../../../include" --include_path="C:/Users/Mikkel Krogh/Downloads/usbstk5515_v1/tests/USB_Stick_Sample/inc" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/EZDSP_Sample/Debug" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --diag_warning=225 --ptrdiff_size=32 --algebraic --memory_model=large --asm_source=algebraic --preproc_with_compile --preproc_dependency="oled_test.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

rtc.obj: C:/Users/Mikkel\ Krogh/Downloads/usbstk5515_v1/tests/USB_Stick_Sample/src/rtc.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -vcpu:3.3 -g --define="_DEBUG" --define="C55X" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --include_path="../../../../include" --include_path="C:/Users/Mikkel Krogh/Downloads/usbstk5515_v1/tests/USB_Stick_Sample/inc" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/EZDSP_Sample/Debug" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --diag_warning=225 --ptrdiff_size=32 --algebraic --memory_model=large --asm_source=algebraic --preproc_with_compile --preproc_dependency="rtc.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

sar.obj: C:/Users/Mikkel\ Krogh/Downloads/usbstk5515_v1/tests/USB_Stick_Sample/src/sar.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -vcpu:3.3 -g --define="_DEBUG" --define="C55X" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --include_path="../../../../include" --include_path="C:/Users/Mikkel Krogh/Downloads/usbstk5515_v1/tests/USB_Stick_Sample/inc" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/EZDSP_Sample/Debug" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --diag_warning=225 --ptrdiff_size=32 --algebraic --memory_model=large --asm_source=algebraic --preproc_with_compile --preproc_dependency="sar.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

timer.obj: C:/Users/Mikkel\ Krogh/Downloads/usbstk5515_v1/tests/USB_Stick_Sample/src/timer.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -vcpu:3.3 -g --define="_DEBUG" --define="C55X" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --include_path="../../../../include" --include_path="C:/Users/Mikkel Krogh/Downloads/usbstk5515_v1/tests/USB_Stick_Sample/inc" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/EZDSP_Sample/Debug" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --diag_warning=225 --ptrdiff_size=32 --algebraic --memory_model=large --asm_source=algebraic --preproc_with_compile --preproc_dependency="timer.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

vector.obj: C:/Users/Mikkel\ Krogh/Downloads/usbstk5515_v1/tests/USB_Stick_Sample/asm/vector.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -vcpu:3.3 -g --define="_DEBUG" --define="C55X" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --include_path="../../../../include" --include_path="C:/Users/Mikkel Krogh/Downloads/usbstk5515_v1/tests/USB_Stick_Sample/inc" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/EZDSP_Sample/Debug" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --diag_warning=225 --ptrdiff_size=32 --algebraic --memory_model=large --asm_source=algebraic --preproc_with_compile --preproc_dependency="vector.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


