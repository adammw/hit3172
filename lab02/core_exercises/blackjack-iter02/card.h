/*
 * card.h
 *
 *  Created on: 30/07/2012
 *      Author: Adam Malcontenti-Wilson
 */
#include <string>

#ifndef CARD_H_
#define CARD_H_

class card {
public:
	enum suit {
		CLUB,
		DIAMOND,
		HEART,
		SPADE,
		SUIT_MAX
	};

	enum rank {
		ACE = 1,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK,
		QUEEN,
		KING,
		RANK_MAX
	};

	card(rank r, suit s);
	void turn_over();
	std::string str();

	suit get_suit();
	rank get_rank();
	bool is_faceup();

private:
	suit _suit;
	rank _rank;
	bool _faceup;

};

#endif /* CARD_H_ */
