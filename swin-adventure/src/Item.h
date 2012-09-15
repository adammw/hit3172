/*
 * Item.h
 *
 *  Created on: 16/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef ITEM_H_
#define ITEM_H_

#include "GameObject.h"
#include <string>

namespace swinadventure {

/**
 * Stub class which inherits from GameObject for any Item
 * Only Items can be added to an inventory
 */
class Item : public swinadventure::GameObject {
public:
	Item(std::string ids[], size_t idlen, std::string name, std::string desc);
};

} /* namespace swinadventure */
#endif /* ITEM_H_ */
