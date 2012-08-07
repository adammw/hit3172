#include <iostream>
#include "counter.h"

using namespace std;

int main() {
	int i;
	counter* counter1 = new counter;
	counter* counter2 = new counter;

	for (i = 0; i < 5; i++) {
		counter1->increment();
	}

	for (i = 0; i < 10; i++) {
		counter2->increment();
	}

	cout << "Counter 1: " << counter1->get_value() << endl;
	cout << "Counter 2: " << counter2->get_value() << endl;

	delete counter1;
	delete counter2;

	return 0;
}