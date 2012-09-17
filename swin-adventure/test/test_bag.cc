/*
 * test_bag.cc
 *
 *  Created on: 17/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "gtest/gtest.h"
#include "custom_macros.h"

#include "Bag.h"
#include "Item.h"
#include "Inventory.h"
#include <sstream>

namespace {

using namespace swinadventure;
using namespace std;

// The fixture for testing Items
class BagTest : public ::testing::Test {
 protected:

	BagTest() {
		std::string idents0[1] = {"bag"};
		_bag = new Bag(idents0, 1, "A Test Bag", "A bag used for unit testing");
		ASSERT_TRUE(NULL != _bag);
		Inventory* inventory = _bag->get_inventory();
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

	virtual ~BagTest() {
		delete _bag;
	}

	// Objects declared here can be used by all tests in the test case for Foo.
	Bag* _bag;
	Item* _items[3];
};

/**
 * Check the bag can identify itself
 */
TEST_F(BagTest, Identifiable) {
	ASSERT_TRUE(_bag->are_you("bag"));
	ASSERT_FALSE(_bag->are_you("container"));
}

/**
 * Check the bag can locate itself
 */
TEST_F(BagTest, LocateItself) {
	ASSERT_EQ(_bag, _bag->locate("bag"));
	ASSERT_EQ(NULL, _bag->locate("inventory"));
}

/**
 * Check the bag can locate items
 */
TEST_F(BagTest, LocateItems) {
	// Run twice to ensure items are not removed
	for (int i = 0; i < 2; i++) {
		ASSERT_EQ(_items[0], _bag->locate("ruby"));
		ASSERT_EQ(_items[1], _bag->locate("crowbar"));
		ASSERT_EQ(_items[2], _bag->locate("hammer"));
	}
}

/**
 * Check the bag cannot locate items it does not have
 */
TEST_F(BagTest, LocateNothing) {
	ASSERT_EQ(NULL, _bag->locate("sapphire"));
	ASSERT_EQ(NULL, _bag->locate("chocolate"));
	ASSERT_EQ(NULL, _bag->locate("newspaper"));
}

/**
 * Check the bag full description is in the form
 * "You are carrying: " and the inventory's item list
 */
TEST_F(BagTest, ShortDescription) {
	Inventory* inventory = _bag->get_inventory();
	ostringstream expected;
	expected << _bag->first_id() << " contains: " << endl << inventory->get_item_list();
	ASSERT_STROBJEQ(expected.str(), _bag->get_full_description());
}

}  // namespace
