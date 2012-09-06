/*
 * cardrenderer.h
 *
 *  Created on: 05/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef CARDRENDERER_H_
#define CARDRENDERER_H_

#include "guiobject.h"
#include "card.h"

/**
 * TODO: Document this class
 */
class card_renderer: public gui_object {
private:
	card* _card;
    static bitmap _cards_bitmap;

public:
	card_renderer(card* card);
	virtual ~card_renderer();
	virtual void render();
	virtual void render(point2d position);

	card* get_card();
	void set_card(card* card);
	void set_height(float);
	void set_width(float);
};

#endif /* CARDRENDERER_H_ */
