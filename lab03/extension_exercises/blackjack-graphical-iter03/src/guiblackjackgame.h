/*
 * guiblackjackgame.h
 *
 *  Created on: 05/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef GUIBLACKJACKGAME_H_
#define GUIBLACKJACKGAME_H_

#include "blackjackgame.h"
#include "blackjackhand.h"
#include "guigame.h"
#include "SwinGame.h"
#include "cardhandrenderer.h"
#include <string>

class gui_blackjack_game: public blackjack_game, public gui_game {
private:
	card_hand_renderer* _dealer_hand_renderer;
	card_hand_renderer* _player_hand_renderer;
	card_renderer* _deck_placeholder_renderer;
	std::string _message;
	bool _game_over;
	bool _show_dealer_score;

	std::string hand_score(blackjack_hand* hand);
	static void render_background();
public:
	gui_blackjack_game();
	virtual ~gui_blackjack_game();
	virtual void update();
	virtual void render();
};

#endif /* GUIBLACKJACKGAME_H_ */
