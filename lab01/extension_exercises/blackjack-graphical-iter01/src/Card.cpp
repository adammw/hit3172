/*
 * card.cpp
 *
 *  Created on: 30/07/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include <sstream>
#include <iostream>
#include "Card.h"

Card::Card(rank r, suit s) {
	_rank = r;
	_suit = s;
	_faceup = false;
}

void Card::turn_over() {
	_faceup = !_faceup;
}

std::string Card::str() {
	if (!_faceup)
		return "**";

	std::ostringstream result;
	if (_rank < JACK) {
		result << _rank;
	} else if (_rank == JACK) {
		result << "J";
	} else if (_rank == QUEEN) {
		result << "Q";
	} else if (_rank == KING) {
		result << "K";
	}

	if (_suit == CLUB) {
		result << "C";
	} else if (_suit == DIAMOND) {
		result << "D";
	} else if (_suit == HEART) {
		result << "H";
	} else if (_suit == SPADE) {
		result << "S";
	}

	return result.str();
}

Card::suit Card::get_suit() {
	return _suit;
}

Card::rank Card::get_rank() {
	return _rank;
}

bool Card::is_faceup() {
	return _faceup;
}
