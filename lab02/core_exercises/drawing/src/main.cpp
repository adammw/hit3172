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

int main() {
	open_audio();
	open_graphics_window("Blackjack", 800, 600);
	load_default_colors();

	Drawing* my_drawing = new Drawing;

	Shape* my_shape = new Shape;
	point2d pos = {10.0,10.0};
	my_shape->set_color(ColorRed);
	my_shape->set_position(pos);
	my_shape->set_width(20);
	my_shape->set_height(10);

	cout << "Shape " << (my_shape->is_at(pos) ? "is" : "is NOT") << " at " << pos.x << "," << pos.y << endl;

	pos.x = pos.y = 15;

	cout << "Shape " << (my_shape->is_at(pos) ? "is" : "is NOT") << " at " << pos.x << "," << pos.y << endl;

	pos.x = 30;
	pos.y = 20;

	cout << "Shape " << (my_shape->is_at(pos) ? "is" : "is NOT") << " at " << pos.x << "," << pos.y << endl;

	my_drawing->add_shape(my_shape);

	do
	{
		process_events();

		clear_screen(ColorWhite);

		my_drawing->draw();

		draw_framerate(0,0);

		refresh_screen();
	} while ( ! window_close_requested() );

	delete my_shape;

	close_audio();

	release_all_resources();

	return 0;
}
