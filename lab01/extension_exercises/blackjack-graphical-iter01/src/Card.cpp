/*
 * card.cpp
 *
 *  Created on: 30/07/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include <sstream>
#include <iostream>
#include "Card.h"

/**
 * Card constructor with parameters to initialise which card it represents
 * @param r rank
 * @param s suit
 */
Card::Card(rank r, suit s) {
	_rank = r;
	_suit = s;
	_faceup = false;
}

/**
 * Turn the card over
 */
void Card::turn_over() {
	_faceup = !_faceup;
}

/**
 * Get a string representation of the card
 * @return a string representation of the card
 */
std::string Card::str() {
	// Returns asterisks
	if (!_faceup)
		return "**";

	std::ostringstream result;
	// Print the number value of the rank for 2-9,
	// or use a letter representing the card
	if (_rank == ACE) {
		result << "A";
	} else if (_rank < JACK) {
		result << _rank;
	} else if (_rank == JACK) {
		result << "J";
	} else if (_rank == QUEEN) {
		result << "Q";
	} else if (_rank == KING) {
		result << "K";
	}

	// Append a letter representing the suit
	if (_suit == CLUB) {
		result << "C";
	} else if (_suit == DIAMOND) {
		result << "D";
	} else if (_suit == HEART) {
		result << "H";
	} else if (_suit == SPADE) {
		result << "S";
	}

	// Return a string represntation of the stringstream
	return result.str();
}

/**
 * Get the rank of the Card object
 * @return rank of the card
 */
Card::suit Card::get_suit() {
	return _suit;
}

/**
 * Get the rank of the Card object
 * @return rank of the card
 */
Card::rank Card::get_rank() {
	return _rank;
}

/**
 * Get if the card is face up or not
 * @return true if the Card is face up
 */
bool Card::is_faceup() {
	return _faceup;
}
