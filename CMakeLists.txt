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

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

set(Boost_USE_STATIC_LIBS   ON)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.40 REQUIRED COMPONENTS system)

find_package(OpenGL REQUIRED)
add_definitions(-DGL3_PROTOTYPES=1)

include(Extract)
extract(${CMAKE_SOURCE_DIR}/include/boost-la.zip ${CMAKE_BINARY_DIR}/include)

set(GLEXT_DIRECTORY ${CMAKE_BINARY_DIR}/include/glcc/ext)
macro(DOWNLOAD_GLEXT FILE)
  if(NOT EXISTS ${GLEXT_DIRECTORY}/${FILE})
    file(DOWNLOAD http://www.opengl.org/registry/api/${FILE}
      ${GLEXT_DIRECTORY}/${FILE})
  endif(NOT EXISTS ${GLEXT_DIRECTORY}/${FILE})
endmacro(DOWNLOAD_GLEXT FILE)
download_glext(glext.h)
download_glext(glxext.h)
download_glext(wglext.h)

include_directories(
  include
  ${CMAKE_BINARY_DIR}/include
  ${Boost_INCLUDE_DIRS}
  )

add_library(glcc
  src/glcc/error.cpp
  src/glcc/link.cpp
  )

#add_subdirectory(doc)
add_subdirectory(test)
#add_subdirectory(tools)
