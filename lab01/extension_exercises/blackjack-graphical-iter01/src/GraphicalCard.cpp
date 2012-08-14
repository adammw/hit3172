/*
 * GraphicalCard.cpp
 *
 *  Created on: 07/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "GraphicalCard.h"

/**
 * Constructor for GraphicalCard, initialises local variables and invokes Card constructor
 * @param spritesheet The bitmap conatining the Card image
 * @param r rank
 * @param s suit
 */
GraphicalCard::GraphicalCard(bitmap spritesheet, Card::rank r, Card::suit s) : Card(r,s) {
	_spritesheet = spritesheet;
	_position.x = 20;
	_position.y = 20;
}

/**
 * Get the position of the Card
 * @return the position
 */
point2d GraphicalCard::get_position() {
	return _position;
}

/**
 * Set the position of the Card
 * @param pos the position
 */
void GraphicalCard::set_position(point2d pos) {
	_position = pos;
}

/**
 * Checks if the card is at the point
 * @param pos the point the check
 * @return
 */
bool GraphicalCard::is_at(point2d pos) {
	return (pos.x >= _position.x &&
			pos.x < _position.x + CARD_WIDTH &&
			pos.y >= _position.y &&
			pos.y < _position.y + CARD_HEIGHT);
}

/**
 * Draws the card to the screen at it's location
 */
void GraphicalCard::draw() {
	int x = 2, y = 4;
	if (is_faceup()) {
		x = get_rank() - 1;
		y = get_suit();
	}
	draw_bitmap_part(_spritesheet, x*CARD_WIDTH, y*CARD_HEIGHT, CARD_WIDTH, CARD_HEIGHT, _position.x, _position.y);
}
