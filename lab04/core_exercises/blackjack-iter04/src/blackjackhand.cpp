/*
 * blackjackhand.cpp
 *
 *  Created on: 21/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "blackjackhand.h"
#include <sstream>
#include <iostream>

using namespace std;

/**
 * Initialise the blackjack hand
 */
blackjack_hand::blackjack_hand() : card_hand() {

}

/**
 * Checks if the hand needs evaluating
 * @return boolean true/false
 */
bool blackjack_hand::needs_evaluate() {
	return (get_count() >= 2);
}

/**
 * Calculates the score of the hand
 */
void blackjack_hand::evaluate() {
	int ace = 0;
	_score = 0;

	/* Count number of aces */
	vector<card *>::iterator it;
	for ( it = _cards.begin(); it < _cards.end(); it++) {
		card* card = *it;
		card::rank rank = card->get_rank();

		/* Increment the ace count if the card is an ace */
		if (rank == card::ACE)
			ace++;

		/* Add the card's value to the score */
		if (rank == card::ACE || rank >= card::JACK) {
			_score += 10;
		} else {
			_score += rank;
		}
	}

	/* While the score is larger than 21, treat the aces as a 1 */
	while (_score > 21 && ace > 0) {
		_score -= 10;
		ace--;
	}

	/* If the hand is bust, set score to a -1 */
	if (_score > 21)
		_score = -1;

	/* If count is 2 and score is 21, set score to 22 */
	if (_score == 21 && _cards.size() == 2)
		_score = 22;
}

/**
 * Creates a string representation of the blackjack hand
 * @return a string representation of the blackjack hand
 */
string blackjack_hand::str() {
	if (is_blackjack())
		return "BLACKJACK!";

	return card_hand::str();
}

/**
 * Check if the hand is full (ie. cannot take any more cards)
 * @return if the hand is full
 */
bool blackjack_hand::is_full() {
	return (_cards.size() >= MAX_CARDS_IN_HAND || _score < 0);
}

/**
 * Check if the hand is bust
 * @return if the hand is bust
 */
bool blackjack_hand::is_busted() {
	return (_score == -1);
}

/**
 * Check if the hand has blackjack
 * @return if the hand has blackjack
 */
bool blackjack_hand::is_blackjack() {
	return (_score == 22);
}
