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

void Ellipse::highlight() {
	fill_ellipse(_highlight_color, _position.x - HIGHLIGHT_BORDER_SIZE, _position.y - HIGHLIGHT_BORDER_SIZE, _width + 2*HIGHLIGHT_BORDER_SIZE, _height + 2*HIGHLIGHT_BORDER_SIZE);
}
