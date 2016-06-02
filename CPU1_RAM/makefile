################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/energia-0101E0017/hardware/tools/c2000

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./F2837xS_CodeStartBranch.obj" \
"./F2837xS_DefaultISR.obj" \
"./F2837xS_GlobalVariableDefs.obj" \
"./F2837xS_Gpio.obj" \
"./F2837xS_PieCtrl.obj" \
"./F2837xS_PieVect.obj" \
"./F2837xS_SysCtrl.obj" \
"./F2837xS_usDelay.obj" \
"./HardwareSerial.obj" \
"./main.obj" \
$(GEN_CMDS__FLAG) \
-l"rts2800_fpu32.lib" \
-l"2837xS_Generic_RAM_lnk.cmd" \
-l"F2837xS_Headers_nonBIOS.cmd" \
-l"libc.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
SerialComm.out \

EXE_OUTPUTS__QUOTED += \
"SerialComm.out" \


# All Target
all: SerialComm.out

# Tool invocations
SerialComm.out: $(OBJS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/energia-0101E0017/hardware/tools/c2000/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -g --define=CPU1 --diag_warning=225 --display_error_number --diag_suppress=10063 -z -m"SerialComm.map" --stack_size=0x100 --warn_sections -i"C:/ti/energia-0101E0017/hardware/tools/c2000/lib" -i"C:/ti/energia-0101E0017/hardware/tools/c2000/include" -i"C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_common/cmd" -i"C:/ti/controlSUITE/device_support/F2837xS/v180/F2837xS_headers/cmd" --reread_libs --display_error_number --xml_link_info="SerialComm_linkInfo.xml" --entry_point=code_start --rom_model -o "SerialComm.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "F2837xS_DefaultISR.pp" "F2837xS_GlobalVariableDefs.pp" "F2837xS_Gpio.pp" "F2837xS_PieCtrl.pp" "F2837xS_PieVect.pp" "F2837xS_SysCtrl.pp" "HardwareSerial.pp" "main.pp" 
	-$(RM) "F2837xS_CodeStartBranch.obj" "F2837xS_DefaultISR.obj" "F2837xS_GlobalVariableDefs.obj" "F2837xS_Gpio.obj" "F2837xS_PieCtrl.obj" "F2837xS_PieVect.obj" "F2837xS_SysCtrl.obj" "F2837xS_usDelay.obj" "HardwareSerial.obj" "main.obj" 
	-$(RM) "F2837xS_CodeStartBranch.pp" "F2837xS_usDelay.pp" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

