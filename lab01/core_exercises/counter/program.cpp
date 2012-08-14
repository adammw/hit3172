#include <iostream>
#include "counter.h"

using namespace std;

int main() {
	int i;
	// Create two counter objects
	counter* counter1 = new counter;
	counter* counter2 = new counter;

	// Call the increment method on the first counter five times
	for (i = 0; i < 5; i++) {
		counter1->increment();
	}

	// Call the increment method on the second counter ten times
	for (i = 0; i < 10; i++) {
		counter2->increment();
	}


	// Get the value of the counter objects and print them to the screen
	cout << "Counter 1: " << counter1->get_value() << endl;
	cout << "Counter 2: " << counter2->get_value() << endl;

	// Delete the counter objects
	delete counter1;
	delete counter2;

	return 0;
}