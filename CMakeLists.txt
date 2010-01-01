##############################################################
# Copyright (c) 2008-2009 Daniel Pfeifer                     #
#                                                            #
# Distributed under the Boost Software License, Version 1.0. #
##############################################################

cmake_minimum_required(VERSION 2.6.0 FATAL_ERROR)
project(glcc)

set(CMAKE_BUILD_TYPE "Debug")
#add_definitions(-std=c++0x)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

set(Boost_USE_STATIC_LIBS   ON)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.38.0 REQUIRED
  COMPONENTS filesystem system program_options)

##############################################################

#set(BUILD_QUICKBOOK "ON")
#add_executable(quickbook
#  ${CMAKE_SOURCE_DIR}/tools/quickbook/detail/quickbook.cpp
#  ${CMAKE_SOURCE_DIR}/tools/quickbook/detail/actions.cpp
#  ${CMAKE_SOURCE_DIR}/tools/quickbook/detail/actions_class.cpp
#  ${CMAKE_SOURCE_DIR}/tools/quickbook/detail/utils.cpp
#  ${CMAKE_SOURCE_DIR}/tools/quickbook/detail/post_process.cpp
#  ${CMAKE_SOURCE_DIR}/tools/quickbook/detail/collector.cpp
#  ${CMAKE_SOURCE_DIR}/tools/quickbook/detail/template_stack.cpp
#  )
#target_link_libraries(quickbook ${Boost_LIBRARIES})

##############################################################

#include(tools/BoostDocs.cmake)
#include(tools/BoostUtils.cmake)

#set(OPENCL_ROOT $ENV{ATISTREAMSDKROOT})
#find_package(OpenCL REQUIRED)
find_package(OpenGL REQUIRED)
add_definitions(-DGL3_PROTOTYPES=1)

include_directories(
  include
  ${Boost_INCLUDE_DIRS}
# ${OPENCL_INCLUDE_DIR}
  )

add_library(alcc
  src/alcc/error.cpp
  )

add_library(glcc
  src/glcc/error.cpp
  src/glcc/link.cpp
  )

#add_subdirectory(doc)
add_subdirectory(test)

