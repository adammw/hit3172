/*
 * gameengine.cpp
 *
 *  Created on: 21/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "gameengine.h"
#include "guiblackjackgame.h"

game_engine::game_engine() {
	/* Initialise private fields */
	_game = new gui_blackjack_game;

	/* Initialise SwinGame Graphics */
    ::open_audio();
    ::open_graphics_window("Blackjack", 800, 600);
    ::load_default_colors();
}

game_engine::~game_engine() {
	/* Release game */
	delete _game;

	/* Release SwinGame Objects */
    ::close_audio();
    ::release_all_resources();
}

void game_engine::process_events() {
	::process_events();
}

void game_engine::update() {
	_game->update();
}

void game_engine::render() {
	/* clear the screen each frame */
	::clear_screen(color_white);

	/* ask the renderer to render the frame */
	_game->render();

	/* draw the framerate counter */
	::draw_framerate(0,0);

	/* limit to 60 FPS */
	::refresh_screen(60);
}

bool game_engine::running() {
	return !::window_close_requested();
}
