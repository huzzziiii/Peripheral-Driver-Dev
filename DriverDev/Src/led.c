/*
 * led.c
 *
 *  Created on: Jun 8, 2018
 *      Author: huzaifaasif
 */

#include "led.h"


void led_init(){
	GPIO_Pin_Config led_pin;

	_HAL_RCC_GPIOA_CLOCK_ENABLE();
	led_pin.pin = GPIO_PIN_5;
	led_pin.mode = GPIO_PIN_OUTPUT_MODE;
	led_pin.op_type = GPIO_OP_TYPE_PUSHPULL;
	led_pin.pull = GPIO_PIN_NO_PULL_PUSH;
	led_pin.speed = GPIO_PIN_SPEED_MEDIUM;

	hal_gpio_init(GPIOA, &led_pin);
}

void led_turn_on(GPIO_TypeDef *GPIOx, uint16_t pin){
	hal_gpio_writepin(GPIOx, pin, 1);
}

void led_turn_off(GPIO_TypeDef *GPIOx, uint16_t pin){
	hal_gpio_writepin(GPIOx, pin, 0);
}


