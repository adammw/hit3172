/*
 * beggargame.h
 *
 *  Created on: 28/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef BEGGARGAME_H_
#define BEGGARGAME_H_

#include "deck.h"
#include "beggarhand.h"
#include "discardhand.h"

class beggar_game {
private:
	/**
	 * The deck of cards to use for the game
	 */
	deck* _deck;

	/**
	 * The players hand (face down pile)
	 */
	beggar_hand* _player_hand;

	/**
	 * The dealers hand (face down pile)
	 */
	beggar_hand* _dealer_hand;

	/**
	 * Pointer to the active hand
	 * (either the player or dealer)
	 */
	beggar_hand* _active_hand;

	/**
	 * The discard hand (face up pile)
	 */
	discard_hand* _discard_hand;

	/**
	 * Penalty cards remaining until non-active hand
	 * gets all the cards in the discard hand
	 */
	int _penalty_cards;
public:
	beggar_game();
	virtual ~beggar_game();

	void start();
	card* deal_card();
	bool player_won();

	bool is_game_over();
	int get_penalty_cards_remaining();
	beggar_hand* get_active_hand();
	beggar_hand* get_inactive_hand();
	beggar_hand* get_dealer_hand();
	beggar_hand* get_player_hand();
	discard_hand* get_discard_hand();
};

#endif /* BEGGARGAME_H_ */
