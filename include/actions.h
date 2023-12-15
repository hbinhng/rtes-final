#ifndef RTES_FINAL_INCLUDE_ACTIONS_H
#define RTES_FINAL_INCLUDE_ACTIONS_H

#include "state.h"

#define SW1_PIN (3)
#define SW1_MASK (1<<SW1_PIN)
#define SW3_PIN (12)
#define SW3_MASK (1<<SW3_PIN)

void seatTrigger(State *state, _Bool value);
void beltTrigger(State *state, _Bool value);

void getInCar(State *state);
void getOutCar(State *state);

void fastenSeatBelt(State *state);
void unfastenSeatBelt(State *state);

#endif // RTES_FINAL_INCLUDE_ACTIONS_H
