/*
 * blackjackhand.h
 *
 *  Created on: 21/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef BLACKJACKHAND_H_
#define BLACKJACKHAND_H_

#define MAX_CARDS_IN_HAND 5

#include <string>
#include "card.h"

class blackjack_hand {
private:
	card* _cards[MAX_CARDS_IN_HAND];
	int _score;
	int _count;

	bool needs_evaluate();
	void evaluate();

public:
	blackjack_hand();

	void add_card(card*);
	void return_cards();
	card* card_at(int);
	void reveal();
	std::string str();

	int get_score();
	int get_count();
	bool is_full();
	bool is_blackjack();
	bool is_busted();
};

#endif /* BLACKJACKHAND_H_ */
