/*
 * Line.h
 *
 *  Created on: 08/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef LINE_H_
#define LINE_H_

#include "Shape.h"

/**
 * Line class holds all logic to creating and
 * drawing lines to the Drawing, and inherits basic
 * attributes and methods from the Shape class
 */
class Line: public Shape {
public:
	void draw();
	void highlight();
};

#endif /* LINE_H_ */
