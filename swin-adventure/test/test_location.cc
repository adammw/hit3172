/*
 * test_bag.cc
 *
 *  Created on: 17/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "gtest/gtest.h"
#include "custom_macros.h"

#include "Location.h"
#include "Item.h"
#include "Inventory.h"
#include <sstream>

namespace {

using namespace swinadventure;
using namespace std;

// The fixture for testing Items
class LocationTest : public ::testing::Test {
 protected:

	LocationTest() {
		std::string idents0[1] = {"dungeon"};
		_location = new Location(idents0, 1, "Dungeon", "A small damn spot, with chains locking you to the wall, a small grate allows some light in", NULL, 0);
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
	}

	virtual ~LocationTest() {
		delete _location;
	}

	// Objects declared here can be used by all tests in the test case for Foo.
	Location* _location;
	Item* _items[3];
};

/**
 * Check the bag can identify itself
 */
TEST_F(LocationTest, Identifiable) {
	ASSERT_TRUE(_location->are_you("dungeon"));
}

/**
 * Check the bag can locate itself
 */
TEST_F(LocationTest, LocateItself) {
	ASSERT_EQ(_location, _location->locate("dungeon"));
}

/**
 * Check the bag can locate items
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
 * Check the bag cannot locate items it does not have
 */
TEST_F(LocationTest, LocateNothing) {
	ASSERT_EQ(NULL, _location->locate("sapphire"));
	ASSERT_EQ(NULL, _location->locate("chocolate"));
	ASSERT_EQ(NULL, _location->locate("newspaper"));
}

/**
 * Check the bag full description is in the form
 * "You are carrying: " and the inventory's item list
 */
TEST_F(LocationTest, ShortDescription) {
	Inventory* inventory = _location->get_inventory();
	ostringstream expected;
	expected << _location->first_id() << " contains: " << endl << inventory->get_item_list();
	ASSERT_STROBJEQ(expected.str(), _location->get_full_description());
}

}  // namespace
