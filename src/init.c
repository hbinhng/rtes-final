#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "MKL46Z4.h"
#include "pin_mux.h"

#include "../include/actions.h"
#include "../include/init.h"
#include "../lib/Seg_LCD.h"

#define GPIOMODE 0x100

void SysTick_Alert_Handler(void);
void SysTick_Action_Handler(void);

void SysTick_Handler(void) {
	SysTick_Alert_Handler();
	SysTick_Action_Handler();
}

void alertsInit(void) {	
	/* Enable LEDs */
	
	// Enable Green LED
	BOARD_LED_GREEN_GPIO_PORT->PCR[BOARD_LED_GREEN_GPIO_PIN] = GPIOMODE;
	PTD->PDDR |= 1 << BOARD_LED_GREEN_GPIO_PIN;
	
	LED_GREEN_OFF();
	
	/* Enable LCD */
	
	SegLCD_Init();
}

void actionsInit(void) {
	/* Enable Switches */
	
	// Enable SW1
	PORTC->PCR[3] = GPIOMODE | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
	PTC->PDDR &= ~SW1_MASK;

	// Enable SW3
	PORTC->PCR[12] = GPIOMODE | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
	PTC->PDDR &= ~SW3_MASK;
}

void init(void) {
	SIM->SCGC5 = SIM->SCGC5
		| SIM_SCGC5_PORTB_MASK
		| SIM_SCGC5_PORTC_MASK
		| SIM_SCGC5_PORTD_MASK
		| SIM_SCGC5_PORTE_MASK
		| SIM_SCGC5_SLCD_MASK;
	
	alertsInit();
	actionsInit();
}
