/*
 * beggarhand.h
 *
 *  Created on: 28/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef BEGGARHAND_H_
#define BEGGARHAND_H_

#include "cardhand.h"
#include "card.h"

class beggar_hand: public card_hand {
private:
	virtual bool needs_evaluate();
	virtual void evaluate();
public:
	beggar_hand();

	card* draw();
};

#endif /* BEGGARHAND_H_ */
