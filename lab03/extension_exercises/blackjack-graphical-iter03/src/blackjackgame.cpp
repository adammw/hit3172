/*
 * blackjackgame.cpp
 *
 *  Created on: 21/08/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "blackjackgame.h"

/**
 * Initialise the blackjack game object
 */
blackjack_game::blackjack_game() {
	_deck = new deck;
	_player_hand = new blackjack_hand;
	_dealer_hand = new blackjack_hand;

}

/**
 * Delete the hands and the deck when the game object is destroyed
 */
blackjack_game::~blackjack_game() {
	delete _player_hand;
	delete _dealer_hand;
	delete _deck;
}

/**
 * Deal a card to the hand
 * @param hand the hand to deal to
 * @param flip whether to deal it face up (true) or face down
 */
void blackjack_game::deal_card_to(blackjack_hand* hand, bool flip) {
	/* Check the hand exists and is not full */
	if (!hand || hand->is_full()) return;

	/* Draw a card from the deck */
	card* card = _deck->draw();

	/* Turn the card to the correct side */
	if ((flip && !card->is_faceup()) || (!flip && card->is_faceup()))
		card->turn_over();

	hand->add_card(card);
}

/**
 * Starts a new blackjack game, returns cards, shuffles the deck and
 * deals new cards to the player and dealer
 */
void blackjack_game::start() {
	_player_hand->return_cards();
	_dealer_hand->return_cards();
	_deck->shuffle();
	deal_card_to(_player_hand, true);
	deal_card_to(_dealer_hand, false);
	deal_card_to(_player_hand, true);
	deal_card_to(_dealer_hand, true);
}

/**
 * Gives the player a new card
 */
void blackjack_game::hit() {
	deal_card_to(_player_hand, true);
}

/**
 * Ends the players turn, the dealer then tries to match their score
 */
void blackjack_game::stand() {
	int score;
	/* Reveal dealers cards */
	_dealer_hand->reveal();

	/* Keep hitting until busted or matched */
	while (!(_dealer_hand->is_busted()) && score < 21 && score < _player_hand->get_count()) {
		deal_card_to(_dealer_hand, true);
		score = _dealer_hand->get_score();
	}
}

/**
 * Gets the dealers hand object
 * @return
 */
blackjack_hand* blackjack_game::dealer() {
	return _dealer_hand;
}
/**
 * Gets the players hand object
 * @return
 */
blackjack_hand* blackjack_game::current_player() {
	return _player_hand;
}

/**
 * Checks if the player won
 * @return
 */
bool blackjack_game::player_won() {
	return (_player_hand->get_score() > _dealer_hand->get_score());
}
