/*
 * fsm_button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Beelzebufo
 */

#ifndef INC_FSM_BUTTON_H_
#define INC_FSM_BUTTON_H_

#include <global.h>
#include <main.h>
#include <input_reading.h>
#include <led7Segment.h>

void fsm_simple_buttons_run();

void fsm_complex_buttons_runs();

void fsm_auto_countdown();
#endif /* INC_FSM_BUTTON_H_ */
