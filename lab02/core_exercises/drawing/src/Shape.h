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

/**
 * The Shape class is a generic class that all specific shapes in the
 * Drawing program inherit their basic attributes from, so that colour,
 * width, height and position is all handled by the Shape class once
 * and any subclasses only need to implement the abstract draw and
 * highlight methods.
 * Data fields are marked as `protected` so that they can be directly
 * accessed by any subclasses
 */
class Shape {
protected:
	/**
	 * Fill colour of the shape
	 *
	 * This is needed so each object can have a independent colour
	 * that can be changed an cycled to the next colour.
	 */
	color 	_color;

	/**
	 * Colour of the shape's highlight
	 *
	 * This is needed so the highlight colour matches the shapes colour
	 * and is only recalculated when the colour is changed
	 */
	color 	_highlight_color;

	/** Position of the shape */
	point2d _position;

	/** Width of shape */
	int 	_width;

	/** Height of shape */
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
