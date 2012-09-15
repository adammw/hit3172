/*
 * Item.cpp
 *
 *  Created on: 16/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Item.h"

namespace swinadventure {

using namespace std;

/**
 * Item Constructor
 * @param ids	Identifiers array
 * @param idlen	Length of identifiers array
 * @param name	Name of the object
 * @param desc	Long description of the object
 */
Item::Item(string ids[], size_t idlen, string name, string desc) : GameObject(ids, idlen, name, desc) {
}

} /* namespace swinadventure */
