##
# Require CMAKE 3.7.1 at least
##
cmake_minimum_required (VERSION 3.7.1 FATAL_ERROR)

###############################################################################
#                                                                             #
#                           COMPILER FLAGS                                    #
#                                                                             #
###############################################################################

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11")

###############################################################################
#                                                                             #
#                           THIRD PARTY RESOURCES                             #
#                                                                             #
###############################################################################

set(BOOST_INCLUDE_DIRS
    "/usr/local/boost_installed/include"
    CACHE
    PATH
    "The path to the Boost header files."
)

################################################################################
#                                                                              #
#                              PROJECT VARIABLES                               #
#                                                                              #
################################################################################

project(CallCentre CXX)

set (CALLCENTRE_VERSION_MAJOR 1)
set (CALLCENTRE_VERSION_MINOR 0)

################################################################################
#                                                                              #
#                              SUB PROJECTS                                    #
#                                                                              #
################################################################################

################################################################################
#                                                                              #
#                              CONFIGURE TARGET                                #
#                                                                              #
################################################################################

# Header files #

set(CALLCENTRE_HEADER_DIR
    ${PROJECT_SOURCE_DIR}/src/include/main
)

include_directories (${CALLCENTRE_HEADER_DIR})

# Implementation files #

file(GLOB CALLCENTRE_SRC_FILES
          ${PROJECT_SOURCE_DIR}/src/C++/main/*.cpp
)

# Define target executable #

add_executable(${PROJECT_NAME}
               ${CALLCENTRE_SRC_FILES}
)

################################################################################
#                                                                              #
#                              CUSTOM OPTIONS                                  #
#                                                                              #
################################################################################

################################################################################
#                                                                              #
#                              CONFIGURE TEMPLATES                             #
#                                                                              #
################################################################################

###############################################################################
#                                                                             #
#                           GENERATE DOCUMENTATION                            #
#                                                                             #
###############################################################################

# Add a target to generate API documentation with Doxygen
find_package(Doxygen)

if(DOXYGEN_FOUND)
  configure_file(
      ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
      ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY
  )

  add_custom_target(doc
                    ${DOXYGEN_EXECUTABLE} "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile"
                    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                    COMMENT "Generating API documentation with Doxygen"
                    VERBATIM
  )
endif()

################################################################################
#                                                                              #
#                              INSTALLATION RULES                              #
#                                                                              #
################################################################################

# Install all includes #
install(
  DIRECTORY ${CALLCENTRE_HEADER_DIR}
  DESTINATION include
)

# Install target executable #
install(
  TARGETS ${PROJECT_NAME}
  DESTINATION bin
)

# Install documentation #
if(EXISTS ${PROJECT_BINARY_DIR}/doc)
  install(
    DIRECTORY ${CMAKE_BINARY_DIR}/doc
    DESTINATION doc
  )
endif()

################################################################################
#                                                                              #
#                              CPACK & PUBLISHING                              #
#                                                                              #
################################################################################

# Build a CPack driven installer package
include (InstallRequiredSystemLibraries)

set (CPACK_RESOURCE_FILE_LICENSE
     "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE"
)

set (CPACK_PACKAGE_VERSION_MAJOR
     "${CALLCENTRE_VERSION_MAJOR}"
)

set (CPACK_PACKAGE_VERSION_MINOR
     "${CALLCENTRE_VERSION_MINOR}"
)

include (CPack)
