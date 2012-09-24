/*
 * Player.h
 *
 *  Created on: 16/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "GameObject.h"
#include "Inventory.h"
#include "Location.h"
#include "IHaveInventory.h"
#include <string>

namespace swinadventure {

/**
 * Class for a player which contains an inventory which can retrieve items
 */
class Player : public swinadventure::GameObject, public swinadventure::IHaveInventory {
private:
	/** The player's inventory object */
	Inventory* _inventory;

	/** The player's current location */
	Location* _location;

	/** Default identifiers for the player */
	static const std::string _default_identifiers[2];

public:
	Player(std::string name, std::string desc);
	~Player();

	GameObject* locate(std::string name);
	std::string get_full_description();

	Inventory* get_inventory();
	Location* get_location();
	void set_location(Location* location);
};

} /* namespace swinadventure */
#endif /* PLAYER_H_ */
