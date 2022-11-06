/*
 * timer.c
 *
 *  Created on: Nov 2, 2022
 *      Author: Beelzebufo
 */

#include <software_timer.h>

int timer_counter[NO_OF_TIMERS] = { 0, };

int timer_flag[NO_OF_TIMERS] = { 0, };

void setTimer(int index, int duration) {
	timer_counter[index] = duration / CYCLE;
	timer_flag[index] = 0;
}

void runTimer(int index) {
	if (timer_counter[index] > 0) {
		timer_counter[index]--;
		if (timer_counter[index] <= 0)
			timer_flag[index] = 1;
	}
}
