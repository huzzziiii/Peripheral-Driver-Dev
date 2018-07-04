/*
 * led.h
 *
 *  Created on: Jun 8, 2018
 *      Author: huzaifaasif
 */

#ifndef LED_LED_H_
#define LED_LED_H_

#include "stm32f401xx_gpio_driver.h"

#define LED2_PORT	GPIOA
#define GPIO_PIN_5 	5			//LED PIN

void led_init();
void led_turn_on(GPIO_TypeDef *GPIOx, uint16_t pin);
void led_turn_off(GPIO_TypeDef *GPIOx, uint16_t pin);


#endif /* LED_LED_H_ */
