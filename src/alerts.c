#include "../include/alerts.h"
#include "../lib/Seg_LCD.h"

_Bool blinking = 0;

#define MAX_TIMER_START (2147483647)
#define TICK_INTERVAL 5
#define last(value) ((value) % 10)

int alertTimerStart = MAX_TIMER_START;

void SysTick_Alert_Handler(void) {
	if (alertTimerStart == MAX_TIMER_START) return;
	
	alertTimerStart += TICK_INTERVAL;
}

void setDisplay(char value) {
	SegLCD_Set(last(value / 100), 2);
	SegLCD_Set(last(value / 10), 3);
	SegLCD_Set(last(value), 4);
}

void startBlink(void) {
	
}

void stopBlink(void) {
}
