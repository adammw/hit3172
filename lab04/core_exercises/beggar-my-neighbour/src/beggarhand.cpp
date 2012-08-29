/*
 * beggarhand.cpp
 *
 *  Created on: 28/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "beggarhand.h"

beggar_hand::beggar_hand() : card_hand() {

}

/**
 * Checks if the hand needs evaluating
 * @return boolean true/false
 */
bool beggar_hand::needs_evaluate() {
	return (get_count() >= 0);
}

/**
 * Calculates the score of the hand
 */
void beggar_hand::evaluate() {
	_score = get_count();
}

/**
 * Draw a card from the top of the hand
 */
card* beggar_hand::draw() {
	int idx = get_count()-1;
	card* card = card_at(idx);
	remove_card(idx);
	return card;
}
