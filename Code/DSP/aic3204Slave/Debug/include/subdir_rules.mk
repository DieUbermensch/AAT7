################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
include/usbstk5515.obj: ../include/usbstk5515.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -g --define=CHIP_C5515 --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/include" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/Debug" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/API/inc" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/API/src" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/Debug/include" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=small --asm_source=algebraic --preproc_with_compile --preproc_dependency="include/usbstk5515.pp" --obj_directory="include" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

include/usbstk5515_gpio.obj: ../include/usbstk5515_gpio.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -g --define=CHIP_C5515 --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/include" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/Debug" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/API/inc" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/API/src" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/Debug/include" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=small --asm_source=algebraic --preproc_with_compile --preproc_dependency="include/usbstk5515_gpio.pp" --obj_directory="include" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

include/usbstk5515_i2c.obj: ../include/usbstk5515_i2c.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -g --define=CHIP_C5515 --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/include" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/Debug" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/API/inc" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/API/src" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/Debug/include" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=small --asm_source=algebraic --preproc_with_compile --preproc_dependency="include/usbstk5515_i2c.pp" --obj_directory="include" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

include/usbstk5515_led.obj: ../include/usbstk5515_led.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -g --define=CHIP_C5515 --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/include" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/Debug" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/API/inc" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/API/src" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/Debug/include" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=small --asm_source=algebraic --preproc_with_compile --preproc_dependency="include/usbstk5515_led.pp" --obj_directory="include" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


