/*
 * test_game_object.cc
 *
 *  Created on: 13/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "gtest/gtest.h"
#include "custom_macros.h"

#include "Inventory.h"
#include "Item.h"

namespace {

using namespace swinadventure;

// The fixture for testing Game Objects
class InventoryTest : public ::testing::Test {
 protected:

	InventoryTest() {
		_inventory = new Inventory();

		// Add some sample items
		std::string idents1[2] = {"gem", "ruby"};
		_items[0] = new Item(idents1, 2, "small blood-red ruby", "The small blood-red ruby is dulled from the years of wear");
		_inventory->put(_items[0]);

		std::string idents2[2] = {"crowbar", "bar"};
		_items[1] = new Item(idents2, 2, "large steel crowbar", "The crowbar has signs of rust and heavy wear, but still works fine");
		_inventory->put(_items[1]);

		std::string idents3[1] = {"hammer"};
		_items[2] = new Item(idents3, 1, "cheap nasty hammer", "The hammer is very new - still has it's original sale stickers on it, but looks like it might break");
		_inventory->put(_items[2]);
	}

	virtual ~InventoryTest() {
		delete _inventory;
	}

	// Objects declared here can be used by all tests in the test case for Foo.
	Inventory* _inventory;
	Item* _items[3];
};

/**
 * Check you can create an inventory
 */
TEST_F(InventoryTest, CanCreate) {
	ASSERT_TRUE(NULL != _inventory);
}

/**
 * Check you can find an item in the inventory
 */
TEST_F(InventoryTest, FindItem) {
	ASSERT_TRUE(_inventory->has_item("ruby"));
	ASSERT_TRUE(_inventory->has_item("crowbar"));
	ASSERT_TRUE(_inventory->has_item("hammer"));
}

/**
 * Check you cannot find an item that are not in the inventory
 */
TEST_F(InventoryTest, NotFindItem) {
	ASSERT_FALSE(_inventory->has_item("sapphire"));
	ASSERT_FALSE(_inventory->has_item("chocolate"));
	ASSERT_FALSE(_inventory->has_item("newspaper"));
}


/**
 * Check you can fetch an item from the inventory and they are kept
 */
TEST_F(InventoryTest, FetchItem) {
	// Fetch everything twice - check they stay in the inventory
	for (int i = 0; i < 2; i++) {
		ASSERT_EQ(_items[0], _inventory->fetch("ruby"));
		ASSERT_EQ(_items[1], _inventory->fetch("crowbar"));
		ASSERT_EQ(_items[2], _inventory->fetch("hammer"));
	}
}

/**
 * Check you can take an items from the inventory and they are not kept
 */
TEST_F(InventoryTest, TakeItem) {
	// Check the inventory has all items
	ASSERT_TRUE(_inventory->has_item("ruby"));
	ASSERT_TRUE(_inventory->has_item("crowbar"));
	ASSERT_TRUE(_inventory->has_item("hammer"));

	// Check that taking the item returns the correct item
	ASSERT_EQ(_items[0], _inventory->take("ruby"));
	ASSERT_EQ(_items[1], _inventory->take("crowbar"));
	ASSERT_EQ(_items[2], _inventory->take("hammer"));

	// Check that you can't take an object you have already taken
	ASSERT_EQ(NULL, _inventory->take("ruby"));
	ASSERT_EQ(NULL, _inventory->take("crowbar"));
	ASSERT_EQ(NULL, _inventory->take("hammer"));

	// Check the inventory has none of the items
	ASSERT_FALSE(_inventory->has_item("ruby"));
	ASSERT_FALSE(_inventory->has_item("crowbar"));
	ASSERT_FALSE(_inventory->has_item("hammer"));
}

TEST_F(InventoryTest, ItemList) {
	ASSERT_STROBJEQ(_inventory->get_item_list("",","), "a small blood-red ruby (gem),a large steel crowbar (crowbar),a cheap nasty hammer (hammer)");
	ASSERT_STROBJEQ(_inventory->get_item_list(), "\ta small blood-red ruby (gem)\r\n\ta large steel crowbar (crowbar)\r\n\ta cheap nasty hammer (hammer)");
}

}  // namespace
