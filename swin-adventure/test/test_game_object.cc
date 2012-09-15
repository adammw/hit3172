/*
 * test_game_object.cc
 *
 *  Created on: 13/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "gtest/gtest.h"
#include "custom_macros.h"

#include "GameObject.h"

namespace {

using namespace swinadventure;

// The fixture for testing Game Objects
class GameObjectTest : public ::testing::Test {
 protected:

	GameObjectTest() {
		std::string idents[2] = {"gem", "ruby"};
		_gameObj = new GameObject(idents, 2, "small blood-red ruby", "The small blood-red ruby is dulled from the years of wear");
	}

	virtual ~GameObjectTest() {
		delete _gameObj;
	}

	// Objects declared here can be used by all tests in the test case for Foo.
	GameObject* _gameObj;
};

/**
 * Check you can create an game object with a list of identifiers, name and description
 */
TEST_F(GameObjectTest, CanCreate) {
	ASSERT_TRUE(NULL != _gameObj);
}

/**
 * Check the name can be retrieved
 */
TEST_F(GameObjectTest, Name) {
	ASSERT_STROBJEQ(_gameObj->get_name(), "small blood-red ruby");
}

/**
 * Check the description can be retrieved
 */
TEST_F(GameObjectTest, Description) {
	ASSERT_STROBJEQ(_gameObj->get_description(), "The small blood-red ruby is dulled from the years of wear");
}

/**
 * Check the short description can be retrieved
 */
TEST_F(GameObjectTest, ShortDescription) {
	ASSERT_STROBJEQ(_gameObj->get_short_description(), "a small blood-red ruby (gem)");
}

/**
 * Check the long description can be retrieved
 */
TEST_F(GameObjectTest, LongDescription) {
	ASSERT_STROBJEQ(_gameObj->get_full_description(), "The small blood-red ruby is dulled from the years of wear");
}

/**
 * Check the game object is identifiable
 */
TEST_F(GameObjectTest, Identifiable) {
	ASSERT_TRUE(_gameObj->are_you("gem"));
	ASSERT_TRUE(_gameObj->are_you("RUBY"));
	ASSERT_FALSE(_gameObj->are_you("sapphire"));
}

}  // namespace
