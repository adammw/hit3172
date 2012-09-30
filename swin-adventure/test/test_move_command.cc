/*
 * test_move_command.cc
 *
 *  Created on: 25/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "gtest/gtest.h"
#include "custom_macros.h"

#include "MoveCommand.h"
#include "Player.h"
#include "Path.h"
#include "Location.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

namespace {

using namespace swinadventure;
using namespace std;

// The fixture for testing Move Commands
class MoveCommandTest : public ::testing::Test {
 protected:

	MoveCommandTest() {
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

		// Create new MoveCommand
		_moveCommand = new MoveCommand;
	}

	virtual ~MoveCommandTest() {
		for(int i=0;i<2;i++)
			delete _locations[i];
		delete _player;
		delete _moveCommand;
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
	MoveCommand* _moveCommand;
};

/**
 * Check player can move down paths that exist
 */
TEST_F(MoveCommandTest, MoveSomewhere) {
	ASSERT_EQ(_locations[0], _player->get_location());
	vector<string> tokens = SplitTextIntoCommands("move up");
	string r = _moveCommand->execute(_player, tokens);
	ASSERT_EQ(_locations[1], _player->get_location());
	ASSERT_STROBJEQ(_paths[0]->get_outcome(), r);

	tokens = SplitTextIntoCommands("go down");
	r = _moveCommand->execute(_player, tokens);
	ASSERT_EQ(_locations[0], _player->get_location());
	ASSERT_STROBJEQ(_paths[1]->get_outcome(), r);
}

/**
 * Check players cannot move down paths that don't exist
 */
TEST_F(MoveCommandTest, MoveNowhere) {
	ASSERT_EQ(_locations[0], _player->get_location());
	vector<string> tokens = SplitTextIntoCommands("move down");
	string r = _moveCommand->execute(_player, tokens);
	ASSERT_EQ(_locations[0], _player->get_location());
	ASSERT_STROBJEQ("I can't find down", r);
}

}  // namespace
