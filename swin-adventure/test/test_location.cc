/*
 * test_location.cc
 *
 *  Created on: 17/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "gtest/gtest.h"
#include "custom_macros.h"

#include "Location.h"
#include "Item.h"
#include "Inventory.h"
#include "Path.h"
#include <sstream>

namespace {

using namespace swinadventure;
using namespace std;

// The fixture for testing Locations
class LocationTest : public ::testing::Test {
 protected:

	LocationTest() {
		std::string idents0[1] = {"dungeon"};
		_location = new Location(idents0, 1, "Dungeon", "A small damn spot, with chains locking you to the wall, a small grate allows some light in");
		ASSERT_TRUE(NULL != _location);
		Inventory* inventory = _location->get_inventory();
		ASSERT_TRUE(NULL != inventory);

		// Create some sample items
		std::string idents1[2] = {"gem", "ruby"};
		_items[0] = new Item(idents1, 2, "small blood-red ruby", "The small blood-red ruby is dulled from the years of wear");
		inventory->put(_items[0]);

		std::string idents2[2] = {"crowbar", "bar"};
		_items[1] = new Item(idents2, 2, "large steel crowbar", "The crowbar has signs of rust and heavy wear, but still works fine");
		inventory->put(_items[1]);

		std::string idents3[1] = {"hammer"};
		_items[2] = new Item(idents3, 1, "cheap nasty hammer", "The hammer is very new - still has it's original sale stickers on it, but looks like it might break");
		inventory->put(_items[2]);

		// Create paths
		std::string idents4[2] = {"north","n"};
		_paths[0] = new Path(idents4, 2, "Head north", "Head north through a dim tunnel", "You walk though the tunnel for what feels like an age, and end back up in the dungeon");
		ASSERT_TRUE(NULL != _paths[0]);

		std::string idents5[2] = {"south","s"};
		_paths[1] = new Path(idents5, 2, "Head south", "Head south though a door", "The door is locked");
		ASSERT_TRUE(NULL != _paths[1]);

		// Link paths and locations
		_paths[0]->set_end_location(_location);
		_location->add_path(_paths[0]);
		_paths[1]->set_end_location(_location);
		_location->add_path(_paths[1]);
	}

	virtual ~LocationTest() {
		delete _location;
	}

	// Objects declared here can be used by all tests in the test case for Foo.
	Location* _location;
	Item* _items[3];
	Path* _paths[2];
};

/**
 * Check the location can identify itself
 */
TEST_F(LocationTest, Identifiable) {
	ASSERT_TRUE(_location->are_you("dungeon"));
}

/**
 * Check the location can locate itself
 */
TEST_F(LocationTest, LocateItself) {
	ASSERT_EQ(_location, _location->locate("dungeon"));
}

/**
 * Check the location can locate items
 */
TEST_F(LocationTest, LocateItems) {
	// Run twice to ensure items are not removed
	for (int i = 0; i < 2; i++) {
		ASSERT_EQ(_items[0], _location->locate("ruby"));
		ASSERT_EQ(_items[1], _location->locate("crowbar"));
		ASSERT_EQ(_items[2], _location->locate("hammer"));
	}
}

/**
 * Check the location can locate items
 */
TEST_F(LocationTest, LocatePaths) {
	// Run twice to ensure items are not removed
	for (int i = 0; i < 2; i++) {
		ASSERT_EQ(_paths[0], _location->locate("north"));
		ASSERT_EQ(_paths[1], _location->locate("south"));
		ASSERT_EQ(_paths[0], _location->locate("n"));
		ASSERT_EQ(_paths[1], _location->locate("s"));
	}
}

/**
 * Check the Location cannot locate items/paths it does not have
 */
TEST_F(LocationTest, LocateNothing) {
	ASSERT_EQ(NULL, _location->locate("sapphire"));
	ASSERT_EQ(NULL, _location->locate("chocolate"));
	ASSERT_EQ(NULL, _location->locate("newspaper"));
	ASSERT_EQ(NULL, _location->locate("east"));
	ASSERT_EQ(NULL, _location->locate("west"));
}

/**
 * Check the bag full description is in the form
 * "You are carrying: " and the inventory's item list
 */
TEST_F(LocationTest, ShortDescription) {
	Inventory* inventory = _location->get_inventory();
	ostringstream expected;
	expected << "A small damn spot, with chains locking you to the wall, a small grate allows some light in" << endl;
	expected << _location->first_id() << " contains: " << endl << inventory->get_item_list() << endl;
	expected << "paths:" << endl << _location->get_path_list();
	ASSERT_STROBJEQ(expected.str(), _location->get_full_description());
}

}  // namespace
