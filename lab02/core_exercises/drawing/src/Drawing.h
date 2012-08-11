/*
 * Drawing.h
 *
 *  Created on: 08/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef DRAWING_H_
#define DRAWING_H_

#include <vector>
#include "Shape.h"

/**
 * The Drawing class holds references to all the shapes
 * and can draw them all to the screen in order, as well
 * as selecting, reordering and removing shapes on screen
 */
class Drawing {
private:
	/**
	 * Vector array of the shape references,
	 * creates a "has many" relationship
	 */
	std::vector<Shape *> _shapes;

	/**
	 * Pointer to the selected shape
	 */
	Shape * _selected_shape;

	/**
	 * The background colour of the drawing canvas
	 */
	color _background_color;

public:
	Drawing();
	~Drawing();

	Shape * get_selected_shape();
	color get_background_color();
	void  set_background_color(color);
	
	void add_shape(Shape*);
	void select_shape_at_point(point2d);
	void draw();
	void delete_selected_shape();
	void move_selected_shape_up();
	void move_selected_shape_down();
};

#endif /* DRAWING_H_ */
