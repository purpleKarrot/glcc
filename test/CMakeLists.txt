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

##############################################################

add_test_module(glcc_test detail/GL3Context.cpp
  blend.cpp
  depth.cpp
  extensions.cpp
  hint.cpp
  info.cpp
  logic.cpp
  )

target_link_libraries(glcc_test
  glcc GLEW
  ${SDL_LIBRARY}
  ${Boost_LIBRARIES}
  ${OPENGL_LIBRARIES}
  )
