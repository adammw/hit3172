/*
 * Location.h
 *
 *  Created on: 24/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef LOCATION_H_
#define LOCATION_H_

#include "GameObject.h"
#include "IHaveInventory.h"
#include "Inventory.h"
#include <string>

namespace swinadventure {

/**
 * Class for location objects
 */
class Location: public GameObject, public IHaveInventory {
private:
	/** The location's inventory object */
	Inventory* _inventory;
public:
	Location(std::string ids[], size_t idlen, std::string name, std::string desc);
	virtual ~Location();

	GameObject* locate(std::string name);
	std::string get_full_description();

	Inventory* get_inventory();
};

} /* namespace swinadventure */
#endif /* LOCATION_H_ */
