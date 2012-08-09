/*
 * DrawingController.h
 *
 *  Created on: 09/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef DRAWINGCONTROLLER_H_
#define DRAWINGCONTROLLER_H_

#include "Drawing.h"

#define DEFAULT_COLOR ColorGreen
#define DEFAULT_WIDTH 200
#define DEFAULT_HEIGHT 200

typedef enum drawing_element {
	DRAWING_ELEMENT_LINE,
	DRAWING_ELEMENT_RECTANGLE,
	DRAWING_ELEMENT_MAX
} drawing_element;

class DrawingController {
private:
	Drawing* _controlling;
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
