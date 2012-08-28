/*
 * cardhand.h
 *
 *  Created on: 28/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef CARDHAND_H_
#define CARDHAND_H_

#include <string>
#include <vector>
#include "card.h"

class card_hand {
protected:
	std::vector<card*> _cards;
	int _score;

	virtual bool needs_evaluate();
	virtual void evaluate();

public:
	card_hand();
	virtual ~card_hand();

	void add_card(card* card);
	void remove_card(int idx);
	card* card_at(int idx);

	virtual std::string str();

	void return_cards();
	void reveal();
	void conceal();

	int get_score();
	int get_count();
	bool is_all_faceup();
};

#endif /* CARDHAND_H_ */
