/*
 * Line.cpp
 *
 *  Created on: 08/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Line.h"

Line::Line() {
	// TODO Auto-generated constructor stub

}

Line::~Line() {
	// TODO Auto-generated destructor stub
}

void Line::draw() {
	draw_line(_color, _position.x, _position.y, _position.x + _width, _position.y + _height);
}
