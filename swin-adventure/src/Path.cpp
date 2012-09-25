/*
 * Path.cpp
 *
 *  Created on: 25/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Path.h"

namespace swinadventure {

using namespace std;

Path::Path(string ids[], size_t idlen, string name, string desc) :
	GameObject(ids, idlen, name, desc) { }

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

} /* namespace swinadventure */
