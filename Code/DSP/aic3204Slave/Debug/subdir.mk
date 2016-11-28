################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../main.c 

ASM_SRCS += \
../FIRFunction.asm 

CMD_SRCS += \
../lnkx.cmd 

ASM_DEPS += \
./FIRFunction.pp 

OBJS += \
./FIRFunction.obj \
./main.obj 

C_DEPS += \
./main.pp 

OBJS__QTD += \
".\FIRFunction.obj" \
".\main.obj" 

ASM_DEPS__QTD += \
".\FIRFunction.pp" 

C_DEPS__QTD += \
".\main.pp" 

ASM_SRCS_QUOTED += \
"../FIRFunction.asm" 

C_SRCS_QUOTED += \
"../main.c" 


# Each subdirectory must supply rules for building sources it contributes
FIRFunction.obj: ../FIRFunction.asm $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments2/ccsv4/tools/compiler/c5500/bin/cl55" -vcpu:3.3 -g --include_path="C:/Program Files (x86)/Texas Instruments2/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Christian/Documents/AkustikGit/AAT7/Code/DSP/aic3204/include" --include_path="../../../include" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="FIRFunction.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments2/ccsv4/tools/compiler/c5500/bin/cl55" -vcpu:3.3 -g --include_path="C:/Program Files (x86)/Texas Instruments2/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Christian/Documents/AkustikGit/AAT7/Code/DSP/aic3204/include" --include_path="../../../include" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


