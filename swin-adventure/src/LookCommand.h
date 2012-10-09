/*
 * LookCommand.h
 *
 *  Created on: 16/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef LOOKCOMMAND_H_
#define LOOKCOMMAND_H_

#include "Command.h"
#include "Player.h"
#include "IHaveInventory.h"

namespace swinadventure {

/**
 * Look Command class
 */
class LookCommand: public swinadventure::Command {
private:
	/** Default identifiers for the look command */
	static const std::string _default_identifiers[3];

	std::string object_name( std::vector<std::string> text );
	std::string container_name( std::vector<std::string> text );
	IHaveInventory* locate_container( Player* p, std::vector<std::string> text );
	std::string look_at( GameObject* obj );
	std::string look_at_in( std::string id, IHaveInventory *container );
	bool is_here( std::string id );
public:
	LookCommand();
	virtual ~LookCommand();

	virtual std::string execute( Player* p, std::vector<std::string> text );
};

} /* namespace swinadventure */
#endif /* LOOKCOMMAND_H_ */
