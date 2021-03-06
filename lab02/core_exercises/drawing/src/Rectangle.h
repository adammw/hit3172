/*
 * Rectangle.h
 *
 *  Created on: 08/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

/**
 * Rectangle class holds all logic to creating
 * and drawing rectangles, and inherits basic
 * attributes and methods from the Shape class
 */
class Rectangle: public Shape {
public:
	void make_square();
	void draw();
	void highlight();
};

#endif /* RECTANGLE_H_ */
