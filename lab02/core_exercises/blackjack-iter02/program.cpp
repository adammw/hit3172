/*
 * program.cpp
 *
 *  Created on: 30/07/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include <sstream>
#include <iostream>
#include "deck.h"

using namespace std;

/**
 * Draw all 52 cards, and print both sides to the screen
 * @param current_deck
 */
void draw_all_cards(deck* current_deck) {
	for (int i = 0; i < DECK_SIZE; i++) {
		card* current_card = current_deck->draw();
		cout << current_card->str() << endl;
		current_card->turn_over();
		cout << current_card->str() << endl;
	}
}

int main() {
	// Create Deck Object
	deck* current_deck = new deck;

	// Draw 52 cards, and print both back side and front side
	draw_all_cards(current_deck);

	// Shuffle the deck
	current_deck->shuffle();

	// Draw 52 cards, and print both back side and front side
	draw_all_cards(current_deck);

	// Double-check that the next card is NULL
	if (current_deck->draw() == NULL) {
		cout << "Card #53 is NULL! It works!" << endl;
	} else {
		cout << "Card #53 is NOT NULL! You screwed up." << endl;
	}

	// Delete the deck object
	delete current_deck;

	return 0;
}


