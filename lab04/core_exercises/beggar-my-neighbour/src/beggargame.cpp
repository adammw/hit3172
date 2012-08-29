/*
 * beggargame.cpp
 *
 *  Created on: 28/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "beggargame.h"

/**
 * Initialise the beggar my neighbour game object
 */
beggar_game::beggar_game() {
	_deck = new deck;
	_player_hand = new beggar_hand;
	_dealer_hand = new beggar_hand;
	_discard_hand = new discard_hand;
	_penalty_cards = 0;
	_active_hand = _player_hand;
}


/**
 * Delete the hands and the deck when the game object is destroyed
 */
beggar_game::~beggar_game() {
	delete _discard_hand;
	delete _player_hand;
	delete _dealer_hand;
	delete _deck;
}

/**
 * Starts a new game, returns cards, shuffles the deck and
 * deals all cards to the player and dealer evenly
 */
void beggar_game::start() {
	_player_hand->return_cards();
	_dealer_hand->return_cards();
	_deck->shuffle();

	/* Deal all cards evenly */
	card* card;
	beggar_hand* hand = _dealer_hand;
	while ((card = _deck->draw())) {
		hand->add_card(card);

		/* Switch hands */
		if (hand == _dealer_hand)
			hand = _player_hand;
		else
			hand = _dealer_hand;
	}
}


/**
 * Deal a card from the active hand's pile onto the discard hand
 *
 * Recalculates the number of penalty cards remaining and who plays next
 */
card* beggar_game::deal_card() {
	/* Get a card out of the active hand and put it in the discard hand */
	card* card = _active_hand->draw();
	if (!card) return NULL; //throw
	card->turn_over();
	_discard_hand->add_card(card);

	switch(card->get_rank()) {
		/* Set the number of "penalty cards" if Ace or face card, play continues to the next player  */
		case card::ACE:
			_penalty_cards = 4;
			_active_hand = get_inactive_hand();
			break;
		case card::KING:
			_penalty_cards = 3;
			_active_hand = get_inactive_hand();
			break;
		case card::QUEEN:
			_penalty_cards = 2;
			_active_hand = get_inactive_hand();
			break;
		case card::JACK:
			_penalty_cards = 1;
			_active_hand = get_inactive_hand();
			break;

		/* Otherwise, if the player is taking a penalty, decrement the remaining penalty cards */
		default:
			if (_penalty_cards >= 0) {
				_penalty_cards--;
			} else {
				/* If it is just a regular card, play continues to the next player */
				_active_hand = get_inactive_hand();
			}
			break;
	}

	/* If the player runs out chances to put down a ace or face card,
	 * the other player becomes active and gets the discard pile
	 */
	if (_penalty_cards == 0) {
		_active_hand = get_inactive_hand();
		_discard_hand->give_cards(_active_hand, false, false);
		_penalty_cards = -1;
	}

	return card;
}

/**
 * Check if the player won
 * @return true if the game is over and the player won, false if not
 */
bool beggar_game::player_won() {
	if (!is_game_over()) return false;
	return (_dealer_hand->get_count() == 0);
}

/**
 * Check if the game is over
 * The game is over when either the player or dealer is out of cards in their hand
 * @return true if the game is over
 */
bool beggar_game::is_game_over() {
	return (_player_hand->get_count() == 0 || _dealer_hand->get_count() == 0);
}

/**
 * Get the dealer's hand
 * @return pointer to beggar_hand object
 */
beggar_hand* beggar_game::get_dealer_hand() {
	return _dealer_hand;
}

/**
 * Get the player's hand
 * @return pointer to beggar_hand object
 */
beggar_hand* beggar_game::get_player_hand() {
	return _player_hand;
}

/**
 * Get the active hand
 * @return pointer to beggar_hand object
 */
beggar_hand* beggar_game::get_active_hand() {
	return _active_hand;
}

/**
 * Get the discard hand
 * @return pointer to discard_hand object
 */
discard_hand* beggar_game::get_discard_hand() {
	return _discard_hand;
}

/**
 * Get the inactive (other) hand
 * @return pointer to beggar_hand object
 */
beggar_hand* beggar_game::get_inactive_hand() {
	if (_active_hand == _dealer_hand) {
		return _player_hand;
	} else if (_active_hand == _player_hand) {
		return _dealer_hand;
	} else {
		return NULL;
	}
}


/**
 * Get the number of penalty cards remaining before the
 * other player gets the cards in the discard pile
 * @return
 */
int beggar_game::get_penalty_cards_remaining() {
	return _penalty_cards;
}
