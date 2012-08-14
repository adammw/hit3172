/*
 * program.cpp
 *
 *  Created on: 30/07/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include <sstream>
#include <iostream>
#include "card.h"

using namespace std;

/**
 * Prompt the user for the rank
 * @return rank enum
 */
card::rank prompt_rank() {
	std::string ranks[] = {"1","2","3","4","5","6","7","8","9","10","J","Q","K"};
	std::string input;
	cout << "Select a rank: ";
	cin >> input;
	for (int i = 0; i < 12; i++) {
		if (ranks[i].compare(input) == 0)
			return (card::rank)(i+1);
	}
	return prompt_rank();
}

/**
 * Prompt the user for the suit
 * @return suit enum
 */
card::suit prompt_suit() {
	std::string suits[] = {"C","D","H","S"};
	std::string input;
	cout << "Select a suit [C/D/H/S]: ";
	cin >> input;
	for (int i = 0; i < 4; i++) {
		if (suits[i].compare(input) == 0)
			return (card::suit)i;
	}
	return prompt_suit();
}

/**
 * Prompt the user for which action to take
 * @return 0 = Quit, 1 = Turn card over, 2 = Show card
 */
int prompt_action() {
	// This function uses a lookup array, compares the input and returns the matching index
	std::string actions[] = {"Q","T","S"};
	std::string input;
	cout << "Select an action:" << endl << "  [T]urn Card Over  [S]how Card  [Q]uit" << endl;
	cin >> input;
	for (int i = 0; i < 3; i++) {
		if (actions[i].compare(input) == 0)
			return i;
	}
	return prompt_action();
}

int main() {
	// Prompt the user for a rank and suit
	card::rank rank = prompt_rank();
	card::suit suit = prompt_suit();

	// Create a new card object with the specified rank and suit
	card * selectedCard = new card(rank, suit);
	int action;

	// Loop continues until user enters "Q"
	while ((action = prompt_action())) {
		switch(action) {
		case 1: // "T" - Turn over the card, then print out if it is face up or not
			selectedCard->turn_over();
			cout << "Card has been turned over, is now face " << ((selectedCard->is_faceup()) ? "up" : "down") << endl;
			break;
		case 2: // "S" - Print out the string representation of the card
			cout << "Your card is: " << selectedCard->str() << endl;
			break;
		}
	}
	return 0;
}


