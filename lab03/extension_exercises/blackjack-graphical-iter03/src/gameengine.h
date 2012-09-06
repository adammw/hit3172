/*
 * gameengine.h
 *
 *  Created on: 21/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "SwinGame.h"
#include "guigame.h"
#include "controller.h"

#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_

/**
 * The Game Engine class processes the user input, updates the model state and
 * renders the game on-screen. The main game loop delegates to this class.
 */
class game_engine {
private:
	gui_game* _game;

public:
	game_engine();
	~game_engine();

	void process_events();
	void update();
	void render();
	bool running();

private:
};

#endif /* GAMEENGINE_H_ */
