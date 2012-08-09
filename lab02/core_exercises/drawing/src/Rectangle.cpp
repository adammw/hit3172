/*
 * Rectangle.cpp
 *
 *  Created on: 08/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Rectangle.h"

void Rectangle::make_square() {
	if ( _height > _width )
		_width = _height;
	else
		_height = _width;}

void Rectangle::draw() {
	fill_rectangle(_color, _position.x, _position.y, _width, _height);
}

