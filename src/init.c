#include "fsl_device_registers.h"

#include "../include/init.h"

#define GPIOMODE 0x100
#define BPORT_CLOCK 0x400
#define CPORT_CLOCK 0x800
#define DPORT_CLOCK 0x1000
#define EPORT_CLOCK 0x2000

#define GLEDBIT 0x20
#define GLEDPIN 5

#define GLED_VREG (PTD->PDOR)

static inline void alertsInit();
void alertsInit() {	
	/* Enable LEDs */
	
	// Enable Green LED
	PORTD->PCR[GLEDPIN] = GPIOMODE;
	PTD->PDDR |= GLEDBIT;
	GLED_VREG |= GLEDBIT;
	
	/* Enable LCD */
	
	// Initialize ports
	/* LCD_01 */ PORTD->PCR[0]  = GPIOMODE;
	/* LCD_02 */ PORTE->PCR[4]  = GPIOMODE;
	/* LCD_03 */ PORTB->PCR[23] = GPIOMODE;
	/* LCD_04 */ PORTB->PCR[22] = GPIOMODE;
	/* LCD_05 */ PORTC->PCR[17] = GPIOMODE;
	/* LCD_06 */ PORTB->PCR[21] = GPIOMODE;
	/* LCD_07 */ PORTB->PCR[7]  = GPIOMODE;
	/* LCD_08 */ PORTB->PCR[8]  = GPIOMODE;
	/* LCD_09 */ PORTE->PCR[5]  = GPIOMODE;
	/* LCD_10 */ PORTC->PCR[18] = GPIOMODE;
	/* LCD_11 */ PORTB->PCR[10] = GPIOMODE;
	/* LCD_12 */ PORTB->PCR[11] = GPIOMODE;
}

static inline void actionsInit();
void actionsInit() {
}

void init() {
	SIM->SCGC5 |= BPORT_CLOCK | CPORT_CLOCK | DPORT_CLOCK | EPORT_CLOCK;
	
	alertsInit();
	actionsInit();
}