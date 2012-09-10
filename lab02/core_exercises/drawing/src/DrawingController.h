/*
 * DrawingController.h
 *
 *  Created on: 09/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef DRAWINGCONTROLLER_H_
#define DRAWINGCONTROLLER_H_

#include "Drawing.h"
#include "Rectangle.h"
#include "Line.h"
#include "Ellipse.h"
#include "Triangle.h"

#define DEFAULT_COLOR ColorGreen
#define DEFAULT_WIDTH 200
#define DEFAULT_HEIGHT 200

/**
 * The enum declares which subclasses of Shape is available to draw
 */
typedef enum drawing_element {
	DRAWING_ELEMENT_LINE,     //!< Line
	DRAWING_ELEMENT_RECTANGLE,//!< Rectange
	DRAWING_ELEMENT_ELLIPSE,  //!< Ellipse
	DRAWING_ELEMENT_TRIANGLE, //!< Triangle
	DRAWING_ELEMENT_MAX       //!< The sentinel constant to mark the end of the enum
} drawing_element;

/**
 * The DrawingController contains most of the
 * logic controlling the application, it needs to
 * know what Drawing object it is controlling
 */
class DrawingController {
private:
	/** The Drawing object the controller is controlling */
	Drawing* _controlling;
	/** controls which shape subclass will be drawn to the screen */
	drawing_element _adding;

	void add_new_shape(point2d point);
	void move_shape(point2d point);
	void resize_shape(int rel_width, int rel_height);
	void change_color();
	void change_bg_color();
	color rotate_hue(color);
public:
	DrawingController(Drawing* = NULL);

	Drawing* get_controlling();
	void set_controlling(Drawing*);

	void draw();
	void handle_input();

};

#endif /* DRAWINGCONTROLLER_H_ */
