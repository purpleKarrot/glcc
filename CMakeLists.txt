##############################################################
# Copyright (c) 2008-2009 Daniel Pfeifer                     #
#                                                            #
# Distributed under the Boost Software License, Version 1.0. #
##############################################################

cmake_minimum_required(VERSION 2.6.0 FATAL_ERROR)
project(glcc)

set(CMAKE_BUILD_TYPE "Debug")
#add_definitions(-std=c++0x)

find_package(Boost 1.37.0 REQUIRED
  COMPONENTS filesystem system program_options)

##############################################################
# Fetch Boost documentation tools from svn                   #
##############################################################
find_package(Subversion REQUIRED)

if(NOT EXISTS ${CMAKE_SOURCE_DIR}/doc/src)
  execute_process(COMMAND ${Subversion_SVN_EXECUTABLE} checkout
    http://svn.boost.org/svn/boost/trunk/doc/src/
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/doc/)
endif(NOT EXISTS ${CMAKE_SOURCE_DIR}/doc/src)

if(NOT EXISTS ${CMAKE_SOURCE_DIR}/tools/boostbook)
  execute_process(COMMAND ${Subversion_SVN_EXECUTABLE} checkout
    http://svn.boost.org/svn/boost/trunk/tools/boostbook/
    WORKING_DIRECTORY  ${CMAKE_SOURCE_DIR}/tools/)
endif(NOT EXISTS ${CMAKE_SOURCE_DIR}/tools/boostbook)

if(NOT EXISTS ${CMAKE_SOURCE_DIR}/tools/quickbook)
  execute_process(COMMAND ${Subversion_SVN_EXECUTABLE} checkout
    http://svn.boost.org/svn/boost/tags/release/Boost_1_37_0/tools/quickbook/
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/tools/)
endif(NOT EXISTS ${CMAKE_SOURCE_DIR}/tools/quickbook)

set(BUILD_QUICKBOOK "ON")
add_executable(quickbook
  ${CMAKE_SOURCE_DIR}/tools/quickbook/detail/quickbook.cpp
  ${CMAKE_SOURCE_DIR}/tools/quickbook/detail/actions.cpp
  ${CMAKE_SOURCE_DIR}/tools/quickbook/detail/actions_class.cpp
  ${CMAKE_SOURCE_DIR}/tools/quickbook/detail/utils.cpp
  ${CMAKE_SOURCE_DIR}/tools/quickbook/detail/post_process.cpp
  ${CMAKE_SOURCE_DIR}/tools/quickbook/detail/collector.cpp
  ${CMAKE_SOURCE_DIR}/tools/quickbook/detail/template_stack.cpp
  )
target_link_libraries(quickbook ${Boost_LIBRARIES})

##############################################################

include(tools/BoostDocs.cmake)
include(tools/BoostUtils.cmake)

find_package(OpenGL REQUIRED)

include_directories(
  include
  ${Boost_INCLUDE_DIRS}
  )

add_subdirectory(doc)
add_subdirectory(test)
