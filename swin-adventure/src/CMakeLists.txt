# add a target to generate API documentation with Doxygen
find_package(Doxygen)

if(DOXYGEN_FOUND)
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
        ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        @ONLY
    )
    if (BUILD_DOXYGEN_ALL)
        add_custom_target(doc ALL
            ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
            WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen" VERBATIM
        )
    else()
        add_custom_target(doc 
            ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
            WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen" VERBATIM
        )
    endif(BUILD_DOXYGEN_ALL)
endif(DOXYGEN_FOUND)


# All source files we need to compile the application:
set(SWINADVENTURE_SRC
    GameObject.cpp
    Identifiable.cpp
    Item.cpp
    Inventory.cpp
    Player.cpp
    Command.cpp
    LookCommand.cpp
    Bag.cpp
    Location.cpp
)
set(SRC ${SWINADVENTURE_SRC}
    main.cpp
)
# Libraries to link against
set(LIBS ${LIBS}
    # None yet
)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
    ./config.h.in
    "${PROJECT_BINARY_DIR}/config.h"
    @ONLY
)

# add the binary tree to the search path for include files
# so that we will find config.h
include_directories("${PROJECT_BINARY_DIR}")

# The binaries to be built:
add_library(libswinadventure ${SWINADVENTURE_SRC})
add_executable(swinadventure ${SRC})

# Link against LIBS
target_link_libraries(swinadventure libswinadventure)
target_link_libraries(swinadventure ${LIBS})

# Install rules
install(TARGETS swinadventure DESTINATION ${PROJECT_BINARY_DIR}/bin)
install(FILES "${PROJECT_BINARY_DIR}/config.h" DESTINATION ${PROJECT_BINARY_DIR}/include)