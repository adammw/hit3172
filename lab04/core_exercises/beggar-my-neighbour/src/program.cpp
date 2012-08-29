/*
 * program.cpp
 *
 *  Created on: 30/07/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include <sstream>
#include <iostream>
#include <cstdlib>
#include "blackjackgame.h"
#include "beggargame.h"

using namespace std;

bool prompt_hit() {
	char in;
	cout << "[H]it or [S]tand?" << endl;
	cin >> in;
	return (in == 'h' || in == 'H');
}

void play_blackjack() {
	blackjack_game* game = new blackjack_game;

	/* Start the Game */
	game->start();

	for(;;) {
		/* Output hand descriptions */
		cout << game->dealer()->str() << endl;
		cout << game->current_player()->str() << endl;

		/* Hit or stand */
		if (prompt_hit()) {
			game->hit();

			/* Check for bust */
			if (game->current_player()->is_busted()) {
				cout << "You busted!" << endl;
				break;
			}
		} else {
			game->stand();
			break;
		}
	}

	/* Output hand descriptions */
	cout << game->dealer()->str() << ((game->dealer()->is_busted()) ? "(busted)" : "") << endl;
	cout << game->current_player()->str() << endl;

	/* Win/lose message */
	cout << "You " << ((game->player_won()) ? "won" : "lost") << "!" << endl;

	delete game;
}

card* top_card(card_hand* hand) {
	int idx = hand->get_count();
	return (idx) ? hand->card_at(idx-1) : NULL;
}

void print_hand(card_hand* hand) {
	card* top = top_card(hand);
	cout << ((top) ? top->str() : "  ") << " (" << hand->get_count() << ")" << " \t";
}

string hand_name(beggar_game* game, card_hand* hand) {
	return ((hand == game->get_player_hand()) ? "Player" : "Dealer");
}

void play_beggar() {
//TODO: need to redo class diagram with methods and everything properely
	beggar_game* game = new beggar_game;

	/* Start the Game */
	game->start();

	do {
		/* Output card descriptions */
		cout << "Player \tDiscard \tDealer" << endl;
		print_hand(game->get_player_hand());
		print_hand(game->get_discard_hand());
		print_hand(game->get_dealer_hand());
		cout << endl << endl;

		/* Deal the card */
		cout << hand_name(game, game->get_active_hand()) << " puts down a ";
		card* card = game->deal_card();

		/* Make sure it's face up and print it (then put it back if needed) */
		bool face_down = !card->is_faceup();
		if (face_down)
			card->turn_over();
		cout << card->str();
		if (face_down)
			card->turn_over();

		/* Print the penalty cards remaining */
		int penalty = game->get_penalty_cards_remaining();
		if (penalty > 0) {
			cout << " (" << hand_name(game, game->get_active_hand()) << " has " << game->get_penalty_cards_remaining() << " penalty cards remaining)";
		} else if (penalty == -1 && game->get_discard_hand()->get_count() == 0) {
			cout << " (" << hand_name(game, game->get_active_hand()) << " gets discard pile)";
		}
		cout << endl;
	} while(!game->is_game_over());

	/* Win/lose message */
	cout << "You " << ((game->player_won()) ? "won" : "lost") << "!" << endl;

	delete game;
}

int main() {
	/* Randomise the game - set random seed to time */
	srand(time(NULL));

	play_beggar();
	return 0;
}


