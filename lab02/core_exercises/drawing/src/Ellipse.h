/*
 * Ellipse.h
 *
 *  Created on: 09/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include "Shape.h"

/**
 * Ellipse class holds all logic to creating and
 * drawing ellipses, and inherits basic attributes
 * and methods from the Shape class
 */
class Ellipse: public Shape {
public:
	void draw();
	void highlight();
};

#endif /* ELLIPSE_H_ */
