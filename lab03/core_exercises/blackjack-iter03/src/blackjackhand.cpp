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
blackjack_hand::blackjack_hand() {
	_count = 0;
	_score = 0;
}

/**
 * Add a new card to the hand.
 * If the hand is full and cannot take any more cards this method silently fails
 * @param card the card object to add to the hand
 */
void blackjack_hand::add_card(card* card) {
	if (is_full()) return;
	_cards[_count++] = card;
	if (needs_evaluate())
		evaluate();
}

/**
 * Get a pointer to a card in the hand
 * @param idx the index of the card
 * @return the card pointer, or NULL if that index has no card
 */
card* blackjack_hand::card_at(int idx) {
	if (idx > _count) return NULL;
	return _cards[idx];
}

/**
 * Checks if the hand needs evaluating
 * @return boolean true/false
 */
bool blackjack_hand::needs_evaluate() {
	return (_count >= 2);
}

/**
 * Calculates the score of the hand
 */
void blackjack_hand::evaluate() {
	int ace = 0;
	_score = 0;

	/* Count number of aces */
	for (int i = 0; i < _count; i++) {
		card::rank rank =  _cards[i]->get_rank();

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
	if (_score == 21 && _count == 2)
		_score = 22;
}

/**
 * Creates a string representation of the blackjack hand
 * @return a string representation of the blackjack hand
 */
string blackjack_hand::str() {
	if (is_blackjack())
		return "BLACKJACK!";

	/* Print the string representation of each card, separated by a space */
	std::ostringstream result;
	for (int i = 0; i < _count; i++) {
		result << _cards[i]->str() << " ";
	}
	return result.str();
}

/**
 * Turns all cards face up
 */
void blackjack_hand::reveal() {
	for (int i = 0; i < _count; i++) {
		if (!_cards[i]->is_faceup())
			_cards[i]->turn_over();
	}
}

/**
 * Removes all cards from its cards field, sets count to 0
 */
void blackjack_hand::return_cards() {
	//TODO: check - deck should release cards, not this
	for (int i = 0; i < _count; i++)
		delete _cards[i];
	_count = 0;
}

/**
 * Get the number of cards in the hand
 * @return number of cards in the hand
 */
int blackjack_hand::get_count() {
	return _count;
}

/**
 * Get the hand score
 * @return the hand score
 */
int blackjack_hand::get_score() {
	return _score;
}

/**
 * Check if the hand is full (ie. cannot take any more cards)
 * @return if the hand is full
 */
bool blackjack_hand::is_full() {
	return (_count == MAX_CARDS_IN_HAND || _score < 0);
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
