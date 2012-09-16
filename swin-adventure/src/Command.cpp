/*
 * Command.cpp
 *
 *  Created on: 16/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include "Command.h"

namespace swinadventure {

using namespace std;

Command::Command(string ids[], size_t idlen ) : Identifiable(ids, idlen) {};

Command::~Command() {};

}
