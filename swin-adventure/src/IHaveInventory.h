/*
 * IHaveInventory.h
 *
 *  Created on: 16/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef IHAVEINVENTORY_H_
#define IHAVEINVENTORY_H_

#include "GameObject.h"
#include "Inventory.h"
#include <string>

namespace swinadventure {

/**
 * Abstract "I Have Inventory" Interface Base Class,
 * implemented as a C++ pure virtual class
 *
 * This class should not be instantiated directly,
 * instead use one of the subclasses that implement this interface /
 * inherit from this class
 */
class IHaveInventory {
public:
	virtual GameObject* locate(std::string name) = 0;
	virtual std::string get_full_description() = 0;
	virtual Inventory* get_inventory() = 0;
};

} /* namespace swinadventure */
#endif /* IHAVEINVENTORY_H_ */
