/*
 * Rectangle.cpp
 *
 *  Created on: 08/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Rectangle.h"

Rectangle::Rectangle() {
	// TODO Auto-generated constructor stub

}

Rectangle::~Rectangle() {
	// TODO Auto-generated destructor stub
}

void Rectangle::make_square() {
	_width = _height;
}

void Rectangle::draw() {
	fill_rectangle(_color, _position.x, _position.y, _width, _height);
}

