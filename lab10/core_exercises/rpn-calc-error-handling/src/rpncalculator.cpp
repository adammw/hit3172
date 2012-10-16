/*
 * rpncalculator.cpp
 *
 *  Created on: 03/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "rpncalculator.h"
#include <string>
#include <iostream>

using namespace std;

rpn_calculator::rpn_calculator() {
	// TODO Auto-generated constructor stub

}

rpn_calculator::~rpn_calculator() {
	// TODO Auto-generated destructor stub
}

/**
 * Push a new value onto the operands stack
 * @param value
 */
void rpn_calculator::push(int value) {
	_operands.push_back(value);
}

/**
 * Pop a value from the operands stack
 * (removes the value from the stack and returns it)
 * @return
 */
int rpn_calculator::pop() {
	int value = _operands.back();
	_operands.pop_back();
	return value;
}

/**
 * Peek at the answer (top of stack) without
 * removing it from the stack
 * @return
 */
int rpn_calculator::peek_answer() {
	return _operands.back();
}

/**
 * Add the last two operands together and
 * push the result back onto the stack
 */
void rpn_calculator::add() {
	int operand_1, operand_2;

	if ( _operands.size() < 2 ) {
		cerr << "Insufficient operators for the add command." << endl;
		return;
	}

	operand_1 = pop();
	operand_2 = pop();

	push(operand_2 + operand_1);
}

/**
 * Subtract the second last operand from the last operand and
 * push the result back onto the stack
 */
void rpn_calculator::subtract() {
	int operand_1, operand_2;

	if ( _operands.size() < 2 ) {
		cerr << "Insufficient operators for the subtract command." << endl;
		return;
	}

	operand_1 = pop();
	operand_2 = pop();

	push(operand_2 - operand_1);
}

/**
 * Multiply the last two operands together and
 * push the result back onto the stack
 */
void rpn_calculator::multiply() {
	int operand_1, operand_2;

	if ( _operands.size() < 2 ) {
		cerr << "Insufficient operators for the multiply command." << endl;
		return;
	}

	operand_1 = pop();
	operand_2 = pop();

	push(operand_2 * operand_1);
}

/**
 * Divide the second last operand by the last operand and
 * push the result back onto the stack
 */
void rpn_calculator::divide() {
	int operand_1, operand_2;

	if ( _operands.size() < 2 ) {
		cerr << "Insufficient operators for the divide command." << endl;
		return;
	}

	operand_1 = pop();
	operand_2 = pop();

	push(operand_2 / operand_1);
}

/**
 * Get the answer (result) from the top of the stack
 * and remove it from the stack
 * @see pop
 * @return
 */
int rpn_calculator::answer() {
	return pop();
}
