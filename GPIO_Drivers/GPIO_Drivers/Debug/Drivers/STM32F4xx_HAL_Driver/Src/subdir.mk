################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_gpio_driver.c 

OBJS += \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_gpio_driver.o 

C_DEPS += \
./Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F4xx_HAL_Driver/Src/%.o: ../Drivers/STM32F4xx_HAL_Driver/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DSTM32F401xE -I"/engLife/Projects/Mastering embedded systems/STMCubeX/Driver_Development/GPIO_Drivers/GPIO_Drivers/Inc" -I"/engLife/Projects/Mastering embedded systems/STMCubeX/Driver_Development/GPIO_Drivers/GPIO_Drivers/Drivers/STM32F4xx_HAL_Driver/Inc" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"/engLife/Projects/Mastering embedded systems/STMCubeX/Driver_Development/GPIO_Drivers/GPIO_Drivers/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/engLife/Projects/Mastering embedded systems/STMCubeX/Driver_Development/GPIO_Drivers/GPIO_Drivers/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


