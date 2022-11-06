/*
 * displayLed7Segment.h
 *
 *  Created on: Nov 2, 2022
 *      Author: Beelzebufo
 */

#ifndef INC_LED7SEGMENT_H_
#define INC_LED7SEGMENT_H_

#include "main.h"

/*
 * change the state of led7Segment which are adjective to match a number ( 0 -- 9)
 *
 * @param 		index: address of the 1st pin
 * @param		number: number to display
 *
 * @notice: 	This function doesn't take effect on the last pin of led7Segment (enable).
 * 				Need to set enable to display your number on.
 */
void displayLed7SEG(GPIO_TypeDef *GPIOx, int index, int number);

/*
 *	For display multi-led7Segment within defined scan frequency
 *
 *
 */
#define NO_OF_LED_7SEGMENT 2
extern int led_buffer[NO_OF_LED_7SEGMENT];

/*
 * update the enable which are adjective to display 1 number each time
 * and change the led7Segment with the led_buffer[ ]
 *
 * @param 		index: address of 1st enable
 * @param 		number: number of enable[number] and led_buffer[number] to display *
 *
 */
void updateled7SEG(GPIO_TypeDef* GPIOx, int index, int number);

#endif /* INC_LED7SEGMENT_H_ */
