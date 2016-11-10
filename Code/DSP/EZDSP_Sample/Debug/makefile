################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

EMPTY := 
SPACE := $(EMPTY) $(EMPTY)
CG_TOOL_ROOT := C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500

ORDERED_OBJS += \
$(GEN_CMDS_QUOTED) \
"./vector.obj" \
"./timer.obj" \
"./sar.obj" \
"./rtc.obj" \
"./oled_test.obj" \
"./main.obj" \
"./i2s_register.obj" \
"./i2s.obj" \
"./dma.obj" \
"./aic_test_i2c.obj" \
-l"rts55x.lib" \
-l"usbstk5515bsl.lib" \
"C:/Users/Mikkel Krogh/Downloads/usbstk5515_v1/tests/USB_Stick_Sample/c5505.cmd" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
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
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
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
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: EZDSP_Sample.out


# Tool invocations
EZDSP_Sample.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: Linker'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -vcpu:3.3 -g --define="_DEBUG" --define="C55X" --diag_warning=225 --ptrdiff_size=32 --algebraic --memory_model=large --asm_source=algebraic -z -m"EZDSP_Sample.map" --stack_size=1000 --warn_sections -i"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/lib" -i"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" -i"C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/EZDSP_Sample/../../../lib" -i"C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/rtdx/lib/c5500" -i"C:/Program Files (x86)/Texas Instruments/cssv424/bios_5_41_10_36/packages/ti/bios/lib" -i"C:/Users/Mikkel Krogh/Documents/GitHub/AAT7/Code/DSP/EZDSP_Sample" -i"/lib" --reread_libs --entry_point=reset_isr --rom_model --sys_stacksize=1000 -o "EZDSP_Sample.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(GEN_CMDS__QTD)$(GEN_SRCS__QTD)$(GEN_MISC_FILES__QTD)$(C5500_EXECUTABLE_OUTPUTS__QTD) "EZDSP_Sample.out"
	-$(RM) ".\aic_test_i2c.obj" ".\dma.obj" ".\i2s.obj" ".\i2s_register.obj" ".\main.obj" ".\oled_test.obj" ".\rtc.obj" ".\sar.obj" ".\timer.obj" ".\vector.obj" 
	-$(RM) ".\aic_test_i2c.pp" ".\i2s_register.pp" ".\vector.pp" 
	-$(RM) ".\dma.pp" ".\i2s.pp" ".\main.pp" ".\oled_test.pp" ".\rtc.pp" ".\sar.pp" ".\timer.pp" 
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
