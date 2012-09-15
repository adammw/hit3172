/*
 * test_item.cc
 *
 *  Created on: 15/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "gtest/gtest.h"
#include "custom_macros.h"

#include "Item.h"

namespace {

using namespace swinadventure;

// The fixture for testing Items
class ItemTest : public ::testing::Test {
 protected:

	ItemTest() {
		std::string idents[2] = {"gem", "ruby"};
		_item = new Item(idents, 2, "small blood-red ruby", "The small blood-red ruby is dulled from the years of wear");
	}

	virtual ~ItemTest() {
		delete _item;
	}

	// Objects declared here can be used by all tests in the test case for Foo.
	Item* _item;
};

/**
 * Check you can create an item with a list of identifiers, name and description
 */
TEST_F(ItemTest, CanCreate) {
	ASSERT_TRUE(NULL != _item);
}
/**
 * Check the item is identifiable
 */
TEST_F(ItemTest, Identifiable) {
	ASSERT_TRUE(_item->are_you("gem"));
	ASSERT_TRUE(_item->are_you("RUBY"));
	ASSERT_FALSE(_item->are_you("sapphire"));
}

}  // namespace
