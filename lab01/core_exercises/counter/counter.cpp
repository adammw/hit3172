#include "counter.h"

// Counter constructor resets the count to zero
counter::counter() {
	_count = 0;
}

// Increment method increments the count field
void counter::increment() {
	_count++;
}

// Reset method resets the count field to zero
void counter::reset() {
	_count = 0;
}

// Getter for the count field
int counter::get_value() {
	return _count;
}