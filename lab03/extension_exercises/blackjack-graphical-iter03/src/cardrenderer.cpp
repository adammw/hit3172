/*
 * cardrenderer.cpp
 *
 *  Created on: 05/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "cardrenderer.h"
#include "SwinGame.h"

#define CARD_WIDTH 101.25
#define CARD_HEIGHT 157.5

bitmap card_renderer::_cards_bitmap = NULL;


card_renderer::card_renderer(card* card) : gui_object() {
	_card = card;

	_width = CARD_WIDTH;
	_height = CARD_HEIGHT;
}

card_renderer::~card_renderer() {
	// TODO Auto-generated destructor stub
}

void card_renderer::render(point2d position) {
	set_position(position);
	render();
}

void card_renderer::render() {
	int x = 2, y = 4; // card back position

	// Load bitmap on first render call
	if (_cards_bitmap == NULL) {
		_cards_bitmap = load_bitmap("cards.png");
	}

	// Only change to the correct card if pointer is non-null and card is face up
	if (_card && _card->is_faceup() && _card->get_rank() < card::RANK_MAX && _card->get_suit() < card::SUIT_MAX) {
		x = _card->get_rank() - 1; // -1 is for conversion from enum (starts from 1) to index (starts from 0)
		y = _card->get_suit();
	}

	// Draw the portion of the bitmap sheet with the card on it
	::draw_bitmap_part(_cards_bitmap, x*CARD_WIDTH, y*CARD_HEIGHT, CARD_WIDTH, CARD_HEIGHT, _position.x, _position.y);
}

card* card_renderer::get_card() {
	return _card;
}

void card_renderer::set_card(card* card) {
	_card = card;
}

void card_renderer::set_height(float height) {
	//override - do nothing
}

void card_renderer::set_width(float width) {
	//override - do nothing
}
