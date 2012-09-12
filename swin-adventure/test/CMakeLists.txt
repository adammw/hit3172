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

# The binaries to be built:
add_executable(swinadventure_tests ${TESTSRC})

# Link against LIBS
target_link_libraries(swinadventure_tests ${TESTLIBS})

# Declare tests (delegate to testing framework)
GTEST_ADD_TESTS("${EXECUTABLE_OUTPUT_PATH}/swinadventure_tests" "" ${TESTSRC})
#add_test(RunUnitTests "${EXECUTABLE_OUTPUT_PATH}/swinadventure_tests")

