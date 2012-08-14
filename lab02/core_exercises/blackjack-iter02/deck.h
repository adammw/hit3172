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


class deck {
private:
	card* _cards[DECK_SIZE];
	int _top_card;
public:
	deck();
	~deck();

	void shuffle();
	card* draw();

	int get_cards_remaining();
};

#endif /* DECK_H_ */
