################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/audioLoopTest.c 

ASM_SRCS += \
../src/vector.asm 

ASM_DEPS += \
./src/vector.pp 

OBJS += \
./src/audioLoopTest.obj \
./src/vector.obj 

C_DEPS += \
./src/audioLoopTest.pp 

ASM_DEPS__QUOTED += \
"src\vector.pp" 

C_DEPS__QUOTED += \
"src\audioLoopTest.pp" 

OBJS__QUOTED += \
"src\audioLoopTest.obj" \
"src\vector.obj" 

C_SRCS__QUOTED += \
"../src/audioLoopTest.c" 

ASM_SRCS__QUOTED += \
"../src/vector.asm" 


# Each subdirectory must supply rules for building sources it contributes
src/audioLoopTest.obj: ../src/audioLoopTest.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 --symdebug:coff --define="_DEBUG" --define="C55X" --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="C:/ti/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/ti/bios_5_41_10_36/packages/ti/bios/include" --diag_warning=225 --ptrdiff_size=16 --no_mac_expand --memory_model=large --asm_source=mnemonic --preproc_with_compile --preproc_dependency="src/audioLoopTest.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/vector.obj: ../src/vector.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C5500 Compiler'
	"C:/ti/ccsv5/tools/compiler/c5500/bin/cl55" -v5505 --symdebug:coff --define="_DEBUG" --define="C55X" --include_path="C:/ti/ccsv5/tools/compiler/c5500/include" --include_path="..\inc" --include_path="C:/ti/bios_5_41_10_36/packages/ti/rtdx/include/c5500" --include_path="C:/ti/bios_5_41_10_36/packages/ti/bios/include" --diag_warning=225 --ptrdiff_size=16 --no_mac_expand --memory_model=large --asm_source=mnemonic --preproc_with_compile --preproc_dependency="src/vector.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


