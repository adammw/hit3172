#ifndef COUNTER_H
#define COUNTER_H

class counter {
private:
	int _count;

public:
	counter();

	void increment();
	void reset();
	int get_value();
};

#endif