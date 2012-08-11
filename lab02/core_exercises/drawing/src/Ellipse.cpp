/*
 * Ellipse.cpp
 *
 *  Created on: 09/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Ellipse.h"

/**
 * Draws an ellipse with the inherited attributes
 */
void Ellipse::draw() {
	fill_ellipse(_color, _position.x, _position.y, _width, _height);
}

/**
 * Draws a larger ellipse of different colour to indicate
 * that the ellipse is highlighted
 */
void Ellipse::highlight() {
	fill_ellipse(_highlight_color, _position.x - HIGHLIGHT_BORDER_SIZE, _position.y - HIGHLIGHT_BORDER_SIZE, _width + 2*HIGHLIGHT_BORDER_SIZE, _height + 2*HIGHLIGHT_BORDER_SIZE);
}
