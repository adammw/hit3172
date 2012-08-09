/*
 * DrawingController.cpp
 *
 *  Created on: 09/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "DrawingController.h"

DrawingController::DrawingController(Drawing* drawing) {
	_adding = DRAWING_ELEMENT_RECTANGLE;
	_controlling = drawing;
}


Drawing* DrawingController::get_controlling() {
	return _controlling;
}

void DrawingController::set_controlling(Drawing* drawing) {
	_controlling = drawing;
}

void DrawingController::draw() {
	_controlling->draw();

	const char * text;
	switch(_adding){
	case DRAWING_ELEMENT_RECTANGLE:
		text = "Drawing Rectangles";
		break;
	case DRAWING_ELEMENT_LINE:
		text = "Drawing Lines";
		break;
	case DRAWING_ELEMENT_ELLIPSE:
		text = "Drawing Ellipses";
		break;
	default:
		text = "Drawing Unknown Shape";
	}
	draw_text_lines_with_font_named(text, color_black, color_transparent, "mavenpro", ALIGN_LEFT, 10, screen_height() - 26, screen_width() - 20, 16);
}

void DrawingController::handle_input() {
	/* "S" key toggles between possible shapes */
	if (key_typed(VK_S)) {
		((int)_adding)++;
		if (_adding >= DRAWING_ELEMENT_MAX)
			((int)_adding) = 0;
	}
	/* "R" key sets to rectangle */
	if (key_typed(VK_R))
		_adding = DRAWING_ELEMENT_RECTANGLE;
	/* "L" key sets to line */
	if (key_typed(VK_L))
		_adding = DRAWING_ELEMENT_LINE;
	/* "E" key sets to ellipse */
	if (key_typed(VK_E))
		_adding = DRAWING_ELEMENT_ELLIPSE;
	/* "C" key changes colour */
	if (key_down(VK_C)) {
		if (key_down(VK_LSHIFT) || key_down(VK_RSHIFT)) {
			change_bg_color();
		} else {
			change_color();
		}
	}
	/* delete/backspace key removes shape */
	if (key_typed(VK_DELETE) || key_typed(VK_BACKSPACE)) {
		_controlling->delete_selected_shape();
	}
	/* page up/down controls layering */
	if (key_typed(VK_PAGEDOWN))
		_controlling->move_selected_shape_down();
	if (key_typed(VK_PAGEUP))
		_controlling->move_selected_shape_up();

	if (key_down(VK_LSHIFT) || key_down(VK_RSHIFT)) {
		/* Arrow keys + Shift resize shape */
		if (key_down(VK_LEFT)) {
			resize_shape(-1,0);
		}
		if (key_down(VK_RIGHT)) {
			resize_shape(1,0);
		}
		if (key_down(VK_UP)) {
			resize_shape(0,-1);
		}
		if (key_down(VK_DOWN)) {
			resize_shape(0,1);
		}
	} else {
		/* Arrow keys move selected shape */
		if (key_down(VK_LEFT)) {
			point2d p = {-1,0};
			move_shape(p);
		}
		if (key_down(VK_RIGHT)) {
			point2d p = {1,0};
			move_shape(p);
		}
		if (key_down(VK_UP)) {
			point2d p = {0,-1};
			move_shape(p);
		}
		if (key_down(VK_DOWN)) {
			point2d p = {0,1};
			move_shape(p);
		}
	}

	/* add new shape on left click */
	if (mouse_clicked(LEFT_BUTTON)) {
		add_new_shape(mouse_position());
	}
	/* select shape on right click */
	if (mouse_clicked(RIGHT_BUTTON)) {
		_controlling->select_shape_at_point(mouse_position());
	}
}

void DrawingController::add_new_shape(point2d point) {
	Shape* s;
	switch(_adding) {
	case DRAWING_ELEMENT_LINE:
		s = new Line;
		break;
	case DRAWING_ELEMENT_RECTANGLE:
		s = new Rectangle;
		break;
	case DRAWING_ELEMENT_ELLIPSE:
		s = new Ellipse;
		break;
	default:
		return;
	}

	point2d p;
	p.x = point.x - DEFAULT_WIDTH / 2.0;
	p.y = point.y - DEFAULT_HEIGHT / 2.0;

	s->set_position(p);
	s->set_width(DEFAULT_WIDTH);
	s->set_height(DEFAULT_HEIGHT);
	s->set_color(DEFAULT_COLOR);
	_controlling->add_shape(s);
}

color DrawingController::rotate_hue(color c) {
	float hue = hue_of(c),
		  sat = saturation_of(c),
		  bri = brightness_of(c);

	hue += 0.01;
	if (hue > 1) hue -=1;

	return hsbcolor(hue, sat, bri);
}

void DrawingController::change_color() {
	Shape *s = _controlling->get_selected_shape();

	if (s == NULL) return;

	s->set_color(rotate_hue(s->get_color()));
}

void DrawingController::change_bg_color() {
	color c = _controlling->get_background_color();

	_controlling->set_background_color(rotate_hue(c));
}

void DrawingController::move_shape(point2d relative_movement) {
	Shape *s = _controlling->get_selected_shape();

	if (s == NULL) return;

	point2d location = s->get_position();
	location.x += relative_movement.x;
	location.y += relative_movement.y;
	s->set_position(location);
}

void DrawingController::resize_shape(int rel_width, int rel_height) {
	const int size_theshold = 20;
	Shape *s = _controlling->get_selected_shape();

	if (s == NULL) return;

	int width = s->get_width(),
		height = s->get_height();

	width += rel_width;
	height += rel_height;

	// Only the Line supports a negative width and height
	// Limit all other shapes to the threshold size
	if (dynamic_cast<Line *>(s) == NULL) {
		if (width < size_theshold) width = size_theshold;
		if (height < size_theshold) height = size_theshold;
	}

	s->set_width(width);
	s->set_height(height);
}
