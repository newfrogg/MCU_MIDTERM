/*
 * input_reading.h
 *
 *  Created on: Nov 2, 2022
 *      Author: Beelzebufo
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_
#include <main.h>
#include <global.h>
#include <software_timer.h>

void button_reading(void);
unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_pressed_3s(unsigned char index);
int check_button_flag(int i);
#endif /* INC_INPUT_READING_H_ */
