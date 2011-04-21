##############################################################
# Copyright (c) 2008-2011 Daniel Pfeifer                     #
#                                                            #
# Distributed under the Boost Software License, Version 1.0. #
##############################################################

cmake_minimum_required(VERSION 2.8.4 FATAL_ERROR)
project(glcc)

add_definitions(
  -DGL_GLEXT_PROTOTYPES
# -std=c++0x
  )

find_package(Boost 1.46 REQUIRED COMPONENTS system NO_MODULE)
include("${Boost_USE_FILE}")

find_package(OpenGL REQUIRED)

include_directories(
  include
  ${CMAKE_SOURCE_DIR}/../Hexapogon/
  )

add_library(glcc
  src/error.cpp
  )

#add_subdirectory(doc EXCLUDE_FROM_ALL)

add_subdirectory(test)
#add_subdirectory(tools)
