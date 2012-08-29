/*
 * discardhand.cpp
 *
 *  Created on: 28/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "discardhand.h"
#include "card.h"

using namespace std;

discard_hand::discard_hand() : card_hand() {

}

/**
 * Give all the cards to another card_hand object
 * @param hand the 	card_hand object to give cards to
 * @param face_up	give the cards face up
 * @param on_top	add the cards to the top of the hand
 */
void discard_hand::give_cards(card_hand* hand, bool face_up, bool on_top) {
	for(int i = get_count() - 1; i >= 0; i--) {
		card* card = card_at(i);
		remove_card(i);
		if (!face_up && card->is_faceup()) {
			card->turn_over();
		} else if (face_up && !card->is_faceup()) {
			card->turn_over();
		}
		hand->add_card(card, on_top);
	}
}
