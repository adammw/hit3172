#include "counter.h"

counter::counter() {
	_count = 0;
}

void counter::increment() {
	_count++;
}

void counter::reset() {
	_count = 0;
}

int counter::get_value() {
	return _count;
}