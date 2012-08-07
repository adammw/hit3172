/*
 * GraphicalCard.cpp
 *
 *  Created on: 07/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "GraphicalCard.h"

GraphicalCard::GraphicalCard(bitmap spritesheet, Card::rank r, Card::suit s) : Card(r,s) {
	_spritesheet = spritesheet;
	_position.x = 20;
	_position.y = 20;
}

point2d GraphicalCard::get_position() {
	return _position;
}

void GraphicalCard::set_position(point2d pos) {
	_position = pos;
}

bool GraphicalCard::is_at(point2d pos) {
	return (pos.x >= _position.x &&
			pos.x < _position.x + CARD_WIDTH &&
			pos.y >= _position.y &&
			pos.y < _position.y + CARD_HEIGHT);
}

void GraphicalCard::draw() {
	int x = 2, y = 4;
	if (is_faceup()) {
		x = get_rank() - 1;
		y = get_suit();
	}
	draw_bitmap_part(_spritesheet, x*CARD_WIDTH, y*CARD_HEIGHT, CARD_WIDTH, CARD_HEIGHT, _position.x, _position.y);
}
