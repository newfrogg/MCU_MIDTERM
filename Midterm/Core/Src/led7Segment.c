/*
 * displayLed7Segment.c
 *
 *  Created on: Nov 2, 2022
 *      Author: Beelzebufo
 */

#include <led7Segment.h>

void displayLed7SEG(GPIO_TypeDef *GPIOx, int index, int number) {
	__IO uint16_t temp;
	switch (number) {
	case 0:
		temp = 0b0111111;
		break;
	case 1:
		temp = 0b0000110;
		break;
	case 2:
		temp = 0b1011011;
		break;
	case 3:
		temp = 0b1001111;
		break;
	case 4:
		temp = 0b1100110;
		break;
	case 5:
		temp = 0b1101101;
		break;
	case 6:
		temp = 0b1111101;
		break;
	case 7:
		temp = 0b0000111;
		break;
	case 8:
		temp = 0b1111111;
		break;
	case 9:
		temp = 0b1101111;
		break;
	default:
		temp = 0b1111111;
		break;
	}
	temp = ~temp;
	uint16_t bitmask = 0b1111111 << index;
	GPIOx->ODR = (GPIOx->ODR & ~bitmask) | (temp << index);

}

void updateled7SEG(GPIO_TypeDef* GPIOx, int index, int number){
	if(number < 0 || index > NO_OF_LED_7SEGMENT) return;

}











