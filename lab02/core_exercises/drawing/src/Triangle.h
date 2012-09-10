/*
 * Triangle.h
 *
 *  Created on: 10/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"

/**
 * Triangle class holds all logic to creating and
 * drawing triangles, and inherits basic attributes
 * and methods from the Shape class
 */
class Triangle: public Shape {
public:
	void draw();
	void highlight();
};

#endif /* TRIANGLE_H_ */
