/*
 * Inventory.h
 *
 *  Created on: 16/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <vector>
#include "Item.h"

namespace swinadventure {

/**
 * Class for a player's inventory, contains a collection of Item objects
 * that the user can take and put from
 */
class Inventory {
private:
	/** Vector to contain all item pointers */
	std::vector<Item*> _items;
	Item* find_item(std::string name, bool remove);

public:
	Inventory();
	~Inventory();

	bool has_item(std::string name);

	void put(Item* itm);
	Item* take(std::string name);
	Item* fetch(std::string name);

	std::string get_item_list();
	std::string get_item_list(std::string prefix, std::string sep);
};

} /* namespace swinadventure */
#endif /* INVENTORY_H_ */
