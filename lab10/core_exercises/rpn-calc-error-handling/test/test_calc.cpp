/*
 * test_calc.cpp
 *
 *  Created on: 03/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#define BOOST_TEST_MODULE RPN calculator test
#include "boost/test/included/unit_test.hpp"
#include "rpncalculator.h"
#include <string>

BOOST_AUTO_TEST_CASE( test_push )
{
	rpn_calculator *c = new rpn_calculator();
	int actual;

	c->push(1);
	actual = c->answer();

	BOOST_REQUIRE_EQUAL(actual, 1);

	delete c;
}

BOOST_AUTO_TEST_CASE( test_push_multiple )
{
	rpn_calculator *c = new rpn_calculator();
	int actual;

	c->push(1);
	c->push(5);
	actual = c->answer();

	BOOST_REQUIRE_EQUAL(actual, 5);

	actual = c->answer();

	BOOST_REQUIRE_EQUAL(actual, 1);

	delete c;
}


BOOST_AUTO_TEST_CASE( test_add )
{
	rpn_calculator *c = new rpn_calculator();
	int actual;

	c->push(1);
	c->push(1);
	c->add();
	actual = c->answer();

	BOOST_REQUIRE_MESSAGE((2 == actual), "1 + 1 = 2");

	delete c;
}

BOOST_AUTO_TEST_CASE( test_subtract )
{
	rpn_calculator *c = new rpn_calculator();
	int actual;

	c->push(3);
	c->push(2);
	c->subtract();
	actual = c->answer();

	BOOST_REQUIRE_MESSAGE(1 == actual, "3 - 2 = 1");

	delete c;
}

BOOST_AUTO_TEST_CASE( test_multiply )
{
	rpn_calculator *c = new rpn_calculator();
	int actual;

	c->push(5);
	c->push(4);
	c->multiply();
	actual = c->answer();

	BOOST_REQUIRE_MESSAGE(20 == actual, "5 * 4 = 20");

	delete c;
}

BOOST_AUTO_TEST_CASE( test_divide )
{
	rpn_calculator *c = new rpn_calculator();
	int actual;

	c->push(20);
	c->push(4);
	c->divide();
	actual = c->answer();

	BOOST_REQUIRE_MESSAGE(5 == actual, "20 / 4 = 5");

	delete c;
}

BOOST_AUTO_TEST_CASE( test_bomdas )
{
	rpn_calculator *c = new rpn_calculator();
	int actual;

	c->push(1);
	c->push(5);
	c->push(4);
	c->multiply();
	BOOST_CHECK_EQUAL(c->peek_answer(), 20);
	c->push(4);
	c->divide();
	BOOST_CHECK_EQUAL(c->peek_answer(), 5);
	c->add();
	actual = c->answer();

	BOOST_REQUIRE_MESSAGE(6 == actual, "1, 5, 4, *, 4, /, + gives 6");

	delete c;
}

BOOST_AUTO_TEST_CASE( test_add_error )
{
	rpn_calculator *c = new rpn_calculator();
	int actual;
	c->push(1);
	c->add();

	actual = c->answer();
	BOOST_REQUIRE_MESSAGE(actual == 1, "1 should remain on the RPN stack.");
	delete c;
}

BOOST_AUTO_TEST_CASE( test_subtract_error )
{
	rpn_calculator *c = new rpn_calculator();
	int actual;
	c->push(1);
	c->subtract();

	actual = c->answer();
	BOOST_REQUIRE_MESSAGE(actual == 1, "1 should remain on the RPN stack.");
	delete c;
}

BOOST_AUTO_TEST_CASE( test_multiply_error )
{
	rpn_calculator *c = new rpn_calculator();
	int actual;
	c->push(1);
	c->multiply();

	actual = c->answer();
	BOOST_REQUIRE_MESSAGE(actual == 1, "1 should remain on the RPN stack.");
	delete c;
}


BOOST_AUTO_TEST_CASE( test_divide_error )
{
	rpn_calculator *c = new rpn_calculator();
	int actual;
	c->push(1);
	c->divide();

	actual = c->answer();
	BOOST_REQUIRE_MESSAGE(actual == 1, "1 should remain on the RPN stack.");
	delete c;
}
