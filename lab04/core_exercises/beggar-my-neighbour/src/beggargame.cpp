/*
 * beggargame.cpp
 *
 *  Created on: 28/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "beggargame.h"

using namespace std;

/**
 * Initialise the beggar my neighbour game object
 */
beggar_game::beggar_game(unsigned num_players) {
	_deck = new deck;
	while(num_players--) {
		_player_hands.push_back(new beggar_hand);
	}
	_discard_hand = new discard_hand;
}


/**
 * Delete the hands and the deck when the game object is destroyed
 */
beggar_game::~beggar_game() {
	delete _discard_hand;
	for (vector<beggar_hand*>::iterator it = _player_hands.begin(); it != _player_hands.end(); ++it) {
		delete *it;
	}
	delete _deck;
}

/**
 * Starts a new game, returns cards, shuffles the deck and
 * deals all cards to the player and dealer evenly
 */
void beggar_game::start() {
	/* Return all cards to the deck */
	for (vector<beggar_hand*>::iterator it = _player_hands.begin(); it != _player_hands.end(); ++it) {
		beggar_hand* hand = *it;
		hand->return_cards();
	}

	/* Shuffle the deck */
	_deck->shuffle();

	/* Deal all cards evenly */
	card* card;
	for (unsigned i = 0; (card = _deck->draw()); i++) {
		beggar_hand* hand = _player_hands[i % _player_hands.size()];

		hand->add_card(card);
	}

	/* Reset state */
	_active_hand_idx = 0;
	_paying_penalty = false;
	_game_over = false;
	_penalty_cards = 0;
}


/**
 * Deal a card from the active hand's pile onto the discard hand
 *
 * Recalculates the number of penalty cards remaining and who plays next
 */
card* beggar_game::deal_card() {
	/* Get a card out of the active hand and put it in the discard hand */
	beggar_hand* active_hand = get_active_hand();
	card* card = active_hand->draw();
	if (!card) return NULL;
	card->turn_over();
	_discard_hand->add_card(card);

	unsigned penalty = 0;

	/* Check the card they discarded */
	switch(card->get_rank()) {
		/* Set the number of "penalty cards" if Ace or face card, play continues to the next player  */
		case card::ACE:   penalty++;
		case card::KING:  penalty++;
		case card::QUEEN: penalty++;
		case card::JACK:  penalty++;
			_penalty_cards = penalty;
			_paying_penalty = true;
			next_player();
			break;

		default:
			/* Pay one card of their penalty if required */
			if (_paying_penalty) {
				_penalty_cards--;
			}

			/*
			 * Play goes to the next player if they are not playing a penalty, or
			 * if they have run out of cards to pay their penalty
			 * (the next player inherits the debt if they are out of cards with a penalty remaining)
			 */
			if (!_paying_penalty || is_game_over_for_player(_active_hand_idx) || _penalty_cards == 0) {
				next_player();

				/*
				 * If the player runs out chances to put down a ace or face card,
				 * the other player gets the discard pile
				 */
				if (_paying_penalty && _penalty_cards == 0) {
					_discard_hand->give_cards(get_active_hand(), false, false);
					_paying_penalty = false;
				}
			}
			break;
	}

	return card;
}

/**
 * Check if the player won
 * @return true if the game is over and the player won, false if not
 */
bool beggar_game::player_won(unsigned idx) {
	if (!is_game_over()) return false;
	return (_player_hands[idx]->get_count());
}

/**
 * Check if the game is over
 * The game is over when there is only one player left
 * @return true if the game is over
 */
bool beggar_game::is_game_over() {
	return _game_over;
}

/**
 * Check if the game is over for the specified player
 * @param idx the player index
 * @return true if the player is out of the game
 */
bool beggar_game::is_game_over_for_player(unsigned idx) {
	return !(_player_hands[idx]->get_count());
}

/**
 * Get the hand specified by the player index
 * @param idx 0-based player index
 * @return pointer to beggar_hand object
 */
beggar_hand* beggar_game::get_hand(unsigned idx) {
	return _player_hands[idx];
}

/**
 * Get the active hand
 * @return pointer to beggar_hand object
 */
beggar_hand* beggar_game::get_active_hand() {
	return _player_hands[_active_hand_idx];
}

/**
 * Get the discard hand
 * @return pointer to discard_hand object
 */
discard_hand* beggar_game::get_discard_hand() {
	return _discard_hand;
}

/**
 * Get the number of players
 * @return the number of players
 */
unsigned beggar_game::get_player_count() {
	return _player_hands.size();
}

/**
 * Get the index of the active player
 * @return the index of the active player
 */
unsigned beggar_game::get_active_player_index() {
	return _active_hand_idx;
}

bool beggar_game::is_paying_penalty() {
	return _paying_penalty;
}

/**
 * Increment the active hand index to the next hand that has cards
 */
void beggar_game::next_player() {
	/* Loop through to the next player that still has cards remaining */
	unsigned start_idx = _active_hand_idx;
	do {
		if (++_active_hand_idx >= get_player_count()) _active_hand_idx = 0;
	} while (_player_hands[_active_hand_idx]->get_count() == 0 && _active_hand_idx != start_idx);

	/* Game is over when all cards are split between one player and the discard pile */
	_game_over = (_player_hands[_active_hand_idx]->get_count() + _discard_hand->get_count() == 52);
}


/**
 * Get the number of penalty cards remaining before the
 * other player gets the cards in the discard pile
 * @return
 */
int beggar_game::get_penalty_cards_remaining() {
	return _penalty_cards;
}
