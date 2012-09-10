/*
 * Triangle.cpp
 *
 *  Created on: 10/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Triangle.h"

/**
 * Draws a right-angled triangle with the inherited attributes
 */
void Triangle::draw() {
	fill_triangle(_color, _position.x, _position.y, _position.x + _width, _position.y, _position.x + _width, _position.y + _height);
}

/**
 * Draws a larger triangle of different colour to indicate
 * that the triangle is highlighted
 */
void Triangle::highlight() {
	fill_triangle(_highlight_color, _position.x - 2*HIGHLIGHT_BORDER_SIZE, _position.y - HIGHLIGHT_BORDER_SIZE, _position.x + _width + HIGHLIGHT_BORDER_SIZE, _position.y - HIGHLIGHT_BORDER_SIZE, _position.x + _width + HIGHLIGHT_BORDER_SIZE, _position.y + _height + 2*HIGHLIGHT_BORDER_SIZE);
}
