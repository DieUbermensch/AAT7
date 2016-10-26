################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
C:/Users/Mikkel\ Krogh/Documents/GitHub/AAT7/Code/DSP/loopback/src/Debug/loopback.obj: ../src/loopback.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -v5510 -g --define="_DEBUG" --define=CHIP_5510PG2_2 1 --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/loopback/Debug" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/bios/include" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/xdais_7_10_00_06/packages/ti/xdais" --include_path="/include" --include_path="../src" --include_path="E:/DSP/C55xDSP/ch01_2ed/experiments/exp1.6.6_loopback" --quiet --diag_warning=225 --optimize_with_debug --large_memory_model --ptrdiff_size=32 --algebraic --memory_model=large --obj_directory="../src/Debug" --preproc_with_compile --preproc_dependency="src/loopback.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


