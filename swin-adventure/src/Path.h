/*
 * Path.h
 *
 *  Created on: 25/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef PATH_H_
#define PATH_H_

#include "GameObject.h"
#include "Location.h"
#include "Player.h"
#include <string>

namespace swinadventure {

/**
 * The Path class represents a Path to a location,
 * which can move a player and is identifiable and
 * has a description
 */
class Path: public swinadventure::GameObject {
private:
	/** Final location to move the player to */
	Location* _end_location;
public:
	Path(std::string ids[], size_t idlen, std::string name, std::string desc, Location* end_loc);
	virtual ~Path();

	void move_player(Player* player);
};

} /* namespace swinadventure */
#endif /* PATH_H_ */
