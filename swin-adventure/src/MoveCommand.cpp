/*
 * MoveCommand.cpp
 *
 *  Created on: 25/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "MoveCommand.h"
#include "Location.h"
#include "GameObject.h"
#include "Path.h"
#include <sstream>

namespace swinadventure {

using namespace std;

string MoveCommand::_default_identifiers[] = {"move", "go"};

MoveCommand::MoveCommand() {
	// TODO Auto-generated constructor stub

}

MoveCommand::~MoveCommand() {
	// TODO Auto-generated destructor stub
}

/**
 * Extract the path name from the text
 * @param p
 * @param text
 * @return the path name or an empty string when parsing fails
 */
string MoveCommand::path_name(vector<string> text) {
	// Only accept the form "move xxx"
	if (text.size() != 2)
		return "";

	return text[1];
}


/**
 * Attempt to locate the Path object specified
 * @param p
 * @param text
 * @return a pointer to the path object or NULL
 */
Path* MoveCommand::locate_path(Player* p, vector<string> text) {
	string name = path_name(text);
	if (!name.size())
		return NULL;

	// Get a path from the player
	GameObject* obj = p->locate(name);
	Path* path = dynamic_cast<Path*>(obj);
	return path;
}

/**
 * Execute the move command
 * @param p		Player object pointer
 * @param text
 * @return
 */
string MoveCommand::execute(Player* p, vector<string> text) {
	ostringstream result;
	Path* path = locate_path(p, text);
	if (path == NULL) {
		string name = path_name(text);
		if (name.size()) {
			result << "I can't find " << path_name(text);
		} else {
			result << "I don't know where to go";
		}
	} else {
		path->move_player(p);
		result << path->get_description();
	}
}

} /* namespace swinadventure */
