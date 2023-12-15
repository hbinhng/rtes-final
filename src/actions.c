#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "MKL46Z4.h"
#include "pin_mux.h"

#include "../include/init.h"
#include "../include/actions.h"
#include "../include/alerts.h"

#define MAX_TIMER_START (2147483647)

extern State *state;

_Bool lastSeatTriggerState = false;
_Bool lastBeltTriggerState = false;
int actionTimerStart = MAX_TIMER_START;

void SysTick_Action_Handler(void) {
	if (actionTimerStart == MAX_TIMER_START) return;

	actionTimerStart += TICK_INTERVAL;

	if (actionTimerStart == 10 * ONE_SECOND) {
		state->status |= 4;
		actionTimerStart = MAX_TIMER_START;
	}
}

void seatTrigger(_Bool value) {
	if (lastSeatTriggerState == value) return;

	if (lastSeatTriggerState == true && value == false) {
		if (state->seated)
			getOutCar(state);
		else
			getInCar(state);
	}

	lastSeatTriggerState = value;
}

void beltTrigger(_Bool value) {
	if (lastBeltTriggerState == value) return;
	if (state->seated == false) goto final;

	if (lastBeltTriggerState == true && value == false) {
		if (state->belted)
			unfastenSeatBelt(state);
		else
			fastenSeatBelt(state);
	}

	final:
	lastBeltTriggerState = value;
}

void getInCar() {
	state->seated = true;
	state->belted = false;
	actionTimerStart = 0;
	state->status = 1;
}

void getOutCar() {
	state->seated = false;
	state->belted = false;
	actionTimerStart = MAX_TIMER_START;
	state->status = 0;
}

void fastenSeatBelt() {
	state->belted = true;
}

void unfastenSeatBelt() {
	state->belted = false;
	actionTimerStart = 0;
	state->status &= 1;
}
