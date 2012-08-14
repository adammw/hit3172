#ifndef COUNTER_H
#define COUNTER_H
/**
 * The counter class is the specification for all the counter objects *
 */
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