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
 * @return object name or NULL if not specified
 */
string* LookCommand::object_name(vector<string>* text) {
	// TODO: This may be replaced with a nicer regex-based function in the future
	// for more flexibility

	// Check if the fourth word is "in", if so, locate the container before
	// attempting to look_at_in
	if (text->size() >= 3) {
		string temp = (*text)[1];
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		if (temp.compare("at") == 0) {
			return &(*text)[2];
		}
	} else if (text->size() == 2) {
		return &(*text)[1];
	}

	return NULL;
}

/**
 * Extract the container name from the command set
 * @param text
 * @return container name or NULL if not specified
 */
string* LookCommand::container_name(vector<string>* text) {
	// TODO: This may be replaced with a nicer regex-based function in the future
	// for more flexibility

	// Check if the fourth word is "in", if so, locate the container before
	// attempting to look_at_in
	if (text->size() == 5) {
		string temp = (*text)[4];
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		if (temp.compare("in") == 0) {
			return &(*text)[5];
		}
	}

	return NULL;
}

/**
 * Determine which container to use from the command set
 * @param p
 * @param text
 * @return pointer to container (or player if not specified) or NULL if not found
 */
IHaveInventory* LookCommand::locate_container(Player* p,
		vector<string> text) {
	string* container = container_name(&text);

	// If container not specified, return the player
	if (NULL == container)
		return p;

	GameObject* obj = p->locate(*container);
	// TODO: ensure GameObject is actually a container
	return (IHaveInventory*)obj;
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
	GameObject* obj = container->locate(id);

	if (NULL == obj) {
		result << "I can't find " << id;
	} else {
		result << obj->get_description();
	}

	return result.str();
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

	if (NULL == container) {
		result << "I can't find " << *container_name(&text);
	} else {
		string* name = object_name(&text);
		if (NULL == name) {
			result << "I don't know what to look at";
		} else {
			result << look_at_in(*name, container);
		}
	}

	return result.str();
}

} /* namespace swinadventure */
