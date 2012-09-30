/*
 * Path.cpp
 *
 *  Created on: 25/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Path.h"

namespace swinadventure {

using namespace std;

/**
 * Create a new Path object
 * @param ids		Array of string identifiers
 * @param idlen		Length of identifier array
 * @param name		Name of the Path
 * @param desc		Textual description of Path (as seen from starting location)
 * @param outcome	Textual description of the outcome of taking the path
 * 					(shown when path has been taken)
 */
Path::Path(string ids[], size_t idlen, string name, string desc, string outcome) :
	GameObject(ids, idlen, name, desc) {
	_outcome_description = outcome;
}

Path::~Path() {
	// TODO Auto-generated destructor stub
}

/**
 * Move the player to the location specified by the Path object
 * @param player
 */
void Path::move_player(Player* player) {
	player->set_location(_end_location);
}

/**
 * Set the end location for the path
 * @param loc
 */
void Path::set_end_location(Location* loc) {
	_end_location = loc;
}

/**
 * Get the string description of the Path's outcome
 * @return
 */
string Path::get_outcome() {
	return _outcome_description;
}

} /* namespace swinadventure */
