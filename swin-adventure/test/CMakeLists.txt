# Compile GTest
add_subdirectory("${PROJECT_SOURCE_DIR}/deps/gtest" "${PROJECT_BINARY_DIR}/deps/gtest")
include("${PROJECT_SOURCE_DIR}/deps/gtest_add_tests.cmake")

# All of the tests themselves
set(TESTSRC
    #Controller
    #controller.cpp

    # Test the whole
    test_main.cc
)

# Test libraries to link against
set(TESTLIBS ${LIBS}
    gtest
    gtest_main
)

include_directories("${gtest_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/src")


# Emulate make check
add_custom_target(check COMMAND swinadventure_tests)

# The binaries to be built:
add_executable(swinadventure_tests ${TESTSRC})
add_dependencies(swinadventure_tests gtest)
add_dependencies(check swinadventure_tests)

# Link against LIBS
target_link_libraries(swinadventure_tests ${TESTLIBS})

# Hack to make `make test` work... just.
add_test("Building.Tests" "${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target swinadventure_tests)
GTEST_ADD_TESTS("${EXECUTABLE_OUTPUT_PATH}/swinadventure_tests" "" ${TESTSRC})

