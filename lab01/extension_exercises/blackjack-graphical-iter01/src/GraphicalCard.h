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

/**
 * The GraphicalCard class inherits the Card class because it has the same functionality as
 * a Card, but it can also get and set it's position, and draw itself to the screen.
 */
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
