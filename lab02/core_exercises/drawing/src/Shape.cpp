/*
 * Shape.cpp
 *
 *  Created on: 07/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Shape.h"

/**
 * Shape constructor initialises data members
 */
Shape::Shape() {
	// Initialise data members
	_position.x = _position.y = 0;
	_width = _height = 200;
	_color = color_green;

	// Calculate the highlight colour to initialise _highlight_color
	calculate_highlight_color();
}

// A virtual destructor is required so that the delete method will
// invoke the destructor of the most heavily derivied class
// See http://blogs.msdn.com/b/oldnewthing/archive/2004/05/07/127826.aspx
Shape::~Shape() { }

/**
 * Gets the Shape's fill colour
 * @return the Shape's fill colour
 */
color Shape::get_color() {
	return _color;
}

/**
 * Gets the Shape's highlight colour
 * @return the Shape's highlight colour
 */
color Shape::get_highlight_color() {
	return _highlight_color;
}

/**
 * Gets the position of the Shape object
 * @return the Shape's position
 */
point2d Shape::get_position() {
	return _position;
}

/**
 * Gets the width of the Shape object
 * @return the Shape's width
 */
int Shape::get_width() {
	return _width;
}

/**
 * Gets the height of the Shape object
 * @return the Shape's height
 */
int Shape::get_height() {
	return _height;
}

/**
 * Gets the x-value of the Shape's position
 * @return the x position of the Shape
 */
float Shape::get_x() {
	return _position.x;
}

/**
 * Gets the y-value of the Shape's position
 * @return the y position of the Shape
 */
float Shape::get_y() {
	return _position.y;
}

/**
 * Sets the fill colour of the shape and
 * recalculates the highlight colour
 * @param color the colour to set
 * @see Shape::calculate_highlight_color
 */
void Shape::set_color(color color) {
	_color = color;
	calculate_highlight_color();
}

/**
 * Sets the highlight colour of the shape
 *
 * Will be overridden after any #set_color call
 * @param highlight_color highlight colour set
 */
void Shape::set_highlight_color(color highlight_color) {
	_highlight_color = highlight_color;
}

/**
 * Sets the position of the shape
 * @param position 	position to set
 */
void Shape::set_position(point2d position) {
	_position = position;
}

/**
 * Sets the width of the shape
 * @param width 	width to set
 */
void Shape::set_width(int width) {
	_width = width;
}

/**
 * Sets the height of the shape
 * @param height	height to set
 */
void Shape::set_height(int height) {
	_height = height;
}

/**
 * Sets the x position of the shape
 * @param x x position of shape to set
 */
void Shape::set_x(float x) {
	_position.x = x;
}

/**
 * Sets the y position of the shape
 * @param y y position of shape to set
 */
void Shape::set_y(float y) {
	_position.y = y;
}

/**
 * Checks if the Shape object is at that position
 *
 * This method is approximate and does only rectangular region checking
 * @param position position to check for
 * @return true/false
 */
bool Shape::is_at(point2d position) {
	if (_width >= 0 && _height >= 0) {
		return (position.x >= _position.x &&
				position.x < _position.x + _width &&
				position.y >= _position.y &&
				position.y < _position.y + _height);
	} else if (_width < 0 && _height >= 0) {
		return (position.x >= _position.x + _width &&
				position.x < _position.x  &&
				position.y >= _position.y &&
				position.y < _position.y + _height);
	} else if (_width >= 0 && _height < 0) {
		return (position.x >= _position.x &&
				position.x < _position.x + _width &&
				position.y >= _position.y + _height &&
				position.y < _position.y );
	} else { // width < 0 && height < 0
		return (position.x >= _position.x + _width &&
				position.x < _position.x &&
				position.y >= _position.y + _height &&
				position.y < _position.y );
	}
}

/**
 * Highlight colour calculation method
 *
 * This method changes the highlight colour to be a darker version
 * of the Shape's fill colour
 */
void Shape::calculate_highlight_color() {
	float hue = hue_of(_color),
		  sat = saturation_of(_color),
		  bri = brightness_of(_color);

	bri -= 0.2;

	_highlight_color = hsbcolor(hue, sat, bri);
}
