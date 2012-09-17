/*
 * Bag.h
 *
 *  Created on: 17/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef BAG_H_
#define BAG_H_

#include "Item.h"
#include "Inventory.h"
#include "IHaveInventory.h"
#include "GameObject.h"
#include <string>

namespace swinadventure {

class Bag : public Item, public IHaveInventory {
private:
	/** The bag's inventory object */
	Inventory* _inventory;
public:
	Bag(std::string ids[], size_t idlen, std::string name, std::string desc);
	virtual ~Bag();

	GameObject* locate(std::string name);

	std::string get_full_description();
	Inventory* get_inventory();
};

} /* namespace swinadventure */
#endif /* BAG_H_ */
