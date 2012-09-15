/*
 * GameObject.cpp
 *
 *  Created on: 13/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "GameObject.h"
#include <sstream>

namespace swinadventure {

using namespace std;

/**
 * Game Object Constructor
 * @param ids	Identifiers array
 * @param idlen	Length of identifiers array
 * @param name	Name of the object
 * @param desc	Long description of the object
 */
GameObject::GameObject(string ids[], size_t idlen, string name, string desc) : Identifiable(ids, idlen) {
	_name = name;
	_description = desc;
}

/**
 * @see get_full_description
 * @return
 */
string GameObject::get_description() {
	get_full_description();
}

/**
 * Get the name of the object
 * @return
 */
string GameObject::get_name() {
	return _name;
}

/**
 * Get a short description of the object in the form:
 * "a <name> (<first_id>)"
 * @return
 */
string GameObject::get_short_description() {
	ostringstream result;
	result << "a " << _name << '(' << first_id() << ')';
	return result.str();
}


/**
 * Get the full description of the object
 * @return
 */
string GameObject::get_full_description() {
	return _description;
}

}
/* namespace swinadventure */
