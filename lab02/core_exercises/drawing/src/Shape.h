/*
 * Shape.h
 *
 *  Created on: 07/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include "SwinGame.h"

#define HIGHLIGHT_BORDER_SIZE 5

class Shape {
protected:
	color 	_color;
	color 	_highlight_color;
	point2d _position;
	int 	_width;
	int 	_height;

	void calculate_highlight_color();

public:
	Shape();
	virtual ~Shape();

	color get_color();
	color get_highlight_color();
	point2d get_position();
	int get_width();
	int get_height();
	float get_x();
	float get_y();
	void set_color(color);
	void set_highlight_color(color);
	void set_position(point2d);
	void set_width(int);
	void set_height(int);
	void set_x(float);
	void set_y(float);

	bool is_at(point2d);
	virtual void draw() = 0;
	virtual void highlight() = 0;
};

#endif /* SHAPE_H_ */
