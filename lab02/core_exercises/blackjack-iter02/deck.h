/*
 * deck.h
 *
 *  Created on: 14/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "card.h"

#ifndef DECK_H_
#define DECK_H_

#define DECK_SIZE 52

/**
 * Deck class represents a Deck of 52 Card objects, and is
 * responsible for knowing which card is on top, how many
 * cards are left, and drawing cards from the Deck.
 */
class deck {
private:
	/**
	 * Array of the card pointers, creates a "has many" relationship
	 * with Card. The Deck is composed of many Cards.
	 */
	card* _cards[DECK_SIZE];

	/**
	 * Field to remember which index to draw from,
	 * is incremented each draw call
	 */
	int _top_card;
public:
	deck();
	~deck();

	void shuffle();
	card* draw();

	int get_cards_remaining();
};

#endif /* DECK_H_ */
