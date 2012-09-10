/*
 * rpncalculator.h
 *
 *  Created on: 03/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include <vector>

#ifndef RPNCALCULATOR_H_
#define RPNCALCULATOR_H_

class rpn_calculator {
private:
	std::vector<int> _operands;
	int pop();

public:
	rpn_calculator();
	virtual ~rpn_calculator();

	void push(int value);
	int peek_answer();
	int answer();
	void add();
	void subtract();
	void multiply();
	void divide();
};

#endif /* RPNCALCULATOR_H_ */
