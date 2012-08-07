/*
 * GraphicalCard.h
 *
 *  Created on: 07/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef GRAPHICALCARD_H_
#define GRAPHICALCARD_H_

#include "SwinGame.h"
#include "Card.h"

#define CARD_WIDTH 202.5
#define CARD_HEIGHT 315

class GraphicalCard: public Card {
private:
	point2d _position;
	bitmap _spritesheet;

public:
	GraphicalCard(bitmap spritesheet, Card::rank r, Card::suit s);

	point2d get_position();
	void set_position(point2d pos);

	void draw();
	bool is_at(point2d pos);
};

#endif /* GRAPHICALCARD_H_ */
