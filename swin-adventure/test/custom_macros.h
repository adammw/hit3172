/*
 * custom_macros.h
 *
 *  Created on: 15/09/2012
 *      Author: Adam Malcontenti-Wilson
 */

#ifndef CUSTOM_MACROS_H_
#define CUSTOM_MACROS_H_

#include <string>

// std::string Object Comparisons. Converts to C String to compare.
//
//    * {ASSERT|EXPECT}_STREQ(s1, s2):     Tests that s1 == s2
//    * {ASSERT|EXPECT}_STRNE(s1, s2):     Tests that s1 != s2
//    * {ASSERT|EXPECT}_STRCASEEQ(s1, s2): Tests that s1 == s2, ignoring case
//    * {ASSERT|EXPECT}_STRCASENE(s1, s2): Tests that s1 != s2, ignoring case
//
// Don't depend on the order in which the arguments are evaluated,
// which is undefined.
//
// These macros evaluate their arguments exactly once.

#define EXPECT_STROBJEQ(expected, actual) EXPECT_STREQ(std::string(expected).c_str(), std::string(actual).c_str())
#define EXPECT_STROBJNE(s1, s2) EXPECT_STRNE(std::string(s1).c_str(), std::string(s2).c_str())
#define EXPECT_STROBJCASEEQ(expected, actual) EXPECT_STRCASEEQ(std::string(expected).c_str(), std::string(actual).c_str())
#define EXPECT_STROBJCASENE(s1, s2) EXPECT_STRCASENE(std::string(s1).c_str(), std::string(s2).c_str())

#define ASSERT_STROBJEQ(expected, actual) ASSERT_STREQ(std::string(expected).c_str(), std::string(actual).c_str())
#define ASSERT_STROBJNE(s1, s2) ASSERT_STRNE(std::string(s1).c_str(), std::string(s2).c_str())
#define ASSERT_STROBJCASEEQ(expected, actual) ASSERT_STRCASEEQ(std::string(expected).c_str(), std::string(actual).c_str())
#define ASSERT_STROBJCASENE(s1, s2) ASSERT_STRCASEEQ(std::string(s1).c_str(), std::string(s2).c_str())

#endif /* CUSTOM_MACROS_H_ */
