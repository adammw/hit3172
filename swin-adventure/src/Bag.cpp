/*
 * Bag.cpp
 *
 *  Created on: 17/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Bag.h"
#include <sstream>

namespace swinadventure {

using namespace std;

Bag::Bag(string ids[], size_t idlen, string name, string desc) : Item(ids, idlen, name, desc) {
	_inventory = new Inventory;
}

Bag::~Bag() {
	delete _inventory;
}

/**
 * Fetches a game object related to the bag,
 * for example an Item in the Player's inventory
 * or the player themselves
 * @param name	Game Object Identifier
 * @return pointer to Game Object
 */
GameObject* Bag::locate(string name) {
	// Check ourselves
	if (are_you(name))
		return this;

	// Ask the inventory to fetch the object
	return _inventory->fetch(name);
}

/**
 * Get a string description of what the bag is carrying
 * @return
 */
string Bag::get_full_description() {
	ostringstream result;
	result << first_id() << " contains: " << endl;
	result << _inventory->get_item_list();
	return result.str();
}

/**
 * Gets the inventory
 * @return a pointer to the bag's Inventory object
 */
Inventory* Bag::get_inventory() {
	return _inventory;
}

} /* namespace swinadventure */
