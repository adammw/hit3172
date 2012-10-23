/*
 * test_item.cc
 *
 *  Created on: 15/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "gtest/gtest.h"
#include "custom_macros.h"

#include "Location.h"
#include "Item.h"
#include "Inventory.h"
#include "Path.h"
#include "CommandProcessor.h"
#include "LookCommand.h"
#include "MoveCommand.h"
#include <sstream>

namespace {

using namespace swinadventure;
using namespace std;

// The fixture for testing Items
class CommandProcessorTest : public ::testing::Test {
 protected:

	CommandProcessorTest() {
		std::string idents[] = {"up" /* paths[0] */, "down" /* paths[1] */, "dungeon" /* location[0] */, "field" /* location[1] */ };

		// Create paths
		_paths[0] = new Path(idents, 1, "Crawl through the grate", "The grate has an opening that looks just large enough to crawl through", "After much squeezing, you somehow manage to crawl your way through the grate and end up outside in a field");
		ASSERT_TRUE(NULL != _paths[0]);

		_paths[1] = new Path(idents + 1, 1, "Jump down the hole", "There's a hole in the ground that seems to lead somewhere", "You start to climb down but slip and slide down a dirty hole, ending up somewhere cold and damp");
		ASSERT_TRUE(NULL != _paths[1]);

		// Create locations
		_locations[0] = new Location(idents + 2, 1, "Dungeon", "A small damn spot, with chains locking you to the wall, a small grate allows some light in");
		ASSERT_TRUE(NULL != _locations[0]);

		_locations[1] = new Location(idents + 3, 1, "A Field", "A large green field");
		ASSERT_TRUE(NULL != _locations[1]);

		// Link paths and locations
		_paths[0]->set_end_location(_locations[1]);
		_locations[0]->add_path(_paths[0]);
		_paths[1]->set_end_location(_locations[0]);
		_locations[1]->add_path(_paths[1]);

		// Create a player, start in the dungeon location
		_player = new Player("Test Player", "A player used for unit testing");
		ASSERT_TRUE(NULL != _player);
		_player->set_location(_locations[0]);

		// Create a new command processor object
		_processor = new CommandProcessor;
	}

	virtual ~CommandProcessorTest() {
		for(int i=0;i<2;i++)
		    delete _locations[i];
		delete _player;
	}

	vector<string> SplitTextIntoCommands(string text) {
		stringstream ss(text);
		istream_iterator<string> begin(ss);
		istream_iterator<string> end;
		vector<string> tokens(begin, end);
		return tokens;
	}

	// Objects declared here can be used by all tests in the test case for Foo.
	Location* _locations[2];
	Path* _paths[2];
	Player* _player;
	CommandProcessor* _processor;
};

/**
 * Check the player can look around
 */
TEST_F(CommandProcessorTest, Look) {
	vector<string> tokens = SplitTextIntoCommands("look");
	ASSERT_STROBJEQ((new LookCommand)->execute(_player, tokens), _processor->execute(_player, tokens));
}

/**
 * Check the player can move
 */
TEST_F(CommandProcessorTest, Move) {
	vector<string> tokens = SplitTextIntoCommands("move up");
	_player->set_location(_locations[0]);
	string expected = (new MoveCommand)->execute(_player, tokens);
	_player->set_location(_locations[0]);
	string actual = _processor->execute(_player, tokens);
	ASSERT_STROBJEQ(expected, actual);
}

/**
 * Check what happens with invalid command
 */
TEST_F(CommandProcessorTest, Gibberish) {
	vector<string> tokens = SplitTextIntoCommands("blahblahblah");
	ASSERT_TRUE(_processor->execute(_player, tokens).size() != 0);
}


}  // namespace
