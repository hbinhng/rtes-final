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

int main() {
	BOARD_InitPins();
	BOARD_BootClockRUN();
	BOARD_InitDebugConsole();
	
	init();
	
	State *state = (State*)malloc(sizeof(State));
	
	return 0;
}
