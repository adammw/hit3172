/*
 * test_game_object.cc
 *
 *  Created on: 13/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "gtest/gtest.h"
#include "custom_macros.h"

#include "LookCommand.h"
#include "Player.h"
#include "Inventory.h"
#include "Bag.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

namespace {

using namespace swinadventure;
using namespace std;

// The fixture for testing Game Objects
class LookCommandTest : public ::testing::Test {
 protected:

	LookCommandTest() {
		_player = new Player("Test Player", "A player used for unit testing");
		ASSERT_TRUE(NULL != _player);
		Inventory* pi = _player->get_inventory();
		ASSERT_TRUE(NULL != pi);

		// Create some sample items
		std::string idents1[2] = {"gem", "ruby"};
		Item* i = new Item(idents1, 2, "small blood-red ruby", "The small blood-red ruby is dulled from the years of wear");
		pi->put(i);

		std::string idents2[2] = {"crowbar", "bar"};
		i = new Item(idents2, 2, "large steel crowbar", "The crowbar has signs of rust and heavy wear, but still works fine");
		pi->put(i);

		std::string idents3[1] = {"hammer"};
		i = new Item(idents3, 1, "cheap nasty hammer", "The hammer is very new - still has it's original sale stickers on it, but looks like it might break");
		pi->put(i);

		// Create a bag with a sword in it
		std::string idents4[1] = {"bag"};
		Bag* b = new Bag(idents4, 1, "bag", "A bag used for unit testing");
		pi->put(b);
		std::string idents5[1] = {"sword"};
		i = new Item(idents5, 1, "sharp long-sword", "Be careful not to cut yourself of this sharp long-sword");
		b->get_inventory()->put(i);


		_lookCommand = new LookCommand;
	}

	virtual ~LookCommandTest() {
		delete _player;
		delete _lookCommand;
	}

	vector<string> SplitTextIntoCommands(string text) {
		stringstream ss(text);
		istream_iterator<string> begin(ss);
		istream_iterator<string> end;
		vector<string> tokens(begin, end);
		return tokens;
	}

	// Objects declared here can be used by all tests in the test case for Foo.
	Player* _player;
	LookCommand* _lookCommand;
};

/**
 * Check players description when looking at "me"
 */
TEST_F(LookCommandTest, LookAtMe) {
	vector<string> tokens = SplitTextIntoCommands("look at me");
	string r = _lookCommand->execute(_player, tokens);
	ASSERT_STROBJEQ(_player->get_description(), r);
}

/**
 * Check players description when looking at "inventory"
 */
TEST_F(LookCommandTest, LookAtInventory) {
	vector<string> tokens = SplitTextIntoCommands("look at inventory");
	string r = _lookCommand->execute(_player, tokens);
	ASSERT_STROBJEQ(_player->get_description(), r);
}

/**
 * Check gem's description when looking at "gem"
 */
TEST_F(LookCommandTest, LookAtGem) {
	vector<string> tokens = SplitTextIntoCommands("look at gem");
	string r = _lookCommand->execute(_player, tokens);
	ASSERT_STROBJEQ("The small blood-red ruby is dulled from the years of wear", r);
}

/**
 * Check location description when looking
 */
TEST_F(LookCommandTest, LookAtLocation) {
	string ident[] = {"dungeon"};
	Location* loc =  new Location(ident, 1, "Dungeon", "A small damn spot, with chains locking you to the wall, a small grate allows some light in");
	_player->set_location(loc);
	vector<string> tokens = SplitTextIntoCommands("look");
	string r = _lookCommand->execute(_player, tokens);
	ASSERT_STROBJEQ(loc->get_description(), r);
}


/**
 * Check you don't crash when looking without location
 */
TEST_F(LookCommandTest, LookAtNoLocation) {
	vector<string> tokens = SplitTextIntoCommands("look");
	string r = _lookCommand->execute(_player, tokens);
	ASSERT_STROBJEQ("You aren't anywhere", r);
}

/**
 * Check location description when looking
 */
TEST_F(LookCommandTest, LookAtLocationHere) {
	string ident[] = {"dungeon"};
	Location* loc =  new Location(ident, 1, "Dungeon", "A small damn spot, with chains locking you to the wall, a small grate allows some light in");
	_player->set_location(loc);
	vector<string> tokens = SplitTextIntoCommands("look here");
	string r = _lookCommand->execute(_player, tokens);
	ASSERT_STROBJEQ(loc->get_description(), r);
}


/**
 * Check you don't crash when looking without location
 */
TEST_F(LookCommandTest, LookAtNoLocationHere) {
	vector<string> tokens = SplitTextIntoCommands("look here");
	string r = _lookCommand->execute(_player, tokens);
	ASSERT_STROBJEQ("You aren't anywhere", r);
}


/**
 * Check that it can't find items you don't have
 */
TEST_F(LookCommandTest, LookAtUnk) {
	vector<string> tokens = SplitTextIntoCommands("look at money");
	string r = _lookCommand->execute(_player, tokens);
	ASSERT_STROBJEQ("I can't find money", r);
}

/**
 * Check gem's description is gem in inventory
 */
TEST_F(LookCommandTest, LookAtGemInInventory) {
	vector<string> tokens = SplitTextIntoCommands("look at gem in inventory");
	string r = _lookCommand->execute(_player, tokens);
	ASSERT_STROBJEQ("The small blood-red ruby is dulled from the years of wear", r);
}

/**
 * Check sword's description is gem in bag
 */
TEST_F(LookCommandTest, LookAtSwordInBag) {
	vector<string> tokens = SplitTextIntoCommands("look at sword in bag");
	string r = _lookCommand->execute(_player, tokens);
	ASSERT_STROBJEQ("Be careful not to cut yourself of this sharp long-sword", r);
}

/**
 * Check sword cannot be found in a bag that doesn't exist
 */
TEST_F(LookCommandTest, LookAtSwordInNoBag) {
	vector<string> tokens = SplitTextIntoCommands("look at sword in nobag");
	string r = _lookCommand->execute(_player, tokens);
	ASSERT_STROBJEQ("I can't find nobag", r);
}

/**
 * Check gem cannot be found in bag
 */
TEST_F(LookCommandTest, LookAtNoGemInBag) {
	vector<string> tokens = SplitTextIntoCommands("look at gem in bag");
	string r = _lookCommand->execute(_player, tokens);
	ASSERT_STROBJEQ("I can't find gem", r);
}

}  // namespace