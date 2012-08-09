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


class Drawing {
private:
	std::vector<Shape *> _shapes;
	Shape * _selected_shape;
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
};

#endif /* DRAWING_H_ */
