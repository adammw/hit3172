/*
 * CommandProcessor.h
 *
 *  Created on: 09/10/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Command.h"
#include <string>
#include <vector>

#ifndef COMMANDPROCESSOR_H_
#define COMMANDPROCESSOR_H_

namespace swinadventure {

class CommandProcessor {
private:
	std::vector<Command*> _commands;
	std::vector<std::string> _not_found_sayings;

public:
	CommandProcessor();
	virtual ~CommandProcessor();

	std::string execute(Player* p, std::vector<std::string> text);
};

} /* namespace swinadventure */
#endif /* COMMANDPROCESSOR_H_ */
