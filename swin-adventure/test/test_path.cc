/*
 * test_path.cc
 *
 *  Created on: 25/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "gtest/gtest.h"
#include "custom_macros.h"

#include "Location.h"
#include "Path.h"
#include "Inventory.h"
#include <sstream>

namespace {

using namespace swinadventure;
using namespace std;

// The fixture for testing Paths
class PathTest : public ::testing::Test {
 protected:

	PathTest() {
		std::string idents[] = {"up" /* paths[0] */, "down" /* paths[1] */, "dungeon" /* location[0] */, "field" /* location[1] */ };

		// Create paths
		_paths[0] = new Path(idents, 1, "Crawl through the grate", "You somehow manage to crawl your way through the grate");
		ASSERT_TRUE(NULL != _paths[0]);

		_paths[1] = new Path(idents + 1, 1, "Jump down the hole", "There's a hole in the ground that seems to lead somewhere");
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
	}

	virtual ~PathTest() {
		for(int i=0;i<2;i++)
		    delete _locations[i];
		delete _player;
	}

	// Objects declared here can be used by all tests in the test case for Foo.
	Location* _locations[2];
	Path* _paths[2];
	Player* _player;
};

/**
 * Check the path can be identified directly
 */
TEST_F(PathTest, Identifiable) {
	ASSERT_TRUE(_paths[0]->are_you("up"));
	ASSERT_FALSE(_paths[1]->are_you("up"));
	ASSERT_FALSE(_paths[0]->are_you("down"));
	ASSERT_TRUE(_paths[1]->are_you("down"));
}

/**
 * Check the path can be located by a location
 */
TEST_F(PathTest, LocationLocate) {
	ASSERT_EQ(_paths[0], _locations[0]->locate("up"));
	ASSERT_EQ(NULL, _locations[0]->locate("down"));
	ASSERT_EQ(_paths[1], _locations[1]->locate("down"));
	ASSERT_EQ(NULL, _locations[1]->locate("up"));
}

/**
 * Check the path can be located by a player
 * in the location
 */
TEST_F(PathTest, PlayerLocate) {
	ASSERT_EQ(_paths[0], _player->locate("up"));
	ASSERT_EQ(NULL, _player->locate("down"));
	_player->set_location(_locations[1]);
	ASSERT_EQ(_paths[1], _player->locate("down"));
	ASSERT_EQ(NULL, _player->locate("up"));
}

/**
 * Check the path can move a player
 */
TEST_F(PathTest, CanMovePlayer) {
	ASSERT_EQ(_locations[0], _player->get_location());
	GameObject* obj = _player->locate("up");
	ASSERT_TRUE(NULL != obj);
	Path* path = dynamic_cast<Path*>(obj);
	ASSERT_TRUE(NULL != path);
	path->move_player(_player);
	ASSERT_EQ(_locations[1], _player->get_location());
	obj = _player->locate("down");
	ASSERT_TRUE(NULL != obj);
	path = dynamic_cast<Path*>(obj);
	ASSERT_TRUE(NULL != path);
	path->move_player(_player);
	ASSERT_EQ(_locations[0], _player->get_location());
}


}  // namespace
