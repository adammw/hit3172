/*
 * discardhand.h
 *
 *  Created on: 28/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef DISCARDHAND_H_
#define DISCARDHAND_H_

#include "cardhand.h"

class discard_hand: public card_hand {
public:
	discard_hand();

	void give_cards(card_hand* hand, bool face_up, bool on_top);
};

#endif /* DISCARDHAND_H_ */
