/*
 * Shape.cpp
 *
 *  Created on: 07/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Shape.h"

Shape::Shape() {
	// Initalise position
	_position.x = _position.y = 0;
}

Shape::~Shape() {
	// TODO Auto-generated destructor stub
}

color Shape::get_color() {
	return _color;
}

point2d Shape::get_position() {
	return _position;
}

int Shape::get_width() {
	return _width;
}

int Shape::get_height() {
	return _height;
}
float Shape::get_x() {
	return _position.x;
}

void Shape::set_color(color theColor){
	_color = theColor;
}
void Shape::set_position(point2d position) {
	_position = position;
}
void Shape::set_width(int width) {
	_width = width;
}
void Shape::set_height(int height) {
	_height = height;
}
void Shape::set_x(float x) {
	_position.x = x;
}
void Shape::set_y(float y) {
	_position.y = y;
}
bool Shape::is_at(point2d position) {
	return (position.x >= _position.x &&
			position.x < _position.x + _width &&
			position.y >= _position.y &&
			position.y < _position.y + _height);
}
