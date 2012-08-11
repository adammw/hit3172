/*
 * Rectangle.cpp
 *
 *  Created on: 08/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Rectangle.h"

/**
 * This makes the rectangle a square
 * based on it's largest side
 */
void Rectangle::make_square() {
	if ( _height > _width )
		_width = _height;
	else
		_height = _width;
}

/**
 * This method draws the rectangle to the screen
 * using the Shape's #_color property
 */
void Rectangle::draw() {
	fill_rectangle(_color, _position.x, _position.y, _width, _height);
}

/**
 * This method draws a larger rectangle to the screen
 * using the Shape's #_highlight_color property
 */
void Rectangle::highlight() {
	fill_rectangle(_highlight_color, _position.x - HIGHLIGHT_BORDER_SIZE, _position.y - HIGHLIGHT_BORDER_SIZE, _width + 2*HIGHLIGHT_BORDER_SIZE, _height + 2*HIGHLIGHT_BORDER_SIZE);
}
