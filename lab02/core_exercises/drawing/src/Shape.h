/*
 * Shape.h
 *
 *  Created on: 07/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include "SwinGame.h"

class Shape {
private:
	color 	_color;
	point2d _position;
	int 	_width;
	int 	_height;
public:
	Shape();
	virtual ~Shape();

	color get_color();
	point2d get_position();
	int get_width();
	int get_height();
	float get_x();
	float get_y();
	void set_color(color);
	void set_position(point2d);
	void set_width(int);
	void set_height(int);
	void set_x(float);
	void set_y(float);

	bool is_at(point2d);
	void draw();
};

#endif /* SHAPE_H_ */
