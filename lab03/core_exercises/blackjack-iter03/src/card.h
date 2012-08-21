/*
 * card.h
 *
 *  Created on: 30/07/2012
 *      Author: Adam Malcontenti-Wilson
 */
#ifndef CARD_H_
#define CARD_H_

#include <string>

/**
 * Card class represents a card and what the card knows and it can do
 * For example it knows what rank and suit it is, and if it is face up
 * and can turn it self over
 */
class card {
public:
	/**
	 * Enum for all possible card suits
	 */
	enum suit {
		CLUB,    //!< CLUB
		DIAMOND, //!< DIAMOND
		HEART,   //!< HEART
		SPADE,   //!< SPADE
		SUIT_MAX //!< Symbolic Sentinel value for the last possible suit
		         //!  (not a valid suit)
	};

	/**
	 * Enum for all possible card ranks
	 *
	 * Rank starts at one instead of zero for ease-of-use, be care
	 */
	enum rank {
		ACE = 1, //!< ACE
		TWO,     //!< TWO
		THREE,   //!< THREE
		FOUR,    //!< FOUR
		FIVE,    //!< FIVE
		SIX,     //!< SIX
		SEVEN,   //!< SEVEN
		EIGHT,   //!< EIGHT
		NINE,    //!< NINE
		TEN,     //!< TEN
		JACK,    //!< JACK
		QUEEN,   //!< QUEEN
		KING,    //!< KING
		RANK_MAX //!< Symbolic Sentinel value for the last possible rank
		         //!  (not a valid rank)
	};

	card(rank r, suit s);
	void turn_over();
	std::string str();

	suit get_suit();
	rank get_rank();
	bool is_faceup();

private:
	/**
	 * Stores the suit of the Card object
	 */
	suit _suit;

	/**
	 * Stores the rank of the Card object
	 */
	rank _rank;

	/**
	 * Stores whether the Card object is face up (true) or face down (false)
	 */
	bool _faceup;

};

#endif /* CARD_H_ */
