#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "MKL46Z4.h"
#include "pin_mux.h"

#include "../include/init.h"
#include "../include/alerts.h"
#include "../lib/Seg_LCD.h"

_Bool blinking = false;

int alertTimer = 0;

void SysTick_Alert_Handler(void) {
	if (alertTimer > 1e9)
		alertTimer = 0;
	
	alertTimer += TICK_INTERVAL;
	
	if (blinking) {
		if (alertTimer % 50 == 0)
			PTD->PDOR ^= (1 << BOARD_LED_GREEN_GPIO_PIN);
	}
}

void setDisplay(char value) {
	SegLCD_Set((value & 4) >> 2, 2);
	SegLCD_Set((value & 2) >> 1, 3);
	SegLCD_Set(value & 1, 4);
}

void startBlink(void) {
	blinking = true;
}

void stopBlink(void) {
	blinking = false;
	
	PTD->PDOR |= (1 << BOARD_LED_GREEN_GPIO_PIN);
}
