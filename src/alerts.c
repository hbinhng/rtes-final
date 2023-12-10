#include "../include/alerts.h"
#include "../lib/Seg_LCD.h"

_Bool blinking = 0;

#define last(value) ((value) % 10)

void setDisplay(char value) {
	SegLCD_Set(last(value / 100), 2);
	SegLCD_Set(last(value / 10), 3);
	SegLCD_Set(last(value), 4);
}

void startBlink(void) {
}

void stopBlink(void) {
}
