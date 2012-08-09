/*
 * Line.cpp
 *
 *  Created on: 08/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Line.h"

void Line::draw() {
	draw_line(_color, _position.x, _position.y, _position.x + _width, _position.y + _height);
}

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
