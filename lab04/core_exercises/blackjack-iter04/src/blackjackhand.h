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
#include "cardhand.h"

class blackjack_hand : public card_hand{
private:
	virtual bool needs_evaluate();
	virtual void evaluate();

public:
	blackjack_hand();

	std::string str();

	bool is_full();
	bool is_blackjack();
	bool is_busted();
};

#endif /* BLACKJACKHAND_H_ */
