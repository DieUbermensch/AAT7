################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

EMPTY := 
SPACE := $(EMPTY) $(EMPTY)
CG_TOOL_ROOT := C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500

ORDERED_OBJS += \
$(GEN_CMDS_QUOTED) \
"./API/src/vectors.obj" \
"./API/src/evm5515_i2c.obj" \
"./API/src/evm5515_gpio.obj" \
"./API/src/evm5515.obj" \
"./API/src/csl_wdt.obj" \
"./API/src/csl_usb.obj" \
"./API/src/csl_uhpi.obj" \
"./API/src/csl_uart.obj" \
"./API/src/csl_sysctrl.obj" \
"./API/src/csl_spi.obj" \
"./API/src/csl_sdio.obj" \
"./API/src/csl_sar.obj" \
"./API/src/csl_rtc.obj" \
"./API/src/csl_pll.obj" \
"./API/src/csl_nand.obj" \
"./API/src/csl_msc.obj" \
"./API/src/csl_mmcsd_ataIf.obj" \
"./API/src/csl_mmcsd.obj" \
"./API/src/csl_mem.obj" \
"./API/src/csl_mcspi.obj" \
"./API/src/csl_mcbsp.obj" \
"./API/src/csl_lcdc.obj" \
"./API/src/csl_irqplug.obj" \
"./API/src/csl_intc.obj" \
"./API/src/csl_i2s.obj" \
"./API/src/csl_i2c_ioExpander.obj" \
"./API/src/csl_i2c.obj" \
"./API/src/csl_hid.obj" \
"./API/src/csl_gpt.obj" \
"./API/src/csl_gpio.obj" \
"./API/src/csl_emif.obj" \
"./API/src/csl_dma.obj" \
"./API/src/csl_dat.obj" \
"./API/src/csl_cdc.obj" \
"./API/src/csl_audioClass.obj" \
"./include/usbstk5515_led.obj" \
"./include/usbstk5515_i2c.obj" \
"./include/usbstk5515_gpio.obj" \
"./include/usbstk5515.obj" \
"./main.obj" \
"./Functions.obj" \
-l"rts55x_eh.lib" \
"../lnkx.cmd" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include include/subdir_vars.mk
-include API/src/subdir_vars.mk
-include subdir_rules.mk
-include include/subdir_rules.mk
-include API/src/subdir_rules.mk
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
all: aic3204Slave.out


# Tool invocations
aic3204Slave.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: Linker'
	"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/bin/cl55" -g --define=CHIP_C5515 --diag_warning=225 --ptrdiff_size=16 --algebraic --memory_model=small --asm_source=algebraic -z -m"aic3204Slave.map" --warn_sections -i"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/lib" -i"C:/Program Files (x86)/Texas Instruments/cssv424/ccsv4/tools/compiler/c5500/include" --reread_libs --rom_model -o "aic3204Slave.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C5500_EXECUTABLE_OUTPUTS__QTD) "aic3204Slave.out"
	-$(RM) ".\Functions.obj" ".\main.obj" ".\include\usbstk5515.obj" ".\include\usbstk5515_gpio.obj" ".\include\usbstk5515_i2c.obj" ".\include\usbstk5515_led.obj" ".\API\src\csl_audioClass.obj" ".\API\src\csl_cdc.obj" ".\API\src\csl_dat.obj" ".\API\src\csl_dma.obj" ".\API\src\csl_emif.obj" ".\API\src\csl_gpio.obj" ".\API\src\csl_gpt.obj" ".\API\src\csl_hid.obj" ".\API\src\csl_i2c.obj" ".\API\src\csl_i2c_ioExpander.obj" ".\API\src\csl_i2s.obj" ".\API\src\csl_intc.obj" ".\API\src\csl_irqplug.obj" ".\API\src\csl_lcdc.obj" ".\API\src\csl_mcbsp.obj" ".\API\src\csl_mcspi.obj" ".\API\src\csl_mem.obj" ".\API\src\csl_mmcsd.obj" ".\API\src\csl_mmcsd_ataIf.obj" ".\API\src\csl_msc.obj" ".\API\src\csl_nand.obj" ".\API\src\csl_pll.obj" ".\API\src\csl_rtc.obj" ".\API\src\csl_sar.obj" ".\API\src\csl_sdio.obj" ".\API\src\csl_spi.obj" ".\API\src\csl_sysctrl.obj" ".\API\src\csl_uart.obj" ".\API\src\csl_uhpi.obj" ".\API\src\csl_usb.obj" ".\API\src\csl_wdt.obj" ".\API\src\evm5515.obj" ".\API\src\evm5515_gpio.obj" ".\API\src\evm5515_i2c.obj" 
	-$(RM) ".\API\src\vectors.obj" 
	-$(RM) ".\Functions.pp" ".\API\src\csl_irqplug.pp" ".\API\src\vectors.pp" 
	-$(RM) ".\main.pp" ".\include\usbstk5515.pp" ".\include\usbstk5515_gpio.pp" ".\include\usbstk5515_i2c.pp" ".\include\usbstk5515_led.pp" ".\API\src\csl_audioClass.pp" ".\API\src\csl_cdc.pp" ".\API\src\csl_dat.pp" ".\API\src\csl_dma.pp" ".\API\src\csl_emif.pp" ".\API\src\csl_gpio.pp" ".\API\src\csl_gpt.pp" ".\API\src\csl_hid.pp" ".\API\src\csl_i2c.pp" ".\API\src\csl_i2c_ioExpander.pp" ".\API\src\csl_i2s.pp" ".\API\src\csl_intc.pp" ".\API\src\csl_lcdc.pp" ".\API\src\csl_mcbsp.pp" ".\API\src\csl_mcspi.pp" ".\API\src\csl_mem.pp" ".\API\src\csl_mmcsd.pp" ".\API\src\csl_mmcsd_ataIf.pp" ".\API\src\csl_msc.pp" ".\API\src\csl_nand.pp" ".\API\src\csl_pll.pp" ".\API\src\csl_rtc.pp" ".\API\src\csl_sar.pp" ".\API\src\csl_sdio.pp" ".\API\src\csl_spi.pp" ".\API\src\csl_sysctrl.pp" ".\API\src\csl_uart.pp" ".\API\src\csl_uhpi.pp" ".\API\src\csl_usb.pp" ".\API\src\csl_wdt.pp" ".\API\src\evm5515.pp" ".\API\src\evm5515_gpio.pp" ".\API\src\evm5515_i2c.pp" 
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
