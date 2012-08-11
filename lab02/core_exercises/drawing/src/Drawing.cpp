/*
 * Drawing.cpp
 *
 *  Created on: 08/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Drawing.h"

/**
 * The constructor initialises the #_selected_shape and
 * #_background_color data members
 */
Drawing::Drawing() {
	_selected_shape = NULL;
	_background_color = 0xffeeeecc;
}

/**
 * Upon destruction, memory for each shape the drawing
 * holds is freed (ie. each shape is deleted)
 */
Drawing::~Drawing() {
	for ( size_t i = 0; i < _shapes.size(); i++ ) {
		delete _shapes[i];
	}
}

/**
 * Gets the selected shape
 * @return the selected shape
 */
Shape* Drawing::get_selected_shape() {
	return _selected_shape;
}

/**
 * Gets the background colour
 * @return the background colour
 */
color Drawing::get_background_color() {
	return _background_color;
}

/**
 * Sets the background colour
 * @param bg background colour
 */
void Drawing::set_background_color(color bg) {
	_background_color = bg;
}

/**
 * Adds a Shape to the drawing
 * @param shape the shape to add
 */
void Drawing::add_shape(Shape* shape) {
	_shapes.push_back(shape);
}

/**
 * Deletes the selected shape from the drawing,
 * freeing it's memory and removing it from #_shapes
 */
void Drawing::delete_selected_shape() {
	if (!_selected_shape) return;

	// find position in vector and remove it
	for ( size_t i = 0; i < _shapes.size(); i++) {
		if (_shapes[i] == _selected_shape) {
			_shapes.erase(_shapes.begin()+i);
			delete _selected_shape;
			_selected_shape = NULL;
			return;
		}
	}
}

/**
 * Moves the selected shape down in the array,
 * unless it is the first already
 */
void Drawing::move_selected_shape_down() {
	if (!_selected_shape) return;

	// find position in vector and remove it
	for ( size_t i = 0; i < _shapes.size(); i++) {
		if (_shapes[i] == _selected_shape) {
			if (i == 0) return;
			std::vector<Shape *>::iterator iter = _shapes.begin();
			_shapes.erase(iter+i);
			_shapes.insert(iter+i-1, _selected_shape);
			return;
		}
	}
}

/**
 * Moves the selected shape up in the array,
 * unless it is the last already
 */
void Drawing::move_selected_shape_up() {
	if (!_selected_shape) return;

	size_t size = _shapes.size() - 1; // we can't move the last one up

	// find position in vector and remove it
	for ( size_t i = 0; i < size; i++) {
		if (_shapes[i] == _selected_shape) {
			std::vector<Shape *>::iterator iter = _shapes.begin();
			_shapes.erase(iter+i);
			_shapes.insert(iter+i+1, _selected_shape);
			return;
		}
	}
}

/**
 * Selects the shape that is at the point point
 * by checking if each Shape#is_at the point
 * @param point the point to select the shape at
 */
void Drawing::select_shape_at_point(point2d point) {
	_selected_shape = NULL;
	for ( size_t i = 0; i < _shapes.size(); i++ ) {
		if (_shapes[i]->is_at(point))
			_selected_shape = _shapes[i];
	}
}

/**
 * Clears the screen with the background colour,
 * then draws each of the Shape objects with their
 * #draw method. Also highlights the selected shape.
 */
void Drawing::draw() {
	clear_screen(_background_color);

	for ( size_t i = 0; i < _shapes.size(); i++ ) {
		if (_selected_shape && _shapes[i] == _selected_shape)
			_selected_shape->highlight();
		_shapes[i]->draw();
	}
}
