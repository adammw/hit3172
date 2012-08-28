/*
 * cardhand.cpp
 *
 *  Created on: 28/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "cardhand.h"
#include <sstream>
#include <iostream>

using namespace std;

/**
 *  Initialise the card hand
 */
card_hand::card_hand() {
	_score = 0;
}

card_hand::~card_hand() {
	// TODO Auto-generated destructor stub
}

/**
 * Stub for needs_evaluate function, should be overridden by a subclass
 * @return always returns false
 */
bool card_hand::needs_evaluate() {
	return false;
}

/**
 * Stub for evaluate function, should be overridden by a subclass
 * Sets score to zero
 */
void card_hand::evaluate() {
	_score = 0;
}

/**
 * Add a new card to the hand, and evaluates score if necessary
 * @param card the card object to add to the hand
 */
void card_hand::add_card(card* card) {
	_cards.push_back(card);

	if (needs_evaluate())
		evaluate();
}

/**
 * Remove a card from the hand
 * @param idx the index of the card in the hand
 */
void card_hand::remove_card(int idx) {
	_cards.erase(_cards.begin() + idx);
}

/**
 * Get a pointer to a card in the hand
 * @param idx the index of the card
 * @return the card pointer
 */
card* card_hand::card_at(int idx) {
	return _cards[idx];
}

/**
 * Print the string representation of each card, separated by a space
 * @return a string representation of the hand
 */
string card_hand::str() {
	ostringstream result;
	vector<card *>::iterator it;
	for ( it = _cards.begin(); it < _cards.end(); it++) {
		result << (*it)->str() << " ";
	}
	return result.str();
}

/**
 * Removes all cards from its cards field
 */
void card_hand::return_cards() {
	//TODO: check if this is enough
	_cards.clear();
}

/**
 * Turns all cards face up
 */
void card_hand::reveal() {
	vector<card *>::iterator it;
	for (it = _cards.begin(); it < _cards.end(); it++) {
		card* card = *it;
		if (!card->is_faceup())
			card->turn_over();
	}
}

/**
 * Turns all cards face down
 */
void card_hand::conceal() {
	vector<card *>::iterator it;
	for (it = _cards.begin(); it < _cards.end(); it++) {
		card* card = *it;
		if (card->is_faceup())
			card->turn_over();
	}
}

/**
 * Get the number of cards in the hand
 * @return number of cards in the hand
 */
int card_hand::get_count() {
	return _cards.size();
}

/**
 * Get the hand score
 * @return the hand score
 */
int card_hand::get_score() {
	return _score;
}
