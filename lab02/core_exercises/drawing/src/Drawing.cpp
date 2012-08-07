/*
 * Drawing.cpp
 *
 *  Created on: 08/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Drawing.h"

Drawing::Drawing() {
	// TODO Auto-generated constructor stub

}

Drawing::~Drawing() {
	// TODO Auto-generated destructor stub
}

Shape* Drawing::get_seleted_shape() {
	return _selected_shape;
}

void Drawing::add_shape(Shape* shape) {
	_shapes.push_back(shape);
}

void Drawing::select_shape_at_point(point2d point) {
	_selected_shape = NULL;
	for ( int i = 0; i < _shapes.size(); i++ ) {
		if (_shapes[i]->is_at(point))
			_selected_shape = _shapes[i];
	}
}

void Drawing::draw() {
	for ( int i = 0; i < _shapes.size(); i++ ) {
		_shapes[i]->draw();
	}
}
