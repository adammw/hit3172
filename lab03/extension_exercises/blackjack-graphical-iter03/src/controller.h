/*
 * controller.h
 *
 *  Created on: 21/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/**
 * This is an abstract class which all controllers inherit from
 */
class controller {
public:
	virtual void update() = 0;
};


#endif /* CONTROLLER_H_ */
