/*
 * main.cpp
 *
 *  Created on: 08/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include <iostream>
#include "Shape.h"
#include "Drawing.h"

using namespace std;

/* TODO - Exercises
 * 1. In your own words explain why all the fields in the ShapeDrawer program are private.
 * 2. Point2D is a structure (value type) in C#. Review the material on the stack and heap and
 * their relationship with value and reference types then answer the following question.
 * In C#, why cant you use s.Position.X += dx to move the Shape? Explain what would occur at run
 * time if the compiler allows this. Would this work correctly in Objective C or Java?
 * What is the difference?
 * 3. Add accessor methods or properties for X and Y in the Shape class. This will read and write the component values from the Shape's Position, and provide convenient access for modifying these values. (Make sure that the position field is initialised to a new object when the Shape is constructed.)
 */

int main() {
	open_audio();
	open_graphics_window("Blackjack", 800, 600);
	load_default_colors();

	Drawing *d = new Drawing();

	// Create a shape
	Shape *s = new Rectangle();
	s->set_color(ColorRed);
	s->set_position(random_screen_point());
	s->set_width(200);
	s->set_height(200);

	// Add to drawing
	d->add_shape(s);

	// Create a shape
	s = new Line();
	s->set_color(ColorGreen);
	s->set_position(random_screen_point());
	s->set_width(100);
	s->set_height(250);

	// Add to drawing
	d->add_shape(s);

	// Create a shape
	s = new Rectangle();
	s->set_color(ColorBlue);
	s->set_position(random_screen_point());
	s->set_width(250);
	s->set_height(100);

	// Add to drawing
	d->add_shape(s);

	// Forget s... its owned by d now
	s = NULL;

	do
	{
		process_events();

		clear_screen(ColorWhite);

		d->draw();

		draw_framerate(0,0);

		refresh_screen();
	} while ( ! window_close_requested() );

	delete d;

	close_audio();

	release_all_resources();

	return 0;
}
