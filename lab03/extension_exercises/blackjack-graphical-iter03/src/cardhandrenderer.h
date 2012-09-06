/*
 * cardhandrenderer.h
 *
 *  Created on: 05/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef CARDHANDRENDERER_H_
#define CARDHANDRENDERER_H_

#include "blackjackhand.h"
#include "card.h"
#include "cardrenderer.h"
#include "guiobject.h"

class card_hand_renderer: public gui_object {
	blackjack_hand* _hand;
	card_renderer* 	_renderers[5];
public:
	card_hand_renderer(blackjack_hand* hand);
	virtual ~card_hand_renderer();

	card* card_at(point2d point);

	virtual void render();
	virtual void render(point2d position);

	blackjack_hand* get_card_hand();
	void set_card_hand(blackjack_hand* hand);
};

#endif /* CARDHANDRENDERER_H_ */
