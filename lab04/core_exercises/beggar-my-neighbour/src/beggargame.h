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
#include <vector>

class beggar_game {
private:
	/**
	 * The deck of cards to use for the game
	 */
	deck* _deck;

	/**
	 * The vector array of each player's hand (face down pile)
	 */
	std::vector<beggar_hand*> _player_hands;

	/**
	 * Index of the active hand in the vector array
	 */
	unsigned _active_hand_idx;

	/**
	 * The discard hand (face up pile)
	 */
	discard_hand* _discard_hand;

	/**
	 * Penalty cards remaining until non-active hand
	 * gets all the cards in the discard hand
	 */
	int _penalty_cards;

	bool _paying_penalty;
	bool _game_over;

	void next_player();
public:
	beggar_game(unsigned num_players);
	virtual ~beggar_game();

	void start();
	card* deal_card();
	bool player_won(unsigned idx);

	bool is_game_over();
	bool is_game_over_for_player(unsigned idx);
	bool is_paying_penalty();
	unsigned get_player_count();
	unsigned get_active_player_index();
	int get_penalty_cards_remaining();
	beggar_hand* get_hand(unsigned idx);
	beggar_hand* get_active_hand();
	discard_hand* get_discard_hand();
};

#endif /* BEGGARGAME_H_ */
