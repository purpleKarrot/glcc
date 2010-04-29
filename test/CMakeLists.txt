##############################################################
# Copyright (c) 2008-2009 Daniel Pfeifer                     #
#                                                            #
# Distributed under the Boost Software License, Version 1.0. #
##############################################################

include(AddTestModule)

find_package(Boost 1.40.0 REQUIRED
  COMPONENTS unit_test_framework)

##############################################################

set(SDLDIR /usr/local/)
find_package(SDL REQUIRED)
include_directories(${SDL_INCLUDE_DIR})

add_library(GL3Context GL3Context.cpp)

##############################################################

file(GLOB_RECURSE GLCC_TEST_SRC glcc/*.cpp)
add_test_module(glcc_test ${GLCC_TEST_SRC})

target_link_libraries(glcc_test
  GL3Context
  ${SDL_LIBRARY}
  ${Boost_LIBRARIES}
  ${OPENGL_LIBRARIES}
  GLEW
  )

##############################################################

#file(GLOB_RECURSE CLCC_TEST_SRC clcc/*.cpp)
#add_test_module(clcc_test ${CLCC_TEST_SRC})

