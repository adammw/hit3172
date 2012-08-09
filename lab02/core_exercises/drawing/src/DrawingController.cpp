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
	/* "C" key changes colour */
	if (key_down(VK_C)) {
		if (key_down(VK_LSHIFT) || key_down(VK_RSHIFT)) {
			change_bg_color();
		} else {
			change_color();
		}
	}

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

	if (width < size_theshold) width = size_theshold;
	if (height < size_theshold) height = size_theshold;

	s->set_width(width);
	s->set_height(height);
}
