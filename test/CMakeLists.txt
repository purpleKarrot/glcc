##############################################################
# Copyright (c) 2008-2009 Daniel Pfeifer                     #
#                                                            #
# Distributed under the Boost Software License, Version 1.0. #
##############################################################

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})

find_package(Boost 1.38.0 REQUIRED
  COMPONENTS unit_test_framework)

file(GLOB_RECURSE GLCC_TEST_SRC glcc/*.cpp)
add_executable(glcc_test ${GLCC_TEST_SRC})

target_link_libraries(glcc_test
  ${Boost_LIBRARIES}
  ${OPENGL_LIBRARIES}
  ${GLUT_glut_LIBRARY}
  )

#file(GLOB_RECURSE CLCC_TEST_SRC clcc/*.cpp)
#add_test_module(clcc_test ${CLCC_TEST_SRC})

