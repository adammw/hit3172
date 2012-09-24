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
	_location = NULL;
}

Player::~Player() {
	delete _inventory;
}

/**
 * Fetches a game object related to the player,
 * in this order:
 * Firstly checks themselves,
 * Secondly checks for object in inventory,
 * Thirdly checks for object in current location
 * @param name	Game Object Identifier
 * @return pointer to Game Object
 */
GameObject* Player::locate(string name) {
	// Check ourselves
	if (are_you(name))
		return this;

	// Check our inventory
	GameObject* result;
	if ((result = _inventory->fetch(name)))
		return result;

	// Abort if we are not anywhere
	if (!_location)
		return NULL;

	// Check our current location (or return null)
	return _location->locate(name);
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

/**
 * Get the current location
 * @return a pointer to the object of the current location
 */
Location* Player::get_location() {
	return _location;
}

/**
 * Set the current location
 * @param location	pointer to new location object
 */
void Player::set_location(Location* location) {
	_location = location;
}

} /* namespace swinadventure */
