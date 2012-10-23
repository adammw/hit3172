cmake_minimum_required (VERSION 2.6)
project (Swin-Adventure)

add_definitions(-Wall)
enable_testing()

# The version number
set (SWINADVENTURE_VERSION_MAJOR 0)
set (SWINADVENTURE_VERSION_MINOR 7)

# Set binary output directory
set (EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")

# Options
option (BUILD_DOXYGEN_ALL "Build Doxygen Documentation")

# Decend in subdirs
add_subdirectory(src)
add_subdirectory(test EXCLUDE_FROM_ALL)