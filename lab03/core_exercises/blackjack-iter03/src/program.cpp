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

using namespace std;

bool prompt_hit() {
	char in;
	cout << "[H]it or [S]tand?" << endl;
	cin >> in;
	return (in == 'h' || in == 'H');
}

int main() {
	blackjack_game* game = new blackjack_game;

	/* Randomise the game - set random seed to time */
	srand(time(NULL));

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
			break;11
		}
	}

	/* Output hand descriptions */
	cout << game->dealer()->str() << endl;
	cout << game->current_player()->str() << endl;

	/* Win/lose message */
	cout << "You " << ((game->player_won()) ? "won" : "lost") << "!" << endl;

	delete game;

	return 0;
}


