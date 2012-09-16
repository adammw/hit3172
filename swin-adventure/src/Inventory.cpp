/*
 * Inventory.cpp
 *
 *  Created on: 16/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Inventory.h"
#include <sstream>

namespace swinadventure {

using namespace std;

/**
 * Inventory constructor
 */
Inventory::Inventory() {
	// TODO Auto-generated constructor stub
}

/**
 * Inventory destructor
 *
 * Frees all items in the inventory
 */
Inventory::~Inventory() {
	for(vector<Item*>::iterator it = _items.begin(); it != _items.end(); ++it) {
		delete *it;
	}
}

/**
 * Find an item in the Inventory object by item identifier
 * @param name		Identifier to search for
 * @param remove	True to remove the object from the Inventory after return
 * @return Item
 */
Item* Inventory::find_item(string name, bool remove) {
	// Loop through all items asking if it is the name specified
	for(vector<Item*>::iterator it = _items.begin(); it != _items.end(); ++it) {
		Item* item = *it;
		if (item->are_you(name)) {
			if (remove) {
				_items.erase(it);
			}
			return item;
		}
	}

	// Return NULL if not found
	return NULL;
}

/**
 * Check if the inventory contains the item
 * @param name
 * @return
 */
bool Inventory::has_item(string name) {
	return (find_item(name, false) != NULL);
}

/**
 * Add an item to the inventory
 * @param itm
 */
void Inventory::put(Item* itm) {
	_items.push_back(itm);
}

/**
 * Take an item from the inventory, removing it from the inventory
 * @param name
 * @return
 */
Item* Inventory::take(string name) {
	return find_item(name, true);
}

/**
 * Find an item in the inventory, leaving it in the inventory
 * @param name
 * @return
 */
Item* Inventory::fetch(string name) {
	return find_item(name, false);
}

/**
 * Get a string list of the inventory (separated by '\n' characters)
 * @return
 */
string Inventory::get_item_list() {
	return get_item_list("\t","\r\n");
}

/**
 * Get a string list of the inventory
 * @param prefix	The prefix to add before each item
 * @param sep		The string to separate each item (e.g. "\n")
 * @return
 */
string Inventory::get_item_list(string prefix, string sep) {
	ostringstream result;

	// Loop through all items adding their short descriptions
	for(vector<Item*>::iterator it = _items.begin(); it != _items.end(); ++it) {
		Item* item = *it;

		result << prefix << item->get_short_description();

		// Don't add separator on last item
		if (item != _items.back()) {
			result << sep;
		}
	}

	return result.str();
}

} /* namespace swinadventure */
