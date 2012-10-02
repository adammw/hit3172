/*
 * program.cpp
 *
 *  Created on: 30/07/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include <sstream>
#include <iostream>
#include <iomanip>
#include <limits>
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
	cout << ((top) ? top->str() : "  ") << " (" << setw(2) << right << hand->get_count() << ")" << "        ";
}

void print_beggar_table(beggar_game* game) {
	unsigned count = game->get_player_count();
	cout << endl << "Discard Pile   ";
	for (unsigned i = 0; i < count; i++) {
		cout << ((game->get_active_hand() == game->get_hand(i)) ? "<" : "");
		cout << "Player #" << setw(3) << i;
		cout << ((game->get_active_hand() == game->get_hand(i)) ? ">  " : "    ");
	}
	cout << endl;
	print_hand(game->get_discard_hand());
	for (unsigned i = 0; i < count; i++) {
		print_hand(game->get_hand(i));
	}
	cout << endl << endl;
}

void play_beggar() {
//TODO: need to redo class diagram with methods and everything properely
	unsigned num_players;
	do {
		cout << "How many players? ";
		cin >> num_players;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while(num_players < 2 || num_players > 50);

	beggar_game* game = new beggar_game(num_players);

	/* Start the Game */
	game->start();

	do {
		/* Output card descriptions */
		print_beggar_table(game);

		/* Deal the card */
		unsigned orig_player = game->get_active_player_index();
		cout << "Player #" << orig_player << " puts down a ";
		card* card = game->deal_card();

		/* Make sure it's face up and print it (then put it back if needed) */
		bool face_down = !card->is_faceup();
		if (face_down)
			card->turn_over();
		cout << card->str();
		if (face_down)
			card->turn_over();

		/* Check if the player lost */
		if (game->is_game_over_for_player(orig_player)) {
			cout << ", and is now out of cards";
		}

		/* Print the penalty cards remaining */
		if (!game->is_game_over()) {
			if (game->is_paying_penalty()) {
				cout << " (Player #" << game->get_active_player_index() << " has " << game->get_penalty_cards_remaining() << " penalty cards remaining)";
			} else if (game->get_discard_hand()->get_count() == 0) {
				cout << " (Player #" << game->get_active_player_index() << " gets discard pile)";
			}
		}
		cout << endl << endl;
	} while(!game->is_game_over());

	/* Final description*/
	print_beggar_table(game);

	/* Win/lose message */
	cout << "Player #" << game->get_active_player_index() << " wins!" << endl;

	delete game;
}

int main() {
	unsigned game;
	do {
		cout << "Which game?" << endl;
		cout << "1. Blackjack" << endl;
		cout << "2. Beggar-My-Neighbour" << endl;
		cout << ">> ";
		cin >> game;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while(game != 1 && game != 2);

	/* Randomise the game - set random seed to time */
	srand(time(NULL));

	switch(game) {
	case 1:
		play_blackjack();
		break;
	case 2:
		play_beggar();
		break;
	}
	return 0;
}


