#include <iostream>
#include "config.h"

#include "Player.h"
#include "Item.h"
#include "Inventory.h"
#include "Location.h"
#include "Path.h"
#include "CommandProcessor.h"
#include "Bag.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>


using namespace std;
using namespace swinadventure;

int main (int argc, char *argv[])
{
	cout << argv[0] << " Version " << SWINADVENTURE_VERSION_MAJOR << '.' << SWINADVENTURE_VERSION_MINOR << endl << endl;

	std::string player_name;
	std::string player_description;

	// Get the player's name and description from the user
	cout << "Player Name: ";
	cin >> player_name;
	cout << "Player Description: ";
	cin >> player_description;

	// Use these details to create a Player object.
	Player* p = new Player(player_name, player_description);
	Inventory* pi = p->get_inventory();

	// Create some sample items
	std::string idents1[2] = {"crowbar", "bar"};
	Item* i = new Item(idents1, 2, "large steel crowbar", "The crowbar has signs of rust and heavy wear, but still works fine");
	pi->put(i);

	std::string idents2[1] = {"hammer"};
	i = new Item(idents2, 1, "cheap nasty hammer", "The hammer is very new - still has it's original sale stickers on it, but looks like it might break");
	pi->put(i);

	// Create a bag
	std::string idents3[1] = {"bag"};
	Bag* b = new Bag(idents3, 1, "bag of loot", "Small bag for your loot");
	pi->put(b);

	// Create item to inside bag
	std::string idents4[2] = {"gem", "ruby"};
	i = new Item(idents4, 2, "small blood-red ruby", "The small blood-red ruby is dulled from the years of wear");
	b->get_inventory()->put(i);

	std::string idents[] = {"up" /* paths[0] */, "down" /* paths[1] */, "dungeon" /* location[0] */, "field" /* location[1] */ };

	// Create paths
	Path* paths[2];
	paths[0] = new Path(idents, 1, "Crawl through the grate", "The grate has an opening that looks just large enough to crawl through", "After much squeezing, you somehow manage to crawl your way through the grate and end up outside in a field");
	paths[1] = new Path(idents + 1, 1, "Jump down the hole", "There's a hole in the ground that seems to lead somewhere", "You start to climb down but slip and slide down a dirty hole, ending up somewhere cold and damp");

	// Create locations
	Location* locations[2];
	locations[0] = new Location(idents + 2, 1, "Dungeon", "A small damn spot, with chains locking you to the wall, a small grate allows some light in");
	locations[1] = new Location(idents + 3, 1, "A Field", "A large green field");

	// Link paths and locations
	paths[0]->set_end_location(locations[1]);
	locations[0]->add_path(paths[0]);
	paths[1]->set_end_location(locations[0]);
	locations[1]->add_path(paths[1]);

	// Start player in location
	p->set_location(locations[0]);

	std::string input;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();
	bool running = true;

	// Loop reading commands from user
	while(running) {
		cout << "> ";
		getline(cin, input);
		if (input.size() == 0)
			continue;

		// Split string into vector
		istringstream iss(input);
		vector<string> tokens;
		copy(istream_iterator<string>(iss),
		         istream_iterator<string>(),
		         back_inserter<vector<string> >(tokens));

		if (tokens[0].compare("quit") == 0) {
			running = false;
			break;
		}

		// Execute Look Command
		CommandProcessor* cmdProcessor = new CommandProcessor;
		cout << cmdProcessor->execute(p, tokens) << endl << endl;
	}

	// Free objects
	delete p;
	return 0;
}
