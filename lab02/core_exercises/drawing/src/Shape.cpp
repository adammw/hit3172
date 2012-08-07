/*
 * Shape.cpp
 *
 *  Created on: 07/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Shape.h"

Shape::Shape() {

	//TODO
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
bool Shape::is_at(point2d position) {
	return (position.x >= _position.x &&
			position.x < _position.x + _width &&
			position.y >= _position.y &&
			position.y < _position.y + _height);
}
void Shape::draw() {
	draw_rectangle_on_screen(_color, _position.x, _position.y, _width, _height);
}
