##############################################################
# Copyright (c) 2008-2009 Daniel Pfeifer                     #
#                                                            #
# Distributed under the Boost Software License, Version 1.0. #
##############################################################

cmake_minimum_required(VERSION 2.8.0 FATAL_ERROR)
project(glcc)

set(CMAKE_BUILD_TYPE "Debug")
#add_definitions(-std=c++0x)

set(CTOOLBOX_USE_FILE ${CMAKE_BINARY_DIR}/UseCToolBox.cmake)
file(DOWNLOAD
  http://github.com/purpleKarrot/CToolBox/raw/master/UseCToolBox.cmake
  ${CTOOLBOX_USE_FILE})
include(${CTOOLBOX_USE_FILE})

include(${CMAKE_SOURCE_DIR}/gl3w.cmake)

set(Boost_USE_STATIC_LIBS   ON)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.40 REQUIRED COMPONENTS system)

find_package(OpenGL REQUIRED)

include(Extract)
extract(${CMAKE_SOURCE_DIR}/include/boost-la.zip ${CMAKE_BINARY_DIR}/include)

include_directories(
  include
  ${CMAKE_BINARY_DIR}/include
  ${Boost_INCLUDE_DIRS}
  )

add_library(gl3w ${CMAKE_BINARY_DIR}/src/gl3w.c)
add_library(glcc src/error.cpp)

set(THIS_PROJECT_NAME glcc)
include(AddReference)
include(AddDocumentation)
add_subdirectory(doc EXCLUDE_FROM_ALL)

add_subdirectory(test)
add_subdirectory(tools)
