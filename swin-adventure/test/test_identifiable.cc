/*
 * test_identifiable.cc
 *
 *  Created on: 13/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#include <string>

#include "gtest/gtest.h"

#include "Identifiable.h"

namespace {

using namespace swinadventure;

// The fixture for testing Identifiable Objects
class IdentifiableTest : public ::testing::Test {
 protected:

	IdentifiableTest() {
		std::string idents[2] = {"gem", "ruby"};
		_identObj = new Identifiable(idents, 2);
	}

	virtual ~IdentifiableTest() {
		delete _identObj;
	}

	// Objects declared here can be used by all tests in the test case for Foo.
	Identifiable* _identObj;
};

/**
 * Check you can create an identifiable object with a list of identifiers.
 */
TEST_F(IdentifiableTest, CanCreate) {
	ASSERT_TRUE(_identObj != NULL);
}

/**
 * Check that it responds "True" to the "Are You" message where the request
 * matches one of the object's identifiers.
 */
TEST_F(IdentifiableTest, AreYou) {
	ASSERT_TRUE(_identObj->are_you("gem"));
	ASSERT_TRUE(_identObj->are_you("ruby"));
}

/**
 * Check that it responds "False" to the "Are You" message where the request
 * does not match one of the object's identifiers.
 */
TEST_F(IdentifiableTest, NotAreYou) {
	ASSERT_FALSE(_identObj->are_you("fred"));
	ASSERT_FALSE(_identObj->are_you("bob"));
}

/**
 * Check that it responds "True" to the "Are You" message where the request
 * matches one of the object's identifiers where there is a mismatch in case.
 */
TEST_F(IdentifiableTest, AreYouCaseInsensitive) {
	ASSERT_TRUE(_identObj->are_you("GeM"));
	ASSERT_TRUE(_identObj->are_you("rUBY"));
}

/**
 * Check that the first id returns the first identifier in the list of
 * identifiers.
 */
TEST_F(IdentifiableTest, FirstID) {
	ASSERT_STREQ(_identObj->first_id().c_str(), "gem");
}

/**
 * Check that you can add identifiers to the object
 */
TEST_F(IdentifiableTest, AddID) {
	ASSERT_FALSE(_identObj->are_you("rock"));
	_identObj->add_identifier("rock");
	ASSERT_TRUE(_identObj->are_you("rock"));
}

}  // namespace

