/*
 * Command.h
 *
 *  Created on: 16/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include "Identifiable.h"
#include "Player.h"
#include <string>
#include <vector>

namespace swinadventure {

/**
 * Abstract Command Interface Base Class,
 * implemented as a C++ virtual class
 * The constructor is non-virtual
 *
 * This class should not be instantiated directly,
 * instead use one of the subclasses
 */
class Command: public Identifiable {
public:
	Command( std::string ids[], size_t idlen );
	virtual ~Command();

	virtual std::string execute( Player *p, std::vector<std::string> text) = 0;
};

} /* namespace swinadventure */
#endif /* COMMAND_H_ */
