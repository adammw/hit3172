/*
 * renderer.h
 *
 *  Created on: 05/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef RENDERER_H_
#define RENDERER_H_

/**
 * Interface for renderers
 */
class renderer {
public:
	renderer();
	virtual ~renderer();

	virtual void render() = 0;
};

#endif /* RENDERER_H_ */
