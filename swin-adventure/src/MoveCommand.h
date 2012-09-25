/*
 * MoveCommand.h
 *
 *  Created on: 25/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef MOVECOMMAND_H_
#define MOVECOMMAND_H_

#include "Command.h"
#include <vector>

namespace swinadventure {

/**
 * Move command class, allows a player to move down a path
 */
class MoveCommand: public Command {
private:
	/** Default identifiers for the look command */
	static const std::string _default_identifiers[2];

	std::string path_name(std::vector<std::string> text);
	Path* locate_path(Player* p, std::vector<std::string> text);
public:
	MoveCommand();
	virtual ~MoveCommand();

	std::string execute(Player* p, std::vector<std::string> text);
};

} /* namespace swinadventure */
#endif /* MOVECOMMAND_H_ */
