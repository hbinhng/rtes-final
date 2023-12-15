#ifndef RTES_FINAL_INCLUDE_ACTIONS_H
#define RTES_FINAL_INCLUDE_ACTIONS_H

#include "state.h"

#define SW1_PIN (3)
#define SW1_MASK (1<<SW1_PIN)
#define SW3_PIN (12)
#define SW3_MASK (1<<SW3_PIN)

void seatTrigger(_Bool value);
void beltTrigger(_Bool value);

void getInCar();
void getOutCar();

void fastenSeatBelt();
void unfastenSeatBelt();

#endif // RTES_FINAL_INCLUDE_ACTIONS_H
