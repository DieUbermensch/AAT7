################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/audioLoopTest.obj: ../src/audioLoopTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -v5505 --symdebug:coff --define="_DEBUG" --define="C55X" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --include_path="../inc" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="/inc" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/audioLoop/Debug" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/bios/include" --diag_warning=225 --ptrdiff_size=16 --no_mac_expand --memory_model=large --asm_source=mnemonic --preproc_with_compile --preproc_dependency="src/audioLoopTest.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

src/vector.obj: ../src/vector.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -v5505 --symdebug:coff --define="_DEBUG" --define="C55X" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --include_path="../inc" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="/inc" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/audioLoop/Debug" --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/bios/include" --diag_warning=225 --ptrdiff_size=16 --no_mac_expand --memory_model=large --asm_source=mnemonic --preproc_with_compile --preproc_dependency="src/vector.pp" --obj_directory="src" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


