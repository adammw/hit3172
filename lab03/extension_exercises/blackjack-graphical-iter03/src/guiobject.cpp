/*
 * guiobject.cpp
 *
 *  Created on: 23/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "guiobject.h"

gui_object::gui_object() {
	// TODO Auto-generated constructor stub

}

gui_object::~gui_object() {
	// TODO Auto-generated destructor stub
}

float gui_object::get_height() {
	return _height;
}

float gui_object::get_width() {
	return _width;
}

point2d gui_object::get_position() {
	return _position;
}

void gui_object::set_height(float height) {
	_height = height;
}

void gui_object::set_width(float width) {
	_width = width;
}

void gui_object::set_position(point2d position) {
	_position = position;
}

bool gui_object::is_at(point2d point) {
	return (point.x >= _position.x && point.x <= _position.x + _width &&
			point.y >= _position.y && point.y <= _position.y + _height);
}
