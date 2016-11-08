################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
FIRFunction.obj: ../FIRFunction.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/TexasInstruments/ccsv4/tools/compiler/c5500/bin/cl55" -vcpu:3.3 -g --include_path="C:/Program Files/TexasInstruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Kiis/Dropbox/Uni/7. semester/AAT7/Code/DSP/aic3204/include" --include_path="../../../include" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="FIRFunction.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files/TexasInstruments/ccsv4/tools/compiler/c5500/bin/cl55" -vcpu:3.3 -g --include_path="C:/Program Files/TexasInstruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Kiis/Dropbox/Uni/7. semester/AAT7/Code/DSP/aic3204/include" --include_path="../../../include" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


