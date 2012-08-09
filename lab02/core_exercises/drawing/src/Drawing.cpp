/*
 * Drawing.cpp
 *
 *  Created on: 08/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Drawing.h"

Drawing::Drawing() {
	_selected_shape = NULL;
	_background_color = 0xffeeeecc;
}

Drawing::~Drawing() {
	for ( size_t i = 0; i < _shapes.size(); i++ ) {
		delete _shapes[i];
	}
}

Shape* Drawing::get_selected_shape() {
	return _selected_shape;
}

color Drawing::get_background_color() {
	return _background_color;
}

void Drawing::set_background_color(color bg) {
	_background_color = bg;
}

void Drawing::add_shape(Shape* shape) {
	_shapes.push_back(shape);
}

void Drawing::select_shape_at_point(point2d point) {
	_selected_shape = NULL;
	for ( size_t i = 0; i < _shapes.size(); i++ ) {
		if (_shapes[i]->is_at(point))
			_selected_shape = _shapes[i];
	}
}

void Drawing::draw() {
	clear_screen(_background_color);

	for ( size_t i = 0; i < _shapes.size(); i++ ) {
		if (_selected_shape && _shapes[i] == _selected_shape)
			_selected_shape->highlight();
		_shapes[i]->draw();
	}
}
