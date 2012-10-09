/*
 * Location.cpp
 *
 *  Created on: 24/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Location.h"
#include <sstream>

namespace swinadventure {

using namespace std;

Location::Location(string ids[], size_t idlen, string name, string desc) : GameObject(ids, idlen, name, desc) {
	_inventory = new Inventory;
}

Location::~Location() {
	delete _inventory;

	// free all paths
	for(vector<Path*>::iterator path_iter = _paths.begin(); path_iter != _paths.end(); ++path_iter) {
		delete *path_iter;
	}
}


/**
 * Fetches a game object related to the location,
 * for example an Item in the Location's inventory
 * or the location itself
 * @param name	Game Object Identifier
 * @return pointer to Game Object
 */
GameObject* Location::locate(string name) {
	// Check ourselves
	if (are_you(name))
		return this;

	// Check if one of our paths matches
	for(vector<Path*>::iterator path_iter = _paths.begin(); path_iter != _paths.end(); ++path_iter) {
		if ((*path_iter)->are_you(name))
			return *path_iter;
	}

	// Ask the inventory to fetch the object
	return _inventory->fetch(name);
}

/**
 * Get a string description of what the location contains
 * @return
 */
string Location::get_full_description() {
	ostringstream result;
	result << GameObject::get_full_description() << endl;
	result << first_id() << " contains: " << endl;
	result << _inventory->get_item_list() << endl;
	result << "paths:" << endl;
	result << get_path_list();
	return result.str();
}

/**
 * Get a string description of the paths in the location
 * @return
 */
string Location::get_path_list() {
	return get_path_list("\t","\r\n");
}

/**
 * Get a string description of the paths in the location
 * @param prefix	The prefix to add before each path
 * @param sep		The string to separate each path (e.g. "\n")
 * @return
 */
string Location::get_path_list(string prefix, string sep) {
	ostringstream result;

	// Loop through all items adding their short descriptions
	for(vector<Path*>::iterator it = _paths.begin(); it != _paths.end(); ++it) {
		Path* path = *it;

		result << prefix << path->get_short_description();

		// Don't add separator on last item
		if (path != _paths.back()) {
			result << sep;
		}
	}

	return result.str();
}

/**
 * Gets the inventory
 * @return a pointer to the location's Inventory object
 */
Inventory* Location::get_inventory() {
	return _inventory;
}

/**
 * Add a path leading from this location
 * @param path
 */
void Location::add_path(Path* path) {
	_paths.push_back(path);
}

/**
 * Remove a path leading from this location
 * @param path
 */
void Location::remove_path(Path* path) {
	for(vector<Path*>::iterator path_iter = _paths.begin(); path_iter != _paths.end(); ++path_iter) {
		if (*path_iter == path) {
			_paths.erase(path_iter);
			return;
		}
	}
}

} /* namespace swinadventure */
