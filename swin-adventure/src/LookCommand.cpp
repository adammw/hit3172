/*
 * LookCommand.cpp
 *
 *  Created on: 16/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "LookCommand.h"
#include "GameObject.h"
#include <sstream>
#include <algorithm>
#include <iostream>

namespace swinadventure {

using namespace std;

string LookCommand::_default_identifiers[] = {"look", "examine", "inspect"};

LookCommand::LookCommand() : Command((string*)_default_identifiers, 3) {
	// TODO Auto-generated constructor stub

}

LookCommand::~LookCommand() {
	// TODO Auto-generated destructor stub
}

/**
 * Extract the object name from the command set
 * @param text
 * @return object name or empty string if not specified
 */
string LookCommand::object_name(vector<string> text) {
	// TODO: This may be replaced with a nicer regex-based function in the future
	// for more flexibility

	// Check if the fourth word is "in", if so, locate the container before
	// attempting to look_at_in
	if (text.size() >= 3) {
		string temp = text[1];
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		if (temp.compare("at") == 0) {
			return text[2];
		} else {
			return text[1];
		}
	} else if (text.size() == 2) {
		return text[1];
	}

	return "";
}

/**
 * Extract the container name from the command set
 * @param text
 * @return container name or empty string if not specified
 */
string LookCommand::container_name(vector<string> text) {
	// TODO: This may be replaced with a nicer regex-based function in the future
	// for more flexibility

	// Check if the fourth word is "in", if so, locate the container before
	// attempting to look_at_in
	if (text.size() == 5) {
		string temp = text[3];
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		if (temp.compare("in") == 0) {
			return text[4];
		}
	}

	return "";
}

/**
 * Determine which container to use from the command set
 * @param p
 * @param text
 * @return pointer to container (or player if not specified) or NULL if not found
 */
IHaveInventory* LookCommand::locate_container(Player* p,
		vector<string> text) {
	string container = container_name(text);

	// If container not specified, return the player
	if (container.size() == 0)
		return p;

	// Get the player to locate the container or return NULL
	GameObject* obj = p->locate(container);
	return dynamic_cast<IHaveInventory*>(obj);
}

/**
 * Find a Game Object within the specified container, and return
 * it's string representation or a not found message
 * @param id
 * @param container
 * @return
 */
string LookCommand::look_at_in(string id, IHaveInventory* container) {
	ostringstream result;
	GameObject* obj;

	obj = container->locate(id);

	if (NULL == obj) {
		result << "I can't find " << id;
	} else {
		result << look_at(obj);
	}

	return result.str();
}

string LookCommand::look_at(GameObject* obj) {
	ostringstream result;
	result << obj->get_description();
	return result.str();
}

/**
 * Check if the id is "here" (case insensitive)
 * @param id
 * @return
 */
bool LookCommand::is_here(std::string id) {
	transform(id.begin(), id.end(), id.begin(), ::tolower);
	return (id.compare("here") == 0);
}

/**
 * Execute the look command
 * @param p
 * @param text
 * @return
 */
string LookCommand::execute(Player* p, vector<string> text) {
	ostringstream result;
	IHaveInventory* container = locate_container(p, text);
	string container_name_str = container_name(text);

	// If container could not be found (only if specified)
	if (NULL == container) {
		result << "I can't find " << container_name_str;
	} else {
		string name = object_name(text);
		Location* loc = p->get_location();
		if (name.size() == 0) {
			// Show the location if just "look"
			if (loc != NULL) {
				result << look_at(loc);
			} else {
				result << "You aren't anywhere";
			}
		// Check for "look here"
		} else if (is_here(name)) {
			if (loc == NULL) {
				result << "You aren't anywhere";
			} else {
				result << look_at(p->get_location());
			}
		// Otherwise, attempt to look at in the container
		} else {
			result << look_at_in(name, container);
		}
	}

	return result.str();
}

} /* namespace swinadventure */
