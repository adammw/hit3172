/*
 * Player.cpp
 *
 *  Created on: 16/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Player.h"
#include <sstream>

namespace swinadventure {

using namespace std;

std::string Player::_default_identifiers[] = {"me", "inventory"};

Player::Player(string name, string desc) : GameObject((std::string*) _default_identifiers, 2, name, desc) {
	_inventory = new Inventory;
}

Player::~Player() {
	delete _inventory;
}

/**
 * Fetches a game object related to the player,
 * for example an Item in the Player's inventory
 * or the player themselves
 * @param name	Game Object Identifier
 * @return pointer to Game Object
 */
GameObject* Player::locate(string name) {
	// Check ourselves
	if (are_you(name))
		return this;

	// Ask the inventory to fetch the object
	return _inventory->fetch(name);
}

/**
 * Get a string description of what the player is carrying
 * @return
 */
string Player::get_full_description() {
	ostringstream result;
	result << "You are carrying: " << endl;
	result << _inventory->get_item_list();
	return result.str();
}

/**
 * Gets the inventory
 * @return a pointer to the player's Inventory object
 */
Inventory* Player::get_inventory() {
	return _inventory;
}

} /* namespace swinadventure */
