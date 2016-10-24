################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
main.obj: ../main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -v5510 -g --define=CHIP_5510 --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/ActiveNoiseCancelling" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


