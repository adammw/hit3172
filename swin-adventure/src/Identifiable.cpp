/*
 * Identifiable.cpp
 *
 *  Created on: 13/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include <algorithm>

#include "Identifiable.h"

namespace swinadventure {

using namespace std;

/**
 * Constructor for Identifiable object
 * @param idents array of strings to identify object as
 * @param length length of array
 */
Identifiable::Identifiable(string idents[], size_t length) {
	_identifiers.reserve(length);
	for (size_t i = 0; i < length; i++ ){
		// Convert identifier to lowercase
		transform(idents[i].begin(), idents[i].end(), idents[i].begin(), ::tolower);
		_identifiers.push_back(idents[i]);
	}
}

Identifiable::~Identifiable() {
	// TODO Auto-generated destructor stub
}

/**
 * Test if the object is identified by name
 * @param name
 * @return true if name is one of the object's identifiers
 */
bool Identifiable::are_you(string name) {
	// Convert input to lowercase
	transform(name.begin(), name.end(), name.begin(), ::tolower);

	// Check each identifier for a match
	for (vector<string>::iterator it = _identifiers.begin(); it != _identifiers.end(); ++it) {
		if (it->compare(name) == 0)
			return true;
	}

	return false;
}

/**
 * Get the first (primary) identifier
 * @return
 */
string Identifiable::first_id() {
	return _identifiers[0];
}

/**
 * Add an identifier to the identifiable object
 * @param id
 */
void Identifiable::add_identifier(string id) {
	_identifiers.push_back(id);
}

} /* namespace swinadventure */
