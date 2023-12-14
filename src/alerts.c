#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "MKL46Z4.h"
#include "pin_mux.h"

#include "../include/alerts.h"
#include "../lib/Seg_LCD.h"

_Bool blinking = 0;

#define TICK_INTERVAL 5
#define last(value) ((value) % 10)

int alertTimer = 0;

void SysTick_Alert_Handler(void) {
	if (alertTimer > 1e9)
		alertTimer = 0;
	
	alertTimer += TICK_INTERVAL;
	
	if (blinking == 1) {
		if (alertTimer % 50 == 0)
			LED_GREEN_TOGGLE();
	}
}

void setDisplay(char value) {
	SegLCD_Set(last(value / 100), 2);
	SegLCD_Set(last(value / 10), 3);
	SegLCD_Set(last(value), 4);
}

void startBlink(void) {
	blinking = 1;
}

void stopBlink(void) {
	blinking = 0;
	
	LED_GREEN_OFF();
}
