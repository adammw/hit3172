/*
 * Identifiable.h
 *
 *  Created on: 13/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef IDENTIFIABLE_H_
#define IDENTIFIABLE_H_

#include <string>
#include <vector>

namespace swinadventure {

/**
 * Base class for any Identifiable Object
 */
class Identifiable {
private:
	/** An array of keywords that the object can be identified by */
	std::vector<std::string> _identifiers;
public:
	Identifiable(std::string idents[], size_t length);
	virtual ~Identifiable();

	bool are_you(std::string name);
	std::string first_id();
	void add_identifier(std::string id);
};

} /* namespace swinadventure */
#endif /* IDENTIFIABLE_H_ */
