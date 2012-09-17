#include <iostream>
#include "config.h"

#include "Player.h"
#include "Item.h"
#include "Inventory.h"
#include "LookCommand.h"
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

	std::string input;
	bool running = true;

	// Loop reading commands from user
	while(running) {
		cout << "> ";
		getline(cin, input);

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
		LookCommand* lookCmd = new LookCommand;
		cout << lookCmd->execute(p, tokens) << endl << endl;
	}

	// Free objects
	delete p;
	return 0;
}
