#include "../include/alerts.h"
#include "../lib/Seg_LCD.h"

_Bool blinking = 0;

void setDisplay(char value) {
	SegLCD_Set(value / 10, 3);
	SegLCD_Set(value % 10, 4);
}

void startBlink(void) {
}

void stopBlink(void) {
}
