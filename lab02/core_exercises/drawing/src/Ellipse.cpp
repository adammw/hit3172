/*
 * Ellipse.cpp
 *
 *  Created on: 09/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Ellipse.h"

void Ellipse::draw() {
	fill_ellipse(_color, _position.x, _position.y, _width, _height);
}
