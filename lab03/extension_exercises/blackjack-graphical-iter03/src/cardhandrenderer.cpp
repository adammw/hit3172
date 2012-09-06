/*
 * cardhandrenderer.cpp
 *
 *  Created on: 05/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "cardhandrenderer.h"

card_hand_renderer::card_hand_renderer(blackjack_hand* hand) {
	_hand = hand;
	memset(_renderers, NULL, sizeof(_renderers));
}

card_hand_renderer::~card_hand_renderer() {
	// TODO Auto-generated destructor stub
}

card* card_hand_renderer::card_at(point2d point) {
	for (int i = 0; i < _hand->get_count(); i++) {
		if (_renderers[i]->is_at(point)) {
			return _hand->card_at(i);
		}
	}
	return NULL;
}

blackjack_hand* card_hand_renderer::get_card_hand() {
	return _hand;
}

void card_hand_renderer::set_card_hand(blackjack_hand* hand) {
	_hand = hand;
}

void card_hand_renderer::render(point2d position) {
	set_position(position);
	render();
}

void card_hand_renderer::render() {
	const int offset = 20;
	point2d position = _position;

	for (int i = 0; i < _hand->get_count(); i++) {
		card* card = _hand->card_at(i);

		if (_renderers[i] == NULL) {
			_renderers[i] = new card_renderer(card);
		} else if (_renderers[i]->get_card() != card) {
			_renderers[i]->set_card(card);
		}

		_renderers[i]->render(position);

		position.x += _renderers[i]->get_width() + offset;
	}
}
