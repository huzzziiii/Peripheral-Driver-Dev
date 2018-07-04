################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/led.c \
../Src/main.c \
../Src/system_stm32f4xx.c 

OBJS += \
./Src/led.o \
./Src/main.o \
./Src/system_stm32f4xx.o 

C_DEPS += \
./Src/led.d \
./Src/main.d \
./Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DSTM32F401xE -DUSE_HAL_DRIVER -I"/engLife/Projects/Mastering embedded systems/STMCubeX/Driver_Development/DriverDev/Inc" -I"/engLife/Projects/Mastering embedded systems/STMCubeX/Driver_Development/DriverDev/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/engLife/Projects/Mastering embedded systems/STMCubeX/Driver_Development/DriverDev/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/engLife/Projects/Mastering embedded systems/STMCubeX/Driver_Development/DriverDev/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/engLife/Projects/Mastering embedded systems/STMCubeX/Driver_Development/DriverDev/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


