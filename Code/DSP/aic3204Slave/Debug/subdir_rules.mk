################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Functions.obj: ../Functions.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -g --define=CHIP_C5515 --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/include" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/Debug" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/API/inc" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/API/src" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/Debug/include" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=small --asm_source=algebraic --preproc_with_compile --preproc_dependency="Functions.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -g --define=CHIP_C5515 --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/include" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/Debug" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/API/inc" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/API/src" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204Slave/Debug/include" --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=small --asm_source=algebraic --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


