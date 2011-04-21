##############################################################
# Copyright (c) 2008-2009 Daniel Pfeifer                     #
#                                                            #
# Distributed under the Boost Software License, Version 1.0. #
##############################################################

find_package(Boost COMPONENTS test NO_MODULE)
include(BoostTestSuite)

add_custom_target(test)
set(BOOST_CURRENT_PROJECT glcc)

find_package(PNG REQUIRED)
find_package(JPEG REQUIRED)

find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
include_directories(${SDL_INCLUDE_DIR})

##############################################################

boost_test_suite(
  RUN
    blend
    depth
    extensions
    hint
    info
    logic
    stencil
    texture
  LINK_BOOST_LIBRARIES
    system
    unit_test_framework
  LINK_LIBRARIES
    glcc
    ${SDL_LIBRARY}
    ${SDLIMAGE_LIBRARY}
    ${PNG_LIBRARIES}
    ${JPEG_LIBRARIES}
    ${OPENGL_LIBRARIES}
  )
