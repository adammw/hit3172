#include <iostream>
#include "config.h"

#include "GameObject.h"
 
using namespace std;
using namespace swinadventure;

int main (int argc, char *argv[])
{
	cout << argv[0] << " Version " << SWINADVENTURE_VERSION_MAJOR << '.' << SWINADVENTURE_VERSION_MINOR << endl;

	string idents[2] = {"gem", "ruby"};
	GameObject* gameObj = new GameObject(idents, 2, "blood-red ruby", "The small blood-red ruby is dulled from the years of wear");
	cout << "Game Object name: " << std::string(gameObj->get_name()).c_str() << endl;
	cout << "Game Object short desc: " << gameObj->get_short_description() << endl;
	cout << "Game Object long desc: " << gameObj->get_full_description() << endl;
	return 0;
}
