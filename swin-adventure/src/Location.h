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
#include "Path.h"
#include <string>
#include <vector>

namespace swinadventure {

class Path; //forward declaration

/**
 * Class for location objects
 */
class Location: public GameObject, public IHaveInventory {
private:
	/** The location's inventory object */
	Inventory* _inventory;

	/** The paths going from the location */
	std::vector<Path*> _paths;
public:
	Location(std::string ids[], size_t idlen, std::string name, std::string desc);
	virtual ~Location();

	GameObject* locate(std::string name);
	std::string get_full_description();
	std::string get_path_list();
	std::string get_path_list(std::string prefix, std::string sep);

	Inventory* get_inventory();
	void add_path(Path* path);
	void remove_path(Path* path);
};

} /* namespace swinadventure */
#endif /* LOCATION_H_ */
