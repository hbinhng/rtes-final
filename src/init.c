#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "MKL46Z4.h"
#include "pin_mux.h"

#include "../include/init.h"
#include "../lib/Seg_LCD.h"

#define GPIOMODE 0x100
#define BPORT_CLOCK 0x400
#define CPORT_CLOCK 0x800
#define DPORT_CLOCK 0x1000
#define EPORT_CLOCK 0x2000

#define GLEDBIT 0x20
#define GLEDPIN 5

#define GLED_VREG (PTD->PDOR)

void alertsInit() {	
	/* Enable LEDs */
	
	// Enable Green LED
	PORTD->PCR[GLEDPIN] = GPIOMODE;
	PTD->PDDR |= GLEDBIT;
	GLED_VREG |= GLEDBIT;
	GLED_VREG ^= GLEDBIT;
	
	/* Enable LCD */
	
	SegLCD_Init();
}

void actionsInit() {
	/* Enable Switches */
	
	PORTC->PCR[3] = GPIOMODE | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
	PTC->PDDR &= ~0x8;
}

void init() {
	SIM->SCGC5 = SIM->SCGC5
		| SIM_SCGC5_PORTB_MASK
		| SIM_SCGC5_PORTC_MASK
		| SIM_SCGC5_PORTD_MASK
		| SIM_SCGC5_PORTE_MASK
		| SIM_SCGC5_SLCD_MASK;
	
	alertsInit();
	actionsInit();
}