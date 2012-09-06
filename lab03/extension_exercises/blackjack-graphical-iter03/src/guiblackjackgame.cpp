/*
 * guiblackjackgame.cpp
 *
 *  Created on: 05/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include <cstdlib>
#include <sstream>
#include "guiblackjackgame.h"

using namespace std;

/**
 * Start the blackjack game when constructed, and initialise the location and position
 * of the dealer hand, player hand and deck renderers, as well as initialising private
 * game state fields
 */
gui_blackjack_game::gui_blackjack_game() : blackjack_game() {
	srand(time(NULL));

	start();
	_game_over = false;
	_show_dealer_score = false;
	_message = "";
	_dealer_hand_renderer = new card_hand_renderer(dealer());
	_player_hand_renderer = new card_hand_renderer(current_player());
	_deck_placeholder_renderer = new card_renderer(NULL);
	point2d p1 = {680, 220};
	_deck_placeholder_renderer->set_position(p1);
	point2d p2 = {20, 420};
	_player_hand_renderer->set_position(p2);
	point2d p3 = {20, 20};
	_dealer_hand_renderer->set_position(p3);
}

/**
 * Clean up on destruction
 */
gui_blackjack_game::~gui_blackjack_game() {
	delete _dealer_hand_renderer;
	delete _player_hand_renderer;
	delete _deck_placeholder_renderer;
}

/**
 * Returns a string representation of the hand score
 * @param hand
 * @return
 */
string gui_blackjack_game::hand_score(blackjack_hand* hand) {
	ostringstream result;
	if (hand->is_blackjack())
		result << "21";
	else if (hand->is_busted())
		result << "BUST";
	else
		result << hand->get_score();

	return result.str();
}

/**
 * Updates game state based on input
 */
void gui_blackjack_game::update() {
	point2d mouse = mouse_position();

	if (current_player()->is_busted()) {
		_game_over = true;
		_message = "You busted!";
	}

	if (!_game_over) {
		if (mouse_clicked(LEFT_BUTTON) && _deck_placeholder_renderer->is_at(mouse) || key_typed(VK_H)) {
			hit();
		}
		if (key_typed(VK_S)) {
			stand();
			_game_over = true;
			_show_dealer_score = true;
			_message = (player_won() ? "You won!" : "You lose!");
		}
	} else {
		if (key_typed(VK_N)) {
			start();
			_game_over = false;
			_show_dealer_score = false;
			_message = "";
		}
	}
}

/**
 * Draw the background art
 */
void gui_blackjack_game::render_background() {
	static bitmap felt = ::load_bitmap("felt_01.jpg");
	static bitmap wood = ::load_bitmap("wood.jpg");
	::draw_bitmap(felt, 0, 0);
	::draw_bitmap(wood, 0, 400);
	::draw_bitmap(wood, 200, 400);
	::draw_bitmap(wood, 400, 400);
	::draw_bitmap(wood, 600, 400);
	::draw_bitmap(wood, 0, 0);
	::draw_bitmap(wood, 200, 0);
	::draw_bitmap(wood, 400, 0);
	::draw_bitmap(wood, 600, 0);
}

/**
 * Render a new frame
 *
 * Calls a separate hand or card renderer to render the hands and deck
 */
void gui_blackjack_game::render() {
	//TODO: Use SwinGame resource loading better
	static font font_big = ::load_font("maven_pro_regular.ttf", 32);
	static font font_small = ::load_font("maven_pro_regular.ttf", 16);
	render_background();

	// Draw instructions
	if (_game_over) {
		::draw_text("N = New Game", color_white, font_small, 680, 500);
	} else {
		::draw_text("H = Hit", color_white, font_small, 680, 500);
		::draw_text("S = Stand", color_white, font_small, 680, 520);
	}

	// Draw the game state message if any
	::draw_text(_message.c_str(), color_white, font_big, 100, 250);

	// Print the scores of each hand (the dealer only if needed)
	if (_game_over && _show_dealer_score)
		::draw_text(hand_score(dealer()).c_str(), color_white, font_big, 680, 20);
	::draw_text(hand_score(current_player()).c_str(), color_white, font_big, 680, 420);

	// Render each hands cards and a single card back for the deck
	_dealer_hand_renderer->render();
	_player_hand_renderer->render();
	_deck_placeholder_renderer->render();
}
