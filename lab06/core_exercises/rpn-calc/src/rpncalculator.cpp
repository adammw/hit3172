/*
 * rpncalculator.cpp
 *
 *  Created on: 03/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "rpncalculator.h"

using namespace std;

rpn_calculator::rpn_calculator() {
	// TODO Auto-generated constructor stub

}

rpn_calculator::~rpn_calculator() {
	// TODO Auto-generated destructor stub
}

void rpn_calculator::push(int value) {
	_operands.push_back(value);
}

int rpn_calculator::pop() {
	int value = _operands.back();
	_operands.pop_back();
	return value;
}

int rpn_calculator::peek_answer() {
	return _operands.back();
}

void rpn_calculator::add() {
	int operand_1 = pop();
	int operand_2 = pop();

	push(operand_2 + operand_1);
}

void rpn_calculator::subtract() {
	int operand_1 = pop();
	int operand_2 = pop();

	push(operand_2 - operand_1);
}

void rpn_calculator::multiply() {
	int operand_1 = pop();
	int operand_2 = pop();

	push(operand_2 * operand_1);
}

void rpn_calculator::divide() {
	int operand_1 = pop();
	int operand_2 = pop();

	push(operand_2 / operand_1);
}

int rpn_calculator::answer() {
	return pop();
}
