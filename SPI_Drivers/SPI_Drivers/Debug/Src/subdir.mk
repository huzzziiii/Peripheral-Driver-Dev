################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/spi_master.c \
../Src/system_stm32f4xx.c 

OBJS += \
./Src/spi_master.o \
./Src/system_stm32f4xx.o 

C_DEPS += \
./Src/spi_master.d \
./Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DSTM32F401xE -I"/engLife/Projects/Mastering embedded systems/STMCubeX/Driver_Development/SPI_Drivers/SPI_Drivers/Inc" -I"/engLife/Projects/Mastering embedded systems/STMCubeX/Driver_Development/SPI_Drivers/SPI_Drivers/Drivers/STM32F4xx_HAL_Driver/Inc" -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"/engLife/Projects/Mastering embedded systems/STMCubeX/Driver_Development/SPI_Drivers/SPI_Drivers/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/engLife/Projects/Mastering embedded systems/STMCubeX/Driver_Development/SPI_Drivers/SPI_Drivers/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


