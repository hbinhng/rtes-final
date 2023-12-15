#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "MKL46Z4.h"
#include "pin_mux.h"

#include "../include/actions.h"
#include "../include/alerts.h"

#define MAX_TIMER_START (2147483647)
#define TICK_INTERVAL 5

_Bool lastSeatTriggerState = false;
int actionTimerStart = MAX_TIMER_START;

void SysTick_Action_Handler(void) {
	if (actionTimerStart == MAX_TIMER_START) return;

	actionTimerStart += TICK_INTERVAL;
}

void seatTrigger(State *state, _Bool value) {
	if (lastSeatTriggerState == value) return;

	if (lastSeatTriggerState == true && value == false) {
		if (state->seated)
			getOutCar(state);
		else
			getInCar(state);
	}

	lastSeatTriggerState = value;
}

void getInCar(State *state) {
	state->seated = true;
	actionTimerStart = 0;
	setDisplay(1);
}

void getOutCar(State *state) {
	state->seated = false;
	actionTimerStart = MAX_TIMER_START;
	setDisplay(0);
}

void fastenSeatBelt(State *state) {
	state->belted = true;
	setDisplay(11);
}

void unfastenSeatBelt(State *state) {
	state->belted = false;
	setDisplay(1);
}
