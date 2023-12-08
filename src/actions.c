#include "../include/actions.h"

void getInCar(State *state) {
	state->seated = true;
}

void getOutCar(State *state) {
	state->seated = false;
}

void fastenSeatBelt(State *state) {
	state->belted = true;
}

void unfastenSeatBelt(State *state) {
	state->belted = false;
}
