/*
 * GameObject.h
 *
 *  Created on: 13/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <Identifiable.h>
#include <string>

namespace swinadventure {

/**
 * Base Game Object class, inherits from an Identifiable object
 * Contains methods to get description and name
 */
class GameObject: public swinadventure::Identifiable {
private:
	/** Object description */
	std::string _description;

	/** Object name */
	std::string _name;
public:
	GameObject(std::string ids[], size_t idlen, std::string name, std::string desc);

	std::string get_description();
	std::string get_name();

	std::string get_short_description();
	std::string get_full_description();
};

} /* namespace swinadventure */
#endif /* GAMEOBJECT_H_ */
