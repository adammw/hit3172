/*
 * main.cpp
 *
 *  Created on: 08/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include <iostream>
#include "Shape.h"

using namespace std;

int main() {
	Shape* my_shape = new Shape;
	point2d pos = {10.0,10.0};
	my_shape->set_position(pos);
	my_shape->set_width(20);
	my_shape->set_height(10);

	cout << "Shape " << (my_shape->is_at(pos) ? "is" : "is NOT") << " at " << pos.x << "," << pos.y << endl;

	pos.x = pos.y = 15;

	cout << "Shape " << (my_shape->is_at(pos) ? "is" : "is NOT") << " at " << pos.x << "," << pos.y << endl;

	pos.x = 30;
	pos.y = 20;

	cout << "Shape " << (my_shape->is_at(pos) ? "is" : "is NOT") << " at " << pos.x << "," << pos.y << endl;

	delete my_shape;
	return 0;
}
