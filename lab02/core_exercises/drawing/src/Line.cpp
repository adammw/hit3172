/*
 * Line.cpp
 *
 *  Created on: 08/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Line.h"

/**
 * This method draws a diagonal line to the screen
 * using the Shape's attributes
 */
void Line::draw() {
	draw_line(_color, _position.x, _position.y, _position.x + _width, _position.y + _height);
}

/**
 * This method draws crosses at each end of the line
 */
void Line::highlight() {
	draw_line(	_highlight_color,
				_position.x - HIGHLIGHT_BORDER_SIZE,
				_position.y - HIGHLIGHT_BORDER_SIZE,
				_position.x + HIGHLIGHT_BORDER_SIZE,
				_position.y + HIGHLIGHT_BORDER_SIZE);
	draw_line(	_highlight_color,
				_position.x + HIGHLIGHT_BORDER_SIZE,
				_position.y - HIGHLIGHT_BORDER_SIZE,
				_position.x - HIGHLIGHT_BORDER_SIZE,
				_position.y + HIGHLIGHT_BORDER_SIZE);
	draw_line(	_highlight_color,
				_position.x + _width  - HIGHLIGHT_BORDER_SIZE,
				_position.y + _height - HIGHLIGHT_BORDER_SIZE,
				_position.x + _width  + HIGHLIGHT_BORDER_SIZE,
				_position.y + _height + HIGHLIGHT_BORDER_SIZE);
	draw_line(	_highlight_color,
				_position.x + _width  + HIGHLIGHT_BORDER_SIZE,
				_position.y + _height - HIGHLIGHT_BORDER_SIZE,
				_position.x + _width  - HIGHLIGHT_BORDER_SIZE,
				_position.y + _height + HIGHLIGHT_BORDER_SIZE);
}
