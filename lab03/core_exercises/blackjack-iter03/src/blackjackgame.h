/*
 * blackjackgame.h
 *
 *  Created on: 21/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef BLACKJACKGAME_H_
#define BLACKJACKGAME_H_

#include "blackjackhand.h"
#include "deck.h"

class blackjack_game {
private:
	deck* _deck;
	blackjack_hand* _player_hand;
	blackjack_hand* _dealer_hand;

	void deal_card_to(blackjack_hand* hand, bool flip);
public:
	blackjack_game();
	~blackjack_game();

	void start();
	void hit();
	void stand();

	blackjack_hand* dealer();
	blackjack_hand* current_player();
	bool player_won();
};

#endif /* BLACKJACKGAME_H_ */
