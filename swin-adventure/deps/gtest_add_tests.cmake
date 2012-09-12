#=============================================================================
# Copyright 2009 Kitware, Inc.
# Copyright 2009 Philip Lowman <philip@yhbt.com>
# Copyright 2009 Daniel Blezek <blezek@gmail.com>
#
# Distributed under the OSI-approved BSD License (the "License");
# see accompanying file Copyright.txt for details.
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#=============================================================================
# (To distribute this file outside of CMake, substitute the full
#  License text for the above reference.)
#
# Thanks to Daniel Blezek <blezek@gmail.com> for the GTEST_ADD_TESTS code
#
# If you would like each Google test to show up in CTest as
# a test you may use the following macro.
# NOTE: It will slow down your tests by running an executable
# for each test and test fixture.  You will also have to rerun
# CMake after adding or removing tests or test fixtures.
#
# GTEST_ADD_TESTS(executable extra_args ARGN)
#    executable = The path to the test executable
#    extra_args = Pass a list of extra arguments to be passed to
#                 executable enclosed in quotes (or "" for none)
#    ARGN =       A list of source files to search for tests & test
#                 fixtures.
#
#  Example:
#     set(FooTestArgs --foo 1 --bar 2)
#     add_executable(FooTest FooUnitTest.cc)
#     GTEST_ADD_TESTS(FooTest "${FooTestArgs}" FooUnitTest.cc)

function(GTEST_ADD_TESTS executable extra_args)
    if(NOT ARGN)
        message(FATAL_ERROR "Missing ARGN: Read the documentation for GTEST_ADD_TESTS")
    endif()
    foreach(source ${ARGN})
        file(READ "${source}" contents)
        string(REGEX MATCHALL "TEST_?F?\\(([A-Za-z_0-9 ,]+)\\)" found_tests ${contents})
        foreach(hit ${found_tests})
            string(REGEX REPLACE ".*\\( *([A-Za-z_0-9]+), *([A-Za-z_0-9]+) *\\).*" "\\1.\\2" test_name ${hit})
            add_test(${test_name} ${executable} --gtest_filter=${test_name} ${extra_args})
        endforeach()
    endforeach()
endfunction()