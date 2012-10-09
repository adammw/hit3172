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

class Location; //forward declaration
class Player; //forward declaration

/**
 * The Path class represents a Path to a location,
 * which can move a player and is identifiable and
 * has a description and outcome
 */
class Path: public swinadventure::GameObject {
private:
	/** Final location to move the player to */
	Location* _end_location;

	/** String description of the Path's outcome */
	std::string _outcome_description;
public:
	Path(std::string ids[], size_t idlen, std::string name, std::string desc, std::string outcome);
	virtual ~Path();
	virtual std::string get_short_description();

	void set_end_location(Location* loc);
	void move_player(Player* player);
	std::string get_outcome();
};

} /* namespace swinadventure */
#endif /* PATH_H_ */
