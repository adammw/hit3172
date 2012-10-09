/*
 * CommandProcessor.cpp
 *
 *  Created on: 09/10/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "MoveCommand.h"
#include "LookCommand.h"
#include "CommandProcessor.h"
#include <sstream>
#include <algorithm>
#include <iostream>

namespace swinadventure {

using namespace std;

CommandProcessor::CommandProcessor() {
	_commands.push_back(new MoveCommand);
	_commands.push_back(new LookCommand);

	_not_found_sayings.push_back("I don't understand");
	_not_found_sayings.push_back("What'chu talkin' 'bout, Willis?");
	_not_found_sayings.push_back("Huh?");
	_not_found_sayings.push_back("I'm not Siri");
}

CommandProcessor::~CommandProcessor() {
	for(vector<Command*>::iterator it = _commands.begin(); it != _commands.end(); ++it) {
		Command* cmd = *it;
		delete cmd;
	}
}

/**
 * Execute a command
 * @param p		A pointer to the player object
 * @param text	A vector of strings indexed by space separation
 * @return
 */
std::string CommandProcessor::execute( Player* p, std::vector<std::string> text ) {
	// Execute the first found command that matches "are you"
	for(vector<Command*>::iterator it = _commands.begin(); it != _commands.end(); ++it) {
		Command* cmd = *it;
		if (cmd->are_you(text[0])) {
			return cmd->execute(p, text);
		}
	}

	// Send back a random saying
	return _not_found_sayings[rand() % _not_found_sayings.size()];
}

} /* namespace swinadventure */
