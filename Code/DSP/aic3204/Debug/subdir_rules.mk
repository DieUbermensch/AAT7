################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Functions.obj: ../Functions.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204/include" --include_path="../../../include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="Functions.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
<<<<<<< Updated upstream
	"C:/Program Files/TexasInstruments/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files/TexasInstruments/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Kiis/Dropbox/Uni/7. semester/AAT7/Code/DSP/aic3204/include" --include_path="../../../include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
=======
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -v5515 -g --include_path="C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/aic3204/include" --include_path="../../../include" --diag_warning=225 --ptrdiff_size=16 --memory_model=large --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
>>>>>>> Stashed changes
	@echo 'Finished building: $<'
	@echo ' '


