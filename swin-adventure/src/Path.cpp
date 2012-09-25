/*
 * Path.cpp
 *
 *  Created on: 25/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Path.h"

namespace swinadventure {

using namespace std;

Path::Path(string ids[], size_t idlen, string name, string desc, Location* end_loc) :
	GameObject(ids, idlen, name, desc) {
	_end_location = end_loc;
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

} /* namespace swinadventure */
