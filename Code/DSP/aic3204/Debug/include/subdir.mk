################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../include/usbstk5515.c \
../include/usbstk5515_gpio.c \
../include/usbstk5515_i2c.c \
../include/usbstk5515_led.c 

OBJS += \
./include/usbstk5515.obj \
./include/usbstk5515_gpio.obj \
./include/usbstk5515_i2c.obj \
./include/usbstk5515_led.obj 

C_DEPS += \
./include/usbstk5515.pp \
./include/usbstk5515_gpio.pp \
./include/usbstk5515_i2c.pp \
./include/usbstk5515_led.pp 

OBJS__QTD += \
".\include\usbstk5515.obj" \
".\include\usbstk5515_gpio.obj" \
".\include\usbstk5515_i2c.obj" \
".\include\usbstk5515_led.obj" 

C_DEPS__QTD += \
".\include\usbstk5515.pp" \
".\include\usbstk5515_gpio.pp" \
".\include\usbstk5515_i2c.pp" \
".\include\usbstk5515_led.pp" 

C_SRCS_QUOTED += \
"../include/usbstk5515.c" \
"../include/usbstk5515_gpio.c" \
"../include/usbstk5515_i2c.c" \
"../include/usbstk5515_led.c" 


# Each subdirectory must supply rules for building sources it contributes
include/usbstk5515.obj: ../include/usbstk5515.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments2/ccsv4/tools/compiler/c5500/bin/cl55" -vcpu:3.3 -g --include_path="C:/Program Files (x86)/Texas Instruments2/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Christian/Documents/AkustikGit/AAT7/Code/DSP/aic3204/include" --include_path="../../../include" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="include/usbstk5515.pp" --obj_directory="include" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

include/usbstk5515_gpio.obj: ../include/usbstk5515_gpio.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments2/ccsv4/tools/compiler/c5500/bin/cl55" -vcpu:3.3 -g --include_path="C:/Program Files (x86)/Texas Instruments2/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Christian/Documents/AkustikGit/AAT7/Code/DSP/aic3204/include" --include_path="../../../include" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="include/usbstk5515_gpio.pp" --obj_directory="include" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

include/usbstk5515_i2c.obj: ../include/usbstk5515_i2c.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments2/ccsv4/tools/compiler/c5500/bin/cl55" -vcpu:3.3 -g --include_path="C:/Program Files (x86)/Texas Instruments2/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Christian/Documents/AkustikGit/AAT7/Code/DSP/aic3204/include" --include_path="../../../include" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="include/usbstk5515_i2c.pp" --obj_directory="include" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

include/usbstk5515_led.obj: ../include/usbstk5515_led.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"C:/Program Files (x86)/Texas Instruments2/ccsv4/tools/compiler/c5500/bin/cl55" -vcpu:3.3 -g --include_path="C:/Program Files (x86)/Texas Instruments2/ccsv4/tools/compiler/c5500/include" --include_path="C:/Users/Christian/Documents/AkustikGit/AAT7/Code/DSP/aic3204/include" --include_path="../../../include" --diag_warning=225 --ptrdiff_size=32 --memory_model=large --preproc_with_compile --preproc_dependency="include/usbstk5515_led.pp" --obj_directory="include" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


