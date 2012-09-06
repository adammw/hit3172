/*
 * guiobject.h
 *
 *  Created on: 23/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "SwinGame.h"

#ifndef GUIOBJECT_H_
#define GUIOBJECT_H_

class gui_object {
protected:
	point2d _position;
	float _width;
	float _height;
public:
	gui_object();
	virtual ~gui_object();

	point2d get_position();
	void set_position(point2d position);
	bool is_at(point2d position);
	float get_width();
	float get_height();
	void set_width(float width);
	void set_height(float height);
};

#endif /* GUIOBJECT_H_ */
