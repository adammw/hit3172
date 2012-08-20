/*
 * deck.cpp
 *
 *  Created on: 14/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "deck.h"

/**
 * Initialise the cards array
 */
deck::deck() {
	_top_card = 0;

	for (int suit_idx = 0; suit_idx < card::SUIT_MAX; suit_idx++) {
		for (int rank_idx = card::ACE; rank_idx < card::RANK_MAX; rank_idx++) {
			card::suit suit = static_cast<card::suit>(suit_idx);
			card::rank rank = static_cast<card::rank>(rank_idx);
			_cards[_top_card++] = new card(rank, suit);
		}
	}

	_top_card = 0;
}

/**
 * When destroyed, the Deck destructor deletes all card objects it contains
 */
deck::~deck() {
	for (int i = 0; i < DECK_SIZE; i++) {
		delete _cards[i];
	}
}

/**
 * Shuffles the deck by looping through the cards array
 * and swapping it with another random card lower in the array
 * Goes back to the top of the cards array after completion
 */
void deck::shuffle() {
	for (int i = 0; i < DECK_SIZE - 1; i++) {
		int rnd_idx = (int)random() % (DECK_SIZE - i);
		card* temp = _cards[i];
		_cards[i] = _cards[rnd_idx];
		_cards[rnd_idx] = temp;
	}

	_top_card = 0;
}

/**
 * Get the next card off the deck, or NULL if no more cards
 * @return pointer to card object
 */
card* deck::draw() {
	if (_top_card >= DECK_SIZE) return NULL;
	return _cards[_top_card++];
}

/**
 * Get the number of cards remaining
 * @return the number of cards remaining
 */
int deck::get_cards_remaining() {
	return DECK_SIZE - _top_card;
}


