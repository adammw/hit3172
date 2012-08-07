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

public:
	Drawing();
	virtual ~Drawing();

	Shape * get_seleted_shape();
	void add_shape(Shape*);
	void select_shape_at_point(point2d);
	void draw();
};

#endif /* DRAWING_H_ */
