#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "MKL46Z4.h"
#include "pin_mux.h"

#include "../include/state.h"
#include "../include/init.h"
#include "../include/actions.h"
#include "../include/alerts.h"

#include <stdlib.h>

State *state;

int main(void) {
	BOARD_InitPins();
	BOARD_BootClockRUN();
	BOARD_InitDebugConsole();

	init();

	state = (State*)malloc(sizeof(State));

	state->status = 0;

	while (1) {
		setDisplay(state->status);
		if (state->status >> 2) startBlink();
		else stopBlink();

		_Bool isSwitch1Clicked = 1 - ((PTC->PDIR >> SW1_PIN) & 1);
		_Bool isSwitch3Clicked = 1 - ((PTC->PDIR >> SW3_PIN) & 1);

		seatTrigger(isSwitch1Clicked);
		beltTrigger(isSwitch3Clicked);
	}
}
