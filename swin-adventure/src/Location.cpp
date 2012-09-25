/*
 * Location.cpp
 *
 *  Created on: 24/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Location.h"
#include <sstream>

namespace swinadventure {

using namespace std;

Location::Location(string ids[], size_t idlen, string name, string desc) : GameObject(ids, idlen, name, desc) {
	_inventory = new Inventory;
}

Location::~Location() {
	delete _inventory;
}


/**
 * Fetches a game object related to the location,
 * for example an Item in the Location's inventory
 * or the location itself
 * @param name	Game Object Identifier
 * @return pointer to Game Object
 */
GameObject* Location::locate(string name) {
	// Check ourselves
	if (are_you(name))
		return this;

	// Ask the inventory to fetch the object
	return _inventory->fetch(name);
}

/**
 * Get a string description of what the location contains
 * @return
 */
string Location::get_full_description() {
	ostringstream result;
	result << first_id() << " contains: " << endl;
	result << _inventory->get_item_list();
	return result.str();
}

/**
 * Gets the inventory
 * @return a pointer to the location's Inventory object
 */
Inventory* Location::get_inventory() {
	return _inventory;
}

} /* namespace swinadventure */