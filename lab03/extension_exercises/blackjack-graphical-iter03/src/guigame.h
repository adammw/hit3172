/*
 * guigame.h
 *
 *  Created on: 05/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef GUIGAME_H_
#define GUIGAME_H_

/**
 * Abstract interface for a GUI-based game
 */
class gui_game {
public:
	virtual void update() = 0;
	virtual void render() = 0;
};

#endif /* GUIGAME_H_ */
