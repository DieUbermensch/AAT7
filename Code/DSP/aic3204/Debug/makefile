################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

EMPTY := 
SPACE := $(EMPTY) $(EMPTY)

ORDERED_OBJS += \
$(GEN_CMDS_QUOTED) \
"./include/usbstk5515_led.obj" \
"./include/usbstk5515_i2c.obj" \
"./include/usbstk5515_gpio.obj" \
"./include/usbstk5515.obj" \
"./main.obj" \
"./FIRFunction.obj" \
-l"usbstk5515bsl.lib" \
-l"rts55x_eh.lib" \
"../lnkx.cmd" \

-include ../makefile.init

RM := DEL /F

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include include/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: aic3204.out


# Tool invocations
aic3204.out: $(GEN_CMDS) $(CMD_SRCS) $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Linker'
	"C:/Program Files (x86)/Texas Instruments2/ccsv4/tools/compiler/c5500/bin/cl55" -vcpu:3.3 -g --diag_warning=225 --ptrdiff_size=32 --memory_model=large -z -m"aic3204.map" --warn_sections -i"C:/Program Files (x86)/Texas Instruments2/ccsv4/tools/compiler/c5500/lib" -i"C:/Program Files (x86)/Texas Instruments2/ccsv4/tools/compiler/c5500/include" -i"C:/Users/Christian/Documents/AkustikGit/AAT7/Code/DSP/aic3204/../../lib" --reread_libs --rom_model -o "aic3204.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C5500_EXECUTABLE_OUTPUTS__QTD) "aic3204.out"
	-$(RM) ".\FIRFunction.obj" ".\main.obj" ".\include\usbstk5515.obj" ".\include\usbstk5515_gpio.obj" ".\include\usbstk5515_i2c.obj" ".\include\usbstk5515_led.obj" 
	-$(RM) ".\FIRFunction.pp" 
	-$(RM) ".\main.pp" ".\include\usbstk5515.pp" ".\include\usbstk5515_gpio.pp" ".\include\usbstk5515_i2c.pp" ".\include\usbstk5515_led.pp" 
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
