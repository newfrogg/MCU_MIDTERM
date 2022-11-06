/*
 * fsm_button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Beelzebufo
 */

#include <fsm_button.h>

void fsm_simple_buttons_run() {
	switch (status) {
	case INIT:

		if (check_button_flag(0))
			status = RST;
		if (check_button_flag(1)){
			status = INC;
		}
		if (check_button_flag(2)){
			status = DEC;
		}
		if (is_button_pressed_3s(1)) {
			status = INC_3s;
			setTimer(1, 1000);
		}
		if (is_button_pressed_3s(2)) {
			status = DEC_3s;
			setTimer(1, 1000);
		}

		if (is_button_pressed(0) + is_button_pressed(1) + is_button_pressed(2)
				== 0) {
			status = COUNT_DOWN;
			setTimer(1, 1000);
		}

		break;
	case RST:
		globalCount = 0;
		status = INIT;
		break;
	case INC:
		globalCount = (globalCount + 1) % 10;
		status = INIT;
		break;
	case DEC:
		globalCount = (globalCount + 9) % 10;
		status = INIT;
		break;
	default:
		break;
	}
	displayLed7SEG(GPIOB, 0, globalCount);
}

void fsm_complex_buttons_runs() {
	switch (status) {
	case INC_3s:
		if (timer_flag[1]) {
			globalCount = (globalCount + 1) % 10;
			setTimer(1, 1000);
		}
		if (!is_button_pressed(1)){
			status = INIT;
		}
		break;
	case DEC_3s:
		if (timer_flag[1]) {
			globalCount = (globalCount + 9) % 10;
			setTimer(1, 1000);
		}
		if (!is_button_pressed(2))
			status = INIT;
		break;
	default:
		break;
	}
}

void fsm_auto_countdown() {
	switch (status) {
	case COUNT_DOWN:
		if (check_button_flag(0))
			status = RST;
		if (check_button_flag(1))
			status = INC;
		if (check_button_flag(2))
			status = DEC;

		if (is_button_pressed_3s(1)) {
			status = INC_3s;
			setTimer(1, 1000);
		}
		if (is_button_pressed_3s(2)) {
			status = DEC_3s;
			setTimer(1, 1000);
		}

		if (timer_flag[1]) {
			status = (--globalCount == 0) ? STOP : INIT;
			setTimer(1, 1000);
		}
		break;
	case STOP:
		if(check_button_flag(1))
			status = INC;
		if(check_button_flag(2))
			status = DEC;

		break;
	default:
		break;
	}
}

