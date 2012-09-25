/*
 * test_item.cc
 *
 *  Created on: 15/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "gtest/gtest.h"
#include "custom_macros.h"

#include "Player.h"
#include "Inventory.h"
#include "Location.h"
#include <sstream>

namespace {

using namespace swinadventure;
using namespace std;

// The fixture for testing Items
class PlayerTest : public ::testing::Test {
 protected:

	PlayerTest() {
		_player = new Player("Test Player", "A player used for unit testing");
		ASSERT_TRUE(NULL != _player);
		Inventory* pi = _player->get_inventory();
		ASSERT_TRUE(NULL != pi);

		// Create some sample items
		std::string idents1[2] = {"gem", "ruby"};
		_items[0] = new Item(idents1, 2, "small blood-red ruby", "The small blood-red ruby is dulled from the years of wear");
		pi->put(_items[0]);

		std::string idents2[2] = {"crowbar", "bar"};
		_items[1] = new Item(idents2, 2, "large steel crowbar", "The crowbar has signs of rust and heavy wear, but still works fine");
		pi->put(_items[1]);

		std::string idents3[1] = {"hammer"};
		_items[2] = new Item(idents3, 1, "cheap nasty hammer", "The hammer is very new - still has it's original sale stickers on it, but looks like it might break");
		pi->put(_items[2]);

		// Create a location for the player
		std::string idents4[1] = {"dungeon"};
		_location = new Location(idents4, 1, "Dungeon", "A small damn spot, with chains locking you to the wall, a small grate allows some light in", NULL, 0);
		ASSERT_TRUE(NULL != _location);
		_player->set_location(_location);

		Inventory* li = _location->get_inventory();
		ASSERT_TRUE(NULL != li);

		// Add a sample item to location's inventory
		std::string idents5[1] = {"key"};
		_items[3] = new Item(idents5, 1, "old rusty key", "This key looks very old, almost as old as the grate and the dungeon itself");
		li->put(_items[3]);
	}

	virtual ~PlayerTest() {
		delete _player;
	}

	// Objects declared here can be used by all tests in the test case for Foo.
	Player* _player;
	Item* _items[4];
	Location* _location;
};

/**
 * Check the player can identify itself
 */
TEST_F(PlayerTest, Identifiable) {
	ASSERT_TRUE(_player->are_you("me"));
	ASSERT_TRUE(_player->are_you("inventory"));
	ASSERT_FALSE(_player->are_you("ruby"));
	ASSERT_FALSE(_player->are_you("hammer"));
}

/**
 * Check the player can locate itself
 */
TEST_F(PlayerTest, LocateItself) {
	ASSERT_EQ(_player, _player->locate("me"));
	ASSERT_EQ(_player, _player->locate("inventory"));
}

/**
 * Check the player can locate the current location
 */
TEST_F(PlayerTest, LocateLocation) {
	ASSERT_EQ(_location, _player->locate("dungeon"));
}

/**
 * Check the player can locate items in inventory
 */
TEST_F(PlayerTest, LocateItemsInInventory) {
	// Run twice to ensure items are not removed
	for (int i = 0; i < 2; i++) {
		ASSERT_EQ(_items[0], _player->locate("ruby"));
		ASSERT_EQ(_items[1], _player->locate("crowbar"));
		ASSERT_EQ(_items[2], _player->locate("hammer"));
	}
}

/**
 * Check the player can locate items in current location
 */
TEST_F(PlayerTest, LocateItemsInLocation) {
	// Run twice to ensure items are not removed
	for (int i = 0; i < 2; i++) {
		ASSERT_EQ(_items[3], _player->locate("key"));
	}
}

/**
 * Check the player cannot locate items it does not have
 */
TEST_F(PlayerTest, LocateNothing) {
	ASSERT_EQ(NULL, _player->locate("sapphire"));
	ASSERT_EQ(NULL, _player->locate("sapphire"));
	ASSERT_EQ(NULL, _player->locate("newspaper"));
}

/**
 * Check the player's full description is in the form
 * "You are carrying: " and the inventory's item list
 */
TEST_F(PlayerTest, ShortDescription) {
	Inventory* pi = _player->get_inventory();
	ostringstream result;
	result << "You are carrying: " << endl << pi->get_item_list();
	ASSERT_STROBJEQ(result.str(), _player->get_full_description());
}

}  // namespace
