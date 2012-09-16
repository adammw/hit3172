#include <iostream>
#include "config.h"

#include "Player.h"
#include "Inventory.h"
 
using namespace std;
using namespace swinadventure;

int main (int argc, char *argv[])
{
	cout << argv[0] << " Version " << SWINADVENTURE_VERSION_MAJOR << '.' << SWINADVENTURE_VERSION_MINOR << endl;

	Player* p = new Player("Test Player", "A player used for testing");
	Inventory* pi = p->get_inventory();

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

	// Locate items
	cout << "=== Player description ===" << endl;
	cout << p->get_full_description() << endl;

	// Free objects
	delete p;
	return 0;
}
