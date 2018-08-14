#include "adx345.h"
#include <stdbool.h>

void adxPin_init(){
	GPIO_PIN_CONFIG led_pin_config;
	_HAL_RCC_GPIOC_CLK_ENABLE();			// *CHANGE PORT*

	led_pin_config.pin = ADX_PIN;
	led_pin_config.mode = GPIO_PIN_OUTPUT_MODE;
	led_pin_config.op_type = GPIO_PUSH_PULL;
	led_pin_config.speed = GPIO_MEDIUM_SPEED;
	led_pin_config.pull = GPIO_NO_PUPD;

	//Initializing PIN
	hal_gpio_init(GPIOA, &led_pin_config);	// *CHANGE PORT*

	//Disabling CS
	hal_gpio_write_to_pin(GPIOC, 0, ADX_PIN);	//* CHANGE PORT *

}

void powerOn(spi_handle_t spiHandle){
	writeTo(ADXL345_POWER_CTL, 0, spiHandle);	// Wakeup
	writeTo(ADXL345_POWER_CTL, 16, spiHandle);	// Auto_Sleep
	writeTo(ADXL345_POWER_CTL, 8, spiHandle);	// Measure
}

void setRegisterBit(uint8_t address, uint8_t bit_pos, bool state, spi_handle_t spiHandle){
	uint8_t data;
	readFrom(address, 1, &data, spiHandle);

	if (state){
		data |= (state << bit_pos);	//4-wire SPI
	}
	else{
		data &= ~(state << bit_pos);	//3-wire SPI
	}

	writeTo(address, data, spiHandle);
}


void setSPI(bool state, spi_handle_t spiHandle){
	setRegisterBit(ADXL345_DATA_FORMAT, 6, 1, spiHandle);
}

/*************************** READ FROM SPI **************************/
void readFrom(uint8_t address, uint8_t bytes_to_read, uint8_t buff[], spi_handle_t spiHandle){
	address |= 0x80;		// Enable READ bit
	//MB = 0 	-- read 1 byte

	/* Enabling CS */
	hal_gpio_write_to_pin(ADX_PORT, 0, ADX_PIN);

	/* Transmitting the register address */
	uint32_t temp = SPItransfer(&spiHandle, address, 1);

	/* reading data */
	buffer[0] = SPItransfer(&spiHandle, 0x00, 1);

	/* Disabling CS */
	hal_gpio_write_to_pin(ADX_PORT, 1, ADX_PIN);
}

/*************************** WRITE TO SPI **************************/
void writeTo(uint8_t address, uint8_t data, spi_handle_t spiHandle){
	/* Enabling CS */
	hal_gpio_write_to_pin(ADX_PORT, 0, ADX_PIN);

	/* Transmitting the register address */
	SPItransfer(&spiHandle, address, 1);

	/* Transmitting data */
	SPItransfer(&spiHandle, data, 1);

	/* Disabling CS */
	hal_gpio_write_to_pin(ADX_PORT, 1, ADX_PIN);

}

/*********************** READING ACCELERATION ***********************/

void readAccel(spi_handle_t spiHandle){
	readFrom(ADXL345_DEVID, BYTES_TO_READ, buffer, spiHandle);
}

/*********************** THRESH_ACT REGISTER ************************/
void setActivityThreshold(uint8_t activityThreshold, spi_handle_t spiHandle){
	writeTo(ADXL345_THRESH_ACT, activityThreshold, spiHandle);
}

/************************** ACTIVITY BITS ***************************/
void setActivityXYZ(bool stateX, bool stateY, bool stateZ, spi_handle_t spiHandle){
	setRegisterBit( ADXL345_ACT_INACT_CTL,  6,  stateX, spiHandle);
	setRegisterBit( ADXL345_ACT_INACT_CTL,  5,  stateY, spiHandle);
	setRegisterBit( ADXL345_ACT_INACT_CTL,  4,  stateZ, spiHandle);
}

void setInactivityXYZ(bool stateX, bool stateY, bool stateZ, spi_handle_t spiHandle){
	setRegisterBit( ADXL345_ACT_INACT_CTL,  2,  stateX, spiHandle);
	setRegisterBit( ADXL345_ACT_INACT_CTL,  1,  stateY, spiHandle);
	setRegisterBit( ADXL345_ACT_INACT_CTL,  0,  stateZ, spiHandle);
}

void setInactivityThreshold(uint8_t inactivityThreshold, spi_handle_t spiHandle){
	writeTo(ADXL345_THRESH_INACT, inactivityThreshold, spiHandle);
}

/*********************** TIME_INACT RESIGER *************************/
void setTimeInactivity(uint8_t timeInactivity, spi_handle_t spiHandle) {
	writeTo(ADXL345_TIME_INACT, timeInactivity, spiHandle);

}

/**************************** TAP BITS ******************************/
void setTapDetectionOnXYZ(bool stateX, bool stateY, bool stateZ, spi_handle_t spiHandle){

	setRegisterBit(ADXL345_TAP_AXES, 2, stateX, spiHandle);
	setRegisterBit(ADXL345_TAP_AXES, 1, stateY, spiHandle);
	setRegisterBit(ADXL345_TAP_AXES, 0, stateZ, spiHandle);
}

/*********************** THRESH_TAP BYTE VALUE **********************/
void setTapThreshold(uint8_t tapThreshold, spi_handle_t spiHandle){
	writeTo(ADXL345_THRESH_TAP, tapThreshold, spiHandle);
}

/*********************** THRESH_FF Register *************************/
void setFreeFallThreshold(uint8_t freeFallThreshold, spi_handle_t spiHandle){
	writeTo(ADXL345_THRESH_FF, freeFallThreshold, spiHandle);
}

/************************ TIME_FF Register **************************/
void setFreeFallDuration(uint8_t freeFallDuration, spi_handle_t spiHandle){
	writeTo(ADXL345_TIME_FF, freeFallDuration, spiHandle);
}
